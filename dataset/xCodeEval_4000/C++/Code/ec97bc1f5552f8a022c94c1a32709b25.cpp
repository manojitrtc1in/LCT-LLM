#include <bits/stdc++.h>
using namespace std;



#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define f first
#define s second
#define resz resize

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define sort_by(x, y) sort(all(x), [&](const auto& a, const auto& b) { return y; })

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

#define TRACE(x) x
#define __pn(x) pr(#x, " = ")
#define pd(...) __pn((__VA_ARGS__)), ps(__VA_ARGS__), cout << flush

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
        vector<T> r(sz(v)+1, id); F0Rd (i, sz(v)) r[i] = op(v[i], r[i+1]); return r;
    }
}
using namespace __algorithm;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
struct monostate {
    friend istream& operator>>(istream& is, const monostate& ms) { return is; }
    friend ostream& operator<<(ostream& os, const monostate& ms) { return os; }
    friend monostate operator+(const monostate& a, const monostate& b) { return a; }
} ms;
#pragma GCC diagnostic pop

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





template<typename T, typename F> struct segment_tree {
    int SZ;
    T id; F tt;
    vector<T> table;

    segment_tree() {}
    segment_tree(int _SZ, T _id, F _tt) : SZ(_SZ), id(_id), tt(_tt) {
        table.resize(2 * SZ, id);
    }
    template<typename L> void set_leaves(L create) {
        for (int i = 0; i < SZ; i++) table[SZ + i] = create(i);
        for (int i = SZ - 1; i; i--) table[i] = tt(table[2 * i], table[2 * i + 1]);
    }

    

    void replace(int i, T v) {
        table[i += SZ] = v;
        for (i /= 2; i > 0; i /= 2) {
            table[i] = tt(table[2 * i], table[2 * i + 1]);
        }
    }

    

    T operator()(int i, int j) const {
        T left = id, right = id;
        for (i += SZ, j += SZ; i < j; i /= 2, j /= 2) {
            if (i&1) left = tt(left, table[i++]);
            if (j&1) right = tt(table[--j], right);
        }
        return tt(left, right);
    }
    const T& operator[](int i) const { return table[SZ + i]; }
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

    vi preorder, reverse_preorder;

    vb erased;
    void erase(int u) { erased[u] = true; }

    tree(int _V = 0) : V(_V) {}
    tree(vector<E>& __edge_list, int _root = 0) : edge_list(move(__edge_list)),
            V(sz(edge_list) + 1), root(_root), edges(V),
            nbrs(V), children(V), par(V, -1), depth(V), subt_sz(V), erased(V) {
        for (int ei = 0; ei < sz(edge_list); ei++) {
            E& e = edge_list[ei];
            e.i = ei;
            assert(0 <= e.u && e.u < V && 0 <= e.v && e.v < V);
            

            

            nbrs[e.u].push_back(e.v);
            nbrs[e.v].push_back(e.u);
        }

        init(root);
        for (int u = 0; u < V; u++)
            sort_by(edges[u], subt_sz[a(u)] > subt_sz[b(u)]);

        build_preorder(root);
        reverse_preorder = preorder;
        reverse(all(reverse_preorder));
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
        vector<E> __edge_list(t.V - 1);
        for (int i = 0; i < t.V - 1; i++) {
            E& e = __edge_list[i];
            if (FMT == EDGE_LIST) re<FIRST_INDEX>(e);
            else re<FIRST_INDEX>(e, i + 1);
            e.i = i;
        }
        t = tree<E>(__edge_list);
    }
    friend void pr(const tree& t) { pr("{V=", t.V, " ", t.edge_list, "}"); }

    mutable vi __subt_sz;
    void __calc_subt_sz(int u, bool avoid_erased, int p) const {
        __subt_sz[u] = 1;
        for (int v : nbrs[u]) if (v != p && (!avoid_erased || !erased[v])) {
            __calc_subt_sz(v, avoid_erased, u);
            __subt_sz[u] += __subt_sz[v];
        }
    }

    vi centroids(int r = 0, bool avoid_erased = 1) const {
        if (__subt_sz.empty()) __subt_sz.resz(V);
        __calc_subt_sz(r, avoid_erased, -1);
        int c = r, p = -1;
        FIND: for (int u : nbrs[c]) if (!avoid_erased || !erased[u]) {
            if (subt_sz[u] < subt_sz[c] && 2 * subt_sz[u] >= subt_sz[r]) {
                p = c, c = u; goto FIND;
            }
        }
        return subt_sz[c] * 2 == subt_sz[r] ? vi{c,p} : vi{c};
    }
};




template<typename E, int MAXV, bool PREORDER>
struct centroid_decomposition {
    static const int L = 33 - __builtin_clz(MAXV - 1);

    const tree<E>& t;

    vi layer;        

    vpii par;        

    vi child_ct;     

    vi layer_order;  

    vvpii preorder;  

    vvi ch_sz;       

    vector<array<int, L>> anc_dist;  


    centroid_decomposition(const tree<E>& _t) : t(_t),
            layer(t.V, -1), par(t.V),  anc_dist(t.V) {
        assert(t.V <= MAXV);
        if (PREORDER) preorder.resz(t.V), ch_sz.resz(t.V);
        subt_sz = t.subt_sz, decompose(t.root), subt_sz.clear();
    }

    int lca(int u, int v) const {
        if (layer[u] < layer[v]) swap(u, v);
        while (layer[u] != layer[v]) u = par[u].f;
        while (u != v) u = par[u].f, v = par[v].f;
        return u;
    }

    int dist(int u, int v) const {
        int clca = lca(u, v);
        return anc_dist[u][layer[clca]] + anc_dist[v][layer[clca]];
    }

    vi subt_sz;
    int centroid(int r) {
        int c = r;
        FIND: for (int u : t.nbrs[c]) if (layer[u] == -1) {
            if (subt_sz[u] < subt_sz[c] && 2 * subt_sz[u] >= subt_sz[r]) {
                c = u; goto FIND;
            }
        }
        return c;
    }

    int ly = 0, rt = 0;
    void traverse(int u, int p) {
        anc_dist[u][ly] = anc_dist[p][ly] + 1;
        if (PREORDER) preorder[rt].pb({u, p});
        subt_sz[u] = 1;
        for (int v : t.nbrs[u]) if (v != p && layer[v] == -1) {
            traverse(v, u);
            subt_sz[u] += subt_sz[v];
        }
    }

    void decompose(int r = 0, int p = -1, int i = 0) {
        par[r = centroid(r)] = {p, i}, i = 0;
        layer[r] = ly;
        if (PREORDER) layer_order.pb(r), preorder[r] = {{r, -1}};
        subt_sz[r] = 1;
        for (int u : t.nbrs[r]) if (layer[u] == -1) {
            

            if (PREORDER) ch_sz[r].pb(-sz(preorder[r]));
            rt = r, traverse(u, r);
            if (PREORDER) ch_sz[r].back() += sz(preorder[r]);
            subt_sz[r] += subt_sz[u];
            ly++, decompose(u, r, i++), ly--;
        }
    }
};



int main() {
    setIO();

    int V = 4;

    using E = wedge<>;
    vector<E> elist;
    F0R (u, 3) elist.pb({ 0, 1 + u });

    int Q; re(Q); vi ops(Q); re(ops);

    F0R (q, Q) {
        --ops[q];
        elist.pb({ ops[q], V++ });
        elist.pb({ ops[q], V++ });
    }

    tree<E> tr(elist);
    centroid_decomposition<E, int(1e6 + 4), 0> cd(tr);
    tr.edges.clear();

    


    int diam = 0;
    int deepest = 0;

    auto intro = [&](int u) {
        if (tr.depth[u] > tr.depth[deepest]) {
            diam++;
            deepest = u;
        } else {
            ckmax(diam, cd.dist(deepest, u));
        }
    };

    F0R (u, 4) intro(u);

    F0R (q, Q) {
        intro(4 + 2 * q);
        intro(4 + 2 * q + 1);
        ps(diam);
    }

    

    return 0;
}

