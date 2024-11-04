#pragma GCC target("abm,movbe,bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("f16c,fma,avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("inline")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("omit-frame-pointer")
#pragma GCC optimize("stack-check=no")
#define NDEBUG 1
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
concept signed_integer = integer<Tp> &&(Tp(-1) < Tp(0));
template <typename Tp>
concept unsigned_integer = integer<Tp> &&(Tp(-1) > Tp(0));
template <typename Tp>
concept addable = requires(std::remove_reference_t<Tp> &a,
                           const std::remove_reference_t<Tp> &b) {
  { a += b } -> std::same_as<std::remove_reference_t<Tp> &>;
};
template <typename Tp>
concept multipliable = requires(std::remove_reference_t<Tp> &a,
                                const std::remove_reference_t<Tp> &b) {
  { a *= b } -> std::same_as<std::remove_reference_t<Tp> &>;
};
template <typename Function, typename ReturnType, typename... Args>
concept callable = std::invocable<Function, Args...> &&
    std::same_as<std::invoke_result_t<Function, Args...>, ReturnType>;
template <typename Function, typename Arg>
concept unary_op = callable<Function, Arg, Arg>;
template <typename Function, typename Arg>
concept binary_op = callable<Function, Arg, Arg, Arg>;
template <typename Tp>
concept less_than_comparable = requires(const std::remove_reference_t<Tp> &a,
                                        const std::remove_reference_t<Tp> &b) {
  { a < b } -> std::convertible_to<bool>;
  { !(a < b) } -> std::convertible_to<bool>;
};
template <typename Tp>
concept equality_comparable = std::equality_comparable<Tp>;
template <typename From, typename To>
concept constructible = std::constructible_from<To, From>;
template <typename InputIterator, typename ValueType>
concept input_iterator = std::input_iterator<InputIterator> &&
    std::same_as<std::iter_value_t<InputIterator>, ValueType>;
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
template <typename Function>
struct function_traits
    : public function_traits<
          decltype(&std::remove_reference_t<Function>::operator())> {};
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
template <integer Tp>
constexpr Tp
sqrt(Tp n) {
  if (n == 0) { return 0; }
  if (n == 1) { return 1; }
  Tp ans = 0;
  for (int i = log2_floor(n) - 1; i >= 0; --i) {
    const Tp tmp = (n - ans * ans) >> i;
    if ((ans << 1) + (Tp(1) << i) <= tmp) { ans |= Tp(1) << i; }
  }
  return ans;
}
template <integer Tp>
constexpr Tp
abs(Tp n) {
  if constexpr (std::is_signed_v<Tp>) {
    return n < 0 ? -n : n;
  } else {
    return n;
  }
}
template <integer Tp>
constexpr Tp
div_ceil(Tp x, Tp y) {
  if constexpr (std::is_unsigned_v<Tp>) {
    return x / y + (x % y != 0);
  } else {
    return x / y + (x % y != 0 && (x ^ y) >= 0);
  }
}
template <integer Tp>
constexpr std::make_signed_t<Tp>
pow_m1(Tp n) {
  return -(n & 1) | 1;
}
}
}
namespace algo {
namespace detail {
constexpr bool
likely(bool x) noexcept {
  return __builtin_expect(x, 1);
}
constexpr bool
unlikely(bool x) noexcept {
  return __builtin_expect(x, 0);
}
constexpr void
unreachable() noexcept {
  __builtin_unreachable();
}
constexpr void
assume(bool expr) noexcept {
  if (!expr) unreachable();
}
}
}
namespace algo {
class sieve {
public:
  sieve() = default;
  explicit sieve(int n) noexcept : n_(n), m_((n_ + 5) / 6), lp_(m_ << 1) {
    const int kmax = (detail::sqrt((6 * m_ + 1)) - 5) / 6 + 1;
    lp_[(0 << 1) + 0] = 1;
    for (int k = 0; k <= kmax; ++k) {
      if (lp_[(k << 1) + 0] == 0) {
        const int pm = 6 * k + 1;
        const int s0 = k * (6 * k + 2 * 1) + (1 * 1) / 6;
        const int s1 = s0 + 4 * k + 0;
        for (int s = s0; s < m_; s += pm) { lp_[(s << 1) + 0] = pm; }
        for (int s = s1; s < m_; s += pm) { lp_[(s << 1) + 1] = pm; }
      }
      if (lp_[(k << 1) + 1] == 0) {
        const int pm = 6 * k + 5;
        const int s0 = k * (6 * k + 2 * 5) + (5 * 5) / 6;
        const int s1 = s0 + 2 * k + 1;
        for (int s = s0; s < m_; s += pm) { lp_[(s << 1) + 0] = pm; }
        for (int s = s1; s < m_; s += pm) { lp_[(s << 1) + 1] = pm; }
      }
    }
  }
  std::vector<std::pair<int, int>>
  factorize(int n) const {
    assert(1 <= n && n <= size());
    detail::assume(1 <= n && n <= n_);
    std::vector<std::pair<int, int>> ans;
    ans.reserve(20);
    if (n % 2 == 0) {
      int c = 0;
      do { n /= 2, c++; } while (n % 2 == 0);
      ans.emplace_back(2, c);
    }
    if (n % 3 == 0) {
      int c = 0;
      do { n /= 3, c++; } while (n % 3 == 0);
      ans.emplace_back(3, c);
    }
    while (n > 1) {
      const int p = get_nontrivial_factor(n);
      int c = 0;
      do { n /= p, c++; } while (n % p == 0);
      ans.emplace_back(p, c);
    }
    return ans;
  }
  std::vector<int>
  divisors(int n) const {
    assert(1 <= n && n <= size());
    detail::assume(1 <= n && n <= n_);
    std::vector<int> ans{1};
    for (const auto& [p, c] : factorize(n)) {
      const int sz = std::ssize(ans);
      for (int i = 0; i < sz; ++i) {
        for (int j = 0, d = ans[i]; j < c; ++j) { ans.emplace_back(d *= p); }
      }
    }
    return ans;
  }
  int
  euler(int n) const {
    assert(1 <= n && n <= size());
    detail::assume(1 <= n && n <= n_);
    int ans = n;
    if (n % 2 == 0) {
      ans -= ans / 2;
      do { n /= 2; } while (n % 2 == 0);
    }
    if (n % 3 == 0) {
      ans -= ans / 3;
      do { n /= 3; } while (n % 3 == 0);
    }
    while (n > 1) {
      const int p = get_nontrivial_factor(n);
      ans -= ans / p;
      do { n /= p; } while (n % p == 0);
    }
    return ans;
  }
  int
  mobius(int n) const {
    assert(1 <= n && n <= size());
    detail::assume(1 <= n && n <= n_);
    bool parity = false;
    if (n % 2 == 0) {
      if ((n /= 2) % 2 == 0) { return 0; }
      parity ^= 1;
    }
    if (n % 3 == 0) {
      if ((n /= 3) % 3 == 0) { return 0; }
      parity ^= 1;
    }
    while (n > 1) {
      const int p = get_nontrivial_factor(n);
      if ((n /= p) % p == 0) { return 0; }
      parity ^= 1;
    }
    return -(parity & 1) | 1;
  }
  int
  size() const {
    return n_;
  }
private:
  int
  get_nontrivial_factor(int n) const {
    detail::assume(1 <= n && n <= n_);
    const int d = n / 6, r = n % 6;
    return lp_[(d << 1) + (r >> 2)] ? lp_[(d << 1) + (r >> 2)] : n;
  }
  int n_, m_;
  std::vector<int> lp_;
};
}
namespace algo {
namespace detail {
template <integer Tp>
constexpr Tp
assumed_mulmod(Tp x, Tp y, Tp m) {
  assume(0 <= x && x < m);
  assume(0 <= y && y < m);
  return static_cast<safe_mul_t<std::make_unsigned_t<Tp>>>(x) * y % m;
}
template <multipliable Tp, integer Up>
constexpr Tp
binpow(const Tp &a, Up b) {
  Tp res(1), mul = a;
  std::make_unsigned_t<Up> pw = b;
  while (pw) {
    if (pw & 0x01) { res *= mul; }
    mul *= mul;
    pw >>= 1;
  }
  return res;
}
template <multipliable T1, constructible<T1> T2, integer Up>
constexpr T1
binpow(const T1 &a, Up b, const T2 &init) {
  T1 res(init), mul = a;
  std::make_unsigned_t<Up> pw = b;
  while (pw) {
    if (pw & 0x01) { res *= mul; }
    mul *= mul;
    pw >>= 1;
  }
  return res;
}
template <integer Tp>
constexpr Tp
euler_phi(Tp n) {
  typedef safe_mul_t<Tp> wide_t;
  assume(1 <= n);
  Tp cur_n = n, ans = n;
  if (cur_n % 2 == 0) {
    ans -= ans / 2;
    do { cur_n /= 2; } while (cur_n % 2 == 0);
  }
  if (cur_n % 3 == 0) {
    ans -= ans / 3;
    do { cur_n /= 3; } while (cur_n % 3 == 0);
  }
  for (Tp i = 5, c = 2; i * static_cast<wide_t>(i) <= cur_n; i += c, c ^= 6) {
    if (cur_n % i == 0) {
      ans -= ans / i;
      do { cur_n /= i; } while (cur_n % i == 0);
    }
  }
  if (cur_n > 1) { ans -= ans / cur_n; }
  return ans;
}
template <integer Tp>
constexpr std::make_signed_t<Tp>
mobius(Tp n) {
  typedef safe_mul_t<Tp> wide_t;
  assume(1 <= n);
  Tp cur_n = n;
  int cnt = 0;
  if (cur_n == 1) { return 1; }
  if (cur_n % 2 == 0) {
    if ((cur_n /= 2) % 2 == 0) { return 0; }
    cnt = cnt + 1;
  }
  if (cur_n % 3 == 0) {
    if ((cur_n /= 3) % 3 == 0) { return 0; }
    cnt = cnt + 1;
  }
  for (Tp i = 5, c = 2; i * static_cast<wide_t>(i) <= cur_n; i += c, c ^= 6) {
    if (cur_n % i == 0) {
      if ((cur_n /= i) % i == 0) { return 0; }
      cnt = cnt + 1;
    }
  }
  if (cur_n > 1) { cnt = cnt + 1; }
  return pow_m1(cnt);
}
template <signed_integer Tp>
constexpr std::pair<Tp, Tp>
euclidean_extended(Tp a, Tp b) {
  Tp x0 = 1, y0 = 0, x1 = 0, y1 = 1, a0 = a, b0 = b;
  while (b0) {
    Tp q = a0 / b0, tp = x0;
    x0 = x1, x1 = tp - q * x1, tp = y0, y0 = y1, y1 = tp - q * y1, tp = a0,
    a0 = b0, b0 = tp - q * b0;
  }
  if (a0 < 0) { x0 = -x0, a0 = -a0; }
  return std::make_pair(x0, a0);
}
template <integer Tp, integer Up>
constexpr Tp
binpow_mod(Tp a, Up b, Tp m) {
  Tp ans = 1, mul = a;
  const Tp mod = m;
  std::make_unsigned_t<Up> pw = b;
  if ((mul %= mod) < 0) mul += mod;
  while (pw) {
    if (pw & 0x01) { ans = assumed_mulmod(ans, mul, mod); }
    mul = assumed_mulmod(mul, mul, mod);
    pw >>= 1;
  }
  return ans;
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
  for (const Tp p : primes) {
    Tp x = binpow_mod(p, d, n);
    bool good = x == n - 1 || x == 1;
    for (int r = 1; r < s; ++r) {
      x = assumed_mulmod(x, x, n);
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
  for (const Tp p : primes) {
    Tp x = binpow_mod(p, d, n);
    bool good = x == n - 1 || x == 1;
    for (int r = 1; r < s; ++r) {
      x = assumed_mulmod(x, x, n);
      good |= x == n - 1;
    }
    if (!good) { return false; }
  }
  return true;
}
template <integer Tp>
std::vector<std::tuple<Tp, Tp, Tp>>
quotients(Tp n) {
  std::vector<std::tuple<Tp, Tp, Tp>> ans{};
  for (Tp i = 1, j = 1; i <= n; i = j + 1) {
    const Tp q = n / i;
    j = n / q;
    ans.emplace_back(i, j, q);
  }
  return ans;
}
template <integer Tp>
std::vector<Tp>
euler_phi_n(Tp n) noexcept {
  assume(1 <= n);
  std::vector<Tp> phi(n + 1);
  iota(phi.begin(), phi.end(), 0);
  for (Tp i = 2; i <= n; i += 2) { phi[i] -= phi[i] / 2; }
  for (Tp i = 3; i <= n; i += 3) { phi[i] -= phi[i] / 3; }
  for (Tp i = 5, c = 2; i <= n; i += c, c ^= 6) {
    if (phi[i] == i) {
      for (Tp j = i; j <= n; j += i) { phi[j] -= phi[j] / i; }
    }
  }
  return phi;
}
template <integer Tp>
std::vector<std::make_signed_t<Tp>>
mobius_n(Tp n) noexcept {
  typedef std::make_signed_t<Tp> value_t;
  typedef safe_mul_t<Tp> wide_t;
  assume(1 <= n);
  std::vector<value_t> mu(n + 1, -1);
  std::vector<Tp> lp(n + 1, 0);
  std::vector<Tp> ps;
  ps.reserve(n >> log2_floor(n));
  mu[1] = 1;
  for (Tp i = 2; i <= n; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      ps.emplace_back(i);
    }
    for (const Tp p : ps | std::views::take_while([&](Tp p) {
                        return p <= lp[i] && p * static_cast<wide_t>(i) <= n;
                      })) {
      lp[i * p] = p;
      mu[i * p] = -mu[i] * (p != lp[i]);
    }
  }
  return mu;
}
}
}
namespace algo {
template <uint32_t MOD>
class modint {
  static constexpr bool is_prime = detail::prime_test(MOD);
public:
  constexpr modint() = default;
  template <detail::integer Tp>
  constexpr modint(Tp x) : value_(safe_mod(x)) {}
  constexpr modint &
  operator+=(const modint &rhs) {
    value_ += rhs.val() - MOD;
    if ((value_ & 0x80000000) != 0) { value_ += MOD; }
    return *this;
  }
  constexpr modint &
  operator-=(const modint &rhs) {
    value_ -= rhs.val();
    if ((value_ & 0x80000000) != 0) { value_ += MOD; }
    return *this;
  }
  constexpr modint &
  operator*=(const modint &rhs) {
    typedef detail::safe_mul_t<uint32_t> wide_t;
    detail::assume(0 <= val() && val() < MOD);
    detail::assume(0 <= rhs.val() && rhs.val() < MOD);
    value_ = static_cast<wide_t>(val()) * rhs.val() % MOD;
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
    const modint res(*this);
    operator++();
    return res;
  }
  constexpr modint
  operator--(int) {
    const modint res(*this);
    operator--();
    return res;
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
  constexpr uint32_t
  val() const {
    return value_;
  }
  constexpr static uint32_t
  mod() {
    return MOD;
  }
  constexpr modint
  inv() const requires(is_prime) {
    assert(val() != 0);
    return pow(MOD - 2);
  }
  constexpr modint
  inv() const requires(!is_prime) {
    const auto [res, g] = detail::euclidean_extended<int32_t>(val(), MOD);
    assert(g == 1);
    return modint(res);
  }
  template <detail::integer Tp>
  constexpr modint
  pow(Tp x) const {
    assert(x >= 0);
    modint res(1), mul(*this);
    while (x > 0) {
      if (x & 0x01) { res *= mul; }
      mul *= mul, x >>= 1;
    }
    return res;
  }
  constexpr modint
  fact() const {
    modint res(1);
    for (uint32_t i = 2; i <= val(); ++i) { res *= from(i); }
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
    assert(0 <= x && x < MOD);
    return std::bit_cast<modint>(static_cast<uint32_t>(x));
  }
private:
  template <detail::integer Tp>
  constexpr static uint32_t
  safe_mod(Tp x) {
    if constexpr (std::is_signed_v<Tp>) {
      x %= static_cast<int32_t>(MOD);
      if (x < 0) { x += MOD; }
    } else {
      x %= MOD;
    }
    return static_cast<uint32_t>(x);
  }
  uint32_t value_{0};
};
}
namespace algo {
template <typename Function>
struct rec_lambda {
  constexpr rec_lambda(const Function &f) : f_(f) {}
  template <typename... Args>
  constexpr decltype(auto)
  operator()(Args &&... args) const {
    return f_(*this, std::forward<Args>(args)...);
  }
private:
  Function f_;
};
constexpr bool
likely(bool x) {
  return detail::likely(x);
}
constexpr bool
unlikely(bool x) {
  return detail::unlikely(x);
}
constexpr void
assume(bool x) {
  detail::assume(x);
}
constexpr void
unreachable() {
  detail::unreachable();
}
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
using std::move;
using std::to_string;
namespace ranges = std::ranges;
namespace views = std::views;
template <typename Tp, typename Function>
using ordered_set = __gnu_pbds::tree<Tp,
__gnu_pbds::null_type, Function, __gnu_pbds::rb_tree_tag,
__gnu_pbds::tree_order_statistics_node_update>;
using uint = unsigned int;
using wint = int64_t;
template <typename KeyType, typename ValueType>
using umap = std::unordered_map<KeyType, ValueType>;
template <typename ValueType> using uset = std::unordered_set<ValueType>;
template <typename Tp, typename Function = std::less<Tp>>
using max_heap = std::priority_queue<Tp, std::vector<Tp>, Function>;
template <typename Tp, typename Function = std::greater<Tp>>
using min_heap = std::priority_queue<Tp, std::vector<Tp>, Function>;
#pragma endregion alias
#define INF 0x3f3f3f3f
#define MOD 998244353
#define MAXN 200001
#define MULTI 1
namespace {
const algo::sieve sv(MAXN-1);
vector<int>pf(MAXN),a0(MAXN);
using mint=algo::modint<MOD>;
}
void solve() noexcept {
  int n;cin>>n;
  typedef struct{
    int a,b,to;
  }edge;
  vector<vector<edge>>adj(n);
  for(int i=0;i<n-1;++i){
    int a,b,x,y;cin>>a>>b>>x>>y;
    a--,b--;
    adj[a].emplace_back(x,y,b);
    adj[b].emplace_back(y,x,a);
  }
  vector<mint>num(n);
  set<int>primes;
  num[0]=1;
  algo::rec_lambda([&](auto dfs,int u,int p)->void{
    for(auto&&[x,y,v]:adj[u]){
      if(v!=p){
        num[v]=num[u]*y/x;
        auto fx=sv.factorize(x),fy=sv.factorize(y);
        for(auto&&[f,c]:fy){
          pf[f]+=c;
          primes.insert(f);
        }
        for(auto&&[f,c]:fx){
          pf[f]-=c;
          a0[f]=max(a0[f],-pf[f]);
          primes.insert(f);
        }
        dfs(v,u);
        for(auto&&[f,c]:fx){
          pf[f]+=c;
        }
        for(auto&&[f,c]:fy){
          pf[f]-=c;
        }
      }
    }
  })(0,0);
  mint base=1;
  for(auto&&p:primes){
    base*=mint::from(p).pow(a0[p]);
    pf[p]=a0[p]=0;
  }
  mint ans=0;
  for(int i=0;i<n;++i){
    ans+=base*num[i];
  }
  cout<<ans<<'\n';
}
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cout.precision(15);
  int tc;
  std::cin >> tc;
  while (tc--) { solve(); }
  return 0;
}
