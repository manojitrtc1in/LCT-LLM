#include <stdio.h>
#include <stdlib.h>

#define N 3005

typedef struct edge {
    int v;
    struct edge *next;
} edge;

typedef struct {
    int first;
    long long second;
} pil;

edge pool[3 * N], *h[N];
int n, m, top;
int a[N], size[N];
pil f[N][N], tmp_f[N], nil;

void addedge(int u, int v) {
    edge *tmp = &pool[++top];
    tmp->v = v;
    tmp->next = h[u];
    h[u] = tmp;
}

pil make_pair(int first, long long second) {
    pil p;
    p.first = first;
    p.second = second;
    return p;
}

pil max(pil a, pil b) {
    if (a.first > b.first) {
        return a;
    } else if (a.first < b.first) {
        return b;
    } else {
        if (a.second > b.second) {
            return a;
        } else {
            return b;
        }
    }
}

void dfs(int u, int pre) {
    size[u] = 1;
    f[u][1] = make_pair(0, 1ll * a[u]);
    edge *tmp;
    for (tmp = h[u]; tmp; tmp = tmp->next) {
        int v = tmp->v;
        if (v == pre) continue;
        dfs(v, u);
        int i, j;
        for (i = 1; i <= size[u]; i++) tmp_f[i] = f[u][i], f[u][i] = make_pair(0, -0x3f3f3f3f3f3f3f3fll);
        for (i = 1; i <= size[u]; i++) {
            for (j = 1; j <= size[v]; j++) {
                if (i + j - 1 > m) break;
                f[u][i + j] = max(f[u][i + j], tmp_f[i] + f[v][j] + make_pair(f[v][j].second > 0, -f[v][j].second));
                f[u][i + j - 1] = max(f[u][i + j - 1], tmp_f[i] + f[v][j]);
            }
        }
        size[u] += size[v];
    }
}

void init() {
    int x, y;
    scanf("%d%d", &n, &m);
    int i;
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (i = 1; i <= n; i++) {
        scanf("%d", &x);
        a[i] = x - a[i];
    }
    for (i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        addedge(x, y);
        addedge(y, x);
    }
    for (i = 1; i <= n + 1; i++) for (int j = 1; j <= m + 1; j++) f[i][j] = nil;
    dfs(1, 0);
    printf("%d\n", f[1][m].first + (f[1][m].second > 0));
    top = -1;
    for (i = 1; i <= n + 1; i++) h[i] = NULL;
}

int main() {
    int T;
    scanf("%d", &T);
    int i;
    for (i = 1; i <= T; i++) init();
    return 0;
}