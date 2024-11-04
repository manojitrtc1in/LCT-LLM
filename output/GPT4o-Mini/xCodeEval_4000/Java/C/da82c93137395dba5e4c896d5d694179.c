#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 1000
#define MOD 998244353

typedef struct {
    int *data;
    int size;
} Vector;

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
    int f[MAX_N][MAX_N];
    int h[MAX_N][MAX_N];
} Task;

void initVector(Vector *v, int size) {
    v->data = (int *)malloc(size * sizeof(int));
    v->size = size;
}

void freeVector(Vector *v) {
    free(v->data);
}

void modularInit(Modular *modular, int m) {
    modular->m = m;
}

int modularValueOf(Modular *modular, int x) {
    x %= modular->m;
    if (x < 0) {
        x += modular->m;
    }
    return x;
}

int modularMul(Modular *modular, int x, int y) {
    return modularValueOf(modular, (long long)x * y);
}

int modularPlus(Modular *modular, int x, int y) {
    return modularValueOf(modular, x + y);
}

void powerInit(Power *power, Modular *modular) {
    power->modular = *modular;
}

int powerPow(Power *power, int x, long long n) {
    if (n == 0) {
        return 1;
    }
    long long r = powerPow(power, x, n >> 1);
    r = modularValueOf(&power->modular, r * r);
    if (n & 1) {
        r = modularValueOf(&power->modular, r * x);
    }
    return (int)r;
}

void taskInit(Task *task, int n, int m) {
    task->n = n;
    task->m = m;
    task->fW = 0;
    task->hW = 0;
    task->inv = (int *)malloc((m * 2 + 1) * sizeof(int));
    memset(task->f, -1, sizeof(task->f));
    memset(task->h, -1, sizeof(task->h));
}

void taskFree(Task *task) {
    free(task->inv);
}

void solve(Task *task, Vector *a, Vector *w) {
    int count[2] = {0, 0};
    for (int i = 0; i < task->n; i++) {
        count[a->data[i] % 2]++;
    }

    for (int i = 0; i < task->n; i++) {
        if (a->data[i] % 2 == 0) {
            task->hW += w->data[i];
        } else {
            task->fW += w->data[i];
        }
    }

    // Inverse calculation
    for (int i = 0; i < task->m * 2 + 1; i++) {
        task->inv[i] = powerPow(&power, hW + fW + i - m);
    }

    for (int i = 0; i < task->n; i++) {
        if (a->data[i] % 2 == 1) {
            printf("%d\n", modularMul(&modular, w->data[i], f(0, task->m)));
        } else {
            printf("%d\n", modularMul(&modular, w->data[i], h(0, task->m)));
        }
    }
}

int f(Task *task, int i, int k) {
    if (task->f[i][k] == -1) {
        int j = (task->m - k) - i;
        int fixI = modularPlus(&modular, i, task->fW);
        int fixJ = modularPlus(&modular, task->hW, -j);
        task->f[i][k] = 0;
        int inv = task->inv[i - j + task->m];
        task->f[i][k] = modularPlus(&modular, task->f[i][k], modularMul(&modular, modularMul(&modular, fixI + 1, inv), f(task, i + 1, k - 1)));
        task->f[i][k] = modularPlus(&modular, task->f[i][k], modularMul(&modular, modularMul(&modular, fixJ, inv), f(task, i, k - 1)));
    }
    return task->f[i][k];
}

int h(Task *task, int i, int k) {
    if (task->h[i][k] == -1) {
        int j = (task->m - k) - i;
        int fixI = modularPlus(&modular, i, task->fW);
        int fixJ = modularPlus(&modular, task->hW, -j);
        task->h[i][k] = 0;
        int inv = task->inv[i - j + task->m];
        task->h[i][k] = modularPlus(&modular, task->h[i][k], modularMul(&modular, modularMul(&modular, fixJ - 1, inv), h(task, i, k - 1)));
        task->h[i][k] = modularPlus(&modular, task->h[i][k], modularMul(&modular, modularMul(&modular, fixI, inv), h(task, i + 1, k - 1)));
    }
    return task->h[i][k];
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    Vector a, w;
    initVector(&a, n);
    initVector(&w, n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a.data[i]);
    }
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &w.data[i]);
    }

    Task task;
    taskInit(&task, n, m);
    solve(&task, &a, &w);
    
    taskFree(&task);
    freeVector(&a);
    freeVector(&w);
    
    return 0;
}
