#pragma GCC target("abm,movbe,bmi,bmi2,lzcnt,popcnt,avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("inline")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("omit-frame-pointer")
#define NDEBUG 1
#include <immintrin.h>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
namespace dbg {
#define debug(...) (void)0
}
namespace algo::detail {
template <typename Tp>
concept integer = std::integral<Tp> && !std::same_as<Tp, bool>;
template <typename Tp>
concept signed_integer = integer<Tp> &&(Tp(-1) < Tp(0));
template <typename Tp>
concept unsigned_integer = integer<Tp> &&(Tp(-1) > Tp(0));
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
template <typename InputIterator, typename ValueType>
concept input_iterator = std::input_iterator<InputIterator> &&
    std::same_as<std::iter_value_t<InputIterator>, ValueType>;
template <typename From, typename To>
concept sign_compatible_with = integer<From> &&
    ((std::is_signed_v<From> && std::is_signed_v<To>) ||
     (std::is_unsigned_v<From> && std::is_unsigned_v<To>));
template <typename Tp>
concept qword_fittable = sizeof(Tp) <= 8UL;
template <typename Tp>
concept dword_fittable = qword_fittable<Tp> && sizeof(Tp) <= 4UL;
template <typename Tp>
concept word_fittable = dword_fittable<Tp> && sizeof(Tp) <= 2UL;
template <typename Tp>
concept byte_fittable = word_fittable<Tp> && sizeof(Tp) == 1UL;
template <typename Tp>
struct imul_result {
  static_assert(integer<Tp>);
};
template <qword_fittable Tp>
struct imul_result<Tp> {
  using type =
      std::conditional_t<std::is_signed_v<Tp>, __int128_t, __uint128_t>;
};
template <dword_fittable Tp>
struct imul_result<Tp> {
  using type = std::conditional_t<std::is_signed_v<Tp>, int64_t, uint64_t>;
};
template <word_fittable Tp>
struct imul_result<Tp> {
  using type = std::conditional_t<std::is_signed_v<Tp>, int32_t, uint32_t>;
};
template <byte_fittable Tp>
struct imul_result<Tp> {
  using type = std::conditional_t<std::is_signed_v<Tp>, int16_t, uint16_t>;
};
template <typename Tp>
using imul_result_t = typename imul_result<Tp>::type;
}
namespace algo::detail {
template <typename Tp>
constexpr int
count_lz(Tp n) {
  return std::countl_zero<std::make_unsigned_t<Tp>>(n);
}
template <typename Tp>
constexpr int
count_tz(Tp n) {
  return std::countr_zero<std::make_unsigned_t<Tp>>(n);
}
template <typename Tp>
constexpr int
bit_width(Tp n) {
  return std::bit_width<std::make_unsigned_t<Tp>>(n);
}
template <typename Tp>
constexpr Tp
bit_floor(Tp n) {
  return static_cast<Tp>(std::bit_floor<std::make_unsigned_t<Tp>>(n));
}
template <typename Tp>
constexpr Tp
bit_ceil(Tp n) {
  return static_cast<Tp>(std::bit_ceil<std::make_unsigned_t<Tp>>(n));
}
template <typename Tp>
constexpr int
log2_floor(Tp n) {
  return bit_width(n) - 1;
}
template <typename Tp>
constexpr int
log2_ceil(Tp n) {
  return bit_width(n - (n != 0));
}
template <dword_fittable Tp>
constexpr Tp
blsr(Tp n) {
  if (std::is_constant_evaluated()) { return n & (n - 1); }
  return _blsr_u32(n);
}
template <qword_fittable Tp>
constexpr Tp
blsr(Tp n) {
  if (std::is_constant_evaluated()) { return n & (n - 1); }
  return _blsr_u64(n);
}
template <dword_fittable Tp>
constexpr Tp
blsi(Tp n) {
  if (std::is_constant_evaluated()) { return n & -n; }
  return _blsi_u32(n);
}
template <qword_fittable Tp>
constexpr Tp
blsi(Tp n) {
  if (std::is_constant_evaluated()) { return n & -n; }
  return _blsi_u64(n);
}
template <dword_fittable Tp>
constexpr Tp
blsmsk(Tp n) {
  if (std::is_constant_evaluated()) { return n ^ (n - 1); }
  return _blsmsk_u32(n);
}
template <qword_fittable Tp>
constexpr Tp
blsmsk(Tp n) {
  if (std::is_constant_evaluated()) { return n ^ (n - 1); }
  return _blsmsk_u64(n);
}
template <typename Tp>
constexpr int
popcount(Tp n) {
  return std::popcount<std::make_unsigned_t<Tp>>(n);
}
}
namespace algo {
template <detail::integer Tp>
constexpr int
count_lz(Tp n) {
  return detail::count_lz(n);
}
template <detail::integer Tp>
constexpr int
count_tz(Tp n) {
  return detail::count_tz(n);
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
bit_ceil(Tp n) {
  return detail::bit_ceil(n);
}
template <detail::integer Tp>
constexpr int
log2_floor(Tp n) {
  return detail::log2_floor(n);
}
template <detail::integer Tp>
constexpr int
log2_ceil(Tp n) {
  return detail::log2_ceil(n);
}
template <detail::integer Tp>
constexpr Tp
popcount(Tp n) {
  return detail::popcount(n);
}
}
namespace algo::detail {
constexpr void
assume(bool expr) {
  if (!expr) { __builtin_unreachable(); }
}
}
namespace algo::detail {
template <typename Tp>
constexpr Tp
sqrt(Tp n) {
  if (n <= 1) { return n; }
  Tp ans = 0;
  for (int i = log2_floor(n) - 1; i >= 0; --i) {
    const Tp tmp = (n - ans * ans) >> i;
    if ((ans << 1) + (Tp(1) << i) <= tmp) { ans |= Tp(1) << i; }
  }
  return ans;
}
template <typename Tp>
constexpr Tp
abs(Tp n) {
  return n < 0 ? -n : n;
}
template <typename Tp>
constexpr Tp
cdiv(Tp x, Tp y) {
  return y >= 0 ? (x + y - 1) / y : -(x / -y);
}
template <typename Tp>
constexpr std::make_signed_t<std::common_type_t<Tp, char>>
sgn(Tp n) {
  return (n & 1) ? -1 : 1;
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
template <detail::integer T1, detail::sign_compatible_with<T1> T2>
constexpr std::common_type_t<T1, T2>
cdiv(T1 x, T2 y) {
  assert(y != 0);
  return detail::cdiv<std::common_type_t<T1, T2>>(x, y);
}
template <std::integral Tp>
constexpr std::make_signed_t<std::common_type_t<Tp, char>>
sgn(Tp n) {
  return detail::sgn(n);
}
template <detail::integer T1, detail::sign_compatible_with<T1> T2,
          detail::sign_compatible_with<T2> T3,
          detail::sign_compatible_with<T3> T4>
constexpr std::common_type_t<T1, T2, T3, T4>
floor_sum(T1 a, T2 b, T3 c, T4 n) {
  assert(n >= 0);
  assert(c > 0);
  assert(a >= 0);
  detail::assume(n >= 0);
  detail::assume(c > 0);
  detail::assume(a >= 0);
  typedef std::common_type_t<T1, T2, T3, T4> Tp;
  Tp res = 0, a0 = a, b0 = b, c0 = c, n0 = n;
  bool neg = false;
  while (a0 != 0) {
    if (a0 < c0 && b0 < c0) {
      const Tp m = (a0 * n0 + b0) / c0;
      const Tp tmp = a0;
      res += sgn(neg) * m * n0;
      b0 = c0 - b0 - 1, a0 = c0, c0 = tmp, n0 = m - 1;
      neg ^= true;
    } else {
      const Tp tmp = (n0 * (n0 + 1) >> 1) * (a0 / c0) + (n0 + 1) * (b0 / c0);
      res += sgn(neg) * tmp;
      a0 %= c0, b0 %= c0;
    }
  }
  res += sgn(neg) * (b0 / c0) * (n0 + 1);
  return res;
}
}
namespace algo {
class sieve {
public:
  sieve() = default;
  explicit sieve(int n) noexcept : n_(n), m_((n_ + 5) / 6), factors_(m_ << 1) {
    const int kmax = (detail::sqrt((6 * m_ + 1)) - 5) / 6 + 1;
    factors_[(0 << 1) + 0] = 1;
    for (int k = 0; k <= kmax; ++k) {
      if (factors_[(k << 1) + 0] == 0) {
        const int pm = 6 * k + 1;
        const int s0 = k * (6 * k + 2 * 1) + (1 * 1) / 6;
        const int s1 = s0 + 4 * k + 0;
        for (int s = s0; s < m_; s += pm) { factors_[(s << 1) + 0] = pm; }
        for (int s = s1; s < m_; s += pm) { factors_[(s << 1) + 1] = pm; }
      }
      if (factors_[(k << 1) + 1] == 0) {
        const int pm = 6 * k + 5;
        const int s0 = k * (6 * k + 2 * 5) + (5 * 5) / 6;
        const int s1 = s0 + 2 * k + 1;
        for (int s = s0; s < m_; s += pm) { factors_[(s << 1) + 0] = pm; }
        for (int s = s1; s < m_; s += pm) { factors_[(s << 1) + 1] = pm; }
      }
    }
  }
  [[gnu::pure]] std::vector<std::pair<int, int>>
  factorize(int n) const {
    assert(1 <= n && n <= size());
    detail::assume(1 <= n);
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
  [[gnu::pure]] std::vector<int>
  divisors(int n) const {
    assert(1 <= n && n <= size());
    std::vector<int> ans{1};
    for (auto&& [p, c] : factorize(n)) {
      const int sz = static_cast<int>(std::ssize(ans));
      for (int i = 0; i < sz; ++i) {
        for (int j = 0, d = ans[i]; j < c; ++j) { ans.emplace_back(d *= p); }
      }
    }
    return ans;
  }
  [[gnu::pure]] int
  totient(int n) const {
    assert(1 <= n && n <= size());
    detail::assume(1 <= n);
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
  [[gnu::pure]] int
  mobius(int n) const {
    assert(1 <= n && n <= size());
    detail::assume(1 <= n);
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
    return detail::sgn(parity);
  }
  int
  size() const {
    return n_;
  }
private:
  inline int
  get_nontrivial_factor(int n) const {
    detail::assume(1 <= n);
    const int d = n / 6, r = n % 6;
    return factors_[(d << 1) + (r >> 2)] ? factors_[(d << 1) + (r >> 2)] : n;
  }
  int n_, m_;
  std::vector<int> factors_;
};
}
#pragma region alias
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
using std::lcm;
using std::tie;
using std::max;
using std::min;
using std::move;
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
#pragma endregion alias
#define INF 0x3f3f3f3f
#define MOD 998244353
#define MAXN 20000001
#define MULTI 0
template <typename Tp>
constexpr void chmax(Tp &x, const Tp &y) { x = max(x, y); }
template <typename Tp>
constexpr void chmin(Tp &x, const Tp &y) { x = min(x, y); }
constexpr int64_t operator""_w(unsigned long long x) { return static_cast<int64_t>(x); }
namespace {
}
void solve() noexcept {
  const algo::sieve sv(MAXN-1);
  int n;cin>>n;
  map<int,int>freq;
  for(int i=0;i<n;++i){
    int a;cin>>a;
    freq[a]++;
  }
  vector<wint>cnt(MAXN);
  for(const auto[v,c]:freq){
    for(const int d:sv.divisors(v)){
      cnt[d]+=c;
    }
  }
  vector<wint>dp(MAXN);
  for(int i=MAXN-1;i>1;--i){
    dp[i]+=i*cnt[i];
    for(const auto[j,_]:sv.factorize(i)){
      dp[i/j]=max(dp[i/j],dp[i]-cnt[i]*(i/j));
    }
  }
  cout<<dp[1]+n<<'\n';
}
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cout.precision(15);
  solve();
  return 0;
}
