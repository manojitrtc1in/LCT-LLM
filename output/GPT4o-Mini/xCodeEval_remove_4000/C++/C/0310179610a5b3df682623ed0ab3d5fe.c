#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define MOD 1000000007
#define INF (1LL << 61)
#define EPS 1e-10
#define MAX_SIZE 100000

typedef long long ll;
typedef struct {
    ll first;
    ll second;
} P;

typedef struct {
    int to, rev;
    ll cap;
} Edge;

typedef struct {
    Edge *edges;
    int size;
    int capacity;
} Edges;

typedef struct {
    Edges *adj;
    int size;
} Graph;

typedef struct {
    ll *data;
    int size;
} Array;

typedef struct {
    ll **data;
    int size;
} Matrix;

void init_graph(Graph *G, int n) {
    G->size = n;
    G->adj = (Edges *)malloc(n * sizeof(Edges));
    for (int i = 0; i < n; i++) {
        G->adj[i].edges = (Edge *)malloc(MAX_SIZE * sizeof(Edge));
        G->adj[i].size = 0;
        G->adj[i].capacity = MAX_SIZE;
    }
}

void add_edge(Graph *G, int from, int to, ll cap, bool revFlag, ll revCap) {
    G->adj[from].edges[G->adj[from].size++] = (Edge){to, cap, G->adj[to].size + (from == to)};
    if (revFlag) {
        G->adj[to].edges[G->adj[to].size++] = (Edge){from, revCap, G->adj[from].size - 1};
    }
}

ll id0(Graph *G, ll v, ll t, ll f, bool *used) {
    if (v == t) return f;
    used[v] = true;
    for (int i = 0; i < G->adj[v].size; ++i) {
        Edge *e = &G->adj[v].edges[i];
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

ll max_flow(Graph *G, ll s, ll t) {
    ll flow = 0;
    for (;;) {
        bool *used = (bool *)calloc(G->size, sizeof(bool));
        ll f = id0(G, s, t, INF, used);
        free(used);
        if (f == 0) return flow;
        flow += f;
    }
}

void divisor(ll n, Array *ret) {
    ret->data = (ll *)malloc(MAX_SIZE * sizeof(ll));
    ret->size = 0;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret->data[ret->size++] = i;
            if (i * i != n) ret->data[ret->size++] = n / i;
        }
    }
    // Sort ret->data (not implemented)
}

ll id1(ll a, ll b, ll *x, ll *y) {
    if (a < b) return id1(b, a, y, x);
    if (b > 0) {
        int g = id1(b, a % b, y, x);
        *y -= (a / b) * (*x);
        return g;
    } else {
        *x = 1, *y = 0;
        return a;
    }
}

int main() {
    ll m;
    scanf("%lld", &m);
    ll h1, a1, x1, y1;
    scanf("%lld %lld %lld %lld", &h1, &a1, &x1, &y1);
    
    Array t = {malloc(MAX_SIZE * sizeof(ll)), 0};
    bool used[MAX_SIZE] = {0};
    used[h1] = true;
    t.data[t.size++] = h1;
    
    while (true) {
        ll tmp = (t.data[t.size - 1] * x1 + y1) % m;
        t.data[t.size++] = tmp;
        if (used[tmp]) break;
        used[tmp] = true;
    }
    
    memset(used, 0, sizeof(used));
    ll h2, a2, x2, y2;
    scanf("%lld %lld %lld %lld", &h2, &a2, &x2, &y2);
    used[h2] = true;
    Array s = {malloc(MAX_SIZE * sizeof(ll)), 0};
    s.data[s.size++] = h2;
    
    while (true) {
        ll tmp = (s.data[s.size - 1] * x2 + y2) % m;
        s.data[s.size++] = tmp;
        if (used[tmp]) break;
        used[tmp] = true;
    }

    ll l1 = -1, l2 = -1;
    ll mn1 = INF, mn2 = INF;
    ll now = 0;

    while (true) {
        if (t.data[t.size - 1] == t.data[now]) {
            l1 = t.size - now - 1;
        }
        if (t.data[now] == a1) {
            mn1 = now;
            break;
        }
        now++;
        if (now == t.size) break;
    }

    now = 0;
    while (true) {
        if (s.data[s.size - 1] == s.data[now]) {
            l2 = s.size - now - 1;
        }
        if (s.data[now] == a2) {
            mn2 = now;
            break;
        }
        now++;
        if (now == s.size) break;
    }

    // Calculation logic (calc function) not implemented

    free(t.data);
    free(s.data);
    return 0;
}
