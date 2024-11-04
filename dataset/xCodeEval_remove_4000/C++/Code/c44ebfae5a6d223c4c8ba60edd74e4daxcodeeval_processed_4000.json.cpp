













template <class T, class U>
constexpr bool chmin(T &lhs, const U &rhs) {
  if (lhs > rhs) { lhs = rhs; return true; }
  return false;
}

template <class T, class U>
constexpr bool chmax(T &lhs, const U &rhs) {
  if (lhs < rhs) { lhs = rhs; return true; }
  return false;
}






class range {
public:
  class iterator {
  private:
    int64_t M_position;

  public:
    constexpr iterator(int64_t position) noexcept: M_position(position) { }
    constexpr void operator ++ () noexcept { ++M_position; }
    constexpr bool operator != (iterator other) const noexcept { return M_position != other.M_position; }
    constexpr int64_t operator * () const noexcept { return M_position; }

  };

  class reverse_iterator {
  private:
    int64_t M_position;
  
  public:
    constexpr reverse_iterator(int64_t position) noexcept: M_position(position) { }
    constexpr void operator ++ () noexcept { --M_position; }
    constexpr bool operator != (reverse_iterator other) const noexcept { return M_position != other.M_position; }
    constexpr int64_t operator * () const noexcept { return M_position; }

  };
  
private:
  const iterator M_first, M_last;

public:
  constexpr range(int64_t first, int64_t last) noexcept: M_first(first), M_last(std::max(first, last)) { }
  constexpr iterator begin() const noexcept { return M_first; }
  constexpr iterator end() const noexcept { return M_last; }
  constexpr reverse_iterator rbegin() const noexcept { return reverse_iterator(*M_last - 1); } 
  constexpr reverse_iterator rend() const noexcept { return reverse_iterator(*M_first - 1); } 

};








template <class T>
class rev_impl {
public:
  using iterator = decltype(std::rbegin(std::declval<T>()));

private:
  const iterator M_begin;
  const iterator M_end;

public:
  constexpr rev_impl(T &&cont) noexcept: M_begin(std::rbegin(cont)), M_end(std::rend(cont)) { }
  constexpr iterator begin() const noexcept { return M_begin; }
  constexpr iterator end() const noexcept { return M_end; }

};

template <class T>
constexpr decltype(auto) rev(T &&cont) {
  return rev_impl<T>(std::forward<T>(cont));
}









template <class Edge>
class network {
public:
  using vertex_type = typename Edge::vertex_type;
  using edge_type   = Edge;
  using size_type   = size_t;

  class index_helper {
  private:
    const size_type M_stuff, M_size;
  public:
    explicit index_helper(const size_type stuff, const size_type size): 
      M_stuff(stuff), M_size(size) 
    { }
    vertex_type operator [] (const size_type index) const {
      return to_vertex(index);
    }
    vertex_type to_vertex(const size_type index) const {
      return index + M_stuff;
    }
    size_type to_index(const vertex_type vert) const {
      return vert - M_stuff;
    }
    size_type size() const {
      return M_size;
    }
  };

protected:
  std::vector<std::vector<edge_type>> M_graph;

public:
  network() = default;

  template <bool ReturnsIndex = true>
  typename std::enable_if<ReturnsIndex, vertex_type>::type add_vertex() {
    vertex_type res = M_graph.size();
    M_graph.push_back({ });
    return res;
  }
  template <bool ReturnsIndex = true>
  typename std::enable_if<!ReturnsIndex, void>::type add_vertex() {
    M_graph.push_back({ });
  }

  template <bool ReturnsIndices = true>
  typename std::enable_if<ReturnsIndices, index_helper>::type 
  add_vertices(const size_type size) {
    size_type cur = M_graph.size();
    M_graph.resize(cur + size);
    return index_helper(cur, size);
  }
  template <bool ReturnsIndices = true>
  typename std::enable_if<!ReturnsIndices, void>::type 
  add_vertices(const size_type size) {
    size_type cur = M_graph.size();
    M_graph.resize(cur + size);
  }
  
  void add_edge(const edge_type &edge) {
    M_graph[edge.source].push_back(edge);
  }
  template <class... Args>
  void id3(const vertex_type src, Args&&... args) {
    M_graph[src].emplace_back(src, std::forward<Args>(args)...);
  }

  std::vector<edge_type> &operator [] (const vertex_type vert) {
    return M_graph[vert];
  }
  const std::vector<edge_type> &operator [] (const vertex_type vert) const {
    return M_graph[vert];
  }

  size_type size() const {
    return M_graph.size();
  }
  bool empty() const {
    return M_graph.empty();
  }
  void clear() {
    M_graph.clear();
    M_graph.shrink_to_fit();
  }

};

class base_edge {
public:
  using vertex_type = uint32_t;
  const vertex_type source, dest;
  explicit base_edge(const vertex_type source, const vertex_type dest): 
    source(source), dest(dest) 
  { }
  base_edge reverse() {
    return base_edge(dest, source);
  }
};

template <class Flow>
class flow_edge: public base_edge {
public:
  using vertex_type = typename base_edge::vertex_type;
  using flow_type   = Flow;
  flow_type flow;
  const flow_type capacity;
  explicit flow_edge(const base_edge &edge, const flow_type capacity):
    base_edge(edge), flow(0), capacity(capacity)
  { }
  explicit flow_edge(const base_edge &edge, const flow_type flow, const flow_type capacity):
    base_edge(edge), flow(flow), capacity(capacity)
  { }
  explicit flow_edge(const vertex_type source, const vertex_type dest, const flow_type capacity):
    base_edge(source, dest), flow(0), capacity(capacity)
  { }
  explicit flow_edge(const vertex_type source, const vertex_type dest, const flow_type flow, const flow_type capacity):
    base_edge(source, dest), flow(flow), capacity(capacity)
  { }
  flow_edge reverse() const {
    return flow_edge(static_cast<base_edge>(*this).reverse(), capacity - flow, capacity);
  }
};

template <class Flow, class Cost>
class id0: public flow_edge<Flow> {
public:
  using vertex_type = typename flow_edge<Flow>::vertex_type;
  using flow_type   = typename flow_edge<Flow>::flow_type;
  using cost_type   = Cost;
  const cost_type cost;
  explicit id0(const flow_edge<Flow> &edge, const cost_type cost):
    flow_edge<Flow>(edge), cost(cost)
  { }
  explicit id0(const vertex_type source, const vertex_type dest, const flow_type capacity, const cost_type cost):
    flow_edge<Flow>(source, dest, capacity), cost(cost)
  { }
  explicit id0(const vertex_type source, const vertex_type dest, const flow_type flow, const flow_type capacity, const cost_type cost):
    flow_edge<Flow>(source, dest, flow, capacity), cost(cost)
  { }
  id0 reverse() const {
    return id0(static_cast<flow_edge<Flow>>(*this).reverse(), -cost);
  }
};









class stack_impl {
private:
  const size_t M_size;
  std::vector<size_t> M_stack;
public:
  explicit stack_impl(const size_t size):
    M_size(size), M_stack(size * 2)
  { clear(); }
  size_t top(const size_t height) const {
    return M_stack[M_size + height];
  }
  bool empty(const size_t height) const { 
    return M_stack[M_size + height] == M_size + height; 
  }
  void pop(const size_t height) {
    M_stack[M_size + height] = M_stack[M_stack[M_size + height]];
  }
  void push(const size_t height, const size_t node) {
    M_stack[node] = M_stack[M_size + height];
    M_stack[M_size + height] = node;
  }
  void clear() {
    std::iota(M_stack.begin() + M_size, M_stack.end(), M_size);
  }
};

class list_impl {
private:
  const size_t M_size;
  std::vector<std::pair<size_t, size_t>> M_list;
public:
  explicit list_impl(const size_t size):
    M_size(size), M_list(size * 2)
  { clear(); }
  bool empty(const size_t height) {
    return M_list[M_size + height].second == M_size + height;
  }
  bool more_than_one(const size_t height) {
    return M_list[M_size + height].first != M_list[M_size + height].second;
  }
  void insert(const size_t height, const size_t node) {
    M_list[node].first = M_list[M_size + height].first;
    M_list[node].second = M_size + height;
    M_list[M_list[M_size + height].first].second = node;
    M_list[M_size + height].first = node;
  }
  void erase(const size_t node) {
    M_list[M_list[node].first].second = M_list[node].second;
    M_list[M_list[node].second].first = M_list[node].first;
  }
  void clear() {
    for (size_t index = M_size; index < M_size * 2; ++index) {
      M_list[index].first = M_list[index].second = index;
    }
  }
  void clear(const size_t height) {
    const size_t index = M_size + height;
    M_list[index].first = M_list[index].second = index;
  }
  template <class Func>
  void apply_all(const size_t height, Func &&func) {
    size_t index = M_list[M_size + height].second;
    while (index < M_size) {
      func(index);
      index = M_list[index].second;
    }
  }
};

template <class Network>
class id1 {
public:
  using network_type = Network;
  using vertex_type  = typename Network::vertex_type;
  using edge_type    = typename Network::edge_type;
  using size_type    = typename Network::size_type;
  using flow_type    = typename Network::edge_type::flow_type;
  using height_type  = uint32_t;

  static_assert(std::is_integral<flow_type>::value, "invalid flow type :: non-integral");

private:
  class id2: public edge_type {
  public:
    const size_type rev;
    const bool is_rev;
    explicit id2(const edge_type &edge, const size_type rev, const bool is_rev):
      edge_type(edge), rev(rev), is_rev(is_rev)
    { }
  };

  class node_type {
  public:
    std::vector<id2> edges;
    flow_type excess;
    height_type height;
    size_type iter;
    node_type() = default;
  };

  flow_type M_remain(const id2 &edge) {
    return edge.capacity - edge.flow;
  }
  id2 &M_cur_edge(node_type &node) {
    return node.edges[node.iter];
  }
  id2 &M_rev_edge(const id2 &edge) {
    return M_graph[edge.dest].edges[edge.rev];
  }

  void M_push(node_type &node, id2 &edge) {
    const auto flow = std::min(node.excess, M_remain(edge));
    edge.flow += flow;
    node.excess -= flow;
    M_rev_edge(edge).flow -= flow;
    M_graph[edge.dest].excess += flow;
  }
  void M_relabel(node_type &node) {
    height_type min = M_graph.size() + 1;
    for (const auto &edge: node.edges) {
      if (M_remain(edge) > 0 && min > M_graph[edge.dest].height + 1) {
        min = M_graph[edge.dest].height + 1;
      }
    }
    node.height = min;
  }

  void M_reverse_bfs(const vertex_type source) {
    for (auto &node: M_graph) {
      node.height = M_graph.size() + 1;
    }
    M_graph[source].height = 0;
    std::queue<vertex_type> queue;
    queue.push(source);
    while (!queue.empty()) {
      const auto vert = queue.front();
      queue.pop();
      for (const auto &edge: M_graph[vert].edges) {
        if (M_remain(M_rev_edge(edge)) > 0) {
          if (M_graph[edge.dest].height == M_graph.size() + 1) {
            M_graph[edge.dest].height = M_graph[vert].height + 1;
            queue.push(edge.dest);
          }
        }
      }
    }
  }

  std::vector<node_type> M_graph;

public:
  id1() = default;
  explicit id1(const network_type &net) {
    M_graph.resize(net.size());
    for (size_type src = 0; src < net.size(); ++src) {
      for (const auto &edge: net[src]) {
        M_graph[src].edges.emplace_back(edge, M_graph[edge.dest].edges.size(), false);
        M_graph[edge.dest].edges.emplace_back(edge.reverse(), M_graph[src].edges.size() - 1, true);
      }
    }
  }

  template <bool ValueOnly = true>
  typename std::enable_if<ValueOnly, flow_type>::type
  max_flow(const vertex_type source, const vertex_type sink, const bool initialize_edges = false) {
    stack_impl active(M_graph.size());
    list_impl level(M_graph.size());
    height_type min_gap, max_active;
    for (auto &node: M_graph) {
      node.excess = 0;
      node.iter = 0;
      for (auto &edge: node.edges) {
        if (initialize_edges) {
          if (!edge.is_rev) edge.flow = 0;
          else edge.flow = edge.capacity;
        }
      }
    }
    M_reverse_bfs(sink);
    if (M_graph[source].height == M_graph.size() + 1) {
      return 0;
    }
    for (auto &edge: M_graph[source].edges) {
      M_graph[source].excess += M_remain(edge);
      M_push(M_graph[source], edge);
    }
    M_graph[source].height = M_graph.size();
    min_gap = M_graph.size();
    max_active = 0;
    for (size_type index = 0; index < M_graph.size(); ++index) {
      const auto &node = M_graph[index];
      if (node.height < M_graph.size()) {
        if (node.excess > 0 && index != sink) {
          active.push(node.height, index);
          max_active = std::max(max_active, node.height);
        }
        level.insert(node.height, index);
      }
    }
    for (size_type index = 0; index < M_graph.size(); ++index) {
      if (level.empty(index)) {
        min_gap = index;
        break;
      }
    }
    while (max_active > 0) {
      if (active.empty(max_active)) {
        --max_active;
        continue;
      }
      const auto vert = active.top(max_active);
      auto &node = M_graph[vert];
      active.pop(max_active);
      while (true) {
        auto &edge = M_cur_edge(node);
        const auto &dest = M_graph[edge.dest];
        if (M_remain(edge) > 0 && node.height == dest.height + 1) {
          if (dest.excess == 0 && edge.dest != sink) {
            active.push(dest.height, edge.dest);
            max_active = std::max(max_active, dest.height);
          }
          M_push(node, edge);
          if (node.excess == 0) {
            break;
          }
        }
        node.iter++;
        if (node.iter == node.edges.size()) {
          node.iter = 0;
          if (level.more_than_one(node.height)) {
            level.erase(vert);
            M_relabel(node);
            if (node.height > min_gap) {
              node.height = M_graph.size() + 1;
              break;
            }
            if (node.height == min_gap) {
              min_gap++;
            }
            level.insert(node.height, vert);
          }
          else {
            const height_type old_gap = min_gap;
            min_gap = node.height;
            for (height_type index = node.height; index < old_gap; ++index) {
              level.apply_all(index, [&](const vertex_type vert) {
                M_graph[vert].height = M_graph.size() + 1;
              });
              level.clear(index);
            }
            break;
          }
        }
      }
      max_active = std::min(max_active, min_gap - 1);
    }
    return M_graph[sink].excess;
  }

  template <bool ValueOnly = true>
  typename std::enable_if<!ValueOnly, std::pair<flow_type, network_type>>::type
  max_flow(const vertex_type source, const vertex_type sink, const bool initialize_edges = false) {
    const auto flow = max_flow<true>(source, sink, initialize_edges);
    std::queue<vertex_type> active;
    M_reverse_bfs(source);
    for (vertex_type index = 0; index < M_graph.size(); ++index) {
      const auto &node = M_graph[index];
      if (node.excess > 0 && node.height < M_graph.size() && index != sink) {
        active.push(index);
      }
    }
    while (!active.empty()) {
      auto &node = M_graph[active.front()];
      active.pop();
      while (node.excess > 0) {
        auto &edge = M_cur_edge(node);
        const auto &dest = M_graph[edge.dest];
        if (M_remain(edge) > 0 && node.height == dest.height + 1) {
          if (dest.excess == 0 && edge.dest != source) {
            active.push(edge.dest);
          }
          M_push(node, edge);
          if (node.excess == 0) {
            break;
          }
        }
        node.iter++;
        if (node.iter == node.edges.size()) {
          node.iter = 0;
          M_relabel(node);
        }
      }
    }
    network_type graph;
    graph.template add_vertices <false>(M_graph.size());
    for (size_type index = 0; index < M_graph.size(); ++index) {
      for (const auto &edge: M_graph[index].edges) {
        if (!edge.is_rev) {
          graph.add_edge(static_cast<edge_type>(edge));
        }
      }
    }
    return std::make_pair(flow, std::move(graph));
  } 

};




using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

constexpr i32 inf32 = (i32(1) << 30) - 1;
constexpr i64 inf64 = (i64(1) << 62) - 1;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  i32 H, W;
  std::cin >> H >> W;
  std::vector<std::vector<bool>> wall(H, std::vector<bool>(W));
  i32 ans = 0;
  for (auto i: range(0, H)) {
    for (auto j: range(0, W)) {
      char c;
      std::cin >> c;
      if (c == '
        wall[i][j] = true;
        ++ans;
      }
    }
  }
  network<flow_edge<i32>> net;
  const auto grid = net.add_vertices(H * W);
  const auto src = net.add_vertex();
  const auto sink = net.add_vertex();
  for (auto i: range(0, H)) {
    for (auto j: range(0, W - 1)) {
      if (wall[i][j] && wall[i][j + 1]) {
        --ans;
        const auto n = net.add_vertex();
        net.id3(n, sink, 1);
        net.id3(grid[i * W + j], n, inf32);
        net.id3(grid[i * W + (j + 1)], n, inf32);
      }
    }
  }
  for (auto i: range(0, H - 1)) {
    for (auto j: range(0, W)) {
      if (wall[i][j] && wall[i + 1][j]) {
        --ans;
        const auto n = net.add_vertex();
        net.id3(src, n, 1);
        net.id3(n, grid[i * W + j], inf32);
        net.id3(n, grid[(i + 1) * W + j], inf32);
      }
    }
  }
  std::cout << ans + id1(net).max_flow(src, sink) << '\n';
  return 0;
}
