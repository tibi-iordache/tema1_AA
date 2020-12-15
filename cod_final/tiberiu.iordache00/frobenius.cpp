// Iordache Tiberiu-Mihai 322CD
// ID moodle: tiberiu.iordache00

#include "frobenius.h"

bool is_square(long long number) {
    // check if square root is integer
    return ((sqrt(number) - floor(sqrt(number))) == 0);  
}


long long check_negative_modulo(long long number, long long mod) {
    // compute the rest
    long long n = number % mod;

    // check if it still negative
    if (((mod > 0) && (n < 0)) || ((mod < 0) && (n > 0))) {
        // add the modulo base so it will be positive
        n += mod;
    }
        
    return n;
}

bool frobenius(long long n) {
    // guards
    if (n < 2)
        return false;

    if (n == 2 || n == 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;
    
    // check if number is perfect square
    if (is_square(n))
        return false;
    
    
    // compute c =  the frobenius index
    // (smallest number such that Jacobi(c/n) = -1) 
    long long c = 0;

    // check small values first
    if (n % 4 == 3) {
        c = -1;
    } else if (n % 8 == 5) {
        c = 2;
    } else if (n % 24 == 17) {
        c = 3;
    } else {
        c = 5;

        // stat computing bigger values
        while(1) {
            long long jacobi = jacobian_function(c, n);
            
            if (jacobi == 0)
                return false;
            
            if (jacobi == -1) 
                break;
            
            c += 2;
        }
    }
    
    // z = a + b * sqrt(c)
    long long a = 1, b = 1;
    
    if (c < 3) {
        // for c < 3 we have z = 2 + sqrt(c)
        a = 2;
    }

    // else we got z = 1 + sqrt(c)

    // now we will compute z^n mod n

    // we will multiply z1 with a z2 multiple times
    // a2, b2, mul_a, mul_b will be used for multiplication
    long long a1 = 1, b1 = 0, a2 = a, b2 = b, pow = n;
    long long mul_a, mul_b;

    while(pow > 0) {
        if (pow % 2 == 1) {  
            // z1 = z1 * z2
            mul_b = check_negative_modulo((a1*b2 + a2*b1), n); 
            
            mul_a = check_negative_modulo((a1*a2 + b1*b2*c), n);

            a1 = mul_a;

            b1 = mul_b;
        }

        //  z2 = z2 * z2
        mul_a = check_negative_modulo((a2 * a2 + c * b2 * b2), n);
        b2 = check_negative_modulo((2 * a2 * b2), n);
        
        a2 = mul_a;

        pow /= 2;
    }

    // we check if z^n mod n == conjugated z mod n
    if ((a1 == a) && (b1 == (n - b)))
        // if yes, the number is probable prime
        return true;
    
    // else composite
    return false;
}