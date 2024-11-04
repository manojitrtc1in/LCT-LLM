#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

long pow(long a, long n, long mod) {
    long ret = 1;
    int x = 63 - __builtin_clzll(n);
    for (; x >= 0; x--) {
        ret = ret * ret % mod;
        if (n << (63 - x) < 0) ret = ret * a % mod;
    }
    return ret;
}

long invl(long a, long mod) {
    long b = mod;
    long p = 1, q = 0;
    while (b > 0) {
        long c = a / b;
        swap(a, b);
        b = a % b;
        swap(p, q);
        q -= c * q;
    }
    return p < 0 ? p + mod : p;
}

long C(int n, int r, int mod, vector<vector<int>>& fif) {
    if (n < 0 || r < 0 || r > n) return 0;
    return (long)fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod;
}

vector<vector<int>> enumFIF(int n, int mod) {
    vector<int> f(n + 1), invf(n + 1);
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = (long)f[i - 1] * i % mod;
    }
    long a = f[n], b = mod, p = 1, q = 0;
    while (b > 0) {
        long c = a / b;
        swap(a, b);
        b = a % b;
        swap(p, q);
        q -= c * q;
    }
    invf[n] = (p < 0 ? p + mod : p);
    for (int i = n - 1; i >= 0; i--) {
        invf[i] = (long)invf[i + 1] * (i + 1) % mod;
    }
    return {f, invf};
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(26);
    for (int i = 0; i < 26; i++) cin >> a[i];
    
    long all = 26 * 26 * pow(25, n - 2, mod) % mod;
    vector<vector<vector<long>>> dp(3, vector<vector<long>>(n + 1, vector<long>(n + 1, 0)));
    dp[0][1][0] = 1;
    dp[1][0][1] = 1;
    dp[2][0][0] = 1;

    for (int i = 0; i < n - 1; i++) {
        vector<vector<vector<long>>> ndp(3, vector<vector<long>>(n + 1, vector<long>(n + 1, 0)));
        if (i == (n + 1) / 2 - 1) {
            for (int j = 0; j <= n; j++) {
                for (int k = 0; j + k <= n; k++) {
                    if (j + 1 <= n) {
                        ndp[0][j + 1][k] += (dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 24) % mod;
                        ndp[0][j + 1][k] %= mod;
                    }
                    if (k + 1 <= n) {
                        ndp[1][j][k + 1] += (dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 24) % mod;
                        ndp[1][j][k + 1] %= mod;
                    }
                    ndp[2][j][k] += (dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 24) % mod;
                    ndp[2][j][k] %= mod;
                }
            }
        } else {
            for (int j = 0; j <= n; j++) {
                for (int k = 0; j + k <= n; k++) {
                    if (j + 1 <= n) {
                        ndp[0][j + 1][k] += (dp[1][j][k] + dp[2][j][k] * 24) % mod;
                        ndp[0][j + 1][k] %= mod;
                    }
                    if (k + 1 <= n) {
                        ndp[1][j][k + 1] += (dp[0][j][k] + dp[2][j][k] * 24) % mod;
                        ndp[1][j][k + 1] %= mod;
                    }
                    ndp[2][j][k] += (dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 23) % mod;
                    ndp[2][j][k] %= mod;
                }
            }
        }
        dp = ndp;
    }

    vector<long> sdp(n + 1, 0);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            sdp[i] += (dp[0][i][j] + dp[1][i][j] + dp[2][i][j] * 24) % mod;
            sdp[i] %= mod;
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
                    all += (dp[0][k][l] + dp[1][k][l] + dp[2][k][l] * 24) % mod;
                }
            }
            all %= mod;
        }
    }
    all %= mod;

    if (all < 0) all += mod;
    cout << all << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
