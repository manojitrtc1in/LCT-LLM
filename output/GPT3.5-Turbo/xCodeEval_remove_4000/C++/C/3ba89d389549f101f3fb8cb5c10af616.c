#include <stdio.h>
#include <stdlib.h>

#define ll long long

typedef struct Edge {
    ll to, cap, rev;
} Edge;

typedef struct Graph {
    ll size;
    Edge** edges;
    ll* edges_count;
} Graph;

Graph* createGraph(ll size) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->size = size;
    graph->edges = (Edge**)malloc(size * sizeof(Edge*));
    graph->edges_count = (ll*)calloc(size, sizeof(ll));
    return graph;
}

void add_edge(Graph* graph, ll from, ll to, ll cap, ll revCap) {
    Edge* edge = (Edge*)malloc(sizeof(Edge));
    edge->to = to;
    edge->cap = cap;
    edge->rev = graph->edges_count[to];
    graph->edges[from][graph->edges_count[from]] = *edge;
    graph->edges_count[from]++;
    Edge* revEdge = (Edge*)malloc(sizeof(Edge));
    revEdge->to = from;
    revEdge->cap = revCap;
    revEdge->rev = graph->edges_count[from] - 1;
    graph->edges[to][graph->edges_count[to]] = *revEdge;
    graph->edges_count[to]++;
}

void dfs(Graph* graph, ll v, ll t, ll* used, ll* st, ll* stSize, ll s) {
    used[v] = 1;
    if (v != s) {
        st[*stSize] = v;
        (*stSize)++;
    }
    if (v == t) {
        return;
    }
    if (v != s) {
        for (ll i = 0; i < graph->edges_count[v]; ++i) {
            Edge* e = &(graph->edges[v][i]);
            if (!used[e->to] && e->cap > 0) {
                dfs(graph, e->to, t, used, st, stSize, s);
            } else if (used[e->to] == 2) {
                st[*stSize] = t;
                (*stSize)++;
            }
        }
    } else {
        for (ll i = 0; i < graph->edges_count[v]; ++i) {
            Edge* e = &(graph->edges[v][i]);
            if (used[e->to] != 0) {
                continue;
            }
            dfs(graph, e->to, t, used, st, stSize, s);
            if (st[*stSize - 1] == t) {
                for (ll j = 0; j < *stSize; ++j) {
                    used[st[j]] = 2;
                }
            }
            *stSize = 0;
        }
    }
}

void solve() {
    ll n, m, a, b;
    scanf("%lld %lld %lld %lld", &n, &m, &a, &b);
    a--; b--;
    Graph* g = createGraph(n);
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        scanf("%lld %lld", &u, &v);
        u--; v--;
        add_edge(g, u, v, 1, 1);
    }
    ll* used = (ll*)calloc(n, sizeof(ll));
    ll* st = (ll*)malloc(n * sizeof(ll));
    ll stSize = 0;
    dfs(g, a, b, used, st, &stSize, a);
    ll s = 0, t = 0;
    for (ll i = 0; i < n; ++i) {
        if (used[i] == 1) {
            s++;
        } else if (used[i] == 0) {
            t++;
        }
    }
    s--;
    printf("%lld\n", s * t);
}

int main() {
    ll t;
    scanf("%lld", &t);
    for (ll i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}
