

using namespace std;
























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

    unsigned long long x;
    _umul128(z, im, &x);

    unsigned long long x =
        (unsigned long long)(((unsigned __int128)(z)*im) >> 64);

    unsigned int v = (unsigned int)(z - x * _m);
    if (_m <= v) v += _m;
    return v;
  }
};







constexpr long long id10(long long x, long long n, int m) {
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









constexpr bool id8(int n) {
  if (n <= 1) return false;
  if (n == 2 || n == 7 || n == 61) return true;
  if (n % 2 == 0) return false;
  long long d = n - 1;
  while (d % 2 == 0) d /= 2;
  constexpr long long bases[3] = {2, 7, 61};
  for (long long a : bases) {
    long long t = d;
    long long y = id10(a, t, n);
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
constexpr bool is_prime = id8(n);





constexpr std::pair<long long, long long> id1(long long a, long long b) {
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







constexpr int id4(int m) {
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
      if (id10(g, (m - 1) / divs[i], m) == 1) {
        ok = false;
        break;
      }
    }
    if (ok) return g;
  }
}
template <int m>
constexpr int primitive_root = id4(m);







unsigned long long id0(unsigned long long n,
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



template <class T>
using is_integral = typename std::is_integral<T>;

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


template <int m, std::enable_if_t<(1 <= m)>* = nullptr>
struct id6 : internal::static_modint_base {
  using mint = id6;

 public:
  static constexpr int mod() { return m; }
  static mint raw(int v) {
    mint x;
    x._v = v;
    return x;
  }

  id6() : _v(0) {}
  template <class T, internal::is_signed_int_t<T>* = nullptr>
  id6(T v) {
    long long x = (long long)(v % (long long)(umod()));
    if (x < 0) x += umod();
    _v = (unsigned int)(x);
  }
  template <class T, internal::is_unsigned_int_t<T>* = nullptr>
  id6(T v) {
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
      auto eg = internal::id1(_v, m);
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
struct id5 : internal::modint_base {
  using mint = id5;

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

  id5() : _v(0) {}
  template <class T, internal::is_signed_int_t<T>* = nullptr>
  id5(T v) {
    long long x = (long long)(v % (long long)(mod()));
    if (x < 0) x += mod();
    _v = (unsigned int)(x);
  }
  template <class T, internal::is_unsigned_int_t<T>* = nullptr>
  id5(T v) {
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
    auto eg = internal::id1(_v, mod());
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
internal::barrett id5<id>::bt(998244353);

using modint998244353 = id6<998244353>;
using modint1000000007 = id6<1000000007>;
using modint = id5<-1>;

namespace internal {

template <class T>
using is_static_modint = std::is_base_of<internal::static_modint_base, T>;

template <class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

template <class>
struct is_dynamic_modint : public std::false_type {};
template <int id>
struct is_dynamic_modint<id5<id>> : public std::true_type {};

template <class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

}  


}  












namespace atcoder {

namespace internal {





int id2(int n) {
  int x = 0;
  while ((1U << x) < (unsigned int)(n)) x++;
  return x;
}





constexpr int id3(unsigned int n) {
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

template <class S, S (*op)(S, S), S (*e)()>
struct id7 {
 public:
  id7() : id7(0) {}
  explicit id7(int n) : id7(std::vector<S>(n, e())) {}
  explicit id7(const std::vector<S>& v) : _n(int(v.size())) {
    log = internal::id2(_n);
    size = 1 << log;
    d = std::vector<S>(2 * size, e());
    for (int i = 0; i < _n; i++) d[size + i] = v[i];
    for (int i = size - 1; i >= 1; i--) {
      update(i);
    }
  }

  void set(int p, S x) {
    assert(0 <= p && p < _n);
    p += size;
    d[p] = x;
    for (int i = 1; i <= log; i++) update(p >> i);
  }

  S get(int p) const {
    assert(0 <= p && p < _n);
    return d[p + size];
  }

  S prod(int l, int r) const {
    assert(0 <= l && l <= r && r <= _n);
    S sml = e(), smr = e();
    l += size;
    r += size;

    while (l < r) {
      if (l & 1) sml = op(sml, d[l++]);
      if (r & 1) smr = op(d[--r], smr);
      l >>= 1;
      r >>= 1;
    }
    return op(sml, smr);
  }

  S all_prod() const { return d[1]; }

  template <bool (*f)(S)>
  int max_right(int l) const {
    return max_right(l, [](S x) { return f(x); });
  }
  template <class F>
  int max_right(int l, F f) const {
    assert(0 <= l && l <= _n);
    assert(f(e()));
    if (l == _n) return _n;
    l += size;
    S sm = e();
    do {
      while (l % 2 == 0) l >>= 1;
      if (!f(op(sm, d[l]))) {
        while (l < size) {
          l = (2 * l);
          if (f(op(sm, d[l]))) {
            sm = op(sm, d[l]);
            l++;
          }
        }
        return l - size;
      }
      sm = op(sm, d[l]);
      l++;
    } while ((l & -l) != l);
    return _n;
  }

  template <bool (*f)(S)>
  int min_left(int r) const {
    return min_left(r, [](S x) { return f(x); });
  }
  template <class F>
  int min_left(int r, F f) const {
    assert(0 <= r && r <= _n);
    assert(f(e()));
    if (r == 0) return 0;
    r += size;
    S sm = e();
    do {
      r--;
      while (r > 1 && (r % 2)) r >>= 1;
      if (!f(op(d[r], sm))) {
        while (r < size) {
          r = (2 * r + 1);
          if (f(op(d[r], sm))) {
            sm = op(d[r], sm);
            r--;
          }
        }
        return r + 1 - size;
      }
      sm = op(d[r], sm);
    } while ((r & -r) != r);
    return 0;
  }

 private:
  int _n, size, log;
  std::vector<S> d;

  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  













namespace atcoder {

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct id9 {
 public:
  id9() : id9(0) {}
  explicit id9(int n) : id9(std::vector<S>(n, e())) {}
  explicit id9(const std::vector<S>& v) : _n(int(v.size())) {
    log = internal::id2(_n);
    size = 1 << log;
    d = std::vector<S>(2 * size, e());
    lz = std::vector<F>(size, id());
    for (int i = 0; i < _n; i++) d[size + i] = v[i];
    for (int i = size - 1; i >= 1; i--) {
      update(i);
    }
  }

  void set(int p, S x) {
    assert(0 <= p && p < _n);
    p += size;
    for (int i = log; i >= 1; i--) push(p >> i);
    d[p] = x;
    for (int i = 1; i <= log; i++) update(p >> i);
  }

  S get(int p) {
    assert(0 <= p && p < _n);
    p += size;
    for (int i = log; i >= 1; i--) push(p >> i);
    return d[p];
  }

  S prod(int l, int r) {
    assert(0 <= l && l <= r && r <= _n);
    if (l == r) return e();

    l += size;
    r += size;

    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != r) push((r - 1) >> i);
    }

    S sml = e(), smr = e();
    while (l < r) {
      if (l & 1) sml = op(sml, d[l++]);
      if (r & 1) smr = op(d[--r], smr);
      l >>= 1;
      r >>= 1;
    }

    return op(sml, smr);
  }

  S all_prod() { return d[1]; }

  void apply(int p, F f) {
    assert(0 <= p && p < _n);
    p += size;
    for (int i = log; i >= 1; i--) push(p >> i);
    d[p] = mapping(f, d[p]);
    for (int i = 1; i <= log; i++) update(p >> i);
  }
  void apply(int l, int r, F f) {
    assert(0 <= l && l <= r && r <= _n);
    if (l == r) return;

    l += size;
    r += size;

    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != r) push((r - 1) >> i);
    }

    {
      int l2 = l, r2 = r;
      while (l < r) {
        if (l & 1) all_apply(l++, f);
        if (r & 1) all_apply(--r, f);
        l >>= 1;
        r >>= 1;
      }
      l = l2;
      r = r2;
    }

    for (int i = 1; i <= log; i++) {
      if (((l >> i) << i) != l) update(l >> i);
      if (((r >> i) << i) != r) update((r - 1) >> i);
    }
  }

  template <bool (*g)(S)>
  int max_right(int l) {
    return max_right(l, [](S x) { return g(x); });
  }
  template <class G>
  int max_right(int l, G g) {
    assert(0 <= l && l <= _n);
    assert(g(e()));
    if (l == _n) return _n;
    l += size;
    for (int i = log; i >= 1; i--) push(l >> i);
    S sm = e();
    do {
      while (l % 2 == 0) l >>= 1;
      if (!g(op(sm, d[l]))) {
        while (l < size) {
          push(l);
          l = (2 * l);
          if (g(op(sm, d[l]))) {
            sm = op(sm, d[l]);
            l++;
          }
        }
        return l - size;
      }
      sm = op(sm, d[l]);
      l++;
    } while ((l & -l) != l);
    return _n;
  }

  template <bool (*g)(S)>
  int min_left(int r) {
    return min_left(r, [](S x) { return g(x); });
  }
  template <class G>
  int min_left(int r, G g) {
    assert(0 <= r && r <= _n);
    assert(g(e()));
    if (r == 0) return 0;
    r += size;
    for (int i = log; i >= 1; i--) push((r - 1) >> i);
    S sm = e();
    do {
      r--;
      while (r > 1 && (r % 2)) r >>= 1;
      if (!g(op(d[r], sm))) {
        while (r < size) {
          push(r);
          r = (2 * r + 1);
          if (g(op(d[r], sm))) {
            sm = op(d[r], sm);
            r--;
          }
        }
        return r + 1 - size;
      }
      sm = op(d[r], sm);
    } while ((r & -r) != r);
    return 0;
  }

 private:
  int _n, size, log;
  std::vector<S> d;
  std::vector<F> lz;

  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
  void all_apply(int k, F f) {
    d[k] = mapping(f, d[k]);
    if (k < size) lz[k] = composition(f, lz[k]);
  }
  void push(int k) {
    all_apply(2 * k, lz[k]);
    all_apply(2 * k + 1, lz[k]);
    lz[k] = id();
  }
};

}  






using modint = atcoder::modint998244353;

template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }
void print() { cout << endl; }
template <typename T, typename... Tail>
void print(T&& seq, Tail... tail) {
  if constexpr (ranges::range<T> && !convertible_to<T, string>)
    for (const auto& x : seq) cout << x << ' ';
  else
    cout << seq;
  cout << ' ';
  print(tail...);
}

modint countWays(vector<vector<int>>& grid) {
  

  int R = (int)grid.size();
  int C = (int)grid[0].size();

  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      if (grid[r][c] == -1) {
        

        modint ways = 0;
        for (int x : {0, 1}) {
          grid[r][c] = x;
          ways += countWays(grid);
          grid[r][c] = -1;
        }
        return ways;
      }
    }
  }
  

  int good = 1;
  for (int r = 0; r < R - 1; r++) {
    for (int c = 0; c < C - 1; c++) {
      int total = 0;
      for (int nr : {r, r + 1}) {
        for (int nc : {c, c + 1}) {
          total += grid[nr][nc];
        }
      }
      if (total != 2) {
        good = 0;
      }
    }
  }
  return good;
}

const bool DEBUG = false;

using S = modint;
S op(S l, S r) { return l * r; }
S e() { return 1; }

void solve() {
  
  int R, C, K;
  cin >> R >> C >> K;
  vector<vector<int>> grid;
  if (DEBUG) {
    grid.assign(R, vector<int>(C, -1));
  }

  map<array<int, 2>, int> cells;
  vector<vector<int>> rows(2, vector<int>(R));
  vector<vector<int>> cols(2, vector<int>(C));
  atcoder::id7<S, op, e> rowWays(vector<S>(R, 2));
  atcoder::id7<S, op, e> colWays(vector<S>(C, 2));
  vector<int> checkerWays(2, 0);

  auto insert = [&](int r, int c, int t) {
    assert(t == 0 || t == 1);
    cells[{r, c}] = t;
    rows[c % 2 == t][r] += 1;
    cols[r % 2 == t][c] += 1;
    checkerWays[(r + c + t) % 2] += 1;
    

    

    

    rowWays.set(r, (rows[0][r] == 0) + (rows[1][r] == 0));
    colWays.set(c, (cols[0][c] == 0) + (cols[1][c] == 0));
  };
  auto remove = [&](int r, int c) {
    if (cells.contains({r, c})) {
      int t = cells[{r, c}];
      cells.erase({r, c});
      rows[c % 2 == t][r] -= 1;
      cols[r % 2 == t][c] -= 1;
      checkerWays[(r + c + t) % 2] -= 1;
      rowWays.set(r, (rows[0][r] == 0) + (rows[1][r] == 0));
      colWays.set(c, (cols[0][c] == 0) + (cols[1][c] == 0));
    }
  };
  for (int i = 0; i < K; i++) {
    int r, c, t;
    cin >> r >> c >> t;
    r -= 1;
    c -= 1;
    if (t == -1) {
      remove(r, c);
    } else {
      remove(r, c);
      insert(r, c, t);
    }

    int overcount = (checkerWays[0] == 0) + (checkerWays[1] == 0);
    modint ans = rowWays.prod(0, R) + colWays.prod(0, C) - overcount;
    print(ans.val());
    if (DEBUG) {
      grid[r][c] = t;
      modint ans2 = countWays(grid).val();
      assert(ans == ans2);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin.exceptions(ios::badbit | ios::failbit);
  cout << fixed << setprecision(15);
  int TC = 1;
  while (TC--) {
    solve();
  }
  return 0;
}
