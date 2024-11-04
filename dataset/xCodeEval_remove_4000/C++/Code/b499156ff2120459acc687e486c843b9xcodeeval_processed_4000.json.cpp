
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
using vpll = vector<pll>;
using vpdd = vector<pdd>;

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
    template<typename T> typename vector<T>::const_iterator find(const vector<T>& v, const T& x) {
        auto it = lower_bound(all(v), x); return it != v.end() && *it == x ? it : v.end();
    }
    template<typename T> size_t index(const vector<T>& v, const T& x) {
        auto it = find(v, x); assert(it != v.end() && *it == x); return it - v.begin();
    }

    template<typename T1, typename T2> typename vector<pair<T1, T2>>::iterator lower_bound(
            const vector<pair<T1, T2>>& v, const T1& x) {
        return lower_bound(all(v), x, [](pair<T1, T2> a, pair<T1, T2> b) { return a.f < b.f; });
    }
    template<typename T1, typename T2> typename vector<pair<T1, T2>>::iterator upper_bound(
            const vector<pair<T1, T2>>& v, const T1& x) {
        return upper_bound(all(v), x, [](pair<T1, T2> a, pair<T1, T2> b) { return a.f < b.f; });
    }
}
using namespace __algorithm;

struct __monostate {
    friend istream& operator>>(istream& is, const __attribute__((unused))__monostate& ms) { return is; }
    friend ostream& operator<<(ostream& os, const __attribute__((unused))__monostate& ms) { return os; }
} ms;

template<typename W=__monostate> struct wedge {
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


using mn = modnum<int(998244353)>;
using vmn = vector<mn>;
using vvmn = vector<vmn>;



template<typename T> struct kmp {
    size_t P;
    vector<T> word;
    vector<size_t> fail;

    size_t adv(size_t len, const T& nxt) const {
        if (len == sz(word)) len = fail[len];
        while (len > 0 && word[len] != nxt)
            len = fail[len];
        return len + size_t(word[len] == nxt);
    }

    
    template<typename I> kmp(I begin, I end) : word(begin, end) {
        P = sz(word);
        fail.resize(P + 1);
        for (size_t i = 2; i <= P; i++)
            fail[i] = adv(fail[i - 1], word[i - 1]);
    }

    
    template<typename C> vb find(const C& text) const {
        vb match(text.size());
        for (size_t i = 0, len = 0; i < text.size(); i++) {
            len = adv(len, text[i]);
            if (len == P) {
                match[i - len + 1] = true;
                len = fail[len];
            }
        }
        return match;
    }
};



int main() {
    setIO();

    string source, target;
    re(source, target);

    string tmp = target;
    reverse(all(tmp));

    kmp<char> KMP(all(tmp));

    int T = sz(target);

    vvi substring_match(T + 1, vi(T + 1));
    FOR (len, 1, T + 1)
        id1 (i, T)
            substring_match[len][i] = KMP.adv(substring_match[len-1][i+1], target[i]);

    vi id3;
    int out_len;
    int id0;

    auto add_front = [&](const vi& locs, int len, int suffix_match, char nc) {
        id3.clear();
        id0 = 0;

        if (suffix_match != -1) {
            id0 = KMP.adv(suffix_match, nc);
            return;
        } else assert(!locs.empty());

        for (int inx : locs) {
            if (inx > 0 && target[inx - 1] == nc)
                id3.pb(inx - 1);
        }

        if (!id3.empty())
            out_len = len + 1;
        else {
            out_len = -1;
            id0 = KMP.adv(substring_match[len][locs[0]], nc);
        }
    };
    auto add_back = [&](const vi& locs, int len, int suffix_match, char nc) {
        id3.clear();
        id0 = 0;

        if (suffix_match != -1) {
            id0 = suffix_match;
            return;
        } else assert(!locs.empty());

        for (int inx : locs) {
            if (inx + len < T && target[inx + len] == nc)
                id3.pb(inx);
        }

        if (!id3.empty())
            out_len = len + 1;
        else {
            out_len = -1;
            id0 = substring_match[len][locs[0]];
        }
    };

    struct state {
        vi locs;
        int len;
        mn ways;
    };

    vector<state> dp_internal(T);   

    vmn dp_suffix(T + 1); 


    vector<state> DP_internal(T);
    vmn DP_suffix(T + 1);

    mn final_ans = 0;

    auto clear_DP = [&]() {
        trav (s, DP_internal) { s.locs.clear(); s.len = -1; s.ways = 0; }
        trav (s, DP_suffix) s = 0;
    };
    auto id2 = [&](mn ways) {
        

        if (id3.empty()) {
            DP_suffix[id0] += ways;
        } else {
            int inx = id3.front();
            swap(DP_internal[inx].locs, id3);
            DP_internal[inx].len = out_len;
            DP_internal[inx].ways += ways;
        }
    };
    auto print_dp = [&]() {
        id1 (i, T) {
            ps(i, dp_internal[i].locs, dp_internal[i].len, dp_internal[i].ways);
        }
        pc(dp_suffix);
    };
    auto update_ans = [&]() {
        

        trav (s, dp_internal) if (s.len == T) final_ans += s.ways;
        final_ans += dp_suffix.back();
        

    };

    

    {
        vi locs;
        id1 (i, T) if (target[i] == source[0]) locs.pb(i);
        int sm = KMP.adv(0, source[0]);
        if (locs.empty()) dp_suffix[sm] = 2;
        else dp_internal[locs.front()] = { locs, 1, 2 };
        update_ans();
    }

    

    FOR (move, 1, sz(source)) {
        const char nc = source[move];
        clear_DP();

        id1 (fm, T) if (!dp_internal[fm].locs.empty()) {
            add_front(dp_internal[fm].locs, dp_internal[fm].len, -1, nc);
            id2(dp_internal[fm].ways);

            add_back(dp_internal[fm].locs, dp_internal[fm].len, -1, nc);
            id2(dp_internal[fm].ways);
        }
        id1 (sm, T + 1) if (dp_suffix[sm].v != 0) {
            add_front({}, -1, sm, nc);
            id2(dp_suffix[sm]);

            add_back({}, -1, sm, nc);
            id2(dp_suffix[sm]);
        }

        swap(dp_internal, DP_internal);
        swap(dp_suffix, DP_suffix);
        update_ans();
    }

    ps(final_ans);

    return 0;
}
