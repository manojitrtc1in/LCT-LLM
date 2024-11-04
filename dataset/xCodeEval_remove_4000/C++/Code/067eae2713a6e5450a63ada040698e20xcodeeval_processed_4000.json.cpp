
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
    template<class T> void re(vector<T>& a) { id14(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { id14(i,SZ) re(a[i]); }
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
        vector<T> r(sz(v)+1, id); id14 (i, sz(v)) r[i+1] = op(r[i], v[i]); return r;
    }
    template<typename C, typename T, typename OP> vector<T> suffixes(const C& v, T id, OP op) {
        vector<T> r(sz(v)+1, id); id16 (i, sz(v)) r[i] = op(v[i], r[i+1]); return r;
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
    tree(const vector<E>& id18) : V(sz(id18) + 1), edge_list(id18) {
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
        vector<E> id18(t.V - 1);
        re(id18);
        for (int i = 0; i < t.V - 1; i++) id18[i].i = i;
        t = tree<E>(id18);
    }
    friend void pr(const tree& t) { pr("{V=", t.V, " ", t.edge_list, "}"); }

    vb erased;
    void erase(int u) { erased[u] = true; }

    mutable vi subt_sz;
    void calc_subt_sz(int u, bool id5, int p) const {
        subt_sz[u] = 1;
        for (int v : nbrs[u]) if (v != p && (!id5 || !erased[v])) {
            calc_subt_sz(v, id5, u);
            subt_sz[u] += subt_sz[v];
        }
    }

    vi centroids(int r = 0, bool id5 = 1) const {
        calc_subt_sz(r, id5, -1);
        int c = r, p = -1;
        FIND: for (int u : nbrs[c]) if (!id5 || !erased[u]) {
            if (subt_sz[u] < subt_sz[c] && 2 * subt_sz[u] >= subt_sz[r]) {
                p = c, c = u; goto FIND;
            }
        }
        return subt_sz[c] * 2 == subt_sz[r] ? vi{c,p} : vi{c};
    }
};




template<typename E> struct id20 {
    tree<E> t;
    int root;
    vi _par, _depth, _subt_sz;

    const vi& nbrs(int v) const { return t.nbrs[v]; }
    int par(int v) const { return _par[v]; }
    int depth(int v) const { return _depth[v]; }
    int subt_sz(int v) const { return _subt_sz[v]; }

    struct visit { int node, depth, index; };
    struct adder {
        visit operator()(const visit& a, const visit& b) const {
            if (a.depth != b.depth) return a.depth < b.depth ? a : b;
            return a.index > b.index ? a : b;
        }
    } vv;

    vector<visit> euler_tour;
    vi first_visit;
    id0<visit, adder> table;

    id20() {}
    id20(tree<E> _t, int _root = 0) : t(_t), root(_root) {
        _par.resz(t.V,-1), _depth.resz(t.V), _subt_sz.resz(t.V), first_visit.resz(t.V);
        auto dfs = [&](auto& self, int loc) -> void {
            _subt_sz[loc] = 1;
            first_visit[loc] = sz(euler_tour);
            euler_tour.pb({loc, _depth[loc], sz(euler_tour)});

            for (int nbr : this->nbrs(loc)) if (nbr != this->par(loc)) {
                _par[nbr] = loc;
                _depth[nbr] = this->depth(loc) + 1;
                self(self, nbr);
                _subt_sz[loc] += this->subt_sz(nbr);
                euler_tour.push_back({loc, this->depth(loc), sz(euler_tour)});
            }
        };
        dfs(dfs, root);
        table = id0<visit, adder>(euler_tour, vv);
    }

    int lca(int u, int v) const {
        u = first_visit[u], v = first_visit[v];
        if (u > v) swap(u, v);
        return table(u, v + 1).node;
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
        return euler_tour[table(first_visit[u], first_visit[v]).index + 1].node;
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




struct index_t {
    int i; explicit operator int() { return i; }
    friend bool operator < (const index_t& a, const index_t& b) { return a.i < b.i; }
    friend bool operator > (const index_t& a, const index_t& b) { return a.i > b.i; }
    index_t operator + (int b) { return {i+b}; }
    index_t operator - (int b) { return {i-b}; }
    int operator - (index_t b) { return i-b.i; }
    friend ostream& operator << (ostream& o, index_t a) { o << a.i; return o; }
};
using range_t = pair<index_t, index_t>;
using ranges = vector<range_t>;
template<typename E> struct id19 : id20<E> {
    
    struct heavy_path { index_t index; int htop, hbot; };
    vector<heavy_path> hld;
    vi preorder;

    int par(int v) const { return this->_par[v]; }
    int depth(int v) const { return this->_depth[v]; }
    int subt_sz(int v) const { return this->_subt_sz[v]; }

    id19() {}
    id19(tree<E> _t) : id20<E>(_t) {
        hld.resz(this->t.V), preorder.resz(this->t.V);
        auto dfs = [&](auto& self, int loc, index_t index, int htop) -> index_t {
            hld[loc] = {index, htop, -1};
            preorder[index.i++] = loc;
            const vi& nbrs = this->nbrs(loc);
            vi::const_iterator it = max_element(all(nbrs), [&](int u, int v) {
                if (u == v) return false;
                if (u == this->par(loc)) return true;
                if (v == this->par(loc)) return false;
                return this->subt_sz(u) < this->subt_sz(v);
            });
            if (it != nbrs.end() && *it != this->par(loc)) {
                index = self(self, *it, index, htop);
            } else {
                hld[htop].hbot = loc;
            }
            for (int nbr : nbrs) if (nbr != this->par(loc) && nbr != *it) {
                index = self(self, nbr, index, nbr);
            }
            return index;
        };
        dfs(dfs, 0, index_t{0}, 0);
    }

    index_t index(int v) const { return hld[v].index; }
    int at_index(index_t i) const { return preorder[int(i)]; }
    int htop(int v) const { return hld[v].htop; }
    int hbot(int v) const { return hld[htop(v)].hbot; }

    range_t hpath(int v) const {
        return make_pair(index(htop(v)), index(hbot(v)) + 1);
    }
    range_t subtree(int v) const {
        return {index(v), index(v) + subt_sz(v)};
    }

    

    index_t edge_index(int eid) const {
        const E& e = this->t.edges[eid];
        return index(depth(e.u) > depth(e.v) ? e.u : e.v);
    }

    int kth_ancestor(int u, int k) const {
        assert(0 <= k && k <= depth(u));
        while (true) {
            if (k <= depth(u) - depth(htop(u)))
                return at_index(index(u) - k);
            k -= depth(u) - depth(htop(u)) + 1;
            u = par(htop(u));
        }
    }

    

    int kth_step(int u, int v, int k) const {
        int w = this->lca(u, v), d = this->dist(u, v);
        assert(d >= k);
        return k <= depth(u) - depth(w) ? kth_ancestor(u, k) : kth_ancestor(v, d - k);
    }

    void decompose_vertical_path(int u, int v, bool up, ranges& res) const {
        size_t bef = res.size();
        for (assert(depth(u) >= depth(v)); true; u = par(u)) {
            int w = depth(htop(u)) >= depth(v) ? htop(u) : v;
            res.emplace_back(index(up ? u : w), index(up ? w : u));
            if ((u = w) == v) break;
        }
        if (!up) reverse(res.begin() + bef, res.end());
    }

    ranges decompose_path(int u, int v, bool id1) const {
        ranges res;
        int w = this->lca(u, v);
        bool id9 = id1 && u!=w && htop(w) == htop(this->first_step(w, u)),
             id12 = id1 ^ id9;
        if (u != w || id9)
            decompose_vertical_path(u, id9 ? w : this->first_step(w, u), true, res);
        if (v != w || id12)
            decompose_vertical_path(v, id12 ? w : this->first_step(w, v), false, res);
        return res;
    }

    template<typename FOR, typename FORd>
    void for_each(int u, int v, bool id1, FOR f, FORd fd) const {
        for (range_t r : decompose_path(u, v, id1)) {
            if (r.f > r.s) fd(r.s, r.f + 1);
            else f(r.f, r.s + 1);
        }
    }
    template<typename FOR>
    void id11(int u, int v, bool id1, FOR f) const {
        assert(this->lca(u, v) == u);
        auto fd = [&f](index_t i, index_t j){ assert(j - i <= 1); return f(i, j); };
        for_each(u, v, id1, f, fd);
    }
    template<typename FORd>
    void id8(int u, int v, bool id1, FORd fd) const {
        assert(this->lca(u, v) == v);
        auto f = [&fd](index_t i, index_t j){ assert(j - i <= 1); return fd(i, j); };
        for_each(u, v, id1, f, fd);
    }
    template<typename FOR>
    void id13(int u, int v, bool id1, FOR f) const {
        for_each(u, v, id1, f, f);
    }

    template<typename T, typename OP, typename FOLDL, typename FOLDR>
    T accumulate(int u, int v, bool id1, T iv, OP lplus, FOLDL fl, FOLDR fr) const {
        for (range_t r : decompose_path(u, v, id1)) {
            if (r.f > r.s) iv = lplus(iv, fr(r.s, r.f + 1));
            else iv = lplus(iv, fl(r.f, r.s + 1));
        }
        return iv;
    }
    template<typename T, typename OP, typename FOLDL>
    T id4(int u, int v, bool id1, T iv, OP lplus, FOLDL fl) const {
        assert(this->lca(u, v) == u);
        auto fr = [&fl](index_t i, index_t j){ assert(j - i <= 1); return fl(i, j); };
        return accumulate(u, v, id1, iv, lplus, fl, fr);
    }
    template<typename T, typename OP, typename FOLDR>
    T id10(int u, int v, bool id1, T iv, OP lplus, FOLDR fr) const {
        assert(this->lca(u, v) == v);
        auto fl = [&fr](index_t i, index_t j){ assert(j - i <= 1); return fr(i, j); };
        return accumulate(u, v, id1, iv, lplus, fl, fr);
    }
    template<typename T, typename OP, typename FOLD>
    T id7(int u, int v, bool id1, T iv, OP lplus, FOLD f) const {
        return accumulate(u, v, id1, iv, lplus, f, f);
    }

    

    

    static constexpr range_t EMPTY{index_t{-1}, index_t{-1}};
    range_t intersect(range_t r, int u, int v) {
        int ru = at_index(r.f), rv = at_index(r.s - 1), uvl = this->lca(u, v);
        assert(r.f < r.s && htop(ru) == htop(rv));
        if (depth(rv) < depth(uvl)) return EMPTY;
        if (depth(ru) < depth(uvl)) { assert(htop(uvl) == htop(ru)); ru = uvl; }
        if (!this->uv_path_has_w(u, rv, ru)) return {index(this->lca(u, rv)), index(ru)};
        if (!this->uv_path_has_w(v, rv, ru)) return {index(ru), index(this->lca(v, rv))};
        return this->uv_path_has_w(u, v, ru) ? range_t{index(ru),index(ru)} : EMPTY;
    }

    ranges decompose_subtree(int u, int r) const {
        if (u == r) return {{index_t{0}, index_t{this->t.V}}};
        int w = this->first_step(u, r);
        if (w == par(u)) return {{index(u), index(u) + subt_sz(u)}};
        return {{index_t{0}, index(w)}, {index(w) + subt_sz(w), index_t{this->t.V}}};
    }
    template<typename T, typename OP, typename FOLD>
    T id17(int u, int r, T iv, OP lplus, FOLD f) const {
        ranges st = decompose_subtree(u, r);
        return std::accumulate(all(st), iv, [&](T v, pii p){ return lplus(v, f(p.f, p.s)); });
    }
};




template<typename E> struct id22 {
    const id19<E>& t;
    vi label, above; vb interesting; int root, L;

    id22(const id19<E>& _t, vi id21,
            int _root = -1) : t(_t), label(_t.t.V, -1), interesting(_t.t.V, 0), root(_root), L(0) {
        sort_by(id21, t.index(a) < t.index(b));
        unique(all(id21));
        for (int i = 0; i < sz(id21); i++) {
            interesting[id21[i]] = true;
            if (i) interesting[t.lca(id21[i-1], id21[i])] = true;
        }
        if (~root) interesting[root] = true;

        auto fill = [&](auto& self, int u, int p, int last) -> void {
            if (interesting[u]) {
                if (~last) {
                    int top = t.first_step(last, u);
                    if (~root) {
                        for (int v = u; t.depth(v) >= t.depth(top); v = t.par(v))
                            label[v] = L;
                        above.pb(label[last]), L++;
                    } else {
                        if (top != u) {
                            for (int v = t.par(u); t.depth(v) >= t.depth(top); v = t.par(v))
                                label[v] = L;
                            above.pb(label[last]), L++;
                        }
                        above.pb(label[t.par(u)]), label[u] = L++;
                    }
                } else above.pb(-1), label[u] = L++;
                last = u;
            }
            for (int v : t.nbrs(u)) if (v != p) self(self, v, u, last);
        };
        fill(fill, ~root ? root : 0, -1, -1);
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

    

    id19<E> hld(tr);

    vi tol(N), ops(M); re(tol, ops);

    vb gone(N, false);

    const int BLOCK = 2500;
    for (int bs = 0; bs < M; bs += BLOCK) {
        vi id6(N);
        id16 (_i, N) {
            int u = hld.at_index({_i});
            id6[u] = gone[u];
            trav (v, tr.nbrs[u]) if (hld.depth(v) > hld.depth(u)) {
                id6[u] += id6[v];
            }
        }
        auto allow = [&](int u) { return tol[u] - id6[u]; };

        vi queried{0};
        vb wquery(N); wquery[0] = 1;
        FOR (op, bs, min(bs + BLOCK, M)) {
            int u = abs(ops[op]) - 1;
            queried.pb(u);
            wquery[u] = 1;
        }
        dedup(queried);

        id22<E> ctr(hld, queried, -1);

        int ans = 0;

        vvi _groups(ctr.L);
        id14 (u, N) {
            if (ctr.label[u] == -1) { if (!gone[u] && allow(u) < 0) ans++; }
            else if (!gone[u] || wquery[u]) _groups[ctr.label[u]].pb(allow(u));
        }

        vvpii groups(ctr.L);
        id14 (u, ctr.L) {
            sort(all(_groups[u]));
            for (int i = 0, j = 0; i < sz(_groups[u]); i = j) {
                while (j < sz(_groups[u]) && _groups[u][i] == _groups[u][j]) j++;
                groups[u].eb(_groups[u][i], j - i);
            }
        }

        vi id15(N, -1);
        trav (u, queried) {
            int ug = ctr.label[u];
            auto it = lb(all(groups[ug]), mp(allow(u), -1));
            if (gone[u]) it->s--;
            id15[u] = it - groups[ug].begin();
        }

        vi diff(ctr.L), cloc(ctr.L);
        auto adjust = [&](int g) {
            int &i = cloc[g], gsz = sz(groups[g]);
            while (i < gsz && groups[g][i].f < diff[g]) ans += groups[g][i++].s;
            while (i > 0 && groups[g][i-1].f >= diff[g]) ans -= groups[g][--i].s;
        };
        id14 (u, ctr.L) adjust(u);

        FOR (op, bs, min(bs + BLOCK, M)) {
            int u = abs(ops[op]) - 1, ug = ctr.label[u], gi = id15[u];
            if (!gone[u]) {
                gone[u] = 1;
                if (gi < cloc[ug]) ans--;
                groups[ug][gi].s--;
                ctr.id3(u, 0, 1, [&](int g) { diff[g]++, adjust(g); });
                

            } else {
                gone[u] = 0;
                if (gi < cloc[ug]) ans++;
                groups[ug][gi].s++;
                ctr.id3(u, 0, 1, [&](int g) { diff[g]--, adjust(g); });
                

            }
            if (op) pr(" ");
            pr(ans);
        }
    }
    ps();

    

    return 0;
}
