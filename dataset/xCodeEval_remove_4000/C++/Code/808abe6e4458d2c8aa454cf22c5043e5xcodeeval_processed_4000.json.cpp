
using namespace std;
























using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

using vpii = vector<pii>;
using vvpii = vector<vpii>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;
using vpdd = vector<pdd>;
using vvpdd = vector<vpdd>;

template<typename T> void ckmin(T& a, const T& b) { a = min(a, b); }
template<typename T> void ckmax(T& a, const T& b) { a = max(a, b); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace __input {
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);

    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) {
        re(first); re(rest...);
    }

    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { id3(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { id3(i,SZ) re(a[i]); }
}
using namespace __input;

namespace __output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);

    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) {
        pr(first); pr(rest...);
    }

    template<class T1, class T2> void pr(const pair<T1,T2>& x) {
        pr("{",x.f,", ",x.s,"}");
    }
    template<class T, bool pretty = true> void prContain(const T& x) {
        if (pretty) pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?pretty?", ":" ":"",a), fst = 0;
        if (pretty) pr("}");
    }
    template<class T> void pc(const T& x) { prContain<T, false>(x); pr("\n"); }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }

    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) {
        pr(first); ps();
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) {
        pr(first," "); ps(rest...);
    }
}
using namespace __output;





namespace __algorithm {
    template<typename T> void dedup(vector<T>& v) {
        sort(all(v)); v.erase(unique(all(v)), v.end());
    }
    template<typename T> typename vector<T>::iterator find(vector<T>& v, const T& x) {
        auto it = lower_bound(all(v), x); return it != v.end() && *it == x ? it : v.end();
    }
    template<typename T> size_t index(vector<T>& v, const T& x) {
        auto it = find(v, x); assert(it != v.end() && *it == x); return it - v.begin();
    }
    template<typename C, typename T, typename OP> vector<T> prefixes(const C& v, T id, OP op) {
        vector<T> r(sz(v)+1, id); id3 (i, sz(v)) r[i+1] = op(r[i], v[i]); return r;
    }
    template<typename C, typename T, typename OP> vector<T> suffixes(const C& v, T id, OP op) {
        vector<T> r(sz(v)+1, id); F0Rd (i, sz(v)) r[i] = op(v[i], r[i+1]); return r;
    }
}
using namespace __algorithm;

struct monostate {
    friend istream& operator>>(istream& is, const __attribute__((unused))monostate& ms) { return is; }
    friend ostream& operator<<(ostream& os, const __attribute__((unused))monostate& ms) { return os; }
} ms;

template<typename W=monostate> struct wedge {
    int u, v, i; W w;
    wedge<W>(int _u=-1, int _v=-1, int _i=-1) : u(_u), v(_v), i(_i) {}
    int operator[](int loc) const { return u ^ v ^ loc; }
    friend void re(wedge& e) { re(e.u, e.v, e.w); --e.u, --e.v; }
    friend void pr(const wedge& e) { pr(e.u, "<-", e.w, "->", e.v); }
};

namespace __io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.precision(15);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
}
using namespace __io;





template<typename T> struct id0 {
    using F = function<T(const T&, const T&)>;

    int SZ;
    F combine;
    vector<T> table;

    T& entry(int l, int i) { return table[l * SZ + i]; }
    const T& entry(int l, int i) const { return table[l * SZ + i]; }

    id0() {}
    id0(const vector<T>& elts, F _combine) : SZ(sz(elts)), combine(_combine) {
        const int L = 32 - __builtin_clz(max(SZ - 1, 1));
        table.resize(L * SZ);
        copy(all(elts), table.begin());

        for (int l = 0; l + 1 < L; l++) {
            for (int i = 0; i < SZ; i++) {
                entry(l + 1, i) = entry(l, i);
                if (i + (1 << l) < SZ)
                    entry(l + 1, i) = combine(entry(l + 1, i), entry(l, i + (1 << l)));
            }
        }
    }

    

    T operator()(int i, int j) const {
        assert(0 <= i && i < j && j <= SZ);
        int l = j - i - 1 ? 31 - __builtin_clz(j - i - 1) : 0;
        return combine(entry(l, i), entry(l, j - (1 << l)));
    }
};





tuple<int, vi> id2(const vvi& graph) {
    const int N = graph.size();
    int C = 0, V = 0, top = 0;
    vi comp(N, -1), inx(N, -1), stack(N + 1, -1);

    auto tarjan = [&](auto&& self, int loc) -> int {
        stack[top++] = loc;
        int low = inx[loc] = V++;
        for (int nbr : graph[loc]) {
            if (inx[nbr] == -1) low = min(low, self(self, nbr));
            else if (comp[nbr] == -1) low = min(low, inx[nbr]);
        }
        if (low == inx[loc]) {
            while (stack[top] != loc)
                comp[stack[--top]] = C;
            C++;
        }
        return low;
    };

    for (int i = 0; i < N; i++) {
        if (inx[i] == -1)
            tarjan(tarjan, i);
    }
    return { C, comp };
}




struct two_sat {
    vvi graph;
    two_sat() {}

    int new_var() {
        graph.pb({});
        graph.pb({});
        return sz(graph) - 1;
    }

    void implies(int a, int b) {
        if (a < 0 || b < 0) return;
        graph[a].pb(b);
        graph[b^1].pb(a^1);
    }

    template<typename F> int nullable(int a, int b, F op) {
        return a < 0 ? b : b < 0 ? a : op(a, b);
    }

    int make_and(int a, int b) {
        return nullable(a, b, [&](int a, int b){
            int v = new_var();
            implies(v, a);
            implies(v, b);
            return v;
        });
    }

    int make_or(int a, int b) {
        return nullable(a, b, [&](int a, int b){
            int v = new_var();
            implies(a, v);
            implies(b, v);
            return v;
        });
    }

    

    int make_at_most_one(int a, int b) {
        return nullable(a, b, [&](int a, int b) {
            implies(a, b^1); 

            return make_or(a, b);
        });
    }

    vb solve() {
        int C; vi comp; tie(C, comp) = id2(graph);
        vb res(sz(graph));
        for (int v = 0; v < sz(res); v++) {
            if (comp[v] == comp[v^1]) return {};
            res[v] = comp[v] > comp[v^1];
        }
        return res;
    }
};





struct tree {
    vvi adj;
    int V, root;
    vi depth, par, subt_sz;

    struct visit { int node, depth, index; };
    vector<visit> euler_tour;
    vi first_visit;
    id0<visit> table;

    tree(const vvi& _adj = {}, int _root = 0) : adj(_adj), V(sz(adj)), root(_root) {
        par.resz(V), depth.resz(V), subt_sz.resz(V), first_visit.resz(V);

        auto dfs = [&](auto& self, int loc) -> void {
            subt_sz[loc] = 1;
            first_visit[loc] = sz(euler_tour);
            euler_tour.pb({loc, depth[loc], sz(euler_tour)});

            for (int nbr : adj[loc]) if (nbr != par[loc]) {
                par[nbr] = loc;
                depth[nbr] = depth[loc] + 1;
                self(self, nbr);
                subt_sz[loc] += subt_sz[nbr];
                euler_tour.push_back({loc, depth[loc], sz(euler_tour)});
            }
        };
        dfs(dfs, root);

        table = id0<visit>(euler_tour, [&](visit a, visit b) {
            if (a.depth != b.depth) return a.depth < b.depth ? a : b;
            return a.index > b.index ? a : b;
        });
    }

    int lca(int u, int v) const {
        u = first_visit[u], v = first_visit[v];
        if (u > v) swap(u, v);
        return table(u, v + 1).node;
    }

    int dist(int u, int v) const {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

    bool uv_path_has_w(int u, int v, int w) const {
        return dist(u, v) == (dist(u, w) + dist(w, v));
    }

    

    int first_step(int u, int v) const {
        assert(u != v);
        if (int w = lca(u, v); u != w) return par[u];
        return euler_tour[table(first_visit[u], first_visit[v]).index + 1].node;
    }
};



struct id4 {
    const tree& t;
    struct heavy_path { int index, htop; };
    vector<heavy_path> hld;

    id4(const tree& _t) : t(_t) {
        hld.resz(t.V);
        auto dfs = [&](auto& self, int loc, int index, int htop) -> int {
            hld[loc] = {index++, htop};
            for (int nbr : t.adj[loc]) if (nbr != t.par[loc]) {
                if (t.subt_sz[nbr] * 2 >= t.subt_sz[loc]) {
                    index = self(self, nbr, index, htop);
                    break;
                }
            }
            for (int nbr : t.adj[loc]) if (nbr != t.par[loc]) {
                if (t.subt_sz[nbr] * 2 < t.subt_sz[loc])
                    index = self(self, nbr, index, nbr);
            }
            return index;
        };
        dfs(dfs, t.root, 0, t.root);
    }

    void decompose_vertical_path(int u, int v, bool up, vpii& res) const {
        size_t bef = res.size();
        for (assert(t.depth[u] >= t.depth[v]); true; u = t.par[u]) {
            int w = t.depth[hld[u].htop] >= t.depth[v] ? hld[u].htop : v;
            res.emplace_back(hld[up?u:w].index, hld[up?w:u].index);
            if ((u = w) == v) break;
        }
        if (!up) reverse(res.begin() + bef, res.end());
    }

    vpii decompose_path(int u, int v, bool id1) const {
        vpii res;
        int w = t.lca(u, v);
        if (u != w) decompose_vertical_path(u, t.first_step(w, u), true, res);
        if (id1) res.emplace_back(hld[w].index, hld[w].index);
        if (v != w) decompose_vertical_path(v, t.first_step(w, v), false, res);
        return res;
    }

    template<typename FOR, typename FORd>
    void for_each(int u, int v, bool id1, FOR f, FORd fd) const {
        for (pii r : decompose_path(u, v, id1)) {
            if (r.f > r.s) fd(r.s, r.f + 1);
            else f(r.f, r.s + 1);
        }
    }
};



struct forest {
    int V;
    vi tree_id, node_id;
    vector<vvi> tree_adj;
    vector<tree> trees;
    forest(const vvi& adj = {}, vi roots = {}) : V(sz(adj)) {
        tree_id.resz(V, -1); node_id.resz(V, -1);

        auto dfs = [&](auto& self, int loc, int par, int tid) -> void {
            tree_id[loc] = tid;
            node_id[loc] = sz(tree_adj[tid]);
            tree_adj[tid].pb(adj[loc]);
            for (int nbr : adj[loc]) if (nbr != par) {
                self(self, nbr, loc, tid);
            }
        };

        for (int v : roots) {
            assert(tree_id[v] == -1);
            tree_adj.pb({});
            dfs(dfs, v, v, sz(trees) - 1);
            trees.pb(tree(tree_adj.back(), v));
        }
        for (int v = 0; v < V; v++) {
            if (tree_id[v] != -1) continue;
            trees.eb();
            dfs(dfs, v, v, sz(trees) - 1);
            trees.pb(tree(tree_adj.back(), v));
        }
    }
};



int main() {
    setIO();

    int N, M; re(N);
    vvi adj(N);
    id3 (i, N-1) {
        int u, v; re(u, v); --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    tree tr(adj);
    id4 hl(tr);

    re(M);
    vi seg(2 * N, -1), ants(M);
    two_sat ts;

    id3 (i, M) {
        ants[i] = ts.new_var();
        id3 (j, 2) {
            auto rec = [&](int l, int r) {
                for (l += N, r += N; l < r; l /= 2, r /= 2) {
                    if (l&1) { seg[l] = ts.make_at_most_one(seg[l], ants[i]^j); l++; }
                    if (r&1) { r--; seg[r] = ts.make_at_most_one(seg[r], ants[i]^j); }
                }
            };

            int u, v; re(u, v); --u, --v;
            hl.for_each(u, v, false, rec, rec);
        }
    }

    FORd (i, 1, N) seg[i] = ts.make_at_most_one(seg[i], ts.make_or(seg[2*i], seg[2*i+1]));

    vb res = ts.solve();
    if (!sz(res)) { ps("NO"); return 0; }
    ps("YES");
    id3 (i, M) ps(1 + res[ants[i]]);

    return 0;
}

