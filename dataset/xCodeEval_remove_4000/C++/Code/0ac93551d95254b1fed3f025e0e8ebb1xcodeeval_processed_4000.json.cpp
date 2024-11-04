


using namespace std;
using ll = long long;
using ld = long double;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;













template <class Int> auto constexpr inf_ = numeric_limits<Int>::max()/2-1;
auto constexpr INF32 = inf_<int32_t>;
auto constexpr INF64 = inf_<int64_t>;
auto constexpr INF   = inf_<int>;







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
struct IOSetup { IOSetup() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); } } id2;
template <class F> struct FixPoint : private F {
    constexpr FixPoint(F&& f) : F(forward<F>(f)) {}
    template <class... T> constexpr auto operator()(T&&... x) const { return F::operator()(*this, forward<T>(x)...); }
};
struct MakeFixPoint { template <class F> constexpr auto operator|(F&& f) const { return FixPoint<F>(forward<F>(f)); } };


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
constexpr ll id3(ll x, ll y) { assert(y != 0); return x/y + ((x^y) > 0 and x%y); }
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





struct UnionFind {
    int n, sz; 

    vector<int32_t> par;

    UnionFind(int n = 0) : n(n), sz(n), par(n, -1) { }
    void clear() {
        rep (i, n) par[i] = -1;
        sz = n;
    }
    int root(int x) {
        assert(0 <= x); assert(x < n);
        return par[x] < 0 ? x : par[x] = root(par[x]);
    }
    bool unite(int x, int y) {
        x = root(x), y = root(y);
        if (x == y) return false;
        sz--;
        if (par[x] < par[y]) swap(x, y);
        par[y] += par[x];
        par[x] = y;
        return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -par[root(x)]; }
    int size() const { return sz; }
    vector<vector<int32_t>> groups() {
        vector<vector<int32_t>> g(n);
        rep (i, n) if (par[i] < 0) g[i].reserve(-par[i]);
        rep (i, n) g[root(i)].push_back(i);
        vector<vector<int32_t>> grp; grp.reserve(size());
        rep (i, n) if (g[i].size()) grp.emplace_back(move(g[i]));
        return grp;
    }
};








constexpr int dest(int v) { return v; }
template <class E, class = decltype(declval<E>().to)>
constexpr int dest(E const& e) { return e.to; }
constexpr int cost(int) { return 1; }
template <class E, class = decltype(declval<E>().cost)>
constexpr auto cost(E const& e) { return e.cost; }
template <class E> using cost_t = decltype(cost(declval<E>()));


namespace RMQ {


template <class Handler>
struct DST : Handler {
    using Value = typename Handler::Value;
    using Handler::unit; 

    using Handler::merge; 

    static constexpr int bsr(int32_t x) { return x ? 31-__builtin_clz(x) : -1; }

    vector<vector<Value>> v;
    DST() {}
    template <class... T> DST(T&&... x) { build(forward<T>(x)...); }
    void build(int n) { build(n, unit()); }
    void build(int n, Value const& x) { build(n, [&](int) { return x; }); }
    void build(vector<Value> const& v) { build(v.size(), [&](int i) { return v[i]; }); }
    template <class F, class = decltype(declval<F>()(0))>
    void build(int n, F gen)  {
        assert(n >= 0);
        v.resize(1);
        v[0].resize(n, unit());
        for (int i = 0; i < n; i++) v[0][i] = gen(i);
        if (n <= 1) return;
        const int lg = __lg(2*n-1);
        v.resize(lg, vector<Value>(n, unit()));
        for (int h = 1; h < lg; ++h) {
            const int w = 1<<h;
            for (int b = w; b < n; b += (w<<1)) {
                Value x = unit();
                for (int j = b-1; j >= b-w; --j) {
                    v[h][j] = x = merge(v[0][j], x);
                }
                x = unit();
                for (int j = b; j < min(n, b+w); ++j) {
                    v[h][j] = x = merge(x, v[0][j]);
                }
            }
        }
    }
    int size() const { return v.empty() ? 0 : v[0].size(); }
    Value get(int l, int r) const {
        assert(0 <= l); assert(l <= r); assert(r <= size());
        if (l == r) return unit();
        --r;
        if (l == r) return v[0][l];
        const int h = bsr(l^r);
        return merge(v[h][l], v[h][r]);
    }
    Value operator[](int idx) const {
        assert(0 <= idx); assert(idx < size());
        return v[0][idx];
    }
};


struct Min {
    using Value = pair<int32_t, int32_t>;
    static constexpr auto inf = numeric_limits<int32_t>::max();
    constexpr static Value unit() { return { inf, inf }; }
    constexpr static Value merge(Value const& x, Value const& y) { return min(x, y); }
};
using RMQ = DST<Min>;
}

template <class E, class RMQ = RMQ::RMQ> struct LCA {
    vector<vector<E>> const* g;
    int32_t n, root;
    vector<int32_t> id;
    vector<cost_t<E>> d;
    RMQ rmq;
    LCA() {}
    LCA(vector<vector<E>> const* g, int root)
        : g(g), n(g->size()), root(root), id(n), d(n) {
        vector<pair<int32_t, int32_t>> a;
        a.reserve(n-1);
        auto dfs = [&](auto dfs, int x, int p, int d0, cost_t<E> d1) -> void {
            id[x] = a.size();
            d[x] = d1;
            for (auto const& e : (*g)[x]) {
                if (dest(e) == p) continue;
                a.emplace_back(d0, x);
                dfs(dfs, dest(e), x, d0 + 1, d1 + cost(e));
            }
        };
        dfs(dfs, root, -1, 0, 0);
        rmq = RMQ(a);
    }
    cost_t<E> dep(int a) const { return d[a]; }
    int operator()(int a, int b) const { return lca(a, b); }
    int lca(int a, int b) const {
        if (a == b) return a;
        if (id[a] > id[b]) swap(a, b);
        return rmq.get(id[a], id[b]).second;
    }
    cost_t<E> dist(int a, int b) const { return d[a] + d[b] - 2*d[lca(a, b)]; }
};


template <class E>
auto id0(vector<vector<E>> const& g, int root = 0) {
    return LCA<E, RMQ::RMQ>(&g, root);
}






template <class Handler> struct id1 : Handler {
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

    id1() {}
    template <class... T> id1(T&&... x) { init(forward<T>(x)...); }

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



LCA<int> _lca;
int lca(int x, int y) {
    if (x == -1) return y;
    if (y == -1) return x;
    return _lca(x, y);
}

struct M {
    using Value = pair<int, int>; 

    using Action = int; 

    constexpr static auto unwrap(Value const& x) { return x; }
    constexpr static Value unit_value() { return { -1, -1 }; }
    constexpr static Action unit_action() { return -1; }
    static Value merge(Value const& x, Value const& y) {
        return { lca(x.fst, y.fst), lca(x.snd, y.snd) };
    }
    constexpr static Action compose(Action const& x, Action const& y) {
        return x == unit_action() ? y : x;
    }
    constexpr static Value act(Action const& x, Value const& y) {
        if (x == 0) {
            return { -1, y.snd };
        } else if (x == 1) {
            return { y.snd, y.snd };
        } else {
            return y;
        }
    }
};

int32_t main() {
    int n, q; cin >> n >> q;
    vector<tuple<int, int, int>> es;
    rep (_, n-1) {
        int x, y, w; cin >> x >> y >> w; x--, y--;
        es.eb(w, x, y);
    }
    sort(all(es));

    UnionFind uf(n);
    vector<int> id(n), w(2*n);
    iota(all(id), 0);
    vector<vector<int>> g(n);
    int root = -1;
    for (auto [_w, x, y] : es) {
        x = uf.root(x);
        y = uf.root(y);
        int id_z = g.size();
        g.pb({id[x], id[y]});
        g[id[x]].eb(id_z);
        g[id[y]].eb(id_z);
        uf.unite(x, y);
        int z = uf.root(x);
        id[z] = id_z;
        w[id[z]] = _w;
        root = id[z];
    }
    _lca = id0(g, root);
    dump(as_mat(g));

    id1<M> seg(n, [&](int i) { return pair(-1, i); });
    while (q--) {
        int t; cin >> t;
        if (t == 1 or t == 2) {
            int l, r; cin >> l >> r; --l;
            seg.apply(l, r, t == 1 ? 1 : 0);
        } else if (t == 3) {
            int x; cin >> x; --x;
            dump(seg.dat());
            int y = seg.get_all().fst;
            dump(y);
            y = lca(x, y);
            dump(y);
            if (y >= n) {
                cout << w[y] << '\n';
            } else {
                cout << -1 << '\n';
            }
        } else {
            assert(false);
        }
    }



}
