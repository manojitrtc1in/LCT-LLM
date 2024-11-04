
using namespace std;

namespace IO {
    const int BUFFER_SIZE = 1 << 15;

    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;

    char output_buffer[BUFFER_SIZE];
    int output_pos = 0;

    char number_buffer[100];
    uint8_t lookup[100];

    void id6() {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;

        if (input_len == 0)
            input_buffer[0] = EOF;
    }

    inline char next_char(bool advance = true) {
        if (input_pos >= input_len)
            id6();

        return input_buffer[advance ? input_pos++ : input_pos];
    }

    template<typename T>
    inline void read_int(T &number) {
        bool negative = false;
        number = 0;

        while (!isdigit(next_char(false)))
            if (next_char() == '-')
                negative = true;

        do {
            number = 10 * number + (next_char() - '0');
        } while (isdigit(next_char(false)));

        if (negative)
            number = -number;
    }

    template<typename T, typename... Args>
    inline void read_int(T &number, Args &... args) {
        read_int(number);
        read_int(args...);
    }

    void _flush_output() {
        fwrite(output_buffer, sizeof(char), output_pos, stdout);
        output_pos = 0;
    }

    inline void write_char(char c) {
        if (output_pos == BUFFER_SIZE)
            _flush_output();

        output_buffer[output_pos++] = c;
    }

    template<typename T>
    inline void write_int(T number, char after = '\0') {
        if (number < 0) {
            write_char('-');
            number = -number;
        }

        int length = 0;

        while (number >= 10) {
            uint8_t lookup_value = lookup[number % 100];
            number /= 100;
            number_buffer[length++] = (lookup_value & 15) + '0';
            number_buffer[length++] = (lookup_value >> 4) + '0';
        }

        if (number != 0 || length == 0)
            write_char(number + '0');

        for (int i = length - 1; i >= 0; i--)
            write_char(number_buffer[i]);

        if (after)
            write_char(after);
    }

    void init() {
        

        bool exit_success = atexit(_flush_output) == 0;
        assert(exit_success);

        for (int i = 0; i < 100; i++)
            lookup[i] = (i / 10 << 4) + i % 10;
    }
}
























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
    friend void re(wedge& e) { IO::read_int(e.u, e.v);  --e.u, --e.v; }
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


using mn = modnum<int(998244353)>;
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




template<typename E> struct tree {
    int V, root;

    vvi nbrs, children;
    vi par, depth, subt_sz;

    vi preorder, id3;

    vector<E> edge_list;
    vector<vector<reference_wrapper<E>>> edges;

    vb erased;
    void erase(int u) { erased[u] = true; }

    tree(int _V = 0) : V(_V) {}
    tree(const vector<E>& id4, int _root = 0) : edge_list(id4),
            V(sz(id4) + 1), edges(V), root(_root),
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
        id3 = preorder;
        reverse(all(id3));
    }

    void init(int u) {
        subt_sz[u] = 1;
        for (int v : nbrs[u]) if (v != par[u]) {
            children[u].pb(v);
            par[v] = u;
            depth[v] = depth[u] + 1;
            init(v);
            subt_sz[u] += subt_sz[v];
        }
        sort_by(children[u], subt_sz[a] > subt_sz[b]);
    }

    void build_preorder(int u) {
        preorder.pb(u);
        for (int v : children[u]) build_preorder(v);
    }

    friend void re(tree& t) {
        assert(t.V > 0);
        vector<E> id4(t.V - 1);
        re(id4);
        for (int i = 0; i < t.V - 1; i++) id4[i].i = i;
        t = tree<E>(id4);
    }
    friend void pr(const tree& t) { pr("{V=", t.V, " ", t.edge_list, "}"); }

    mutable vi __subt_sz;
    void __calc_subt_sz(int u, bool id1, int p) const {
        __subt_sz[u] = 1;
        for (int v : nbrs[u]) if (v != p && (!id1 || !erased[v])) {
            __calc_subt_sz(v, id1, u);
            __subt_sz[u] += __subt_sz[v];
        }
    }

    vi centroids(int r = 0, bool id1 = 1) const {
        __calc_subt_sz(r, id1, -1);
        int c = r, p = -1;
        FIND: for (int u : nbrs[c]) if (!id1 || !erased[u]) {
            if (subt_sz[u] < subt_sz[c] && 2 * subt_sz[u] >= subt_sz[r]) {
                p = c, c = u; goto FIND;
            }
        }
        return subt_sz[c] * 2 == subt_sz[r] ? vi{c,p} : vi{c};
    }
};




template<typename E> struct id5 {
    const tree<E>& t;
    vi euler_tour, first_visit, last_visit;

    struct visit_adder {
        vi tour_depths;
        int operator()(int i, int j) const {
            return tour_depths[i] < tour_depths[j] ? i : j;
        }
    } adder;
    id0<int, visit_adder> table;

    id5() {}
    id5(const tree<E>& _t) : t(_t), first_visit(t.V), last_visit(t.V) {
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



int main() {
    IO::init();

    int N, Q; IO::read_int(N, Q);

    using E = wedge<>;
    tree<E> tr(N); re(tr);
    id5<E> lca(tr);

    const mn NINV = mn(1)/N;

    vmn val(N), adjust(N), adj_sum(N);

    int work_done = 0;
    vector<pair<int, mn>> todo;

    int t, v, d;
    id2 (q, Q) {
        if (work_done >= 2 * N) {
            for (auto [node, val] : todo) adj_sum[node] += val;

            vi nodes;
            id2 (u, N) if (adj_sum[u].v) nodes.pb(u);

            fill(all(adjust), 0);
            trav (node, nodes) {
                mn& val = adj_sum[node];
                adjust[0] += val * tr.subt_sz[node];
                adjust[node] += val * (N - tr.subt_sz[node]);
                trav (nbr, tr.children[node]) {
                    adjust[nbr] += val * -tr.subt_sz[nbr];
                }
                val = 0;
            }

            for (int u : tr.preorder) {
                if (u) adjust[u] += adjust[tr.par[u]];
                val[u] += adjust[u];
            }

            work_done = 0;
            todo.clear();
        }

        IO::read_int(t);
        if (t == 1) {
            IO::read_int(v, d);
            todo.eb(--v, d);
        } else {
            IO::read_int(v); --v;
            mn ans = val[v];
            for (pair<int, mn> op : todo) {
                int would = op.f == v ? N : lca.is_ancestor(op.f, v) ? N - tr.subt_sz[lca.first_step(op.f, v)] : tr.subt_sz[op.f];
                ans += would * op.s;
            }
            work_done += sz(todo);
            IO::write_int((int) (ans * NINV), '\n');
        }
    }

    

    return 0;
}

