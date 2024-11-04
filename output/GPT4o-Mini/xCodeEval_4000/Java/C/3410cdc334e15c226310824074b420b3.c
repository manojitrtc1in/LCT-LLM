#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 100005
#define MOD 998244353

typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

void vector_init(Vector *v, int capacity) {
    v->data = (int *)malloc(capacity * sizeof(int));
    v->size = 0;
    v->capacity = capacity;
}

void vector_push_back(Vector *v, int value) {
    if (v->size >= v->capacity) {
        v->capacity *= 2;
        v->data = (int *)realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = value;
}

void vector_free(Vector *v) {
    free(v->data);
}

typedef struct {
    int n, m;
    int a[MAX_N];
    int w[MAX_N];
    int f[MAX_N][MAX_N];
    int h[MAX_N][MAX_N];
    int fW, hW;
    int inv[MAX_N * 2 + 1];
} Task;

int modular(int x) {
    return (x % MOD + MOD) % MOD;
}

int power(int x, long n) {
    if (n == 0) return 1;
    long res = power(x, n >> 1);
    res = modular(res * res);
    if (n & 1) res = modular(res * x);
    return (int)res;
}

int inverse(int x) {
    return power(x, MOD - 2);
}

void solve(Task *task) {
    scanf("%d %d", &task->n, &task->m);
    int count[2] = {0, 0};
    
    for (int i = 0; i < task->n; i++) {
        scanf("%d", &task->a[i]);
        count[task->a[i] % 2]++;
    }
    
    for (int i = 0; i < task->n; i++) {
        scanf("%d", &task->w[i]);
        if (task->a[i] % 2 == 0) {
            task->hW += task->w[i];
        } else {
            task->fW += task->w[i];
        }
    }

    for (int i = 0; i <= task->m * 2; i++) {
        task->inv[i] = inverse(task->hW + task->fW + i - task->m);
    }

    for (int i = 0; i <= task->m; i++) {
        for (int j = 0; j <= task->m; j++) {
            task->f[i][j] = -1;
            task->h[i][j] = -1;
        }
        task->f[i][0] = 1;
        task->h[i][0] = 1;
    }

    for (int i = 0; i < task->n; i++) {
        if (task->a[i] % 2 == 1) {
            printf("%d\n", modular(task->w[i] * f(task, 0, task->m)));
        } else {
            printf("%d\n", modular(task->w[i] * h(task, 0, task->m)));
        }
    }
}

int f(Task *task, int i, int k) {
    if (task->f[i][k] == -1) {
        int j = (task->m - k) - i;
        int fixI = modular(i + task->fW);
        int fixJ = modular(task->hW - j);
        task->f[i][k] = 0;
        int inv = task->inv[i - j + task->m];
        task->f[i][k] = modular(task->f[i][k] + modular(modular(fixI + 1, inv) * f(task, i + 1, k - 1)));
        task->f[i][k] = modular(task->f[i][k] + modular(modular(fixJ, inv) * f(task, i, k - 1)));
    }
    return task->f[i][k];
}

int h(Task *task, int i, int k) {
    if (task->h[i][k] == -1) {
        int j = (task->m - k) - i;
        int fixI = modular(i + task->fW);
        int fixJ = modular(task->hW - j);
        task->h[i][k] = 0;
        int inv = task->inv[i - j + task->m];
        task->h[i][k] = modular(task->h[i][k] + modular(modular(fixJ - 1, inv) * h(task, i, k - 1)));
        task->h[i][k] = modular(task->h[i][k] + modular(modular(fixI, inv) * h(task, i + 1, k - 1)));
    }
    return task->h[i][k];
}

int main() {
    Task task = {0};
    task.fW = 0;
    task.hW = 0;
    solve(&task);
    return 0;
}
