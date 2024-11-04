#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define MAXN 10000001

long gcd(long a, long b) {
    return (b == 0) ? a : gcd(b, a % b);
}

long lcm(long a, long b) {
    return (a * b) / gcd(a, b);
}

long modInverse(long a, long p) {
    long res = 1;
    long x = p - 2;
    while (x > 0) {
        if (x % 2 != 0) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        x /= 2;
    }
    return res;
}

long modBinomial(long n, long k, long p) {
    long numerator = 1;
    for (int i = 0; i < k; i++) {
        numerator = (numerator * (n - i)) % p;
    }

    long denominator = 1;
    for (int i = 1; i <= k; i++) {
        denominator = (denominator * i) % p;
    }

    return (numerator * modInverse(denominator, p)) % p;
}

void solve() {
    long n, a1, a2, a3, b1, b2, b3;
    scanf("%ld", &n);
    scanf("%ld %ld %ld", &a1, &a2, &a3);
    scanf("%ld %ld %ld", &b1, &b2, &b3);

    long min = 0L;

    if (b1 >= a1 + a2) {
        min = a3 - b2 - b3;
    } else if (b2 >= a3 + a2) {
        min = a1 - b1 - b3;
    } else if (b3 >= a1 + a3) {
        min = a2 - b2 - b1;
    } else {
        min = 0;
    }

    long max = fmin(a1, b2) + fmin(a2, b3) + fmin(a3, b1);

    printf("%ld %ld\n", min, max);
}

int main() {
    solve();
    return 0;
}
