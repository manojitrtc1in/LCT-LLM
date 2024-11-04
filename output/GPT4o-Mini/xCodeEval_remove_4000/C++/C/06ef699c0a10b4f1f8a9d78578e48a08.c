#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#define MOD 1000000007
#define INF (1LL << 62)
#define EPS 1e-10

typedef long long ll;
typedef struct {
    ll first, second;
} P;

typedef struct {
    int to, rev;
    ll cap;
} Edge;

typedef struct {
    Edge* edges;
    int size;
} Edges;

typedef struct {
    Edges* edges;
    int size;
} Graph;

typedef struct {
    ll* data;
    int size;
} Array;

typedef struct {
    Array* data;
    int size;
} Matrix;

void add_edge(Graph* G, int from, int to, ll cap, bool revFlag, ll revCap) {
    G->edges[from].edges[G->edges[from].size++] = (Edge){to, revCap, G->edges[to].size + (from == to)};
    if (revFlag) G->edges[to].edges[G->edges[to].size++] = (Edge){from, cap, G->edges[from].size - 1};
}

ll id0(Graph* G, ll v, ll t, ll f, bool* used) {
    if (v == t) return f;
    used[v] = true;
    for (int i = 0; i < G->edges[v].size; ++i) {
        Edge* e = &G->edges[v].edges[i];
        if (!used[e->to] && e->cap > 0) {
            ll d = id0(G, e->to, t, f < e->cap ? f : e->cap, used);
            if (d > 0) {
                e->cap -= d;
                G->edges[e->to].edges[e->rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

ll max_flow(Graph* G, ll s, ll t) {
    ll flow = 0;
    for (;;) {
        bool* used = (bool*)calloc(G->size, sizeof(bool));
        ll f = id0(G, s, t, INF, used);
        free(used);
        if (f == 0) return flow;
        flow += f;
    }
}

void Dijkstra(Graph* G, ll s, Array* d) {
    d->data = (ll*)malloc(G->size * sizeof(ll));
    for (int i = 0; i < G->size; i++) d->data[i] = INF;
    d->data[s] = 0;
    // Priority queue implementation needed
}

void solve(Graph* G, Array* a, ll n, ll k) {
    Array dp;
    dp.data = (ll*)calloc(k + 1, sizeof(ll));
    dp.size = k + 1;
    ll ans = 0;

    // Recursive solve function implementation needed
}

int main() {
    ll n, k;
    scanf("%lld %lld", &n, &k);
    
    Graph G;
    G.size = n;
    G.edges = (Edges*)malloc(n * sizeof(Edges));
    for (int i = 0; i < n; i++) {
        G.edges[i].size = 0;
        G.edges[i].edges = (Edge*)malloc(n * sizeof(Edge)); // Assuming maximum edges
    }

    Array a[n];
    for (int i = 0; i < n; i++) {
        ll t;
        scanf("%lld", &t);
        a[i].data = (ll*)malloc(t * sizeof(ll));
        for (int j = 0; j < t; j++) {
            scanf("%lld", &a[i].data[j]);
        }
    }

    solve(&G, a, n, k);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(G.edges[i].edges);
        free(a[i].data);
    }
    free(G.edges);
    free(dp.data);

    return 0;
}
