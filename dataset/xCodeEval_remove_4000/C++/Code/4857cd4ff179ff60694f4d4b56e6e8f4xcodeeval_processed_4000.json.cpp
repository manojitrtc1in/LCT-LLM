














































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
constexpr Tp id2(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return static_cast<Tp>(std::bit_ceil<Up>(n));
}
template <typename Tp>
constexpr int id3(Tp n) {
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
constexpr int id4(Tp n) {
  return detail::id4(n);
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
constexpr Tp id2(Tp n) {
  return detail::id2(n);
}
template <detail::integer Tp>
constexpr int id3(Tp n) {
  return detail::id3(n);
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
constexpr Tp popcount(Tp n) {
  return detail::popcount(n);
}
}


namespace algo {
template <std::semiregular Monoid,
          detail::function<Monoid(Monoid, Monoid)> BinOp,
          detail::function<Monoid(void)> Id>
class id5 {
public:
  id5() = default;
  id5(int n, BinOp binop, Id id) noexcept
      : tree_(n + 1, id()), binop_(std::move(binop)), id_(std::move(id)) {}
  void apply(int pos, const Monoid& z) {
    for (int i = pos + 1; i <= size(); i += detail::blsi(i)) {
      tree_[i] = binop_(std::move(tree_[i]), z);
    }
  }
  Monoid query(int r) const {
    Monoid res = id_();
    for (int i = r; i > 0; i = detail::blsr(i)) {
      res = binop_(tree_[i], std::move(res));
    }
    return res;
  }
  int size() const { return static_cast<int>(tree_.size()) - 1; }
private:
  std::vector<Monoid> tree_;
  BinOp binop_;
  Id id_;
};
}
namespace algo {
template <typename Monoid, typename Mact, typename Map, typename Comp,
          typename CompId, typename BinOp = void, typename id1 = void>
class id12;
template <std::semiregular Monoid, std::semiregular Mact,
          detail::function<Monoid(Monoid, Mact)> Map,
          detail::function<Mact(Mact, Mact)> Comp,
          detail::function<Mact(void)> CompId,
          detail::function<Monoid(Monoid, Monoid)> BinOp,
          detail::function<Monoid(void)> id1>
class id12<Monoid, Mact, Map, Comp, CompId, BinOp, id1> {
public:
  id12() = default;
  id12(int n, Map map, Comp comp, CompId comp_id, BinOp binop,
               id1 id6) noexcept
      : n_(n),
        id9(detail::id10(n)),
        size_(1 << id9),
        tree_(size_ << 1, id6()),
        lazy_(size_, comp_id()),
        map_(std::move(map)),
        comp_(std::move(comp)),
        comp_id_(std::move(comp_id)),
        binop_(std::move(binop)),
        binop_id_(std::move(id6)) {}
  id12(int n, const Monoid& init, Map map, Comp comp, CompId comp_id,
               BinOp binop, id1 id6) noexcept
      : n_(n),
        id9(detail::id10(n)),
        size_(1 << id9),
        tree_(size_ << 1, init),
        lazy_(size_, comp_id()),
        map_(std::move(map)),
        comp_(std::move(comp)),
        comp_id_(std::move(comp_id)),
        binop_(std::move(binop)),
        binop_id_(std::move(id6)) {
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  template <detail::input_iterator<Monoid> IIter>
  id12(IIter first, IIter last, Map map, Comp comp, CompId comp_id,
               BinOp binop, id1 id6) noexcept
      : id12(static_cast<int>(std::distance(first, last)),
                     std::move(map), std::move(comp), std::move(comp_id),
                     std::move(binop), std::move(id6)) {
    std::copy(first, last, tree_.begin() + size_);
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  template <std::input_iterator IIter,
            detail::function<Monoid(std::iter_value_t<IIter>)> Gen>
  id12(IIter first, IIter last, Map map, Comp comp, CompId comp_id,
               BinOp binop, id1 id6, Gen gen) noexcept
      : id12(static_cast<int>(std::distance(first, last)),
                     std::move(map), std::move(comp), std::move(comp_id),
                     std::move(binop), std::move(id6)) {
    std::transform(first, last, tree_.begin() + size_, std::move(gen));
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  void set(int pos, Monoid new_val) {
    pos += size_;
    for (int i = id9; i > 0; --i) { push(pos >> i); }
    tree_[pos] = std::move(new_val);
    for (int i = 1; i <= id9; ++i) { update(pos >> i); }
  }
  Monoid get(int pos) {
    pos += size_;
    for (int i = id9; i > 0; --i) { push(pos >> i); }
    return tree_[pos];
  }
  void apply(int pos, Mact arg) {
    pos += size_;
    for (int i = id9; i > 0; --i) { push(pos >> i); }
    tree_[pos] = map_(std::move(tree_[pos]), std::move(arg));
    for (int i = 1; i <= id9; ++i) { update(pos >> i); }
  }
  void apply_commutative(int pos, Mact arg) {
    pos += size_;
    tree_[pos] = map_(std::move(tree_[pos]), std::move(arg));
    for (int i = 1; i <= id9; ++i) { push_update(pos >> i); }
  }
  void apply(int l, int r, const Mact& arg) {
    if (l < r) {
      l += size_ - 1;
      r += size_ + 0;
      const int tzl = detail::id11(~l);
      const int tzr = detail::id11(r);
      const int mask = detail::id7(l ^ r) - 1;
      for (int i = id9; i > tzl; --i) { push(l >> i); }
      for (int i = id9; i > tzr; --i) { push(r >> i); }
      for (int v = mask & ~l; v != 0; v = detail::blsr(v)) {
        propagate((l >> detail::id11(v)) + 1, arg);
      }
      for (int v = mask & r; v != 0; v = detail::blsr(v)) {
        propagate((r >> detail::id11(v)) - 1, arg);
      }
      for (int i = tzl + 1; i <= id9; ++i) { update(l >> i); }
      for (int i = tzr + 1; i <= id9; ++i) { update(r >> i); }
    }
  }
  void apply_commutative(int l, int r, const Mact& arg) {
    if (l < r) {
      l += size_ - 1;
      r += size_ + 0;
      const int tzl = detail::id11(~l);
      const int tzr = detail::id11(r);
      const int mask = detail::id7(l ^ r) - 1;
      for (int v = mask & ~l; v != 0; v = detail::blsr(v)) {
        propagate((l >> detail::id11(v)) + 1, arg);
      }
      for (int v = mask & r; v != 0; v = detail::blsr(v)) {
        propagate((r >> detail::id11(v)) - 1, arg);
      }
      for (int i = tzl + 1; i <= id9; ++i) { push_update(l >> i); }
      for (int i = tzr + 1; i <= id9; ++i) { push_update(r >> i); }
    }
  }
  Monoid query(int l, int r) {
    if (l < r) [[likely]] {
      Monoid resl = binop_id_(), resr = binop_id_();
      l += size_ - 1;
      r += size_ + 0;
      const int tzl = detail::id11(~l);
      const int tzr = detail::id11(r);
      const int mask = detail::id7(l ^ r) - 1;
      for (int i = id9; i > tzl; --i) { push(l >> i); }
      for (int i = id9; i > tzr; --i) { push(r >> i); }
      for (int v = mask & ~l; v != 0; v = detail::blsr(v)) {
        resl = binop_(std::move(resl), tree_[(l >> detail::id11(v)) + 1]);
      }
      for (int v = mask & r; v != 0; v = detail::blsr(v)) {
        resr = binop_(tree_[(r >> detail::id11(v)) - 1], std::move(resr));
      }
      return binop_(std::move(resl), std::move(resr));
    }
    return binop_id_();
  }
  Monoid query() const { return tree_[1]; }
  template <std::predicate<Monoid> Pred>
  int id8(int l, const Pred& pred) {
    if (l < size()) [[likely]] {
      l += size_;
      for (int i = id9; i > 0; --i) { push(l >> i); }
      Monoid cur = binop_id_();
      do {
        l >>= detail::id11(l);
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
    return size();
  }
  template <std::predicate<Monoid> Pred>
  int id0(int r, const Pred& pred) {
    if (r > 0) [[likely]] {
      r += size_ - 1;
      for (int i = id9; i > 0; --i) { push(r >> i); }
      Monoid cur = binop_id_();
      do {
        r >>= detail::id11(~r);
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
  int size() const { return n_; }
  Monoid map(Monoid x, Mact a) const {
    return map_(std::move(x), std::move(a));
  }
  Mact comp(Mact a, Mact b) const { return comp_(std::move(a), std::move(b)); }
  Mact comp_id() const { return comp_id_(); }
  Monoid binop(Monoid x, Monoid y) const {
    return binop_(std::move(x), std::move(y));
  }
  Monoid id6() const { return binop_id_(); }
private:
  void update(int v) { tree_[v] = binop_(tree_[v << 1], tree_[v << 1 | 1]); }
  void push_update(int v) {
    update(v);
    tree_[v] = map_(std::move(tree_[v]), lazy_[v]);
  }
  void propagate(int v, const Mact& arg) {
    tree_[v] = map_(std::move(tree_[v]), arg);
    if (v < size_) { lazy_[v] = comp_(std::move(lazy_[v]), arg); }
  }
  void push(int v) {
    propagate(v << 1, lazy_[v]);
    propagate(v << 1 | 1, lazy_[v]);
    lazy_[v] = comp_id_();
  }
  int n_;
  int id9;
  int size_;
  std::vector<Monoid> tree_;
  std::vector<Mact> lazy_;
  Map map_;
  Comp comp_;
  CompId comp_id_;
  BinOp binop_;
  id1 binop_id_;
};
template <std::semiregular Tp, std::semiregular Mact,
          detail::function<Tp(Tp, Mact)> Map,
          detail::function<Mact(Mact, Mact)> Comp,
          detail::function<Mact(void)> CompId>
class id12<Tp, Mact, Map, Comp, CompId, void, void> {
public:
  id12() = default;
  id12(int n, Map map, Comp comp, CompId comp_id) noexcept
      : size_(n),
        tree_(size_),
        lazy_(size_, comp_id()),
        map_(std::move(map)),
        comp_(std::move(comp)),
        comp_id_(std::move(comp_id)) {}
  id12(int n, const Tp& init, Map map, Comp comp,
               CompId comp_id) noexcept
      : size_(n),
        tree_(size_, init),
        lazy_(size_, comp_id()),
        map_(std::move(map)),
        comp_(std::move(comp)),
        comp_id_(std::move(comp_id)) {}
  id12(std::vector<Tp> vec, Map map, Comp comp, CompId comp_id) noexcept
      : size_(static_cast<int>(vec.size())),
        tree_(std::move(vec)),
        lazy_(size_, comp_id()),
        map_(std::move(map)),
        comp_(std::move(comp)),
        comp_id_(std::move(comp_id)) {}
  template <detail::input_iterator<Tp> IIter>
  id12(IIter first, IIter last, Map map, Comp comp,
               CompId comp_id) noexcept
      : id12(static_cast<int>(std::distance(first, last)),
                     std::move(map), std::move(comp), std::move(comp_id)) {
    std::copy(first, last, tree_.begin());
  }
  template <std::input_iterator IIter,
            detail::function<Tp(std::iter_value_t<IIter>)> Gen>
  id12(IIter first, IIter last, Map map, Comp comp, CompId comp_id,
               Gen gen) noexcept
      : id12(static_cast<int>(std::distance(first, last)),
                     std::move(map), std::move(comp), std::move(comp_id)) {
    std::transform(first, last, tree_.begin(), std::move(gen));
  }
  void set(int pos, Tp new_val) {
    pos += size_;
    for (int i = detail::id3(pos); i > 0; --i) { push(pos >> i); }
    tree_[pos - size_] = std::move(new_val);
  }
  Tp get(int pos) {
    pos += size_;
    for (int i = detail::id3(pos); i > 0; --i) { push(pos >> i); }
    return tree_[pos - size_];
  }
  void apply(int pos, Mact arg) {
    pos += size_;
    for (int i = detail::id3(pos); i > 0; --i) { push(pos >> i); }
    tree_[pos - size_] = map_(std::move(tree_[pos - size_]), std::move(arg));
  }
  void apply_commutative(int pos, Mact arg) {
    tree_[pos] = map_(std::move(tree_[pos]), std::move(arg));
  }
  void apply(int l, int r, const Mact& arg) {
    if (l < r) {
      l += size_ - 1;
      r += size_ + 0;
      const int tzl = detail::id11(~l);
      const int tzr = detail::id11(r);
      const int mask = detail::id7(l ^ r) - 1;
      for (int i = detail::id3(l); i > tzl; --i) { push(l >> i); }
      for (int i = detail::id3(r); i > tzr; --i) { push(r >> i); }
      for (int v = mask & ~l; v != 0; v = detail::blsr(v)) {
        propagate((l >> detail::id11(v)) + 1, arg);
      }
      for (int v = mask & r; v != 0; v = detail::blsr(v)) {
        propagate((r >> detail::id11(v)) - 1, arg);
      }
    }
  }
  void apply_commutative(int l, int r, const Mact& arg) {
    l += size_ - 1;
    r += size_ + 0;
    const int mask = detail::id7(l ^ r) - 1;
    for (int v = mask & ~l; v != 0; v = detail::blsr(v)) {
      propagate((l >> detail::id11(v)) + 1, arg);
    }
    for (int v = mask & r; v != 0; v = detail::blsr(v)) {
      propagate((r >> detail::id11(v)) - 1, arg);
    }
  }
  int size() const { return size_; }
  Tp map(Tp x, Mact a) const { return map_(std::move(x), std::move(a)); }
  Mact comp(Mact a, Mact b) const { return comp_(std::move(a), std::move(b)); }
  Mact comp_id() const { return comp_id_(); }
private:
  void propagate(int v, Mact arg) {
    if (v < size_) [[likely]] {
      lazy_[v] = comp_(std::move(lazy_[v]), std::move(arg));
    } else {
      tree_[v - size_] = map_(std::move(tree_[v - size_]), std::move(arg));
    }
  }
  void push(int v) {
    propagate(v << 1, lazy_[v]);
    propagate(v << 1 | 1, std::move(lazy_[v]));
    lazy_[v] = comp_id_();
  }
  int size_;
  std::vector<Tp> tree_;
  std::vector<Mact> lazy_;
  Map map_;
  Comp comp_;
  CompId comp_id_;
};
}
namespace algo::detail {
template <typename Tp>
constexpr Tp sqrt(Tp n) {
  if (n == 0) { return 0; }
  Tp res = 0;
  for (int i = id3(n) >> 1; i >= 0; --i) {
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
  return detail::sqrt(n);
}
template <detail::integer Tp>
constexpr Tp id13(Tp n) {
  if (n == 0) { return 0; }
  Tp res = 0;
  const Tp m = detail::abs(n);
  for (int i = detail::id3(m) / 3; i >= 0; --i) {
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
constexpr std::common_type_t<T1, T2, T3, T4> floor_sum(T1 a, T2 b, T3 c, T4 n) {
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
  using mat3 = array<array<wint, 3>, 3>;
  using vec3 = array<wint, 3>;
  constexpr mat3 A = {{{1, 0, 0}, {1, 1, 0}, {1, 2, 1}}};
  constexpr mat3 AInv = {{
      {1, 0, 0},
      {-1, 1, 0},
      {1, -2, 1},
  }};
  auto g = [](mat3 x, mat3 y) {
    mat3 res{};
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 3; ++k) { res[i][j] += y[i][k] * x[k][j]; }
      }
    }
    return res;
  };
  auto mp = [](vec3 v, mat3 t) {
    vec3 res{};
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) { res[i] += t[i][j] * v[j]; }
    }
    return res;
  };
  auto eg = []() -> mat3 { return {{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}}; };
  auto fx = [](vec3 x, vec3 y) -> vec3 {
    return {x[0] + y[0], x[1] + y[1], x[2] + y[2]};
  };
  auto ef = []() -> vec3 { return {0, 0, 0}; };
  const int N = 200001;
  algo::id12<vec3, mat3, decltype(mp), decltype(g), decltype(eg),
                     decltype(fx), decltype(ef)>
      lsg(N, mp, g, eg, fx, ef);
  int q, d;
  cin >> q >> d;
  vector<bool> in(N);
  while (q--) {
    int p;
    cin >> p;
    if (!in[p]) {
      wint cnt = lsg.query(p + 1, min(lsg.size(), p + d + 1))[0];
      lsg.apply(max(p - d, 0), p, A);
      lsg.set(p, {1, cnt, cnt * cnt});
      in[p] = true;
    } else {
      lsg.apply(max(p - d, 0), p, AInv);
      lsg.set(p, {0, 0, 0});
      in[p] = false;
    }
    auto [x0, x1, x2] = lsg.query();
    cout << (x2 - x1) / 2 << '\n';
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();
  return 0;
}
