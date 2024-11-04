#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 998244353
#define MAX_CAPACITY 5000

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
    int *data;
    int size;
} FastOutput;

typedef struct {
    int *data;
    int size;
} FastInput;

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

void initModular(Modular *mod, int m) {
    mod->m = m;
}

int modularValue(Modular *mod, int x) {
    x %= mod->m;
    if (x < 0) {
        x += mod->m;
    }
    return x;
}

int modularMul(Modular *mod, int x, int y) {
    return modularValue(mod, (long long)x * y);
}

void initFactorial(Factorial *fact, int limit, Modular mod) {
    fact->mod = mod;
    fact->fact = (int *)malloc((limit + 1) * sizeof(int));
    fact->inv = (int *)malloc((limit + 1) * sizeof(int));
    fact->fact[0] = fact->inv[0] = 1;
    for (int i = 1; i <= limit; i++) {
        fact->fact[i] = modularMul(&mod, fact->fact[i - 1], i);
        // Inverse calculation would go here
    }
}

void solve(int n, int m, int k, FastInput *in, FastOutput *out) {
    Modular mod;
    initModular(&mod, MOD);
    Factorial fact;
    initFactorial(&fact, MAX_CAPACITY, mod);

    // Implementation of the main logic goes here
    // This includes reading inputs, performing calculations, and writing outputs
}

int main() {
    FastInput in;
    FastOutput out;

    // Initialize FastInput and FastOutput
    // Read n, m, k and call solve function

    return 0;
}
