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

int *sieveEratosthenes(int n);
void solve();
long nl();
void run();
void initLongHashCounter(LongHashCounterL *counter);
int containsKey(LongHashCounterL *counter, long x);
long get(LongHashCounterL *counter, long x);
long put(LongHashCounterL *counter, long x, long v);
long inc(LongHashCounterL *counter, long x, long v);
int removeKey(LongHashCounterL *counter, long x);
void resizeAndPut(LongHashCounterL *counter, long x, long v);
int next(LongHashCounterL *counter, int itr);
int h(long x);
void initMeisselLehmer2(MeisselLehmer2 *ml, long n);
long pi(MeisselLehmer2 *ml, long x);
long phi(MeisselLehmer2 *ml, long x, int A);
long P2(MeisselLehmer2 *ml, long x, int A);
long P3(MeisselLehmer2 *ml, long x, int A);
void freeLongHashCounter(LongHashCounterL *counter);
void freeMeisselLehmer2(MeisselLehmer2 *ml);

int *primes;

int main() {
    run();
    return 0;
}

int *sieveEratosthenes(int n) {
    if (n <= 32) {
        int *primes = (int *)malloc(11 * sizeof(int));
        int temp[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        memcpy(primes, temp, sizeof(temp));
        for (int i = 0; i < 11; i++) {
            if (n < primes[i]) {
                return realloc(primes, i * sizeof(int));
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

void solve() {
    long n = nl();
    long ans = 0;
    MeisselLehmer2 ml;
    initMeisselLehmer2(&ml, n / 2);
    for (int i = 0; i < primes[i]; i++) {
        long plus = pi(&ml, n / primes[i]) - (i + 1);
        if (plus <= 0) break;
        ans += plus;
    }

    for (int i = 0; primes[i] * primes[i] * primes[i] <= n; i++) {
        ans++;
    }
    printf("%ld\n", ans);
    freeMeisselLehmer2(&ml);
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

void run() {
    primes = sieveEratosthenes(400000);
    long s = clock();
    solve();
    printf("%ldms\n", (clock() - s) * 1000 / CLOCKS_PER_SEC);
}

void initLongHashCounter(LongHashCounterL *counter) {
    counter->scale = 1 << 2;
    counter->rscale = 1 << 1;
    counter->mask = counter->scale - 1;
    counter->size = 0;
    counter->allocated = (long *)malloc(counter->scale * sizeof(long));
    memset(counter->allocated, NG, counter->scale * sizeof(long));
    counter->keys = (long *)malloc(counter->scale * sizeof(long));
}

int containsKey(LongHashCounterL *counter, long x) {
    int pos = h(x) & counter->mask;
    while (counter->allocated[pos] != NG) {
        if (x == counter->keys[pos]) return 1;
        pos = (pos + 1) & counter->mask;
    }
    return 0;
}

long get(LongHashCounterL *counter, long x) {
    int pos = h(x) & counter->mask;
    while (counter->allocated[pos] != NG) {
        if (x == counter->keys[pos]) return counter->allocated[pos];
        pos = (pos + 1) & counter->mask;
    }
    return NG;
}

long put(LongHashCounterL *counter, long x, long v) {
    int pos = h(x) & counter->mask;
    while (counter->allocated[pos] != NG) {
        if (x == counter->keys[pos]) {
            long oldval = counter->allocated[pos];
            counter->allocated[pos] = v;
            return oldval;
        }
        pos = (pos + 1) & counter->mask;
    }
    if (counter->size == counter->rscale) {
        resizeAndPut(counter, x, v);
    } else {
        counter->keys[pos] = x;
        counter->allocated[pos] = v;
    }
    counter->size++;
    return 0;
}

long inc(LongHashCounterL *counter, long x, long v) {
    int pos = h(x) & counter->mask;
    while (counter->allocated[pos] != NG) {
        if (x == counter->keys[pos]) {
            counter->allocated[pos] += v;
            return counter->allocated[pos];
        }
        pos = (pos + 1) & counter->mask;
    }
    if (counter->size == counter->rscale) {
        resizeAndPut(counter, x, v);
    } else {
        counter->keys[pos] = x;
        counter->allocated[pos] = v;
    }
    counter->size++;
    return v;
}

int removeKey(LongHashCounterL *counter, long x) {
    int pos = h(x) & counter->mask;
    while (counter->allocated[pos] != NG) {
        if (x == counter->keys[pos]) {
            counter->size--;
            int last = pos;
            pos = (pos + 1) & counter->mask;
            while (counter->allocated[pos] != NG) {
                int lh = h(counter->keys[pos]) & counter->mask;
                if ((lh <= last && last < pos) || (pos < lh && lh <= last) || (last < pos && pos < lh)) {
                    counter->keys[last] = counter->keys[pos];
                    counter->allocated[last] = counter->allocated[pos];
                    last = pos;
                }
                pos = (pos + 1) & counter->mask;
            }
            counter->keys[last] = 0;
            counter->allocated[last] = NG;
            return 1;
        }
        pos = (pos + 1) & counter->mask;
    }
    return 0;
}

void resizeAndPut(LongHashCounterL *counter, long x, long v) {
    int nscale = counter->scale << 1;
    int nrscale = counter->rscale << 1;
    int nmask = nscale - 1;
    long *nallocated = (long *)malloc(nscale * sizeof(long));
    memset(nallocated, NG, nscale * sizeof(long));
    long *nkeys = (long *)malloc(nscale * sizeof(long));
    for (int i = next(counter, 0); i < counter->scale; i = next(counter, i + 1)) {
        long y = counter->keys[i];
        int pos = h(y) & nmask;
        while (nallocated[pos] != NG) pos = (pos + 1) & nmask;
        nkeys[pos] = y;
        nallocated[pos] = counter->allocated[i];
    }
    {
        int pos = h(x) & nmask;
        while (nallocated[pos] != NG) pos = (pos + 1) & nmask;
        nkeys[pos] = x;
        nallocated[pos] = v;
    }
    free(counter->allocated);
    free(counter->keys);
    counter->allocated = nallocated;
    counter->keys = nkeys;
    counter->scale = nscale;
    counter->rscale = nrscale;
    counter->mask = nmask;
}

int next(LongHashCounterL *counter, int itr) {
    while (itr < counter->scale && counter->allocated[itr] == NG) itr++;
    return itr;
}

int h(long x) {
    x ^= x >> 33;
    x *= 0xff51afd7ed558ccdL;
    x ^= x >> 33;
    x *= 0xc4ceb9fe1a85ec53L;
    x ^= x >> 33;
    return (int)x;
}

void initMeisselLehmer2(MeisselLehmer2 *ml, long n) {
    ml->M = 8;
    ml->B = 100;
    ml->picache = (LongHashCounterL){0};
    ml->phicache = (LongHashCounterL){0};
    initLongHashCounter(&ml->picache);
    initLongHashCounter(&ml->phicache);
    int s = (int)sqrt(n) * ml->B;
    ml->cachelimit = s;
    ml->primes = sieveEratosthenes(s);
    ml->xcums = (int *)calloc((s >> 6) + 1, sizeof(int));
    ml->isp = (long *)calloc((s >> 6) + 1, sizeof(long));
    for (int i = 0; i < s; i++) {
        ml->isp[ml->primes[i] >> 6] |= 1L << ml->primes[i];
    }
    for (int i = 0; i < (s >> 6); i++) {
        ml->xcums[i + 1] = ml->xcums[i] + __builtin_popcountll(ml->isp[i]);
    }

    ml->cumps = (int **)malloc(ml->M * sizeof(int *));
    int len = 1;
    for (int i = 0; i < ml->M; i++) {
        len *= ml->FP[i];
        ml->cumps[i] = (int *)calloc(len + 1, sizeof(int));
        for (int j = 0; j < len; j++) {
            ml->cumps[i][j + 1] = ml->cumps[i][j] + (j % ml->FP[i] == 0 ? 1 : 0);
        }
        ml->FP[i] = len;
    }
}

long pi(MeisselLehmer2 *ml, long x) {
    if (x <= ml->cachelimit) {
        int ix = (int)x;
        return ml->xcums[ix >> 6] + __builtin_popcountll(ml->isp[ix >> 6] << ~ix);
    }
    if (containsKey(&ml->picache, x)) return get(&ml->picache, x);

    int A = (int)pi(ml, sqrt(sqrt(x)));
    long ret = A + phi(ml, x, A) - P2(ml, x, A) - P3(ml, x, A) - 1;
    put(&ml->picache, x, ret);
    return ret;
}

long phi(MeisselLehmer2 *ml, long x, int A) {
    if (A > 0 && A - 1 < ml->M) {
        return ml->cumps[A - 1][ml->FP[A - 1]] * (x / ml->FP[A - 1]) + ml->cumps[A - 1][(int)(x % ml->FP[A - 1] + 1)];
    }
    if (A > 0 && x <= (long)ml->primes[A - 1] * ml->primes[A - 1]) {
        return pi(ml, x) - A + 1;
    }
    long code = x << 13 | A;
    if (containsKey(&ml->phicache, code)) return get(&ml->phicache, code);

    long ret = x;
    for (int i = A - 1; i >= 0; i--) ret -= phi(ml, x / ml->primes[i], i);

    put(&ml->phicache, code, ret);
    return ret;
}

long P2(MeisselLehmer2 *ml, long x, int A) {
    int B = (int)pi(ml, sqrt(x));
    long ret = 0;
    for (int i = A; i < B; i++) {
        ret += pi(ml, x / ml->primes[i]);
    }
    ret -= (long)(B - A) * (B + A - 1) / 2;
    return ret;
}

long P3(MeisselLehmer2 *ml, long x, int A) {
    int C = (int)pi(ml, cbrt(x));
    long ret = 0;
    for (int i = A; i < C; i++) {
        long xi = x / ml->primes[i];
        int B = (int)pi(ml, sqrt(xi));
        for (int j = i; j < B; j++) {
            ret += pi(ml, xi / ml->primes[j]) - j;
        }
    }
    return ret;
}

void freeLongHashCounter(LongHashCounterL *counter) {
    free(counter->allocated);
    free(counter->keys);
}

void freeMeisselLehmer2(MeisselLehmer2 *ml) {
    free(ml->primes);
    free(ml->xcums);
    free(ml->isp);
    for (int i = 0; i < ml->M; i++) {
        free(ml->cumps[i]);
    }
    free(ml->cumps);
    freeLongHashCounter(&ml->picache);
    freeLongHashCounter(&ml->phicache);
}
