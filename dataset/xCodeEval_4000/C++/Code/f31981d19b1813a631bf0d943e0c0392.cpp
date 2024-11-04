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
#include <span>
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
  static inline constexpr bool same_as =
      std::is_invocable_r_v<return_type, Fn, Args...>;
};
template <typename Fn, typename Sig>
concept function = function_traits<Sig>::template same_as<Fn>;
template <typename IIter, typename Value>
concept input_iterator = std::same_as<std::iter_value_t<IIter>, Value>;
}
namespace algo::detail {
[[gnu::noreturn]] void
unreachable() {
  __builtin_unreachable();
}
[[gnu::always_inline]] constexpr void
assume(bool expr) {
  (void)expr;
}
}
namespace algo::detail {
template <typename Tp>
constexpr int
count_lz(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::countl_zero<Up>(n);
}
template <typename Tp>
constexpr int
count_tz(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::countr_zero<Up>(n);
}
template <typename Tp>
constexpr int
bit_width(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::bit_width<Up>(n);
}
template <typename Tp>
constexpr Tp
floor_pow2(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return static_cast<Tp>(std::bit_floor<Up>(n));
}
template <typename Tp>
constexpr Tp
ceil_pow2(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return static_cast<Tp>(std::bit_ceil<Up>(n));
}
template <typename Tp>
constexpr int
floor_log2(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  constexpr int Nd = std::numeric_limits<Up>::digits;
  return Nd - 1 - std::countl_zero<Up>(n);
}
template <typename Tp>
constexpr int
ceil_log2(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  constexpr int Nd = std::numeric_limits<Up>::digits;
  if (n == 0) { return 0; }
  return Nd - std::countl_zero<Up>(n - 1);
}
template <typename Tp>
constexpr Tp
blsr(Tp n) {
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
constexpr Tp
blsi(Tp n) {
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
constexpr int
popcount(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::popcount<Up>(n);
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
blsr(Tp n) {
  return detail::blsr(n);
}
template <detail::integer Tp>
constexpr Tp
blsi(Tp n) {
  return detail::blsi(n);
}
template <detail::integer Tp>
constexpr Tp
popcount(Tp n) {
  return detail::popcount(n);
}
}
#define PRINT(...) (void)0
#define DEBUG(x) (void)0
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
  return -(n & 1) | 1;
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
  using Tp = std::common_type_t<T1, T2>;
  return detail::floor_div<Tp>(x, y);
}
template <detail::integer T1, detail::sign_compatible_with<T1> T2>
constexpr std::common_type_t<T1, T2>
ceil_div(T1 x, T2 y) {
  assert(y != 0);
  using Tp = std::common_type_t<T1, T2>;
  return detail::ceil_div<Tp>(x, y);
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
struct hilbert_ord {
  constexpr hilbert_ord() = default;
  constexpr hilbert_ord(int n) : lg2_(detail::ceil_log2(n)), dim_(1 << lg2_) {}
  constexpr int64_t
  order(int x, int y) const {
    assert(0 <= x && x < dim_);
    assert(0 <= y && y < dim_);
    int64_t res = 0;
    for (int i = lg2_; i-- > 0;) {
      const bool rx = (x >> i) & 1;
      const bool ry = (y >> i) & 1;
      res += (static_cast<int64_t>(1) << (i + i)) * Rot[rx][ry];
      if (!rx) {
        x = ry ? dim_ - 1 - x : x;
        y = ry ? dim_ - 1 - y : y;
        std::swap(x, y);
      }
    }
    return res;
  }
private:
  static constexpr int Rot[2][2]{{0, 3}, {1, 2}};
  int lg2_, dim_;
};
struct custom_hash {
  static inline const uint64_t fx =
      std::chrono::high_resolution_clock::now().time_since_epoch().count();
  static inline uint64_t
  hash64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  static inline uint32_t
  hash32(uint32_t x) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
  }
  inline size_t
  operator()(detail::qword_fittable auto x) const {
    return hash64(x ^ fx);
  }
  inline size_t
  operator()(detail::dword_fittable auto x) const {
    return hash32(x ^ fx);
  }
};
template <std::semiregular Tp>
class vector2d {
public:
  vector2d() = default;
  vector2d(size_t row, size_t col, const Tp &init = Tp())
      : row_(row), col_(col), data_(total_size(), init) {}
  vector2d(size_t row, const std::vector<Tp> &init_col)
      : vector2d(row, init_col.size()) {
    for (size_t i = 0; i < row_size(); ++i) {
      std::copy_n(init_col.begin(), col_size(), data_.begin() + i * col_size());
    }
  }
  std::span<const Tp, std::dynamic_extent>
  operator[](size_t i) const noexcept {
    assert(0 <= i && i < row_size());
    return {data_.cbegin() + i * col_size(), col_size()};
  }
  std::span<Tp, std::dynamic_extent>
  operator[](size_t i) noexcept {
    assert(0 <= i && i < row_size());
    return {data_.begin() + i * col_size(), col_size()};
  }
  size_t
  row_size() const {
    return row_;
  }
  size_t
  col_size() const {
    return col_;
  }
  size_t
  total_size() const {
    return row_ * col_;
  }
  typename std::vector<Tp>::const_iterator
  begin() const {
    return data_.cbegin();
  }
  typename std::vector<Tp>::iterator
  begin() {
    return data_.begin();
  }
  typename std::vector<Tp>::const_iterator
  end() const {
    return data_.cend();
  }
  typename std::vector<Tp>::iterator
  end() {
    return data_.end();
  }
  const Tp *
  data() const {
    return data_.data();
  }
  Tp *
  data() {
    return data_.data();
  }
private:
  size_t row_;
  size_t col_;
  std::vector<Tp> data_;
};
}
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
using std::string_view;
using std::swap;
using std::tie;
using std::to_string;
using std::tuple;
using std::vector;
using wint = int64_t;
using uint = uint32_t;
using bint = uint_fast8_t;
template <typename Key, typename Value, typename Hash = std::hash<Key>>
using umap = std::unordered_map<Key, Value, Hash>;
template <typename Key, typename Hash = std::hash<Key>>
using uset = std::unordered_set<Key, Hash>;
template <typename Tp, typename Comp = std::less<Tp>>
using max_heap = std::priority_queue<Tp, std::vector<Tp>, Comp>;
template <typename Tp, typename Comp = std::greater<Tp>>
using min_heap = std::priority_queue<Tp, std::vector<Tp>, Comp>;
#define INF 0x3f3f3f3f
#define MOD 998244353
#define MAXN 200001
#define MULTI 1
namespace {
}
struct suffix_array {
  suffix_array(const string &str)
      : n(str.size() + 1), c(algo::ceil_log2(n) + 1, vector<int>(n)),
        s(str + '$') {
    const int alpha = 256;
    vector<int> cnt(max(n, alpha));
    vector<int> p(n), pn(n);
    for (int i = 0; i < n; ++i) {
      cnt[s[i]]++;
    }
    for (int i = 1; i < alpha; ++i) {
      cnt[i] += cnt[i - 1];
    }
    for (int i = 0; i < n; ++i) {
      p[--cnt[s[i]]] = i;
    }
    int cls = 0;
    c[0][p[0]] = 0;
    for (int i = 1; i < n; ++i) {
      if (s[p[i]] != s[p[i - 1]]) {
        cls++;
      }
      c[0][p[i]] = cls;
    }
    for (int l = 0; (1 << l) < n; ++l) {
      for (int i = 0; i < n; ++i) {
        pn[i] = norm(p[i] - (1 << l));
      }
      fill(cnt.begin(), cnt.begin() + cls + 1, 0);
      for (int i = 0; i < n; ++i) {
        cnt[c[l][pn[i]]]++;
      }
      for (int i = 1; i <= cls; ++i) {
        cnt[i] += cnt[i - 1];
      }
      for (int i = n - 1; i >= 0; --i) {
        p[--cnt[c[l][pn[i]]]] = pn[i];
      }
      c[l + 1][p[0]] = 0;
      cls = 0;
      for (int i = 1; i < n; ++i) {
        if (tie(c[l][p[i]], c[l][norm(p[i] + (1 << l))]) !=
            tie(c[l][p[i - 1]], c[l][norm(p[i - 1] + (1 << l))])) {
          cls++;
        }
        c[l + 1][p[i]] = cls;
      }
    }
  }
  int lcp(int i, int j) const {
    int ans = 0;
    for (int k = algo::floor_log2(n); k >= 0; --k) {
      if (c[k][i] == c[k][j]) {
        ans += 1 << k;
        i += (1 << k);
        j += (1 << k);
      }
    }
    return ans;
  }
  int norm(int i) const {
    if (i < 0) {
      i += n;
    }
    if (i >= n) {
      i -= n;
    }
    return i;
  }
  int n;
  vector<vector<int>> c;
  string s;
};
void solve() noexcept {
  int n;
  cin >> n;
  string s;
  cin >> s;
  algo::vector2d fn(n, n, 0);
  suffix_array sf(s);
  for (int i = 0; i < n; ++i) {
    fn[i][i] = n - i;
    for (int j = i + 1; j < n; ++j) {
      fn[i][j] = sf.lcp(i, j);
      fn[j][i] = fn[i][j];
    }
  }
  struct node {
    int l, r;
  };
  auto cmp = [&](node x, node y) {
    const int pref = fn[x.l][y.l];
    const int xl = x.r - x.l + 1, yl = y.r - y.l + 1;
    return xl <= pref && yl <= pref && xl < yl || xl <= pref && yl > pref ||
           xl > pref && yl > pref && s[x.l + pref] < s[y.l + pref];
  };
  vector<node> d;
  d.reserve(n * (n + 1) >> 1);
  for (int i = 0; i < n; ++i) {
    auto lb = d.begin();
    for (int j = i; j < n; ++j) {
      lb = lower_bound(lb, d.end(), node{i, j}, cmp);
      if (lb == d.end()) {
        d.emplace_back(node{i, j});
        lb = d.end();
      } else {
        *lb = {i, j};
        ++lb;
      }
    }
  }
  cout << d.size() << '\n';
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int tc;
  std::cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
