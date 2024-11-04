

namespace test {

typedef unsigned int value_t;
typedef unsigned long long int cast_t;
typedef unsigned int size_t;
typedef value_t *ptr_t;
static const size_t BUFFER_SIZE = 1U << 21U;
typedef value_t arr_t[BUFFER_SIZE];
static constexpr value_t P = 998244353U, G = 3U;
static arr_t ROOT;

size_t get_len(size_t n) {
  size_t len = 1;
  while (len < n) len <<= 1U;
  return len;
}
value_t mod_pow(value_t x, value_t exp) {
  value_t res = 1;
  for (; exp != 0; exp >>= 1U, x = static_cast<cast_t>(x) * x % P)
    if (exp & 1U) res = static_cast<cast_t>(res) * x % P;
  return res;
}
value_t mod_inv(value_t x) { return mod_pow(x, P - 2); }
value_t id3(value_t x) { return x == 0 ? 0 : mod_pow(x, P - 1 >> 1); }
value_t id9(value_t a) {
  if (id3(a) != 1) return 0;
  value_t q = P - 1, t = 0, n,
          z; 

  while (!(q & 1U)) q >>= 1U, ++t;
  if (t == 1) return mod_pow(a, P + 1 >> 2U);
  for (n = 1; n != P; ++n)
    if (id3(n) == P - 1) {
      z = mod_pow(n, q);
      break;
    }
  value_t y = z, r = t, x = mod_pow(a, q - 1 >> 1U), b = x;
  x = static_cast<cast_t>(x) * a % P, b = static_cast<cast_t>(x) * b % P;
  while (true) {
    if (b == 1) return x < P - x ? x : P - x;
    value_t m = 1;
    for (; m < r; ++m)
      if (mod_pow(b, 1U << m) == 1) break;
    value_t v = mod_pow(y, 1U << r - m - 1);
    y = static_cast<cast_t>(v) * v % P, r = m, x = static_cast<cast_t>(x) * v % P,
    b = static_cast<cast_t>(b) * y % P;
  }
}
void revbin(size_t n, ptr_t x) {
  for (size_t i = 0, j = 0; i != n; ++i) {
    if (i < j) {
      value_t t = *(x + i);
      *(x + i) = *(x + j), *(x + j) = t;
    }
    for (size_t k = n >> 1U; (j ^= k) < k; k >>= 1U) {
    }
  }
}
void reverse(ptr_t x, ptr_t y) {
  value_t t;
  while (y - x > 0) t = *x, *x++ = *--y, *y = t;
}
void id10(size_t n, ptr_t x) {
  for (size_t i = n; i != 1; i >>= 1U)
    for (size_t j = 0, l = i >> 1U; j != n; j += i)
      for (size_t k = 0; k != l; ++k) {
        value_t u = *(x + j + k), v = *(x + j + k + l);
        *(x + j + k) = (u + v) % P,
                  *(x + j + k + l) = (static_cast<cast_t>(u) + P - v) * ROOT[l + k] % P;
      }
}
void id7(size_t n, ptr_t x) {
  for (size_t i = 2; i <= n; i <<= 1U)
    for (size_t j = 0, l = i >> 1U; j != n; j += i)
      for (size_t k = 0; k != l; ++k) {
        value_t u = *(x + j + k), v = static_cast<cast_t>(ROOT[l + k]) * *(x + j + k + l) % P;
        *(x + j + k) = (u + v) % P, *(x + j + k + l) = (u + P - v) % P;
      }
}
void id5(size_t n, ptr_t x) {
  static size_t lim = 1;
  if (lim < n) {
    size_t l = n >> 1U;
    value_t g = mod_pow(G, (P - 1) / n);
    ROOT[l] = 1;
    for (size_t i = l + 1; i < n; ++i) ROOT[i] = static_cast<cast_t>(ROOT[i - 1]) * g % P;
    for (size_t i = l - 1; i >= lim; --i) ROOT[i] = ROOT[i << 1U];
    lim = n;
  }
  id10(n, x);
}
void id2(size_t n, ptr_t x) {
  id7(n, x), reverse(x + 1, x + n);
  value_t in = P - (P - 1) / n;
  for (ptr_t i = x, e = x + n; i != e; ++i) *i = static_cast<cast_t>(*i) * in % P;
}

struct Poly {
private:
  ptr_t first, last, id4;

public:
  typedef ptr_t iterator;
  typedef value_t const *const_iterator;

  iterator begin() { return first; }
  iterator end() { return last; }
  const_iterator begin() const { return first; }
  const_iterator end() const { return last; }
  size_t size() const { return last - first; }
  size_t capacity() const { return id4 - first; }
  bool empty() const { return first == last; }
  value_t &operator[](size_t x) { return *(first + x); }
  value_t operator[](size_t x) const { return *(first + x); }

  Poly &resize(size_t new_size) {
    if (new_size > capacity()) {
      size_t old_capacity = capacity(), new_capacity = get_len(new_size);
      first = static_cast<ptr_t>(realloc(first, sizeof(value_t) * new_capacity));
      assert(first != nullptr);
      id4 = first + new_capacity;
      memset(first + old_capacity, 0, sizeof(value_t) * (new_capacity - old_capacity));
    } else if (size() > new_size)
      memset(first + new_size, 0, sizeof(value_t) * (size() - new_size));
    return last = first + new_size, *this;
  }
  explicit Poly(size_t reserved = 1)
      : first(static_cast<ptr_t>(calloc(get_len(reserved), sizeof(value_t)))),
        last(first + reserved), id4(first + get_len(reserved)) {
    assert(reserved > 0 && first != nullptr);
  }
  Poly(const_iterator start, const_iterator finish)
      : first(static_cast<ptr_t>(malloc(get_len(finish - start) * sizeof(value_t)))),
        last(first + (finish - start)), id4(first + get_len(finish - start)) {
    assert(first != nullptr);
    memcpy(first, start, sizeof(value_t) * (finish - start));
    memset(last, 0, sizeof(value_t) * (id4 - last));
  }
  Poly(const Poly &rhs) : Poly(rhs.first, rhs.last) {}
  Poly(std::initializer_list<value_t> l) : Poly(l.begin(), l.end()) {}
  ~Poly() { free(first); }
  Poly copy() const { return Poly(*this); }
  Poly slice(size_t len) const { return Poly(first, first + len); }
  Poly &dft(size_t len) { return resize(len), id5(len, first), *this; }
  Poly &idft(size_t len) { return resize(len), id2(len, first), *this; }
  Poly &operator=(const Poly &rhs) {
    return resize(rhs.size()), memcpy(first, rhs.first, sizeof(value_t) * rhs.size()), *this;
  }
  Poly operator-() const {
    Poly res(*this);
    for (ptr_t i = res.first; i != res.last; ++i)
      if (*i != 0) *i = P - *i;
    return res;
  }
  Poly &operator+=(const Poly &rhs) {
    if (size() < rhs.size()) resize(rhs.size());
    for (size_t i = 0, len = rhs.size(); i != len; ++i)
      *(first + i) = (*(first + i) + *(rhs.first + i)) % P;
    return *this;
  }
  Poly &operator-=(const Poly &rhs) {
    if (size() < rhs.size()) resize(rhs.size());
    for (size_t i = 0, len = rhs.size(); i != len; ++i)
      *(first + i) = (*(first + i) + P - *(rhs.first + i)) % P;
    return *this;
  }
  Poly &operator*=(const Poly &rhs) {
    static const size_t id1 = 128;
    size_t n = size(), m = rhs.size(), len = get_len(n + m - 1);
    if (n + m - 1 <= id1) {
      Poly res(n + m - 1);
      for (size_t i = 0; i != n; ++i)
        for (size_t j = 0; j != m; ++j)
          *(res.first + i + j) =
              (*(res.first + i + j) + static_cast<cast_t>(*(first + i)) * *(rhs.first + j)) % P;
      return *this = res;
    }
    Poly id0(rhs);
    dft(len), id0.dft(len);
    for (size_t i = 0; i != len; ++i)
      *(first + i) = (static_cast<cast_t>(*(first + i)) * *(id0.first + i)) % P;
    return idft(len).resize(n + m - 1);
  }
  Poly &operator/=(const Poly &rhs) {
    if (size() < rhs.size()) return *this = Poly{0};
    size_t n = size() - rhs.size() + 1;
    Poly id0(rhs);
    reverse(first, last), reverse(id0.first, id0.last);
    return (*this *= id0.resize(n).inv()).resize(n), reverse(first, last), *this;
  }
  Poly &operator%=(const Poly &rhs) {
    return size() >= rhs.size() ? (*this -= (*this / rhs) * rhs).resize(rhs.size() - 1) : *this;
  }
  Poly &inplace_deriv() {
    assert(size() >= 2);
    for (size_t i = 1, len = size(); i < len; ++i)
      *(first + i - 1) = static_cast<cast_t>(*(first + i)) * i % P;
    return *(--last) = 0, *this;
  }
  Poly &inplace_integr() {
    static size_t lim = 0;
    static arr_t INV;
    size_t n = size();
    if (lim < n) {
      INV[1] = 1;
      for (size_t i = (lim < 2 ? 2 : lim); i < n; ++i)
        INV[i] = static_cast<cast_t>(P - P / i) * INV[P % i] % P;
    }
    for (size_t i = size() - 1; i > 0; --i)
      *(first + i) = static_cast<cast_t>(*(first + i - 1)) * INV[i] % P;
    return *first = 0, *this;
  }
  Poly deriv() const { return copy().inplace_deriv(); }
  Poly integr() const { return copy().inplace_integr(); }
  Poly inv() const {
    assert(*first != 0);
    size_t n = size(), len = get_len(n);
    Poly res(len << 1U);
    res[0] = mod_inv(*first);
    for (size_t i = 2; i <= len; i <<= 1U) {
      Poly cpy(begin(), begin() + i), id8(res);
      id8.dft(i), cpy.dft(i);
      for (size_t j = 0; j != i; ++j)
        *(cpy.first + j) = static_cast<cast_t>(*(cpy.first + j)) * *(id8.first + j) % P;
      cpy.idft(i);
      std::memset(cpy.begin(), 0, sizeof(value_t) * (i >> 1));
      cpy.dft(i);
      for (size_t j = 0; j != i; ++j)
        *(cpy.first + j) = static_cast<cast_t>(*(cpy.first + j)) * *(id8.first + j) % P;
      cpy.idft(i), res.resize(i);
      for (iterator j = cpy.begin() + (i >> 1), e = cpy.end(); j != e; ++j)
        if (*j != 0) *j = P - *j;
      std::memcpy(res.begin() + (i >> 1), cpy.begin() + (i >> 1), sizeof(value_t) * (i >> 1));
    }
    return res.resize(n);
  }
  Poly log() const {
    assert(*first == 1);
    return (deriv() * inv()).resize(size()).inplace_integr();
  }
  Poly exp() const {
    assert(*first == 0);
    size_t n = size(), len = get_len(n);
    Poly res(len << 1U);
    res[0] = 1;
    for (size_t i = 2; i <= len; i <<= 1U) res *= slice(i) - res.resize(i).log() + Poly{1};
    return res.resize(n);
  }
  Poly isqrt() const {
    assert(id3(*first) == 1);
    size_t n = size(), len = get_len(n);
    Poly res(len << 1U);
    res[0] = mod_inv(id9(*first));
    value_t inv2 = (P >> 1U) + 1;
    for (size_t i = 2; i <= len; i <<= 1U) {
      Poly t = Poly{1} - ((slice(i) * res.resize(i)).resize(i) * res).resize(i);
      for (ptr_t j = t.first; j != t.last; ++j) *j = static_cast<cast_t>(*j) * inv2 % P;
      res += (res * t).resize(i);
    }
    return res.resize(n);
  }
  Poly sqrt() const { return (*this * isqrt()).resize(size()); }
  Poly pow(value_t k1, value_t k2 = 0) const {
    if (*first == 1) {
      Poly res = log();
      for (ptr_t i = res.first; i != res.last; ++i) *i = static_cast<cast_t>(*i) * k1 % P;
      return res.exp();
    } else {
      Poly res(size());
      ptr_t id6 = first;
      for (; id6 != last; ++id6)
        if (*id6 != 0) {
          res = Poly(id6, last);
          break;
        }
      if (id6 == last || static_cast<cast_t>(k1) * (id6 - first) >= size())
        return Poly(size());
      value_t res0 = res[0], id11 = mod_inv(res0);
      for (ptr_t i = res.first; i != res.last; ++i) *i = static_cast<cast_t>(*i) * id11 % P;
      res = res.log();
      for (ptr_t i = res.first; i != res.last; ++i) *i = static_cast<cast_t>(*i) * k1 % P;
      res = res.exp();
      res0 = mod_pow(res0, k2 == 0 ? k1 : k2);
      for (ptr_t i = res.first; i != res.last; ++i) *i = static_cast<cast_t>(*i) * res0 % P;
      res.resize(size());
      memmove(res.first + k1 * (id6 - first), res.first,
              sizeof(value_t) * (res.size() - k1 * (id6 - first)));
      memset(res.first, 0, sizeof(value_t) * k1 * (id6 - first));
      return res;
    }
  }
  Poly chirpz(value_t z, size_t n) const;
  value_t horner(value_t x) const {
    value_t res = *(last - 1);
    for (ptr_t i = last - 1; i != first; --i) res = (static_cast<cast_t>(res) * x + *(i - 1)) % P;
    return res;
  }
  typedef std::vector<value_t>::const_iterator v_it;
  static void segment_tree_build(std::vector<Poly> &vp, size_t pos, v_it start, v_it finish) {
    if (finish - start == 1)
      vp[pos] = Poly{P - *start, 1};
    else {
      v_it mid = start + (finish - start >> 1U);
      segment_tree_build(vp, pos << 1U, start, mid),
          segment_tree_build(vp, pos << 1U | 1U, mid, finish);
      vp[pos] = vp[pos << 1U] * vp[pos << 1U | 1U];
    }
  }
  static void segment_tree_solve(std::vector<Poly> &vp, size_t pos, v_it start, v_it finish,
                                 const Poly &r, std::vector<value_t> &res) {
    static const size_t id1 = 128;
    if (finish - start <= id1) {
      for (v_it it = start; it != finish; ++it) res.push_back(r.horner(*it));
      return;
    } else {
      v_it mid = start + (finish - start >> 1U);
      segment_tree_solve(vp, pos << 1U, start, mid, r % vp[pos << 1U], res),
          segment_tree_solve(vp, pos << 1U | 1U, mid, finish, r % vp[pos << 1U | 1U], res);
    }
  }
  std::vector<value_t> eval(const std::vector<value_t> &points) const {
    std::vector<Poly> vp(points.size() << 2U);
    segment_tree_build(vp, 1, points.begin(), points.end());
    std::vector<value_t> res;
    segment_tree_solve(vp, 1, points.begin(), points.end(), *this % vp[1], res);
    return res;
  }
  static Poly inter_rec(const std::vector<Poly> &vp, size_t pos, v_it start, v_it finish) {
    if (finish - start == 1)
      return Poly{*start};
    else {
      v_it mid = start + (finish - start >> 1U);
      return inter_rec(vp, pos << 1U, start, mid) * vp[pos << 1U | 1U] +
             inter_rec(vp, pos << 1U | 1U, mid, finish) * vp[pos << 1U];
    }
  }
  static Poly inter(const std::vector<value_t> &x, const std::vector<value_t> &y) {
    size_t n = x.size();
    assert(y.size() == n);
    std::vector<Poly> vp(n << 2U);
    segment_tree_build(vp, 1, x.begin(), x.end());
    std::vector<value_t> v;
    segment_tree_solve(vp, 1, x.begin(), x.end(), vp[1].deriv() % vp[1], v);
    for (size_t i = 0; i != n; ++i) v[i] = mod_inv(v[i]) * static_cast<cast_t>(y[i]) % P;
    return inter_rec(vp, 1, v.begin(), v.end());
  }
  friend Poly operator+(const Poly &lhs, const Poly &rhs) { return Poly(lhs) += rhs; }
  friend Poly operator-(const Poly &lhs, const Poly &rhs) { return Poly(lhs) -= rhs; }
  friend Poly operator*(const Poly &lhs, const Poly &rhs) { return Poly(lhs) *= rhs; }
  friend Poly operator/(const Poly &lhs, const Poly &rhs) { return Poly(lhs) /= rhs; }
  friend Poly operator%(const Poly &lhs, const Poly &rhs) { return Poly(lhs) %= rhs; }
};

} 


using test::Poly;

using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 5;

int main() {

  freopen("..\\in", "r", stdin), freopen("..\\out", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int t;
  Poly a(m + 1);
  for (int i = 0; i < n; ++i) {
    cin >> t;
    if (t <= m) a[t] = 1;
  }
  Poly ans = Poly{2} * (Poly{1} + (Poly{1} - Poly{4} * a).sqrt()).inv();
  for (int i = 1; i != m + 1; ++i) cout << ans[i] << '\n';
  return 0;
}