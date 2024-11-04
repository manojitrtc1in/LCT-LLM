#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 57
#define M 3007
#define MOD 998244353

typedef long long li;
typedef long double ld;

int n, m;
int a[N], w[N];

int add(int a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
    if (a < 0)
        a += MOD;
    return a;
}

int mul(int a, int b) {
    return a * (li)b % MOD;
}

int binpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int x) {
    return binpow(x, MOD - 2);
}

void solve() {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += w[i];
    int neg = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == 0)
            neg += w[i];
    int dp[N][N][2 * N];
    int rev[M];
    memset(dp, 0, sizeof(dp));
    memset(rev, 0, sizeof(rev));
    for (int i = 0; i < M; i++)
        rev[i] = inv(i);
    for (int z = 0; z < n; z++) {
        dp[0][0][w[z]] = 1;
        for (int i = 0; i < m; i++) {
            for (int pos = 0; pos <= i; pos++) {
                for (int val = 0; val < 2 * N; val++) {
                    if (dp[i][pos][val]) {
                        int p = mul(val, rev[sum + pos - (i - pos)]);
                        int pneg = mul(neg - (a[z] == 0 ? val : 0) - (i - pos), rev[sum + pos - (i - pos)]);
                        int ppos = add(1, -add(p, pneg));
                        if (a[z] == 0 && val > 0)
                            dp[i + 1][pos][val - 1] = add(dp[i + 1][pos][val - 1], mul(dp[i][pos][val], p));
                        if (a[z] == 1)
                            dp[i + 1][pos + 1][val + 1] = add(dp[i + 1][pos + 1][val + 1], mul(dp[i][pos][val], p));
                        dp[i + 1][pos + 1][val] = add(dp[i + 1][pos + 1][val], mul(dp[i][pos][val], ppos));
                        dp[i + 1][pos][val] = add(dp[i + 1][pos][val], mul(dp[i][pos][val], pneg));
                    }
                }
            }
        }
        int ans = 0;
        for (int pos = 0; pos <= m; pos++) {
            for (int val = 0; val < 2 * N; val++) {
                if (dp[m][pos][val]) {
                    ans = add(ans, mul(dp[m][pos][val], val));
                }
            }
        }
        printf("%d\n", ans);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int tt = clock();
    while (scanf("%d%d", &n, &m) == 2) {
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &w[i]);
        solve();
    }
    return 0;
}
