














































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
constexpr int id40(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::countl_zero<Up>(n);
}
template <typename Tp>
constexpr int id61(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::countr_zero<Up>(n);
}
template <typename Tp>
constexpr int bit_width(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::bit_width<Up>(n);
}
template <typename Tp>
constexpr Tp id46(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return static_cast<Tp>(std::bit_floor<Up>(n));
}
template <typename Tp>
constexpr Tp id22(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return static_cast<Tp>(std::bit_ceil<Up>(n));
}
template <typename Tp>
constexpr int id36(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  constexpr int Nd = std::numeric_limits<Up>::digits;
  return Nd - 1 - std::countl_zero<Up>(n);
}
template <typename Tp>
constexpr int id59(Tp n) {
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
constexpr int id40(Tp n) {
  return detail::id40(n);
}
template <detail::integer Tp>
constexpr int id61(Tp n) {
  return detail::id61(n);
}
template <detail::integer Tp>
constexpr int bit_width(Tp n) {
  return detail::bit_width(n);
}
template <detail::integer Tp>
constexpr Tp id46(Tp n) {
  return detail::id46(n);
}
template <detail::integer Tp>
constexpr Tp id22(Tp n) {
  return detail::id22(n);
}
template <detail::integer Tp>
constexpr int id36(Tp n) {
  return detail::id36(n);
}
template <detail::integer Tp>
constexpr int id59(Tp n) {
  return detail::id59(n);
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
namespace algo::detail::simd {
template <int N>
static __m256i id60(__m256i A, __m256i B) {
  return _mm256_castps_si256(
      _mm256_shuffle_ps(_mm256_castsi256_ps(A), _mm256_castsi256_ps(B), N));
}
template <int N>
static __m256i id42(__m256i A, __m256i B) {
  return _mm256_castpd_si256(
      _mm256_shuffle_pd(_mm256_castsi256_pd(A), _mm256_castsi256_pd(B), N));
}
template <int N>
static __m256i id5(__m256i A, __m256i B) {
  constexpr int Lo = (N >> 0) & 0b11;
  constexpr int Hi = (N >> 2) & 0b11;
  return _mm256_permute2f128_si256(A, B, (Hi << 4) | Lo);
}
template <int N>
static __m256i id51(__m256i A) {
  return _mm256_shuffle_epi32(A, N);
}
template <int N>
static __m256i id7(__m256i A) {
  return _mm256_permute4x64_epi64(A, N);
}
template <int N>
static __m256i id3(__m256i A) {
  constexpr int Lo = ((N >> 0) & 1) ? 0b1110 : 0b0100;
  constexpr int Hi = ((N >> 1) & 1) ? 0b1110 : 0b0100;
  return _mm256_permute4x64_epi64(A, (Hi << 4) | Lo);
}
template <int I>
static __m256i id44(__m256i A, uint32_t f) {
  return _mm256_insert_epi32(A, f, I);
}
template <int I>
static __m256i id54(__m256i A, uint64_t f) {
  return _mm256_insert_epi64(A, f, I);
}
template <int I>
static uint32_t id24(__m256i A) {
  return static_cast<uint32_t>(_mm256_extract_epi32(A, I));
}
template <int I>
static uint64_t id4(__m256i A) {
  return static_cast<uint64_t>(_mm256_extract_epi64(A, I));
}
template <int N>
static __m256i id62(__m256i A) {
  const auto mask = _mm256_set_epi32(-((N >> 7) & 1) | 1, -((N >> 6) & 1) | 1,
                                     -((N >> 5) & 1) | 1, -((N >> 4) & 1) | 1,
                                     -((N >> 3) & 1) | 1, -((N >> 2) & 1) | 1,
                                     -((N >> 1) & 1) | 1, -((N >> 0) & 1) | 1);
  return _mm256_sign_epi32(A, mask);
}
}
namespace algo::detail {
template <typename Tp>
constexpr Tp sqrt(Tp n) {
  if (n == 0) { return 0; }
  using Up = std::make_unsigned_t<Tp>;
  const Up x = static_cast<Up>(n);
  Up ans = 0;
  for (int i = id36(n) / 2; i >= 0; --i) {
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
constexpr auto id63(Tp a, Tp b) -> std::array<Tp, 3> {
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
template <typename Tp>
constexpr Tp inv_mod(Tp a, Tp m) {
  using Sp = std::make_signed_t<Tp>;
  auto res = id63<Sp>(a, m)[0] % static_cast<Sp>(m);
  if (res < 0) { res += m; }
  return static_cast<Tp>(res);
}
template <typename Up>
constexpr Up id53(Up n) {
  static_assert(std::is_unsigned_v<Up>, "Invalid integral type");
  constexpr int Nd = std::numeric_limits<Up>::digits;
  Up ans = 1;
  for (int i = 2; i < Nd; i *= 2) { ans *= (2 - ans * n); }
  return ans;
}
template <typename Tp>
constexpr Tp id12(Tp n) {
  Tp ans = 2;
  const Tp exponent = (n - 1) / 2;
  while (pow_mod(ans, exponent, n) != n - 1) { ans += 1; }
  return ans;
}
template <typename Tp>
std::optional<Tp> id34(Tp a, Tp b, Tp m) {
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
constexpr Tp id14(Tp n) {
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
std::optional<Tp> id33(Tp a, Tp b, Tp n) {
  const Tp g = primitive_root(n, n - 1);
  const Tp ga = pow_mod(g, a, n);
  const std::optional<Tp> y = id34(ga, b, n);
  return y ? pow_mod(g, *y, n) : std::nullopt;
}
}
namespace algo::detail {
template <dword_fittable Tp>
constexpr bool prime_test(Tp n) {
  if (n <= 1) { return false; }
  const int s = id61(n - 1);
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
  const int s = id61(n - 1);
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
constexpr int id41(Tp n) {
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
constexpr int id37(Tp n) {
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
namespace algo {
template <uint32_t MOD = 998244353>
  requires(MOD % 2 == 1 && MOD < (1u << 31))
class id10 : detail::modnum_base {
public:
  static constexpr uint32_t R1 = (-MOD) % MOD;
  static constexpr uint32_t R2 = -static_cast<uint64_t>(MOD) % MOD;
  static constexpr uint32_t R3 = detail::mod_mul(R1, R2, MOD);
  static constexpr uint32_t Nd = detail::id53(MOD);
  static constexpr bool IsPrime = detail::prime_test(MOD);
  constexpr id10() noexcept = default;
  template <detail::integer Tp>
  constexpr id10(Tp n) noexcept : value_{transform(n)} {}
  constexpr id10(bool b) noexcept : value_{from(b ? R1 : 0)} {}
  constexpr auto operator+=(id10 rhs) -> id10& {
    value_ += rhs.get() - MOD;
    value_ += (static_cast<int32_t>(value_) >> 31) & MOD;
    return *this;
  }
  constexpr auto operator-=(id10 rhs) -> id10& {
    value_ -= rhs.get();
    value_ += (static_cast<int32_t>(value_) >> 31) & MOD;
    return *this;
  }
  constexpr auto operator*=(id10 rhs) -> id10& {
    value_ = mult(get(), rhs.get());
    return *this;
  }
  constexpr auto operator/=(id10 rhs) -> id10& {
    return operator*=(rhs.inv());
  }
  constexpr auto operator++() -> id10& {
    return operator+=(from(R1));
  }
  constexpr auto operator--() -> id10& {
    return operator-=(from(R1));
  }
  constexpr auto operator++(int) -> id10 {
    const id10 res{*this};
    operator++();
    return res;
  }
  constexpr auto operator--(int) -> id10 {
    const id10 res{*this};
    operator--();
    return res;
  }
  constexpr auto operator+() const -> id10 { return *this; }
  constexpr auto operator-() const -> id10 {
    const uint32_t res = get() != 0 ? MOD - get() : 0;
    return from(res);
  }
  constexpr friend auto operator+(id10 lhs, id10 rhs)
      -> id10 {
    lhs += rhs;
    return lhs;
  }
  constexpr friend auto operator-(id10 lhs, id10 rhs)
      -> id10 {
    lhs -= rhs;
    return lhs;
  }
  constexpr friend auto operator*(id10 lhs, id10 rhs)
      -> id10 {
    lhs *= rhs;
    return lhs;
  }
  constexpr friend auto operator/(id10 lhs, id10 rhs)
      -> id10 {
    lhs /= rhs;
    return lhs;
  }
  constexpr friend bool operator==(id10 lhs,
                                   id10 rhs) {
    return lhs.get() == rhs.get();
  }
  constexpr uint32_t value() const { return reduce(value_); }
  constexpr uint32_t get() const { return value_; }
  static constexpr uint32_t mod() { return MOD; }
  static constexpr bool is_prime_mod() { return IsPrime; }
  constexpr auto inv() const -> id10 {
    if constexpr (IsPrime) {
      return pow(MOD - 2);
    } else {
      const uint32_t res = detail::inv_mod(get(), MOD);
      return from(mult(res, R3));
    }
  }
  template <detail::integer Tp>
  constexpr auto pow(Tp n) const -> id10 {
    id10 res{1};
    id10 mul{*this};
    while (n > 0) {
      if (n % 2 == 1) { res *= mul; }
      mul *= mul;
      n /= 2;
    }
    return res;
  }
  constexpr auto sqrt() const -> std::optional<id10>
    requires(IsPrime)
  {
    if (*this == 0 || *this == 1) { return {*this}; }
    if (pow((MOD - 1) / 2) == -1) { return std::nullopt; }
    constexpr id10 Z = detail::id12(MOD);
    constexpr uint32_t K = detail::id61(MOD - 1);
    constexpr uint32_t C = (MOD - 1) >> K;
    auto res = pow((C + 1) / 2);
    auto cur = pow(C);
    auto fac = Z.pow(C);
    for (uint32_t i = K - 1; i > 0 && cur != 1; --i) {
      const auto nfac = fac * fac;
      if (cur.pow(1 << (i - 1)) == -1) {
        res *= fac;
        cur *= nfac;
      }
      fac = nfac;
    }
    return {res};
  }
  template <detail::integer Tp>
  static constexpr auto from(Tp n) -> id10 {
    return std::bit_cast<id10>(static_cast<uint32_t>(n));
  }
  friend std::ostream& operator<<(std::ostream& os, id10 m) {
    os << m.value();
    return os;
  }
  static constexpr uint32_t reduce(uint32_t n) {
    const uint32_t q = n * Nd;
    const uint64_t r = detail::safe_mul(q, MOD);
    const uint32_t g = static_cast<uint32_t>(r >> 32);
    const uint32_t d = 0 - g;
    return d + ((static_cast<int32_t>(d) >> 31) & MOD);
  }
  static constexpr uint32_t mult(uint32_t x, uint32_t y) {
    const uint64_t prod = detail::safe_mul(x, y);
    const uint32_t l = static_cast<uint32_t>(prod);
    const uint32_t h = static_cast<uint32_t>(prod >> 32);
    const uint32_t q = l * Nd;
    const uint64_t r = detail::safe_mul(q, MOD);
    const uint32_t g = static_cast<uint32_t>(r >> 32);
    const uint32_t d = h - g;
    return d + ((static_cast<int32_t>(d) >> 31) & MOD);
  }
  static constexpr uint32_t transform(uint32_t n) { return mult(n, R2); }
  static constexpr uint32_t transform(int32_t n) {
    n %= static_cast<int32_t>(MOD);
    if (n < 0) { n += static_cast<int32_t>(MOD); }
    return mult(static_cast<uint32_t>(n), R2);
  }
  static constexpr uint32_t transform(uint64_t n) {
    return mult(static_cast<uint32_t>(n % MOD), R2);
  }
  static constexpr uint32_t transform(int64_t n) {
    n %= static_cast<int64_t>(MOD);
    if (n < 0) { n += static_cast<int64_t>(MOD); }
    return mult(static_cast<uint32_t>(n), R2);
  }
  static auto inv_table(int n) -> std::vector<id10>
    requires(IsPrime)
  {
    std::vector<id10> inv(n);
    if (n <= 1) [[unlikely]] { return inv; }
    inv[1] = 1;
    for (int i = 2; i < n; ++i) {
      inv[i] = id10(MOD - MOD / i) * inv[MOD % i];
    }
    return inv;
  }
private:
  uint32_t value_{0};
};
}
namespace algo::detail::simd {
template <uint32_t MOD = 998244353>
struct montgomery_modintx8 {
  using mint_type = id10<MOD>;
  static_assert(MOD % 2 == 1, "Modulus must be odd");
  __m256i v;
  montgomery_modintx8& operator+=(montgomery_modintx8 rhs) {
    v = mod_add(v, rhs.v);
    return *this;
  }
  montgomery_modintx8& operator-=(montgomery_modintx8 rhs) {
    v = mod_sub(v, rhs.v);
    return *this;
  }
  montgomery_modintx8& operator*=(montgomery_modintx8 rhs) {
    v = mod_mul(v, rhs.v);
    return *this;
  }
  friend auto operator+(montgomery_modintx8 d) -> montgomery_modintx8 {
    return d;
  }
  friend auto operator-(montgomery_modintx8 d) -> montgomery_modintx8 {
    d.v = id62<0b11111111>(d.v);
    d.v = normalize(d.v);
    return d;
  }
  friend auto operator+(montgomery_modintx8 lhs, montgomery_modintx8 rhs)
      -> montgomery_modintx8 {
    lhs += rhs;
    return lhs;
  }
  friend auto operator-(montgomery_modintx8 lhs, montgomery_modintx8 rhs)
      -> montgomery_modintx8 {
    lhs -= rhs;
    return lhs;
  }
  friend auto operator*(montgomery_modintx8 lhs, montgomery_modintx8 rhs)
      -> montgomery_modintx8 {
    lhs *= rhs;
    return lhs;
  }
  mint_type extract(int i) const {
    alignas(__m256i) mint_type buf[8];
    store_aligned(buf);
    return buf[i];
  }
  void insert(int i, mint_type x) {
    alignas(__m256i) mint_type buf[8];
    store_aligned(buf);
    buf[i] = x;
    load_aligned(buf);
  }
  void cutoff(int n) {
    const int32_t maskl[16]{-1, -1, -1, -1, -1, -1, -1, -1,
                            0, 0, 0, 0, 0, 0, 0, 0};
    const auto xmm =
        _mm256_loadu_si256(reinterpret_cast<const __m256i_u*>(maskl + 8 - n));
    v = _mm256_and_si256(v, xmm);
  }
  void load(const void* mem) {
    v = _mm256_loadu_si256(reinterpret_cast<const __m256i_u*>(mem));
  }
  void load_aligned(const void* mem) {
    v = _mm256_load_si256(reinterpret_cast<const __m256i*>(mem));
  }
  void store(void* mem) const {
    _mm256_storeu_si256(reinterpret_cast<__m256i_u*>(mem), v);
  }
  void store_aligned(void* mem) const {
    _mm256_store_si256(reinterpret_cast<__m256i*>(mem), v);
  }
  static __m256i normalize(__m256i A) {
    const auto md = _mm256_set1_epi32(MOD);
    const auto mask = _mm256_srai_epi32(A, 31);
    return _mm256_add_epi32(A, _mm256_and_si256(md, mask));
  }
  static __m256i mod_add(__m256i A, __m256i B) {
    const auto md = _mm256_set1_epi32(MOD);
    const auto d = _mm256_add_epi32(A, B);
    const auto r = _mm256_sub_epi32(d, md);
    return normalize(r);
  }
  static __m256i mod_sub(__m256i A, __m256i B) {
    const auto d = _mm256_sub_epi32(A, B);
    return normalize(d);
  }
  static __m256i mod_mul(__m256i A, __m256i B) {
    constexpr uint32_t Nd = mint_type::Nd;
    const auto md = _mm256_set1_epi32(MOD);
    const auto nd = _mm256_set1_epi32(Nd);
    const auto id27 = _mm256_mul_epu32(A, B);
    A = _mm256_srli_si256(A, 4);
    B = _mm256_srli_si256(B, 4);
    const auto id47 = _mm256_mul_epu32(A, B);
    const auto qlo = _mm256_mul_epu32(id27, nd);
    const auto qhi = _mm256_mul_epu32(id47, nd);
    const auto tmplo = _mm256_mul_epu32(qlo, md);
    const auto tmphi = _mm256_mul_epu32(qhi, md);
    const auto alo = _mm256_sub_epi32(id27, tmplo);
    const auto ahi = _mm256_sub_epi32(id47, tmphi);
    const auto tmpd = id60<_MM_SHUFFLE(3, 1, 3, 1)>(alo, ahi);
    const auto d = id51<_MM_SHUFFLE(3, 1, 2, 0)>(tmpd);
    return normalize(d);
  }
  static __m256i reduce(__m256i A) {
    constexpr uint32_t Nd = mint_type::Nd;
    const auto md = _mm256_set1_epi32(MOD);
    const auto nd = _mm256_set1_epi32(Nd);
    const auto qlo = _mm256_mul_epu32(A, nd);
    A = _mm256_srli_si256(A, 4);
    const auto qhi = _mm256_mul_epu32(A, nd);
    const auto prodlo = _mm256_mul_epu32(qlo, md);
    const auto prodhi = _mm256_mul_epu32(qhi, md);
    const auto tmplo = _mm256_sub_epi32(_mm256_setzero_si256(), prodlo);
    const auto tmphi = _mm256_sub_epi32(_mm256_setzero_si256(), prodhi);
    const auto tmpd = id60<_MM_SHUFFLE(3, 1, 3, 1)>(tmplo, tmphi);
    const auto d = id51<_MM_SHUFFLE(3, 1, 2, 0)>(tmpd);
    return normalize(d);
  }
  static __m256i transform(__m256i A) {
    constexpr uint32_t R2 = mint_type::R2;
    const auto rsq = _mm256_set1_epi32(R2);
    return mod_mul(A, rsq);
  }
};
}
namespace algo::detail::simd {
template <uint32_t MOD>
struct dif_info {
  using mint_type = id10<MOD>;
  using mintx8_type = montgomery_modintx8<MOD>;
  static constexpr uint32_t Cap = id61(MOD - 1);
  static constexpr uint32_t Cof = (MOD - 1) >> Cap;
  static constexpr uint32_t Gen = id14(MOD);
  std::array<mintx8_type, Cap + 1> rootx8;
  std::array<mintx8_type, Cap + 1> stepx8;
  dif_info() noexcept {
    auto rot = mint_type(Gen).pow(Cof);
    for (int i = Cap + 1; i-- > 0;) {
      mint_type f = 1;
      alignas(__m256i) std::array<mint_type, 8> buf;
      for (int j = 0; j < 8; ++j) {
        buf[j] = f;
        f *= rot;
      }
      rootx8[i].load_aligned(buf.data());
      buf.fill(f);
      stepx8[i].load_aligned(buf.data());
      rot *= rot;
    }
  }
};
template <uint32_t MOD>
struct dit_info {
  using mint_type = id10<MOD>;
  using mintx8_type = montgomery_modintx8<MOD>;
  static constexpr uint32_t Cap = id61(MOD - 1);
  static constexpr uint32_t Cof = (MOD - 1) >> Cap;
  static constexpr uint32_t Gen = id14(MOD);
  std::array<mintx8_type, Cap + 1> irootx8;
  std::array<mintx8_type, Cap + 1> istepx8;
  dit_info() noexcept {
    auto rot = mint_type(Gen).pow(Cof).inv();
    for (int i = Cap + 1; i-- > 0;) {
      mint_type f = 1;
      alignas(__m256i) std::array<mint_type, 8> buf;
      for (int j = 0; j < 8; ++j) {
        buf[j] = f;
        f *= rot;
      }
      irootx8[i].load_aligned(buf.data());
      buf.fill(f);
      istepx8[i].load_aligned(buf.data());
      rot *= rot;
    }
  }
};
template <uint32_t MOD = 998244353>
void id45(std::span<montgomery_modintx8<MOD>> out) {
  static_assert(MOD % 8 == 1, "Bad modulus for NTT");
  using mint_type = id10<MOD>;
  using mintx8_type = montgomery_modintx8<MOD>;
  static const dif_info<MOD> info{};
  const uint32_t id25 =
      mint_type(info.Gen).pow(0 * (info.Cof << (info.Cap - 3))).get();
  const uint32_t id65 =
      mint_type(info.Gen).pow(1 * (info.Cof << (info.Cap - 3))).get();
  const uint32_t id32 =
      mint_type(info.Gen).pow(2 * (info.Cof << (info.Cap - 3))).get();
  const uint32_t id35 =
      mint_type(info.Gen).pow(3 * (info.Cof << (info.Cap - 3))).get();
  const mintx8_type id11{_mm256_set1_epi32(id32)};
  const int n = static_cast<int>(out.size());
  const int k = id36(n) + 3;
  assume(n > 0);
  for (int h = 0; h + 4 < k; h += 2) {
    const int m = 1 << (k - h - 3);
    assume(m > 0);
    assume(m % 4 == 0);
    const auto id48 = info.rootx8[k - h];
    const auto id43 = id48 * id48;
    const auto id38 = id43 * id48;
    const auto id20 = info.stepx8[k - h];
    const auto id55 = id20 * id20;
    const auto id26 = id55 * id20;
    for (int j = 0; j < n; j += m) {
      auto id18 = id43;
      auto id23 = id48;
      auto id6 = id38;
      for (int i = 0; i < m / 4; ++i) {
        const auto x0 = out[i + j + m / 4 * 0];
        const auto x1 = out[i + j + m / 4 * 1];
        const auto x2 = out[i + j + m / 4 * 2];
        const auto x3 = out[i + j + m / 4 * 3];
        const auto id29 = x0 + x2;
        const auto id67 = x0 - x2;
        const auto id58 = x1 + x3;
        const auto id64 = (x1 - x3) * id11;
        const auto e0 = id29 + id58;
        const auto e1 = id29 - id58;
        const auto e2 = id67 + id64;
        const auto e3 = id67 - id64;
        out[i + j + m / 4 * 0] = e0;
        out[i + j + m / 4 * 1] = e1 * id18;
        out[i + j + m / 4 * 2] = e2 * id23;
        out[i + j + m / 4 * 3] = e3 * id6;
        id18 *= id55;
        id23 *= id20;
        id6 *= id26;
      }
    }
  }
  if (k % 2 == 0) {
    const auto id17 = info.rootx8[4];
    for (int j = 0; j < n; j += 2) {
      const auto x0 = out[j + 0];
      const auto x1 = out[j + 1];
      out[j + 0] = x0 + x1;
      out[j + 1] = (x0 - x1) * id17;
    }
  }
  {
    const auto id49 = _mm256_set_epi32(id32, id32, id25, id25, id25,
                                       id25, id25, id25);
    const auto id31 = _mm256_set_epi32(id35, id25, id65, id25, id32,
                                       id25, id25, id25);
    for (int j = 0; j < n; ++j) {
      const auto x1 = out[j].v;
      const auto y1 = id7<_MM_SHUFFLE(1, 0, 3, 2)>(x1);
      const auto z1 = id62<0b11110000>(x1);
      const auto t1 = mintx8_type::normalize(z1);
      const auto w1 = mintx8_type::mod_add(y1, t1);
      const auto x2 = mintx8_type::mod_mul(w1, id49);
      const auto y2 = id51<_MM_SHUFFLE(1, 0, 3, 2)>(x2);
      const auto z2 = id62<0b11001100>(x2);
      const auto t2 = mintx8_type::normalize(z2);
      const auto w2 = mintx8_type::mod_add(y2, t2);
      const auto x3 = mintx8_type::mod_mul(w2, id31);
      const auto y3 = id51<_MM_SHUFFLE(2, 3, 0, 1)>(x3);
      const auto z3 = id62<0b10101010>(x3);
      const auto t3 = mintx8_type::normalize(z3);
      const auto w3 = mintx8_type::mod_add(y3, t3);
      out[j].v = w3;
    }
  }
}
template <uint32_t MOD = 998244353>
void id56(std::span<montgomery_modintx8<MOD>> out) {
  static_assert(MOD % 8 == 1, "Bad modulus for NTT");
  using mint_type = id10<MOD>;
  using mintx8_type = montgomery_modintx8<MOD>;
  static const dit_info<MOD> info{};
  const uint32_t id25 =
      mint_type(info.Gen).pow(0 * (info.Cof << (info.Cap - 3))).inv().get();
  const uint32_t id65 =
      mint_type(info.Gen).pow(1 * (info.Cof << (info.Cap - 3))).inv().get();
  const uint32_t id32 =
      mint_type(info.Gen).pow(2 * (info.Cof << (info.Cap - 3))).inv().get();
  const uint32_t id35 =
      mint_type(info.Gen).pow(3 * (info.Cof << (info.Cap - 3))).inv().get();
  const mintx8_type id11{_mm256_set1_epi32(id32)};
  const int n = static_cast<int>(out.size());
  const int k = id36(n) + 3;
  assume(n > 0);
  {
    const auto id49 = _mm256_set_epi32(id32, id25, id25, id25, id32,
                                       id25, id25, id25);
    const auto id31 = _mm256_set_epi32(id35, id32, id65, id25, id25,
                                       id25, id25, id25);
    for (int j = 0; j < n; ++j) {
      const auto x1 = out[j].v;
      const auto y1 = id51<_MM_SHUFFLE(2, 3, 0, 1)>(x1);
      const auto z1 = id62<0b10101010>(x1);
      const auto t1 = mintx8_type::normalize(z1);
      const auto w1 = mintx8_type::mod_add(y1, t1);
      const auto x2 = mintx8_type::mod_mul(w1, id49);
      const auto y2 = id51<_MM_SHUFFLE(1, 0, 3, 2)>(x2);
      const auto z2 = id62<0b11001100>(x2);
      const auto t2 = mintx8_type::normalize(z2);
      const auto w2 = mintx8_type::mod_add(y2, t2);
      const auto x3 = mintx8_type::mod_mul(w2, id31);
      const auto y3 = id7<_MM_SHUFFLE(1, 0, 3, 2)>(x3);
      const auto z3 = id62<0b11110000>(x3);
      const auto t3 = mintx8_type::normalize(z3);
      const auto w3 = mintx8_type::mod_add(y3, t3);
      out[j].v = w3;
    }
  }
  if (k % 2 == 0) {
    const auto id17 = info.irootx8[4];
    for (int j = 0; j < n; j += 2) {
      const auto x0 = out[j + 0];
      const auto x1 = out[j + 1] * id17;
      out[j + 0] = x0 + x1;
      out[j + 1] = x0 - x1;
    }
  }
  for (int h = 6 - (k % 2); h <= k; h += 2) {
    const int m = 1 << (h - 3);
    assume(m > 0);
    assume(m % 4 == 0);
    const auto id48 = info.irootx8[h];
    const auto id43 = id48 * id48;
    const auto id38 = id43 * id48;
    const auto id20 = info.istepx8[h];
    const auto id55 = id20 * id20;
    const auto id26 = id55 * id20;
    for (int j = 0; j < n; j += m) {
      auto id18 = id43;
      auto id23 = id48;
      auto id6 = id38;
      for (int i = 0; i < m / 4; ++i) {
        const auto x0 = out[i + j + m / 4 * 0];
        const auto x1 = out[i + j + m / 4 * 1] * id18;
        const auto x2 = out[i + j + m / 4 * 2] * id23;
        const auto x3 = out[i + j + m / 4 * 3] * id6;
        const auto id50 = x0 + x1;
        const auto id16 = x0 - x1;
        const auto id2 = x2 + x3;
        const auto id57 = (x2 - x3) * id11;
        out[i + j + m / 4 * 0] = id50 + id2;
        out[i + j + m / 4 * 1] = id16 + id57;
        out[i + j + m / 4 * 2] = id50 - id2;
        out[i + j + m / 4 * 3] = id16 - id57;
        id18 *= id55;
        id23 *= id20;
        id6 *= id26;
      }
    }
  }
}
}
namespace algo {
template <uint32_t MOD = 998244353>
  requires(detail::prime_test(MOD) && MOD % 8 == 1)
class id1 {
  using mint_type = id10<MOD>;
  using mintx8_type = detail::simd::montgomery_modintx8<MOD>;
public:
  id1() noexcept = default;
  id1(const std::vector<mint_type>& vec) noexcept
      : c_((vec.size() + 7) / 8) {
    const int n = static_cast<int>(vec.size());
    detail::assume(n >= 0);
    alignas(__m256i) std::array<uint32_t, 8> buf;
    for (int i = 0; i < n / 8; ++i) {
      for (int j = 0; j < 8; ++j) { buf[j] = vec[i * 8 + j].get(); }
      c_[i].load_aligned(buf.data());
    }
    if (n % 8 != 0) {
      buf.fill(0);
      for (int j = 0; j < n % 8; ++j) { buf[j] = vec[(n / 8) * 8 + j].get(); }
      c_[n / 8].load_aligned(buf.data());
    }
  }
  id1(std::vector<mintx8_type> vec) noexcept : c_{std::move(vec)} {}
  id1& operator+=(const id1& rhs) {
    if (c_.size() < rhs.c_.size()) { c_.resize(rhs.c_.size()); }
    for (int i = 0; i < rhs.size_8(); ++i) { c_[i] += rhs.c_[i]; }
    return *this;
  }
  id1& operator-=(const id1& rhs) {
    if (c_.size() < rhs.c_.size()) { c_.resize(rhs.c_.size()); }
    for (int i = 0; i < rhs.size_8(); ++i) { c_[i] -= rhs.c_[i]; }
    return *this;
  }
  id1& operator*=(id1 rhs) {
    if (!empty() && !rhs.empty()) [[likely]] {
      const int id52 = size_8();
      const int id66 = rhs.size_8();
      const int id0 = id52 + id66;
      const int id8 = detail::id22(id0);
      c_.resize(id8);
      rhs.c_.resize(id8);
      detail::simd::id45(std::span{c_});
      detail::simd::id45(std::span{rhs.c_});
      for (int i = 0; i < id8; ++i) { c_[i] *= rhs.c_[i]; }
      detail::simd::id56(std::span{c_});
      const auto ipoints = mint_type(id8 * 8).inv();
      const mintx8_type id13{_mm256_set1_epi32(ipoints.get())};
      c_.resize(id0);
      for (auto& f : c_) { f *= id13; }
    } else {
      if (c_.capacity() < rhs.c_.capacity()) { c_.swap(rhs.c_); }
      c_.clear();
    }
    return *this;
  }
  id1& operator*=(mint_type rhs) {
    const mintx8_type id28{_mm256_set1_epi32(rhs.get())};
    for (auto& f : c_) { f *= id28; }
    return *this;
  }
  mint_type coef(int i) const {
    if (0 <= i && i < size()) { return c_[i / 8].extract(i % 8); }
    return 0;
  }
  friend auto operator+(id1 fx) -> id1 { return fx; }
  friend auto operator-(id1 fx) -> id1 {
    for (auto& f : fx.c_) { f = -f; }
    return fx;
  }
  friend auto operator+(id1 lhs, const id1& rhs)
      -> id1 {
    lhs += rhs;
    return lhs;
  }
  friend auto operator-(id1 lhs, const id1& rhs)
      -> id1 {
    lhs -= rhs;
    return lhs;
  }
  friend auto operator*(id1 lhs, id1 rhs)
      -> id1 {
    lhs *= std::move(rhs);
    return lhs;
  }
  friend auto operator*(id1 lhs, mint_type rhs) -> id1 {
    lhs *= rhs;
    return lhs;
  }
  friend auto operator*(mint_type lhs, id1 rhs) -> id1 {
    rhs *= lhs;
    return rhs;
  }
  id1 diff_x() const {
    auto res{*this};
    res.inplace_diff_x();
    return res;
  }
  id1& inplace_diff_x() {
    mintx8_type fac{_mm256_setr_epi32(0, 1, 2, 3, 4, 5, 6, 7)};
    const mintx8_type step{_mm256_set1_epi32(mint_type(8).get())};
    fac.v = mintx8_type::transform(fac.v);
    for (auto& f : c_) {
      f *= fac;
      fac += step;
    }
    return *this;
  }
  id1 inv(int n) const {
    const int id0 = std::max(1, detail::id22(n) / 8);
    std::vector<mintx8_type> q_x(id0);
    {
      alignas(__m256i) std::array<mint_type, 8> a0;
      alignas(__m256i) std::array<mint_type, 8> b0;
      c_.front().store_aligned(a0.data());
      const auto id15 = a0.front().inv();
      b0.front() = id15;
      for (int i = 1; i < 8; ++i) {
        b0[i] = 0;
        for (int j = 0; j < i; ++j) { b0[i] -= b0[j] * a0[i - j]; }
        b0[i] *= id15;
      }
      q_x.front().load_aligned(b0.data());
    }
    const mintx8_type id19{_mm256_set1_epi32(mint_type(4).inv().get())};
    mintx8_type id21{_mm256_set1_epi32(mint_type(64).inv().get())};
    for (int k = 1; k < id0; k *= 2) {
      id21 *= id19;
      const int cur_k = k;
      const int id30 = k * 2;
      std::vector<mintx8_type> buf_fx(id30);
      std::vector<mintx8_type> id9(id30);
      std::copy_n(c_.begin(), std::min(size_8(), id30), buf_fx.begin());
      std::copy_n(q_x.begin(), k, id9.begin());
      detail::simd::id45(std::span{buf_fx});
      detail::simd::id45(std::span{id9});
      for (int i = 0; i < id30; ++i) { buf_fx[i] *= id9[i]; }
      detail::simd::id56(std::span{buf_fx});
      std::fill_n(buf_fx.begin(), cur_k, mintx8_type{});
      for (int i = cur_k; i < id30; ++i) { buf_fx[i] *= id21; }
      detail::simd::id45(std::span{buf_fx});
      for (int i = 0; i < id30; ++i) { id9[i] *= -buf_fx[i]; }
      detail::simd::id56(std::span{id9});
      std::copy_n(id9.begin() + cur_k, cur_k, q_x.begin() + cur_k);
    }
    id1 res{std::move(q_x)};
    res.resize(n);
    return res;
  }
  id1 exp(int n) const {
    const int id0 = std::max(1, detail::id22(n) / 8);
    std::vector<mintx8_type> f_x(id0);
    std::vector<mintx8_type> q_x(id0);
    std::vector<mintx8_type> r_x(id0);
    const auto invs = mint_type::inv_table(8 * id0);
    {
      mintx8_type fac{_mm256_setr_epi32(0, 1, 2, 3, 4, 5, 6, 7)};
      const mintx8_type step{_mm256_set1_epi32(mint_type(8).get())};
      fac.v = mintx8_type::transform(fac.v);
      for (int i = 0; i < std::min(size_8(), id0); ++i) {
        f_x[i] = c_[i] * fac;
        fac += step;
      }
    }
    {
      alignas(__m256i) std::array<mint_type, 8> f0;
      alignas(__m256i) std::array<mint_type, 8> q0;
      alignas(__m256i) std::array<mint_type, 8> r0;
      f_x.front().store_aligned(f0.data());
      q0.front() = 1;
      r0.front() = 1;
      for (int i = 1; i < 8; ++i) {
        q0[i] = 0;
        for (int j = 0; j < i; ++j) { q0[i] += q0[j] * f0[i - j]; }
        q0[i] *= invs[i];
        r0[i] = 0;
        for (int j = 0; j < i; ++j) { r0[i] -= r0[j] * q0[i - j]; }
      }
      q_x.front().load_aligned(q0.data());
      r_x.front().load_aligned(r0.data());
    }
    const mintx8_type id39{_mm256_set1_epi32(mint_type(2).inv().get())};
    mintx8_type id21{_mm256_set1_epi32(mint_type(8).inv().get())};
    for (int k = 1; k < id0; k *= 2) {
      const int cur_k = k;
      const int id30 = k * 2;
      std::vector<mintx8_type> buf_fx(id30);
      std::vector<mintx8_type> id9(id30);
      std::vector<mintx8_type> buf_rx(id30);
      std::copy_n(f_x.begin(), cur_k, buf_fx.begin());
      std::copy_n(q_x.begin(), cur_k, id9.begin());
      std::copy_n(r_x.begin(), cur_k, buf_rx.begin());
      detail::simd::id45(
          std::span{buf_fx.begin(), buf_fx.begin() + cur_k});
      detail::simd::id45(
          std::span{id9.begin(), id9.begin() + id30});
      detail::simd::id45(
          std::span{buf_rx.begin(), buf_rx.begin() + id30});
      for (int i = 0; i < cur_k; ++i) { buf_fx[i] *= id9[i]; }
      detail::simd::id56(
          std::span{buf_fx.begin(), buf_fx.begin() + cur_k});
      {
        mintx8_type fac{_mm256_setr_epi32(0, 1, 2, 3, 4, 5, 6, 7)};
        const mintx8_type step{_mm256_set1_epi32(mint_type(8).get())};
        fac.v = mintx8_type::transform(fac.v);
        for (int i = 0; i < cur_k; ++i) {
          buf_fx[i] *= id21;
          buf_fx[i] -= fac * q_x[i];
          fac += step;
        }
      }
      std::copy_n(buf_fx.begin(), cur_k, buf_fx.begin() + cur_k);
      std::fill_n(buf_fx.begin(), cur_k, mintx8_type{});
      detail::simd::id45(std::span{buf_fx});
      for (int i = 0; i < id30; ++i) { buf_fx[i] *= buf_rx[i]; }
      detail::simd::id56(std::span{buf_fx});
      std::fill_n(buf_fx.begin(), cur_k, mintx8_type{});
      {
        id21 *= id39;
        mintx8_type buf;
        for (int i = cur_k; i < id30; ++i) {
          buf_fx[i] *= id21;
          buf_fx[i] += f_x[i];
          buf.load(&invs[8 * i]);
          buf_fx[i] *= buf;
        }
      }
      detail::simd::id45(std::span{buf_fx});
      for (int i = 0; i < id30; ++i) { id9[i] *= buf_fx[i]; }
      detail::simd::id56(std::span{id9});
      for (int i = cur_k; i < id30; ++i) { id9[i] *= id21; }
      std::copy_n(id9.begin() + cur_k, cur_k, q_x.begin() + cur_k);
      if (id30 != id0) {
        std::copy_n(q_x.begin(), cur_k, id9.begin());
        detail::simd::id45(std::span{id9});
        for (int i = 0; i < id30; ++i) { id9[i] *= buf_rx[i]; }
        detail::simd::id56(std::span{id9});
        std::fill_n(id9.begin(), cur_k, mintx8_type{});
        for (int i = cur_k; i < id30; ++i) { id9[i] *= id21; }
        detail::simd::id45(std::span{id9});
        for (int i = 0; i < id30; ++i) { buf_rx[i] *= -id9[i]; }
        detail::simd::id56(std::span{buf_rx});
        for (int i = cur_k; i < id30; ++i) { buf_rx[i] *= id21; }
        std::copy_n(buf_rx.begin() + cur_k, cur_k, r_x.begin() + cur_k);
      }
    }
    id1 res{std::move(q_x)};
    res.resize(n);
    return res;
  }
  id1 log(int n) const {
    auto res{*this};
    res.resize(n);
    {
      mintx8_type fac{_mm256_setr_epi32(0, 1, 2, 3, 4, 5, 6, 7)};
      const mintx8_type step{_mm256_set1_epi32(mint_type(8).get())};
      fac.v = mintx8_type::transform(fac.v);
      for (int i = 0; i < res.size_8(); ++i) {
        res.c_[i] *= fac;
        fac += step;
      }
    }
    res *= inv(n);
    res.resize(n);
    {
      const auto invs = mint_type::inv_table(res.size());
      mintx8_type buf;
      for (int i = 0; i < res.size_8(); ++i) {
        buf.load(&invs[8 * i]);
        res.c_[i] *= buf;
      }
    }
    return res;
  }
  void resize(int n) {
    detail::assume(n >= 0);
    const int id0 = (n + 7) / 8;
    c_.resize(id0);
    if (n % 8 != 0) { c_.back().cutoff(n % 8); }
  }
  int size() const { return size_8() * 8; }
  bool empty() const { return c_.empty(); }
  std::vector<mint_type> to_vector() const {
    std::vector<mint_type> res(size());
    alignas(__m256i) std::array<uint32_t, 8> buf;
    for (int i = 0; i < size_8(); ++i) {
      c_[i].store_aligned(buf.data());
      for (int j = 0; j < 8; ++j) { res[i * 8 + j] = mint_type::from(buf[j]); }
    }
    while (!res.empty() && res.back() == mint_type(0)) { res.pop_back(); }
    return res;
  }
  std::vector<mintx8_type> data() const& { return c_; }
  std::vector<mintx8_type> data() && { return std::move(c_); }
private:
  int size_8() const { return static_cast<int>(c_.size()); }
  std::vector<mintx8_type> c_;
};
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
using slong = int64_t;
using ulong = uint64_t;
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
using mint = algo::id10<>;
using poly = algo::id1<>;
const algo::factorial<mint> fac(MAXN);
const auto invs = mint::inv_table(MAXN);
}
void solve() noexcept {
  int n;
  cin >> n;
  vector<mint> dp(n);
  vector<mint> dp2(n + 1);
  vector<mint> f(n), g(n);
  dp[0] = dp2[1] = 1;
  const int mid = (n - 1) >> 1;
  for (int i = 1; i < n; ++i) {
    mint c = invs[i];
    mint d = dp2[i];
    if (i >= mid) { d -= dp2[i - mid]; }
    dp[i] = c * d;
    dp2[i + 1] = dp2[i] + dp[i];
  }
  for (int i = n - mid - 1; i < n - 1; ++i) {
    auto c = dp2[i];
    if (i >= mid) { c -= dp2[i - mid]; }
    f[i] = c * fac.fact(n - i - 2) * invs[i];
  }
  for (int i = 0; i < n; ++i) { g[i] = fac.inv_fact(i); }
  auto coef = (poly(f) * poly(g)).to_vector();
  coef.resize(n);
  vector<mint> ans(n);
  for (int i = 1; i < n; ++i) {
    ans[i] = i * fac.fact(n - i - 1) * coef[n - i - 1];
  }
  ans[0] = ans[1];
  for (int i = 0; i < n; ++i) { cout << ans[i] << " \n"[i + 1 == n]; }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cout.precision(15);
  std::fixed(std::cout);
  solve();
  return 0;
}