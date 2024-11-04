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
#if !defined(_WIN32) || defined(_WIN64)
        return x % m;
#endif
        

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

int main() {
    setIO();

    const int BITS = 5;

    using ss = unsigned int;
    vector<ss> elts;
    vvi add;

    {
        auto sum = [](ss a, ss b) {
            if (a&b) return ss(1);
            ss r = a | b;
            if (r&1) return ss(1);
            F0R (v, 1 << BITS) if (a & (1ull << v))
                F0R (w, 1 << BITS) if (b & (1ull << w))
                    r |= 1ull << (v ^ w);
            return r;
        };
        {
            set<ss> uniq({0});
            F0R (v, 1 << BITS)
                uniq.insert(1ull << v);

            while (1) {
                set<ss> ins;
                for (auto a = uniq.begin(); a != uniq.end(); a++) {
                    for (auto b = next(a); b != uniq.end(); b++) {
                        ss pos = sum(*a, *b);
                        if (!uniq.count(pos)) ins.insert(pos);
                    }
                }
                if (ins.empty()) break;
                uniq.insert(all(ins));
            }

            assert(sz(uniq) == 375);
            elts = vector<ss>(all(uniq));
            assert(elts[0] == 0);
        }
        {
            int E = sz(elts);
            add = vvi(E, vi(E));
            F0R (i, E) F0R (j, E)
                add[i][j] = index(elts, sum(elts[i], elts[j]));
        }
    }

    int N, M; re(N, M);

    struct edge { int u, v, w, i; };
    vector<edge> edges(M);

    vvi adj(N);
    F0R (i, M) {
        int u, v, w; re(u, v, w); --u, --v;
        if (u > v) swap(u, v);
        edges[i] = {u, v, w, i};
        adj[u].pb(i);
        adj[v].pb(i);
    }

    vb in_tree(M);
    vi through(N);
    vi root_wt(N);
    {
        through[0] = -1;
        queue<int> bfs({0});
        for (; !bfs.empty(); bfs.pop()) {
            int loc = bfs.front();
            for (int ei : adj[loc]) {
                auto [u, v, w, i] = edges[ei];
                int nbr = u ^ v ^ loc;
                if (!through[nbr]) {
                    in_tree[ei] = 1;
                    if (loc) {
                        through[nbr] = through[loc];
                    } else {
                        through[nbr] = nbr;
                    }
                    root_wt[nbr] = root_wt[loc] ^ w;
                    bfs.push(nbr);
                }
            }
        }
    }

    auto put_sum = [&](int &a, int b) {
        a = add[a][b];
    };

    vi partner(N);
    vi pair_wt(N);
    vi only(N);
    vi both(N);
    {
        F0R (i, N) partner[i] = i;
        for (auto [u, v, w, i] : edges) {
            if (through[u] == u && through[v] == v) {
                partner[u] = v;
                partner[v] = u;
                pair_wt[u] = w;
                pair_wt[v] = w;
            }
        }
        for (auto [u, v, w, i] : edges) {
            if (!u || !v || in_tree[i]) continue;
            int cyc = root_wt[u] ^ w ^ root_wt[v];
            int cyc_i = index(elts, ss(1ull << cyc));
            int ur = through[u], vr = through[v];
            if (ur != vr) {
                put_sum(both[min(ur, vr)], cyc_i);
                if (ur != through[u] || vr != through[v]) {
                    int swi = cyc ^ root_wt[ur] ^ root_wt[vr] ^ pair_wt[ur];
                    int swi_i = index(elts, ss(1ull << swi));
                    put_sum(only[ur], swi_i);
                    put_sum(only[vr], swi_i);
                }
            } else if (partner[ur] == ur) {
                put_sum(only[ur], cyc_i);
            } else {
                put_sum(both[min(ur, partner[ur])], cyc_i);
                put_sum(only[ur], cyc_i);
                put_sum(only[partner[ur]], cyc_i);
            }
        }
    }

    vmn ways(sz(elts));
    ways[0] = 1;

    vb done(N);
    F0R (u, N) if (partner[u] > u) {
        int v = partner[u];
        vmn WAYS = ways;
        F0R (e, sz(ways)) {
            WAYS[add[e][both[u]]] += ways[e];
            WAYS[add[e][only[u]]] += ways[e];
            WAYS[add[e][only[v]]] += ways[e];
        }
        ways = move(WAYS);
    }

    F0R (loc, N) if (through[loc] == loc && partner[loc] == loc) {
        vmn WAYS = ways;
        F0R (e, sz(ways))
            WAYS[add[e][only[loc]]] += ways[e];
        ways = move(WAYS);
    }

    mn ans = 0;
    F0R (e, sz(ways)) if (!(elts[e]&1)) ans += ways[e];
    ps(ans);

    

    

    return 0;
}

