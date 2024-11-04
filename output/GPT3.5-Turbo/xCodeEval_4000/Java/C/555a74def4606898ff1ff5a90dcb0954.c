#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAXN 1000000

int primes[MAXN];
int primesSize;

void sieveEratosthenes(int n) {
    bool isPrime[MAXN];
    for (int i = 0; i <= n; i++) {
        isPrime[i] = true;
    }

    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p] == true) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    primesSize = 0;
    for (int p = 2; p <= n; p++) {
        if (isPrime[p]) {
            primes[primesSize++] = p;
        }
    }
}

long long pi(long long x) {
    if (x <= primes[primesSize - 1]) {
        int count = 0;
        for (int i = 0; i < primesSize; i++) {
            if (primes[i] <= x) {
                count++;
            } else {
                break;
            }
        }
        return count;
    }

    int A = (int) sqrt(sqrt(x));
    long long ret = pi(sqrt(sqrt(x))) - pi(A);

    int B = pi(sqrt(x));
    int C = pi(cbrt(x));

    for (int i = A; i < B; i++) {
        long long xi = x / primes[i];
        for (int j = i; j < C; j++) {
            ret -= pi(xi / primes[j]) - j;
        }
    }

    return ret;
}

int main() {
    long long n;
    scanf("%lld", &n);

    sieveEratosthenes(sqrt(n));

    long long ans = pi(n);
    printf("%lld\n", ans);

    return 0;
}
