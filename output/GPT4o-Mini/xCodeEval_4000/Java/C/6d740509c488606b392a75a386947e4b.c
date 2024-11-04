#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MOD 998244353
#define MAX_SIZE 100000

typedef struct {
    int *data;
    int size;
    int cap;
} IntList;

typedef struct {
    int m;
} Modular;

typedef struct {
    Modular mod;
    int *wCache;
    int *invCache;
    int g;
} NumberTheoryTransform;

typedef struct {
    int *data;
    int size;
    int cap;
} Buffer;

void initIntList(IntList *list, int cap) {
    list->data = (int *)malloc(cap * sizeof(int));
    list->size = 0;
    list->cap = cap;
}

void addAll(IntList *list, int *x, int len) {
    if (list->size + len > list->cap) {
        list->cap = (list->cap + len) * 2;
        list->data = (int *)realloc(list->data, list->cap * sizeof(int));
    }
    memcpy(list->data + list->size, x, len * sizeof(int));
    list->size += len;
}

void clearIntList(IntList *list) {
    list->size = 0;
}

void freeIntList(IntList *list) {
    free(list->data);
}

void initModular(Modular *mod, int m) {
    mod->m = m;
}

int modValue(Modular *mod, int x) {
    x %= mod->m;
    if (x < 0) {
        x += mod->m;
    }
    return x;
}

int modMul(Modular *mod, int x, int y) {
    return modValue(mod, (long long)x * y);
}

int modPlus(Modular *mod, int x, int y) {
    return modValue(mod, x + y);
}

void initNTT(NumberTheoryTransform *ntt, Modular mod, int g) {
    ntt->mod = mod;
    ntt->g = g;
    ntt->wCache = (int *)malloc(30 * sizeof(int));
    ntt->invCache = (int *)malloc(30 * sizeof(int));
    for (int i = 0; i < 30; i++) {
        int s = 1 << i;
        ntt->wCache[i] = modMul(&mod, g, (mod.m - 1) / (2 * s));
        ntt->invCache[i] = modMul(&mod, s, mod.m - 2);
    }
}

void freeNTT(NumberTheoryTransform *ntt) {
    free(ntt->wCache);
    free(ntt->invCache);
}

void dft(NumberTheoryTransform *ntt, int *p, int m) {
    int n = 1 << m;
    // Implementation of DFT
}

void idft(NumberTheoryTransform *ntt, int *p, int m) {
    dft(ntt, p, m);
    // Implementation of IDFT
}

void solve(int n, int k, int *allow) {
    IntList p;
    initIntList(&p, 10);
    addAll(&p, allow, k);

    int m = n / 2;
    IntList last;
    initIntList(&last, p.size);
    memcpy(last.data, p.data, p.size * sizeof(int));
    
    NumberTheoryTransform ntt;
    initNTT(&ntt, (Modular){MOD}, 3);

    // Main logic for solving the problem
    // ...

    freeIntList(&p);
    freeIntList(&last);
    freeNTT(&ntt);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int allow[10] = {0};
    for (int i = 0; i < k; i++) {
        int x;
        scanf("%d", &x);
        allow[x] = 1;
    }
    solve(n, k, allow);
    return 0;
}
