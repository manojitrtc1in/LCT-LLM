
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

namespace __io {
    FILE* setIn(string s) { return freopen(s.c_str(),"r",stdin); }
    FILE* setOut(string s) { return freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        cout << setprecision(15);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
}
using namespace __io;





using v_t = int;
using vv_t = ll;
template<v_t MOD> struct modnum {
    static_assert(numeric_limits<v_t>::max() / 2 >= MOD, "Addition overflows v_t");
    static_assert(numeric_limits<vv_t>::max() / MOD >= MOD, "Multiplication overflows vv_t");

    v_t v;
    modnum() : v(0) {}
    modnum(vv_t _v) : v(v_t(_v % MOD)) { if (v < 0) v += MOD; }
    explicit operator v_t() const { return v; }
    friend istream& operator >> (istream& i, modnum& n) { vv_t w; i >> w; n = modnum(w); return i; }
    friend ostream& operator << (ostream& o, const modnum& n) { return o << n.v; }

    friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {

        return unsigned(x % m);

        

        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x), quot, rem;
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



enum DIVISOR_TYPE { ALL, SQUARE_FREE };
template<int MAXV> struct sieve {
    vi primes;
    struct num {
        int  least_prime;       

        int  div_least_prime;   

        char lp_multiplicity;   

        char mu;                

        int  phi;               


        static num ONE() { return { INT_MAX, 1, 0, 1, 1}; }

        num prod(int my_value, int p) const {
            if (p < least_prime)
                return { p, my_value, 1, char(-mu), phi * (p - 1) };
            assert(p == least_prime);
            return { p, my_value, char(lp_multiplicity + 1), 0, phi * p };
        }
    };
    vector<num> nums;
    const num& operator[](int i){ return nums[i]; }

    sieve() : nums(MAXV) {
        nums[1] = num::ONE();
        for (int v = 2; v < MAXV; v++) {
            num& n = nums[v];
            if (!n.least_prime) {
                n = nums[1].prod(1, v);
                primes.pb(v);
            }
            for (int p : primes) {
                if (p > n.least_prime || v * p >= MAXV) break;
                nums[v * p] = n.prod(v, p);
            }
        }
    }

    bool is_prime(int v) const {
        assert(0 < v && v < MAXV);
        return nums[v].least_prime == v;
    }

    int eliminate_least_prime(int v) const {
        assert(1 < v && v < MAXV);
        for (int m = nums[v].lp_multiplicity; m > 0; m--)
            v = nums[v].div_least_prime;
        return v;
    }

    const vpii& factor(int v) const {
        assert(0 < v && v < MAXV);
        static vpii res; res.clear();
        for (; v > 1; v = eliminate_least_prime(v))
            res.emplace_back(nums[v].least_prime, nums[v].lp_multiplicity);
        reverse(all(res));
        return res;
    }

    template<typename F> void id2(int v, F f,
            DIVISOR_TYPE t = ALL, int d = 1) const {
        assert(0 < v && v < MAXV);
        if (v == 1) { f(d); return; }
        int w = eliminate_least_prime(v);
        char M = min(nums[v].lp_multiplicity, char(t == ALL ? CHAR_MAX : 1));
        for (int m = 0; m <= M; m++, d *= nums[v].least_prime) {
            id2(w, f, t, d);
        }
    }

    const vi& unordered_divisors(int v, DIVISOR_TYPE t = ALL) const {
        assert(0 < v && v < MAXV);
        static vi res; res.clear();
        id2(v, [&](int d) { res.pb(d); }, t);
        return res;
    }
};



const int MAXV = 2e5 + 1;
sieve<MAXV> sv;



template<typename T, typename F, typename I = int>
struct id3 {
    struct node {
        T val;
        size_t left, right;
    };
    struct snapshot {
        I when;
        size_t root;
        size_t data_size;
        bool operator < (const snapshot &o) const { return when < o.when; }
    };

    int SZ; T tid; F tt;
    vector<node> data;
    vector<snapshot> history;

    id3() {}
    id3(int SZ_, T tid_, F tt_) : tid(tid_), tt(tt_) {
        SZ = 1 << (32 - __builtin_clz(SZ_ - 1));

        data.push_back({ tid, 0, 0 });
        for (size_t loc = 1; loc <= __builtin_clz(SZ); loc++)
            data.push_back({ tt(data[loc - 1].val, data[loc - 1].val), loc - 1, loc - 1 });

        history.push_back({ numeric_limits<I>::min(), data.size() - 1, data.size() });
    }

    void replace           (int i, T val, I when) { __modify_leaf(i, val, when, true ); }
    void combine_and_assign(int i, T val, I when) { __modify_leaf(i, val, when, false); }

    void __modify_leaf(int i, T v, I w, bool replace) {
        assert(0 <= i && i < SZ && history.back().when <= w);

        size_t current_root = history.back().root;
        if (history.back().when == w) history.pop_back();

        size_t immutable = history.back().data_size;
        size_t updated_root = __modify_leaf(i, v, current_root, 0, SZ, immutable, replace);
        history.push_back({ w, updated_root, data.size() });
    }
    size_t __modify_leaf(int i, T v, size_t loc, int L, int R, size_t immutable, bool replace) {
        node updated;
        if (R - L == 1) {
            updated = { replace ? v : tt(data[loc].val, v), 0, 0 };
        } else {
            int M = L + (R - L) / 2;
            size_t left  = i <  M ? __modify_leaf(i, v, data[loc].left,  L, M, immutable, replace) : data[loc].left;
            size_t right = M <= i ? __modify_leaf(i, v, data[loc].right, M, R, immutable, replace) : data[loc].right;
            updated = { tt(data[left].val, data[right].val), left, right };
        }
        if (loc < immutable) {
            loc = data.size();
            data.push_back(updated);
        } else {
            data[loc] = updated;
        }
        return loc;
    }

    

    T accumulate(int i, int j, I w) const {
        if (i >= j) return tid;
        assert(0 <= i && j <= SZ);
        size_t id0 = prev(lower_bound(history.begin(), history.end(), snapshot{ w, 0, 0 }))->root;
        return __accumulate(i, j, tid, id0, 0, SZ);
    }
    T __accumulate(int i, int j, T init, size_t loc, int L, int R) const {
        if (L == i && j == R) {
            init = tt(init, data[loc].val);
        } else {
            int M = L + (R - L) / 2;
            if (i < M) init = __accumulate(i, min(j, M), init, data[loc].left,  L, M);
            if (M < j) init = __accumulate(max(i, M), j, init, data[loc].right, M, R);
        }
        return init;
    }
};



int main() {
    setIO();

    int N; re(N); vi a(N); re(a);

    auto prod = [](mn a, mn b) { return a * b; };
    id3<mn, decltype(prod)> st(N, mn(1), prod);

    vector<vector<pii>> locs(MAXV);

    int LG = 0;
    while ((1 << LG) < N) LG++;

    id1 (i, N) {
        trav (pf, sv.factor(a[i])) {
            auto [p, m] = pf;

            int tf = 0;
            while (!locs[p].empty() && tf + locs[p].back().s <= m) {
                auto [inx, inx_ct] = locs[p].back();
                st.combine_and_assign(inx, mn::small_inv(p).pow(inx_ct), i);
                tf += inx_ct;
                locs[p].pop_back();
            }

            if (tf < m && !locs[p].empty()) {
                auto [inx, inx_ct] = locs[p].back();
                int new_ct = tf + inx_ct - m;
                assert(new_ct < inx_ct);
                st.combine_and_assign(inx, mn::small_inv(p).pow(inx_ct - new_ct), i);
                locs[p].pop_back();
                locs[p].push_back({ inx, new_ct });
            }

            locs[p].push_back({ i, m });
            st.combine_and_assign(i, mn(p).pow(m), i);
        }
    }

    int Q; re(Q);
    int last = 0;
    id1 (q, Q) {
        int x, y; re(x, y);
        x = (x + last) % N + 1;
        y = (y + last) % N + 1;
        if (x > y) swap(x, y);
        --x;
        ps(last = st.accumulate(x, y, y).v);
    }

    return 0;
}
