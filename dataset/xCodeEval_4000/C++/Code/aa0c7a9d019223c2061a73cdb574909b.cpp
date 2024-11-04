#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> PP;
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx")
#pragma comment(linker, "/stack:200000000")
#define overload4(_1, _2, _3, _4, name, ...) name
#define overload3(_1, _2, _3, name, ...) name
#define rep1(n) for (ll i = 0; i < n; ++i)
#define rep2(i, n) for (ll i = 0; i < n; ++i)
#define rep3(i, a, b) for (ll i = a; i < b; ++i)
#define rep4(i, a, b, c) for (ll i = a; i < b; i += c)
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rrep1(n) for (ll i = n; i--;)
#define rrep2(i, n) for (ll i = n; i--;)
#define rrep3(i, a, b) for (ll i = b; i-- > (a);)
#define rrep4(i, a, b, c) \
  for (ll i = (a) + ((b) - (a)-1) / (c) * (c); i >= (a); i -= c)
#define rrep(...) \
  overload4(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)
#define elif else if
ll beki(ll i)
{
  return 1ll << i;
}
#define skip(M) \
  if (M)        \
  continue
#define all(v) v.begin(), v.end()
#define allm(x, y, M) for (auto [(x), (y)] : (M))
#define alls(i, S) for (auto(&i) : (S))
#define pb push_back
#define fi first
#define se second
const ll INF = (1LL << 61) - 1;
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
const ll MAX_N1 = 200010;
const ll MAX_N2 = 500010;
template <class X>
void print(X x) { cout << x << endl; }
void print(vl x)
{
  for (ll i : x)
  {
    cout << i << " ";
  }
  cout << endl;
}
void print(vector<PP> x)
{
  for (PP i : x)
  {
    cout << i.first << " " << i.second << endl;
  }
  cout << endl;
}
template <class X>
void printr(X x) { cerr << x << endl; }
void printr(vl x)
{
  for (ll i : x)
  {
    cerr << i << " ";
  }
  cerr << endl;
}
void printr(vector<PP> x)
{
  for (PP i : x)
  {
    cerr << i.first << " " << i.second << endl;
  }
  cout << endl;
}
template <class X>
int lbound(vector<X> &Y, X a)
{
  return lower_bound(all(Y), a) - Y.begin();
}
template <class X>
int ubound(vector<X> &Y, X a)
{
  return upper_bound(all(Y), a) - Y.begin();
}
template <class X>
X lbound2(vector<X> &Y, X a, int mode = 0)
{
  int x = lbound(Y, a) - mode;
  if (x < 0 || x >= Y.size())
    return INF;
  return Y[x];
}
template <class X>
X ubound2(vector<X> &Y, X a, int mode = 0)
{
  int x = ubound(Y, a) - mode;
  if (x < 0 || x >= Y.size())
    return INF;
  return Y[x];
}
template <class... T>
void cl(T &...t) { (..., (t.clear())); }
template <class... T>
void in(T &...t) { (..., (cin >> t)); }
template <class... T>
void put(vl &V, int n, int mode = 0)
{
  ll k;
  if (mode == 0)
    cl(V);
  rep(i, n)
  {
    cin >> k;
    V.pb(k);
  }
}
int max_index(vl &V) { return max_element(all(V)) - V.begin(); }
int min_index(vl &V) { return min_element(all(V)) - V.begin(); }
ll sum(vl &V) { return accumulate(all(V), 0ll); }
template <typename T>
void UNIQUE(vector<T> &v)
{
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}
template <typename T>
T ADD(T a, T b)
{
  T res;
  return __builtin_add_overflow(a, b, &res) ? numeric_limits<T>::max() : res;
}
template <typename T>
T MUL(T a, T b)
{
  T res;
  return __builtin_mul_overflow(a, b, &res) ? numeric_limits<T>::max() : res;
};
template <typename T>
T POW(T a, int n)
{
  T res = 1;
  for (; n > 0; n >>= 1, a *= a)
    if (n & 1)
      res *= a;
  return res;
}
template <class X>
bool ma(X &a, X b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}
template <class X>
bool mi(X &a, X b)
{
  if (a > b)
  {
    a = b;
    return true;
  }
  return false;
}
void vset(vl &A, ll n, ll k) { A = vl(n, k); }
void so(vl &A) { sort(all(A)); }
ll age(ll x, ll y) { return (x + y - 1) / y; }
ll a, b, c, d, aa, bb, cc, dd, h, x, y, z, p, q, n, t, r, k, w, l, ans, m, u, v;
ll codeforces = 1;
string S, T, U;
vl A, B, C, D;
vl g[MAX_N2];
vector<PP> VP, VP2;
set<ll> s1, s2;

#include <algorithm>
#include <array>

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {





int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}





int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  


}  




#include <utility>

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

    

    barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}

    

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


#include <cassert>
#include <numeric>
#include <type_traits>

#ifdef _MSC_VER
#include <intrin.h>
#endif

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
    static_modint(bool v) { _v = ((unsigned int)(v) % umod()); }

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
    dynamic_modint(bool v) { _v = ((unsigned int)(v) % mod()); }

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
template <int id> internal::barrett dynamic_modint<id>::bt = 998244353;

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


#include <cassert>
#include <type_traits>
#include <vector>

namespace atcoder {

namespace internal {

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
void butterfly(std::vector<mint>& a) {
    static constexpr int g = internal::primitive_root<mint::mod()>;
    int n = int(a.size());
    int h = internal::ceil_pow2(n);

    static bool first = true;
    static mint sum_e[30];  

    if (first) {
        first = false;
        mint es[30], ies[30];  

        int cnt2 = bsf(mint::mod() - 1);
        mint e = mint(g).pow((mint::mod() - 1) >> cnt2), ie = e.inv();
        for (int i = cnt2; i >= 2; i--) {
            

            es[i - 2] = e;
            ies[i - 2] = ie;
            e *= e;
            ie *= ie;
        }
        mint now = 1;
        for (int i = 0; i <= cnt2 - 2; i++) {
            sum_e[i] = es[i] * now;
            now *= ies[i];
        }
    }
    for (int ph = 1; ph <= h; ph++) {
        int w = 1 << (ph - 1), p = 1 << (h - ph);
        mint now = 1;
        for (int s = 0; s < w; s++) {
            int offset = s << (h - ph + 1);
            for (int i = 0; i < p; i++) {
                auto l = a[i + offset];
                auto r = a[i + offset + p] * now;
                a[i + offset] = l + r;
                a[i + offset + p] = l - r;
            }
            now *= sum_e[bsf(~(unsigned int)(s))];
        }
    }
}

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
void butterfly_inv(std::vector<mint>& a) {
    static constexpr int g = internal::primitive_root<mint::mod()>;
    int n = int(a.size());
    int h = internal::ceil_pow2(n);

    static bool first = true;
    static mint sum_ie[30];  

    if (first) {
        first = false;
        mint es[30], ies[30];  

        int cnt2 = bsf(mint::mod() - 1);
        mint e = mint(g).pow((mint::mod() - 1) >> cnt2), ie = e.inv();
        for (int i = cnt2; i >= 2; i--) {
            

            es[i - 2] = e;
            ies[i - 2] = ie;
            e *= e;
            ie *= ie;
        }
        mint now = 1;
        for (int i = 0; i <= cnt2 - 2; i++) {
            sum_ie[i] = ies[i] * now;
            now *= es[i];
        }
    }

    for (int ph = h; ph >= 1; ph--) {
        int w = 1 << (ph - 1), p = 1 << (h - ph);
        mint inow = 1;
        for (int s = 0; s < w; s++) {
            int offset = s << (h - ph + 1);
            for (int i = 0; i < p; i++) {
                auto l = a[i + offset];
                auto r = a[i + offset + p];
                a[i + offset] = l + r;
                a[i + offset + p] =
                    (unsigned long long)(mint::mod() + l.val() - r.val()) *
                    inow.val();
            }
            inow *= sum_ie[bsf(~(unsigned int)(s))];
        }
    }
}

}  


template <class mint, internal::is_static_modint_t<mint>* = nullptr>
std::vector<mint> convolution(std::vector<mint> a, std::vector<mint> b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};
    if (std::min(n, m) <= 60) {
        if (n < m) {
            std::swap(n, m);
            std::swap(a, b);
        }
        std::vector<mint> ans(n + m - 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i + j] += a[i] * b[j];
            }
        }
        return ans;
    }
    int z = 1 << internal::ceil_pow2(n + m - 1);
    a.resize(z);
    internal::butterfly(a);
    b.resize(z);
    internal::butterfly(b);
    for (int i = 0; i < z; i++) {
        a[i] *= b[i];
    }
    internal::butterfly_inv(a);
    a.resize(n + m - 1);
    mint iz = mint(z).inv();
    for (int i = 0; i < n + m - 1; i++) a[i] *= iz;
    return a;
}

template <unsigned int mod = 998244353,
          class T,
          std::enable_if_t<internal::is_integral<T>::value>* = nullptr>
std::vector<T> convolution(const std::vector<T>& a, const std::vector<T>& b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};

    using mint = static_modint<mod>;
    std::vector<mint> a2(n), b2(m);
    for (int i = 0; i < n; i++) {
        a2[i] = mint(a[i]);
    }
    for (int i = 0; i < m; i++) {
        b2[i] = mint(b[i]);
    }
    auto c2 = convolution(move(a2), move(b2));
    std::vector<T> c(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) {
        c[i] = c2[i].val();
    }
    return c;
}

std::vector<long long> convolution_ll(const std::vector<long long>& a,
                                      const std::vector<long long>& b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};

    static constexpr unsigned long long MOD1 = 754974721;  

    static constexpr unsigned long long MOD2 = 167772161;  

    static constexpr unsigned long long MOD3 = 469762049;  

    static constexpr unsigned long long M2M3 = MOD2 * MOD3;
    static constexpr unsigned long long M1M3 = MOD1 * MOD3;
    static constexpr unsigned long long M1M2 = MOD1 * MOD2;
    static constexpr unsigned long long M1M2M3 = MOD1 * MOD2 * MOD3;

    static constexpr unsigned long long i1 =
        internal::inv_gcd(MOD2 * MOD3, MOD1).second;
    static constexpr unsigned long long i2 =
        internal::inv_gcd(MOD1 * MOD3, MOD2).second;
    static constexpr unsigned long long i3 =
        internal::inv_gcd(MOD1 * MOD2, MOD3).second;

    auto c1 = convolution<MOD1>(a, b);
    auto c2 = convolution<MOD2>(a, b);
    auto c3 = convolution<MOD3>(a, b);

    std::vector<long long> c(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) {
        unsigned long long x = 0;
        x += (c1[i] * i1) % MOD1 * M2M3;
        x += (c2[i] * i2) % MOD2 * M1M3;
        x += (c3[i] * i3) % MOD3 * M1M2;
        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        long long diff =
            c1[i] - internal::safe_mod((long long)(x), (long long)(MOD1));
        if (diff < 0) diff += MOD1;
        static constexpr unsigned long long offset[5] = {
            0, 0, M1M2M3, 2 * M1M2M3, 3 * M1M2M3};
        x -= offset[diff % 5];
        c[i] = x;
    }

    return c;
}

}  


template <int MOD>
struct ModInt
{
  static const int Mod = MOD;
  unsigned x;
  ModInt() : x(0) {}
  ModInt(signed sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
  ModInt(signed long long sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
  int get() const { return (int)x; }
  ModInt &operator+=(ModInt that)
  {
    if ((x += that.x) >= MOD)
      x -= MOD;
    return *this;
  }
  ModInt &operator-=(ModInt that)
  {
    if ((x += MOD - that.x) >= MOD)
      x -= MOD;
    return *this;
  }
  ModInt &operator*=(ModInt that)
  {
    x = (unsigned long long)x * that.x % MOD;
    return *this;
  }
  ModInt &operator/=(ModInt that) { return *this *= that.inv(); }
  ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
  ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
  ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
  ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
  ModInt inv() const
  {
    long long a = x, b = MOD, u = 1, v = 0;
    while (b)
    {
      long long t = a / b;
      a -= t * b;
      std::swap(a, b);
      u -= t * v;
      std::swap(u, v);
    }
    return ModInt(u);
  }
  bool operator==(ModInt that) const { return x == that.x; }
  bool operator!=(ModInt that) const { return x != that.x; }
  ModInt operator-() const
  {
    ModInt t;
    t.x = x == 0 ? 0 : Mod - x;
    return t;
  }
};
template <int MOD>
ostream &operator<<(ostream &st, const ModInt<MOD> a)
{
  st << a.get();
  return st;
};
template <int MOD>
ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k)
{
  ModInt<MOD> r = 1;
  while (k)
  {
    if (k & 1)
      r *= a;
    a *= a;
    k >>= 1;
  }
  return r;
}
typedef ModInt<MOD> mint;
template <class T>
struct FormalPowerSeries : vector<T>
{
  using vector<T>::vector;
  using vector<T>::operator=;
  using F = FormalPowerSeries;

  F operator-() const
  {
    F res(*this);
    for (auto &e : res)
      e = -e;
    return res;
  }
  F &operator*=(const T &g)
  {
    for (auto &e : *this)
      e *= g;
    return *this;
  }
  F &operator/=(const T &g)
  {
    assert(g != T(0));
    *this *= g.inv();
    return *this;
  }
  F &operator+=(const F &g)
  {
    int n = (*this).size(), m = g.size();
    rep(i, min(n, m))(*this)[i] += g[i];
    return *this;
  }
  F &operator-=(const F &g)
  {
    int n = (*this).size(), m = g.size();
    rep(i, min(n, m))(*this)[i] -= g[i];
    return *this;
  }
  F &operator<<=(const int d)
  {
    int n = (*this).size();
    (*this).insert((*this).begin(), d, 0);
    (*this).resize(n);
    return *this;
  }
  F &operator>>=(const int d)
  {
    int n = (*this).size();
    (*this).erase((*this).begin(), (*this).begin() + min(n, d));
    (*this).resize(n);
    return *this;
  }
  F inv(int d = -1) const
  {
    int n = (*this).size();
    assert(n != 0 && (*this)[0] != 0);
    if (d == -1)
      d = n;
    assert(d > 0);
    F res{(*this)[0].inv()};
    while (res.size() < d)
    {
      int m = size(res);
      F f(begin(*this), begin(*this) + min(n, 2 * m));
      F r(res);
      f.resize(2 * m), atcoder::internal::butterfly(f);
      r.resize(2 * m), atcoder::internal::butterfly(r);
      rep(i, 2 * m) f[i] *= r[i];
      atcoder::internal::butterfly_inv(f);
      f.erase(f.begin(), f.begin() + m);
      f.resize(2 * m), atcoder::internal::butterfly(f);
      rep(i, 2 * m) f[i] *= r[i];
      atcoder::internal::butterfly_inv(f);
      T iz = T(2 * m).inv();
      iz *= -iz;
      rep(i, m) f[i] *= iz;
      res.insert(res.end(), f.begin(), f.begin() + m);
    }
    return {res.begin(), res.begin() + d};
  }

  

  

  

  

  

  

  

  

  

  

  

  

  


  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  


  

  F &operator*=(vector<pair<int, T>> g)
  {
    int n = (*this).size();
    auto [d, c] = g.front();
    if (d == 0)
      g.erase(g.begin());
    else
      c = 0;
    rrep(i, n)
    {
      (*this)[i] *= c;
      for (auto &[j, b] : g)
      {
        if (j > i)
          break;
        (*this)[i] += (*this)[i - j] * b;
      }
    }
    return *this;
  }
  F &operator/=(vector<pair<int, T>> g)
  {
    int n = (*this).size();
    auto [d, c] = g.front();
    assert(d == 0 && c != T(0));
    T ic = c.inv();
    g.erase(g.begin());
    rep(i, n)
    {
      for (auto &[j, b] : g)
      {
        if (j > i)
          break;
        (*this)[i] -= (*this)[i - j] * b;
      }
      (*this)[i] *= ic;
    }
    return *this;
  }
  

  void multiply(const int d, const T c)
  {
    int n = (*this).size();
    if (c == T(1))
      rrep(i, n - d)(*this)[i + d] += (*this)[i];
    else if (c == T(-1))
      rrep(i, n - d)(*this)[i + d] -= (*this)[i];
    else
      rrep(i, n - d)(*this)[i + d] += (*this)[i] * c;
  }
  void divide(const int d, const T c)
  {
    int n = (*this).size();
    if (c == T(1))
      rep(i, n - d)(*this)[i + d] -= (*this)[i];
    else if (c == T(-1))
      rep(i, n - d)(*this)[i + d] += (*this)[i];
    else
      rep(i, n - d)(*this)[i + d] -= (*this)[i] * c;
  }

  T eval(const T &a) const
  {
    T x(1), res(0);
    for (auto e : *this)
      res += e * x, x *= a;
    return res;
  }

  F operator*(const T &g) const { return F(*this) *= g; }
  F operator/(const T &g) const { return F(*this) /= g; }
  F operator+(const F &g) const { return F(*this) += g; }
  F operator-(const F &g) const { return F(*this) -= g; }
  F operator<<(const int d) const { return F(*this) <<= d; }
  F operator>>(const int d) const { return F(*this) >>= d; }
  F operator*(const F &g) const { return F(*this) *= g; }
  F operator/(const F &g) const { return F(*this) /= g; }
  F operator*(vector<pair<int, T>> g) const { return F(*this) *= g; }
  F operator/(vector<pair<int, T>> g) const { return F(*this) /= g; }
};
vector<mint> fact(MAX_N2 * 6 + 1);
void factcreate(void)
{
  fact[0] = 1;
  rep(i, MAX_N2 * 6) { fact[i + 1] = fact[i] * (i + 1); }
}
using fps = FormalPowerSeries<mint>;
using sfps = vector<pair<int, mint>>;
void solve()
{
  in(n, q);
  fps Ft(n * 3 + 4), Wa(4), K(4);
  rep(i, 1, 3 * n + 4)
  {
    Ft[(i - 1)] = fact[3 * (n + 1)] / (fact[3 * (n + 1) - i] * fact[i]);
  }
  sfps W = {{0, 3}, {1, 3}, {2, 1}};
  Ft /= W;
  Ft[0]+=1;
  
  while (q--) {
    in(x);
    print(Ft[x]);
  }
}
int main()
{
  cout << fixed << setprecision(15);
  cin.tie(0);
  ios::sync_with_stdio(false);
  

  factcreate();
  while (codeforces--)
  {
    ans = 0;
    solve();
  }
}
