
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
    template<class T> void re(vector<T>& a) { id1(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { id1(i,SZ) re(a[i]); }
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
        vector<T> r(sz(v)+1, id); id1 (i, sz(v)) r[i+1] = op(r[i], v[i]); return r;
    }
    template<typename C, typename T, typename OP> vector<T> suffixes(const C& v, T id, OP op) {
        vector<T> r(sz(v)+1, id); F0Rd (i, sz(v)) r[i] = op(v[i], r[i+1]); return r;
    }
}
using namespace __algorithm;



struct id3 {
    id3 (int v = 0) {}
    friend istream& operator>>(istream& is, const id3& ms) { return is; }
    friend ostream& operator<<(ostream& os, const id3& ms) { return os; }
    friend id3 operator+(const id3& a, const id3& b) { return a; }
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

    static modnum factorial(int n) {
        static vector<modnum> fact = {1};
        assert(n >= 0);
        if (sz(fact) <= n) {
            int had = sz(fact);
            fact.resize(n + 1);
            for (int i = had; i <= n; i++) fact[i] = fact[i-1] * i;
        }
        return fact[n];
    }
    static modnum inverse_factorial(int n) {
        static vector<modnum> finv = {1};
        assert(n >= 0);
        if (sz(finv) <= n) {
            int had = sz(finv);
            finv.resz(n + 1), finv[n] = factorial(n).inv();
            for (int i = n - 1; i >= had; i--) finv[i] = finv[i+1] * (i+1);
        }
        return finv[n];
    }

    static modnum small_inv(int n) {
        assert(n > 0); return factorial(n - 1) * inverse_factorial(n);
    }

    static modnum ncr(int n, int r) {
        if (r < 0 || n < r) return 0;
        return factorial(n) * inverse_factorial(r) * inverse_factorial(n - r);
    }
};


using mn = modnum<int(1e9 + 7)>;
using vmn = vector<mn>;
using vvmn = vector<vmn>;



template<typename WEIGHT> struct edge_base {
    WEIGHT weight;
    friend istream& operator>>(istream& i, edge_base& e) { i >> e.weight; return i; }
    WEIGHT& wt()       { return weight; }
    WEIGHT  wt() const { return weight; }
};
template<> struct edge_base<id3> {
    edge_base(__attribute__((unused))id3 _) {}
    friend istream& operator>>(istream& i, __attribute__((unused))edge_base& e) { return i; }
    id3& wt() const { return ms; }
};
template<typename WEIGHT = id3>
struct edge : edge_base<WEIGHT> {
    int uv;
    edge (int _uv = 0, WEIGHT _weight = {}) : edge_base<WEIGHT>(_weight), uv(_uv) {}
    int operator()(int u) const { return uv ^ u; }
};

enum INPUT_FORMAT { EDGE_LIST, PARENT_LIST };
template<typename E> struct tree {
    int V, root;
    vector<vector<E>> nbrs, children;

    vi par, depth, id4;
    vi preorder, id2;

    tree(int _V = 0, int _root = 0) : V(_V), root(_root),
        nbrs(V), children(V), par(V, -1), depth(V), id4(V) {}

    void add_edge(int u, int v, E e) {
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
            if (FMT == PARENT_LIST) u = i;
            else re(u), u -= FIRST_INDEX;
            re(v), v -= FIRST_INDEX;
            E e{}; re(e);
            t.add_edge(u, v, e);
        }
        t.init();
    }

    void init() {
        traverse(root);
        for (int u = 0; u < V; u++)
            sort_by(nbrs[u], id4[a(u)] > id4[b(u)]);
        build_preorder(root);
        id2 = preorder, reverse(all(id2));
    }

    void traverse(int u) {
        id4[u] = 1;
        for (E e : nbrs[u]) if (int v = e(u); v != par[u]) {
            par[v] = u;
            depth[v] = depth[u] + 1;
            traverse(v);
            children[u].pb(e);
            id4[u] += id4[v];
        }
        sort_by(children[u], id4[a(u)] > id4[b(u)]);
    }

    void build_preorder(int u) {
        preorder.pb(u);
        for (E e : children[u]) build_preorder(e(u));
    }

    friend void pr(const tree& t) {
        pr("{root=", t.root, " |");
        for (int u = 0; u < t.V; u++) {
            pr(" ", u, "--{");
            for (E e : t.children[u])
                pr("(ch=", e(u), " wt=", e.wt(), ")");
            pr("}");
        }
        pr("}");
    }
};





template<typename W, int MAXV, bool PREORDER>
struct id0 {
    using E = edge<W>;
    static const int L = 33 - __builtin_clz(MAXV - 1);

    const tree<E>& t;

    vi layer;        

    vpii par;        

    vi child_ct;     


    struct visit { int v; E e; };
    vector<vector<visit>> preorder;  

    vvi ch_sz;                       


    vector<array<E, L>> anc_path;    


    id0(const tree<E>& _t) : t(_t),
            layer(t.V, -1), par(t.V), child_ct(t.V), anc_path(t.V) {
        assert(t.V <= MAXV);
        if (PREORDER) preorder.resz(t.V), ch_sz.resz(t.V);
        id4 = t.id4, decompose(t.root), id4.clear();
    }

    vi id4;
    int centroid(int r) {
        int c = r;
        FIND: for (E e : t.nbrs[c]) if (int u = e(c); layer[u] == -1) {
            if (id4[u] < id4[c] && 2 * id4[u] >= id4[r]) {
                c = u; goto FIND;
            }
        }
        return c;
    }

    int ly = 0, rt = 0;
    void traverse(int u, E in) {
        if (PREORDER) preorder[rt].pb({u, in});
        id4[u] = 1;
        for (E e : t.nbrs[u]) if (int v = e(u); v != in(u) && layer[v] == -1) {
            anc_path[v][ly] = E(anc_path[u][ly].uv + 1, anc_path[u][ly].wt() + e.wt());
            traverse(v, e);
            id4[u] += id4[v];
        }
    }

    void decompose(int r = 0, int p = -1, int i = 0) {
        par[r = centroid(r)] = {p, i}, i = 0;
        layer[r] = ly;
        if (PREORDER) preorder[r] = {{r}};
        id4[r] = 1;
        for (E e : t.nbrs[r]) if (int u = e(r); layer[u] == -1) {
            if (PREORDER) ch_sz[r].pb(-sz(preorder[r]));
            rt = r, anc_path[u][ly] = E(1, {e.wt()}), traverse(u, e);
            if (PREORDER) ch_sz[r].back() += sz(preorder[r]);
            id4[r] += id4[u], child_ct[r]++;
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
        return anc_path[u][layer[clca]].l + anc_path[v][layer[clca]].l;
    }
};



int main() {
    setIO();

    int N; re(N);
    vpii range(N); re(range);

    using E = edge<>; tree<E> tr(N); re(tr);
    id0<id3, int(1e5), 0> cd(tr);

    mn ans = 0;

    vector<pair<mn, mn>> tot(N);
    vector<vector<pair<mn, mn>>> contrib(N);
    id1 (i, N) contrib[i].resz(cd.child_ct[i]);

    auto proc = [&](int c, int u, bool rem) {
        mn wt = mn::small_inv(range[u].s - range[u].f + 1);
        if (rem) wt = -wt;

        int p = u, pi = -1;
        F0Rd (i, cd.layer[u] + 1) {
            tot[p].f += wt;     

            tot[p].s -= wt * c; 

            if (pi != -1) {
                contrib[p][pi].f += wt;
                contrib[p][pi].s -= wt * c;
            }

            ans -= cd.anc_path[u][i].uv * wt * c * (tot[p].f - (pi != -1 ? contrib[p][pi].f : 0));
            ans -= cd.anc_path[u][i].uv * wt * (tot[p].s - (pi != -1 ? contrib[p][pi].s : 0));

            tie(p, pi) = cd.par[p];
        }
    };

    vector<array<int, 3>> ev; 

    id1 (i, N) {
        ev.pb({ range[i].f - 1, i, 0 });
        ev.pb({ range[i].s    , i, 1 });
    }
    sort(all(ev));

    trav (e, ev) proc(e[0], e[1], e[2]);

    trav (e, range) ans *= e.s - e.f + 1;
    ps(ans);

    

    return 0;
}
