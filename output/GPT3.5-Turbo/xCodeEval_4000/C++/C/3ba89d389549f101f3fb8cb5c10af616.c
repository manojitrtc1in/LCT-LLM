#include<stdio.h>
#include<stdlib.h>

#define MAX_N 100000
#define MAX_M 100000

typedef struct {
    int to;
    int cap;
    int rev;
} Edge;

typedef struct {
    Edge edges[MAX_M];
    int size;
} Edges;

typedef struct {
    Edges graph[MAX_N];
    int size;
} Graph;

void add_edge(Graph* G, int from, int to, int cap, int revFlag, int revCap) {
    Edges* edges = &(G->graph[from]);
    edges->edges[edges->size].to = to;
    edges->edges[edges->size].cap = cap;
    edges->edges[edges->size].rev = edges->size + 1;
    edges->size++;

    if (revFlag) {
        edges = &(G->graph[to]);
        edges->edges[edges->size].to = from;
        edges->edges[edges->size].cap = revCap;
        edges->edges[edges->size].rev = edges->size - 1;
        edges->size++;
    }
}

int max_flow_dfs(Graph* G, int v, int t, int f, int* used) {
    if (v == t)
        return f;
    used[v] = 1;
    int i;
    for (i = 0; i < G->graph[v].size; ++i) {
        Edge* e = &(G->graph[v].edges[i]);
        if (!used[e->to] && e->cap > 0) {
            int d = max_flow_dfs(G, e->to, t, (f < e->cap) ? f : e->cap, used);
            if (d > 0) {
                e->cap -= d;
                G->graph[e->to].edges[e->rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(Graph* G, int s, int t) {
    int flow = 0;
    for (;;) {
        int used[MAX_N] = {0};
        int f = max_flow_dfs(G, s, t, 1000000000, used);
        if (f == 0) {
            return flow;
        }
        flow += f;
    }
}

void solve() {
    int n, m, a, b;
    scanf("%d %d %d %d", &n, &m, &a, &b);
    a--; b--;
    Graph g;
    g.size = n;
    int i;
    for (i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        add_edge(&g, u, v, 1, 1, 1);
    }
    int used[MAX_N] = {0};
    int st[MAX_N] = {0};
    int s = 0, t = 0;
    dfs(&g, a, b, st, used, a);
    for (i = 0; i < n; i++) {
        if (used[i] == 1) s++;
        else if (used[i] == 0) t++;
    }
    s--;
    printf("%d\n", s * t);
}

int main() {
    int t;
    scanf("%d", &t);
    int i;
    for (i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
