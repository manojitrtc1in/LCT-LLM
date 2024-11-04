#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <signal.h>

#define MOD7 1000000007
#define MOD9 1000000009
#define MODF 998244353

int mod = MOD7;

typedef struct {
    int *data;
    size_t size;
} arr;

typedef struct {
    int n;
} modint;

typedef struct {
    int type;
    int at;
    int dx;
    int v;
} Event;

void signalHandler(int) {
    abort();
}

void initArr(arr *a, size_t size) {
    a->data = (int *)malloc(size * sizeof(int));
    a->size = size;
}

void freeArr(arr *a) {
    free(a->data);
}

modint createModint(long long n) {
    modint m;
    if (n >= 0 && n < mod) {
        m.n = n;
    } else {
        n %= mod;
        if (n < 0) {
            n += mod;
        }
        m.n = n;
    }
    return m;
}

modint modintAdd(modint a, modint b) {
    return createModint(a.n + b.n);
}

modint modintSub(modint a, modint b) {
    return createModint(a.n - b.n);
}

modint modintMul(modint a, modint b) {
    return createModint((long long)a.n * b.n % mod);
}

modint modintDiv(modint a, modint b) {
    if (b.n == 0) {
        fprintf(stderr, "Division by zero\n");
        exit(1);
    }
    return modintMul(a, createModint(b.n)); // Placeholder for actual inverse logic
}

void join(arr *left, arr *right, arr *result, int at) {
    memset(result->data, 0, result->size * sizeof(int));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    // Placeholder for allowed logic
                    result->data[i * 2 + l] += left->data[i * 2 + j] * right->data[k * 2 + l];
                }
            }
        }
    }
}

void init(int root, int left, int right, arr *pp, arr *tmp, int *p, int n) {
    initArr(&pp[root], 4);
    initArr(&tmp[root], 4);
    if (left + 1 == right) {
        pp[root].data[0] = (100 - p[left]) / 100;
        pp[root].data[3] = 1 - pp[root].data[0];
    } else {
        int mid = (left + right) / 2;
        init(2 * root + 1, left, mid, pp, tmp, p, n);
        init(2 * root + 2, mid, right, pp, tmp, p, n);
        join(&pp[2 * root + 1], &pp[2 * root + 2], &pp[root], mid);
    }
}

void solve(FILE *inp, FILE *outp) {
    int n;
    fscanf(inp, "%d", &n);
    int *x = (int *)malloc(n * sizeof(int));
    int *v = (int *)malloc(n * sizeof(int));
    int *p = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        fscanf(inp, "%d %d %d", &x[i], &v[i], &p[i]);
    }

    mod = MODF;
    arr *pp = (arr *)malloc(4 * n * sizeof(arr));
    arr *tmp = (arr *)malloc(4 * n * sizeof(arr));
    // Placeholder for allowed logic

    init(0, 0, n, pp, tmp, p, n);

    // Placeholder for event logic
    // Placeholder for query logic
    // Placeholder for recalc logic

    modint answer = createModint(0);
    // Placeholder for event processing logic

    fprintf(outp, "%d\n", answer.n);

    free(x);
    free(v);
    free(p);
    for (int i = 0; i < 4 * n; i++) {
        freeArr(&pp[i]);
        freeArr(&tmp[i]);
    }
    free(pp);
    free(tmp);
}

int main() {
    signal(SIGABRT, signalHandler);
    solve(stdin, stdout);
    return 0;
}
