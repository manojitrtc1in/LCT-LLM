#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const long big = (LLONG_MAX / mod / mod - 1) * mod * mod;

long pow(long a, long n) {
    long ret = 1;
    for (int x = 63 - __builtin_clzll(n); x >= 0; x--) {
        ret = ret * ret % mod;
        if (n & (1LL << x)) ret = ret * a % mod;
    }
    return ret;
}

long invl(long a) {
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

class NTTStockham998244353 {
public:
    static long* convolve(long* a, long* b, int n, int m) {
        int size = max(2, 1 << (32 - __builtin_clz(max(n, m) - 1) + 2));
        long* wps = new long[size];
        long unit = pow(3, (mod - 1) / size);
        wps[0] = 1;
        for (int p = 1; p < size; p++) {
            wps[p] = wps[p - 1] * unit % mod;
        }

        long* fa = go(a, n, size, false);
        long* fb = (a == b) ? fa : go(b, m, size, false);
        for (int i = 0; i < size; i++) {
            fa[i] = fa[i] * fb[i] % mod;
        }
        fa = go(fa, size, size, true);
        for (int i = 1, j = size - 1; i < j; i++, j--) {
            swap(fa[i], fa[j]);
        }
        return fa;
    }

private:
    static long* go(long* src, int n, int size, bool inverse) {
        long* dst = new long[size];
        copy(src, src + n, dst);
        fft(dst, new long[size], size);
        if (inverse) {
            long in = invl(size);
            for (int i = 0; i < size; i++) {
                dst[i] = dst[i] * in % mod;
            }
        }
        return dst;
    }

    static void fft(long* X, long* Y, int size) {
        int s = 1;
        bool eo = false;
        for (int n = size; n >= 4; n /= 2) {
            int m = n / 2;
            for (int p = 0; p < m; p++) {
                long wp = wps[s * p];
                long wk = (wp << 32) / mod;
                for (int q = 0; q < s; q++) {
                    long a = X[q + s * (p + 0)];
                    long b = X[q + s * (p + m)];
                    long ndsts = (a + b) % mod;
                    long T = (a - b + 2 * mod) % mod;
                    long Q = wk * T >> 32;
                    Y[q + s * (2 * p + 0)] = ndsts;
                    Y[q + s * (2 * p + 1)] = (wp * T - Q * mod) & ((1LL << 32) - 1);
                }
            }
            s *= 2;
            eo = !eo;
            swap(X, Y);
        }
        long* z = eo ? Y : X;
        for (int q = 0; q < s; q++) {
            long a = X[q + 0];
            long b = X[q + s];
            z[q + 0] = (a + b) % mod;
            z[q + s] = (a - b + 2 * mod) % mod;
        }
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

        vector<long> dp(1 << 9, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            vector<long> ndp(1 << 9, 0);
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
        long ans = accumulate(dp.begin(), dp.end(), 0LL) % mod;
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
