













namespace atcoder {
namespace internal {

template <class E> struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    explicit csr(int n, const std::vector<std::pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};

}  


}  



namespace atcoder {
namespace internal {

struct id2 {
  public:
    explicit id2(int n) : _n(n) {}

    int num_vertices() { return _n; }

    void add_edge(int from, int to) { edges.push_back({from, {to}}); }

    std::pair<int, std::vector<int>> scc_ids() {
        auto g = csr<edge>(_n, edges);
        int now_ord = 0, group_num = 0;
        std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void {
            low[v] = ord[v] = now_ord++;
            visited.push_back(v);
            for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                auto to = g.elist[i].to;
                if (ord[to] == -1) {
                    self(self, to);
                    low[v] = std::min(low[v], low[to]);
                } else {
                    low[v] = std::min(low[v], ord[to]);
                }
            }
            if (low[v] == ord[v]) {
                while (true) {
                    int u = visited.back();
                    visited.pop_back();
                    ord[u] = _n;
                    ids[u] = group_num;
                    if (u == v) break;
                }
                group_num++;
            }
        };
        for (int i = 0; i < _n; i++) {
            if (ord[i] == -1) dfs(dfs, i);
        }
        for (auto& x : ids) {
            x = group_num - 1 - x;
        }
        return {group_num, ids};
    }

    std::vector<std::vector<int>> scc() {
        auto ids = scc_ids();
        int group_num = ids.first;
        std::vector<int> counts(group_num);
        for (auto x : ids.second) counts[x]++;
        std::vector<std::vector<int>> groups(ids.first);
        for (int i = 0; i < group_num; i++) {
            groups[i].reserve(counts[i]);
        }
        for (int i = 0; i < _n; i++) {
            groups[ids.second[i]].push_back(i);
        }
        return groups;
    }

  private:
    int _n;
    struct edge {
        int to;
    };
    std::vector<std::pair<int, edge>> edges;
};

}  


}  



namespace atcoder {

struct two_sat {
  public:
    two_sat() : _n(0), scc(0) {}
    explicit two_sat(int n) : _n(n), _answer(n), scc(2 * n) {}

    void add_clause(int i, bool f, int j, bool g) {
        assert(0 <= i && i < _n);
        assert(0 <= j && j < _n);
        scc.add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));
        scc.add_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));
    }
    bool satisfiable() {
        auto id = scc.scc_ids().second;
        for (int i = 0; i < _n; i++) {
            if (id[2 * i] == id[2 * i + 1]) return false;
            _answer[i] = id[2 * i] < id[2 * i + 1];
        }
        return true;
    }
    std::vector<bool> answer() { return _answer; }

  private:
    int _n;
    std::vector<bool> _answer;
    internal::id2 scc;
};

}  


using namespace atcoder;



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
struct IOSetup { IOSetup() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); } } id1;
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






constexpr int dest(int v) { return v; }
template <class E, class = decltype(declval<E>().to)>
constexpr int dest(E const& e) { return e.to; }
constexpr int cost(...) { return 1; }
template <class E, class = decltype(declval<E>().cost)>
constexpr auto cost(E const& e) { return e.cost; }
template <class E> using cost_t = decltype(cost(declval<E>()));

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
    vector<pair<int, int>> path(int x, int y, bool id0) const {
        assert(built);
        static vector<pair<int, int>> ret;
        ret.clear();
        while (true) {
            if (id[x] > id[y]) swap(x, y);
            if (head[x] == head[y]) {
                ret.emplace_back(id[x] + (id0 ? 0 : 1), id[y]+1);
                return ret;
            } else {
                ret.emplace_back(id[head[y]], id[y]+1);
                y = par[head[y]];
            }
        }
    }
    auto vertices(int x, int y) const { return path(x, y, true); }
    auto edges(int x, int y) const { return path(x, y, false); }

    vector<int> get_vertices(int x, int y) {
        vector<int> L, R;
        int z = lca(x, y);
        while (true) {
            L.push_back(x);
            if (x == z) break;
            x = par[x];
        }
        while (true) {
            if (y == z) break;
            R.push_back(y);
            y = par[y];
        }
        while (R.size()) L.push_back(R.back()), R.pop_back();
        return L;
    };

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



int32_t main() {
    int n, q; cin >> n >> q;
    HLD<int> g(n);
    rep (i, n-1) {
        int x, y; cin >> x >> y; --x, --y;
        g.add_edge(x, y);
    }
    vector<int> x(q), y(q);
    vector<string> s(q);
    rep (i, q) cin >> x[i] >> y[i] >> s[i], --x[i], --y[i];

    vector<string> cs(n);
    auto match = [&](string s, char c) -> int {
        rep (i, 2) if (s[i] == c) return i;
        return -1;
    };
    auto compose = [&](string &A, string B) -> string {
        string s;
        for (char c : B) if (match(A, c) >= 0) s += c;
        return s;
    };
    rep (i, q) {
        auto path = g.get_vertices(x[i], y[i]);
        rep (j, path.size()) {
            int x = path[j];
            int k = sz(s[i])-1-j;
            char c = s[i][j], d = s[i][k];
            dump(x, cs[x], c, d);
            if (cs[x].empty()) {
                cs[x] = { c, d };
            } else {
                cs[x] = compose(cs[x], { c, d });
                if (cs[x].empty()) {
                    dump(x, i, c, d);
                    quit("NO");
                }
            }
        }
    }
    dump(cs);

    rep (x, n) {
        if (cs[x].empty()) {
            cs[x] = { 'a', 'a' };
        } else if (sz(cs[x]) == 1) {
            cs[x] += cs[x].back();
        }
    }

    two_sat ts(n+q);
    rep (i, q) {
        auto path = g.get_vertices(x[i], y[i]);
        rep (j, path.size()) {
            int x = path[j];
            int k = sz(s[i])-1-j;
            char c = s[i][j], d = s[i][k];
            string s = { c, d };
            rep (p, 2) {
                int idx = match(cs[x], s[p]);
                if (idx < 0) {
                    ts.add_clause(n+i, p^1, n+i, p^1);
                } else {
                    ts.add_clause(n+i, p^1, x, idx);
                }
            }
        }
    }

    if (not ts.satisfiable()) quit("NO");

    auto ans = ts.answer();
    dump(ans);
    cout << "YES" << '\n';
    string str;
    rep (x, n) str += cs[x][ans[x]];
    cout << str << '\n';




}