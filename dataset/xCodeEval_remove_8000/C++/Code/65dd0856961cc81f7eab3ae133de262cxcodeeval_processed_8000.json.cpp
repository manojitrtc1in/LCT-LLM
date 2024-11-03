
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
    template<class T> void re(vector<T>& a) { id11(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { id11(i,SZ) re(a[i]); }
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
        vector<T> r(sz(v)+1, id); id11 (i, sz(v)) r[i+1] = op(r[i], v[i]); return r;
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





template<typename T, typename U, typename TT, typename UU, typename UT>
struct id13 {
    int SZ;
    T tid; U uid; TT tt; UU uu; UT ut;

    

    vector<T> table;
    vector<U> ops;

    inline T& val(int i) { return table[i]; }
    inline U&  op(int i) { return ops[i]; }

    id13() {}
    id13(int _SZ, T _tid, U _uid, TT _tt, UU _uu, UT _ut)
            : tid(_tid), uid(_uid), tt(_tt), uu(_uu), ut(_ut) {
        init(_SZ);
    }
    void init(int _SZ) {
        SZ = _SZ;
        table.resize(2 * SZ, tid);
        ops.resize(SZ, uid);
    }
    template<typename L> void id17(L create) {
        id11 (i, SZ) val(SZ + i) = create(i);
        FORd (i, 1, SZ) val(i) = tt(val(2 * i), val(2 * i + 1));
    }

    void _apply(int i, const U &u) {
        val(i) = ut(u, val(i));
        if (i < SZ) op(i) = uu(u, op(i));
    }
    void _rebuild(int i) {
        for (i /= 2; i; i /= 2)
            val(i) = ut(op(i), tt(val(2 * i), val(2 * i + 1)));
    }
    void _propagate(int i) {
        for (int j = 31 - __builtin_clz(i); j > 0; j--) {
            int k = i >> j;
            if (memcmp(&uid, &op(k), sizeof(U))) {
                _apply(2 * k, op(k));
                _apply(2 * k + 1, op(k));
                op(k) = uid;
            }
        }
    }

    

    void replace(int i, T v) {
        i += SZ;
        _propagate(i);
        table[i] = v;
        _rebuild(i);
    }

    

    void operator()(int i, int j, U op) {
        i += SZ, j += SZ;
        _propagate(i); if (j-1 != i) _propagate(j-1);
        for (int l = i, r = j; l < r; l /= 2, r /= 2) {
            if (l&1) _apply(l++, op);
            if (r&1) _apply(--r, op);
        }
        _rebuild(i); if (j-1 != i) _rebuild(j-1);
    }

    

    T operator()(int i, int j) {
        i += SZ, j += SZ;
        _propagate(i); if (j-1 != i) _propagate(j-1);
        T left = tid, right = tid;
        for (; i < j; i /= 2, j /= 2) {
            if (i&1) left = tt(left, val(i++));
            if (j&1) right = tt(val(--j), right);
        }
        return tt(left, right);
    }
    T operator[](int i) { return (*this)(i, i+1); }
};





using v_t = int;
using vv_t = ll;
template<v_t MOD> struct modnum {
    v_t v;
    modnum() : v(0) {}
    modnum(vv_t _v) : v(_v % MOD) { if (v < 0) v += MOD; }
    explicit operator v_t() const { return v; }
    friend istream& operator >> (istream& i, modnum& n) { vv_t w; i >> w; n = modnum(w); return i; }
    friend ostream& operator << (ostream& o, const modnum& n) { return o << n.v; }

    friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {

        return x % m;

        

        unsigned x_high = x >> 32, x_low = (unsigned) x, quot, rem;
        asm("divl %4\n"
                : "=a" (quot), "=d" (rem)
                : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }

    modnum& operator += (const modnum& o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    modnum& operator -= (const modnum& o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    modnum& operator *= (const modnum& o) { v = fast_mod(vv_t(v) * o.v); return *this; }
    modnum operator - () { modnum res; if (v) res.v = MOD - v; return res; }
    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }

    modnum pow(vv_t e) const {
        if (e < 0) return 1 / this->pow(-e);
        if (e == 0) return 1;
        if (e & 1) return *this * this->pow(e-1);
        return (*this * *this).pow(e/2);
    }

    modnum inv() const {
        v_t g = MOD, x = 0, y = 1;
        for (v_t r = v; r != 0; ) {
            v_t q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }

        assert(g == 1);
        assert(y == MOD || y == -MOD);
        return x < 0 ? x + MOD : x;
    }
    modnum& operator /= (const modnum& o) { return (*this) *= o.inv(); }
    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= modnum(b); }

    static constexpr v_t totient() {
        v_t tot = MOD, tmp = MOD;
        for (v_t p = 2; p * p <= tmp; p++) if (tmp % p == 0) {
            tot = tot / p * (p - 1);
            while (tmp % p == 0) tmp /= p;
        }
        if (tmp > 1) tot = tot / tmp * (tmp - 1);
        return tot;
    }

    static v_t primitive_root() {
        if (MOD == 1) return 0;
        if (MOD == 2) return 1;

        v_t tot = totient(), tmp = tot;
        vi tot_pr;
        for (v_t p = 2; p * p <= tmp; p++) if (tot % p == 0) {
            tot_pr.push_back(p);
            while (tmp % p == 0) tmp /= p;
        }
        if (tmp > 1) tot_pr.push_back(tmp);

        for (v_t r = 2; r < MOD; r++) if (__gcd(r, MOD) == 1) {
            bool root = true;
            for (v_t p : tot_pr) root &= modnum(r).pow(tot / p) != 1;
            if (root) return r;
        }
        assert(false);
    }

    static modnum generator() { static modnum g = primitive_root(); return g; }
    static v_t discrete_log(modnum v) {
        static const v_t M = ceil(sqrt(MOD));
        static unordered_map<v_t, v_t> table;
        if (table.empty()) {
            modnum e = 1;
            for (v_t i = 0; i < M; i++) { table[e.v] = i; e *= generator(); }
        }
        static modnum f = generator().pow(totient() - M);

        for (v_t i = 0; i < M; i++) {
            if (table.count(v.v)) return table[v.v] + i * M;
            v *= f;
        }
        assert(false);
    }

    static modnum unity_root(int deg) {
        assert(totient() % deg == 0);
        return generator().pow(totient() / deg);
    }

    static modnum unity_root(int deg, int pow) {
        static vector<modnum> table{ 0, 1 };
        while (sz(table) <= deg) {
            modnum w = unity_root(sz(table));
            for (int i = sz(table)/2, s = sz(table); i < s; i++) {
                table.push_back(table[i]);
                table.push_back(table[i] * w);
            }
        }
        return table[deg + (pow < 0 ? deg + pow : pow)];
    }

    static modnum fact(int n) {
        static vector<modnum> fact = { 1 };
        for (assert(n >= 0); fact.size() <= n; )
            fact.push_back(fact.back() * fact.size());
        return fact[n];
    }

    static modnum finv(int n) {
        static vector<modnum> finv = { 1 };
        for (assert(n >= 0); finv.size() <= n; )
            finv.push_back(finv.back() / finv.size());
        return finv[n];
    }

    static modnum ncr(int n, int r) {
        assert(n >= 0);
        if (r < 0 || n < r) return 0;
        return fact(n) * finv(r) * finv(n - r);
    }
};


using mn = modnum<int(1e9 + 7)>;
using vmn = vector<mn>;
using vvmn = vector<vmn>;



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




template<typename W=monostate> struct wedge {
    int u, v, i; W w;
    wedge<W>(int _u=-1, int _v=-1, int _i=-1, W _w = W{}) : u(_u), v(_v), i(_i), w(_w) {}
    int operator[](int loc) const { return u ^ v ^ loc; }
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

    vi preorder, id12;

    vb erased;
    void erase(int u) { erased[u] = true; }

    tree(int _V = 0) : V(_V) {}
    tree(const vector<E>& id15, int _root = 0) : edge_list(id15),
            V(sz(id15) + 1), root(_root), edges(V),
            nbrs(V), children(V), par(V, -1), depth(V), subt_sz(V), erased(V) {
        for (E& e : edge_list) {
            assert(0 <= e.u && e.u < V && 0 <= e.v && e.v < V);
            nbrs[e.u].push_back(e.v);
            nbrs[e.v].push_back(e.u);
            edges[e.u].pb(e);
            edges[e.v].pb(e);
        }

        init(root);
        build_preorder(root);
        id12 = preorder;
        reverse(all(id12));
    }

    void init(int u) {
        subt_sz[u] = 1;
        for (int v : nbrs[u]) if (v != par[u]) {
            par[v] = u;
            depth[v] = depth[u] + 1;
            init(v);
            subt_sz[u] += subt_sz[v];

            children[u].pb(v);
            if (subt_sz[v] > subt_sz[children[u].front()])
                swap(children[u].front(), children[u].back());
        }
    }

    void build_preorder(int u) {
        preorder.pb(u);
        for (int v : children[u]) build_preorder(v);
    }

    template<INPUT_FORMAT FMT = EDGE_LIST, bool FIRST_INDEX = 1>
    friend void re(tree& t) {
        assert(t.V > 0);
        vector<E> id15(t.V - 1);
        for (int i = 0; i < t.V - 1; i++) {
            E& e = id15[i];
            if (FMT == EDGE_LIST) re<FIRST_INDEX>(e);
            else re<FIRST_INDEX>(e, i + 1);
            e.i = i;
        }
        t = tree<E>(id15);
    }
    friend void pr(const tree& t) { pr("{V=", t.V, " ", t.edge_list, "}"); }

    mutable vi __subt_sz;
    void __calc_subt_sz(int u, bool id3, int p) const {
        __subt_sz[u] = 1;
        for (int v : nbrs[u]) if (v != p && (!id3 || !erased[v])) {
            __calc_subt_sz(v, id3, u);
            __subt_sz[u] += __subt_sz[v];
        }
    }

    vi centroids(int r = 0, bool id3 = 1) const {
        if (__subt_sz.empty()) __subt_sz.resz(V);
        __calc_subt_sz(r, id3, -1);
        int c = r, p = -1;
        FIND: for (int u : nbrs[c]) if (!id3 || !erased[u]) {
            if (subt_sz[u] < subt_sz[c] && 2 * subt_sz[u] >= subt_sz[r]) {
                p = c, c = u; goto FIND;
            }
        }
        return subt_sz[c] * 2 == subt_sz[r] ? vi{c,p} : vi{c};
    }
};




template<typename E> struct id18 {
    const tree<E>& t;
    vi euler_tour, first_visit, last_visit;

    struct visit_adder {
        vi tour_depths;
        int operator()(int i, int j) const {
            return tour_depths[i] < tour_depths[j] ? i : j;
        }
    } adder;
    id0<int, visit_adder> table;

    id18() {}
    id18(const tree<E>& _t) : t(_t), first_visit(t.V), last_visit(t.V) {
        record_tour(t.root);

        vi index(sz(euler_tour));
        for (int i = 0; i < sz(index); i++) index[i] = i;
        table = id0<int, visit_adder>(index, adder);
    }

    void record_tour(int u) {
        first_visit[u] = sz(euler_tour);
        euler_tour.pb(u);
        adder.tour_depths.pb(t.depth[u]);

        for (int v : t.children[u]) {
            record_tour(v);
            euler_tour.pb(u);
            adder.tour_depths.pb(t.depth[u]);
        }
        last_visit[u] = sz(euler_tour) - 1;
    }

    bool is_ancestor(int anc, int desc) const {
        return first_visit[anc] <= first_visit[desc]
                                && first_visit[desc] <= last_visit[anc];
    }

    int lca(int u, int v) const {
        u = first_visit[u], v = first_visit[v];
        if (u > v) swap(u, v);
        return euler_tour[table(u, v + 1)];
    }

    int dist(int u, int v) const {
        return t.depth[u] + t.depth[v] - 2 * t.depth[lca(u, v)];
    }

    bool uv_path_has_w(int u, int v, int w) const {
        return w != -1 && dist(u, v) == (dist(u, w) + dist(w, v));
    }

    

    int first_step(int u, int v) const {
        assert(u != v);
        if (!is_ancestor(u, v)) return t.par[u];
        return euler_tour[table(first_visit[u], first_visit[v]) + 1];
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
template<typename E> struct id16 : id18<E> {
    const tree<E>& t;
    
    struct heavy_path { index_t index; int htop; };
    vector<heavy_path> hld;

    id16() {}
    id16(const tree<E>& _t) : t(_t), id18<E>(_t), hld(t.V) {
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
    


    
    range_t subtree(int v) const {
        return {index(v), index(v) + t.subt_sz[v]};
    }

    

    index_t edge_index(int eid) const {
        const E& e = this->t.edges[eid];
        return index(depth(e.u) > depth(e.v) ? e.u : e.v);
    }

    int kth_ancestor(int u, int k) const {
        assert(0 <= k && k <= t.depth[u]);
        while (true) {
            if (k <= t.depth[u] - t.depth[htop(u)])
                return at_index(index(u) - k);
            k -= t.depth[u] - t.depth[htop(u)] + 1;
            u = t.par[htop(u)];
        }
    }

    

    int kth_step(int u, int v, int k) const {
        int w = this->lca(u, v), d = this->dist(u, v);
        assert(d >= k);
        return k <= t.depth[u] - t.depth[w] ? kth_ancestor(u, k) : kth_ancestor(v, d - k);
    }

    void decompose_vertical_path(int u, int v, bool up, ranges& res) const {
        size_t bef = res.size();
        for (assert(t.depth[u] >= t.depth[v]); true; u = t.par[u]) {
            int w = t.depth[htop(u)] >= t.depth[v] ? htop(u) : v;
            res.emplace_back(index(up ? u : w), index(up ? w : u));
            if ((u = w) == v) break;
        }
        if (!up) reverse(res.begin() + bef, res.end());
    }

    const ranges& decompose_path(int u, int v, bool id1) const {
        static ranges res; res.clear();
        int w = this->lca(u, v);
        bool id6 = id1 && u!=w && htop(w) == htop(this->first_step(w, u)),
             id9 = id1 ^ id6;
        if (u != w || id6)
            decompose_vertical_path(u, id6 ? w : this->first_step(w, u), true, res);
        if (v != w || id9)
            decompose_vertical_path(v, id9 ? w : this->first_step(w, v), false, res);
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
    void id8(int u, int v, bool id1, FOR f) const {
        assert(this->lca(u, v) == u);
        auto fd = [&f](index_t i, index_t j){ assert(j - i <= 1); return f(i, j); };
        for_each(u, v, id1, f, fd);
    }
    template<typename FORd>
    void id5(int u, int v, bool id1, FORd fd) const {
        assert(this->lca(u, v) == v);
        auto f = [&fd](index_t i, index_t j){ assert(j - i <= 1); return fd(i, j); };
        for_each(u, v, id1, f, fd);
    }
    template<typename FOR>
    void id10(int u, int v, bool id1, FOR f) const {
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
    T id2(int u, int v, bool id1, T iv, OP lplus, FOLDL fl) const {
        assert(this->lca(u, v) == u);
        auto fr = [&fl](index_t i, index_t j){ assert(j - i <= 1); return fl(i, j); };
        return accumulate(u, v, id1, iv, lplus, fl, fr);
    }
    template<typename T, typename OP, typename FOLDR>
    T id7(int u, int v, bool id1, T iv, OP lplus, FOLDR fr) const {
        assert(this->lca(u, v) == v);
        auto fl = [&fr](index_t i, index_t j){ assert(j - i <= 1); return fr(i, j); };
        return accumulate(u, v, id1, iv, lplus, fl, fr);
    }
    template<typename T, typename OP, typename FOLD>
    T id4(int u, int v, bool id1, T iv, OP lplus, FOLD f) const {
        return accumulate(u, v, id1, iv, lplus, f, f);
    }

    

    

    static constexpr range_t EMPTY{index_t{-1}, index_t{-1}};
    range_t intersect(range_t r, int u, int v) {
        int ru = at_index(r.f), rv = at_index(r.s - 1), uvl = this->lca(u, v);
        assert(r.f < r.s && htop(ru) == htop(rv));
        if (t.depth[rv] < t.depth[uvl]) return EMPTY;
        if (t.depth[ru] < t.depth[uvl]) { assert(htop(uvl) == htop(ru)); ru = uvl; }
        if (!this->uv_path_has_w(u, rv, ru)) return {index(this->lca(u, rv)), index(ru)};
        if (!this->uv_path_has_w(v, rv, ru)) return {index(ru), index(this->lca(v, rv))};
        return this->uv_path_has_w(u, v, ru) ? range_t{index(ru),index(ru)} : EMPTY;
    }

    ranges decompose_subtree(int u, int r) const {
        if (u == r) return {{index_t{0}, index_t{this->t.V}}};
        int w = this->first_step(u, r);
        if (w == t.par[u]) return {{index(u), index(u) + t.subt_sz[u]}};
        return {{index_t{0}, index(w)}, {index(w) + t.subt_sz[w], index_t{this->t.V}}};
    }
    template<typename T, typename OP, typename FOLD>
    T id14(int u, int r, T iv, OP lplus, FOLD f) const {
        ranges st = decompose_subtree(u, r);
        return std::accumulate(all(st), iv, [&](T v, pii p){ return lplus(v, f(p.f, p.s)); });
    }
};



int main() {
    setIO();

    int N; re(N);

    vpii range(N); re(range);

    using E = wedge<>;
    tree<E> tr(N); re(tr);
    id16<E> hld(tr);

    const int MAXC = 1e5 + 1;
    vmn invs(MAXC);
    FOR (i, 1, MAXC) invs[i] = mn(1) / i;

    vvi toggle(MAXC + 1);

    id11 (i, N) {
        toggle[range[i].f].pb(i + 1);
        toggle[range[i].s + 1].pb(-i - 1);
    }

    mn tot_color = 1;
    trav (e, range) tot_color *= e.s - e.f + 1;

    struct node { int elts; mn x, y; };
    auto nn = [](node a, node b) { return node{a.elts + b.elts, a.x + b.x, a.y + b.y }; };
    struct update { mn x, y; };
    auto uu = [](update a, update b) { return update{a.x + b.x, a.y + b.y}; };
    auto un = [](update u, node n) { return node{n.elts, n.x + u.x * n.elts, n.y + u.y * n.elts }; };

    id13 st(N, node{0,0,0}, update{0,0}, nn, uu, un);
    st.id17([](int i){ return node{1,0,0}; });

    mn cur = 0, ans = 0;

    auto _modify = [&](int i, int j, update u) {
        node n = st(i, j);
        cur += n.x * u.y + n.y * u.x + u.x * u.y * n.elts;
        st(i, j, u);
    };

    auto modify = [&](int u, mn v) {
        _modify(0, N, update{0, v});
        hld.id10(u, 0, true, [&](index_t i, index_t j) {
            _modify(int(i), int(j), update{v, -v});
        });
    };

    FOR (c, 1, MAXC) {
        trav (ev, toggle[c]) {
            int u = abs(ev) - 1;
            int cc = range[u].s - range[u].f + 1;
            modify(u, ev > 0 ? invs[cc] : -invs[cc]);
        }
        ans += cur;
    }

    ps(ans * tot_color);

    

    return 0;
}

