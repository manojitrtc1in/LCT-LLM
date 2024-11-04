#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>

typedef struct {
    int x, y;
} xyPoint;

typedef struct {
    xyPoint center;
    double radius;
} xyCircle;

typedef struct {
    size_t *parent;
    size_t *rank;
    size_t size;
} UnionFind;

UnionFind* createUnionFind(size_t n) {
    UnionFind *uf = malloc(sizeof(UnionFind));
    uf->parent = malloc(n * sizeof(size_t));
    uf->rank = malloc(n * sizeof(size_t));
    uf->size = n;
    for (size_t j = 0; j < n; ++j) {
        uf->parent[j] = j;
        uf->rank[j] = 0;
    }
    return uf;
}

size_t find(UnionFind *uf, size_t s) {
    size_t p = uf->parent[s];
    return uf->parent[p] == p ? p : (uf->parent[s] = find(uf, p));
}

void lazy_union(UnionFind *uf, size_t i, size_t j) {
    i = find(uf, i);
    j = find(uf, j);
    if (i != j) {
        if (uf->rank[i] < uf->rank[j]) {
            uf->parent[i] = j;
        } else {
            uf->parent[j] = i;
            uf->rank[i] += (uf->rank[i] == uf->rank[j]);
        }
    }
}

void freeUnionFind(UnionFind *uf) {
    free(uf->parent);
    free(uf->rank);
    free(uf);
}

int refill(int k, int left[][3], int leftSize, int right[][3], int rightSize) {
    int val = 0;
    for (int i = 0; i < leftSize; ++i) {
        if (left[i][0] < right[i][1]) {
            int w = (k < left[i][2]) ? k : left[i][2];
            k -= w;
            val += w * (right[i][1] - left[i][0]);
        }
    }
    return val;
}

int main() {
    size_t n, m, k;
    scanf("%zu %zu %zu", &n, &m, &k);

    int a[n][m][3]; // Assuming maximum size for simplicity

    for (size_t i = 0; i < n; ++i) {
        char str[100]; // Assuming max length of string
        scanf("%s", str);
        for (size_t j = 0; j < m; ++j) {
            scanf("%d %d %d", &a[i][j][0], &a[i][j][1], &a[i][j][2]);
        }
    }

    int val = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (i != j) {
                val = (val > refill(k, a[i], m, a[j], m)) ? val : refill(k, a[i], m, a[j], m);
            }
        }
    }

    printf("%d\n", val);
    return 0;
}
