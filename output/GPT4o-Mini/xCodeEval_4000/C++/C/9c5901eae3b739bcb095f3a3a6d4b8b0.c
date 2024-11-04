#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_N 300000 + 13
#define MOD 998244353

typedef long long li;

int n;
int g[MAX_N][2]; // Adjacency list representation
int dp[MAX_N][3];

int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    if (a < 0) a += MOD;
    return a;
}

int mul(int a, int b) {
    return a * (li)b % MOD;
}

void dfs(int v, int p) {
    dp[v][0] = 1;
    dp[v][1] = 1;
    int vals[MAX_N], init[MAX_N];
    int vals_size = 0, init_size = 0;

    for (int i = 0; i < n; i++) {
        if (g[v][i] != p) {
            dfs(g[v][i], v);
            vals[vals_size++] = add(dp[g[v][i]][1], add(dp[g[v][i]][2], dp[g[v][i]][2]));
            init[init_size++] = add(dp[g[v][i]][0], dp[g[v][i]][1]);
            dp[v][0] = mul(dp[v][0], add(dp[g[v][i]][1], add(dp[g[v][i]][2], dp[g[v][i]][2])));
            dp[v][1] = mul(dp[v][1], add(dp[g[v][i]][1], dp[g[v][i]][2]));
        }
    }
    dp[v][0] = add(dp[v][0], -dp[v][1]);

    int pr[MAX_N], su[MAX_N];
    pr[0] = 1;
    for (int i = 0; i < vals_size; i++) {
        pr[i + 1] = mul(pr[i], vals[i]);
    }
    for (int i = vals_size - 1; i >= 0; i--) {
        su[vals_size - i] = mul(su[vals_size - i - 1], vals[i]);
    }

    dp[v][2] = 0;
    for (int i = 0; i < vals_size; i++) {
        dp[v][2] = add(dp[v][2], mul(init[i], mul(pr[i], su[i + 1])));
    }
}

int read() {
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        g[i][0] = g[i][1] = 0; // Clear adjacency list
    }
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        scanf("%d%d", &v, &u);
        --v; --u;
        g[v][g[v][0]++] = u; // Add edge
        g[u][g[u][0]++] = v; // Add edge
    }
    return 1;
}

void solve() {
    dfs(0, -1);
    printf("%d\n", add(dp[0][1], dp[0][2]));
}

int main() {
    while (read()) {
        solve();
    }
    return 0;
}
