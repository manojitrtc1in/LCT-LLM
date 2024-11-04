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





namespace IO {
    const int BUFFER_SIZE = 1 << 15;

    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;

    char output_buffer[BUFFER_SIZE];
    int output_pos = 0;

    char number_buffer[100];
    uint8_t lookup[100];

    void _update_input_buffer() {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;

        if (input_len == 0)
            input_buffer[0] = EOF;
    }

    inline char next_char(bool advance = true) {
        if (input_pos >= input_len)
            _update_input_buffer();

        return input_buffer[advance ? input_pos++ : input_pos];
    }

    inline bool isspace(char c) {
        return (unsigned char) (c - '\t') < 5 || c == ' ';
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

    inline void read_str(string &str) {
        while (isspace(next_char(false)))
            next_char();

        str.clear();

        do {
            str += next_char();
        } while (!isspace(next_char(false)));
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

    inline void write_str(const string &str, char after = '\0') {
        for (char c : str)
            write_char(c);

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





struct edge {
    int uv; 

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
    vi preorder, reverse_preorder;

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
            IO::read_int(u), u -= FIRST_INDEX;
            if (FMT == PARENT_LIST) v = i+1;
            else IO::read_int(v), v -= FIRST_INDEX;
            E e{}; re(e.wt()); 

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
        reverse_preorder = preorder, reverse(all(reverse_preorder));
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
template<typename E> struct heavy_path_decomposition {
    const tree<E>& t;
    
    struct heavy_path { index_t index; int htop; };
    vector<heavy_path> hld;

    heavy_path_decomposition() {}
    heavy_path_decomposition(const tree<E>& _t) : t(_t), hld(t.V) {
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

    E first_step(int u, int v) const {
        assert(u != v);
        if (!is_ancestor(u, v)) return t.up_edge(u);
        return *upper_bound(all(t.children[u]), v,
            [&](int v, E c) { return index(v) < index(c(u)) + t.subt_sz[c(u)]; });
    }

    int par(int v) const { return t.par[v]; }
    int depth(int v) const { return t.depth[v]; }

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

    mutable int path_lca;
    mutable ranges path_up, path_down;
    void decompose_path(int u, int v, bool include_lca) const {
        path_up.clear(), path_down.clear();
        while (htop(u) != htop(v)) {
            int& jump = index(htop(u)) > index(htop(v)) ? u : v;
            (jump == u ? path_up : path_down).eb(index(htop(jump)), index(jump) + 1);
            jump = t.par[htop(jump)];
        }
        path_lca = t.depth[u] < t.depth[v] ? u : v;
        if (u != v || include_lca) {
            (u != path_lca ? path_up : path_down).eb(
                    index(path_lca) + !include_lca, index(path_lca^u^v) + 1);
        }
        reverse(all(path_down));
    }

    template<typename FOR, typename FORd>
    void for_each(int u, int v, bool include_lca, const FOR& f, const FORd& fd) const {
        decompose_path(u, v, include_lca);
        for (range_t r : path_up)    f(r.f, r.s);
        for (range_t r : path_down) fd(r.f, r.s);
    }
    template<typename FOR>
    void for_each_commutative(int u, int v, bool include_lca, const FOR& f) const {
        for_each(u, v, include_lca, f, f);
    }

    template<typename T, typename OP, typename FOLDL, typename FOLDR>
    T accumulate(int u, int v, bool include_lca, T iv,
            const OP& lplus, const FOLDL& fl, const FOLDR& fr) const {
        decompose_path(u, v, include_lca);
        for (range_t r : path_up)   iv = lplus(iv, fr(r.f, r.s));
        for (range_t r : path_down) iv = lplus(iv, fl(r.f, r.s));
        return iv;
    }
    template<typename T, typename OP, typename FOLD>
    T accumulate_commutative(int u, int v, bool include_lca, T iv,
            const OP& lplus, const FOLD& f) const {
        return accumulate(u, v, include_lca, iv, lplus, f, f);
    }
};





struct union_find {
    struct node {
        int par, rnk, size;
        node(int id = 0) : par(id), rnk(0), size(1) {}
    };

    vector<node> uf;
    union_find(int N = 0) : uf(N) {
        for (int i = 0; i < N; i++)
            uf[i] = node(i);
    }

    int rep(int i) {
        if (i != uf[i].par)
            uf[i].par = rep(uf[i].par);
        return uf[i].par;
    }

    bool unio(int a, int b) {
        a = rep(a), b = rep(b);
        if (a == b) return false;
        if (uf[a].rnk < uf[b].rnk) swap(a, b);
        uf[b].par = a;
        uf[a].size += uf[b].size;
        if (uf[a].rnk == uf[b].rnk) uf[a].rnk++;
        return true;
    }

    node& operator[](int i) { return uf[rep(i)]; }

    friend void pr(const union_find& u) {
        pr("{"); bool f = 1;
        for (int i = 0; i < sz(u.uf); i++) if (u.uf[i].par == i) {
            if (!f) pr(", "); else f = 0;
            pr("[ ", i, " | rank=", u.uf[i].rnk, " size=", u.uf[i].size, " ]");
        }
        pr("}");
    }
};



struct node { int first = -1, last = -1; };
auto nn = [](node a, node b) {
    node r;
    r.first = a.first != -1 ? a.first : b.first;
    r.last = b.last != -1 ? b.last : a.last;
    return r;
};



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



int main() {
    setIO();

    int N, K, R; IO::read_int(N, K, R);
    using E = edge; tree<E> tr(N, 0); re(tr);

    vb is_rest(N);
    F0R (r, R) {
        int rest; IO::read_int(rest); --rest;
        is_rest[rest] = 1;
    }

    const int INF = 1e9;

    vi dist_below(N, INF);
    trav (u, tr.reverse_preorder) {
        if (is_rest[u]) dist_below[u] = 0;
        else {
            trav (c, tr.children[u])
                ckmin(dist_below[u], 1 + dist_below[c(u)]);
        }
    }

    vi dist_above(N, INF);
    trav (u, tr.preorder) {
        if (u != tr.root) ckmin(dist_above[u], 1 + dist_above[tr.par[u]]);

        if (is_rest[u]) {
            trav (c, tr.children[u]) dist_above[c(u)] = 1;
            continue;
        }

        vi child_dist;
        trav (c, tr.children[u]) child_dist.pb(dist_below[c(u)]);

        vi pref = prefixes(child_dist, INF, [](int a, int b) { return min(a, b); });
        vi suff = suffixes(child_dist, INF, [](int a, int b) { return min(a, b); });

        F0R (i, sz(child_dist)) {
            ckmin(dist_above[tr.children[u][i](u)], 2 + min(pref[i], suff[i+1]));
        }
    }

    union_find uf(N);

    FOR (v, 1, N) {
        if (dist_above[v] + dist_below[v] <= K) {
            uf.unio(tr.par[v], v);
        }
    }

    heavy_path_decomposition<E> hld(tr);

    vi color(N, -1);
    {
        vi dist(N, -1);
        queue<int> bfs;

        F0R (i, N) if (is_rest[i]) {
            color[i] = uf.rep(i);
            dist[i] = 0;
            bfs.push(i);
        }

        for (; !bfs.empty(); bfs.pop()) {
            int loc = bfs.front();
            if (dist[loc] == K/2) break;
            trav (e, tr.nbrs[loc]) if (int nbr = e(loc); dist[nbr] == -1) {
                dist[nbr] = dist[loc] + 1;
                color[nbr] = color[loc];
                bfs.push(nbr);
            }
        }
    }

    segment_tree st(N, node{}, nn);
    auto NN = [](node a, node b) { return nn(b, a); };
    segment_tree ST(N, node{}, NN);
    st.set_leaves([&](int i) {
            int v = hld.at_index({i});
            return node{color[v], color[v]};
    });
    ST.set_leaves([&](int i) {
            int v = hld.at_index({i});
            return node{color[v], color[v]};
    });

    auto read_path = [&](int u, int v) {
        return hld.accumulate(u, v, true, node{}, nn,
                [&](index_t i, index_t j) { return st(i.i, j.i); },
                [&](index_t i, index_t j) { return ST(i.i, j.i); });
    };

    int Q;
    IO::read_int(Q);
    F0R (q, Q) {
        int a, b; IO::read_int(a, b); --a, --b;

        int DIST = hld.dist(a, b);
        if (DIST <= K) { 

            ps("YES");
        }  else { 

            int A = hld.kth_step(a, b, (K+1) / 2);
            int B = hld.kth_step(b, a, (K+1) / 2);

            node left = read_path(a, A);
            node right = read_path(b, B);

            

            if (left.last != -1 && left.last == right.last)
                ps("YES");
            else
                ps("NO");
        }
    }

    

    

    return 0;
}

