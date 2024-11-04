#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cstring>
#include <iomanip>

using namespace std;

class Main {
public:
    static int groups;
    static vector<int> fa;
    static vector<int> sz;

    static void init1(int n) {
        groups = n;
        fa.resize(n);
        for (int i = 1; i < n; ++i) {
            fa[i] = i;
        }
        sz.resize(n, 1);
    }

    static int root(int p) {
        while (p != fa[p]) {
            fa[p] = fa[fa[p]];
            p = fa[p];
        }
        return p;
    }

    static void combine(int p, int q) {
        int i = root(p);
        int j = root(q);
        if (i == j) {
            return;
        }
        fa[i] = j;
        if (sz[i] < sz[j]) {
            fa[i] = j;
            sz[j] += sz[i];
        } else {
            fa[j] = i;
            sz[i] += sz[j];
        }
        groups--;
    }

    static string roundS(double result, int scale) {
        stringstream fmt;
        fmt << fixed << setprecision(scale) << result;
        return fmt.str();
    }

    static vector<int> unique(vector<int>& a) {
        int p = 1;
        for (int i = 1; i < a.size(); ++i) {
            if (a[i] != a[i - 1]) {
                a[p++] = a[i];
            }
        }
        return vector<int>(a.begin(), a.begin() + p);
    }

    static int bigger(vector<long>& a, long key) {
        return bigger(a, 0, a.size(), key);
    }

    static int bigger(vector<long>& a, int lo, int hi, long key) {
        while (lo < hi) {
            int mid = (lo + hi) >> 1;
            if (a[mid] > key) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }

    static vector<int> h;
    static vector<int> to;
    static vector<int> ne;
    static int m;

    static void addEdge(int u, int v, int w) {
        to[++m] = v;
        ne[m] = h[u];
        h[u] = m;
    }

    vector<int> w;
    int cc = 0;

    void add(int u, int v, int ww) {
        to[++cc] = u;
        w[cc] = ww;
        ne[cc] = h[v];
        h[v] = cc;

        to[++cc] = v;
        w[cc] = ww;
        ne[cc] = h[u];
        h[u] = cc;
    }

    class S {
    public:
        int l = 0;
        int r = 0;
        int miss = 0;
        int cnt = 0;
        int c = 0;

        S(int l, int r) : l(l), r(r) {}
    };

    static vector<S> a;
    static vector<int> o;

    static void init11(vector<int>& f) {
        o = f;
        int len = o.size();
        a.resize(len * 4);
        build1(1, 0, len - 1);
    }

    static void build1(int num, int l, int r) {
        S cur(l, r);
        if (l == r) {
            cur.c = o[l];
            a[num] = cur;
            return;
        } else {
            int m = (l + r) >> 1;
            int le = num << 1;
            int ri = le | 1;
            build1(le, l, m);
            build1(ri, m + 1, r);
            a[num] = cur;
            pushup(num, le, ri);
        }
    }

    static int query1(int num, int l, int r) {
        if (a[num].l >= l && a[num].r <= r) {
            return a[num].c;
        } else {
            int m = (a[num].l + a[num].r) >> 1;
            int le = num << 1;
            int ri = le | 1;

            int mi = -1;

            if (r > m) {
                int res = query1(ri, l, r);
                mi = max(mi, res);
            }

            if (l <= m) {
                int res = query1(le, l, r);
                mi = max(mi, res);
            }

            return mi;
        }
    }

    static void pushup(int num, int le, int ri) {
        a[num].c = max(a[le].c, a[ri].c);
    }

    vector<int> clr;
    vector<vector<int>> qr;
    vector<vector<int>> qs;

    int rr = 100;
    vector<int> cao;

    void df(int n, vector<int>& li) {
        int sz = li.size();
        if (sz >= rr || sz >= 11) return;
        int v = li.back();
        if (v == n) {
            cao = li;
            rr = sz;
            return;
        }
        vector<int> res(li.rbegin(), li.rend());

        for (int u : res) {
            for (int vv : res) {
                if (u + vv > v && u + vv <= n) {
                    li.push_back(u + vv);
                    df(n, li);
                    li.pop_back();
                } else if (u + vv > n) {
                    break;
                }
            }
        }
    }

    static long mul(long a, long b, long p) {
        long res = 0, base = a;
        while (b > 0) {
            if ((b & 1L) > 0)
                res = (res + base) % p;
            base = (base + base) % p;
            b >>= 1;
        }
        return res;
    }

    static long mod_pow(long k, long n, long p) {
        long res = 1L;
        long temp = k % p;
        while (n != 0L) {
            if ((n & 1L) == 1L) {
                res = mul(res, temp, p);
            }
            temp = mul(temp, temp, p);
            n = n >> 1L;
        }
        return res % p;
    }

    long gen(long x) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<long> dis(1, x - 1);
        return dis(gen);
    }

    bool robin_miller(long x) {
        if (x == 1) return false;
        if (x == 2) return true;
        if (x == 3) return true;
        if ((x & 1) == 0) return false;
        long y = x % 6;
        if (y == 1 || y == 5) {
            long ck = x - 1;
            while ((ck & 1) == 0) ck >>= 1;

            long as[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

            for (int i = 0; i < sizeof(as) / sizeof(as[0]); ++i) {
                long a = as[i];
                long ck1 = ck;
                a = mod_pow(a, ck1, x);
                while (ck1 < x) {
                    y = mod_pow(a, 2, x);
                    if (y == 1 && a != 1 && a != x - 1)
                        return false;
                    a = y;
                    ck1 <<= 1;
                }
                if (a != 1)
                    return false;
            }
            return true;
        } else {
            return false;
        }
    }

    long inv(long a, long MOD) {
        return a == 1 ? 1 : (long)(MOD - MOD / a) * inv(MOD % a, MOD) % MOD;
    }

    long C(long n, long m, long MOD) {
        if (m + m > n) m = n - m;
        long up = 1, down = 1;
        for (long i = 0; i < m; i++) {
            up = up * (n - i) % MOD;
            down = down * (i + 1) % MOD;
        }
        return up * inv(down, MOD) % MOD;
    }

    static vector<long> ex_gcd(long a, long b) {
        if (b == 0) {
            return {1, 0, a};
        }
        vector<long> r = ex_gcd(b, a % b);
        return {r[1], r[0] - (a / b) * r[1], r[2]};
    }

    void chinese_rm(vector<long>& m, vector<long>& r) {
        vector<long> res = ex_gcd(m[0], m[1]);
        long rm = r[1] - r[0];
        if (rm % res[2] == 0) {
            // Implementation needed
        }
    }

    void go(int i, int c, vector<int>& cl) {
        cl[i] = c;
        for (int j = h[i]; j != -1; j = ne[j]) {
            int v = to[j];
            if (cl[v] == 0) {
                go(v, -c, cl);
            }
        }
    }

    void solve() {
        int t;
        cin >> t;
        vector<int> dp(1000001, 0);
        for (int i = 0; i < t; ++i) {
            int n, k, d;
            cin >> n >> k >> d;
            vector<int> a(n);
            for (int j = 0; j < n; ++j) {
                cin >> a[j];
            }

            int g = 0;
            for (int j = 0; j < d; ++j) {
                if (dp[a[j]]++ == 0) {
                    g++;
                }
            }
            int all = g;
            for (int j = d; j < n; ++j) {
                if (--dp[a[j - d]] == 0) {
                    g--;
                }
                if (dp[a[j]]++ == 0) {
                    g++;
                }
                all = min(all, g);
            }
            cout << all << endl;
            for (int j = 0; j < d; ++j) {
                dp[a[n - j - 1]]--;
            }
        }
    }

    long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    void run() {
        solve();
    }
};

int Main::groups = 0;
vector<int> Main::fa;
vector<int> Main::sz;
vector<int> Main::h;
vector<int> Main::to;
vector<int> Main::ne;
int Main::m = 0;
vector<Main::S> Main::a;
vector<int> Main::o;

int main() {
    Main main;
    main.run();
    return 0;
}
