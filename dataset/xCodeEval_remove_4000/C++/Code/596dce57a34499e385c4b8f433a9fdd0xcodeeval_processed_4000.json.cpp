
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
        ios_base::sync_with_stdio(0); cin.tie(0);
        cout << fixed << setprecision(15);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
}
using namespace __io;





template<typename T, typename F> struct id0 {
    int SZ;
    F tt; 

    vector<T> table;

    T& entry(int l, int i) { return table[l * SZ + i]; }
    const T& entry(int l, int i) const { return table[l * SZ + i]; }

    id0() {}
    id0(const vector<T>& elts, F _tt) : SZ(sz(elts)), tt(_tt) {
        const int L = 32 - __builtin_clz(max(SZ - 1, 1));
        table.resize(L * SZ);
        copy(all(elts), table.begin());

        for (int l = 0; l + 1 < L; l++) {
            for (int i = 0; i < SZ; i++) {
                entry(l + 1, i) = entry(l, i);
                if (i + (1 << l) < SZ)
                    entry(l + 1, i) = tt(entry(l + 1, i), entry(l, i + (1 << l)));
            }
        }
    }

    

    T operator()(int i, int j) const {
        assert(0 <= i && i < j && j <= SZ);
        int l = j - i - 1 ? 31 - __builtin_clz(j - i - 1) : 0;
        return tt(entry(l, i), entry(l, j - (1 << l)));
    }
};




template<typename E> struct tree {
    int V;
    vvi nbrs;
    vector<vector<reference_wrapper<E>>> edges;
    vector<E> edge_list;

    tree(int _V = 0) : V(_V) {}
    tree(const vector<E>& id6) : V(sz(id6) + 1), edge_list(id6) {
        nbrs.resize(V), edges.resize(V);
        for (E& e : edge_list) {
            assert(0 <= e.u && e.u < V && 0 <= e.v && e.v < V);
            nbrs[e.u].push_back(e.v);
            nbrs[e.v].push_back(e.u);
            edges[e.u].pb(e);
            edges[e.v].pb(e);
        }
        erased.resize(V), subt_sz.resize(V);
    }

    friend void re(tree& t) {
        assert(t.V > 0);
        vector<E> id6(t.V - 1);
        re(id6);
        for (int i = 0; i < t.V - 1; i++) id6[i].i = i;
        t = tree<E>(id6);
    }
    friend void pr(const tree& t) { pr("{V=", t.V, " ", t.edge_list, "}"); }

    vb erased;
    void erase(int u) { erased[u] = true; }

    mutable vi subt_sz;
    void calc_subt_sz(int u, bool id4, int p) const {
        subt_sz[u] = 1;
        for (int v : nbrs[u]) if (v != p && (!id4 || !erased[v])) {
            calc_subt_sz(v, id4, u);
            subt_sz[u] += subt_sz[v];
        }
    }

    vi centroids(int r = 0, bool id4 = 1) const {
        calc_subt_sz(r, id4, -1);
        int c = r, p = -1;
        FIND: for (int u : nbrs[c]) if (!id4 || !erased[u]) {
            if (subt_sz[u] < subt_sz[c] && 2 * subt_sz[u] >= subt_sz[r]) {
                p = c, c = u; goto FIND;
            }
        }
        return subt_sz[c] * 2 == subt_sz[r] ? vi{c,p} : vi{c};
    }
};




template<typename E> struct id7 {
    const tree<E>& t;
    int root;
    vi _par, _depth, _subt_sz;

    const vi& nbrs(int v) const { return t.nbrs[v]; }
    int par(int v) const { return _par[v]; }
    int depth(int v) const { return _depth[v]; }
    int subt_sz(int v) const { return _subt_sz[v]; }

    vi euler_tour, preorder, first_visit;
    id0<int, function<int(int, int)>> table;

    id7() {}
    id7(const tree<E>& _t, int _root = 0) : t(_t), root(_root) {
        _par.resz(t.V,-1), _depth.resz(t.V), _subt_sz.resz(t.V), first_visit.resz(t.V);
        auto dfs = [&](auto& self, int loc) -> void {
            _subt_sz[loc] = 1;
            first_visit[loc] = sz(euler_tour);
            preorder.pb(loc);
            euler_tour.pb(loc);

            for (int nbr : this->nbrs(loc)) if (nbr != this->par(loc)) {
                _par[nbr] = loc;
                _depth[nbr] = this->depth(loc) + 1;
                self(self, nbr);
                _subt_sz[loc] += this->subt_sz(nbr);
                euler_tour.pb(loc);
            }
        };
        dfs(dfs, root);
        vi index(sz(euler_tour)); for (int i = 0; i < sz(index); i++) index[i] = i;
        table = id0<int, function<int(int, int)>>(index, [&](int i, int j) {
            return _depth[euler_tour[i]] < _depth[euler_tour[j]] ? i : j;
        });
    }

    int lca(int u, int v) const {
        u = first_visit[u], v = first_visit[v];
        if (u > v) swap(u, v);
        return euler_tour[table(u, v + 1)];
    }

    int dist(int u, int v) const {
        return depth(u) + depth(v) - 2 * depth(lca(u, v));
    }

    bool uv_path_has_w(int u, int v, int w) const {
        return w != -1 && dist(u, v) == (dist(u, w) + dist(w, v));
    }

    

    int first_step(int u, int v) const {
        assert(u != v);
        if (lca(u, v) != u) return par(u);
        return euler_tour[table(first_visit[u], first_visit[v]) + 1];
    }

    template<typename T, typename F> vector<T> id2(T id, F op) {
        vector<T> res(t.V, id);
        auto dfs = [&](auto& self, int loc) -> void {
            for (int eid : t.eids[loc]) {
                E& e = t.edges[eid]; int nbr = e[loc];
                if (nbr == par(loc)) continue;
                res[nbr] = op(res[loc], e);
                self(self, nbr);
            }
        };
        dfs(dfs, root);
        return res;
    }
    template<typename T> T read_path(vector<T> id2, int u, int v) {
        return id2[u] + id2[v] - 2 * id2[lca(u, v)];
    }
};



template<typename E> struct id9 {
    const id7<E>& t;
    vi label, above; vb interesting; int root, L;

    id9(const id7<E>& _t, vi id8,
            int _root = -1) : t(_t), label(_t.t.V, -1), interesting(_t.t.V, 0), root(_root), L(0) {
        sort_by(id8, t.first_visit[a] < t.first_visit[b]);
        unique(all(id8));
        for (int i = 0; i < sz(id8); i++) {
            interesting[id8[i]] = true;
            if (i) interesting[t.lca(id8[i-1], id8[i])] = true;
        }
        if (~root) interesting[root] = true;

        for (int u : t.preorder) if (interesting[u]) {
            label[u] = L;
            int v = t.par(u);
            if (v == -1 || interesting[v]) {
                above.pb(v != -1 ? label[v] : -1), L++;
                continue;
            }

            if (root == -1) above.pb(++L);
            for (; v != -1 && !interesting[v]; v = t.par(v))
                label[v] = L;
            above.pb(v != -1 ? label[v] : -1), L++;
        }
    }

    const vi& decompose_path(int u, int v, bool id1) const {
        static vi res; res.clear();
        int w = t.lca(u, v); if (root != -1) assert(root == w);
        assert(interesting[u] && interesting[v] && interesting[w]);
        for (int x = label[u]; x != label[w]; x = above[x]) res.pb(x);
        if (id1) res.pb(label[w]);
        size_t bef = res.size();
        for (int x = label[v]; x != label[w]; x = above[x]) res.pb(x);
        reverse(res.begin() + bef, res.end());
        return res;
    }

    template<typename F>
    void id3(int u, int v, bool id1, F f) const {
        int w = t.lca(u, v); if (root != -1) assert(root == w);
        assert(interesting[u] && interesting[v] && interesting[w]);
        for (int x = label[u]; x != label[w]; x = above[x]) f(x);
        if (id1) f(label[w]);
        for (int x = label[v]; x != label[w]; x = above[x]) f(x);
    }
};

int main() {
    setIO();

    int N, M; re(N, M);
    using E = wedge<>;

    vi par(N);
    vector<E> edges;
    FOR (i, 1, N) { re(par[i]); edges.pb({ --par[i], i }); }
    tree<E> tr(edges);

    

    id7<E> lca(tr);

    vi tol(N), ops(M); re(tol, ops);

    vb gone(N, false);
    

    const int BLOCK = 600;
    for (int bs = 0; bs < M; bs += BLOCK) {
        vi id5(N);
        reverse(all(lca.preorder));
        trav (u, lca.preorder) {
            id5[u] = gone[u];
            trav (v, tr.nbrs[u]) if (lca.depth(v) > lca.depth(u)) id5[u] += id5[v];
        }
        reverse(all(lca.preorder));

        vi queried;
        vb wquery(N);
        int lo = 0, hi = 1;
        FOR (op, bs, min(bs + BLOCK, M)) {
            if (ops[op] > 0) hi++;
            else lo--;
            int u = abs(ops[op]) - 1;
            queried.pb(u);
            wquery[u] = 1;
        }
        dedup(queried);

        id9<E> ctr(lca, queried, 0);

        const int G = ctr.L, R = hi - lo;
        auto ok = [&](int i) { return 0 <= i && i < R; };

        vvi groups(G, vi(R));
        vi index(N), curv(G, 0 - lo);
        F0R (u, N) index[u] = tol[u] - id5[u] - lo;

        int ans = 0;
        F0R (u, N) if (!gone[u]) {
            if (index[u] < 0 - lo) ans++;
            if (ctr.label[u] != -1 && ok(index[u])) groups[ctr.label[u]][index[u]]++;
        }

        FOR (op, bs, min(bs + BLOCK, M)) {
            int u = abs(ops[op]) - 1, ug = ctr.label[u];
            if (!gone[u]) {
                gone[u] = 1;
                if (index[u] < curv[ug]) ans--;
                if (ok(index[u])) groups[ug][index[u]]--;
                ctr.id3(u, 0, 1, [&](int g) { ans += groups[g][curv[g]++]; });
            } else {
                gone[u] = 0;
                if (index[u] < curv[ug]) ans++;
                if (ok(index[u])) groups[ug][index[u]]++;
                ctr.id3(u, 0, 1, [&](int g) { ans -= groups[g][--curv[g]]; });
            }

            if (op) pr(" ");
            pr(ans);
        }
    }
    ps();

    

    return 0;
}
