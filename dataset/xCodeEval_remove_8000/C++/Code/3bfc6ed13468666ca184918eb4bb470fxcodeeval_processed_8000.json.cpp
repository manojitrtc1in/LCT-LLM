












namespace dbg {

}
namespace algo {
namespace detail {
template <typename Tp>
concept integer = std::integral<Tp> && !std::same_as<Tp, bool>;
template <typename Tp>
concept signed_integer = integer<Tp> && (Tp(-1) < Tp(0));
template <typename Tp>
concept unsigned_integer = integer<Tp> && (Tp(-1) > Tp(0));
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
template <dword_fittable Tp>
constexpr Tp
sqrt(Tp n) {
  typedef safe_mul_t<Tp> wide_t;
  int p = 32 - __builtin_clz(n);
  Tp ans = p & 0x01;
  for (p >>= 1, p &= ~1u; p >= 0; --p) {
    ans <<= 1;
    if (static_cast<wide_t>(ans + 1) * (ans + 1) <= (n >> (p << 1))) {
      ans |= 1;
    }
  }
  return ans;
}
template <qword_fittable Tp>
constexpr Tp
sqrt(Tp n) {
  typedef safe_mul_t<Tp> wide_t;
  int p = 64 - __builtin_clzll(n);
  Tp ans = p & 0x01;
  for (p >>= 1, p &= ~1u; p >= 0; --p) {
    ans <<= 1;
    if (static_cast<wide_t>(ans + 1) * (ans + 1) <= (n >> (p << 1))) {
      ans |= 1;
    }
  }
  return ans;
}
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
assume(bool expr) noexcept {
  if (!expr) unreachable();
}
}
}
namespace algo {
namespace detail {
template <integer Tp>
constexpr Tp
id10(Tp x, Tp y, Tp m) {
  assume(0 <= x && x < m);
  assume(0 <= y && y < m);
  return static_cast<safe_mul_t<std::make_unsigned_t<Tp>>>(x) * y % m;
}
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
id23(Tp n) {
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
constexpr std::make_signed_t<std::common_type_t<Tp, int>>
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
  if (cnt & 0x01) { return -1; }
  return 1;
}
template <signed_integer Tp>
constexpr std::pair<Tp, Tp>
id35(Tp a, Tp b) {
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
id30(Tp a, Up b, Tp m) {
  Tp ans = 1, mul = a;
  const Tp mod = m;
  std::make_unsigned_t<Up> pw = b;
  if ((mul %= mod) < 0) mul += mod;
  while (pw) {
    if (pw & 0x01) { ans = id10(ans, mul, mod); }
    mul = id10(mul, mul, mod);
    pw >>= 1;
  }
  return ans;
}
}
}
namespace algo {
namespace detail {
template <signed_integer Tp>
constexpr Tp
inv_mod(Tp a, Tp m) {
  auto&& [x, _] = id35(a, m);
  if ((x %= m) < 0) { x += m; }
  return x;
}
template <integer Tp>
std::optional<Tp>
id18(Tp a, Tp b, Tp m) {
  Tp a0 = a, b0 = b;
  const Tp mod = m;
  if ((a0 %= mod) < 0) { a0 += mod; }
  if ((b0 %= mod) < 0) { b0 += mod; }
  const Tp n = sqrt(mod);
  assume(a0 >= 0 && a0 < mod);
  const Tp an = id30(a0, n, mod);
  std::unordered_map<Tp, Tp> f2;
  for (Tp q = 0, now = b0; q <= n; ++q) {
    f2[now] = q;
    now = id10(now, a0, mod);
  }
  for (Tp p = 1, cur = 1; p <= n; ++p) {
    cur = id10(cur, an, mod);
    if (f2.contains(cur)) { return std::optional(n * p - f2[cur]); }
  }
  return std::nullopt;
}
template <integer Tp>
constexpr std::optional<Tp>
primitive_root(Tp n, Tp phi) {
  Tp phi_n = phi;
  std::array<Tp, 23> divs{};
  int cnt = 0;
  if (!(phi_n & 0x01)) {
    divs[cnt++] = 2;
    do { phi_n >>= 1; } while (!(phi_n & 0x01));
  }
  for (Tp i = 3; i * i <= phi_n; i += 2) {
    if (Tp x = phi_n / i; phi_n - x * i == 0) {
      divs[cnt++] = i;
      do { phi_n = x, x /= i; } while (phi_n - x * i == 0);
    }
  }
  if (phi_n > 1) { divs[cnt++] = phi_n; }
  const auto first = divs.begin();
  const auto last = divs.begin() + cnt;
  for (Tp g = 1; g < n; ++g) {
    const auto check = std::find_if(
        first, last, [=](Tp p) { return id30(g, phi / p, n) == 1; });
    if (check == last) { return std::optional(g); }
  }
  return n == 1 ? std::optional(1) : std::nullopt;
}
template <integer Tp>
std::optional<Tp>
id17(Tp a, Tp b, Tp n) noexcept {
  const Tp a0 = a, b0 = b, n0 = n;
  const Tp g = primitive_root(n0, n0 - 1).value();
  const Tp ga = id30(g, a0, n0);
  std::optional y = id18(ga, b0, n0);
  return y.has_value() ? std::optional(id30(g, y.value(), n0))
                       : std::nullopt;
}
}
}
namespace algo {
namespace detail {
template <dword_fittable Tp>
constexpr int
id33(Tp n) {
  return __builtin_clz(n);
}
template <qword_fittable Tp>
constexpr int
id33(Tp n) {
  return __builtin_clzll(n);
}
template <dword_fittable Tp>
constexpr int
id52(Tp n) {
  return __builtin_ctz(n);
}
template <qword_fittable Tp>
constexpr int
id52(Tp n) {
  return __builtin_ctzll(n);
}
template <dword_fittable Tp>
constexpr int
id50(Tp n) {
  return __builtin_ffs(n) - 1;
}
template <qword_fittable Tp>
constexpr int
id50(Tp n) {
  return __builtin_ffsll(n) - 1;
}
template <dword_fittable Tp>
constexpr int
bit_width(Tp n) {
  return 32 - id33(n);
}
template <qword_fittable Tp>
constexpr int
bit_width(Tp n) {
  return 64 - id33(n);
}
template <dword_fittable Tp>
constexpr Tp
bit_floor(Tp n) {
  return 1u << (31 - id33(n));
}
template <qword_fittable Tp>
constexpr Tp
bit_floor(Tp n) {
  return 1ull << (63 - id33(n));
}
template <integer Tp>
constexpr Tp
id0(Tp n) {
  if (n == 0 || n == 1) { return 1; }
  return bit_floor(n - 1) << 1;
}
template <dword_fittable Tp>
constexpr int
id43(Tp n) {
  return 31 - id33(n);
}
template <qword_fittable Tp>
constexpr int
id43(Tp n) {
  return 63 - id33(n);
}
template <integer Tp>
constexpr int
id44(Tp n) {
  if (n == 0 || n == 1) { return 0; }
  return id43(n - 1) + 1;
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
  const int s = id52(n - 1);
  const Tp d = (n - 1) >> s;
  constexpr Tp primes[] = {2, 3, 5, 7};
  for (const auto &p : primes) {
    Tp x = id30(p, d, n);
    bool good = x == n - 1 || x == 1;
    for (int r = 1; r < s; ++r) {
      x = id10(x, x, n);
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
  const int s = id52(n - 1);
  const Tp d = (n - 1) >> s;
  constexpr Tp primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
  for (const auto &p : primes) {
    Tp x = id30(p, d, n);
    bool good = x == n - 1 || x == 1;
    for (int r = 1; r < s; ++r) {
      x = id10(x, x, n);
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
std::vector<int>
id39(int n) noexcept {
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
template <integer Tp>
std::vector<Tp>
id15(Tp n) noexcept {
  std::vector<Tp> phi(n + 1);
  iota(phi.begin(), phi.end(), 0);
  for (Tp i = 2; i <= n; ++i) {
    if (phi[i] == i) {
      for (Tp j = i; j <= n; j += i) { phi[j] -= phi[j] / i; }
    }
  }
  return phi;
}
std::vector<int>
id2(int n) noexcept {
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
template <int MOD, bool IsPrime = detail::prime_test(MOD)>
struct modint {
  constexpr modint() = default;
  template <detail::integer Tp>
  constexpr modint(Tp x) : value_(static_cast<int>(x % MOD)) {
    if constexpr (std::is_signed_v<Tp>) { value_ += (value_ >> 31) & MOD; }
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
    detail::assume(0 <= val() && val() < MOD);
    detail::assume(0 <= rhs.val() && rhs.val() < MOD);
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
  constexpr int
  val() const {
    return value_;
  }
  constexpr modint
  inv() const requires(IsPrime) {
    assert(val() != 0);
    return pow(MOD - 2);
  }
  constexpr modint
  inv() const requires(!IsPrime) {
    const auto [res, g] = detail::id35(val(), MOD);
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
    for (int i = 2; i <= val(); ++i) { res *= from(i); }
    return res;
  }
  friend std::ostream &
  operator<<(std::ostream &os, const modint &mt) {
    os << mt.val();
    return os;
  }
  constexpr static int
  mod() {
    return MOD;
  }
  template <detail::integer Tp>
  constexpr static modint
  from(Tp x) {
    assert(0 <= x && x < MOD);
    detail::assume(0 <= x && x < MOD);
    return modint(x);
  }
private:
  int value_{0};
};
}
namespace algo {
namespace detail {
namespace fft {
namespace meta {
  template <int MOD>
  constexpr int id20 = inv_mod<int64_t>(MOD, 0x100000000);
  template <int MOD>
  constexpr int id31 = -static_cast<uint64_t>(MOD) % MOD;
}
static inline __m256i
id6(__m256i A, __m256i B, __m256i M, __m256i id19) {
  const __m256i id13 = _mm256_mul_epu32(A, B);
  const __m256i id40 =
      _mm256_mul_epu32(_mm256_srli_si256(A, 4), _mm256_srli_si256(B, 4));
  const __m256i qlo = _mm256_mul_epu32(id13, id19);
  const __m256i qhi = _mm256_mul_epu32(id40, id19);
  const __m256i tmplo = _mm256_mul_epu32(qlo, M);
  const __m256i tmphi = _mm256_mul_epu32(qhi, M);
  const __m256i alo = _mm256_sub_epi32(id13, tmplo);
  const __m256i ahi = _mm256_sub_epi32(id40, tmphi);
  const __m256 tmpd =
      _mm256_shuffle_ps(_mm256_castsi256_ps(alo), _mm256_castsi256_ps(ahi),
                        _MM_SHUFFLE(3, 1, 3, 1));
  const __m256i d =
      _mm256_castps_si256(_mm256_permute_ps(tmpd, _MM_SHUFFLE(3, 1, 2, 0)));
  return _mm256_add_epi32(d, _mm256_and_si256(_mm256_srai_epi32(d, 31), M));
}
static inline __m256i
id46(__m256i A, __m256i M, __m256i id19) {
  const __m256i qlo = _mm256_mul_epu32(A, id19);
  const __m256i qhi = _mm256_mul_epu32(_mm256_srli_si256(A, 4), id19);
  const __m256i prodlo = _mm256_mul_epu32(qlo, M);
  const __m256i prodhi = _mm256_mul_epu32(qhi, M);
  const __m256i tmplo = _mm256_sub_epi32(_mm256_setzero_si256(), prodlo);
  const __m256i tmphi = _mm256_sub_epi32(_mm256_setzero_si256(), prodhi);
  const __m256 tmpd =
      _mm256_shuffle_ps(_mm256_castsi256_ps(tmplo), _mm256_castsi256_ps(tmphi),
                        _MM_SHUFFLE(3, 1, 3, 1));
  const __m256i d =
      _mm256_castps_si256(_mm256_permute_ps(tmpd, _MM_SHUFFLE(3, 1, 2, 0)));
  return _mm256_add_epi32(d, _mm256_and_si256(_mm256_srai_epi32(d, 31), M));
}
static inline __m256i
id37(__m256i A, __m256i B, __m256i M) {
  const __m256i d = _mm256_sub_epi32(_mm256_add_epi32(A, B), M);
  return _mm256_add_epi32(d, _mm256_and_si256(_mm256_srai_epi32(d, 31), M));
}
static inline __m256i
id3(__m256i A, __m256i B, __m256i M) {
  return id37(A, _mm256_sub_epi32(M, B), M);
}
static int *
get_storage(size_t n) noexcept {
  constexpr std::align_val_t algn = std::align_val_t(alignof(__m256i));
  void *mem = ::operator new[](n * sizeof(int), algn, std::nothrow);
  memset(mem, 0, n * sizeof(int));
  return static_cast<int *>(mem);
}
static void
free_storage(int *ptr) noexcept {
  constexpr std::align_val_t algn = std::align_val_t(alignof(__m256i));
  ::operator delete[](ptr, algn);
}
static inline void
id16(int *rev, int n) {
  rev[0] = 0;
  for (int j = 2; j <= n; j <<= 1) {
    for (int i = 0; i < (j >> 1); ++i) {
      rev[i] = rev[i] << 1;
      rev[i + (j >> 1)] = rev[i] | 1;
    }
  }
}
static inline void
id5(int *out, const int *rev, int n) {
  for (int i = 0; i < n; ++i) {
    if (i < rev[i]) { std::swap(out[i], out[rev[i]]); }
  }
}
template <int MOD, bool Inverse>
static inline void
id28(int *out, const int *rev, int n) {
  typedef std::make_unsigned_t<safe_mul_t<int>> mul_t;
  constexpr int minv = meta::id20<MOD>;
  constexpr int rbase = (static_cast<mul_t>(1) << 32) % MOD;
  constexpr static auto id11 = [] {
    constexpr int k = id52(MOD - 1);
    constexpr int c = (MOD - 1) >> k;
    constexpr int g = primitive_root(MOD, MOD - 1).value();
    constexpr int w = id30(g, c, MOD);


    std::array<std::array<int, 17>, k + 1> ans{};
    ans[k][0] = 1;
    ans[k][1] = (Inverse) ? inv_mod(w, MOD) : w;
    for (int i = 2; i < 17; ++i) {
      ans[k][i] = static_cast<mul_t>(ans[k][i - 1]) * ans[k][1] % MOD;
    }
    for (int i = k - 1; i >= 0; --i) {
      ans[i][0] = 1;
      ans[i][1] = static_cast<mul_t>(ans[i + 1][1]) * ans[i + 1][1] % MOD;
      for (int j = 2; j < 17; ++j) {
        ans[i][j] = static_cast<mul_t>(ans[i][j - 1]) * ans[i][1] % MOD;
      }
    }
    for (int i = 0; i <= k; ++i) {
      for (int j = 0; j < 17; ++j) {
        ans[i][j] = static_cast<mul_t>(ans[i][j]) * rbase % MOD;
      }
    }

    return ans;
  }();
  const __m256i reg_m = _mm256_set1_epi32(MOD);
  const __m256i id38 = _mm256_set1_epi32(minv);
  const __m256i id8 = _mm256_set1_epi32(id11[1][0]);
  const __m256i id42 =
      _mm256_set_epi32(id11[2][1], id11[2][1], id11[2][0], id11[2][0], id11[2][1],
                       id11[2][1], id11[2][0], id11[2][0]);
  const __m256i id53 =
      _mm256_set_epi32(id11[3][3], id11[3][3], id11[3][2], id11[3][2], id11[3][1],
                       id11[3][1], id11[3][0], id11[3][0]);
  const __m256i id47 =
      _mm256_set_epi32(id11[4][7], id11[4][6], id11[4][5], id11[4][4], id11[4][3],
                       id11[4][2], id11[4][1], id11[4][0]);
  id5(out, rev, n);
  for (int i = 0; i < n; i += 16) {
    __m256i v0 = _mm256_load_si256((__m256i *)&out[i]);
    __m256i v1 = _mm256_load_si256((__m256i *)&out[i + 8]);
    __m256i u0 = _mm256_castps_si256(
        _mm256_shuffle_ps(_mm256_castsi256_ps(v0), _mm256_castsi256_ps(v1),
                          _MM_SHUFFLE(2, 0, 2, 0)));
    __m256i u1 = _mm256_castps_si256(
        _mm256_shuffle_ps(_mm256_castsi256_ps(v0), _mm256_castsi256_ps(v1),
                          _MM_SHUFFLE(3, 1, 3, 1)));
    u1 = id6(u1, id8, reg_m, id38);
    v0 = id37(u0, u1, reg_m);
    v1 = id3(u0, u1, reg_m);
    u0 = _mm256_castps_si256(_mm256_shuffle_ps(_mm256_castsi256_ps(v0),
                                               _mm256_castsi256_ps(v1),
                                               _MM_SHUFFLE(2, 0, 2, 0)));
    u1 = _mm256_castps_si256(_mm256_shuffle_ps(_mm256_castsi256_ps(v0),
                                               _mm256_castsi256_ps(v1),
                                               _MM_SHUFFLE(3, 1, 3, 1)));
    u1 = id6(u1, id42, reg_m, id38);
    v0 = id37(u0, u1, reg_m);
    v1 = id3(u0, u1, reg_m);
    u0 = _mm256_castps_si256(_mm256_permute2f128_ps(
        _mm256_castsi256_ps(v0), _mm256_castsi256_ps(v1), 0x20));
    u1 = _mm256_castps_si256(_mm256_permute2f128_ps(
        _mm256_castsi256_ps(v0), _mm256_castsi256_ps(v1), 0x31));
    u1 = id6(u1, id53, reg_m, id38);
    v0 = id37(u0, u1, reg_m);
    v1 = id3(u0, u1, reg_m);
    const __m256d tmp0 = _mm256_castps_pd(
        _mm256_shuffle_ps(_mm256_castsi256_ps(v0), _mm256_castsi256_ps(v1),
                          _MM_SHUFFLE(2, 0, 2, 0)));
    const __m256d tmp1 = _mm256_castps_pd(
        _mm256_shuffle_ps(_mm256_castsi256_ps(v0), _mm256_castsi256_ps(v1),
                          _MM_SHUFFLE(3, 1, 3, 1)));
    u0 = _mm256_castpd_si256(
        _mm256_permute4x64_pd(tmp0, _MM_SHUFFLE(3, 1, 2, 0)));
    u1 = _mm256_castpd_si256(
        _mm256_permute4x64_pd(tmp1, _MM_SHUFFLE(3, 1, 2, 0)));
    u1 = id6(u1, id47, reg_m, id38);
    v0 = id37(u0, u1, reg_m);
    v1 = id3(u0, u1, reg_m);
    _mm256_store_si256((__m256i *)&out[i], v0);
    _mm256_store_si256((__m256i *)&out[i + 8], v1);
  }
  for (int lg = 5, l = 32; l <= n; ++lg, l <<= 1) {
    const __m256i reg_stride = _mm256_set1_epi32(id11[lg][16]);
    const __m256i id51 =
        _mm256_set_epi32(id11[lg][7], id11[lg][6], id11[lg][5], id11[lg][4],
                         id11[lg][3], id11[lg][2], id11[lg][1], id11[lg][0]);
    const __m256i reg_sec =
        _mm256_set_epi32(id11[lg][15], id11[lg][14], id11[lg][13], id11[lg][12],
                         id11[lg][11], id11[lg][10], id11[lg][9], id11[lg][8]);
    for (int i = 0; i < n; i += l) {
      __m256i id49 = id51;
      __m256i reg_ws = reg_sec;
      for (int j = 0; j < (l >> 1); j += 16) {
        __m256i v0 = _mm256_load_si256((__m256i *)&out[i + j]);
        __m256i v1 = _mm256_load_si256((__m256i *)&out[i + j + 8]);
        __m256i v2 = _mm256_load_si256((__m256i *)&out[i + j + (l >> 1)]);
        __m256i v3 = _mm256_load_si256((__m256i *)&out[i + j + (l >> 1) + 8]);
        v2 = id6(v2, id49, reg_m, id38);
        v3 = id6(v3, reg_ws, reg_m, id38);
        _mm256_store_si256((__m256i *)&out[i + j],
                           id37(v0, v2, reg_m));
        _mm256_store_si256((__m256i *)&out[i + j + 8],
                           id37(v1, v3, reg_m));
        _mm256_store_si256((__m256i *)&out[i + j + (l >> 1)],
                           id3(v0, v2, reg_m));
        _mm256_store_si256((__m256i *)&out[i + j + (l >> 1) + 8],
                           id3(v1, v3, reg_m));
        id49 = id6(id49, reg_stride, reg_m, id38);
        reg_ws = id6(reg_ws, reg_stride, reg_m, id38);
      }
    }
  }
  if constexpr (Inverse) {
    const int ninv = id10(inv_mod(n, MOD), rbase, MOD);
    const __m256i id48 = _mm256_set1_epi32(ninv);
    for (int i = 0; i < n; i += 16) {
      __m256i v0 = _mm256_load_si256((__m256i *)&out[i]);
      __m256i v1 = _mm256_load_si256((__m256i *)&out[i + 8]);
      v0 = id6(v0, id48, reg_m, id38);
      v1 = id6(v1, id48, reg_m, id38);
      _mm256_store_si256((__m256i *)&out[i], v0);
      _mm256_store_si256((__m256i *)&out[i + 8], v1);
    }
  }
}
template <int MOD>
inline static void
convolution(int *__restrict__ c1, int *__restrict__ c2, const int *rev, int n) {
  constexpr int minv = meta::id20<MOD>;
  constexpr int rsq = meta::id31<MOD>;
  const __m256i reg_m = _mm256_set1_epi32(MOD);
  const __m256i id38 = _mm256_set1_epi32(minv);
  const __m256i id45 = _mm256_set1_epi32(rsq);
  for (int i = 0; i < n; i += 16) {
    const __m256i v0 = _mm256_load_si256((__m256i *)&c1[i]);
    const __m256i v1 = _mm256_load_si256((__m256i *)&c1[i + 8]);
    const __m256i u0 = _mm256_load_si256((__m256i *)&c2[i]);
    const __m256i u1 = _mm256_load_si256((__m256i *)&c2[i + 8]);
    const __m256i a0 = id6(v0, id45, reg_m, id38);
    const __m256i a1 = id6(v1, id45, reg_m, id38);
    const __m256i b0 = id6(u0, id45, reg_m, id38);
    const __m256i b1 = id6(u1, id45, reg_m, id38);
    _mm256_store_si256((__m256i *)&c1[i], a0);
    _mm256_store_si256((__m256i *)&c1[i + 8], a1);
    _mm256_store_si256((__m256i *)&c2[i], b0);
    _mm256_store_si256((__m256i *)&c2[i + 8], b1);
  }
  id28<MOD, false>(c1, rev, n);
  id28<MOD, false>(c2, rev, n);
  for (int i = 0; i < n; i += 16) {
    const __m256i v0 = _mm256_load_si256((__m256i *)&c1[i]);
    const __m256i v1 = _mm256_load_si256((__m256i *)&c1[i + 8]);
    const __m256i u0 = _mm256_load_si256((__m256i *)&c2[i]);
    const __m256i u1 = _mm256_load_si256((__m256i *)&c2[i + 8]);
    const __m256i prod0 = id6(v0, u0, reg_m, id38);
    const __m256i prod1 = id6(v1, u1, reg_m, id38);
    _mm256_store_si256((__m256i *)&c1[i], prod0);
    _mm256_store_si256((__m256i *)&c1[i + 8], prod1);
    _mm256_store_si256((__m256i *)&c2[i], _mm256_setzero_si256());
    _mm256_store_si256((__m256i *)&c2[i + 8], _mm256_setzero_si256());
  }
  id28<MOD, true>(c1, rev, n);
  for (int i = 0; i < n; i += 16) {
    const __m256i v0 = _mm256_load_si256((__m256i *)&c1[i]);
    const __m256i v1 = _mm256_load_si256((__m256i *)&c1[i + 8]);
    const __m256i tmp0 = id46(v0, reg_m, id38);
    const __m256i tmp1 = id46(v1, reg_m, id38);
    _mm256_store_si256((__m256i *)&c1[i], tmp0);
    _mm256_store_si256((__m256i *)&c1[i + 8], tmp1);
  }
}
template <int MOD>
static inline void
id14(const int *c1, const int *c2, const int *c3, int *out, int n) {
  typedef std::make_unsigned_t<safe_mul_t<int>> mul_t;
  constexpr int MOD1 = 167772161;
  constexpr int MOD2 = 469762049;
  constexpr int MOD3 = 754974721;
  constexpr int inv12 = inv_mod(MOD1, MOD2);
  constexpr int inv13 = inv_mod(MOD1, MOD3);
  constexpr int inv23 = inv_mod(MOD2, MOD3);
  constexpr int id1 = (static_cast<mul_t>(inv12) << 32) % MOD2;
  constexpr int id4 = (static_cast<mul_t>(inv13) << 32) % MOD3;
  constexpr int id34 = (static_cast<mul_t>(inv23) << 32) % MOD3;
  constexpr int co1 = (-static_cast<uint32_t>(MOD)) % MOD;
  constexpr int co2 = (static_cast<mul_t>(co1) * MOD1) % MOD;
  constexpr int co3 = (static_cast<mul_t>(co2) * MOD2) % MOD;
  constexpr int id29 = meta::id20<MOD2>;
  constexpr int id36 = meta::id20<MOD3>;
  constexpr int minv = meta::id20<MOD>;
  const __m256i id12 = _mm256_set1_epi32(id1);
  const __m256i id54 = _mm256_set1_epi32(id4);
  const __m256i id24 = _mm256_set1_epi32(id34);
  const __m256i id21 = _mm256_set1_epi32(co1);
  const __m256i id7 = _mm256_set1_epi32(co2);
  const __m256i id27 = _mm256_set1_epi32(co3);
  const __m256i id25 = _mm256_set1_epi32(MOD2);
  const __m256i id41 = _mm256_set1_epi32(MOD3);
  const __m256i reg_m = _mm256_set1_epi32(MOD);
  const __m256i id22 = _mm256_set1_epi32(id29);
  const __m256i id32 = _mm256_set1_epi32(id36);
  const __m256i id38 = _mm256_set1_epi32(minv);
  for (int i = 0; i < n; i += 16) {
    __m256i x1 = _mm256_load_si256((__m256i *)&c1[i]);
    __m256i y1 = _mm256_load_si256((__m256i *)&c1[i + 8]);
    __m256i x2 = _mm256_load_si256((__m256i *)&c2[i]);
    __m256i y2 = _mm256_load_si256((__m256i *)&c2[i + 8]);
    __m256i x3 = _mm256_load_si256((__m256i *)&c3[i]);
    __m256i y3 = _mm256_load_si256((__m256i *)&c3[i + 8]);
    x2 = id6(id3(x2, x1, id25), id12,
                              id25, id22);
    y2 = id6(id3(y2, y1, id25), id12,
                              id25, id22);
    __m256i tmp1 = id6(id3(x3, x1, id41),
                                        id54, id41, id32);
    __m256i tmp2 = id6(id3(y3, y1, id41),
                                        id54, id41, id32);
    x3 = id6(id3(tmp1, x2, id41), id24,
                              id41, id32);
    y3 = id6(id3(tmp2, y2, id41), id24,
                              id41, id32);
    x1 = id6(x1, id21, reg_m, id38);
    y1 = id6(y1, id21, reg_m, id38);
    x2 = id6(x2, id7, reg_m, id38);
    y2 = id6(y2, id7, reg_m, id38);
    x3 = id6(x3, id27, reg_m, id38);
    y3 = id6(y3, id27, reg_m, id38);
    x2 = id37(x1, x2, reg_m);
    y2 = id37(y1, y2, reg_m);
    x3 = id37(x2, x3, reg_m);
    y3 = id37(y2, y3, reg_m);
    _mm256_storeu_si256((__m256i *)&out[i], x3);
    _mm256_storeu_si256((__m256i *)&out[i + 8], y3);
  }
}
}
template <int MOD>
static std::vector<modint<MOD>>
id26(const std::vector<modint<MOD>> &f1,
             const std::vector<modint<MOD>> &f2, int n) noexcept {
  const int n1 = std::ssize(f1);
  const int n2 = std::ssize(f2);
  const size_t block_sz = size_t(n) * 3;
  const int *c1 = reinterpret_cast<const int *>(f1.data());
  const int *c2 = reinterpret_cast<const int *>(f2.data());
  int *buffer = fft::get_storage(block_sz);
  int *p1 = buffer + 0 * n;
  int *p2 = buffer + 1 * n;
  int *br = buffer + 2 * n;
  fft::id16(br, n);
  std::copy(c1, c1 + n1, p1);
  std::copy(c2, c2 + n2, p2);
  fft::convolution<MOD>(p1, p2, br, n);
  std::vector<modint<MOD>> res(n);
  int *out = reinterpret_cast<int *>(res.data());
  std::copy(p1, p1 + n, out);
  fft::free_storage(buffer);
  return res;
}
template <int MOD>
static std::vector<modint<MOD>>
id9(const std::vector<modint<MOD>> &f1,
             const std::vector<modint<MOD>> &f2, int n) noexcept {
  constexpr int MOD1 = 167772161;
  constexpr int MOD2 = 469762049;
  constexpr int MOD3 = 754974721;
  const int n1 = std::ssize(f1);
  const int n2 = std::ssize(f2);
  const size_t block_sz = size_t(n) * 5;
  const int *c1 = reinterpret_cast<const int *>(f1.data());
  const int *c2 = reinterpret_cast<const int *>(f2.data());
  int *buffer = fft::get_storage(block_sz);
  int *p1 = buffer + 0 * n;
  int *p2 = buffer + 1 * n;
  int *p3 = buffer + 2 * n;
  int *p4 = buffer + 3 * n;
  int *br = buffer + 4 * n;
  fft::id16(br, n);
  std::copy(c1, c1 + n1, p1);
  std::copy(c2, c2 + n2, p4);
  fft::convolution<MOD1>(p1, p4, br, n);
  std::copy(c1, c1 + n1, p2);
  std::copy(c2, c2 + n2, p4);
  fft::convolution<MOD2>(p2, p4, br, n);
  std::copy(c1, c1 + n1, p3);
  std::copy(c2, c2 + n2, p4);
  fft::convolution<MOD3>(p3, p4, br, n);
  std::vector<modint<MOD>> res(n);
  int *out = reinterpret_cast<int *>(res.data());
  fft::id14<MOD>(p1, p2, p3, out, n);
  fft::free_storage(buffer);
  return res;
}
}
template <int MOD>
class poly {
public:
  using mint_type = modint<MOD>;
  poly() = default;
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
  operator+=(const mint_type &x) {
    if (is_zero()) { c_.emplace_back(0); }
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
  operator-=(const mint_type &x) {
    if (is_zero()) { c_.emplace_back(0); }
    c_[0] -= x;
    drop_zeros();
    return *this;
  }
  poly &
  operator*=(const poly &rhs) {
    const int m = std::min(size(), rhs.size());
    *this = is_large(m) ? mul_fast(rhs) : mul_slow(rhs);
    return *this;
  }
  poly &
  operator*=(const mint_type &x) {
    for (auto &coef : c_) { coef *= x; }
    drop_zeros();
    return *this;
  }
  poly &
  operator/=(const poly &rhs) {
    assert(!rhs.is_zero());
    const int m = deg() - rhs.deg() + 1;
    *this = is_large(m) ? div_fast(rhs) : div_slow(rhs);
    return *this;
  }
  poly &
  operator%=(const poly &rhs) {
    assert(!rhs.is_zero());
    const poly D = *this / rhs;
    *this -= D * rhs;
    return *this;
  }
  poly
  operator-() const {
    std::vector<mint_type> res(size());
    std::transform(c_.begin(), c_.end(), res.begin(), std::negate<mint_type>{});
    return poly(std::move(res));
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
  operator+(poly lhs, const mint_type &rhs) {
    return lhs += rhs;
  }
  friend poly
  operator+(const mint_type &lhs, const poly &rhs) {
    return poly(rhs) += lhs;
  }
  friend poly
  operator-(poly lhs, const mint_type &rhs) {
    return lhs -= rhs;
  }
  friend poly
  operator-(const mint_type &lhs, const poly &rhs) {
    return poly(-rhs) += lhs;
  }
  friend poly
  operator*(poly lhs, const mint_type &rhs) {
    return lhs *= rhs;
  }
  friend poly
  operator*(const mint_type &lhs, const poly &rhs) {
    return poly(rhs) *= lhs;
  }
  mint_type
  operator[](int i) const {
    return i >= 0 && i < size() ? c_[i] : 0;
  }
  mint_type
  operator()(mint_type x) const {
    mint_type ans = 0;
    for (const auto &coef : c_) {
      ans *= x;
      ans += coef;
    }
    return ans;
  }
  poly
  mul_xk(int k) const {
    assert(k >= 0);
    std::vector<mint_type> out(k + size());
    std::copy_backward(c_.begin(), c_.end(), out.end());
    return poly(std::move(out));
  }
  poly
  mod_xk(int k) const {
    assert(k >= 0);
    return poly(std::vector(c_.begin(), c_.begin() + std::min(k, size())));
  }
  poly
  div_xk(int k) const {
    assert(k >= 0);
    return poly(std::vector(c_.begin() + std::min(k, size()), c_.end()));
  }
  poly
  rev(int n) const {
    assert(n >= 0);
    std::vector<mint_type> res(std::max(size(), n + 1));
    std::copy_backward(c_.rbegin(), c_.rend(), res.end());
    return poly(std::move(res));
  }
  poly
  inv(int n) const {
    assert(deg() >= 0 && c_[0] != 0);
    int pw = 1;
    poly ans = {c_[0].inv()};
    while (pw < n) {
      const poly D = (ans * mod_xk(pw << 1)).mod_xk(pw << 1).div_xk(pw);
      ans -= (ans * D).mod_xk(pw).mul_xk(pw);
      pw <<= 1;
    }
    return ans.mod_xk(n);
  }
  poly
  binpow(int k, int n) const {
    assert(k >= 0);
    assert(n >= 0);
    poly res = {mint_type::from(1)};
    poly mul = mod_xk(n);
    while (k > 0) {
      if (k & 0x01) { res *= mul; }
      mul *= mul;
      mul = mul.mod_xk(n);
      k >>= 1;
    }
    return res;
  }
  poly
  deriv() const {
    if (detail::likely(size() > 1)) {
      std::vector<mint_type> res(deg());
      for (int i = 1; i < size(); ++i) { res[i - 1] = c_[i] * i; }
      return poly(std::move(res));
    } else {
      return poly{};
    }
  }
  mint_type
  lead() const {
    return is_zero() ? 0 : c_.back();
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
  bool
  is_zero() const {
    return c_.empty();
  }
  friend std::ostream &
  operator<<(std::ostream &os, const poly &p) {
    for (int i = 0; i < p.size(); ++i) {
      if (i) os << ' ';
      os << p.c_[i].val();
    }
    if (p.is_zero()) { os << 0; }
    return os;
  }
private:
  static constexpr bool
  is_large(int n) {
    return n >= 128;
  }
  void
  drop_zeros() noexcept {
    while (!c_.empty() && c_.back() == 0) { c_.pop_back(); }
  }
  void
  resize(int n) noexcept {
    c_.resize(n);
  }
  poly
  mul_slow(const poly &rhs) const {
    if (detail::likely(!is_zero() && !rhs.is_zero())) {
      const int n1 = size();
      const int n2 = rhs.size();
      const int n = n1 + n2 - 1;
      std::vector<mint_type> res(n);
      for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) { res[i + j] += c_[i] * rhs.c_[j]; }
      }
      return poly(std::move(res));
    } else {
      return poly{};
    }
  }
  poly
  mul_fast(const poly &rhs) const {
    constexpr int cap = 1 << detail::id52(MOD - 1);
    const int n1 = size();
    const int n2 = rhs.size();
    const int n = detail::id0(n1 + n2 - 1);
    return n <= cap ? poly(detail::id26(c_, rhs.c_, n))
                    : poly(detail::id9(c_, rhs.c_, n));
  }
  poly
  div_slow(const poly &rhs) const {
    const int d1 = deg();
    const int d2 = rhs.deg();
    const int m = d1 - d2 + 1;
    if (d1 < d2) { return poly{}; }
    std::vector<mint_type> out(m), temp(m);
    std::copy(c_.begin() + d2, c_.end(), temp.begin());
    const mint_type x = rhs.c_.back().inv();
    for (int i = m - 1; i >= 0; --i) {
      out[i] = temp[i];
      if (temp[i] != 0) {
        out[i] *= x;
        const int q = std::max(d2 - i, 0);
        for (int j = d2; j >= q; --j) {
          temp[i + j - d2] -= out[i] * rhs.c_[j];
        }
      }
    }
    return poly(std::move(out));
  }
  poly
  div_fast(const poly &rhs) const {
    const int d1 = deg();
    const int d2 = rhs.deg();
    const int m = d1 - d2 + 1;
    return (rev(d1).mod_xk(m) * rhs.rev(d2).inv(m)).mod_xk(m).rev(m - 1);
  }
  std::vector<mint_type> c_;
};
}
namespace algo {
template <int MOD, int Num>
struct factorial {
  using mint_type = modint<MOD>;
  constexpr factorial() : fac_(), inv_() {
    fac_[0] = 1;
    for (int i = 1; i <= Num; ++i) { fac_[i] = fac_[i - 1] * i; }
    inv_[Num] = fac_[Num].inv();
    for (int i = Num; i >= 1; --i) { inv_[i - 1] = inv_[i] * i; }
  }
  constexpr mint_type
  fact(int i) const {
    assert(0 <= i && i <= Num);
    return fac_[i];
  }
  constexpr mint_type
  inv(int i) const {
    assert(0 <= i && i <= Num);
    return inv_[i];
  }
  constexpr mint_type
  comb(int n, int r) const {
    assert(0 <= r && r <= n && n <= Num);
    return fac_[n] * inv_[n - r] * inv_[r];
  }
  constexpr mint_type
  perm(int n, int r) {
    assert(0 <= r && r <= n && n <= Num);
    return fac_[n] * inv_[n - r];
  }
private:
  std::array<mint_type, Num + 1> fac_, inv_;
};
}

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





static const algo::factorial<MOD,MAXN-1>fac{};
inline void solve() noexcept {
  using mint=algo::modint<MOD>;
  using poly=algo::poly<MOD>;
  int n;cin>>n;
  vector<mint>dp(n);
  vector<mint>dp2(n+1);
  vector<mint>f(n),g(n);
  dp[0]=dp2[1]=1;
  const int mid=(n-1)>>1;
  for(int i=1;i<n;++i){
    mint c=mint::from(i).inv();
    mint d=dp2[i];
    if(i>=mid){d-=dp2[i-mid];}
    dp[i]=c*d;
    dp2[i+1]=dp2[i]+dp[i];
  }
  for(int i=n-mid-1;i<n-1;++i){
    auto c=dp2[i];
    if(i>=mid){c-=dp2[i-mid];}
    f[i]=c*fac.fact(n-i-2)*mint::from(i).inv();
  }
  for(int i=0;i<n;++i){
    g[i]=fac.inv(i);
  }
  vector<mint>coef=(poly(move(f))*poly(move(g))).to_vector();
  coef.resize(n);
  vector<mint>ans(n);
  for(int i=1;i<n;++i){
    ans[i]=mint::from(i)*fac.fact(n-i-1)*coef[n-i-1];
  }
  ans[0]=ans[1];
  for(int i=0;i<n;++i){
    cout<<ans[i]<<" \n"[i==n-1];
  }
}
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cout.precision(15);
  solve();
  return 0;
}
