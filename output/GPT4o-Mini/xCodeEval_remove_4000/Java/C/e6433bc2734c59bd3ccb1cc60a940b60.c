#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 998244353
#define MAX_N 1000

long pow(long a, long n, long mod) {
    long ret = 1;
    for (int x = 63 - __builtin_clzll(n); x >= 0; x--) {
        ret = ret * ret % mod;
        if (n & (1LL << x)) ret = ret * a % mod;
    }
    return ret;
}

long invl(long a, long mod) {
    long b = mod, p = 1, q = 0;
    while (b > 0) {
        long c = a / b;
        long d = a; a = b; b = d % b;
        d = p; p = q; q = d - c * q;
    }
    return p < 0 ? p + mod : p;
}

long C(int n, int r, int mod, int fif[2][MAX_N]) {
    if (n < 0 || r < 0 || r > n) return 0;
    return (long)fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod;
}

void id0(int n, int mod, int f[MAX_N], int invf[MAX_N]) {
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = (long)f[i - 1] * i % mod;
    }
    long a = f[n], b = mod, p = 1, q = 0;
    while (b > 0) {
        long c = a / b;
        long d = a; a = b; b = d % b;
        d = p; p = q; q = d - c * q;
    }
    invf[n] = (p < 0 ? p + mod : p);
    for (int i = n - 1; i >= 0; i--) {
        invf[i] = (long)invf[i + 1] * (i + 1) % mod;
    }
}

void solve() {
    int n;
    scanf("%d", &n);
    int a[26] = {0};
    long all = 26 * 26 * pow(25, n - 2, MOD) % MOD;

    long dp[3][MAX_N][MAX_N] = {{{0}}};
    dp[0][1][0] = 1;
    dp[1][0][1] = 1;
    dp[2][0][0] = 1;

    for (int i = 0; i < n - 1; i++) {
        long ndp[3][MAX_N][MAX_N] = {{{0}}};
        if (i == (n + 1) / 2 - 1) {
            for (int j = 0; j <= n; j++) {
                for (int k = 0; j + k <= n; k++) {
                    if (j + 1 <= n) {
                        ndp[0][j + 1][k] += (dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 24) % MOD;
                        ndp[0][j + 1][k] %= MOD;
                    }
                    if (k + 1 <= n) {
                        ndp[1][j][k + 1] += (dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 24) % MOD;
                        ndp[1][j][k + 1] %= MOD;
                    }
                    ndp[2][j][k] += (dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 24) % MOD;
                    ndp[2][j][k] %= MOD;
                }
            }
        } else {
            for (int j = 0; j <= n; j++) {
                for (int k = 0; j + k <= n; k++) {
                    if (j + 1 <= n) {
                        ndp[0][j + 1][k] += (dp[1][j][k] + dp[2][j][k] * 24) % MOD;
                        ndp[0][j + 1][k] %= MOD;
                    }
                    if (k + 1 <= n) {
                        ndp[1][j][k + 1] += (dp[0][j][k] + dp[2][j][k] * 24) % MOD;
                        ndp[1][j][k + 1] %= MOD;
                    }
                    ndp[2][j][k] += (dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 23) % MOD;
                    ndp[2][j][k] %= MOD;
                }
            }
        }
        memcpy(dp, ndp, sizeof(dp));
    }

    long sdp[MAX_N] = {0};
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            sdp[i] += (dp[0][i][j] + dp[1][i][j] + dp[2][i][j] * 24) % MOD;
            sdp[i] %= MOD;
        }
    }

    for (int i = 0; i < 26; i++) {
        for (int k = a[i] + 1; k <= n; k++) {
            all -= sdp[k];
        }
    }

    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            for (int k = a[i] + 1; k <= n; k++) {
                for (int l = a[j] + 1; l + k <= n; l++) {
                    all += (dp[0][k][l] + dp[1][k][l] + dp[2][k][l] * 24) % MOD;
                }
            }
            all %= MOD;
        }
    }
    all %= MOD;

    if (all < 0) all += MOD;
    printf("%ld\n", all);
}

int main() {
    solve();
    return 0;
}
