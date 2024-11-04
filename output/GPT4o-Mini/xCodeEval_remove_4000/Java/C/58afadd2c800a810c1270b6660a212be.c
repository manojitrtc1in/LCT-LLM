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
    int *FP;
    int M;
    int B;
} id7;

int *id0(int n);
void id4_init(id4 *cache);
int id4_containsKey(id4 *cache, long x);
long id4_get(id4 *cache, long x);
long id4_put(id4 *cache, long x, long v);
long id4_inc(id4 *cache, long x, long v);
int id4_remove(id4 *cache, long x);
void id4_resize(id4 *cache, long x, long v);
int id4_next(id4 *cache, int itr);
int id4_h(long x);
void id7_init(id7 *ml, long n);
long id7_pi(id7 *ml, long x);
long phi(long x, int A, id7 *ml);
long P2(long x, int A, id7 *ml);
long P3(long x, int A, id7 *ml);
long sqrt_long(long n);
long id6(long n);
void solve();
long nl();
void run();

int *primes;

int *id0(int n) {
    if (n <= 32) {
        int *primes = (int *)malloc(11 * sizeof(int));
        int primes_arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        memcpy(primes, primes_arr, sizeof(primes_arr));
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

    int id3[] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    for (int i = 0; i < 10; i++) {
        int tp = id3[i];
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

void id4_init(id4 *cache) {
    cache->scale = 1 << 2;
    cache->rscale = 1 << 1;
    cache->mask = cache->scale - 1;
    cache->size = 0;
    cache->allocated = (long *)malloc(cache->scale * sizeof(long));
    memset(cache->allocated, NG, cache->scale * sizeof(long));
    cache->keys = (long *)malloc(cache->scale * sizeof(long));
}

int id4_containsKey(id4 *cache, long x) {
    int pos = id4_h(x) & cache->mask;
    while (cache->allocated[pos] != NG) {
        if (x == cache->keys[pos]) return 1;
        pos = (pos + 1) & cache->mask;
    }
    return 0;
}

long id4_get(id4 *cache, long x) {
    int pos = id4_h(x) & cache->mask;
    while (cache->allocated[pos] != NG) {
        if (x == cache->keys[pos]) return cache->allocated[pos];
        pos = (pos + 1) & cache->mask;
    }
    return NG;
}

long id4_put(id4 *cache, long x, long v) {
    int pos = id4_h(x) & cache->mask;
    while (cache->allocated[pos] != NG) {
        if (x == cache->keys[pos]) {
            long oldval = cache->allocated[pos];
            cache->allocated[pos] = v;
            return oldval;
        }
        pos = (pos + 1) & cache->mask;
    }
    if (cache->size == cache->rscale) {
        id4_resize(cache, x, v);
    } else {
        cache->keys[pos] = x;
        cache->allocated[pos] = v;
    }
    cache->size++;
    return 0;
}

long id4_inc(id4 *cache, long x, long v) {
    int pos = id4_h(x) & cache->mask;
    while (cache->allocated[pos] != NG) {
        if (x == cache->keys[pos]) {
            cache->allocated[pos] += v;
            return cache->allocated[pos];
        }
        pos = (pos + 1) & cache->mask;
    }
    if (cache->size == cache->rscale) {
        id4_resize(cache, x, v);
    } else {
        cache->keys[pos] = x;
        cache->allocated[pos] = v;
    }
    cache->size++;
    return v;
}

int id4_remove(id4 *cache, long x) {
    int pos = id4_h(x) & cache->mask;
    while (cache->allocated[pos] != NG) {
        if (x == cache->keys[pos]) {
            cache->size--;
            int last = pos;
            pos = (pos + 1) & cache->mask;
            while (cache->allocated[pos] != NG) {
                int lh = id4_h(cache->keys[pos]) & cache->mask;
                if ((lh <= last && last < pos) || (pos < lh && lh <= last) || (last < pos && pos < lh)) {
                    cache->keys[last] = cache->keys[pos];
                    cache->allocated[last] = cache->allocated[pos];
                    last = pos;
                }
                pos = (pos + 1) & cache->mask;
            }
            cache->keys[last] = 0;
            cache->allocated[last] = NG;
            return 1;
        }
        pos = (pos + 1) & cache->mask;
    }
    return 0;
}

void id4_resize(id4 *cache, long x, long v) {
    int nscale = cache->scale << 1;
    int nrscale = cache->rscale << 1;
    int nmask = nscale - 1;
    long *nallocated = (long *)malloc(nscale * sizeof(long));
    memset(nallocated, NG, nscale * sizeof(long));
    long *nkeys = (long *)malloc(nscale * sizeof(long));
    for (int i = id4_next(cache, 0); i < cache->scale; i = id4_next(cache, i + 1)) {
        long y = cache->keys[i];
        int pos = id4_h(y) & nmask;
        while (nallocated[pos] != NG) pos = (pos + 1) & nmask;
        nkeys[pos] = y;
        nallocated[pos] = cache->allocated[i];
    }
    {
        int pos = id4_h(x) & nmask;
        while (nallocated[pos] != NG) pos = (pos + 1) & nmask;
        nkeys[pos] = x;
        nallocated[pos] = v;
    }
    free(cache->allocated);
    free(cache->keys);
    cache->allocated = nallocated;
    cache->keys = nkeys;
    cache->scale = nscale;
    cache->rscale = nrscale;
    cache->mask = nmask;
}

int id4_next(id4 *cache, int itr) {
    while (itr < cache->scale && cache->allocated[itr] == NG) itr++;
    return itr;
}

int id4_h(long x) {
    x ^= x >> 33;
    x *= 0xff51afd7ed558ccdL;
    x ^= x >> 33;
    x *= 0xc4ceb9fe1a85ec53L;
    x ^= x >> 33;
    return (int)x;
}

void id7_init(id7 *ml, long n) {
    ml->B = 100;
    ml->M = 8; // Length of FP
    ml->FP = (int *)malloc(ml->M * sizeof(int));
    int FP_arr[] = {2, 3, 5, 7, 11, 13, 17, 19};
    memcpy(ml->FP, FP_arr, sizeof(FP_arr));
    ml->picache = (id4){0};
    id4_init(&ml->picache);
    ml->id1 = (id4){0};
    id4_init(&ml->id1);
    int s = (int)sqrt(n) * ml->B;
    ml->cachelimit = s;
    ml->primes = id0(s);
    ml->xcums = (int *)calloc((s >> 6) + 1, sizeof(int));
    ml->isp = (long *)calloc((s >> 6) + 1, sizeof(long));
    for (int i = 0; i < sizeof(ml->primes) / sizeof(int); i++) {
        ml->isp[ml->primes[i] >> 6] |= 1L << ml->primes[i];
    }
    for (int i = 0; i < (s >> 6); i++) {
        ml->xcums[i + 1] = ml->xcums[i] + __builtin_popcountll(ml->isp[i]);
    }
    ml->cumps = (int **)malloc(ml->M * sizeof(int *));
    int len = 1;
    for (int i = 0; i < ml->M; i++) {
        len *= ml->FP[i];
        ml->cumps[i] = (int *)malloc((len + 1) * sizeof(int));
        int *c = (int *)malloc(len * sizeof(int));
        memset(c, 1, len * sizeof(int));
        for (int j = 0; j < ml->FP[i]; j++) {
            for (int k = 0; k < len; k += ml->FP[i]) {
                c[k] = 0;
            }
        }
        for (int j = 0; j < len; j++) {
            ml->cumps[i][j + 1] = ml->cumps[i][j] + (c[j] ? 1 : 0);
        }
        ml->FP[i] = len;
        free(c);
    }
}

long sqrt_long(long n) {
    long i = fmax(0, (long)sqrt(n) - 2);
    while (i * i <= n) i++;
    return i - 1;
}

long id6(long n) {
    long i = fmax(0, (long)sqrt(n) - 2);
    while (i * i * i <= n) i++;
    return i - 1;
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
    id7 ml;
    id7_init(&ml, n / 2);
    for (int i = 0; i < sizeof(primes) / sizeof(int); i++) {
        long plus = id7_pi(&ml, n / primes[i]) - (i + 1);
        if (plus <= 0) break;
        ans += plus;
    }
    for (int i = 0; i < sizeof(primes) / sizeof(int); i++) {
        if ((long)primes[i] * primes[i] * primes[i] <= n) {
            ans++;
        } else {
            break;
        }
    }
    printf("%ld\n", ans);
}

int main() {
    primes = id0(400000);
    run();
    free(primes);
    return 0;
}

void run() {
    long s = clock();
    solve();
    printf("%ldms\n", (clock() - s) * 1000 / CLOCKS_PER_SEC);
}
