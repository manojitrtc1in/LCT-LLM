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
    Factorial factorial;
    Modular mod;
} Composite;

typedef struct {
    int *first;
    int *second;
    Modular mod;
    int powMod;
} CachedPow;

typedef struct {
    int *data;
    int size;
    int cap;
} FastInput;

typedef struct {
    int *data;
    int size;
    int cap;
} FastOutput;

void initIntegerList(IntegerList *list, int cap) {
    list->cap = cap;
    list->size = 0;
    list->data = (int *)malloc(cap * sizeof(int));
}

void addToIntegerList(IntegerList *list, int x) {
    if (list->size >= list->cap) {
        list->cap *= 2;
        list->data = (int *)realloc(list->data, list->cap * sizeof(int));
    }
    list->data[list->size++] = x;
}

void freeIntegerList(IntegerList *list) {
    free(list->data);
}

void initModular(Modular *mod, int m) {
    mod->m = m;
}

int modValue(Modular *mod, int x) {
    x %= mod->m;
    if (x < 0) x += mod->m;
    return x;
}

int modMul(Modular *mod, int x, int y) {
    return modValue(mod, (long long)x * y);
}

int modPlus(Modular *mod, int x, int y) {
    return modValue(mod, x + y);
}

void initFactorial(Factorial *fact, int limit, Modular mod) {
    fact->mod = mod;
    fact->fact = (int *)malloc((limit + 1) * sizeof(int));
    fact->inv = (int *)malloc((limit + 1) * sizeof(int));
    fact->fact[0] = fact->inv[0] = 1;
    for (int i = 1; i <= limit; i++) {
        fact->fact[i] = modMul(&mod, fact->fact[i - 1], i);
        // Inverse calculation can be added here
    }
}

void freeFactorial(Factorial *fact) {
    free(fact->fact);
    free(fact->inv);
}

void initComposite(Composite *comp, int limit, Modular mod) {
    initFactorial(&comp->factorial, limit, mod);
    comp->mod = mod;
}

int composite(Composite *comp, int m, int n) {
    if (n > m) return 0;
    return modMul(&comp->mod, modMul(&comp->mod, comp->factorial.fact[m], comp->factorial.inv[n]), comp->factorial.inv[m - n]);
}

void initCachedPow(CachedPow *cp, int x, int maxExp, Modular mod) {
    cp->mod = mod;
    cp->first = (int *)malloc((int)sqrt(maxExp) * sizeof(int));
    cp->second = (int *)malloc((maxExp / (int)sqrt(maxExp) + 1) * sizeof(int));
    cp->first[0] = 1;
    for (int i = 1; i < (int)sqrt(maxExp); i++) {
        cp->first[i] = modMul(&mod, x, cp->first[i - 1]);
    }
    cp->second[0] = 1;
    int step = modMul(&mod, x, cp->first[(int)sqrt(maxExp) - 1]);
    for (int i = 1; i < maxExp / (int)sqrt(maxExp) + 1; i++) {
        cp->second[i] = modMul(&mod, cp->second[i - 1], step);
    }
}

int powCached(CachedPow *cp, int exp) {
    return modMul(&cp->mod, cp->first[exp % (int)sqrt(exp)], cp->second[exp / (int)sqrt(exp)]);
}

void freeCachedPow(CachedPow *cp) {
    free(cp->first);
    free(cp->second);
}

void solve(int n, int m, int k) {
    Modular mod;
    initModular(&mod, MOD);
    Composite comp;
    initComposite(&comp, MAX_N, mod);
    CachedPow pm;
    initCachedPow(&pm, m, k, mod);

    int *xk = (int *)malloc((k + 1) * sizeof(int));
    for (int i = 0; i <= k; i++) {
        xk[i] = powCached(&pm, i);
    }

    int ans = 0;
    for (int t = 0; t <= k; t++) {
        int p1 = 0; // Placeholder for id1.get(t)
        int p2 = 0;
        for (int i = 0; i <= t; i++) {
            int contrib = composite(&comp, t, i);
            contrib = modMul(&mod, contrib, xk[t - i]);
            if (i % 2 == 1) {
                contrib = modValue(&mod, -contrib);
            }
            p2 = modPlus(&mod, p2, contrib);
        }
        int p3 = powCached(&pm, t);

        int contrib = modMul(&mod, p1, p2);
        contrib = modMul(&mod, contrib, p3);
        ans = modPlus(&mod, ans, contrib);
    }

    printf("%d\n", ans);
    free(xk);
    freeFactorial(&comp.factorial);
    freeCachedPow(&pm);
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    solve(n, m, k);
    return 0;
}
