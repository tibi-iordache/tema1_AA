// Iordache Tiberiu-Mihai 322CD
// ID moodle: tiberiu.iordache00

#ifndef SOLOVAY_H
#define SOLOVAY_H

// required for swap and rand  
#include <algorithm>

// function that will compute a^((n - 1) / 2) mod n
long long legendre_function(long long base, long long exponent, long long mod);

// function that will compute the Jacobian symbol of a given number
int jacobian_function(long long a, long long n);

// The Solovay-Strassen function
bool solovay_strassen(long long p, int iterations);


#endif