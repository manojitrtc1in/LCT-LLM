








namespace dbg {

}
namespace algo {
namespace base {
template <typename _Tp>
concept integer = std::integral<_Tp> && !std::same_as<_Tp, bool>;
template <typename _Tp>
concept addable = requires(std::remove_reference_t<_Tp> &a,
                           const std::remove_reference_t<_Tp> &b) {
  { a += b }
  ->std::same_as<std::remove_reference_t<_Tp> &>;
};
template <typename _Tp>
concept multipliable = requires(std::remove_reference_t<_Tp> &a,
                                const std::remove_reference_t<_Tp> &b) {
  { a *= b }
  ->std::same_as<std::remove_reference_t<_Tp> &>;
};
template <typename _Fn>
struct function_traits : public function_traits<decltype(
                             &std::remove_reference_t<_Fn>::operator())> {};
template <typename _Fn, typename _Ret, typename... _Args>
struct function_traits<_Ret (_Fn::*)(_Args...) const> {
  static constexpr size_t arity = sizeof...(_Args);
  using result_type = _Ret;
  template <size_t I>
  struct arg {
    using type = typename std::tuple_element<I, std::tuple<_Args...>>::type;
  };
};
template <typename _Ret, typename... _Args>
struct function_traits<_Ret (*)(_Args...)> {
  static constexpr size_t arity = sizeof...(_Args);
  using result_type = _Ret;
  template <size_t I>
  struct arg {
    using type = typename std::tuple_element<I, std::tuple<_Args...>>::type;
  };
};
template <typename _Ret, typename... _Args>
struct function_traits<_Ret(_Args...)> {
  static constexpr size_t arity = sizeof...(_Args);
  using result_type = _Ret;
  template <size_t I>
  struct arg {
    using type = typename std::tuple_element<I, std::tuple<_Args...>>::type;
  };
};
template <typename _Fn>
using extract_return_t = typename function_traits<_Fn>::result_type;
template <typename _Fn, typename _Ret, typename... _Args>
concept callable = std::invocable<_Fn, _Args...>
    &&std::same_as<std::invoke_result_t<_Fn, _Args...>, _Ret>;
template <typename _Fn, typename _Arg>
concept unary_op = callable<_Fn, _Arg, _Arg>;
template <typename _Fn, typename _Arg>
concept binary_op = callable<_Fn, _Arg, _Arg, _Arg>;
template <typename _Fn, typename _Arg>
concept unary_predicate = callable<_Fn, bool, _Arg>;
template <typename _Tp>
concept less_than_comparable = requires(const std::remove_reference_t<_Tp> &a,
                                        const std::remove_reference_t<_Tp> &b) {
  { a < b }
  ->std::convertible_to<bool>;
  { !(a < b) }
  ->std::convertible_to<bool>;
};
template <typename _Tp>
concept equality_comparable = std::equality_comparable<_Tp>;
template <typename _From, typename _To>
concept constructible = std::constructible_from<_To, _From>;
template <typename _Iter, typename _Value>
concept input_iterator =
    std::input_iterator<_Iter> &&std::same_as<std::iter_value_t<_Iter>, _Value>;
template <typename _Tp>
concept qword_fittable = integer<_Tp> && sizeof(_Tp) <= 8UL;
template <typename _Tp>
concept dword_fittable = qword_fittable<_Tp> && sizeof(_Tp) <= 4UL;
template <typename _Tp>
concept word_fittable = dword_fittable<_Tp> && sizeof(_Tp) <= 2UL;
template <typename _Tp>
concept byte_fittable = word_fittable<_Tp> && sizeof(_Tp) == 1UL;
template <integer _Tp>
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
template <typename _Tp>
using safe_mul_t = typename safely_multipliable<_Tp>::type;
}
}
namespace algo {
namespace base {
template <typename _Tp>
constexpr _Tp
id16(const _Tp &a, const _Tp &b) {
  return a < b ? b : a;
}
template <typename _Tp>
constexpr _Tp
__mini(const _Tp &a, const _Tp &b) {
  return a < b ? a : b;
}
template <typename _Tp>
constexpr void
__swap(_Tp &a, _Tp &b) {
  _Tp tp = a;
  a = b;
  b = tp;
}
template <typename _Tp>
constexpr void
__swap(_Tp *a, _Tp *b) {
  _Tp tp = *a;
  *a = *b;
  *b = tp;
}
}
}
namespace algo {
namespace base {
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
template <base::less_than_comparable _Tp>
constexpr _Tp max(const _Tp &a, const _Tp &b) {
  return base::id16(a, b);
}
template <base::less_than_comparable _Tp>
constexpr _Tp min(const _Tp &a, const _Tp &b) {
  return base::__mini(a, b);
}
template <base::less_than_comparable _Tp>
std::vector<int> argsort(const std::vector<_Tp> &v) {
  std::vector<int> ind(v.size());
  std::iota(ind.begin(), ind.end(), 0);
  std::sort(ind.begin(), ind.end(),
            [&v](int a, int b) -> bool { return v[a] < v[b]; });
  return ind;
}
template <base::less_than_comparable _Tp>
void id22(std::vector<_Tp> &vec) noexcept {
  std::sort(vec.begin(), vec.end());
  vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
}
template <base::less_than_comparable _Tp>
int argmin(const std::vector<_Tp> &v) {
  const int n = (int)v.size();
  int j = -1;
  for (int i = 0; i < n; ++i) {
    if (base::unlikely(j == -1 || v[j] < v[i])) { j = i; }
  }
  return j;
}
template <base::less_than_comparable _Tp>
int argmax(const std::vector<_Tp> &v) {
  const int n = (int)v.size();
  int j = -1;
  for (int i = 0; i < n; ++i) {
    if (base::unlikely(j == -1 || v[j] < v[i])) { j = i; }
  }
  return j;
}
template <base::integer _Tp, base::unary_predicate<_Tp> _Pred>
constexpr _Tp bisect(_Tp low, _Tp high, _Pred &&pred) {
  while (low < high) {
    _Tp mid = low + high >> 1;
    pred(mid) ? low = mid + 1 : high = mid;
  }
  return low;
}
template <base::less_than_comparable _Tp>
int lower_bound(const std::vector<_Tp> &vec, const _Tp &x) {
  return (int)std::distance(vec.begin(),
                            std::lower_bound(vec.begin(), vec.end(), x));
}
template <base::less_than_comparable _Tp>
int upper_bound(const std::vector<_Tp> &vec, const _Tp &x) {
  return (int)std::distance(vec.begin(),
                            std::upper_bound(vec.begin(), vec.end(), x));
}
void inverse(std::vector<int> &perm) {
  const int n = (int)perm.size();
  std::vector<int> out(n);
  for (int i = 0; i < n; ++i) { out[perm[i]] = i; }
  perm = std::move(out);
}
template <typename _Tp>
void permute(std::vector<_Tp> &vec, const std::vector<int> &perm) {
  std::vector<_Tp> out(vec.size());
  const int n = (int)vec.size();
  for (int i = 0; i < n; ++i) { out[perm[i]] = vec[i]; }
  vec = std::move(out);
}
constexpr auto id5(base::integer auto n) {
  return -(n & 1) | 1;
}
constexpr int id5(bool n) {
  return -(int)(n) | 1;
}
}
namespace algo {
namespace base {
template <multipliable _Tp, integer _Up>
constexpr _Tp
id21(_Tp a, _Up b) {
  _Tp res(1);
  while (b) {
    if (b & 0x01) { res *= a; }
    a *= a;
    b >>= 1;
  }
  return res;
}
template <multipliable _T1, constructible<_T1> _T2, integer _Up>
constexpr _T1
id21(_T1 a, _Up b, const _T2 &init) {
  _T1 res = init;
  while (b) {
    if (b & 0x01) { res *= a; }
    a *= a;
    b >>= 1;
  }
  return res;
}
template <integer _Tp>
constexpr _Tp
id18(_Tp n) {
  _Tp ans = n;
  if (!(n & 0x01)) {
    ans >>= 1;
    do { n >>= 1; } while (!(n & 0x01));
  }
  for (_Tp i = 3; i * i <= n; i += 2) {
    if (_Tp x = n / i; n - x * i == 0) {
      ans -= ans / i;
      do { n = x, x /= i; } while (n - x * i == 0);
    }
  }
  if (n > 1) { ans -= ans / n; }
  return ans;
}
template <integer _Tp>
constexpr _Tp
id0(_Tp n) {
  if (n == 1) { return 1; }
  int cnt = 0;
  if (!(n & 0x01)) {
    n >>= 1;
    if (!(n & 0x01)) { return 0; }
    cnt++;
  }
  for (_Tp i = 3; i * i <= n; i += 2) {
    if (_Tp x = n / i; n - x * i == 0) {
      n = x;
      if (n % i == 0) { return 0; }
      cnt++;
    }
  }
  return (cnt & 0x01) ? -1 : 1;
}
template <integer _T1, integer _T2>
constexpr std::pair<std::common_type_t<_T1, _T2>, std::common_type_t<_T1, _T2>>
id9(_T1 a, _T2 b) {
  using common_t = std::common_type_t<_T1, _T2>;
  common_t x0 = 1, y0 = 0, x1 = 0, y1 = 1, a0 = a, b0 = b;
  while (b0) {
    common_t q = a0 / b0, tp = x0;
    x0 = x1, x1 = tp - q * x1, tp = y0, y0 = y1, y1 = tp - q * y1, tp = a0,
    a0 = b0, b0 = tp - q * b0;
  }
  if (a0 < 0) { x0 = -x0, a0 = -a0; }
  return std::make_pair(x0, a0);
}
template <integer _T1, integer _T2, integer _Up>
constexpr std::common_type_t<_T1, _T2>
id24(_T1 a, _Up b, _T2 m) {
  using common_t = std::common_type_t<_T1, _T2>;
  common_t ans(1), mul(a), mod(m);
  mul %= mod;
  if (mul < 0) mul += mod;
  while (b) {
    if (b & 0x01) { ans = safe_mul_t<common_t>(mul) * ans % mod; }
    mul = safe_mul_t<common_t>(mul) * mul % mod;
    b >>= 1;
  }
  return ans;
}
}
}
namespace algo {
namespace base {


constexpr int
__sqrt(int n) {
  int p = 32 - __builtin_clz(n);
  int ans = p & 0x01;
  for (p >>= 1, p &= ~1u; p >= 0; --p) {
    ans <<= 1;
    if ((ans + 1) * 1ll * (ans + 1) <= (n >> (p << 1))) { ans |= 1; }
  }
  return ans;
}
constexpr long long
__sqrt(long long n) {
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
namespace base {
template <dword_fittable _Tp>
constexpr int
id28(_Tp n) {
  return __builtin_clz(n);
}
template <qword_fittable _Tp>
constexpr int
id28(_Tp n) {
  return __builtin_clzll(n);
}
template <dword_fittable _Tp>
constexpr int
id1(_Tp n) {
  return __builtin_ctz(n);
}
template <qword_fittable _Tp>
constexpr int
id1(_Tp n) {
  return __builtin_ctzll(n);
}
template <dword_fittable _Tp>
constexpr int
id13(_Tp n) {
  return 32 - id28(n);
}
template <qword_fittable _Tp>
constexpr int
id13(_Tp n) {
  return 64 - id28(n);
}
template <dword_fittable _Tp>
constexpr _Tp
id23(_Tp n) {
  return 1u << (31 - id28(n));
}
template <qword_fittable _Tp>
constexpr _Tp
id23(_Tp n) {
  return 1ull << (63 - id28(n));
}
template <integer _Tp>
constexpr _Tp
id26(_Tp n) {
  if (n == 0 || n == 1) { return 1; }
  return id23(n - 1) << 1;
}
template <dword_fittable _Tp>
constexpr int
id12(_Tp n) {
  return 31 - id28(n);
}
template <qword_fittable _Tp>
constexpr int
id12(_Tp n) {
  return 63 - id28(n);
}
template <integer _Tp>
constexpr int
id29(_Tp n) {
  if (n == 0 || n == 1) { return 0; }
  return id12(n - 1) + 1;
}
template <dword_fittable _Tp>
constexpr int
id3(_Tp n) {
  return __builtin_popcount(n);
}
template <qword_fittable _Tp>
constexpr int
id3(_Tp n) {
  return __builtin_popcountll(n);
}
}
}
namespace algo {
namespace base {
template <dword_fittable _Tp>
constexpr bool
id4(_Tp n) {
  if (n <= 1) { return false; }
  if (n == 2 || n == 3 || n == 5 || n == 7) { return true; }
  const int s = id1(n - 1);
  const _Tp d = (n - 1) >> s;
  constexpr _Tp primes[] = {2, 3, 5, 7};
  for (_Tp p : primes) {
    _Tp x = id24(p, d, n);
    bool good = x == n - 1 || x == 1;
    for (int r = 1; r < s; ++r) {
      x = base::safe_mul_t<_Tp>(x) * x % n;
      good |= x == n - 1;
    }
    if (!good) { return false; }
  }
  return true;
}
template <qword_fittable _Tp>
constexpr bool
id4(_Tp n) {
  if (n <= 1) { return false; }
  if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17 ||
      n == 19 || n == 23 || n == 29 || n == 31 || n == 37) {
    return true;
  }
  const int s = id1(n - 1);
  const _Tp d = (n - 1) >> s;
  constexpr _Tp primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
  for (_Tp p : primes) {
    _Tp x = id24(p, d, n);
    bool good = x == n - 1 || x == 1;
    for (int r = 1; r < s; ++r) {
      x = base::safe_mul_t<_Tp>(x) * x % n;
      good |= x == n - 1;
    }
    if (!good) { return false; }
  }
  return true;
}
std::vector<int>
id20(int n) noexcept {
  constexpr int block = 30007;
  std::vector<int> primes;
  const int rn = __sqrt(n);
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
      for (int j = base::id16((start + p - 1) / p, p) * p - start; j < block;
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
id8(int n) noexcept {
  std::vector<int> phi(n + 1);
  std::iota(phi.begin(), phi.end(), 0);
  for (int i = 2; i <= n; ++i) {
    if (phi[i] == i) {
      for (int j = i; j <= n; j += i) { phi[j] -= phi[j] / i; }
    }
  }
  return phi;
}
std::vector<int>
id25(int n) noexcept {
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
template <base::multipliable _Tp, base::integer _Up>
constexpr _Tp
pow(_Tp a, _Up b) {
  base::assume(b >= 0);
  return base::id21(a, b);
}
template <base::integer _T1, base::constructible<_T1> _T2, base::integer _Up>
constexpr _T1
pow(_T1 a, _Up b, _T2 ini) {
  base::assume(b >= 0);
  return base::id21(a, b, ini);
}
template <base::integer _T1, base::integer _T2>
constexpr std::pair<std::common_type_t<_T1, _T2>, std::common_type_t<_T1, _T2>>
id14(_T1 a, _T2 b) {
  return base::id9(a, b);
}
template <base::integer _Tp>
constexpr _Tp
id11(_Tp n) {
  base::assume(n >= 0);
  return base::id18(n);
}
template <base::integer _Tp>
constexpr _Tp
mobius(_Tp n) {
  base::assume(n >= 0);
  return base::id0(n);
}
template <base::dword_fittable _Tp>
std::vector<int>
id10(_Tp n) {
  base::assume(n >= 0);
  return base::id8(n);
}
template <base::dword_fittable _Tp>
std::vector<int>
id2(_Tp n) {
  base::assume(n >= 0);
  return base::id25(n);
}
template <base::dword_fittable _Tp>
std::vector<int>
id15(_Tp n) {
  base::assume(n >= 0);
  return base::id20(n);
}
template <base::integer _Tp>
constexpr bool
prime_test(_Tp n) {
  return base::id4(n);
}
}
namespace algo {
namespace base {
template <integer _T1, integer _T2>
constexpr std::common_type_t<_T1, _T2>
id27(_T1 a, _T2 m) {
  auto r = id9(a, m);
  auto x = r.first % m;
  if (x < 0) x += m;
  return x;
}
template <integer _T1, integer _T2, integer _T3>
std::optional<std::common_type_t<_T1, _T2, _T3>>
id19(_T1 a, _T2 b, _T3 m) {
  using common_t = std::common_type_t<_T1, _T2, _T3>;
  common_t a0(a), b0(b), m0(m);
  if ((a0 %= m0) < 0) { a0 += m0; }
  if ((b0 %= m0) < 0) { b0 += m0; }
  const common_t n = __sqrt(m0);
  assume(a0 >= 0 && a0 < m0);
  const common_t an = id24(a0, n, m0);
  std::unordered_map<common_t, common_t> f2;
  for (common_t q = 0, now = b0; q <= n; ++q) {
    f2[now] = q;
    now = safe_mul_t<common_t>(now) * a0 % m0;
  }
  for (int p = 1, cur = 1; p <= n; ++p) {
    cur = safe_mul_t<common_t>(cur) * an % m0;
    if (f2.contains(cur)) { return std::optional(n * p - f2[cur]); }
  }
  return std::nullopt;
}
template <integer _Tp>
constexpr std::optional<_Tp>
id6(_Tp n) {
  _Tp phi_n = id18(n);
  const _Tp phi = phi_n;
  std::array<_Tp, 23> divs = {};
  int cnt = 0;
  if (!(phi_n & 0x01)) {
    divs[cnt++] = 2;
    do { phi_n >>= 1; } while (!(phi_n & 0x01));
  }
  for (_Tp i = 3; i * i <= phi_n; i += 2) {
    if (_Tp x = phi / i; phi_n - x * i == 0) {
      divs[cnt++] = i;
      do { phi_n = x, x /= i; } while (phi_n - x * i == 0);
    }
  }
  if (phi_n > 1) { divs[cnt++] = phi_n; }
  for (_Tp g = 1; g < n; ++g) {
    bool found = true;
    for (int p = 0; p < cnt; ++p) {
      if (id24(g, phi / divs[p], n) == 1) {
        found = false;
        break;
      }
    }
    if (found) { return std::optional(g); }
  }
  return n == 1 ? std::optional(1) : std::nullopt;
}
template <integer _Tp>
constexpr _Tp
id17(_Tp n) {
  if (n == 2) { return 1; }
  std::array<_Tp, 23> divs = {2};
  int cnt = 1;
  _Tp x = n - 1;
  do { x >>= 1; } while (!(x & 0x01));
  for (_Tp i = 3; i * i <= x; i += 2) {
    if (_Tp y = x / i; x - y * i == 0) {
      divs[cnt++] = i;
      do { x = y, y /= i; } while (x - y * i == 0);
    }
  }
  if (x > 1) { divs[cnt++] = x; }
  for (_Tp g = 2; g <= n; ++g) {
    bool found = true;
    for (int i = 0; i < cnt; ++i) {
      if (id24(g, (n - 1) / divs[i], n) == 1) {
        found = false;
        break;
      }
    }
    if (found) { return g; }
  }
  unreachable();
}
template <integer _T1, integer _T2, integer _T3>
std::optional<std::common_type_t<_T1, _T2, _T3>>
id7(_T1 a, _T2 b, _T3 n) {
  using common_t = std::common_type_t<_T1, _T2, _T3>;
  common_t a0(a), b0(b), n0(n);
  const common_t g = id17(n0);
  const common_t ga = id24(g, a0, n0);
  std::optional y = id19(ga, b0, n0);
  return y.has_value() ? std::optional(id24(g, y.value(), n0))
                       : std::nullopt;
}
std::vector<int>
__crt(const std::vector<int>& a, const std::vector<int>& p) {
  const int k = (int)p.size();
  std::vector<int> ans(k);
  ans[0] = a[0];
  for (int i = 1; i < k; ++i) {
    ans[i] = a[i];
    for (int j = 0; j < i; ++j) {
      ans[i] = (int)id27(p[j], p[i]) * 1ll * (ans[i] - ans[j]) % p[i];
      ans[i] += (ans[i] >> 31) & p[i];
    }
  }
  return ans;
}
}
}
namespace algo {
template <base::integer auto _MOD, bool _IsPrime = base::id4(_MOD)>
struct modint {
  using value_type = decltype(_MOD);
  constexpr modint() = default;
  template <base::integer _Up>
  constexpr modint(_Up val) : _M_val(static_cast<value_type>(val % _MOD)) {
    if (_M_val < 0) _M_val += _MOD;
  }
  constexpr modint &
  operator+=(const modint &rhs) {
    _M_val += rhs.val();
    if (_M_val >= _MOD) _M_val -= _MOD;
    return *this;
  }
  constexpr modint &
  operator-=(const modint &rhs) {
    return operator+=(-rhs);
  }
  constexpr modint &
  operator*=(const modint &rhs) {
    base::assume(val() >= 0 && val() < _MOD);
    base::assume(rhs.val() >= 0 && rhs.val() < _MOD);
    _M_val = base::safe_mul_t<value_type>(val()) * rhs.val() % _MOD;
    return *this;
  }
  constexpr modint &
  operator/=(const modint &rhs) {
    return operator*=(rhs.inv());
  }
  constexpr modint
  operator-() const {
    base::assume(0 <= val() && val() < _MOD);
    return val() ? _MOD - val() : 0;
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
  constexpr value_type
  val() const {
    return _M_val;
  }
  constexpr value_type
  mod() const {
    return _MOD;
  }
  constexpr modint
  inv() const {
    if constexpr (_IsPrime) {
      constexpr value_type ph = _MOD - 2;
      constexpr int bw = base::id13(ph);
      modint res(1), mul(*this);
      for (int i = 0; i < bw; ++i) {
        if ((ph >> i) & 0x01) { res *= mul; }
        mul *= mul;
      }
      return res;
    } else {
      value_type res = base::id27(val(), _MOD);
      base::assume(0 <= res && res < _MOD);
      return res;
    }
  }
  constexpr explicit operator int() const { return val(); }
  constexpr explicit operator bool() const { return val(); }
  constexpr explicit operator long() const { return val(); }
  constexpr explicit operator long long() const { return val(); }
  constexpr explicit operator unsigned int() const { return val(); }
  constexpr explicit operator unsigned long() const { return val(); }
  template <base::integer _Up>
  constexpr modint
  pow(_Up x) const {
    base::assume(x >= 0);
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
private:
  value_type _M_val = {0};
};
}
namespace algo {
template struct modint<998244353>;
template struct modint<1000000007>;
template struct modint<1000000009>;
}
namespace algo {
template <int _N>
struct sieve {
  constexpr sieve() : _lp{}, _cnt{} {
    constexpr int sqn = base::__sqrt(_N);
    _lp[1] = 1;
    for (int i = 2; i <= sqn; ++i) {
      if (!_lp[i]) {
        _lp[i] = i, _cnt++;
        for (int j = i * i; j <= _N; j += i) { _lp[j] = i; }
      }
    }
    for (int i = sqn + 1; i <= _N; ++i) {
      if (!_lp[i]) { _lp[i] = i, _cnt++; }
    }
  }
  constexpr int
  num_primes() const {
    return _cnt;
  }
  constexpr bool
  is_prime(int n) const {
    return _lp[n] == n;
  }
  std::vector<int>
  prime_list() const noexcept {
    std::vector<int> ans(_cnt);
    if constexpr (_N >= 2) { ans[0] = 2; }
    for (int i = 3, c = 1; i <= _N; i += 2) {
      if (_lp[i] == i) { ans[c++] = i; }
    }
    return ans;
  }
  std::vector<int>
  prime_list(int n) const noexcept {
    std::vector<int> ans;
    for (int i = 2; i <= n; ++i) {
      if (_lp[i] == i) { ans.emplace_back(i); }
    }
    return ans;
  }
  std::vector<std::pair<int, int>>
  factorize(int n) const noexcept {
    std::vector<std::pair<int, int>> ans{};
    while (n > 1) {
      int p = _lp[n];
      int cnt = 0;
      int x = n / p;
      do { n = x, x /= p, ++cnt; } while (n - x * p == 0);
      ans.emplace_back(p, cnt);
    }
    return ans;
  }
  std::vector<int>
  divisors(int n) const noexcept {
    std::vector<int> ans{1};
    int sz = 1;
    for (auto [p, c] : factorize(n)) {
      const int cur = sz;
      for (int i = 0; i < cur; ++i) {
        for (int j = 0, d = ans[i]; j < c; ++j, ++sz) {
          ans.emplace_back(d *= p);
        }
      }
    }
    return ans;
  }
private:
  std::array<int, _N + 1> _lp;
  int _cnt;
};
}
using namespace std;
using namespace std::literals;
using namespace __gnu_pbds;
template <typename _Tp, typename _Fn>
using ordered_set =
    tree<_Tp, null_type, _Fn, rb_tree_tag, tree_order_statistics_node_update>;
using uint = unsigned int;
template <typename _Key, typename _Value>
using umap = unordered_map<_Key, _Value>;
template <typename _Tp, typename _Fn = less<_Tp>>
using max_heap = priority_queue<_Tp, vector<_Tp>, _Fn>;
template <typename _Tp, typename _Fn = greater<_Tp>>
using min_heap = priority_queue<_Tp, vector<_Tp>, _Fn>;
template <typename _Value> using uset = unordered_set<_Value>;
using wint = long long int;




namespace {
  constexpr algo::sieve<MAXN-1>s;
  const vector phi=algo::id10(MAXN-1);
  array<vector<int>,MAXN>divs;
}
inline void solve() noexcept {
  for(int i=1;i<MAXN;++i){
    divs[i]=s.divisors(i);
  }
  int n;cin>>n;
  vector<int>arr(n+1,0);
  for(int i=1;i<=n;++i){cin>>arr[i];}
  algo::modint<MOD>ans=0;
  for(int d=1;d<=n;++d){
    unordered_map<int,int>cnt;
    for(int x=d;x<=n;x+=d){
      for(int r:divs[arr[x]]){
        cnt[r]++;
      }
    }
    algo::modint<MOD>pd=phi[d];
    for(auto&&[r,c]:cnt){
      ans+=pd*phi[r]*c*c;
    }
  }
  cout<<ans<<'\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(15);
  solve();
  return 0;
}
