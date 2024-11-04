#pragma GCC target("abm,movbe,bmi,bmi2,lzcnt,popcnt,avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("inline")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("omit-frame-pointer")
#define NDEBUG 1
#include <immintrin.h>
#include <algorithm>
#include <array>
#include <bit>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <compare>
#include <complex>
#include <concepts>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <memory_resource>
#include <new>
#include <numeric>
#include <optional>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
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
floor_pow2(Tp n) {
  return static_cast<Tp>(std::bit_floor<std::make_unsigned_t<Tp>>(n));
}
template <typename Tp>
constexpr Tp
ceil_pow2(Tp n) {
  return static_cast<Tp>(std::bit_ceil<std::make_unsigned_t<Tp>>(n));
}
template <typename Tp>
constexpr int
floor_log2(Tp n) {
  return bit_width(n) - 1;
}
template <typename Tp>
constexpr int
ceil_log2(Tp n) {
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
floor_pow2(Tp n) {
  return detail::floor_pow2(n);
}
template <detail::integer Tp>
constexpr Tp
ceil_pow2(Tp n) {
  return detail::ceil_pow2(n);
}
template <detail::integer Tp>
constexpr int
floor_log2(Tp n) {
  return detail::floor_log2(n);
}
template <detail::integer Tp>
constexpr int
ceil_log2(Tp n) {
  return detail::ceil_log2(n);
}
template <detail::integer Tp>
constexpr Tp
popcount(Tp n) {
  return detail::popcount(n);
}
}
namespace dbg {
#define debug(...) (void)0
}
namespace algo::detail {
constexpr void
assume(bool expr) {
  if (!expr) { __builtin_unreachable(); }
}
}
namespace algo {
template <std::semiregular Monoid, detail::binary_op<Monoid> Operation,
          detail::callable<Monoid> Identity>
class fenwick_tree {
public:
  fenwick_tree() = default;
  fenwick_tree(int n, const Operation& f, const Identity& e)
      : size_(n), tree_(size_ + 1, e()), f_(f), ef_(e) {}
  void
  apply(int pos, const Monoid& z) {
    assert(0 <= pos && pos < size());
    for (++pos; pos <= size_; pos += detail::blsi(pos)) {
      tree_[pos] = f_(std::move(tree_[pos]), z);
    }
  }
  Monoid
  query(int r) const {
    assert(0 <= r && r <= size());
    Monoid res = ef_();
    for (; r > 0; r = detail::blsr(r)) { res = f_(tree_[r], std::move(res)); }
    return res;
  }
  int
  size() const {
    return size_;
  }
private:
  int size_;
  std::vector<Monoid> tree_;
  Operation f_;
  Identity ef_;
};
}
namespace algo::detail {
template <typename Tp>
constexpr Tp
sqrt(Tp n) {
  if (n <= 1) { return n; }
  Tp ans = 0;
  for (int i = floor_log2(n) - 1; i >= 0; --i) {
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
floor_div(Tp x, Tp y) {
  if constexpr (std::is_signed_v<Tp>) {
    return x / y - ((x ^ y) < 0 && x % y != 0);
  } else {
    return x / y;
  }
}
template <typename Tp>
constexpr Tp
ceil_div(Tp x, Tp y) {
  if constexpr (std::is_signed_v<Tp>) {
    return y > 0 ? floor_div(x + y - 1, y) : -floor_div(x, -y);
  } else {
    return floor_div(x + y - 1, y);
  }
}
template <typename Tp>
constexpr std::make_signed_t<std::common_type_t<Tp, char>>
alt(Tp n) {
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
floor_div(T1 x, T2 y) {
  assert(y != 0);
  return detail::floor_div<std::common_type_t<T1, T2>>(x, y);
}
template <detail::integer T1, detail::sign_compatible_with<T1> T2>
constexpr std::common_type_t<T1, T2>
ceil_div(T1 x, T2 y) {
  assert(y != 0);
  return detail::ceil_div<std::common_type_t<T1, T2>>(x, y);
}
template <std::integral Tp>
constexpr std::make_signed_t<std::common_type_t<Tp, char>>
alt(Tp n) {
  return detail::alt(n);
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
#pragma region alias
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
using std::pair;
using std::queue;
using std::set;
using std::stack;
using std::string;
using std::swap;
using std::tie;
using std::to_string;
using std::tuple;
using std::vector;
using wint = int64_t;
using uint = uint32_t;
template <typename KeyType, typename ValueType>
using umap = std::unordered_map<KeyType, ValueType>;
template <typename ValueType>
using uset = std::unordered_set<ValueType>;
template <typename Tp, typename Function = std::less<Tp>>
using max_heap = std::priority_queue<Tp, std::vector<Tp>, Function>;
template <typename Tp, typename Function = std::greater<Tp>>
using min_heap = std::priority_queue<Tp, std::vector<Tp>, Function>;
#pragma endregion alias
#define INF 0x3f3f3f3f
#define MOD 998244353
#define MAXN 200001
#define MULTI 0
namespace {
}
void solve() noexcept {
  constexpr int M = algo::sqrt(MAXN);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> xy(n + 1);
  for (int i = 1; i <= n; ++i) { cin >> xy[i].first >> xy[i].second; }
  debug("xs={}\n", xy);
  vector<pair<int, int>> qs(m + 1);
  for (int i = 1; i <= m; ++i) { cin >> qs[i].first >> qs[i].second; }
  struct node {
    int t0, x, y, t1;
  };
  vector<node> itv;
  vector<int> times(n + 1, -1);
  for (int i = 1; i <= m; ++i) {
    const int k = qs[i].second;
    if (xy[k].first + xy[k].second < M) { continue; }
    if (qs[i].first == 1) {
      times[k] = i;
    } else {
      itv.emplace_back(times[k], xy[k].first, xy[k].second, i);
      times[k] = -1;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (times[i] != -1) {
      itv.emplace_back(times[i], xy[i].first, xy[i].second, m + 1);
    }
  }
  vector<int> pref(MAXN + 10);
  for (const auto [t0, x, y, t1] : itv) {
    for (int t = t0 + x; t < t1; t += x + y) {
      pref[t] += 1;
      pref[min(t1, t + y)] -= 1;
    }
  }
  for (int i = 1; i <= m; ++i) { pref[i] += pref[i - 1]; }
  vector<vector<int>> inc(M, vector<int>(M));
  for (int t = 1; t <= m; ++t) {
    int ans = pref[t];
    const int k = qs[t].second;
    const int x = xy[k].first, y = xy[k].second;
    const int w = x + y;
    if (w < M) {
      if (qs[t].first == 1) {
        const int tk = t % w;
        for (int tt = max(0, tk + x - w); tt < tk; ++tt) { inc[w][tt]++; }
        for (int tt = x + tk; tt < w; ++tt) { inc[w][tt]++; }
        times[k] = t;
      } else {
        const int tk = times[k] % w;
        for (int tt = max(0, tk + x - w); tt < tk; ++tt) { inc[w][tt]--; }
        for (int tt = x + tk; tt < w; ++tt) { inc[w][tt]--; }
      }
    }
    for (int xx = 2; xx < M; ++xx) { ans += inc[xx][t % xx]; }
    cout << ans << '\n';
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
