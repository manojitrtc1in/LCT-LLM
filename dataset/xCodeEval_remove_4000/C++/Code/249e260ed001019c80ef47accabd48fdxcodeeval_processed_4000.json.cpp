














































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
template <>
struct imul_result<int64_t> {
  using type = __int128_t;
};
template <>
struct imul_result<uint64_t> {
  using type = __uint128_t;
};
template <>
struct imul_result<int32_t> {
  using type = int64_t;
};
template <>
struct imul_result<uint32_t> {
  using type = uint64_t;
};
template <>
struct imul_result<int16_t> {
  using type = int32_t;
};
template <>
struct imul_result<uint16_t> {
  using type = uint32_t;
};
template <>
struct imul_result<int8_t> {
  using type = int16_t;
};
template <>
struct imul_result<uint8_t> {
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
constexpr int id2(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::countl_zero<Up>(n);
}
template <typename Tp>
constexpr int id4(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::countr_zero<Up>(n);
}
template <typename Tp>
constexpr int bit_width(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::bit_width<Up>(n);
}
template <typename Tp>
constexpr Tp id5(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return static_cast<Tp>(std::bit_floor<Up>(n));
}
template <typename Tp>
constexpr Tp id3(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return static_cast<Tp>(std::bit_ceil<Up>(n));
}
template <typename Tp>
constexpr int id0(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  constexpr int Nd = std::numeric_limits<Up>::digits;
  return Nd - 1 - std::countl_zero<Up>(n);
}
template <typename Tp>
constexpr int id1(Tp n) {
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
constexpr int id2(Tp n) {
  return detail::id2(n);
}
template <detail::integer Tp>
constexpr int id4(Tp n) {
  return detail::id4(n);
}
template <detail::integer Tp>
constexpr int bit_width(Tp n) {
  return detail::bit_width(n);
}
template <detail::integer Tp>
constexpr Tp id5(Tp n) {
  return detail::id5(n);
}
template <detail::integer Tp>
constexpr Tp id3(Tp n) {
  return detail::id3(n);
}
template <detail::integer Tp>
constexpr int id0(Tp n) {
  return detail::id0(n);
}
template <detail::integer Tp>
constexpr int id1(Tp n) {
  return detail::id1(n);
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


namespace algo::detail {
template <typename Tp>
constexpr Tp sqrt(Tp n) {
  if (n == 0) { return 0; }
  Tp ans = 0;
  for (int i = id0(n) >> 1; i >= 0; --i) {
    const Tp tmp = (n - ans * ans) >> i;
    if ((Tp(1) << i) + (ans << 1) <= tmp) { ans |= Tp(1) << i; }
  }
  return ans;
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
constexpr std::common_type_t<T1, T2> floor_div(T1 x, T2 y) {
  using Tp = std::common_type_t<T1, T2>;
  return detail::floor_div<Tp>(x, y);
}
template <detail::integer T1, detail::sign_compatible_with<T1> T2>
constexpr std::common_type_t<T1, T2> ceil_div(T1 x, T2 y) {
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
      const Tp tmp = (n0 * (n0 + 1) >> 1) * (a0 / c0) + (n0 + 1) * (b0 / c0);
      res += alt(neg) * tmp;
      a0 %= c0, b0 %= c0;
    }
  }
  res += alt(neg) * (b0 / c0) * (n0 + 1);
  return res;
}
}
namespace algo {
class sieve {
public:
  sieve() = default;
  explicit sieve(int n) noexcept : lim_{n}, factors_(((n + 5) / 6) << 1) {
    const int m = (n + 5) / 6;
    const int kmax = (detail::sqrt((6 * m + 1)) - 5) / 6 + 1;
    factors_[(0 << 1) + 0] = 1;
    for (int k = 0; k <= kmax; ++k) {
      if (factors_[(k << 1) + 0] == 0) {
        const int pm = 6 * k + 1;
        const int s0 = k * (6 * k + 2 * 1) + (1 * 1) / 6;
        const int s1 = s0 + 4 * k + 0;
        for (int s = s0; s < m; s += pm) { factors_[(s << 1) + 0] = pm; }
        for (int s = s1; s < m; s += pm) { factors_[(s << 1) + 1] = pm; }
      }
      if (factors_[(k << 1) + 1] == 0) {
        const int pm = 6 * k + 5;
        const int s0 = k * (6 * k + 2 * 5) + (5 * 5) / 6;
        const int s1 = s0 + 2 * k + 1;
        for (int s = s0; s < m; s += pm) { factors_[(s << 1) + 0] = pm; }
        for (int s = s1; s < m; s += pm) { factors_[(s << 1) + 1] = pm; }
      }
    }
  }
  auto factorize(int n) const -> std::vector<std::array<int, 2>> {
    detail::assume(1 <= n);
    std::vector<std::array<int, 2>> ans;
    ans.reserve(20);
    while (n > 1) {
      const int p = get_factor(n);
      int c = 0;
      do { n /= p, c++; } while (n % p == 0);
      ans.push_back({p, c});
    }
    return ans;
  }
  std::vector<int> divisors(int n) const {
    detail::assume(0 < n);
    std::vector<int> ans{1};
    while (n > 1) {
      const int p = get_factor(n);
      int c = 0;
      do { n /= p, c++; } while (n % p == 0);
      const int sz = static_cast<int>(ans.size());
      for (int i = 0; i < sz; ++i) {
        for (int j = 0, d = ans[i]; j < c; ++j) {
          d *= p;
          ans.emplace_back(d);
        }
      }
    }
    return ans;
  }
  int totient(int n) const {
    detail::assume(1 <= n);
    int ans = n;
    while (n > 1) {
      const int p = get_factor(n);
      ans -= ans / p;
      do { n /= p; } while (n % p == 0);
    }
    return ans;
  }
  int mobius(int n) const {
    detail::assume(1 <= n);
    bool parity = false;
    while (n > 1) {
      const int p = get_factor(n);
      if ((n /= p) % p == 0) { return 0; }
      parity ^= 1;
    }
    return detail::alt(parity);
  }
  int small_omega(int n) const {
    detail::assume(1 <= n);
    int ans = 0;
    while (n > 1) {
      const int p = get_factor(n);
      ans = ans + 1;
      do { n /= p; } while (n % p == 0);
    }
    return ans;
  }
  int big_omega(int n) const {
    detail::assume(1 <= n);
    int ans = 0;
    while (n > 1) {
      const int p = get_factor(n);
      do { n /= p, ans++; } while (n % p == 0);
    }
    return ans;
  }
  int radical(int n) const {
    detail::assume(1 <= n);
    int ans = 1;
    while (n > 1) {
      const int p = get_factor(n);
      ans *= p;
      do { n /= p; } while (n % p == 0);
    }
    return ans;
  }
  int num_divisors(int n) const {
    detail::assume(1 <= n);
    int ans = 1;
    while (n > 1) {
      const int p = get_factor(n);
      int c = 0;
      do { n /= p, c++; } while (n % p == 0);
      ans *= 1 + c;
    }
    return ans;
  }
  bool is_prime(int n) const {
    detail::assume(1 <= n);
    return n == get_factor(n);
  }
  int get_factor(int n) const {
    detail::assume(1 <= n);
    if (n % 2 == 0) { return 2; }
    if (n % 3 == 0) { return 3; }
    return get_nontrivial_factor(n);
  }
  int limit() const { return lim_; }
private:
  int get_nontrivial_factor(int n) const {
    detail::assume(1 <= n);
    const int index = n / 3;
    return factors_[index] ? factors_[index] : n;
  }
  int lim_;
  std::vector<int> factors_;
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
using bint = uint8_t;
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
}
void solve() noexcept {
  const algo::sieve sv(MAXN - 1);
  vector<wint> cnt(MAXN);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int v;
    cin >> v;
    cnt[v]++;
  }
  for (int i = 2; i < MAXN; ++i) {
    if (sv.is_prime(i)) {
      for (int j = (MAXN - 1) / i; j > 0; --j) { cnt[j] += cnt[j * i]; }
    }
  }
  vector<wint> dp(MAXN);
  for (int i = MAXN - 1; i > 1; --i) {
    dp[i] += i * cnt[i];
    for (const auto [j, _] : sv.factorize(i)) {
      dp[i / j] = max(dp[i / j], dp[i] - cnt[i] * (i / j));
    }
  }
  cout << dp[1] + n << '\n';
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
