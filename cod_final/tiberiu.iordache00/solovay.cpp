// Iordache Tiberiu-Mihai 322CD
// ID moodle: tiberiu.iordache00

#include "solovay.h"

long long legendre_function(long long base,
                            long long exponent,
                            long long mod) {
    long long result = 1;
    
    //make a copy of the base
    long long base_copy = base;
    
    while (1) {
        // infinite loop until the exponent becomes 0 or lower
        if (exponent <= 0)
            break;

        // check if the exponent is odd
        if (exponent % 2 == 1) 
            // we compute the new result
            result = (result * base_copy) % mod;

        // update the base
        base_copy *= base_copy;
        
        base_copy %= mod;

        // keep dividing the exponent
        exponent /= 2;
    }

    return result % mod;
}

int jacobian_function(long long a, long long n) {
    // guards
    if (!a) 
        // (0/n) = 0
        return 0;

    if (a == 1)
        // (1/n) = 1
        return 1; 
        
    int res = 1;

    while (1) {
        // infinite loop until a becomes 0
        if (a == 0)
            break;

        if (a < 0) {
            // if a becomes negative, we need to change the sign
            // (a/n) = (-a/n)*(-1/n)
            a = -a;

            // check the value of (-1/n)
            if (n % 4 == 3)
                // (-1/n) = -1 if n = 3 (mod 4)  
                res = -res;
        }    

        // we extract any even numerator
        while (1) {
            // infinte loop until we make a an odd number
            if (a % 2 == 1)
                break;

            // if a is even, we keep diving it    
            a = a / 2;

            // we check the value of (2/n)
            // (2/n) == 1 if n = 3(mod 8)/5(mod 8)
            if (n % 8 == 3 || n % 8 == 5)
                // so we will change the sign of the result
                res = -res;
        }

        // after that we can swap a and n
        std::swap(a, n);

        // check the result of (a/n)(n/a)
        // (a/n)(n/a) = -1 if a = n = 3(mod 4)
        if (a % 4 == 3 && n % 4 == 3)
            res = -res;

        // recalculate the rest and redo the check above
        a = a % n;

        if (a > n / 2)
            a = a - n;
    }
    
    // (a/n) = 1 if gcd(a,n) = 1
    if (n == 1)
        return res;

    // (a/n) = 0 if gcd(a,n) != 1
    return 0;
}

bool solovay_strassen(long long p, int iterations) {
    // guard
    if (p < 2)
        return false;

    // the only even number that is prime is 2
    if (p != 2 && p % 2 == 0)
        return false;

    // repeat the primality test for a number of iterations
    // for more accurate results
    for (int i = 0; i <  iterations; i++) {
        // generate a random number from the interval [1, p - 1]
        long long a = rand() % (p - 1) + 1;

        // compute the jacobian (a/n)
        long long jacobian_result = (p + jacobian_function(a, p)) % p;

        // compute a^((n - 1) / 2) mod n
        long long euler_result = legendre_function(a, (p - 1) / 2, p);
        
        // compare them
        if (!jacobian_result || euler_result != jacobian_result)
            // if they aren't equal we can exit the program
            return false;
    }

    // if they are equal, we can say that the number is probable prime
    return true;
}