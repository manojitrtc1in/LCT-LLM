#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;

const int MOD = 998244353;

long long pow(long long a, long long n, long long mod) {
    long long ret = 1;
    for (int x = 63 - __builtin_clzll(n); x >= 0; x--) {
        ret = ret * ret % mod;
        if (n & (1LL << x)) ret = ret * a % mod;
    }
    return ret;
}

long long invl(long long a, long long mod) {
    long long b = mod, p = 1, q = 0;
    while (b > 0) {
        long long c = a / b;
        swap(a, b);
        b = a % b;
        swap(p, q);
        q -= c * q;
    }
    return p < 0 ? p + mod : p;
}

long long C(int n, int r, int mod, vector<vector<int>>& fif) {
    if (n < 0 || r < 0 || r > n) return 0;
    return (1LL * fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod);
}

vector<vector<int>> id0(int n, int mod) {
    vector<int> f(n + 1), invf(n + 1);
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = 1LL * f[i - 1] * i % mod;
    }
    long long a = f[n], b = mod, p = 1, q = 0;
    while (b > 0) {
        long long c = a / b;
        swap(a, b);
        b = a % b;
        swap(p, q);
        q -= c * q;
    }
    invf[n] = p < 0 ? p + mod : p;
    for (int i = n - 1; i >= 0; i--) {
        invf[i] = 1LL * invf[i + 1] * (i + 1) % mod;
    }
    return {f, invf};
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(26);
    for (int i = 0; i < 26; i++) cin >> a[i];

    long long all = 26 * 26 * pow(25, n - 2, MOD) % MOD;
    vector<vector<vector<long long>>> dp(3, vector<vector<long long>>(n + 1, vector<long long>(n + 1, 0)));
    dp[0][1][0] = 1;
    dp[1][0][1] = 1;
    dp[2][0][0] = 1;

    for (int i = 0; i < n - 1; i++) {
        vector<vector<vector<long long>>> ndp(3, vector<vector<long long>>(n + 1, vector<long long>(n + 1, 0)));
        if (i == (n + 1) / 2 - 1) {
            for (int j = 0; j <= n; j++) {
                for (int k = 0; j + k <= n; k++) {
                    if (j + 1 <= n) {
                        ndp[0][j + 1][k] = (ndp[0][j + 1][k] + dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 24) % MOD;
                    }
                    if (k + 1 <= n) {
                        ndp[1][j][k + 1] = (ndp[1][j][k + 1] + dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 24) % MOD;
                    }
                    ndp[2][j][k] = (ndp[2][j][k] + dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 24) % MOD;
                }
            }
        } else {
            for (int j = 0; j <= n; j++) {
                for (int k = 0; j + k <= n; k++) {
                    if (j + 1 <= n) {
                        ndp[0][j + 1][k] = (ndp[0][j + 1][k] + dp[1][j][k] + dp[2][j][k] * 24) % MOD;
                    }
                    if (k + 1 <= n) {
                        ndp[1][j][k + 1] = (ndp[1][j][k + 1] + dp[0][j][k] + dp[2][j][k] * 24) % MOD;
                    }
                    ndp[2][j][k] = (ndp[2][j][k] + dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 23) % MOD;
                }
            }
        }
        dp = ndp;
    }

    vector<long long> sdp(n + 1, 0);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            sdp[i] = (sdp[i] + dp[0][i][j] + dp[1][i][j] + dp[2][i][j] * 24) % MOD;
        }
    }

    for (int i = 0; i < 26; i++) {
        for (int k = a[i] + 1; k <= n; k++) {
            all = (all - sdp[k] + MOD) % MOD;
        }
    }

    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            for (int k = a[i] + 1; k <= n; k++) {
                for (int l = a[j] + 1; l + k <= n; l++) {
                    all = (all + (dp[0][k][l] + dp[1][k][l] + dp[2][k][l] * 24) % MOD) % MOD;
                }
            }
        }
    }
    all = (all + MOD) % MOD;

    cout << all << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
