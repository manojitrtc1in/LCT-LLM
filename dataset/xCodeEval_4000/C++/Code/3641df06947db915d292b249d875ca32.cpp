

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







#ifndef JHELPER_EXAMPLE_PROJECT_LIBRARY_COMMON_HPP_
#define JHELPER_EXAMPLE_PROJECT_LIBRARY_COMMON_HPP_
#define TOKENPASTE(x, y) x##y
#define TOKENPASTE2(x, y) TOKENPASTE(x, y)
#endif


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
std::istream &operator>>(std::istream &in, const std::tuple<Ts...> &t) {
  std::apply([&in](auto &...args) { ((in >> args), ...); }, t);
  return in;
}

template<class... Args> void scan(Args &...args) {
  ((std::cin >> args), ...);
}

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
  ndarray() = default;
  template<typename... Args>
  ndarray(unsigned d, Args... args)
      : std::vector<ndarray<dimension - 1, T>>(
          d, ndarray<dimension - 1, T>(args...)) {}
};
template<typename T> class ndarray<1, T> : public std::vector<T> {
 public:
  template<typename... Args>
  ndarray<1, T>(Args &&...args) : std::vector<T>(std::forward<Args>(args)...) {}
};
#endif









#ifndef JHELPER_EXAMPLE_PROJECT_LIBRARY_MACROS_H_
#define JHELPER_EXAMPLE_PROJECT_LIBRARY_MACROS_H_






#define EVAL0(...) __VA_ARGS__
#define EVAL1(...) EVAL0(EVAL0(EVAL0(__VA_ARGS__)))
#define EVAL(...) EVAL1(EVAL1(EVAL1(__VA_ARGS__)))

#define EMPTY
#define MAP_END(...)                                                           \
  do {                                                                         \
  } while (0)

#define MAP_GET_END() 0, MAP_END
#define MAP_NEXT0(test, next, ...) next EMPTY
#define MAP_NEXT1(test, next) MAP_NEXT0(test, next)
#define MAP_NEXT(test, next) MAP_NEXT1(MAP_GET_END test, next)
#define MAP0(f, x, y, peek, ...)                                               \
  f(x, y) MAP_NEXT(peek, MAP1)(f, peek, __VA_ARGS__)
#define MAP1(f, x, y, peek, ...)                                               \
  f(x, y) MAP_NEXT(peek, MAP0)(f, peek, __VA_ARGS__)
#define MAP_2(f, ...) EVAL(MAP1(f, __VA_ARGS__, ()))

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
  for (auto &&[i, TOKENPASTE2(iter_, __LINE__), TOKENPASTE2(end_, __LINE__)] = \
           range_tuple<std::common_type<decltype(a), decltype(b)>::type>(a,    \
                                                                         b);   \
       i < TOKENPASTE2(end_, __LINE__); TOKENPASTE2(iter_, __LINE__) += c)
#define rng3(i, a, b) rng4(i, a, b, 1)
#define rng2(i, n) rng3(i, 0, n)
#define GET4(_1, _2, _3, _4, NAME, ...) NAME
#define rng(...) GET4(__VA_ARGS__, rng4, rng3, rng2)(__VA_ARGS__)
#define up4(i, a, b, c) rng (i, a, b + 1, c)
#define up3(i, a, b) up4(i, a, b, 1)
#define up(...) GET4(__VA_ARGS__, up4, up3, NO_IMPL)(__VA_ARGS__)
#define down4(i, b, a, c)                                                      \
  for (auto &&[i, TOKENPASTE2(iter_, __LINE__), TOKENPASTE2(end_, __LINE__)] = \
           range_tuple<std::common_type<decltype(a), decltype(b)>::type>(b,    \
                                                                         a);   \
       i >= TOKENPASTE2(end_, __LINE__); TOKENPASTE2(iter_, __LINE__) -= c)
#define down3(i, b, a) down4(i, b, a, 1)
#define down(...) GET4(__VA_ARGS__, down4, down3, NO_IMPL)(__VA_ARGS__)
#define rep(n)                                                                 \
  for (auto TOKENPASTE2(_iter_, __LINE__) = n;                                 \
       TOKENPASTE2(_iter_, __LINE__) > 0; --TOKENPASTE2(_iter_, __LINE__))
#define FOR(x, cont) for (auto &&x : cont)
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
  for (auto TOKENPASTE2(_n_, __LINE__) = n; i < TOKENPASTE2(_n_, __LINE__); ++i)
#define radv(i, n)                                                             \
  for (auto TOKENPASTE2(_n_, __LINE__) = n; i > TOKENPASTE2(_n_, __LINE__); --i)
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
#define rd(type, name, ...)                                                    \
  type name(__VA_ARGS__);                                                      \
  scan(name)
#define NL                                                                     \
  [] {                                                                         \
    std::cout << '\n';                                                         \
  }()
#define READ_VI(NAME, LEN)                                                     \
  std::vector<int> NAME(LEN);                                                  \
  scan(NAME);
#define VI(...) MAP_2(READ_VI, __VA_ARGS__)
#define READ_VL(NAME, LEN)                                                     \
  std::vector<long long> NAME(LEN);                                            \
  scan(NAME);
#define VL(...) MAP_2(READ_VL, __VA_ARGS__)
#define READ_VS(NAME, LEN)                                                     \
  std::vector<std::string> NAME(LEN);                                          \
  scan(NAME);
#define VS(...) MAP_2(READ_VS, __VA_ARGS__)
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
  s.erase(std::unique(std::begin(s), std::end(s)), std::end(s));
  return s;
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



template<typename T> std::vector<T> divisors(T n) {
  std::vector<T> res;
  T i = 1;
  for (; (unsigned long long) i * i < n; ++i) {
    if (n % i == 0) {
      res.push_back(i);
    }
  }
  int j = (int) res.size() - 1;
  if ((unsigned long long) i * i == n)
    res.push_back(i);
  while (j >= 0) {
    res.push_back(n / res[j]);
    --j;
  }
  return res;
}

template<typename T> std::vector<std::pair<T, int>> factorize_p(T n) {
  std::vector<std::pair<T, int>> res;
  for (T i = 2; (unsigned long long) i * i <= n; ++i) {
    int cnt = 0;
    while (n % i == 0) {
      n /= i;
      ++cnt;
    }
    if (cnt) {
      res.emplace_back(i, cnt);
    }
  }
  if (n > 1) {
    res.emplace_back(n, 1);
  }
  return res;
}

template<typename T> std::vector<T> factorize(T n) {
  std::vector<T> res;
  for (T i = 2; (unsigned long long) i * i <= n; ++i) {
    T t = 1;
    while (n % i == 0) {
      t *= i;
      n /= i;
    }
    if (t > 1)
      res.push_back(t);
  }
  if (n > 1)
    res.push_back(n);
  return res;
}

std::vector<int> get_prime(int n) {
  std::vector<int> minp((size_t) n + 1), p;
  for (int i = 2; i <= n; i++) {
    if (!minp[i]) {
      minp[i] = i;
      p.push_back(i);
    }
    for (auto x : p) {
      if (x <= minp[i] && (long long) x * i <= n)
        minp[x * i] = x;
      else
        break;
    }
  }
  return p;
}

std::vector<int> get_mpf(int n) {
  std::vector<int> minp((size_t) n + 1), p;
  for (int i = 2; i <= n; i++) {
    if (!minp[i]) {
      minp[i] = i;
      p.push_back(i);
    }
    int max_p = std::min(minp[i], n / i);
    for (int x : p) {
      if (x <= max_p) {
        minp[x * i] = x;
      } else
        break;
    }
  }
  return minp;
}

long long gcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long t = gcd(b, a % b, y, x);
  

  

  

  y -= x * (a / b);
  return t;
}

void solve() {
  auto mpf = get_mpf(20000000);
  auto npf = [&](int x) {
    int ans = 0;
    while (x > 1) {
      ++ans;
      int p = mpf[x];
      while (x % p == 0)
        x /= p;
    }
    return ans;
  };
  INT(ncase);
  rep (ncase) {
    INT(c, d, x);
    auto g = gcd(c, d);
    if (x % g) {
      pl(0);
      continue;
    }
    c /= g, d /= g, x /= g;
    ll ans = 0;
    auto check = [&](int y) {
      int t = d + y;
      if (t % c)
        return;
      ans += 1ll << npf(t / c);
    };
    int i = 1;
    for (; i * i < x; ++i) {
      if (x % i == 0)
        check(i), check(x / i);
    }
    if (i * i == x)
      check(i);
    pl(ans);
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
