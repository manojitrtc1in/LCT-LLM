



using namespace std;



int nxt() {
    int t;
    cin >> t;
    return t;
}

struct modint {
    int64_t n;
    static const int64_t mod = 998244353;  

    modint() : n(0) {}
    modint(int64_t m) : n((m % mod + mod) % mod) {}
};
modint fastpow(modint, int64_t);
modint inverse(modint);
modint operator+(modint a, modint b) { return (a.n + b.n) % a.mod; }
modint operator-(modint a, modint b) { return (a.n - b.n + a.mod) % a.mod; }
modint operator*(modint a, modint b) { return (a.n * b.n) % a.mod; }
modint operator/(modint a, modint b) { return (a.n * inverse(b).n) % a.mod; }
modint operator+=(modint &a, modint b) { return a = a + b; }
modint operator-=(modint &a, modint b) { return a = a - b; }
modint operator*=(modint &a, modint b) { return a = a * b; }
modint operator/=(modint &a, modint b) { return a = a / b; }
bool operator==(modint a, modint b) { return a.n == b.n; }
bool operator!=(modint a, modint b) { return a.n != b.n; }
bool operator<(modint a, modint b) { return a.n < b.n; }
bool operator<=(modint a, modint b) { return a.n <= b.n; }
bool operator>(modint a, modint b) { return a.n > b.n; }
bool operator>=(modint a, modint b) { return a.n >= b.n; }

istream &operator>>(istream &i, modint a) { return i >> a.n; }
ostream &operator<<(ostream &o, modint a) { return o << a.n; }

modint stringpow(modint base, string exponent) {
    modint res = 1;
    for (int i = exponent.size() - 1; i >= 0; --i) {
        for (int j = 0; j < exponent[i] - '0'; ++j) {
            res *= base;
        }
        base = base * base * base * base * base * base * base * base * base * base;
    }
    return res;
}
modint fastpow(modint base, int64_t exponent) {
    modint res = 1;
    while (exponent) {
        if (exponent & 1) res *= base;
        base *= base;
        exponent >>= 1;
    }
    return res;
}
modint inverse(modint x) { return fastpow(x, x.mod - 2); };

int a[13][12][12] = {{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},
                     {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},
                     {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},
                     {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},
                     {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},
                     {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 2, 12, 2, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 2, 12, 4, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 9, 6, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 3, 6, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},
                     {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 5, 10, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 3, 28, 13, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 4, 35, 29, 1, 0, 0, 0, 0, 0, 0, 0},
                      {0, 3, 35, 41, 4, 0, 0, 0, 0, 0, 0, 0},
                      {0, 1, 30, 44, 7, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 17, 45, 7, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 8, 30, 11, 0, 0, 0, 0, 0, 0, 0}},
                     {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 6, 20, 6, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 4, 55, 50, 3, 0, 0, 0, 0, 0, 0, 0},
                      {0, 6, 80, 118, 18, 0, 0, 0, 0, 0, 0, 0},
                      {0, 6, 95, 186, 48, 0, 0, 0, 0, 0, 0, 0},
                      {0, 6, 101, 230, 85, 2, 0, 0, 0, 0, 0, 0},
                      {0, 2, 94, 260, 113, 4, 0, 0, 0, 0, 0, 0}},
                     {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 7, 35, 21, 1, 0, 0, 0, 0, 0, 0, 0},
                      {0, 5, 96, 145, 26, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 155, 358, 124, 3, 0, 0, 0, 0, 0, 0},
                      {0, 9, 207, 616, 313, 16, 0, 0, 0, 0, 0, 0},
                      {0, 11, 250, 859, 567, 53, 0, 0, 0, 0, 0, 0}},
                     {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 56, 56, 8, 0, 0, 0, 0, 0, 0, 0},
                      {0, 6, 154, 350, 126, 4, 0, 0, 0, 0, 0, 0},
                      {0, 10, 268, 898, 552, 48, 0, 0, 0, 0, 0, 0},
                      {0, 12, 389, 1654, 1404, 204, 1, 0, 0, 0, 0, 0}},
                     {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 9, 84, 126, 36, 1, 0, 0, 0, 0, 0, 0},
                      {0, 7, 232, 742, 448, 43, 0, 0, 0, 0, 0, 0},
                      {0, 12, 427, 1967, 1887, 357, 6, 0, 0, 0, 0, 0}},
                     {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 10, 120, 252, 120, 10, 0, 0, 0, 0, 0, 0},
                      {0, 8, 333, 1428, 1302, 252, 5, 0, 0, 0, 0, 0}},
                     {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 11, 165, 462, 330, 55, 1, 0, 0, 0, 0, 0}}};
modint dp[12][23][12][12];  


void solve() {
    int n = nxt(), k = nxt(), x = nxt();
    modint ans = 0;
    for (int i = 1; i <= 11; ++i) {
        modint cur = 1;
        for (int j = 1; j <= i; ++j) cur = cur * (n + j) / j;
        

        for (int j = 1; j <= 22 && j <= n; ++j) {
            

            

            cur = cur / (n - j + i + 1) * (n - j + 1);
            ans += cur * dp[i][j][k][x];
        }
        

    }
    cout << ans << '\n';
}

int32_t main() {
    dp[0][0][0][0] = 1;
    for (int i = 0; i < 11; ++i) {
        for (int j = 0; j <= 22; ++j) {
            for (int k = 0; k <= 11; ++k) {
                for (int l = 0; l <= 11; ++l) {
                    for (int dj = 0; j + dj <= 22 && dj <= 12; ++dj) {
                        for (int dk = 0; k + dk <= 11; ++dk) {
                            for (int dl = 0; l + dl <= 11; ++dl) {
                                dp[i + 1][j + dj][k + dk][l + dl] += dp[i][j][k][l] * a[dj][dk][dl];
                            }
                        }
                    }
                }
            }
        }
    }

    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; ++i) {
        

        solve();
    }
}