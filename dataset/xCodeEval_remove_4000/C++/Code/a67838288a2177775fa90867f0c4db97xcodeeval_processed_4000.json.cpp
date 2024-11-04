
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
    template<class T> void re(vector<T>& a) { id10(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { id10(i,SZ) re(a[i]); }
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
        vector<T> r(sz(v)+1, id); id10 (i, sz(v)) r[i+1] = op(r[i], v[i]); return r;
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





struct frac {
    ll n, d;
    frac(ll _n, ll _d = 1) : n(_n), d(_d) {
        assert(n != 0 || d != 0);
        if (d < 0) { n *= -1; d *= -1; }
        ll g = __gcd(abs(n), d);
        n /= g;
        d /= g;
    }
    frac& simp() {
        return *this;
        

        

    }
    explicit operator double() const { return double(n)/d; }
    friend ostream& operator << (ostream& o, const frac& f) {
        return o << f.n << "/" << f.d;
    }

    friend bool operator < (const frac& a, const frac& b) {
        return a.n * b.d < b.n * a.d;
    }
    friend bool operator <= (const frac& a, const frac& b) {
        return a.n * b.d <= b.n * a.d;
    }
    friend bool operator == (const frac& a, const frac& b) {
        return a.n * b.d == b.n * a.d;
    }
    friend bool operator != (const frac& a, const frac& b) {
        return a.n * b.d != b.n * a.d;
    }
    friend bool operator >= (const frac& a, const frac& b) {
        return a.n * b.d >= b.n * a.d;
    }
    friend bool operator > (const frac& a, const frac& b) {
        return a.n * b.d > b.n * a.d;
    }

    friend frac min(const frac a, const frac b) { return a <= b ? a : b; }
    friend frac max(const frac a, const frac b) { return a >= b ? a : b; }

    frac& operator += (const frac& b) {
        if (d == b.d) { n+=b.n; return *this; }
        return *this = frac(n*b.d+b.n*d, d*b.d);
    }
    frac& operator -= (const frac& b) {
        if (d == b.d) { n-=b.n; return *this; }
        return *this = frac(n*b.d-b.n*d, d*b.d);
    }
    frac& operator *= (const frac& b) { return *this = frac(n*b.n, d*b.d); }
    frac& operator /= (const frac& b) { return *this = frac(n*b.d, d*b.n); }
    friend frac operator + (const frac& a, const frac& b) { return frac(a) += b; }
    friend frac operator - (const frac& a, const frac& b) { return frac(a) -= b; }
    friend frac operator * (const frac& a, const frac& b) { return frac(a) *= b; }
    friend frac operator / (const frac& a, const frac& b) { return frac(a) /= b; }

    

    vll to_cont() const {
        if (d == 0) return { id4 };
        vll cont;
        for (ll n = this->n, d = this->d; ; swap(n, d)) {
            ll f = (n >= 0 ? n : n - d + 1) / d;
            cont.push_back(f);
            n -= f * d;
            if (n == 0) break;
        }
        return cont;
    }

    static frac from_cont(const vll& cont) {
        ll n = 1, d = 0;
        for (int i = int(cont.size()) - 1; i >= 0; i--) {
            swap(n, d);
            n += d * cont[i];
        }
        return { n, d };
    }

    

    friend frac best_in(const frac x, const frac y) {
        assert(x < y);

        vll x1 = x.to_cont(), y1 = y.to_cont();
        vll x2 = x1; x2.back()--; x2.push_back(1);
        vll y2 = y1; y2.back()--; y2.push_back(1);

        auto z = [](const vll& a, const vll& b) {
            vll c;
            for (int i = 0; ; i++) {
                ll ai = i < a.size() ? a[i] : id4;
                ll bi = i < b.size() ? b[i] : id4;
                if (ai != bi) {
                    c.push_back(min(ai, bi) + 1);
                    return from_cont(c);
                }
                c.push_back(ai);
            }
        };

        frac ans = { 1, 0 };
        for (const frac f : {z(x1, y1), z(x1, y2), z(x2, y1), z(x2, y2)}) {
            if (x < f && f < y && (ans.d == 0 || f.d < ans.d))
                ans = f;
        }
        return ans;
    }
};




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
    vector<E> edges;
    vector<vector<E>> adj;

    vi subt_sz;
    vb erased;

    tree() {}
    tree(int _V) : V(_V) {
        edges.resz(V-1);
        nbrs.resz(V), adj.resz(V), subt_sz.resz(V), erased.resz(V);
    }
    tree(const vector<E>& __edges) : tree(sz(__edges) + 1) {
        edges = __edges;
        init();
    }

    void init() {
        id10 (i, sz(edges)) {
            auto& e = edges[i]; e.i = i;
            assert(0 <= e.u && e.u < V && 0 <= e.v && e.v < V);
            adj[e.u].pb(e), nbrs[e.u].pb(e.v);
            adj[e.v].pb(e), nbrs[e.v].pb(e.u);
        }
    }

    friend void re(tree& t) { re(t.edges); t.init(); }
    friend void pr(const tree& t) { pr("{V=", t.V, " ", t.edges, "}"); }

    void erase(int v) { erased[v] = true; }

    void calc_subt_sz(int v, int p = -1) {
        subt_sz[v] = 1;
        trav (e, adj[v]) {
            int u = e[v];
            if (erased[u] || u == p) continue;
            calc_subt_sz(u, v);
            subt_sz[v] += subt_sz[u];
        }
    }

    int centroid(int v) {
        calc_subt_sz(v);
        int c = v;
        FIND: trav (e, adj[c]) {
            int u = e[c];
            if (!erased[u] && subt_sz[u] < subt_sz[c] && 2 * subt_sz[u] >= subt_sz[v]) {
                c = u; goto FIND;
            }
        }
        return c;
    }
};




template<typename E> struct id13 {
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

    id13() {}
    id13(tree<E> _t, int _root = 0) : t(_t), root(_root) {
        _par.resz(t.V), _depth.resz(t.V), _subt_sz.resz(t.V), first_visit.resz(t.V);
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
        return dist(u, v) == (dist(u, w) + dist(w, v));
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




template<typename E> struct id12 : id13<E> {
    struct heavy_path { int index, htop, hbot; };
    vector<heavy_path> hld;
    vi preorder;

    int par(int v) const { return this->_par[v]; }
    int depth(int v) const { return this->_depth[v]; }
    int subt_sz(int v) const { return this->_subt_sz[v]; }

    id12() {}
    id12(tree<E> _t) : id13<E>(_t) {
        hld.resz(this->t.V), preorder.resz(this->t.V);
        auto dfs = [&](auto& self, int loc, int index, int htop) -> int {
            preorder[index] = loc;
            hld[loc] = {index++, htop, -1};
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
        dfs(dfs, 0, 0, 0);
    }

    int index(int v) const { return hld[v].index; }
    int at_index(int i) const { return preorder[i]; }
    pii subtree(int v) const { return {index(v), index(v) + subt_sz(v)}; }

    int htop(int v) const { return hld[v].htop; }
    int hbot(int v) const { return hld[htop(v)].hbot; }
    pii hpath(int v) const {
        return make_pair(index(htop(v)), index(hbot(v)) + 1);
    }

    int edge_index(int eid) const {
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

    void decompose_vertical_path(int u, int v, bool up, vpii& res) const {
        size_t bef = res.size();
        for (assert(depth(u) >= depth(v)); true; u = par(u)) {
            int w = depth(htop(u)) >= depth(v) ? htop(u) : v;
            res.emplace_back(index(up ? u : w), index(up ? w : u));
            if ((u = w) == v) break;
        }
        if (!up) reverse(res.begin() + bef, res.end());
    }

    vpii decompose_path(int u, int v, bool id1) const {
        vpii res;
        int w = this->lca(u, v);
        if (u != w) decompose_vertical_path(u, this->first_step(w, u), true, res);
        if (id1) res.emplace_back(index(w), index(w));
        if (v != w) decompose_vertical_path(v, this->first_step(w, v), false, res);
        return res;
    }

    template<typename FOR, typename FORd>
    void for_each(int u, int v, bool id1, FOR f, FORd fd) const {
        for (pii r : decompose_path(u, v, id1)) {
            if (r.f > r.s) fd(r.s, r.f + 1);
            else f(r.f, r.s + 1);
        }
    }
    template<typename FOR>
    void id8(int u, int v, bool id1, FOR f) const {
        assert(this->lca(u, v) == u);
        auto fd = [&f](int i, int j){ assert(j - i <= 1); return f(i, j); };
        for_each(u, v, id1, f, fd);
    }
    template<typename FORd>
    void id6(int u, int v, bool id1, FORd fd) const {
        assert(this->lca(u, v) == v);
        auto f = [&fd](int i, int j){ assert(j - i <= 1); return fd(i, j); };
        for_each(u, v, id1, f, fd);
    }
    template<typename FOR>
    void id9(int u, int v, bool id1, FOR f) const {
        for_each(u, v, id1, f, f);
    }

    template<typename T, typename OP, typename FOLDL, typename FOLDR>
    T accumulate(int u, int v, bool id1, T iv, OP lplus, FOLDL fl, FOLDR fr) const {
        for (pii r : decompose_path(u, v, id1)) {
            if (r.f > r.s) iv = lplus(iv, fr(r.s, r.f + 1));
            else iv = lplus(iv, fl(r.f, r.s + 1));
        }
        return iv;
    }
    template<typename T, typename OP, typename FOLDL>
    T id3(int u, int v, bool id1, T iv, OP lplus, FOLDL fl) const {
        assert(this->lca(u, v) == u);
        auto fr = [&fl](int i, int j){ assert(j - i <= 1); return fl(i, j); };
        return accumulate(u, v, id1, iv, lplus, fl, fr);
    }
    template<typename T, typename OP, typename FOLDR>
    T id7(int u, int v, bool id1, T iv, OP lplus, FOLDR fr) const {
        assert(this->lca(u, v) == v);
        auto fl = [&fr](int i, int j){ assert(j - i <= 1); return fr(i, j); };
        return accumulate(u, v, id1, iv, lplus, fl, fr);
    }
    template<typename T, typename OP, typename FOLD>
    T id5(int u, int v, bool id1, T iv, OP lplus, FOLD f) const {
        return accumulate(u, v, id1, iv, lplus, f, f);
    }

    vpii decompose_subtree(int u, int r) const {
        if (u == r) return {{0, this->t.V}};
        int w = this->first_step(u, r);
        if (w == par(u)) return {{index(u), index(u) + subt_sz(u)}};
        return {{0, index(w)}, {index(w) + subt_sz(w), this->t.V}};
    }
    template<typename T, typename OP, typename FOLD>
    T id11(int u, int r, T iv, OP lplus, FOLD f) const {
        vpii st = decompose_subtree(u, r);
        return std::accumulate(all(st), iv, [&](T v, pii p){ return lplus(v, f(p.f, p.s)); });
    }
};



frac inf = { 20001, 1 };

struct suit {
    int u, v, c; frac tu, tv;
    frac loc(frac t) const {
        return u + c * (t - tu);
        
    }
    double loc(double t) const {
        return u + c * (t - double(tu));
    }
    friend frac hit(const suit& a, const suit& b) {
        frac t0 = max(a.tu, b.tu), t1 = min(a.tv, b.tv);
        if (t0 > t1) return inf;

        frac a0 = a.loc(t0).simp(), a1 = a.loc(t1).simp(),
             b0 = b.loc(t0).simp(), b1 = b.loc(t1).simp();

        if (a0 == b0) return t0;
        if ((a0 < b0 && a1 >= b1) || (a0 > b0 && a1 <= b1))
            return t0 + (b0 - a0) / (a.c - b.c);
        return inf;
    }
    friend ostream& operator<<(ostream& o, const suit& s) {
        o << "{" << s.u << "(" << s.tu << ") =" << s.v
            << "=> " << s.v << "(" << s.tv << ")";
        return o;
    }
};

int main() {
    setIO();

    using E = wedge<>;
    int N, M; re(N, M); tree<E> tr(N); re(tr);
    id12<E> hld(tr);

    vector<vector<suit>> lines(N);
    id10 (m, M) {
        int t, c, u, v; re(t, c, u, v); --v, --u;

        hld.id9(u, v, false, [&](int i, int j) {
            

            int pu = hld.at_index(i), pv = hld.at_index(j-1);
            assert(hld.htop(pu) == hld.htop(pv));
            int li = hld.htop(pu);

            int du = hld.dist(u, pu), dv = hld.dist(u, pv);
            if (du > dv) { swap(pu, pv); swap(du, dv); }

            int pt = hld.depth(pu) < hld.depth(pv) ? pu : pv;
            bool down = hld.dist(u, hld.par(pt)) < hld.dist(u, pt);

            suit s {
                    hld.depth(pu) - hld.depth(li) - down,
                    hld.depth(pv) - hld.depth(li) - !down,
                    c, t+frac{du-down,c}, t+frac{dv+!down, c}
            };
            if (s.u > s.v) s.c *= -1;
            lines[li].pb(s);
        });

        bool id14 = false;
        int lca = hld.lca(u, v), li = hld.htop(lca);
        if (u != lca && hld.htop(hld.first_step(lca, u)) == li) id14 = true;
        if (v != lca && hld.htop(hld.first_step(lca, v)) == li) id14 = true;
        if (!id14) {
            int lloc = hld.depth(lca) - hld.depth(li);
            frac tl = t + frac{hld.depth(u) - hld.depth(lca), c};
            suit s{lloc, lloc, c, tl, tl};
            lines[li].pb(s);
        }
    }

    frac ans = inf;
    trav (line, lines) {
        const int L = sz(line);

        vi ev(2 * L);
        id10 (i, sz(ev)) ev[i] = i;

        id10 (i, L) assert(line[i].tu <= line[i].tv);

        sort(all(ev), [&](int a, int b) {
            frac ta = a&1 ? line[a/2].tv : line[a/2].tu;
            frac tb = b&1 ? line[b/2].tv : line[b/2].tu;
            if (ta != tb) return ta < tb;
            return (a&1) < (b&1);
        });

        frac t = 0;
        auto cmp = [&](int i, int j) {
            frac il = line[i].loc(t);
            frac jl = line[j].loc(t);
            bool res;
            if (il != jl) res = il < jl;
            else res = line[i].u < line[j].u;
            return res;
        };
        set<int, decltype(cmp)> active(cmp);
        trav (ei, ev) {
            const suit& s = line[ei/2];
            t = ei&1 ? s.tv : s.tu;
            if (t >= ans) break;
            if (ei&1) { 

                auto it = active.find(ei/2);
                assert(it != active.end());
                active.erase(it++);
                if (it != active.end() && it != active.begin())
                    ckmin(ans, hit(line[*it], line[*prev(it)]));
            } else { 

                auto it = active.lb(ei/2);
                if (it != active.end()) ckmin(ans, hit(s, line[*it]));
                if (it != active.begin()) ckmin(ans, hit(s, line[*prev(it)]));
                if (t >= ans) break;
                active.insert(it, ei/2);
            }
        }
    }
    if (ans != inf) ps(double(ans)); else ps(-1);

    

    return 0;
}

