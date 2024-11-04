

#if not defined LOCAL and not defined NDEBUG
#define NDEBUG
#endif
#include <iostream>
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
#define debug(...)
#endif
#ifndef show
#define show(...)
#endif
using namespace io;
using namespace std;
#endif



void solve() {
  INT(n, m);
  vv<pii> g(n);
  rep (m) {
    INT(a, b, c);
    g[a].eb(b, c);
  }
  const int inf = INT_MAX / 2;
  auto Dijkstra = [&](int s) {
    vi d(n, inf);
    vb done(n, false);
    FOR (u, w, g[s]) {
      debug(s, u, w);
      d[u] = w;
    }
    while (1) {
      int t = -1;
      rng (i, n)
        if (not done[i] and (t == -1 or d[t] > d[i]))
          t = i;
      if (t == -1)
        break;
      done[t] = true;
      debug(t, d[t]);
      chkmin(d[(t + 1) % n], d[t] + 1);
      FOR (u, w, g[t]) { chkmin(d[(u + d[t]) % n], d[t] + w); }
    }
    rng (i, s)
      pt(d[i]);
    pt(0);
    rng (i, s + 1, n)
      pt(d[i]);
    NL;
  };
  rng (i, n) {
    Dijkstra(i);
  }
}



int main() {
#if defined FILE_IO and not defined LOCAL
  freopen(FILE_IO ".in", "r", stdin);
  freopen(FILE_IO ".out", "w", stdout);
#endif
  solve();
  return 0;
}
