

#if not defined LOCAL and not defined NDEBUG
#define NDEBUG
#endif
extern const bool show_all_failed_tests = false;
extern const bool compare_real_numbers = false;
#ifndef CP_UTILS
#define CP_UTILS
#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstring>
#include <map>
#include <numeric>
#include <set>







#ifndef JHELPER_EXAMPLE_PROJECT_LIBRARY_ALIAS_HPP_
#define JHELPER_EXAMPLE_PROJECT_LIBRARY_ALIAS_HPP_
#include <string>
#include <cassert>
#include <queue>
#ifndef JHELPER_EXAMPLE_PROJECT_LIBRARY_IO_HPP_
#define JHELPER_EXAMPLE_PROJECT_LIBRARY_IO_HPP_
#include <iostream>
#include <vector>
#include <tuple>
struct fast_ios {
  fast_ios() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cout.precision(10);
    std::cout << std::fixed;
  };
} fast_ios_;
namespace io {
template<typename... Ts>
std::istream &operator>>(std::istream &in, std::tuple<Ts...> &t);
template<typename T, typename U>
std::istream &operator>>(std::istream &in, std::pair<T, U> &p) {
  in >> p.first >> p.second;
  return in;
}

template<typename T>
std::istream &operator>>(std::istream &stream, std::vector<T> &vec) {
  for (auto &x : vec)
    stream >> x;
  return stream;
}

#if __cplusplus >= 201703L
template<typename... Ts>
std::istream &operator>>(std::istream &in, const std::tuple<Ts...> &t) {
  std::apply([&in](auto &... args) { ((in >> args), ...); }, t);
  return in;
}

template<class... Args> void scan(Args &... args) {
  ((std::cin >> args), ...);
}
#endif

template<typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vec) {
  bool first = true;
  for (const T &t : vec) {
    if (first)
      first = false;
    else
      out << ' ';
    out << t;
  }
  return out;
}

template<typename T, typename U>
std::ostream &operator<<(std::ostream &out, const std::pair<T, U> &p) {
  out << p.first << ' ' << p.second;
  return out;
}

template<typename T>
std::ostream &operator<<(std::ostream &out,
                         const std::vector<std::vector<T>> &t) {
  bool is_first = true;
  for (const auto &row : t) {
    if (is_first)
      is_first = false;
    else
      out << '\n';
    out << row;
  }
  return out;
}

#if __cplusplus >= 201703L
template<typename... Args> void pt(Args &&... args) {
  ((std::cout << args << ' '), ...);
}

template<typename First, typename... Args>
void pl(const First &first, const Args &... args) {
  std::cout << first;
  ((std::cout << ' ' << args), ...);
  std::cout << '\n';
}

template<typename... Args> void pn(const Args &... args) {
  ((std::cout << args << '\n'), ...);
}
#endif
}

inline int ri() {
  int x;
  std::cin >> x;
  return x;
}
#endif








#ifndef JHELPER_EXAMPLE_PROJECT_LIBRARY_NDARRAY_HPP_
#define JHELPER_EXAMPLE_PROJECT_LIBRARY_NDARRAY_HPP_









template<unsigned dimension, typename T>
class vec : public std::vector<vec<dimension - 1, T>> {
  using std::vector<vec<dimension - 1, T>>::vector;

 public:
  template<typename... Args>
  vec(unsigned d, Args... args)
      : std::vector<vec<dimension - 1, T>>(d, vec<dimension - 1, T>(args...)) {}
};
template<typename T> class vec<1, T> : public std::vector<T> {
  using std::vector<T>::vector;
};
#endif


using ll = long long;
using ull = unsigned long long;
using vl = std::vector<ll>;
using vb = std::vector<bool>;
using vi = std::vector<int>;
using vs = std::vector<std::string>;
using pii = std::pair<int, int>;
using pli = std::pair<ll, int>;
using pil = std::pair<int, ll>;
using pll = std::pair<ll, ll>;
using vii = std::vector<pii>;
template<typename T, typename U = std::less<T>>
using pq = std::priority_queue<T, std::vector<T>, U>;
template<typename... Ts> using vt = std::vector<std::tuple<Ts...>>;
template<typename T> using vv = vec<2, T>;
#define TOKENPASTE(x, y) x##y
#define TOKENPASTE2(x, y) TOKENPASTE(x, y)
#define rng3(i, a, b)                                                          \
  for (std::common_type<decltype(a), decltype(b)>::type                        \
           i = a,                                                              \
           TOKENPASTE2(r_end_, __LINE__) = b;                                  \
       i < TOKENPASTE2(r_end_, __LINE__); ++i)
#define rng4(i, a, b, c)                                                       \
  for (std::common_type<decltype(a), decltype(b)>::type                        \
           i = a,                                                              \
           TOKENPASTE2(r_end_, __LINE__) = b;                                  \
       i < TOKENPASTE2(r_end_, __LINE__); i += c)
#define rng2(i, n) rng3(i, 0, n)
#define GET4(_1, _2, _3, _4, NAME, ...) NAME
#define rng(...) GET4(__VA_ARGS__, rng4, rng3, rng2)(__VA_ARGS__)
#define up3(i, a, b)                                                           \
  for (std::common_type<decltype(a), decltype(b)>::type                        \
           i = a,                                                              \
           TOKENPASTE2(r_end_, __LINE__) = b;                                  \
       i <= TOKENPASTE2(r_end_, __LINE__); ++i)
#define up4(i, a, b, c)                                                        \
  for (std::common_type<decltype(a), decltype(b)>::type                        \
           i = a,                                                              \
           TOKENPASTE2(r_end_, __LINE__) = b;                                  \
       i <= TOKENPASTE2(r_end_, __LINE__); i += c)
#define up(...) GET4(__VA_ARGS__, up4, up3, NO_IMPL)(__VA_ARGS__)
#define down(i, b, a)                                                          \
  for (std::common_type<decltype(a), decltype(b)>::type                        \
           i = b,                                                              \
           TOKENPASTE2(r_end_, __LINE__) = a;                                  \
       i >= TOKENPASTE2(r_end_, __LINE__); --i)
#define rep(n)                                                                 \
  for (auto TOKENPASTE2(_iter_, __LINE__) = n;                                 \
       TOKENPASTE2(_iter_, __LINE__) > 0; --TOKENPASTE2(_iter_, __LINE__))
#define FOR(x, cont) for (auto &&x : cont)
#define ALL(x) begin(x), end(x)


#define RALL(x) rbegin(x), rend(x)
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ep emplace
#define SZ(x) (int) (x).size()
#define rp(...) return pl(__VA_ARGS__)
#define rpn(...) return pn(__VA_ARGS__)
#define adv(i, n)                                                              \
  for (auto TOKENPASTE2(_n_, __LINE__) = n; i < TOKENPASTE2(_n_, __LINE__); ++i)
#define INT(...)                                                               \
  int __VA_ARGS__;                                                             \
  scan(__VA_ARGS__)
#define LL(...)                                                                \
  long long __VA_ARGS__;                                                       \
  scan(__VA_ARGS__)
#define STR(...)                                                               \
  std::string __VA_ARGS__;                                                     \
  scan(__VA_ARGS__)
#define rd(type, name, ...)                                                    \
  type name(__VA_ARGS__);                                                      \
  scan(name)
#define NL std::cout << '\n'
#endif


inline void Yn(bool p) {
  std::cout << (p ? "Yes\n" : "No\n");
}
inline void YN(bool p) {
  std::cout << (p ? "YES\n" : "NO\n");
}
inline void yn(bool p) {
  std::cout << (p ? "yes\n" : "no\n");
}
template<typename Container> Container inc(Container &&c) {
  for (auto &e : c)
    ++e;
  return c;
}
template<typename Container> Container dec(Container &&c) {
  for (auto &e : c)
    --e;
  return c;
}
template<typename A, typename B> inline bool chkmin(A &a, const B &b) {
  return b < a ? a = b, true : false;
}

template<typename A, typename B> inline bool chkmax(A &a, const B &b) {
  return a < b ? a = b, true : false;
}

template<typename Container> Container rev(Container &&c) {
  std::reverse(std::begin(c), std::end(c));
  return c;
}

template<typename Container> auto max(const Container &c) {
  return *std::max_element(std::begin(c), std::end(c));
}

template<typename Container> auto min(const Container &c) {
  return *std::min_element(std::begin(c), std::end(c));
}

template<typename Container> Container iota(Container &&c, int v = 0) {
  std::iota(std::begin(c), std::end(c), v);
  return c;
}

template<typename Container, typename Compare = void *>
Container sort(Container &&c, Compare comp = nullptr) {
  if constexpr (std::is_same_v<Compare, void *>)
    std::sort(std::begin(c), std::end(c));
  else
    std::sort(std::begin(c), std::end(c), comp);
  return c;
}

template<typename T> struct reversion_wrapper { T &iterable; };
template<typename T> auto begin(reversion_wrapper<T> w) {
  using std::rbegin;
  return rbegin(w.iterable);
}
template<typename T> auto end(reversion_wrapper<T> w) {
  using std::rend;
  return rend(w.iterable);
}
template<typename T> reversion_wrapper<T> reverse(T &&iterable) {
  return {iterable};
}
template<typename T, typename U> T ceil(T x, U y) {
  assert(y > 0);
  if (x > 0)
    x += y - 1;
  return x / y;
}

template<typename T, typename U> T floor(T x, U y) {
  assert(y > 0);
  if (x < 0)
    x -= y - 1;
  return x / y;
}

template<class...> struct typelist {};

template<class T, class... Ts>
constexpr bool any_same = (std::is_same_v<T, Ts> || ...);

template<class F> struct y_combinator {
  template<class... TLs> struct ref {
    y_combinator &self;
    template<class... Args> decltype(auto) operator()(Args &&... args) const {
      using G = std::conditional_t<any_same<typelist<Args...>, TLs...>,
                                   ref<TLs...>, ref<TLs..., typelist<Args...>>>;
      return self.f(G{self}, std::forward<Args>(args)...);
    }
  };
  F f;
  template<class... Args> decltype(auto) operator()(Args &&... args) {
    return ref<>{*this}(std::forward<Args>(args)...);
  }
};
template<class F> y_combinator(F) -> y_combinator<F>;
#ifndef debug
#define debug(...) 42
#endif
#ifndef show
#define show(...) 42
#endif
using namespace io;
using namespace std;
#endif


#ifndef ALGO_MODULAR
#define ALGO_MODULAR




template<typename T> T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a;
    std::swap(a, m);
    u -= t * v;
    std::swap(u, v);
  }
  assert(m == 1);
  return u;
}

template<typename T> class Modular {
 public:
  using Type = typename std::decay<decltype(T::value)>::type;

  constexpr Modular() : value() {}

  template<typename U> Modular(const U &x) { value = normalize(x); }

  template<typename U> static Type normalize(const U &x) {
    Type v;
    if (-mod() <= x && x < mod())
      v = static_cast<Type>(x);
    else
      v = static_cast<Type>(x % mod());
    if (v < 0)
      v += mod();
    return v;
  }

  const Type &operator()() const { return value; }

  template<typename U> explicit operator U() const {
    return static_cast<U>(value);
  }

  constexpr static Type mod() { return T::value; }

  Modular &operator+=(const Modular &other) {
    if ((value += other.value) >= mod())
      value -= mod();
    return *this;
  }

  Modular &operator-=(const Modular &other) {
    if ((value -= other.value) < 0)
      value += mod();
    return *this;
  }

  template<typename U> Modular &operator+=(const U &other) {
    return *this += Modular(other);
  }

  template<typename U> Modular &operator-=(const U &other) {
    return *this -= Modular(other);
  }

  Modular &operator++() { return *this += 1; }

  Modular &operator--() { return *this -= 1; }

  Modular operator++(int) {
    Modular result(*this);
    *this += 1;
    return result;
  }

  Modular operator--(int) {
    Modular result(*this);
    *this -= 1;
    return result;
  }

  Modular operator-() const { return Modular(-value); }

  template<typename U = T>
  std::enable_if_t<std::is_same_v<typename Modular<U>::Type, int>, Modular> &
  operator*=(const Modular &rhs) {
#ifdef _WIN32
    uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
    uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x),
             d, m;
    asm("divl %4; \n\t" : "=a"(d), "=d"(m) : "d"(xh), "a"(xl), "r"(mod()));
    value = m;
#else
    value = normalize(static_cast<int64_t>(value)
                      * static_cast<int64_t>(rhs.value));
#endif
    return *this;
  }

  template<typename U = T>
  std::enable_if_t<std::is_same_v<typename Modular<U>::Type, int64_t>, Modular>
      &operator*=(const Modular &rhs) {
    int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value
                                     / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }

  template<typename U = T>
  std::enable_if_t<not std::is_integral_v<typename Modular<U>::Type>, Modular> &
  operator*=(const Modular &rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }

  Modular &operator/=(const Modular &other) {
    return *this *= Modular(inverse(other.value, mod()));
  }

  template<typename U> friend const Modular<U> &abs(const Modular<U> &v) {
    return v;
  }

  template<typename U>
  friend bool operator==(const Modular<U> &lhs, const Modular<U> &rhs);

  template<typename U>
  friend bool operator<(const Modular<U> &lhs, const Modular<U> &rhs);

  template<typename U>
  friend std::istream &operator>>(std::istream &stream, Modular<U> &number);

 private:
  Type value;
};

template<typename T>
bool operator==(const Modular<T> &lhs, const Modular<T> &rhs) {
  return lhs.value == rhs.value;
}

template<typename T, typename U> bool operator==(const Modular<T> &lhs, U rhs) {
  return lhs == Modular<T>(rhs);
}

template<typename T, typename U> bool operator==(U lhs, const Modular<T> &rhs) {
  return Modular<T>(lhs) == rhs;
}

template<typename T, typename U> bool operator!=(const Modular<T> &lhs, U rhs) {
  return !(lhs == rhs);
}

template<typename T, typename U,
         typename = std::enable_if_t<not std::is_same_v<U, Modular<T>>>>
bool operator!=(U lhs, const Modular<T> &rhs) {
  return !(lhs == rhs);
}

template<typename T>
bool operator<(const Modular<T> &lhs, const Modular<T> &rhs) {
  return lhs.value < rhs.value;
}

template<typename T, typename U>
Modular<T> operator+(const Modular<T> &lhs, U rhs) {
  return Modular<T>(lhs) += rhs;
}

template<typename T, typename U,
         typename = std::enable_if_t<not std::is_same_v<U, Modular<T>>>>
Modular<T> operator+(U lhs, const Modular<T> &rhs) {
  return Modular<T>(lhs) += rhs;
}

template<typename T, typename U>
Modular<T> operator-(const Modular<T> &lhs, U rhs) {
  return Modular<T>(lhs) -= rhs;
}

template<typename T, typename U,
         typename = std::enable_if_t<not std::is_same_v<U, Modular<T>>>>
Modular<T> operator-(U lhs, const Modular<T> &rhs) {
  return Modular<T>(lhs) -= rhs;
}

template<typename T, typename U>
Modular<T> operator*(const Modular<T> &lhs, U rhs) {
  return Modular<T>(lhs) *= rhs;
}

template<typename T, typename U,
         typename = std::enable_if_t<not std::is_same_v<U, Modular<T>>>>
Modular<T> operator*(U lhs, const Modular<T> &rhs) {
  return Modular<T>(lhs) *= rhs;
}

template<typename T, typename U>
Modular<T> operator/(const Modular<T> &lhs, U rhs) {
  return Modular<T>(lhs) /= rhs;
}

template<typename T, typename U,
         typename = std::enable_if_t<not std::is_same_v<U, Modular<T>>>>
Modular<T> operator/(U lhs, const Modular<T> &rhs) {
  return Modular<T>(lhs) /= rhs;
}

template<typename T, typename U>
Modular<T> power(const Modular<T> &a, const U &b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1)
      res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}

template<typename T> bool IsZero(const Modular<T> &number) {
  return number() == 0;
}

template<typename T>
std::ostream &operator<<(std::ostream &stream, const Modular<T> &number) {
  return stream << number();
}

template<typename T>
std::istream &operator>>(std::istream &stream, Modular<T> &number) {
  std::common_type_t<typename Modular<T>::Type, int64_t> x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}

template<int md> using Mint = Modular<std::integral_constant<int, md>>;





template<int64_t md>
using Mint64 = Modular<std::integral_constant<int64_t, md>>;

using ModType = int;
struct VarMod {
  static ModType value;
};
ModType VarMod::value;
ModType &md = VarMod::value;
#endif







#ifndef JHELPER_EXAMPLE_PROJECT_LIBRARY_BOUND_HPP_
#define JHELPER_EXAMPLE_PROJECT_LIBRARY_BOUND_HPP_









template<typename Sequence, typename Value>
int lb(const Sequence &seq, const Value &val) {
  return std::lower_bound(std::begin(seq), std::end(seq), val)
      - std::begin(seq);
}
template<typename Sequence, typename Value>
int ub(const Sequence &seq, const Value &val) {
  return std::upper_bound(std::begin(seq), std::end(seq), val)
      - std::begin(seq);
}
template<typename Sequence, typename Value, typename Compare>
int lb(const Sequence &seq, const Value &val, Compare comp) {
  return std::lower_bound(std::begin(seq), std::end(seq), val, comp)
      - std::begin(seq);
}
template<typename Sequence, typename Value, typename Compare>
int ub(const Sequence &seq, const Value &val, Compare comp) {
  return std::upper_bound(std::begin(seq), std::end(seq), val, comp)
      - std::begin(seq);
}
#endif


using mint = Mint<998244353>;
mint operator""_m(unsigned long long v) {
  return mint(v);
}
void solve() {
  INT(n);
  vi a(n);
  scan(a);
  sort(a);
  vector<mint> f(n, 1);
  vi half(n);
  int j = 0;
  rng (i, n) {
    while (a[j] <= a[i] / 2)
      ++j;
    half[i] = j;
  }
  vector<mint> sum(n);
  iota(sum, 1);
  up (len, 2, n) {
    rng (i, n) {
      f[i] *= max(half[i] - (len - 2), 0);
      if (half[i] > 0)
        f[i] += sum[half[i] - 1];
    }
    mint s = 0;
    rng (i, n)
      sum[i] = s += f[i];
  }
  pl(sum.back());
}



int main() {
#if defined FILE_IO and not defined LOCAL
  freopen(FILE_IO ".in", "r", stdin);
  freopen(FILE_IO ".out", "w", stdout);
#endif
  solve();
  return 0;
}
