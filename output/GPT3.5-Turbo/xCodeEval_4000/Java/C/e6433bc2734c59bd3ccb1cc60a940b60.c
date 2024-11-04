#include <stdio.h>
#include <stdlib.h>

long long pow(long long a, long long n, long long mod) {
    long long ret = 1;
    int x = 63 - __builtin_clzll(n);
    for (; x >= 0; x--) {
        ret = ret * ret % mod;
        if (n << 63 - x < 0) ret = ret * a % mod;
    }
    return ret;
}

long long invl(long long a, long long mod) {
    long long b = mod;
    long long p = 1, q = 0;
    while (b > 0) {
        long long c = a / b;
        long long d;
        d = a;
        a = b;
        b = d % b;
        d = p;
        p = q;
        q = d - c * q;
    }
    return p < 0 ? p + mod : p;
}

long long C(int n, int r, int mod, int** fif) {
    if (n < 0 || r < 0 || r > n) return 0;
    return (long long) fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod;
}

int** enumFIF(int n, int mod) {
    int* f = (int*) malloc((n + 1) * sizeof(int));
    int* invf = (int*) malloc((n + 1) * sizeof(int));
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = (long long) f[i - 1] * i % mod;
    }
    long long a = f[n];
    long long b = mod;
    long long p = 1, q = 0;
    while (b > 0) {
        long long c = a / b;
        long long d;
        d = a;
        a = b;
        b = d % b;
        d = p;
        p = q;
        q = d - c * q;
    }
    invf[n] = (p < 0 ? p + mod : p);
    for (int i = n - 1; i >= 0; i--) {
        invf[i] = (long long) invf[i + 1] * (i + 1) % mod;
    }
    int** result = (int**) malloc(2 * sizeof(int*));
    result[0] = f;
    result[1] = invf;
    return result;
}

void solve() {
    const int mod = 998244353;
    int n;
    scanf("%d", &n);
    int* a = (int*) malloc(26 * sizeof(int));
    for (int i = 0; i < 26; i++) {
        scanf("%d", &a[i]);
    }
    long long all = 26 * 26 * pow(25, n - 2, mod) % mod;

    long long*** dp = (long long***) malloc(3 * sizeof(long long**));
    for (int i = 0; i < 3; i++) {
        dp[i] = (long long**) malloc((n + 1) * sizeof(long long*));
        for (int j = 0; j <= n; j++) {
            dp[i][j] = (long long*) malloc((n + 1) * sizeof(long long));
            for (int k = 0; k <= n; k++) {
                dp[i][j][k] = 0;
            }
        }
    }
    dp[0][1][0] = 1;
    dp[1][0][1] = 1;
    dp[2][0][0] = 1;
    for (int i = 0; i < n - 1; i++) {
        long long*** ndp = (long long***) malloc(3 * sizeof(long long**));
        for (int j = 0; j < 3; j++) {
            ndp[j] = (long long**) malloc((n + 1) * sizeof(long long*));
            for (int k = 0; k <= n; k++) {
                ndp[j][k] = (long long*) malloc((n + 1) * sizeof(long long));
                for (int l = 0; l <= n; l++) {
                    ndp[j][k][l] = 0;
                }
            }
        }
        if (i == (n + 1) / 2 - 1) {
            for (int j = 0; j <= n; j++) {
                for (int k = 0; j + k <= n; k++) {
                    if (j + 1 <= n) {
                        ndp[0][j + 1][k] += dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 24;
                        ndp[0][j + 1][k] %= mod;
                    }
                    if (k + 1 <= n) {
                        ndp[1][j][k + 1] += dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 24;
                        ndp[1][j][k + 1] %= mod;
                    }
                    ndp[2][j][k] += dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 24;
                    ndp[2][j][k] %= mod;
                }
            }
        } else {
            for (int j = 0; j <= n; j++) {
                for (int k = 0; j + k <= n; k++) {
                    if (j + 1 <= n) {
                        ndp[0][j + 1][k] += dp[1][j][k] + dp[2][j][k] * 24;
                        ndp[0][j + 1][k] %= mod;
                    }
                    if (k + 1 <= n) {
                        ndp[1][j][k + 1] += dp[0][j][k] + dp[2][j][k] * 24;
                        ndp[1][j][k + 1] %= mod;
                    }
                    ndp[2][j][k] += dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 23;
                    ndp[2][j][k] %= mod;
                }
            }
        }
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k <= n; k++) {
                free(dp[j][k]);
            }
            free(dp[j]);
        }
        dp = ndp;
    }

    long long* sdp = (long long*) malloc((n + 1) * sizeof(long long));
    for (int i = 0; i <= n; i++) {
        sdp[i] = 0;
        for (int j = 0; j <= n; j++) {
            sdp[i] += dp[0][i][j] + dp[1][i][j] + dp[2][i][j] * 24;
        }
        sdp[i] %= mod;
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
                    all += (dp[0][k][l] + dp[1][k][l] + dp[2][k][l] * 24);
                }
            }
            all %= mod;
        }
    }
    all %= mod;

    if (all < 0) all += mod;
    printf("%lld\n", all);
}

int main() {
    solve();
    return 0;
}
