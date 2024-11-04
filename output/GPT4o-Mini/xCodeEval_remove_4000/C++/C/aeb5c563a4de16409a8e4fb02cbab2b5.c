#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

typedef long long ll;
typedef struct {
    ll first, second;
} P;

#define MOD 1000000007
#define INF (1LL << 62)

typedef struct {
    int to, rev;
    ll cap;
} Edge;

typedef struct {
    Edge* edges;
    int size;
    int capacity;
} Edges;

typedef struct {
    Edges* edges;
    int size;
    int capacity;
} Graph;

void init_graph(Graph* G, int capacity) {
    G->edges = (Edges*)malloc(capacity * sizeof(Edges));
    G->size = 0;
    G->capacity = capacity;
    for (int i = 0; i < capacity; i++) {
        G->edges[i].edges = NULL;
        G->edges[i].size = 0;
        G->edges[i].capacity = 0;
    }
}

void add_edge(Graph* G, int from, int to, ll cap, bool revFlag, ll revCap) {
    if (G->edges[from].size == G->edges[from].capacity) {
        G->edges[from].capacity = G->edges[from].capacity ? G->edges[from].capacity * 2 : 1;
        G->edges[from].edges = (Edge*)realloc(G->edges[from].edges, G->edges[from].capacity * sizeof(Edge));
    }
    G->edges[from].edges[G->edges[from].size++] = (Edge){to, cap, G->edges[to].size + (from == to)};
    if (revFlag) {
        if (G->edges[to].size == G->edges[to].capacity) {
            G->edges[to].capacity = G->edges[to].capacity ? G->edges[to].capacity * 2 : 1;
            G->edges[to].edges = (Edge*)realloc(G->edges[to].edges, G->edges[to].capacity * sizeof(Edge));
        }
        G->edges[to].edges[G->edges[to].size++] = (Edge){from, revCap, G->edges[from].size - 1};
    }
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

void Dijkstra(Graph* G, ll s, ll* d) {
    for (int i = 0; i < G->size; i++) d[i] = INF;
    d[s] = 0;
    // Priority queue implementation is omitted for simplicity
}

int main() {
    ll n, k;
    scanf("%lld %lld", &n, &k);
    Graph a;
    init_graph(&a, n);
    
    for (ll i = 0; i < n; i++) {
        ll t;
        scanf("%lld", &t);
        for (ll j = 0; j < t; j++) {
            ll tmp;
            scanf("%lld", &tmp);
            // Add logic to handle the array size limit
        }
    }
    
    ll* w = (ll*)malloc(n * sizeof(ll));
    for (ll i = 0; i < n; i++) {
        // Calculate w[i]
    }
    
    ll ans = 0;
    // Implement the solve function logic here
    
    printf("%lld\n", ans);
    
    // Free allocated memory
    free(a.edges);
    free(w);
    
    return 0;
}
