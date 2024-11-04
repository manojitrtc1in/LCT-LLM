#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>

#define MAX_N 100000

typedef struct {
    int p, q;
} Frac;

typedef struct {
    int m[2][2];
} Mat;

typedef struct {
    int par[MAX_N], sz[MAX_N], nTree;
} UnionFind;

typedef struct {
    double value;
} Mint;

int n;
int x[MAX_N], v[MAX_N];
double p[MAX_N];
Mat allowed_collisions[MAX_N];
Mat a[2 * (MAX_N - 1) - 1];

void init_union_find(UnionFind *uf, int n) {
    uf->nTree = n;
    for (int i = 0; i < n; i++) {
        uf->par[i] = i;
        uf->sz[i] = 1;
    }
}

int root(UnionFind *uf, int x) {
    return x == uf->par[x] ? x : (uf->par[x] = root(uf, uf->par[x]));
}

bool unite(UnionFind *uf, int x, int y) {
    int rx = root(uf, x), ry = root(uf, y);
    if (rx != ry) {
        uf->par[rx] = ry;
        uf->nTree--;
        uf->sz[ry] += uf->sz[rx];
        return true;
    }
    return false;
}

void normalize(double *value) {
    if (*value < 0) *value += 1;
}

double get_prob(int to_right, Mat *mat) {
    return to_right * (mat->m[1][0] + mat->m[1][1]) + (1 - to_right) * (mat->m[0][0] + mat->m[0][1]);
}

void build(int l, int r) {
    if (l == r) {
        a[2 * l] = allowed_collisions[l];
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid);
    build(mid + 1, r);
    // Combine matrices
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            a[get_id(l, r)].m[i][j] = a[get_id(l, mid)].m[i][0] * a[get_id(mid + 1, r)].m[0][j];
        }
    }
}

void modify(int l, int r, int k) {
    if (l == r) {
        a[2 * l] = allowed_collisions[k];
        return;
    }
    int mid = (l + r) / 2;
    if (k <= mid) {
        modify(l, mid, k);
    } else {
        modify(mid + 1, r, k);
    }
    // Combine matrices
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            a[get_id(l, r)].m[i][j] = a[get_id(l, mid)].m[i][0] * a[get_id(mid + 1, r)].m[0][j];
        }
    }
}

void scan() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %lf", &x[i], &v[i], &p[i]);
        p[i] /= 100.0;
    }
}

int main() {
    scan();
    if (n == 1) {
        printf("0\n");
        return 0;
    }

    for (int i = 0; i < n - 1; i++) {
        allowed_collisions[i].m[0][1] = p[i + 1];
    }

    build(0, n - 2);
    double prev_prob = get_prob(p[0], &a[get_id(0, n - 2)]);
    double ans = 0;

    // Process events (not fully implemented)
    // ...

    printf("%lf\n", ans);
    return 0;
}
