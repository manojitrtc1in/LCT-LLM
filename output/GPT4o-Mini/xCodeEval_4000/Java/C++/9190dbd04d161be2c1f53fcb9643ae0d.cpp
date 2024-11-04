#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const long long big = (LLONG_MAX / mod / mod - 1) * mod * mod;

long long pow(long long a, long long n) {
    long long ret = 1;
    for (int x = 63 - __builtin_clzll(n); x >= 0; x--) {
        ret = ret * ret % mod;
        if (n & (1LL << x)) ret = ret * a % mod;
    }
    return ret;
}

long long invl(long long a) {
    long long b = mod;
    long long p = 1, q = 0;
    while (b > 0) {
        long long c = a / b;
        swap(a, b);
        b = a % b;
        swap(p, q);
        q -= c * q;
    }
    return p < 0 ? p + mod : p;
}

class NTTStockham998244353 {
public:
    static long long* convolve(long long* a, long long* b, int len_a, int len_b) {
        int m = max(2, 1 << (32 - __builtin_clz(max(len_a, len_b) - 1) + 2));
        vector<long long> wps(m);
        long long unit = pow(3, (mod - 1) / m);
        wps[0] = 1;
        for (int p = 1; p < m; p++) {
            wps[p] = wps[p - 1] * unit % mod;
        }

        auto go = [&](long long* src, int n, bool inverse) {
            vector<long long> dst(n);
            copy(src, src + len_a, dst.begin());
            fft(dst.data(), n, wps.data());
            if (inverse) {
                long long in = invl(n);
                for (int i = 0; i < n; i++) {
                    dst[i] = dst[i] * in % mod;
                }
            }
            return dst;
        };

        auto fft = [&](long long* X, int n, long long* wps) {
            int s = 1;
            bool eo = false;
            vector<long long> Y(n);
            for (int m = n; m >= 4; m /= 2) {
                for (int p = 0; p < m / 2; p++) {
                    long long wp = wps[s * p];
                    long long wk = (wp << 32) / mod;
                    for (int q = 0; q < s; q++) {
                        long long a = X[q + s * (p + 0)];
                        long long b = X[q + s * (p + m / 2)];
                        long long ndsts = (a + b) % mod;
                        long long T = (a - b + 2 * mod) % mod;
                        long long Q = wk * T >> 32;
                        Y[q + s * (2 * p + 0)] = ndsts;
                        Y[q + s * (2 * p + 1)] = (wp * T - Q * mod) & ((1LL << 32) - 1);
                    }
                }
                s *= 2;
                eo = !eo;
                swap(X, Y);
            }
            for (int q = 0; q < s; q++) {
                long long a = X[q + 0];
                long long b = X[q + s];
                X[q + 0] = (a + b) % mod;
                X[q + s] = (a - b + 2 * mod) % mod;
            }
        };

        vector<long long> fa = go(a, m, false);
        vector<long long> fb = (a == b) ? fa : go(b, m, false);
        for (int i = 0; i < m; i++) {
            fa[i] = fa[i] * fb[i] % mod;
        }
        fa = go(fa.data(), m, true);
        return fa.data();
    }
};

class F2 {
public:
    void solve() {
        int n;
        cin >> n;
        vector<vector<bool>> g(10, vector<bool>(10, false));
        int m;
        cin >> m;
        while (m--) {
            int x, y;
            cin >> x >> y;
            g[x][y] = g[y][x] = true;
        }
        for (int i = 0; i < 10; i++) g[i][i] = true;

        vector<vector<int>> njs(1 << 9, vector<int>(10));
        for (int j = 0; j < (1 << 9); j++) {
            for (int k = 0; k < 10; k++) {
                if (j & (1 << k)) {
                    int nj = j;
                    for (int l = 0; l < 10; l++) {
                        if (g[k][l]) {
                            if (k > l) {
                                nj |= 1 << l;
                            }
                        } else {
                            nj &= ~(1 << l);
                        }
                    }
                    njs[j][k] = nj;
                }
            }
        }

        vector<long long> dp(1 << 9, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            vector<long long> ndp(1 << 9, 0);
            for (int j = 0; j < (1 << 9); j++) {
                for (int k = 0; k < 10; k++) {
                    if (j & (1 << k)) {
                        int nj = njs[j][k];
                        ndp[nj] += dp[j];
                        if (ndp[nj] >= mod) ndp[nj] -= mod;
                    }
                }
            }
            dp = ndp;
        }
        long long ans = accumulate(dp.begin(), dp.end(), 0LL) % mod;
        cout << ans << endl;
    }

    void run() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        solve();
    }
};

int main() {
    F2 f2;
    f2.run();
    return 0;
}
