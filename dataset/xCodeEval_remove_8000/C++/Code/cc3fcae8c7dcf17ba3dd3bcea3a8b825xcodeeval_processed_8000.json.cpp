














































namespace algo::detail {
struct modnum_base {};
struct monostate {};
template <typename Tp>
concept integer = std::integral<Tp> && !(std::same_as<Tp, bool>);
template <typename Tp>
concept signed_integer = integer<Tp> && (Tp(-1) < Tp(0));
template <typename Tp>
concept unsigned_integer = integer<Tp> && (Tp(-1) > Tp(0));
template <typename Tp>
concept modular_integer = std::is_base_of_v<modnum_base, Tp>;
template <typename From, typename To>
concept sign_compatible_with =
    integer<From> && ((std::is_signed_v<From> && std::is_signed_v<To>) ||
                      (std::is_unsigned_v<From> && std::is_unsigned_v<To>));
template <typename Tp>
concept arithmetic = integer<Tp> || (std::is_floating_point_v<Tp>);
template <typename Tp>
concept qword_fittable = sizeof(Tp) <= 8UL;
template <typename Tp>
concept dword_fittable = qword_fittable<Tp> && sizeof(Tp) <= 4UL;
template <typename Tp>
concept word_fittable = dword_fittable<Tp> && sizeof(Tp) <= 2UL;
template <typename Tp>
concept byte_fittable = word_fittable<Tp> && sizeof(Tp) == 1UL;
template <typename Tp>
struct imul_result;
template <qword_fittable Tp>
  requires std::signed_integral<Tp>
struct imul_result<Tp> {
  using type = __int128_t;
};
template <qword_fittable Tp>
  requires std::unsigned_integral<Tp>
struct imul_result<Tp> {
  using type = __uint128_t;
};
template <dword_fittable Tp>
  requires std::signed_integral<Tp>
struct imul_result<Tp> {
  using type = int64_t;
};
template <dword_fittable Tp>
  requires std::unsigned_integral<Tp>
struct imul_result<Tp> {
  using type = uint64_t;
};
template <word_fittable Tp>
  requires std::signed_integral<Tp>
struct imul_result<Tp> {
  using type = int32_t;
};
template <word_fittable Tp>
  requires std::unsigned_integral<Tp>
struct imul_result<Tp> {
  using type = uint32_t;
};
template <byte_fittable Tp>
  requires std::signed_integral<Tp>
struct imul_result<Tp> {
  using type = int16_t;
};
template <byte_fittable Tp>
  requires std::unsigned_integral<Tp>
struct imul_result<Tp> {
  using type = uint16_t;
};
template <typename Tp>
using imul_result_t = typename imul_result<Tp>::type;
template <typename Sig>
struct function_traits;
template <typename Ret, typename... Args>
struct function_traits<Ret(Args...)> {
  using return_type = Ret;
  template <typename Fn>
  static constexpr bool same_as =
      std::is_invocable_r_v<return_type, Fn, Args...>;
};
template <typename Fn, typename Sig>
concept function = (function_traits<Sig>::template same_as<Fn>);
template <typename IIter, typename Value>
concept input_iterator = std::same_as<std::iter_value_t<IIter>, Value>;
template <typename OIter, typename Value>
concept output_iterator = std::output_iterator<OIter, Value>;
}
namespace algo::detail {
inline void unreachable [[gnu::noreturn]] () { __builtin_unreachable(); }
constexpr void assume [[gnu::always_inline]] (bool expr) {
  if (!expr) { __builtin_unreachable(); }
}
}
namespace algo::detail {
template <typename Tp>
constexpr int id13(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::countl_zero<Up>(n);
}
template <typename Tp>
constexpr int id25(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::countr_zero<Up>(n);
}
template <typename Tp>
constexpr int bit_width(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::bit_width<Up>(n);
}
template <typename Tp>
constexpr Tp id17(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return static_cast<Tp>(std::bit_floor<Up>(n));
}
template <typename Tp>
constexpr Tp id5(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return static_cast<Tp>(std::bit_ceil<Up>(n));
}
template <typename Tp>
constexpr int id11(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  constexpr int Nd = std::numeric_limits<Up>::digits;
  return Nd - 1 - std::countl_zero<Up>(n);
}
template <typename Tp>
constexpr int id24(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  constexpr int Nd = std::numeric_limits<Up>::digits;
  if (n == 0) { return 0; }
  return Nd - std::countl_zero<Up>(n - 1);
}
template <typename Tp>
constexpr Tp blsr(Tp n) {
  if (std::is_constant_evaluated()) { return n & (n - 1); }
  if constexpr (dword_fittable<Tp>) {
    return static_cast<Tp>(_blsr_u32(n));
  } else if constexpr (qword_fittable<Tp>) {
    return static_cast<Tp>(_blsr_u64(n));
  } else {
    return n & (n - 1);
  }
}
template <typename Tp>
constexpr Tp blsi(Tp n) {
  if (std::is_constant_evaluated()) { return n & -n; }
  if constexpr (dword_fittable<Tp>) {
    return static_cast<Tp>(_blsi_u32(n));
  } else if constexpr (qword_fittable<Tp>) {
    return static_cast<Tp>(_blsi_u64(n));
  } else {
    return n & -n;
  }
}
template <typename Tp>
constexpr int popcount(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::popcount<Up>(n);
}
}
namespace algo {
template <detail::integer Tp>
constexpr int id13(Tp n) {
  return detail::id13(n);
}
template <detail::integer Tp>
constexpr int id25(Tp n) {
  return detail::id25(n);
}
template <detail::integer Tp>
constexpr int bit_width(Tp n) {
  return detail::bit_width(n);
}
template <detail::integer Tp>
constexpr Tp id17(Tp n) {
  return detail::id17(n);
}
template <detail::integer Tp>
constexpr Tp id5(Tp n) {
  return detail::id5(n);
}
template <detail::integer Tp>
constexpr int id11(Tp n) {
  return detail::id11(n);
}
template <detail::integer Tp>
constexpr int id24(Tp n) {
  return detail::id24(n);
}
template <detail::integer Tp>
constexpr Tp blsr(Tp n) {
  return detail::blsr(n);
}
template <detail::integer Tp>
constexpr Tp blsi(Tp n) {
  return detail::blsi(n);
}
template <detail::integer Tp>
constexpr int popcount(Tp n) {
  return detail::popcount(n);
}
}


namespace algo {
template <detail::modular_integer ModNum>
  requires(ModNum::is_prime_mod())
class factorial {
public:
  factorial() noexcept = default;
  explicit factorial(int n) noexcept : fac_(n), inv_(n) {
    if (n == 0) [[unlikely]] { return; }
    fac_[0] = 1;
    for (int i = 1; i < n; ++i) { fac_[i] = fac_[i - 1] * ModNum(i); }
    inv_.back() = fac_.back().inv();
    for (int i = n; i-- > 1;) { inv_[i - 1] = inv_[i] * ModNum(i); }
  }
  ModNum fact(int n) const { return n >= 0 ? fac_[n] : 0; }
  ModNum rising_fact(int n, int k) const {
    return n <= 0 || k < 0 ? 0 : fac_[n + k - 1] * inv_[n - 1];
  }
  ModNum falling_fact(int n, int k) const {
    return n < 0 || k < 0 || k > n ? 0 : fac_[n] * inv_[n - k];
  }
  ModNum inv_fact(int n) const { return n >= 0 ? inv_[n] : 0; }
  ModNum comb(int n, int r) const {
    return n >= r && r >= 0 ? fac_[n] * inv_[r] * inv_[n - r] : 0;
  }
  ModNum perm(int n, int r) const {
    return n >= r && r >= 0 ? fac_[n] * inv_[n - r] : 0;
  }
  ModNum catalan(int n) const {
    return n < 0 ? 0 : fac_[2 * n] * inv_[n] * inv_[n + 1];
  }
  int limit() const { return static_cast<int>(fac_.size()); }
private:
  std::vector<ModNum> fac_;
  std::vector<ModNum> inv_;
};
}
namespace algo::detail {
template <typename Tp>
constexpr Tp sqrt(Tp n) {
  if (n == 0) { return 0; }
  using Up = std::make_unsigned_t<Tp>;
  const Up x = static_cast<Up>(n);
  Up ans = 0;
  for (int i = id11(n) / 2; i >= 0; --i) {
    const Up tmp = ans | (Up(1) << i);
    if (tmp * tmp <= x) { ans = tmp; }
  }
  return static_cast<Tp>(ans);
}
template <typename Tp>
constexpr Tp abs(Tp n) {
  return n < 0 ? -n : n;
}
template <typename Tp>
constexpr Tp floor_div(Tp x, Tp y) {
  if constexpr (std::is_signed_v<Tp>) {
    return x / y - ((x ^ y) < 0 && x % y != 0);
  } else {
    return x / y;
  }
}
template <typename Tp>
constexpr Tp ceil_div(Tp x, Tp y) {
  if constexpr (std::is_signed_v<Tp>) {
    return y > 0 ? floor_div(x + y - 1, y) : -floor_div(x, -y);
  } else {
    return floor_div(x + y - 1, y);
  }
}
template <typename Tp>
constexpr int alt(Tp n) {
  return -(n & 1) | 1;
}
}
namespace algo {
template <detail::integer Tp>
constexpr Tp sqrt(Tp n) {
  return detail::sqrt(n);
}
template <detail::integer Tp>
constexpr Tp abs(Tp n) {
  return detail::abs(n);
}
template <detail::integer T1, detail::sign_compatible_with<T1> T2>
constexpr auto floor_div(T1 x, T2 y) -> std::common_type_t<T1, T2> {
  using Tp = std::common_type_t<T1, T2>;
  return detail::floor_div<Tp>(x, y);
}
template <detail::integer T1, detail::sign_compatible_with<T1> T2>
constexpr auto ceil_div(T1 x, T2 y) -> std::common_type_t<T1, T2> {
  using Tp = std::common_type_t<T1, T2>;
  return detail::ceil_div<Tp>(x, y);
}
template <std::integral Tp>
constexpr int alt(Tp n) {
  return detail::alt(n);
}
template <detail::integer T1, detail::sign_compatible_with<T1> T2,
          detail::sign_compatible_with<T2> T3,
          detail::sign_compatible_with<T3> T4>
constexpr auto floor_sum(T1 a, T2 b, T3 c, T4 n)
    -> std::common_type_t<T1, T2, T3, T4> {
  detail::assume(n >= 0);
  detail::assume(c > 0);
  detail::assume(a >= 0);
  using Tp = std::common_type_t<T1, T2, T3, T4>;
  Tp res = 0, a0 = a, b0 = b, c0 = c, n0 = n;
  bool neg = false;
  while (a0 != 0) {
    if (a0 < c0 && b0 < c0) {
      const Tp m = (a0 * n0 + b0) / c0;
      const Tp tmp = a0;
      res += alt(neg) * m * n0;
      b0 = c0 - b0 - 1, a0 = c0, c0 = tmp, n0 = m - 1;
      neg ^= true;
    } else {
      detail::assume(n0 >= 0);
      const Tp tmp = (n0 * (n0 + 1) / 2) * (a0 / c0) + (n0 + 1) * (b0 / c0);
      res += alt(neg) * tmp;
      a0 %= c0, b0 %= c0;
    }
  }
  res += alt(neg) * (b0 / c0) * (n0 + 1);
  return res;
}
}
namespace algo::detail {
template <typename Tp>
constexpr auto safe_mul(Tp x, Tp y) -> imul_result_t<Tp> {
  using promoted_type = imul_result_t<Tp>;
  return static_cast<promoted_type>(x) * y;
}
template <typename Tp>
constexpr Tp mod_mul(Tp x, Tp y, Tp m) {
  assume(0 < m);
  assume(0 <= x && x < m);
  assume(0 <= y && y < m);
  const auto prod = safe_mul(x, y) % m;
  return static_cast<Tp>(prod);
}
template <typename Tp>
constexpr auto id26(Tp a, Tp b) -> std::array<Tp, 3> {
  static_assert(std::is_signed_v<Tp>, "Invalid integral type");
  Tp x0 = 1, y0 = 0, x1 = 0, y1 = 1, a0 = a, b0 = b;
  while (b0) {
    Tp q = a0 / b0, tp = x0;
    x0 = x1;
    x1 = tp - q * x1;
    tp = y0;
    y0 = y1;
    y1 = tp - q * y1;
    tp = a0;
    a0 = b0;
    b0 = tp - q * b0;
  }
  if (a0 < 0) { x0 = -x0, y0 = -y0, a0 = -a0; }
  return {x0, y0, a0};
}
template <typename Tp, typename Up>
constexpr Tp pow_mod(Tp a, Up b, Tp m) {
  Tp ans = 1, mul = a;
  const Tp mod = m;
  std::make_unsigned_t<Up> pw = b;
  if ((mul %= mod) < 0) mul += mod;
  while (pw > 0) {
    if (pw % 2 == 1) { ans = mod_mul(ans, mul, mod); }
    mul = mod_mul(mul, mul, mod);
    pw /= 2;
  }
  return ans;
}
}
namespace algo::detail {
template <dword_fittable Tp>
constexpr bool prime_test(Tp n) {
  if (n <= 1) { return false; }
  const int s = id25(n - 1);
  const Tp d = (n - 1) >> s;
  constexpr std::array<Tp, 4> primes{2, 3, 5, 7};
  for (const Tp p : primes) {
    if (p == n) { return true; }
    Tp x = pow_mod(p, d, n);
    bool good = x == n - 1 || x == 1;
    for (int r = 1; r < s; ++r) {
      x = mod_mul(x, x, n);
      good |= x == n - 1;
    }
    if (!good) { return false; }
  }
  return true;
}
template <qword_fittable Tp>
constexpr bool prime_test(Tp n) {
  if (n <= 1) { return false; }
  const int s = id25(n - 1);
  const Tp d = (n - 1) >> s;
  constexpr std::array<Tp, 12> primes{2, 3, 5, 7, 11, 13,
                                      17, 19, 23, 29, 31, 37};
  for (const Tp p : primes) {
    if (p == n) { return true; }
    Tp x = pow_mod(p, d, n);
    bool good = x == n - 1 || x == 1;
    for (int r = 1; r < s; ++r) {
      x = mod_mul(x, x, n);
      good |= x == n - 1;
    }
    if (!good) { return false; }
  }
  return true;
}
template <typename Tp>
constexpr int mobius(Tp n) {
  assume(n > 0);
  bool parity = false;
  if (n == 1) { return 1; }
  if (n % 2 == 0) {
    if ((n /= 2) % 2 == 0) { return 0; }
    parity ^= true;
  }
  if (n % 3 == 0) {
    if ((n /= 3) % 3 == 0) { return 0; }
    parity ^= true;
  }
  const Tp sn = sqrt(n);
  for (Tp i = 5, c = 2; i <= sn; i += c, c ^= 6) {
    if (n % i == 0) {
      if ((n /= i) % i == 0) { return 0; }
      parity ^= true;
    }
  }
  if (n > 1) { parity ^= 1; }
  return alt(parity);
}
template <typename Tp>
constexpr Tp totient(Tp n) {
  assume(n > 0);
  Tp ans = n;
  if (n % 2 == 0) {
    ans -= ans / 2;
    do { n /= 2; } while (n % 2 == 0);
  }
  if (n % 3 == 0) {
    ans -= ans / 3;
    do { n /= 3; } while (n % 3 == 0);
  }
  const Tp sn = sqrt(n);
  for (Tp i = 5, c = 2; i <= sn; i += c, c ^= 6) {
    if (n % i == 0) {
      ans -= ans / i;
      do { n /= i; } while (n % i == 0);
    }
  }
  if (n > 1) { ans -= ans / n; }
  return ans;
}
template <typename Tp>
constexpr int id14(Tp n) {
  assume(n > 0);
  int ans = 0;
  if (n % 2 == 0) {
    ans = ans + 1;
    do { n /= 2; } while (n % 2 == 0);
  }
  if (n % 3 == 0) {
    ans = ans + 1;
    do { n /= 3; } while (n % 3 == 0);
  }
  const Tp sn = sqrt(n);
  for (Tp i = 5, c = 2; i <= sn; i += c, c ^= 6) {
    if (n % i == 0) {
      ans = ans + 1;
      do { n /= i; } while (n % i == 0);
    }
  }
  if (n > 1) { ans = ans + 1; }
  return ans;
}
template <typename Tp>
constexpr int id12(Tp n) {
  assume(n > 0);
  int cnt = 0;
  if (n % 2 == 0) {
    do { n /= 2, cnt++; } while (n % 2 == 0);
  }
  if (n % 3 == 0) {
    do { n /= 3, cnt++; } while (n % 3 == 0);
  }
  const Tp sn = sqrt(n);
  for (Tp i = 5, c = 2; i <= sn; i += c, c ^= 6) {
    if (n % i == 0) {
      do { n /= i, cnt++; } while (n % i == 0);
    }
  }
  if (n > 1) { cnt = cnt + 1; }
  return cnt;
}
}
namespace algo::detail {
template <typename Tp>
constexpr Tp inv_mod(Tp a, Tp m) {
  using Sp = std::make_signed_t<Tp>;
  auto res = id26<Sp>(a, m)[0] % static_cast<Sp>(m);
  if (res < 0) { res += m; }
  return static_cast<Tp>(res);
}
template <typename Up>
constexpr Up id19(Up n) {
  static_assert(std::is_unsigned_v<Up>, "Invalid integral type");
  constexpr int Nd = std::numeric_limits<Up>::digits;
  Up ans = 1;
  for (int i = 2; i < Nd; i *= 2) { ans *= (2 - ans * n); }
  return ans;
}
template <typename Tp>
constexpr Tp id2(Tp n) {
  Tp ans = 2;
  const Tp exponent = (n - 1) / 2;
  while (pow_mod(ans, exponent, n) != n - 1) { ans += 1; }
  return ans;
}
template <typename Tp>
std::optional<Tp> id9(Tp a, Tp b, Tp m) {
  if ((a %= m) < 0) { a += m; }
  if ((b %= m) < 0) { b += m; }
  const Tp n = sqrt(m);
  assume(a >= 0 && a < m);
  const Tp an = pow_mod(a, n, m);
  std::map<Tp, Tp> f2;
  for (Tp q = 0, now = b; q <= n; ++q) {
    f2[now] = q;
    now = mod_mul(now, a, m);
  }
  for (Tp p = 1, cur = 1; p <= n; ++p) {
    cur = mod_mul(cur, an, m);
    if (f2.contains(cur)) { return n * p - f2[cur]; }
  }
  return std::nullopt;
}
template <typename Tp>
constexpr auto primitive_root(Tp n, Tp phi) -> std::optional<Tp> {
  assume(n >= 1);
  assume(phi >= 1);
  if (n == 1) { return 1; }
  Tp cur_phi = phi;
  std::array<Tp, 23> factors{};
  int cnt = 0;
  if (cur_phi % 2 == 0) {
    factors[cnt++] = 2;
    do { cur_phi /= 2; } while (cur_phi % 2 == 0);
  }
  if (cur_phi % 3 == 0) {
    factors[cnt++] = 3;
    do { cur_phi /= 3; } while (cur_phi % 3 == 0);
  }
  const Tp sp = sqrt(cur_phi);
  for (Tp i = 5, c = 2; i <= sp; i += c, c ^= 6) {
    if (cur_phi % i == 0) {
      factors[cnt++] = i;
      do { cur_phi /= i; } while (cur_phi % i == 0);
    }
  }
  if (cur_phi > 1) { factors[cnt++] = cur_phi; }
  const auto first = factors.begin();
  const auto last = factors.begin() + cnt;
  for (Tp g = 1; g < n; ++g) {
    if (std::gcd(n, g) != 1) { continue; }
    const auto check = std::find_if(
        first, last, [phi, n, g](Tp p) { return pow_mod(g, phi / p, n) == 1; });
    if (check == last) { return g; }
  }
  return std::nullopt;
}
template <typename Tp>
constexpr Tp id3(Tp n) {
  assume(n >= 1);
  Tp cur_phi = n - 1;
  std::array<Tp, 23> factors{};
  int cnt = 0;
  if (cur_phi % 2 == 0) {
    factors[cnt++] = 2;
    do { cur_phi /= 2; } while (cur_phi % 2 == 0);
  }
  if (cur_phi % 3 == 0) {
    factors[cnt++] = 3;
    do { cur_phi /= 3; } while (cur_phi % 3 == 0);
  }
  const Tp sp = sqrt(cur_phi);
  for (Tp i = 5, c = 2; i <= sp; i += c, c ^= 6) {
    if (cur_phi % i == 0) {
      factors[cnt++] = i;
      do { cur_phi /= i; } while (cur_phi % i == 0);
    }
  }
  if (cur_phi > 1) { factors[cnt++] = cur_phi; }
  const auto first = factors.begin();
  const auto last = factors.begin() + cnt;
  for (Tp g = 1; g < n; ++g) {
    const auto check = std::find_if(
        first, last, [n, g](Tp p) { return pow_mod(g, (n - 1) / p, n) == 1; });
    if (check == last) { return g; }
  }
  detail::unreachable();
}
template <typename Tp>
std::optional<Tp> id8(Tp a, Tp b, Tp n) {
  const Tp g = primitive_root(n, n - 1);
  const Tp ga = pow_mod(g, a, n);
  const std::optional<Tp> y = id9(ga, b, n);
  return y ? pow_mod(g, *y, n) : std::nullopt;
}
}
namespace algo {
template <uint32_t MOD = 998244353>
  requires(0 < MOD && MOD < (1u << 31))
class modint : detail::modnum_base {
public:
  static constexpr bool IsPrime = detail::prime_test(MOD);
  constexpr modint() noexcept = default;
  template <detail::integer Tp>
  constexpr modint(Tp n) noexcept : value_{transform(n)} {}
  constexpr modint(bool b) noexcept : value_{b ? 0 : 1 % MOD} {}
  constexpr modint& operator+=(modint rhs) {
    value_ += rhs.value() - MOD;
    value_ += (static_cast<int32_t>(value_) < 0) ? MOD : 0;
    return *this;
  }
  constexpr modint& operator-=(modint rhs) {
    value_ -= rhs.value();
    value_ += (static_cast<int32_t>(value_) < 0) ? MOD : 0;
    return *this;
  }
  constexpr modint& operator*=(modint rhs) {
    detail::assume(rhs.value() < MOD);
    detail::assume(value() < MOD);
    value_ = detail::mod_mul(value(), rhs.value(), MOD);
    return *this;
  }
  constexpr modint& operator/=(modint rhs) { return operator*=(rhs.inv()); }
  constexpr modint& operator++() { return operator+=(1); }
  constexpr modint& operator--() { return operator-=(1); }
  constexpr modint operator++(int) {
    const modint res{*this};
    operator++();
    return res;
  }
  constexpr modint operator--(int) {
    const modint res{*this};
    operator--();
    return res;
  }
  constexpr modint operator+() const { return *this; }
  constexpr modint operator-() const {
    const uint32_t res = value() != 0 ? MOD - value() : 0;
    return from(res);
  }
  constexpr friend auto operator+(modint lhs, modint rhs) -> modint {
    lhs += rhs;
    return lhs;
  }
  constexpr friend auto operator-(modint lhs, modint rhs) -> modint {
    lhs -= rhs;
    return lhs;
  }
  constexpr friend auto operator*(modint lhs, modint rhs) -> modint {
    lhs *= rhs;
    return lhs;
  }
  constexpr friend auto operator/(modint lhs, modint rhs) -> modint {
    lhs /= rhs;
    return lhs;
  }
  constexpr friend bool operator==(modint lhs, modint rhs) {
    return lhs.get() == rhs.get();
  }
  constexpr uint32_t value() const { return value_; }
  constexpr uint32_t get() const { return value_; }
  static constexpr uint32_t mod() { return MOD; }
  static constexpr bool is_prime_mod() { return IsPrime; }
  constexpr modint inv() const {
    if constexpr (IsPrime) {
      return pow(MOD - 2);
    } else {
      return from(detail::inv_mod(value(), MOD));
    }
  }
  template <detail::integer Tp>
  constexpr modint pow(Tp x) const {
    modint res{1};
    modint mul{*this};
    while (x > 0) {
      if (x % 2 == 1) { res *= mul; }
      mul *= mul;
      x /= 2;
    }
    return res;
  }
  constexpr auto sqrt() const -> std::optional<modint>
    requires(IsPrime)
  {
    if constexpr (MOD == 2) { return {*this}; }
    if (*this == 0 || *this == 1) { return {*this}; }
    if (pow((MOD - 1) / 2) == -1) { return std::nullopt; }
    constexpr modint Z = detail::id2(MOD);
    constexpr uint32_t K = detail::id25(MOD - 1);
    constexpr uint32_t C = (MOD - 1) >> K;
    modint res = pow((C + 1) / 2);
    modint cur = pow(C);
    modint fac = Z.pow(C);
    for (uint32_t i = K - 1; i > 0 && cur != 1; --i) {
      const modint nfac = fac * fac;
      if (cur.pow(1 << (i - 1)) == MOD - 1) {
        res *= fac;
        cur *= nfac;
      }
      fac = nfac;
    }
    return {res};
  }
  template <detail::integer Tp>
  constexpr static modint from(Tp x) {
    return std::bit_cast<modint>(static_cast<uint32_t>(x));
  }
  friend std::ostream& operator<<(std::ostream& os, modint m) {
    os << m.value();
    return os;
  }
  constexpr static uint32_t transform(uint32_t n) { return n % MOD; }
  constexpr static uint32_t transform(int32_t n) {
    n %= static_cast<int32_t>(MOD);
    if (n < 0) { n += static_cast<int32_t>(MOD); }
    return static_cast<uint32_t>(n);
  }
  constexpr static uint32_t transform(uint64_t n) {
    return static_cast<uint32_t>(n % MOD);
  }
  constexpr static uint32_t transform(int64_t n) {
    n %= static_cast<int64_t>(MOD);
    if (n < 0) { n += static_cast<int64_t>(MOD); }
    return static_cast<uint32_t>(n);
  }
  static std::vector<modint> inv_table(int n)
    requires(IsPrime)
  {
    std::vector<modint> inv(n);
    if (n <= 1) [[unlikely]] { return inv; }
    inv[1] = 1;
    for (int i = 2; i < n; ++i) { inv[i] = from(MOD - MOD / i) * inv[MOD % i]; }
    return inv;
  }
private:
  uint32_t value_{0};
};
}
namespace algo::detail {
template <typename ModNum>
struct dif_info {
  static constexpr uint32_t Mod = ModNum::mod();
  static constexpr uint32_t Cap = id25(Mod - 1);
  static constexpr uint32_t Cof = (Mod - 1) >> Cap;
  static constexpr uint32_t Gen = id3(Mod);
  std::array<ModNum, Cap + 1> root;
  constexpr dif_info() noexcept {
    auto rot = ModNum(Gen).pow(Cof);
    for (int i = Cap; i >= 0; --i) {
      root[i] = rot;
      rot *= rot;
    }
  }
};
template <typename ModNum>
struct dit_info {
  static constexpr uint32_t Mod = ModNum::mod();
  static constexpr uint32_t Cap = id25(Mod - 1);
  static constexpr uint32_t Cof = (Mod - 1) >> Cap;
  static constexpr uint32_t Gen = id3(Mod);
  std::array<ModNum, Cap + 1> root;
  constexpr dit_info() noexcept {
    auto rot = ModNum(Gen).pow(Cof).inv();
    for (int i = Cap; i >= 0; --i) {
      root[i] = rot;
      rot *= rot;
    }
  }
};
template <typename ModNum>
void id15(std::span<ModNum> out) {
  static const dif_info<ModNum> info{};
  static_assert(info.Mod % 4 == 1, "Bad modulus for NTT");
  const ModNum imag = info.root[2];
  const int n = static_cast<int>(out.size());
  const int k = id11(n);
  assume(n > 0);
  for (int h = 0; h + (k % 2) < k; h += 2) {
    const int m = 1 << (k - h);
    assume(m > 0);
    assume(m % 4 == 0);
    const ModNum id10 = info.root[k - h];
    const ModNum id20 = id10 * id10;
    const ModNum id16 = id20 * id10;
    for (int j = 0; j < n; j += m) {
      ModNum w1 = 1;
      ModNum w2 = 1;
      ModNum w3 = 1;
      for (int i = 0; i < m / 4; ++i) {
        const ModNum x0 = out[i + j + m / 4 * 0];
        const ModNum x1 = out[i + j + m / 4 * 1];
        const ModNum x2 = out[i + j + m / 4 * 2];
        const ModNum x3 = out[i + j + m / 4 * 3];
        const ModNum id6 = x0 + x2;
        const ModNum id28 = x0 - x2;
        const ModNum id23 = x1 + x3;
        const ModNum id27 = (x1 - x3) * imag;
        const ModNum e0 = id6 + id23;
        const ModNum e1 = id6 - id23;
        const ModNum e2 = id28 + id27;
        const ModNum e3 = id28 - id27;
        out[i + j + m / 4 * 0] = e0;
        out[i + j + m / 4 * 1] = e1 * w1;
        out[i + j + m / 4 * 2] = e2 * w2;
        out[i + j + m / 4 * 3] = e3 * w3;
        w1 *= id20;
        w2 *= id10;
        w3 *= id16;
      }
    }
  }
  if (k % 2 == 1) {
    for (int i = 0; i < n; i += 2) {
      const ModNum x0 = out[i + 0];
      const ModNum x1 = out[i + 1];
      out[i + 0] = x0 + x1;
      out[i + 1] = x0 - x1;
    }
  }
}
template <typename ModNum>
void id21(std::span<ModNum> out) {
  static const dit_info<ModNum> info{};
  static_assert(info.Mod % 4 == 1, "Bad modulus for NTT");
  const ModNum imag = info.root[2];
  const int n = static_cast<int>(out.size());
  const int k = id11(n);
  if (k % 2 == 1) {
    for (int i = 0; i < n; i += 2) {
      const ModNum x0 = out[i + 0];
      const ModNum x1 = out[i + 1];
      out[i + 0] = x0 + x1;
      out[i + 1] = x0 - x1;
    }
  }
  for (int h = 2 + (k % 2); h <= k; h += 2) {
    const int m = 1 << h;
    assume(m > 0);
    assume(m % 4 == 0);
    const ModNum id10 = info.root[h];
    const ModNum id20 = id10 * id10;
    const ModNum id16 = id20 * id10;
    for (int j = 0; j < n; j += m) {
      ModNum w1 = 1;
      ModNum w2 = 1;
      ModNum w3 = 1;
      for (int i = 0; i < m / 4; ++i) {
        const ModNum x0 = out[i + j + m / 4 * 0];
        const ModNum x1 = out[i + j + m / 4 * 1] * w1;
        const ModNum x2 = out[i + j + m / 4 * 2] * w2;
        const ModNum x3 = out[i + j + m / 4 * 3] * w3;
        const ModNum id18 = x0 + x1;
        const ModNum id4 = x0 - x1;
        const ModNum id0 = x2 + x3;
        const ModNum id22 = (x2 - x3) * imag;
        out[i + j + m / 4 * 0] = id18 + id0;
        out[i + j + m / 4 * 1] = id4 + id22;
        out[i + j + m / 4 * 2] = id18 - id0;
        out[i + j + m / 4 * 3] = id4 - id22;
        w1 *= id20;
        w2 *= id10;
        w3 *= id16;
      }
    }
  }
}
}
namespace algo {
template <detail::modular_integer ModNum>
  requires(ModNum::is_prime_mod())
class series {
public:
  series() noexcept = default;
  series(std::vector<ModNum> vec) noexcept : c_{std::move(vec)} {}
  template <std::input_iterator IIter>
    requires std::convertible_to<std::iter_value_t<IIter>, ModNum>
  series(IIter first, IIter last) noexcept : c_(first, last) {}
  series(std::initializer_list<ModNum> lst) noexcept : c_{lst} {}
  ModNum& operator[](int i) { return c_[i]; }
  const ModNum& operator[](int i) const { return c_[i]; }
  ModNum coef(int i) const {
    if (0 <= i && i < size()) { return c_[i]; }
    return 0;
  }
  ModNum eval(ModNum x) const {
    ModNum ans = 0;
    ModNum cx = 1;
    for (const auto& v : c_) {
      ans += cx * v;
      cx *= x;
    }
    return ans;
  }
  series& operator+=(const series& rhs) {
    if (c_.size() < rhs.c_.size()) { c_.resize(rhs.c_.size()); }
    for (int i = 0; i < rhs.size(); ++i) { c_[i] += rhs.c_[i]; }
    return *this;
  }
  series& operator-=(const series& rhs) {
    if (c_.size() < rhs.c_.size()) { c_.resize(rhs.c_.size()); }
    for (int i = 0; i < rhs.size(); ++i) { c_[i] -= rhs.c_[i]; }
    return *this;
  }
  series& operator*=(series rhs) {
    if (!empty() && !rhs.empty()) [[likely]] {
      const int size_l = size();
      const int size_r = rhs.size();
      const int size_lr = size_l + size_r - 1;
      const int num_points = detail::id5(size_lr);
      c_.resize(num_points);
      rhs.c_.resize(num_points);
      detail::id15(std::span{c_});
      detail::id15(std::span{rhs.c_});
      for (int i = 0; i < num_points; ++i) { c_[i] *= rhs.c_[i]; }
      detail::id21(std::span{c_});
      c_.resize(size_lr);
      const auto inum_points = ModNum(num_points).inv();
      for (auto& f : c_) { f *= inum_points; }
    } else {
      if (c_.capacity() < rhs.c_.capacity()) { c_.swap(rhs.c_); }
      c_.clear();
    }
    return *this;
  }
  series& operator*=(ModNum rhs) {
    for (auto& f : c_) { f *= rhs; }
    return *this;
  }
  friend series operator+(series fx) { return fx; }
  friend series operator-(series fx) {
    for (auto& f : fx.c_) { f = -f; }
    return fx;
  }
  friend series operator+(series lhs, const series& rhs) {
    lhs += rhs;
    return lhs;
  }
  friend series operator-(series lhs, const series& rhs) {
    lhs -= rhs;
    return lhs;
  }
  friend series operator*(series lhs, series rhs) {
    lhs *= std::move(rhs);
    return lhs;
  }
  friend series operator*(series lhs, ModNum rhs) {
    lhs *= rhs;
    return lhs;
  }
  friend series operator*(ModNum lhs, series rhs) {
    rhs *= lhs;
    return rhs;
  }
  series& drop(int n) {
    if (size() > n) [[likely]] {
      std::shift_left(c_.begin(), c_.end(), n);
      c_.resize(size() - n);
    } else {
      c_.clear();
    }
    return *this;
  }
  series& reverse() {
    normalize();
    std::reverse(c_.begin(), c_.end());
    return *this;
  }
  series& square() {
    if (!empty()) [[likely]] {
      const int nsize = 2 * size() - 1;
      const int num_points = detail::id5(nsize);
      c_.resize(num_points);
      detail::id15(std::span{c_});
      for (auto& f : c_) { f *= f; }
      detail::id21(std::span{c_});
      c_.resize(nsize);
      const auto inum_points = ModNum(num_points).inv();
      for (auto& f : c_) { f *= inum_points; }
    }
    return *this;
  }
  series& diff() {
    if (!empty()) [[likely]] {
      const int nsize = size() - 1;
      for (int i = 0; i < nsize; ++i) { c_[i] = c_[i + 1] * ModNum(i + 1); }
      c_.pop_back();
    }
    return *this;
  }
  series& diff_x() {
    for (int i = 0; i < size(); ++i) { c_[i] *= ModNum(i); }
    return *this;
  }
  series& integrate() {
    const int nsize = size() + 1;
    c_.emplace_back(0);
    const auto invs = ModNum::inv_table(nsize);
    for (int i = nsize - 1; i > 0; --i) { c_[i] = c_[i - 1] * invs[i]; }
    c_.front() = 0;
    return *this;
  }
  series& integrate_x() {
    const auto invs = ModNum::inv_table(size());
    for (int i = 0; i < size(); ++i) { c_[i] *= invs[i]; }
    return *this;
  }
  series inv(int n) const {
    const int nsize = detail::id5(n);
    std::vector<ModNum> q_x(nsize);
    const auto i4 = ModNum(4).inv();
    ModNum isize = 1;
    q_x[0] = c_[0].inv();
    for (int k = 1; k < nsize; k *= 2) {
      isize *= i4;
      const int cur_k = k;
      const int id7 = k * 2;
      std::vector<ModNum> buf_fx(id7);
      std::vector<ModNum> id1(id7);
      std::copy_n(c_.begin(), std::min(size(), id7), buf_fx.begin());
      std::copy_n(q_x.begin(), k, id1.begin());
      detail::id15(std::span{buf_fx});
      detail::id15(std::span{id1});
      for (int i = 0; i < id7; ++i) { buf_fx[i] *= id1[i]; }
      detail::id21(std::span{buf_fx});
      std::fill_n(buf_fx.begin(), cur_k, 0);
      for (int i = cur_k; i < id7; ++i) { buf_fx[i] *= isize; }
      detail::id15(std::span{buf_fx});
      for (int i = 0; i < id7; ++i) { buf_fx[i] *= -id1[i]; }
      detail::id21(std::span{buf_fx});
      std::copy_n(buf_fx.begin() + cur_k, cur_k, q_x.begin() + cur_k);
    }
    q_x.resize(n);
    return q_x;
  }
  series exp(int n) const {
    const int nsize = detail::id5(n);
    std::vector<ModNum> f_x(nsize / 1);
    std::vector<ModNum> q_x(nsize / 1);
    std::vector<ModNum> r_x(nsize / 2);
    q_x.front() = 1;
    if (!r_x.empty()) { r_x.front() = 1; }
    for (int i = 0; i < nsize; ++i) { f_x[i] = ModNum(i) * coef(i); }
    const auto invs = ModNum::inv_table(nsize);
    const auto i2 = ModNum(2).inv();
    ModNum isize = 1;
    for (int k = 1; k < nsize; k *= 2) {
      const int cur_k = k;
      const int id7 = k * 2;
      std::vector<ModNum> buf_fx(id7);
      std::vector<ModNum> id1(id7);
      std::vector<ModNum> buf_rx(id7);
      std::copy_n(f_x.begin(), cur_k, buf_fx.begin());
      std::copy_n(q_x.begin(), cur_k, id1.begin());
      std::copy_n(r_x.begin(), cur_k, buf_rx.begin());
      detail::id15(std::span{buf_fx.begin(), buf_fx.begin() + cur_k});
      detail::id15(std::span{id1.begin(), id1.begin() + id7});
      detail::id15(std::span{buf_rx.begin(), buf_rx.begin() + id7});
      for (int i = 0; i < cur_k; ++i) { buf_fx[i] *= id1[i]; }
      detail::id21(std::span{buf_fx.begin(), buf_fx.begin() + cur_k});
      for (int i = 0; i < cur_k; ++i) { buf_fx[i] *= isize; }
      for (int i = 0; i < cur_k; ++i) { buf_fx[i] -= ModNum(i) * q_x[i]; }
      std::copy_n(buf_fx.begin(), cur_k, buf_fx.begin() + cur_k);
      std::fill_n(buf_fx.begin(), cur_k, 0);
      detail::id15(std::span{buf_fx});
      for (int i = 0; i < id7; ++i) { buf_fx[i] *= buf_rx[i]; }
      detail::id21(std::span{buf_fx});
      std::fill_n(buf_fx.begin(), cur_k, 0);
      isize *= i2;
      for (int i = cur_k; i < id7; ++i) { buf_fx[i] *= isize; }
      for (int i = cur_k; i < id7; ++i) { buf_fx[i] += f_x[i]; }
      for (int i = cur_k; i < id7; ++i) { buf_fx[i] *= invs[i]; }
      detail::id15(std::span{buf_fx});
      for (int i = 0; i < id7; ++i) { id1[i] *= buf_fx[i]; }
      detail::id21(std::span{id1});
      for (int i = cur_k; i < id7; ++i) { id1[i] *= isize; }
      std::copy_n(id1.begin() + cur_k, cur_k, q_x.begin() + cur_k);
      if (id7 != nsize) {
        std::copy_n(q_x.begin(), cur_k, id1.begin());
        detail::id15(std::span{id1});
        for (int i = 0; i < id7; ++i) { id1[i] *= buf_rx[i]; }
        detail::id21(std::span{id1});
        std::fill_n(id1.begin(), cur_k, 0);
        for (int i = cur_k; i < id7; ++i) { id1[i] *= isize; }
        detail::id15(std::span{id1});
        for (int i = 0; i < id7; ++i) { buf_rx[i] *= -id1[i]; }
        detail::id21(std::span{buf_rx});
        for (int i = cur_k; i < id7; ++i) { buf_rx[i] *= isize; }
        std::copy_n(buf_rx.begin() + cur_k, cur_k, r_x.begin() + cur_k);
      }
    }
    q_x.resize(n);
    return q_x;
  }
  series log(int n) const {
    auto res{*this};
    res.resize(n);
    for (int i = 0; i < n; ++i) { res.c_[i] *= ModNum(i); }
    res *= inv(n);
    res.resize(n);
    const auto invs = ModNum::inv_table(n);
    for (int i = 1; i < n; ++i) { res.c_[i] *= invs[i]; }
    return res;
  }
  void reserve(int n) { c_.reserve(n); }
  void resize(int n) { c_.resize(n); }
  void normalize() {
    const auto pos =
        std::find_if(c_.rbegin(), c_.rend(), [](ModNum x) { return x != 0; });
    c_.erase(pos.base(), c_.end());
  }
  void clear() { c_.clear(); }
  int size() const { return static_cast<int>(c_.size()); }
  bool empty() const { return c_.empty(); }
  std::vector<ModNum> data() const& { return c_; }
  std::vector<ModNum> data() && { return std::move(c_); }
private:
  std::vector<ModNum> c_;
};
}
namespace views = std::views;
namespace chrono = std::chrono;
using std::array;
using std::bitset;
using std::cin;
using std::complex;
using std::cout;
using std::deque;
using std::endl;
using std::gcd;
using std::lcm;
using std::map;
using std::max;
using std::min;
using std::move;
using std::multimap;
using std::multiset;
using std::nullopt;
using std::optional;
using std::pair;
using std::queue;
using std::set;
using std::span;
using std::string;
using std::string_view;
using std::swap;
using std::tie;
using std::to_string;
using std::tuple;
using std::vector;
using wint = int64_t;
using uint = uint32_t;
template <typename Tp>
using stack = std::stack<Tp, std::vector<Tp>>;
template <typename Key, typename Value, typename Hash = std::hash<Key>>
using umap = std::unordered_map<Key, Value, Hash>;
template <typename Key, typename Hash = std::hash<Key>>
using uset = std::unordered_set<Key, Hash>;
template <typename Tp, typename Comp = std::less<Tp>>
using max_heap = std::priority_queue<Tp, std::vector<Tp>, Comp>;
template <typename Tp, typename Comp = std::greater<Tp>>
using min_heap = std::priority_queue<Tp, std::vector<Tp>, Comp>;




namespace {
using mint = algo::modint<>;
const algo::factorial<mint> fac(MAXN);
}
void solve() noexcept {
  int n;
  cin >> n;
  using poly = algo::series<mint>;
  const auto f = poly{mint(0), mint(1), mint(1) / 2}.exp(n + 1).data();
  DEBUG(f);
  mint ans = 0;
  for (int s = 0; s <= (n / 4); ++s) {
    ans += fac.fact(n - 2 * s) * fac.inv_fact(s) * f[n - 4 * s];
  }
  cout << ans << '\n';
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cout.precision(15);
  std::fixed(std::cout);
  int tc;
  std::cin >> tc;
  while (tc--) { solve(); }
  return 0;
}
