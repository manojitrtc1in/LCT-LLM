#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <string.h>

typedef long long ll;
typedef struct {
    ll first, second;
} P;

#define MOD 1000000007
#define INF (1LL << 61)

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
    Edges* adj;
    int size;
} Graph;

void init_graph(Graph* G, int n) {
    G->size = n;
    G->adj = (Edges*)malloc(n * sizeof(Edges));
    for (int i = 0; i < n; i++) {
        G->adj[i].edges = (Edge*)malloc(10 * sizeof(Edge));
        G->adj[i].size = 0;
        G->adj[i].capacity = 10;
    }
}

void add_edge(Graph* G, int from, int to, ll cap, bool revFlag, ll revCap) {
    if (G->adj[from].size >= G->adj[from].capacity) {
        G->adj[from].capacity *= 2;
        G->adj[from].edges = (Edge*)realloc(G->adj[from].edges, G->adj[from].capacity * sizeof(Edge));
    }
    G->adj[from].edges[G->adj[from].size++] = (Edge){to, cap, G->adj[to].size + (from == to)};
    
    if (revFlag) {
        if (G->adj[to].size >= G->adj[to].capacity) {
            G->adj[to].capacity *= 2;
            G->adj[to].edges = (Edge*)realloc(G->adj[to].edges, G->adj[to].capacity * sizeof(Edge));
        }
        G->adj[to].edges[G->adj[to].size++] = (Edge){from, revCap, G->adj[from].size - 1};
    }
}

ll id0(Graph* G, ll v, ll t, ll f, bool* used) {
    if (v == t) return f;
    used[v] = true;
    for (int i = 0; i < G->adj[v].size; ++i) {
        Edge* e = &G->adj[v].edges[i];
        if (!used[e->to] && e->cap > 0) {
            ll d = id0(G, e->to, t, f < e->cap ? f : e->cap, used);
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
        ll f = id0(G, s, t, INF, used);
        free(used);
        if (f == 0) return flow;
        flow += f;
    }
}

void divisor(ll n, ll* ret, int* count) {
    *count = 0;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret[(*count)++] = i;
            if (i * i != n) ret[(*count)++] = n / i;
        }
    }
    // Sort ret array
    qsort(ret, *count, sizeof(ll), cmp);
}

int cmp(const void* a, const void* b) {
    return (*(ll*)a - *(ll*)b);
}

int main() {
    ll m;
    scanf("%lld", &m);
    ll h1, a1, x1, y1;
    scanf("%lld %lld %lld %lld", &h1, &a1, &x1, &y1);
    
    ll* t = (ll*)malloc(m * sizeof(ll));
    bool* used = (bool*)calloc(m, sizeof(bool));
    t[0] = h1;
    used[h1] = true;
    int t_size = 1;

    while (true) {
        ll tmp = (t[t_size - 1] * x1 + y1) % m;
        t[t_size++] = tmp;
        if (used[tmp]) break;
        used[tmp] = true;
    }

    used = (bool*)calloc(m, sizeof(bool));
    ll h2, a2, x2, y2;
    scanf("%lld %lld %lld %lld", &h2, &a2, &x2, &y2);
    
    used[h2] = true;
    ll* s = (ll*)malloc(m * sizeof(ll));
    s[0] = h2;
    int s_size = 1;

    while (true) {
        ll tmp = (s[s_size - 1] * x2 + y2) % m;
        s[s_size++] = tmp;
        if (used[tmp]) break;
        used[tmp] = true;
    }

    ll l1 = -1, l2 = -1;
    ll mn1 = INF, mn2 = INF;
    ll now = 0;

    while (true) {
        if (t[t_size - 1] == t[now]) {
            l1 = t_size - now - 1;
        }
        if (t[now] == a1) {
            mn1 = now;
            break;
        }
        now++;
        if (now == t_size) break;
    }

    now = 0;
    while (true) {
        if (s[s_size - 1] == s[now]) {
            l2 = s_size - now - 1;
        }
        if (s[now] == a2) {
            mn2 = now;
            break;
        }
        now++;
        if (now == s_size) break;
    }

    // Calculation logic here...

    free(t);
    free(s);
    free(used);
    return 0;
}
