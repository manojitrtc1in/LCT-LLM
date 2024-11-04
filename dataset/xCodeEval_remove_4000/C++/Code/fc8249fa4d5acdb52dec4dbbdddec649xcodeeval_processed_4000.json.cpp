











































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
template <typename Tp>
constexpr int
id4(Tp n) {
  return std::countl_zero<std::make_unsigned_t<Tp>>(n);
}
template <typename Tp>
constexpr int
id11(Tp n) {
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
id9(Tp n) {
  return bit_width(n - (n != 0));
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
constexpr Tp
id12(Tp n) {
  if (std::is_constant_evaluated()) { return n ^ (n - 1); }
  if constexpr (dword_fittable<Tp>) {
    return static_cast<Tp>(_blsmsk_u32(n));
  } else if constexpr (qword_fittable<Tp>) {
    return static_cast<Tp>(_blsmsk_u64(n));
  } else {
    return n ^ (n - 1);
  }
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
id11(Tp n) {
  return detail::id11(n);
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
id9(Tp n) {
  return detail::id9(n);
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
namespace detail {
template <typename Derived, typename Node>
class id3 {
public:
  static constexpr int Null = 0;
  id3() = default;
  id3(int n, Node v) : n_(n), tree_(n + 1, v) {}
  void
  reroot(int u) {
    assert(0 < u && u <= size());
    make_root(u);
  }
  void
  link(int v, int u) {
    assert(0 < u && u <= size());
    assert(0 < v && v <= size());
    make_root(u);
    access(v);
    toggle(v, u);
  }
  void
  cut(int v, int u) {
    assert(0 < u && u <= size());
    assert(0 < v && v <= size());
    make_root(v);
    access(u);
    if (tree_[u].children_[0] == v) {
      tree_[u].children_[0] = Null;
      tree_[v].parent_ = Null;
      update(u);
    }
  }
  int
  get_parent(int u) {
    assert(0 < u && u <= size());
    access(u);
    return tree_[u].children_[0];
  }
  int
  get_root(int u) {
    assert(0 < u && u <= size());
    access(u);
    while (tree_[u].children_[0] != Null) {
      u = tree_[u].children_[0];
      push(u);
    }
    splay(u);
    return u;
  }
  bool
  connected(int v, int u) {
    assert(0 < u && u <= size());
    assert(0 < v && v <= size());
    return lca(u, v);
  }
  int
  lca(int v, int u) {
    assert(0 < u && u <= size());
    assert(0 < v && v <= size());
    if (u == v) { return u; }
    access(v);
    int w = Null, z = u;
    do {
      splay(z);
      toggle(z, w);
      w = z, z = tree_[z].parent_;
    } while (z != Null);
    splay(u);
    return tree_[v].parent_ != Null ? w : Null;
  }
  int
  size() const {
    return n_;
  }
protected:
  void
  make_root(int u) {
    access(u);
    tree_[u].flip_ ^= true;
    push(u);
  }
  int
  side(int u) const {
    const int p = tree_[u].parent_;
    if (tree_[p].children_[0] == u) { return 0; }
    if (tree_[p].children_[1] == u) { return 1; }
    return -1;
  }
  void
  access(int u) {
    splay(u);
    toggle(u, 0);
    while (tree_[u].parent_ != Null) {
      const int w = tree_[u].parent_;
      splay(w);
      toggle(w, u);
      rotate(u);
    }
  }
  bool
  is_root(int u) const {
    return side(u) < 0;
  }
  void
  toggle(int v, int u) {
    reset(v, u);
    tree_[v].children_[1] = u;
    tree_[u].parent_ = v;
    update(v);
  }
  void
  rotate(int u) {
    const int v = tree_[u].parent_;
    const int w = tree_[v].parent_;
    const int du = side(u);
    const int dv = side(v);
    attach(v, tree_[u].children_[!du], du);
    attach(u, v, !du);
    if (dv != -1) { attach(w, u, dv); }
    tree_[u].parent_ = w;
  }
  void
  attach(int v, int u, bool d) {
    tree_[v].children_[d] = u;
    tree_[u].parent_ = v;
    update(v);
  }
  void
  push(int u) {
    if (u != Null && tree_[u].flip_) {
      const int l = tree_[u].children_[0];
      const int r = tree_[u].children_[1];
      tree_[l].flip_ ^= true;
      tree_[r].flip_ ^= true;
      std::swap(tree_[u].children_[0], tree_[u].children_[1]);
      tree_[u].flip_ = false;
    }
  }
  void
  splay(int u) {
    push(u);
    while (!is_root(u) && !is_root(tree_[u].parent_)) {
      const int v = tree_[u].parent_;
      const int w = tree_[v].parent_;
      push(w);
      push(v);
      push(u);
      rotate(side(v) == side(u) ? v : u);
      rotate(u);
    }
    if (!is_root(u)) {
      push(tree_[u].parent_);
      push(u);
      rotate(u);
    }
  }
  void
  update(int u) {
    static_cast<Derived *>(this)->update(u);
  }
  void
  reset(int v, int u) {
    static_cast<Derived *>(this)->reset(v, u);
  }
  int n_;
  std::vector<Node> tree_;
};
template <typename Tp = void, bool id7 = false>
struct lct_node {
  int children_[2]{0, 0}, parent_{0};
  bool flip_{0};
  Tp self_, path_, sub_, vsub_;
};
template <typename Tp>
struct lct_node<Tp, false> {
  int children_[2]{0, 0}, parent_{0};
  bool flip_{0};
  Tp self_, path_;
};
template <>
struct lct_node<void, false> {
  int children_[2]{0, 0}, parent_{0};
  bool flip_{0};
};
}
template <typename Tp = void, typename BinOp = void, typename Id = void,
          typename Inv = void>
class id10;
template <std::semiregular Group, detail::function<Group(Group, Group)> BinOp,
          detail::function<Group()> Id, detail::function<Group(Group)> Inv>
class id10<Group, BinOp, Id, Inv>
    : public detail::id3<id10<Group, BinOp, Id, Inv>,
                              detail::lct_node<Group, true>> {
  friend class detail::id3<id10, detail::lct_node<Group, true>>;
  using splay_node = detail::lct_node<Group, true>;
  using base_type = detail::id3<id10, splay_node>;
public:
  id10() = default;
  id10(int n, BinOp binop, Id id, Inv inv)
      : base_type(n, splay_node{{}, {}, {}, id(), id(), id(), id()}),
        binop_(std::move(binop)),
        id_(std::move(id)),
        inv_(std::move(inv)) {}
  id10(int n, const Group &init, BinOp binop, Id id, Inv inv)
      : base_type(n, splay_node{{}, {}, {}, init, init, init, id()}),
        binop_(std::move(binop)),
        id_(std::move(id)),
        inv_(std::move(inv_)) {
    this->tree_[this->Null].self_ = id_();
    this->tree_[this->Null].path_ = id_();
    this->tree_[this->Null].sub_ = id_();
  }
  Group
  query_subtree(int u) {
    assert(0 < u && u <= this->size());
    this->access(u);
    return binop_(this->tree_[u].self_, this->tree_[u].vsub_);
  }
  Group
  query_path(int v, int u) {
    assert(0 < u && u <= this->size());
    assert(0 < v && v <= this->size());
    assert(this->connected(u, v));
    this->make_root(u);
    this->access(v);
    return this->tree_[v].path_;
  }
  void
  set(int u, Group new_val) {
    assert(0 < u && u <= this->size());
    this->access(u);
    this->tree_[u].self_ = std::move(new_val);
    this->update(u);
  }
  Group
  get(int u) const {
    assert(0 < u && u <= this->size());
    return this->tree_[u].self_;
  }
private:
  void
  reset(int v, int u) {
    const int c = this->tree_[v].children_[1];
    this->tree_[v].vsub_ =
        binop_(std::move(this->tree_[v].vsub_), this->tree_[c].sub_);
    if (this->tree_[u].parent_ == v) {
      this->tree_[v].vsub_ =
          binop_(std::move(this->tree_[v].vsub_), inv_(this->tree_[u].sub_));
    }
  }
  void
  update(int u) {
    const int l = this->tree_[u].children_[0];
    const int r = this->tree_[u].children_[1];
    this->tree_[u].sub_ =
        binop_(binop_(this->tree_[u].self_, this->tree_[u].vsub_),
               binop_(this->tree_[l].sub_, this->tree_[r].sub_));
    this->tree_[u].path_ =
        binop_(this->tree_[u].self_,
               binop_(this->tree_[l].path_, this->tree_[r].path_));
  }
  BinOp binop_;
  Id id_;
  Inv inv_;
};
template <std::semiregular Monoid,
          detail::function<Monoid(Monoid, Monoid)> BinOp,
          detail::function<Monoid()> Id>
class id10<Monoid, BinOp, Id, void>
    : public detail::id3<id10<Monoid, BinOp, Id, void>,
                              detail::lct_node<Monoid, false>> {
  friend class detail::id3<id10, detail::lct_node<Monoid, false>>;
  using splay_node = detail::lct_node<Monoid, false>;
  using base_type = detail::id3<id10, splay_node>;
public:
  id10() = default;
  id10(int n, BinOp binop, Id id)
      : base_type(n, splay_node{{}, {}, {}, id(), id()}),
        binop_(std::move(binop)),
        id_(std::move(id)) {}
  id10(int n, const Monoid &init, BinOp binop, Id id)
      : base_type(n, splay_node{{}, {}, {}, init, init}),
        binop_(std::move(binop)),
        id_(std::move(id)) {
    this->tree_[this->Null].self_ = id_();
    this->tree_[this->Null].path_ = id_();
  }
  Monoid
  query_path(int v, int u) {
    assert(0 < u && u <= this->size());
    assert(0 < v && v <= this->size());
    assert(this->connected(u, v));
    this->make_root(u);
    this->access(v);
    return this->tree_[v].path_;
  }
  void
  set(int u, Monoid new_val) {
    assert(0 < u && u <= this->size());
    this->access(u);
    this->tree_[u].self_ = std::move(new_val);
    this->update(u);
  }
  Monoid
  get(int u) const {
    assert(0 < u && u <= this->size());
    return this->tree_[u].self_;
  }
private:
  void
  reset(int, int) {}
  void
  update(int u) {
    const int l = this->tree_[u].children_[0];
    const int r = this->tree_[u].children_[1];
    this->tree_[u].path_ =
        binop_(this->tree_[u].self_,
               binop_(this->tree_[l].path_, this->tree_[r].path_));
  }
  BinOp binop_;
  Id id_;
};
template <>
class id10<void, void, void, void>
    : public detail::id3<id10<void, void, void, void>,
                              detail::lct_node<void, false>> {
  friend class detail::id3<id10, detail::lct_node<void, false>>;
  using splay_node = detail::lct_node<void, false>;
  using base_type = detail::id3<id10, splay_node>;
public:
  id10(int n) : base_type(n, splay_node{}) {}
private:
  void
  reset(int, int) {}
  void
  update(int) {}
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
namespace algo {
template <std::semiregular Monoid,
          detail::function<Monoid(Monoid, Monoid)> BinOp,
          detail::function<Monoid()> Id>
class id8 {
public:
  id8() = default;
  id8(int n, BinOp binop, Id id)
      : n_(n),
        lg2_(detail::id9(n)),
        size_(1 << lg2_),
        tree_(size_ << 1, id()),
        binop_(std::move(binop)),
        id_(std::move(id)) {}
  id8(int n, const Monoid& init, BinOp binop, Id id)
      : n_(n),
        lg2_(detail::id9(n)),
        size_(1 << lg2_),
        tree_(size_ << 1, init),
        binop_(std::move(binop)),
        id_(std::move(id)) {
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  template <detail::input_iterator<Monoid> IIter>
  id8(IIter first, IIter last, BinOp binop, Id id)
      : id8(std::distance(first, last), std::move(binop), std::move(id)) {
    std::copy(first, last, tree_.begin() + size_);
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  template <std::input_iterator IIter,
            detail::function<Monoid(std::iter_value_t<IIter>)> Gen>
  id8(IIter first, IIter last, BinOp binop, Id id, Gen gen)
      : id8(std::distance(first, last), std::move(binop), std::move(id)) {
    std::transform(first, last, tree_.begin() + size_, std::move(gen));
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  void
  set(int pos, Monoid new_val) {
    assert(0 <= pos && pos < size());
    pos += size_;
    tree_[pos] = std::move(new_val);
    for (int i = 1; i <= lg2_; ++i) { update(pos >> i); }
  }
  Monoid
  get(int pos) const {
    assert(0 <= pos && pos < size());
    return tree_[pos + size_];
  }
  void
  apply(int pos, Monoid z) {
    assert(0 <= pos && pos < size());
    pos += size_;
    tree_[pos] = binop_(std::move(tree_[pos]), std::move(z));
    for (int i = 1; i <= lg2_; ++i) { update(pos >> i); }
  }
  Monoid
  query(int l, int r) const {
    assert(0 <= l && l <= r && r <= size());
    Monoid resl = id_(), resr = id_();
    l += size_;
    r += size_;
    const int mask = (1 << detail::id2(--l ^ r)) - 1;
    for (int v = mask & ~l; v != 0; v = detail::blsr(v)) {
      resl = binop_(std::move(resl), tree_[(l >> detail::id11(v)) + 1]);
    }
    for (int v = mask & r; v != 0; v = detail::blsr(v)) {
      resr = binop_(tree_[(r >> detail::id11(v)) - 1], std::move(resr));
    }
    return binop_(std::move(resl), std::move(resr));
  }
  Monoid
  query() const {
    return tree_[1];
  }
  template <std::predicate<Monoid> Pred>
  int
  id6(int l, const Pred& pred) const {
    assert(0 <= l && l <= size());
    assert(pred(id_()));
    if (l < n_) [[likely]] {
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
        cur = binop_(std::move(cur), tree_[l++]);
      } while (detail::popcount(l) != 1);
    }
    return n_;
  }
  template <std::predicate<Monoid> Pred>
  int
  id0(int r, const Pred& pred) const {
    assert(0 <= r && r <= size());
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
        cur = binop_(tree_[r], std::move(cur));
      } while (detail::popcount(r--) != 1);
    }
    return 0;
  }
  int
  size() const {
    return n_;
  }
  std::vector<Monoid>
  data() const {
    return tree_;
  }
private:
  void
  update(int v) {
    tree_[v] = binop_(tree_[v << 1], tree_[v << 1 | 1]);
  }
  int n_, lg2_, size_;
  std::vector<Monoid> tree_;
  BinOp binop_;
  Id id_;
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
using std::swap;
using std::tie;
using std::to_string;
using std::tuple;
using std::vector;
using wint = int64_t;
using uint = uint32_t;
template <typename Key, typename Value, typename Hash = std::hash<Key>>
using umap = std::unordered_map<Key, Value, Hash>;
template <typename Value, typename Hash = std::hash<Value>>
using uset = std::unordered_set<Value, Hash>;
template <typename Tp, typename Comp = std::less<Tp>>
using max_heap = std::priority_queue<Tp, std::vector<Tp>, Comp>;
template <typename Tp, typename Comp = std::greater<Tp>>
using min_heap = std::priority_queue<Tp, std::vector<Tp>, Comp>;





namespace {
}
void solve() noexcept {
  int n;
  cin >> n;
  auto f = [](int x, int y) { return x + y; };
  auto ef = [] { return 0; };
  algo::id10<int, decltype(f), decltype(ef)> lct(n, 1, f, ef);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    lct.link(u, v);
  }
  vector<int> dist(n + 1);
  for (int i = 1; i <= n; ++i) {
    dist[i] = lct.query_path(1, i) - 1;
    lct.reroot(1);
  }
  debug("dist = {}\n", dist);
  auto calc = [&](int u, int v) {
    const int lca = lct.lca(u, v);
    return dist[u] + dist[v] - 2 * dist[lca];
  };
  int q;
  cin >> q;
  vector<int> buf(n);
  while (q--) {
    int k;
    cin >> k;
    int u = -1, mx = -1;
    for (int i = 0; i < k; ++i) {
      cin >> buf[i];
      if (dist[buf[i]] > mx) { mx = dist[buf[i]], u = buf[i]; }
    }
    int v = u, d = 0;
    for (int i = 0; i < k; ++i) {
      if (int tmp = calc(buf[i], u); d < tmp) { d = tmp, v = buf[i]; }
    }
    bool ok = true;
    for (int i = 0; i < k; ++i) {
      ok &= (calc(u, buf[i]) + calc(buf[i], v) == d);
    }
    cout << (ok ? "YES\n" : "NO\n");
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
