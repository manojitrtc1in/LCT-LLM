#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define INPUT "100000000000"

typedef struct {
    int* keys;
    long* allocated;
    int scale;
    int rscale;
    int mask;
    int size;
} id4;

typedef struct {
    int* primes;
    int* xcums;
    long* isp;
    int cachelimit;
    id4* picache;
    id4* id1;
    bool cachePhi;
    int** cumps;
    int* FP;
    int M;
    int B;
} id7;

int* id0(int n) {
    if (n <= 32) {
        int* primes = (int*)malloc(11 * sizeof(int));
        primes[0] = 2;
        primes[1] = 3;
        primes[2] = 5;
        primes[3] = 7;
        primes[4] = 11;
        primes[5] = 13;
        primes[6] = 17;
        primes[7] = 19;
        primes[8] = 23;
        primes[9] = 29;
        primes[10] = 31;
        return primes;
    }

    int u = n + 32;
    double lu = log(u);
    int* ret = (int*)malloc((int)(u / lu + u / lu / lu * 1.5) * sizeof(int));
    ret[0] = 2;
    int pos = 1;

    int* isnp = (int*)malloc(((n + 1) / 32 / 2 + 1) * sizeof(int));
    int sup = (n + 1) / 32 / 2 + 1;

    int id3[10] = { 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
    for (int k = 0; k < 10; k++) {
        int tp = id3[k];
        ret[pos++] = tp;
        int* ptn = (int*)malloc(tp * sizeof(int));
        for (int i = (tp - 3) / 2; i < tp << 5; i += tp)
            ptn[i >> 5] |= 1 << (i & 31);
        for (int j = 0; j < sup; j += tp) {
            for (int i = 0; i < tp && i + j < sup; i++) {
                isnp[j + i] |= ptn[i];
            }
        }
        free(ptn);
    }

    int magic[32] = { 0, 1, 23, 2, 29, 24, 19, 3, 30, 27, 25, 11, 20, 8, 4, 13, 31, 22, 28, 18, 26, 10, 7, 12, 21, 17, 9, 6, 16, 5, 15, 14 };
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

id7* create_id7(long n) {
    id7* obj = (id7*)malloc(sizeof(id7));
    obj->primes = id0(400000);

    int s = (int)sqrt(n) * obj->B;

    obj->cachelimit = s;
    obj->xcums = (int*)malloc(((s >> 6) + 1) * sizeof(int));
    obj->isp = (long*)malloc(((s >> 6) + 1) * sizeof(long));
    for (int i = 0; i < ((s >> 6) + 1); i++) {
        obj->isp[i] = 0;
    }
    for (int i = 0; i < s; i++) {
        obj->xcums[i + 1] = obj->xcums[i] + __builtin_popcountll(obj->isp[i]);
    }

    obj->cumps = (int**)malloc(obj->M * sizeof(int*));
    bool* b = (bool*)malloc(sizeof(bool));
    *b = true;
    int len = 1;
    for (int i = 0; i < obj->M; i++) {
        len *= obj->FP[i];
        bool* c = (bool*)malloc(len * sizeof(bool));
        for (int j = 0; j < obj->FP[i]; j++) {
            memcpy(&c[j * len / obj->FP[i]], b, len / obj->FP[i] * sizeof(bool));
        }
        for (int k = 0; k < len; k += obj->FP[i]) {
            c[k] = false;
        }
        obj->cumps[i] = (int*)malloc((len + 1) * sizeof(int));
        for (int j = 0; j < len; j++) {
            obj->cumps[i][j + 1] = obj->cumps[i][j] + (c[j] ? 1 : 0);
        }
        obj->FP[i] = len;
        free(b);
        b = c;
    }
    free(b);

    return obj;
}

long id7_pi(id7* obj, long x) {
    if (x <= obj->cachelimit) {
        int ix = (int)x;
        return obj->xcums[ix >> 6] + __builtin_popcountll(obj->isp[ix >> 6] << ~ix);
    }
    if (obj->picache != NULL && id4_containsKey(obj->picache, x)) {
        return id4_get(obj->picache, x);
    }

    int A = (int)id7_pi(obj, sqrt(sqrt(x)));
    long ret = A + id7_phi(obj, x, A) - id7_P2(obj, x, A) - id7_P3(obj, x, A) - 1;
    if (obj->picache != NULL) {
        id4_put(obj->picache, x, ret);
    }
    return ret;
}

long id7_phi(id7* obj, long x, int A) {
    if (A > 0 && A - 1 < obj->M) {
        return obj->cumps[A - 1][obj->FP[A - 1]] * (x / obj->FP[A - 1]) + obj->cumps[A - 1][(int)(x % obj->FP[A - 1] + 1)];
    }
    if (A > 0 && x <= (long)obj->primes[A - 1] * obj->primes[A - 1]) {
        return id7_pi(obj, x) - A + 1;
    }

    long ret = x;
    for (int i = A - 1; i >= 0; i--) {
        ret -= id7_phi(obj, x / obj->primes[i], i);
    }

    return ret;
}

long id7_P2(id7* obj, long x, int A) {
    int B = (int)id7_pi(obj, sqrt(x));
    long ret = 0;
    for (int i = A; i < B; i++) {
        ret += id7_pi(obj, x / obj->primes[i]);
    }
    ret -= (long)(B - A) * (B + A - 1) / 2;
    return ret;
}

long id7_P3(id7* obj, long x, int A) {
    int C = (int)id7_pi(obj, id6(x));
    long ret = 0;
    for (int i = A; i < C; i++) {
        long xi = x / obj->primes[i];
        int B = (int)id7_pi(obj, sqrt(xi));
        for (int j = i; j < B; j++) {
            ret += id7_pi(obj, xi / obj->primes[j]) - j;
        }
    }
    return ret;
}

id4* create_id4() {
    id4* obj = (id4*)malloc(sizeof(id4));
    obj->keys = (int*)malloc(1 * sizeof(int));
    obj->allocated = (long*)malloc(1 * sizeof(long));
    obj->scale = 1 << 2;
    obj->rscale = 1 << 1;
    obj->mask = obj->scale - 1;
    obj->size = 0;
    return obj;
}

bool id4_containsKey(id4* obj, long x) {
    int pos = id4_h(x) & obj->mask;
    while (obj->allocated[pos] != 0xFFFFFFFFFFFFFFFF) {
        if (x == obj->keys[pos]) {
            return true;
        }
        pos = (pos + 1) & obj->mask;
    }
    return false;
}

long id4_get(id4* obj, long x) {
    int pos = id4_h(x) & obj->mask;
    while (obj->allocated[pos] != 0xFFFFFFFFFFFFFFFF) {
        if (x == obj->keys[pos]) {
            return obj->allocated[pos];
        }
        pos = (pos + 1) & obj->mask;
    }
    return 0xFFFFFFFFFFFFFFFF;
}

long id4_put(id4* obj, long x, long v) {
    int pos = id4_h(x) & obj->mask;
    while (obj->allocated[pos] != 0xFFFFFFFFFFFFFFFF) {
        if (x == obj->keys[pos]) {
            long oldval = obj->allocated[pos];
            obj->allocated[pos] = v;
            return oldval;
        }
        pos = (pos + 1) & obj->mask;
    }
    if (obj->size == obj->rscale) {
        id4_id5(obj, x, v);
    }
    else {
        obj->keys[pos] = x;
        obj->allocated[pos] = v;
    }
    obj->size++;
    return 0;
}

long id4_inc(id4* obj, long x, long v) {
    int pos = id4_h(x) & obj->mask;
    while (obj->allocated[pos] != 0xFFFFFFFFFFFFFFFF) {
        if (x == obj->keys[pos]) {
            obj->allocated[pos] += v;
            return obj->allocated[pos];
        }
        pos = (pos + 1) & obj->mask;
    }
    if (obj->size == obj->rscale) {
        id4_id5(obj, x, v);
    }
    else {
        obj->keys[pos] = x;
        obj->allocated[pos] = v;
    }
    obj->size++;
    return v;
}

bool id4_remove(id4* obj, long x) {
    int pos = id4_h(x) & obj->mask;
    while (obj->allocated[pos] != 0xFFFFFFFFFFFFFFFF) {
        if (x == obj->keys[pos]) {
            obj->size--;

            int last = pos;
            pos = (pos + 1) & obj->mask;
            while (obj->allocated[pos] != 0xFFFFFFFFFFFFFFFF) {
                int lh = id4_h(obj->keys[pos]) & obj->mask;

                if ((lh <= last && last < pos) ||
                    (pos < lh && lh <= last) ||
                    (last < pos && pos < lh)) {
                    obj->keys[last] = obj->keys[pos];
                    obj->allocated[last] = obj->allocated[pos];
                    last = pos;
                }
                pos = (pos + 1) & obj->mask;
            }
            obj->keys[last] = 0;
            obj->allocated[last] = 0xFFFFFFFFFFFFFFFF;

            return true;
        }
        pos = (pos + 1) & obj->mask;
    }
    return false;
}

int id4_next(id4* obj, int itr) {
    while (itr < obj->scale && obj->allocated[itr] == 0xFFFFFFFFFFFFFFFF) {
        itr++;
    }
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

void solve() {
    long n = nl();
    long ans = 0;
    id7* ml = create_id7(n / 2);
    for (int i = 0; i < sizeof(ml->primes) / sizeof(ml->primes[0]); i++) {
        long plus = id7_pi(ml, n / ml->primes[i]) - (i + 1);
        if (plus <= 0)
            break;
        ans += plus;
    }

    for (int j = 0; j < sizeof(ml->primes) / sizeof(ml->primes[0]); j++) {
        int p = ml->primes[j];
        if ((long)p * p * p <= n) {
            ans++;
        }
        else {
            break;
        }
    }
    printf("%ld\n", ans);
}

int main() {
    solve();
    return 0;
}
