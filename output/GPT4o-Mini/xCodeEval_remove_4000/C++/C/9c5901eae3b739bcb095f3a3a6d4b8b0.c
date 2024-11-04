#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef long long li;
typedef long double ld;
#define MAXN 300000 + 13
#define MOD 998244353

int n;
int g[MAXN][2]; // Adjacency list representation
int dp[MAXN][3];

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
    int vals[MAXN], init[MAXN];
    int vals_count = 0, init_count = 0;

    for (int i = 0; i < n; i++) {
        if (g[i][0] == v && g[i][1] != p) {
            dfs(g[i][1], v);
            vals[vals_count++] = add(dp[g[i][1]][1], add(dp[g[i][1]][2], dp[g[i][1]][2]));
            init[init_count++] = add(dp[g[i][1]][0], dp[g[i][1]][1]);
            dp[v][0] = mul(dp[v][0], add(dp[g[i][1]][1], add(dp[g[i][1]][2], dp[g[i][1]][2])));
            dp[v][1] = mul(dp[v][1], add(dp[g[i][1]][1], dp[g[i][1]][2]));
        }
    }
    dp[v][0] = add(dp[v][0], -dp[v][1]);

    int pr[MAXN], su[MAXN];
    pr[0] = 1;
    for (int i = 0; i < vals_count; i++) {
        pr[i + 1] = mul(pr[i], vals[i]);
    }
    for (int i = vals_count - 1; i >= 0; i--) {
        su[vals_count - i] = mul(su[vals_count - i - 1], vals[i]);
    }

    dp[v][2] = 0;
    for (int i = 0; i < vals_count; i++) {
        dp[v][2] = add(dp[v][2], mul(init[i], mul(pr[i], su[i + 1])));
    }
}

int read() {
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        g[i][0] = g[i][1] = -1; // Clear adjacency list
    }
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        scanf("%d%d", &v, &u);
        --v; --u;
        g[v][0] = u; // Assuming a simple representation
        g[u][0] = v; // Assuming a simple representation
    }
    return 1;
}

void solve() {
    dfs(0, -1);
    printf("%d\n", add(dp[0][1], dp[0][2]));
}

int main() {
    freopen("input.txt", "r", stdin);
    clock_t tt = clock();

    while (read()) {
        solve();
        fprintf(stderr, "TIME = %ld\n", clock() - tt);
        tt = clock();
    }
    return 0;
}
