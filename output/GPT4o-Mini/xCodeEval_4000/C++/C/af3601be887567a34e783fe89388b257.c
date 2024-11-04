#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define MAX_N 3007
#define INF INT_MAX
#define INF64 LLONG_MAX

typedef long long li;
typedef struct {
    int x;
    li y;
} Pair;

int n, k;
int a[MAX_N], b[MAX_N];
int g[MAX_N][MAX_N], g_size[MAX_N];

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
            Pair tmp[MAX_N] = {{-INF, -INF64}};
            for (int j = 0; j < siz[v]; j++) {
                for (int l = 0; l <= siz[u]; l++) {
                    Pair nw = {dp[v][j].x + dp[u][l].x, dp[v][j].y + dp[u][l].y};
                    if (nw.x > tmp[j + l].x || (nw.x == tmp[j + l].x && nw.y > tmp[j + l].y)) {
                        tmp[j + l] = nw;
                    }
                }
            }
            for (int j = 0; j < siz[v] + siz[u]; j++) {
                dp[v][j] = tmp[j];
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
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        if (!read()) break;
        solve();
    }
    return 0;
}
