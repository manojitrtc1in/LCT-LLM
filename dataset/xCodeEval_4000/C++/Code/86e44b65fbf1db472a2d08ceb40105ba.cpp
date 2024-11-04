

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







#ifndef JHELPER_EXAMPLE_PROJECT_TASKS_TYPE_TRAITS_HPP_
#define JHELPER_EXAMPLE_PROJECT_TASKS_TYPE_TRAITS_HPP_
#include <type_traits>
template<typename T> T type();

template<typename Container> auto value_type_of_() {
  if constexpr (std::is_array_v<Container>)
    return type<std::remove_extent_t<Container>>();
  else
    return type<typename Container::value_type>();
}
template<typename Container>
using value_type_of = decltype(value_type_of_<Container>());



namespace is_iterable_impl {
using std::begin, std::end;
template<typename T>
using check_specs = std::void_t<
    std::enable_if_t<
        std::is_same_v<decltype(begin(std::declval<T &>())),

                       decltype(end(std::declval<T &>()))   

                       >>,

    decltype(*begin(std::declval<T &>()))>;

template<typename, typename = void> struct is_iterable : std::false_type {};


template<class T> struct is_iterable<T, check_specs<T>> : std::true_type {};
}

template<class T> using is_iterable = is_iterable_impl::is_iterable<T>;
template<typename T> constexpr bool is_iterable_v = is_iterable<T>::value;



template<typename T>
using is_string =
    std::disjunction<std::is_same<char *, typename std::decay_t<T>>,
                     std::is_same<const char *, typename std::decay_t<T>>,
                     std::is_same<std::string, typename std::decay_t<T>>>;
template<typename T> constexpr bool is_string_v = is_string<T>::value;


#endif


struct fast_ios {
  fast_ios() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cout.precision(10);
    std::cout << std::fixed;
  };
} fast_ios_;
namespace io {
template<typename T, typename U>
std::ostream &operator<<(std::ostream &out, const std::pair<T, U> &p);
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

template<typename... Ts>
std::istream &operator>>(std::istream &in, std::tuple<Ts...> &t) {
  std::apply([&in](auto &...args) { ((in >> args), ...); }, t);
  return in;
}

template<class... Args> void scan(Args &...args) {
  ((std::cin >> args), ...);
}

template<typename Container,
         typename = std::enable_if_t<std::conjunction_v<
             is_iterable<Container>, std::negation<is_string<Container>>>>>
std::ostream &operator<<(std::ostream &out, const Container &container) {
  using std::begin;
  constexpr char delimiter =
      is_iterable_v<decltype(*begin(std::declval<Container &>()))> ? '\n' : ' ';
  bool first = true;
  for (auto &element : container) {
    if (first)
      first = false;
    else
      out << delimiter;
    out << element;
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

template<typename... Args> void pt(Args &&...args) {
  ((std::cout << args << ' '), ...);
}

template<typename First, typename... Args>
void pl(const First &first, const Args &...args) {
  std::cout << first;
  ((std::cout << ' ' << args), ...);
  std::cout << '\n';
}

template<typename... Args> void pn(const Args &...args) {
  ((std::cout << args << '\n'), ...);
}
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
class ndarray : public std::vector<ndarray<dimension - 1, T>> {
 public:
  using std::vector<ndarray<dimension - 1, T>>::vector;
  template<typename... Args>
  ndarray(unsigned d, Args... args)
      : std::vector<ndarray<dimension - 1, T>>(
          d, ndarray<dimension - 1, T>(args...)) {}
};
template<typename T> class ndarray<1, T> : public std::vector<T> {
 public:
  using std::vector<T>::vector;
  template<typename... Args>
  ndarray<1, T>(Args &&...args) : std::vector<T>(std::forward<Args>(args)...) {}
};
#endif









#ifndef JHELPER_EXAMPLE_PROJECT_LIBRARY_MACROS_H_
#define JHELPER_EXAMPLE_PROJECT_LIBRARY_MACROS_H_

#define CALL_WITH_EXPANDED_ARGS(function, ...) function(__VA_ARGS__)

#define JOIN_IMPL(arg1, arg2) arg1##arg2
#define JOIN(arg1, arg2) JOIN_IMPL(arg1, arg2)

#define EXPAND_1(...) __VA_ARGS__
#define EXPAND_4(...) EXPAND_1(EXPAND_1(EXPAND_1(__VA_ARGS__)))
#define EXPAND_13(...) EXPAND_4(EXPAND_4(EXPAND_4(__VA_ARGS__)))

#define PAUSE
#define COMMA() ,
#define TERMINATE(...)
#define SELECT_SECOND_ARG(arg1, arg2, ...) arg2
#define CONDITIONAL(peek, arg1, arg2)                                          \
  CALL_WITH_EXPANDED_ARGS(SELECT_SECOND_ARG, COMMA peek arg1, arg2)
#define TERMINATE_OR(peek, arg) CONDITIONAL(peek, TERMINATE, arg)

#define FOR_EACH_2_IMPL0(function, arg1, arg2, peek, ...)                      \
  function(arg1, arg2) TERMINATE_OR(peek, FOR_EACH_2_IMPL1)                    \
      PAUSE(function, peek, __VA_ARGS__)

#define FOR_EACH_2_IMPL1(function, arg1, arg2, peek, ...)                      \
  function(arg1, arg2) TERMINATE_OR(peek, FOR_EACH_2_IMPL0)                    \
      PAUSE(function, peek, __VA_ARGS__)

#define FOR_EACH_2(function, ...)                                              \
  EXPAND_13(FOR_EACH_2_IMPL0(function, __VA_ARGS__, ()))

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
template<typename T>
using pq = std::priority_queue<std::pair<T, int>,
                               std::vector<std::pair<T, int>>, std::greater<>>;
template<typename... Ts> using vt = std::vector<std::tuple<Ts...>>;
template<typename T> using vv = ndarray<2, T>;
template<typename T> struct range_tuple {
  const T &ref = beg;
  T beg;
  const T end;
  range_tuple(T b, T e) : beg(b), end(e) {}
};
#define rng4(i, a, b, c)                                                       \
  for (auto &&[i, JOIN(iter_, __LINE__), JOIN(end_, __LINE__)] =               \
           range_tuple<std::common_type<decltype(a), decltype(b)>::type>(a,    \
                                                                         b);   \
       i < JOIN(end_, __LINE__); JOIN(iter_, __LINE__) += c)
#define rng3(i, a, b) rng4(i, a, b, 1)
#define rng2(i, n) rng3(i, 0, n)
#define GET4(_1, _2, _3, _4, NAME, ...) NAME
#define rng(...) GET4(__VA_ARGS__, rng4, rng3, rng2)(__VA_ARGS__)
#define up4(i, a, b, c) rng (i, a, b + 1, c)
#define up3(i, a, b) up4(i, a, b, 1)
#define up(...) GET4(__VA_ARGS__, up4, up3, NO_IMPL)(__VA_ARGS__)
#define down4(i, b, a, c)                                                      \
  for (auto &&[i, JOIN(iter_, __LINE__), JOIN(end_, __LINE__)] =               \
           range_tuple<std::common_type<decltype(a), decltype(b)>::type>(b,    \
                                                                         a);   \
       i >= JOIN(end_, __LINE__); JOIN(iter_, __LINE__) -= c)
#define down3(i, b, a) down4(i, b, a, 1)
#define down(...) GET4(__VA_ARGS__, down4, down3, NO_IMPL)(__VA_ARGS__)
#define rep(n)                                                                 \
  for (auto JOIN(_iter_, __LINE__) = n; JOIN(_iter_, __LINE__) > 0;            \
       --JOIN(_iter_, __LINE__))
#define FOR_LAST_OPERATION_IMPL(arg1, arg2) arg1] : arg2
#define FOR_NORMAL_OPERATION_IMPL(arg1, arg2) arg1,
#define FOR_IMPL0(arg1, arg2, peek, ...)                                       \
  CONDITIONAL(peek, FOR_LAST_OPERATION_IMPL, FOR_NORMAL_OPERATION_IMPL)        \
  (arg1, arg2) TERMINATE_OR(peek, FOR_IMPL1) PAUSE(arg2, peek, __VA_ARGS__)
#define FOR_IMPL1(arg1, arg2, peek, ...)                                       \
  CONDITIONAL(peek, FOR_LAST_OPERATION_IMPL, FOR_NORMAL_OPERATION_IMPL)        \
  (arg1, arg2) TERMINATE_OR(peek, FOR_IMPL0) PAUSE(arg2, peek, __VA_ARGS__)
#define FOR_IMPL3(arg1, arg2, peek, ...)                                       \
  CONDITIONAL(peek, for (auto && arg1 : arg2),                                 \
  for (auto && [EXPAND_13(FOR_IMPL0(arg1, arg2, peek, __VA_ARGS__))))
#define FOR(...) FOR_IMPL3(__VA_ARGS__, ())
#define ALL(x) std::begin(x), std::end(x)


#define RALL(x) std::rbegin(x), std::rend(x)
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ep emplace
#define SZ(x) (int) (x).size()
#define rp(...) return pl(__VA_ARGS__)
#define rpn(...) return pn(__VA_ARGS__)
#define adv(i, n)                                                              \
  for (auto JOIN(_n_, __LINE__) = n; i < JOIN(_n_, __LINE__); ++i)
#define radv(i, n)                                                             \
  for (auto JOIN(_n_, __LINE__) = n; i > JOIN(_n_, __LINE__); --i)
#define INT(...)                                                               \
  int __VA_ARGS__;                                                             \
  scan(__VA_ARGS__)
#define LL(...)                                                                \
  long long __VA_ARGS__;                                                       \
  scan(__VA_ARGS__)
#define STR(...)                                                               \
  std::string __VA_ARGS__;                                                     \
  scan(__VA_ARGS__)
#define CHAR(...)                                                              \
  char __VA_ARGS__;                                                            \
  scan(__VA_ARGS__)
#define NL                                                                     \
  [] {                                                                         \
    std::cout << '\n';                                                         \
  }()
#define READ_VI(NAME, LEN)                                                     \
  std::vector<int> NAME(LEN);                                                  \
  scan(NAME);
#define VI(...) FOR_EACH_2(READ_VI, __VA_ARGS__)
#define READ_VL(NAME, LEN)                                                     \
  std::vector<long long> NAME(LEN);                                            \
  scan(NAME);
#define VL(...) FOR_EACH_2(READ_VL, __VA_ARGS__)
#define READ_VS(NAME, LEN)                                                     \
  std::vector<std::string> NAME(LEN);                                          \
  scan(NAME);
#define VS(...) FOR_EACH_2(READ_VS, __VA_ARGS__)
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


template<typename Sequence> Sequence uniq(Sequence &&s) {
  assert(std::is_sorted(std::begin(s), std::end(s)));
  s.erase(std::unique(std::begin(s), std::end(s)), std::end(s));
  return s;
}

template<typename Container> auto max(const Container &c) {
  assert(std::size(c) > 0);
  return *std::max_element(std::begin(c), std::end(c));
}

template<typename Container> auto min(const Container &c) {
  assert(std::size(c) > 0);
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

template<typename iterator> struct range {
  iterator beg_, end_;
  iterator begin() const { return beg_; }
  iterator end() const { return end_; }
  

  range(iterator beg, iterator end) : beg_(beg), end_(end) {}
};

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
template<typename T, typename U> T ceil_div(T x, U y) {
  assert(y > 0);
  T q = x / y;
  return q + (q * y < x);
}

template<typename T, typename U> T floor_div(T x, U y) {
  assert(y > 0);
  T q = x / y;
  return q - (q * y > x);
}

template<typename T, typename U> T ceil(T x, U y) {
  assert(y > 0);
  return ceil_div(x, y) * y;
}

template<typename T, typename U> T floor(T x, U y) {
  assert(y > 0);
  return floor_div(x, y) * y;
}

template<class...> struct typelist {};

template<class T, class... Ts>
constexpr bool any_same = (std::is_same_v<T, Ts> || ...);

template<class F> struct y_combinator {
  template<class... TLs> struct ref {
    y_combinator &self;
    template<class... Args> decltype(auto) operator()(Args &&...args) const {
      using G = std::conditional_t<any_same<typelist<Args...>, TLs...>,
                                   ref<TLs...>, ref<TLs..., typelist<Args...>>>;
      return self.f(G{self}, std::forward<Args>(args)...);
    }
  };
  F f;
  template<class... Args> decltype(auto) operator()(Args &&...args) {
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









#ifndef JHELPER_EXAMPLE_PROJECT_TASKS_SEARCH_HPP_
#define JHELPER_EXAMPLE_PROJECT_TASKS_SEARCH_HPP_

#include <optional>







#ifndef JHELPER_EXAMPLE_PROJECT_LIBRARY_MIDPOINT_HPP_
#define JHELPER_EXAMPLE_PROJECT_LIBRARY_MIDPOINT_HPP_











template<typename Int> constexpr Int midpoint(Int a, Int b) noexcept {
  using U = std::make_unsigned_t<Int>;
  int sign = 1;
  U m = a;
  U M = b;
  if (a > b) {
    sign = -1;
    m = b;
    M = a;
  }
  return a + sign * Int(U(M - m) >> 1);
}
#endif


template<typename Compare>
int ternary_search(int L, int R, const Compare &compare) {
  assert(L <= R);
  

  

  while (L < R) {
    int mid = L + (R - L) / 2, mm = mid + 1 + (R - mid - 1) / 2;
    if (compare(mid, mm)) {
      

      R = mm - 1;
    } else {
      

      L = mid + 1;
    }
  }
  assert(L == R);
  return L;
}








template<typename Int, typename Check>
std::optional<Int> bin_search(Int L, Int R, const Check &check, int type = 0,
                              bool knowingly = false) {
  Int l = L, r = R;
  std::optional<Int> ans;
  while (l <= r) {
    if (l == r and knowingly) {
      ans = l;
      break;
    }
    Int m = midpoint(l, r);
    int res = check(m);
    if (res == -1) {
      if (m == R)
        break;
      l = m + 1;
    } else if (res == 1) {
      if (m == L)
        break;
      r = m - 1;
    } else {
      ans = m;
      if (type == 0)
        break;
      knowingly = false;
      if (type == -1) {
        if (m == L)
          break;
        else
          r = m - 1;
      } else {
        if (m == R)
          break;
        else
          l = m + 1;
      }
    }
  }
  return ans;
}
template<typename Int, typename Check>
std::optional<Int> find_first(Int L, Int R, const Check &check) {
  std::optional<Int> ans;
  Int l = L, r = R;
  while (l <= r) {
    Int m = midpoint(l, r);
    if (check(m)) {
      ans = m;
      if (m == L)
        break;
      r = m - 1;
    } else {
      if (m == R)
        break;
      l = m + 1;
    }
  }
  return ans;
}
template<typename Int, typename Check>
std::optional<Int> find_last(Int L, Int R, const Check &check) {
  std::optional<Int> ans;
  Int l = L, r = R;
  while (l <= r) {
    Int m = midpoint(l, r);
    if (check(m)) {
      ans = m;
      if (m == R)
        break;
      l = m + 1;
    } else {
      if (m == L)
        break;
      r = m - 1;
    }
  }
  return ans;
}
#endif


#ifndef ALGO_MODULAR
#define ALGO_MODULAR









#ifndef JHELPER_EXAMPLE_PROJECT_LIBRARY_INVERSE_HPP_
#define JHELPER_EXAMPLE_PROJECT_LIBRARY_INVERSE_HPP_

template<typename T> T inverse(T a, T m) {
  assert(a != 0);
  assert(m > 0);
  T b = m, u = 0, v = 1;
  while (a != 0) {
    T t = b / a;
    b -= t * a;
    std::swap(a, b);
    u -= t * v;
    std::swap(u, v);
  }
  assert(b == 1);
  return u < 0 ? u + m : u;
}
#endif




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
using mint = Mint<998244353>;
mint operator""_m(unsigned long long v) {
  return mint(static_cast<int>(v));
}
void solve() {
  INT(n);
  VI(a, n);
  if (n == 1)
    rp(1);

  vl sum(n);
  ll t = 0;
  rng (i, 0, n, 2)
    sum[i] = t += a[i];
  t = 0;
  rng (i, 1, n, 2)
    sum[i] = t += a[i];

  mint ans = 0;
  ans += sum[n - 1] != sum[n - 2];
  const ll half = accumulate(ALL(a), 0LL) / 2;
  debug(ans);

  vl suf_sum(n);
  t = 0;
  down (i, n - 1, 0) { suf_sum[i] = t += a[i]; }
  vl pre_sum(n);
  t = 0;
  rng (i, n)
    pre_sum[i] = t += a[i];

  

  rng (i, 1, n) {
    if (pre_sum[i] > half) {
      ans += n - i;
      break;
    }
  }
  

  

  up (i, 1, n - 2) {
    ll sum_p = suf_sum[i] + (i - 2 >= 0 ? sum[i - 2] : 0LL);
    ans += sum_p > half;
    if (i + 2 < n) {
      ans += sum_p - a[n - 1] > half;
    }
  }

  vl s_sum(n);
  t = 0;
  down (i, n - 1, 0, 2) { s_sum[i] = t += a[i]; }
  t = 0;
  down (i, n - 2, 0, 2) { s_sum[i] = t += a[i]; }
  

  rng (i, 2, n) {
    ll sum_p = s_sum[i];
    ans += sum_p > half;
  }
  

  

  rng (i, 2, n) {
    ll sum_p = a[0] + (i + 1 < n ? s_sum[i + 1] : 0LL);
    ans += sum_p > half;
  }
  

  down (i, n - 2, 2) {
    int max_cnt = (i - 2) / 2;
    

    auto res = find_first(0, max_cnt, [&](int c) {
      return suf_sum[i] + sum[i - 2] - sum[i - 2 - 2 * c] > half;
    });
    if (res) {
      ans += max_cnt - *res + 1;
    }
  }
  

  down (i, n - 2, 3) {
    int max_c = (i - 3) / 2;
    auto res = find_first(0, max_c, [&](int c) {
      return suf_sum[i] + a[0] + sum[i - 2] - sum[i - 2 - 2 * c] > half;
    });
    if (res) {
      ans += max_c - *res + 1;
    }
  }
  

  down (i, n - 3, 2) {
    int max_c = (i - 2) / 2;
    auto res = find_first(0, max_c, [&](int c) {
      return suf_sum[i] - a[n - 1] + sum[i - 2] - sum[i - 2 - 2 * c] > half;
    });
    if (res) {
      ans += max_c - *res + 1;
    }
  }
  

  down (i, n - 3, 3) {
    int max_c = (i - 3) / 2;
    auto res = find_first(0, max_c, [&](int c) {
      return suf_sum[i] - a[n - 1] + a[0] + sum[i - 2] - sum[i - 2 - 2 * c]
          > half;
    });
    if (res) {
      ans += max_c - *res + 1;
    }
  }
  pl(ans);
}



int main() {
#if defined FILE_IO and not defined LOCAL
  freopen(FILE_IO ".in", "r", stdin);
  freopen(FILE_IO ".out", "w", stdout);
#endif
  int n;
cin >> n;
for (int i = 0; i < n; ++i) {
	solve();
}

  return 0;
}