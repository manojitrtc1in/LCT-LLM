const int mod1 = 1000000007, mod2 = 998244353;
const int mod = mod2;
#include <bits/stdc++.h>
using namespace std;


template <int MOD_> struct modnum {
    static constexpr int MOD = MOD_;
    static_assert(MOD_ > 0, "MOD must be positive");
private:
    using ll = long long;
    int v;
    static int minv(int a, int m) {
        a %= m;
        assert(a);
        return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
    }
public:
    modnum() : v(0) {}
    modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
    explicit operator int() const { return v; }
    friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
    friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }

    friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

    modnum inv() const {
        modnum res;
        res.v = minv(v, MOD);
        return res;
    }
    modnum neg() const {
        modnum res;
        res.v = v ? MOD-v : 0;
        return res;
    }
    modnum operator- () const {
        return neg();
    }
    modnum operator+ () const {
        return modnum(*this);
    }

    modnum& operator ++ () {
        v ++;
        if (v == MOD) v = 0;
        return *this;
    }
    modnum& operator -- () {
        if (v == 0) v = MOD;
        v --;
        return *this;
    }
    modnum& operator += (const modnum& o) {
        v += o.v;
        if (v >= MOD) v -= MOD;
        return *this;
    }
    modnum& operator -= (const modnum& o) {
        v -= o.v;
        if (v < 0) v += MOD;
        return *this;
    }
    modnum& operator *= (const modnum& o) {
        v = int(ll(v) * ll(o.v) % MOD);
        return *this;
    }
    modnum& operator /= (const modnum& o) {
        return *this *= o.inv();
    }

    friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
    friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
    friend modnum pow(modnum x, size_t n) {
        modnum res = 1;
        while (n) {
            if (n & 1) res *= x;
            x *= x;
            n /= 2;
        }
        return res;
    }
};

struct Modnum {
private:
    static int MOD; 

    using ll = long long;
    using modnum = Modnum;
    int v;

    static int minv(int a, int m) {
        a %= m;
        assert(a);
        return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
    }

public:
    Modnum() : v(0) {}
    Modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
    static void set_mod(const int &m) {
        assert(m > 0);
        MOD = m;
    }
    explicit operator int() const { return v; }
    friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
    friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }

    friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

    modnum inv() const {
        modnum res;
        res.v = minv(v, MOD);
        return res;
    }
    modnum neg() const {
        modnum res;
        res.v = v ? MOD-v : 0;
        return res;
    }
    modnum operator- () const {
        return neg();
    }
    modnum operator+ () const {
        return *this;
    }

    modnum& operator ++ () {
        v ++;
        if (v == MOD) v = 0;
        return *this;
    }
    modnum& operator -- () {
        if (v == 0) v = MOD;
        v --;
        return *this;
    }
    modnum& operator += (const modnum& o) {
        v += o.v;
        if (v >= MOD) v -= MOD;
        return *this;
    }
    modnum& operator -= (const modnum& o) {
        v -= o.v;
        if (v < 0) v += MOD;
        return *this;
    }
    modnum& operator *= (const modnum& o) {
        v = int(ll(v) * ll(o.v) % MOD);
        return *this;
    }
    modnum& operator /= (const modnum& o) {
        return *this *= o.inv();
    }

    friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
    friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};
int Modnum::MOD = 1; 


#define sq(x) (x)*(x) 

#define FAST_READ ios::sync_with_stdio(false); cin.tie(nullptr);
#ifdef LOCAL
#define see(x) cout  <<"<DBG> " << #x << ": " << (x) << endl
#endif
#ifndef LOCAL
#define see(x)
#endif
#define LSON(x) ((x) * 2)
#define RSON(x) ((x) * 2 + 1)
template<typename A, typename B>
void Min(A &a, const B &b){
    if (b < a) a = b;
}
template<typename A, typename B>
void Max(A &a, const B &b){
    if (b > a) a = b;
}

int cas;
ostream& kase() {
    return cout << "Case #" << ++cas << ": ";
}

#if __cplusplus < 201402L
template<class Iterator>
std::reverse_iterator<Iterator> make_reverse_iterator(Iterator it)
{
    return std::reverse_iterator<Iterator>(it);
}
#endif

template <typename iter_t>
struct iter_pair {
    iter_t _beg, _end;
    iter_t begin(){return _beg;}
    iter_t end(){return _end;}
};

template<class cont> iter_pair<reverse_iterator<decltype(begin(declval<cont>()))>>
reverse(cont &&r) {
    return {make_reverse_iterator(end(r)), make_reverse_iterator(begin(r))};
}

template<typename T> void dprintln(const T &t) { cout << t << endl; } 

template<typename T, typename ...Args> void dprintln(const T &t, const Args &...rest) { cout << t << ' '; dprintln(rest...); }
template<typename T> void println(const T &t) { cout << t << '\n'; }


template<typename T, typename ...Args> void println(const T &t, const Args &...rest) { cout << t << ' '; println(rest...); }
template<typename T> void println(const vector<T>& vec) {
    if (!vec.empty()) {
        cout << vec[0];
        for (size_t i = 1; i < vec.size(); ++i)
            cout << ' ' << vec[i];
    }
    cout << '\n';
}

template<typename T> void print(const T &t) { cout << t << ' '; }

template<typename T, typename ...Args> void print(const T &t, const Args &...rest) { cout << t << ' '; print(rest...); }



template<class T> void scan(T &t) { cin >> t; }
template<class T, class ...Args> void scan(T &a, Args &...rest) { cin >> a; scan(rest...); }
template<typename T> istream& operator>>(istream& stream, vector<T>& vec) {
    for (auto& x : vec) stream >> x;
    return stream;
}
using ull = unsigned long long;
using ll = long long;
using ul = unsigned long;
using vl = vector<ll>;
using vi = vector<int>;
using pii = pair<int,int>;
using pip = pair<int,pii>;
using pll = pair<ll,ll>;
using vb = vector<bool>;
using vpii = vector<pii>;
using ldb = long double;
template <typename int_t>
inline int_t lowbit(int_t x) {return x & -x;}
#define rng(i, a, b) for(int i = (int)(a); i < (int)(b); ++i)
#define up(i, a, b) for (int i = int(a); i <= int(b); ++i)
#define down(i, b, a) for (int i = int(b); i >= int(a); i--)
#define rep(n) for(int _iter_##n = 0, _num_##n = (int)n; _iter_##n < _num_##n; ++_iter_##n)
#define stp(i, a, b, c) for (int i = (a); i < (b); i += (c))
#define FOR(x, cont) for (const auto &x: cont)
#define INC(init, x, y) for (init; x <= y; ++x)
#define For(x, cont) for (auto &x: cont)
#define all(x) begin(x), end(x)
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define SZ(x) (int)(x).size()
#define UP(i, l, r) for(i = decltype(i)(l); i <= decltype(i)(r); ++i)
#define DOWN(i, r, l) for (i = decltype(i)(r); i >= decltype(i)(l); --i)
#define Dec(a, b) for (; a >= b; --a)
template <typename T, typename Comp = less<T>>
using pq = priority_queue<T, vector<T>, Comp>;
#define popcnt(x) __builtin_popcountll((x))
#define SET(arr, v) memset(arr, (v), sizeof (arr))
#define UNIQ(vec) (vec).erase(unique(all(vec)), end(vec))
#define LB(cont, x) int(lower_bound(all(cont), x) - begin(cont))
#define UB(cont, x) int(upper_bound(all(cont), x) - begin(cont))
#define AI(name, n, m) vv<int> name(n, vi(m));
#define AL(name, n, m) vv<ll> name(size_t(n), vl(size_t(m)));
#define set0(arr) memset(arr, 0, sizeof arr)
#define set1(arr) memset(arr, -1, sizeof arr)
#define AT(T, n, m, a)  vector<vector<T>> a(n, vector<T>(m))
const int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
auto bet = [](const ll x, const ll y, const ll i) {
    return x <= i && i <= y;
};

template<typename T1, typename T2>
T1 ceil(T1 x, T2 y) { 

    return (x + y - 1) / y;
}

inline int h_bit(unsigned long long x) {
    return (int)sizeof(unsigned long long) * 8 - 1 - __builtin_clzll(x);
}

int pow2(int x){ 

    return int(1U << h_bit((ull)x)) + (x != lowbit(x));
}

template <typename T>
struct bit {
    vector<T> a;
    function<T(T,T)> bin_op;
    const T init;
    explicit bit(int n, function<T(T,T)> bin_op, T init):bin_op(bin_op), init(init) {
        a.assign(n + 1, init);
    }

    T prefix(T x) {
        auto res = init;
        while (x) {
            res = bin_op(a[x], res);
            x -= x & -x;
        }
        return res;
    }
    void modify(int x, T v) {
        while (x < (int)a.size()) {
            a[x] = bin_op(a[x], v);
            x += x & -x;
        }
    }
    void clear(){
        fill(a.begin(), a.end(), init);
    }
};

template <typename T>
struct r_bit {
    vector<T> a;
    function<T(T,T)> bin_op;
    const T init;
    explicit r_bit(int n, function<T(T,T)> bin_op, T init):bin_op(move(bin_op)), init(init) {
        a.ssign(n + 1, init);
    }
    T suffix(int x) {
        T res = init;
        while (x < SZ(a)) {
            res = bin_op(res, a[x]);
            x += x & -x;
        }
        return res;
    }
    void modify(int x, T v) {
        while (x > 0) {
            a[x] = bin_op(a[x], v);
            x -= x & -x;
        }
    }
    void clear(){
        fill(a.begin(), a.end(), init);
    }
};

vi get_prime(int n) {
    vi minp((ul) n + 1), p;
    for (int i = 2; i <= n; i++) {
        if (!minp[i]) {
            minp[i] = i;
            p.pb(i);
        }
        FOR(x, p) {
            if (x <= minp[i] && x * i <= n)
                minp[x * i] = x;
            else break;
        }
    }
    return p;
}



template<typename T> using vv = vector<vector<T>>;
template <typename T1, typename T2 = T1> using vp = vector<pair<T1,T2>>;
template<typename T, int n> using va = vector<array<T,n>>;





#ifdef __GNUC__
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
template <typename T>
using rank_tree = __gnu_pbds::tree<
        T,
        __gnu_pbds::null_type,
        less<T>,
        __gnu_pbds::rb_tree_tag,
        __gnu_pbds::tree_order_statistics_node_update>;
#endif



struct UF {
    vi par, sz;
    int n_tree;
    explicit UF(int n) { 

        par.assign(n, 0);
        sz.assign(n, 1);
        rng (i, 0, n) par[i] = i;
        n_tree = n;
    }
    int n_cluster() const {
        return n_tree;
    }
    int size(int x) {
        return sz[root(x)];
    }
    int root(int x) {
        return x == par[x] ? x : par[x] = root(par[x]);
    }
    bool unite(int x, int y) {
        int rx = root(x), ry = root(y);
        if(rx != ry) {
            par[rx] = ry;
            --n_tree;
            sz[ry] += sz[rx];
            return true;
        }
        return false;
    }
};

template<typename T, typename Compare = std::less<T>>
struct SparseTable {
    size_t n{}; 

    vv<T> a;

    template<typename ptr_t>
    SparseTable(ptr_t beg, ptr_t end):n(end - beg) {
        a.resize((size_t) h_bit(n) + 1); 

        a[0].assign(beg, end);
        rng (i, 0, SZ(a) - 1) {
            a[i + 1].resize(n);
            rng(j, 0, n - (1u << i)) {
                a[i + 1][j] = min(a[i][j], a[i][j + (1u << i)], Compare());
            }
            rng(j, n - (1u << i), n) {
                a[i + 1][j] = a[i][j];
            }
        }
    }
    using idx_t = long;
    T query(idx_t l, idx_t r) { 

        int i = h_bit(r - l + 1ul);
        return min(a[i][l], a[i][r + 1 - (1u << i)], Compare());
    }
};

vi get_popcnt(int n) {
    vi res((ul)n + 1);
    rng (i, 0, n) {
        if (i * 2 <= n) res[i * 2] = res[i];
        if ((i & 1) == 0) res[i + 1] = res[i] + 1;
    }
    return res;
}

vi get_mu(int n) {
    assert(n > 0);
    vi mu(n + 1);
    vi min_p(n + 1);
    vi prime;
    mu[1] = 1;
    rng (i, 2, n + 1) {
        if (!min_p[i]) {
            prime.pb(i);
            min_p[i] = i;
            mu[i] = -1;
        }
        FOR (p, prime) {
            if (p > min_p[i]) {
                break;
            }
            int t = p * i;
            if (t > n) break;
            min_p[t] = p;
            mu[t] = p == min_p[i] ? 0 : -mu[i];
        }
    }
    return mu;
}

template<typename num>
num fp(num x, ll n) { 

    if (n < 0) {
        x = fp(x, mod - 2);
        n = -n;
    }
    num ans = 1;
    while (n) {
        if (n & 1) ans *= x;
        n /= 2;
        x *= x;
    }
    return ans;
}

template<typename num>
void bit_reverse_swap(vector<num> &a) {
    int n = SZ(a);
    for (int i = 1, j = n >> 1, k; i < n - 1; i++) {
        if (i < j) swap(a[i], a[j]);
        

        for (k = n >> 1; j >= k; j -= k, k >>= 1);    

        j += k;
    }
}

template<typename num>
void FFT(vector<num> &a, int type) {
    bit_reverse_swap(a);
    int n = SZ(a);
    for (int i = 2; i <= n; i *= 2) {
        const auto wi = fp(3, type * (mod - 1) / i); 

        for (int j = 0; j < n; j += i) {
            num w(1);
            for (int k = j, h = i >> 1; k < j + h; k++) {
                auto t = w * a[k + h], u = a[k];
                a[k] = u + t;
                a[k + h] = u - t;
                w *= wi;
            }
        }
    }
    const auto inv = num(n).inv();
    if (type == -1) for (auto &x : a) x *= inv;
}
template <typename num>
void fp(vector<num> &a, const int n) {
    a.resize((ul)pow2((SZ(a)-1) * n + 1));
    FFT(a, 1);
    for(auto &x: a) x = fp(x, n);
    FFT(a, -1);
}


string to_string(const string& s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif





struct point {
    int x, y;

    void read() {
        scan(x, y);
    }

    ll cross(const point &b) const {
        return 1LL * x * b.y - 1LL * y * b.x;
    }

    point operator-(const point &b) const {
        return {x - b.x, y - b.y};
    }

    bool para(const point &b) const { 

        return 1LL * x * b.y == 1LL * y * b.x;
    }

    bool operator<(const point &b) const {
        return cross(b) < 0;
    }
};

struct segment {
    point p, dir;

    bool on_same_line(const segment &other) const {
        return dir.para(other.dir) && (p - other.p).para(dir);
    }

    bool para(const segment &b) const {
        return dir.para(b.dir);
    }

    bool operator==(const segment &b) const {
        return this->on_same_line(b);
    }
};
struct fraction {
    int n, d;
    bool operator<(const fraction& that) const {
        return 1LL * n * that.d < 1LL * that.n * d;
    }
    bool operator==(const fraction& that) const {
        return n == that.n && d == that.d;
    }
    bool operator>=(const fraction& that) const {
        return !(*this < that);
    }
    bool operator>(const fraction& that) const {
        return 1LL * n * that.d > 1LL * that.n * d;
    }
    fraction inverse() const {
        return n < 0 ? fraction{-d, -n} : fraction{d, n};
    }
    fraction(int n, int d) {
        if (d < 0) n = -n, d = -d;
        int g = __gcd(abs(n), d);
        n /= g, d /= g;
        this->n = n, this->d = d;
    }
    explicit fraction(int x): n(x), d(1) {}
    fraction operator+(const fraction& that) const {
        return fraction{n * that.d + that.n * d, d * that.d};
    }
    fraction operator-(const fraction& that) const {
        return fraction{n * that.d - that.n * d, d * that.d};
    }
    fraction floor() const {
        if (d == 0) return *this;
        return fraction((n < 0 ? n - (d - 1) : n) / d);
    }
    friend ostream& operator<<(ostream& out, const fraction& f) {
        return out << "(" << f.n <<',' << f.d << ')';
    }
    pii to_pair() const {
        return {n, d};
    }
};
using Num = modnum<mod>;
struct Binom {
    vector<Num> f;
    explicit Binom(int n){
        f.resize(n + 1);
        f[0] = 1;
        up (i, 1, n) f[i] = f[i - 1] * i;
    }
    Num get_binom(int x, int y) const {
        assert(x <= SZ(f) - 1);
        assert(x >= 0 && y >= 0);
        if (x < y) return 0;
        return f[x] / (f[y] * f[x - y]);
    }
    Num get_fact(int n) const {
        assert(n < SZ(f));
        return f[n];
    }
};



namespace HLD {
    const int max_V = 1e5 + 5;
    vi g[max_V]; 

    int fa[max_V];
    int sz[max_V];
    int heavy_son[max_V];
    int dep[max_V];
    void dfs(int u, int f) {
        fa[u] = f;
        sz[u] = 1;
        dep[u] = dep[f] + 1;
        int hson = 0;
        FOR(v, g[u]) {
            if (v != f) {
                dfs(v, u);
                sz[u] += sz[v];
                if (sz[v] > sz[hson]) hson = v;
            }
        }
        heavy_son[u] = hson;
    }

    int top[max_V];
    int pos[max_V]; 




    void init(int n) { 

        int idx = 0;
        rng (i, 1, n + 1) {
            if (i != heavy_son[fa[i]]) {
                for (int j = i; j != 0; j = heavy_son[j]) {
                    top[j] = i;
                    pos[j] = idx++;
                }
            }
        }
    }



    bool VALUE_ON_EDGE = true;



    template<class BinOpr>
    void process_path(int u, int v, BinOpr op) {
        while (top[u] != top[v]) {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            op(pos[top[u]], pos[u]);
            u = fa[top[u]];
        }
        if (dep[u] > dep[v]) swap(u, v);
        op(pos[u] + VALUE_ON_EDGE, pos[v]);
    }
}


template <typename T>
T get_mid(T l, T r) {
    assert(l <= r);
    return l + (r - l) / 2;
}
template <typename T>
int get_bit(T a, int i) {
    return a >> i & 1;
}


template <typename T>
T inverse(T a, T m) {
    T u = 0, v = 1;
    while (a != 0) {
        T t = m / a;
        m -= t * a; swap(a, m);
        u -= t * v; swap(u, v);
    }


    return u; 

}



int main() {
    FAST_READ
    cout << fixed << setprecision(10);
#ifdef LOCAL
    ifstream in("main.in");
    cin.rdbuf(in.rdbuf());




#endif
    int h, w, n;
    scan(h, w, n);
    vb is_covered_row(h + 1);
    vb is_covered_col(w + 1);
    rep (n) {
        rep (2) {
            int r, c;
            scan(r, c);
            is_covered_col[c] = true;
            is_covered_row[r] = true;
        }
    }
    vv<int> f(h + 1, vi(h/2 + 1));
    up (r, 0, h) f[r][0] = 1;
    up (r, 2, h) {
        up (i, 1, r/2) {
            if (is_covered_row[r] || is_covered_row[r - 1]) {
                f[r][i] = f[r - 1][i];
            } else {
                f[r][i] = f[r - 1][i] + f[r - 2][i - 1];
                if (f[r][i] >= mod) {
                    f[r][i] -= mod;
                }
            }
        }
    }
    vv<int> g(w + 1, vi(w/2 + 1));
    up (c, 0, w) {
        g[c][0] = 1;
    }
    up (c, 2, w) {
        up (i, 1, w / 2) {
            if (is_covered_col[c] || is_covered_col[c - 1]) {
                g[c][i] = g[c - 1][i];
            } else {
                g[c][i] = g[c - 1][i] + g[c - 2][i - 1];
                if (g[c][i] >= mod) {
                    g[c][i] -= mod;
                }
            }
        }
    }
    int n_empty_row = 0;
    rng (i, 1, h + 1) {
        n_empty_row += !is_covered_row[i];
    }
    int n_empty_col = 0;
    rng (i, 1, w + 1) {
        n_empty_col += !is_covered_col[i];
    }
    const int max_n = 3600;
    Binom b(max_n);
    Num ans;

    for (int dv = 0; dv <= n_empty_row / 2; ++dv) {
        Num t;
        for (int dh = 0; dh <= n_empty_row - 2 * dv; ++dh) {
            if (2 * dh + dv <= n_empty_col) {








                t += b.get_binom(n_empty_row - 2 * dv, dh) * g[w][dh] * b.get_binom(n_empty_col - 2 * dh, dv) * b.get_fact(dh);
            }
        }
        ans += f[h][dv] * b.get_fact(dv) * t;
    }
    println(ans);

#ifdef LOCAL
    cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}

