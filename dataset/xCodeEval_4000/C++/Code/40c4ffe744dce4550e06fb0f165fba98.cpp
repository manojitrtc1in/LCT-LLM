

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
#define pb push_back
#define eb emplace_back
#define fst first
#define snd second
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
template <class T, class U> constexpr bool chmin(T& x, U const& y) { if (x > (T)y) { x = (T)y; return true; } return false; }
template <class T, class U> constexpr bool chmax(T& x, U const& y) { if (x < (T)y) { x = (T)y; return true; } return false; }
template <class It> constexpr auto sumof(It b, It e) { return accumulate(b, e, typename iterator_traits<It>::value_type{}); }
template <class T> int sz(T const& x) { return x.size(); }
template <class C, class T> int lbd(C const& v, T const& x) { return lower_bound(begin(v), end(v), x)-begin(v); }
template <class C, class T> int ubd(C const& v, T const& x) { return upper_bound(begin(v), end(v), x)-begin(v); }
constexpr ll mod(ll x, ll m) { assert(m > 0); return (x %= m) < 0 ? x+m : x; }
constexpr ll div_floor(ll x, ll y) { assert(y != 0); return x/y - ((x^y) < 0 and x%y); }
constexpr ll div_ceil(ll x, ll y) { assert(y != 0); return x/y + ((x^y) > 0 and x%y); }
constexpr int dx[] = { 1, 0, -1, 0, 1, -1, -1, 1 };
constexpr int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
constexpr int popcnt(ll x) { return __builtin_popcountll(x); }
mt19937_64 seed_{random_device{}()};
template <class Int> Int rand(Int a, Int b) { return uniform_int_distribution<Int>(a, b)(seed_); }
i64 irand(i64 a, i64 b) { return rand<i64>(a, b); } 

u64 urand(u64 a, u64 b) { return rand<u64>(a, b); } 

template <class It> void shuffle(It l, It r) { shuffle(l, r, seed_); }
template <class V> V &operator--(V &v) { for (auto &x : v) --x; return v; }
template <class V> V &operator++(V &v) { for (auto &x : v) ++x; return v; }
bool next_product(vector<int> &v, int m) {
    repR (i, v.size()) if (++v[i] < m) return true; else v[i] = 0;
    return false;
}
bool next_product(vector<int> &v, vector<int> const& s) {
    repR (i, v.size()) if (++v[i] < s[i]) return true; else v[i] = 0;
    return false;
}
template <class vec> int sort_unique(vec &v) {
    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));
    return v.size();
}
template <class V> auto prefix_sum(V const& a) {
    vector<typename V::value_type> s;
    s.reserve(a.size() + 1);
    s.push_back(0);
    for (auto const& x : a) s.emplace_back(s.back() + x);
    return s;
}
template <class V> auto suffix_sum(V const& a) {
    vector<typename V::value_type> s(a.size() + 1);
    int pos = a.size();
    for (auto it = a.rbegin(); it != a.rend(); ++it, --pos) {
        s[pos-1] = *it + s[pos];
    }
    return s;
}




#ifndef EDGE_INFO
#define EDGE_INFO
constexpr int dest(int v) { return v; }
template <class E, class = decltype(declval<E>().to)>
constexpr int dest(E const& e) { return e.to; }
constexpr int cost(...) { return 1; }
template <class E, class = decltype(declval<E>().cost)>
constexpr auto cost(E const& e) { return e.cost; }
template <class E> using cost_t = decltype(cost(declval<E>()));
#endif
template <class edge> struct HLD {
    int n, m = 0, root;
    vector<vector<edge>> g;
    vector<int32_t> id, inv, head, sz, par;
    vector<cost_t<edge>> dep;
    bool built = false;
    HLD() : n(0), root(-1) {};
    HLD(int n, int root = 0) : n(n), root(root), g(n), id(n), inv(n), head(n), sz(n), par(n), dep(n) {
        if (n == 1) build();
    }
    int size() const { return n; }
    vector<edge> const& operator[](int i) const {
        assert(built);
        assert(0 <= i); assert(i < (int)g.size());
        return g[i];
    }
    template <class... Args> void add_edge(int x, int y, Args&&... args) {
        g[x].push_back({y, args...});
        g[y].push_back({x, args...});
        if (++m == n-1) build();
    }
    void build() {
        assert(m == n-1);
        fill(sz.begin(), sz.end(), 1);
        dep[root] = 0, par[root] = -1, head[root] = root;
        int time = 0;
        dfs1(root), dfs2(root, time);
        rep (x, g.size()) inv[id[x]] = x;
        built = true;
    }
    int lca(int x, int y) const {
        assert(built);
        while (true) {
            if (id[x] > id[y]) swap(x, y);
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
        if (x == par[y]) return id[y];
        if (y == par[x]) return id[x];
        assert(false);
        return -1;
    }
    int vid(int x) const { assert(built); return id[x]; }
    int in(int x) const { assert(built); return id[x]; }
    int out(int x) const { assert(built); return id[x] + sz[x]; }
    pair<int, int> subtree(int x) const { return { in(x), out(x) }; }
    pair<int, int> split_size(int x, int y) const {
        assert(built);
        if (x == par[y]) return { n-sz[y], sz[y] };
        if (y == par[x]) return { sz[x], n-sz[y] };
        assert(false);
        return { -1, -1 };
    }
    int meet(int x, int y, int z) const {
        return lca(x, y) ^ lca(y, z) ^ lca(z, x);
    }
    bool is_ancestor(int x, int y) const { 

        return in(x) < in(y) and out(y) <= out(x);
    }
    int step(int x, int y) const { 

        assert(built);
        assert(x != y);
        if (not is_ancestor(x, y)) return par[x];
        while (true) {
            if (head[x] == head[y]) return dest(g[x][0]);
            y = head[y];
            if (x == par[y]) return y;
            y = par[y];
        }
    }
    int climb(int x, cost_t<edge> d) const {
        assert(built);
        assert(0 <= d); assert(d <= dep[x]);
        auto const dep_y = dep[x] - d;
        while (true) {
            x = head[x];
            if (dep[x] <= dep_y) return inv[id[x] + dep_y - dep[x]];
            x = par[x];
        }
    }
    

    int jump(int x, int y, cost_t<edge> d) const {
        assert(built);
        auto const z = lca(x, y);
        auto const dist = dep[x] + dep[y] - 2*dep[z];
        return d <= dep[x] - dep[z] ? climb(x, d) : climb(y, dist-d);
    }
    vector<pair<int, int>> path(int x, int y, bool with_lca) const {
        assert(built);
        static vector<pair<int, int>> ret;
        ret.clear();
        while (true) {
            if (id[x] > id[y]) swap(x, y);
            if (head[x] == head[y]) {
                ret.emplace_back(id[x] + (with_lca ? 0 : 1), id[y]+1);
                return ret;
            } else {
                ret.emplace_back(id[head[y]], id[y]+1);
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
    void dfs2(int x, int &time) {
        id[x] = time++;
        for (auto const& e : g[x]) {
            const int y = dest(e);
            head[y] = (y == dest(g[x][0]) ? head[x] : y);
            dfs2(y, time);
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

    using Handler::unwrap;      


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


    void init(int n, Value const& x) { init(n, [&](int) { return x; }); }
    template <class T>
    void init(vector<T> const& v) { init(v.size(), [&](int i) { return Value(v[i]); }); }
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
    auto get(int l, int r) {
        assert(0 <= l); assert(l <= r); assert(r <= n);
        l += n, r += n;
        flush(l, r);
        Value x = unit_value(), y = unit_value();
        for ( ; l < r; l >>= 1, r >>= 1) {
            if (l & 1) x = merge(x, v[l++]);
            if (r & 1) y = merge(v[--r], y);
        }
        return unwrap(merge(x, y));
    }
    auto get_all() { return get(0, size()); }
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
    auto operator[](int i) const { return get(i); }
    auto get(int i) const {
        assert(0 <= i); assert(i < n);
        Value x = v[i += n];
        while (i >>= 1) x = act(a[i], x);
        return unwrap(x);
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
    auto dat() const {
        vector<decltype(unwrap(declval<Value>()))> ret(size());
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
    constexpr static auto unwrap(Value const& x) { return x; }
};





struct M {
    struct Value {
        array<int, 2> cnt = {}, sum = {};
    };
    using Action = int;
    constexpr static auto unwrap(Value const& x) { return x; }
    constexpr static Value unit_value() { return {}; }
    constexpr static Action unit_action() { return 0; }
    constexpr static Value merge(Value const& x, Value const& y) {
        Value z;
        rep (i, 2) {
            z.cnt[i] = x.cnt[i] + y.cnt[i];
            z.sum[i] = x.sum[i] + y.sum[i];
        }
        return z;
    }
    constexpr static Action compose(Action const& x, Action const& y) {
        return x ^ y;
    }
    constexpr static Value act(Action const& x, Value const& y) {
        if (x) {
            Value z = y;
            swap(z.cnt[0], z.cnt[1]);
            swap(z.sum[0], z.sum[1]);
            return z;
        } else {
            return y;
        }
    }
};



int32_t main() {
    int n; cin >> n;
    struct edge { int to, id; };
    HLD<edge> g(n);
    rep (i, n-1) {
        int x, y; cin >> x >> y; --x, --y;
        g.add_edge(x, y, i+1);
    }

    LazySegtree<M> seg(n, M::unit_value());
    rep (x, n) {
        for (auto [y, id] : g[x]) {
            M::Value val;
            val.cnt[0] = 0, val.cnt[1] = 1;
            val.sum[0] = 0, val.sum[1] = id;
            seg.set(g.eid(x, y), val);
        }
    }

    vector<int> active(n);
    int cnt_active = 0;

    auto activate = [&](int x) {
        for (auto [l, r] : g.edges(x, 0)) {
            seg.apply(l, r, 1);
        }
        assert(not active[x]);
        active[x] = 1;
        cnt_active++;
    };

    auto query1 = [&]() -> int {
        if (cnt_active % 2 != 0) return 0;
        auto val = seg.get_all();
        int cnt = val.cnt[0], sum = val.sum[0];
        if (2*cnt == cnt_active) {
            return sum;
        } else {
            return 0;
        }
    };

    activate(0);

    int prev_ans = -1;
    while (true) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x; --x;
            activate(x);
            int ans = query1();
            cout << ans << endl;
            prev_ans = ans;
        } else if (t == 2) {
            assert(prev_ans >= 0);
            if (prev_ans == 0) {
                cout << 0 << endl;
                continue;
            }

            vector<int> ans;
            for (auto val : seg.dat()) {
                int cnt = val.cnt[0], id = val.sum[0];
                if (cnt) ans.eb(id);
            }
            sort(all(ans));
            dump(ans);
            assert(prev_ans == sumof(all(ans)));
            cout << ans.size() << ' ' << ans << endl;
        } else if (t == 3) {
            return 0;
        } else {
            assert(false);
        }
    }

}
