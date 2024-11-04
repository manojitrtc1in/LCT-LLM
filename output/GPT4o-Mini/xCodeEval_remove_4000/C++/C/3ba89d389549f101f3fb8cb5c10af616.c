#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <set>

typedef long long ll;
typedef struct {
    ll to, cap, rev;
} Edge;

typedef struct {
    Edge *edges;
    size_t size;
    size_t capacity;
} Edges;

typedef struct {
    Edges *adj;
    size_t size;
} Graph;

typedef struct {
    ll *data;
    size_t size;
} Array;

typedef struct {
    Array *data;
    size_t size;
} Matrix;

const long long INF = 1LL << 60;

void init_graph(Graph *g, size_t n) {
    g->size = n;
    g->adj = (Edges *)malloc(n * sizeof(Edges));
    for (size_t i = 0; i < n; i++) {
        g->adj[i].edges = NULL;
        g->adj[i].size = 0;
        g->adj[i].capacity = 0;
    }
}

void add_edge(Graph *G, ll from, ll to, ll cap, bool revFlag, ll revCap) {
    if (G->adj[from].size == G->adj[from].capacity) {
        G->adj[from].capacity = G->adj[from].capacity ? G->adj[from].capacity * 2 : 1;
        G->adj[from].edges = (Edge *)realloc(G->adj[from].edges, G->adj[from].capacity * sizeof(Edge));
    }
    G->adj[from].edges[G->adj[from].size++] = (Edge){to, cap, G->adj[to].size};

    if (revFlag) {
        if (G->adj[to].size == G->adj[to].capacity) {
            G->adj[to].capacity = G->adj[to].capacity ? G->adj[to].capacity * 2 : 1;
            G->adj[to].edges = (Edge *)realloc(G->adj[to].edges, G->adj[to].capacity * sizeof(Edge));
        }
        G->adj[to].edges[G->adj[to].size++] = (Edge){from, revCap, G->adj[from].size - 1};
    }
}

ll id1(Graph *G, ll v, ll t, ll f, bool *used) {
    if (v == t) return f;
    used[v] = true;
    for (size_t i = 0; i < G->adj[v].size; ++i) {
        Edge *e = &G->adj[v].edges[i];
        if (!used[e->to] && e->cap > 0) {
            ll d = id1(G, e->to, t, f < e->cap ? f : e->cap, used);
            if (d > 0) {
                e->cap -= d;
                G->adj[e->to].edges[e->rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

ll max_flow(Graph *G, ll s, ll t) {
    ll flow = 0;
    for (;;) {
        bool *used = (bool *)calloc(G->size, sizeof(bool));
        ll f = id1(G, s, t, INF, used);
        if (f == 0) {
            free(used);
            return flow;
        }
        flow += f;
        free(used);
    }
}

void dfs(Graph *g, ll v, ll t, set<ll> *st, ll *used, ll s) {
    used[v] = 1;
    if (v != s) st->insert(v);
    if (v == t) return;
    if (v != s) {
        for (size_t i = 0; i < g->adj[v].size; i++) {
            ll to = g->adj[v].edges[i].to;
            if (used[to] == 0) dfs(g, to, t, st, used, s);
            else if (used[to] == 2) st->insert(t);
        }
    } else {
        for (size_t i = 0; i < g->adj[v].size; i++) {
            ll to = g->adj[v].edges[i].to;
            if (used[to] != 0) continue;
            dfs(g, to, t, st, used, s);
            if (st->count(t)) {
                for (auto itr : *st) used[itr] = 2;
            }
            st->clear();
        }
    }
}

void solve() {
    ll n, m, a, b;
    scanf("%lld %lld %lld %lld", &n, &m, &a, &b);
    a--; b--;
    Graph g;
    init_graph(&g, n);
    for (ll i = 0; i < m; i++) {
        ll u, v;
        scanf("%lld %lld", &u, &v);
        u--; v--;
        add_edge(&g, u, v, 1, true, 1);
    }
    ll *used = (ll *)calloc(n, sizeof(ll));
    set<ll> st;
    dfs(&g, a, b, &st, used, a);
    ll s = 0, t = 0;
    for (ll i = 0; i < n; i++) {
        if (used[i] == 1) s++;
        else if (used[i] == 0) t++;
    }
    s--;
    printf("%lld\n", s * t);
    free(used);
    for (size_t i = 0; i < g.size; i++) {
        free(g.adj[i].edges);
    }
    free(g.adj);
}

int main() {
    ll t;
    scanf("%lld", &t);
    for (ll i = 0; i < t; i++) solve();
    return 0;
}
