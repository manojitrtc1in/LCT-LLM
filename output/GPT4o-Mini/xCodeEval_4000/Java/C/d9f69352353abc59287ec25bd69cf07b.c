#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define NG 0

typedef struct {
    long *keys;
    long *allocated;
    int scale;
    int rscale;
    int mask;
    int size;
} LongHashCounterL;

typedef struct {
    int *primes;
    int *xcums;
    long *isp;
    int cachelimit;
    LongHashCounterL picache;
    LongHashCounterL phicache;
    int **cumps;
    int FP[8];
    int M;
    int B;
} MeisselLehmer2;

int* sieveEratosthenes(int n) {
    if (n <= 32) {
        int *primes = (int *)malloc(11 * sizeof(int));
        int primesArr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        int count = 0;
        for (int i = 0; i < 11; i++) {
            if (n < primesArr[i]) {
                return realloc(primes, count * sizeof(int));
            }
            primes[count++] = primesArr[i];
        }
        return primes;
    }

    int u = n + 32;
    double lu = log(u);
    int *ret = (int *)malloc((int)(u / lu + u / lu / lu * 1.5) * sizeof(int));
    ret[0] = 2;
    int pos = 1;

    int *isnp = (int *)calloc((n + 1) / 32 / 2 + 1, sizeof(int));
    int sup = (n + 1) / 32 / 2 + 1;

    int tprimes[] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    for (int i = 0; i < 10; i++) {
        int tp = tprimes[i];
        ret[pos++] = tp;
        int *ptn = (int *)calloc(tp, sizeof(int));
        for (int j = (tp - 3) / 2; j < tp << 5; j += tp)
            ptn[j >> 5] |= 1 << (j & 31);
        for (int j = 0; j < sup; j += tp) {
            for (int k = 0; k < tp && k + j < sup; k++) {
                isnp[j + k] |= ptn[k];
            }
        }
        free(ptn);
    }

    int magic[] = {0, 1, 23, 2, 29, 24, 19, 3, 30, 27, 25, 11, 20, 8, 4, 13, 31, 22, 28, 18, 26, 10, 7, 12, 21, 17, 9, 6, 16, 5, 15, 14};
    int h = n / 2;
    for (int i = 0; i < sup; i++) {
        for (int j = ~isnp[i]; j != 0; j &= j - 1) {
            int pp = i << 5 | magic[(j & -j) * 0x076be629 >> 27];
            int p = 2 * pp + 3;
            if (p > n)
                break;
            ret[pos++] = p;
            if ((long)p * p > n)
                continue;
            for (int q = (p * p - 3) / 2; q <= h; q += p)
                isnp[q >> 5] |= 1 << q;
        }
    }

    free(isnp);
    return realloc(ret, pos * sizeof(int));
}

long nl() {
    long num = 0;
    int b;
    int minus = 0;
    while ((b = getchar()) != EOF && !((b >= '0' && b <= '9') || b == '-'));
    if (b == '-') {
        minus = 1;
        b = getchar();
    }

    while (1) {
        if (b >= '0' && b <= '9') {
            num = num * 10 + (b - '0');
        } else {
            return minus ? -num : num;
        }
        b = getchar();
    }
}

void solve() {
    long n = nl();
    long ans = 0;
    MeisselLehmer2 ml = {0};
    ml.primes = sieveEratosthenes(400000);
    for (int i = 0; ml.primes[i] != 0; i++) {
        long plus = ml.pi(n / ml.primes[i]) - (i + 1);
        if (plus <= 0) break;
        ans += plus;
    }

    for (int i = 0; ml.primes[i] != 0; i++) {
        if ((long)ml.primes[i] * ml.primes[i] * ml.primes[i] <= n) {
            ans++;
        } else {
            break;
        }
    }
    printf("%ld\n", ans);
}

int main() {
    solve();
    return 0;
}
