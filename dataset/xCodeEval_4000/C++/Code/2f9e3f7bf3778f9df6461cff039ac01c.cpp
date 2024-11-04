#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif

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


#include <bits/stdc++.h>

#include <iostream>
#include <iterator>

namespace cplib
{
using namespace std;
template <typename InputIt,
          typename T = typename iterator_traits<InputIt>::value_type>
void read_n(InputIt it, int n)
{
    copy_n(istream_iterator<T>(cin), n, it);
}

template <typename InputIt,
          typename T = typename iterator_traits<InputIt>::value_type>
void read(InputIt first, InputIt last)
{
    read_n(first, distance(first, last));
}

template <typename InputIt,
          typename T = typename iterator_traits<InputIt>::value_type>
void write(InputIt first, InputIt last, const char *delim = "\n")
{
    copy(first, last, ostream_iterator<T>(cout, delim));
}

template <typename InputIt,
          typename T = typename iterator_traits<InputIt>::value_type>
void decrement(InputIt first, InputIt last, T k = 1)
{
    transform(first, last, first, [k](T x) { return x - k; });
}

template <typename InputIt,
          typename T = typename iterator_traits<InputIt>::value_type>
void increment(InputIt first, InputIt last, T k = 1)
{
    transform(first, last, first, [k](T x) { return x + k; });
}

} 



#include <algorithm>
#include <cassert>
#include <functional>
#include <map>
#include <numeric>
#include <vector>

namespace cplib
{
using namespace std;

template <class T>
struct minimum : binary_function<T, T, T>
{
    T operator()(const T &x, const T &y) const { return std::min(x, y); }
    template <class Compare>
    T operator()(const T &x, const T &y, Compare comp) const
    {
        return std::min(x, y, comp);
    }
};

template <class T>
struct maximum : binary_function<T, T, T>
{
    T operator()(const T &x, const T &y) const { return std::max(x, y); }
    template <class Compare>
    T operator()(const T &x, const T &y, Compare comp) const
    {
        return std::max(x, y, comp);
    }
};

template <typename T1, typename T2>
vector<pair<T1, T2>> map_union(vector<pair<T1, T2>> const &a,
                               vector<pair<T1, T2>> const &b)
{
    vector<pair<T1, T2>> ans;
    ans.reserve(max(size(a), size(b)));
    int i = 0, j = 0;
    while (i < (int)a.size() and j < (int)b.size())
    {
        if (a[i].first == b[j].first)
        {
            ans.emplace_back(a[i].first, a[i].second + b[j].second);
            i++, j++;
        }
        else if (a[i].first < b[j].first)
            ans.push_back(a[i++]);
        else
            ans.push_back(b[j++]);
    }
    while (i < (int)a.size())
        ans.push_back(a[i++]);

    while (j < (int)b.size())
        ans.push_back(b[j++]);
    return ans;
}

template <typename T1, typename T2>
vector<pair<T1, T2>> map_intersection(vector<pair<T1, T2>> const &a,
                                      vector<pair<T1, T2>> const &b)
{
    vector<pair<T1, T2>> ans;
    int                  i = 0, j = 0;
    while (i < (int)a.size() and j < (int)b.size())
    {
        if (a[i].first == b[j].first)
        {
            ans.emplace_back(a[i].first, min(a[i].second, b[j].second));
            i++, j++;
        }
        else if (a[i].first < b[j].first)
            i++;
        else
            j++;
    }
    return ans;
}

template <typename T>
long long count_inversions(vector<T> const &a)
{
    int       n   = a.size();
    long long ans = 0;
    for (int i = 1; i < n; ++i)
        for (int j = 0; j < i; ++j)
            ans += a[i] < a[j];
    return ans;
}

long long permutation_sign(vector<int> const &sigma)
{
    return count_inversions(sigma) & 1LL ? -1 : +1;
}

template <typename InputIt,
          typename T    = typename iterator_traits<InputIt>::value_type,
          class Compare = std::less<T>>
vector<int> argsort(InputIt first, InputIt last, Compare cmp = std::less<T>())
{
    vector<int> indices(distance(first, last));
    std::iota(indices.begin(), indices.end(), 0);
    std::sort(indices.begin(),
              indices.end(),
              [&](int i, int j) { return cmp(*(first + i), *(first + j)); });
    return indices;
}

template <typename InputIt,
          typename T    = typename iterator_traits<InputIt>::value_type,
          class Compare = std::less<T>>
vector<int>
stable_argsort(InputIt first, InputIt last, Compare cmp = std::less<T>())
{
    vector<int> indices(distance(first, last));
    std::iota(indices.begin(), indices.end(), 0);
    std::sort(indices.begin(),
              indices.end(),
              [&](int i, int j)
              {
                  T a = *(first + i), b = *(first + j);
                  if (!cmp(a, b) and !cmp(b, a)) 

                      return i < j;
                  return cmp(a, b);
              });
    return indices;
}

template <typename InputIt,
          typename T = typename iterator_traits<InputIt>::value_type>
vector<T>
apply_permutation(InputIt first, InputIt last, vector<int> const &sigma)
{
    int n = distance(first, last);
    assert(n == (int)sigma.size());
    vector<T> a_sigma(n);
    for (int i = 0; i < n; ++i)
        a_sigma[i] = *(first + sigma[i]);
    return a_sigma;
}

vector<int> inverse_permutation(vector<int> const &sigma)
{
    int         n = sigma.size();
    vector<int> inv(n);
    for (int i = 0; i < n; ++i)
        inv[sigma[i]] = i;
    return inv;
}

template <typename T>
map<T, int> compress(vector<T> values)
{
    map<T, int> mp;
    int         cnt = 0;
    for (auto v : values)
        mp[v];
    for (auto &[k, v] : mp)
        v = cnt++;
    return mp;
}

template <typename T>
vector<T> apply_map(vector<T> values, map<T, T> m)
{
    for (auto &x : values)
        x = m[x];
    return values;
}

} 


#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll   = long long;
using ii   = pair<int, int>;
using vi   = vector<int>;
using mint = atcoder::modint998244353;

int solve(vector<string> s)
{
    int          n = s.size(), m = s.back().size();
    int const    NMAX = 3e5 + 11;
    vector<mint> p(NMAX);
    p[0] = mint(1) / 2;
    for (int i = 1; i < NMAX; ++i)
    {
        if (i % 2)
            p[i] = p[i - 1] - mint(1) / mint(2).pow(i);
        else
            p[i] = p[i - 1] + mint(1) / mint(2).pow(i);
    }

    mint ans = 0;
    int  w   = 0;
    for (int i = 0; i < n; ++i)
        w += count(all(s[i]), 'o');

    for (int i = 0; i < n; ++i)
    {
        int c = 0;
        for (int j = 0; j < m; ++j)
        {
            if (s[i][j] == '*')
                c = 0;
            else
                c++;
            if (c > 0)
                ans += p[c];
        }
    }
    for (int j = 0; j < m; ++j)
    {
        int c = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i][j] == '*')
                c = 0;
            else
                c++;
            if (c > 0)
                ans += p[c];
        }
    }
    return (ans * mint(2).pow(w)).val();
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    read(all(s));

    cout << solve(s) << endl;

    return 0;
}
