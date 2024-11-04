














































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
constexpr int id7(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::countl_zero<Up>(n);
}
template <typename Tp>
constexpr int id12(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::countr_zero<Up>(n);
}
template <typename Tp>
constexpr int bit_width(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::bit_width<Up>(n);
}
template <typename Tp>
constexpr Tp id9(Tp n) {
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
constexpr int id7(Tp n) {
  return detail::id7(n);
}
template <detail::integer Tp>
constexpr int id12(Tp n) {
  return detail::id12(n);
}
template <detail::integer Tp>
constexpr int bit_width(Tp n) {
  return detail::bit_width(n);
}
template <detail::integer Tp>
constexpr Tp id9(Tp n) {
  return detail::id9(n);
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
class id11;
template <std::semiregular Weight>
class id11<Weight> {
public:
  using edge_type = edge<Weight>;
  using arc_type = typename edge_type::arc_type;
  id11() = default;
  id11(directed_tag, int n,
                 const std::vector<edge_type>& edges) noexcept
      : start_(n + 1), elist_(edges.size()) {
    for (const auto& e : edges) { start_[e.u]++; }
    for (int i = 1; i <= n; ++i) { start_[i] += start_[i - 1]; }
    for (auto it = edges.rbegin(); it != edges.rend(); ++it) {
      elist_[--start_[it->u]] = { it->v, it->w };
    }
  }
  id11(undirected_tag, int n,
                 const std::vector<edge_type>& edges) noexcept
      : start_(n + 1), elist_(edges.size() << 1) {
    for (const auto& e : edges) {
      start_[e.u]++;
      start_[e.v]++;
    }
    for (int i = 1; i <= n; ++i) { start_[i] += start_[i - 1]; }
    for (auto it = edges.rbegin(); it != edges.rend(); ++it) {
      elist_[--start_[it->u]] = { it->v, it->w };
      elist_[--start_[it->v]] = { it->u, it->w };
    }
  }
  std::span<const arc_type> operator[](int u) const {
    return { elist_.cbegin() + start_[u], elist_.cbegin() + start_[u + 1] };
  }
  std::span<arc_type> operator[](int u) {
    return { elist_.begin() + start_[u], elist_.begin() + start_[u + 1] };
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
class id11<void> {
public:
  using edge_type = edge<>;
  using arc_type = edge_type::arc_type;
  id11() = default;
  id11(directed_tag, int n,
                 const std::vector<edge_type>& edges) noexcept
      : start_(n + 1), elist_(edges.size()) {
    for (const auto& e : edges) { start_[e.u]++; }
    for (int i = 1; i <= n; ++i) { start_[i] += start_[i - 1]; }
    for (auto it = edges.rbegin(); it != edges.rend(); ++it) {
      elist_[--start_[it->u]] = { it->v };
    }
  }
  id11(undirected_tag, int n,
                 const std::vector<edge_type>& edges) noexcept
      : start_(n + 1), elist_(edges.size() << 1) {
    for (const auto& e : edges) {
      start_[e.u]++;
      start_[e.v]++;
    }
    for (int i = 1; i <= n; ++i) { start_[i] += start_[i - 1]; }
    for (auto it = edges.rbegin(); it != edges.rend(); ++it) {
      elist_[--start_[it->u]] = { it->v };
      elist_[--start_[it->v]] = { it->u };
    }
  }
  std::span<const arc_type> operator[](int u) const {
    return { elist_.cbegin() + start_[u], elist_.cbegin() + start_[u + 1] };
  }
  std::span<arc_type> operator[](int u) {
    return { elist_.begin() + start_[u], elist_.begin() + start_[u + 1] };
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
id11(directed_tag, int, const std::vector<edge<Weight>>&)
    -> id11<Weight>;
template <typename Weight>
id11(undirected_tag, int, const std::vector<edge<Weight>>&)
    -> id11<Weight>;
template <typename Weight>
std::vector<int> id0(const id11<Weight>& adj) {
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
auto preorder(const id11<Weight>& adj, int root = 0)
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
class id2 {
  struct hld_node {
    int parent;
    int depth;
    int head;
    int time;
  };
  using node_type = hld_node;
public:
  id2() = default;
  template <typename Weight>
  explicit id2(const id11<Weight>& adj,
                            int root = 0) noexcept
      : nodes_(adj.num_nodes()),
        size_(adj.num_nodes()),
        order_(adj.num_nodes()) {
    decompose(adj, root);
  }
  int lca(int u, int v) const {
    while (head(u) != head(v)) {
      if (depth(head(u)) > depth(head(v))) {
        u = parent(head(u));
      } else {
        v = parent(head(v));
      }
    }
    return depth(u) < depth(v) ? u : v;
  }
  int dist(int u, int v) const {
    return depth(u) + depth(v) - 2 * depth(lca(u, v));
  }
  int head(int u) const { return nodes_[u].head; }
  int time(int u) const { return nodes_[u].time; }
  int leave(int u) const { return time(u) + size(u); }
  int depth(int u) const { return nodes_[u].depth; }
  int parent(int u) const { return nodes_[u].parent; }
  int size(int u) const { return size_[u]; }
  int node_index(int u) const { return time(u); }
  int edge_index(int u, int v) const {
    return parent(u) == v ? time(u) : time(v);
  }
  int order(int i) const { return order_[i]; }
  int ancestor(int u, int k) const {
    if (depth(u) < k) { return null(); }
    while (depth(u) - depth(head(u)) < k) {
      k -= depth(u) - depth(head(u)) + 1;
      u = parent(head(u));
    }
    return order(time(u) - k);
  }
  int move(int u, int v, int k) const {
    const int w = lca(u, v);
    const int uw = depth(u) - depth(w);
    const int vw = depth(v) - depth(w);
    if (k <= uw) { return ancestor(u, k); }
    return k <= uw + vw ? ancestor(v, uw + vw - k) : null();
  }
  bool is_above(int u, int v) const {
    return time(v) <= time(u) && time(u) < leave(v);
  }
  bool on_path(int x, int u, int v) const {
    return is_above(x, lca(u, v)) && (is_above(u, x) || is_above(v, x));
  }
  std::vector<int> get_path(int u, int v) const {
    const int w = lca(u, v);
    const int uw = depth(u) - depth(w);
    const int vw = depth(v) - depth(w);
    const int uv = uw + vw;
    std::vector<int> path(uv + 1);
    for (int i = 0; u != w; u = parent(u), ++i) { path[i] = u; }
    path[uw] = w;
    for (int i = uv; v != w; v = parent(v), --i) { path[i] = v; }
    return path;
  }
  auto vertex_segments(int u, int v) const -> std::vector<std::array<int, 2>> {
    std::vector<std::array<int, 2>> segments{};
    while (head(u) != head(v)) {
      if (depth(head(u)) > depth(head(v))) {
        segments.push_back({ time(head(u)), time(u) + 1 });
        u = parent(head(u));
      } else {
        segments.push_back({ time(head(v)), time(v) + 1 });
        v = parent(head(v));
      }
    }
    if (depth(u) > depth(v)) {
      segments.push_back({ time(v), time(u) + 1 });
    } else {
      segments.push_back({ time(u), time(v) + 1 });
    }
    return segments;
  }
  auto oriented_vertex_segments(int u, int v) const
      -> std::array<std::vector<std::array<int, 2>>, 2> {
    std::vector<std::array<int, 2>> up{}, down{};
    while (head(u) != head(v)) {
      if (depth(head(u)) > depth(head(v))) {
        up.push_back({ time(head(u)), time(u) + 1 });
        u = parent(head(u));
      } else {
        down.push_back({ time(head(v)), time(v) + 1 });
        v = parent(head(v));
      }
    }
    if (depth(u) > depth(v)) {
      up.push_back({ time(v), time(u) + 1 });
    } else {
      down.push_back({ time(u), time(v) + 1 });
    }
    std::reverse(down.begin(), down.end());
    return { std::move(up), std::move(down) };
  }
  template <detail::function<void(int, int)> Fn>
  void id8(int u, int v, Fn fn) const {
    while (head(u) != head(v)) {
      if (depth(head(u)) > depth(head(v))) {
        fn(time(head(u)), time(u) + 1);
        u = parent(head(u));
      } else {
        fn(time(head(v)), time(v) + 1);
        v = parent(head(v));
      }
    }
    if (depth(u) > depth(v)) {
      fn(time(v), time(u) + 1);
    } else {
      fn(time(u), time(v) + 1);
    }
  }
  auto edge_segments(int u, int v) const -> std::vector<std::array<int, 2>> {
    std::vector<std::array<int, 2>> segments{};
    while (head(u) != head(v)) {
      if (depth(head(u)) > depth(head(v))) {
        segments.push_back({ time(head(u)), time(u) + 1 });
        u = parent(head(u));
      } else {
        segments.push_back({ time(head(v)), time(v) + 1 });
        v = parent(head(v));
      }
    }
    if (depth(u) > depth(v)) {
      segments.push_back({ time(v) + 1, time(u) + 1 });
    } else if (depth(u) < depth(v)) {
      segments.push_back({ time(u) + 1, time(v) + 1 });
    }
    return segments;
  }
  auto oriented_edge_segments(int u, int v) const
      -> std::array<std::vector<std::array<int, 2>>, 2> {
    std::vector<std::array<int, 2>> up{}, down{};
    while (head(u) != head(v)) {
      if (depth(head(u)) > depth(head(v))) {
        up.push_back({ time(head(u)), time(u) + 1 });
        u = parent(head(u));
      } else {
        down.push_back({ time(head(v)), time(v) + 1 });
        v = parent(head(v));
      }
    }
    if (depth(u) > depth(v)) {
      up.push_back({ time(v) + 1, time(u) + 1 });
    } else if (depth(u) < depth(v)) {
      down.push_back({ time(u) + 1, time(v) + 1 });
    }
    std::reverse(down.begin(), down.end());
    return { std::move(up), std::move(down) };
  }
  template <detail::function<void(int, int)> Fn>
  void id1(int u, int v, Fn fn) const {
    while (head(u) != head(v)) {
      if (depth(head(u)) > depth(head(v))) {
        fn(time(head(u)), time(u) + 1);
        u = parent(head(u));
      } else {
        fn(time(head(v)), time(v) + 1);
        v = parent(head(v));
      }
    }
    if (depth(u) > depth(v)) {
      fn(time(v) + 1, time(u) + 1);
    } else if (depth(u) < depth(v)) {
      fn(time(u) + 1, time(v) + 1);
    }
  }
  std::vector<int> compressed() const { return order_; }
  int num_nodes() const { return static_cast<int>(order_.size()); }
  int null() const { return Null - 1; }
private:
  template <typename Weight>
  void decompose(const id11<Weight>& adj, int root = 0) {
    std::vector<int> heavy(num_nodes(), Null);
    std::fill(size_.begin(), size_.end(), 1);
    const auto dfs_tree = [&](auto self, int u, int p) -> void {
      int big_child = Null, id6 = 0;
      for (const int v : adj.neighbors(u)) {
        if (v == p) { continue; }
        nodes_[v].parent = u;
        nodes_[v].depth = nodes_[u].depth + 1;
        self(self, v, u);
        size_[u] += size_[v];
        if (id6 < size_[v]) {
          id6 = size_[v];
          big_child = v;
        }
      }
      heavy[u] = big_child;
    };
    int timer = 0;
    const auto id3 = [&](auto self, int u, int h) -> void {
      nodes_[u].head = h;
      nodes_[u].time = timer;
      order_[timer++] = u;
      if (heavy[u] != Null) { self(self, heavy[u], h); }
      for (const int v : adj.neighbors(u)) {
        if (v != nodes_[u].parent && v != heavy[u]) { self(self, v, v); }
      }
    };
    nodes_[root].parent = Null;
    dfs_tree(dfs_tree, root, Null);
    id3(id3, root, root);
  }
  static constexpr int Null = -1;
  std::vector<node_type> nodes_;
  std::vector<int> size_;
  std::vector<int> order_;
};
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
  vector<algo::edge<>> good, bad;
  algo::dsu uf(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    if (!uf.same(u, v)) {
      uf.merge(u, v);
      good.emplace_back(u, v);
    } else {
      bad.emplace_back(u, v);
    }
  }
  algo::id11 adj(algo::undirected, n, good);
  algo::id2 hld(adj);
  vector<int> sum(n + 1);
  for (auto [u, v] : bad) {
    if (hld.depth(u) < hld.depth(v)) { swap(u, v); }
    int w = hld.lca(u, v);
    if (v == w) {
      int x = hld.move(v, u, 1);
      sum[hld.time(x)]++;
      sum[hld.leave(x)]--;
      sum[hld.time(u)]--;
      sum[hld.leave(u)]++;
    } else {
      sum[hld.time(0)]++;
      sum[hld.leave(0)]--;
      sum[hld.time(u)]--;
      sum[hld.leave(u)]++;
      sum[hld.time(v)]--;
      sum[hld.leave(v)]++;
    }
  }
  for (int i = 1; i < n; ++i) { sum[i] += sum[i - 1]; }
  for (int i = 0; i < n; ++i) { cout << char('0' + (sum[hld.time(i)] == 0)); }
  cout << '\n';
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();
  return 0;
}
