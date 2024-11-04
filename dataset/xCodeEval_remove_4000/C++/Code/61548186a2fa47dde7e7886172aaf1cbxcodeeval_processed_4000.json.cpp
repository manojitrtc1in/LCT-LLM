
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

    template<typename C, typename T> vector<T> prefixes(const C& v, T zero) {
        vector<T> res(sz(v) + 1, zero); id1 (i, sz(v)) res[i+1] = res[i] + v[i]; return res;
    }
    template<typename C, typename T> vector<T> suffixes(const C& v, T zero) {
        vector<T> res(sz(v) + 1, zero); F0Rd (i, sz(v)) res[i] = v[i] + res[i+1]; return res;
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
        ios_base::sync_with_stdio(0); cin.tie(0); cout.precision(15);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
}
using namespace __io;





template<typename T> struct id0 {
    using F = function<T(const T&, const T&)>;

    int SZ;
    F combine;
    vector<T> table;

    T& entry(int l, int i) { return table[l * SZ + i]; }
    const T& entry(int l, int i) const { return table[l * SZ + i]; }

    id0() {}
    id0(const vector<T>& elts, F _combine) : SZ(sz(elts)), combine(_combine) {
        const int L = 32 - __builtin_clz(max(SZ - 1, 1));
        table.resize(L * SZ);
        copy(all(elts), table.begin());

        for (int l = 0; l + 1 < L; l++) {
            for (int i = 0; i < SZ; i++) {
                entry(l + 1, i) = entry(l, i);
                if (i + (1 << l) < SZ)
                    entry(l + 1, i) = combine(entry(l + 1, i), entry(l, i + (1 << l)));
            }
        }
    }

    

    T operator()(int i, int j) const {
        assert(0 <= i && i < j && j <= SZ);
        int l = j - i - 1 ? 31 - __builtin_clz(j - i - 1) : 0;
        return combine(entry(l, i), entry(l, j - (1 << l)));
    }
};






struct id2 {
    struct visit {
        int node, depth, index;
        static visit higher(const visit& a, const visit& b) {
            if (a.depth != b.depth) return a.depth < b.depth ? a : b;
            return a.index > b.index ? a : b;
        }
    };

    int V;
    vector<visit> tour;
    id0<visit> table;
    vi first, depth, par, comp;

    id2(const vvi& tree = {}, vi roots = {}) : V(sz(tree)) {
        depth.resz(V), comp.resz(V, -1), first.resz(V, -1), par.resz(V, -1);

        int cc = 0;
        auto dfs = [&](auto& self, int loc) -> void {
            comp[loc] = cc, first[loc] = sz(tour);
            tour.push_back({loc, depth[loc], sz(tour)});
            for (int nbr : tree[loc]) if (nbr != par[loc]) {
                par[nbr] = loc;
                depth[nbr] = depth[loc] + 1;
                self(self, nbr);
                tour.push_back({loc, depth[loc], sz(tour)});
            }
        };
        for (int i : roots) {
            assert(comp[i] == -1);
            dfs(dfs, i), cc++;
        }
        for (int i = 0; i < V; i++) {
            if (comp[i] == -1) dfs(dfs, i), cc++;
        }

        table = id0<visit>(tour, visit::higher);
    }

    

    

    int lca(int u, int v) {
        if (comp[u] != comp[v]) return -1;
        u = first[u], v = first[v];
        if (u > v) swap(u, v);
        return table(u, v + 1).node;
    }

    int dist(int u, int v) {
        assert(comp[u] == comp[v]);
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

    int lcad(int u, int v) {
        

        u = first[u], v = first[v];
        return table(min(u,v), max(u,v) + 1).depth;
    }

    

    bool on_path(int u, int v, int btw) {
        return dist(u, v) == (dist(u, btw) + dist(btw, v));
    }

    

    int first_step(int u, int v) {
        assert(u != v && comp[u] == comp[v]);
        int w = lca(u, v);
        return u == w ? tour[table(first[u], first[v]).index+1].node : par[u];
    }
};



using ull = unsigned long long;
using pset = map<int, ull>;

const int MM = 20032, L = 64, B = MM / L;
ull wbit[6];
ull share[MM][B], trans[MM][B];
ull arc[MM][B], rev[MM][B];

void finish() {
    memcpy(trans, share, sizeof(share));

    id1 (ib, B) id1 (jb, B) {
        id1 (k, 6) id1 (i, L) {
            if (i & (1 << k)) continue;
            ull& r1 = trans[(ib << 6) + i][jb];
            ull& r2 = trans[(ib << 6) + i + (1 << k)][jb];

            ull f = r1 & wbit[k]; r1 ^= f;
            ull g = r2 & ~wbit[k]; r2 ^= g;

            r1 |= g << (1 << k);
            r2 |= f >> (1 << k);
        }
    }
    id1 (ib, B) FOR (jb, ib + 1, B) {
        id1 (i, L) swap(trans[(ib << 6) + i][jb], trans[(jb << 6) + i][ib]);
    }

    

    id1 (i, MM) id1 (jb, B) {
        share[i][jb] |= trans[i][jb];
    }
}

int N, M;
vvi adj, ins, rem;
id2 lca;

void rec(const pset& m, int pi) {
    trav (e, m) share[pi][e.f] |= e.s;
}
void flip(pset& m, int pi) {
    m[pi >> 6] ^= 1ull << (pi & 63);
}
void join(pset& a, pset& b) {
    if (sz(a) < sz(b)) swap(a, b);
    trav (e, b) for (ull t = e.s; t; t -= t & -t) {
        rec(a, (e.f << 6) + 63 - __builtin_clzll(t&-t));
    }
    trav (e, b) a[e.f] |= e.s;
}

pset dfs(int loc, int par) {
    pset ret;
    trav (pi, ins[loc]) {
        rec(ret, pi);
        flip(ret, pi);
    }

    trav (nbr, adj[loc]) if (nbr != par) {
        pset res = dfs(nbr, loc);
        trav (pi, rem[nbr]) flip(res, pi);
        join(ret, res);
    }
    return ret;
}

int main() {
    setIO();

    id1 (k, 6) id1 (i, 64)
        if (i & (1 << k)) wbit[k] |= 1ull << i;

    re(N); adj.resz(N);
    id1 (i, N - 1) {
        int u, v; re(u, v); --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    lca = id2(adj);

    ins.resz(N); rem.resz(N);
    auto put = [&](int u, int v, int pi) {
        if (lca.depth[u] > lca.depth[v]) swap(u, v);
        int w = lca.lca(u, v);
        ins[v].pb(pi); rem[lca.first_step(w, v)].pb(pi);
        if (w != u) { ins[u].pb(pi); rem[lca.first_step(w, u)].pb(pi); }
    };

    re(M);
    vpii ants;
    id1 (i, M) {
        int a, b, c, d; re(a, b, c, d);
        if (a == b || c == d) { return 0; }
        put(--a, --b, 2 * i);
        put(--c, --d, 2 * i + 1);
        ants.eb(a, b); ants.eb(c, d);
    }

    dfs(0, 0);
    finish();

    vi ancd(2* M); id1 (i, 2 * M) ancd[i] = lca.lcad(ants[i].f, ants[i].s);
    auto overlap = [&](int i, int j) {
        int dm = max(ancd[i], ancd[j]);
        return lca.lcad(ants[i].f, ants[j].f) > dm
            || lca.lcad(ants[i].f, ants[j].s) > dm
            || lca.lcad(ants[i].s, ants[j].f) > dm
            || lca.lcad(ants[i].s, ants[j].s) > dm;
    };

    

    id1 (i, 2 * M) id1 (jb, B) {
        arc[i][jb] = (share[i][jb] & wbit[0])/2 + 2 * (share[i][jb] & ~wbit[0]);
        rev[i][jb] = share[i^1][jb];
    }

    

    vi post;
    vector<ull> nvis(B, ~0);
    auto go = [&](auto& self, int loc) -> void {
        nvis[loc >> 6] ^= 1ull << (loc & 63);
        id1 (jb, B) while (true) {
            ull uv = arc[loc][jb] & nvis[jb];
            if (!uv) break;
            self(self, (jb << 6) + 63 - __builtin_clzll(uv & -uv));
        }
        post.pb(loc);
    };
    id1 (i, 2 * M) if (nvis[i >> 6] & (1ull << (i & 63))) go(go, i);
    reverse(all(post));

    vi scc(2 * M, -1);
    fill(all(nvis), ~0);
    auto gogo = [&](auto& self, int loc, int root) -> void {
        scc[loc] = root;
        nvis[loc >> 6] ^= 1ull << (loc & 63);
        id1 (jb, B) while (true) {
            ull uv = rev[loc][jb] & nvis[jb];
            if (!uv) break;
            self(self, (jb << 6) + 63 - __builtin_clzll(uv & -uv), root);
        }
    };
    int SCC = 0;
    trav (e, post) if (nvis[e >> 6] & (1ull << (e & 63))) gogo(gogo, e, SCC++);
    id1 (i, M) if (scc[2 * i] == scc[2 * i + 1]) { ps("NO"); return 0; }

    ps("YES");
    vi ans(M, -1);
    id1 (i, M) ps(ans[i] = scc[2 * i] < scc[2 * i + 1] ? 2 : 1);

    

    return 0;
}

