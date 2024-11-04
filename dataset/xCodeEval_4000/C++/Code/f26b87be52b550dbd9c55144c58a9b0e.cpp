#pragma GCC target("abm,movbe,bmi,bmi2,lzcnt,popcnt,avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("inline")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("omit-frame-pointer")
#define NDEBUG 1
#include <immintrin.h>
#include <algorithm>
#include <array>
#include <bit>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <compare>
#include <complex>
#include <concepts>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <memory_resource>
#include <new>
#include <numeric>
#include <optional>
#include <queue>
#include <random>
#include <set>
#include <span>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
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
count_lz(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::countl_zero<Up>(n);
}
template <typename Tp>
constexpr int
count_tz(Tp n) {
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
floor_pow2(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return static_cast<Tp>(std::bit_floor<Up>(n));
}
template <typename Tp>
constexpr Tp
ceil_pow2(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return static_cast<Tp>(std::bit_ceil<Up>(n));
}
template <typename Tp>
constexpr int
floor_log2(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  constexpr int Nd = std::numeric_limits<Up>::digits;
  return Nd - 1 - std::countl_zero<Up>(n);
}
template <typename Tp>
constexpr int
ceil_log2(Tp n) {
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
count_lz(Tp n) {
  return detail::count_lz(n);
}
template <detail::integer Tp>
constexpr int
count_tz(Tp n) {
  return detail::count_tz(n);
}
template <detail::integer Tp>
constexpr int
bit_width(Tp n) {
  return detail::bit_width(n);
}
template <detail::integer Tp>
constexpr Tp
floor_pow2(Tp n) {
  return detail::floor_pow2(n);
}
template <detail::integer Tp>
constexpr Tp
ceil_pow2(Tp n) {
  return detail::ceil_pow2(n);
}
template <detail::integer Tp>
constexpr int
floor_log2(Tp n) {
  return detail::floor_log2(n);
}
template <detail::integer Tp>
constexpr int
ceil_log2(Tp n) {
  return detail::ceil_log2(n);
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
#define LOG(...) (void)0
#define DEBUG(x) (void)0
namespace algo {
class dsu {
public:
  dsu() = default;
  explicit dsu(int n) : fa_(n, -1) {}
  int
  merge(int a, int b) {
    assert(0 <= a && a < num_nodes());
    assert(0 <= b && b < num_nodes());
    int sa = leader(a), sb = leader(b);
    if (sa != sb) {
      if (-fa_[sa] < -fa_[sb]) { std::swap(sa, sb); }
      fa_[sa] += fa_[sb];
      fa_[sb] = sa;
    }
    return sa;
  }
  int
  leader(int a) {
    assert(0 <= a && a < num_nodes());
    if (fa_[a] >= 0) {
      fa_[a] = leader(fa_[a]);
      return fa_[a];
    }
    return a;
  }
  int
  size(int a) {
    assert(0 <= a && a < num_nodes());
    return -fa_[leader(a)];
  }
  bool
  is_same(int a, int b) {
    assert(0 <= a && a < num_nodes());
    assert(0 <= b && b < num_nodes());
    return leader(a) == leader(b);
  }
  int
  num_nodes() const {
    return static_cast<int>(fa_.size());
  }
private:
  std::vector<int> fa_;
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
struct undirected_tag {};
struct directed_tag {};
template <typename = void>
class adjacency_list;
template <std::semiregular Weight>
class adjacency_list<Weight> {
public:
  using edge_type = edge<Weight>;
  using arc_type = typename edge_type::arc_type;
  adjacency_list() = default;
  adjacency_list(int n, const std::vector<edge_type>& edges,
                 directed_tag) noexcept
      : start_(n + 1), elist_(edges.size()) {
    for (const auto& e : edges) { start_[e.u]++; }
    for (int i = 1; i <= n; ++i) { start_[i] += start_[i - 1]; }
    for (auto it = edges.rbegin(); it != edges.rend(); ++it) {
      elist_[--start_[it->u]] = {it->v, it->w};
    }
  }
  adjacency_list(int n, const std::vector<edge_type>& edges,
                 undirected_tag) noexcept
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
class adjacency_list<void> {
public:
  using edge_type = edge<>;
  using arc_type = edge_type::arc_type;
  adjacency_list() = default;
  adjacency_list(int n, const std::vector<edge_type>& edges,
                 directed_tag) noexcept
      : start_(n + 1), elist_(edges.size()) {
    for (const auto& e : edges) { start_[e.u]++; }
    for (int i = 1; i <= n; ++i) { start_[i] += start_[i - 1]; }
    for (auto it = edges.rbegin(); it != edges.rend(); ++it) {
      elist_[--start_[it->u]] = {it->v};
    }
  }
  adjacency_list(int n, const std::vector<edge_type>& edges,
                 undirected_tag) noexcept
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
adjacency_list(int, const std::vector<edge<Weight>>&, directed_tag)
    -> adjacency_list<Weight>;
template <typename Weight>
adjacency_list(int, const std::vector<edge<Weight>>&, undirected_tag)
    -> adjacency_list<Weight>;
template <typename Weight>
std::vector<int>
toposort(const adjacency_list<Weight>& adj) {
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
preorder(const adjacency_list<Weight>& adj, int root = 0) {
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
class vector2d {
public:
  vector2d() = default;
  vector2d(int row, int col, const Tp& init = Tp()) noexcept
      : row_(row), col_(col), data_(total_size(), init) {}
  vector2d(std::pair<int, int> dims, const Tp& init = Tp()) noexcept
      : vector2d(dims.first, dims.second, init) {}
  vector2d(int row, const std::vector<Tp>& init_col) noexcept
      : vector2d(row, static_cast<int>(init_col.size())) {
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
class lca_tree {
  static constexpr int Null = 0;
  using table_type = algo::vector2d<int>;
public:
  using graph_type = algo::adjacency_list<>;
  lca_tree() = default;
  explicit lca_tree(const graph_type& adj, int root = 0)
      : depth_(adj.num_nodes() + 1),
        parent_(adj.num_nodes() + 1, detail::bit_width(adj.num_nodes())) {
    build(adj, root + 1);
  }
  int
  lca(int u, int v) const {
    assert(0 <= u && u < num_nodes());
    assert(0 <= v && v < num_nodes());
    return get_lca(u + 1, v + 1) - 1;
  }
  int
  move(int u, int v, int d) const {
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
      const int tz = detail::count_tz(k);
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
  build(const graph_type& adj, int u, int p = Null) {
    parent_[u][0] = p;
    for (int i = 1; (1 << i) <= depth_[u]; ++i) {
      parent_[u][i] = parent_[parent_[u][i - 1]][i - 1];
    }
    for (const int v : adj[u - 1]) {
      const int nv = v + 1;
      if (nv == p) { continue; }
      depth_[nv] = depth_[u] + 1;
      build(adj, nv, u);
    }
  }
  std::vector<int> depth_;
  table_type parent_;
};
}
namespace algo::detail {
template <typename Tp>
constexpr Tp
sqrt(Tp n) {
  if (n == 0) { return 0; }
  Tp res = 0;
  for (int i = floor_log2(n) >> 1; i >= 0; --i) {
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
cbrt(Tp n) {
  if (n == 0) { return 0; }
  Tp res = 0;
  const Tp m = detail::abs(n);
  for (int i = detail::floor_log2(m) / 3; i >= 0; --i) {
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
#define INF 0x3f3f3f3f
#define MOD 998244353
#define MAXN 200001
#define MULTI 0
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
    if (!uf.is_same(u, v)) {
      uf.merge(u, v);
      good.emplace_back(u, v);
    } else {
      bad.emplace_back(u, v);
    }
  }
  const algo::adjacency_list adj(n, good, algo::undirected_tag{});
  const algo::lca_tree lt(adj);
  const auto ts = algo::preorder(adj);
  vector<int> sum(n + 1);
  for (auto [u, v] : bad) {
    if (lt.depth(u) < lt.depth(v)) {
      swap(u, v);
    }
    int w = lt.lca(u, v);
    if (v == w) {
      int x = lt.move(v, u, 1);
      sum[ts[x].first]++;
      sum[ts[x].second]--;
      sum[ts[u].first]--;
      sum[ts[u].second]++;
    } else {
      sum[ts[0].first]++;
      sum[ts[0].second]--;
      sum[ts[u].first]--;
      sum[ts[u].second]++;
      sum[ts[v].first]--;
      sum[ts[v].second]++;
    }
  }
  for (int i = 1; i < n; ++i) {
    sum[i] += sum[i - 1];
  }
  for (int u = 0; u < n; ++u) {
    cout << char('0' + (sum[ts[u].first] == 0));
  }
  cout << '\n';
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();
  return 0;
}
