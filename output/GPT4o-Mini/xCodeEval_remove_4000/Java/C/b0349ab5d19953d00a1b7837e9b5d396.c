#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_N 100000

typedef struct {
    long numerator;
    long denominator;
} Fraction;

long gcd(long a, long b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

long lcm(long a, long b) {
    return a / gcd(a, b) * b;
}

void cancellation(Fraction *f) {
    long g = gcd(abs(f->numerator), abs(f->denominator));
    f->numerator /= g;
    f->denominator /= g;
    if (f->denominator < 0) {
        f->numerator *= -1;
        f->denominator *= -1;
    }
}

Fraction add(Fraction f1, Fraction f2) {
    Fraction result;
    result.denominator = lcm(f1.denominator, f2.denominator);
    result.numerator = f1.numerator * result.denominator / f1.denominator + f2.numerator * result.denominator / f2.denominator;
    cancellation(&result);
    return result;
}

Fraction subtract(Fraction f1, Fraction f2) {
    Fraction result;
    result.denominator = lcm(f1.denominator, f2.denominator);
    result.numerator = f1.numerator * result.denominator / f1.denominator - f2.numerator * result.denominator / f2.denominator;
    cancellation(&result);
    return result;
}

Fraction multiply(Fraction f1, Fraction f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.numerator;
    result.denominator = f1.denominator * f2.denominator;
    cancellation(&result);
    return result;
}

Fraction divide(Fraction f1, Fraction f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.denominator;
    result.denominator = f1.denominator * f2.numerator;
    cancellation(&result);
    return result;
}

void init(FILE **in, FILE **out) {
    if (getenv("id5")) {
        *in = stdin;
        *out = stdout;
    } else {
        *in = fopen("input.txt", "r");
        *out = fopen("output.txt", "w");
    }
}

int readInt(FILE *in) {
    int value;
    fscanf(in, "%d", &value);
    return value;
}

void solve(FILE *in, FILE *out) {
    int n = readInt(in) - 1;
    int m = readInt(in);
    int a = readInt(in) - 1;
    int b = readInt(in) - 1;
    int i = a / m;
    int j = b / m;
    int l = a % m;
    int r = (b == n ? m - 1 : b % m);
    
    if (l == 0 && r == m - 1) {
        fprintf(out, "1");
        return;
    }
    if (j - i < 2) {
        fprintf(out, "%d", j - i + 1);
        return;
    }
    if ((l != 0 && r == m - 1) || (l == 0 && r != m - 1)) {
        fprintf(out, "2");
        return;
    }
    if (l - r == 1) {
        fprintf(out, "2");
        return;
    }
    fprintf(out, "3");
}

int main() {
    FILE *in, *out;
    init(&in, &out);
    
    long t1 = clock();
    solve(in, out);
    long t2 = clock();
    
    if (in != stdin) fclose(in);
    if (out != stdout) fclose(out);
    
    fprintf(stderr, "Time = %ld\n", (t2 - t1) * 1000 / CLOCKS_PER_SEC);
    return 0;
}
