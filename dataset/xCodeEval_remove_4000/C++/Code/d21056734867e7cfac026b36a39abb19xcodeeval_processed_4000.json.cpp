













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
}
}
namespace algo {
namespace detail {
template <dword_fittable Tp>
constexpr int
id11(Tp n) {
  return __builtin_clz(n);
}
template <qword_fittable Tp>
constexpr int
id11(Tp n) {
  return __builtin_clzll(n);
}
template <dword_fittable Tp>
constexpr int
id16(Tp n) {
  return __builtin_ctz(n);
}
template <qword_fittable Tp>
constexpr int
id16(Tp n) {
  return __builtin_ctzll(n);
}
template <dword_fittable Tp>
constexpr int
bit_width(Tp n) {
  return 32 - id11(n);
}
template <qword_fittable Tp>
constexpr int
bit_width(Tp n) {
  return 64 - id11(n);
}
template <dword_fittable Tp>
constexpr Tp
bit_floor(Tp n) {
  return 1u << (31 - id11(n));
}
template <qword_fittable Tp>
constexpr Tp
bit_floor(Tp n) {
  return 1ull << (63 - id11(n));
}
template <integer Tp>
constexpr Tp
id0(Tp n) {
  if (n == 0 || n == 1) { return 1; }
  return bit_floor(n - 1) << 1;
}
template <dword_fittable Tp>
constexpr int
id13(Tp n) {
  return 31 - id11(n);
}
template <qword_fittable Tp>
constexpr int
id13(Tp n) {
  return 63 - id11(n);
}
template <integer Tp>
constexpr int
id14(Tp n) {
  if (n == 0 || n == 1) { return 0; }
  return id13(n - 1) + 1;
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
template <detail::integer Tp>
constexpr int
id4(Tp n) {
  return detail::id11(n);
}
template <detail::integer Tp>
constexpr int
id9(Tp n) {
  return detail::id11(~n);
}
template <detail::integer Tp>
constexpr int
id6(Tp n) {
  return detail::id16(n);
}
template <detail::integer Tp>
constexpr int
id3(Tp n) {
  return detail::id16(~n & (n + 1));
}
template <detail::integer Tp>
constexpr int
bit_width(Tp n) {
  return detail::bit_width(n);
}
template <detail::integer Tp>
constexpr Tp
bit_floor(Tp n) {
  return detail::bit_floor(n);
}
template <detail::integer Tp>
constexpr Tp
id0(Tp n) {
  return detail::id0(n);
}
template <detail::integer Tp>
constexpr int
id13(Tp n) {
  return detail::id13(n);
}
template <detail::integer Tp>
constexpr int
id14(Tp n) {
  return detail::id14(n);
}
template <detail::integer Tp>
constexpr Tp
popcount(Tp n) {
  return detail::popcount(n);
}
}
namespace dbg {

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
namespace detail {
template <integer Tp>
constexpr Tp
sqrt(Tp n) {
  if (n == 0) { return 0; }
  if (n == 1) { return 1; }
  Tp ans = 0;
  for (int i = id13(n) - 1; i >= 0; --i) {
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
id15(Tp x, Tp y) {
  if constexpr (std::is_unsigned_v<Tp>) {
    return x / y + (x % y != 0);
  } else {
    return x / y + (x % y != 0 && (x ^ y) >= 0);
  }
}
template <std::integral Tp>
constexpr std::make_signed_t<std::common_type_t<Tp, int>>
id5(Tp n) {
  return -(n & 1) | 1;
}
template <integer Tp>
constexpr Tp
floor_sum(Tp a, Tp b, Tp c, Tp n) {
  Tp res = 0;
  bool neg = false;
  while (a != 0) {
    if (a < c && b < c) {
      const Tp m = (a * n + b) / c;
      const Tp tmp = a;
      res += id5(neg) * m * n;
      b = c - b - 1, a = c, c = tmp, n = m - 1;
      neg ^= true;
    } else {
      const Tp tmp = (n * (n + 1) >> 1) * (a / c) + (n + 1) * (b / c);
      res += id5(neg) * tmp;
      a %= c, b %= c;
    }
  }
  res += id5(neg) * (b / c) * (n + 1);
  return res;
}
}
}
namespace algo {
template <detail::integer Tp>
constexpr Tp
sqrt(Tp n) {
  assert(n >= 0);
  return detail::sqrt(n);
}
template <detail::integer Tp>
constexpr Tp
abs(Tp n) {
  return detail::abs(n);
}
template <detail::integer Tp>
constexpr Tp
id15(Tp x, Tp y) {
  assert(y != 0);
  return detail::id15(x, y);
}
template <detail::integer Tp>
constexpr std::make_signed_t<Tp>
id5(Tp n) {
  return detail::id5(n);
}
template <detail::integer Tp>
constexpr Tp
floor_sum(Tp a, Tp b, Tp c, Tp n) {
  assert(n >= 0);
  assert(c > 0);
  return detail::floor_sum(a, b, c, n);
}
}
namespace algo {
namespace detail {
template <integer Tp>
constexpr Tp
id1(Tp x, Tp y, Tp m) {
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
id8(Tp n) {
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
  bool parity = false;
  if (cur_n == 1) { return 1; }
  if (cur_n % 2 == 0) {
    if ((cur_n /= 2) % 2 == 0) { return 0; }
    parity ^= true;
  }
  if (cur_n % 3 == 0) {
    if ((cur_n /= 3) % 3 == 0) { return 0; }
    parity ^= true;
  }
  for (Tp i = 5, c = 2; i * static_cast<wide_t>(i) <= cur_n; i += c, c ^= 6) {
    if (cur_n % i == 0) {
      if ((cur_n /= i) % i == 0) { return 0; }
      parity ^= true;
    }
  }
  if (cur_n > 1) { parity ^= 1; }
  return id5(parity);
}
template <signed_integer Tp>
constexpr std::pair<Tp, Tp>
id12(Tp a, Tp b) {
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
id10(Tp a, Up b, Tp m) {
  Tp ans = 1, mul = a;
  const Tp mod = m;
  std::make_unsigned_t<Up> pw = b;
  if ((mul %= mod) < 0) mul += mod;
  while (pw) {
    if (pw & 0x01) { ans = id1(ans, mul, mod); }
    mul = id1(mul, mul, mod);
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
  const int s = id16(n - 1);
  const Tp d = (n - 1) >> s;
  constexpr Tp primes[] = {2, 3, 5, 7};
  for (const Tp p : primes) {
    Tp x = id10(p, d, n);
    bool good = x == n - 1 || x == 1;
    for (int r = 1; r < s; ++r) {
      x = id1(x, x, n);
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
  const int s = id16(n - 1);
  const Tp d = (n - 1) >> s;
  constexpr Tp primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
  for (const Tp p : primes) {
    Tp x = id10(p, d, n);
    bool good = x == n - 1 || x == 1;
    for (int r = 1; r < s; ++r) {
      x = id1(x, x, n);
      good |= x == n - 1;
    }
    if (!good) { return false; }
  }
  return true;
}
template <integer Tp>
std::vector<std::tuple<Tp, Tp, Tp>>
quotients(Tp n) {
  assume(0 <= n);
  std::vector<std::tuple<Tp, Tp, Tp>> ans{};
  for (Tp i = 1, j = 1; i <= n; i = j + 1) {
    const Tp q = n / i;
    j = n / q;
    ans.emplace_back(i, j, q);
  }
  return ans;
}
template <integer Tp>
std::vector<std::pair<Tp, int>>
factorize(Tp n) {
  assume(1 <= n);
  typedef safe_mul_t<Tp> wide_t;
  std::vector<std::pair<Tp, int>> ans{};
  ans.reserve(23);
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
  for (Tp i = 5, ec = 2; i * static_cast<wide_t>(i) <= n; i += ec, ec ^= 6) {
    if (n % i == 0) {
      int c = 0;
      do { n /= i, c++; } while (n % i == 0);
      ans.emplace_back(i, c);
    }
  }
  if (n > 1) { ans.emplace_back(n, 1); }
  return ans;
}
template <integer Tp>
std::vector<Tp>
id7(Tp n) noexcept {
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
id2(Tp n) noexcept {
  typedef std::make_signed_t<Tp> value_t;
  assume(1 <= n);
  std::vector<value_t> mu(n + 1);
  mu[1] = 1;
  for (Tp i = 2; i <= n; ++i) {
    mu[i] -= 1;
    for (Tp j = i + i; j <= n; j += i) { mu[j] -= mu[i]; }
  }
  return mu;
}
}
}
namespace algo {
template <int MOD>
class modint {
  static constexpr bool IsPrime = detail::prime_test(MOD);
public:
  constexpr modint() = default;
  template <detail::signed_integer Tp>
  constexpr modint(Tp x) : value_(static_cast<int>(x % MOD)) {
    value_ += (value_ < 0) ? MOD : 0;
  }
  template <detail::unsigned_integer Tp>
  constexpr modint(Tp x) : value_(static_cast<int>(x % MOD)) {}
  constexpr modint &
  operator+=(const modint &rhs) {
    value_ += rhs.val() - MOD;
    value_ += (value_ < 0) ? MOD : 0;
    return *this;
  }
  constexpr modint &
  operator-=(const modint &rhs) {
    value_ -= rhs.val();
    value_ += (value_ < 0) ? MOD : 0;
    return *this;
  }
  constexpr modint &
  operator*=(const modint &rhs) {
    typedef detail::safe_mul_t<int32_t> wide_t;
    detail::assume(0 <= val() && val() < MOD);
    detail::assume(0 <= rhs.val() && rhs.val() < MOD);
    value_ = static_cast<int>(static_cast<wide_t>(val()) * rhs.val() % MOD);
    return *this;
  }
  constexpr modint &
  operator/=(const modint &rhs) {
    return operator*=(rhs.inv());
  }
  constexpr modint
  operator-() const {
    const int res = val() != 0 ? MOD - val() : 0;
    return from(res);
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
    const modint res = *this;
    operator++();
    return res;
  }
  constexpr modint
  operator--(int) {
    const modint res = *this;
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
    const auto [res, g] = detail::id12(val(), MOD);
    assert(g == 1);
    return modint(res);
  }
  constexpr std::optional<modint>
  sqrt() const requires(IsPrime) {
    if constexpr (MOD == 2) { return std::optional(*this); }
    if (val() == 0 || val() == 1) { return std::optional(*this); }
    if (pow((MOD - 1) / 2).val() == MOD - 1) { return std::nullopt; }
    constexpr modint z = get_quadratic_nonresidue();
    constexpr int k = detail::id16(MOD - 1);
    constexpr int c = (MOD - 1) >> k;
    modint res = pow((c + 1) >> 1);
    modint cur = pow(c);
    modint fac = z.pow(c);
    for (int i = k - 1; i > 0 && cur != 1; --i) {
      const modint nfac = fac * fac;
      if (cur.pow(1 << (i - 1)) == MOD - 1) {
        res *= fac;
        cur *= nfac;
      }
      fac = nfac;
    }
    return std::optional(res);
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
  template <detail::integer Tp>
  constexpr static modint
  from(Tp x) {
    assert(0 <= x && x < MOD);
    return std::bit_cast<modint>(static_cast<int>(x));
  }
  constexpr static int
  mod() {
    return MOD;
  }
  friend std::ostream &
  operator<<(std::ostream &os, const modint &mt) {
    os << mt.val();
    return os;
  }
private:
  constexpr static modint
  get_quadratic_nonresidue() requires(IsPrime) {
    for (int x = 2; x < MOD; ++x) {
      if (modint::from(x).pow((MOD - 1) >> 1).val() == MOD - 1) {
        return modint(x);
      }
    }
    detail::unreachable();
  }
  int value_{0};
};
}
namespace algo {
template <int MOD>
class factorial {
  static_assert(detail::prime_test(MOD));
  using mint_type = modint<MOD>;
public:
  factorial() : factorial(MOD - 1) {}
  factorial(int n) noexcept : n_(n), fac_(n + 1), inv_(n + 1) {
    assert(n < MOD);
    fac_[0] = 1;
    fac_[1] = 1;
    for (int i = 2; i <= n; ++i) { fac_[i] = fac_[i - 1] * mint_type::from(i); }
    inv_[n] = fac_[n].inv();
    inv_[0] = 1;
    for (int i = n; i > 1; --i) { inv_[i - 1] = inv_[i] * mint_type::from(i); }
  }
  mint_type
  fact(int n) const {
    assert(n <= n_);
    return n >= 0 ? fac_[n] : 0;
  }
  mint_type
  inv_fact(int n) const {
    assert(n <= n_);
    return n >= 0 ? inv_[n] : 0;
  }
  mint_type
  comb(int n, int r) const {
    assert(n <= n_);
    return n >= r && r >= 0 ? fac_[n] * inv_[r] * inv_[n - r] : 0;
  }
  mint_type
  perm(int n, int r) const {
    assert(n <= n_);
    return n >= r && r >= 0 ? fac_[n] * inv_[n - r] : 0;
  }
private:
  int n_;
  std::vector<mint_type> fac_, inv_;
};
}

using std::array;
using std::vector;
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
using std::pair;
using std::tuple;
using std::cin;
using std::cout;
using std::endl;
using std::gcd;
using std::tie;
using std::lcm;
using std::max;
using std::min;
using std::swap;
using std::to_string;
template <typename Tp, typename Function>
using ordered_set = __gnu_pbds::tree<Tp,
__gnu_pbds::null_type, Function, __gnu_pbds::rb_tree_tag,
__gnu_pbds::tree_order_statistics_node_update>;
using wint = int64_t;
template <typename KeyType, typename ValueType>
using umap = std::unordered_map<KeyType, ValueType>;
template <typename ValueType> using uset = std::unordered_set<ValueType>;
template <typename Tp, typename Function = std::less<Tp>>
using max_heap = std::priority_queue<Tp, std::vector<Tp>, Function>;
template <typename Tp, typename Function = std::greater<Tp>>
using min_heap = std::priority_queue<Tp, std::vector<Tp>, Function>;





template <typename Tp>
constexpr void chmax(Tp &x, const Tp &y) { x = max(x, y); }
template <typename Tp>
constexpr void chmin(Tp &x, const Tp &y) { x = min(x, y); }
namespace {
using mint=algo::modint<MOD>;
algo::factorial<MOD>fac(3000);
}
mint calc(int n,wint r,wint z) {
  const int m=62;
  vector<vector<mint>>dp(m+1,vector<mint>(n+1));
  dp[m][0]=1;
  for(int i=m-1;i>=0;--i){
    const int c=(r>>i)&1;
    dp[i][n]=dp[i+1][n]*mint(2).pow(n-1);
    for(int j=0;j<n;++j){
      for(int k=(z>>i)&1;k<=n;k+=2){
        if(2*j-k+c>=0){
          dp[i][min(2*j-k+c,n)]+=dp[i+1][j]*fac.comb(n,k);
        }
      }
    }
  }
  mint ans=0;
  for(int i=0;i<=n;++i){
    ans+=dp[0][i];
  }
  return ans;
}
void solve() noexcept {
  int n;cin>>n;
  wint l,r,z;cin>>l>>r>>z;
  cout<<calc(n,r,z)-calc(n,l-1,z)<<'\n';
}
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cout.precision(15);
  solve();
  return 0;
}
