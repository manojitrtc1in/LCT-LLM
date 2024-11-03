

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
#include <random>
#include <chrono>







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
using value_type_of =
    decltype(value_type_of_<std::remove_reference_t<Container>>());



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



template<template<typename...> typename Target, typename Aux, typename... Ts>
struct is_specialized_for_impl : std::false_type {};

template<template<typename...> typename Target, typename... Args>
struct is_specialized_for_impl<Target, decltype(sizeof(Target<Args...>)),
                               Args...> : std::true_type {};

template<template<typename...> typename Target, typename... Args>
using is_specialized_for =
    is_specialized_for_impl<Target, std::size_t, Args...>;
template<template<typename...> typename Target, typename... Args>
constexpr bool is_specialized_for_v =
    is_specialized_for<Target, Args...>::value;

template<typename T>
using is_tuple_like = is_specialized_for<std::tuple_size, T>;
template<typename T> constexpr bool is_tuple_like_v = is_tuple_like<T>::value;

template<typename T, typename = void> struct remove_all_extents_ {
  typedef std::remove_reference_t<T> type;
};

template<typename T>
struct remove_all_extents_<T, std::void_t<decltype(std::declval<T>()[0])>> {
  typedef
      typename remove_all_extents_<decltype(std::declval<T>()[0])>::type type;
};

template<typename T, typename = void>
struct rank_ : public std::integral_constant<std::size_t, 0> {};

template<typename T>
struct rank_<T, std::void_t<decltype(std::declval<T>()[0])>>
    : public std::integral_constant<
          std::size_t, rank_<decltype(std::declval<T>()[0])>::value + 1> {};
#endif



struct fast_ios {
  fast_ios() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cout.precision(10);
    std::cout << std::fixed;
  };
} const fast_ios_;

namespace io {
template<typename T, typename U>
std::ostream &operator<<(std::ostream &out, const std::pair<T, U> &p);
template<typename... Ts>
std::istream &operator>>(std::istream &in, std::tuple<Ts...> &t);
template<typename... Ts>
std::ostream &operator<<(std::ostream &, const std::tuple<Ts...> &);

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
  using value_type =
      std::remove_reference_t<decltype(*begin(std::declval<Container &>()))>;
  constexpr char delimiter =
      is_iterable_v<value_type> or is_tuple_like_v<value_type> ? '\n' : ' ';
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



template<typename... Ts>
std::ostream &operator<<(std::ostream &out, const std::tuple<Ts...> &theTuple) {
  std::apply(
      [&out](Ts const &...tupleArgs) {
        std::size_t n{0};
        ((out << tupleArgs << (++n != sizeof...(Ts) ? " " : "")), ...);
      },
      theTuple);
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
  explicit ndarray(Args&&... args)
      : std::vector<T>(std::forward<Args>(args)...) {}
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
#define pb emplace_back
#define eb emplace_back
#define MP make_pair
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
#define RI                                                                     \
  ([] {                                                                        \
    int x;                                                                     \
    std::cin >> x;                                                             \
    return x;                                                                  \
  })()
#define READ_VI(NAME, LEN)                                                     \
  std::vector<int> NAME(LEN);                                                  \
  scan(NAME);
#define VI(...) FOR_EACH_2(READ_VI, __VA_ARGS__)
#define READ_VII(NAME, LEN)                                                    \
  std::vector<std::pair<int, int>> NAME(LEN);                                  \
  scan(NAME);
#define VII(...) FOR_EACH_2(READ_VII, __VA_ARGS__)
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
  return std::forward<Container>(c);
}
template<typename Container> Container dec(Container &&c) {
  for (auto &e : c)
    --e;
  return std::forward<Container>(c);
}
template<typename A, typename B> inline bool chkmin(A &a, const B &b) {
  return b < a ? a = b, true : false;
}

template<typename A, typename B> inline bool chkmax(A &a, const B &b) {
  return a < b ? a = b, true : false;
}

template<typename Container> Container rev(Container &&c) {
  std::reverse(std::begin(c), std::end(c));
  return std::forward<Container>(c);
}


template<typename Sequence> Sequence uniq(Sequence &&s) {
  assert(std::is_sorted(std::begin(s), std::end(s)));
  s.erase(std::unique(std::begin(s), std::end(s)), std::end(s));
  return std::forward<Sequence>(s);
}

template<typename Container> auto max(const Container &c) {
  assert(std::size(c) > 0);
  return *std::max_element(std::begin(c), std::end(c));
}

template<typename Container> auto min(const Container &c) {
  assert(std::size(c) > 0);
  return *std::min_element(std::begin(c), std::end(c));
}

template<typename Array> int maxi(const Array &a) {
  assert(a.size() > 0);
  return int(std::max_element(std::begin(a), std::end(a)) - std::begin(a));
}

template<typename Array> int mini(const Array &a) {
  assert(a.size() > 0);
  return int(std::min_element(std::begin(a), std::end(a)) - std::begin(a));
}

template<typename Array, typename Value> auto lb(const Array &a, Value v) {
  assert(std::size(a) > 0);
  return std::lower_bound(std::begin(a), std::end(a), v);
}

template<typename Array, typename Value> auto ub(const Array &a, Value v) {
  assert(std::size(a) > 0);
  return std::upper_bound(std::begin(a), std::end(a), v);
}

template<typename Array, typename Value> int lbi(const Array &a, Value v) {
  return int(lb(a, v) - std::begin(a));
}

template<typename Iter, typename Value> int lbi(Iter beg, int count, Value v) {
  assert(count > 0);
  return int(std::lower_bound(beg, beg + count, v) - beg);
}

template<typename Iter, typename Value> int ubi(Iter beg, int count, Value v) {
  assert(count > 0);
  return int(std::upper_bound(beg, beg + count, v) - beg);
}

template<typename Array, typename Value> int ubi(const Array &a, Value v) {
  return int(ub(a, v) - std::begin(a));
}

template<typename Container>
Container iota(Container &&c, value_type_of<Container> v) {
  std::iota(std::begin(c), std::end(c), v);
  return std::forward<Container>(c);
}

template<typename Container, typename Compare = void *>
Container sort(Container &&c, Compare comp = nullptr) {
  if constexpr (std::is_same_v<Compare, void *>)
    std::sort(std::begin(c), std::end(c));
  else
    std::sort(std::begin(c), std::end(c), comp);
  return std::forward<Container>(c);
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
  return {std::forward<T>(iterable)};
}



template<typename T, typename U> T qceil(T x, U y) {
  assert(y > 0);
  T q = x / y;
  return q + (q * y < x);
}



template<typename T, typename U> T qfloor(T x, U y) {
  assert(y > 0);
  T q = x / y;
  return q - (q * y > x);
}



template<typename T, typename U> T mceil(T x, U y) {
  assert(y > 0);
  return qceil(x, y) * y;
}



template<typename T, typename U> T mfloor(T x, U y) {
  assert(y > 0);
  return qfloor(x, y) * y;
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

template<typename T> constexpr T INF = std::numeric_limits<T>::max() / 2;



template<typename T, typename U> T acc(const U& array) {
  return std::accumulate(std::begin(array), std::end(array), T(0));
}

#ifndef debug
#define debug(...)
#endif
#ifndef show
#define show(...)
#endif
using namespace io;
using namespace std;
#endif




template<typename int_t> inline int_t lowbit(int_t x) {
  return x & -x;
}





inline int bit_width(unsigned long long x) {
  assert(x > 0);
  return int(sizeof(unsigned long long) * 8 - __builtin_clzll(x));
}



template<typename int_t> inline int_t bit_floor(int_t x) {
  assert(x >= 0);
  while (x > lowbit(x)) {
    x &= x - 1;
  }
  return x;
}



unsigned long long bit_ceil(unsigned long long x) {
  if (x == 0)
    return 1;
  return x == lowbit(x) ? x : 1ULL << bit_width(x);
}

template<typename T> inline int bit(T a, int i) {
  return a >> i & 1;
}

inline bool is_subset(long long sub, long long s) {
  return (sub & s) == sub;
}

#define popcnt(x) __builtin_popcountll((x))

template<typename T> struct subset_tuple {
  explicit subset_tuple(T u) : s(u), u(u) {}
  const T &ref = s;
  T s;
  const T u;
};

#define for_each_nonempty_subset(s, u)                                         \
  for (auto &&[s, JOIN(subset_, __LINE__), JOIN(set_, __LINE__)] =             \
           subset_tuple(u);                                                    \
       s > 0; JOIN(subset_, __LINE__) = (s - 1) & JOIN(set_, __LINE__))

template<typename T> struct loop_controller {
  T loop_var;
  bool flag;
  const T u;
  explicit loop_controller(T u) : loop_var(u), flag(u >= 0), u(u) {}
  void after() {
    flag = loop_var > 0;
    loop_var = (loop_var - 1) & u;
  }
};

#define for_each_subset(s, u)                                                  \
  loop_controller JOIN(loop_controller_, __LINE__)(u);                         \
  for (const auto &s = JOIN(loop_controller_, __LINE__).loop_var;              \
       JOIN(loop_controller_, __LINE__).flag;                                  \
       JOIN(loop_controller_, __LINE__).after())



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

std::vector<mint> pow2_(1, mint(1));
mint pow2(int n) {
  assert(n >= 0);
  while (n + 1 > (int) pow2_.size())
    pow2_.push_back(pow2_.back() * 2);
  return pow2_[n];
}



int x;


























mint not_both(int n, int m) {
  return pow2(n) + pow2(m) - 1;
}

mint dfs2(const vi& p, const vi& q, int cur_bit) {
  if (p.empty() or q.empty())
    return 0;
  if (cur_bit == -1) {
    return (pow2(SZ(p)) - 1) * (pow2(SZ(q)) - 1);
  }
  vi p0, p1, q0, q1;
  FOR (t, p)
    bit(t, cur_bit) ? p1.pb(t) : p0.pb(t);
  FOR (t, q)
    bit(t, cur_bit) ? q1.pb(t) : q0.pb(t);

  if (bit(x, cur_bit) == 0) {
    return dfs2(p0, q0, cur_bit - 1) + dfs2(p1, q1, cur_bit - 1);
  }

  mint ans = 0;
  ans += (pow2(SZ(p0)) - 1) * (pow2(SZ(q0)) - 1);
  ans += (pow2(SZ(p1)) - 1) * (pow2(SZ(q1)) - 1);
  mint t1 = dfs2(p1, q0, cur_bit - 1);
  mint t2 = dfs2(p0, q1, cur_bit - 1);
  ans += t1 * not_both(SZ(p0), SZ(q1));
  ans += t2 * not_both(SZ(p1), SZ(q0));
  ans += t1 * t2;
  return ans;
}





mint dfs(const vi& a, int cur_bit) {
  if (a.empty())
    return 0;
  if (cur_bit == -1) {
    return pow2(SZ(a)) - 1;
  }
  vi a0, a1;
  FOR (t, a)
    if (bit(t, cur_bit))
      a1.pb(t);
    else
      a0.pb(t);
  if (bit(x, cur_bit) == 0) {
    return dfs(a1, cur_bit - 1) + dfs(a0, cur_bit - 1);
  }
  

  return pow2(SZ(a0)) - 1 + pow2(SZ(a1)) - 1 + dfs2(a0, a1, cur_bit - 1);
}






























































































void solve() {
  INT(n);
  cin >> x;
  VI (a, n);
  debug(a);
  pl(dfs(a, 29));

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

}


#include <iostream>

int main() {
#if defined FILE_IO and not defined LOCAL
  freopen(FILE_IO ".in", "r", stdin);
  freopen(FILE_IO ".out", "w", stdout);
#endif
  solve();
  return 0;
}
