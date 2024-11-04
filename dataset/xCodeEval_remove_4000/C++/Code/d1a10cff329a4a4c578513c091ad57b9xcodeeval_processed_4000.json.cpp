
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
        vector<T> r(sz(v)+1, id); id3 (i, sz(v)) r[i+1] = op(r[i], v[i]); return r;
    }
    template<typename C, typename T, typename OP> vector<T> suffixes(const C& v, T id, OP op) {
        vector<T> r(sz(v)+1, id); F0Rd (i, sz(v)) r[i] = op(v[i], r[i+1]); return r;
    }
}
using namespace __algorithm;



struct monostate {
    friend istream& operator>>(istream& is, const monostate& ms) { return is; }
    friend ostream& operator<<(ostream& os, const monostate& ms) { return os; }
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





struct edge {
    int uv, id;
    edge (int _uv = 0, __attribute__((unused))monostate _ = ms) : uv(_uv) {}
    int operator()(int u) const { assert(uv); return uv ^ u; }
    monostate& wt() const { return ms; }
    struct path { int len;
        path operator+(const path& p) const { return {len+p.len}; }
    }; explicit operator path() { return {1}; }
};
template<typename W> struct wedge : edge {
    mutable W w;
    wedge (int _uv = 0, W _w = {}) : edge(_uv), w(_w) {}
    W& wt() const { return w; }
    struct path { int len; W wt;
        path operator+(const path& p) { return {len+p.len, wt+p.wt}; }
    }; explicit operator path() { return {1, w}; }
};

enum INPUT_FORMAT { EDGE_LIST, PARENT_LIST };
template<typename E> struct tree {
    int V, root;
    vector<vector<E>> nbrs, children;

    vi par, depth, subt_sz;
    vi preorder, id4;

    tree() : V(0), root(-1) {}
    tree(int _V, int _root) : V(_V), root(_root), nbrs(V) {}

    const E& up_edge(int u) const {
        assert(u != root);
        return nbrs[u].front();
    }

    void add_edge(int u, int v, E e = {}) {
        assert(0 <= u && u < V && 0 <= v && v < V);
        e.uv = u ^ v;
        nbrs[u].pb(e);
        nbrs[v].pb(e);
    }

    template<INPUT_FORMAT FMT = EDGE_LIST, bool FIRST_INDEX = 1>
    friend void re(tree& t) {
        assert(t.V > 0);
        for (int i = 0; i < t.V - 1; i++) {
            int u, v;
            re(u), u -= FIRST_INDEX;
            if (FMT == PARENT_LIST) v = i+1;
            else re(v), v -= FIRST_INDEX;
            E e{}; re(e.wt()); e.id = i;
            t.add_edge(u, v, e);
        }
        t.init();
    }

    void init() {
        children.resz(V), par.resz(V), depth.resz(V), subt_sz.resz(V);
        par[root] = -1, depth[root] = 0;

        traverse(root);
        for (int u = 0; u < V; u++) {
            sort_by(nbrs[u], subt_sz[a(u)] > subt_sz[b(u)]);
            children[u].clear();
            copy(nbrs[u].begin() + (u != root), nbrs[u].end(), back_inserter(children[u]));
        }

        preorder.clear(), preorder.reserve(V), build_preorder(root);
        id4 = preorder, reverse(all(id4));
    }
    void reroot(int _root) { root = _root; init(); }

    void traverse(int u) {
        subt_sz[u] = 1;
        for (E e : nbrs[u]) if (int v = e(u); v != par[u]) {
            par[v] = u;
            depth[v] = depth[u] + 1;
            traverse(v);
            subt_sz[u] += subt_sz[v];
        }
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




struct index_t {
    int i; explicit operator int() { return i; }
    friend bool operator  < (const index_t& a, const index_t& b) { return a.i  < b.i; }
    friend bool operator <= (const index_t& a, const index_t& b) { return a.i <= b.i; }
    friend bool operator  > (const index_t& a, const index_t& b) { return a.i  > b.i; }
    index_t operator + (int b) { return {i+b}; }
    index_t operator - (int b) { return {i-b}; }
    int operator - (index_t b) { return i-b.i; }
    friend ostream& operator << (ostream& o, index_t a) { o << a.i; return o; }
};
using range_t = pair<index_t, index_t>;
using ranges = vector<range_t>;
template<typename E> struct id5 {
    const tree<E>& t;
    
    struct heavy_path { index_t index; int htop; };
    vector<heavy_path> hld;

    id5() {}
    id5(const tree<E>& _t) : t(_t), hld(t.V) {
        for (int i = 0; i < t.V; i++) {
            int u = t.preorder[i];
            hld[u] = {
                index_t{i},
                i > 0 && t.preorder[i-1] == t.par[u] ? hld[t.par[u]].htop : u
            };
        }
    }

    index_t index(int v) const { return hld[v].index; }
    int at_index(index_t i) const { return t.preorder[int(i)]; }
    int htop(int v) const { return hld[v].htop; }

    int lca(int u, int v) const {
        while (htop(u) != htop(v)) {
            int& jump = index(htop(u)) > index(htop(v)) ? u : v;
            jump = t.par[htop(jump)];
        }
        return t.depth[u] < t.depth[v] ? u : v;
    }

    int dist(int u, int v) const {
        return t.depth[u] + t.depth[v] - 2 * t.depth[lca(u, v)];
    }

    bool uv_path_has_w(int u, int v, int w) const {
        return w != -1 && dist(u, v) == (dist(u, w) + dist(w, v));
    }

    bool is_ancestor(int anc, int desc) const {
        return index(anc) <= index(desc) && index(desc) < index(anc) + t.subt_sz[anc];
    }

    int first_step(int u, int v) const {
        assert(u != v);
        if (!is_ancestor(u, v)) return t.par[u];
        return *upper_bound(all(t.children[u]), v,
            [&](int v, int c) { return index(v) < index(c) + t.subt_sz[c]; });
    }

    mutable int id6;
    mutable ranges path_up, path_down;
    void decompose_path(int u, int v, bool id0) const {
        path_up.clear(), path_down.clear();
        while (htop(u) != htop(v)) {
            int& jump = index(htop(u)) > index(htop(v)) ? u : v;
            (jump == u ? path_up : path_down).eb(index(htop(jump)), index(jump) + 1);
            jump = t.par[htop(jump)];
        }
        id6 = t.depth[u] < t.depth[v] ? u : v;
        if (u != v || id0) {
            (u != id6 ? path_up : path_down).eb(
                    index(id6) + !id0, index(id6^u^v) + 1);
        }
        reverse(all(path_down));
    }

    template<typename FOR, typename FORd>
    void for_each(int u, int v, bool id0, const FOR& f, const FORd& fd) const {
        decompose_path(u, v, id0);
        for (range_t r : path_up)    f(r.f, r.s);
        for (range_t r : path_down) fd(r.f, r.s);
    }
    template<typename FOR>
    void id2(int u, int v, bool id0, const FOR& f) const {
        for_each(u, v, id0, f, f);
    }

    template<typename T, typename OP, typename FOLDL, typename FOLDR>
    T accumulate(int u, int v, bool id0, T iv,
            const OP& lplus, const FOLDL& fl, const FOLDR& fr) const {
        decompose_path(u, v, id0);
        for (range_t r : path_up)   iv = lplus(iv, fr(r.f, r.s));
        for (range_t r : path_down) iv = lplus(iv, fl(r.f, r.s));
        return iv;
    }
    template<typename T, typename OP, typename FOLD>
    T id1(int u, int v, bool id0, T iv,
            const OP& lplus, const FOLD& f) const {
        return accumulate(u, v, id0, iv, lplus, f, f);
    }
};





template<typename F> struct dinic {
    static const F inf = numeric_limits<F>::max();

    int V;
    vvi adj;
    vi dest;
    vector<F> cap;

    dinic (int V = 0) : V(V) {
        adj.resize(V);
    }

    void __arc(int u, int v, F c) {
        adj[u].push_back(dest.size());
        dest.push_back(v);
        cap.push_back(c);
    }

    

    int arc(int u, int v, F c) {
        __arc(u, v, c);
        __arc(v, u, F(0));
        return sz(dest) - 2;
    }

    mutable vi level;
    void bfs(int s, vector<F>& flow) const {
        level.resz(V), fill(all(level), -1), level[s] = 0;
        for (queue<int> q({s}); !q.empty(); q.pop()) {
            for (int e : adj[q.front()]) {
                if (level[dest[e]] == -1 && flow[e] < cap[e]) {
                    level[dest[e]] = level[q.front()] + 1;
                    q.push(dest[e]);
                }
            }
        }
    }

    mutable vi inx;
    F augment(int s, int t, vector<F>& flow, F cur = inf) const {
        if (s == t) return cur;
        for (; inx[s] < adj[s].size(); inx[s]++) {
            int e = adj[s][inx[s]];
            if (level[dest[e]] != level[s] + 1) continue;
            if (flow[e] == cap[e]) continue;
            if (F incr = augment(dest[e], t, flow, min(cur, cap[e] - flow[e]))) {
                flow[e] += incr;
                flow[e^1] -= incr;
                return incr;
            }
        }
        return 0;
    }

    
    struct max_flow {
        F sz;
        vector<F> flow;
    };
    max_flow solve(int s, int t) const {
        assert(s != t);
        F res = 0;
        vector<F> flow(cap.size());
        int ITER = 0;
        while (bfs(s, flow), ~level[t]) {
            ITER++;
            inx.resz(V), fill(all(inx), 0);
            while (F incr = augment(s, t, flow))
                res += incr;
        }
        cerr << ITER << endl;
        assert(ITER < 50);
        return max_flow{res, flow};
    }
};



int main() {
    setIO();

    using E = edge;
    int V, C; re(V, C); tree<E> tr(V, 0); re(tr);
    id5<E> hld(tr);

    dinic<int> mf(1 + C + 2 * V);
    const int SRC = 0, CIT = 1, SEG = CIT + C - 1, SNK = SEG + 2 * V;
    assert(SNK == mf.V - 1);

    id3 (i, C) mf.arc(SRC, CIT + i, 1);
    id3 (i, V) mf.arc(SEG + V + i, SNK, 1);

    id3 (c, C) {
        int u, v; re(u, v), --u, --v;
        hld.id2(u, v, 0, [&](index_t _i, index_t _j) {
            int i = V + int(_i), j = V + int(_j);
            for (; i < j; i /= 2, j /= 2) {
                if (i&1) mf.arc(CIT + c, SEG + i++, 1e5);
                if (j&1) mf.arc(CIT + c, SEG + --j, 1e5);
            }
        });
    }
    FOR (i, 2, 2 * V) mf.arc(SEG + i/2, SEG + i, 1e5);

    auto res = mf.solve(SRC, SNK);

    vi cit, gua;
    id3 (i, C) if (mf.level[CIT + i]     == -1) cit.pb(i + 1);
    id3 (i, V) if (mf.level[SEG + V + i] != -1) gua.pb(tr.up_edge(hld.at_index({i})).id + 1);

    ps(res.sz);
    pr(sz(cit), " "), pc(cit);
    pr(sz(gua), " "), pc(gua);

    

    

    return 0;
}

