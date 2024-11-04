#include <bits/stdc++.h>

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
template <int n>
constexpr bool is_prime = is_prime_constexpr(n);





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
template <int m>
constexpr int primitive_root = primitive_root_constexpr(m);

}  


}  


namespace atcoder {

namespace internal {

#ifndef _MSC_VER
template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __int128>::value,
                              std::true_type, std::false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned __int128>::value,
                              std::true_type, std::false_type>::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value, __uint128_t,
                              unsigned __int128>;

template <class T>
using is_integral =
    typename std::conditional<std::is_integral<T>::value ||
                                  is_signed_int128<T>::value ||
                                  is_unsigned_int128<T>::value,
                              std::true_type, std::false_type>::type;

template <class T>
using is_signed_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_signed<T>::value) ||
                                  is_signed_int128<T>::value,
                              std::true_type, std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type, std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value, make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value, std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;

#else

template <class T>
using is_integral = typename std::is_integral<T>;

template <class T>
using is_signed_int =
    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                              std::true_type, std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<is_integral<T>::value &&
                                  std::is_unsigned<T>::value,
                              std::true_type, std::false_type>::type;

template <class T>
using to_unsigned =
    typename std::conditional<is_signed_int<T>::value, std::make_unsigned<T>,
                              std::common_type<T>>::type;

#endif

template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T>
using to_unsigned_t = typename to_unsigned<T>::type;

}  


}  


#ifdef _MSC_VER
#endif

namespace atcoder {

namespace internal {

struct modint_base {};
struct static_modint_base : modint_base {};

template <class T>
using is_modint = std::is_base_of<modint_base, T>;
template <class T>
using is_modint_t = std::enable_if_t<is_modint<T>::value>;

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

template <int id>
struct dynamic_modint : internal::modint_base {
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
template <int id>
internal::barrett dynamic_modint<id>::bt = 998244353;

using modint998244353 = static_modint<998244353>;
using modint1000000007 = static_modint<1000000007>;
using modint = dynamic_modint<-1>;

namespace internal {

template <class T>
using is_static_modint = std::is_base_of<internal::static_modint_base, T>;

template <class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

template <class>
struct is_dynamic_modint : public std::false_type {};
template <int id>
struct is_dynamic_modint<dynamic_modint<id>> : public std::true_type {};

template <class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

}  


}  


template <class T, class U, class AssociativeOp = std::multiplies<>>
constexpr T power(T a, U n, T init = 1, AssociativeOp op = AssociativeOp{}) {
  static_assert(std::is_integral_v<U> and not std::is_same_v<U, bool>);
  assert(n >= 0);
  while (n) {
    if (n & 1) init = op(init, a);
    if (n >>= 1) a = op(a, a);
  }
  return init;
}

#pragma region my_template

struct Rep {
  struct I {
    int i;
    void operator++() { ++i; }
    int operator*() const { return i; }
    bool operator!=(I o) const { return i < *o; }
  };
  const int l, r;
  Rep(int _l, int _r) : l(_l), r(_r) {}
  Rep(int n) : Rep(0, n) {}
  I begin() const { return {l}; }
  I end() const { return {r}; }
};
struct Per {
  struct I {
    int i;
    void operator++() { --i; }
    int operator*() const { return i; }
    bool operator!=(I o) const { return i > *o; }
  };
  const int l, r;
  Per(int _l, int _r) : l(_l), r(_r) {}
  Per(int n) : Per(0, n) {}
  I begin() const { return {r - 1}; }
  I end() const { return {l - 1}; }
};

template <class F>
struct Fix : private F {
  Fix(F f) : F(f) {}
  template <class... Args>
  decltype(auto) operator()(Args&&... args) const {
    return F::operator()(*this, std::forward<Args>(args)...);
  }
};

template <class T = int>
T scan() {
  T res;
  std::cin >> res;
  return res;
}

template <class T, class U = T>
bool chmin(T& a, U&& b) {
  return b < a ? a = std::forward<U>(b), true : false;
}
template <class T, class U = T>
bool chmax(T& a, U&& b) {
  return a < b ? a = std::forward<U>(b), true : false;
}

#ifndef LOCAL
#define DUMP(...) void(0)
template <int OnlineJudge, int Local>
constexpr int OjLocal = OnlineJudge;
#endif

using namespace std;

#define ALL(c) begin(c), end(c)

#pragma endregion

using Mint = atcoder::modint;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  if (OjLocal<0, 1>) {
    int n = scan();
    Mint::set_mod(n);
    vector<int> a(n);
    iota(ALL(a), 1);
    vector<int> p;
    p.reserve(n);
    do {
      Mint cur = 1;
      p.clear();
      for (int e : a) {
        cur *= e;
        p.push_back(cur.val() + 1);
      }
      if (is_permutation(ALL(p), begin(a))) {
        DUMP(a);
        DUMP(p);
        exit(0);
      }
    } while (next_permutation(ALL(a)));
    exit(0);
  }
  int n = scan();
  if (n == 1) {
    cout << "YES\n1\n";
    exit(0);
  }
  if (n == 2) {
    cout << "YES\n1\n2\n";
    exit(0);
  }
  if (n == 4) {
    cout << "YES\n1\n3\n2\n4\n";
    exit(0);
  }
  if (atcoder::internal::is_prime_constexpr(n)) {
    cout << "YES\n";
    Mint::set_mod(n);
    Mint g = atcoder::internal::primitive_root_constexpr(n);
    for (int i : Rep(n - 1)) {
      int e = -1;
      if (i < n / 2) {
        e = i & 1 ? n - i - 1 : i;
      } else {
        int j = n - i - 1;
        e = i & 1 ? j : n - j - 1;
      }
      DUMP(i, e);
      cout << power(g, e).val() << '\n';
    }
    cout << n << '\n';
  } else {
    cout << "NO\n";
  }
}