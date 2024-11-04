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
[[gnu::noreturn]] inline void
unreachable() {
  __builtin_unreachable();
}
[[gnu::always_inline]] constexpr void
assume(bool expr) {
  if (!expr) { __builtin_unreachable(); }
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
namespace algo {
template <typename Tp>
class buffer_queue {
public:
  using sequence_type = std::vector<Tp>;
  buffer_queue() : removed_(0), buffer_{} {}
  void push(Tp v) noexcept { buffer_.push_back(std::move(v)); }
  void pop() { removed_++; }
  const Tp& front() const {
    assert(!empty());
    return buffer_[removed_];
  }
  Tp& front() {
    assert(!empty());
    return buffer_[removed_];
  }
  const Tp& back() const {
    assert(!empty());
    return buffer_.back();
  }
  Tp& back() {
    assert(!empty());
    return buffer_.back();
  }
  void reserve(int n) noexcept { buffer_.reserve(n); }
  bool empty() const { return size() == 0; }
  int size() const { return static_cast<int>(buffer_.size()) - removed_; }
private:
  int removed_;
  sequence_type buffer_;
};
}
namespace algo {
template <detail::arithmetic Flow>
class maximum_flow {
  struct flow_edge {
    int u;
    int v;
    Flow cap;
    Flow flow;
  };
  struct flow_node_map {
    int start;
    int head;
    int level;
  };
  struct flow_edge_map {
    int id;
    int next;
  };
  using edge_type = flow_edge;
  static constexpr int Undefined = -1;
  static constexpr Flow FlowInf = std::numeric_limits<Flow>::max() / 2;
public:
  maximum_flow() = default;
  explicit maximum_flow(int n) : num_nodes_(n), edges_{} {}
  int add_edge(int u, int v, Flow cap) {
    assert(0 <= u && u < num_nodes());
    assert(0 <= v && v < num_nodes());
    assert(0 <= cap);
    const int id = num_arcs();
    edges_.emplace_back(u, v, cap, 0);
    edges_.emplace_back(v, u, 0, 0);
    return id;
  }
  void set_capacity(int e, Flow new_cap) {
    assert(0 <= e && e < num_arcs());
    assert(0 <= new_cap);
    edges_[e << 1].cap = new_cap;
  }
  void add_capacity(int e, Flow d) {
    assert(0 <= e && e < num_arcs());
    set_capacity(e, get_capacity(e) + d);
  }
  Flow get_capacity(int e) const {
    assert(0 <= e && e < num_arcs());
    return edges_[e << 1].cap;
  }
  Flow get_flow(int e) const {
    assert(0 <= e && e < num_arcs());
    return edges_[e << 1].flow;
  }
  Flow max_flow(int s, int t) {
    assert(0 <= s && s < num_nodes());
    assert(0 <= t && t < num_nodes());
    assert(s != t);
    const int m = num_arcs();
    const int n = num_nodes();
    std::vector<flow_edge_map> elist(m + m);
    std::vector<flow_node_map> nodes(n + 1);
    for (const auto& e : edges_) { nodes[e.u].start++; }
    for (int i = 1; i <= n; ++i) { nodes[i].start += nodes[i - 1].start; }
    for (int i = m + m - 1; i >= 0; --i) {
      elist[--nodes[edges_[i].u].start] = {i, Undefined};
    }
    Flow total_flow = 0;
    while (reachable(s, t, elist, nodes)) {
      total_flow += push_flow(s, t, FlowInf, elist, nodes);
    }
    return total_flow;
  }
  void clear() {
    const int m = num_arcs();
    for (int i = 0; i < m + m; ++i) { edges_[i].flow = 0; }
  }
  int num_nodes() const { return num_nodes_; }
  int num_arcs() const { return static_cast<int>(edges_.size()) >> 1; }
private:
  bool reachable(int s, int t, std::vector<flow_edge_map>& elist,
                 std::vector<flow_node_map>& nodes) const {
    const int n = num_nodes();
    const int m = num_arcs();
    for (int i = 0; i < m; ++i) {
      elist[i << 1].next = Undefined;
      elist[i << 1 | 1].next = Undefined;
    }
    for (int i = 0; i < n; ++i) {
      nodes[i].head = Undefined;
      nodes[i].level = Undefined;
    }
    buffer_queue<int> que;
    que.push(s);
    nodes[s].level = 0;
    while (!que.empty()) {
      const int u = que.front();
      que.pop();
      for (int e = nodes[u].start; e < nodes[u + 1].start; ++e) {
        const int id = elist[e].id;
        const auto& [_, v, cap, flow] = edges_[id];
        if (flow == cap) { continue; }
        if (nodes[v].level == Undefined) {
          nodes[v].level = nodes[u].level + 1;
          que.push(v);
        }
        if (nodes[u].level < nodes[v].level) {
          elist[e].next = nodes[u].head;
          nodes[u].head = e;
        }
      }
    }
    return nodes[t].level != Undefined;
  }
  Flow push_flow(int u, int t, Flow flow_to_push,
                 const std::vector<flow_edge_map>& elist,
                 std::vector<flow_node_map>& nodes) {
    if (u == t) { return flow_to_push; }
    Flow pushed_flow = 0;
    int& e = nodes[u].head;
    while (e != Undefined && flow_to_push > 0) {
      const int id = elist[e].id;
      const int v = edges_[id].v;
      const Flow next_flow =
          std::min(flow_to_push, edges_[id].cap - edges_[id].flow);
      const Flow improved = push_flow(v, t, next_flow, elist, nodes);
      if (improved != 0) {
        edges_[id].flow += improved;
        edges_[id ^ 1].flow -= improved;
        pushed_flow += improved;
        flow_to_push -= improved;
      }
      if (edges_[id].flow == edges_[id].cap || flow_to_push > 0) {
        e = elist[e].next;
      }
    }
    return pushed_flow;
  }
  int num_nodes_;
  std::vector<edge_type> edges_;
};
}
namespace algo {
template <detail::arithmetic Flow>
class circulation {
  struct flow_edge {
    int u;
    int v;
    Flow low;
    Flow cap;
  };
public:
  using edge_type = flow_edge;
  using solver_type = maximum_flow<Flow>;
  circulation() = default;
  explicit circulation(int n) : num_nodes_(n), supply_(n), flow_{}, edges_{} {}
  int add_edge(int u, int v, Flow low, Flow cap) {
    assert(0 <= u && u < num_nodes());
    assert(0 <= v && v < num_nodes());
    assert(0 <= low && low <= cap);
    const int id = num_arcs();
    flow_.emplace_back(0);
    edges_.emplace_back(u, v, low, cap);
    return id;
  }
  void set_lower(int e, Flow new_low) {
    assert(0 <= e && e < num_arcs());
    assert(0 <= new_low && get_capacity(e));
    edges_[e].low = new_low;
  }
  void set_capacity(int e, Flow new_cap) {
    assert(0 <= e && e < num_arcs());
    assert(0 <= new_cap && get_lower(e) <= new_cap);
    edges_[e].cap = new_cap;
  }
  void set_supply(int u, Flow new_supply) {
    assert(0 <= u && u < num_nodes());
    supply_[u] = new_supply;
  }
  void set_demand(int u, Flow new_demand) {
    assert(0 <= u && u < num_nodes());
    supply_[u] = -new_demand;
  }
  void add_demand(int u, Flow d) {
    assert(0 <= u && u < num_nodes());
    supply_[u] -= d;
  }
  void add_supply(int u, Flow d) {
    assert(0 <= u && u < num_nodes());
    supply_[u] += d;
  }
  Flow get_lower(int e) const {
    assert(0 <= e && e < num_arcs());
    return edges_[e].low;
  }
  Flow get_capacity(int e) const {
    assert(0 <= e && e < num_arcs());
    return edges_[e].cap;
  }
  Flow get_flow(int e) const {
    assert(0 <= e && e < num_arcs());
    return flow_[e];
  }
  Flow get_supply(int u) const {
    assert(0 <= u && u < num_nodes());
    return supply_[u];
  }
  Flow get_demand(int u) const {
    assert(0 <= u && u < num_nodes());
    return -get_supply(u);
  }
  std::optional<Flow> feasible_circulation() {
    const int s_dummy = num_nodes();
    const int t_dummy = num_nodes() + 1;
    solver_type mf_net(t_dummy + 1);
    std::vector<Flow> excess = supply_;
    Flow total_supply = 0;
    Flow total_demand = 0;
    for (const auto& [u, v, low, cap] : edges_) {
      excess[u] -= low;
      excess[v] += low;
      mf_net.add_edge(u, v, cap - low);
    }
    for (int u = 0; u < num_nodes(); ++u) {
      if (excess[u] > 0) {
        mf_net.add_edge(s_dummy, u, excess[u]);
        total_supply += excess[u];
      } else if (excess[u] < 0) {
        mf_net.add_edge(u, t_dummy, -excess[u]);
        total_demand += -excess[u];
      }
    }
    const Flow flow = mf_net.max_flow(s_dummy, t_dummy);
    if (flow != total_supply || flow != total_demand) { return std::nullopt; }
    for (int e = 0; e < num_arcs(); ++e) { flow_[e] = mf_net.get_flow(e); }
    return flow;
  }
  int num_nodes() const { return static_cast<int>(supply_.size()); }
  int num_arcs() const { return static_cast<int>(edges_.size()); }
private:
  int num_nodes_;
  std::vector<Flow> supply_;
  std::vector<Flow> flow_;
  std::vector<edge_type> edges_;
};
}
#define PRINT(...) (void)0
#define DEBUG(x) (void)0
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
  std::span<const arc_type, std::dynamic_extent> operator[](
      int u) const noexcept {
    assert(0 <= u && u < num_nodes());
    return {elist_.cbegin() + start_[u], elist_.cbegin() + start_[u + 1]};
  }
  std::span<arc_type, std::dynamic_extent> operator[](int u) noexcept {
    assert(0 <= u && u < num_nodes());
    return {elist_.begin() + start_[u], elist_.begin() + start_[u + 1]};
  }
  auto neighbors(int u) const { return std::views::keys(operator[](u)); }
  int degree(int u) const {
    assert(0 <= u && u < num_nodes());
    return start_[u + 1] - start_[u];
  }
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
  std::span<const arc_type, std::dynamic_extent> operator[](
      int u) const noexcept {
    assert(0 <= u && u < num_nodes());
    return {elist_.cbegin() + start_[u], elist_.cbegin() + start_[u + 1]};
  }
  std::span<arc_type, std::dynamic_extent> operator[](int u) noexcept {
    assert(0 <= u && u < num_nodes());
    return {elist_.begin() + start_[u], elist_.begin() + start_[u + 1]};
  }
  auto neighbors(int u) const { return operator[](u); }
  int degree(int u) const {
    assert(0 <= u && u < num_nodes());
    return start_[u + 1] - start_[u];
  }
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
std::vector<int>
toposort(const adjacency_list<Weight>& adj) {
  std::vector<uint_fast8_t> vis(adj.num_nodes());
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
std::vector<std::pair<int, int>>
preorder(const adjacency_list<Weight>& adj, int root = 0) {
  std::vector<std::pair<int, int>> res(adj.num_nodes());
  int time = 0;
  const auto dfs = [&](auto dfs, int u, int p) -> void {
    res[u].first = time++;
    for (const int v : adj.neighbors(u)) {
      if (v == p) { continue; }
      dfs(dfs, v, u);
    }
    res[u].second = time;
  };
  dfs(dfs, root, root);
  return res;
}
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
void
solve() noexcept {
  int n, m;
  cin >> n >> m;
  vector<int> sn(n);
  vector<int> an(n);
  for (int i = 0; i < n; ++i) { cin >> sn[i]; }
  for (int i = 0; i < n; ++i) { cin >> an[i]; }
  vector<algo::edge<>> es(m);
  vector<int> deg(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    es[i] = {u, v};
    deg[u]--, deg[v]--;
  }
  int tot = 0;
  for (int i = 0; i < n; ++i) {
    if (sn[i]) {
      if (deg[i] > an[i] || (an[i] - deg[i]) % 2) {
        cout << "NO\n";
        return;
      } else {
        an[i] = (an[i] - deg[i]) / 2;
        tot += an[i];
      }
    }
  }
  if (tot > m) {
    cout << "NO\n";
    return;
  }
  algo::circulation<int> net(n + m + 2);
  vector<algo::edge<>> en(m);
  for (int i = 0; i < m; ++i) {
    auto [u, v] = es[i];
    net.add_edge(n + m, i, 0, 1);
    int a = net.add_edge(i, m + u, 0, 1);
    int b = net.add_edge(i, m + v, 0, 1);
    en[i] = {a, b};
  }
  for (int i = 0; i < n; ++i) {
    if (sn[i]) {
      net.add_edge(m + i, n + m + 1, an[i], an[i]);
    } else {
      net.add_edge(m + i, n + m + 1, 0, m);
    }
  }
  net.add_supply(n + m, m);
  net.add_demand(n + m + 1, m);
  auto f = net.feasible_circulation();
  if (!f) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (int i = 0; i < m; ++i) {
    auto [x, y] = en[i];
    auto [u, v] = es[i];
    if (net.get_flow(x)) {
      cout << v + 1 << ' ' << u + 1 << '\n';
    } else {
      cout << u + 1 << ' ' << v + 1 << '\n';
    }
  }
}
int
main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();
  return 0;
}
