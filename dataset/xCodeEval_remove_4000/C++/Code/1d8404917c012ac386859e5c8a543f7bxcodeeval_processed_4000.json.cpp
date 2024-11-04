














































namespace algo::detail {
template <typename Tp>
concept integer = std::integral<Tp> && !(std::same_as<Tp, bool>);
template <typename Tp>
concept signed_integer = integer<Tp> && (Tp(-1) < Tp(0));
template <typename Tp>
concept unsigned_integer = integer<Tp> && (Tp(-1) > Tp(0));
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
}
namespace algo::detail {
[[gnu::noreturn]] inline void unreachable() { __builtin_unreachable(); }
[[gnu::always_inline]] constexpr void assume(bool expr) {
  if (!expr) { __builtin_unreachable(); }
}
}
namespace algo::detail {
template <typename Tp>
constexpr int id4(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::countl_zero<Up>(n);
}
template <typename Tp>
constexpr int id6(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::countr_zero<Up>(n);
}
template <typename Tp>
constexpr int bit_width(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::bit_width<Up>(n);
}
template <typename Tp>
constexpr Tp id8(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return static_cast<Tp>(std::bit_floor<Up>(n));
}
template <typename Tp>
constexpr Tp id5(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return static_cast<Tp>(std::bit_ceil<Up>(n));
}
template <typename Tp>
constexpr int id1(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  constexpr int Nd = std::numeric_limits<Up>::digits;
  return Nd - 1 - std::countl_zero<Up>(n);
}
template <typename Tp>
constexpr int id3(Tp n) {
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
constexpr int id4(Tp n) {
  return detail::id4(n);
}
template <detail::integer Tp>
constexpr int id6(Tp n) {
  return detail::id6(n);
}
template <detail::integer Tp>
constexpr int bit_width(Tp n) {
  return detail::bit_width(n);
}
template <detail::integer Tp>
constexpr Tp id8(Tp n) {
  return detail::id8(n);
}
template <detail::integer Tp>
constexpr Tp id5(Tp n) {
  return detail::id5(n);
}
template <detail::integer Tp>
constexpr int id1(Tp n) {
  return detail::id1(n);
}
template <detail::integer Tp>
constexpr int id3(Tp n) {
  return detail::id3(n);
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
constexpr Tp popcount(Tp n) {
  return detail::popcount(n);
}
}




namespace algo {
namespace pb_ds = __gnu_pbds;
template <std::semiregular Key,
          std::relation<Key, Key> Compare = std::less<Key>>
using set = pb_ds::tree<Key, pb_ds::null_type, Compare, pb_ds::rb_tree_tag,
                        pb_ds::tree_order_statistics_node_update>;
template <std::semiregular Key, std::semiregular Value,
          std::relation<Key, Key> Compare = std::less<Key>>
using map = pb_ds::tree<Key, Value, Compare, pb_ds::rb_tree_tag,
                        pb_ds::tree_order_statistics_node_update>;
template <std::semiregular Key, std::semiregular Value,
          detail::function<size_t(Key)> Hash = std::hash<Key>,
          std::equivalence_relation<Key, Key> Eq = std::equal_to<Key>>
using hash_map = pb_ds::gp_hash_table<Key, Value, Hash>;
template <std::semiregular Key,
          detail::function<size_t(Key)> Hash = std::hash<Key>,
          std::equivalence_relation<Key, Key> Eq = std::equal_to<Key>>
using hash_set = pb_ds::gp_hash_table<Key, pb_ds::null_type, Hash, Eq>;
}
namespace algo::detail {
template <typename Tp>
constexpr Tp sqrt(Tp n) {
  if (n == 0) { return 0; }
  Tp res = 0;
  for (int i = id1(n) >> 1; i >= 0; --i) {
    const Tp tmp = res | Tp(1) << i;
    if (tmp * tmp <= n) { res = tmp; }
  }
  return res;
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
  assert(n >= 0);
  return detail::sqrt(n);
}
template <detail::integer Tp>
constexpr Tp id7(Tp n) {
  if (n == 0) { return 0; }
  Tp res = 0;
  const Tp m = detail::abs(n);
  for (int i = detail::id1(m) / 3; i >= 0; --i) {
    const Tp low = (m - res * res * res) >> i;
    const Tp tmp = res | Tp(1) << i;
    if (3 * res * tmp + (Tp(1) << (i + i)) <= low) { res = tmp; }
  }
  return res;
}
template <detail::integer Tp>
constexpr Tp abs(Tp n) {
  return detail::abs(n);
}
template <detail::integer T1, detail::sign_compatible_with<T1> T2>
constexpr std::common_type_t<T1, T2> floor_div(T1 x, T2 y) {
  assert(y != 0);
  using Tp = std::common_type_t<T1, T2>;
  return detail::floor_div<Tp>(x, y);
}
template <detail::integer T1, detail::sign_compatible_with<T1> T2>
constexpr std::common_type_t<T1, T2> ceil_div(T1 x, T2 y) {
  assert(y != 0);
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
constexpr std::common_type_t<T1, T2, T3, T4> floor_sum(T1 a, T2 b, T3 c, T4 n) {
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
class id2 {
public:
  constexpr id2() = default;
  constexpr id2(int n) : id0(detail::id3(n)), dim_(1 << id0) {}
  constexpr int64_t order(int x, int y) const {
    assert(0 <= x && x < dim_);
    assert(0 <= y && y < dim_);
    int64_t res = 0;
    for (int i = id0; i-- > 0;) {
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
  int id0;
  int dim_;
};
class custom_hash {
public:
  static inline const uint64_t fx =
      std::chrono::high_resolution_clock::now().time_since_epoch().count();
  static inline uint64_t hash64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  static inline uint32_t hash32(uint32_t x) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
  }
  inline size_t operator()(detail::qword_fittable auto x) const {
    return hash64(x ^ fx);
  }
  inline size_t operator()(detail::dword_fittable auto x) const {
    return hash32(x ^ static_cast<uint32_t>(fx));
  }
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
using std::nullopt;
using std::optional;
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
using bint = uint8_t;
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
int compute(const vector<int>& an) {
  constexpr int S = 100;
  using fmap = algo::hash_map<int, int>;
  int n = an.size();
  int ans = 1;
  for (int d = 0; d < S; ++d) {
    fmap cnt;
    for (int i = 0; i < n; ++i) {
      cnt[an[i] + (n - i) * d]++;
      ans = max(cnt[an[i] + (n - i) * d], ans);
    }
  }
  constexpr int E = 100040 / S;
  vector<fmap> pd(n);
  for (int i = 1; i < n; ++i) {
    for (int j = i - 1; j >= max(i - E, 0); --j) {
      if (int d = (an[i] - an[j]) / (i - j);
          d * (i - j) == an[i] - an[j] && d >= S) {
        pd[i][d] = max(pd[i][d], pd[j][d] + 1);
        ans = max(pd[i][d] + 1, ans);
      }
    }
  }
  return ans;
}
void solve() noexcept {
  int n;
  cin >> n;
  vector<int> an(n);
  for (int i = 0; i < n; ++i) { cin >> an[i]; }
  int ans = compute(an);
  reverse(an.begin(), an.end());
  ans = max(ans, compute(an));
  cout << n - ans << '\n';
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();
  return 0;
}
