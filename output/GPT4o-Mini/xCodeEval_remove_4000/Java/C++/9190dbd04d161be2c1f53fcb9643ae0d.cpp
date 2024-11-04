#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iomanip>

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

long long* id3(long long* a, long long* b, int len_a, int len_b, int lim) {
    long long* c = new long long[lim]();
    for (int i = 0; i < len_a; i++) {
        for (int j = 0; j < len_b && i + j < lim; j++) {
            c[i + j] += a[i] * b[j];
            if (c[i + j] >= big) c[i + j] -= big;
        }
    }
    for (int i = 0; i < lim; i++) c[i] %= mod;
    return c;
}

long long sum(long long* a, int size) {
    long long ret = 0;
    for (int i = 0; i < size; i++) ret += a[i];
    return ret;
}

void solve() {
    int n;
    cin >> n;
    bool g[10][10] = {};
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x][y] = g[y][x] = true;
    }
    for (int i = 0; i < 10; i++) g[i][i] = true;

    int njs[1 << 9][10];
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

    long long dp[1 << 9] = {};
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        long long ndp[1 << 9] = {};
        for (int j = 0; j < (1 << 9); j++) {
            for (int k = 0; k < 10; k++) {
                if (j & (1 << k)) {
                    int nj = njs[j][k];
                    ndp[nj] += dp[j];
                    if (ndp[nj] >= mod) ndp[nj] -= mod;
                }
            }
        }
        memcpy(dp, ndp, sizeof(dp));
    }
    long long ans = sum(dp, 1 << 9) % mod;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
