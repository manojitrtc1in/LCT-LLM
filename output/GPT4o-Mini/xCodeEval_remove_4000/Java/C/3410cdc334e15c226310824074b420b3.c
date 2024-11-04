#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 100000
#define MAX_M 100000

typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

typedef struct {
    int *inv;
    int m;
} Modular;

typedef struct {
    Modular modular;
    int *g;
    int exp;
    int fact;
    int p;
    int pc;
} id17;

typedef struct {
    id17 *id9;
    int size;
} ExtLucas;

typedef struct {
    int *fact;
    int *inv;
    Modular modular;
} Factorial;

typedef struct {
    int *data;
    int size;
    int capacity;
} FastIO;

typedef struct {
    int n;
    int m;
    int fW;
    int hW;
    int *inv;
    int **f;
    int **h;
    FastIO io;
} Task;

void initVector(Vector *v, int capacity) {
    v->data = (int *)malloc(capacity * sizeof(int));
    v->size = 0;
    v->capacity = capacity;
}

void pushBack(Vector *v, int value) {
    if (v->size >= v->capacity) {
        v->capacity *= 2;
        v->data = (int *)realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = value;
}

void freeVector(Vector *v) {
    free(v->data);
}

void initModular(Modular *modular, int m) {
    modular->m = m;
    modular->inv = (int *)malloc((2 * MAX_M + 1) * sizeof(int));
}

int modularValue(Modular *modular, long x) {
    x %= modular->m;
    if (x < 0) {
        x += modular->m;
    }
    return (int)x;
}

int modularMul(Modular *modular, int x, int y) {
    return modularValue(modular, (long)x * y);
}

int modularPlus(Modular *modular, int x, int y) {
    return modularValue(modular, x + y);
}

void initFastIO(FastIO *io, FILE *input, FILE *output) {
    io->data = (int *)malloc(1 << 13);
    io->size = 0;
    io->capacity = 1 << 13;
}

void flush(FastIO *io) {
    fwrite(io->data, sizeof(int), io->size, stdout);
    io->size = 0;
}

int readInt(FastIO *io) {
    int sign = 1;
    int val = 0;
    char c;
    while ((c = getchar()) != EOF && (c < '0' || c > '9') && c != '-' && c != '+');
    if (c == '-') {
        sign = -1;
        c = getchar();
    } else if (c == '+') {
        c = getchar();
    }
    do {
        val = val * 10 + (c - '0');
    } while ((c = getchar()) >= '0' && c <= '9');
    return sign * val;
}

void solve(Task *task) {
    task->n = readInt(&task->io);
    task->m = readInt(&task->io);
    int *a = (int *)malloc(task->n * sizeof(int));
    int count[2] = {0, 0};
    for (int i = 0; i < task->n; i++) {
        a[i] = readInt(&task->io);
        count[a[i] % 2]++;
    }
    int *w = (int *)malloc(task->n * sizeof(int));
    for (int i = 0; i < task->n; i++) {
        w[i] = readInt(&task->io);
        if (a[i] % 2 == 0) {
            task->hW += w[i];
        } else {
            task->fW += w[i];
        }
    }

    task->inv = (int *)malloc((task->m * 2 + 1) * sizeof(int));
    for (int i = 0; i < task->m * 2 + 1; i++) {
        task->inv[i] = modularInverse(task->hW + task->fW + i - task->m);
    }

    task->f = (int **)malloc((task->m + 1) * sizeof(int *));
    task->h = (int **)malloc((task->m + 1) * sizeof(int *));
    for (int i = 0; i <= task->m; i++) {
        task->f[i] = (int *)malloc((task->m + 1) * sizeof(int));
        task->h[i] = (int *)malloc((task->m + 1) * sizeof(int));
        memset(task->f[i], -1, (task->m + 1) * sizeof(int));
        memset(task->h[i], -1, (task->m + 1) * sizeof(int));
    }

    for (int i = 0; i <= task->m; i++) {
        task->f[i][0] = 1;
        task->h[i][0] = 1;
    }

    for (int i = 0; i < task->n; i++) {
        if (a[i] % 2 == 1) {
            printf("%d\n", modularMul(&task->modular, w[i], f(0, task->m, task)));
        } else {
            printf("%d\n", modularMul(&task->modular, w[i], h(0, task->m, task)));
        }
    }

    free(a);
    free(w);
}

int f(int i, int k, Task *task) {
    if (task->f[i][k] == -1) {
        int j = (task->m - k) - i;
        int fixI = modularPlus(&task->modular, i, task->fW);
        int fixJ = modularPlus(&task->modular, task->hW, -j);
        task->f[i][k] = 0;
        int inv = task->inv[i - j + task->m];
        task->f[i][k] = modularPlus(&task->modular, task->f[i][k], modularMul(&task->modular, modularMul(&task->modular, fixI + 1, inv), f(i + 1, k - 1, task)));
        task->f[i][k] = modularPlus(&task->modular, task->f[i][k], modularMul(&task->modular, modularMul(&task->modular, fixJ, inv), f(i, k - 1, task)));
    }
    return task->f[i][k];
}

int h(int i, int k, Task *task) {
    if (task->h[i][k] == -1) {
        int j = (task->m - k) - i;
        int fixI = modularPlus(&task->modular, i, task->fW);
        int fixJ = modularPlus(&task->modular, task->hW, -j);
        task->h[i][k] = 0;
        int inv = task->inv[i - j + task->m];

        task->h[i][k] = modularPlus(&task->modular, task->h[i][k], modularMul(&task->modular, modularMul(&task->modular, fixJ - 1, inv), h(i, k - 1, task)));
        task->h[i][k] = modularPlus(&task->modular, task->h[i][k], modularMul(&task->modular, modularMul(&task->modular, fixI, inv), h(i + 1, k - 1, task)));
    }
    return task->h[i][k];
}

int main() {
    Task task;
    initFastIO(&task.io, stdin, stdout);
    task.fW = 0;
    task.hW = 0;
    solve(&task);
    flush(&task.io);
    return 0;
}
