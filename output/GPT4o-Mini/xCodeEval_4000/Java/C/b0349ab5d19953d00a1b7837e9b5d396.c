#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_N 100000

typedef struct {
    long long numerator;
    long long denominator;
} Fraction;

long long gcd(long long a, long long b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

void cancellation(Fraction *f) {
    long long g = gcd(abs(f->numerator), abs(f->denominator));
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

void solve() {
    int n, m, a, b;
    scanf("%d %d %d %d", &n, &m, &a, &b);
    n--;
    a--;
    b--;
    
    int i = a / m;
    int j = b / m;
    int l = a % m;
    int r = (b == n ? m - 1 : b % m);
    
    if (l == 0 && r == m - 1) {
        printf("1\n");
        return;
    }
    if (j - i < 2) {
        printf("%d\n", j - i + 1);
        return;
    }
    if ((l != 0 && r == m - 1) || (l == 0 && r != m - 1)) {
        printf("2\n");
        return;
    }
    if (l - r == 1) {
        printf("2\n");
        return;
    }
    printf("3\n");
}

int main() {
    long long t1 = clock();
    solve();
    long long t2 = clock();
    fprintf(stderr, "Time = %lld\n", (t2 - t1) * 1000 / CLOCKS_PER_SEC);
    return 0;
}
