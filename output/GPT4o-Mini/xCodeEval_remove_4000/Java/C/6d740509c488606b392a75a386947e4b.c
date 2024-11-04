#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_CAPACITY 1000000
#define MOD 998244353

typedef struct {
    int *data;
    int size;
    int capacity;
} IntList;

typedef struct {
    int m;
} Modular;

typedef struct {
    Modular mod;
    int *wCache;
    int *invCache;
    int g;
} id9;

void initIntList(IntList *list, int capacity) {
    list->data = (int *)malloc(capacity * sizeof(int));
    list->size = 0;
    list->capacity = capacity;
}

void addAll(IntList *list, int *x, int len) {
    if (list->size + len > list->capacity) {
        list->capacity = list->size + len;
        list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
    }
    memcpy(list->data + list->size, x, len * sizeof(int));
    list->size += len;
}

void clearIntList(IntList *list) {
    list->size = 0;
}

int readInt() {
    int value;
    scanf("%d", &value);
    return value;
}

Modular createModular(int m) {
    Modular mod;
    mod.m = m;
    return mod;
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

void ntt(int *a, int n, bool invert, int mod, int root) {
    int shift = 32 - __builtin_clz(n);
    for (int i = 1; i < n; i++) {
        int j = __builtin_bitreverse32(i) >> shift;
        if (i < j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    int root_inv = modPow(root, mod - 2, mod);
    for (int len = 1; len < n; len <<= 1) {
        int wlen = modPow(invert ? root_inv : root, (mod - 1) / (2 * len), mod);
        for (int i = 0; i < n; i += 2 * len) {
            int w = 1;
            for (int j = 0; j < len; ++j) {
                int u = a[i + j];
                int v = modMul(&mod, a[i + j + len], w);
                a[i + j] = modPlus(&mod, u, v);
                a[i + j + len] = modPlus(&mod, u, -v);
                w = modMul(&mod, w, wlen);
            }
        }
    }
    if (invert) {
        int nrev = modPow(n, mod - 2, mod);
        for (int i = 0; i < n; ++i) {
            a[i] = modMul(&mod, a[i], nrev);
        }
    }
}

int modPow(int x, int n, int mod) {
    int res = 1;
    for (long long p = x; n > 0; n >>= 1, p = (p * p) % mod) {
        if (n & 1) {
            res = (int)((long long)res * p % mod);
        }
    }
    return res;
}

void solve(int testNumber) {
    int n = readInt();
    int k = readInt();
    int allow[10] = {0};
    for (int i = 0; i < k; i++) {
        allow[readInt()] = 1;
    }

    IntList p;
    initIntList(&p, 10);
    addAll(&p, allow, 10);

    int m = n / 2;
    IntList last = p;
    id9 ntt = {createModular(MOD), NULL, NULL, 3};

    while (m > 1) {
        if (m % 2 == 1) {
            // Add last to lists (not implemented)
        }
        // NTT and other operations (not implemented)
        m /= 2;
    }

    // Final answer calculation (not implemented)
    printf("%d\n", 0); // Placeholder for answer
}

int main() {
    int testCases = 1; // Assuming single test case for simplicity
    for (int i = 1; i <= testCases; i++) {
        solve(i);
    }
    return 0;
}
