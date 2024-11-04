#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 1000000
#define MODULO 1000000007

long long id34;

long long add(long long a, long long b) {
    return ((a % MODULO + b % MODULO) % MODULO + MODULO) % MODULO;
}

long long mult(long long a, long long b) {
    return (a % MODULO) * (b % MODULO) % MODULO;
}

long long binpow(long long base, long long power) {
    if (power == 0) return 1;

    if ((power & 1) == 0) {
        long long half = binpow(base, power >> 1);
        return mult(half, half);
    } else {
        long long prev = binpow(base, power - 1);
        return mult(prev, base);
    }
}

long long inverse(long long x) {
    return binpow(x, MODULO - 2);
}

long long multSequence(long long start, long long end) {
    long long res = 1;
    for (long long i = start; i <= end; ++i) {
        res = mult(res, i);
    }

    return res;
}

long long binom(long long n, long long k) {
    return mult(multSequence(k + 1, n), id34);
}

void solve() {
    int n;
    long long s;

    scanf("%d %lld", &n, &s);

    long long f[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &f[i]);
    }

    long long coeffs[MAX_SIZE];
    memset(coeffs, 0, sizeof(coeffs));
    coeffs[0] = 1;

    for (int i = 0; i < n; i++) {
        long long size = f[i];
        long long coeffEntries[MAX_SIZE][2];
        int coeffEntriesCount = 0;

        for (int j = 0; j < MAX_SIZE; j++) {
            if (coeffs[j] != 0) {
                long long power = j;
                long long coeff = coeffs[j];

                long long nextPower = power + size + 1;
                coeffEntries[coeffEntriesCount][0] = nextPower;
                coeffEntries[coeffEntriesCount][1] = -coeff;
                coeffEntriesCount++;
            }
        }

        for (int j = 0; j < coeffEntriesCount; j++) {
            long long power = coeffEntries[j][0];
            long long coeff = coeffEntries[j][1];

            coeffs[power] = add(coeffs[power], coeff);
        }
    }

    long long id25 = multSequence(1, n - 1);
    id34 = inverse(id25);

    long long answer = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (coeffs[i] != 0) {
            long long power = i;
            long long coeff = coeffs[i];

            if (s >= power) {
                long long need = s - power;
                answer = add(answer, mult(binom(n + need - 1, need), coeff));
            }
        }
    }

    printf("%lld\n", answer);
}

int main() {
    solve();

    return 0;
}
