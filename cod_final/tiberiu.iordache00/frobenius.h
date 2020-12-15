// Iordache Tiberiu-Mihai 322CD
// ID moodle: tiberiu.iordache00

#ifndef FROBENIUS_H
#define FROBENIUS_H

#include <algorithm>
#include <math.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

// check if a given number is a perfect square
bool is_square(long long number);

// computes number % mod and also check if the number is negative
// so the result of modulo operation will always be positive
long long check_negative_modulo(long long number, long long mod);

// function that will compute the Jacobian symbol of a given number
// (already implemented in solovay-strassen)
int jacobian_function(long long a, long long n);

// the frobenius primality test function
bool frobenius(long long n);


#endif