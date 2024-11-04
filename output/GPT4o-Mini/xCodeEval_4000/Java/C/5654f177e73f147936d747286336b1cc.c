#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MAXN 100000
#define MAXM 100000

typedef struct {
    int *p;
    int *sz;
    int *q[MAXN];
    int less[MAXM];
    int more[MAXM];
    bool used[MAXN + 1];
    int less_size;
    int more_size;
} DSU1;

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
    int *sum;
    int *maxPrefSum;
    int *maxSufSum;
    int *maxSum;
    int pow;
} SegmentTreeMaxSum;

int inv[MAXN];
int n, m, q;
int a[MAXM], b[MAXM];
bool removed[MAXM];
bool type[MAXN];
int x[MAXN];

void dsu1_init(DSU1 *dsu, int *v, int m) {
    int n = sizeof(v) / sizeof(v[0]);
    dsu->p = (int *)malloc(n * sizeof(int));
    dsu->sz = (int *)malloc(n * sizeof(int));
    dsu->less_size = 0;
    dsu->more_size = 0;
    for (int i = 0; i < n; i++) {
        dsu->p[i] = i;
        dsu->sz[i] = 1;
        dsu->q[i] = (int *)malloc(MAXM * sizeof(int));
        dsu->q[i][0] = -v[i];
    }
}

int dsu1_get(DSU1 *dsu, int x) {
    while (x != dsu->p[x]) {
        x = dsu->p[x];
    }
    return x;
}

bool dsu1_unite(DSU1 *dsu, int a, int b) {
    int pa = dsu1_get(dsu, a);
    int pb = dsu1_get(dsu, b);
    if (pa == pb) {
        dsu->less[dsu->less_size++] = -1;
        dsu->more[dsu->more_size++] = -1;
        return false;
    }
    if (dsu->sz[pa] < dsu->sz[pb]) {
        dsu->p[pa] = pb;
        dsu->sz[pb] += dsu->sz[pa];
        dsu->less[dsu->less_size++] = pa;
        dsu->more[dsu->more_size++] = pb;
        for (int i = 0; i < dsu->sz[pa]; i++) {
            dsu->q[pb][i] = dsu->q[pa][i];
        }
    } else {
        dsu->p[pb] = pa;
        dsu->sz[pa] += dsu->sz[pb];
        dsu->less[dsu->less_size++] = pb;
        dsu->more[dsu->more_size++] = pa;
        for (int i = 0; i < dsu->sz[pb]; i++) {
            dsu->q[pa][i] = dsu->q[pb][i];
        }
    }
    return true;
}

void dsu1_pop_edge(DSU1 *dsu) {
    int pa = dsu->less[--dsu->less_size];
    int pb = dsu->more[--dsu->more_size];
    if (pa < 0) {
        return;
    }
    dsu->p[pa] = pa;
    dsu->sz[pb] -= dsu->sz[pa];
}

int dsu1_poll(DSU1 *dsu, int x) {
    int px = dsu1_get(dsu, x);
    while (dsu->q[px][0] != 0) {
        int v = -dsu->q[px][0];
        if (!dsu->used[v] && dsu1_get(dsu, inv[v - 1]) == px) {
            dsu->used[v] = true;
            return v;
        }
    }
    return 0;
}

void solve() {
    scanf("%d %d %d", &n, &m, &q);
    int v[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        inv[v[i] - 1] = i;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a[i], &b[i]);
        a[i]--;
        b[i]--;
    }
    for (int i = 0; i < q; i++) {
        scanf("%d", &x[i]);
        if (x[i] == 1) {
            scanf("%d", &x[i]);
            x[i]--;
            type[i] = true;
        } else {
            scanf("%d", &x[i]);
            x[i]--;
            removed[x[i]] = true;
        }
    }
    DSU1 dsu;
    dsu1_init(&dsu, v, m);
    for (int i = 0; i < m; i++) {
        if (!removed[i]) {
            dsu1_unite(&dsu, a[i], b[i]);
        }
    }
    for (int i = q - 1; i >= 0; i--) {
        if (!type[i]) {
            dsu1_unite(&dsu, a[x[i]], b[x[i]]);
        }
    }
    for (int i = 0; i < q; i++) {
        if (type[i]) {
            printf("%d\n", dsu1_poll(&dsu, x[i]));
        } else {
            dsu1_pop_edge(&dsu);
        }
    }
}

int main() {
    solve();
    return 0;
}
