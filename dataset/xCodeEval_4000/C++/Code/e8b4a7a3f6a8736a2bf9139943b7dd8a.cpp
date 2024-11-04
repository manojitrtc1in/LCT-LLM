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
#include <ranges>
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
constexpr int count_lz(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::countl_zero<Up>(n);
}
template <typename Tp>
constexpr int count_tz(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::countr_zero<Up>(n);
}
template <typename Tp>
constexpr int bit_width(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return std::bit_width<Up>(n);
}
template <typename Tp>
constexpr Tp floor_pow2(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return static_cast<Tp>(std::bit_floor<Up>(n));
}
template <typename Tp>
constexpr Tp ceil_pow2(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  return static_cast<Tp>(std::bit_ceil<Up>(n));
}
template <typename Tp>
constexpr int floor_log2(Tp n) {
  using Up = std::make_unsigned_t<Tp>;
  constexpr int Nd = std::numeric_limits<Up>::digits;
  return Nd - 1 - std::countl_zero<Up>(n);
}
template <typename Tp>
constexpr int ceil_log2(Tp n) {
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
constexpr int count_lz(Tp n) {
  return detail::count_lz(n);
}
template <detail::integer Tp>
constexpr int count_tz(Tp n) {
  return detail::count_tz(n);
}
template <detail::integer Tp>
constexpr int bit_width(Tp n) {
  return detail::bit_width(n);
}
template <detail::integer Tp>
constexpr Tp floor_pow2(Tp n) {
  return detail::floor_pow2(n);
}
template <detail::integer Tp>
constexpr Tp ceil_pow2(Tp n) {
  return detail::ceil_pow2(n);
}
template <detail::integer Tp>
constexpr int floor_log2(Tp n) {
  return detail::floor_log2(n);
}
template <detail::integer Tp>
constexpr int ceil_log2(Tp n) {
  return detail::ceil_log2(n);
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
#define PRINT(...) (void)0
#define DEBUG(x) (void)0
namespace algo::detail {
template <typename Tp>
constexpr Tp sqrt(Tp n) {
  if (n == 0) { return 0; }
  Tp ans = 0;
  for (int i = floor_log2(n) >> 1; i >= 0; --i) {
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
template <typename Tp>
class buffer_queue {
public:
  using sequence_type = std::vector<Tp>;
  buffer_queue() : removed_(0), buffer_{} {}
  void push(Tp v) noexcept { buffer_.push_back(std::move(v)); }
  void pop() { removed_++; }
  const Tp& front() const { return buffer_[removed_]; }
  Tp& front() { return buffer_[removed_]; }
  const Tp& back() const { return buffer_.back(); }
  Tp& back() { return buffer_.back(); }
  void reserve(int n) noexcept { buffer_.reserve(n); }
  bool empty() const { return size() == 0; }
  int size() const { return static_cast<int>(buffer_.size()) - removed_; }
private:
  int removed_;
  sequence_type buffer_;
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
class adjacency_list;
template <std::semiregular Weight>
class adjacency_list<Weight> {
public:
  using edge_type = edge<Weight>;
  using arc_type = typename edge_type::arc_type;
  adjacency_list() = default;
  adjacency_list(directed_tag, int n,
                 const std::vector<edge_type>& edges) noexcept
      : start_(n + 1), elist_(edges.size()) {
    for (const auto& e : edges) { start_[e.u]++; }
    for (int i = 1; i <= n; ++i) { start_[i] += start_[i - 1]; }
    for (auto it = edges.rbegin(); it != edges.rend(); ++it) {
      elist_[--start_[it->u]] = {it->v, it->w};
    }
  }
  adjacency_list(undirected_tag, int n,
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
class adjacency_list<void> {
public:
  using edge_type = edge<>;
  using arc_type = edge_type::arc_type;
  adjacency_list() = default;
  adjacency_list(directed_tag, int n,
                 const std::vector<edge_type>& edges) noexcept
      : start_(n + 1), elist_(edges.size()) {
    for (const auto& e : edges) { start_[e.u]++; }
    for (int i = 1; i <= n; ++i) { start_[i] += start_[i - 1]; }
    for (auto it = edges.rbegin(); it != edges.rend(); ++it) {
      elist_[--start_[it->u]] = {it->v};
    }
  }
  adjacency_list(undirected_tag, int n,
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
adjacency_list(directed_tag, int, const std::vector<edge<Weight>>&)
    -> adjacency_list<Weight>;
template <typename Weight>
adjacency_list(undirected_tag, int, const std::vector<edge<Weight>>&)
    -> adjacency_list<Weight>;
template <typename Weight>
std::vector<int> toposort(const adjacency_list<Weight>& adj) {
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
auto preorder(const adjacency_list<Weight>& adj, int root = 0)
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
template <detail::arithmetic Flow>
class maximum_flow {
  struct flow_edge_map {
    int v;
    int rev;
    Flow cap;
  };
  struct flow_node_map {
    int head;
    int level;
  };
  using edge_type = edge<Flow>;
  static constexpr int Undefined = -1;
  static constexpr Flow FlowInf = std::numeric_limits<Flow>::max() / 2;
public:
  maximum_flow() = default;
  explicit maximum_flow(int n) noexcept : num_nodes_(n), edges_{} {}
  int add_edge(int u, int v, Flow cap) {
    const int id = num_arcs();
    edges_.emplace_back(u, v, cap);
    return id;
  }
  void set_capacity(int e, Flow new_cap) { edges_[e].w = new_cap; }
  void add_capacity(int e, Flow d) { set_capacity(e, get_capacity(e) + d); }
  Flow get_capacity(int e) const { return edges_[e].w; }
  const edge_type& get_edge(int e) const { return edges_[e]; }
  Flow max_flow(int s, int t) const {
    const int m = num_arcs();
    const int n = num_nodes();
    std::vector<flow_edge_map> elist(m + m);
    std::vector<int> start(n + 1);
    std::vector<int> edge_id(m);
    for (const auto& [u, v, cap] : edges_) {
      start[u]++;
      start[v]++;
    }
    for (int u = 1; u <= n; ++u) { start[u] += start[u - 1]; }
    for (int i = m - 1; i >= 0; --i) {
      const auto& [u, v, cap] = edges_[i];
      const int e1 = --start[u];
      const int e0 = --start[v];
      elist[e1] = {.v = v, .rev = e0, .cap = cap};
      elist[e0] = {.v = u, .rev = e1, .cap = 0};
      edge_id[i] = e1;
    }
    std::vector<flow_node_map> nodes(n);
    std::vector<int> next_edge(m + m);
    Flow total_flow = 0;
    while (reachable(s, t, start, elist, next_edge, nodes)) {
      total_flow += push_flow(s, t, FlowInf, next_edge, elist, nodes);
    }
    return total_flow;
  }
  Flow max_flow(int s, int t, std::vector<Flow>& flow) const {
    const int m = num_arcs();
    const int n = num_nodes();
    std::vector<flow_edge_map> elist(m + m);
    std::vector<int> start(n + 1);
    std::vector<int> edge_id(m);
    for (const auto& [u, v, cap] : edges_) {
      start[u]++;
      start[v]++;
    }
    for (int u = 1; u <= n; ++u) { start[u] += start[u - 1]; }
    for (int i = m - 1; i >= 0; --i) {
      const auto& [u, v, cap] = edges_[i];
      const int e1 = --start[u];
      const int e0 = --start[v];
      elist[e1] = {.v = v, .rev = e0, .cap = cap};
      elist[e0] = {.v = u, .rev = e1, .cap = 0};
      edge_id[i] = e1;
    }
    std::vector<flow_node_map> nodes(n);
    std::vector<int> next_edge(m + m);
    Flow total_flow = 0;
    while (reachable(s, t, start, elist, next_edge, nodes)) {
      total_flow += push_flow(s, t, FlowInf, next_edge, elist, nodes);
    }
    for (size_t i = 0; i < flow.size(); ++i) {
      flow[i] = edges_[i].w - elist[edge_id[i]].cap;
    }
    return total_flow;
  }
  std::vector<bool> min_cut(int s, int t) const {
    const int m = num_arcs();
    const int n = num_nodes();
    std::vector<flow_edge_map> elist(m + m);
    std::vector<int> start(n + 1);
    std::vector<int> edge_id(m);
    for (const auto& [u, v, cap] : edges_) {
      start[u]++;
      start[v]++;
    }
    for (int u = 1; u <= n; ++u) { start[u] += start[u - 1]; }
    for (int i = m - 1; i >= 0; --i) {
      const auto& [u, v, cap] = edges_[i];
      const int e1 = --start[u];
      const int e0 = --start[v];
      elist[e1] = {.v = v, .rev = e0, .cap = cap};
      elist[e0] = {.v = u, .rev = e1, .cap = 0};
      edge_id[i] = e1;
    }
    std::vector<flow_node_map> nodes(n);
    std::vector<int> next_edge(m + m);
    Flow total_flow = 0;
    while (reachable(s, t, start, elist, next_edge, nodes)) {
      total_flow += push_flow(s, t, FlowInf, next_edge, elist, nodes);
    }
    std::vector<bool> right(n);
    std::transform(nodes.begin(), nodes.end(), right.begin(),
                   [](flow_node_map nd) { return nd.level == Undefined; });
    return right;
  }
  std::vector<bool> min_cut(int s, int t, std::vector<Flow>& flow) const {
    const int m = num_arcs();
    const int n = num_nodes();
    std::vector<flow_edge_map> elist(m + m);
    std::vector<int> start(n + 1);
    std::vector<int> edge_id(m);
    for (const auto& [u, v, cap] : edges_) {
      start[u]++;
      start[v]++;
    }
    for (int u = 1; u <= n; ++u) { start[u] += start[u - 1]; }
    for (int i = m - 1; i >= 0; --i) {
      const auto& [u, v, cap] = edges_[i];
      const int e1 = --start[u];
      const int e0 = --start[v];
      elist[e1] = {.v = v, .rev = e0, .cap = cap};
      elist[e0] = {.v = u, .rev = e1, .cap = 0};
      edge_id[i] = e1;
    }
    std::vector<flow_node_map> nodes(n);
    std::vector<int> next_edge(m + m);
    Flow total_flow = 0;
    while (reachable(s, t, start, elist, next_edge, nodes)) {
      total_flow += push_flow(s, t, FlowInf, next_edge, elist, nodes);
    }
    for (size_t i = 0; i < flow.size(); ++i) {
      flow[i] = edges_[i].w - elist[edge_id[i]].cap;
    }
    std::vector<bool> right(n);
    std::transform(nodes.begin(), nodes.end(), right.begin(),
                   [](flow_node_map nd) { return nd.level == Undefined; });
    return right;
  }
  int num_nodes() const { return num_nodes_; }
  int num_arcs() const { return static_cast<int>(edges_.size()); }
private:
  bool reachable(int s, int t, const std::vector<int>& start,
                 const std::vector<flow_edge_map>& elist,
                 std::vector<int>& next_edge,
                 std::vector<flow_node_map>& nodes) const {
    std::fill(next_edge.begin(), next_edge.end(), Undefined);
    std::fill(nodes.begin(), nodes.end(), flow_node_map{Undefined, Undefined});
    buffer_queue<int> que;
    que.push(s);
    nodes[s].level = 0;
    while (!que.empty()) {
      const int u = que.front();
      que.pop();
      for (int e = start[u]; e < start[u + 1]; ++e) {
        if (elist[e].cap == 0) { continue; }
        const int v = elist[e].v;
        if (nodes[v].level == Undefined) {
          nodes[v].level = nodes[u].level + 1;
          que.push(v);
        }
        if (nodes[u].level < nodes[v].level) {
          next_edge[e] = nodes[u].head;
          nodes[u].head = e;
        }
      }
    }
    return nodes[t].level != Undefined;
  }
  Flow push_flow(int u, int t, Flow flow_to_push,
                 const std::vector<int>& next_edge,
                 std::vector<flow_edge_map>& elist,
                 std::vector<flow_node_map>& nodes) const {
    if (u == t) { return flow_to_push; }
    Flow pushed_flow = 0;
    int& e = nodes[u].head;
    while (e != Undefined && flow_to_push > 0) {
      const int v = elist[e].v;
      const Flow next_flow = std::min(flow_to_push, elist[e].cap);
      const Flow improved = push_flow(v, t, next_flow, next_edge, elist, nodes);
      if (improved != 0) {
        elist[e].cap -= improved;
        elist[elist[e].rev].cap += improved;
        pushed_flow += improved;
        flow_to_push -= improved;
      }
      if (elist[e].cap == 0 || flow_to_push > 0) { e = next_edge[e]; }
    }
    return pushed_flow;
  }
  int num_nodes_;
  std::vector<edge_type> edges_;
};
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
#define INF 0x3f3f3f3f
#define MOD 998244353
#define MAXN 200001
#define MULTI 0
namespace {
}
void solve() noexcept {
  int n1, n2;
  cin >> n1 >> n2;
  int m;
  cin >> m;
  int q;
  cin >> q;
  vector<algo::edge<>> es(m);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    es[i] = {--x, --y + n1};
  }
  int tot = n1 + n2;
  int ds = tot, dt = tot + 1;
  algo::maximum_flow<int> mf(tot + 2);
  set<int> mat;
  for (int i = 0; i < m; ++i) { mf.add_edge(es[i].u, es[i].v, 1); }
  for (int u = 0; u < n1; ++u) { mf.add_edge(ds, u, 1); }
  for (int u = n1; u < tot; ++u) { mf.add_edge(u, dt, 1); }
  vector<int> flow(m);
  vector<int> pos(tot);
  auto mct = mf.min_cut(ds, dt, flow);
  wint sum = 0;
  for (int i = 0; i < m; ++i) {
    if (flow[i]) {
      mat.insert(i);
      pos[es[i].u] = i;
      pos[es[i].v] = i;
      sum += i + 1;
    }
  }
  vector<int> cover;
  for (int u = 0; u < n1; ++u) {
    if (mct[u]) { cover.push_back(u); }
  }
  for (int u = n1; u < tot; ++u) {
    if (!mct[u]) { cover.push_back(u); }
  }
  while (q--) {
    if (int t; cin >> t, t == 1) {
      cout << "1\n";
      int u = cover.back();
      cover.pop_back();
      if (u < n1) {
        cout << u + 1 << '\n';
      } else {
        cout << -(u - n1 + 1) << '\n';
      }
      sum -= pos[u] + 1;
      cout << sum << '\n';
      assert(mat.contains(pos[u]));
      mat.erase(pos[u]);
    } else {
      cout << mat.size() << '\n';
      for (int e : mat) { cout << e + 1 << ' '; }
      cout << '\n';
    }
    cout.flush();
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();
  return 0;
}
