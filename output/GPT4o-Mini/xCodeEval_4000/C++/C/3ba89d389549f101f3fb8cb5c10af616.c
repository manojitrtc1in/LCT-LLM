#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define MOD 1000000007
#define INF (1LL << 60)

typedef long long ll;
typedef struct {
    ll to, cap, rev;
} Edge;

typedef struct {
    Edge* edges;
    int size;
    int capacity;
} Edges;

typedef struct {
    Edges* adj;
    int size;
} Graph;

void init_graph(Graph* g, int n) {
    g->size = n;
    g->adj = (Edges*)malloc(n * sizeof(Edges));
    for (int i = 0; i < n; i++) {
        g->adj[i].edges = (Edge*)malloc(10 * sizeof(Edge));
        g->adj[i].size = 0;
        g->adj[i].capacity = 10;
    }
}

void add_edge(Graph* G, ll from, ll to, ll cap, bool revFlag, ll revCap) {
    if (G->adj[from].size >= G->adj[from].capacity) {
        G->adj[from].capacity *= 2;
        G->adj[from].edges = (Edge*)realloc(G->adj[from].edges, G->adj[from].capacity * sizeof(Edge));
    }
    G->adj[from].edges[G->adj[from].size++] = (Edge){to, cap, G->adj[to].size};

    if (revFlag) {
        if (G->adj[to].size >= G->adj[to].capacity) {
            G->adj[to].capacity *= 2;
            G->adj[to].edges = (Edge*)realloc(G->adj[to].edges, G->adj[to].capacity * sizeof(Edge));
        }
        G->adj[to].edges[G->adj[to].size++] = (Edge){from, revCap, G->adj[from].size - 1};
    }
}

ll max_flow_dfs(Graph* G, ll v, ll t, ll f, bool* used) {
    if (v == t) return f;
    used[v] = true;
    for (int i = 0; i < G->adj[v].size; ++i) {
        Edge* e = &G->adj[v].edges[i];
        if (!used[e->to] && e->cap > 0) {
            ll d = max_flow_dfs(G, e->to, t, f < e->cap ? f : e->cap, used);
            if (d > 0) {
                e->cap -= d;
                G->adj[e->to].edges[e->rev].cap += d;
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
        ll f = max_flow_dfs(G, s, t, INF, used);
        free(used);
        if (f == 0) return flow;
        flow += f;
    }
}

void dfs(Graph* g, ll v, ll t, bool* st, bool* used, ll s) {
    used[v] = true;
    if (v != s) st[v] = true;
    if (v == t) return;
    if (v != s) {
        for (int i = 0; i < g->adj[v].size; i++) {
            ll to = g->adj[v].edges[i].to;
            if (!used[to]) dfs(g, to, t, st, used, s);
        }
    } else {
        for (int i = 0; i < g->adj[v].size; i++) {
            ll to = g->adj[v].edges[i].to;
            if (used[to]) continue;
            dfs(g, to, t, st, used, s);
        }
    }
}

void solve() {
    ll n, m, a, b;
    scanf("%lld %lld %lld %lld", &n, &m, &a, &b);
    a--; b--;
    Graph g;
    init_graph(&g, n);
    for (int i = 0; i < m; i++) {
        ll u, v;
        scanf("%lld %lld", &u, &v);
        u--; v--;
        add_edge(&g, u, v, 1, true, 1);
    }
    bool* used = (bool*)calloc(n, sizeof(bool));
    bool* st = (bool*)calloc(n, sizeof(bool));
    dfs(&g, a, b, st, used, a);
    ll s = 0, t = 0;
    for (int i = 0; i < n; i++) {
        if (used[i]) s++;
        else t++;
    }
    s--;
    printf("%lld\n", s * t);
    free(used);
    free(st);
    for (int i = 0; i < n; i++) {
        free(g.adj[i].edges);
    }
    free(g.adj);
}

int main() {
    ll t;
    scanf("%lld", &t);
    for (int i = 0; i < t; i++) solve();
    return 0;
}
