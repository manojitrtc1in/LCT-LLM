
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>



#include <array>


#include <algorithm>
#include <array>


#include <map>
#include <tuple>
#include <utility>
template <class T>
class AnyMap {
  static int instance_count;
  const int instance_id_;
  T default_value_;
 public:
  AnyMap(T default_value = T())
      : instance_id_(instance_count++),
        default_value_(std::move(default_value)) {}
  template <class... Args>
  auto &operator()(Args &&...args) {
    using Tuple =
        decltype(std::make_tuple(instance_id_, std::forward<Args>(args)...));
    static std::map<Tuple, T> map;
    auto it = map.emplace(Tuple{instance_id_, std::forward<Args>(args)...},
                          default_value_)
                  .first;
    return it->second;
  }
};
template <class T>
int AnyMap<T>::instance_count = 0;


#include <limits>


#include <iostream>
#ifdef ENABLE_DEBUG
#define LOCAL_ASSERT(condition, message)            \
  if (!(condition)) {                               \
    std::cerr << "Assertion (" << #condition        \
              << ") failed\non line " << __LINE__   \
              << " in " << __FILE__                 \
              << '#' << __FUNCTION__ << "()\n";     \
    std::cerr << message << '\n';                   \
    abort();                                        \
  }
#else
#define LOCAL_ASSERT(...) do {} while (0);
#endif
#define LOCAL_ASSERT_IN_RANGE(variable, low, high)  \
  LOCAL_ASSERT(low <= variable && variable <= high, \
               #variable << '=' << variable         \
               << " is out of the range "           \
               << '[' << low << ", " << high << ']')


#include <numeric>
#include <string>
#include <tuple>




#include <cstdint>
using i8 = int8_t;
using u8 = uint8_t;
using i16 = int16_t;
using u16 = uint16_t;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using i128 = __int128_t;
using u128 = __uint128_t;


#include <random>
#include <chrono>
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
struct r_hash {
  static u64 splitmix64(u64 x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  template<class T>
  u64 operator()(const T &x) const;
  u64 operator()(u64 x) const {
    static const u64 FIXED_RANDOM = rng();
    return splitmix64(x + FIXED_RANDOM);
  }
};
#if __cplusplus >= 201703L
template<class...Ts>
struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts>
overloaded(Ts...) -> overloaded<Ts...>;
#endif
template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
struct {
  template<class T>
  operator T() {
    T x;
    std::cin >> x;
    return x;
  }
} in;


#include <vector>


struct LayeredNodeNameTranslator {
  const std::vector<int> layer_sizes;
  const std::vector<int> layer_sizes_prefix_sum;
  template <class... Args>
  LayeredNodeNameTranslator(Args &&...args)
      : layer_sizes{std::forward<Args>(args)...},
        layer_sizes_prefix_sum(get_prefix_sum(layer_sizes)) {}
  static std::vector<int> get_prefix_sum(const std::vector<int> &a) {
    std::vector<int> res(a.size() + 1);
    for (int i = 0; i < (int)a.size(); ++i) res[i + 1] = res[i] + a[i];
    return res;
  }
  
  int to_id(int layer_number, int index_in_layer) {
    LOCAL_ASSERT_IN_RANGE(layer_number, 0, (int)layer_sizes.size() - 1);
    LOCAL_ASSERT_IN_RANGE(index_in_layer, 0, layer_sizes[layer_number] - 1);
    return layer_sizes_prefix_sum[layer_number] + index_in_layer;
  }
  
  int to_id(int index_in_layer) { return to_id(0, index_in_layer); }
  std::array<int, 2> from_id(int id) {
    LOCAL_ASSERT_IN_RANGE(id, 0, layer_sizes_prefix_sum.back() - 1);
    auto it = std::upper_bound(layer_sizes_prefix_sum.begin(),
                               layer_sizes_prefix_sum.end(), id);
    LOCAL_ASSERT(it != layer_sizes_prefix_sum.begin(),
                 "oops, something is wrong with the internal binary search.");
    int layer_number = int(it - layer_sizes_prefix_sum.begin()) - 1;
    int index_in_layer = id - layer_sizes_prefix_sum[layer_number];
    return {layer_number, index_in_layer};
  }
  auto get_edge_group_descriptor(int from_layer, int to_layer) {
    std::vector<int> from_list(layer_sizes[from_layer]);
    std::iota(from_list.begin(), from_list.end(),
              layer_sizes_prefix_sum[from_layer]);
    auto is_in_to_layer =
        [begin = layer_sizes_prefix_sum[to_layer],
         end = layer_sizes_prefix_sum[to_layer + 1]](int index) {
          return begin <= index && index < end;
        };
    return std::make_pair(from_list, is_in_to_layer);
  }
};
struct AnyNodeNameTranslator {
  AnyMap<int> mp;
  int next_node_id;
  AnyNodeNameTranslator() : mp(-1), next_node_id(0) {}
  template <class... Args>
  int to_id(Args &&...args) {
    int &v = mp(std::forward<Args>(args)...);
    if (v == -1) v = next_node_id++;
    return v;
  }
};
template <class FlowType = long long, class CapType = FlowType,
          bool shuffle = false,
          class NodeNameTranslator = LayeredNodeNameTranslator>
class Flow {
  struct EdgeReference {
    Flow &flow;
    int i, j;
    void operator=(CapType w) { flow.make_edge(i, j, w); }
    FlowType max_flow() { return flow.max_flow(i, j); }
  };
  struct NodeReference {
    Flow &flow;
    int i;
    template <class... Args>
    EdgeReference operator()(Args &&...args) {
      return {flow, i,
              flow.node_name_translator.to_id(std::forward<Args>(args)...)};
    }
  };
 public:
  NodeNameTranslator node_name_translator;
  template <class... Args>
  Flow(Args &&...args) : node_name_translator(std::forward<Args>(args)...) {}
  std::vector<int> to;
  std::vector<CapType> cap;
  std::vector<std::basic_string<int>> graph;
  std::vector<int> bfs_graph, bfs_graph_outdegree, bfs_graph_start, queue,
      used_edge;
  std::vector<int> vis, dist;
  template <class... Args>
  NodeReference operator()(Args &&...args) {
    return NodeReference{
        *this, node_name_translator.to_id(std::forward<Args>(args)...)};
  }
  template <class... Args>
  std::vector<std::tuple<int, int, CapType, CapType>> get_edge_group(int x,
                                                                     int y) {
    auto group_descriptor =
        node_name_translator.get_edge_group_descriptor(x, y);
    auto &from = group_descriptor.first;
    auto &is_to = group_descriptor.second;
    std::vector<std::tuple<int, int, CapType, CapType>> res;
    for (int i : from) {
      for (int eid : graph[i]) {
        int j = to[eid];
        if (!is_to(j)) continue;
        CapType current_flow = cap[eid ^ 1];
        CapType capacity = cap[eid] + current_flow;
        res.emplace_back(i, j, current_flow, capacity);
      }
    }
    return res;
  }
  
  void make_edge(int from_id, int to_id, CapType weight) {
    LOCAL_ASSERT(from_id != to_id, "Self-loops are not supported.")
    expand_graph(std::max(from_id, to_id) + 1);
    graph[from_id].push_back(cap.size());
    to.emplace_back(to_id);
    cap.push_back(weight);
    graph[to_id].push_back(cap.size());
    to.push_back(from_id);
    cap.push_back(0);
  }
  
  FlowType max_flow(int source_id, int sink_id) {
    expand_graph(std::max(source_id, sink_id) + 1);
    source_id_ = source_id;
    sink_id_ = sink_id;
    if constexpr (shuffle)
      for (auto &adj_list : graph)
        std::shuffle(adj_list.begin(), adj_list.end(), rng);
    FlowType ans = 0;
    FlowType to_add;
    while ((to_add = blocking_flow())) ans += to_add;
    return ans;
  }
 private:
  int source_id_, sink_id_;
  void expand_graph(int new_size) {
    while ((int)graph.size() < new_size) {
      graph.emplace_back();
      bfs_graph_outdegree.emplace_back();
      bfs_graph_start.emplace_back();
      vis.emplace_back();
      dist.emplace_back();
    }
  }
  
  FlowType blocking_flow() {
    init_bfs_graph();
    FlowType ans = 0;
    FlowType to_add;
    while ((to_add = dfs(source_id_, std::numeric_limits<CapType>::max())))
      ans += to_add;
    return ans;
  }
  void init_bfs_graph() {
    reset_bfs_graph();
    forward_bfs();
    backward_bfs();
    load_edges();
  }
  void reset_bfs_graph() {
    for (int i : queue) {
      vis[i] = 0;
      dist[i] = 0;
      bfs_graph_outdegree[i] = 0;
    }
    queue.clear();
  }
  void forward_bfs() {
    queue.push_back(source_id_);
    vis[source_id_] = 1;
    for (int qq = 0; qq < (int)queue.size(); ++qq) {
      int i = queue[qq];
      if (i == sink_id_) break;
      for (int eid : graph[i]) {
        if (!cap[eid]) continue;
        int j = to[eid];
        if (vis[j]) continue;
        vis[j] = 1;
        dist[j] = dist[i] + 1;
        queue.push_back(j);
      }
    }
  }
  void backward_bfs() {
    vis[sink_id_] = 0;
    bfs_graph_start[queue.back()] = 0;
    for (int qq = (int)queue.size() - 1; qq >= 0; --qq) {
      int j = queue[qq];
      if (qq + 1 < (int)queue.size()) {
        int nxt = queue[qq + 1];
        bfs_graph_start[j] = bfs_graph_start[nxt] + bfs_graph_outdegree[nxt];
        bfs_graph_outdegree[nxt] = 0;
      }
      if (vis[j]) continue;
      for (int eid : graph[j]) {
        if (!cap[eid ^ 1]) continue;
        int i = to[eid];
        if (dist[i] + 1 != dist[j]) continue;
        vis[i] = 0;
        ++bfs_graph_outdegree[i];
        used_edge.push_back(eid);
      }
    }
  }
  void load_edges() {
    bfs_graph.resize(bfs_graph_start[queue.front()] +
                     bfs_graph_outdegree[queue.front()]);
    bfs_graph_outdegree[queue.front()] = 0;
    while (used_edge.size()) {
      int rev_eid = used_edge.back();
      used_edge.pop_back();
      int i = to[rev_eid];
      bfs_graph[bfs_graph_start[i] + bfs_graph_outdegree[i]++] = rev_eid ^ 1;
    }
  }
  FlowType dfs(int current, CapType prefix_cap) {
    if (current == sink_id_) return prefix_cap;
    while (bfs_graph_outdegree[current]) {
      int eid = bfs_graph[bfs_graph_start[current] +
                          bfs_graph_outdegree[current] - 1];
      int next = to[eid];
      if (vis[next]) {
        --bfs_graph_outdegree[current];
        continue;
      }
      if (!cap[eid]) {
        --bfs_graph_outdegree[current];
        continue;
      }
      CapType here = dfs(next, std::min(prefix_cap, cap[eid]));
      if (!here) {
        --bfs_graph_outdegree[current];
        continue;
      }
      cap[eid] -= here;
      cap[eid ^ 1] += here;
      if (!cap[eid]) {
        if (!--bfs_graph_outdegree[current]) vis[current] = 1;
      }
      return here;
    }
    vis[current] = 1;
    return 0;
  }
};


#include <vector>

struct BipartiteMatcher {
  Flow<int> internal_flow;
  int n_l, n_r;
  BipartiteMatcher(int n_l, int n_r)
      : n_l(n_l), n_r(n_r), internal_flow(1, n_l, n_r, 1) {
    for (int i = 0; i < n_l; i++) internal_flow(0, 0)(1, i) = 1;
    for (int i = 0; i < n_r; i++) internal_flow(2, i)(3, 0) = 1;
  }
  BipartiteMatcher(int n) : BipartiteMatcher(n, n) {}
  void add_edge(int u, int v) { internal_flow(1, u)(2, v) = 1; }
  int compute_matching_size() { return internal_flow(0, 0)(3, 0).max_flow(); }
  std::vector<std::array<int, 2>> get_matching() {
    int matching_size = compute_matching_size();
    std::vector<std::array<int, 2>> matching(matching_size);
    auto it = matching.begin();
    for (const auto &pack : internal_flow.get_edge_group(1, 2)) {
      auto &u = std::get<0>(pack);
      auto &v = std::get<1>(pack);
      auto &flow = std::get<2>(pack);
      if (flow > 0) *(it++) = std::array<int, 2>({u, v});
    }
    for (auto &e : matching)
      for (auto &v : e) v = internal_flow.node_name_translator.from_id(v)[1];
    return matching;
  }
  std::vector<int> min_vertex_cover() {
    auto M = get_matching();
    std::vector<int> cover(M.size());
    std::vector<uint8_t> vis(n_l + n_r);
    for (auto &e : M) vis[e[0]] = 1;
    std::vector<std::vector<int>> g(n_l + n_r);
    for (auto &pack : internal_flow.get_edge_group(1, 2)) {
      auto &u = std::get<0>(pack);
      auto &v = std::get<1>(pack);
      auto &flow = std::get<2>(pack);
      if (flow)
        g[v + n_l].push_back(u);
      else
        g[u].push_back(v + n_l);
    }
    std::vector<int> queue;
    for (int i = 0; i < n_l; i++)
      if (vis[i]) queue.push_back(i);
    for (int qq = 0; qq < (int)queue.size(); ++qq) {
      int u = queue[qq];
      for (auto &v : g[u]) {
        if (vis[v]) continue;
        vis[v] = 1;
        queue.push_back(v);
      }
    }
    for (auto &pack : M) {
      auto &u = pack[0];
      auto &v = pack[0];
      if (vis[v])
        cover.push_back(v);
      else
        cover.push_back(u);
    }
    return cover;
  }
};



using std::array;
using std::cerr;
using std::cin;
using std::cout;
using std::map;
using std::max;
using std::min;
using std::set;
using std::sort;
using std::swap;
using std::unique;
using std::vector;
using __gnu_pbds::gp_hash_table;

template<>
u64 r_hash::operator()(const int &x) const {
  return (*this)(u64(x));
}

std::optional<std::tuple<int, int, vector<int>>> solve_given_distance(
    int d, const vector<int> &a, const vector<int> &b) {
  int n = (int)a.size();
  assert(n == (int)b.size());

  BipartiteMatcher bm(n, n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int x = a[i];
      int y = b[j];
      bool ok = false;
      ok |= +x == d + y;
      ok |= -x == d + y;
      ok |= +x == d - y;
      ok |= -x == d - y;
      if (ok) bm.add_edge(i, j);
    }
  }

  auto m = bm.get_matching();
  if ((int)m.size() != n) return std::nullopt;

  int pa = 0;
  int pb = d;
  vector<int> res;

  for (auto [i, j] : m) {
    int x = a[i];
    int y = b[j];
    if (x == d - y || x == d + y) {
      res.push_back(x);
    } else if (-x == d - y || -x == d + y) {
      res.push_back(-x);
    }
  }

  int mn = min(0, *min_element(res.begin(), res.end()));
  pa -= mn;
  pb -= mn;
  for (int &x : res) x -= mn;
  return std::make_tuple(pa, pb, res);
}

void show_ans(const std::tuple<int, int, vector<int>> &t) {
  cout << "Yes\n";
  auto [pa, pb, ans] = t;
  for (int x : ans) cout << x << ' ';
  cout << '\n';
  cout << pa << ' ' << pb << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    

    

    

    

    

    

    


    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    gp_hash_table<int, int, r_hash> cnt;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        ++cnt[a[i] + b[j]];
        ++cnt[abs(a[i] - b[j])];
      }
    }

    bool found = false;

    for (auto [diff, c] : cnt) {
      

      if (c >= n) {
        auto maybe_res = solve_given_distance(diff, a, b);
        if (maybe_res) {
          show_ans(*maybe_res);
          found = true;
          break;
        }
      }
    }

    if (!found) cout << "No\n";
  }
}
