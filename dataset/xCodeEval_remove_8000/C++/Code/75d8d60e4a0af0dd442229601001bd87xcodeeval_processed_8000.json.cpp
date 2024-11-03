











namespace dbg {

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
id45(std::vector<Tp> &vec) noexcept {
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
id8(Tp n) {
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
id19(Tp n) {
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
id29(T1 a, T2 b) {
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
id25(T1 a, Up b, T2 m) {
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
id27(Tp n) {
  return __builtin_clz(n);
}
template <qword_fittable Tp>
constexpr int
id27(Tp n) {
  return __builtin_clzll(n);
}
template <dword_fittable Tp>
constexpr int
id47(Tp n) {
  return __builtin_ctz(n);
}
template <qword_fittable Tp>
constexpr int
id47(Tp n) {
  return __builtin_ctzll(n);
}
template <dword_fittable Tp>
constexpr int
id44(Tp n) {
  return __builtin_ffs(n) - 1;
}
template <qword_fittable Tp>
constexpr int
id44(Tp n) {
  return __builtin_ffsll(n) - 1;
}
template <dword_fittable Tp>
constexpr int
bit_width(Tp n) {
  return 32 - id27(n);
}
template <qword_fittable Tp>
constexpr int
bit_width(Tp n) {
  return 64 - id27(n);
}
template <dword_fittable Tp>
constexpr Tp
bit_floor(Tp n) {
  return 1u << (31 - id27(n));
}
template <qword_fittable Tp>
constexpr Tp
bit_floor(Tp n) {
  return 1ull << (63 - id27(n));
}
template <integer Tp>
constexpr Tp
id0(Tp n) {
  if (n == 0 || n == 1) { return 1; }
  return bit_floor(n - 1) << 1;
}
template <dword_fittable Tp>
constexpr int
id36(Tp n) {
  return 31 - id27(n);
}
template <qword_fittable Tp>
constexpr int
id36(Tp n) {
  return 63 - id27(n);
}
template <integer Tp>
constexpr int
id38(Tp n) {
  if (n == 0 || n == 1) { return 0; }
  return id36(n - 1) + 1;
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
  const int s = id47(n - 1);
  const Tp d = (n - 1) >> s;
  constexpr Tp primes[] = {2, 3, 5, 7};
  for (Tp p : primes) {
    Tp x = id25(p, d, n);
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
  const int s = id47(n - 1);
  const Tp d = (n - 1) >> s;
  constexpr Tp primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
  for (Tp p : primes) {
    Tp x = id25(p, d, n);
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
id33(int n) noexcept {
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
id14(int n) noexcept {
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
namespace detail {
template <integer T1, integer T2>
constexpr std::common_type_t<T1, T2>
inv_mod(T1 a, T2 m) {
  auto r = id29(a, m);
  auto x = r.first % m;
  if (x < 0) x += m;
  return x;
}
template <integer T1, integer T2, integer T3>
std::optional<std::common_type_t<T1, T2, T3>>
id16(T1 a, T2 b, T3 m) {
  using common_t = std::common_type_t<T1, T2, T3>;
  common_t a0 = a, b0 = b, m0 = m;
  if ((a0 %= m0) < 0) { a0 += m0; }
  if ((b0 %= m0) < 0) { b0 += m0; }
  const common_t n = sqrt(m0);
  assume(a0 >= 0 && a0 < m0);
  const common_t an = id25(a0, n, m0);
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
  Tp phi_n = id19(n);
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
      if (id25(g, phi / divs[p], n) == 1) {
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
id9(Tp n) {
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
      if (id25(g, (n - 1) / divs[i], n) == 1) {
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
id15(T1 a, T2 b, T3 n) {
  using common_t = std::common_type_t<T1, T2, T3>;
  common_t a0 = a, b0 = b, n0 = n;
  const common_t g = id9(n0);
  const common_t ga = id25(g, a0, n0);
  std::optional y = id16(ga, b0, n0);
  return y.has_value() ? std::optional(id25(g, y.value(), n0))
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
namespace detail {
namespace fft {
template <int MOD>
constexpr int k = id47(MOD - 1);
template <int MOD>
constexpr int c = (MOD - 1) >> (k<MOD>);
template <int MOD>
constexpr int g = id9(MOD);
template <int MOD>
constexpr int minv = inv_mod(MOD, 0x100000000);
template <int MOD, bool Inverse>
constexpr std::array<std::array<int, 17>, k<MOD> + 1> id10 = [] {
  std::array<std::array<int, 17>, k<MOD> + 1> ans = {{}};
  ans[k<MOD>][0] = 1;
  ans[k<MOD>][1] = id25(g<MOD>, c<MOD>, MOD);
  if constexpr (Inverse) { ans[k<MOD>][1] = inv_mod(ans[k<MOD>][1], MOD); }
  for (int i = 2; i < 17; ++i) {
    ans[k<MOD>][i] =
        static_cast<safe_mul_t<int>>(ans[k<MOD>][i - 1]) * ans[k<MOD>][1] % MOD;
  }
  for (int i = k<MOD> - 1; i >= 0; --i) {
    ans[i][0] = 1;
    ans[i][1] =
        static_cast<safe_mul_t<int>>(ans[i + 1][1]) * ans[i + 1][1] % MOD;
    for (int j = 2; j < 17; ++j) {
      ans[i][j] = static_cast<safe_mul_t<int>>(ans[i][j - 1]) * ans[i][1] % MOD;
    }
  }
  for (int i = 0; i <= k<MOD>; ++i) {
    for (int j = 0; j < 17; ++j) {
      ans[i][j] = (static_cast<safe_mul_t<int>>(ans[i][j]) << 32) % MOD;
    }
  }
  return ans;
}();
}
static inline __m256i
id5(__m256i A, __m256i B, __m256i M, __m256i Mi) {
  __m256i id12 = _mm256_mul_epu32(A, B);
  __m256i id34 = _mm256_mul_epu32(
      _mm256_srli_si256(A, 0b100),
      _mm256_srli_si256(B, 0b100));
  __m256i qlo = _mm256_mul_epu32(id12, Mi);
  __m256i qhi = _mm256_mul_epu32(id34, Mi);
  __m256i tmplo = _mm256_mul_epu32(qlo, M);
  __m256i tmphi = _mm256_mul_epu32(qhi, M);
  __m256i alo = _mm256_sub_epi32(id12, tmplo);
  __m256i ahi = _mm256_sub_epi32(id34, tmphi);
  __m256i d = _mm256_unpackhi_epi32(_mm256_shuffle_epi32(alo, _MM_SHUFFLE(3, 1, 2, 0)),
                                    _mm256_shuffle_epi32(ahi, _MM_SHUFFLE(3, 1, 2, 0)));
  return _mm256_add_epi32(d, _mm256_and_si256(_mm256_srai_epi32(d, 0x1F), M));
}
static inline __m256i
id40(__m256i A, __m256i M, __m256i Mi) {
  __m256i qlo = _mm256_mul_epu32(A, Mi);
  __m256i qhi = _mm256_mul_epu32(_mm256_srli_si256(A, 0x04), Mi);
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
id31(__m256i A, __m256i B, __m256i M) {
  __m256i d = _mm256_sub_epi32(_mm256_add_epi32(A, B), M);
  return _mm256_add_epi32(d, _mm256_and_si256(_mm256_srai_epi32(d, 0x1F), M));
}
static inline __m256i
id3(__m256i A, __m256i B, __m256i M) {
  return id31(A, _mm256_sub_epi32(M, B), M);
}
template <int MOD, bool Inverse>
static inline void
id23(int *out, int n) noexcept {
  constexpr int minv = fft::minv<MOD>;
  constexpr auto id10 = fft::id10<MOD, Inverse>;
  const __m256i reg_m = _mm256_set1_epi32(MOD);
  const __m256i id32 = _mm256_set1_epi32(minv);
  const __m256i id7 = _mm256_set1_epi32(id10[1][0]);
  const __m256i id37 =
      _mm256_set_epi32(id10[2][1], id10[2][0], id10[2][1], id10[2][0], id10[2][1],
                       id10[2][0], id10[2][1], id10[2][0]);
  const __m256i id48 =
      _mm256_set_epi32(id10[3][3], id10[3][2], id10[3][3], id10[3][2], id10[3][1],
                       id10[3][0], id10[3][1], id10[3][0]);
  const __m256i id41 =
      _mm256_set_epi32(id10[4][7], id10[4][6], id10[4][5], id10[4][4], id10[4][3],
                       id10[4][2], id10[4][1], id10[4][0]);
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
    u1 = id5(u1, id7, reg_m, id32);
    v0 = id31(u0, u1, reg_m);
    v1 = id3(u0, u1, reg_m);
    u0 = _mm256_unpacklo_epi32(v0, v1);
    u1 = _mm256_unpackhi_epi32(v0, v1);
    u1 = id5(u1, id37, reg_m, id32);
    v0 = id31(u0, u1, reg_m);
    v1 = id3(u0, u1, reg_m);
    u0 = _mm256_permute2x128_si256(v0, v1, 0x20);
    u1 = _mm256_permute2x128_si256(v0, v1, 0x31);
    u1 = id5(u1, id48, reg_m, id32);
    v0 = id31(u0, u1, reg_m);
    v1 = id3(u0, u1, reg_m);
    u0 = _mm256_unpacklo_epi64(v0, v1);
    u1 = _mm256_unpackhi_epi64(v0, v1);
    v0 = _mm256_permute4x64_epi64(u0, _MM_SHUFFLE(3, 1, 2, 0));
    v1 = _mm256_permute4x64_epi64(u1, _MM_SHUFFLE(3, 1, 2, 0));
    v1 = id5(v1, id41, reg_m, id32);
    _mm256_store_si256((__m256i *)&out[i], id31(v0, v1, reg_m));
    _mm256_store_si256((__m256i *)&out[i + 8], id3(v0, v1, reg_m));
  }
  for (int lg = 5, l = 32; l <= n; ++lg, l <<= 1) {
    const __m256i reg_stride = _mm256_set1_epi32(id10[lg][16]);
    const __m256i id46 =
        _mm256_set_epi32(id10[lg][7], id10[lg][6], id10[lg][5], id10[lg][4],
                         id10[lg][3], id10[lg][2], id10[lg][1], id10[lg][0]);
    const __m256i reg_sec =
        _mm256_set_epi32(id10[lg][15], id10[lg][14], id10[lg][13], id10[lg][12],
                         id10[lg][11], id10[lg][10], id10[lg][9], id10[lg][8]);
    for (int i = 0; i < n; i += l) {
      __m256i id43 = id46;
      __m256i reg_ws = reg_sec;
      for (int j = 0; j < (l >> 1); j += 16) {
        __m256i v0 = _mm256_load_si256((__m256i *)&out[i + j]);
        __m256i v1 = _mm256_load_si256((__m256i *)&out[i + j + 8]);
        __m256i v2 = _mm256_load_si256((__m256i *)&out[i + j + (l >> 1)]);
        __m256i v3 = _mm256_load_si256((__m256i *)&out[i + j + (l >> 1) + 8]);
        v2 = id5(v2, id43, reg_m, id32);
        v3 = id5(v3, reg_ws, reg_m, id32);
        _mm256_store_si256((__m256i *)&out[i + j], id31(v0, v2, reg_m));
        _mm256_store_si256((__m256i *)&out[i + j + 8], id31(v1, v3, reg_m));
        _mm256_store_si256((__m256i *)&out[i + j + (l >> 1)], id3(v0, v2, reg_m));
        _mm256_store_si256((__m256i *)&out[i + j + (l >> 1) + 8], id3(v1, v3, reg_m));
        id43 = id5(id43, reg_stride, reg_m, id32);
        reg_ws = id5(reg_ws, reg_stride, reg_m, id32);
      }
    }
  }
  if constexpr (Inverse) {
    const int ninv =
        (static_cast<safe_mul_t<int>>(inv_mod(n, MOD)) << 32) % MOD;
    const __m256i id42 = _mm256_set1_epi32(ninv);
    for (int i = 0; i < n; i += 16) {
      __m256i v0 = _mm256_load_si256((__m256i *)&out[i]);
      __m256i v1 = _mm256_load_si256((__m256i *)&out[i + 8]);
      _mm256_store_si256((__m256i *)&out[i],
                         id5(v0, id42, reg_m, id32));
      _mm256_store_si256((__m256i *)&out[i + 8],
                         id5(v1, id42, reg_m, id32));
    }
  }
}
template <int MOD>
inline static void
convolution(int *__restrict__ c1, int *__restrict__ c2, int n) noexcept {
  constexpr int minv = fft::minv<MOD>;
  constexpr int rsq = (-static_cast<uint64_t>(MOD)) % MOD;
  const __m256i reg_m = _mm256_set1_epi32(MOD);
  const __m256i id32 = _mm256_set1_epi32(minv);
  const __m256i id39 = _mm256_set1_epi32(rsq);
  c1 = std::assume_aligned<32>(c1);
  c2 = std::assume_aligned<32>(c2);
  for (int i = 0; i < n; i += 16) {
    __m256i v0 = _mm256_load_si256((__m256i *)&c1[i]);
    __m256i v1 = _mm256_load_si256((__m256i *)&c1[i + 8]);
    __m256i u0 = _mm256_load_si256((__m256i *)&c2[i]);
    __m256i u1 = _mm256_load_si256((__m256i *)&c2[i + 8]);
    _mm256_store_si256((__m256i *)&c1[i],
                       id5(v0, id39, reg_m, id32));
    _mm256_store_si256((__m256i *)&c1[i + 8],
                       id5(v1, id39, reg_m, id32));
    _mm256_store_si256((__m256i *)&c2[i],
                       id5(u0, id39, reg_m, id32));
    _mm256_store_si256((__m256i *)&c2[i + 8],
                       id5(u1, id39, reg_m, id32));
  }
  id23<MOD, false>(c1, n);
  id23<MOD, false>(c2, n);
  for (int i = 0; i < n; i += 16) {
    __m256i v0 = _mm256_load_si256((__m256i *)&c1[i]);
    __m256i v1 = _mm256_load_si256((__m256i *)&c1[i + 8]);
    __m256i u0 = _mm256_load_si256((__m256i *)&c2[i]);
    __m256i u1 = _mm256_load_si256((__m256i *)&c2[i + 8]);
    _mm256_store_si256((__m256i *)&c1[i],
                       id5(v0, u0, reg_m, id32));
    _mm256_store_si256((__m256i *)&c1[i + 8],
                       id5(v1, u1, reg_m, id32));
    _mm256_store_si256((__m256i *)&c2[i], _mm256_setzero_si256());
    _mm256_store_si256((__m256i *)&c2[i + 8], _mm256_setzero_si256());
  }
  id23<MOD, true>(c1, n);
  for (int i = 0; i < n; i += 16) {
    __m256i v0 = _mm256_load_si256((__m256i *)&c1[i]);
    __m256i v1 = _mm256_load_si256((__m256i *)&c1[i + 8]);
    _mm256_store_si256((__m256i *)&c1[i],
                       id40(v0, reg_m, id32));
    _mm256_store_si256((__m256i *)&c1[i + 8],
                       id40(v1, reg_m, id32));
  }
}
template <int MOD, int MOD1 = 167772161, int MOD2 = 469762049, int MOD3 = 754974721>
static inline void
id13(int *__restrict__ c1, int *__restrict__ c2, int *__restrict__ c3,
             int *__restrict__ out, int n) noexcept
    requires(MOD1 < MOD2 && MOD2 < MOD3) {
  constexpr int inv12 = inv_mod(MOD1, MOD2);
  constexpr int inv13 = inv_mod(MOD1, MOD3);
  constexpr int inv23 = inv_mod(MOD2, MOD3);
  constexpr int id1 = (static_cast<safe_mul_t<int>>(inv12) << 32) % MOD2;
  constexpr int id4 = (static_cast<safe_mul_t<int>>(inv13) << 32) % MOD3;
  constexpr int id28 = (static_cast<safe_mul_t<int>>(inv23) << 32) % MOD3;
  constexpr int co1 = (-static_cast<uint32_t>(MOD)) % MOD;
  constexpr int co2 = (static_cast<safe_mul_t<int>>(co1) * MOD1) % MOD;
  constexpr int co3 = (static_cast<safe_mul_t<int>>(co2) * MOD2) % MOD;
  constexpr int id24 = fft::minv<MOD2>;
  constexpr int id30 = fft::minv<MOD3>;
  constexpr int minv = fft::minv<MOD>;
  const __m256i id11 = _mm256_set1_epi32(id1);
  const __m256i id49 = _mm256_set1_epi32(id4);
  const __m256i id20 = _mm256_set1_epi32(id28);
  const __m256i id17 = _mm256_set1_epi32(co1);
  const __m256i id6 = _mm256_set1_epi32(co2);
  const __m256i id22 = _mm256_set1_epi32(co3);
  const __m256i id21 = _mm256_set1_epi32(MOD2);
  const __m256i id35 = _mm256_set1_epi32(MOD3);
  const __m256i reg_m = _mm256_set1_epi32(MOD);
  const __m256i id18 = _mm256_set1_epi32(id24);
  const __m256i id26 = _mm256_set1_epi32(id30);
  const __m256i id32 = _mm256_set1_epi32(minv);
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
    x2 = id5(id3(x2, x1, id21), id11, id21, id18);
    y2 = id5(id3(y2, y1, id21), id11, id21, id18);
    __m256i tmp1 = id5(id3(x3, x1, id35), id49, id35, id26);
    __m256i tmp2 = id5(id3(y3, y1, id35), id49, id35, id26);
    x3 = id5(id3(tmp1, x2, id35), id20, id35, id26);
    y3 = id5(id3(tmp2, y2, id35), id20, id35, id26);
    x1 = id5(x1, id17, reg_m, id32);
    y1 = id5(y1, id17, reg_m, id32);
    x2 = id5(x2, id6, reg_m, id32);
    y2 = id5(y2, id6, reg_m, id32);
    x3 = id5(x3, id22, reg_m, id32);
    y3 = id5(y3, id22, reg_m, id32);
    x2 = id31(x1, x2, reg_m);
    y2 = id31(y1, y2, reg_m);
    x3 = id31(x2, x3, reg_m);
    y3 = id31(y2, y3, reg_m);
    _mm256_storeu_si256((__m256i *)&out[i], x3);
    _mm256_storeu_si256((__m256i *)&out[i + 8], y3);
  }
}
}
template <int MOD, size_t MAXN = (1 << 23)>
struct poly {
public:
  using mint_type = modint<MOD>;
  poly() = default;
  poly(const std::vector<int> &vec) : _c(vec.begin(), vec.end()) {
    _normalize();
  }
  poly(const std::vector<mint_type> &vec) : _c(vec) { _normalize(); }
  poly(std::vector<mint_type> &&vec) noexcept : _c(move(vec)) { _normalize(); }
  poly(std::initializer_list<int> lst) : _c(lst.begin(), lst.end()) {
    _normalize();
  }
  poly(std::initializer_list<mint_type> lst) : _c(lst) { _normalize(); }
  poly &
  operator+=(const poly &rhs) {
    if (size() < rhs.size()) { _c.resize(rhs.size()); }
    for (int i = 0; i < rhs.size(); ++i) { _c[i] += rhs._c[i]; }
    _normalize();
    return *this;
  }
  poly &
  operator+=(mint_type x) {
    if (detail::unlikely(size() == 0)) { _c.emplace_back(0); }
    _c[0] += x;
    _normalize();
    return *this;
  }
  poly &
  operator-=(const poly &rhs) {
    if (size() < rhs.size()) { _c.resize(rhs.size()); }
    for (int i = 0; i < rhs.size(); ++i) { _c[i] -= rhs._c[i]; }
    _normalize();
    return *this;
  }
  poly &
  operator-=(mint_type x) {
    if (detail::unlikely(size() == 0)) { _c.emplace_back(0); }
    _c[0] -= x;
    _normalize();
    return *this;
  }
  poly &
  operator*=(const poly &rhs) noexcept {
    if (size() <= 128 || rhs.size() <= 128) {
      _mul_naive(rhs);
    } else {
      _mul_fft(rhs);
    }
    return *this;
  }
  poly &
  operator*=(mint_type x) {
    for (int i = 0; i < size(); ++i) { _c[i] *= x; }
    _normalize();
    return *this;
  }
  poly
  operator-() const {
    poly res(*this);
    transform(res._c.begin(), res._c.end(), res._c.begin(),
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
    return i < size() ? _c[i] : 0;
  }
  mint_type
  operator()(mint_type x) const {
    mint_type ans = 0;
    for (int i = size() - 1; i >= 0; --i) {
      ans *= x;
      ans += _c[i];
    }
    return ans;
  }
  poly
  mul_xk(int k) const noexcept {
    detail::assume(k >= 0);
    std::vector<mint_type> out(k + size());
    copy(_c.begin(), _c.end(), out.begin() + k);
    return out;
  }
  poly
  mod_xk(int k) const noexcept {
    detail::assume(k >= 0);
    return std::vector(_c.begin(), _c.begin() + std::min(k, size()));
  }
  poly
  div_xk(int k) const noexcept {
    detail::assume(k >= 0);
    return std::vector(_c.begin() + std::min(k, size()), _c.end());
  }
  poly
  inv(int n) const noexcept {
    int a = 1;
    poly ans = {_c[0].inv()};
    while (a < n) {
      poly c = (ans * mod_xk(a << 1)).mod_xk(a << 1).div_xk(a);
      ans -= (ans * c).mod_xk(a).mul_xk(a);
      a <<= 1;
    }
    return ans.mod_xk(n);
  }
  int
  deg() const {
    return size() - 1;
  }
  int
  size() const {
    return ssize(_c);
  }
  friend std::ostream &
  operator<<(std::ostream &os, const poly &p) noexcept {
    for (int i = 0; i < p.size(); ++i) {
      if (i) os << ' ';
      os << p._c[i];
    }
    if (p.size() == 0) { os << 0; }
    return os;
  }
  bool
  is_zero() const {
    return _c.empty();
  }
private:
  void
  _normalize() noexcept {
    while (!_c.empty() && _c.back() == 0) { _c.pop_back(); }
  }
  void
  _mul_naive(const poly &rhs) noexcept {
    if (detail::unlikely(rhs.size() == 0 || size() == 0)) {
      _c.clear();
    } else {
      const int n1 = size();
      const int n2 = rhs.size();
      const int n = n1 + n2 - 1;
      for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
          _buf4[i + j] += (_c[i] * rhs._c[j]).val() - MOD;
          _buf4[i + j] += (_buf4[i + j] >> 31) & MOD;
        }
      }
      _c.resize(n);
      for (int i = 0; i < n; ++i) {
        _c[i] = mint_type::from(_buf4[i]);
        _buf4[i] = 0;
      }
      _normalize();
    }
  }
  void
  _mul_fft(const poly &rhs) noexcept {
    constexpr int MOD1 = 167772161;
    constexpr int MOD2 = 469762049;
    constexpr int MOD3 = 754974721;
    const int n1 = size();
    const int n2 = rhs.size();
    const int n = detail::id0(n1 + n2 - 1);
    std::fill_n(_buf1 + n1, n, 0);
    std::fill_n(_buf2 + n1, n, 0);
    std::fill_n(_buf3 + n1, n, 0);
    {
      std::copy_n(reinterpret_cast<const int *>(_c.data()), n1, _buf1);
      std::copy_n(reinterpret_cast<const int *>(rhs._c.data()), n2, _buf4);
      detail::convolution<MOD1>(_buf1, _buf4, n);
    }
    {
      std::copy_n(reinterpret_cast<const int *>(_c.data()), n1, _buf2);
      std::copy_n(reinterpret_cast<const int *>(rhs._c.data()), n2, _buf4);
      detail::convolution<MOD2>(_buf2, _buf4, n);
    }
    {
      std::copy_n(reinterpret_cast<const int *>(_c.data()), n1, _buf3);
      std::copy_n(reinterpret_cast<const int *>(rhs._c.data()), n2, _buf4);
      detail::convolution<MOD3>(_buf3, _buf4, n);
    }
    _c.resize(n);
    detail::id13<MOD>(_buf1, _buf2, _buf3, (int *)_c.data(), n);
    _normalize();
  }
  std::vector<mint_type> _c;
  alignas(32) static inline int _buf1[MAXN];
  alignas(32) static inline int _buf2[MAXN];
  alignas(32) static inline int _buf3[MAXN];
  alignas(32) static inline int _buf4[MAXN];
};
template <int MOD>
poly(const std::vector<algo::modint<MOD>> &) -> poly<MOD>;
template <int MOD>
poly(std::vector<algo::modint<MOD>> &&) -> poly<MOD>;
}
namespace algo {
  template struct modint<998244353>;
  template struct modint<1000000007>;
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
