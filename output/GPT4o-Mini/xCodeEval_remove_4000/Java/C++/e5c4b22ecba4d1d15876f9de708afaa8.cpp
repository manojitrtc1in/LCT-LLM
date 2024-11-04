#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const long long big = (LLONG_MAX / mod / mod - 1) * mod * mod;

long long pow(long long a, long long n) {
    long long ret = 1;
    int x = 63 - __builtin_clzll(n);
    for (; x >= 0; x--) {
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
        b = b % a;
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

class FastWriter {
    static const int BUF_SIZE = 1 << 13;
    byte buf[BUF_SIZE];
    ostream& out;
    int ptr = 0;

public:
    FastWriter(ostream& os) : out(os) {}

    void write(byte b) {
        buf[ptr++] = b;
        if (ptr == BUF_SIZE) innerflush();
    }

    void innerflush() {
        out.write(reinterpret_cast<char*>(buf), ptr);
        ptr = 0;
    }

    void flush() {
        innerflush();
        out.flush();
    }

    FastWriter& writeln(long long x) {
        if (x == LLONG_MIN) return *this << x;
        if (ptr + 21 >= BUF_SIZE) innerflush();
        if (x < 0) {
            write('-');
            x = -x;
        }
        int d = countDigits(x);
        for (int i = ptr + d - 1; i >= ptr; i--) {
            buf[i] = '0' + x % 10;
            x /= 10;
        }
        ptr += d;
        return *this;
    }

    int countDigits(long long l) {
        if (l >= 1000000000000000000LL) return 19;
        if (l >= 100000000000000000LL) return 18;
        if (l >= 10000000000000000LL) return 17;
        if (l >= 1000000000000000LL) return 16;
        if (l >= 100000000000000LL) return 15;
        if (l >= 10000000000000LL) return 14;
        if (l >= 1000000000000LL) return 13;
        if (l >= 100000000000LL) return 12;
        if (l >= 10000000000LL) return 11;
        if (l >= 1000000000LL) return 10;
        if (l >= 100000000LL) return 9;
        if (l >= 10000000LL) return 8;
        if (l >= 1000000LL) return 7;
        if (l >= 100000LL) return 6;
        if (l >= 10000LL) return 5;
        if (l >= 1000LL) return 4;
        if (l >= 100LL) return 3;
        if (l >= 10LL) return 2;
        return 1;
    }
};

class F2 {
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

public:
    void run() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        solve();
    }
};

int main() {
    F2 f2;
    f2.run();
    return 0;
}
