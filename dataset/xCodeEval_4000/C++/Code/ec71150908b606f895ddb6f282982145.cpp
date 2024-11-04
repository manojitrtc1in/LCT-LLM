
#include <bits/extc++.h>




using namespace __gnu_pbds;
using namespace std;

#ifndef asr_debug
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")





#pragma GCC target("avx2")
#pragma GCC target("popcnt,lzcnt,bmi,bmi2,tune=native")








#endif

#define vamos ios_base::sync_with_stdio(false);
#define fix(prec) cout << setprecision(prec) << fixed;

#define tcT template <class T
#define tcTU tcT, class U
#define tcTUU tcT, class... U

#define f0r(i, n) for (int i = 0; i < (n); ++i)
#define f1r(i, l, r) for (int i = (l); i <= (r); ++i)
#define f0rd(i, n) for (int i = (n); i >= 0; --i)
#define f1rd(i, l, r) for (int i = (l); i >= (r); --i)
#define each(i, a) for (auto &i : a)



#define ai(a, n) f0r(i, n) cin >> a[i];
#define ain(a, l, r) f1r(i, l, r) cin >> a[i];
#define ao(a, n) f0r(i, n) cout << a[i] << " \n"[i == n - 1];
#define aout(a, l, r) f1r(i, l, r) cout << a[i] << " \n"[i == r];

#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define ft front()
#define bk back()
#define rsz resize
#define ass assign
#define eq equal_range
#define ts to_string
#define nl '\n'

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sor(v) sort(all(v))
#define soR(v) sort(rall(v))
#define sz(v) ((int)v.size())
#define bg(v) v.begin()

tcT > using V = vector<T>;
tcT > using Q = queue<T>;
tcTU > using P = pair<T, U>;
tcT, size_t SZ > using AR = array<T, SZ>;
tcT > using pqdec = std::priority_queue<T>;
tcT > using pqinc = std::priority_queue<T, V<T>, greater<T>>;

using ll = long long;
using db = double;
using ld = long double;
using ull = unsigned long long;
using str = string;

using vs = V<string>;
using vb = V<bool>;

using vi = V<int>;
using vd = V<db>;
using vl = V<ll>;
using vld = V<ld>;

using vvi = V<vi>;
using vvl = V<vl>;
using vvd = V<vd>;
using vvld = V<vld>;

using pi = P<int, int>;
using pl = P<ll, ll>;
using pd = P<db, db>;
using pld = P<ld, ld>;

using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;
using vpld = V<pld>;

tcT > bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
tcT > bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }
tcT > T cdiv(T &a, T &b) { return a / b + ((a ^ b) > 0 && a % b); }
tcT > T fdiv(T &a, T &b) { return a / b - ((a ^ b) < 0 && a % b); }
tcT > int lwb(V<T> &a, const T &b) { return int(lb(all(a), b) - bg(a)); }
tcT > int upb(V<T> &a, const T &b) { return int(ub(all(a), b) - bg(a)); }
tcT > void remDup(V<T> &v) { sort(all(v)), v.erase(unique(all(v)), end(v)); }

tcTU > bool erase(T &t, const U &u) {
    auto it = t.find(u);
    if (it == end(t)) return false;
    else
        t.erase(it);
    return true;
}
tcTU > T fstTrue(T lo, T hi, U f) {
    ++hi, assert(lo <= hi);
    while (lo < hi) {
        T mid = lo + (hi - lo) / 2;
        f(mid) ? hi = mid : lo = mid + 1;
    }
    return lo;
}
tcTU > T lstTrue(T lo, T hi, U f) {
    --lo, assert(lo <= hi);
    while (lo < hi) {
        T mid = lo + (hi - lo + 1) / 2;
        f(mid) ? lo = mid : hi = mid - 1;
    }
    return lo;
}

template <class Fun>
class y_combinator_result {
    Fun fun_;

public:
    template <class T>
    explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
    template <class... Args>
    decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template <class Fun>
decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

constexpr int pct(int x) { return __builtin_popcount(x); }                                  

constexpr int log_2(int x) { return x ? (8 * (int)sizeof(x)) - 1 - __builtin_clz(x) : -1; } 

constexpr int next_pow_2(int x) { return x > 0 ? 1 << log_2(2 * x - 1) : 0; }               

constexpr int log_2_ceil(int x) { return log_2(x) + int(__builtin_popcount(x) != 1); }      




tcT > void re(complex<T> &c);
tcTU > void re(pair<T, U> &p);
tcT > void re(V<T> &v);
tcT, size_t SZ > void re(AR<T, SZ> &a);

tcT > void re(T &x) { cin >> x; }
void re(db &d) {
    str t;
    re(t);
    d = stod(t);
}
void re(ld &d) {
    str t;
    re(t);
    d = stold(t);
}
tcTUU > void re(T &t, U &...u) {
    re(t);
    re(u...);
}
tcT > void re(complex<T> &c) {
    T a, b;
    re(a, b);
    c = {a, b};
}
tcTU > void re(pair<T, U> &p) { re(p.ff, p.ss); }
tcT > void re(V<T> &x) { each(a, x) re(a); }
tcT, size_t SZ > void re(AR<T, SZ> &x) { each(a, x) re(a); }
tcT > void rv(int n, V<T> &x) {
    x.rsz(n);
    re(x);
}



str ts(char c) { return str(1, c); }
str ts(const char *s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) {
#ifdef asr_debug
    return b ? "true" : "false";
#else
    return ts((int)b);
#endif
}
tcT > str ts(complex<T> c) {
    stringstream ss;
    ss << c;
    return ss.str();
}
str ts(V<bool> v) {
    str res = "{";
    f0r(i, sz(v))
        res += char('0' + v[i]);
    res += "}";
    return res;
}
template <size_t SZ>
str ts(bitset<SZ> b) {
    str res = "";
    f0r(i, SZ)
        res += char('0' + b[i]);
    return res;
}
tcTU > str ts(pair<T, U> p);
tcT > str ts(T v) { 

#ifdef asr_debug
    bool fst = 1;
    str res = "{";
    for (const auto &x : v) {
        if (!fst) res += ", ";
        fst = 0;
        res += ts(x);
    }
    res += "}";
    return res;
#else
    bool fst = 1;
    str res = "";
    for (const auto &x : v) {
        if (!fst) res += " ";
        fst = 0;
        res += ts(x);
    }
    return res;

#endif
}
tcTU > str ts(pair<T, U> p) {
#ifdef asr_debug
    return "(" + ts(p.ff) + ", " + ts(p.ss) + ")";
#else
    return ts(p.ff) + " " + ts(p.ss);
#endif
}



tcT > void pr(T x) { cout << ts(x); }
tcTUU > void pr(const T &t, const U &...u) { 

    pr(t);
    pr(u...);
}

void ps() { pr("\n"); }
tcTUU > void ps(const T &t, const U &...u) { 

    pr(t);
    if (sizeof...(u)) pr(" ");
    ps(u...);
}



void DBG() { cerr << "]" << endl; }
tcTUU > void DBG(const T &t, const U &...u) {
    cerr << ts(t);
    if (sizeof...(u)) cerr << ", ";
    DBG(u...);
}
#ifdef asr_debug 

#define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#define chk(...) \
    if (!(__VA_ARGS__)) cerr << "Line(" << __LINE__ << ") -> function(" << __FUNCTION__ << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << '\n', exit(0);
#else
#define dbg(...) 007
#define chk(...) 007
#endif

template <int MOD, int RT>
struct mint {
    static const int mod = MOD;
    static constexpr mint rt() { return RT; } 

    int v;
    explicit operator int() const { return v; } 

    mint() { v = 0; }
    mint(ll _v) {
        v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
        if (v < 0) v += MOD;
    }
    friend bool operator==(const mint &a, const mint &b) { return a.v == b.v; }
    friend bool operator!=(const mint &a, const mint &b) { return !(a == b); }
    friend bool operator<(const mint &a, const mint &b) { return a.v < b.v; }
    friend void re(mint &a) {
        ll x;
        re(x);
        a = mint(x);
    }
    friend str ts(mint a) { return ts(a.v); }

    mint &operator+=(const mint &m) {
        if ((v += m.v) >= MOD) v -= MOD;
        return *this;
    }
    mint &operator-=(const mint &m) {
        if ((v -= m.v) < 0) v += MOD;
        return *this;
    }
    mint &operator*=(const mint &m) {
        v = (ll)v * m.v % MOD;
        return *this;
    }
    mint &operator/=(const mint &m) { return (*this) *= inv(m); }
    friend mint pow(mint a, ll p) {
        mint ans = 1;
        assert(p >= 0);
        for (; p; p /= 2, a *= a)
            if (p & 1) ans *= a;
        return ans;
    }
    friend mint inv(const mint &a) {
        assert(a.v != 0);
        return pow(a, MOD - 2);
    }

    mint operator-() const { return mint(-v); }
    mint &operator++() { return *this += 1; }
    mint &operator--() { return *this -= 1; }
    friend mint operator+(mint a, const mint &b) { return a += b; }
    friend mint operator-(mint a, const mint &b) { return a -= b; }
    friend mint operator*(mint a, const mint &b) { return a *= b; }
    friend mint operator/(mint a, const mint &b) { return a /= b; }
};

const int MOD = 1e9 + 007; 

typedef mint<MOD, 5> mi;   

typedef vector<mi> vmi;
typedef pair<mi, mi> pmi;
typedef vector<pmi> vpmi;

vector<vmi> scmb; 

void genComb(int SZ) {
    scmb.assign(SZ, vmi(SZ));
    scmb[0][0] = 1;
    f1r(i, 1, SZ - 1) f0r(j, i + 1)
        scmb[i][j] = scmb[i - 1][j] + (j ? scmb[i - 1][j - 1] : 0);
}






























struct splitmix64_hash {
    static uint64_t splitmix64(uint64_t x) {
        

        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

tcTU, typename Hash = splitmix64_hash > using hash_map = gp_hash_table<T, U, Hash>;
tcT, typename Hash = splitmix64_hash > using hash_set = hash_map<T, null_type, Hash>;
tcT > using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

tcT > using ord_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937 rng((unsigned int)std::chrono::steady_clock::now().time_since_epoch().count()); 






const float epsf = 1e-7F;
const long double epsld = 1e-19L;
const double epsd = 2e-16;
const long double PI = 3.14159265358979323846L;
const long long lINF = 2e18L + 007;
const int iINF = 2e9 + 007;

const int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1}; 

const char dir[4] = {'U', 'R', 'D', 'L'};
const int __ = 1e6 + 007; 

const int _ = 2e5 + 007;  



















void solve() {
    int n,m; re(n,m); vi res;
    f0r(i,n)f0r(j,m) res.pb((max(i,n-i-1)+max(j,m-j-1)));
    sor(res); ao(res,n*m);
}

int main() {

#ifdef asr_time
    auto begin = chrono::high_resolution_clock::now();
#endif

    vamos;



    cin.tie(nullptr);



    fix(15);
    

    int TT = 1;
    cin >> TT;
    f1r(TC, 1, TT)
        solve();

#ifdef asr_time
    auto end = chrono::high_resolution_clock::now();
    cout << setprecision(2) << fixed;
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end - begin).count() * 1000 << " ms" << endl;
#endif

    return 0;
}