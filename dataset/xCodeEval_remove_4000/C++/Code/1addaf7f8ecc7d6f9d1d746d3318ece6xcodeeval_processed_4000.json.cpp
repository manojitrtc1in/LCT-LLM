


using namespace std;
using ll = long long;
using ld = long double;
using i32 = int32_t;
using i64 = int64_t;















auto constexpr INF32 = numeric_limits<int32_t>::max()/2-1;
auto constexpr INF64 = numeric_limits<int64_t>::max()/2-1;
auto constexpr INF   = numeric_limits<int>::max()/2-1;










template <class T> using pque_max = priority_queue<T>;
template <class T> using pque_min = priority_queue<T, vector<T>, greater<T> >;
template <class T, class = typename T::iterator, class = typename enable_if<!is_same<T, string>::value>::type>
ostream& operator<<(ostream& os, T const& v) { bool f = true; for (auto const& x : v) os << (f ? "" : " ") << x, f = false; return os; }
template <class T, class = typename T::iterator, class = typename enable_if<!is_same<T, string>::value>::type>
istream& operator>>(istream& is, T &v) { for (auto& x : v) is >> x; return is; }
template <class T, class S> istream& operator>>(istream& is, pair<T,S>& p) { return is >> p.first >> p.second; }
struct IOSetup { IOSetup() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); } } id2;
template <class F> struct FixPoint : private F {
    constexpr FixPoint(F&& f) : F(forward<F>(f)) {}
    template <class... T> constexpr auto operator()(T&&... x) const { return F::operator()(*this, forward<T>(x)...); }
};
struct MakeFixPoint {
    template <class F> constexpr auto operator|(F&& f) const { return FixPoint<F>(forward<F>(f)); }
};


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
template <class It> constexpr auto sumof(It b, It e) { return accumulate(b,e,typename iterator_traits<It>::value_type{}); }
template <class T> int sz(T const& x) { return x.size(); }
template <class C, class T> int lbd(C const& v, T const& x) {
    return lower_bound(v.begin(), v.end(), x)-v.begin();
}
template <class C, class T> int ubd(C const& v, T const& x) {
    return upper_bound(v.begin(), v.end(), x)-v.begin();
}
template <class C, class F> int ppt(C const& v, F f) {
    return partition_point(v.begin(), v.end(), f)-v.begin();
}




struct UnionFind {
    int n, sz; 

    vector<int> par;

    UnionFind(int n = 0) : n(n), sz(n), par(n,-1) { }
    int root(int x) {
        assert(0 <= x); assert(x < n);
        return par[x] < 0 ? x : par[x] = root(par[x]);
    }
    bool unite(int x, int y) {
        x = root(x), y = root(y);
        if (x == y) return false;
        sz--;
        if (par[x] < par[y]) swap(x,y);
        par[y] += par[x];
        par[x] = y;
        return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -par[root(x)]; }
    int size() const { return sz; }
    struct groups_t {
        vector<vector<int> > grp;
        vector<pair<int,int> > id;
    };
    groups_t groups() {
        vector<vector<int> > g(n);
        rep (i,n) if (par[i] < 0) g[i].reserve(-par[i]);
        rep (i,n) g[root(i)].push_back(i);
        vector<vector<int> > grp; grp.reserve(size());
        rep (i,n) if (g[i].size()) grp.emplace_back(move(g[i]));
        vector<pair<int,int> > id(n);
        rep (i,grp.size()) rep (j,grp[i].size()) {
            id[grp[i][j]] = make_pair(i,j);
        }
        return { grp, id };
    }
};




struct HLD {
    vector<vector<int32_t>> g;
    vector<int32_t> vid,inv,head,sz,dep,par;
    bool built = false;
    HLD(int n) : g(n),vid(n),inv(n),head(n),sz(n,1),dep(n,0),par(n,-1) {}
    vector<int32_t> const& operator[](int i) const {
        assert(built);
        assert(0 <= i); assert(i < (int)g.size());
        return g[i];
    }
    void add_edge(int x, int y) {
        g[x].push_back(y);
        g[y].push_back(x);
        built = false;
    }
    void build(int root = 0) {
        dfs1(root);
        head[root] = root;
        int id = 0;
        dfs2(root,id);
        rep (x,g.size()) inv[vid[x]] = x;
        built = true;
    }
    int lca(int x, int y) const {
        assert(built);
        while (1) {
            if (vid[x] > vid[y]) swap(x,y);
            if (head[x] == head[y]) return x;
            y = par[head[y]];
        }
    }
    int dist(int x, int y) const {
        assert(built);
        return dep[x] + dep[y] - 2*dep[lca(x,y)];
    }
    int edge_id(int x, int y) const {
        assert(built);
        if (x == par[y]) return vid[y];
        if (y == par[x]) return vid[x];
        return -1;
    }
    vector<pair<int,int>> path(int x, int y, bool id0) const {
        assert(built);
        vector<pair<int,int>> ret;
        while (1) {
            if (vid[x] > vid[y]) swap(x,y);
            if (head[x] == head[y]) {
                ret.emplace_back(vid[x] + (id0 ? 0 : 1), vid[y]+1);
                return ret;
            } else {
                ret.emplace_back(vid[head[y]], vid[y]+1);
                y = par[head[y]];
            }
        }
    }
    vector<pair<int,int>> vertices(int x, int y) const {
        return path(x,y,true);
    }
    vector<pair<int,int>> edges(int x, int y) const {
        return path(x,y,false);
    }

    void dfs1(int x) {
        for (auto &y : g[x]) {
            if (y == par[x]) {
                swap(y, g[x].back());
                g[x].pop_back();
                break;
            }
        }
        for (auto &y : g[x]) {
            par[y] = x;
            dep[y] = dep[x] + 1;
            dfs1(y);
            sz[x] += sz[y];
            if (sz[y] > sz[g[x][0]]) swap(y, g[x][0]);
        }
    }
    void dfs2(int x, int &id) {
        vid[x] = id++;
        for (auto y : g[x]) {
            head[y] = (y == g[x][0] ? head[x] : y);
            dfs2(y,id);
        }
    }
};




template <class Handler>
struct Segtree : Handler {
    using Value = typename Handler::Value;
    using Handler::unit; 

    using Handler::merge; 


    vector<Value> v; 

    int cap; 

    int n; 


    Segtree() {}
    template <class... T> Segtree(T&&... x) { init(forward<T>(x)...); }

    template <class F, class = decltype(declval<F>()(0))>
    void init(int n, F gen)  {
        assert(n >= 0); this->n = n;
        cap = n; 

        v.resize(2*cap, unit());
        for (int i = 0; i < n; i++) v[cap+i] = gen(i);
        for (int i = cap-1; i >= 1; i--) v[i] = merge(v[2*i],v[2*i+1]);
    }
    void init(int n) { init(n, [&](int) { return unit(); }); }
    void init(int n, Value const& x) { init(n, [&](int) { return x; }); }
    void init(vector<Value> const& v) { init(v.size(), [&](int i) { return v[i]; }); }
    int size() const { return n; }

    void set(int i, Value const& x) {
        assert(0 <= i); assert(i < size());
        i += cap; v[i] = x;
        while (i > 1) i >>= 1, v[i] = merge(v[2*i],v[2*i+1]);
    }
    Value operator[](int i) const { return get(i); }
    Value get(int i) const {
        assert(0 <= i); assert(i < size());
        return v[cap + i];
    }
    

    Value get(int l, int r) const {
        assert(0 <= l); assert(l <= r); assert(r <= size());
        Value x = unit(), y = unit();
        for (l += cap, r += cap; l < r; l >>= 1, r >>= 1) {
            if (l&1) x = merge(x, v[l++]);
            if (r&1) y = merge(v[--r], y);
        }
        return merge(x,y);
    }
    vector<Value> dat() const {
        vector<Value> ret(size());
        for (int i = 0; i < size(); i++) ret[i] = get(i);
        return ret;
    }
};


struct RangeMax {
    using Value = int;
    constexpr static Value unit() { return -INF; }
    constexpr static Value merge(Value x, Value y) { return max(x,y); }
};


template <class Handler>
struct id1 : Handler {
    static int32_t btmbit(int64_t x) { return x ? __builtin_ctzll(x) : -1; }



    using Value = typename Handler::Value;
    using Lazy = typename Handler::Lazy;
    using Handler::unit_value; 

    using Handler::unit_action; 

    using Handler::merge; 

    using Handler::act; 


    vector<Value> v;
    vector<Lazy> lz;
    int n;
    mutable Lazy tmp;

    id1() {}
    template <class... T> id1(T&&... x) { init(forward<T>(x)...); }

    template <class F, class = decltype(declval<F>()(0))>
    void init(int n, F gen)  {
        assert(n >= 0); this->n = n;
        v.resize(2*n); lz.assign(n, unit_action());
        for (int i = 0; i < n; i++) v[n+i] = gen(i);
        for (int i = n-1; i >= 1; i--) v[i] = merge(v[2*i],v[2*i+1]);
    }
    void init(int n) { init(n, [&](int) { return unit_value(); }); }
    void init(int n, Value const& x) { init(n, [&](int) { return x; }); }
    void init(vector<Value> const& v) { init(v.size(), [&](int i) { return v[i]; }); }
    int size() const { return n; }


    void act(Lazy const& x, int i) { act(x, (i < n ? lz[i] : tmp), v[i]); }
    void flush(int k) {
        if (n <= k || lz[k] == unit_action()) return;
        act(lz[k], 2*k);
        act(lz[k], 2*k+1);
        lz[k] = unit_action();
    }
    void flush(int l, int r) {
        for (int p = __lg(l += n), q = __lg(r += n-1); q; --p,--q) {
            flush(l >> p); flush(r >> q);
        }
    }
    void build(int i) {
        i += n; i >>= btmbit(i);
        while (i >>= 1) v[i] = merge(v[2*i],v[2*i+1]);
    }
    Value get(int l, int r) {
        assert(0 <= l); assert(l <= r); assert(r <= n);
        flush(l,r);
        Value x = unit_value(), y = unit_value();
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) x = merge(x,v[l++]);
            if (r&1) y = merge(v[--r],y);
        }
        return merge(x,y);
    }
    void apply(int l, int r, Lazy const& x) {
        assert(0 <= l); assert(l <= r); assert(r <= n);
        flush(l,r);
        for (int a = l+n, b = r+n; a < b; a >>= 1, b >>= 1) {
            if (a&1) act(x, a++);
            if (b&1) act(x, --b);
        }
        build(l); build(r);
    }
    Value operator[](int i) const { return get(i); }
    Value get(int i) const {
        assert(0 <= i); assert(i < n);
        Value x = v[i += n];
        while (i >>= 1) act(lz[i], tmp, x);
        return x;
    }
    void set(int i, Value const& x) {
        assert(0 <= i); assert(i < n);
        for (int p = __lg(i += n); p; --p) flush(i >> p);
        for (v[i] = x; i >>= 1; ) v[i] = merge(v[2*i],v[2*i+1]);
    }
    vector<Value> dat() const {
        vector<Value> ret(size());
        for (int i = 0; i < size(); i++) ret[i] = get(i);
        return ret;
    }
};


struct RangeMinChmin {
    using Value = int;
    using Lazy = int;
    constexpr static Value unit_value() { return INF; }
    constexpr static Lazy unit_action() { return INF; }
    constexpr static Value merge(Value x, Value y) { return min(x,y); }
    static void act(Lazy x, Lazy &y, Value &z) {
        y = min(x,y), z = min(x,z);
    }
};

int32_t main() {
    int n,m; cin >> n >> m;
    vector<int> a(m),b(m),c(m);
    rep (i,m) cin >> a[i] >> b[i] >> c[i], --a[i],--b[i];

    vector<int> idx(m);
    iota(all(idx),0);
    sort(all(idx), [&](int i, int j) { return c[i] < c[j]; });

    vector<int> used(m);
    UnionFind uf(n);
    HLD hld(n);
    for (int i : idx) {
        if (uf.unite(a[i],b[i])) {
            used[i] = 1;
            hld.add_edge(a[i],b[i]);
        }
    }
    hld.build();
    dump(hld.g);

    Segtree<RangeMax> seg_max(n);
    id1<RangeMinChmin> id3(n);
    rep (i,m) if (used[i]) {
        int id = hld.edge_id(a[i],b[i]);
        seg_max.set(id, c[i]);
    }

    vector<int> ans(m,-1);
    rep (i,m) if (not used[i]) {
        int ma = -INF;
        for (auto [l,r] : hld.edges(a[i],b[i])) {
            chmax(ma, seg_max.get(l,r));
            id3.apply(l,r,c[i]);
        }
        ans[i] = ma-1;
    }
    rep (i,m) if (used[i]) {
        int id = hld.edge_id(a[i],b[i]);
        int val = id3[id];
        if (val < INF) ans[i] = val-1;
    }

    cout << ans << endl;


}
