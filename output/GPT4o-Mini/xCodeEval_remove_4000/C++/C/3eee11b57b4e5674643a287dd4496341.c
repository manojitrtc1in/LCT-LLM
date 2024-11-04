#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define MAX_N 202020
#define MAX_M 100
#define INF INT_MAX

typedef long long ll;
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
    Edges* graph;
    int size;
} Graph;

ll sum[MAX_M][MAX_N];
int a[MAX_N];
int mp[404040];

void add_edge(Graph* G, int from, int to, ll cap, bool revFlag, ll revCap) {
    if (G[from].size >= G[from].capacity) {
        G[from].capacity *= 2;
        G[from].edges = realloc(G[from].edges, G[from].capacity * sizeof(Edge));
    }
    G[from].edges[G[from].size++] = (Edge){to, (ll)G[to].size + (from == to), cap};
    if (revFlag) {
        if (G[to].size >= G[to].capacity) {
            G[to].capacity *= 2;
            G[to].edges = realloc(G[to].edges, G[to].capacity * sizeof(Edge));
        }
        G[to].edges[G[to].size++] = (Edge){from, G[from].size - 1, revCap};
    }
}

ll id1(Graph* G, ll v, ll t, ll f, bool* used) {
    if (v == t) return f;
    used[v] = true;
    for (int i = 0; i < G[v].size; ++i) {
        Edge* e = &G[v].edges[i];
        if (!used[e->to] && e->cap > 0) {
            ll d = id1(G, e->to, t, f < e->cap ? f : e->cap, used);
            if (d > 0) {
                e->cap -= d;
                G[e->to].edges[e->rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

ll max_flow(Graph* G, ll s, ll t) {
    ll flow = 0;
    for (;;) {
        bool used[G->size];
        memset(used, false, sizeof(used));
        ll f = id1(G, s, t, INF, used);
        if (f == 0) return flow;
        flow += f;
    }
}

int find() {
    int mx = 0, ret = -1;
    for (int i = 0; i < MAX_M; i++) {
        if (sum[i][MAX_N - 1] > mx) {
            mx = sum[i][MAX_N - 1];
            ret = i;
        }
    }
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i]--;
    }

    Graph G[MAX_M];
    for (int i = 0; i < MAX_M; i++) {
        G[i].edges = malloc(10 * sizeof(Edge));
        G[i].size = 0;
        G[i].capacity = 10;
    }

    for (int i = 0; i < n; i++) {
        sum[a[i]][i + 1]++;
    }

    for (int i = 0; i < MAX_M; i++) {
        for (int j = 0; j < n; j++) {
            sum[i][j + 1] += sum[i][j];
        }
    }

    int i = find();
    int ans = 0;
    memset(mp, -1, sizeof(mp));

    for (int j = 0; j < MAX_M; j++) {
        if (i == j) continue;
        if (G[i].size == 0 || G[j].size == 0) continue;

        int x = 0, y = 0;
        int now = 202020;
        mp[202020] = 0;
        int era[404040];
        int era_size = 0;

        while (true) {
            int tmp_x = (x < G[i].size) ? G[i].edges[x].to : -1;
            int tmp_y = (y < G[j].size) ? G[j].edges[y].to : -1;

            if (tmp_x != -1 && tmp_y != -1) {
                if (tmp_x < tmp_y) {
                    now++;
                    x++;
                } else {
                    now--;
                    y++;
                }
            } else if (tmp_x != -1) {
                now++;
                x++;
            } else if (tmp_y != -1) {
                now--;
                y++;
            } else {
                break;
            }

            if (mp[now] != -1) {
                if (tmp_x == -1 && tmp_y == -1) {
                    ans = (ans > n - mp[now]) ? ans : n - mp[now];
                } else {
                    ans = (ans > tmp_y - mp[now]) ? ans : tmp_y - mp[now];
                }
            } else {
                mp[now] = tmp_y + 1;
                era[era_size++] = now;
            }
        }

        for (int k = 0; k < era_size; k++) {
            mp[era[k]] = -1;
        }
    }

    printf("%d\n", ans);
    return 0;
}
