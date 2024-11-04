

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> ppi;
typedef pair<int, pair<int, int>> pii;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<pair<int, int>> vp;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;
typedef vector<vector<bool>> vvb;
typedef vector<vector<string>> vvs;
typedef vector<vector<char>> vvc;
typedef vector<vector<pair<int, int>>> vvp;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<vector<vector<vector<int>>>> vvvvi;
template <typename T>
using vv = vector<vector<T>>;
template <typename T>
using vvv = vector<vector<vector<T>>>;
template <typename T>
using vvvv = vector<vector<vector<vector<T>>>>;
template <typename T>
using pq = priority_queue<T>;
template <typename T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

#define _PI 3.14159265358979323846
#define _E 2.7182818284590452354
#define fi first
#define se second
#define mset multiset
#define uset unordered_set
#define umap unordered_map
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define td typedef
#define elif else if
#define unless(a) if (!(a))
#define el '\n'
#define len(x) (int)(x).size()
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
#define sumv(a) accumulate(all(a), 0LL)
#define lb(v, a) (lower_bound(begin(v), end(v), a) - begin(v))
#define ub(v, a) (upper_bound(begin(v), end(v), a) - begin(v))
#define cbit(x) __builtin_popcountll(x)
#define bits(x) (1LL << (x))
#define gbit(a, i) ((a >> i) & 1)
#define topbit(t) (t == 0 ? -1 : 63 - __builtin_clzll(t))
#define botbit(t) (t == 0 ? 64 : __builtin_ctzll(t))
#define bis(_ac, _wa, _f)            \
    [&] {                            \
        ll ac = _ac, wa = _wa;       \
        while (abs(ac - wa) > 1) {   \
            ll wj = (ac + wa) / 2;   \
            (_f(wj) ? ac : wa) = wj; \
        }                            \
        return ac;                   \
    }()

#define rep1(a) for (int i = 0; i < (int)a; i++)
#define rep2(i, a) for (int i = 0; i < (int)a; i++)
#define rep3(i, a, b) for (int i = a; i < (int)b; i++)
#define rep4(i, a, b, c) for (int i = a; i < (int)b; i += c)
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rrep1(n) for (ll i = n; i--;)
#define rrep2(i, n) for (ll i = n; i--;)
#define rrep3(i, a, b) for (ll i = b; i-- > (a);)
#define rrep4(i, a, b, c) \
    for (ll i = (a) + ((b) - (a)-1) / (c) * (c); i >= (a); i -= c)
#define rrep(...) \
    overload4(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)
#define fore1(i, a) for (auto &&i : a)
#define fore2(x, y, a) for (auto &&[x, y] : a)
#define fore3(x, y, z, a) for (auto &&[x, y, z] : a)
#define fore(...) overload4(__VA_ARGS__, fore3, fore2, fore1)(__VA_ARGS__)





#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0, a1, a2, a3, a4, x, ...) x
#define debug_1(x1) cout << #x1 << ": " << x1 << endl
#define debug_2(x1, x2) \
    cout << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << endl
#define debug_3(x1, x2, x3)                                                 \
    cout << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " \
         << x3 << endl
#define debug_4(x1, x2, x3, x4)                                             \
    cout << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " \
         << x3 << ", " #x4 << ": " << x4 << endl
#define debug_5(x1, x2, x3, x4, x5)                                         \
    cout << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " \
         << x3 << ", " #x4 << ": " << x4 << ", " #x5 << ": " << x5 << endl
#ifdef _DEBUG
#define debug(...)                                                        \
    CHOOSE((__VA_ARGS__, debug_5, debug_4, debug_3, debug_2, debug_1, ~)) \
    (__VA_ARGS__)
#else
#define debug(...)
#endif

template <class T>
istream &operator>>(istream &is, vector<T> &v) {
    for (auto &e : v) is >> e;
    return is;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (auto &e : v) os << e << ' ';
    return os;
}
template <class T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v) {
    for (auto &e : v) {
        for (auto &c : e) os << c << ' ';
        os << endl;
    }
    return os;
}
template <class T, class U>
istream &operator>>(istream &is, pair<T, U> &p) {
    is >> p.first >> p.second;
    return is;
}
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
    os << p.first << "," << p.second;
    return os;
}
template <class T>
ostream &operator<<(ostream &s, set<T> P) {
    fore(it, P) {
        s << it << " ";
    }
    return s;
}
template <class T1, class T2>
ostream &operator<<(ostream &s, map<T1, T2> P) {
    fore(x, y, P) {
        s << "<" << x << "->" << y << "> ";
    }
    return s;
}
template <class T>
ostream &operator<<(ostream &s, multiset<T> P) {
    fore(it, P) {
        s << it << " ";
    }
    return s;
}
template <class T>
ostream &operator<<(ostream &s, unordered_set<T> P) {
    fore(it, P) {
        s << it << " ";
    }
    return s;
}
template <class T1, class T2>
ostream &operator<<(ostream &s, unordered_map<T1, T2> P) {
    fore(x, y, P) {
        s << "<" << x << "->" << y << "> ";
    }
    return s;
}
struct fast_ios {
    fast_ios() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(12);
    };
} fast_ios_;

clock_t start_time = clock();
double now_time() {
    clock_t end_time = clock();
    return (double)(end_time - start_time) / CLOCKS_PER_SEC;
}

void input_graph(vector<vector<int>> &g, int m = -1, int bidirected = true) {
    if (m == -1) m = g.size() - 1;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        if (bidirected) g[v].push_back(u);
    }
}

template <int mod>
struct ModInt {
    int x;

    ModInt() : x(0) {
    }

    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {
    }

    ModInt &operator+=(const ModInt &p) {
        if ((x += p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator-=(const ModInt &p) {
        if ((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator*=(const ModInt &p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }

    ModInt &operator/=(const ModInt &p) {
        *this *= p.inverse();
        return *this;
    }

    ModInt operator-() const {
        return ModInt(-x);
    }

    ModInt operator+(const ModInt &p) const {
        return ModInt(*this) += p;
    }

    ModInt operator-(const ModInt &p) const {
        return ModInt(*this) -= p;
    }

    ModInt operator*(const ModInt &p) const {
        return ModInt(*this) *= p;
    }

    ModInt operator/(const ModInt &p) const {
        return ModInt(*this) /= p;
    }

    bool operator==(const ModInt &p) const {
        return x == p.x;
    }

    bool operator!=(const ModInt &p) const {
        return x != p.x;
    }

    ModInt inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }

    ModInt pow(int64_t n) const {
        ModInt ret(1), mul(x);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const ModInt &p) {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, ModInt &a) {
        int64_t t;
        is >> t;
        a = ModInt<mod>(t);
        return (is);
    }

    static int get_mod() {
        return mod;
    }
};

vector<int> iota(int n, int s = 0) {
    vi a(n);
    iota(a.begin(), a.end(), s);
    return a;
}
template <class T>
void sort(vector<T> &v) {
    sort(all(v));
}
template <class T>
void rsort(vector<T> &v) {
    sort(rall(v));
}
template <class T>
void reverse(vector<T> &v) {
    reverse(all(v));
}
template <class T>
auto min(const T &a) {
    return *min_element(all(a));
}
template <class T>
auto max(const T &a) {
    return *max_element(all(a));
}
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
vector<T> uniq(vector<T> v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    return v;
}
template <class T>
vector<T> compress(vector<T> v) {
    vector<T> v2(v.size());
    v2 = v;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for (int i = 0; i < (int)v2.size(); i++) {
        v2[i] = lower_bound(v.begin(), v.end(), v2[i]) - v.begin();
    }
    return v2;
}
template <typename T>
vector<T> acc(vector<T> &v, bool er = false) {
    vector<T> res(v.size() + 1);
    for (int i = 0; i < (int)v.size(); i++) {
        res[i + 1] = res[i] + v[i];
    }
    if (er) res.erase(res.begin());
    return res;
}
template <typename T>
vector<vector<T>> acc(vector<vector<T>> &v, bool er = false) {
    int h = v.size(), w = v[0].size();
    vector<vector<T>> res(h + 1, vector<T>(w + 1));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            res[i + 1][j + 1] =
                v[i][j] + res[i][j + 1] + res[i + 1][j] - res[i][j];
        }
    }
    if (er) {
        res.erase(res.begin());
        for (int i = 0; i < h; i++) res[i].erase(res[i].begin());
    }
    return res;
}
template <class T>
T exp(T x, ll n) {
    T res = 1;
    while (n > 0) {
        if (n & 1) res = res * x;
        x = x * x;
        n >>= 1;
    }
    return res;
}
long long pow_mod(long long x, long long n, const long long &p) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) (ret *= x) %= p;
        (x *= x) %= p;
        n >>= 1;
    }
    return ret;
}
constexpr ll ten(int n) {
    return n == 0 ? 1 : ten(n - 1) * 10;
}
long long ceil(long long x, long long y) {
    return (x + y - 1) / y;
}
void yesno(bool x) {
    if (x) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
void yes() {
    cout << "YES" << endl;
}
void no() {
    cout << "NO" << endl;
}
void err() {
    cout << -1 << endl;
}

int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};

long long inf = 2000000000005000005;
double eps = 1e-9;





long long mod = 998244353;
using mint = ModInt<998244353>;
typedef vector<mint> vm;
typedef vector<vector<mint>> vvm;
typedef vector<vector<vector<mint>>> vvvm;


struct edge {
    int to, id;
    edge() {
    }
    edge(int to, int id) : to(to), id(id) {
    }
};
typedef vector<edge> ve;
typedef vector<vector<edge>> vve;


void solve();

signed main() {
    int testcase = 1;
    cin >> testcase;
    for (int i = 0; i < testcase; i++) {
        solve();
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vve g(n);
    vp E(m);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        E[i] = mp(u, v);
        g[u].eb(v, i);
        g[v].eb(u, i);
    }
    vi ans(m);
    vb visited(n);
    vi depth(n);
    vi par(n);

    auto dfs = [&](auto dfs, int v) -> void {
        visited[v] = true;
        for (auto e : g[v]) {
            if (visited[e.to]) continue;
            ans[e.id] = 1;
            depth[e.to] = depth[v] + 1;
            par[e.to] = v;
            dfs(dfs, e.to);
        }
    };
    dfs(dfs, 0);

    vp V;
    rep(i, n) {
        for (auto e : g[i]) {
            if (ans[e.id] == 0) {
                if (i < e.to) {
                    V.eb(i, e.to);
                }
            }
        }
    }
    bool ok = true;
    set<int> st;
    if (V.size() == 3 && m == n + 2) {
        for (auto p : V) {
            st.insert(p.first);
            st.insert(p.second);
        }
        if (st.size() == 3) ok = false;
    }
    if (ok) {
        rep(i, m) cout << ans[i];
        cout << endl;
        return;
    }
    debug(ans);
    debug(st);
    vi v;
    for (auto tt : st) v.pb(tt);
    sort(all(v), [&](int i, int j) { return depth[i] < depth[j]; });

    int x = v[2], y = v[0], z = par[x];
    rep(i, m) {
        if (E[i] == mp(x, y) || E[i] == mp(y, x)) ans[i] = 1;
        if (E[i] == mp(x, z) || E[i] == mp(z, x)) ans[i] = 0;
    }

    rep(i, m) cout << ans[i];
    cout << endl;
    return;
}