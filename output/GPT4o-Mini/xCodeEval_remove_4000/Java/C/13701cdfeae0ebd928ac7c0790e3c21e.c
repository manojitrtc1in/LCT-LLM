#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_CAPACITY 100000

typedef struct {
    int *data;
    int size;
    int capacity;
} IntList;

typedef struct {
    int mod;
} Modular;

typedef struct {
    Modular *mod;
    int *wCache;
    int *invCache;
    int g;
} id8;

typedef struct {
    int *data;
    int size;
    int capacity;
} Buffer;

void initIntList(IntList *list, int capacity) {
    list->data = (int *)malloc(capacity * sizeof(int));
    list->size = 0;
    list->capacity = capacity;
}

void addAll(IntList *list, int *x, int len) {
    if (list->size + len > list->capacity) {
        list->capacity = (list->capacity + len) * 2;
        list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
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
    mod->mod = m;
}

int modularValueOf(Modular *mod, int x) {
    x %= mod->mod;
    if (x < 0) {
        x += mod->mod;
    }
    return x;
}

int modularMul(Modular *mod, int x, int y) {
    return modularValueOf(mod, (long long)x * y);
}

int modularPlus(Modular *mod, int x, int y) {
    return modularValueOf(mod, x + y);
}

void initId8(id8 *ntt, Modular *mod, int g) {
    ntt->mod = mod;
    ntt->g = g;
    ntt->wCache = (int *)malloc(30 * sizeof(int));
    ntt->invCache = (int *)malloc(30 * sizeof(int));
    for (int i = 0; i < 30; i++) {
        int s = 1 << i;
        ntt->wCache[i] = modularValueOf(mod, (int)pow(g, (mod->mod - 1) / (2 * s)));
        ntt->invCache[i] = modularValueOf(mod, (int)pow(s, mod->mod - 2));
    }
}

void freeId8(id8 *ntt) {
    free(ntt->wCache);
    free(ntt->invCache);
}

void dft(int *p, int m, Modular *mod) {
    int n = 1 << m;
    for (int i = 1; i < n; i++) {
        int j = __builtin_bitreverse32(i) >> (32 - __builtin_ctz(n));
        if (i < j) {
            int temp = p[i];
            p[i] = p[j];
            p[j] = temp;
        }
    }

    for (int d = 0; d < m; d++) {
        int w1 = ntt->wCache[d];
        int s = 1 << d;
        int s2 = s << 1;
        for (int i = 0; i < n; i += s2) {
            int w = 1;
            for (int j = 0; j < s; j++) {
                int a = i + j;
                int b = a + s;
                int t = modularMul(mod, w, p[b]);
                p[b] = modularPlus(mod, p[a], -t);
                p[a] = modularPlus(mod, p[a], t);
                w = modularMul(mod, w, w1);
            }
        }
    }
}

void idft(int *p, int m, Modular *mod) {
    dft(p, m, mod);
    int n = 1 << m;
    int invN = ntt->invCache[m];
    p[0] = modularMul(mod, p[0], invN);
    for (int i = 1; i < n / 2; i++) {
        int a = p[n - i];
        p[n - i] = modularMul(mod, p[i], invN);
        p[i] = modularMul(mod, a, invN);
    }
}

void solve(int n, int k, int *allow) {
    Modular mod;
    initModular(&mod, 998244353);
    IntList p;
    initIntList(&p, 10);
    addAll(&p, allow, k);

    int m = n / 2;
    IntList last = p; // Clone not implemented for simplicity
    id8 ntt;
    initId8(&ntt, &mod, 3);
    
    // Further implementation would go here...

    freeIntList(&p);
    freeId8(&ntt);
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
