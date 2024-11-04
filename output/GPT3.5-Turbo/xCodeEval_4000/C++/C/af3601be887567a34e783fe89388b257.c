#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 3007

typedef long long li;
typedef long double ld;

typedef struct {
    int x;
    int y;
} pt;

typedef struct {
    int a;
    int b;
} pair;

int n, k;
int a[N], b[N];
int g[N][N];
int g_size[N];

pair dp[N][N];
li val[N];
int siz[N];

pair make_pair(int x, int y) {
    pair p;
    p.a = x;
    p.b = y;
    return p;
}

pt mp(int x, int y) {
    pt p;
    p.x = x;
    p.y = y;
    return p;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

li max64(li a, li b) {
    return (a > b) ? a : b;
}

void dfs(int v, int p) {
    val[v] = b[v] - a[v];
    for (int i = 0; i < N; i++) {
        dp[v][i] = make_pair(-INF, -INF64);
    }
    dp[v][0] = make_pair(0, val[v]);
    siz[v] = 1;
    for (int i = 0; i < g_size[v]; i++) {
        int u = g[v][i];
        if (u != p) {
            dfs(u, v);
            pair tmp[N + N];
            for (int i = 0; i < siz[v]; i++) {
                for (int j = 0; j < siz[u] + 1; j++) {
                    pair nw = make_pair(dp[v][i].a + dp[u][j].a, dp[v][i].b + dp[u][j].b);
                    tmp[i + j] = max(tmp[i + j], nw);
                }
            }
            for (int i = 0; i < siz[v] + siz[u]; i++) {
                dp[v][i] = tmp[i];
            }
            siz[v] += siz[u];
            val[v] += val[u];
        }
    }
    for (int i = siz[v] - 1; i >= 0; i--) {
        dp[v][i + 1] = max(dp[v][i + 1], make_pair(dp[v][i].a + (dp[v][i].b > 0), 0ll));
    }
}

void solve() {
    dfs(0, -1);
    printf("%d\n", dp[0][k - 1].a + (dp[0][k - 1].b > 0));
}

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }
        for (int i = 0; i < n - 1; i++) {
            int v, u;
            scanf("%d%d", &v, &u);
            --v, --u;
            g[v][g_size[v]] = u;
            g[u][g_size[u]] = v;
            g_size[v]++;
            g_size[u]++;
        }
        solve();
    }
    return 0;
}
