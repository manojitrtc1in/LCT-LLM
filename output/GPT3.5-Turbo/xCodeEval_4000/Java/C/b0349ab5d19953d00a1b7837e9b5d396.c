#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    long numerator;
    long denominator;
} Fraction;

Fraction fraction_zero;
Fraction fraction_one;

long gcd(long a, long b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

long lcm(long a, long b) {
    return a / gcd(a, b) * b;
}

Fraction fraction_create(long numerator, long denominator) {
    Fraction f;
    f.numerator = numerator;
    f.denominator = denominator;
    return f;
}

Fraction fraction_add(Fraction f1, Fraction f2) {
    Fraction result;
    result.denominator = lcm(f1.denominator, f2.denominator);
    result.numerator = f1.numerator * (result.denominator / f1.denominator) + f2.numerator * (result.denominator / f2.denominator);
    long g = gcd(abs(result.numerator), abs(result.denominator));
    result.numerator /= g;
    result.denominator /= g;
    if (result.denominator < 0) {
        result.numerator *= -1;
        result.denominator *= -1;
    }
    return result;
}

Fraction fraction_subtract(Fraction f1, Fraction f2) {
    Fraction result;
    result.denominator = lcm(f1.denominator, f2.denominator);
    result.numerator = f1.numerator * (result.denominator / f1.denominator) - f2.numerator * (result.denominator / f2.denominator);
    long g = gcd(abs(result.numerator), abs(result.denominator));
    result.numerator /= g;
    result.denominator /= g;
    if (result.denominator < 0) {
        result.numerator *= -1;
        result.denominator *= -1;
    }
    return result;
}

Fraction fraction_multiply(Fraction f1, Fraction f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.numerator;
    result.denominator = f1.denominator * f2.denominator;
    long g = gcd(abs(result.numerator), abs(result.denominator));
    result.numerator /= g;
    result.denominator /= g;
    if (result.denominator < 0) {
        result.numerator *= -1;
        result.denominator *= -1;
    }
    return result;
}

Fraction fraction_divide(Fraction f1, Fraction f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.denominator;
    result.denominator = f1.denominator * f2.numerator;
    long g = gcd(abs(result.numerator), abs(result.denominator));
    result.numerator /= g;
    result.denominator /= g;
    if (result.denominator < 0) {
        result.numerator *= -1;
        result.denominator *= -1;
    }
    return result;
}

Fraction fraction_floor(Fraction f) {
    Fraction result;
    result.numerator = (f.numerator / f.denominator) * f.denominator;
    result.denominator = f.denominator;
    return result;
}

Fraction fraction_ceil(Fraction f) {
    Fraction result;
    result.numerator = ((f.numerator / f.denominator) + 1) * f.denominator;
    result.denominator = f.denominator;
    return result;
}

Fraction fraction_binpow(Fraction f, int n) {
    if (n == 0) return fraction_one;
    if ((n & 1) == 0) {
        Fraction b = fraction_binpow(f, n / 2);
        return fraction_multiply(b, b);
    } else {
        return fraction_multiply(fraction_binpow(f, n - 1), f);
    }
}

int main() {
    fraction_zero.numerator = 0;
    fraction_zero.denominator = 1;
    fraction_one.numerator = 1;
    fraction_one.denominator = 1;

    // Your code here

    return 0;
}
