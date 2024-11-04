










template<class T>
class AnyMap {
  static int instance_count;
  const int id6;
  T default_value_;
 public:
  AnyMap(T default_value = T())
      : id6(instance_count++), default_value_(std::move(default_value)) {}
  template <class... Args>
  auto &operator()(Args &&...args) {
    using Tuple =
        decltype(std::make_tuple(id6, std::forward<Args>(args)...));
    static std::map<Tuple, T> map;
    auto [it, placed] = map.emplace(
        Tuple{id6, std::forward<Args>(args)...}, default_value_);
    return it->second;
  }
};
template<class T>
int AnyMap<T>::instance_count = 0;







  if (!(condition)) {                               \
    std::cerr << "Assertion (" << 
              << ") failed\non line " << __LINE__   \
              << " in " << __FILE__                 \
              << '
    std::cerr << message << '\n';                   \
    abort();                                        \
  }




  LOCAL_ASSERT(low <= variable && variable <= high, \
               
               << " is out of the range "           \
               << '[' << low << ", " << high << ']')










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
    static const u64 id8 = rng();
    return splitmix64(x + id8);
  }
};
template<class...Ts>
struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts>
overloaded(Ts...) -> overloaded<Ts...>;
template<class Fun>
class id7 {
	Fun fun_;
public:
	template<class T>
	explicit id7(T &&fun): fun_(std::forward<T>(fun)) {}
	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};
template<class Fun>
decltype(auto) id11(Fun &&fun) {
	return id7<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
struct {
  template<class T>
  operator T() {
    T x;
    std::cin >> x;
    return x;
  }
} in;





struct id2 {
  const std::vector<int> layer_sizes;
  const std::vector<int> layer_sizes_prefix_sum;
  template <class... Args>
  id2(Args &&...args)
      : layer_sizes{std::forward<Args>(args)...},
        layer_sizes_prefix_sum(get_prefix_sum(layer_sizes)) {}
  static std::vector<int> get_prefix_sum(const std::vector<int> &a) {
    std::vector<int> res(a.size() + 1);
    for (int i = 0; i < (int)a.size(); ++i) res[i + 1] = res[i] + a[i];
    return res;
  }
  
  int to_id(int layer_number, int id9) {
    LOCAL_ASSERT_IN_RANGE(layer_number, 0, (int)layer_sizes.size() - 1);
    LOCAL_ASSERT_IN_RANGE(id9, 0, layer_sizes[layer_number] - 1);
    return layer_sizes_prefix_sum[layer_number] + id9;
  }
  
  int to_id(int id9) { return to_id(0, id9); }
  std::array<int, 2> from_id(int id) {
    LOCAL_ASSERT_IN_RANGE(id, 0, layer_sizes_prefix_sum.back() - 1);
    auto it = std::upper_bound(layer_sizes_prefix_sum.begin(),
                               layer_sizes_prefix_sum.end(), id);
    LOCAL_ASSERT(it != layer_sizes_prefix_sum.begin(),
                 "oops, something is wrong with the internal binary search.");
    int layer_number = int(it - layer_sizes_prefix_sum.begin()) - 1;
    int id9 = id - layer_sizes_prefix_sum[layer_number];
    return {layer_number, id9};
  }
  auto get_edge_group_descriptor(int from_layer, int to_layer) {
    std::vector<int> from_list(layer_sizes[from_layer]);
    std::iota(from_list.begin(), from_list.end(),
              layer_sizes_prefix_sum[from_layer]);
    auto id4 =
        [begin = layer_sizes_prefix_sum[to_layer],
         end = layer_sizes_prefix_sum[to_layer + 1]](int index) {
          return begin <= index && index < end;
        };
    return std::make_pair(from_list, id4);
  }
};
struct id0 {
  AnyMap<int> mp;
  int next_node_id;
  id0() : mp(-1), next_node_id(0) {}
  template <class... Args>
  int to_id(Args &&...args) {
    int &v = mp(std::forward<Args>(args)...);
    if (v == -1) v = next_node_id++;
    return v;
  }
};
template <class FlowType = long long, class CapType = FlowType,
          bool shuffle = false,
          class NodeNameTranslator = id2>
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
  std::vector<std::tuple<int, int, CapType, CapType>> id10(int x,
                                                                       int y) {
    auto [from, is_to] = node_name_translator.get_edge_group_descriptor(x, y);
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
    id3 = source_id;
    id5 = sink_id;
    if constexpr (shuffle)
      for (auto &adj_list : graph)
        std::shuffle(adj_list.begin(), adj_list.end(), rng);
    FlowType ans = 0;
    FlowType to_add;
    while ((to_add = blocking_flow())) ans += to_add;
    return ans;
  }
 private:
  int id3, id5;
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
    while ((to_add = dfs(id3, std::numeric_limits<CapType>::max())))
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
    queue.push_back(id3);
    vis[id3] = 1;
    for (int qq = 0; qq < (int)queue.size(); ++qq) {
      int i = queue[qq];
      if (i == id5) break;
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
    vis[id5] = 0;
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
      int id1 = used_edge.back();
      used_edge.pop_back();
      int i = to[id1];
      bfs_graph[bfs_graph_start[i] + bfs_graph_outdegree[i]++] = id1 ^ 1;
    }
  }
  FlowType dfs(int current, CapType prefix_cap) {
    if (current == id5) return prefix_cap;
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



using namespace std;
using std::cout;  

using u32 = uint32_t;
using u64 = uint64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  vector<int> s(n), a(n);
  for (int &x : s) cin >> x;
  for (int &x : a) cin >> x;
  vector<array<int, 2>> es(m);
  for (auto &[i, j] : es) cin >> i >> j, --i, --j;

  for (auto [i, j] : es) {
    if (s[i] == 1) ++a[i];
    if (s[j] == 1) ++a[j];
  }

  for (int i = 0; i < n; ++i) {
    if (a[i] % 2 || a[i] < 0) {
      cout << "NO\n";
      return 0;
    }
    a[i] /= 2;
  }

  enum { S, T, SPRIME, TPRIME };
  enum { _, EDGE, VERTEX };
  Flow<u64, u64> f(4, m, n);

  f(T)(S) = ~u32(0);

  for (int e = 0; e < m; ++e) {
    f(S)(TPRIME) = 1;
    f(SPRIME)(EDGE, e) = 1;
  }

  for (int e = 0; e < m; ++e) {
    auto [i, j] = es[e];
    f(EDGE, e)(VERTEX, i) = 1;
    f(EDGE, e)(VERTEX, j) = 1;
  }

  for (int i = 0; i < n; ++i) {
    if (s[i] == 0) {
      f(VERTEX, i)(T) = ~u32(0);
    } else if (s[i] == 1) {
      f(SPRIME)(T) = a[i];
      f(VERTEX, i)(TPRIME) = a[i];
    } else {
      assert(0 && "invalid s[i]");
    }
  }

  u64 saturation = m + accumulate(a.begin(), a.end(), u64(0));

  if (saturation != f(SPRIME)(TPRIME).max_flow()) {
    cout << "NO\n";
    return 0;
  }

  cout << "YES\n";

  for (auto [e, i, fwd, bak] : f.id10(EDGE, VERTEX)) {
    if (fwd != 0) {
      e = f.node_name_translator.from_id(e)[1];
      i = f.node_name_translator.from_id(i)[1];
      cout << es[e][i == es[e][0]] + 1 << ' ' << i + 1 << '\n';
    }
  }
}
