
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
    template<class T> void re(vector<T>& a) { id2(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { id2(i,SZ) re(a[i]); }
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
        vector<T> r(sz(v)+1, id); id2 (i, sz(v)) r[i+1] = op(r[i], v[i]); return r;
    }
    template<typename C, typename T, typename OP> vector<T> suffixes(const C& v, T id, OP op) {
        vector<T> r(sz(v)+1, id); id4 (i, sz(v)) r[i] = op(v[i], r[i+1]); return r;
    }
}
using namespace __algorithm;

struct monostate {
    friend istream& operator>>(istream& is, const __attribute__((unused))monostate& ms) { return is; }
    friend ostream& operator<<(ostream& os, const __attribute__((unused))monostate& ms) { return os; }
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





template<typename W=monostate> struct wedge {
    int u, v, i; W w;
    wedge<W>(int _u=-1, int _v=-1, int _i=-1, W _w = W{}) : u(_u), v(_v), i(_i), w(_w) {}
    int operator()(int loc) const { return u ^ v ^ loc; }
    friend void pr(const wedge& e) { pr(e.u, "<-", e.w, "->", e.v); }

    template<bool FIRST_INDEX = 1>
    friend void re(wedge& e) { re(e.u, e.v, e.w); if (FIRST_INDEX) --e.u, --e.v; }
    template<bool FIRST_INDEX = 1>
    friend void re(wedge& e, int _u) { e.u = _u; re(e.v, e.w); if (FIRST_INDEX) --e.v; }
};

enum INPUT_FORMAT { EDGE_LIST, PARENT_LIST };
template<typename E> struct tree {
    vector<E> edge_list;

    int V, root;
    vector<vector<E>> edges;

    vvi nbrs, children;
    vi par, depth, subt_sz;

    vi preorder, id3;

    vb erased;
    void erase(int u) { erased[u] = true; }

    tree(int _V = 0) : V(_V) {}
    tree(vector<E>& id5, int _root = 0) : edge_list(move(id5)),
            V(sz(edge_list) + 1), root(_root), edges(V),
            nbrs(V), children(V), par(V, -1), depth(V), subt_sz(V), erased(V) {
        for (const E& e : edge_list) {
            assert(0 <= e.u && e.u < V && 0 <= e.v && e.v < V);
            edges[e.u].pb(e);
            edges[e.v].pb(e);
            nbrs[e.u].push_back(e.v);
            nbrs[e.v].push_back(e.u);
        }

        init(root);
        for (int u = 0; u < V; u++)
            sort_by(edges[u], subt_sz[a(u)] > subt_sz[b(u)]);

        build_preorder(root);
        id3 = preorder;
        reverse(all(id3));
    }

    void init(int u) {
        subt_sz[u] = 1;
        for (int v : nbrs[u]) if (v != par[u]) {
            par[v] = u;
            depth[v] = depth[u] + 1;
            init(v);
            children[u].pb(v);
            subt_sz[u] += subt_sz[v];
        }
        sort_by(children[u], subt_sz[a] > subt_sz[b]);
    }

    void build_preorder(int u) {
        preorder.pb(u);
        for (int v : children[u]) build_preorder(v);
    }

    template<INPUT_FORMAT FMT = EDGE_LIST, bool FIRST_INDEX = 1>
    friend void re(tree& t) {
        assert(t.V > 0);
        vector<E> id5(t.V - 1);
        for (int i = 0; i < t.V - 1; i++) {
            E& e = id5[i];
            if (FMT == EDGE_LIST) re<FIRST_INDEX>(e);
            else re<FIRST_INDEX>(e, i + 1);
            e.i = i;
        }
        t = tree<E>(id5);
    }
    friend void pr(const tree& t) { pr("{V=", t.V, " ", t.edge_list, "}"); }

    mutable vi __subt_sz;
    void __calc_subt_sz(int u, bool id0, int p) const {
        __subt_sz[u] = 1;
        for (int v : nbrs[u]) if (v != p && (!id0 || !erased[v])) {
            __calc_subt_sz(v, id0, u);
            __subt_sz[u] += __subt_sz[v];
        }
    }

    vi centroids(int r = 0, bool id0 = 1) const {
        if (__subt_sz.empty()) __subt_sz.resz(V);
        __calc_subt_sz(r, id0, -1);
        int c = r, p = -1;
        FIND: for (int u : nbrs[c]) if (!id0 || !erased[u]) {
            if (subt_sz[u] < subt_sz[c] && 2 * subt_sz[u] >= subt_sz[r]) {
                p = c, c = u; goto FIND;
            }
        }
        return subt_sz[c] * 2 == subt_sz[r] ? vi{c,p} : vi{c};
    }
};




template<typename E, int MAXV> struct id1 {
    static const int L = 33 - __builtin_clz(MAXV - 1);

    const tree<E>& t;

    vi layer;        

    vpii par;        

    vi layer_order;  

    vvpii preorder;  

    vvi ch_sz;       

    vector<array<pii, L>> anc_dist;  


    int child_ct(int u) { return sz(ch_sz[u]); }

    id1(const tree<E>& _t) : t(_t), layer(t.V, -1), par(t.V),
            preorder(t.V), ch_sz(t.V), anc_dist(t.V), subt_sz(t.V) {
        assert(t.V <= MAXV);
        calc_subt_sz();
        decompose();

        for (int r : layer_order)
            for (pii u : preorder[r]) if (~u.s) {
                const E& e = t.edge_list[u.s];
                anc_dist[u.f][layer[r]] = {
                    anc_dist[e(u.f)][layer[r]].f + 1,
                    anc_dist[e(u.f)][layer[r]].s + e.w
                };
            }
    }

    vi subt_sz;
    void calc_subt_sz(int u = 0, int p = -1) {
        subt_sz[u] = 1;
        for (int v : t.nbrs[u]) if (v != p) {
            calc_subt_sz(v, u);
            subt_sz[u] += subt_sz[v];
        }
    }

    int centroid(int r) {
        int c = r;
        FIND: for (int u : t.nbrs[c]) if (layer[u] == -1) {
            if (subt_sz[u] < subt_sz[c] && 2 * subt_sz[u] >= subt_sz[r]) {
                c = u; goto FIND;
            }
        }
        return c;
    }

    void calc_preorder(int u, int ei, int r) {
        preorder[r].pb({u, ei});
        subt_sz[u] = 1;
        for (E e : t.edges[u]) if (int v = e(u); e.i != ei && layer[v] == -1) {
            if (u == r) ch_sz[r].pb(-sz(preorder[r]));
            calc_preorder(v, e.i, r);
            subt_sz[u] += subt_sz[v];
            if (u == r) ch_sz[r].back() += sz(preorder[r]);
        }
    }

    void decompose(int r = 0, int p = -1, int i = 0, int ly = 0) {
        par[r = centroid(r)] = {p, i}, i = 0;
        layer[r] = ly, layer_order.pb(r);
        calc_preorder(r, -1, r);
        for (int u : t.nbrs[r]) if (layer[u] == -1) {
            decompose(u, r, i++, ly + 1);
        }
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
        id2 (ci, sz(cd.ch_sz[r])) {
            int md = 0;
            id2 (i, cd.ch_sz[r][ci]) {
                int u = cd.preorder[r][t++].f;
                int depth = cd.anc_dist[u][cd.layer[r]].f;
                int dist = cd.anc_dist[u][cd.layer[r]].s;
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
    id4 (i, sz(paths)) {
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
    id1<E, int(1e5)> cd(tr);

    const int REP = 10;

    ll ans = 0;

    id2 (r, REP) {
        trav (u, cd.layer_order) {
            ans += count_pairs(cd, u);
        }
    }

    ps(ans / REP);

    

    return 0;
}
