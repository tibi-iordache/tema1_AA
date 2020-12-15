// Iordache Tiberiu-Mihai 322CD
// ID moodle: tiberiu.iordache00

#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // test 0 handmade

    // ---------------------------------------

    // test 1 first 100 numbers
    ofstream outfile ("in/test1.in");

    int n = 100;

    outfile << n << "\n";

    for (int i = 1; i <= n; i++) {
        outfile << i << " ";
    }

    outfile.close();

    // ---------------------------------------

    // test 2 first 1000 numbers
    ofstream outfile2 ("in/test2.in");

    n = 1000;

    outfile2 << n << "\n";

    for (int i = 1; i <= n; i++) {
        outfile2 << i << " ";
    }

    outfile2.close();
    
    // ---------------------------------------

    // test 3 first 10000 numbers
    ofstream outfile3 ("in/test3.in");
    
    n = 10000;

    outfile3 << n << "\n";

    for (int i = 1; i <= n; i++) {
        outfile3 << i << " ";
    }
    
    outfile3.close();

    // ---------------------------------------

    // test 4 only composite numbers

    ofstream outfile4 ("in/test4.in");

    n = 20;

    outfile4 << n << "\n";

    int first_no = 4;

    for (int i = 1; i <= n; i++) {
        // multiply each time by 3
        first_no *= 3;
        outfile4 << first_no << " ";
    }

    outfile4.close();

    // ---------------------------------------

    // test 5 large composite numbers handmade

    // ---------------------------------------

    // test 6 fibonacci

    ofstream outfile5 ("in/test6.in");

    n = 40;

    outfile5 << n << "\n";

    long long t1 = 0, t2 = 1, t_next = 0;

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            outfile5 << t1 << " ";
            
            continue;
        }

        if (i == 2) {
            outfile5 << t2 << " ";

            continue;
        }

        t_next = t1 + t2;

        t1 = t2;
        t2 = t_next;

        outfile5 << t_next << " ";
    }

    outfile5.close();

    // ---------------------------------------

    // test 7 Eratostene 
    // test with only prime numbers

    ofstream outfile6("in/test7.in");

    const int VMAX = 1001;
    // all prime numbers <1000
    n = 1000;

    bool sieve[VMAX];

    int sol; // number of prime numbers
    int primes[VMAX]; // the prime numbers

    sieve[0] = sieve[1] = true;

    for (int j = 4; j <= n; j += 2) {
        sieve[j] = true;
    } 

    for (int i = 3; i * i <= n; i += 2) {
        if (!sieve[i]) {
            for (int j = i * i; j <= n; j += 2 * i) {
                sieve[j] = true;
            }       
        }
    }
        

    primes[sol++] = 2;

    for (int i = 3; i <= n; i += 2) {
        if (!sieve[i])
            primes[sol++] = i;
    }
        
    // write the number of prime numbers found
    outfile6 << sol - 1 << "\n";

    // write each prime number
    for (int i = 0; i < sol; i++)
        outfile6 << primes[i] << ' ';

    outfile6.close();    

    return 0;
}