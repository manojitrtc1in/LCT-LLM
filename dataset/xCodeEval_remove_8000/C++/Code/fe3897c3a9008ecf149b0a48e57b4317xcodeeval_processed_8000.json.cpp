













































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
id4(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::countl_zero<Up>(n);
}
template <typename Tp>
constexpr int
id11(Tp n) {
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
id5(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return static_cast<Tp>(std::bit_floor<Up>(n));
}
template <typename Tp>
constexpr Tp
id2(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return static_cast<Tp>(std::bit_ceil<Up>(n));
}
template <typename Tp>
constexpr int
id3(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  constexpr int Nd = std::numeric_limits<Up>::digits;
  return Nd - 1 - std::countl_zero<Up>(n);
}
template <typename Tp>
constexpr int
id8(Tp n) {
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
template <typename = void>
struct edge;
template <std::semiregular Weight>
struct edge<Weight> {
  int u;
  int v;
  Weight w;
  using arc_type = struct {
    int v;
    Weight w;
    constexpr operator int() const { return v; }
  };
};
template <>
struct edge<void> {
  int u;
  int v;
  using arc_type = struct {
    int v;
    constexpr operator int() const { return v; }
  };
};
struct directed_tag {};
struct undirected_tag {};
inline constexpr directed_tag directed{};
inline constexpr undirected_tag undirected{};
template <typename = void>
class id10;
template <std::semiregular Weight>
class id10<Weight> {
public:
  using edge_type = edge<Weight>;
  using arc_type = typename edge_type::arc_type;
  id10() = default;
  id10(directed_tag, int n,
                 const std::vector<edge_type>& edges) noexcept
      : start_(n + 1), elist_(edges.size()) {
    for (const auto& e : edges) { start_[e.u]++; }
    for (int i = 1; i <= n; ++i) { start_[i] += start_[i - 1]; }
    for (auto it = edges.rbegin(); it != edges.rend(); ++it) {
      elist_[--start_[it->u]] = {.v = it->v, .w = it->w};
    }
  }
  id10(undirected_tag, int n,
                 const std::vector<edge_type>& edges) noexcept
      : start_(n + 1), elist_(edges.size() << 1) {
    for (const auto& e : edges) {
      start_[e.u]++;
      start_[e.v]++;
    }
    for (int i = 1; i <= n; ++i) { start_[i] += start_[i - 1]; }
    for (auto it = edges.rbegin(); it != edges.rend(); ++it) {
      elist_[--start_[it->u]] = {.v = it->v, .w = it->w};
      elist_[--start_[it->v]] = {.v = it->u, .w = it->w};
    }
  }
  std::span<const arc_type, std::dynamic_extent>
  operator[](int u) const noexcept {
    assert(0 <= u && u < num_nodes());
    return {elist_.cbegin() + start_[u], elist_.cbegin() + start_[u + 1]};
  }
  std::span<arc_type, std::dynamic_extent>
  operator[](int u) noexcept {
    assert(0 <= u && u < num_nodes());
    return {elist_.begin() + start_[u], elist_.begin() + start_[u + 1]};
  }
  int
  num_nodes() const {
    return static_cast<int>(start_.size()) - 1;
  }
  int
  num_arcs() const {
    return static_cast<int>(elist_.size());
  }
private:
  std::vector<int> start_;
  std::vector<arc_type> elist_;
};
template <>
class id10<void> {
public:
  using edge_type = edge<>;
  using arc_type = edge_type::arc_type;
  id10() = default;
  id10(directed_tag, int n,
                 const std::vector<edge_type>& edges) noexcept
      : start_(n + 1), elist_(edges.size()) {
    for (const auto& e : edges) { start_[e.u]++; }
    for (int i = 1; i <= n; ++i) { start_[i] += start_[i - 1]; }
    for (auto it = edges.rbegin(); it != edges.rend(); ++it) {
      elist_[--start_[it->u]] = {.v = it->v};
    }
  }
  id10(undirected_tag, int n,
                 const std::vector<edge_type>& edges) noexcept
      : start_(n + 1), elist_(edges.size() << 1) {
    for (const auto& e : edges) {
      start_[e.u]++;
      start_[e.v]++;
    }
    for (int i = 1; i <= n; ++i) { start_[i] += start_[i - 1]; }
    for (auto it = edges.rbegin(); it != edges.rend(); ++it) {
      elist_[--start_[it->u]] = {.v = it->v};
      elist_[--start_[it->v]] = {.v = it->u};
    }
  }
  std::span<const arc_type, std::dynamic_extent>
  operator[](int u) const noexcept {
    assert(0 <= u && u < num_nodes());
    return {elist_.cbegin() + start_[u], elist_.cbegin() + start_[u + 1]};
  }
  std::span<arc_type, std::dynamic_extent>
  operator[](int u) noexcept {
    assert(0 <= u && u < num_nodes());
    return {elist_.begin() + start_[u], elist_.begin() + start_[u + 1]};
  }
  int
  num_nodes() const {
    return static_cast<int>(start_.size()) - 1;
  }
  int
  num_arcs() const {
    return static_cast<int>(elist_.size());
  }
private:
  std::vector<int> start_;
  std::vector<arc_type> elist_;
};
template <typename Weight>
edge(int, int, Weight) -> edge<Weight>;
edge(int, int)->edge<void>;
template <typename Weight>
id10(directed_tag, int, const std::vector<edge<Weight>>&)
    -> id10<Weight>;
template <typename Weight>
id10(undirected_tag, int, const std::vector<edge<Weight>>&)
    -> id10<Weight>;
template <typename Weight>
std::vector<int>
id1(const id10<Weight>& adj) {
  std::vector<uint_fast8_t> vis(adj.num_nodes());
  std::vector<int> order;
  order.reserve(adj.num_nodes());
  const auto dfs = [&](auto dfs, int u) -> void {
    vis[u] = true;
    for (const int v : adj[u]) {
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
std::vector<std::pair<int, int>>
preorder(const id10<Weight>& adj, int root = 0) {
  std::vector<std::pair<int, int>> res(adj.num_nodes());
  int time = 0;
  const auto dfs = [&](auto dfs, int u, int p) -> void {
    res[u].first = time++;
    for (const int v : adj[u]) {
      if (v == p) { continue; }
      dfs(dfs, v, u);
    }
    res[u].second = time;
  };
  dfs(dfs, root, root);
  return res;
}
}
namespace algo {
template <std::semiregular Tp>
class id12 {
public:
  id12() = default;
  id12(int row, int col, const Tp& init = Tp()) noexcept
      : row_(row), col_(col), data_(total_size(), init) {}
  id12(std::pair<int, int> dims, const Tp& init = Tp()) noexcept
      : id12(dims.first, dims.second, init) {}
  id12(int row, const std::vector<Tp>& init_col) noexcept
      : id12(row, static_cast<int>(init_col.size())) {
    for (int i = 0; i < row_size(); ++i) {
      std::copy_n(init_col.begin(), col_size(), data_.begin() + i * col_size());
    }
  }
  std::span<const Tp, std::dynamic_extent>
  operator[](int i) const noexcept {
    assert(0 <= i && i < row_size());
    return {data_.cbegin() + i * col_size(),
            data_.cbegin() + (i + 1) * col_size()};
  }
  std::span<Tp, std::dynamic_extent>
  operator[](int i) noexcept {
    assert(0 <= i && i < row_size());
    return {data_.begin() + i * col_size(),
            data_.begin() + (i + 1) * col_size()};
  }
  const Tp&
  operator()(int i, int j) const {
    assert(0 <= i && i < row_size());
    assert(0 <= j && j < col_size());
    return data_[i * col_size() + j];
  }
  Tp&
  operator()(int i, int j) {
    assert(0 <= i && i < row_size());
    assert(0 <= j && j < col_size());
    return data_[i * col_size() + j];
  }
  void
  assign(int row, int col, const Tp& value = Tp()) noexcept {
    assert(0 <= row);
    assert(0 <= col);
    row_ = row;
    col_ = col;
    data_.assign(total_size(), value);
  }
  int
  total_size() const {
    return row_ * col_;
  }
  int
  row_size() const {
    return row_;
  }
  int
  col_size() const {
    return col_;
  }
  auto
  begin() const {
    return data_.cbegin();
  }
  auto
  begin() {
    return data_.begin();
  }
  auto
  end() const {
    return data_.cend();
  }
  auto
  end() {
    return data_.end();
  }
  auto
  rbegin() const {
    return data_.crbegin();
  }
  auto
  rbegin() {
    return data_.rbegin();
  }
  auto
  rend() const {
    return data_.crend();
  }
  auto
  rend() {
    return data_.rend();
  }
  const Tp*
  data() const {
    return data_.data();
  }
  Tp*
  data() {
    return data_.data();
  }
private:
  int row_;
  int col_;
  std::vector<Tp> data_;
};
}
namespace algo {
template <typename = void, typename = void, typename = void>
class id9;
template <std::semiregular Monoid,
          detail::function<Monoid(Monoid, Monoid)> BinOp,
          detail::function<Monoid(void)> Id>
class id9<Monoid, BinOp, Id> {
public:
  using graph_type = algo::id10<Monoid>;
  id9() = default;
  explicit id9(const graph_type& adj, BinOp binop, Id id)
      : depth_(adj.num_nodes() + 1),
        parent_(adj.num_nodes() + 1, detail::bit_width(adj.num_nodes())),
        path_(adj.num_nodes() + 1, detail::bit_width(adj.num_nodes()), id()),
        binop_(std::move(binop)),
        id_(std::move(id)) {
    build(adj);
  }
  int
  lca(int u, int v) const {
    assert(0 <= u && u < num_nodes());
    assert(0 <= v && v < num_nodes());
    return get_lca(u + 1, v + 1) - 1;
  }
  int
  move_to(int u, int v, int d) const {
    assert(0 <= u && u < num_nodes());
    assert(0 <= v && v < num_nodes());
    assert(0 <= d);
    return do_move(u + 1, v + 1, d) - 1;
  }
  int
  parent(int u) const {
    assert(0 <= u && u < num_nodes());
    return get_parent(u + 1) - 1;
  }
  int
  ancestor(int u, int k) const {
    assert(0 <= u && u < num_nodes());
    return get_ancestor(u + 1, k) - 1;
  }
  int
  depth(int u) const {
    assert(0 <= u && u < num_nodes());
    return get_depth(u + 1);
  }
  int
  dist(int u, int v) const {
    assert(0 <= u && u < num_nodes());
    assert(0 <= v && v < num_nodes());
    return get_dist(u + 1, v + 1);
  }
  Monoid
  query(int u, int v) const {
    assert(0 <= u && u < num_nodes());
    assert(0 <= v && v < num_nodes());
    return do_query(u + 1, v + 1);
  }
  int
  num_nodes() const {
    return static_cast<int>(depth_.size()) - 1;
  }
  int
  null() const {
    return Null - 1;
  }
private:
  int
  get_ancestor(int u, int k) const {
    for (; k != 0; k = detail::blsr(k)) {
      const int tz = detail::id11(k);
      u = parent_[u][tz];
    }
    return u;
  }
  int
  do_move(int u, int v, int d) const {
    const int w = get_lca(u, v);
    const int uw = get_depth(u) - get_depth(w);
    const int vw = get_depth(v) - get_depth(w);
    if (uw + vw < d) { return Null; }
    if (uw >= d) { return get_ancestor(u, d); }
    return get_ancestor(v, uw + vw - d);
  }
  int
  get_parent(int u) const {
    return parent_[u][0];
  }
  int
  get_depth(int u) const {
    return depth_[u];
  }
  int
  get_lca(int u, int v) const {
    const int du = get_depth(u);
    const int dv = get_depth(v);
    if (du > dv) { u = get_ancestor(u, du - dv); }
    if (dv > du) { v = get_ancestor(v, dv - du); }
    if (u == v) { return u; }
    for (int i = parent_.col_size() - 1; i >= 0; --i) {
      if (parent_[u][i] != parent_[v][i]) {
        u = parent_[u][i];
        v = parent_[v][i];
      }
    }
    return parent_[u][0];
  }
  int
  get_dist(int u, int v) const {
    const int w = get_lca(u, v);
    const int uw = get_depth(u) - get_depth(w);
    const int vw = get_depth(v) - get_depth(w);
    return uw + vw;
  }
  Monoid
  do_query(int u, int v) const {
    const int w = get_lca(u, v);
    const int du = get_depth(u) - get_depth(w);
    const int dv = get_depth(v) - get_depth(w);
    Monoid res = id_();
    for (int k = du; k != 0; k = detail::blsr(k)) {
      const int tz = detail::id11(k);
      res = binop_(std::move(res), path_[u][tz]);
      u = parent_[u][tz];
    }
    for (int k = dv; k != 0; k = detail::blsr(k)) {
      const int tz = detail::id11(k);
      res = binop_(std::move(res), path_[v][tz]);
      v = parent_[v][tz];
    }
    return res;
  }
  void
  build(const graph_type& adj, int u = 1, int p = Null) {
    for (int i = 1; (1 << i) <= depth_[u]; ++i) {
      path_[u][i] = binop_(path_[u][i - 1], path_[parent_[u][i - 1]][i - 1]);
      parent_[u][i] = parent_[parent_[u][i - 1]][i - 1];
    }
    for (const auto& [v, w] : adj[u - 1]) {
      const int nv = v + 1;
      if (nv == p) { continue; }
      parent_[nv][0] = u;
      path_[nv][0] = w;
      depth_[nv] = depth_[u] + 1;
      build(adj, nv, u);
    }
  }
  static constexpr int Null = 0;
  std::vector<int> depth_;
  algo::id12<int> parent_;
  algo::id12<Monoid> path_;
  BinOp binop_;
  Id id_;
};
template <>
class id9<void, void, void> {
public:
  using graph_type = algo::id10<>;
  id9() = default;
  explicit id9(const graph_type& adj)
      : depth_(adj.num_nodes() + 1),
        parent_(adj.num_nodes() + 1, detail::bit_width(adj.num_nodes())) {
    build(adj);
  }
  int
  lca(int u, int v) const {
    assert(0 <= u && u < num_nodes());
    assert(0 <= v && v < num_nodes());
    return get_lca(u + 1, v + 1) - 1;
  }
  int
  move_to(int u, int v, int d) const {
    assert(0 <= u && u < num_nodes());
    assert(0 <= v && v < num_nodes());
    assert(0 <= d);
    return do_move(u + 1, v + 1, d) - 1;
  }
  int
  parent(int u) const {
    assert(0 <= u && u < num_nodes());
    return get_parent(u + 1) - 1;
  }
  int
  ancestor(int u, int k) const {
    assert(0 <= u && u < num_nodes());
    return get_ancestor(u + 1, k) - 1;
  }
  int
  depth(int u) const {
    assert(0 <= u && u < num_nodes());
    return get_depth(u + 1);
  }
  int
  dist(int u, int v) const {
    assert(0 <= u && u < num_nodes());
    assert(0 <= v && v < num_nodes());
    return get_dist(u + 1, v + 1);
  }
  int
  num_nodes() const {
    return static_cast<int>(depth_.size()) - 1;
  }
  int
  null() const {
    return Null - 1;
  }
private:
  int
  get_ancestor(int u, int k) const {
    for (; k != 0; k = detail::blsr(k)) {
      const int tz = detail::id11(k);
      u = parent_[u][tz];
    }
    return u;
  }
  int
  do_move(int u, int v, int d) const {
    const int w = get_lca(u, v);
    const int uw = get_depth(u) - get_depth(w);
    const int vw = get_depth(v) - get_depth(w);
    if (uw + vw < d) { return Null; }
    if (uw >= d) { return get_ancestor(u, d); }
    return get_ancestor(v, uw + vw - d);
  }
  int
  get_parent(int u) const {
    return parent_[u][0];
  }
  int
  get_depth(int u) const {
    return depth_[u];
  }
  int
  get_lca(int u, int v) const {
    const int du = get_depth(u);
    const int dv = get_depth(v);
    if (du > dv) { u = get_ancestor(u, du - dv); }
    if (dv > du) { v = get_ancestor(v, dv - du); }
    if (u == v) { return u; }
    for (int i = parent_.col_size() - 1; i >= 0; --i) {
      if (parent_[u][i] != parent_[v][i]) {
        u = parent_[u][i];
        v = parent_[v][i];
      }
    }
    return parent_[u][0];
  }
  int
  get_dist(int u, int v) const {
    const int w = get_lca(u, v);
    const int uw = get_depth(u) - get_depth(w);
    const int vw = get_depth(v) - get_depth(w);
    return uw + vw;
  }
  void
  build(const graph_type& adj, int u = 1, int p = Null) {
    for (int i = 1; (1 << i) <= depth_[u]; ++i) {
      parent_[u][i] = parent_[parent_[u][i - 1]][i - 1];
    }
    for (const int v : adj[u - 1]) {
      const int nv = v + 1;
      if (nv == p) { continue; }
      parent_[nv][0] = u;
      depth_[nv] = depth_[u] + 1;
      build(adj, nv, u);
    }
  }
  static constexpr int Null = 0;
  std::vector<int> depth_;
  algo::id12<int> parent_;
};
template <typename Monoid, typename BinOp, typename Id>
id9(const id10<Monoid>&, BinOp, Id)
    -> id9<Monoid, BinOp, Id>;
id9(const id10<void>&)->id9<void, void, void>;
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
id2(Tp n) {
  return detail::id2(n);
}
template <detail::integer Tp>
constexpr int
id3(Tp n) {
  return detail::id3(n);
}
template <detail::integer Tp>
constexpr int
id8(Tp n) {
  return detail::id8(n);
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
class dsu {
public:
  dsu() = default;
  explicit dsu(int n) : parent_(n, -1) {}
  bool
  merge(int a, int b) {
    assert(0 <= a && a < num_nodes());
    assert(0 <= b && b < num_nodes());
    int sa = find(a), sb = find(b);
    if (sa != sb) {
      if (-parent_[sa] < -parent_[sb]) { std::swap(sa, sb); }
      parent_[sa] += parent_[sb];
      parent_[sb] = sa;
      return true;
    }
    return false;
  }
  int
  find(int a) {
    assert(0 <= a && a < num_nodes());
    if (parent_[a] >= 0) {
      parent_[a] = find(parent_[a]);
      return parent_[a];
    }
    return a;
  }
  int
  size(int a) {
    assert(0 <= a && a < num_nodes());
    return -parent_[find(a)];
  }
  bool
  same(int a, int b) {
    assert(0 <= a && a < num_nodes());
    assert(0 <= b && b < num_nodes());
    return find(a) == find(b);
  }
  int
  num_nodes() const {
    return static_cast<int>(parent_.size());
  }
private:
  std::vector<int> parent_;
};
}
namespace algo::detail {
template <typename Tp>
constexpr Tp
sqrt(Tp n) {
  if (n == 0) { return 0; }
  Tp res = 0;
  for (int i = id3(n) >> 1; i >= 0; --i) {
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
id13(Tp n) {
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
namespace algo {
template <std::semiregular Monoid,
          detail::function<Monoid(Monoid, Monoid)> BinOp,
          detail::function<Monoid(void)> Id>
class id7 {
public:
  id7() = default;
  id7(int n, BinOp binop, Id id)
      : n_(n),
        lg2_(detail::id8(n)),
        size_(1 << lg2_),
        tree_(size_ << 1, id()),
        binop_(std::move(binop)),
        id_(std::move(id)) {}
  id7(int n, const Monoid& init, BinOp binop, Id id)
      : n_(n),
        lg2_(detail::id8(n)),
        size_(1 << lg2_),
        tree_(size_ << 1, init),
        binop_(std::move(binop)),
        id_(std::move(id)) {
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  template <detail::input_iterator<Monoid> IIter>
  id7(IIter first, IIter last, BinOp binop, Id id)
      : id7(static_cast<int>(std::distance(first, last)), std::move(binop),
                std::move(id)) {
    std::copy(first, last, tree_.begin() + size_);
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  template <std::input_iterator IIter,
            detail::function<Monoid(std::iter_value_t<IIter>)> Gen>
  id7(IIter first, IIter last, BinOp binop, Id id, Gen gen)
      : id7(static_cast<int>(std::distance(first, last)), std::move(binop),
                std::move(id)) {
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
    l += size_ - 1;
    r += size_ + 0;
    const int mask = detail::id5(l ^ r) - 1;
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
    return size();
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
  Monoid
  id() const {
    return id_();
  }
  Monoid
  binop(Monoid x, Monoid y) const {
    return binop_(std::move(x), std::move(y));
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
  int n_;
  int lg2_;
  int size_;
  std::vector<Monoid> tree_;
  BinOp binop_;
  Id id_;
};
template <typename Monoid, typename BinOp, typename Id>
id7(int, const Monoid&, BinOp, Id) -> id7<Monoid, BinOp, Id>;
template <typename IIter, typename BinOp, typename Id>
id7(IIter, IIter, BinOp, Id)
    -> id7<std::iter_value_t<IIter>, BinOp, Id>;
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
using std::polar;
using std::queue;
using std::remainder;
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
  int n, m, q;
  cin >> n >> m >> q;
  auto fx = [](int x, int y) { return max(x, y); };
  auto ef = [] { return 0; };
  vector<algo::edge<int>> es;
  algo::dsu uf(n);
  es.reserve(n - 1);
  for (int k = 1; k <= m; ++k) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    if (uf.merge(u, v)) {
      es.emplace_back(u, v, k);
    }
  }
  const algo::id10 adj(algo::undirected, n, es);
  const algo::id9 bin(adj, fx, ef);
  vector<int> xn(n - 1);
  for (int u = 0; u < n - 1; ++u) {
    xn[u] = bin.query(u, u + 1);
  }
  const algo::id7 seg(xn.begin(), xn.end(), fx, ef);
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << seg.query(--l, --r) << ' ';
  }
  cout << '\n';
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int tc;
  std::cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
