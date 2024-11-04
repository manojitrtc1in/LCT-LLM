











































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
id4(Tp n) {
  return std::countl_zero<std::make_unsigned_t<Tp>>(n);
}
template <typename Tp>
constexpr int
id9(Tp n) {
  return std::countr_zero<std::make_unsigned_t<Tp>>(n);
}
template <typename Tp>
constexpr int
bit_width(Tp n) {
  return std::bit_width<std::make_unsigned_t<Tp>>(n);
}
template <typename Tp>
constexpr Tp
id5(Tp n) {
  return static_cast<Tp>(std::bit_floor<std::make_unsigned_t<Tp>>(n));
}
template <typename Tp>
constexpr Tp
id1(Tp n) {
  return static_cast<Tp>(std::bit_ceil<std::make_unsigned_t<Tp>>(n));
}
template <typename Tp>
constexpr int
id2(Tp n) {
  return bit_width(n) - 1;
}
template <typename Tp>
constexpr int
id8(Tp n) {
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
id11(Tp n) {
  if (std::is_constant_evaluated()) { return n ^ (n - 1); }
  return _blsmsk_u32(n);
}
template <qword_fittable Tp>
constexpr Tp
id11(Tp n) {
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
id4(Tp n) {
  return detail::id4(n);
}
template <detail::integer Tp>
constexpr int
id9(Tp n) {
  return detail::id9(n);
}
template <detail::integer Tp>
constexpr int
bit_width(Tp n) {
  return detail::bit_width(n);
}
template <detail::integer Tp>
constexpr Tp
id5(Tp n) {
  return detail::id5(n);
}
template <detail::integer Tp>
constexpr Tp
id1(Tp n) {
  return detail::id1(n);
}
template <detail::integer Tp>
constexpr int
id2(Tp n) {
  return detail::id2(n);
}
template <detail::integer Tp>
constexpr int
id8(Tp n) {
  return detail::id8(n);
}
template <detail::integer Tp>
constexpr Tp
popcount(Tp n) {
  return detail::popcount(n);
}
}
namespace dbg {

}
namespace algo::detail {
constexpr void
assume(bool expr) {
  if (!expr) { __builtin_unreachable(); }
}
}
namespace algo {
template <typename...>
class id10;
template <std::semiregular Monoid, std::semiregular id3,
          detail::binary_op<Monoid> Operation,
          detail::callable<Monoid, Monoid, id3> Map,
          detail::binary_op<id3> Composition,
          detail::callable<Monoid> Identity,
          detail::callable<id3> CompositionIdentity>
class id10<Monoid, id3, Operation, Map, Composition, Identity,
                   CompositionIdentity> {
public:
  id10() = default;
  id10(int n, const Operation& f, const Map& mapping,
               const Composition& g, const Identity& ef,
               const CompositionIdentity& eg)
      : n_(n),
        id7(detail::id8(n)),
        size_(1 << id7),
        tree_(size_ << 1, ef()),
        lazy_(size_, eg()),
        binop_(f),
        map_(mapping),
        comp_(g),
        id_(ef),
        id_comp_(eg) {}
  id10(int n, const Monoid& init, const Operation& f,
               const Map& mapping, const Composition& g, const Identity& ef,
               const CompositionIdentity& eg)
      : n_(n),
        id7(detail::id8(n)),
        size_(1 << id7),
        tree_(size_ << 1, init),
        lazy_(size_, eg()),
        binop_(f),
        map_(mapping),
        comp_(g),
        id_(ef),
        id_comp_(eg) {
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  template <detail::input_iterator<Monoid> InputIterator>
  id10(InputIterator first, InputIterator last, const Operation& f,
               const Map& mapping, const Composition& g, const Identity& ef,
               const CompositionIdentity& eg)
      : id10(std::distance(first, last), f, mapping, g, ef, eg) {
    std::copy(first, last, tree_.begin() + size_);
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  template <
      std::input_iterator InputIterator,
      detail::callable<Monoid, std::iter_value_t<InputIterator> > Generator>
  id10(InputIterator first, InputIterator last, const Operation& f,
               const Map& mapping, const Composition& g, const Identity& ef,
               const CompositionIdentity& eg, const Generator& gen)
      : id10(std::distance(first, last), f, mapping, g, ef, eg) {
    std::transform(first, last, tree_.begin() + size_, gen);
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  void
  set(int pos, const Monoid& new_val) {
    assert(0 <= pos && pos < size());
    pos += size_;
    for (int i = id7; i > 0; --i) { push(pos >> i); }
    tree_[pos] = new_val;
    for (int i = 1; i <= id7; ++i) { update(pos >> i); }
  }
  void
  set(int pos, Monoid&& new_val) {
    assert(0 <= pos && pos < size());
    pos += size_;
    for (int i = id7; i > 0; --i) { push(pos >> i); }
    tree_[pos] = std::move(new_val);
    for (int i = 1; i <= id7; ++i) { update(pos >> i); }
  }
  Monoid
  get(int pos) {
    assert(0 <= pos && pos < size());
    pos += size_;
    for (int i = id7; i > 0; --i) { push(pos >> i); }
    return tree_[pos];
  }
  void
  apply(int pos, const id3& arg) {
    assert(0 <= pos && pos < size());
    pos += size_;
    for (int i = id7; i > 0; --i) { push(pos >> i); }
    tree_[pos] = map_(std::move(tree_[pos]), arg);
    for (int i = 1; i <= id7; ++i) { update(pos >> i); }
  }
  void
  apply(int pos, id3&& arg) {
    assert(0 <= pos && pos < size());
    pos += size_;
    for (int i = id7; i > 0; --i) { push(pos >> i); }
    tree_[pos] = map_(std::move(tree_[pos]), std::move(arg));
    for (int i = 1; i <= id7; ++i) { update(pos >> i); }
  }
  void
  apply(int l, int r, const id3& arg) {
    assert(0 <= l && l <= r && r <= size());
    if (l < r) {
      l += size_;
      r += size_;
      const int tz_l = detail::id9(l);
      const int tz_r = detail::id9(r);
      const int dept = detail::id2(--l ^ r);
      const int mask = (1 << dept) - 1;
      for (int i = id7; i > tz_l; --i) { push(l >> i); }
      for (int i = dept; i > tz_r; --i) { push(r >> i); }
      for (int v = mask & ~l; v != 0; v = detail::blsr(v)) {
        const int tz = detail::id9(v);
        apply_subtree((l >> tz) + 1, arg);
      }
      for (int v = mask & r; v != 0; v = detail::blsr(v)) {
        const int tz = detail::id9(v);
        apply_subtree((r >> tz) - 1, arg);
      }
      for (int i = tz_l + 1; i <= dept; ++i) { update(l >> i); }
      for (int i = tz_r + 1; i <= id7; ++i) { update(r >> i); }
    }
  }
  Monoid
  query(int l, int r) {
    assert(0 <= l && l <= r && r <= size());
    if (l < r) [[likely]] {
      Monoid resl = id_(), resr = id_();
      l += size_;
      r += size_;
      const int tz_l = detail::id9(l);
      const int tz_r = detail::id9(r);
      const int dept = detail::id2(--l ^ r);
      const int mask = (1 << dept) - 1;
      for (int i = id7; i > tz_l; --i) { push(l >> i); }
      for (int i = dept; i > tz_r; --i) { push(r >> i); }
      for (int v = mask & ~l; v != 0; v = detail::blsr(v)) {
        const int tz = detail::id9(v);
        resl = binop_(std::move(resl), tree_[(l >> tz) + 1]);
      }
      for (int v = mask & r; v != 0; v = detail::blsr(v)) {
        const int tz = detail::id9(v);
        resr = binop_(tree_[(r >> tz) - 1], std::move(resr));
      }
      return binop_(std::move(resl), std::move(resr));
    }
    return id_();
  }
  Monoid
  query() const {
    return tree_[1];
  }
  template <std::predicate<Monoid> Predicate>
  int
  id6(int l, const Predicate& pred) {
    assert(0 <= l && l <= size());
    assert(pred(id_()));
    if (l < n_) [[likely]] {
      l += size_;
      for (int i = id7; i > 0; --i) { push(l >> i); }
      Monoid cur = id_();
      do {
        l >>= detail::id9(l);
        if (!pred(binop_(cur, tree_[l]))) {
          while (l < size_) {
            push(l);
            l <<= 1;
            if (Monoid tmp = binop_(cur, tree_[l]); pred(tmp)) {
              cur = std::move(tmp), ++l;
            }
          }
          return l - size_;
        }
        cur = binop_(std::move(cur), tree_[l++]);
      } while (detail::popcount(l) != 1);
    }
    return n_;
  }
  template <std::predicate<Monoid> Predicate>
  int
  id0(int r, const Predicate& pred) {
    assert(0 <= r && r <= size());
    assert(pred(id_()));
    if (r > 0) [[likely]] {
      r += size_ - 1;
      for (int i = id7; i > 0; --i) { push(r >> i); }
      Monoid cur = id_();
      do {
        r >>= detail::id9(~r);
        if (!pred(binop_(tree_[r], cur))) {
          while (r < size_) {
            push(r);
            r <<= 1;
            r |= 1;
            if (Monoid tmp = binop_(tree_[r], cur); pred(tmp)) {
              cur = std::move(tmp), --r;
            }
          }
          return r + 1 - size_;
        }
        cur = binop_(tree_[r], std::move(cur));
      } while (detail::popcount(r--) != 1);
    }
    return 0;
  }
  int
  size() const {
    return n_;
  }
private:
  void
  update(int v) {
    tree_[v] = binop_(tree_[v << 1], tree_[v << 1 | 1]);
  }
  void
  apply_subtree(int v, const id3& arg) {
    tree_[v] = map_(std::move(tree_[v]), arg);
    if (v < size_) { lazy_[v] = comp_(std::move(lazy_[v]), arg); }
  }
  void
  push(int v) {
    apply_subtree(v << 1, lazy_[v]);
    apply_subtree(v << 1 | 1, lazy_[v]);
    lazy_[v] = id_comp_();
  }
  int n_, id7, size_;
  std::vector<Monoid> tree_;
  std::vector<id3> lazy_;
  Operation binop_;
  Map map_;
  Composition comp_;
  Identity id_;
  CompositionIdentity id_comp_;
};
template <std::semiregular Tp, std::semiregular id3,
          detail::callable<Tp, Tp, id3> Map,
          detail::binary_op<id3> Composition,
          detail::callable<id3> CompositionIdentity>
class id10<Tp, id3, Map, Composition, CompositionIdentity> {
public:
  id10() = default;
  id10(int n, const Map& mapping, const Composition& g,
               const CompositionIdentity& eg)
      : n_(n),
        id7(detail::id8(n)),
        size_(1 << id7),
        tree_(size_),
        lazy_(size_, eg()),
        map_(mapping),
        comp_(g),
        id_comp_(eg) {}
  id10(int n, const Tp& init, const Map& mapping, const Composition& g,
               const CompositionIdentity& eg)
      : n_(n),
        id7(detail::id8(n)),
        size_(1 << id7),
        tree_(size_, init),
        lazy_(size_, eg()),
        map_(mapping),
        comp_(g),
        id_comp_(eg) {}
  template <detail::input_iterator<Tp> InputIterator>
  id10(InputIterator first, InputIterator last, const Map& mapping,
               const Composition& g, const CompositionIdentity& eg)
      : id10(std::distance(first, last), mapping, g, eg) {
    std::copy(first, last, tree_.begin());
  }
  template <std::input_iterator InputIterator,
            detail::callable<Tp, std::iter_value_t<InputIterator> > Generator>
  id10(InputIterator first, InputIterator last, const Map& mapping,
               const Composition& g, const CompositionIdentity& eg,
               const Generator& gen)
      : id10(std::distance(first, last), mapping, g, eg) {
    std::transform(first, last, tree_.begin(), gen);
  }
  void
  set(int pos, const Tp& new_val) {
    assert(0 <= pos && pos < size());
    pos += size_;
    for (int i = id7; i > 0; --i) { push(pos >> i); }
    tree_[pos - size_] = new_val;
  }
  void
  set(int pos, Tp&& new_val) {
    assert(0 <= pos && pos < size());
    pos += size_;
    for (int i = id7; i > 0; --i) { push(pos >> i); }
    tree_[pos - size_] = std::move(new_val);
  }
  Tp
  get(int pos) {
    assert(0 <= pos && pos < size());
    pos += size_;
    for (int i = id7; i > 0; --i) { push(pos >> i); }
    return tree_[pos - size_];
  }
  void
  apply(int pos, const id3& arg) {
    assert(0 <= pos && pos < size());
    pos += size_;
    for (int i = id7; i > 0; --i) { push(pos >> i); }
    tree_[pos - size_] = map_(std::move(tree_[pos - size_]), arg);
  }
  void
  apply(int pos, id3&& arg) {
    assert(0 <= pos && pos < size());
    pos += size_;
    for (int i = id7; i > 0; --i) { push(pos >> i); }
    tree_[pos - size_] = map_(std::move(tree_[pos - size_]), std::move(arg));
  }
  void
  apply_commutative(int pos, const id3& arg) {
    assert(0 <= pos && pos < size());
    tree_[pos] = map_(std::move(tree_[pos]), arg);
  }
  void
  apply_commutative(int pos, id3&& arg) {
    assert(0 <= pos && pos < size());
    tree_[pos] = map_(std::move(tree_[pos]), std::move(arg));
  }
  void
  apply(int l, int r, const id3& arg) {
    assert(0 <= l && l <= r && r <= size());
    if (l < r) {
      l += size_;
      r += size_;
      const int tz_l = detail::id9(l);
      const int tz_r = detail::id9(r);
      const int dept = detail::id2(--l ^ r);
      const int mask = (1 << dept) - 1;
      for (int i = id7; i > tz_l; --i) { push(l >> i); }
      for (int i = dept; i > tz_r; --i) { push(r >> i); }
      for (int v = mask & ~l; v != 0; v = detail::blsr(v)) {
        const int tz = detail::id9(v);
        apply_subtree((l >> tz) + 1, arg);
      }
      for (int v = mask & r; v != 0; v = detail::blsr(v)) {
        const int tz = detail::id9(v);
        apply_subtree((r >> tz) - 1, arg);
      }
    }
  }
  void
  apply_commutative(int l, int r, const id3& arg) {
    assert(0 <= l && l <= r && r <= size());
    l += size_;
    r += size_;
    const int mask = (1 << detail::id2(--l ^ r)) - 1;
    for (int v = mask & ~l; v != 0; v = detail::blsr(v)) {
      const int tz = detail::id9(v);
      apply_subtree((l >> tz) + 1, arg);
    }
    for (int v = mask & r; v != 0; v = detail::blsr(v)) {
      const int tz = detail::id9(v);
      apply_subtree((r >> tz) - 1, arg);
    }
  }
  int
  size() const {
    return n_;
  }
private:
  void
  apply_subtree(int v, const id3& arg) {
    if (v < size_) [[likely]] {
      lazy_[v] = comp_(std::move(lazy_[v]), arg);
    } else {
      tree_[v - size_] = map_(std::move(tree_[v - size_]), arg);
    }
  }
  void
  push(int v) {
    apply_subtree(v << 1, lazy_[v]);
    apply_subtree(v << 1 | 1, lazy_[v]);
    lazy_[v] = id_comp_();
  }
  int n_, id7, size_;
  std::vector<Tp> tree_;
  std::vector<id3> lazy_;
  Map map_;
  Composition comp_;
  CompositionIdentity id_comp_;
};
}
namespace algo::detail {
template <typename Tp>
constexpr Tp
sqrt(Tp n) {
  if (n <= 1) { return n; }
  Tp ans = 0;
  for (int i = id2(n) - 1; i >= 0; --i) {
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





namespace {
}
void solve() noexcept {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> adj(n);
  vector<int> dep(n), tin(n), tout(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[--u].emplace_back(--v);
    adj[v].emplace_back(u);
  }
  vector<int> fa(n);
  int time = 0;
  dep[0] = 1;
  auto dfs = [&](auto self, int u, int p) -> void {
    tin[u] = time++;
    fa[u] = p;
    for (const int v : adj[u]) {
      if (v != p) {
        dep[v] = dep[u] + 1;
        self(self, v, u);
      }
    }
    tout[u] = time;
  };
  dfs(dfs, 0, 0);
  auto f = [](pair<int, int> x, pair<int, int> y) { return max(x, y); };
  auto mp = [](pair<int, int> x, int y) { return pair(x.first + y, x.second); };
  auto g = [](int x, int y) { return x + y; };
  auto ef = [] { return pair(0, -1); };
  auto eg = [] { return 0; };
  assert(time == n);
  vector<pair<int, int>> dat(time);
  for (int i = 0; i < n; ++i) { dat[tin[i]] = {dep[i], i}; }
  algo::id10<pair<int, int>, int, decltype(f), decltype(mp),
                     decltype(g), decltype(ef), decltype(eg)>
      lsg(dat.begin(), dat.end(), f, mp, g, ef, eg);
  auto opt = [n](int rem) {
    wint v = min(rem, n / 2);
    return v * (n - v);
  };
  wint ans = -opt(n);
  int red = 0;
  vector<char> vis(n, false);
  for (int x = 1; x <= k; ++x) {
    auto [d, u] = lsg.query();
    red += d;
    for (; !vis[u]; u = fa[u]) {
      vis[u] = true;
      lsg.apply(tin[u], tout[u], -1);
    }
    ans = max(ans, x * wint(1) * (n - x) - opt(n - red));
  }
  cout << ans << '\n';
}
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cout.precision(15);
  solve();
  return 0;
}
