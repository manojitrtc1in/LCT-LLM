














































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
constexpr int id6(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::countl_zero<Up>(n);
}
template <typename Tp>
constexpr int id11(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::countr_zero<Up>(n);
}
template <typename Tp>
constexpr int bit_width(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::bit_width<Up>(n);
}
template <typename Tp>
constexpr Tp id7(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return static_cast<Tp>(std::bit_floor<Up>(n));
}
template <typename Tp>
constexpr Tp id3(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return static_cast<Tp>(std::bit_ceil<Up>(n));
}
template <typename Tp>
constexpr int id5(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  constexpr int Nd = std::numeric_limits<Up>::digits;
  return Nd - 1 - std::countl_zero<Up>(n);
}
template <typename Tp>
constexpr int id10(Tp n) {
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
constexpr int id6(Tp n) {
  return detail::id6(n);
}
template <detail::integer Tp>
constexpr int id11(Tp n) {
  return detail::id11(n);
}
template <detail::integer Tp>
constexpr int bit_width(Tp n) {
  return detail::bit_width(n);
}
template <detail::integer Tp>
constexpr Tp id7(Tp n) {
  return detail::id7(n);
}
template <detail::integer Tp>
constexpr Tp id3(Tp n) {
  return detail::id3(n);
}
template <detail::integer Tp>
constexpr int id5(Tp n) {
  return detail::id5(n);
}
template <detail::integer Tp>
constexpr int id10(Tp n) {
  return detail::id10(n);
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
  for (int i = id5(n) >> 1; i >= 0; --i) {
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
template <std::semiregular Monoid,
          detail::function<Monoid(Monoid, Monoid)> BinOp,
          detail::function<Monoid(void)> Id>
class id9 {
public:
  id9() = default;
  id9(int n, BinOp binop, Id id) noexcept
      : n_{n},
        lg2_{detail::id10(n)},
        size_{1 << lg2_},
        tree_(size_ << 1, id()),
        binop_{std::move(binop)},
        id_{std::move(id)} {}
  id9(int n, const Monoid& init, BinOp binop, Id id) noexcept
      : id9(n, std::move(binop), std::move(id)) {
    std::fill_n(tree_.begin() + size_, size(), init);
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  template <detail::input_iterator<Monoid> IIter>
  id9(IIter first, IIter last, BinOp binop, Id id) noexcept
      : id9(static_cast<int>(std::distance(first, last)), std::move(binop),
                std::move(id)) {
    std::copy(first, last, tree_.begin() + size_);
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  template <std::input_iterator IIter,
            detail::function<Monoid(std::iter_value_t<IIter>)> Gen>
  id9(IIter first, IIter last, BinOp binop, Id id, Gen gen) noexcept
      : id9(static_cast<int>(std::distance(first, last)), std::move(binop),
                std::move(id)) {
    std::transform(first, last, tree_.begin() + size_, std::move(gen));
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  void set(int pos, Monoid new_val) {
    pos += size_;
    tree_[pos] = std::move(new_val);
    for (int i = 1; i <= lg2_; ++i) { update(pos >> i); }
  }
  Monoid get(int pos) const { return tree_[pos + size_]; }
  void apply(int pos, Monoid z) {
    pos += size_;
    tree_[pos] = binop_(tree_[pos], std::move(z));
    for (int i = 1; i <= lg2_; ++i) { update(pos >> i); }
  }
  Monoid query(int l, int r) const {
    Monoid resl = id_(), resr = id_();
    l += size_ - 1;
    r += size_ + 0;
    const int mask = detail::id7(l ^ r) - 1;
    for (int v = mask & ~l; v != 0; v = detail::blsr(v)) {
      resl = binop_(resl, tree_[(l >> detail::id11(v)) + 1]);
    }
    for (int v = mask & r; v != 0; v = detail::blsr(v)) {
      resr = binop_(tree_[(r >> detail::id11(v)) - 1], resr);
    }
    return binop_(std::move(resl), std::move(resr));
  }
  Monoid query() const { return tree_[1]; }
  template <std::predicate<Monoid> Pred>
  int id8(int l, const Pred& pred) const {
    if (l < size()) [[likely]] {
      l += size_;
      Monoid cur = id_();
      do {
        l >>= detail::id11(l);
        if (!pred(binop_(cur, tree_[l]))) {
          while (l < size_) {
            l <<= 1;
            if (Monoid tmp = binop_(cur, tree_[l]); pred(tmp)) {
              cur = std::move(tmp), ++l;
            }
          }
          return l - size_;
        }
        cur = binop_(cur, tree_[l++]);
      } while (detail::popcount(l) != 1);
    }
    return size();
  }
  template <std::predicate<Monoid> Pred>
  int id1(int r, const Pred& pred) const {
    if (r > 0) [[likely]] {
      r += size_ - 1;
      Monoid cur = id_();
      do {
        r >>= detail::id11(~r);
        if (!pred(binop_(tree_[r], cur))) {
          while (r < size_) {
            r <<= 1;
            r |= 1;
            if (Monoid tmp = binop_(tree_[r], cur); pred(tmp)) {
              cur = std::move(tmp), --r;
            }
          }
          return r + 1 - size_;
        }
        cur = binop_(tree_[r], cur);
      } while (detail::popcount(r--) != 1);
    }
    return 0;
  }
  int size() const { return n_; }
  std::vector<Monoid> data() const { return tree_; }
private:
  void update(int v) { tree_[v] = binop_(tree_[v << 1], tree_[v << 1 | 1]); }
  int n_;
  int lg2_;
  int size_;
  std::vector<Monoid> tree_;
  [[no_unique_address]] BinOp binop_;
  [[no_unique_address]] Id id_;
};
}
namespace algo {
template <std::semiregular Monoid,
          detail::function<Monoid(Monoid, Monoid)> BinOp,
          detail::function<Monoid(void)> Id>
auto id0(int n, BinOp binop, Id id) -> id9<Monoid, BinOp, Id> {
  return {n, std::move(binop), std::move(id)};
}
template <std::semiregular Monoid,
          detail::function<Monoid(Monoid, Monoid)> BinOp,
          detail::function<Monoid(void)> Id>
auto id0(int n, const Monoid& def, BinOp binop, Id id)
    -> id9<Monoid, BinOp, Id> {
  return {n, def, std::move(binop), std::move(id)};
}
template <
    std::semiregular Monoid, detail::function<Monoid(Monoid, Monoid)> BinOp,
    detail::function<Monoid(void)> Id, detail::input_iterator<Monoid> IIter>
auto id0(IIter first, IIter last, BinOp binop, Id id)
    -> id9<Monoid, BinOp, Id> {
  return {first, last, std::move(binop), std::move(id)};
}
template <std::semiregular Monoid,
          detail::function<Monoid(Monoid, Monoid)> BinOp,
          detail::function<Monoid(void)> Id, std::input_iterator IIter,
          detail::function<Monoid(std::iter_value_t<IIter>)> Gen>
auto id0(IIter first, IIter last, BinOp binop, Id id, Gen gen)
    -> id9<Monoid, BinOp, Id> {
  return {first, last, std::move(binop), std::move(id), std::move(gen)};
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
  int n;
  cin >> n;
  string s1;
  string s2;
  cin >> s1 >> s2;
  vector p1(n + 1, 0);
  vector p2(n + 1, 0);
  transform(s1.begin(), s1.end(), p1.begin() + 1,
            [](char c) { return c - '0'; });
  transform(s2.begin(), s2.end(), p2.begin() + 1,
            [](char c) { return c - '0'; });
  for (int i = 1; i <= n; ++i) {
    p1[i] += p1[i - 1];
    p2[i] += p2[i - 1];
  }
  auto fx = [](int x, int y) { return min(x, y); };
  auto ef = [] { return INF; };
  auto id4 = algo::id0<int>(n + 3, fx, ef);
  auto id2 = algo::id0<int>(n + 3, fx, ef);
  id4.set(n + 2, p1[n]);
  id2.set(n + 2, p2[n]);
  for (int i = n; i > 0; --i) {
    if (s1[i - 1] == '1') {
      int tj = id2.query(i + 2, id2.size());
      id4.set(i, tj - p2[i] + p1[i - 1]);
    }
    if (s2[i - 1] == '1') {
      int tj = id4.query(i + 2, id4.size());
      id2.set(i, tj - p1[i] + p2[i - 1]);
    }
  }
  cout << p1[n] + p2[n] - id2.query() << '\n';
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
