#include <stdio.h>
#include <stdlib.h>

#define N (300 * 1000 + 13)
#define MOD 998244353

int n;
int g[N][N];
int dp[N][3];

int add(int a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
    if (a < 0)
        a += MOD;
    return a;
}

int mul(int a, int b) {
    return ((long long)a * b) % MOD;
}

void dfs(int v, int p) {
    dp[v][0] = 1;
    dp[v][1] = 1;
    int vals[N], init[N];
    int valsSize = 0, initSize = 0;
    for (int i = 0; i < n; i++) {
        int u = g[v][i];
        if (u != p) {
            dfs(u, v);
            vals[valsSize++] = add(dp[u][1], add(dp[u][2], dp[u][2]));
            init[initSize++] = add(dp[u][0], dp[u][1]);
            dp[v][0] = mul(dp[v][0], add(dp[u][1], add(dp[u][2], dp[u][2])));
            dp[v][1] = mul(dp[v][1], add(dp[u][1], dp[u][2]));
        }
    }
    dp[v][0] = add(dp[v][0], -dp[v][1]);

    int pr[N], su[N];
    pr[0] = 1;
    su[0] = 1;
    for (int i = 0; i < valsSize; i++) {
        pr[i + 1] = mul(pr[i], vals[i]);
    }
    for (int i = valsSize - 1; i >= 0; i--) {
        su[valsSize - i] = mul(su[valsSize - i - 1], vals[i]);
    }

    dp[v][2] = 0;
    for (int i = 0; i < valsSize; i++) {
        dp[v][2] = add(dp[v][2], mul(init[i], mul(pr[i], su[i + 1])));
    }
}

void solve() {
    dfs(0, -1);
    printf("%d\n", add(dp[0][1], dp[0][2]));
}

int main() {
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j] = 0;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            int v, u;
            scanf("%d%d", &v, &u);
            --v, --u;
            g[v][u] = 1;
            g[u][v] = 1;
        }
        solve();
    }
    return 0;
}
