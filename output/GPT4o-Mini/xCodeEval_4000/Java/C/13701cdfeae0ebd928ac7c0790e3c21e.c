#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_SIZE 100000
#define MOD 998244353

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

void dft(NumberTheoryTransform *ntt, int *p, int m) {
    int n = 1 << m;
    int shift = 32 - __builtin_clz(n) - 1;
    for (int i = 1; i < n; i++) {
        int j = __builtin_bswap32(i << shift) >> (32 - shift);
        if (i < j) {
            int temp = p[i];
            p[i] = p[j];
            p[j] = temp;
        }
    }
    // Implement the rest of the DFT logic...
}

void idft(NumberTheoryTransform *ntt, int *p, int m) {
    dft(ntt, p, m);
    // Implement the rest of the IDFT logic...
}

void solve(int n, int k, int *allow) {
    Modular mod = {MOD};
    IntList p;
    initIntList(&p, 10);
    addAll(&p, allow, k);

    int m = n / 2;
    IntList last;
    initIntList(&last, p.size);
    memcpy(last.data, p.data, p.size * sizeof(int));
    last.size = p.size;

    NumberTheoryTransform ntt;
    ntt.mod = mod;
    ntt.wCache = (int *)malloc(30 * sizeof(int));
    ntt.invCache = (int *)malloc(30 * sizeof(int));
    ntt.g = 3; // Example primitive root

    // Implement the rest of the solve logic...

    freeIntList(&p);
    freeIntList(&last);
    free(ntt.wCache);
    free(ntt.invCache);
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
