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
} id4;

typedef struct {
    int *primes;
    int *xcums;
    long *isp;
    int cachelimit;
    id4 picache;
    id4 id1;
    int **cumps;
    int FP[8];
    int M;
    int B;
} id7;

int* id0(int n) {
    if (n <= 32) {
        int *primes = (int *)malloc(11 * sizeof(int));
        int primes_arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        memcpy(primes, primes_arr, sizeof(primes_arr));
        for (int i = 0; i < 11; i++) {
            if (n < primes[i]) {
                primes = realloc(primes, i * sizeof(int));
                return primes;
            }
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

    int id3[] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    for (int tp = 0; tp < 10; tp++) {
        ret[pos++] = id3[tp];
        int *ptn = (int *)calloc(tp, sizeof(int));
        for (int i = (tp - 3) / 2; i < tp << 5; i += tp)
            ptn[i >> 5] |= 1 << (i & 31);
        for (int j = 0; j < sup; j += tp) {
            for (int i = 0; i < tp && i + j < sup; i++) {
                isnp[j + i] |= ptn[i];
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

id7* create_id7(long n) {
    id7 *ml = (id7 *)malloc(sizeof(id7));
    ml->picache.keys = (long *)malloc((1 << 2) * sizeof(long));
    ml->picache.allocated = (long *)malloc((1 << 2) * sizeof(long));
    memset(ml->picache.allocated, NG, (1 << 2) * sizeof(long));
    ml->picache.scale = 1 << 2;
    ml->picache.rscale = 1 << 1;
    ml->picache.mask = ml->picache.scale - 1;
    ml->picache.size = 0;

    ml->M = 8;
    ml->B = 100;
    ml->FP[0] = 2;
    ml->FP[1] = 3;
    ml->FP[2] = 5;
    ml->FP[3] = 7;
    ml->FP[4] = 11;
    ml->FP[5] = 13;
    ml->FP[6] = 17;
    ml->FP[7] = 19;

    int s = (int)sqrt(n) * ml->B;
    ml->cachelimit = s;
    ml->primes = id0(s);
    ml->xcums = (int *)calloc((s >> 6) + 1, sizeof(int));
    ml->isp = (long *)calloc((s >> 6) + 1, sizeof(long));
    for (int p = 0; p < sizeof(ml->primes) / sizeof(int); p++)
        ml->isp[ml->primes[p] >> 6] |= 1L << ml->primes[p];

    for (int i = 0; i < (s >> 6); i++)
        ml->xcums[i + 1] = ml->xcums[i] + __builtin_popcountll(ml->isp[i]);

    ml->cumps = (int **)malloc(ml->M * sizeof(int *));
    for (int i = 0; i < ml->M; i++) {
        int len = 1;
        for (int j = 0; j <= i; j++)
            len *= ml->FP[j];
        ml->cumps[i] = (int *)malloc((len + 1) * sizeof(int));
        memset(ml->cumps[i], 0, (len + 1) * sizeof(int));
        for (int j = 0; j < len; j++)
            ml->cumps[i][j + 1] = ml->cumps[i][j] + (j % ml->FP[i] == 0 ? 1 : 0);
    }

    return ml;
}

long pi(id7 *ml, long x) {
    if (x <= ml->cachelimit) {
        int ix = (int)x;
        return ml->xcums[ix >> 6] + __builtin_popcountll(ml->isp[ix >> 6] << ~ix);
    }
    // Implement caching logic here if needed
    return 0; // Placeholder return
}

void solve() {
    long n;
    scanf("%ld", &n);
    long ans = 0;
    if (n <= 10) {
        if (n >= 6) ans++;
        if (n >= 8) ans++;
        if (n >= 10) ans++;
        printf("%ld\n", ans);
        return;
    }

    id7 *ml = create_id7(n / 2);
    int *primes = id0(400000);
    for (int i = 0; primes[i] != 0; i++) {
        long plus = pi(ml, n / primes[i]) - (i + 1);
        if (plus <= 0) break;
        ans += plus;
    }

    for (int i = 0; primes[i] != 0; i++) {
        if ((long)primes[i] * primes[i] * primes[i] <= n) {
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
