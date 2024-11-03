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
    using type = typename std::tuple_element<I, std::tuple<Args...>>::type;
  };
};
template <typename ReturnType, typename... Args>
struct function_traits<ReturnType (*)(Args...)> {
  static constexpr size_t arity = sizeof...(Args);
  using result_type = ReturnType;
  template <size_t I>
  struct arg {
    using type = typename std::tuple_element<I, std::tuple<Args...>>::type;
  };
};
template <typename ReturnType, typename... Args>
struct function_traits<ReturnType(Args...)> {
  static constexpr size_t arity = sizeof...(Args);
  using result_type = ReturnType;
  template <size_t I>
  struct arg {
    using type = typename std::tuple_element<I, std::tuple<Args...>>::type;
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
  std::vector<int> out(ssize(perm));
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
  if (a0 < 0) { x0 = -x0, a0 = -a0; }
  return std::make_pair(x0, a0);
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
namespace detail {
template <integer T1, integer T2>
constexpr std::common_type_t<T1, T2>
inv_mod(T1 a, T2 m) {
  auto r = euclidean_extended(a, m);
  auto x = r.first % m;
  if (x < 0) x += m;
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
  constexpr modint(Tp x) : _value(static_cast<int>(x % MOD)) {
    _value += (_value >> 31) & MOD;
  }
  constexpr modint &
  operator+=(const modint &rhs) {
    _value += rhs.val() - MOD;
    _value += (_value >> 31) & MOD;
    return *this;
  }
  constexpr modint &
  operator-=(const modint &rhs) {
    _value -= rhs.val();
    _value += (_value >> 31) & MOD;
    return *this;
  }
  constexpr modint &
  operator*=(const modint &rhs) {
    detail::assume(val() >= 0 && val() < MOD);
    detail::assume(rhs.val() >= 0 && rhs.val() < MOD);
    _value = static_cast<detail::safe_mul_t<int>>(val()) * rhs.val() % MOD;
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
    return _value;
  }
  constexpr int
  mod() const {
    return MOD;
  }
  constexpr modint
  inv() const {
    if constexpr (IsPrime) {
      constexpr int ph = MOD - 2;
      constexpr int bw = detail::bit_width(ph);
      modint res(1), mul(*this);
      for (int i = 0; i < bw; ++i) {
        if ((ph >> i) & 0x01) { res *= mul; }
        mul *= mul;
      }
      return res;
    } else {
      int res = detail::inv_mod(val(), MOD);
      detail::assume(0 <= res && res < MOD);
      return modint(res);
    }
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
  int _value = {0};
};
}
namespace algo {
template <int MOD, int Num>
struct factorial {
  using mint_type = modint<MOD>;
  constexpr factorial() : _fac(), _inv() {
    _fac[0] = 1;
    for (int i = 1; i <= Num; ++i) { _fac[i] = _fac[i - 1] * i; }
    _inv[Num] = _fac[Num].inv();
    for (int i = Num; i >= 1; --i) { _inv[i - 1] = _inv[i] * i; }
  }
  constexpr const mint_type&
  operator[](int i) const {
    return _fac[i];
  }
  constexpr mint_type
  operator()(int i) const {
    return _fac[i];
  }
  constexpr mint_type
  comb(int n, int r) const {
    return _fac[n] * _inv[n - r] * _inv[r];
  }
  constexpr mint_type
  perm(int n, int r) {
    return _fac[n] * _inv[n - r];
  }
private:
  std::array<mint_type, Num + 1> _fac, _inv;
};
}
namespace algo {
  template struct modint<998244353>;
  template struct modint<1000000007>;
}
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
static const algo::factorial<MOD,MAXN+MAXN-2>fac{};
inline void solve() noexcept {
  int n;cin>>n;
  int cw=0,cb=0,m=0,alx=true,aly=true,bb=false,ww=false;
  char buf[3];
  for(int i=0;i<n;++i){
    cin>>buf;
    cw+=(buf[0]=='W');
    cb+=(buf[0]=='B');
    cw+=(buf[1]=='W');
    cb+=(buf[1]=='B');
    m+=(buf[0]=='?'&&buf[1]=='?');
    alx&=(buf[0]!='B'&&buf[1]!='W');
    aly&=(buf[0]!='W'&&buf[1]!='B');
    bb|=(buf[0]=='W'&&buf[1]=='W');
    ww|=(buf[0]=='B'&&buf[1]=='B');
  }
  algo::modint<MOD>ans=0;
  if(cb<=n&&cw<=n){
    int w=2*n-cw-cb;
    ans+=fac.comb(w,n-cw);
    if(!bb&&!ww){
      algo::modint<MOD>e=(2);
      ans-=e.pow(m);
      ans+=alx+aly;
    }
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
