#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 998244353
#define MAX_N 5000

typedef struct {
    int *data;
    int size;
    int cap;
} IntegerList;

typedef struct {
    int m;
} Modular;

typedef struct {
    int *fact;
    int *inv;
    Modular mod;
} Factorial;

typedef struct {
    int *inv;
} InverseNumber;

typedef struct {
    int *first;
    int *second;
    Modular mod;
} CachedPow;

typedef struct {
    int n;
    int m;
    Modular mod;
    IntegerList id8;
    int fft;
} Id1;

typedef struct {
    int *data;
    int size;
    int cap;
} FastInput;

typedef struct {
    char *cache;
    int cacheSize;
    FILE *os;
} FastOutput;

void initIntegerList(IntegerList *list, int cap) {
    list->cap = cap;
    list->size = 0;
    list->data = (int *)malloc(cap * sizeof(int));
}

void addIntegerList(IntegerList *list, int x) {
    if (list->size >= list->cap) {
        list->cap *= 2;
        list->data = (int *)realloc(list->data, list->cap * sizeof(int));
    }
    list->data[list->size++] = x;
}

void clearIntegerList(IntegerList *list) {
    list->size = 0;
}

void initModular(Modular *mod, int m) {
    mod->m = m;
}

int valueOf(Modular *mod, int x) {
    x %= mod->m;
    if (x < 0) {
        x += mod->m;
    }
    return x;
}

int mul(Modular *mod, int x, int y) {
    return valueOf(mod, (long long)x * y);
}

int plus(Modular *mod, int x, int y) {
    return valueOf(mod, x + y);
}

void initFactorial(Factorial *fact, int limit, Modular mod) {
    fact->mod = mod;
    fact->fact = (int *)malloc((limit + 1) * sizeof(int));
    fact->inv = (int *)malloc((limit + 1) * sizeof(int));
    fact->fact[0] = fact->inv[0] = 1;
    for (int i = 1; i <= limit; i++) {
        fact->fact[i] = mul(&mod, fact->fact[i - 1], i);
        fact->inv[i] = mul(&mod, fact->inv[i - 1], fact->inv[i]);
    }
}

void initInverseNumber(InverseNumber *in, int limit, Modular mod) {
    in->inv = (int *)malloc((limit + 1) * sizeof(int));
    in->inv[1] = 1;
    for (int i = 2; i <= limit; i++) {
        int k = mod.m / i;
        int r = mod.m % i;
        in->inv[i] = mul(&mod, -k, in->inv[r]);
    }
}

void initCachedPow(CachedPow *cp, int x, int maxExp, Modular mod) {
    cp->mod = mod;
    cp->first = (int *)malloc((int)sqrt(maxExp) * sizeof(int));
    cp->second = (int *)malloc((maxExp / (int)sqrt(maxExp) + 1) * sizeof(int));
    cp->first[0] = 1;
    for (int i = 1; i < (int)sqrt(maxExp); i++) {
        cp->first[i] = mul(&mod, x, cp->first[i - 1]);
    }
    cp->second[0] = 1;
    int step = mul(&mod, x, cp->first[(int)sqrt(maxExp) - 1]);
    for (int i = 1; i < (maxExp / (int)sqrt(maxExp) + 1); i++) {
        cp->second[i] = mul(&mod, cp->second[i - 1], step);
    }
}

int powCached(CachedPow *cp, int exp) {
    return mul(&cp->mod, cp->first[exp % (int)sqrt(cp->mod.m)], cp->second[exp / (int)sqrt(cp->mod.m)]);
}

void initFastInput(FastInput *fi, FILE *is) {
    fi->data = (int *)malloc(1 << 13);
    fi->size = 0;
    fi->cap = 1 << 13;
    fi->os = is;
}

void initFastOutput(FastOutput *fo, FILE *os) {
    fo->cache = (char *)malloc(10 << 20);
    fo->cacheSize = 0;
    fo->os = os;
}

void printlnFastOutput(FastOutput *fo, int c) {
    fo->cache[fo->cacheSize++] = c;
    fo->cache[fo->cacheSize++] = '\n';
}

void flushFastOutput(FastOutput *fo) {
    fwrite(fo->cache, sizeof(char), fo->cacheSize, fo->os);
    fo->cacheSize = 0;
}

void closeFastOutput(FastOutput *fo) {
    flushFastOutput(fo);
    fclose(fo->os);
}

void solve( int n, int m, int k, FastOutput *out) {
    Modular mod;
    initModular(&mod, MOD);
    Factorial fact;
    initFactorial(&fact, MAX_N, mod);
    CachedPow cp;
    initCachedPow(&cp, m, k, mod);
    IntegerList xk;
    initIntegerList(&xk, k + 1);
    for (int i = 0; i <= k; i++) {
        addIntegerList(&xk, powCached(&cp, i));
    }

    int ans = 0;
    Id1 bc;
    // Initialize bc here (not shown for brevity)
    
    for (int t = 0; t <= k; t++) {
        int p1 = bc.id8.data[t];
        int p2 = 0;
        for (int i = 0; i <= t; i++) {
            int contrib = fact.fact[t] * fact.inv[i] * fact.inv[t - i]; // Composite calculation
            contrib = mul(&mod, contrib, xk.data[t - i]);
            if (i % 2 == 1) {
                contrib = -contrib;
            }
            p2 = plus(&mod, p2, contrib);
        }
        int p3 = powCached(&cp, t);
        int contrib = mul(&mod, p1, p2);
        contrib = mul(&mod, contrib, p3);
        ans = plus(&mod, ans, contrib);
    }

    printlnFastOutput(out, ans);
}

int main() {
    FastInput in;
    initFastInput(&in, stdin);
    FastOutput out;
    initFastOutput(&out, stdout);

    int n, m, k;
    fscanf(in.os, "%d %d %d", &n, &m, &k);
    solve(n, m, k, &out);

    closeFastOutput(&out);
    return 0;
}
