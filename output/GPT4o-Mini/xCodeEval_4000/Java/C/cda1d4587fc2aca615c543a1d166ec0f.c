#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 998244353
#define MAX_SIZE 5000

typedef struct {
    int *data;
    int size;
    int cap;
} IntegerList;

typedef struct {
    int m;
} Modular;

typedef struct {
    Modular mod;
    int *fact;
    int *inv;
} Factorial;

typedef struct {
    Factorial factorial;
    Modular mod;
} Composite;

typedef struct {
    int *first;
    int *second;
    Modular mod;
} CachedPow;

typedef struct {
    int *data;
    int size;
} FastInput;

typedef struct {
    char *cache;
    size_t size;
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

void initFactorial(Factorial *fact, int limit, Modular *mod) {
    fact->mod = *mod;
    fact->fact = (int *)malloc((limit + 1) * sizeof(int));
    fact->inv = (int *)malloc((limit + 1) * sizeof(int));
    fact->fact[0] = fact->inv[0] = 1;
    for (int i = 1; i <= limit; i++) {
        fact->fact[i] = modMul(mod, fact->fact[i - 1], i);
        // Inverse calculation can be added here
    }
}

void freeFactorial(Factorial *fact) {
    free(fact->fact);
    free(fact->inv);
}

void initComposite(Composite *comp, int limit, Modular *mod) {
    initFactorial(&comp->factorial, limit, mod);
    comp->mod = *mod;
}

int composite(Composite *comp, int m, int n) {
    if (n > m) return 0;
    return modMul(&comp->mod, modMul(&comp->mod, comp->factorial.fact[m], comp->factorial.inv[n]), comp->factorial.inv[m - n]);
}

void initCachedPow(CachedPow *cp, int x, int maxExp, Modular *mod) {
    cp->mod = *mod;
    cp->first = (int *)malloc((maxExp + 1) * sizeof(int));
    cp->second = (int *)malloc((maxExp + 1) * sizeof(int));
    cp->first[0] = 1;
    for (int i = 1; i <= maxExp; i++) {
        cp->first[i] = modMul(mod, x, cp->first[i - 1]);
    }
    cp->second[0] = 1;
    for (int i = 1; i <= maxExp; i++) {
        cp->second[i] = modMul(mod, cp->second[i - 1], cp->first[maxExp]);
    }
}

int powCached(CachedPow *cp, int exp) {
    return modMul(&cp->mod, cp->first[exp % (sizeof(cp->first) / sizeof(int))], cp->second[exp / (sizeof(cp->first) / sizeof(int))]);
}

void initFastInput(FastInput *input, FILE *stream) {
    input->data = (int *)malloc(1024 * sizeof(int));
    input->size = 0;
    // Read from stream can be implemented here
}

void freeFastInput(FastInput *input) {
    free(input->data);
}

void initFastOutput(FastOutput *output) {
    output->size = 1024;
    output->cache = (char *)malloc(output->size * sizeof(char));
}

void flushFastOutput(FastOutput *output) {
    // Flush output can be implemented here
}

void freeFastOutput(FastOutput *output) {
    free(output->cache);
}

int main() {
    // Initialize and run the main logic
    Modular mod;
    initModular(&mod, MOD);
    
    // Other initializations and logic can be added here

    return 0;
}
