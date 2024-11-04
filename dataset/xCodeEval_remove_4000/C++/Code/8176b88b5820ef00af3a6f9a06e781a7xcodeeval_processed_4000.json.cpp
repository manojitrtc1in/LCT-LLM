














































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
}
namespace algo::detail {
inline void unreachable [[gnu::noreturn]] () { __builtin_unreachable(); }
constexpr void assume [[gnu::always_inline]] (bool expr) {
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
constexpr int id8(Tp n) {
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
constexpr int id7(Tp n) {
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
constexpr int id8(Tp n) {
  return detail::id8(n);
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
constexpr Tp id2(Tp n) {
  return detail::id2(n);
}
template <detail::integer Tp>
constexpr int id3(Tp n) {
  return detail::id3(n);
}
template <detail::integer Tp>
constexpr int id7(Tp n) {
  return detail::id7(n);
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
  for (int i = id3(n) >> 1; i >= 0; --i) {
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
namespace algo::detail {
template <typename Derived, typename Node>
class id1 {
public:
  using node_pointer = Node *;
  using const_node_pointer = const Node *;
  using key_type = typename Node::key_type;
  using pool_resource_type = std::pmr::monotonic_buffer_resource;
  id1() noexcept = default;
  id1(id1 &&tree) noexcept
      : root_{std::exchange(tree.root_, null())} {}
  id1 &operator=(id1 &&rhs) noexcept {
    root_ = std::exchange(rhs.root_, null());
    return *this;
  }
  void reroot(node_pointer u) {
    splay(u);
    root_ = u;
  }
  node_pointer address(int i) {
    if (i == size()) { return null(); }
    const auto node = find_by_index(i);
    reroot(node);
    return node;
  }
  int index(node_pointer u) {
    if (u == null()) { return size(); }
    reroot(u);
    return size(u->children[0]);
  }
  key_type get(int i) { return get(find_by_index(i)); }
  key_type get(node_pointer u) {
    reroot(u);
    return u->self;
  }
  void set(int i, key_type new_key) {
    set(find_by_index(i), std::move(new_key));
  }
  void set(node_pointer u, key_type new_key) {
    reroot(u);
    u->self = std::move(new_key);
    update(u);
  }
  node_pointer insert(int i, key_type key) {
    return insert(i, allocate(std::move(key)));
  }
  node_pointer insert(node_pointer u, key_type key) {
    return insert(u, allocate(std::move(key)));
  }
  node_pointer insert(int i, node_pointer new_node) {
    if (i < size()) {
      const auto node = find_by_index(i);
      splay(node);
      insert_before(node, new_node);
      reroot(new_node);
      return new_node;
    }
    return push_back(new_node);
  }
  node_pointer insert(node_pointer u, node_pointer new_node) {
    if (u != null()) {
      splay(u);
      insert_before(u, new_node);
      reroot(new_node);
      return new_node;
    }
    return push_back(new_node);
  }
  void erase(int i) {
    erase(find_by_index(i));
  }
  void erase(node_pointer u) {
    splay(u);
    const auto l = detach_discard(u, 0);
    const auto r = detach_discard(u, 1);
    root_ = concat(l, r);
  }
  void erase(int l, int r) {
    if (l < r) {
      const auto node = access_range(l, r);
      const auto nxt = node->parent;
      if (nxt != null()) {
        detach(nxt, side(node));
        splay(nxt);
      }
      root_ = nxt;
    }
  }
  node_pointer extract(int i) {
    return extract(find_by_index(i));
  }
  node_pointer extract(node_pointer u) {
    splay(u);
    const auto l = detach(u, 0);
    const auto r = detach(u, 1);
    root_ = concat(l, r);
    return u;
  }
  node_pointer push_back(key_type key) {
    return push_back(allocate(std::move(key)));
  }
  node_pointer push_back(node_pointer new_node) {
    if (!empty()) [[likely]] {
      const auto node = root_;
      const auto nxt = right_most(node);
      attach(nxt, new_node, 1);
      splay(new_node);
    }
    root_ = new_node;
    return new_node;
  }
  node_pointer push_front(key_type key) {
    return push_front(allocate(std::move(key)));
  }
  node_pointer push_front(node_pointer new_node) {
    if (!empty()) [[likely]] {
      const auto node = root_;
      const auto nxt = left_most(node);
      attach(nxt, new_node, 0);
      splay(new_node);
    }
    root_ = new_node;
    return new_node;
  }
  void pop_back() {
    const auto node = root_;
    const auto last = right_most(node);
    splay(last);
    const auto nxt = detach_discard(last, 0);
    root_ = nxt;
  }
  void pop_front() {
    const auto node = root_;
    const auto first = left_most(node);
    splay(first);
    const auto nxt = detach_discard(first, 1);
    root_ = nxt;
  }
  template <
      std::strict_weak_order<key_type, key_type> Compare = std::less<key_type>>
  node_pointer lower_bound(const key_type &key, const Compare &comp = {}) {
    node_pointer res = null();
    node_pointer prev = root_;
    node_pointer cur = root_;
    while (cur != null()) {
      push(cur);
      prev = cur;
      if (!comp(cur->self, key)) {
        res = cur;
        cur = cur->children[0];
      } else {
        cur = cur->children[1];
      }
    }
    if (prev != null()) { reroot(prev); }
    return res;
  }
  template <
      std::strict_weak_order<key_type, key_type> Compare = std::less<key_type>>
  node_pointer upper_bound(const key_type &key, const Compare &comp = {}) {
    node_pointer res = null();
    node_pointer prev = root_;
    node_pointer cur = root_;
    while (cur != null()) {
      push(cur);
      prev = cur;
      if (comp(key, cur->self)) {
        res = cur;
        cur = cur->children[0];
      } else {
        cur = cur->children[1];
      }
    }
    if (prev != null()) { reroot(prev); }
    return res;
  }
  void clear() { root_ = null(); }
  int size() const { return size(root_); }
  bool empty() const { return size() == 0; }
  node_pointer null() const { return nullptr; }
protected:
  node_pointer access_range(int l, int r) const {
    const auto left = l != 0 ? find_by_index(l - 1) : null();
    const auto right = r != size() ? find_by_index(r) : null();
    if (left != null() && right != null()) {
      splay(left);
      splay(right);
      if (left->parent != right) { rotate(left); }
      return left->children[1];
    } else if (left != null()) {
      splay(left);
      return left->children[1];
    } else if (right != null()) {
      splay(right);
      return right->children[0];
    }
    return root_;
  }
  node_pointer find_by_index(int i) const {
    auto cur = root_;
    while (true) {
      push(cur);
      const int left = size(cur->children[0]);
      if (i == left) {
        return cur;
      } else if (i < left) {
        cur = cur->children[0];
      } else {
        i -= left + 1;
        cur = cur->children[1];
      }
    }
    unreachable();
  }
  node_pointer concat(node_pointer l, node_pointer r) const {
    if (l != null()) {
      const auto nxt = right_most(l);
      attach(nxt, r, 1);
      splay(nxt);
      return nxt;
    }
    return r;
  }
  node_pointer left_most(node_pointer u) const {
    push(u);
    while (u->children[0] != null()) {
      u = u->children[0];
      push(u);
    }
    return u;
  }
  node_pointer right_most(node_pointer u) const {
    push(u);
    while (u->children[1] != null()) {
      u = u->children[1];
      push(u);
    }
    return u;
  }
  void insert_before(node_pointer v, node_pointer u) const {
    if (v->children[0] == null()) {
      attach(v, u, 0);
    } else {
      const auto nxt = right_most(v->children[0]);
      attach(nxt, u, 1);
    }
  }
  void insert_after(node_pointer v, node_pointer u) const {
    if (v->children[1] == null()) {
      attach(v, u, 1);
    } else {
      const auto nxt = left_most(v->children[1]);
      attach(nxt, u, 0);
    }
  }
  int side(const_node_pointer u) const {
    const auto p = u->parent;
    return !is_root(u) ? p->children[1] == u : -1;
  }
  bool is_root(const_node_pointer u) const { return u->parent == null(); }
  void push(node_pointer u) const { self()->push_down(u); }
  void update(node_pointer u) const { self()->push_up(u); }
  void attach(node_pointer v, node_pointer u, bool d) const {
    v->children[d] = u;
    if (u != null()) { u->parent = v; }
    update(v);
  }
  node_pointer detach(node_pointer v, bool d) const {
    const auto u = v->children[d];
    v->children[d] = null();
    if (u != null()) { u->parent = null(); }
    update(v);
    return u;
  }
  node_pointer detach_discard(node_pointer v, bool d) const {
    const auto u = v->children[d];
    if (u != null()) { u->parent = null(); }
    return u;
  }
  void rotate(node_pointer u) const {
    const auto v = u->parent;
    const auto w = v->parent;
    const int du = side(u);
    const int dv = side(v);
    const auto b = u->children[!du];
    attach(v, b, du);
    attach(u, v, !du);
    if (w != null()) { attach(w, u, dv); }
    u->parent = w;
  }
  [[gnu::hot]] void splay(node_pointer u) const {
    push(u);
    while (!is_root(u) && !is_root(u->parent)) {
      const auto v = u->parent;
      const auto w = v->parent;
      push(w);
      push(v);
      push(u);
      rotate(side(u) == side(v) ? v : u);
      rotate(u);
    }
    if (!is_root(u)) {
      push(u->parent);
      push(u);
      rotate(u);
    }
  }
  int size(const_node_pointer node) const {
    return node != null() ? node->size : 0;
  }
  node_pointer allocate(key_type key) const noexcept {
    void *mem = pool_.allocate(sizeof(Node), alignof(Node));
    return ::new (mem) Node{self()->make(std::move(key))};
  }
  auto self() const { return static_cast<const Derived *>(this); }
  auto self() { return static_cast<Derived *>(this); }
  void push_down(node_pointer) const {}
  void push_up(node_pointer) const {}
  node_pointer root_{nullptr};
  static inline pool_resource_type pool_;
};
}
namespace algo::lazy_splay {
namespace impl {
template <typename Tp, typename Mact>
struct point_query_node {
  using key_type = Tp;
  point_query_node *children[2]{0};
  point_query_node *parent{0};
  Tp self{};
  Mact lazy{};
  int size{1};
};
}
template <std::semiregular Tp, std::semiregular Mact,
          detail::function<Tp(Tp, Mact)> Map,
          detail::function<Mact(Mact, Mact)> Comp,
          detail::function<Mact(void)> CompId>
class id0
    : public detail::id1<
          id0<Tp, Mact, Map, Comp, CompId>,
          impl::point_query_node<Tp, Mact>> {
public:
  using self_type = id0;
  using node_type = impl::point_query_node<Tp, Mact>;
  using base_type = detail::id1<self_type, node_type>;
  using typename base_type::const_node_pointer;
  using typename base_type::node_pointer;
  friend class detail::id1<self_type, node_type>;
  id0() noexcept = default;
  id0(int n, Map map, Comp comp, CompId comp_id) noexcept
      : base_type{},
        map_(std::move(map)),
        comp_(std::move(comp)),
        comp_id_(std::move(comp_id)) {
    this->root_ = build_tree(n, Tp{});
  }
  id0(int n, const Tp &def, Map map, Comp comp,
                      CompId comp_id) noexcept
      : base_type{},
        map_(std::move(map)),
        comp_(std::move(comp)),
        comp_id_(std::move(comp_id)) {
    this->root_ = build_tree(n, def);
  }
  template <detail::input_iterator<Tp> IIter>
  id0(IIter first, IIter last, Map map, Comp comp,
                      CompId comp_id) noexcept
      : base_type{},
        map_(std::move(map)),
        comp_(std::move(comp)),
        comp_id_(std::move(comp_id)) {
    const int n = static_cast<int>(std::distance(first, last));
    this->root_ = build_tree(first, n);
  }
  void apply(int i, const Mact &arg) { apply(i, i + 1, arg); }
  void apply(int l, int r, const Mact &arg) {
    if (l < r) {
      const auto node = this->access_range(l, r);
      apply_subtree(node, arg);
      this->reroot(node);
    }
  }
protected:
  node_pointer build_tree(int n, const Tp &def) const noexcept {
    if (n == 0) {
      return this->null();
    } else {
      const auto node = this->allocate(def);
      this->attach(node, build_tree(n >> 1, def), 0);
      this->attach(node, build_tree((n - 1) >> 1, def), 1);
      return node;
    }
  }
  template <typename IIter>
  node_pointer build_tree(IIter base, int n) const noexcept {
    if (n == 0) {
      return this->null();
    } else {
      const auto mid = base + (n >> 1);
      const auto node = this->allocate(*mid);
      this->attach(node, build_tree(base, n >> 1), 0);
      this->attach(node, build_tree(mid + 1, (n - 1) >> 1), 1);
      return node;
    }
  }
  void push_up(node_pointer u) const {
    const auto [l, r] = u->children;
    const int size_l = this->size(l);
    const int size_r = this->size(r);
    u->size = size_l + size_r + 1;
  }
  void push_down(node_pointer u) const {
    const auto [l, r] = u->children;
    if (l != this->null()) { apply_subtree(l, u->lazy); }
    if (r != this->null()) { apply_subtree(r, u->lazy); }
    u->lazy = comp_id_();
  }
  void apply_subtree(node_pointer u, const Mact &arg) const {
    u->self = map_(u->self, arg);
    u->lazy = comp_(u->lazy, arg);
  }
  node_type make(Tp key) const {
    return {.self = std::move(key), .lazy = comp_id_()};
  }
  [[no_unique_address]] Map map_;
  [[no_unique_address]] Comp comp_;
  [[no_unique_address]] CompId comp_id_;
};
}
namespace algo::lazy_splay {
template <std::semiregular Tp, std::semiregular Mact,
          detail::function<Tp(Tp, Mact)> Map,
          detail::function<Mact(Mact, Mact)> Comp,
          detail::function<Mact(void)> CompId>
auto id6(int n, Map map, Comp comp, CompId comp_id)
    -> id0<Tp, Mact, Map, Comp, CompId> {
  return {n, std::move(map), std::move(comp), std::move(comp_id)};
}
template <std::semiregular Tp, std::semiregular Mact,
          detail::function<Tp(Tp, Mact)> Map,
          detail::function<Mact(Mact, Mact)> Comp,
          detail::function<Mact(void)> CompId>
auto id6(int n, const Tp &def, Map map, Comp comp,
                              CompId comp_id)
    -> id0<Tp, Mact, Map, Comp, CompId> {
  return {n, def, std::move(map), std::move(comp), std::move(comp_id)};
}
template <std::semiregular Tp, std::semiregular Mact,
          detail::function<Tp(Tp, Mact)> Map,
          detail::function<Mact(Mact, Mact)> Comp,
          detail::function<Mact(void)> CompId, detail::input_iterator<Tp> IIter>
auto id6(IIter first, IIter last, Map map, Comp comp,
                              CompId comp_id)
    -> id0<Tp, Mact, Map, Comp, CompId> {
  return {first, last, std::move(map), std::move(comp), std::move(comp_id)};
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
  int n;
  cin >> n;
  auto mp = [](int x, int t) { return t == -1 ? x : t; };
  auto gx = [](int x, int y) { return y == -1 ? x : y; };
  auto eg = [] { return -1; };
  vector<int> an(n);
  for (int i = 0; i < n; ++i) { cin >> an[i]; }
  vector ind(n, 0);
  iota(ind.begin(), ind.end(), 0);
  sort(ind.begin(), ind.end(), [&](int a, int b) { return an[a] < an[b]; });
  sort(an.begin(), an.end());
  auto tree = algo::lazy_splay::id6<int, int>(
      an.begin(), an.end(), mp, gx, eg);
  using ptr = decltype(tree)::node_pointer;
  vector<ptr> idm(n);
  for (int i = 0; i < n; ++i) { idm[ind[i]] = tree.address(i); }
  int q;
  cin >> q;
  while (q--) {
    if (int t; cin >> t, t == 1) {
      int k, w;
      cin >> k >> w, --k;
      auto nd = tree.extract(idm[k]);
      auto nx = tree.lower_bound(w);
      nd->self = w;
      idm[k] = tree.insert(nx, nd);
    } else if (t == 2) {
      int k;
      cin >> k, --k;
      cout << tree.get(idm[k]) << '\n';
    } else {
      int l, r;
      cin >> l >> r;
      auto l1 = tree.lower_bound(l);
      auto m1 = tree.lower_bound((l + r + 1) >> 1);
      auto r1 = tree.lower_bound(r + 1);
      tree.apply(tree.index(l1), tree.index(m1), l - 1);
      tree.apply(tree.index(m1), tree.index(r1), r + 1);
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
