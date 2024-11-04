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

void sieve(int spf[]) {
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        spf[i] = i;
    }
    for (int i = 4; i < MAXN; i += 2) {
        spf[i] = 2;
    }
    for (int i = 3; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

void getFactorization(int x, int spf[], int *ret, int *size) {
    *size = 0;
    while (x != 1) {
        ret[(*size)++] = spf[x];
        x = x / spf[x];
    }
}

void solve() {
    long n;
    scanf("%ld", &n);
    
    int spf[MAXN];
    sieve(spf);
    
    int factors[100];
    int size = 0;
    getFactorization(n, spf, factors, &size);
    
    if (n == 1) {
        printf("1\n0\n");
    } else if (size == 2) {
        printf("2\n");
    } else {
        printf("1\n");
        if (size == 1) {
            printf("0\n");
        } else {
            long ans = (factors[0] * factors[1]);
            printf("%ld\n", ans);
        }
    }
}

int main() {
    solve();
    return 0;
}
