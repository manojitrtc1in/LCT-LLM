


#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdlib>
#include <deque>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <optional>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

using namespace std;

template <class C>
constexpr auto ssize(const C& c)
    -> std::common_type_t<std::ptrdiff_t,
                          std::make_signed_t<decltype(c.size())>> {
  return (std::common_type_t<std::ptrdiff_t,
                             std::make_signed_t<decltype(c.size())>>)c.size();
}

template <class T, std::ptrdiff_t N>
constexpr std::ptrdiff_t ssize(const T (&)[N]) noexcept {
  return N;
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, bool> has_single_bit(
    T x) noexcept {
  return x != 0 && (x & (x - 1)) == 0;
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, int> countl_zero(
    T x) noexcept {
  if constexpr (sizeof(T) <= sizeof(unsigned)) {
    return __builtin_clz(x) - (std::numeric_limits<unsigned>::digits -
                               std::numeric_limits<T>::digits);
  } else if constexpr (sizeof(T) <= sizeof(unsigned long)) {
    return __builtin_clzl(x) - (std::numeric_limits<unsigned long>::digits -
                                std::numeric_limits<T>::digits);
  } else {
    static_assert(sizeof(T) <= sizeof(unsigned long long));
    return __builtin_clzll(x) -
           (std::numeric_limits<unsigned long long>::digits -
            std::numeric_limits<T>::digits);
  }
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, int> countr_zero(
    T x) noexcept {
  if constexpr (sizeof(T) <= sizeof(unsigned)) {
    return __builtin_ctz(x);
  } else if constexpr (sizeof(T) <= sizeof(unsigned long)) {
    return __builtin_ctzl(x);
  } else {
    static_assert(sizeof(T) <= sizeof(unsigned long long));
    return __builtin_ctzll(x);
  }
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, int> popcount(T x) noexcept {
  if constexpr (sizeof(T) <= sizeof(unsigned)) {
    return __builtin_popcount(x);
  } else if constexpr (sizeof(T) <= sizeof(unsigned long long)) {
    return __builtin_popcountl(x);
  } else {
    static_assert(sizeof(T) <= sizeof(unsigned long long));
    return __builtin_popcountll(x);
  }
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, T> bit_width(T x) noexcept {
  return (T)(std::numeric_limits<T>::digits - countl_zero(x));
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, T> bit_ceil(T x) noexcept {
  return (T)(x <= 1 ? 1 : (T)1 << bit_width((T)(x - 1)));
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, T> bit_floor(T x) noexcept {
  return (T)(x == 0 ? 0 : (T)1 << (bit_width(x) - 1));
}

template <class Fun>
class y_combinator_result {
 public:
  template <class T>
  explicit y_combinator_result(T&& fun) : fun_(std::forward<T>(fun)) {}

  template <class... Args>
  decltype(auto) operator()(Args&&... args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }

 private:
  Fun fun_;
};

template <class Fun>
decltype(auto) y_combinator(Fun&& fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::optional<T>& opt) {
  return opt ? os << *opt : os << "nullopt";
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) {
  return os << '{' << p.first << ", " << p.second << '}';
}

template <typename Container,
          std::enable_if_t<!std::is_convertible_v<Container, std::string_view>,
                           typename Container::const_iterator>* = nullptr>
std::ostream& operator<<(std::ostream& os, const Container& c) {
  os << '{';
  for (auto it = c.begin(); it != c.end(); ++it) {
    if (it != c.begin()) {
      os << ", ";
    }
    os << *it;
  }
  return os << '}';
}

template <typename T, typename Container>
std::ostream& operator<<(std::ostream& os, std::stack<T, Container> s) {
  std::vector<T> v(s.size());
  for (auto it = v.rbegin(); it != v.rend(); ++it) {
    *it = s.top();
    s.pop();
  }
  return os << v;
}

template <typename T, typename Container>
std::ostream& operator<<(std::ostream& os, std::queue<T, Container> q) {
  os << '{';
  if (!q.empty()) {
    os << q.front();
    q.pop();
    while (!q.empty()) {
      os << ", " << q.front();
      q.pop();
    }
  }
  return os << '}';
}

template <typename T, typename Container, typename Compare>
std::ostream& operator<<(std::ostream& os,
                         std::priority_queue<T, Container, Compare> pq) {
  os << '{';
  if (!pq.empty()) {
    os << pq.top();
    pq.pop();
    while (!pq.empty()) {
      os << ", " << pq.top();
      pq.pop();
    }
  }
  return os << '}';
}

namespace detail {

template <int I, typename... Ts>
void tuple_print(std::ostream& os, const std::tuple<Ts...>& t) {
  static_assert(0 <= I && I <= sizeof...(Ts));
  if constexpr (I != sizeof...(Ts)) {
    if constexpr (I != 0) {
      os << ", ";
    }
    os << std::get<I>(t);
    tuple_print<I + 1>(os, t);
  }
}

}  


template <typename... Ts>
std::ostream& operator<<(std::ostream& os, const std::tuple<Ts...>& t) {
  os << '{';
  detail::tuple_print<0>(os, t);
  return os << '}';
}

namespace detail {

template <typename T1, typename... Ts>
void debug_print(std::string_view keys, const T1& val1, const Ts&... vals) {
  if constexpr (sizeof...(Ts) == 0) {
    std::cerr << keys << " = " << val1 << std::endl;
  } else {
    for (int i = 0, paren = 0; i < (int)keys.size(); ++i) {
      if (keys[i] == '(' || keys[i] == '{') {
        ++paren;
      } else if (keys[i] == ')' || keys[i] == '}') {
        --paren;
      } else if (keys[i] == ',' && paren == 0) {
        std::cerr << keys.substr(0, i) << " = " << val1 << ',';
        return debug_print(keys.substr(i + 1), vals...);
      }
    }
  }
}

template <typename... Ts>
void debug_print(int line, const Ts&... keyvals) {
  if constexpr (sizeof...(Ts) <= 1) {
    std::cerr << "  " << line << " |" << std::endl;
  } else {
    std::cerr << "  " << line << " | ";
    debug_print(keyvals...);
  }
}

}  


#if defined(TYLER) && defined(__GNUC__) && __GNUC__ >= 8
#define debug(...) \
  detail::debug_print(__LINE__, #__VA_ARGS__ __VA_OPT__(, ) __VA_ARGS__)
#elif defined(TYLER)
#define debug(...) detail::debug_print(__LINE__, #__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) ((void)0)
#endif



constexpr bool is_prime(int n) {
  if (n < 0) {
    n = -n;
  }
  if (n == 2) {
    return true;
  }
  if ((n & 1) == 0 || n == 1) {
    return false;
  }
  int r = countr_zero((unsigned)(n - 1));
  int d = (n - 1) >> r;
  for (long long a : {2, 3, 5, 7}) {
    if ((a == 3 && n < 2'047) || (a == 5 && n < 1'373'653) ||
        (a == 7 && n < 25'326'001)) {
      return true;
    }
    long long x = 1;
    for (int b = d; b != 0; b >>= 1) {
      if (b & 1) {
        x = x * a % n;
      }
      a = a * a % n;
    }
    if (x == 1) {
      continue;
    }
    for (int i = 1; x != n - 1; ++i) {
      if (i == r || (x = x * x % n) == 1) {
        return false;
      }
    }
  }
  return true;
}

#ifdef __SIZEOF_INT128__

// Miller-Rabin primality test for long long.
constexpr bool is_prime(long long n) {
  if (n < 0) {
    n = -n;
  }
  if (n == 2) {
    return true;
  }
  if ((n & 1) == 0 || n == 1) {
    return false;
  }
  int r = countr_zero((unsigned long long)(n - 1));
  long long d = (n - 1) >> r;
  for (__int128 a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
    if ((a == 3 && n < 2'047LL) || (a == 5 && n < 1'373'653LL) ||
        (a == 7 && n < 25'326'001LL) || (a == 11 && n < 3'215'031'751LL) ||
        (a == 13 && n < 2'152'302'898'747LL) ||
        (a == 17 && n < 3'474'749'660'383LL) ||
        (a == 19 && n < 341'550'071'728'321LL) ||
        (a == 29 && n < 3'825'123'056'546'413'051LL)) {
      return true;
    }
    __int128 x = 1;
    for (long long b = d; b != 0; b >>= 1) {
      if (b & 1) {
        x = x * a % n;
      }
      a = a * a % n;
    }
    if (x == 1) {
      continue;
    }
    for (int i = 1; x != n - 1; ++i) {
      if (i == r || (x = x * x % n) == 1) {
        return false;
      }
    }
  }
  return true;
}

#endif

namespace detail {

// Pollard's rho integer factorization algorithm for int.


int factorize(int n) {
  std::mt19937 rng((std::uint_fast32_t)std::chrono::high_resolution_clock::now()
                       .time_since_epoch()
                       .count());
  std::uniform_int_distribution<int> dist(0, n - 1);
  while (true) {
    int x = dist(rng), c = dist(rng);
    int y = x, factor = 1;
    for (int k = 1; factor == 1; k <<= 1) {
      for (int i = 0; i < k && factor == 1; ++i) {
        x = (int)(((long long)x * x + c) % n);
        factor = std::gcd(y - x, n);
      }
      y = x;
    }
    if (factor != n) {
      return factor;
    }
  }
}

#ifdef __SIZEOF_INT128__





long long factorize(long long n) {
  std::mt19937_64 rng(
      std::chrono::high_resolution_clock::now().time_since_epoch().count());
  std::uniform_int_distribution<long long> dist(0, n - 1);
  while (true) {
    long long x = dist(rng), c = dist(rng);
    long long y = x, factor = 1;
    for (int k = 1; factor == 1; k <<= 1) {
      for (int i = 0; i < k && factor == 1; ++i) {
        x = (long long)(((__int128)x * x + c) % n);
        factor = std::gcd(y - x, n);
      }
      y = x;
    }
    if (factor != n) {
      return factor;
    }
  }
}

#endif

}  




class sieve {
 public:
  sieve(int n) : least_factor_(n + 1, 0) {
    for (int i = 2; i <= n; ++i) {
      if (least_factor_[i] == 0) {
        least_factor_[i] = i;
        primes_.push_back(i);
      }
      for (int p : primes_) {
        if (p > least_factor_[i] || p * i > n) {
          break;
        }
        least_factor_[p * i] = p;
      }
    }
  }

  std::vector<int> primes() const { return primes_; }

  template <typename T>
  std::vector<std::pair<T, int>> factorize(T x) const {
    static_assert(std::is_integral_v<T>);
    x = std::abs(x);
    std::vector<std::pair<T, int>> prime_counts;
    for (T p : primes_) {
      if (x < (int)least_factor_.size()) {
        while (x > 1) {
          p = least_factor_[x];
          int count = 0;
          do {
            x /= p;
            ++count;
          } while (least_factor_[x] == p);
          prime_counts.emplace_back(p, count);
        }
        return prime_counts;
      }
      if (p * p > x) {
        prime_counts.emplace_back(x, 1);
        return prime_counts;
      }
      if (x % p == 0) {
        int count = 0;
        do {
          x /= p;
          ++count;
        } while (x % p == 0);
        prime_counts.emplace_back(p, count);
      }
    }
    int k = (int)prime_counts.size();
    while (x > 1) {
      T p = x;
      while (!is_prime(p)) {
        p = detail::factorize(p);
      }
      int count = 0;
      do {
        x /= p;
        ++count;
      } while (x % p == 0);
      prime_counts.emplace_back(p, count);
    }
    std::sort(prime_counts.begin() + k, prime_counts.end());
    return prime_counts;
  }

 private:
  std::vector<int> primes_, least_factor_;
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.precision(12);
  std::cerr.precision(12);
  std::mt19937 rng((std::uint_fast32_t)std::chrono::high_resolution_clock::now()
                       .time_since_epoch()
                       .count());
  sieve sv(100);
  int n;
  cin >> n;
  map<int, vector<int>> mp;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    for (auto& [k, v] : sv.factorize(a)) {
      mp[k].push_back(v);
    }
  }
  long long ans = 1;
  for (auto& [k, v] : mp) {
    int x = 1 - (n - (int)v.size());
    if (x < 0) {
      continue;
    }
    nth_element(v.begin(), v.begin() + x, v.end());
    for (int i = 0; i < v[x]; ++i) {
      ans *= k;
    }
  }
  cout << ans << '\n';
  return 0;
}

int main_post_contest() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> pref(n + 1), suff(n + 1);
  for (int i = 0; i < n; ++i) {
    pref[i + 1] = gcd(pref[i], a[i]);
  }
  for (int i = n - 1; i >= 0; --i) {
    suff[i] = gcd(suff[i + 1], a[i]);
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    ans = gcd(ans, lcm((long long)a[i], gcd(pref[i], suff[i + 1])));
  }
  cout << ans << '\n';
  return 0;
}
