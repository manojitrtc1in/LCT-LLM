#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX_N 100000
#define MAX_M 100000
#define MAX_Q 100000
#define LONG_MIN (LONG_MIN / 2)

typedef struct {
    int *p;
    int *sz;
    int *q[MAX_N];
    int less[MAX_N];
    int more[MAX_N];
    bool used[MAX_N + 1];
    int n;
    int m;
} id1;

typedef struct {
    long x1, x2, y1, y2;
    int number;
} Rect;

typedef struct {
    double x, y;
} Point;

typedef struct {
    long x, y;
} Fraction;

typedef struct {
    int *t;
    int n;
} id6;

typedef struct {
    int *sum;
    int *maxSum;
    int *id3;
    int *id7;
    int pow;
} id4;

typedef struct {
    int **to;
    int *sz;
    int *x;
    int *y;
    int n;
    int m;
} Graph;

void init_id1(id1 *dsu, int *v, int m) {
    dsu->n = sizeof(v) / sizeof(v[0]);
    dsu->p = (int *)malloc(dsu->n * sizeof(int));
    dsu->sz = (int *)malloc(dsu->n * sizeof(int));
    for (int i = 0; i < dsu->n; i++) {
        dsu->p[i] = i;
        dsu->sz[i] = 1;
        dsu->q[i] = (int *)malloc(m * sizeof(int));
        dsu->q[i][0] = -v[i];
    }
}

int get(int *p, int x) {
    while (x != p[x]) {
        x = p[x];
    }
    return x;
}

bool unite(id1 *dsu, int a, int b) {
    int pa = get(dsu->p, a);
    int pb = get(dsu->p, b);
    if (pa == pb) {
        dsu->less[pa] = -1;
        dsu->more[pb] = -1;
        return false;
    }
    if (dsu->sz[pa] < dsu->sz[pb]) {
        dsu->p[pa] = pb;
        dsu->sz[pb] += dsu->sz[pa];
        dsu->less[pa] = pa;
        dsu->more[pb] = pb;
        for (int i = 0; i < dsu->sz[pa]; i++) {
            dsu->q[pb][i] = dsu->q[pa][i];
        }
    } else {
        dsu->p[pb] = pa;
        dsu->sz[pa] += dsu->sz[pb];
        dsu->less[pb] = pb;
        dsu->more[pa] = pa;
        for (int i = 0; i < dsu->sz[pb]; i++) {
            dsu->q[pa][i] = dsu->q[pb][i];
        }
    }
    return true;
}

void popEdge(id1 *dsu) {
    int pa = dsu->less[0];
    int pb = dsu->more[0];
    if (pa < 0) {
        return;
    }
    dsu->p[pa] = pa;
    dsu->sz[pb] -= dsu->sz[pa];
}

int poll(id1 *dsu, int x) {
    int px = get(dsu->p, x);
    while (dsu->q[px][0] != 0) {
        int v = -dsu->q[px][0];
        if (!dsu->used[v] && get(dsu->p, v - 1) == px) {
            dsu->used[v] = true;
            return v;
        }
    }
    return 0;
}

void solve() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    int v[MAX_N], inv[MAX_N];
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        inv[v[i] - 1] = i;
    }
    int a[MAX_M], b[MAX_M];
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a[i], &b[i]);
        a[i]--;
        b[i]--;
    }
    bool type[MAX_Q];
    int x[MAX_Q];
    bool removed[MAX_M] = {false};
    for (int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d", &x[i]);
            x[i]--;
            type[i] = true;
        } else {
            scanf("%d", &x[i]);
            removed[x[i]] = true;
        }
    }
    id1 dsu;
    init_id1(&dsu, v, m);
    for (int i = 0; i < m; i++) {
        if (!removed[i]) {
            unite(&dsu, a[i], b[i]);
        }
    }
    for (int i = q - 1; i >= 0; i--) {
        if (!type[i]) {
            unite(&dsu, a[x[i]], b[x[i]]);
        }
    }
    for (int i = 0; i < q; i++) {
        if (type[i]) {
            printf("%d\n", poll(&dsu, x[i]));
        } else {
            popEdge(&dsu);
        }
    }
}

int main() {
    solve();
    return 0;
}
