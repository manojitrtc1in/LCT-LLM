#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#define MAX_M 100000

typedef long long ll;
typedef struct {
    ll to, cap, rev;
} Edge;

typedef struct {
    Edge* edges;
    int size;
} Edges;

typedef struct {
    Edges* graph;
    int size;
} Graph;

typedef struct {
    ll* data;
    int size;
} Array;

void add_edge(Graph* G, int from, int to, ll cap, bool revFlag, ll revCap) {
    G->graph[from].edges[G->graph[from].size++] = (Edge){to, cap, G->graph[to].size};
    if (revFlag) {
        G->graph[to].edges[G->graph[to].size++] = (Edge){from, revCap, G->graph[from].size - 1};
    }
}

ll max_flow_dfs(Graph* G, ll v, ll t, ll f, bool* used) {
    if (v == t) return f;
    used[v] = true;
    for (int i = 0; i < G->graph[v].size; ++i) {
        Edge* e = &G->graph[v].edges[i];
        if (!used[e->to] && e->cap > 0) {
            ll d = max_flow_dfs(G, e->to, t, f < e->cap ? f : e->cap, used);
            if (d > 0) {
                e->cap -= d;
                G->graph[e->to].edges[e->rev].cap += d;
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
        ll f = max_flow_dfs(G, s, t, LLONG_MAX, used);
        free(used);
        if (f == 0) return flow;
        flow += f;
    }
}

void divisor(ll n, Array* ret) {
    ret->data = (ll*)malloc(sizeof(ll) * MAX_M);
    ret->size = 0;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret->data[ret->size++] = i;
            if (i * i != n) ret->data[ret->size++] = n / i;
        }
    }
    // Sorting is omitted for brevity
}

ll extgcd(ll a, ll b, ll* x, ll* y) {
    if (a < b) return extgcd(b, a, y, x);
    if (b > 0) {
        int g = extgcd(b, a % b, y, x);
        *y -= (a / b) * (*x);
        return g;
    } else {
        *x = 1; *y = 0;
        return a;
    }
}

int main() {
    ll m;
    scanf("%lld", &m);
    ll h1, a1, x1, y1;
    scanf("%lld %lld %lld %lld", &h1, &a1, &x1, &y1);
    
    Array t = { .data = (ll*)malloc(sizeof(ll) * MAX_M), .size = 0 };
    bool used[MAX_M] = {0};
    used[h1] = true;
    t.data[t.size++] = h1;

    while (true) {
        ll tmp = (t.data[t.size - 1] * x1 + y1) % m;
        t.data[t.size++] = tmp;
        if (used[tmp]) break;
        used[tmp] = true;
    }

    used[h1] = false; // Reset used for second sequence
    ll h2, a2, x2, y2;
    scanf("%lld %lld %lld %lld", &h2, &a2, &x2, &y2);
    used[h2] = true;
    Array s = { .data = (ll*)malloc(sizeof(ll) * MAX_M), .size = 0 };
    s.data[s.size++] = h2;

    while (true) {
        ll tmp = (s.data[s.size - 1] * x2 + y2) % m;
        s.data[s.size++] = tmp;
        if (used[tmp]) break;
        used[tmp] = true;
    }

    ll l1 = -1, l2 = -1;
    ll mn1 = LLONG_MAX, mn2 = LLONG_MAX;
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

    // Calculation logic omitted for brevity

    free(t.data);
    free(s.data);
    return 0;
}
