#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MODULO 1000000007

typedef struct {
    long power;
    long coeff;
} Pair;

long inverseNMinus1Factorial;

long mult(long a, long b) {
    return (a % MODULO) * (b % MODULO) % MODULO;
}

long add(long a, long b) {
    return ((a % MODULO + b % MODULO) % MODULO + MODULO) % MODULO;
}

long binpow(long base, long power) {
    if (power == 0) return 1;
    if (power % 2 == 0) {
        long half = binpow(base, power / 2);
        return mult(half, half);
    } else {
        return mult(base, binpow(base, power - 1));
    }
}

long inverse(long x) {
    return binpow(x, MODULO - 2);
}

long multSequence(long start, long end) {
    long res = 1;
    for (long i = start; i <= end; ++i) {
        res = mult(res, i);
    }
    return res;
}

long binom(long n, long k) {
    return mult(multSequence(k + 1, n), inverseNMinus1Factorial);
}

void solve() {
    int n;
    long s;
    scanf("%d %ld", &n, &s);

    long *f = (long *)malloc(n * sizeof(long));
    for (int i = 0; i < n; ++i) {
        scanf("%ld", &f[i]);
    }

    long *coeffs = (long *)calloc(1000000, sizeof(long));
    coeffs[0] = 1;

    for (int i = 0; i < n; ++i) {
        long size = f[i];
        Pair *coeffEntries = (Pair *)malloc(1000000 * sizeof(Pair));
        int coeffCount = 0;

        for (long j = 0; j < 1000000; ++j) {
            if (coeffs[j] != 0) {
                long nextPower = j + size + 1;
                coeffEntries[coeffCount++] = (Pair){nextPower, -coeffs[j]};
            }
        }

        for (int j = 0; j < coeffCount; ++j) {
            coeffs[coeffEntries[j].power] = add(coeffs[coeffEntries[j].power], coeffEntries[j].coeff);
        }
        free(coeffEntries);
    }

    long nMinus1Factorial = multSequence(1, n - 1);
    inverseNMinus1Factorial = inverse(nMinus1Factorial);

    long answer = 0;
    for (long j = 0; j < 1000000; ++j) {
        if (coeffs[j] != 0) {
            long power = j;
            long coeff = coeffs[j];

            if (s >= power) {
                long need = s - power;
                answer = add(answer, mult(binom(n + need - 1, need), coeff));
            }
        }
    }

    printf("%ld\n", answer);
    free(f);
    free(coeffs);
}

int main() {
    solve();
    return 0;
}
