#pragma GCC target("movbe")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4.1,sse4.2")
#pragma GCC optimize("O3")
#pragma GCC optimize("inline")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("omit-frame-pointer")
#include <immintrin.h>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
namespace dbg {
#define debug(x) ((void)0)
}
namespace algo {
namespace detail {
template <typename Tp>
concept integer = std::integral<Tp> && !std::same_as<Tp, bool>;
template <typename Tp>
concept addable = requires(std::remove_reference_t<Tp> &a,
                           const std::remove_reference_t<Tp> &b) {
  { a += b }
  ->std::same_as<std::remove_reference_t<Tp> &>;
};
template <typename Tp>
concept multipliable = requires(std::remove_reference_t<Tp> &a,
                                const std::remove_reference_t<Tp> &b) {
  { a *= b }
  ->std::same_as<std::remove_reference_t<Tp> &>;
};
template <typename Function>
struct function_traits : public function_traits<decltype(
                             &std::remove_reference_t<Function>::operator())> {
};
template <typename Function, typename ReturnType, typename... Args>
struct function_traits<ReturnType (Function::*)(Args...) const> {
  static constexpr size_t arity = sizeof...(Args);
  using result_type = ReturnType;
  template <size_t I>
  struct arg {
    using type = std::tuple_element_t<I, std::tuple<Args...>>;
  };
};
template <typename ReturnType, typename... Args>
struct function_traits<ReturnType (*)(Args...)> {
  static constexpr size_t arity = sizeof...(Args);
  using result_type = ReturnType;
  template <size_t I>
  struct arg {
    using type = std::tuple_element_t<I, std::tuple<Args...>>;
  };
};
template <typename ReturnType, typename... Args>
struct function_traits<ReturnType(Args...)> {
  static constexpr size_t arity = sizeof...(Args);
  using result_type = ReturnType;
  template <size_t I>
  struct arg {
    using type = std::tuple_element_t<I, std::tuple<Args...>>;
  };
};
template <typename Function>
using extract_return_t = typename function_traits<Function>::result_type;
template <typename Function, typename ReturnType, typename... Args>
concept callable = std::invocable<Function, Args...>
    &&std::same_as<std::invoke_result_t<Function, Args...>, ReturnType>;
template <typename Function, typename Arg>
concept unary_op = callable<Function, Arg, Arg>;
template <typename Function, typename Arg>
concept binary_op = callable<Function, Arg, Arg, Arg>;
template <typename Tp>
concept less_than_comparable = requires(const std::remove_reference_t<Tp> &a,
                                        const std::remove_reference_t<Tp> &b) {
  { a < b }
  ->std::convertible_to<bool>;
  { !(a < b) }
  ->std::convertible_to<bool>;
};
template <typename Tp>
concept equality_comparable = std::equality_comparable<Tp>;
template <typename From, typename To>
concept constructible = std::constructible_from<To, From>;
template <typename InputIterator, typename ValueType>
concept input_iterator = std::input_iterator<InputIterator>
    &&std::same_as<std::iter_value_t<InputIterator>, ValueType>;
template <typename Tp>
concept qword_fittable = integer<Tp> && sizeof(Tp) <= 8UL;
template <typename Tp>
concept dword_fittable = qword_fittable<Tp> && sizeof(Tp) <= 4UL;
template <typename Tp>
concept word_fittable = dword_fittable<Tp> && sizeof(Tp) <= 2UL;
template <typename Tp>
concept byte_fittable = word_fittable<Tp> && sizeof(Tp) == 1UL;
template <integer Tp>
struct safely_multipliable;
template <>
struct safely_multipliable<char> {
  using type = int16_t;
};
template <>
struct safely_multipliable<unsigned char> {
  using type = uint16_t;
};
template <>
struct safely_multipliable<short> {
  using type = int32_t;
};
template <>
struct safely_multipliable<int> {
  using type = int64_t;
};
template <>
struct safely_multipliable<unsigned int> {
  using type = uint64_t;
};
template <>
struct safely_multipliable<long> {
  using type = __int128_t;
};
template <>
struct safely_multipliable<unsigned long> {
  using type = __uint128_t;
};
template <>
struct safely_multipliable<long long> {
  using type = __int128_t;
};
template <>
struct safely_multipliable<unsigned long long> {
  using type = __uint128_t;
};
template <typename Tp>
using safe_mul_t = typename safely_multipliable<Tp>::type;
}
}
namespace algo {
namespace detail {
constexpr long
likely(bool x) noexcept {
  return __builtin_expect(x, 1);
}
constexpr long
unlikely(bool x) noexcept {
  return __builtin_expect(x, 0);
}
constexpr void
unreachable() noexcept {
  __builtin_unreachable();
}
constexpr void
assume(bool x) noexcept {
  if (!x) unreachable();
}
}
}
namespace algo {
template <detail::less_than_comparable Tp>
std::vector<int>
argsort(const std::vector<Tp> &vec) {
  std::vector<int> ind(vec.size());
  iota(ind.begin(), ind.end(), 0);
  sort(ind.begin(), ind.end(),
       [&](int a, int b) -> bool { return vec[a] < vec[b]; });
  return ind;
}
template <detail::less_than_comparable Tp>
void
sort_unique_erase(std::vector<Tp> &vec) noexcept {
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
}
template <detail::less_than_comparable Tp>
int
argmin(const std::vector<Tp> &vec) {
  int j = -1;
  for (int i = 0; i < ssize(vec); ++i) {
    if (detail::unlikely(j == -1 || vec[j] < vec[i])) { j = i; }
  }
  return j;
}
template <detail::less_than_comparable Tp>
int
argmax(const std::vector<Tp> &vec) {
  int j = -1;
  for (int i = 0; i < ssize(vec); ++i) {
    if (detail::unlikely(j == -1 || vec[j] < vec[i])) { j = i; }
  }
  return j;
}
template <detail::integer Tp, std::predicate<Tp> Predicate>
constexpr Tp
bisect(Tp low, Tp high, const Predicate &pred) {
  while (low < high) {
    Tp mid = low + high >> 1;
    pred(mid) ? low = mid + 1 : high = mid;
  }
  return low;
}
template <detail::less_than_comparable Tp>
int
lower_bound(const std::vector<Tp> &vec, const Tp &x) {
  return distance(vec.begin(), lower_bound(vec.begin(), vec.end(), x));
}
template <detail::less_than_comparable Tp>
int
upper_bound(const std::vector<Tp> &vec, const Tp &x) {
  return distance(vec.begin(), upper_bound(vec.begin(), vec.end(), x));
}
void
inverse(std::vector<int> &perm) {
  std::vector<int> out(perm.size());
  for (int i = 0; i < ssize(perm); ++i) { out[perm[i]] = i; }
  perm = move(out);
}
template <std::semiregular Tp>
void
permute(std::vector<Tp> &vec, const std::vector<int> &perm) {
  std::vector<Tp> out(vec.size());
  for (int i = 0; i < ssize(vec); ++i) { out[perm[i]] = vec[i]; }
  vec = move(out);
}
template <detail::less_than_comparable Tp>
std::vector<int>
compress(const std::vector<Tp> &vec) {
  std::vector<int> ind = argsort(vec);
  std::vector<int> out(vec.size());
  for (int i = 0, c = 0; i < ssize(vec); ++c) {
    int j = i;
    do {
      out[ind[j]] = c;
    } while (++j < ssize(vec) && !(vec[ind[j]] < vec[ind[i]]) &&
             !(vec[ind[i]] < vec[ind[j]]));
    i = j;
  }
  return out;
}
template <std::integral Tp>
constexpr std::common_type_t<int, Tp>
pow_m1(Tp n) {
  return -(n & 1) | 1;
}
}
namespace algo {
namespace detail {
template <multipliable Tp, integer Up>
constexpr Tp
binpow(Tp a, Up b) {
  Tp res(1);
  std::make_unsigned_t<Up> pw = b;
  while (pw) {
    if (pw & 0x01) { res *= a; }
    a *= a;
    pw >>= 1;
  }
  return res;
}
template <multipliable T1, constructible<T1> T2, integer Up>
constexpr T1
binpow(T1 a, Up b, const T2 &init) {
  T1 res(init);
  std::make_unsigned_t<Up> pw = b;
  while (pw) {
    if (pw & 0x01) { res *= a; }
    a *= a;
    pw >>= 1;
  }
  return res;
}
template <integer Tp>
constexpr Tp
euler_phi(Tp n) {
  Tp ans = n;
  if (!(n & 0x01)) {
    ans >>= 1;
    do { n >>= 1; } while (!(n & 0x01));
  }
  for (Tp i = 3; i * i <= n; i += 2) {
    if (Tp x = n / i; n - x * i == 0) {
      ans -= ans / i;
      do { n = x, x /= i; } while (n - x * i == 0);
    }
  }
  if (n > 1) { ans -= ans / n; }
  return ans;
}
template <integer Tp>
constexpr std::common_type_t<int, Tp>
mobius(Tp n) {
  if (n == 1) { return 1; }
  int cnt = 0;
  if (!(n & 0x01)) {
    n >>= 1;
    if (!(n & 0x01)) { return 0; }
    cnt++;
  }
  for (Tp i = 3; i * i <= n; i += 2) {
    if (Tp x = n / i; n - x * i == 0) {
      n = x;
      if (n % i == 0) { return 0; }
      cnt++;
    }
  }
  return (cnt & 0x01) ? -1 : 1;
}
template <integer T1, integer T2>
constexpr std::pair<std::common_type_t<T1, T2>, std::common_type_t<T1, T2>>
euclidean_extended(T1 a, T2 b) {
  using common_t = std::common_type_t<T1, T2>;
  common_t x0 = 1, y0 = 0, x1 = 0, y1 = 1, a0 = a, b0 = b;
  while (b0) {
    common_t q = a0 / b0, tp = x0;
    x0 = x1, x1 = tp - q * x1, tp = y0, y0 = y1, y1 = tp - q * y1, tp = a0,
    a0 = b0, b0 = tp - q * b0;
  }
  if (a0 < 0) { x0 = -x0, y0 = -y0; }
  return std::make_pair(x0, y0);
}
template <integer T1, integer T2, integer Up>
constexpr std::common_type_t<T1, T2>
binpow_mod(T1 a, Up b, T2 m) {
  using common_t = std::common_type_t<T1, T2>;
  common_t ans = 1, mul = a, mod = m;
  std::make_unsigned_t<Up> pw = b;
  if ((mul %= mod) < 0) mul += mod;
  while (pw) {
    if (pw & 0x01) { ans = static_cast<safe_mul_t<common_t>>(mul) * ans % mod; }
    mul = static_cast<safe_mul_t<common_t>>(mul) * mul % mod;
    pw >>= 1;
  }
  return ans;
}
}
}
namespace algo {
namespace detail {
#define M_PI 3.14159265358979323846
#define M_PI_2 1.57079632679489661923
constexpr int
sqrt(int n) {
  int p = 32 - __builtin_clz(n);
  int ans = p & 0x01;
  for (p >>= 1, p &= ~1u; p >= 0; --p) {
    ans <<= 1;
    if ((ans + 1) * 1ll * (ans + 1) <= (n >> (p << 1))) { ans |= 1; }
  }
  return ans;
}
constexpr long long
sqrt(long long n) {
  int p = 64 - __builtin_clzll(n);
  long long ans = p & 0x01;
  for (p >>= 1, p &= ~1u; p >= 0; --p) {
    ans <<= 1;
    if ((ans + 1) * (ans + 1) <= (n >> (p << 1))) { ans |= 1; }
  }
  return ans;
}
double
cos(double x) noexcept {
  constexpr double tp = 1. / (2. * M_PI);
  x *= tp;
  x -= .25 + std::floor(x + .25);
  x *= 16. * (std::abs(x) - .5);
  x += .225 * x * (std::abs(x) - 1.);
  return x;
}
double
sin(double x) noexcept {
  return cos(M_PI_2 - x);
}
}
}
namespace algo {
namespace detail {
template <dword_fittable Tp>
constexpr int
count_lz(Tp n) {
  return __builtin_clz(n);
}
template <qword_fittable Tp>
constexpr int
count_lz(Tp n) {
  return __builtin_clzll(n);
}
template <dword_fittable Tp>
constexpr int
count_tz(Tp n) {
  return __builtin_ctz(n);
}
template <qword_fittable Tp>
constexpr int
count_tz(Tp n) {
  return __builtin_ctzll(n);
}
template <dword_fittable Tp>
constexpr int
find_ffs(Tp n) {
  return __builtin_ffs(n) - 1;
}
template <qword_fittable Tp>
constexpr int
find_ffs(Tp n) {
  return __builtin_ffsll(n) - 1;
}
template <dword_fittable Tp>
constexpr int
bit_width(Tp n) {
  return 32 - count_lz(n);
}
template <qword_fittable Tp>
constexpr int
bit_width(Tp n) {
  return 64 - count_lz(n);
}
template <dword_fittable Tp>
constexpr Tp
bit_floor(Tp n) {
  return 1u << (31 - count_lz(n));
}
template <qword_fittable Tp>
constexpr Tp
bit_floor(Tp n) {
  return 1ull << (63 - count_lz(n));
}
template <integer Tp>
constexpr Tp
bit_ceil(Tp n) {
  if (n == 0 || n == 1) { return 1; }
  return bit_floor(n - 1) << 1;
}
template <dword_fittable Tp>
constexpr int
log2_floor(Tp n) {
  return 31 - count_lz(n);
}
template <qword_fittable Tp>
constexpr int
log2_floor(Tp n) {
  return 63 - count_lz(n);
}
template <integer Tp>
constexpr int
log2_ceil(Tp n) {
  if (n == 0 || n == 1) { return 0; }
  return log2_floor(n - 1) + 1;
}
template <dword_fittable Tp>
constexpr int
popcount(Tp n) {
  return __builtin_popcount(n);
}
template <qword_fittable Tp>
constexpr int
popcount(Tp n) {
  return __builtin_popcountll(n);
}
}
}
namespace algo {
namespace detail {
template <dword_fittable Tp>
constexpr bool
prime_test(Tp n) {
  if (n <= 1) { return false; }
  if (n == 2 || n == 3 || n == 5 || n == 7) { return true; }
  const int s = count_tz(n - 1);
  const Tp d = (n - 1) >> s;
  constexpr Tp primes[] = {2, 3, 5, 7};
  for (Tp p : primes) {
    Tp x = binpow_mod(p, d, n);
    bool good = x == n - 1 || x == 1;
    for (int r = 1; r < s; ++r) {
      x = static_cast<safe_mul_t<Tp>>(x) * x % n;
      good |= x == n - 1;
    }
    if (!good) { return false; }
  }
  return true;
}
template <qword_fittable Tp>
constexpr bool
prime_test(Tp n) {
  if (n <= 1) { return false; }
  if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17 ||
      n == 19 || n == 23 || n == 29 || n == 31 || n == 37) {
    return true;
  }
  const int s = count_tz(n - 1);
  const Tp d = (n - 1) >> s;
  constexpr Tp primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
  for (Tp p : primes) {
    Tp x = binpow_mod(p, d, n);
    bool good = x == n - 1 || x == 1;
    for (int r = 1; r < s; ++r) {
      x = static_cast<safe_mul_t<Tp>>(x) * x % n;
      good |= x == n - 1;
    }
    if (!good) { return false; }
  }
  return true;
}
std::vector<int>
sieve_n(int n) noexcept {
  constexpr int block = 30007;
  std::vector<int> primes;
  const int rn = sqrt(n);
  std::vector<char> is_prime(rn + 2, true);
  for (int i = 2; i <= rn; ++i) {
    if (is_prime[i]) {
      primes.emplace_back(i);
      for (int j = i * i; j <= rn; j += i) { is_prime[j] = false; }
    }
  }
  std::vector<int> ans;
  std::array<char, block> blk;
  blk.fill(true);
  blk[0] = blk[1] = false;
  for (int k = 0; k * block <= n; ++k) {
    const int start = k * block;
    for (auto &&p : primes) {
      for (int j = std::max((start + p - 1) / p, p) * p - start; j < block;
           j += p) {
        blk[j] = false;
      }
    }
    for (int i = 0; i < block && start + i <= n; ++i) {
      if (blk[i]) { ans.emplace_back(start + i); }
      blk[i] = true;
    }
  }
  return ans;
}
std::vector<int>
euler_phi_n(int n) noexcept {
  std::vector<int> phi(n + 1);
  iota(phi.begin(), phi.end(), 0);
  for (int i = 2; i <= n; ++i) {
    if (phi[i] == i) {
      for (int j = i; j <= n; j += i) { phi[j] -= phi[j] / i; }
    }
  }
  return phi;
}
std::vector<int>
mobius_n(int n) noexcept {
  std::vector<int> ps;
  std::vector<int> lp(n + 1);
  std::vector<int> mu(n + 1, -1);
  mu[1] = 1;
  for (int i = 2, cnt = 0; i <= n; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      ps.emplace_back(i);
      cnt++;
    }
    for (int j = 0; j < cnt && ps[j] <= lp[i] && i * ps[j] <= n; ++j) {
      lp[i * ps[j]] = ps[j];
      mu[i * ps[j]] = -mu[i] * (ps[j] != lp[i]);
    }
  }
  return mu;
}
}
}
namespace algo {
template <detail::multipliable Tp, detail::integer Up>
constexpr Tp
pow(Tp a, Up b) {
  detail::assume(b >= 0);
  return detail::binpow(a, b);
}
template <detail::integer T1, detail::constructible<T1> T2, detail::integer Up>
constexpr T1
pow(T1 a, Up b, T2 ini) {
  detail::assume(b >= 0);
  return detail::binpow(a, b, ini);
}
template <detail::integer T1, detail::integer T2>
constexpr std::pair<std::common_type_t<T1, T2>, std::common_type_t<T1, T2>>
euclidean_extended(T1 a, T2 b) {
  return detail::euclidean_extended(a, b);
}
template <detail::integer Tp>
constexpr Tp
euler_phi(Tp n) {
  detail::assume(n >= 0);
  return detail::euler_phi(n);
}
template <detail::integer Tp>
constexpr std::common_type_t<int, Tp>
mobius(Tp n) {
  detail::assume(n >= 0);
  return detail::mobius(n);
}
template <detail::dword_fittable Tp>
std::vector<int>
euler_phi_n(Tp n) {
  detail::assume(n >= 0);
  return detail::euler_phi_n(n);
}
template <detail::dword_fittable Tp>
std::vector<int>
mobius_n(Tp n) {
  detail::assume(n >= 0);
  return detail::mobius_n(n);
}
template <detail::dword_fittable Tp>
std::vector<int>
sieve_n(Tp n) {
  detail::assume(n >= 0);
  return detail::sieve_n(n);
}
template <detail::integer Tp>
constexpr bool
prime_test(Tp n) {
  return detail::prime_test(n);
}
}
namespace algo {
namespace detail {
template <integer T1, integer T2>
constexpr std::common_type_t<T1, T2>
inv_mod(T1 a, T2 m) {
  auto&& [x, _] = euclidean_extended(a, m);
  if ((x %= m) < 0) { x += m; }
  return x;
}
template <integer T1, integer T2, integer T3>
std::optional<std::common_type_t<T1, T2, T3>>
discrete_log(T1 a, T2 b, T3 m) {
  using common_t = std::common_type_t<T1, T2, T3>;
  common_t a0 = a, b0 = b, m0 = m;
  if ((a0 %= m0) < 0) { a0 += m0; }
  if ((b0 %= m0) < 0) { b0 += m0; }
  const common_t n = sqrt(m0);
  assume(a0 >= 0 && a0 < m0);
  const common_t an = binpow_mod(a0, n, m0);
  std::unordered_map<common_t, common_t> f2;
  for (common_t q = 0, now = b0; q <= n; ++q) {
    f2[now] = q;
    now = static_cast<safe_mul_t<common_t>>(now) * a0 % m0;
  }
  for (int p = 1, cur = 1; p <= n; ++p) {
    cur = static_cast<safe_mul_t<common_t>>(cur) * an % m0;
    if (f2.contains(cur)) { return std::optional(n * p - f2[cur]); }
  }
  return std::nullopt;
}
template <integer Tp>
constexpr std::optional<Tp>
primitive_root(Tp n) {
  Tp phi_n = euler_phi(n);
  const Tp phi = phi_n;
  std::array<Tp, 23> divs = {};
  int cnt = 0;
  if (!(phi_n & 0x01)) {
    divs[cnt++] = 2;
    do { phi_n >>= 1; } while (!(phi_n & 0x01));
  }
  for (Tp i = 3; i * i <= phi_n; i += 2) {
    if (Tp x = phi / i; phi_n - x * i == 0) {
      divs[cnt++] = i;
      do { phi_n = x, x /= i; } while (phi_n - x * i == 0);
    }
  }
  if (phi_n > 1) { divs[cnt++] = phi_n; }
  for (Tp g = 1; g < n; ++g) {
    bool found = true;
    for (int p = 0; p < cnt; ++p) {
      if (binpow_mod(g, phi / divs[p], n) == 1) {
        found = false;
        break;
      }
    }
    if (found) { return std::optional(g); }
  }
  return n == 1 ? std::optional(1) : std::nullopt;
}
template <integer Tp>
constexpr Tp
primitive_root_prime(Tp n) {
  if (n == 2) { return 1; }
  std::array<Tp, 23> divs = {2};
  int cnt = 1;
  Tp x = n - 1;
  do { x >>= 1; } while (!(x & 0x01));
  for (Tp i = 3; i * i <= x; i += 2) {
    if (Tp y = x / i; x - y * i == 0) {
      divs[cnt++] = i;
      do { x = y, y /= i; } while (x - y * i == 0);
    }
  }
  if (x > 1) { divs[cnt++] = x; }
  for (Tp g = 2; g <= n; ++g) {
    bool found = true;
    for (int i = 0; i < cnt; ++i) {
      if (binpow_mod(g, (n - 1) / divs[i], n) == 1) {
        found = false;
        break;
      }
    }
    if (found) { return g; }
  }
  unreachable();
}
template <integer T1, integer T2, integer T3>
std::optional<std::common_type_t<T1, T2, T3>>
discrete_root(T1 a, T2 b, T3 n) {
  using common_t = std::common_type_t<T1, T2, T3>;
  common_t a0 = a, b0 = b, n0 = n;
  const common_t g = primitive_root_prime(n0);
  const common_t ga = binpow_mod(g, a0, n0);
  std::optional y = discrete_log(ga, b0, n0);
  return y.has_value() ? std::optional(binpow_mod(g, y.value(), n0))
                       : std::nullopt;
}
std::vector<int>
crt(const std::vector<int>& a, const std::vector<int>& p) {
  const int k = static_cast<int>(p.size());
  std::vector<int> ans(k);
  ans[0] = a[0];
  for (int i = 1; i < k; ++i) {
    ans[i] = a[i];
    for (int j = 0; j < i; ++j) {
      ans[i] = (int)inv_mod(p[j], p[i]) * 1ll * (ans[i] - ans[j]) % p[i];
      ans[i] += (ans[i] >> 31) & p[i];
    }
  }
  return ans;
}
}
}
namespace algo {
template <int MOD, bool IsPrime = detail::prime_test(MOD)>
struct modint {
  constexpr modint() = default;
  template <detail::integer Tp>
  constexpr modint(Tp x) : value_(static_cast<int>(x % MOD)) {
    value_ += (value_ >> 31) & MOD;
  }
  constexpr modint &
  operator+=(const modint &rhs) {
    value_ += rhs.val() - MOD;
    value_ += (value_ >> 31) & MOD;
    return *this;
  }
  constexpr modint &
  operator-=(const modint &rhs) {
    value_ -= rhs.val();
    value_ += (value_ >> 31) & MOD;
    return *this;
  }
  constexpr modint &
  operator*=(const modint &rhs) {
    detail::assume(val() >= 0 && val() < MOD);
    detail::assume(rhs.val() >= 0 && rhs.val() < MOD);
    value_ = static_cast<detail::safe_mul_t<int>>(val()) * rhs.val() % MOD;
    return *this;
  }
  constexpr modint &
  operator/=(const modint &rhs) {
    return operator*=(rhs.inv());
  }
  constexpr modint
  operator-() const {
    detail::assume(0 <= val() && val() < MOD);
    return modint(MOD - val());
  }
  constexpr modint &
  operator++() {
    return operator+=(1);
  }
  constexpr modint &
  operator--() {
    return operator-=(1);
  }
  constexpr modint
  operator++(int) {
    modint res(*this);
    operator++();
    return res;
  }
  constexpr modint
  operator--(int) {
    modint res(*this);
    operator--();
    return res;
  }
  constexpr friend bool
  operator<(const modint &lhs, const modint &rhs) {
    return lhs.val() < rhs.val();
  }
  constexpr friend bool
  operator>(const modint &lhs, const modint &rhs) {
    return rhs < lhs;
  }
  constexpr friend bool
  operator<=(const modint &lhs, const modint &rhs) {
    return !(lhs > rhs);
  }
  constexpr friend bool
  operator>=(const modint &lhs, const modint &rhs) {
    return !(lhs < rhs);
  }
  constexpr friend bool
  operator==(const modint &lhs, const modint &rhs) {
    return lhs.val() == rhs.val();
  }
  constexpr friend bool
  operator!=(const modint &lhs, const modint &rhs) {
    return !(lhs == rhs);
  }
  constexpr friend modint
  operator+(modint lhs, const modint &rhs) {
    lhs += rhs;
    return lhs;
  }
  constexpr friend modint
  operator-(modint lhs, const modint &rhs) {
    lhs -= rhs;
    return lhs;
  }
  constexpr friend modint
  operator*(modint lhs, const modint &rhs) {
    lhs *= rhs;
    return lhs;
  }
  constexpr friend modint
  operator/(modint lhs, const modint &rhs) {
    lhs /= rhs;
    return lhs;
  }
  constexpr int
  val() const {
    return value_;
  }
  constexpr int
  mod() const {
    return MOD;
  }
  constexpr modint
  inv() const requires(IsPrime) {
    return pow(MOD - 2);
  }
  constexpr modint
  inv() const requires(!IsPrime) {
    auto &&[res, g] = detail::euclidean_extended(val(), MOD);
    return res;
  }
  constexpr explicit operator int() const { return val(); }
  constexpr explicit operator bool() const { return val(); }
  constexpr explicit operator long() const { return val(); }
  constexpr explicit operator long long() const { return val(); }
  constexpr explicit operator unsigned int() const { return val(); }
  constexpr explicit operator unsigned long() const { return val(); }
  template <detail::integer Tp>
  constexpr modint
  pow(Tp x) const {
    detail::assume(x >= 0);
    modint res(1), mul(*this);
    while (x > 0) {
      if (x & 0x01) { res *= mul; }
      mul *= mul, x >>= 1;
    }
    return res;
  }
  friend std::ostream &
  operator<<(std::ostream &os, const modint &mt) {
    os << mt.val();
    return os;
  }
  template <detail::integer Tp>
  constexpr static modint
  from(Tp x) {
    detail::assume(0 <= x && x < MOD);
    return modint(x);
  }
private:
  int value_ = {0};
};
}
namespace algo {
namespace detail {
namespace fft {
template <int MOD>
constexpr int k = count_tz(MOD - 1);
template <int MOD>
constexpr int c = (MOD - 1) >> (k<MOD>);
template <int MOD>
constexpr int g = primitive_root_prime(MOD);
template <int MOD>
constexpr int minv = inv_mod(MOD, 0x100000000);
}
static inline __m256i
_mm256_mulmod2_epu32(__m256i A, __m256i B, __m256i M, __m256i Mi) {
  __m256i prod0246 = _mm256_mul_epu32(A, B);
  __m256i prod1357 = _mm256_mul_epu32(
      _mm256_srli_si256(A, 0b100),
      _mm256_srli_si256(B, 0b100));
  __m256i qlo = _mm256_mul_epu32(prod0246, Mi);
  __m256i qhi = _mm256_mul_epu32(prod1357, Mi);
  __m256i tmplo = _mm256_mul_epu32(qlo, M);
  __m256i tmphi = _mm256_mul_epu32(qhi, M);
  __m256i alo = _mm256_sub_epi32(prod0246, tmplo);
  __m256i ahi = _mm256_sub_epi32(prod1357, tmphi);
  __m256i d = _mm256_unpackhi_epi32(_mm256_shuffle_epi32(alo, _MM_SHUFFLE(3, 1, 2, 0)),
                                    _mm256_shuffle_epi32(ahi, _MM_SHUFFLE(3, 1, 2, 0)));
  return _mm256_add_epi32(d, _mm256_and_si256(_mm256_srai_epi32(d, 0x1F), M));
}
static inline __m256i
_mm256_reduce2_epu32(__m256i A, __m256i M, __m256i Mi) {
  __m256i qlo = _mm256_mul_epu32(A, Mi);
  __m256i qhi = _mm256_mul_epu32(_mm256_srli_si256(A, 0b100), Mi);
  __m256i prodlo = _mm256_mul_epu32(qlo, M);
  __m256i prodhi = _mm256_mul_epu32(qhi, M);
  __m256i tmplo = _mm256_sub_epi32(_mm256_setzero_si256(), prodlo);
  __m256i tmphi = _mm256_sub_epi32(_mm256_setzero_si256(), prodhi);
  __m256i d = _mm256_unpackhi_epi32(
      _mm256_shuffle_epi32(tmplo, _MM_SHUFFLE(3, 1, 2, 0)),
      _mm256_shuffle_epi32(tmphi, _MM_SHUFFLE(3, 1, 2, 0)));
  return _mm256_add_epi32(d, _mm256_and_si256(_mm256_srai_epi32(d, 0x1F), M));
}
static inline __m256i
_mm256_addmod2_epu32(__m256i A, __m256i B, __m256i M) {
  __m256i d = _mm256_sub_epi32(_mm256_add_epi32(A, B), M);
  return _mm256_add_epi32(d, _mm256_and_si256(_mm256_srai_epi32(d, 0x1F), M));
}
static inline __m256i
_mm256_submod2_epu32(__m256i A, __m256i B, __m256i M) {
  return _mm256_addmod2_epu32(A, _mm256_sub_epi32(M, B), M);
}
template <int MOD, bool Inverse>
static inline void
do_butterfly(int *out, int n) {
  constexpr int minv = fft::minv<MOD>;
  constexpr static auto w2k = [] {
    constexpr int k = count_tz(MOD - 1);
    constexpr int c = (MOD - 1) >> k;
    constexpr int g = primitive_root_prime(MOD);
    constexpr int w = binpow_mod(g, c, MOD);
    std::array<std::array<int, 17>, k + 1> ans{{}};
    ans[k][0] = 1;
    ans[k][1] = (Inverse) ? inv_mod(w, MOD) : w;
    for (int i = 2; i < 17; ++i) {
      ans[k][i] = static_cast<safe_mul_t<int>>(ans[k][i - 1]) * ans[k][1] % MOD;
    }
    for (int i = k - 1; i >= 0; --i) {
      ans[i][0] = 1;
      ans[i][1] = static_cast<safe_mul_t<int>>(ans[i + 1][1]) * ans[i + 1][1] % MOD;
      for (int j = 2; j < 17; ++j) {
        ans[i][j] = static_cast<safe_mul_t<int>>(ans[i][j - 1]) * ans[i][1] % MOD;
      }
    }
    for (int i = 0; i <= k; ++i) {
      for (int j = 0; j < 17; ++j) {
        ans[i][j] = (static_cast<safe_mul_t<int>>(ans[i][j]) << 32) % MOD;
      }
    }
    return ans;
  }();
  const __m256i reg_m = _mm256_set1_epi32(MOD);
  const __m256i reg_minv = _mm256_set1_epi32(minv);
  const __m256i reg_w1 = _mm256_set1_epi32(w2k[1][0]);
  const __m256i reg_w2 =
      _mm256_set_epi32(w2k[2][1], w2k[2][0], w2k[2][1], w2k[2][0], w2k[2][1],
                       w2k[2][0], w2k[2][1], w2k[2][0]);
  const __m256i reg_w3 =
      _mm256_set_epi32(w2k[3][3], w2k[3][2], w2k[3][3], w2k[3][2], w2k[3][1],
                       w2k[3][0], w2k[3][1], w2k[3][0]);
  const __m256i reg_w4 =
      _mm256_set_epi32(w2k[4][7], w2k[4][6], w2k[4][5], w2k[4][4], w2k[4][3],
                       w2k[4][2], w2k[4][1], w2k[4][0]);
  for (int i = 1, j = 0; i < n; ++i) {
    int mask = n >> 1;
    for (; mask & j; mask >>= 1) { j ^= mask; }
    j ^= mask;
    if (i < j) { std::swap(out[i], out[j]); }
  }
  for (int i = 0; i < n; i += 16) {
    __m256i v0 = _mm256_load_si256((__m256i *)&out[i]);
    __m256i v1 = _mm256_load_si256((__m256i *)&out[i + 8]);
    v0 = _mm256_shuffle_epi32(v0, _MM_SHUFFLE(3, 1, 2, 0));
    v1 = _mm256_shuffle_epi32(v1, _MM_SHUFFLE(3, 1, 2, 0));
    __m256i u0 = _mm256_unpacklo_epi32(v0, v1);
    __m256i u1 = _mm256_unpackhi_epi32(v0, v1);
    u1 = _mm256_mulmod2_epu32(u1, reg_w1, reg_m, reg_minv);
    v0 = _mm256_addmod2_epu32(u0, u1, reg_m);
    v1 = _mm256_submod2_epu32(u0, u1, reg_m);
    u0 = _mm256_unpacklo_epi32(v0, v1);
    u1 = _mm256_unpackhi_epi32(v0, v1);
    u1 = _mm256_mulmod2_epu32(u1, reg_w2, reg_m, reg_minv);
    v0 = _mm256_addmod2_epu32(u0, u1, reg_m);
    v1 = _mm256_submod2_epu32(u0, u1, reg_m);
    u0 = _mm256_permute2x128_si256(v0, v1, 0x20);
    u1 = _mm256_permute2x128_si256(v0, v1, 0x31);
    u1 = _mm256_mulmod2_epu32(u1, reg_w3, reg_m, reg_minv);
    v0 = _mm256_addmod2_epu32(u0, u1, reg_m);
    v1 = _mm256_submod2_epu32(u0, u1, reg_m);
    u0 = _mm256_unpacklo_epi64(v0, v1);
    u1 = _mm256_unpackhi_epi64(v0, v1);
    v0 = _mm256_permute4x64_epi64(u0, _MM_SHUFFLE(3, 1, 2, 0));
    v1 = _mm256_permute4x64_epi64(u1, _MM_SHUFFLE(3, 1, 2, 0));
    v1 = _mm256_mulmod2_epu32(v1, reg_w4, reg_m, reg_minv);
    _mm256_store_si256((__m256i *)&out[i], _mm256_addmod2_epu32(v0, v1, reg_m));
    _mm256_store_si256((__m256i *)&out[i + 8], _mm256_submod2_epu32(v0, v1, reg_m));
  }
  for (int lg = 5, l = 32; l <= n; ++lg, l <<= 1) {
    const __m256i reg_stride = _mm256_set1_epi32(w2k[lg][16]);
    const __m256i reg_fst =
        _mm256_set_epi32(w2k[lg][7], w2k[lg][6], w2k[lg][5], w2k[lg][4],
                         w2k[lg][3], w2k[lg][2], w2k[lg][1], w2k[lg][0]);
    const __m256i reg_sec =
        _mm256_set_epi32(w2k[lg][15], w2k[lg][14], w2k[lg][13], w2k[lg][12],
                         w2k[lg][11], w2k[lg][10], w2k[lg][9], w2k[lg][8]);
    for (int i = 0; i < n; i += l) {
      __m256i reg_wf = reg_fst;
      __m256i reg_ws = reg_sec;
      for (int j = 0; j < (l >> 1); j += 16) {
        __m256i v0 = _mm256_load_si256((__m256i *)&out[i + j]);
        __m256i v1 = _mm256_load_si256((__m256i *)&out[i + j + 8]);
        __m256i v2 = _mm256_load_si256((__m256i *)&out[i + j + (l >> 1)]);
        __m256i v3 = _mm256_load_si256((__m256i *)&out[i + j + (l >> 1) + 8]);
        v2 = _mm256_mulmod2_epu32(v2, reg_wf, reg_m, reg_minv);
        v3 = _mm256_mulmod2_epu32(v3, reg_ws, reg_m, reg_minv);
        _mm256_store_si256((__m256i *)&out[i + j], _mm256_addmod2_epu32(v0, v2, reg_m));
        _mm256_store_si256((__m256i *)&out[i + j + 8], _mm256_addmod2_epu32(v1, v3, reg_m));
        _mm256_store_si256((__m256i *)&out[i + j + (l >> 1)], _mm256_submod2_epu32(v0, v2, reg_m));
        _mm256_store_si256((__m256i *)&out[i + j + (l >> 1) + 8], _mm256_submod2_epu32(v1, v3, reg_m));
        reg_wf = _mm256_mulmod2_epu32(reg_wf, reg_stride, reg_m, reg_minv);
        reg_ws = _mm256_mulmod2_epu32(reg_ws, reg_stride, reg_m, reg_minv);
      }
    }
  }
  if constexpr (Inverse) {
    const int ninv = (static_cast<safe_mul_t<int>>(inv_mod(n, MOD)) << 32) % MOD;
    const __m256i reg_ninv = _mm256_set1_epi32(ninv);
    for (int i = 0; i < n; i += 16) {
      __m256i v0 = _mm256_load_si256((__m256i *)&out[i]);
      __m256i v1 = _mm256_load_si256((__m256i *)&out[i + 8]);
      _mm256_store_si256((__m256i *)&out[i],
                         _mm256_mulmod2_epu32(v0, reg_ninv, reg_m, reg_minv));
      _mm256_store_si256((__m256i *)&out[i + 8],
                         _mm256_mulmod2_epu32(v1, reg_ninv, reg_m, reg_minv));
    }
  }
}
template <int MOD>
inline static void
convolution(int *__restrict__ c1, int *__restrict__ c2, int n) {
  constexpr int minv = fft::minv<MOD>;
  constexpr int rsq = (-static_cast<uint64_t>(MOD)) % MOD;
  const __m256i reg_m = _mm256_set1_epi32(MOD);
  const __m256i reg_minv = _mm256_set1_epi32(minv);
  const __m256i reg_rsq = _mm256_set1_epi32(rsq);
  c1 = std::assume_aligned<32>(c1);
  c2 = std::assume_aligned<32>(c2);
  for (int i = 0; i < n; i += 16) {
    __m256i v0 = _mm256_load_si256((__m256i *)&c1[i]);
    __m256i v1 = _mm256_load_si256((__m256i *)&c1[i + 8]);
    __m256i u0 = _mm256_load_si256((__m256i *)&c2[i]);
    __m256i u1 = _mm256_load_si256((__m256i *)&c2[i + 8]);
    _mm256_store_si256((__m256i *)&c1[i],
                       _mm256_mulmod2_epu32(v0, reg_rsq, reg_m, reg_minv));
    _mm256_store_si256((__m256i *)&c1[i + 8],
                       _mm256_mulmod2_epu32(v1, reg_rsq, reg_m, reg_minv));
    _mm256_store_si256((__m256i *)&c2[i],
                       _mm256_mulmod2_epu32(u0, reg_rsq, reg_m, reg_minv));
    _mm256_store_si256((__m256i *)&c2[i + 8],
                       _mm256_mulmod2_epu32(u1, reg_rsq, reg_m, reg_minv));
  }
  do_butterfly<MOD, false>(c1, n);
  do_butterfly<MOD, false>(c2, n);
  for (int i = 0; i < n; i += 16) {
    __m256i v0 = _mm256_load_si256((__m256i *)&c1[i]);
    __m256i v1 = _mm256_load_si256((__m256i *)&c1[i + 8]);
    __m256i u0 = _mm256_load_si256((__m256i *)&c2[i]);
    __m256i u1 = _mm256_load_si256((__m256i *)&c2[i + 8]);
    _mm256_store_si256((__m256i *)&c1[i],
                       _mm256_mulmod2_epu32(v0, u0, reg_m, reg_minv));
    _mm256_store_si256((__m256i *)&c1[i + 8],
                       _mm256_mulmod2_epu32(v1, u1, reg_m, reg_minv));
    _mm256_store_si256((__m256i *)&c2[i], _mm256_setzero_si256());
    _mm256_store_si256((__m256i *)&c2[i + 8], _mm256_setzero_si256());
  }
  do_butterfly<MOD, true>(c1, n);
  for (int i = 0; i < n; i += 16) {
    __m256i v0 = _mm256_load_si256((__m256i *)&c1[i]);
    __m256i v1 = _mm256_load_si256((__m256i *)&c1[i + 8]);
    _mm256_store_si256((__m256i *)&c1[i],
                       _mm256_reduce2_epu32(v0, reg_m, reg_minv));
    _mm256_store_si256((__m256i *)&c1[i + 8],
                       _mm256_reduce2_epu32(v1, reg_m, reg_minv));
  }
}
template <int MOD, int MOD1 = 167772161, int MOD2 = 469762049, int MOD3 = 754974721>
static inline void
consolidate(int *__restrict__ c1, int *__restrict__ c2, int *__restrict__ c3,
             int *__restrict__ out, int n)
    requires(MOD1 < MOD2 && MOD2 < MOD3) {
  constexpr int inv12 = inv_mod(MOD1, MOD2);
  constexpr int inv13 = inv_mod(MOD1, MOD3);
  constexpr int inv23 = inv_mod(MOD2, MOD3);
  constexpr int i12_redc = (static_cast<safe_mul_t<int>>(inv12) << 32) % MOD2;
  constexpr int i13_redc = (static_cast<safe_mul_t<int>>(inv13) << 32) % MOD3;
  constexpr int i23_redc = (static_cast<safe_mul_t<int>>(inv23) << 32) % MOD3;
  constexpr int co1 = (-static_cast<uint32_t>(MOD)) % MOD;
  constexpr int co2 = (static_cast<safe_mul_t<int>>(co1) * MOD1) % MOD;
  constexpr int co3 = (static_cast<safe_mul_t<int>>(co2) * MOD2) % MOD;
  constexpr int m2inv = fft::minv<MOD2>;
  constexpr int m3inv = fft::minv<MOD3>;
  constexpr int minv = fft::minv<MOD>;
  const __m256i reg_i12 = _mm256_set1_epi32(i12_redc);
  const __m256i reg_i13 = _mm256_set1_epi32(i13_redc);
  const __m256i reg_i23 = _mm256_set1_epi32(i23_redc);
  const __m256i reg_co1 = _mm256_set1_epi32(co1);
  const __m256i reg_co2 = _mm256_set1_epi32(co2);
  const __m256i reg_co3 = _mm256_set1_epi32(co3);
  const __m256i reg_m2 = _mm256_set1_epi32(MOD2);
  const __m256i reg_m3 = _mm256_set1_epi32(MOD3);
  const __m256i reg_m = _mm256_set1_epi32(MOD);
  const __m256i reg_m2inv = _mm256_set1_epi32(m2inv);
  const __m256i reg_m3inv = _mm256_set1_epi32(m3inv);
  const __m256i reg_minv = _mm256_set1_epi32(minv);
  c1 = std::assume_aligned<32>(c1);
  c2 = std::assume_aligned<32>(c2);
  c3 = std::assume_aligned<32>(c3);
  for (int i = 0; i < n; i += 16) {
    __m256i x1 = _mm256_load_si256((__m256i *)&c1[i]);
    __m256i y1 = _mm256_load_si256((__m256i *)&c1[i + 8]);
    __m256i x2 = _mm256_load_si256((__m256i *)&c2[i]);
    __m256i y2 = _mm256_load_si256((__m256i *)&c2[i + 8]);
    __m256i x3 = _mm256_load_si256((__m256i *)&c3[i]);
    __m256i y3 = _mm256_load_si256((__m256i *)&c3[i + 8]);
    x2 = _mm256_mulmod2_epu32(_mm256_submod2_epu32(x2, x1, reg_m2), reg_i12, reg_m2, reg_m2inv);
    y2 = _mm256_mulmod2_epu32(_mm256_submod2_epu32(y2, y1, reg_m2), reg_i12, reg_m2, reg_m2inv);
    __m256i tmp1 = _mm256_mulmod2_epu32(_mm256_submod2_epu32(x3, x1, reg_m3), reg_i13, reg_m3, reg_m3inv);
    __m256i tmp2 = _mm256_mulmod2_epu32(_mm256_submod2_epu32(y3, y1, reg_m3), reg_i13, reg_m3, reg_m3inv);
    x3 = _mm256_mulmod2_epu32(_mm256_submod2_epu32(tmp1, x2, reg_m3), reg_i23, reg_m3, reg_m3inv);
    y3 = _mm256_mulmod2_epu32(_mm256_submod2_epu32(tmp2, y2, reg_m3), reg_i23, reg_m3, reg_m3inv);
    x1 = _mm256_mulmod2_epu32(x1, reg_co1, reg_m, reg_minv);
    y1 = _mm256_mulmod2_epu32(y1, reg_co1, reg_m, reg_minv);
    x2 = _mm256_mulmod2_epu32(x2, reg_co2, reg_m, reg_minv);
    y2 = _mm256_mulmod2_epu32(y2, reg_co2, reg_m, reg_minv);
    x3 = _mm256_mulmod2_epu32(x3, reg_co3, reg_m, reg_minv);
    y3 = _mm256_mulmod2_epu32(y3, reg_co3, reg_m, reg_minv);
    x2 = _mm256_addmod2_epu32(x1, x2, reg_m);
    y2 = _mm256_addmod2_epu32(y1, y2, reg_m);
    x3 = _mm256_addmod2_epu32(x2, x3, reg_m);
    y3 = _mm256_addmod2_epu32(y2, y3, reg_m);
    _mm256_storeu_si256((__m256i *)&out[i], x3);
    _mm256_storeu_si256((__m256i *)&out[i + 8], y3);
    _mm256_store_si256((__m256i *)&c1[i], _mm256_setzero_si256());
    _mm256_store_si256((__m256i *)&c2[i], _mm256_setzero_si256());
    _mm256_store_si256((__m256i *)&c3[i], _mm256_setzero_si256());
    _mm256_store_si256((__m256i *)&c1[i + 8], _mm256_setzero_si256());
    _mm256_store_si256((__m256i *)&c2[i + 8], _mm256_setzero_si256());
    _mm256_store_si256((__m256i *)&c3[i + 8], _mm256_setzero_si256());
  }
}
}
template <int MOD, size_t MAXN>
struct poly {
public:
  using mint_type = modint<MOD>;
  poly() = default;
  explicit poly(int n) : c_(n + 1) { c_[n] = 1; }
  poly(const std::vector<int> &vec) : c_(vec.begin(), vec.end()) {
    drop_zeros();
  }
  poly(const std::vector<mint_type> &vec) : c_(vec) { drop_zeros(); }
  poly(std::vector<mint_type> &&vec) noexcept : c_(std::move(vec)) {
    drop_zeros();
  }
  poly(std::initializer_list<int> lst) : c_(lst.begin(), lst.end()) {
    drop_zeros();
  }
  poly(std::initializer_list<mint_type> lst) : c_(lst) { drop_zeros(); }
  poly &
  operator+=(const poly &rhs) {
    if (size() < rhs.size()) { resize(rhs.size()); }
    for (int i = 0; i < rhs.size(); ++i) { c_[i] += rhs.c_[i]; }
    drop_zeros();
    return *this;
  }
  poly &
  operator+=(mint_type x) {
    if (detail::unlikely(size() == 0)) { c_.emplace_back(0); }
    c_[0] += x;
    drop_zeros();
    return *this;
  }
  poly &
  operator-=(const poly &rhs) {
    if (size() < rhs.size()) { resize(rhs.size()); }
    for (int i = 0; i < rhs.size(); ++i) { c_[i] -= rhs.c_[i]; }
    drop_zeros();
    return *this;
  }
  poly &
  operator-=(mint_type x) {
    if (detail::unlikely(size() == 0)) { c_.emplace_back(0); }
    c_[0] -= x;
    drop_zeros();
    return *this;
  }
  poly &
  operator*=(const poly &rhs) noexcept {
    const int m = std::min(size(), rhs.size());
    *this = is_large(m) ? mul_fast(rhs) : mul_slow(rhs);
    return *this;
  }
  poly &
  operator*=(mint_type x) {
    for (int i = 0; i < size(); ++i) { c_[i] *= x; }
    drop_zeros();
    return *this;
  }
  poly &
  operator/=(const poly &rhs) noexcept {
    const int m = deg() - rhs.deg() + 1;
    *this = is_large(m) ? div_fast(rhs) : div_slow(rhs);
    return *this;
  }
  poly &
  operator%=(const poly &rhs) noexcept {
    poly D = *this / rhs;
    *this -= D * rhs;
    return *this;
  }
  poly
  operator-() const {
    poly res(*this);
    std::transform(res.c_.begin(), res.c_.end(), res.c_.begin(),
                   [](auto x) { return -x; });
    return res;
  }
  poly
  operator+(const poly &rhs) const {
    return poly(*this) += rhs;
  }
  poly
  operator-(const poly &rhs) const {
    return poly(*this) -= rhs;
  }
  poly
  operator*(const poly &rhs) const {
    return poly(*this) *= rhs;
  }
  poly
  operator/(const poly &rhs) const {
    return poly(*this) /= rhs;
  }
  poly
  operator%(const poly &rhs) const {
    return poly(*this) %= rhs;
  }
  friend poly
  operator+(poly lhs, mint_type rhs) {
    return lhs += rhs;
  }
  friend poly
  operator+(mint_type lhs, const poly &rhs) {
    return poly(rhs) += lhs;
  }
  friend poly
  operator-(poly lhs, mint_type rhs) {
    return lhs -= rhs;
  }
  friend poly
  operator-(mint_type lhs, const poly &rhs) {
    return poly({lhs}) -= rhs;
  }
  friend poly
  operator*(poly lhs, mint_type rhs) {
    return lhs *= rhs;
  }
  friend poly
  operator*(mint_type lhs, const poly &rhs) {
    return poly(rhs) *= lhs;
  }
  mint_type
  operator[](int i) const {
    return i < size() ? c_[i] : 0;
  }
  mint_type
  operator()(mint_type x) const {
    mint_type ans = 0;
    for (int i = size() - 1; i >= 0; --i) {
      ans *= x;
      ans += c_[i];
    }
    return ans;
  }
  poly
  mul_xk(int k) const noexcept {
    detail::assume(k >= 0);
    std::vector<mint_type> out(k + size());
    std::copy(c_.begin(), c_.end(), out.begin() + k);
    return out;
  }
  poly
  mod_xk(int k) const noexcept {
    detail::assume(k >= 0);
    return std::vector(c_.begin(), c_.begin() + std::min(k, size()));
  }
  poly
  div_xk(int k) const noexcept {
    detail::assume(k >= 0);
    return std::vector(c_.begin() + std::min(k, size()), c_.end());
  }
  poly
  rev(int n) const noexcept {
    std::vector res(this->c_);
    res.resize(std::max(size(), n + 1));
    std::reverse(res.begin(), res.end());
    return res;
  }
  poly
  inv(int n) const {
    int a = 1;
    poly ans = {c_[0].inv()};
    while (a < n) {
      poly D = (ans * mod_xk(a << 1)).mod_xk(a << 1).div_xk(a);
      ans -= (ans * D).mod_xk(a).mul_xk(a);
      a <<= 1;
    }
    return ans.mod_xk(n);
  }
  mint_type
  lead() const {
    return c_.back();
  }
  std::vector<mint_type>
  to_vector() const {
    return c_;
  }
  int
  deg() const {
    return size() - 1;
  }
  int
  size() const {
    return std::ssize(c_);
  }
  friend std::ostream &
  operator<<(std::ostream &os, const poly &p) {
    for (int i = 0; i < p.size(); ++i) {
      if (i) os << ' ';
      os << p.c_[i];
    }
    if (p.size() == 0) { os << 0; }
    return os;
  }
  bool
  is_zero() const {
    return c_.empty();
  }
private:
  void
  drop_zeros() noexcept {
    while (!c_.empty() && c_.back() == 0) { c_.pop_back(); }
  }
  void
  resize(int n) noexcept {
    c_.resize(n);
  }
  bool
  is_large(int n) const {
    return n >= 256;
  }
  poly
  mul_slow(const poly &rhs) const noexcept {
    if (detail::unlikely(is_zero() || rhs.is_zero())) { return poly{}; }
    const int n1 = size();
    const int n2 = rhs.size();
    const int n = n1 + n2 - 1;
    std::vector<mint_type> out(n);
    for (int i = 0; i < n1; ++i) {
      for (int j = 0; j < n2; ++j) { out[i + j] += c_[i] * rhs.c_[j]; }
    }
    return out;
  }
  poly
  mul_fast(const poly &rhs) const noexcept {
    constexpr int MOD1 = 167772161;
    constexpr int MOD2 = 469762049;
    constexpr int MOD3 = 754974721;
    const int n1 = size();
    const int n2 = rhs.size();
    const int n = detail::bit_ceil(n1 + n2 - 1);
    {
      std::copy_n((int *)c_.data(), n1, buf1_);
      std::copy_n((int *)rhs.c_.data(), n2, buf4_);
      detail::convolution<MOD1>(buf1_, buf4_, n);
    }
    {
      std::copy_n((int *)c_.data(), n1, buf2_);
      std::copy_n((int *)rhs.c_.data(), n2, buf4_);
      detail::convolution<MOD2>(buf2_, buf4_, n);
    }
    {
      std::copy_n((int *)c_.data(), n1, buf3_);
      std::copy_n((int *)rhs.c_.data(), n2, buf4_);
      detail::convolution<MOD3>(buf3_, buf4_, n);
    }
    std::vector<mint_type> out(n);
    detail::consolidate<MOD>(buf1_, buf2_, buf3_, (int *)out.data(), n);
    return out;
  }
  poly
  div_slow(const poly &rhs) const noexcept {
    const int d1 = deg(), d2 = rhs.deg(), m = d1 - d2 + 1;
    if (d1 < d2) { return poly{}; }
    std::copy_n((int *)c_.data() + d2, m, buf4_);
    std::vector<mint_type> out(m);
    const mint_type x = rhs.c_.back().inv();
    for (int i = m - 1; i >= 0; --i) {
      out[i] = mint_type::from(buf4_[i]);
      if (buf4_[i] != 0) {
        out[i] *= x;
        const int q = std::min(i - d2, 0);
        for (int j = d2; j >= q; --j) {
          buf4_[i + j - d2] -= (out[i] * rhs.c_[j]).val();
          buf4_[i + j - d2] += (buf4_[i + j - d2] >> 31) & MOD;
        }
      }
    }
    return out;
  }
  poly
  div_fast(const poly &rhs) const noexcept {
    const int d1 = deg(), d2 = rhs.deg(), m = d1 - d2 + 1;
    return rev(d1).mod_xk(m).operator*=(rhs.rev(d2).inv(m)).mod_xk(m).rev(m - 1);
  }
  std::vector<mint_type> c_;
  alignas(32) static inline int buf1_[MAXN];
  alignas(32) static inline int buf2_[MAXN];
  alignas(32) static inline int buf3_[MAXN];
  alignas(32) static inline int buf4_[MAXN];
};
}
namespace algo {}
#pragma region alias
using std::array;
using std::vector;
using std::span;
using std::bitset;
using std::stack;
using std::queue;
using std::deque;
using std::set;
using std::map;
using std::multimap;
using std::multiset;
using std::complex;
using std::string;
using std::string_view;
using std::stringstream;
using std::pair;
using std::tuple;
using std::cin;
using std::cout;
using std::endl;
using std::gcd;
using std::lcm;
using std::max;
using std::min;
using std::swap;
using std::to_string;
namespace ranges = std::ranges;
namespace views = std::views;
template <typename Tp, typename Fn>
using ordered_set = __gnu_pbds::tree<Tp,
__gnu_pbds::null_type, Fn, __gnu_pbds::rb_tree_tag,
__gnu_pbds::tree_order_statistics_node_update>;
using uint = unsigned int;
using wint = int64_t;
template <typename KeyType, typename ValueType>
using umap = std::unordered_map<KeyType, ValueType>;
template <typename ValueType> using uset = std::unordered_set<ValueType>;
template <typename Tp, typename Fn = std::less<Tp>>
using max_heap = std::priority_queue<Tp, std::vector<Tp>, Fn>;
template <typename Tp, typename Fn = std::greater<Tp>>
using min_heap = std::priority_queue<Tp, std::vector<Tp>, Fn>;
#pragma endregion alias
#define INF 0x3f3f3f3f
#define MOD 998244353
#define MAXN 100001
#define MULTI 0
inline void solve() noexcept {
  vector mu=algo::mobius_n(MAXN);
  int n,m;cin>>n>>m;
  using node=struct{
    int l,r;
  };
  using mint=algo::modint<MOD>;
  vector<node>vals(n);
  for(int i=0;i<n;++i){
    cin>>vals[i].l>>vals[i].r;
  }
  auto calc=[&](int d){
    const int nm=m/d;
    vector<vector<mint>>dp(n+1,vector<mint>(nm+1));
    fill(dp[0].begin(),dp[0].end(),mint(1));
    for(int i=1;i<=n;++i){
      int l=(vals[i-1].l+d-1)/d,r=vals[i-1].r/d;
      for(int j=1;j<=nm;++j){
        dp[i][j]=dp[i][j-1];
        if(j>=l){
          dp[i][j]+=dp[i-1][j-l];
        }
        if(j>r){
          dp[i][j]-=dp[i-1][j-r-1];
        }
      }
    }
    return dp[n][nm];
  };
  mint ans=0;
  for(int d=1;d<=m;++d){
    ans+=mu[d]*calc(d);
  }
  cout<<ans<<'\n';
}
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cout.precision(15);
  solve();
  return 0;
}
