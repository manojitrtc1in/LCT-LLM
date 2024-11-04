#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 400000

int primes[MAX_SIZE];

int* id0(int n) {
    if (n <= 32) {
        int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
        int* result = (int*)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) {
            result[i] = primes[i];
        }
        return result;
    }

    int u = n + 32;
    double lu = log(u);
    int* ret = (int*)malloc(sizeof(int) * ((int)(u / lu + u / lu / lu * 1.5)));
    ret[0] = 2;
    int pos = 1;

    int* isnp = (int*)malloc(sizeof(int) * ((n + 1) / 32 / 2 + 1));
    int sup = (n + 1) / 32 / 2 + 1;

    int id3[] = { 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
    for (int k = 0; k < sizeof(id3) / sizeof(id3[0]); k++) {
        int tp = id3[k];
        ret[pos++] = tp;
        int* ptn = (int*)malloc(sizeof(int) * tp);
        for (int i = (tp - 3) / 2; i < tp << 5; i += tp) {
            ptn[i >> 5] |= 1 << (i & 31);
        }
        for (int j = 0; j < sup; j += tp) {
            for (int i = 0; i < tp && i + j < sup; i++) {
                isnp[j + i] |= ptn[i];
            }
        }
        free(ptn);
    }

    int magic[] = { 0, 1, 23, 2, 29, 24, 19, 3, 30, 27, 25, 11, 20, 8, 4, 13, 31, 22, 28, 18, 26, 10, 7, 12, 21, 17, 9, 6, 16, 5, 15, 14 };
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
    return ret;
}

typedef struct {
    int* keys;
    long* allocated;
    int scale;
    int rscale;
    int mask;
    int size;
} id4;

id4* id1;

id4* id4_new() {
    id4* map = (id4*)malloc(sizeof(id4));
    map->keys = (int*)malloc(sizeof(int) * 16);
    map->allocated = (long*)malloc(sizeof(long) * 16);
    map->scale = 16;
    map->rscale = 2;
    map->mask = 15;
    map->size = 0;
    return map;
}

void id4_put(id4* map, long x, long v) {
    int pos = (x & 0x7fffffff) % map->scale;
    while (map->allocated[pos] != -1) {
        if (x == map->keys[pos]) {
            map->allocated[pos] = v;
            return;
        }
        pos = (pos + 1) % map->scale;
    }
    if (map->size == map->rscale) {
        int nscale = map->scale << 1;
        int nrscale = map->rscale << 1;
        int nmask = nscale - 1;
        int* nkeys = (int*)malloc(sizeof(int) * nscale);
        long* nallocated = (long*)malloc(sizeof(long) * nscale);
        for (int i = 0; i < map->scale; i++) {
            if (map->allocated[i] != -1) {
                int npos = (map->keys[i] & 0x7fffffff) % nscale;
                while (nallocated[npos] != -1) {
                    npos = (npos + 1) % nscale;
                }
                nkeys[npos] = map->keys[i];
                nallocated[npos] = map->allocated[i];
            }
        }
        free(map->keys);
        free(map->allocated);
        map->keys = nkeys;
        map->allocated = nallocated;
        map->scale = nscale;
        map->rscale = nrscale;
        map->mask = nmask;
    }
    map->keys[pos] = x;
    map->allocated[pos] = v;
    map->size++;
}

long id4_get(id4* map, long x) {
    int pos = (x & 0x7fffffff) % map->scale;
    while (map->allocated[pos] != -1) {
        if (x == map->keys[pos]) {
            return map->allocated[pos];
        }
        pos = (pos + 1) % map->scale;
    }
    return -1;
}

bool id4_containsKey(id4* map, long x) {
    int pos = (x & 0x7fffffff) % map->scale;
    while (map->allocated[pos] != -1) {
        if (x == map->keys[pos]) {
            return true;
        }
        pos = (pos + 1) % map->scale;
    }
    return false;
}

void id4_free(id4* map) {
    free(map->keys);
    free(map->allocated);
    free(map);
}

typedef struct {
    int** cumps;
    int M;
    int B;
} id7;

id7* id7_new(long n) {
    id7* ml = (id7*)malloc(sizeof(id7));
    ml->M = 8;
    ml->B = 100;
    ml->cumps = (int**)malloc(sizeof(int*) * ml->M);
    bool* b = (bool*)malloc(sizeof(bool));
    *b = true;
    int len = 1;
    for (int i = 0; i < ml->M; i++) {
        len *= ml->B;
        bool* c = (bool*)malloc(sizeof(bool) * len);
        for (int j = 0; j < ml->B; j++) {
            for (int k = 0; k < len; k += ml->B) {
                c[j * len + k] = *b;
            }
        }
        for (int k = 0; k < len; k += ml->B) {
            c[k] = false;
        }
        ml->cumps[i] = (int*)malloc(sizeof(int) * (len + 1));
        for (int j = 0; j < len; j++) {
            ml->cumps[i][j + 1] = ml->cumps[i][j] + (c[j] ? 1 : 0);
        }
        ml->B = len;
        b = c;
    }
    return ml;
}

long id7_pi(id7* ml, long x) {
    if (x <= ml->B) {
        return ml->cumps[ml->M - 1][ml->B] * (x / ml->B) + ml->cumps[ml->M - 1][x % ml->B + 1];
    }
    if (id4_containsKey(id1, x)) {
        return id4_get(id1, x);
    }
    long A = id7_pi(ml, (long)sqrt(sqrt(x)));
    long ret = A + phi(x, A) - P2(x, A) - P3(x, A) - 1;
    id4_put(id1, x, ret);
    return ret;
}

long phi(long x, int A) {
    if (A > 0 && A - 1 < id7->M) {
        return id7->cumps[A - 1][id7->B] * (x / id7->B) + id7->cumps[A - 1][x % id7->B + 1];
    }
    if (A > 0 && x <= (long)primes[A - 1] * primes[A - 1]) {
        return id7_pi(x) - A + 1;
    }
    long code = x << 13 | A;
    if (id4_containsKey(id1, code)) {
        return id4_get(id1, code);
    }
    long ret = x;
    for (int i = A - 1; i >= 0; i--) {
        ret -= phi(x / primes[i], i);
    }
    id4_put(id1, code, ret);
    return ret;
}

long P2(long x, int A) {
    int B = id7_pi(sqrt(x));
    long ret = 0;
    for (int i = A; i < B; i++) {
        ret += id7_pi(x / primes[i]);
    }
    ret -= (long)(B - A) * (B + A - 1) / 2;
    return ret;
}

long P3(long x, int A) {
    int C = id7_pi(id6(x));
    long ret = 0;
    for (int i = A; i < C; i++) {
        long xi = x / primes[i];
        int B = id7_pi(sqrt(xi));
        for (int j = i; j < B; j++) {
            ret += id7_pi(xi / primes[j]) - j;
        }
    }
    return ret;
}

long id6(long n) {
    long i = fmax(0, (long)sqrt(n) - 2);
    while (i * i * i <= n) {
        i++;
    }
    return i - 1;
}

void solve() {
    long n;
    scanf("%ld", &n);
    long ans = 0;
    id7* ml = id7_new(n / 2);
    for (int i = 0; i < sizeof(primes) / sizeof(primes[0]); i++) {
        long plus = id7_pi(ml, n / primes[i]) - (i + 1);
        if (plus <= 0) {
            break;
        }
        ans += plus;
    }
    for (int i = 0; i < sizeof(primes) / sizeof(primes[0]); i++) {
        if ((long)primes[i] * primes[i] * primes[i] <= n) {
            ans++;
        } else {
            break;
        }
    }
    printf("%ld\n", ans);
}

int main() {
    int n = sizeof(primes) / sizeof(primes[0]);
    primes = id0(n);
    id1 = id4_new();
    solve();
    id4_free(id1);
    free(primes);
    return 0;
}
