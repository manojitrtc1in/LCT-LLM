#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXN 202020
#define INF 1011111111

typedef struct {
    int a, b, c;
} tri;

typedef struct {
    int first, second;
} pii;

int g[MAXN][MAXN];
int g_size[MAXN];
int ct;
int sz[MAXN];
bool used[MAXN];
int n;
tri ans[MAXN * 2];
int ans_size = 0;

void go(int cur, int iter) {
    sz[cur] = 1;
    used[cur] = iter;
    int t = 0;
    for (int i = 0; i < g_size[cur]; i++) {
        int to = g[cur][i];
        if (used[to] != iter) {
            go(to, iter);
            sz[cur] += sz[to];
            t = (t > sz[to]) ? t : sz[to];
        }
    }
    t = (t > n - sz[cur]) ? t : (n - sz[cur]);
    if (t * 2 <= n) {
        ct = cur;
    }
}

pii st[MAXN];
int st_size = 0;

void dfs2(int cur, int p) {
    used[cur] = true;
    for (int i = 0; i < g_size[cur]; i++) {
        int to = g[cur][i];
        if (!used[to]) {
            dfs2(to, cur);
        }
    }
    st[st_size++] = (pii){cur, p};
}

void solve(int cur) {
    st_size = 0;
    dfs2(cur, -1);
    st_size--;
    int last = cur;
    for (int i = 0; i < st_size; i++) {
        int v = st[i].first;
        int par = st[i].second;
        if (par != cur) {
            ans[ans_size++] = (tri){ct, last, v};
            ans[ans_size++] = (tri){v, par, cur};
            last = v;
        }
    }
    if (last != cur) {
        ans[ans_size++] = (tri){ct, last, cur};
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x][g_size[x]++] = y;
        g[y][g_size[y]++] = x;
    }
    go(1, 1);
    memset(used, 0, sizeof(used));
    for (int i = 0; i < n; i++) {
        if (g_size[i] > 0) {
            used[i] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        if (used[i]) {
            ct = i;
            for (int j = 0; j < g_size[ct]; j++) {
                int to = g[ct][j];
                if (!used[to]) {
                    solve(to);
                }
            }
        }
    }
    printf("%d\n", ans_size);
    for (int i = 0; i < ans_size; i++) {
        printf("%d %d %d\n", ans[i].a, ans[i].b, ans[i].c);
    }
    return 0;
}
