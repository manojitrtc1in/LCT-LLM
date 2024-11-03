












using ld = long double;















    vector<type> name(size);                                                                                                                                   \
    IN(name)

    vector<type> name1(size), name2(size);                                                                                                                     \
    for(int i = 0; i < size; i++) IN(name1[i], name2[i])

    vector<type> name1(size), name2(size), name3(size);                                                                                                        \
    for(int i = 0; i < size; i++) IN(name1[i], name2[i], name3[i])


    vector<vector<type>> name(h, vector<type>(w));                                                                                                             \
    IN(name)


    vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(id4))))







template <class T = ll, class S> T SUM(const S &v) { return accumulate(all(v), T(0)); }




using namespace std;
constexpr pii dx4[4] = {pii{1, 0}, pii{0, 1}, pii{-1, 0}, pii{0, -1}};
constexpr pii dx8[8] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
const string YESNO[2] = {"NO", "YES"};
const string YesNo[2] = {"No", "Yes"};
const string yesno[2] = {"no", "yes"};
void YES(bool t = 1) { cout << YESNO[t] << endl; }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { cout << YesNo[t] << endl; }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { cout << yesno[t] << endl; }
void no(bool t = 1) { yes(!t); }
template <class T> using vc = vector<T>;
template <class T> using vvc = vector<vc<T>>;
template <class T> using vvvc = vector<vvc<T>>;
template <class T> using vvvvc = vector<vvvc<T>>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;


    int id4;                                                                                                                                           \
    IN(id4)

    ll id4;                                                                                                                                            \
    IN(id4)

    string id4;                                                                                                                                        \
    IN(id4)

    char id4;                                                                                                                                          \
    IN(id4)

    double id4;                                                                                                                                        \
    IN(id4)
int scan() { return getchar(); }
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(string &a) { cin >> a; }
template <class T, class S> void scan(pair<T, S> &p) { scan(p.first), scan(p.second); }
template <class T> void scan(vector<T> &);
template <class T> void scan(vector<T> &a) {
    for(auto &i : a) scan(i);
}
template <class T> void scan(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail> void IN(Head &head, Tail &...tail) {
    scan(head);
    IN(tail...);
}

template <class T, class S> inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S> inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }
vi iota(int n) {
    vi a(n);
    iota(all(a), 0);
    return a;
}
template <typename T> vi iota(vector<T> &a, bool greater = false) {
    vi res(a.size());
    iota(all(res), 0);
    sort(all(res), [&](int i, int j) {
        if(greater) return a[i] > a[j];
        return a[i] < a[j];
    });
    return res;
}


template <class T> T ceil(T x, T y) {
    assert(y >= 1);
    return (x > 0 ? (x + y - 1) / y : x / y);
}

template <class T> T floor(T x, T y) {
    assert(y >= 1);
    return (x > 0 ? x / y : (x + y - 1) / y);
}
template <class T> T POW(T x, int n) {
    T res = 1;
    for(; n; n >>= 1, x *= x)
        if(n & 1) res *= x;
    return res;
}
template <class T, class S> T POW(T x, S n, const ll &mod) {
    T res = 1;
    for(; n; n >>= 1, x = x * x % mod)
        if(n & 1) res = res * x % mod;
    return res;
}
vector<pll> factor(ll x) {
    vector<pll> ans;
    for(ll i = 2; i * i <= x; i++)
        if(x % i == 0) {
            ans.push_back({i, 1});
            while((x /= i) % i == 0) ans.back().second++;
        }
    if(x != 1) ans.push_back({x, 1});
    return ans;
}
template <class T> vector<T> divisor(T x) {
    vector<T> ans;
    for(T i = 1; i * i <= x; i++)
        if(x % i == 0) {
            ans.pb(i);
            if(i * i != x) ans.pb(x / i);
        }
    return ans;
}
template <typename T> void zip(vector<T> &x) {
    vector<T> y = x;
    UNIQUE(y);
    for(int i = 0; i < x.size(); ++i) { x[i] = lb(y, x[i]); }
}
template <class S> void fold_in(vector<S> &v) {}
template <typename Head, typename... Tail, class S> void fold_in(vector<S> &v, Head &&a, Tail &&...tail) {
    for(auto e : a) v.emplace_back(e);
    fold_in(v, tail...);
}
template <class S> void renumber(vector<S> &v) {}
template <typename Head, typename... Tail, class S> void renumber(vector<S> &v, Head &&a, Tail &&...tail) {
    for(auto &&e : a) e = lb(v, e);
    renumber(v, tail...);
}
template <class S, class... Args> vector<S> zip(vector<S> &head, Args &&...args) {
    vector<S> v;
    fold_in(v, head, args...);
    sort(all(v)), v.erase(unique(all(v)), v.end());
    renumber(v, head, args...);
    return v;
}



template <class T, class S> bool inc(const T &x, const S &l, const S &r) { return l <= x and x < r; }


template <class T, class S> bool inc(const pair<T, T> &x, const S &lx, const S &ly, const S &rx, const S &ry) { return inc(x.fi, lx, rx) && inc(x.se, ly, ry); }

constexpr ll ten(int n) { return n == 0 ? 1 : ten(n - 1) * 10; }


ll pow2(int i) { return 1LL << i; }
int topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
int topbit(ll t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
int lowbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }
int lowbit(ll a) { return a == 0 ? 64 : __builtin_ctzll(a); }


constexpr ll allbit(int n) { return (1LL << n) - 1; }
int popcount(signed t) { return __builtin_popcount(t); }
int popcount(ll t) { return __builtin_popcountll(t); }
bool id6(int i) { return i && (i & -i) == i; }

ll rnd(ll l, ll r) { 


    static mt19937_64 gen;

    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());

    return uniform_int_distribution<ll>(l, r - 1)(gen);
}
ll rnd(ll n) { return rnd(0, n); }

template <class t> void random_shuffle(vc<t> &a) { rep(i, si(a)) swap(a[i], a[rnd(0, i + 1)]); }

int in() {
    int x;
    cin >> x;
    return x;
}
ll lin() {
    unsigned long long x;
    cin >> x;
    return x;
}

template <class T, class S> pair<T, S> operator-(const pair<T, S> &x, const pair<T, S> &y) { return pair<T, S>(x.fi - y.fi, x.se - y.se); }
template <class T, class S> pair<T, S> operator+(const pair<T, S> &x, const pair<T, S> &y) { return pair<T, S>(x.fi + y.fi, x.se + y.se); }
template <class T> pair<T, T> operator&(const pair<T, T> &l, const pair<T, T> &r) { return pair<T, T>(max(l.fi, r.fi), min(l.se, r.se)); }
template <class T, class S> pair<T, S> operator+=(pair<T, S> &l, const pair<T, S> &r) { return l = l + r; }
template <class T, class S> pair<T, S> operator-=(pair<T, S> &l, const pair<T, S> &r) { return l = l - r; }
template <class T> bool intersect(const pair<T, T> &l, const pair<T, T> &r) { return (l.se < r.se ? r.fi < l.se : l.fi < r.se); }

template <class T> ll operator*(const pair<T, T> &x, const pair<T, T> &y) { return (ll)x.fi * y.fi + (ll)x.se * y.se; }

template <typename T> struct edge {
    int from, to;
    T cost;
    int id;
    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
    edge(int from, int to, T cost, int id) : from(from), to(to), cost(cost), id(id) {}
    constexpr bool operator<(const edge<T> &rhs) const noexcept { return cost < rhs.cost; }
    edge &operator=(const int &x) {
        to = x;
        return *this;
    }
    operator int() const { return to; }
};
template <typename T> using Edges = vector<edge<T>>;

using Tree = vector<vector<int>>;
using Graph = vector<vector<int>>;
template <class T> using Wgraph = vector<vector<edge<T>>>;
Graph getG(int n, int m = -1, bool directed = false, int margin = 1) {
    Tree res(n);
    if(m == -1) m = n - 1;
    while(m--) {
        int a, b;
        cin >> a >> b;
        a -= margin, b -= margin;
        res[a].emplace_back(b);
        if(!directed) res[b].emplace_back(a);
    }
    return res;
}
Graph id3(int n, int margin = 1) {
    Graph res(n);
    for(int i = 1; i < n; i++) {
        int a;
        cin >> a;
        res[a - margin].emplace_back(i);
    }
    return res;
}
template <class T> Wgraph<T> id8(int n, int m = -1, bool directed = false, int margin = 1) {
    Wgraph<T> res(n);
    if(m == -1) m = n - 1;
    while(m--) {
        int a, b;
        T c;
        cin >> a >> b >> c;
        a -= margin, b -= margin;
        res[a].emplace_back(b, c);
        if(!directed) res[b].emplace_back(a, c);
    }
    return res;
}
void add(Graph &G, int x, int y) { G[x].eb(y), G[y].eb(x); }
template <class S, class T> void add(Wgraph<S> &G, int x, int y, T c) { G[x].eb(y, c), G[y].eb(x, c); }




    INT(testcases);                                                                                                                                            \
    while(testcases--)
template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
    for(auto it = begin(v); it != end(v); ++it) {
        if(it == begin(v))
            os << *it;
        else
            os << " " << *it;
    }
    return os;
}
template <class T, class S> ostream &operator<<(ostream &os, const pair<T, S> &p) {
    os << p.first << " " << p.second;
    return os;
}
template <class S, class T> string to_string(pair<S, T> p) { return "(" + to_string(p.first) + "," + to_string(p.second) + ")"; }
string to_string(string s) { return "\"" + s + "\""; }
string to_string(char c) { return string(1, c); }
template <class T> string to_string(vector<T> s) {
    string res = "{";
    for(auto it = s.begin(); it != s.end(); it++) res += to_string(*it) + (next(it) == s.end() ? "" : ", ");
    return res + "}";
}
template <class T> string to_string(set<T> s) {
    string res = "{";
    for(auto it = s.begin(); it != s.end(); it++) res += to_string(*it), res += (next(it) == end(s) ? "" : ", ");
    return res + "}";
}




void dump() { cerr << endl; }
template <class Head, class... Tail> void dump(Head head, Tail... tail) {
    cerr << to_string(head) << " ";
    dump(tail...);
}


    cout << 
    dump(x)

void dump() {}
template <class Head, class... Tail> void dump(Head head, Tail... tail) {}


template <class T> void print(const T &a) { cout << a; }
void OUT() { cout << endl; }
template <class Head, class... Tail> void OUT(const Head &head, const Tail &...tail) {
    print(head);
    if(sizeof...(tail)) cout << ' ';
    OUT(tail...);
}

template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;


template <int N> struct id2 {
    std::array<int, N> v;
    id2(std::array<int, N> v_) : v(v_) {}
    struct id1 {
        const std::array<int, N> &v;
        std::array<int, N> tmp;
        bool is_end;
        id1(const std::array<int, N> &v_) : v(v_), tmp(), is_end(false) {}
        bool operator!=(const id1 &) const { return !is_end; }
        void operator++() {
            int pos = N - 1;
            while(pos != -1) {
                tmp[pos] += 1;
                if(tmp[pos] == v[pos]) {
                    tmp[pos] = 0;
                    pos -= 1;
                } else {
                    break;
                }
            }
            if(pos == -1) { is_end = true; }
        }
        const std::array<int, N> &operator*() const { return tmp; }
    };
    id1 begin() const { return id1(v); }
    id1 end() const { return id1(v); }
};

struct id5 {
    std::vector<int> v;
    id5(std::vector<int> v_) : v(v_) {}
    struct id1 {
        const std::vector<int> &v;
        std::vector<int> tmp;
        bool is_end;
        id1(const std::vector<int> &v_) : v(v_), tmp(v.size(), 0), is_end(false) {}
        bool operator!=(const id1 &) const { return !is_end; }
        void operator++() {
            int pos = v.size() - 1;
            while(pos != -1) {
                tmp[pos] += 1;
                if(tmp[pos] == v[pos]) {
                    tmp[pos] = 0;
                    pos -= 1;
                } else {
                    break;
                }
            }
            if(pos == -1) { is_end = true; }
        }
        const std::vector<int> &operator*() const { return tmp; }
    };
    id1 begin() const { return id1(v); }
    id1 end() const { return id1(v); }
};

auto ndFOR(std::vector<int> v) { return id5(v); }
template <class... Ts> auto ndFOR(Ts... v) { return id2<std::tuple_size<std::tuple<Ts...>>::value>({v...}); }
template <class F> struct REC {
    F f;
    REC(F &&f_) : f(std::forward<F>(f_)) {}
    template <class... Args> auto operator()(Args &&...args) const { return f(*this, std::forward<Args>(args)...); }
};

template <class S> vector<pair<S, int>> runLength(const vector<S> &v) {
    vector<pair<S, int>> res;
    for(auto &e : v) {
        if(res.empty() or res.back().fi != e)
            res.eb(e, 1);
        else
            res.back().se++;
    }
    return res;
}
vector<pair<char, int>> runLength(const string &v) {
    vector<pair<char, int>> res;
    for(auto &e : v) {
        if(res.empty() or res.back().fi != e)
            res.eb(e, 1);
        else
            res.back().se++;
    }
    return res;
}

template <class T = int> struct Imos {
    int n;
    vector<T> a;
    Imos(int _n) : n(_n), a(_n + 1) {}
    void add(int l, int r, T val = 1) {
        if(l >= r) return;
        l = clamp(l, 0, n);
        r = clamp(r, 0, n + 1);
        a[l] += val;
        if(r <= n) a[r] -= val;
    }
    void build() {
        for(int i = 0; i < n; i++) a[i + 1] += a[i];
    }
    const T &operator[](int k) { return a[k]; }
};

template <class T> struct RUI {
    vector<T> a;
    RUI(const vector<T> &v) : a(v.size() + 1) {
        for(int i = 0; i < v.size(); i++) a[i + 1] = a[i] + v[i];
    }
    T get(int l, int r) { return a[r] - a[l]; }
};

template <class T, class F> T bin_search(T ok, T ng, const F &f) {
    while(abs(ok - ng) > 1) {
        T mid = ok + ng >> 1;
        (f(mid) ? ok : ng) = mid;
    }
    return ok;
}
struct Setup_io {
    Setup_io() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(15);
    }
} setup_io;


template <class T, class F> struct UnionFind {
    vector<T> data;
    vector<int> sz;
    int num;
    const F &f;
    T unit;

    UnionFind(int n, const F &f = plus<T>(), const T &unit = T()) : num(n), f(f), unit(unit), sz(n, -1), data(n, unit) {}

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        num--;
        if(-sz[x] < -sz[y]) swap(x, y);
        f(data[x], data[y]);
        sz[y] = x;
        return true;
    }

    bool same(int x, int y) { return find(x) == find(y); }

    int find(int x) {
        if(sz[x] < 0) return x;
        return (sz[x] = find(sz[x]));
    }
    int size(int x) { return -sz[find(x)]; }
    const int operator[](const int k) { return find(k); }
    vector<vector<int>> belong() {
        vector<vector<int>> res(data.size());
        for(int i = 0; i < data.size(); i++) res[find(i)].emplace_back(i);
        return res;
    }
};

template <typename G> struct id7 {
    G &g;
    vector<int> sz, in, out, head, rev, par, d, vis, roots;

    id7(G &g, vector<int> r = vector<int>())
        : g(g), d(g.size()), sz(g.size()), in(g.size()), out(g.size()), head(g.size()), rev(g.size()), par(g.size()) {
        if(empty(r)) {
            vector<bool> vis(g.size());
            for(int i = 0; i < g.size(); i++) {
                if(vis[i]) continue;
                roots.emplace_back(i);
                queue<int> q;
                q.emplace(i);
                while(!empty(q)) {
                    int x = q.front();
                    vis[x] = true;
                    q.pop();
                    for(auto e : g[x]) {
                        if(!vis[e]) q.emplace(e);
                    }
                }
            }
        } else
            roots = r;
    }

    void dfs_sz(int idx, int p) {
        par[idx] = p;
        sz[idx] = 1;
        if(g[idx].size() and g[idx][0] == p) swap(g[idx][0], g[idx].back());
        for(auto &to : g[idx]) {
            if(to == p) continue;
            d[to] = d[idx] + 1;
            dfs_sz(to, idx);
            sz[idx] += sz[to];
            if(sz[g[idx][0]] < sz[to]) swap(g[idx][0], to);
        }
    }

    void id0(int idx, int par, int &times) {
        in[idx] = times++;
        rev[in[idx]] = idx;
        for(auto &to : g[idx]) {
            if(to == par) continue;
            head[to] = (g[idx][0] == to ? head[idx] : to);
            id0(to, idx, times);
        }
        out[idx] = times;
    }

    template <typename T> void id0(int idx, int par, int &times, vector<T> &v) {
        in[idx] = times++;
        rev[in[idx]] = idx;
        for(auto &to : g[idx]) {
            if(to == par) {
                v[in[idx]] = to.cost;
                continue;
            }
            head[to] = (g[idx][0] == to ? head[idx] : to);
            id0(to, idx, times, v);
        }
        out[idx] = times;
    }

    template <typename T> void id0(int idx, int par, int &times, vector<T> &v, vector<T> &a) {
        in[idx] = times++;
        rev[in[idx]] = idx;
        v[in[idx]] = a[idx];
        for(auto &to : g[idx]) {
            if(to == par) continue;
            head[to] = (g[idx][0] == to ? head[idx] : to);
            id0(to, idx, times, v, a);
        }
        out[idx] = times;
    }

    void build() {
        for(auto root : roots) {
            head[root] = root;
            dfs_sz(root, -1);
            int t = 0;
            id0(root, -1, t);
        }
    }

    template <typename T> vector<T> build(int root = 0) {
        vector<T> res(g.size());
        for(auto root : roots) {
            head[root] = root;
            dfs_sz(root, -1);
            int t = 0;
            id0(root, -1, t, res);
        }
        return res;
    }

    template <typename T> vector<T> build(vector<T> &a, int root = 0) {
        vector<T> res(g.size());
        for(auto root : roots) {
            head[root] = root;
            dfs_sz(root, -1);
            int t = 0;
            id0(root, -1, t, res, a);
        }
        return res;
    }

    int la(int v, int k) {
        while(1) {
            int u = head[v];
            if(in[v] - k >= in[u]) return rev[in[v] - k];
            k -= in[v] - in[u] + 1;
            v = par[u];
        }
    }

    int lca(int u, int v) {
        for(;; v = par[head[v]]) {
            if(in[u] > in[v]) swap(u, v);
            if(head[u] == head[v]) return u;
        }
    }

    template <typename T, typename Q, typename F> T query(int u, int v, const T &e, const Q &q, const F &f, bool edge = false) {
        T l = e, r = e;
        for(;; v = par[head[v]]) {
            if(in[u] > in[v]) swap(u, v), swap(l, r);
            if(head[u] == head[v]) break;
            l = f(q(in[head[v]], in[v] + 1), l);
        }
        return f(f(q(in[u] + edge, in[v] + 1), l), r);
    }

    template <typename T, typename Q, typename Q2, typename F> T query(int u, int v, const T &e, const Q &q1, const Q2 &q2, const F &f, bool edge = false) {
        T l = e, r = e;
        for(;;) {
            if(head[u] == head[v]) break;
            if(in[u] > in[v]) {
                l = f(l, q2(in[head[u]], in[u] + 1));
                u = par[head[u]];
            } else {
                r = f(q1(in[head[v]], in[v] + 1), r);
                v = par[head[v]];
            }
        }
        if(in[u] > in[v]) return f(f(l, q2(in[v] + edge, in[u] + 1)), r);
        return f(f(l, q1(in[u] + edge, in[v] + 1)), r);
    }

    template <typename Q> void add(int u, int v, const Q &q, bool edge = false) {
        for(;; v = par[head[v]]) {
            if(in[u] > in[v]) swap(u, v);
            if(head[u] == head[v]) break;
            q(in[head[v]], in[v] + 1);
        }
        q(in[u] + edge, in[v] + 1);
    }

    constexpr int operator[](int k) { return in[k]; }

    constexpr int dist(int u, int v) { return d[u] + d[v] - 2 * d[lca(u, v)]; }

    

    vector<int> road(int u, int v) {
        int l = lca(u, v);
        vector<int> a, b;
        for(; v != l; v = la(v)) b.eb(v);
        for(; u != l; u = la(u)) a.eb(u);
        a.eb(l);
        rep3(i, si(b) - 1, 0) a.eb(b[i]);
        return a;
    }
};

template <typename T> struct SparseTable {
    using F = function<T(T, T)>;
    const F &f;
    T unit;
    vector<vector<T>> st;
    vector<int> lookup;

    SparseTable(const vector<T> &v,const F &f, T unit) : f(f), unit(unit) {
        int b = 0;
        while((1 << b) <= v.size()) ++b;
        st.assign(b, vector<T>(1 << b));
        for(int i = 0; i < v.size(); i++) { st[0][i] = v[i]; }
        for(int i = 1; i < b; i++) {
            for(int j = 0; j + (1 << i) <= (1 << b); j++) { st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]); }
        }
        lookup.resize(v.size() + 1);
        for(int i = 2; i < lookup.size(); i++) { lookup[i] = lookup[i >> 1] + 1; }
    }

    inline T query(int l, int r) {
        if(l == r) return unit;
        int b = lookup[r - l];
        return f(st[b][l], st[b][r - (1 << b)]);
    }
};
int main() {
    INT(n, q);
    VEC(int, a, n);
    struct E {
        int u, v, c, t;
        bool operator<(const E &r) const { return c > r.c; }
    };

    vector<E> edges;
    Wgraph<int> g(n);
    rep(i, n - 1) {
        INT(u, v, c, t);
        u--, v--;
        add(g, u, v, t);
        edges.emplace_back(E{u, v, c, t});
    }
    sort(all(edges));

    id7 hld(g);
    auto v = hld.build<int>(0);
    dump(v);
    auto ff = [](int x,int y) {return max(x,y);};
    function<int(int, int)> fff(ff);
    SparseTable<int> sp(
        v, fff, 0);
    auto get = [&](int x, int y) {
        int u = hld.rev[x], v = hld.rev[y];
        int res = hld.query(
            u, v, 0,
            [&](int x, int y) {
                dump(x, y);
                int res = sp.query(x, y);
                dump(res);
                return res;
            },
            [](int x, int y) { return max(x, y); }, true);
        return res;
    };

    struct S {
        int v, max_t;
        set<int> nodes;
        S() = default;
        void Dump() { dump(v, max_t, nodes); }
    };

    auto f = [&](S &x, S &y) {
        if(x.v < y.v) swap(x, y);
        if(x.v == y.v) {
            if(x.nodes.size() < y.nodes.size()) swap(x, y);
            chmax(x.max_t, y.max_t);
            for(auto e : y.nodes) {
                auto it = x.nodes.lower_bound(e);
                if(it != end(x.nodes)) chmax(x.max_t, get(e, *it));
                if(it != begin(x.nodes)) chmax(x.max_t, get(e, *prev(it)));
                x.nodes.emplace_hint(it, e);
            }
        }
    };

    vector<S> s(n);
    rep(i, n) {
        s[i].max_t = 0;
        s[i].v = a[i];
        s[i].nodes.emplace(hld[i]);
    }

    UnionFind<S, decltype(f)> uf(n, f, S());
    uf.data = s;

    int idx = 0;
    vector<tuple<int, int, int>> qs;
    rep(i, q) {
        INT(x, v);
        v--;
        qs.emplace_back(x, v, i);
    }

    vpi ans(q);
    sort(all(qs), greater{});

    for(auto [x, v, i] : qs) {
        while(idx < n - 1 and edges[idx].c >= x) {
            uf.unite(edges[idx].u, edges[idx].v);
            idx++;
        }

        auto &ss = uf.data[uf[v]];
        int res = ss.max_t;
        int p = *ss.nodes.begin();
        ans[i] = pii(ss.v, max(res, get(p, hld[v])));
    }

    for(auto p : ans) OUT(p);
}