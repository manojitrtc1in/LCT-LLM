#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>

typedef long long int int64;
typedef unsigned long long int uint64;

#define MAX_N 1000
#define MAX_M 1000

typedef struct {
    size_t u;
    int64 w;
} edge_type;

typedef struct {
    edge_type edges[MAX_M];
    size_t size;
} graph;

typedef struct {
    size_t parent[MAX_N];
    size_t rank[MAX_N];
} UnionFind;

void init_union_find(UnionFind *uf, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        uf->parent[i] = i;
        uf->rank[i] = 0;
    }
}

size_t find(UnionFind *uf, size_t s) {
    if (uf->parent[s] != s) {
        uf->parent[s] = find(uf, uf->parent[s]);
    }
    return uf->parent[s];
}

void union_sets(UnionFind *uf, size_t i, size_t j) {
    i = find(uf, i);
    j = find(uf, j);
    if (i != j) {
        if (uf->rank[i] < uf->rank[j]) {
            uf->parent[i] = j;
        } else {
            uf->parent[j] = i;
            if (uf->rank[i] == uf->rank[j]) {
                uf->rank[i]++;
            }
        }
    }
}

void dijkstra(graph *g, size_t n, int64 *dist) {
    bool visited[MAX_N] = {false};
    for (size_t i = 0; i < n; ++i) {
        dist[i] = LLONG_MAX;
    }
    dist[0] = 0;

    for (size_t i = 0; i < n; ++i) {
        size_t u = -1;
        for (size_t j = 0; j < n; ++j) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }
        visited[u] = true;

        for (size_t j = 0; j < g->size; ++j) {
            if (g->edges[j].u == u) {
                size_t v = g->edges[j].u;
                int64 w = g->edges[j].w;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
}

int main() {
    size_t n, m;
    scanf("%zu %zu", &n, &m);

    graph g;
    g.size = 0;

    for (size_t j = 0; j < m; ++j) {
        size_t u, v;
        int64 w;
        scanf("%zu %zu %lld", &u, &v, &w);
        g.edges[g.size++] = (edge_type){v - 1, w};
        g.edges[g.size++] = (edge_type){u - 1, w};
    }

    int64 dist[MAX_N];
    dijkstra(&g, n, dist);

    if (dist[n - 1] != LLONG_MAX) {
        printf("%lld\n", dist[n - 1]);
    } else {
        printf("-1\n");
    }

    return 0;
}
