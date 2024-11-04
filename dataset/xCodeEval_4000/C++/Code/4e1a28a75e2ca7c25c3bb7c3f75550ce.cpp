

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
#define int ll
#define double ld
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
#define repR(i,n) for (int i = (int)(n)-1; i >= 0; i--)
#define rep1R(i,n) for (int i = (int)(n); i >= 1; i--)
#define loop(i,a,B) for (int i = a; i B; i++)
#define loopR(i,a,B) for (int i = a; i B; i--)
#define all(x) begin(x), end(x)
#define allR(x) rbegin(x), rend(x)
#define rng(x,l,r) begin(x) + (l), begin(x) + (r)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fst first
#define snd second
template <class Int> auto constexpr inf = numeric_limits<Int>::max()/2-1;
auto constexpr INF32 = inf<int32_t>;
auto constexpr INF64 = inf<int64_t>;
auto constexpr INF   = inf<int>;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dump(...) (void)(0)
#define say(x) (void)(0)
#define debug if (0)
#endif
template <class T, class Comp> struct pque : priority_queue<T, vector<T>, Comp> {
    vector<T> &data() { return this->c; }
    void clear() { this->c.clear(); }
};
template <class T> using pque_max = pque<T, less<T>>;
template <class T> using pque_min = pque<T, greater<T>>;
template <class T, class = typename T::iterator, enable_if_t<!is_same<T, string>::value, int> = 0>
ostream& operator<<(ostream& os, T const& a) { bool f = true; for (auto const& x : a) os << (f ? "" : " ") << x, f = false; return os; }
template <class T, size_t N, enable_if_t<!is_same<T, char>::value, int> = 0>
ostream& operator<<(ostream& os, const T (&a)[N]) { bool f = true; for (auto const& x : a) os << (f ? "" : " ") << x, f = false; return os; }
template <class T, class = decltype(begin(declval<T&>())), class = typename enable_if<!is_same<T, string>::value>::type>
istream& operator>>(istream& is, T &a) { for (auto& x : a) is >> x; return is; }
template <class T, class S> ostream& operator<<(ostream& os, pair<T,S> const& p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <class T, class S> istream& operator>>(istream& is, pair<T,S>& p) { return is >> p.first >> p.second; }
struct IOSetup { IOSetup() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); } } iosetup;
template <class F> struct FixPoint : private F {
    constexpr FixPoint(F&& f) : F(forward<F>(f)) {}
    template <class... T> constexpr auto operator()(T&&... x) const { return F::operator()(*this, forward<T>(x)...); }
};
struct MakeFixPoint { template <class F> constexpr auto operator|(F&& f) const { return FixPoint<F>(forward<F>(f)); } };
#define MFP MakeFixPoint()|
#define def(name, ...) auto name = MFP [&](auto &&name, __VA_ARGS__)
template <class T, size_t d> struct vec_impl {
    using type = vector<typename vec_impl<T,d-1>::type>;
    template <class... U> static type make_v(size_t n, U&&... x) { return type(n, vec_impl<T,d-1>::make_v(forward<U>(x)...)); }
};
template <class T> struct vec_impl<T,0> { using type = T; static type make_v(T const& x = {}) { return x; } };
template <class T, size_t d = 1> using vec = typename vec_impl<T,d>::type;
template <class T, size_t d = 1, class... Args> auto make_v(Args&&... args) { return vec_impl<T,d>::make_v(forward<Args>(args)...); }
template <class T> void quit(T const& x) { cout << x << endl; exit(0); }
template <class T, class U> constexpr bool chmin(T& x, U const& y) { if (x > y) { x = y; return true; } return false; }
template <class T, class U> constexpr bool chmax(T& x, U const& y) { if (x < y) { x = y; return true; } return false; }
template <class It> constexpr auto sumof(It b, It e) { return accumulate(b, e, typename iterator_traits<It>::value_type{}); }
template <class T> int sz(T const& x) { return x.size(); }
template <class C, class T> int lbd(C const& v, T const& x) { return lower_bound(begin(v), end(v), x)-begin(v); }
template <class C, class T> int ubd(C const& v, T const& x) { return upper_bound(begin(v), end(v), x)-begin(v); }
const int dx[] = { 1,0,-1,0,1,-1,-1,1 };
const int dy[] = { 0,1,0,-1,1,1,-1,-1 };
constexpr int popcnt(ll x) { return __builtin_popcountll(x); }


template <class Int> Int rand(Int a, Int b) { static mt19937_64 mt{random_device{}()}; return uniform_int_distribution<Int>(a,b)(mt); }
i64 irand(i64 a, i64 b) { return rand<i64>(a,b); }
u64 urand(u64 a, u64 b) { return rand<u64>(a,b); }




template <uint32_t md>
class modint {
    static_assert(md < (1u<<31), "");
    using M = modint;
    using i64 = int64_t;
    uint32_t x;
public:
    static constexpr uint32_t mod = md;
    constexpr modint(i64 x = 0) : x((x%=md) < 0 ? x+md : x) { }
    constexpr i64 val() const { return x; }
    constexpr explicit operator i64() const { return x; }
    constexpr bool operator==(M r) const { return x == r.x; }
    constexpr bool operator!=(M r) const { return x != r.x; }
    constexpr M operator+() const { return *this; }
    constexpr M operator-() const { return M()-*this; }
    constexpr M& operator+=(M r) { x += r.x; x = (x < md ? x : x-md); return *this; }
    constexpr M& operator-=(M r) { x += md-r.x; x = (x < md ? x : x-md); return *this; }
    constexpr M& operator*=(M r) { x = (uint64_t(x)*r.x)%md; return *this; }
    constexpr M& operator/=(M r) { return *this *= r.inv(); }
    constexpr M operator+(M r) const { return M(*this) += r; }
    constexpr M operator-(M r) const { return M(*this) -= r; }
    constexpr M operator*(M r) const { return M(*this) *= r; }
    constexpr M operator/(M r) const { return M(*this) /= r; }
    friend constexpr M operator+(i64 x, M y) { return M(x)+y; }
    friend constexpr M operator-(i64 x, M y) { return M(x)-y; }
    friend constexpr M operator*(i64 x, M y) { return M(x)*y; }
    friend constexpr M operator/(i64 x, M y) { return M(x)/y; }
    constexpr M inv() const { assert(x > 0); return pow(md-2); }
    constexpr M pow(i64 n) const {
        assert(not (x == 0 && n == 0));
        if (n < 0) return inv().pow(-n);
        M v = *this, r = 1;
        for (; n > 0; n >>= 1, v *= v) if (n&1) r *= v;
        return r;
    }
#ifdef LOCAL
    friend string to_s(M r) { return to_s(r.val(), mod); }
#endif
    friend ostream& operator<<(ostream& os, M r) { return os << r.val(); }
    friend istream& operator>>(istream& is, M &r) { i64 x; is >> x; r = x; return is; }
};




constexpr int64_t MOD = 1e9+7;
using mint = modint<MOD>;
mint sgn(int n) { return n%2 == 0 ? +1 : -1; }


template <uint32_t mod>
struct ModTable {
    vector<uint32_t> fact = {1,1}, finv = {1,1}, inv = {0,1};
    void calc(int n) {
        int old = fact.size();
        if (n < old) return;
        fact.resize(n+1);
        finv.resize(n+1);
        inv.resize(n+1);
        for (uint32_t i = old; i <= n; i++) {
            fact[i] = uint64_t(fact[i-1])*i % mod;
            inv[i] = mod - uint64_t(inv[mod%i])*(mod/i) % mod;
            finv[i] = uint64_t(finv[i-1])*inv[i] % mod;
        }
    }
};
ModTable<MOD> mod_tab;

modint<MOD> fact(int n) {
    assert(0 <= n);
    return mod_tab.calc(n), mod_tab.fact[n];
}
modint<MOD> finv(int n) {
    assert(0 <= n);
    return mod_tab.calc(n), mod_tab.finv[n];
}
modint<MOD> C(int n, int k) {
    if (n < 0 || k < 0 || n < k) return 0;
    return fact(n)*finv(k)*finv(n-k);
}
modint<MOD> P(int n, int k) {
    assert(k >= 0); assert(n >= k);
    return fact(n)*finv(n-k);
}





constexpr int dst(int v) { return v; }
template <class E, class = decltype(declval<E>().to)>
constexpr int dst(E const& e) { return e.to; }

template <class E> struct LCA {
    vector<vector<E>> const* g;
    int32_t n,lg,root;
    vector<int32_t> d;
    vector<vector<int32_t>> anc;
    LCA() {}
    LCA(vector<vector<E>> const* g, int root = 0)
        : g(g), n(g->size()), root(root), d(n) {
        lg = 1; while ((1<<lg) < n) lg++; 

        anc.assign(lg, vector<int32_t>(n,-1));
        dfs(root);
        rep (i,lg-1) rep (j,n) if (anc[i][j] >= 0) {
            anc[i+1][j] = anc[i][anc[i][j]];
        }
    }
    void dfs(int x, int p = -1) {
        anc[0][x] = p;
        d[x] = (p == -1 ? 0 : d[p]+1);
        for (auto const& e : (*g)[x]) if (dst(e) != p) dfs(dst(e),x);
    }
    int dep(int a) const { return d[a]; }
    int operator()(int a, int b) const { return lca(a,b); }
    int lca(int a, int b) const {
        if (d[a] > d[b]) swap(a,b);
        for (int dd = d[b]-d[a], i = 0; dd; dd >>= 1, i++) {
            if (dd&1) b = anc[i][b];
        }
        if (a == b) return a;
        for (int i = lg-1; i >= 0; i--) {
            if (anc[i][a] != anc[i][b]) a = anc[i][a], b = anc[i][b];
        }
        return anc[0][a];
    }
    int dist(int a, int b) const { return d[a] + d[b] - 2*d[lca(a,b)]; }
    int climb(int v, int dist) const {
        for (int i = 0; dist && v >= 0; dist >>= 1, i++) {
            if (dist&1) v = anc[i][v];
        }
        return v;
    }
};
template <class E>
auto get_lca(vector<vector<E>> const& g, int root = 0) { return LCA<E>(&g,root); }






template <class Handler>
struct ReRooting : Handler {
    using edge = typename Handler::edge;
    using subs = typename Handler::subs; 

    using sub = typename Handler::sub; 

    using Handler::subs_unit; 

    using Handler::sub_unit; 

    using Handler::add; 

    using Handler::merge; 


    vector<vector<edge>> const* g;
    vector<sub> dp1,dp2,dp0;
    ReRooting(vector<vector<edge>> const& g)
        : g(&g), dp1(g.size()), dp2(g.size()) {}
    vector<sub> run() {
        assert(g->size());
        dfs1(0,-1);
        dump(dp1);
        dp0 = dp1;
        dp2[0] = sub_unit(0);
        dfs2(0,-1);
        dump(dp2);
        dump(dp1);
        return dp1;
    }
    void dfs1(int x, int p) {
        subs dat = subs_unit(x);
        for (auto const& e : (*g)[x]) {
            const int y = dst(e);
            if (y == p) continue;
            dfs1(y,x);
            dat = add(dat,dp1[y],e,x);
        }
        dp1[x] = merge(dat,subs_unit(x),x);
    }
    void dfs2(int x, int p) {
        auto const& es = (*g)[x];
        auto d = [&](int i) { return dst(es[i]); };
        const int m = es.size();
        {
            vector<subs> ldp(m+1, subs_unit(x)), rdp(m+1, subs_unit(x));
            for (int i = 0; i < m; i++) {
                sub val = (d(i) == p ? dp2[x] : dp1[d(i)]);
                ldp[i+1] = add(ldp[i],val,es[i],x);
            }
            for (int i = m-1; i >= 0; i--) {
                sub val = (d(i) == p ? dp2[x] : dp1[d(i)]);
                rdp[i] = add(rdp[i+1],val,es[i],x);
            }
            dp1[x] = merge(subs_unit(x),rdp[0],x);
            for (int i = 0; i < m; i++) {
                if (d(i) != p) dp2[d(i)] = merge(ldp[i],rdp[i+1],x);
            }
        }
        for (int i = 0; i < m; i++) if (d(i) != p) dfs2(d(i),x);
    }
};




struct edge { int to, cost; };
struct Handler {
    using edge = ::edge;
    using sub = array<mint, 3>;
    using subs = sub;
    static sub sub_unit(int) { return {0,0,0}; }
    static subs subs_unit(int x) { return sub_unit(x); }
    static subs add(subs const& x, sub const& y, edge const& e, int) {
        return { x[0] + y[0],
                 x[1] + y[1] + y[0]*e.cost,
                 x[2] + y[2] + 2*y[1]*e.cost + y[0]*e.cost*e.cost };
    }
    static sub merge(subs const& x, subs const& y, int) {
        return { x[0] + y[0] + 1, x[1] + y[1], x[2] + y[2] };
    }
};

int32_t main() {
    int n; cin >> n;
    vector<vector<edge>> g(n);
    rep (i,n-1) {
        int a,b,c; cin >> a >> b >> c; --a, --b;
        g[a].pb({b,c});
        g[b].pb({a,c});
    }

    auto lca = get_lca(g);
    vector<int> dep(n), par_d(n);
    def (dfs, int x, int p, int d) -> void {
        dep[x] = d;
        for (auto e : g[x]) {
            if (e.to == p) continue;
            par_d[e.to] = e.cost;
            dfs(e.to, x, d + e.cost);
        }
    };
    dfs(0, -1, 0);

    ReRooting<Handler> rr(g);
    rr.run();

    int q; cin >> q;
    rep (_,q) {
        int a,b; cin >> a >> b, --a, --b;
        mint total = rr.dp1[a][2];
        mint dist = dep[a] + dep[b] - 2*dep[lca(a,b)];
        if (lca(a,b) != b) {
            mint A = rr.dp0[b][2] + 2*rr.dp0[b][1]*dist + rr.dp0[b][0]*dist*dist;
            mint B = total - A;
            cout << A - B << "\n";
        } else {
            dist += par_d[b];
            mint B = rr.dp2[b][2] + 2*rr.dp2[b][1]*dist + rr.dp2[b][0]*dist*dist;
            mint A = total - B;
            cout << A - B << "\n";
        }
    }

}
