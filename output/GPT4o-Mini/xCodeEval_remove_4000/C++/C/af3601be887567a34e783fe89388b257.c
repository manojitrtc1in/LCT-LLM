#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef long long li;
typedef long double ld;

#define MAX_N 3007
#define INF (int)(1e9)
#define INF64 (li)(1e18)

int n, k;
int a[MAX_N], b[MAX_N];
int g[MAX_N][MAX_N];
int g_size[MAX_N];

typedef struct {
    int x;
    li y;
} Pair;

Pair dp[MAX_N][MAX_N];
li val[MAX_N];
int siz[MAX_N];

void dfs(int v, int p) {
    val[v] = b[v] - a[v];
    for (int i = 0; i <= n; i++) {
        dp[v][i].x = -INF;
        dp[v][i].y = -INF64;
    }
    dp[v][0].x = 0;
    dp[v][0].y = val[v];
    siz[v] = 1;

    for (int i = 0; i < g_size[v]; i++) {
        int u = g[v][i];
        if (u != p) {
            dfs(u, v);
            Pair tmp[MAX_N] = { { -INF, -INF64 } };

            for (int i = 0; i < siz[v]; i++) {
                for (int j = 0; j <= siz[u]; j++) {
                    Pair nw = { dp[v][i].x + dp[u][j].x, dp[v][i].y + dp[u][j].y };
                    if (nw.x > tmp[i + j].x || (nw.x == tmp[i + j].x && nw.y > tmp[i + j].y)) {
                        tmp[i + j] = nw;
                    }
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
        dp[v][i + 1].x = fmax(dp[v][i + 1].x, dp[v][i].x + (dp[v][i].y > 0));
        dp[v][i + 1].y = 0;
    }
}

void solve() {
    dfs(0, -1);
    printf("%d\n", dp[0][k - 1].x + (dp[0][k - 1].y > 0));
}

int read() {
    if (scanf("%d%d", &n, &k) != 2) return 0;
    for (int i = 0; i < n; i++) {
        g_size[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        scanf("%d%d", &v, &u);
        v--; u--;
        g[v][g_size[v]++] = u;
        g[u][g_size[u]++] = v;
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        if (!read()) break;
        solve();
    }
    return 0;
}
