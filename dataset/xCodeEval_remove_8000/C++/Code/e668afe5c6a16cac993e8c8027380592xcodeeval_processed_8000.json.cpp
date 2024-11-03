














































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
constexpr int id13(Tp n) {
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
constexpr Tp id4(Tp n) {
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
constexpr int id12(Tp n) {
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
constexpr int id13(Tp n) {
  return detail::id13(n);
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
constexpr Tp id4(Tp n) {
  return detail::id4(n);
}
template <detail::integer Tp>
constexpr int id5(Tp n) {
  return detail::id5(n);
}
template <detail::integer Tp>
constexpr int id12(Tp n) {
  return detail::id12(n);
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


namespace algo {
template <typename Monoid, typename Mact, typename Map, typename Comp,
          typename CompId, typename BinOp = void, typename id3 = void>
class id14;
}
namespace algo {
template <std::semiregular Monoid, std::semiregular Mact,
          detail::function<Monoid(Monoid, Mact)> Map,
          detail::function<Mact(Mact, Mact)> Comp,
          detail::function<Mact(void)> CompId,
          detail::function<Monoid(Monoid, Monoid)> BinOp,
          detail::function<Monoid(void)> id3>
class id14<Monoid, Mact, Map, Comp, CompId, BinOp, id3> {
public:
  id14() = default;
  id14(int n, Map map, Comp comp, CompId comp_id, BinOp binop,
               id3 id7) noexcept
      : n_(n),
        id10(detail::id12(n)),
        size_(1 << id10),
        tree_(size_ << 1, id7()),
        lazy_(size_, comp_id()),
        map_(std::move(map)),
        comp_(std::move(comp)),
        comp_id_(std::move(comp_id)),
        binop_(std::move(binop)),
        binop_id_(std::move(id7)) {}
  id14(int n, const Monoid& def, Map map, Comp comp, CompId comp_id,
               BinOp binop, id3 id7) noexcept
      : id14(n, std::move(map), std::move(comp), std::move(comp_id),
                     std::move(binop), std::move(id7)) {
    std::fill_n(tree_.begin() + size_, size(), def);
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  template <detail::input_iterator<Monoid> IIter>
  id14(IIter first, IIter last, Map map, Comp comp, CompId comp_id,
               BinOp binop, id3 id7) noexcept
      : id14(static_cast<int>(std::distance(first, last)),
                     std::move(map), std::move(comp), std::move(comp_id),
                     std::move(binop), std::move(id7)) {
    std::copy(first, last, tree_.begin() + size_);
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  template <std::input_iterator IIter,
            detail::function<Monoid(std::iter_value_t<IIter>)> Gen>
  id14(IIter first, IIter last, Map map, Comp comp, CompId comp_id,
               BinOp binop, id3 id7, Gen gen) noexcept
      : id14(static_cast<int>(std::distance(first, last)),
                     std::move(map), std::move(comp), std::move(comp_id),
                     std::move(binop), std::move(id7)) {
    std::transform(first, last, tree_.begin() + size_, std::move(gen));
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  void set(int pos, Monoid new_val) {
    pos += size_;
    for (int i = id10; i > 0; --i) { push(pos >> i); }
    tree_[pos] = std::move(new_val);
    for (int i = 1; i <= id10; ++i) { update(pos >> i); }
  }
  Monoid get(int pos) {
    pos += size_;
    for (int i = id10; i > 0; --i) { push(pos >> i); }
    return tree_[pos];
  }
  void apply(int pos, Mact arg) {
    pos += size_;
    for (int i = id10; i > 0; --i) { push(pos >> i); }
    tree_[pos] = map_(tree_[pos], std::move(arg));
    for (int i = 1; i <= id10; ++i) { update(pos >> i); }
  }
  void apply_commutative(int pos, Mact arg) {
    pos += size_;
    tree_[pos] = map_(tree_[pos], std::move(arg));
    for (int i = 1; i <= id10; ++i) { push_update(pos >> i); }
  }
  void apply(int l, int r, const Mact& arg) {
    if (l < r) {
      l += size_ - 1;
      r += size_ + 0;
      const int tzl = detail::id13(~l);
      const int tzr = detail::id13(r);
      const int mask = detail::id8(l ^ r) - 1;
      for (int i = id10; i > tzl; --i) { push(l >> i); }
      for (int i = id10; i > tzr; --i) { push(r >> i); }
      for (int v = mask & ~l; v != 0; v = detail::blsr(v)) {
        propagate((l >> detail::id13(v)) + 1, arg);
      }
      for (int v = mask & r; v != 0; v = detail::blsr(v)) {
        propagate((r >> detail::id13(v)) - 1, arg);
      }
      for (int i = tzl + 1; i <= id10; ++i) { update(l >> i); }
      for (int i = tzr + 1; i <= id10; ++i) { update(r >> i); }
    }
  }
  void apply_commutative(int l, int r, const Mact& arg) {
    if (l < r) {
      l += size_ - 1;
      r += size_ + 0;
      const int tzl = detail::id13(~l);
      const int tzr = detail::id13(r);
      const int mask = detail::id8(l ^ r) - 1;
      for (int v = mask & ~l; v != 0; v = detail::blsr(v)) {
        propagate((l >> detail::id13(v)) + 1, arg);
      }
      for (int v = mask & r; v != 0; v = detail::blsr(v)) {
        propagate((r >> detail::id13(v)) - 1, arg);
      }
      for (int i = tzl + 1; i <= id10; ++i) { push_update(l >> i); }
      for (int i = tzr + 1; i <= id10; ++i) { push_update(r >> i); }
    }
  }
  Monoid query(int l, int r) {
    if (l < r) [[likely]] {
      Monoid resl = binop_id_(), resr = binop_id_();
      l += size_ - 1;
      r += size_ + 0;
      const int tzl = detail::id13(~l);
      const int tzr = detail::id13(r);
      const int mask = detail::id8(l ^ r) - 1;
      for (int i = id10; i > tzl; --i) { push(l >> i); }
      for (int i = id10; i > tzr; --i) { push(r >> i); }
      for (int v = mask & ~l; v != 0; v = detail::blsr(v)) {
        resl = binop_(resl, tree_[(l >> detail::id13(v)) + 1]);
      }
      for (int v = mask & r; v != 0; v = detail::blsr(v)) {
        resr = binop_(tree_[(r >> detail::id13(v)) - 1], resr);
      }
      return binop_(std::move(resl), std::move(resr));
    }
    return binop_id_();
  }
  Monoid query() const { return tree_[1]; }
  template <std::predicate<Monoid> Pred>
  int id9(int l, const Pred& pred) {
    if (l < size()) [[likely]] {
      l += size_;
      for (int i = id10; i > 0; --i) { push(l >> i); }
      Monoid cur = binop_id_();
      do {
        l >>= detail::id13(l);
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
        cur = binop_(cur, tree_[l++]);
      } while (detail::popcount(l) != 1);
    }
    return size();
  }
  template <std::predicate<Monoid> Pred>
  int id1(int r, const Pred& pred) {
    if (r > 0) [[likely]] {
      r += size_ - 1;
      for (int i = id10; i > 0; --i) { push(r >> i); }
      Monoid cur = binop_id_();
      do {
        r >>= detail::id13(~r);
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
        cur = binop_(tree_[r], cur);
      } while (detail::popcount(r--) != 1);
    }
    return 0;
  }
  int size() const { return n_; }
private:
  void update(int v) { tree_[v] = binop_(tree_[v << 1], tree_[v << 1 | 1]); }
  void push_update(int v) {
    update(v);
    tree_[v] = map_(tree_[v], lazy_[v]);
  }
  void propagate(int v, const Mact& arg) {
    tree_[v] = map_(tree_[v], arg);
    if (v < size_) { lazy_[v] = comp_(lazy_[v], arg); }
  }
  void push(int v) {
    propagate(v << 1, lazy_[v]);
    propagate(v << 1 | 1, lazy_[v]);
    lazy_[v] = comp_id_();
  }
  int n_;
  int id10;
  int size_;
  std::vector<Monoid> tree_;
  std::vector<Mact> lazy_;
  Map map_;
  Comp comp_;
  CompId comp_id_;
  BinOp binop_;
  id3 binop_id_;
};
}
namespace algo {
template <std::semiregular Monoid, std::semiregular Mact,
          detail::function<Monoid(Monoid, Mact)> Map,
          detail::function<Mact(Mact, Mact)> Comp,
          detail::function<Mact(void)> CompId,
          detail::function<Monoid(Monoid, Monoid)> BinOp,
          detail::function<Monoid(void)> id3>
auto id2(int n, Map map, Comp comp, CompId comp_id, BinOp binop,
                       id3 id7)
    -> id14<Monoid, Mact, Map, Comp, CompId, BinOp, id3> {
  return {n,
          std::move(map),
          std::move(comp),
          std::move(comp_id),
          std::move(binop),
          std::move(id7)};
}
template <std::semiregular Monoid, std::semiregular Mact,
          detail::function<Monoid(Monoid, Mact)> Map,
          detail::function<Mact(Mact, Mact)> Comp,
          detail::function<Mact(void)> CompId,
          detail::function<Monoid(Monoid, Monoid)> BinOp,
          detail::function<Monoid(void)> id3>
auto id2(int n, const Monoid& def, Map map, Comp comp,
                       CompId comp_id, BinOp binop, id3 id7)
    -> id14<Monoid, Mact, Map, Comp, CompId, BinOp, id3> {
  return {n,
          def,
          std::move(map),
          std::move(comp),
          std::move(comp_id),
          std::move(binop),
          std::move(id7)};
}
template <std::semiregular Monoid, std::semiregular Mact,
          detail::function<Monoid(Monoid, Mact)> Map,
          detail::function<Mact(Mact, Mact)> Comp,
          detail::function<Mact(void)> CompId,
          detail::function<Monoid(Monoid, Monoid)> BinOp,
          detail::function<Monoid(void)> id3,
          detail::input_iterator<Monoid> IIter>
auto id2(IIter first, IIter last, Map map, Comp comp,
                       CompId comp_id, BinOp binop, id3 id7)
    -> id14<Monoid, Mact, Map, Comp, CompId, BinOp, id3> {
  return {first,
          last,
          std::move(map),
          std::move(comp),
          std::move(comp_id),
          std::move(binop),
          std::move(id7)};
}
template <std::semiregular Monoid, std::semiregular Mact,
          detail::function<Monoid(Monoid, Mact)> Map,
          detail::function<Mact(Mact, Mact)> Comp,
          detail::function<Mact(void)> CompId,
          detail::function<Monoid(Monoid, Monoid)> BinOp,
          detail::function<Monoid(void)> id3, std::input_iterator IIter,
          detail::function<Monoid(std::iter_value_t<IIter>)> Gen>
auto id2(IIter first, IIter last, Map map, Comp comp,
                       CompId comp_id, BinOp binop, id3 id7, Gen gen)
    -> id14<Monoid, Mact, Map, Comp, CompId, BinOp, id3> {
  return {first,
          last,
          std::move(map),
          std::move(comp),
          std::move(comp_id),
          std::move(binop),
          std::move(id7),
          std::move(gen)};
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
class id11 {
public:
  id11() = default;
  id11(int n, BinOp binop, Id id) noexcept
      : n_(n),
        id10(detail::id12(n)),
        size_(1 << id10),
        tree_(size_ << 1, id()),
        binop_(std::move(binop)),
        id_(std::move(id)) {}
  id11(int n, const Monoid& init, BinOp binop, Id id) noexcept
      : id11(n, std::move(binop), std::move(id)) {
    std::fill_n(tree_.begin() + size_, size(), init);
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  template <detail::input_iterator<Monoid> IIter>
  id11(IIter first, IIter last, BinOp binop, Id id) noexcept
      : id11(static_cast<int>(std::distance(first, last)), std::move(binop),
                std::move(id)) {
    std::copy(first, last, tree_.begin() + size_);
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  template <std::input_iterator IIter,
            detail::function<Monoid(std::iter_value_t<IIter>)> Gen>
  id11(IIter first, IIter last, BinOp binop, Id id, Gen gen) noexcept
      : id11(static_cast<int>(std::distance(first, last)), std::move(binop),
                std::move(id)) {
    std::transform(first, last, tree_.begin() + size_, std::move(gen));
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  void set(int pos, Monoid new_val) {
    pos += size_;
    tree_[pos] = std::move(new_val);
    for (int i = 1; i <= id10; ++i) { update(pos >> i); }
  }
  Monoid get(int pos) const { return tree_[pos + size_]; }
  void apply(int pos, Monoid z) {
    pos += size_;
    tree_[pos] = binop_(tree_[pos], std::move(z));
    for (int i = 1; i <= id10; ++i) { update(pos >> i); }
  }
  Monoid query(int l, int r) const {
    Monoid resl = id_(), resr = id_();
    l += size_ - 1;
    r += size_ + 0;
    const int mask = detail::id8(l ^ r) - 1;
    for (int v = mask & ~l; v != 0; v = detail::blsr(v)) {
      resl = binop_(resl, tree_[(l >> detail::id13(v)) + 1]);
    }
    for (int v = mask & r; v != 0; v = detail::blsr(v)) {
      resr = binop_(tree_[(r >> detail::id13(v)) - 1], resr);
    }
    return binop_(std::move(resl), std::move(resr));
  }
  Monoid query() const { return tree_[1]; }
  template <std::predicate<Monoid> Pred>
  int id9(int l, const Pred& pred) const {
    if (l < size()) [[likely]] {
      l += size_;
      Monoid cur = id_();
      do {
        l >>= detail::id13(l);
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
        r >>= detail::id13(~r);
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
  int id10;
  int size_;
  std::vector<Monoid> tree_;
  BinOp binop_;
  Id id_;
};
}
namespace algo {
template <std::semiregular Monoid,
          detail::function<Monoid(Monoid, Monoid)> BinOp,
          detail::function<Monoid(void)> Id>
auto id0(int n, BinOp binop, Id id) -> id11<Monoid, BinOp, Id> {
  return {n, std::move(binop), std::move(id)};
}
template <std::semiregular Monoid,
          detail::function<Monoid(Monoid, Monoid)> BinOp,
          detail::function<Monoid(void)> Id>
auto id0(int n, const Monoid& def, BinOp binop, Id id)
    -> id11<Monoid, BinOp, Id> {
  return {n, def, std::move(binop), std::move(id)};
}
template <
    std::semiregular Monoid, detail::function<Monoid(Monoid, Monoid)> BinOp,
    detail::function<Monoid(void)> Id, detail::input_iterator<Monoid> IIter>
auto id0(IIter first, IIter last, BinOp binop, Id id)
    -> id11<Monoid, BinOp, Id> {
  return {first, last, std::move(binop), std::move(id)};
}
template <std::semiregular Monoid,
          detail::function<Monoid(Monoid, Monoid)> BinOp,
          detail::function<Monoid(void)> Id, std::input_iterator IIter,
          detail::function<Monoid(std::iter_value_t<IIter>)> Gen>
auto id0(IIter first, IIter last, BinOp binop, Id id, Gen gen)
    -> id11<Monoid, BinOp, Id> {
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
void solve() noexcept {
  int n, q;
  cin >> n >> q;
  auto lsg = algo::id2<int, int>(
      n, 1, [](int x, int y) { return y == -1 ? x : y; },
      [](int x, int y) { return y == -1 ? x : y; }, [] { return -1; },
      [](int x, int y) { return x + y; }, [] { return 0; });
  auto seg = algo::id0<int>(
      n, [](int x, int y) { return min(x, y); }, [n] { return n; });
  vector<bool> ans(n, false);
  for (int i = 0; i < q; ++i) {
    if (int t; cin >> t, t == 0) {
      int l, r;
      cin >> l >> r;
      if (int x; cin >> x, x == 0) {
        lsg.apply(l - 1, r, 0);
      } else {
        seg.apply(l - 1, r - 1);
      }
    } else {
      int p;
      cin >> p;
      if (ans[p - 1]) {
        cout << "YES\n";
      } else if (lsg.get(p - 1) == 0) {
        cout << "NO\n";
      } else {
        int lb = lsg.id1(p - 1, [](int x) { return x < 1; });
        int rb = lsg.id9(p, [](int x) { return x < 1; });
        if (seg.query(lb, p) < rb) {
          ans[p - 1] = true;
          cout << "YES\n";
        } else {
          cout << "N/A\n";
        }
      }
    }
  }
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
