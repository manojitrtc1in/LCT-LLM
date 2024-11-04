#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXN 1000001
#define MOD 998244353
#define INF 1e10
#define EPS 1e-9

typedef struct {
    double x, y;
} Point;

typedef struct {
    int *p;
    int *size;
    int n;
} UnionFind;

typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

void initVector(Vector *v, int capacity) {
    v->data = (int *)malloc(capacity * sizeof(int));
    v->size = 0;
    v->capacity = capacity;
}

void pushBack(Vector *v, int value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (int *)realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = value;
}

void freeVector(Vector *v) {
    free(v->data);
}

UnionFind* createUnionFind(int n) {
    UnionFind *uf = (UnionFind *)malloc(sizeof(UnionFind));
    uf->p = (int *)malloc(n * sizeof(int));
    uf->size = (int *)malloc(n * sizeof(int));
    uf->n = n;
    for (int i = 0; i < n; i++) {
        uf->p[i] = i;
        uf->size[i] = 1;
    }
    return uf;
}

int findSet(UnionFind *uf, int v) {
    if (v == uf->p[v]) return v;
    return uf->p[v] = findSet(uf, uf->p[v]);
}

void combine(UnionFind *uf, int a, int b) {
    a = findSet(uf, a);
    b = findSet(uf, b);
    if (a == b) return;
    if (uf->size[a] > uf->size[b]) {
        uf->p[b] = a;
        uf->size[a] += uf->size[b];
    } else {
        uf->p[a] = b;
        uf->size[b] += uf->size[a];
    }
}

void freeUnionFind(UnionFind *uf) {
    free(uf->p);
    free(uf->size);
    free(uf);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k, d;
        scanf("%d %d %d", &n, &k, &d);
        int *a = (int *)malloc(n * sizeof(int));
        int *occ = (int *)calloc(n + 1, sizeof(int));
        int *hm = (int *)malloc(n * sizeof(int));
        int id = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (hm[a[i]] == 0) {
                hm[a[i]] = ++id;
            }
            a[i] = hm[a[i]];
        }
        int ans = 0;
        for (int i = 0; i < d; i++) {
            occ[a[i]]++;
            if (occ[a[i]] == 1) ans++;
        }
        int ansl = ans;
        for (int i = d; i < n; i++) {
            int ans1 = ansl;
            occ[a[i]]++;
            if (occ[a[i]] == 1) ans1++;
            occ[a[i - d]]--;
            if (occ[a[i - d]] == 0) ans1--;
            ans = fmin(ans, ans1);
            ansl = ans1;
        }
        printf("%d\n", ans);
        free(a);
        free(occ);
        free(hm);
    }
    return 0;
}
