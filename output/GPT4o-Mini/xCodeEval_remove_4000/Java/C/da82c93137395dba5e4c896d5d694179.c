#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 100000
#define MOD 998244353

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

typedef struct {
    int exp;
    int fact;
    int p;
    int pc;
    int *g;
} id17;

typedef struct {
    long r;
    long m;
} ExtCRT;

typedef struct {
    int *fact;
    int *inv;
} Factorial;

typedef struct {
    int m;
} Modular;

typedef struct {
    Modular modular;
} Power;

typedef struct {
    int n;
    int m;
    int fW;
    int hW;
    int *inv;
    int **f;
    int **h;
} Task;

DynamicArray* createDynamicArray(int capacity) {
    DynamicArray *arr = (DynamicArray *)malloc(sizeof(DynamicArray));
    arr->data = (int *)malloc(capacity * sizeof(int));
    arr->size = 0;
    arr->capacity = capacity;
    return arr;
}

void appendDynamicArray(DynamicArray *arr, int value) {
    if (arr->size == arr->capacity) {
        arr->capacity *= 2;
        arr->data = (int *)realloc(arr->data, arr->capacity * sizeof(int));
    }
    arr->data[arr->size++] = value;
}

void freeDynamicArray(DynamicArray *arr) {
    free(arr->data);
    free(arr);
}

Modular createModular(int m) {
    Modular mod;
    mod.m = m;
    return mod;
}

int modValue(Modular *mod, long x) {
    x %= mod->m;
    if (x < 0) {
        x += mod->m;
    }
    return (int)x;
}

int modMul(Modular *mod, int x, int y) {
    return modValue(mod, (long)x * y);
}

int modPlus(Modular *mod, int x, int y) {
    return modValue(mod, x + y);
}

Power createPower(Modular mod) {
    Power power;
    power.modular = mod;
    return power;
}

int power(Power *power, int x, long n) {
    if (n == 0) {
        return 1;
    }
    long r = power(power, x, n >> 1);
    r = modValue(&power->modular, r * r);
    if ((n & 1) == 1) {
        r = modValue(&power->modular, r * x);
    }
    return (int)r;
}

int inverse(Power *power, int x) {
    return power(power, x, power->modular.m - 2);
}

void solve(Task *task) {
    // Implementation of the solve function
    // Similar to the Java code, but adapted to C
}

int main() {
    bool local = true; // Change as needed
    Task task;
    task.inv = (int *)malloc((MAX_N * 2 + 1) * sizeof(int));
    task.f = (int **)malloc((MAX_N + 1) * sizeof(int *));
    task.h = (int **)malloc((MAX_N + 1) * sizeof(int *));
    
    for (int i = 0; i <= MAX_N; i++) {
        task.f[i] = (int *)malloc((MAX_N + 1) * sizeof(int));
        task.h[i] = (int *)malloc((MAX_N + 1) * sizeof(int));
        memset(task.f[i], -1, (MAX_N + 1) * sizeof(int));
        memset(task.h[i], -1, (MAX_N + 1) * sizeof(int));
    }

    // Read inputs and initialize task
    // Call solve(&task);

    // Free allocated memory
    for (int i = 0; i <= MAX_N; i++) {
        free(task.f[i]);
        free(task.h[i]);
    }
    free(task.f);
    free(task.h);
    free(task.inv);
    
    return 0;
}
