#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;


#define FOR(i,l,r) for (ll i = (l); i < (r); ++i)
#define RFOR(i,l,r) for (ll i = (r)-1; (l) <= i; --i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(c) (c).begin(), (c).end()
#define RALL(c) (c).rbegin(), (c).rend()
#define SORT(c) sort(ALL(c))
#define RSORT(c) sort(RALL(c))
#define MIN(c) *min_element(ALL(c))
#define MAX(c) *max_element(ALL(c))
#define COUNT(c,v) count(ALL(c),(v))
#define SZ(c) ((ll)(c).size())
#define BIT(b,i) (((b)>>(i)) & 1)
#define PCNT(b) ((ll)__builtin_popcountll(b))
#define P0(i) (((i) & 1) == 0)
#define P1(i) (((i) & 1) == 1)
#define LB(c,v) distance((c).begin(), lower_bound(ALL(c), (v)))
#define UB(c,v) distance((c).begin(), upper_bound(ALL(c), (v)))
#define UQ(c) do { SORT(c); (c).erase(unique(ALL(c)), (c).end()); } while (0)
#define END(...) do { print(__VA_ARGS__); exit(0); } while (0)
#define elif else if
template<class T> using PQ_max = priority_queue<T>;
template<class T> using PQ_min = priority_queue<T, vector<T>, greater<T>>;
constexpr int inf = (1 << 30) - 1;   

constexpr ll INF = (1LL << 62) - 1;  

#ifdef _LOCAL
    #define debug_bar cerr << "----------------------------------------\n";
    #define debug_header cerr << "[" << __FUNCTION__ << ":" << __LINE__ << "] "
    #define debug(...) do { debug_header; cerr << #__VA_ARGS__ << " = "; view(__VA_ARGS__); cerr << '\n'; } while (0)
    #define debug2(vv) do { debug_header; cerr << #vv << " = [\n"; view2d(vv); cerr << "  ]\n"; } while (0)
    #define debug3(vvv) do { debug_header; cerr << #vvv << " = [\n"; view3d(vvv); cerr << "  ]\n"; } while (0)
    void view() {}
    void view(const int& a) { if (abs(a) == inf) { cerr << "+-"[signbit(a)] << "inf"; } else { cerr << a; } }
    void view(const ll& a) { if (abs(a) == INF) { cerr << "+-"[signbit(a)] << "INF"; } else { cerr << a; } }
    template<class T> void view(const T& a) { cerr << a; }
    template<class P1, class P2> void view(const pair<P1, P2>& a) { cerr << "("; view(a.first); cerr << ", "; view(a.second); cerr << ")"; }
    template<class T1, class T2, class T3> void view(const tuple<T1, T2, T3>& a) { cerr << "("; view(get<0>(a)); cerr << ", "; view(get<1>(a)); cerr << ", "; view(get<2>(a)); cerr << ")"; }
    template<class T1, class T2, class T3, class T4> void view(const tuple<T1, T2, T3, T4>& a) { cerr << "("; view(get<0>(a)); cerr << ", "; view(get<1>(a)); cerr << ", "; view(get<2>(a)); cerr << ", "; view(get<3>(a)); cerr << ")"; }
    template<class T> void view(const vector<T>& v){ cerr << "["; for (int i = 0; i < (int)v.size(); i++) { if (i) { cerr << ", "; } view(v[i]); } cerr << "]"; }
    template<class T> void view(const vector<vector<T>>& vv){ cerr << "["; for (int i = 0; i < (int)vv.size(); i++) { if (i) { cerr << ", "; } view(vv[i]); } cerr << "]"; }
    template<class K, class V> void view(const map<K, V>& mp){ cerr << "["; for (auto it = mp.begin(); it != mp.end(); it++) { if (it != mp.begin()) { cerr << ", "; } cerr << "("; view(it->first); cerr << ", "; view(it->second); cerr << ")"; } cerr << "]"; }
    template<class K, class V> void view(const multimap<K, V>& mmp){ cerr << "["; for (auto it = mmp.begin(); it != mmp.end(); it++) { if (it != mmp.begin()) { cerr << ", "; } cerr << "("; view(it->first); cerr << ", "; view(it->second); cerr << ")"; } cerr << "]"; }
    template<class T> void view(const set<T>& s){ cerr << "["; for (auto it = s.begin(); it != s.end(); it++) { if (it != s.begin()) { cerr << ", "; } view(*it); } cerr << "]"; }
    template<class T> void view(const multiset<T>& ms){ cerr << "["; for (auto it = ms.begin(); it != ms.end(); it++) { if (it != ms.begin()) { cerr << ", "; } view(*it); } cerr << "]"; }
    template<class T> void view(const deque<T>& d){ cerr << "(front)<-["; for (auto it = d.begin(); it != d.end(); it++) { if (it != d.begin()) { cerr << ", "; } view(*it); } cerr << "]"; }
    template<class T> void view(stack<T> s){ vector<T> v; while (not s.empty()) { v.push_back(s.top()); s.pop(); } reverse(v.begin(), v.end()); view(v); cerr << "->(top)"; }
    template<class T> void view(queue<T> q){ vector<T> v; while (not q.empty()) { v.push_back(q.front()); q.pop(); } cerr << "(front)<-"; view(v); }
    template<class T> void view(PQ_max<T> pq){ vector<T> v; while (not pq.empty()) { v.push_back(pq.top()); pq.pop(); } cerr << "(top)<-"; view(v); }
    template<class T> void view(PQ_min<T> pq){ vector<T> v; while (not pq.empty()) { v.push_back(pq.top()); pq.pop(); } cerr << "(top)<-"; view(v); }
    template<class T> void view2d(const vector<vector<T>>& vv){ for (int i = 0; i < (int)vv.size(); i++) { cerr << "    "; view(vv[i]); cerr << ",\n"; } }
    template<class T> void view3d(const vector<vector<vector<T>>>& vvv) { for (int i = 0; i < (int)vvv.size(); i++) { for (int j = 0; j < (int)vvv[i].size(); j++) { cerr << "    " << " ["[j == 0]; view(vvv[i][j]); if (j == (int)vvv[i].size() - 1) { cerr << "]"; } cerr << ",\n"; } if (i < (int)vvv.size() - 1) { cerr << "\n"; } } }
    template<class T, class... Ts> void view(const T& a, const Ts&... b) { view(a); cerr << ", "; view(b...); }
#else
    #define cerr if (false) cerr
    #define debug_bar
    #define debug(...)
    #define debug2(vv)
    #define debug3(vvv)
#endif
template<class... T> void input(T&... a) { (cin >> ... >> a); }
void print() { cout << '\n'; }
template<class T> void print(const T& a) { cout << a << '\n'; }
template<class T, class... Ts> void print(const T& a, const Ts&... b) { cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }
template<class T> void cout_line(const vector<T>& ans, int l, int r) { for (int i = l; i < r; i++) { if (i != l) { cout << ' '; } cout << ans[i]; } cout << '\n'; }
template<class T> bool chmin(T& a, const T b) { if (b < a) { a = b; return 1; } return 0; }
template<class T> bool chmax(T& a, const T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> T SUM(const vector<T>& A) { return accumulate(ALL(A), T(0)); }
template<class T> vector<T> cumsum(const vector<T>& A, bool offset = false) { int N = A.size(); vector<T> S(N+1, 0); for (int i = 0; i < N; i++) { S[i+1] = S[i] + A[i]; } if (not offset) { S.erase(S.begin()); } return S; }
template<class T> string to_binary(T x, int B) { string s; while (x) { s += ('0' + (x & 1)); x >>= 1; } while ((int)s.size() < B) { s += '0'; } reverse(s.begin(), s.end()); return s; }
ll min(int a, ll b) { return min((ll)a, b); }
ll min(ll a, int b) { return min(a, (ll)b); }
ll max(int a, ll b) { return max((ll)a, b); }
ll max(ll a, int b) { return max(a, (ll)b); }
ll mod(ll x, ll m) { assert(m != 0); return (x % m + m) % m; }
ll ceil(ll a, ll b) { if (b < 0) { return ceil(-a, -b); } assert(b > 0); return (a < 0 ? a / b : (a + b - 1) / b); }
ll floor(ll a, ll b) { if (b < 0) { return floor(-a, -b); } assert(b > 0); return (a > 0 ? a / b : (a - b + 1) / b); }
ll powint(ll x, ll n) { assert(n >= 0); if (n == 0) { return 1; }; ll res = powint(x, n>>1); res *= res; if (n & 1) { res *= x; } return res; }
pair<ll,ll> divmod(ll a, ll b) { assert(b != 0); ll q = floor(a, b); return make_pair(q, a - q * b); }
ll bitlen(ll b) { if (b <= 0) { return 0; } return (64LL - __builtin_clzll(b)); }
ll digit_len(ll n) { assert(n >= 0); if (n == 0) { return 1; } ll sum = 0; while (n > 0) { sum++; n /= 10; } return sum; }
ll digit_sum(ll n) { assert(n >= 0); ll sum = 0; while (n > 0) { sum += n % 10; n /= 10; } return sum; }
ll digit_prod(ll n) { assert(n >= 0); if (n == 0) { return 0; } ll prod = 1; while (n > 0) { prod *= n % 10; n /= 10; } return prod; }
ll xor_sum(ll x) { assert(0 <= x); switch (x % 4) { case 0: return x; case 1: return 1; case 2: return x ^ 1; case 3: return 0; } assert(false); }
string toupper(const string& S) { string T(S); for (int i = 0; i < (int)T.size(); i++) { T[i] = toupper(T[i]); } return T; }
string tolower(const string& S) { string T(S); for (int i = 0; i < (int)T.size(); i++) { T[i] = tolower(T[i]); } return T; }
int a2i(const char& c) { assert(islower(c)); return (c - 'a'); }
int A2i(const char& c) { assert(isupper(c)); return (c - 'A'); }
int d2i(const char& d) { assert(isdigit(d)); return (d - '0'); }
char i2a(const int& i) { assert(0 <= i && i < 26); return ('a' + i); }
char i2A(const int& i) { assert(0 <= i && i < 26); return ('A' + i); }
char i2d(const int& i) { assert(0 <= i && i <= 9); return ('0' + i); }
using P = pair<ll,ll>;
using VP = vector<P>;
using VVP = vector<VP>;
using VS = vector<string>;
using VVS = vector<VS>;
using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
using VLL = vector<ll>;
using VVLL = vector<VLL>;
using VVVLL = vector<VVLL>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VVVB = vector<VVB>;
using VD = vector<double>;
using VVD = vector<VD>;
using VVVD = vector<VVD>;
using VLD = vector<ld>;
using VVLD = vector<VLD>;
using VVVLD = vector<VVLD>;
const ld EPS = 1e-10;
const ld PI  = acosl(-1.0);









#include <cassert>
#include <numeric>
#include <type_traits>

#ifdef _MSC_VER
#include <intrin.h>
#endif


#include <utility>

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

constexpr long long safe_mod(long long x, long long m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

struct barrett {
    unsigned int _m;
    unsigned long long im;

    explicit barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}

    unsigned int umod() const { return _m; }

    unsigned int mul(unsigned int a, unsigned int b) const {

        unsigned long long z = a;
        z *= b;
#ifdef _MSC_VER
        unsigned long long x;
        _umul128(z, im, &x);
#else
        unsigned long long x =
            (unsigned long long)(((unsigned __int128)(z)*im) >> 64);
#endif
        unsigned int v = (unsigned int)(z - x * _m);
        if (_m <= v) v += _m;
        return v;
    }
};

constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
    if (m == 1) return 0;
    unsigned int _m = (unsigned int)(m);
    unsigned long long r = 1;
    unsigned long long y = safe_mod(x, m);
    while (n) {
        if (n & 1) r = (r * y) % _m;
        y = (y * y) % _m;
        n >>= 1;
    }
    return r;
}

constexpr bool is_prime_constexpr(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    constexpr long long bases[3] = {2, 7, 61};
    for (long long a : bases) {
        long long t = d;
        long long y = pow_mod_constexpr(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = y * y % n;
            t <<= 1;
        }
        if (y != n - 1 && t % 2 == 0) {
            return false;
        }
    }
    return true;
}
template <int n> constexpr bool is_prime = is_prime_constexpr(n);

constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
    a = safe_mod(a, b);
    if (a == 0) return {b, 0};

    long long s = b, t = a;
    long long m0 = 0, m1 = 1;

    while (t) {
        long long u = s / t;
        s -= t * u;
        m0 -= m1 * u;  



        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    if (m0 < 0) m0 += b / s;
    return {s, m0};
}

constexpr int primitive_root_constexpr(int m) {
    if (m == 2) return 1;
    if (m == 167772161) return 3;
    if (m == 469762049) return 3;
    if (m == 754974721) return 11;
    if (m == 998244353) return 3;
    int divs[20] = {};
    divs[0] = 2;
    int cnt = 1;
    int x = (m - 1) / 2;
    while (x % 2 == 0) x /= 2;
    for (int i = 3; (long long)(i)*i <= x; i += 2) {
        if (x % i == 0) {
            divs[cnt++] = i;
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        divs[cnt++] = x;
    }
    for (int g = 2;; g++) {
        bool ok = true;
        for (int i = 0; i < cnt; i++) {
            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}
template <int m> constexpr int primitive_root = primitive_root_constexpr(m);

unsigned long long floor_sum_unsigned(unsigned long long n,
                                      unsigned long long m,
                                      unsigned long long a,
                                      unsigned long long b) {
    unsigned long long ans = 0;
    while (true) {
        if (a >= m) {
            ans += n * (n - 1) / 2 * (a / m);
            a %= m;
        }
        if (b >= m) {
            ans += n * (b / m);
            b %= m;
        }

        unsigned long long y_max = a * n + b;
        if (y_max < m) break;
        n = (unsigned long long)(y_max / m);
        b = (unsigned long long)(y_max % m);
        std::swap(m, a);
    }
    return ans;
}

}  


}  



#include <cassert>
#include <numeric>
#include <type_traits>

namespace atcoder {

namespace internal {

#ifndef _MSC_VER
template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value,
                              __uint128_t,
                              unsigned __int128>;

template <class T>
using is_integral = typename std::conditional<std::is_integral<T>::value ||
                                                  is_signed_int128<T>::value ||
                                                  is_unsigned_int128<T>::value,
                                              std::true_type,
                                              std::false_type>::type;

template <class T>
using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                 std::is_signed<T>::value) ||
                                                    is_signed_int128<T>::value,
                                                std::true_type,
                                                std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value,
    make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value,
                              std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;

#else

template <class T> using is_integral = typename std::is_integral<T>;

template <class T>
using is_signed_int =
    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<is_integral<T>::value &&
                                  std::is_unsigned<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<is_signed_int<T>::value,
                                              std::make_unsigned<T>,
                                              std::common_type<T>>::type;

#endif

template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

}  


}  



namespace atcoder {

namespace internal {

struct modint_base {};
struct static_modint_base : modint_base {};

template <class T> using is_modint = std::is_base_of<modint_base, T>;
template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;

}  


template <int m, std::enable_if_t<(1 <= m)>* = nullptr>
struct static_modint : internal::static_modint_base {
    using mint = static_modint;

  public:
    static constexpr int mod() { return m; }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    static_modint() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    static_modint(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    static_modint(T v) {
        _v = (unsigned int)(v % umod());
    }

    unsigned int val() const { return _v; }

    mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v -= rhs._v;
        if (_v >= umod()) _v += umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        unsigned long long z = _v;
        z *= rhs._v;
        _v = (unsigned int)(z % umod());
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        if (prime) {
            assert(_v);
            return pow(umod() - 2);
        } else {
            auto eg = internal::inv_gcd(_v, m);
            assert(eg.first == 1);
            return eg.second;
        }
    }

    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

  private:
    unsigned int _v;
    static constexpr unsigned int umod() { return m; }
    static constexpr bool prime = internal::is_prime<m>;
};

template <int id> struct dynamic_modint : internal::modint_base {
    using mint = dynamic_modint;

  public:
    static int mod() { return (int)(bt.umod()); }
    static void set_mod(int m) {
        assert(1 <= m);
        bt = internal::barrett(m);
    }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    dynamic_modint() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    dynamic_modint(T v) {
        long long x = (long long)(v % (long long)(mod()));
        if (x < 0) x += mod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    dynamic_modint(T v) {
        _v = (unsigned int)(v % mod());
    }

    unsigned int val() const { return _v; }

    mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v += mod() - rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        _v = bt.mul(_v, rhs._v);
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        auto eg = internal::inv_gcd(_v, mod());
        assert(eg.first == 1);
        return eg.second;
    }

    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

  private:
    unsigned int _v;
    static internal::barrett bt;
    static unsigned int umod() { return bt.umod(); }
};
template <int id> internal::barrett dynamic_modint<id>::bt(998244353);

using modint998244353 = static_modint<998244353>;
using modint1000000007 = static_modint<1000000007>;
using modint = dynamic_modint<-1>;

namespace internal {

template <class T>
using is_static_modint = std::is_base_of<internal::static_modint_base, T>;

template <class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

template <class> struct is_dynamic_modint : public std::false_type {};
template <int id>
struct is_dynamic_modint<dynamic_modint<id>> : public std::true_type {};

template <class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

}  


}  


using namespace atcoder;










using mint = modint998244353;

using VM = vector<mint>;
using VVM = vector<VM>;
using VVVM = vector<VVM>;
using VVVVM = vector<VVVM>;

template<int M> istream &operator>>(istream &is, static_modint<M> &m) { ll v; is >> v; m = v; return is; }
template<int M> istream &operator>>(istream &is, dynamic_modint<M> &m) { ll v; is >> v; m = v; return is; }
template<int M> ostream &operator<<(ostream &os, const static_modint<M> &m) { return os << m.val(); }
template<int M> ostream &operator<<(ostream &os, const dynamic_modint<M> &m) { return os << m.val(); }

struct combination {
  public:
    combination() : combination(1) {}
    combination(int n) : N(1), fact_(2,0), ifact_(2,0), inv_(2,0) {
        M = mint().mod();
        assert(0 < n && n < M);

        fact_[0] = fact_[1] = 1;
        ifact_[0] = ifact_[1] = 1;
        inv_[1] = 1;

        if (N < n) { build(n); }
    }

    mint P(int n, int k) {
        if (N < n) { build(n); }
        if (n < 0 || k < 0 || n < k) { return 0; }
        return fact_[n] * ifact_[n-k];
    }
    mint C(int n, int k) {
        if (N < n) { build(n); }
        if (n < 0 || k < 0 || n < k) { return 0; }
        return fact_[n] * ifact_[n-k] * ifact_[k];
    }
    mint H(int n, int k) {
        if (n == 0 && k == 0) { return 1; }
        if (n < 0 || k < 0) { return 0; }
        return C(n + k - 1, k);
    }
    mint fact(int n) {
        if (N < n) { build(n); }
        if (n < 0) { return 0; }
        return fact_[n];
    }
    mint ifact(int n) {
        if (N < n) { build(n); }
        if (n < 0) { return 0; }
        return ifact_[n];
    }
    mint inv(int n) {
        if (N < n) { build(n); }
        if (n < 0) { return 0; }
        return inv_[n];
    }
    mint P_naive(ll n, int k) const noexcept {
        if (n < 0 || k < 0 || n < k) { return 0; }
        mint res = 1;
        for (int i = 1; i <= k; i++) { res *= (n - i + 1); }
        return res;
    }
    mint C_naive(ll n, int k) const noexcept {
        if (n < 0 || k < 0 || n < k) { return 0; }
        if (k > n - k) { k = n - k; }
        mint nume = 1, deno = 1;
        for (int i = 1; i <= k; i++) { nume *= (n - i + 1); deno *= i; }
        return nume / deno;
    }
    mint H_naive(ll n, int k) const noexcept {
        if (n == 0 && k == 0) { return 1; }
        if (n < 0 || k < 0) { return 0; }
        return C_naive(n + k - 1, k);
    }

  private:
    int N;
    int M;  

    vector<mint> fact_, ifact_, inv_;

    void build(int N_new) {
        assert(N < N_new);
        fact_.resize(N_new + 1);
        ifact_.resize(N_new + 1);
        inv_.resize(N_new + 1);
        for (int i = N + 1; i <= N_new; i++) {
            fact_[i] = fact_[i - 1] * i;
            inv_[i] = -inv_[M % i] * (M / i);
            ifact_[i] = ifact_[i - 1] * inv_[i];
        }
        N = N_new;
    }
};








const int M = 1e5;


int dp[2][M + 1];
VI memo[2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    

    

    


    int tt; cin >> tt;
    while (tt--) {
        int N; input(N);
        VI A(N); REP(i,N) { input(A[i]); }

        mint ans = 0;
        RREP(i,N) {
            int a = A[i];
            int k = i % 2;
            memo[k].push_back(a);
            dp[k][a] = 1;
            int last = a;
            ll res = 0;
            for (const auto& b : memo[k ^ 1]) {
                int t = ceil(a, b);
                int x = floor(a, t);
                res += (ll)dp[k ^ 1][b] * (i + 1) * (t - 1);
                dp[k][x] += dp[k ^ 1][b];

                if (last != x) {
                    memo[k].push_back(x);
                    last = x;
                }
            }
            for (const auto& b : memo[k ^ 1]) {
                dp[k ^ 1][b] = 0;
            }
            ans += res;
            memo[k ^ 1].clear();
        }
        print(ans);

        REP(k,2) {
            for (const auto& b : memo[k]) dp[k][b] = 0;
            memo[k].clear();
        }
    }


    return 0;
}