














































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
constexpr int id3(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::countl_zero<Up>(n);
}
template <typename Tp>
constexpr int id9(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::countr_zero<Up>(n);
}
template <typename Tp>
constexpr int bit_width(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::bit_width<Up>(n);
}
template <typename Tp>
constexpr Tp id4(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return static_cast<Tp>(std::bit_floor<Up>(n));
}
template <typename Tp>
constexpr Tp id1(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return static_cast<Tp>(std::bit_ceil<Up>(n));
}
template <typename Tp>
constexpr int id2(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  constexpr int Nd = std::numeric_limits<Up>::digits;
  return Nd - 1 - std::countl_zero<Up>(n);
}
template <typename Tp>
constexpr int id6(Tp n) {
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
constexpr int id3(Tp n) {
  return detail::id3(n);
}
template <detail::integer Tp>
constexpr int id9(Tp n) {
  return detail::id9(n);
}
template <detail::integer Tp>
constexpr int bit_width(Tp n) {
  return detail::bit_width(n);
}
template <detail::integer Tp>
constexpr Tp id4(Tp n) {
  return detail::id4(n);
}
template <detail::integer Tp>
constexpr Tp id1(Tp n) {
  return detail::id1(n);
}
template <detail::integer Tp>
constexpr int id2(Tp n) {
  return detail::id2(n);
}
template <detail::integer Tp>
constexpr int id6(Tp n) {
  return detail::id6(n);
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
class dsu {
public:
  dsu() = default;
  explicit dsu(int n) noexcept : parent_(n, -1) {}
  bool merge(int a, int b) {
    int sa = find(a), sb = find(b);
    if (sa != sb) {
      if (-parent_[sa] < -parent_[sb]) { std::swap(sa, sb); }
      parent_[sa] += parent_[sb];
      parent_[sb] = sa;
      return true;
    }
    return false;
  }
  int find(int a) {
    if (parent_[a] >= 0) {
      parent_[a] = find(parent_[a]);
      return parent_[a];
    }
    return a;
  }
  int size(int a) { return -parent_[find(a)]; }
  bool same(int a, int b) { return find(a) == find(b); }
  int num_nodes() const { return static_cast<int>(parent_.size()); }
private:
  std::vector<int> parent_;
};
}
namespace algo {
template <typename = void>
struct edge;
template <std::semiregular Weight>
struct edge<Weight> {
  int u;
  int v;
  Weight w;
  using arc_type = std::pair<int, Weight>;
};
template <>
struct edge<void> {
  int u;
  int v;
  using arc_type = int;
};
struct directed_tag {};
struct undirected_tag {};
inline constexpr directed_tag directed{};
inline constexpr undirected_tag undirected{};
template <typename = void>
class id7;
template <std::semiregular Weight>
class id7<Weight> {
public:
  using edge_type = edge<Weight>;
  using arc_type = typename edge_type::arc_type;
  id7() = default;
  id7(directed_tag, int n,
                 const std::vector<edge_type>& edges) noexcept
      : start_(n + 1), elist_(edges.size()) {
    for (const auto& e : edges) { start_[e.u]++; }
    for (int i = 1; i <= n; ++i) { start_[i] += start_[i - 1]; }
    for (auto it = edges.rbegin(); it != edges.rend(); ++it) {
      elist_[--start_[it->u]] = {it->v, it->w};
    }
  }
  id7(undirected_tag, int n,
                 const std::vector<edge_type>& edges) noexcept
      : start_(n + 1), elist_(edges.size() << 1) {
    for (const auto& e : edges) {
      start_[e.u]++;
      start_[e.v]++;
    }
    for (int i = 1; i <= n; ++i) { start_[i] += start_[i - 1]; }
    for (auto it = edges.rbegin(); it != edges.rend(); ++it) {
      elist_[--start_[it->u]] = {it->v, it->w};
      elist_[--start_[it->v]] = {it->u, it->w};
    }
  }
  std::span<const arc_type> operator[](int u) const {
    return {elist_.cbegin() + start_[u], elist_.cbegin() + start_[u + 1]};
  }
  std::span<arc_type> operator[](int u) {
    return {elist_.begin() + start_[u], elist_.begin() + start_[u + 1]};
  }
  auto neighbors(int u) const { return std::views::keys(operator[](u)); }
  int degree(int u) const { return start_[u + 1] - start_[u]; }
  int num_nodes() const { return static_cast<int>(start_.size()) - 1; }
  int num_arcs() const { return static_cast<int>(elist_.size()); }
private:
  std::vector<int> start_;
  std::vector<arc_type> elist_;
};
template <>
class id7<void> {
public:
  using edge_type = edge<>;
  using arc_type = edge_type::arc_type;
  id7() = default;
  id7(directed_tag, int n,
                 const std::vector<edge_type>& edges) noexcept
      : start_(n + 1), elist_(edges.size()) {
    for (const auto& e : edges) { start_[e.u]++; }
    for (int i = 1; i <= n; ++i) { start_[i] += start_[i - 1]; }
    for (auto it = edges.rbegin(); it != edges.rend(); ++it) {
      elist_[--start_[it->u]] = {it->v};
    }
  }
  id7(undirected_tag, int n,
                 const std::vector<edge_type>& edges) noexcept
      : start_(n + 1), elist_(edges.size() << 1) {
    for (const auto& e : edges) {
      start_[e.u]++;
      start_[e.v]++;
    }
    for (int i = 1; i <= n; ++i) { start_[i] += start_[i - 1]; }
    for (auto it = edges.rbegin(); it != edges.rend(); ++it) {
      elist_[--start_[it->u]] = {it->v};
      elist_[--start_[it->v]] = {it->u};
    }
  }
  std::span<const arc_type> operator[](int u) const {
    return {elist_.cbegin() + start_[u], elist_.cbegin() + start_[u + 1]};
  }
  std::span<arc_type> operator[](int u) {
    return {elist_.begin() + start_[u], elist_.begin() + start_[u + 1]};
  }
  auto neighbors(int u) const { return operator[](u); }
  int degree(int u) const { return start_[u + 1] - start_[u]; }
  int num_nodes() const { return static_cast<int>(start_.size()) - 1; }
  int num_arcs() const { return static_cast<int>(elist_.size()); }
private:
  std::vector<int> start_;
  std::vector<arc_type> elist_;
};
template <typename Weight>
edge(int, int, Weight) -> edge<Weight>;
edge(int, int)->edge<void>;
template <typename Weight>
id7(directed_tag, int, const std::vector<edge<Weight>>&)
    -> id7<Weight>;
template <typename Weight>
id7(undirected_tag, int, const std::vector<edge<Weight>>&)
    -> id7<Weight>;
template <typename Weight>
std::vector<int> id0(const id7<Weight>& adj) {
  std::vector<bool> vis(adj.num_nodes());
  std::vector<int> order;
  order.reserve(adj.num_nodes());
  const auto dfs = [&](auto dfs, int u) -> void {
    vis[u] = true;
    for (const int v : adj.neighbors(u)) {
      if (!vis[v]) { dfs(dfs, v); }
    }
    order.emplace_back(u);
  };
  for (int u = 0; u < adj.num_nodes(); ++u) {
    if (!vis[u]) { dfs(dfs, u); }
  }
  std::reverse(order.begin(), order.end());
  return order;
}
template <typename Weight>
auto preorder(const id7<Weight>& adj, int root = 0)
    -> std::vector<std::array<int, 2>> {
  std::vector<std::array<int, 2>> res(adj.num_nodes());
  int timer = 0;
  const auto dfs = [&](auto dfs, int u, int p) -> void {
    res[u][0] = timer++;
    for (const int v : adj.neighbors(u)) {
      if (v == p) { continue; }
      dfs(dfs, v, u);
    }
    res[u][1] = timer;
  };
  dfs(dfs, root, root);
  return res;
}
}
namespace algo {
template <std::semiregular Group, detail::function<Group(Group, Group)> BinOp,
          detail::function<Group(void)> Id, detail::function<Group(Group)> Inv,
          detail::function<Group(Group, int)> Pow>
class id5 {
  struct splay_node {
    int children[2];
    int parent;
    bool flip;
    int size;
    Group self;
    Group sub;
    Group path;
    Group diff;
    int vsize;
    Group vsub;
  };
  using node_type = splay_node;
public:
  id5() = default;
  id5(int n, BinOp binop, Id id, Inv inv, Pow pow) noexcept
      : tree_(n + 1, {Null, Null, Null, 0, 1, id(), id(), id(), id(), 0, id()}),
        binop_(std::move(binop)),
        id_(std::move(id)),
        inv_(std::move(inv)),
        pow_(std::move(pow)) {
    tree_[Null].size = 0;
  }
  id5(int n, const Group& def, BinOp binop, Id id, Inv inv,
                     Pow pow) noexcept
      : tree_(n + 1, {Null, Null, Null, 0, 1, def, def, def, id(), 0, id()}),
        binop_(std::move(binop)),
        id_(std::move(id)),
        inv_(std::move(inv)),
        pow_(std::move(pow)) {
    tree_[Null].size = 0;
    tree_[Null].self = id_();
    tree_[Null].sub = id_();
    tree_[Null].path = id_();
  }
  void reroot(int u) { do_reroot(u + 1); }
  void link(int v, int u) { do_link(v + 1, u + 1); }
  void cut(int v, int u) { do_cut(v + 1, u + 1); }
  int parent(int u) { return get_parent(u + 1) - 1; }
  int root(int u) { return get_root(u + 1) - 1; }
  int lca(int v, int u) { return get_lca(v + 1, u + 1) - 1; }
  bool connected(int v, int u) { return reachable(v + 1, u + 1); }
  Group query_subtree(int u) { return get_subtree(u + 1); }
  Group query_path(int v, int u) { return get_path(v + 1, u + 1); }
  void apply_subtree(int u, Group z) { act_subtree(u + 1, std::move(z)); }
  void set(int u, Group new_val) { do_set(u + 1, std::move(new_val)); }
  Group get(int u) { return do_get(u + 1); }
  int num_nodes() const { return static_cast<int>(tree_.size()) - 1; }
  int null() const { return Null - 1; }
private:
  void do_reroot(int u) {
    access(u);
    tree_[u].flip ^= true;
    push(u);
  }
  void do_link(int v, int u) {
    do_reroot(u);
    access(v);
    tree_[v].children[1] = u;
    tree_[u].parent = v;
    tree_[u].diff = binop_(tree_[u].diff, inv_(tree_[v].diff));
    update(v);
  }
  void do_cut(int v, int u) {
    do_reroot(v);
    access(u);
    if (tree_[u].children[0] == v) {
      tree_[u].children[0] = Null;
      tree_[v].parent = Null;
      tree_[v].diff = binop_(tree_[v].diff, tree_[u].diff);
      update(u);
    }
  }
  int get_parent(int u) {
    access(u);
    return tree_[u].children[0];
  }
  int get_root(int u) {
    access(u);
    while (tree_[u].children[0] != Null) {
      u = tree_[u].children[0];
      push(u);
    }
    splay(u);
    return u;
  }
  int get_lca(int v, int u) {
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
  bool reachable(int v, int u) { return get_lca(u, v) != Null; }
  Group get_subtree(int u) {
    access(u);
    Group fac = pow_(tree_[u].diff, tree_[u].vsize + 1);
    return binop_(binop_(tree_[u].vsub, tree_[u].self), std::move(fac));
  }
  Group get_path(int v, int u) {
    do_reroot(u);
    access(v);
    Group fac = pow_(tree_[v].diff, tree_[v].size - tree_[v].vsize);
    return binop_(tree_[v].path, std::move(fac));
  }
  void act_subtree(int u, Group z) {
    access(u);
    tree_[u].diff = binop_(tree_[u].diff, z);
    const int l = tree_[u].children[0];
    if (l != Null) {
      tree_[l].diff = binop_(tree_[l].diff, inv_(std::move(z)));
      update(u);
    }
  }
  void do_set(int u, Group new_val) {
    access(u);
    tree_[u].self = std::move(new_val);
    update(u);
  }
  Group do_get(int u) {
    access(u);
    return binop_(tree_[u].self, tree_[u].diff);
  }
  void access(int u) {
    splay(u);
    toggle(u, Null);
    while (tree_[u].parent != Null) {
      const int w = tree_[u].parent;
      splay(w);
      toggle(w, u);
      rotate(u);
    }
  }
  int side(int u) const {
    const int p = tree_[u].parent;
    if (tree_[p].children[0] == u) { return 0; }
    if (tree_[p].children[1] == u) { return 1; }
    return -1;
  }
  bool is_root(int u) const { return side(u) < 0; }
  void update(int u) {
    const int l = tree_[u].children[0];
    const int r = tree_[u].children[1];
    Group sub_l = binop_(tree_[l].sub, pow_(tree_[l].diff, tree_[l].size));
    Group sub_r = binop_(tree_[r].sub, pow_(tree_[r].diff, tree_[r].size));
    Group path_l = binop_(tree_[l].path,
                          pow_(tree_[l].diff, tree_[l].size - tree_[l].vsize));
    Group path_r = binop_(tree_[r].path,
                          pow_(tree_[r].diff, tree_[r].size - tree_[r].vsize));
    tree_[u].sub = binop_(binop_(tree_[u].self, tree_[u].vsub),
                          binop_(std::move(sub_l), std::move(sub_r)));
    tree_[u].path =
        binop_(tree_[u].self, binop_(std::move(path_l), std::move(path_r)));
    tree_[u].size = tree_[l].size + tree_[r].size + tree_[u].vsize + 1;
  }
  void toggle(int v, int u) {
    const int c = tree_[v].children[1];
    Group sub_c = binop_(tree_[c].sub, pow_(tree_[c].diff, tree_[c].size));
    Group sub_u = binop_(tree_[u].sub, pow_(tree_[u].diff, tree_[u].size));
    tree_[v].vsub = binop_(tree_[v].vsub, std::move(sub_c));
    tree_[v].vsize += tree_[c].size;
    tree_[v].vsub = binop_(tree_[v].vsub, inv_(std::move(sub_u)));
    tree_[v].vsize -= tree_[u].size;
    tree_[v].children[1] = u;
    tree_[u].parent = v;
    update(v);
  }
  void rotate(int u) {
    const int v = tree_[u].parent;
    const int w = tree_[v].parent;
    const int du = side(u);
    const int dv = side(v);
    tree_[u].diff = binop_(tree_[u].diff, tree_[v].diff);
    tree_[v].diff = binop_(tree_[v].diff, inv_(tree_[u].diff));
    const int b = tree_[u].children[!du];
    if (b != Null) {
      tree_[b].diff = binop_(tree_[b].diff, inv_(tree_[v].diff));
    }
    attach(v, b, du);
    attach(u, v, !du);
    if (dv != -1) { attach(w, u, dv); }
    tree_[u].parent = w;
  }
  void attach(int v, int u, bool d) {
    tree_[v].children[d] = u;
    tree_[u].parent = v;
    update(v);
  }
  void push(int u) {
    if (u != Null && tree_[u].flip) {
      const int l = tree_[u].children[0];
      const int r = tree_[u].children[1];
      tree_[l].flip ^= true;
      tree_[r].flip ^= true;
      std::swap(tree_[u].children[0], tree_[u].children[1]);
      tree_[u].flip = false;
    }
  }
  void splay(int u) {
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
  static constexpr int Null = 0;
  std::vector<node_type> tree_;
  BinOp binop_;
  Id id_;
  Inv inv_;
  Pow pow_;
};
}
namespace algo {
template <std::semiregular Group, detail::function<Group(Group, Group)> BinOp,
          detail::function<Group(void)> Id, detail::function<Group(Group)> Inv,
          detail::function<Group(Group, int)> Pow>
auto id8(int n, BinOp binop, Id id, Inv inv, Pow pow)
    -> id5<Group, BinOp, Id, Inv, Pow> {
  return {n, std::move(binop), std::move(id), std::move(inv), std::move(pow)};
}
template <std::semiregular Group, detail::function<Group(Group, Group)> BinOp,
          detail::function<Group(void)> Id, detail::function<Group(Group)> Inv,
          detail::function<Group(Group, int)> Pow>
auto id8(int n, const Group& def, BinOp binop, Id id,
                             Inv inv, Pow pow)
    -> id5<Group, BinOp, Id, Inv, Pow> {
  return {
      n, def, std::move(binop), std::move(id), std::move(inv), std::move(pow)};
}
}
namespace algo::detail {
template <typename Tp>
constexpr Tp sqrt(Tp n) {
  if (n == 0) { return 0; }
  Tp ans = 0;
  for (int i = id2(n) >> 1; i >= 0; --i) {
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
  int n, m;
  cin >> n >> m;
  vector<algo::edge<>> bad;
  auto lct = algo::id8<int>(
      n, [](int x, int y) { return x + y; }, [] { return 0; },
      [](int x) { return -x; }, [](int x, int n) { return x * n; });
  algo::dsu uf(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v, --u, --v;
    if (!uf.merge(u, v)) {
      bad.emplace_back(u, v);
    } else {
      lct.link(u, v);
    }
  }
  for (auto [u, v] : bad) {
    lct.reroot(u);
    lct.apply_subtree(v, 1);
    lct.reroot(v);
    lct.apply_subtree(u, 1);
  }
  int k = bad.size();
  for (int i = 0; i < n; ++i) {
    if (lct.get(i) == k) {
      cout << '1';
    } else {
      cout << '0';
    }
  }
  cout << '\n';
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
