













































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
[[gnu::noreturn]] void
unreachable() {
  __builtin_unreachable();
}
[[gnu::always_inline]] constexpr void
assume(bool expr) {
  if (!expr) { unreachable(); }
}
}
namespace algo::detail {
template <typename Tp>
constexpr int
id3(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::countl_zero<Up>(n);
}
template <typename Tp>
constexpr int
id5(Tp n) {
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
id7(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return static_cast<Tp>(std::bit_floor<Up>(n));
}
template <typename Tp>
constexpr Tp
id4(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return static_cast<Tp>(std::bit_ceil<Up>(n));
}
template <typename Tp>
constexpr int
id0(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  constexpr int Nd = std::numeric_limits<Up>::digits;
  return Nd - 1 - std::countl_zero<Up>(n);
}
template <typename Tp>
constexpr int
id1(Tp n) {
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
id3(Tp n) {
  return detail::id3(n);
}
template <detail::integer Tp>
constexpr int
id5(Tp n) {
  return detail::id5(n);
}
template <detail::integer Tp>
constexpr int
bit_width(Tp n) {
  return detail::bit_width(n);
}
template <detail::integer Tp>
constexpr Tp
id7(Tp n) {
  return detail::id7(n);
}
template <detail::integer Tp>
constexpr Tp
id4(Tp n) {
  return detail::id4(n);
}
template <detail::integer Tp>
constexpr int
id0(Tp n) {
  return detail::id0(n);
}
template <detail::integer Tp>
constexpr int
id1(Tp n) {
  return detail::id1(n);
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


namespace algo {
template <std::semiregular Group, detail::function<Group(Group, Group)> BinOp,
          detail::function<Group(void)> Id, detail::function<Group(Group)> Inv>
class id2 {
private:
  struct splay_node {
    int children[2];
    int parent;
    bool flip;
    Group self;
    Group sub;
    Group vsub;
    Group path;
  };
  static constexpr int Null = 0;
  using node_type = splay_node;
public:
  id2() = default;
  id2(int n, BinOp binop, Id id, Inv inv)
      : tree_(n + 1, {{Null, Null}, Null, false, id(), id(), id(), id()}),
        binop_(std::move(binop)),
        id_(std::move(id)),
        inv_(std::move(inv)) {}
  id2(int n, const Group &init, BinOp binop, Id id, Inv inv)
      : tree_(n + 1, {{Null, Null}, Null, false, init, init, id(), init}),
        binop_(std::move(binop)),
        id_(std::move(id)),
        inv_(std::move(inv)) {
    tree_[Null].self = id_();
    tree_[Null].path = id_();
    tree_[Null].sub = id_();
  }
  void
  reroot(int u) {
    assert(0 <= u && u < num_nodes());
    do_reroot(u + 1);
  }
  void
  link(int v, int u) {
    assert(0 <= u && u < num_nodes());
    assert(0 <= v && v < num_nodes());
    do_link(v + 1, u + 1);
  }
  void
  cut(int v, int u) {
    assert(0 <= u && u < num_nodes());
    assert(0 <= v && v < num_nodes());
    do_cut(v + 1, u + 1);
  }
  int
  parent(int u) {
    assert(0 <= u && u < num_nodes());
    return get_parent(u + 1) - 1;
  }
  int
  root(int u) {
    assert(0 <= u && u < num_nodes());
    return get_root(u + 1) - 1;
  }
  bool
  connected(int v, int u) {
    assert(0 <= u && u < num_nodes());
    assert(0 <= v && v < num_nodes());
    return reachable(v + 1, u + 1);
  }
  int
  lca(int v, int u) {
    assert(0 <= u && u < num_nodes());
    assert(0 <= v && v < num_nodes());
    return get_lca(v + 1, u + 1) - 1;
  }
  Group
  query_subtree(int u) {
    assert(0 <= u && u < num_nodes());
    return get_subtree(u + 1);
  }
  Group
  query_path(int v, int u) {
    assert(0 <= u && u < num_nodes());
    assert(0 <= v && v < num_nodes());
    assert(connected(u, v));
    return get_path(v + 1, u + 1);
  }
  void
  set(int u, Group new_val) {
    assert(0 <= u && u < num_nodes());
    do_set(u + 1);
  }
  Group
  get(int u) const {
    assert(0 <= u && u < num_nodes());
    return do_get(u + 1);
  }
  int
  num_nodes() const {
    return static_cast<int>(tree_.size()) - 1;
  }
  int
  null() const {
    return -1;
  }
private:
  void
  do_reroot(int u) {
    access(u);
    tree_[u].flip ^= true;
    push(u);
  }
  void
  do_link(int v, int u) {
    do_reroot(u);
    access(v);
    toggle(v, u);
  }
  void
  do_cut(int v, int u) {
    do_reroot(v);
    access(u);
    if (tree_[u].children[0] == v) {
      tree_[u].children[0] = Null;
      tree_[v].parent = Null;
      update(u);
    }
  }
  int
  get_parent(int u) {
    access(u);
    return tree_[u].children[0];
  }
  int
  get_root(int u) {
    access(u);
    while (tree_[u].children[0] != Null) {
      u = tree_[u].children[0];
      push(u);
    }
    splay(u);
    return u;
  }
  bool
  reachable(int v, int u) {
    return get_lca(u, v) != Null;
  }
  int
  get_lca(int v, int u) {
    if (u == v) { return u; }
    access(v);
    int w = Null, z = u;
    do {
      splay(z);
      toggle(z, w);
      w = z, z = tree_[z].parent;
    } while (z != Null);
    splay(u);
    return tree_[v].parent != Null ? w : Null;
  }
  Group
  get_subtree(int u) {
    access(u);
    return binop_(tree_[u].self, tree_[u].vsub);
  }
  Group
  get_path(int v, int u) {
    do_reroot(u);
    access(v);
    return tree_[v].path;
  }
  void
  do_set(int u, Group new_val) {
    access(u);
    tree_[u].self = std::move(new_val);
    update(u);
  }
  Group
  do_get(int u) {
    return tree_[u].self;
  }
  int
  side(int u) const {
    const int p = tree_[u].parent;
    if (tree_[p].children[0] == u) { return 0; }
    if (tree_[p].children[1] == u) { return 1; }
    return -1;
  }
  void
  access(int u) {
    splay(u);
    toggle(u, 0);
    while (tree_[u].parent != Null) {
      const int w = tree_[u].parent;
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
  update(int u) {
    const int l = tree_[u].children[0];
    const int r = tree_[u].children[1];
    tree_[u].sub = binop_(binop_(tree_[u].self, tree_[u].vsub),
                          binop_(tree_[l].sub, tree_[r].sub));
    tree_[u].path = binop_(tree_[u].self, binop_(tree_[l].path, tree_[r].path));
  }
  void
  toggle(int v, int u) {
    const int c = tree_[v].children[1];
    tree_[v].vsub = binop_(std::move(tree_[v].vsub), tree_[c].sub);
    if (tree_[u].parent == v) {
      tree_[v].vsub = binop_(std::move(tree_[v].vsub), inv_(tree_[u].sub));
    }
    tree_[v].children[1] = u;
    tree_[u].parent = v;
    update(v);
  }
  void
  rotate(int u) {
    const int v = tree_[u].parent;
    const int w = tree_[v].parent;
    const int du = side(u);
    const int dv = side(v);
    attach(v, tree_[u].children[!du], du);
    attach(u, v, !du);
    if (dv != -1) { attach(w, u, dv); }
    tree_[u].parent = w;
  }
  void
  attach(int v, int u, bool d) {
    tree_[v].children[d] = u;
    tree_[u].parent = v;
    update(v);
  }
  void
  push(int u) {
    if (u != Null && tree_[u].flip) {
      const int l = tree_[u].children[0];
      const int r = tree_[u].children[1];
      tree_[l].flip ^= true;
      tree_[r].flip ^= true;
      std::swap(tree_[u].children[0], tree_[u].children[1]);
      tree_[u].flip = false;
    }
  }
  void
  splay(int u) {
    push(u);
    while (!is_root(u) && !is_root(tree_[u].parent)) {
      const int v = tree_[u].parent;
      const int w = tree_[v].parent;
      push(w);
      push(v);
      push(u);
      rotate(side(v) == side(u) ? v : u);
      rotate(u);
    }
    if (!is_root(u)) {
      push(tree_[u].parent);
      push(u);
      rotate(u);
    }
  }
  std::vector<splay_node> tree_;
  BinOp binop_;
  Id id_;
  Inv inv_;
};
template <typename Group, typename BinOp, typename Id, typename Inv>
id2(int, const Group &, BinOp, Id, Inv)
    -> id2<Group, BinOp, Id, Inv>;
}
namespace algo::detail {
template <typename Tp>
constexpr Tp
sqrt(Tp n) {
  if (n == 0) { return 0; }
  Tp res = 0;
  for (int i = id0(n) >> 1; i >= 0; --i) {
    const Tp tmp = res | Tp(1) << i;
    if (tmp * tmp <= n) { res = tmp; }
  }
  return res;
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
id6(Tp n) {
  if (n == 0) { return 0; }
  Tp res = 0;
  const Tp m = detail::abs(n);
  for (int i = detail::id0(m) / 3; i >= 0; --i) {
    const Tp low = (m - res * res * res) >> i;
    const Tp tmp = res | Tp(1) << i;
    if (3 * res * tmp + (Tp(1) << (i + i)) <= low) { res = tmp; }
  }
  return res;
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




namespace {
}
void solve() noexcept {
  int n;
  cin >> n;
  auto f = [](int x, int y) { return x + y; };
  auto e = [] { return 0; };
  auto inv = [](int x) { return -x; };
  algo::id2 lct(n, 1, f, e, inv);
  using edge = struct {
    int u, v;
  };
  vector<vector<edge>> qs(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    int x;
    cin >> x;
    lct.link(--u, --v);
    qs[--x].emplace_back(u, v);
  }
  wint ans = 0;
  for (int x = 0; x < n; ++x) {
    for (const auto &[u, v] : qs[x]) {
      lct.cut(u, v);
    }
    for (const auto &[u, v] : qs[x]) {
      lct.reroot(u);
      lct.reroot(v);
      wint vs = lct.query_subtree(v);
      wint us = lct.query_subtree(u);
      ans += vs * us;
    }
    for (const auto &[u, v] : qs[x]) {
      lct.link(u, v);
    }
  }
  cout << ans << '\n';
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();
  return 0;
}