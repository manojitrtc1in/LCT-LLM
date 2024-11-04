










using namespace std;

const LL MOD=998244353;

LL qpow(LL x,LL a)
{
	LL res=x,ret=1;
	while(a>0)
	{
		if((a&1)==1) ret=ret*res%MOD;
		a>>=1;
		res=res*res%MOD;
	}
	return ret;
}

namespace atcoder {
namespace internal {
int id7(int n) {
  int x = 0;
  while ((1U << x) < (unsigned int)(n)) x++;
  return x;
}
constexpr int id8(unsigned int n) {
  int x = 0;
  while (!(n & (1 << x))) x++;
  return x;
}
int bsf(unsigned int n) {

  unsigned long index;
  _BitScanForward(&index, n);
  return index;

  return __builtin_ctz(n);

}
}  

}  













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
  explicit barrett(unsigned int m)
      : _m(m), im((unsigned long long)(-1) / m + 1) {}
  unsigned int umod() const { return _m; }
  unsigned int mul(unsigned int a, unsigned int b) const {
    unsigned long long z = a;
    z *= b;

    unsigned long long x;
    _umul128(z, im, &x);

    unsigned long long x =
        (unsigned long long)(((unsigned __int128)(z)*im) >> 64);

    unsigned int v = (unsigned int)(z - x * _m);
    if (_m <= v) v += _m;
    return v;
  }
  unsigned int mod(unsigned long long z) const {
    unsigned long long x = (unsigned long long)(((__uint128_t)z * im) >> 64);
    unsigned int v = (unsigned int)(z - x * _m);
    if (v >= _m) v += _m;
    return v;
  }
};
constexpr long long id22(long long x, long long n, int m) {
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
constexpr bool id21(int n) {
  if (n <= 1) return false;
  if (n == 2 || n == 7 || n == 61) return true;
  if (n % 2 == 0) return false;
  long long d = n - 1;
  while (d % 2 == 0) d /= 2;
  constexpr long long bases[3] = {2, 7, 61};
  for (long long a : bases) {
    long long t = d;
    long long y = id22(a, t, n);
    while (t != n - 1 && y != 1 && y != n - 1) {
      y = y * y % n;
      t <<= 1;
    }
    if (y != n - 1 && t % 2 == 0) return false;
  }
  return true;
}
template <int n>
constexpr bool is_prime = id21(n);
constexpr std::pair<long long, long long> id3(long long a, long long b) {
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
constexpr int id14(int m) {
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
  for (int i = 3; (long long)(i)*i <= x; i += 2)
    if (x % i == 0) {
      divs[cnt++] = i;
      while (x % i == 0) x /= i;
    }
  if (x > 1) divs[cnt++] = x;
  for (int g = 2;; g++) {
    bool ok = true;
    for (int i = 0; i < cnt; i++)
      if (id22(g, (m - 1) / divs[i], m) == 1) {
        ok = false;
        break;
      }
    if (ok) return g;
  }
}
template <int m>
constexpr int primitive_root = id14(m);
unsigned long long id2(unsigned long long n,
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




namespace atcoder {
namespace internal {

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

template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;
template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;
template <class T>
using to_unsigned_t = typename to_unsigned<T>::type;
}  

}  

namespace atcoder {
namespace internal {
struct modint_base {};
struct static_modint_base : modint_base {};
template <class T>
using is_modint = std::is_base_of<modint_base, T>;
template <class T>
using is_modint_t = std::enable_if_t<is_modint<T>::value>;
}  

template <int m, std::enable_if_t<(1 <= m)> * = nullptr>
struct id20 : internal::static_modint_base {
  using mint = id20;

 public:
  static constexpr int mod() { return m; }
  static mint raw(int v) {
    mint x;
    x._v = v;
    return x;
  }
  id20() : _v(0) {}
  template <class T, internal::is_signed_int_t<T> * = nullptr>
  id20(T v) {
    long long x = (long long)(v % (long long)(umod()));
    if (x < 0) x += umod();
    _v = (unsigned int)(x);
  }
  template <class T, internal::is_unsigned_int_t<T> * = nullptr>
  id20(T v) {
    _v = (unsigned int)(v % umod());
  }
  unsigned int val() const { return _v; }
  mint &operator++() {
    _v++;
    if (_v == umod()) _v = 0;
    return *this;
  }
  mint &operator--() {
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
  mint &operator+=(const mint &rhs) {
    _v += rhs._v;
    if (_v >= umod()) _v -= umod();
    return *this;
  }
  mint &operator-=(const mint &rhs) {
    _v -= rhs._v;
    if (_v >= umod()) _v += umod();
    return *this;
  }
  mint &operator*=(const mint &rhs) {
    unsigned long long z = _v;
    z *= rhs._v;
    _v = (unsigned int)(z % umod());
    return *this;
  }
  mint &operator/=(const mint &rhs) { return *this = *this * rhs.inv(); }
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
      auto eg = internal::id3(_v, m);
      assert(eg.first == 1);
      return eg.second;
    }
  }
  friend mint operator+(const mint &lhs, const mint &rhs) {
    return mint(lhs) += rhs;
  }
  friend mint operator-(const mint &lhs, const mint &rhs) {
    return mint(lhs) -= rhs;
  }
  friend mint operator*(const mint &lhs, const mint &rhs) {
    return mint(lhs) *= rhs;
  }
  friend mint operator/(const mint &lhs, const mint &rhs) {
    return mint(lhs) /= rhs;
  }
  friend bool operator==(const mint &lhs, const mint &rhs) {
    return lhs._v == rhs._v;
  }
  friend bool operator!=(const mint &lhs, const mint &rhs) {
    return lhs._v != rhs._v;
  }
  friend std::istream &operator>>(std::istream &in, mint &x) {
    long long tmp;
    in >> tmp;
    x = tmp;
    return in;
  }
  friend std::ostream &operator<<(std::ostream &out, const mint &x) {
    return out << x.val();
  }

 private:
  unsigned int _v;
  static constexpr unsigned int umod() { return m; }
  static constexpr bool prime = internal::is_prime<m>;
};
template <int id>
struct id19 : internal::modint_base {
  using mint = id19;

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
  id19() : _v(0) {}
  template <class T, internal::is_signed_int_t<T> * = nullptr>
  id19(T v) {
    long long x = (long long)(v % (long long)(mod()));
    if (x < 0) x += mod();
    _v = (unsigned int)(x);
  }
  template <class T, internal::is_unsigned_int_t<T> * = nullptr>
  id19(T v) {
    _v = (unsigned int)(v % mod());
  }
  unsigned int val() const { return _v; }
  mint &operator++() {
    _v++;
    if (_v == umod()) _v = 0;
    return *this;
  }
  mint &operator--() {
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
  mint &operator+=(const mint &rhs) {
    _v += rhs._v;
    if (_v >= umod()) _v -= umod();
    return *this;
  }
  mint &operator-=(const mint &rhs) {
    _v += mod() - rhs._v;
    if (_v >= umod()) _v -= umod();
    return *this;
  }
  mint &operator*=(const mint &rhs) {
    _v = bt.mul(_v, rhs._v);
    return *this;
  }
  mint &operator/=(const mint &rhs) { return *this = *this * rhs.inv(); }
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
    auto eg = internal::id3(_v, mod());
    assert(eg.first == 1);
    return eg.second;
  }
  friend mint operator+(const mint &lhs, const mint &rhs) {
    return mint(lhs) += rhs;
  }
  friend mint operator-(const mint &lhs, const mint &rhs) {
    return mint(lhs) -= rhs;
  }
  friend mint operator*(const mint &lhs, const mint &rhs) {
    return mint(lhs) *= rhs;
  }
  friend mint operator/(const mint &lhs, const mint &rhs) {
    return mint(lhs) /= rhs;
  }
  friend bool operator==(const mint &lhs, const mint &rhs) {
    return lhs._v == rhs._v;
  }
  friend bool operator!=(const mint &lhs, const mint &rhs) {
    return lhs._v != rhs._v;
  }
  friend std::istream &operator>>(std::istream &in, mint &x) {
    long long tmp;
    in >> tmp;
    x = tmp;
    return in;
  }
  friend std::ostream &operator<<(std::ostream &out, const mint &x) {
    return out << x.val();
  }

 private:
  unsigned int _v;
  static internal::barrett bt;
  static unsigned int umod() { return bt.umod(); }
};
template <int id>
internal::barrett id19<id>::bt(998244353);
using modint998244353 = id20<998244353>;
using modint1000000007 = id20<1000000007>;
using modint = id19<-1>;
namespace internal {
template <class T>
using is_static_modint = std::is_base_of<internal::static_modint_base, T>;
template <class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;
template <class>
struct is_dynamic_modint : public std::false_type {};
template <int id>
struct is_dynamic_modint<id19<id>> : public std::true_type {};
template <class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;
}  

}  

namespace atcoder {
namespace internal {
template <class mint, int g = internal::primitive_root<mint::mod()>,
          internal::is_static_modint_t<mint> * = nullptr>
struct fft_info {
  static constexpr int rank2 = id8(mint::mod() - 1);
  std::array<mint, rank2 + 1> root;   

  std::array<mint, rank2 + 1> iroot;  

  std::array<mint, std::max(0, rank2 - 2 + 1)> rate2;
  std::array<mint, std::max(0, rank2 - 2 + 1)> irate2;
  std::array<mint, std::max(0, rank2 - 3 + 1)> rate3;
  std::array<mint, std::max(0, rank2 - 3 + 1)> irate3;
  fft_info() {
    root[rank2] = mint(g).pow((mint::mod() - 1) >> rank2);
    iroot[rank2] = root[rank2].inv();
    for (int i = rank2 - 1; i >= 0; i--) {
      root[i] = root[i + 1] * root[i + 1];
      iroot[i] = iroot[i + 1] * iroot[i + 1];
    }
    {
      mint prod = 1, iprod = 1;
      for (int i = 0; i <= rank2 - 2; i++) {
        rate2[i] = root[i + 2] * prod;
        irate2[i] = iroot[i + 2] * iprod;
        prod *= iroot[i + 2];
        iprod *= root[i + 2];
      }
    }
    {
      mint prod = 1, iprod = 1;
      for (int i = 0; i <= rank2 - 3; i++) {
        rate3[i] = root[i + 3] * prod;
        irate3[i] = iroot[i + 3] * iprod;
        prod *= iroot[i + 3];
        iprod *= root[i + 3];
      }
    }
  }
};
template <class mint, internal::is_static_modint_t<mint> * = nullptr>
void id4(std::vector<mint> &a) {
  int n = int(a.size());
  int h = internal::id7(n);
  static const fft_info<mint> info;
  int len = 0;  

  while (len < h)
    if (h - len == 1) {
      int p = 1 << (h - len - 1);
      mint rot = 1;
      for (int s = 0; s < (1 << len); s++) {
        int offset = s << (h - len);
        for (int i = 0; i < p; i++) {
          auto l = a[i + offset];
          auto r = a[i + offset + p] * rot;
          a[i + offset] = l + r;
          a[i + offset + p] = l - r;
        }
        if (s + 1 != (1 << len)) rot *= info.rate2[bsf(~(unsigned int)(s))];
      }
      len++;
    } else {
      int p = 1 << (h - len - 2);
      mint rot = 1, imag = info.root[2];
      for (int s = 0; s < (1 << len); s++) {
        mint rot2 = rot * rot;
        mint rot3 = rot2 * rot;
        int offset = s << (h - len);
        for (int i = 0; i < p; i++) {
          auto mod2 = 1ULL * mint::mod() * mint::mod();
          auto a0 = 1ULL * a[i + offset].val();
          auto a1 = 1ULL * a[i + offset + p].val() * rot.val();
          auto a2 = 1ULL * a[i + offset + 2 * p].val() * rot2.val();
          auto a3 = 1ULL * a[i + offset + 3 * p].val() * rot3.val();
          auto id11 = 1ULL * mint(a1 + mod2 - a3).val() * imag.val();
          auto na2 = mod2 - a2;
          a[i + offset] = a0 + a2 + a1 + a3;
          a[i + offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));
          a[i + offset + 2 * p] = a0 + na2 + id11;
          a[i + offset + 3 * p] = a0 + na2 + (mod2 - id11);
        }
        if (s + 1 != (1 << len)) rot *= info.rate3[bsf(~(unsigned int)(s))];
      }
      len += 2;
    }
}
template <class mint, internal::is_static_modint_t<mint> * = nullptr>
void id17(std::vector<mint> &a) {
  int n = int(a.size());
  int h = internal::id7(n);
  static const fft_info<mint> info;
  int len = h;  

  while (len)
    if (len == 1) {
      int p = 1 << (h - len);
      mint irot = 1;
      for (int s = 0; s < (1 << (len - 1)); s++) {
        int offset = s << (h - len + 1);
        for (int i = 0; i < p; i++) {
          auto l = a[i + offset];
          auto r = a[i + offset + p];
          a[i + offset] = l + r;
          a[i + offset + p] =
              (unsigned long long)(mint::mod() + l.val() - r.val()) *
              irot.val();
        }
        if (s + 1 != (1 << (len - 1)))
          irot *= info.irate2[bsf(~(unsigned int)(s))];
      }
      len--;
    } else {
      int p = 1 << (h - len);
      mint irot = 1, iimag = info.iroot[2];
      for (int s = 0; s < (1 << (len - 2)); s++) {
        mint id13 = irot * irot;
        mint id12 = id13 * irot;
        int offset = s << (h - len + 2);
        for (int i = 0; i < p; i++) {
          auto a0 = 1ULL * a[i + offset + 0 * p].val();
          auto a1 = 1ULL * a[i + offset + 1 * p].val();
          auto a2 = 1ULL * a[i + offset + 2 * p].val();
          auto a3 = 1ULL * a[i + offset + 3 * p].val();
          auto id9 =
              1ULL * mint((mint::mod() + a2 - a3) * iimag.val()).val();
          a[i + offset] = a0 + a1 + a2 + a3;
          a[i + offset + 1 * p] =
              (a0 + (mint::mod() - a1) + id9) * irot.val();
          a[i + offset + 2 * p] =
              (a0 + a1 + (mint::mod() - a2) + (mint::mod() - a3)) * id13.val();
          a[i + offset + 3 * p] =
              (a0 + (mint::mod() - a1) + (mint::mod() - id9)) *
              id12.val();
        }
        if (s + 1 != (1 << (len - 2)))
          irot *= info.irate3[bsf(~(unsigned int)(s))];
      }
      len -= 2;
    }
}
template <class mint, internal::is_static_modint_t<mint> * = nullptr>
std::vector<mint> id18(const std::vector<mint> &a,
                                    const std::vector<mint> &b) {
  int n = int(a.size()), m = int(b.size());
  std::vector<mint> ans(n + m - 1);
  if (n < m)
    for (int j = 0; j < m; j++)
      for (int i = 0; i < n; i++) ans[i + j] += a[i] * b[j];
  else
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) ans[i + j] += a[i] * b[j];
  return ans;
}
template <class mint, internal::is_static_modint_t<mint> * = nullptr>
std::vector<mint> id5(std::vector<mint> a, std::vector<mint> b) {
  int n = int(a.size()), m = int(b.size());
  int z = 1 << internal::id7(n + m - 1);
  a.resize(z);
  internal::id4(a);
  b.resize(z);
  internal::id4(b);
  for (int i = 0; i < z; i++) a[i] *= b[i];
  internal::id17(a);
  a.resize(n + m - 1);
  mint iz = mint(z).inv();
  for (int i = 0; i < n + m - 1; i++) a[i] *= iz;
  return a;
}
}  

template <class mint, internal::is_static_modint_t<mint> * = nullptr>
std::vector<mint> convolution(std::vector<mint> &&a, std::vector<mint> &&b) {
  int n = int(a.size()), m = int(b.size());
  if (!n || !m) return {};
  if (std::min(n, m) <= 60) return id18(a, b);
  return internal::id5(a, b);
}
template <class mint, internal::is_static_modint_t<mint> * = nullptr>
std::vector<mint> convolution(const std::vector<mint> &a,
                              const std::vector<mint> &b) {
  int n = int(a.size()), m = int(b.size());
  if (!n || !m) return {};
  if (std::min(n, m) <= 60) return id18(a, b);
  return internal::id5(a, b);
}
template <unsigned int mod = 998244353, class T,
          std::enable_if_t<internal::is_integral<T>::value> * = nullptr>
std::vector<T> convolution(const std::vector<T> &a, const std::vector<T> &b) {
  int n = int(a.size()), m = int(b.size());
  if (!n || !m) return {};
  using mint = id20<mod>;
  std::vector<mint> a2(n), b2(m);
  for (int i = 0; i < n; i++) a2[i] = mint(a[i]);
  for (int i = 0; i < m; i++) b2[i] = mint(b[i]);
  auto c2 = convolution(move(a2), move(b2));
  std::vector<T> c(n + m - 1);
  for (int i = 0; i < n + m - 1; i++) c[i] = c2[i].val();
  return c;
}
std::vector<long long> id10(const std::vector<long long> &a,
                                      const std::vector<long long> &b) {
  int n = int(a.size()), m = int(b.size());
  if (!n || !m) return {};
  static constexpr unsigned long long MOD1 = 754974721;  

  static constexpr unsigned long long MOD2 = 167772161;  

  static constexpr unsigned long long MOD3 = 469762049;  

  static constexpr unsigned long long id1 = MOD2 * MOD3;
  static constexpr unsigned long long id16 = MOD1 * MOD3;
  static constexpr unsigned long long id0 = MOD1 * MOD2;
  static constexpr unsigned long long id15 = MOD1 * MOD2 * MOD3;
  static constexpr unsigned long long i1 =
      internal::id3(MOD2 * MOD3, MOD1).second;
  static constexpr unsigned long long i2 =
      internal::id3(MOD1 * MOD3, MOD2).second;
  static constexpr unsigned long long i3 =
      internal::id3(MOD1 * MOD2, MOD3).second;
  auto c1 = convolution<MOD1>(a, b);
  auto c2 = convolution<MOD2>(a, b);
  auto c3 = convolution<MOD3>(a, b);
  std::vector<long long> c(n + m - 1);
  for (int i = 0; i < n + m - 1; i++) {
    unsigned long long x = 0;
    x += (c1[i] * i1) % MOD1 * id1;
    x += (c2[i] * i2) % MOD2 * id16;
    x += (c3[i] * i3) % MOD3 * id0;
    long long diff =
        c1[i] - internal::safe_mod((long long)(x), (long long)(MOD1));
    if (diff < 0) diff += MOD1;
    static constexpr unsigned long long offset[5] = {0, 0, id15, 2 * id15,
                                                     3 * id15};
    x -= offset[diff % 5];
    c[i] = x;
  }
  return c;
}
std::vector<int> id6(const std::vector<int> &a,
                                 const std::vector<int> &b, unsigned int mod) {
  int n = int(a.size()), m = int(b.size());
  if (!n || !m) return {};
  static constexpr unsigned long long MOD1 = 754974721;  

  static constexpr unsigned long long MOD2 = 167772161;  

  static constexpr unsigned long long MOD3 = 469762049;  

  static constexpr unsigned long long id0 = MOD1 * MOD2;
  auto c1 = convolution<MOD1>(a, b);
  auto c2 = convolution<MOD2>(a, b);
  auto c3 = convolution<MOD3>(a, b);
  using mint2 = id20<MOD2>;
  using mint3 = id20<MOD3>;
  mint2 i1 = mint2(MOD1).inv();
  mint3 i12 = mint3(id0).inv();
  std::vector<int> c(n + m - 1);
  internal::barrett bt(mod);
  for (int i = 0; i < n + m - 1; i++) {
    long long x1 = c1[i], x2 = c2[i], x3 = c3[i];
    long long k1 = (mint2(x2 - x1) * i1).val();
    long long x4 = x1 + k1 * MOD1;
    long long k4 = (mint3(x3 - x4) * i12).val();
    c[i] = bt.mod(x4 + k4 * bt.mul(MOD1, MOD2));
  }
  return c;
}
template <class mint, internal::is_static_modint_t<mint> * = nullptr>
std::vector<mint> inverse(const std::vector<mint> &a) {
  int n = int(a.size());
  if (n == 1) return {a[0].inv()};
  std::vector<mint> f0 =
      inverse(std::vector<mint>(a.begin(), a.begin() + ((n + 1) >> 1)));
  int z = 1 << internal::id7(2 * n);
  f0.resize(z);
  internal::id4(f0);
  std::vector<mint> b = a;
  b.resize(z);
  internal::id4(b);
  for (int i = 0; i < z; i++) f0[i] *= 2 - f0[i] * b[i];
  internal::id17(f0);
  f0.resize(n);
  mint iz = mint(z).inv();
  for (int i = 0; i < n; i++) f0[i] *= iz;
  return f0;
}
}  


using mint=atcoder::modint998244353;

LL n,a[1010],b[1010],fac[2000010],inv[2000010];
vector <LL> ans;

LL CC(LL nn,LL mm){return fac[nn]*inv[mm]%MOD*inv[nn-mm]%MOD;}

int main()
{
  fac[0]=1;repn(i,2000005) fac[i]=fac[i-1]*i%MOD;
  rep(i,2000005) inv[i]=qpow(fac[i],MOD-2);
  cin>>n;
  rep(i,n) scanf("%lld%lld",&a[i],&b[i]);
  ans={1};
  rep(i,n)
  {
    LL dia=ans.size()+a[i],tot=a[i]+b[i],eds=ans.size()+a[i]-b[i];
    vector <mint> A,B,C;rep(j,ans.size()) A.pb(ans[j]);
    for(int j=-ans.size()+1;j<eds;++j) if(dia-eds+j>=0&&dia-eds+j<=tot) B.pb(CC(tot,dia-eds+j));else B.pb(0);
    C=atcoder::convolution(A,B);
    int sv=ans.size()-1;
    ans.clear();
    for(int j=sv;j<C.size();++j)
    {
      ans.pb(C[j].val());
      

      if(ans.size()==eds) break;
    }
  }
  LL rans=0;
  rep(i,ans.size()) (rans+=ans[i])%=MOD;
  cout<<rans<<endl;
  return 0;
}