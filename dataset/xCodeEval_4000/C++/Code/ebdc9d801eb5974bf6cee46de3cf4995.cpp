






































































































































#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double; 

using str = string;     




using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
#define mp make_pair
#define f first
#define s second

#define tcT template <class T
#define tcTU tcT, class U


tcT > using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;





#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()

#define lb lower_bound
#define ub upper_bound
tcT > int lwb(V<T> &a, const T &b)
{
    return int(lb(all(a), b) - bg(a));
}
tcT > int upb(V<T> &a, const T &b) { return int(ub(all(a), b) - bg(a)); }



#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)
#define each(a, x) for (auto &a : x)

const int MOD = 1e9 + 7; 

const int MX = 2e5 + 5;
const ll BIG = 1e18; 

const db PI = acos((db)-1);
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1}; 

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;





constexpr int pct(int x) { return __builtin_popcount(x); } 

constexpr int bits(int x)
{ 

    return x == 0 ? 0 : 31 - __builtin_clz(x);
} 

constexpr int p2(int x) { return 1 << x; }
constexpr int msk2(int x) { return p2(x) - 1; }

ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } 

ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); } 


tcT > bool ckmin(T &a, const T &b)
{
    return b < a ? a = b, 1 : 0;
} 

tcT > bool ckmax(T &a, const T &b)
{
    return a < b ? a = b, 1 : 0;
} 


tcTU > T fstTrue(T lo, T hi, U f)
{
    ++hi;
    assert(lo <= hi); 

    while (lo < hi)
    { 

        T mid = lo + (hi - lo) / 2;
        f(mid) ? hi = mid : lo = mid + 1;
    }
    return lo;
}
tcTU > T lstTrue(T lo, T hi, U f)
{
    --lo;
    assert(lo <= hi); 

    while (lo < hi)
    { 

        T mid = lo + (hi - lo + 1) / 2;
        f(mid) ? lo = mid : hi = mid - 1;
    }
    return lo;
}
tcT > void remDup(vector<T> &v)
{ 

    sort(all(v));
    v.erase(unique(all(v)), end(v));
}
tcTU > void erase(T &t, const U &u)
{ 

    auto it = t.find(u);
    assert(it != end(t));
    t.erase(it);
} 


#define tcTUU tcT, class... U

inline namespace Helpers
{
    

    

    

    tcT, class = void > struct is_iterable : false_type
    {
    };
    tcT > struct is_iterable<T, void_t<decltype(begin(declval<T>())),
                                       decltype(end(declval<T>()))>> : true_type
    {
    };
    tcT > constexpr bool is_iterable_v = is_iterable<T>::value;

    

    tcT, class = void > struct is_readable : false_type
    {
    };
    tcT > struct is_readable<T,
                             typename std::enable_if_t<
                                 is_same_v<decltype(cin >> declval<T &>()), istream &>>> : true_type
    {
    };
    tcT > constexpr bool is_readable_v = is_readable<T>::value;

    

    

    tcT, class = void > struct is_printable : false_type
    {
    };
    tcT > struct is_printable<T,
                              typename std::enable_if_t<
                                  is_same_v<decltype(cout << declval<T>()), ostream &>>> : true_type
    {
    };
    tcT > constexpr bool is_printable_v = is_printable<T>::value;
}

inline namespace Input
{
    tcT > constexpr bool needs_input_v = !is_readable_v<T> && is_iterable_v<T>;
    tcTUU > void re(T &t, U &...u);
    tcTU > void re(pair<T, U> &p); 


    

    tcT > typename enable_if<is_readable_v<T>, void>::type re(T &x) { cin >> x; } 

    tcT > void re(complex<T> &c)
    {
        T a, b;
        re(a, b);
        c = {a, b};
    }                                                                

    tcT > typename enable_if<needs_input_v<T>, void>::type re(T &i); 

    tcTU > void re(pair<T, U> &p) { re(p.f, p.s); }
    tcT > typename enable_if<needs_input_v<T>, void>::type re(T &i)
    {
        each(x, i) re(x);
    }
    tcTUU > void re(T &t, U &...u)
    {
        re(t);
        re(u...);
    } 


    

    void rv(size_t) {}
    tcTUU > void rv(size_t N, V<T> &t, U &...u);
    template <class... U>
    void rv(size_t, size_t N2, U &...u);
    tcTUU > void rv(size_t N, V<T> &t, U &...u)
    {
        t.rsz(N);
        re(t);
        rv(N, u...);
    }
    template <class... U>
    void rv(size_t, size_t N2, U &...u)
    {
        rv(N2, u...);
    }

    

    void decrement() {} 

    tcTUU > void decrement(T &t, U &...u)
    {
        --t;
        decrement(u...);
    }
#define ints(...)    \
    int __VA_ARGS__; \
    re(__VA_ARGS__);
#define int1(...)      \
    ints(__VA_ARGS__); \
    decrement(__VA_ARGS__);
}

inline namespace ToString
{
    tcT > constexpr bool needs_output_v = !is_printable_v<T> && is_iterable_v<T>;

    

    tcT > typename enable_if<is_printable_v<T>, str>::type ts(T v)
    {
        stringstream ss;
        ss << fixed << setprecision(15) << v;
        return ss.str();
    } 

    tcT > str bit_vec(T t)
    { 

        str res = "{";
        F0R(i, sz(t))
        res += ts(t[i]);
        res += "}";
        return res;
    }
    str ts(V<bool> v) { return bit_vec(v); }
    template <size_t SZ>
    str ts(bitset<SZ> b) { return bit_vec(b); }                     

    tcTU > str ts(pair<T, U> p);                                    

    tcT > typename enable_if<needs_output_v<T>, str>::type ts(T v); 

    tcTU > str ts(pair<T, U> p) { return "(" + ts(p.f) + ", " + ts(p.s) + ")"; }
    tcT > typename enable_if<is_iterable_v<T>, str>::type ts_sep(T v, str sep)
    {
        

        bool fst = 1;
        str res = "";
        for (const auto &x : v)
        {
            if (!fst)
                res += sep;
            fst = 0;
            res += ts(x);
        }
        return res;
    }
    tcT > typename enable_if<needs_output_v<T>, str>::type ts(T v)
    {
        return "{" + ts_sep(v, ", ") + "}";
    }

    

    template <int, class T>
    typename enable_if<!needs_output_v<T>, vs>::type
    ts_lev(const T &v) { return {ts(v)}; }
    template <int lev, class T>
    typename enable_if<needs_output_v<T>, vs>::type
    ts_lev(const T &v)
    {
        if (lev == 0 || !sz(v))
            return {ts(v)};
        vs res;
        for (const auto &t : v)
        {
            if (sz(res))
                res.bk += ",";
            vs tmp = ts_lev<lev - 1>(t);
            res.ins(end(res), all(tmp));
        }
        F0R(i, sz(res))
        {
            str bef = " ";
            if (i == 0)
                bef = "{";
            res[i] = bef + res[i];
        }
        res.bk += "}";
        return res;
    }
}

inline namespace Output
{
    template <class T>
    void pr_sep(ostream &os, str, const T &t) { os << ts(t); }
    template <class T, class... U>
    void pr_sep(ostream &os, str sep, const T &t, const U &...u)
    {
        pr_sep(os, sep, t);
        os << sep;
        pr_sep(os, sep, u...);
    }
    

    template <class... T>
    void pr(const T &...t) { pr_sep(cout, "", t...); }
    

    void ps() { cout << "\n"; }
    template <class... T>
    void ps(const T &...t)
    {
        pr_sep(cout, " ", t...);
        ps();
    }
    

    template <class... T>
    void dbg_out(const T &...t)
    {
        pr_sep(cerr, " | ", t...);
        cerr << endl;
    }
    void loc_info(int line, str names)
    {
        cerr << "Line(" << line << ") -> [" << names << "]: ";
    }
    template <int lev, class T>
    void dbgl_out(const T &t)
    {
        cerr << "\n\n"
             << ts_sep(ts_lev<lev>(t), "\n") << "\n"
             << endl;
    }
#ifdef LOCAL
#define dbg(...) loc_info(__LINE__, #__VA_ARGS__), dbg_out(__VA_ARGS__)
#define dbgl(lev, x) loc_info(__LINE__, #x), dbgl_out<lev>(x)
#else 

#define dbg(...) 0
#define dbgl(lev, x) 0
#endif

    const clock_t beg = clock();
#define dbg_time() dbg((db)(clock() - beg) / CLOCKS_PER_SEC)
}

inline namespace FileIO
{
    void setIn(str s) { freopen(s.c_str(), "r", stdin); }
    void setOut(str s) { freopen(s.c_str(), "w", stdout); }
    void setIO(str s = "")
    {
        cin.tie(0)->sync_with_stdio(0); 

        

        

        

        if (sz(s))
            setIn(s + ".in"), setOut(s + ".out"); 

    }
}



template <int MOD, int RT>
struct mint
{
    static const int mod = MOD;
    static constexpr mint rt() { return RT; } 

    int v;
    explicit operator int() const { return v; } 

    mint() : v(0) {}
    mint(ll _v)
    {
        v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
        if (v < 0)
            v += MOD;
    }
    bool operator==(const mint &o) const
    {
        return v == o.v;
    }
    friend bool operator!=(const mint &a, const mint &b)
    {
        return !(a == b);
    }
    friend bool operator<(const mint &a, const mint &b)
    {
        return a.v < b.v;
    }
    friend void re(mint &a)
    {
        ll x;
        re(x);
        a = mint(x);
    }
    friend str ts(mint a) { return ts(a.v); }

    mint &operator+=(const mint &o)
    {
        if ((v += o.v) >= MOD)
            v -= MOD;
        return *this;
    }
    mint &operator-=(const mint &o)
    {
        if ((v -= o.v) < 0)
            v += MOD;
        return *this;
    }
    mint &operator*=(const mint &o)
    {
        v = int((ll)v * o.v % MOD);
        return *this;
    }
    mint &operator/=(const mint &o) { return (*this) *= inv(o); }
    friend mint pow(mint a, ll p)
    {
        mint ans = 1;
        assert(p >= 0);
        for (; p; p /= 2, a *= a)
            if (p & 1)
                ans *= a;
        return ans;
    }
    friend mint inv(const mint &a)
    {
        assert(a.v != 0);
        return pow(a, MOD - 2);
    }

    mint operator-() const { return mint(-v); }
    mint &operator++() { return *this += 1; }
    mint &operator--() { return *this -= 1; }
    friend mint operator+(mint a, const mint &b) { return a += b; }
    friend mint operator-(mint a, const mint &b) { return a -= b; }
    friend mint operator*(mint a, const mint &b) { return a *= b; }
    friend mint operator/(mint a, const mint &b) { return a /= b; }
};

using mi = mint<MOD, 5>; 

using vmi = V<mi>;
using pmi = pair<mi, mi>;
using vpmi = V<pmi>;

V<vmi> scmb; 

void genComb(int SZ)
{
    scmb.assign(SZ, vmi(SZ));
    scmb[0][0] = 1;
    FOR(i, 1, SZ)
    F0R(j, i + 1)
    scmb[i][j] = scmb[i - 1][j] + (j ? scmb[i - 1][j - 1] : 0);
}

int N, K;
vi A;

bool is_neg(int x) { return x < 0; }

mi neg_even()
{
    mi ans = 0;
    V<AR<mi, 2>> dp{{1, 0}};
    R0F(i, N)
    {
        V<AR<mi, 2>> ndp = dp;
        ndp.eb();
        F0R(cur_size, sz(dp))
        F0R(p, 2)
        {
            if (cur_size < K)
            {
                ndp.at(cur_size + 1).at(p ^ is_neg(A[i])) += dp.at(cur_size).at(p) * A.at(i);
            }
            else
            {
                ndp.at(cur_size + 1).at(p) += dp.at(cur_size).at(p);
            }
        }
        swap(dp, ndp);
    }
    FOR(i, K, sz(dp))
    ans += dp.at(i).at(0);
    return ans;
}

mi neg_odd()
{
    mi ans = 0;
    if (K & 1)
    {
        { 

            vmi dp(K + 1);
            dp.at(0) = 1;
            F0R(i, N)
            if (is_neg(A[i]))
            {
                vmi ndp = dp;
                ndp.eb();
                F0R(cur_size, K + 1)
                {
                    if (cur_size < K)
                    {
                        ndp.at(cur_size + 1) += dp.at(cur_size) * A.at(i);
                    }
                    else
                    {
                        ndp.at(cur_size) += dp.at(cur_size);
                    }
                }
                swap(dp, ndp);
            }
            ans += dp.at(K);
        }
        { 

            vmi dp(K + 2);
            dp[0] = 1;
            R0F(i, N)
            {
                vmi ndp = dp;
                if (is_neg(A[i]))
                {
                    F0R(j, K - 1)
                    ndp[j + 1] += dp[j] * A[i];
                    ndp[K] += dp[K - 1];
                    ndp[K] += dp[K];
                    ndp[K + 1] += dp[K + 1];
                }
                else
                {
                    ndp[K + 1] += dp[K] * A[i];
                    ndp[K + 1] += dp[K + 1];
                }
                swap(dp, ndp);
            }
            ans += dp.at(K + 1);
        }
    }
    

    V<AR<mi, 2>> dp(K);
    dp[0] = {1, 0};
    vi num_below(N);
    F0R(i, N)
    {
        int j = i - 1;
        while (j >= 0 && is_neg(A[j]) != is_neg(A[i]))
            --j;
        if (j != -1)
        {
            num_below.at(i) = num_below.at(j) + 1;
        }
    }
    

    vmi po2(N + 1);
    po2[0] = 1;
    FOR(i, 1, N + 1)
    po2[i] = po2[i - 1] * 2;
    V<V<tuple<int, mi>>> tuples(N);
    R0F(i, N)
    {
        {
            

            vmi count(K);
            if (is_neg(A[i]))
            {
                F0R(j, K - 1)
                count.at(j + 1) = dp.at(j).at(0);
            }
            else
            {
                F0R(j, K - 1)
                {
                    count.at(j + 1) = dp.at(j).at(((K - 1 - j) & 1) ^ 1);
                }
            }
            

            R0F(i2, i)
            if (is_neg(A[i2]) != is_neg(A[i]))
            {
                R0F(j, K)
                {
                    if (j == K - 1)
                    {
                        

                        

                        ans += count.at(j) * A.at(i) * A.at(i2);
                        F0R(x, i2)
                        if (is_neg(A.at(x)) == is_neg(A.at(i)))
                        {
                            ans += count.at(j) * A.at(x) * A.at(i) * po2[num_below.at(x)];
                        }
                        F0R(y, i2)
                        if (is_neg(A.at(y)) == is_neg(A.at(i2)))
                        {
                            ans += count.at(j) * A.at(y) * A.at(i2) * po2[num_below.at(y)];
                        }
                        tuples.at(i2).pb({i, count.at(j)});
                    }
                    else
                    {
                        count.at(j + 1) += count.at(j) * A.at(i2);
                    }
                }
            }
        }
        R0F(j, K - 1)
        F0R(p, 2)
        {
            dp.at(j + 1).at(p ^ is_neg(A[i])) += dp.at(j).at(p) * A.at(i);
        }
    }
    F0R(i2, N)
    {
        vi all_y;
        F0R(y, i2)
        if (is_neg(A.at(y)) == is_neg(A.at(i2)))
            all_y.pb(y);
        for (auto [i, contrib] : tuples[i2])
        {
            mi tot_sum_y = 0;
            for (int y : all_y)
                tot_sum_y += A.at(y) * po2[num_below.at(y)];
            mi tot_sum_po = 0;
            int iy = 0;
            F0R(x, i2)
            if (is_neg(A.at(x)) == is_neg(A.at(i)))
            { 

                for (; iy < sz(all_y) && (ll)A.at(x) * A.at(i) > (ll)A.at(all_y.at(iy)) * A.at(i2); ++iy)
                {
                    const int y = all_y.at(iy);
                    tot_sum_y -= A.at(y) * po2[num_below.at(y)];
                    tot_sum_po += po2[num_below.at(y)];
                }
                ans += contrib * po2[num_below.at(x)] * tot_sum_y * A.at(i2);
                ans += contrib * po2[num_below.at(x)] * A.at(x) * A.at(i) * tot_sum_po;
                

                

                

                

                

                

                

                

                

                

                

                

                

                

            }
        }
    }
    return ans;
}

int main()
{
    setIO();
    re(N, K);
    A.rsz(N);
    re(A);
    sort(all(A), [](int x, int y)
         { return abs(x) < abs(y); });
    mi ans_even = neg_even();
    mi ans_odd = neg_odd();
    ps(ans_even + ans_odd);
}
