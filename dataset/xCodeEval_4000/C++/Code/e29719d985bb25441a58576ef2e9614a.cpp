

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
#define int ll
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define repR(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define rep1R(i, n) for (int i = (int)(n); i >= 1; i--)
#define loop(i, a, B) for (int i = a; i B; i++)
#define loopR(i, a, B) for (int i = a; i B; i--)
#define all(x) begin(x), end(x)
#define allR(x) rbegin(x), rend(x)
#define rng(x, l, r) begin(x) + (l), begin(x) + (r)
#define pb push_back
#define eb emplace_back
#define fst first
#define snd second
template <class A, class B> constexpr auto mp(A &&a, B &&b) { return make_pair(forward<A>(a), forward<B>(b)); }
template <class... T> constexpr auto mt(T&&... x) { return make_tuple(forward<T>(x)...); }
template <class Int> auto constexpr inf_ = numeric_limits<Int>::max()/2-1;
auto constexpr INF32 = inf_<int32_t>;
auto constexpr INF64 = inf_<int64_t>;
auto constexpr INF   = inf_<int>;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dump(...) (void)(0)
#define say(x) (void)(0)
#define debug if (0)
#endif
template <class T, class Comp> struct pque : priority_queue<T, vector<T>, Comp> { vector<T> &data() { return this->c; } void clear() { this->c.clear(); } };
template <class T> using pque_max = pque<T, less<T>>;
template <class T> using pque_min = pque<T, greater<T>>;
template <class T, class = typename T::iterator, enable_if_t<!is_same<T, string>::value, int> = 0>
ostream& operator<<(ostream& os, T const& a) { bool f = true; for (auto const& x : a) os << (f ? "" : " ") << x, f = false; return os; }
template <class T, size_t N, enable_if_t<!is_same<T, char>::value, int> = 0>
ostream& operator<<(ostream& os, const T (&a)[N]) { bool f = true; for (auto const& x : a) os << (f ? "" : " ") << x, f = false; return os; }
template <class T, class = decltype(begin(declval<T&>())), class = typename enable_if<!is_same<T, string>::value>::type>
istream& operator>>(istream& is, T &a) { for (auto& x : a) is >> x; return is; }
template <class T, class S> ostream& operator<<(ostream& os, pair<T, S> const& p) { return os << p.first << " " << p.second; }
template <class T, class S> istream& operator>>(istream& is, pair<T, S>& p) { return is >> p.first >> p.second; }
struct IOSetup { IOSetup() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); } } iosetup;
template <class F> struct FixPoint : private F {
    constexpr FixPoint(F&& f) : F(forward<F>(f)) {}
    template <class... T> constexpr auto operator()(T&&... x) const { return F::operator()(*this, forward<T>(x)...); }
};
struct MakeFixPoint { template <class F> constexpr auto operator|(F&& f) const { return FixPoint<F>(forward<F>(f)); } };
#define MFP MakeFixPoint()|
#define def(name, ...) auto name = MFP [&](auto &&name, __VA_ARGS__)
template <class T, size_t d> struct vec_impl {
    using type = vector<typename vec_impl<T, d-1>::type>;
    template <class... U> static type make_v(size_t n, U&&... x) { return type(n, vec_impl<T, d-1>::make_v(forward<U>(x)...)); }
};
template <class T> struct vec_impl<T, 0> { using type = T; static type make_v(T const& x = {}) { return x; } };
template <class T, size_t d = 1> using vec = typename vec_impl<T, d>::type;
template <class T, size_t d = 1, class... Args> auto make_v(Args&&... args) { return vec_impl<T, d>::make_v(forward<Args>(args)...); }
template <class T> void quit(T const& x) { cout << x << endl; exit(0); }
template <class T, class U> constexpr bool chmin(T& x, U const& y) { if (x > y) { x = y; return true; } return false; }
template <class T, class U> constexpr bool chmax(T& x, U const& y) { if (x < y) { x = y; return true; } return false; }
template <class It> constexpr auto sumof(It b, It e) { return accumulate(b, e, typename iterator_traits<It>::value_type{}); }
template <class T> int sz(T const& x) { return x.size(); }
template <class C, class T> int lbd(C const& v, T const& x) { return lower_bound(begin(v), end(v), x)-begin(v); }
template <class C, class T> int ubd(C const& v, T const& x) { return upper_bound(begin(v), end(v), x)-begin(v); }
int64_t mod(int64_t x, int64_t m) { assert(m != 0); return (x %= m) < 0 ? x+m : x; }
const int dx[] = { 1, 0, -1, 0, 1, -1, -1, 1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
constexpr int popcnt(ll x) { return __builtin_popcountll(x); }
mt19937_64 seed_{random_device{}()};
template <class Int> Int rand(Int a, Int b) { return uniform_int_distribution<Int>(a, b)(seed_); }
i64 irand(i64 a, i64 b) { return rand<i64>(a, b); } 

u64 urand(u64 a, u64 b) { return rand<u64>(a, b); } 

template <class It> void shuffle(It l, It r) { shuffle(l, r, seed_); }
vector<int> &operator--(vector<int> &v) { for (int &x : v) --x; return v; }
vector<int> &operator++(vector<int> &v) { for (int &x : v) ++x; return v; }




#ifndef EDGE_INFO
#define EDGE_INFO
constexpr int dest(int v) { return v; }
template <class E, class = decltype(declval<E>().to)>
constexpr int dest(E const& e) { return e.to; }
constexpr int cost(int) { return 1; }
template <class E, class = decltype(declval<E>().cost)>
constexpr auto cost(E const& e) { return e.cost; }
template <class E> using cost_t = decltype(cost(declval<E>()));
#endif
template <class edge> struct HLD {
    int n, m = 0;
    vector<vector<edge>> g;
    vector<int32_t> vid, inv, head, sz, par;
    vector<cost_t<edge>> dep;
    bool built = false;
    HLD(int n) : n(n), g(n), vid(n), inv(n), head(n), sz(n), par(n), dep(n) {}
    vector<edge> const& operator[](int i) const {
        assert(built);
        assert(0 <= i); assert(i < (int)g.size());
        return g[i];
    }
    template <class... Args> void add_edge(int x, int y, Args&&... args) {
        g[x].push_back({y, args...});
        g[y].push_back({x, args...});
        m++;
        built = false;
    }
    void build(int root = 0) {
        assert(m == n-1);
        fill(sz.begin(), sz.end(), 1);
        dep[root] = 0, par[root] = -1, head[root] = root;
        int id = 0;
        dfs1(root), dfs2(root, id);
        rep (x, g.size()) inv[vid[x]] = x;
        built = true;
    }
    int lca(int x, int y) const {
        assert(built);
        while (true) {
            if (vid[x] > vid[y]) swap(x, y);
            if (head[x] == head[y]) return x;
            y = par[head[y]];
        }
    }
    cost_t<edge> dist(int x, int y) const {
        assert(built);
        return dep[x] + dep[y] - 2*dep[lca(x, y)];
    }
    int eid(int x, int y) const {
        assert(built);
        if (x == par[y]) return vid[y];
        if (y == par[x]) return vid[x];
        assert(false);
        return -1;
    }
    int in(int x) const { assert(built); return vid[x]; }
    int out(int x) const { assert(built); return vid[x] + sz[x]; }
    pair<int, int> subtree(int x) const { return { in(x), out(x) }; }
    int move_to(int x, int y) { 

        assert(built);
        assert(x != y);
        if (not (in(x) < in(y) and out(y) <= out(x))) return par[x];
        while (true) {
            if (head[x] == head[y]) return dest(g[x][0]);
            y = head[y];
            if (x == par[y]) return y;
            y = par[y];
        }
    }
    vector<pair<int, int>> path(int x, int y, bool with_lca) const {
        assert(built);
        static vector<pair<int, int>> ret;
        ret.clear();
        while (true) {
            if (vid[x] > vid[y]) swap(x, y);
            if (head[x] == head[y]) {
                ret.emplace_back(vid[x] + (with_lca ? 0 : 1), vid[y]+1);
                return ret;
            } else {
                ret.emplace_back(vid[head[y]], vid[y]+1);
                y = par[head[y]];
            }
        }
    }
    auto vertices(int x, int y) const { return path(x, y, true); }
    auto edges(int x, int y) const { return path(x, y, false); }

    void dfs1(int x) {
        for (auto &e : g[x]) {
            if (dest(e) == par[x]) {
                swap(e, g[x].back());
                g[x].pop_back();
                break;
            }
        }
        for (auto &e : g[x]) {
            const int y = dest(e);
            par[y] = x;
            dep[y] = dep[x] + cost(e);
            dfs1(y);
            sz[x] += sz[y];
            if (sz[y] > sz[dest(g[x][0])]) swap(e, g[x][0]);
        }
    }
    void dfs2(int x, int &id) {
        vid[x] = id++;
        for (auto const& e : g[x]) {
            const int y = dest(e);
            head[y] = (y == dest(g[x][0]) ? head[x] : y);
            dfs2(y, id);
        }
    }
};




template <class Handler> struct LazySegtree : Handler {
    using Value  = typename Handler::Value;
    using Action = typename Handler::Action;
    using Handler::unit_value;  

    using Handler::unit_action; 

    using Handler::merge;       

    using Handler::compose;     

    using Handler::act;         


    vector<Value> v;
    vector<Action> a;
    int n, lg;

    LazySegtree() {}
    template <class... T> LazySegtree(T&&... x) { init(forward<T>(x)...); }

    template <class F, class = decltype(declval<F>()(0))>
    void init(int n, F gen)  {
        assert(n >= 0);
        this->n = n;
        this->lg = (n == 0 ? 0 : __lg(2*n-1));
        v.resize(2*n);
        a.assign(n, unit_action());
        for (int i = 0; i < n; i++) v[n+i] = gen(i);
        for (int i = n-1; i >= 1; i--) v[i] = merge(v[i<<1], v[i<<1|1]);
    }
    void init(int n) { init(n, [&](int) { return unit_value(); }); }
    void init(int n, Value const& x) { init(n, [&](int) { return x; }); }
    void init(vector<Value> const& v) { init(v.size(), [&](int i) { return v[i]; }); }
    int size() const { return n; }

    void act_at(Action const& x, int i) {
        if (i < n) a[i] = compose(x, a[i]);
        v[i] = act(x, v[i]);
    }
    void flush(int k) {
        if (n <= k || a[k] == unit_action()) return;
        act_at(a[k], k<<1);
        act_at(a[k], k<<1|1);
        a[k] = unit_action();
    }
    void flush(int l, int r) {
        for (int p = lg; p; --p) flush(l >> p), flush((r - 1) >> p);
    }
    Value get(int l, int r) {
        assert(0 <= l); assert(l <= r); assert(r <= n);
        l += n, r += n;
        flush(l, r);
        Value x = unit_value(), y = unit_value();
        for ( ; l < r; l >>= 1, r >>= 1) {
            if (l & 1) x = merge(x, v[l++]);
            if (r & 1) y = merge(v[--r], y);
        }
        return merge(x, y);
    }
    void build(int i) {
        i >>= __builtin_ctz(i);
        while (i >>= 1) v[i] = merge(v[i<<1], v[i<<1|1]);
    }
    void apply(int l, int r, Action const& x) {
        assert(0 <= l); assert(l <= r); assert(r <= n);
        l += n, r += n;
        flush(l, r);
        for (int a = l, b = r; a < b; a >>= 1, b >>= 1) {
            if (a & 1) act_at(x, a++);
            if (b & 1) act_at(x, --b);
        }
        build(l); build(r);
    }
    Value operator[](int i) const { return get(i); }
    Value get(int i) const {
        assert(0 <= i); assert(i < n);
        Value x = v[i += n];
        while (i >>= 1) x = act(a[i], x);
        return x;
    }
    void set(int i, Value const& x) {
        assert(0 <= i); assert(i < n);
        i += n;
        for (int p = lg; p; --p) flush(i >> p);
        v[i] = x;
        while (i >>= 1) v[i] = merge(v[i<<1], v[i<<1|1]);
    }
    template <class F> int max_right(int l, F f) {
        assert(0 <= l); assert(l <= size());
        assert(f(unit_value()));
        l += n;
        const int r = size() << 1;
        for (int p = lg; p; p--) flush(l >> p);
        Value x = unit_value();
        while (true) {
            if (l == r) return size();
            int k = __builtin_ctz(l | 1 << __lg(r - l));
            auto y = merge(x, v[l >> k]);
            if (not f(y)) { l >>= k; break; }
            x = y, l += 1 << k;
        }
        while (l < size()) {
            flush(l);
            auto y = merge(x, v[l <<= 1]);
            if (f(y)) x = y, l++;
        }
        return l - size();
    }
    template <class F> int min_left(int r, F f) {
        assert(0 <= r); assert(r <= size());
        assert(f(unit_value()));
        r += n;
        const int l = size();
        for (int p = lg; p; p--) flush((r - 1) >> p);
        Value x = unit_value();
        while (true) {
            if (l == r) return 0;
            int k = __builtin_ctz(r | 1 << __lg(r - l));
            auto y = merge(v[(r >> k) - 1], x);
            if (not f(y)) { r >>= k; --r; break; }
            x = y, r -= 1 << k;
        }
        while (r < size()) {
            flush(r);
            r = r << 1 | 1;
            auto y = merge(v[r], x);
            if (f(y)) x = y, r--;
        }
        return r + 1 - size();
    }
    vector<Value> dat() const {
        vector<Value> ret(size());
        for (int i = 0; i < size(); i++) ret[i] = get(i);
        return ret;
    }
};
template <class _Value, class _Action> struct Handler {
    using Value = _Value;
    using Action = _Action;
    constexpr static Value unit_value() { return {}; }
    constexpr static Action unit_action() { return {}; }
    constexpr static Value merge(Value const& x, Value const& y) { return x * y; }
    constexpr static Action compose(Action const& x, Action const& y) { return x * y; }
    constexpr static Value act(Action const& x, Value const& y) { return x(y); }
};



struct MinAdd {
    using Value = int;
    using Action = int;
    constexpr static Value unit_value() { return INF; }
    constexpr static Action unit_action() { return 0; }
    constexpr static Value merge(Value const& x, Value const& y) {
        return min(x, y);
    }
    constexpr static Action compose(Action const& x, Action const& y) {
        return x + y;
    }
    constexpr static Value act(Action const& x, Value const& y) {
        return x + y;
    }
};

int32_t main() {
    int n; cin >> n;
    HLD<int> g(n);
    rep (i, n-1) {
        int x, y; cin >> x >> y; --x, --y;
        g.add_edge(x, y);
    }
    g.build();
    dump(g.vid);
    dump(g.sz);
    int m; cin >> m;
    vector<int> a(m), b(m), lca(m), ach(m, -1), bch(m, -1);
    rep (i, m) cin >> a[i] >> b[i], --a[i], --b[i];
    rep (i, m) {
        lca[i] = g.lca(a[i], b[i]);
        if (a[i] != lca[i]) ach[i] = g.move_to(lca[i], a[i]);
        if (b[i] != lca[i]) bch[i] = g.move_to(lca[i], b[i]);
        dump(i, a[i], b[i], lca[i], ach[i], bch[i]);
    }

    int ans = 0;
    vector<int> cnt0(n);
    vector<map<int, int>> cnt1(n);
    vector<map<pair<int, int>, int>> cnt2(n);
    rep (i, m) {
        int val = 0;
        val += cnt0[lca[i]];
        if (ach[i] >= 0) val -= cnt1[lca[i]][ach[i]];
        if (bch[i] >= 0) val -= cnt1[lca[i]][bch[i]];
        if (ach[i] >= 0 and bch[i] >= 0) {
            val += cnt2[lca[i]][minmax(ach[i], bch[i])];
        }
        dump(i, val);
        ans -= val;

        cnt0[lca[i]]++;
        if (ach[i] >= 0) cnt1[lca[i]][ach[i]]++;
        if (bch[i] >= 0) cnt1[lca[i]][bch[i]]++;
        if (ach[i] >= 0 and bch[i] >= 0) {
            cnt2[lca[i]][minmax(ach[i], bch[i])]++;
        }
    }

    LazySegtree<MinAdd> eseg(n, 0), vseg(n, 0);
    rep (i, m) {
        for (auto [l, r] : g.vertices(a[i], b[i])) {
            vseg.apply(l, r, +1);
        }
        for (auto [l, r] : g.edges(a[i], b[i])) {
            eseg.apply(l, r, +1);
        }
    }

    rep (i, m) {
        int val = 0;
        val += vseg[g.vid[lca[i]]];
        if (ach[i] >= 0) val -= eseg[g.eid(ach[i], lca[i])];
        if (bch[i] >= 0) val -= eseg[g.eid(bch[i], lca[i])];
        if (ach[i] >= 0 and bch[i] >= 0) {
            val += cnt2[lca[i]][minmax(ach[i], bch[i])];
        }
        if (ach[i] < 0 and bch[i] < 0) {
            val--;
        }
        dump(i, val);
        ans += val;
    }

    cout << ans << "\n";



}
