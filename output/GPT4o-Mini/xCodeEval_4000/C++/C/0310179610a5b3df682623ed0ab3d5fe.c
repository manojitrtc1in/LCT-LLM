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
    int capacity;
} Edges;

typedef struct {
    Edges* graph;
    int size;
} Graph;

typedef struct {
    ll* data;
    int size;
} Array;

void init_graph(Graph* G, int n) {
    G->size = n;
    G->graph = (Edges*)malloc(n * sizeof(Edges));
    for (int i = 0; i < n; i++) {
        G->graph[i].edges = (Edge*)malloc(10 * sizeof(Edge));
        G->graph[i].size = 0;
        G->graph[i].capacity = 10;
    }
}

void add_edge(Graph* G, int from, int to, ll cap, bool revFlag, ll revCap) {
    if (G->graph[from].size == G->graph[from].capacity) {
        G->graph[from].capacity *= 2;
        G->graph[from].edges = (Edge*)realloc(G->graph[from].edges, G->graph[from].capacity * sizeof(Edge));
    }
    G->graph[from].edges[G->graph[from].size++] = (Edge){to, cap, G->graph[to].size};
    
    if (revFlag) {
        if (G->graph[to].size == G->graph[to].capacity) {
            G->graph[to].capacity *= 2;
            G->graph[to].edges = (Edge*)realloc(G->graph[to].edges, G->graph[to].capacity * sizeof(Edge));
        }
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
    ret->data = (ll*)malloc(MAX_M * sizeof(ll));
    ret->size = 0;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret->data[ret->size++] = i;
            if (i * i != n) ret->data[ret->size++] = n / i;
        }
    }
    // Sort the array (simple bubble sort for demonstration)
    for (int i = 0; i < ret->size - 1; i++) {
        for (int j = 0; j < ret->size - i - 1; j++) {
            if (ret->data[j] > ret->data[j + 1]) {
                ll temp = ret->data[j];
                ret->data[j] = ret->data[j + 1];
                ret->data[j + 1] = temp;
            }
        }
    }
}

ll extgcd(ll a, ll b, ll* x, ll* y) {
    if (a < b) return extgcd(b, a, y, x);
    if (b > 0) {
        ll g = extgcd(b, a % b, y, x);
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
    
    Array t = { .data = (ll*)malloc(MAX_M * sizeof(ll)), .size = 0 };
    bool used[MAX_M] = {0};
    used[h1] = true;
    t.data[t.size++] = h1;
    
    while (true) {
        ll tmp = (t.data[t.size - 1] * x1 + y1) % m;
        t.data[t.size++] = tmp;
        if (used[tmp]) break;
        used[tmp] = true;
    }
    
    used[0] = {0};
    ll h2, a2, x2, y2;
    scanf("%lld %lld %lld %lld", &h2, &a2, &x2, &y2);
    used[h2] = true;
    Array s = { .data = (ll*)malloc(MAX_M * sizeof(ll)), .size = 0 };
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

    ll result = -1;
    if (mn1 != LLONG_MAX && mn2 != LLONG_MAX) {
        if (mn1 == mn2) {
            result = mn1;
        } else if (mn1 > mn2 && l2 == -1) {
            result = -1;
        } else if (mn1 < mn2 && l1 == -1) {
            result = -1;
        } else if (l1 == -1) {
            if ((mn1 - mn2) % l2 == 0) result = mn1;
        } else if (l2 == -1) {
            if ((mn2 - mn1) % l1 == 0) result = mn2;
        } else if (l1 == l2) {
            if (abs(mn1 - mn2) % l1 == 0) result = fmax(mn1, mn2);
        } else if (mn2 > mn1 && (mn2 - mn1) % l1 == 0) {
            result = mn2;
        } else if (mn1 > mn2 && (mn1 - mn2) % l2 == 0) {
            result = mn1;
        } else if (abs(mn2 - mn1) % abs(gcd(l1, l2)) != 0) {
            result = -1;
        } else {
            ll x, y;
            ll g = extgcd(l1, l2, &x, &y);
            x *= (mn2 - mn1) / g;
            y *= (mn2 - mn1) / g;
            if (x * l1 + mn1 < fmax(mn1, mn2)) {
                x += ((fmax(mn1, mn2) - x * l1 + mn1 + l1 - 1) / l1 + l2 / g - 1) / (l2 / g) * (l2 / g);
            }
            if (x * l1 + mn1 >= fmax(mn1, mn2)) {
                x -= (x * l1 + mn1 - fmax(mn1, mn2)) / l1 / (l2 / g) * (l2 / g);
            }
            result = x * l1 + mn1;
        }
    }

    printf("%lld\n", result);
    free(t.data);
    free(s.data);
    for (int i = 0; i < MAX_M; i++) {
        free(G.graph[i].edges);
    }
    free(G.graph);
    return 0;
}
