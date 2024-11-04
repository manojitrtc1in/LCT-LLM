
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

template<typename T1, typename T2> pair<T1, T2> add(
        const pair<T1, T2>& p1, const pair<T1, T2>& p2) {
    return make_pair(p1.f + p2.f, p1.s + p2.s);
}

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
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}
using namespace __input;

namespace __output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const deque<T>& x);
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
    template<class T> void pr(const deque<T>& x) { prContain(x); }
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
        vector<T> r(sz(v)+1, id); F0R (i, sz(v)) r[i+1] = op(r[i], v[i]); return r;
    }
    template<typename C, typename T, typename OP> vector<T> suffixes(const C& v, T id, OP op) {
        vector<T> r(sz(v)+1, id); id2 (i, sz(v)) r[i] = op(v[i], r[i+1]); return r;
    }
}
using namespace __algorithm;



struct monostate {
    friend istream& operator>>(istream& is, monostate& ms) { return is; }
    friend ostream& operator<<(ostream& os, monostate& ms) { return os; }
    friend monostate operator+(const monostate& a, const monostate& b) { return a; }
} ms;


namespace __io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        cout << fixed << setprecision(15);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
}
using namespace __io;





template<typename T> struct binary_indexed_tree {
    int S;
    vector<T> table;

    binary_indexed_tree<T>(int _S = 0) : S(_S) {
        table.resize(S+1);
    }

    

    void add(int i, T v) {
        for (i++; i <= S; i += i&-i)
            table[i] = table[i] + v;
    }

    

    void replace(int i, T v) {
        add(i, v - sum(i, i+1));
    }

    

    T sum(int i) const {
        assert(0 <= i && i <= S);
        T res{};
        for (; i; i -= i&-i)
            res = res + table[i];
        return res;
    }

    

    T sum(int l, int r) const {
        return l > r ? T{} : sum(r) - sum(l);
    }

    
    int lower_bound(const auto& comp) const {
        T cur = T{};
        if (comp(cur)) return 0;

        int inx = 0;
        for (int i = 31 - __builtin_clz(S); i >= 0; i--) {
            int nxt = inx + (1 << i);
            if (nxt <= S && !comp(cur + table[nxt])) {
                inx = nxt;
                cur = cur + table[nxt];
            }
        }

        return inx < S ? inx + 1 : -1;
    }
};





struct edge {
    int uv;
    edge (int _uv = 0, __attribute__((unused))monostate _ = ms) : uv(_uv) {}
    int operator()(int u) const { assert(uv); return uv ^ u; }
    monostate& wt() const { return ms; }
    struct path {
        int len;
        friend path operator+(const path& a, const path& b) {
            return {a.len+b.len};
        }
    };
    explicit operator path() { return {1}; }
};
template<typename W> struct wedge : edge {
    W w;
    wedge (int _uv = 0, W _w = {}) : edge(_uv), w(_w) {}
    W  wt() const { return w; }
    W& wt()       { return w; }
    struct path {
        int len; W wt;
        friend path operator+(const path& a, const path& b) {
            return {a.len+b.len, a.wt + b.wt};
        }
    };
    explicit operator path() { return {1, w}; }
};

enum INPUT_FORMAT { EDGE_LIST, PARENT_LIST };
template<typename E> struct tree {
    int V, root;
    vector<vector<E>> nbrs, children;

    vi par, depth, id3;
    vi preorder, id1;

    tree(int _V = 0, int _root = 0) : V(_V), root(_root),
        nbrs(V), children(V), par(V, -1), depth(V), id3(V) {}

    void add_edge(int u, int v, E e = {}) {
        assert(0 <= u && u < V && 0 <= v && v < V);
        e.uv = u ^ v;
        nbrs[u].pb(e);
        nbrs[v].pb(e);
    }

    template<INPUT_FORMAT FMT = EDGE_LIST, bool FIRST_INDEX = 1>
    friend void re(tree& t) {
        assert(t.V > 0);
        for (int i = 1; i < t.V; i++) {
            int u, v;
            re(u), u -= FIRST_INDEX;
            if (FMT == PARENT_LIST) v = i;
            else re(v), v -= FIRST_INDEX;
            E e{}; re(e.wt());
            t.add_edge(u, v, e);
        }
        t.init();
    }

    void init() {
        traverse(root);
        for (int u = 0; u < V; u++)
            sort_by(nbrs[u], id3[a(u)] > id3[b(u)]);
        build_preorder(root);
        id1 = preorder, reverse(all(id1));
    }

    void traverse(int u) {
        id3[u] = 1;
        for (E e : nbrs[u]) if (int v = e(u); v != par[u]) {
            par[v] = u;
            depth[v] = depth[u] + 1;
            traverse(v);
            children[u].pb(e);
            id3[u] += id3[v];
        }
        sort_by(children[u], id3[a(u)] > id3[b(u)]);
    }

    void build_preorder(int u) {
        preorder.pb(u);
        for (E e : children[u]) build_preorder(e(u));
    }

    friend void pr(const tree& t) {
        pr("{V=", t.V, " root=", t.root, " |");
        for (int u = 0; u < t.V; u++) {
            pr(" ", u, "--{");
            for (E e : t.children[u])
                pr("(ch=", e(u), " wt=", e.wt(), ")");
            pr("}");
        }
        pr("}");
    }
};




template<typename E, int MAXV, bool PREORDER>
struct id0 {
    static const int L = 33 - __builtin_clz(MAXV - 1);

    const tree<E>& t;

    vi layer;     

    vpii par;     

    vi child_ct;  


    struct visit { int node; E in; };
    vector<vector<visit>> preorder;  

    vvi ch_sz;                       


    vector<array<typename E::path, L>> anc_path;

    id0(const tree<E>& _t) : t(_t),
            layer(t.V, -1), par(t.V), child_ct(t.V), anc_path(t.V) {
        assert(t.V <= MAXV);
        if (PREORDER) preorder.resz(t.V), ch_sz.resz(t.V);
        id3 = t.id3, decompose(t.root), id3.clear();
    }

    vi id3;
    int centroid(int r) {
        int c = r;
        FIND: for (E e : t.nbrs[c]) if (int u = e(c); layer[u] == -1) {
            if (id3[u] < id3[c] && 2 * id3[u] >= id3[r]) {
                c = u; goto FIND;
            }
        }
        return c;
    }

    int ly = 0, rt = 0;
    void traverse(int u, E in) {
        if (PREORDER) preorder[rt].pb({u, in});
        id3[u] = 1;
        for (E e : t.nbrs[u]) if (int v = e(u); v != in(u) && layer[v] == -1) {
            anc_path[v][ly] = anc_path[u][ly] + typename E::path(e);
            traverse(v, e);
            id3[u] += id3[v];
        }
    }

    void decompose(int r = 0, int p = -1, int i = 0) {
        par[r = centroid(r)] = {p, i}, i = 0;
        layer[r] = ly;
        if (PREORDER) preorder[r] = {{r, E{}}};
        id3[r] = 1;
        for (E e : t.nbrs[r]) if (int u = e(r); layer[u] == -1) {
            if (PREORDER) ch_sz[r].pb(-sz(preorder[r]));
            rt = r, anc_path[u][ly] = typename E::path(e), traverse(u, e);
            if (PREORDER) ch_sz[r].back() += sz(preorder[r]);
            id3[r] += id3[u], child_ct[r]++;
            ly++, decompose(u, r, i++), ly--;
        }
    }

    int lca(int u, int v) const {
        if (layer[u] < layer[v]) swap(u, v);
        while (layer[u] != layer[v]) u = par[u].f;
        while (u != v) u = par[u].f, v = par[v].f;
        return u;
    }

    int dist(int u, int v) const {
        int clca = lca(u, v);
        return anc_path[u][layer[clca]].uv + anc_path[v][layer[clca]].uv;
    }
};



int N, L, W;

ll count_pairs(auto& cd, int r) {
    struct path { int dep, dis, ci; };
    vector<path> paths;

    int max_depth = 0;
    vector<binary_indexed_tree<int>> bit;
    {
        int t = 1;
        F0R (ci, sz(cd.ch_sz[r])) {
            int md = 0;
            F0R (i, cd.ch_sz[r][ci]) {
                int u = cd.preorder[r][t++].node;
                auto [depth, dist] = cd.anc_path[u][cd.layer[r]];
                ckmax(md, depth);
                paths.pb({ depth, dist, ci });
            }

            bit.eb(md + 1);
            ckmax(max_depth, md);
        }
    }
    binary_indexed_tree<int> BIT(max_depth + 1);

    sort_by(paths, a.dis < b.dis);

    ll ans = 0;

    int j = 0;
    id2 (i, sz(paths)) {
        if (paths[i].dep <= L && paths[i].dis <= W) ans += 2;

        while (j < sz(paths) && paths[j].dis + paths[i].dis <= W) {
            BIT.add(paths[j].dep, 1);
            bit[paths[j].ci].add(paths[j].dep, 1);
            j++;
        }

        int ok = max(0, L - paths[i].dep + 1);
        ans += BIT.sum(min(ok, BIT.S))
             - bit[paths[i].ci].sum(min(ok, bit[paths[i].ci].S));
    }

    return ans / 2;
}

int main() {
    setIO();

    re(N, L, W);
    using E = wedge<int>; tree<E> tr(N); re<PARENT_LIST, 1>(tr);
    id0<E, int(1e5), 1> cd(tr);

    ll ans = 0;
    F0R (_, 10) F0R (u, N) ans += count_pairs(cd, u);
    ps(ans/10);

    

    return 0;
}
