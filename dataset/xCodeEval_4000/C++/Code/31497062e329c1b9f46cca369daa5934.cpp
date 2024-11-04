#include <algorithm>
#include <cassert>
#include <iostream>
#include <optional>
#include <queue>
#include <stack>
#include <string_view>
#include <vector>

using namespace std;

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::optional<T>& opt) {
  return opt ? os << *opt : os << "nullopt";
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) {
  return os << '{' << p.first << ", " << p.second << '}';
}

template <typename Container,
          std::enable_if_t<!std::is_convertible_v<Container, std::string_view>,
                           typename Container::const_iterator>* = nullptr>
std::ostream& operator<<(std::ostream& os, const Container& c) {
  os << '{';
  if (!c.empty()) {
    os << *c.begin();
    for (auto it = ++c.begin(); it != c.end(); ++it) {
      os << ", " << *it;
    }
  }
  return os << '}';
}

template <typename T, typename Container>
std::ostream& operator<<(std::ostream& os, std::stack<T, Container> s) {
  int n = (int)s.size();
  std::vector<T> v(n);
  for (int i = n - 1; i >= 0; --i) {
    v[i] = s.top();
    s.pop();
  }
  return os << v;
}

template <typename T, typename Container>
std::ostream& operator<<(std::ostream& os, std::queue<T, Container> q) {
  os << '{';
  if (!q.empty()) {
    os << q.front();
    q.pop();
    while (!q.empty()) {
      os << ", " << q.front();
      q.pop();
    }
  }
  return os << '}';
}

template <typename T, typename Container, typename Compare>
std::ostream& operator<<(std::ostream& os,
                         std::priority_queue<T, Container, Compare> pq) {
  os << '{';
  if (!pq.empty()) {
    os << pq.top();
    pq.pop();
    while (!pq.empty()) {
      os << ", " << pq.top();
      pq.pop();
    }
  }
  return os << '}';
}

namespace detail {

template <int I, typename... Ts>
void tuple_print(std::ostream& os, const std::tuple<Ts...>& t) {
  static_assert(0 <= I && I <= sizeof...(Ts));
  if constexpr (I != sizeof...(Ts)) {
    if constexpr (I != 0) {
      os << ", ";
    }
    os << std::get<I>(t);
    tuple_print<I + 1>(os, t);
  }
}

}  


template <typename... Ts>
std::ostream& operator<<(std::ostream& os, const std::tuple<Ts...>& t) {
  os << '{';
  detail::tuple_print<0>(os, t);
  return os << '}';
}

namespace detail {

template <typename T>
void debug_print(std::string_view key, const T& val) {
  std::cerr << key << " = " << val << std::endl;
}

template <typename T1, typename... Ts>
void debug_print(std::string_view keys, const T1& val1, const Ts&... vals) {
  for (int i = 0, paren = 0; i < (int)keys.size(); ++i) {
    if (keys[i] == '(' || keys[i] == '{') {
      ++paren;
    } else if (keys[i] == ')' || keys[i] == '}') {
      --paren;
    } else if (keys[i] == ',' && paren == 0) {
      std::cerr << keys.substr(0, i) << " = " << val1 << ',';
      return debug_print(keys.substr(i + 1), vals...);
    }
  }
}

void debug_print(int line, std::string_view) {
  std::cerr << "  " << line << " |" << std::endl;
}

template <typename... Ts>
void debug_print(int line, std::string_view keys, const Ts&... vals) {
  std::cerr << "  " << line << " | ";
  debug_print(keys, vals...);
}

}  


#ifdef TYLER
#define debug(...) \
  detail::debug_print(__LINE__, #__VA_ARGS__ __VA_OPT__(, ) __VA_ARGS__)
#else
#define debug(...) ((void)0)
#endif










































































































































































































































template <typename Flow, typename Cost>
class min_cost_flow {
 public:
  min_cost_flow(int n) : graph_(n) {}

  void add_edge(int from, int to, Flow cap, Cost cost) {
    graph_[from].emplace_back(to, (int)graph_[to].size(), cap, cost);
    graph_[to].emplace_back(from, (int)graph_[from].size() - 1, 0, -cost);
  }

  std::pair<Flow, Cost> solve(
      int source, int sink, Flow max_flow = std::numeric_limits<Flow>::max()) {
    static constexpr Cost INF_COST = std::numeric_limits<Cost>::max();
    for (std::vector<edge>& edges : graph_) {
      for (edge& e : edges) {
        e.flow = 0;
        e.cost = e.orig_cost;
      }
    }
    int n = (int)graph_.size();
    std::vector<Cost> dist(n, INF_COST);
    dist[source] = 0;
    std::vector<std::pair<int, edge*>> pred(n);
    std::queue<int> q;
    q.push(source);
    std::vector<bool> active(n, false);
    active[source] = true;
    while (!q.empty()) {  

      int u = q.front();
      q.pop();
      active[u] = false;
      for (edge& e : graph_[u]) {
        if (e.flow < e.cap && dist[u] + e.cost < dist[e.to]) {
          dist[e.to] = dist[u] + e.cost;
          pred[e.to] = {u, &e};
          if (!active[e.to]) {
            q.push(e.to);
            active[e.to] = true;
          }
        }
      }
    }
    constexpr auto comp = [](const std::pair<int, Cost>& lhs,
                             const std::pair<int, Cost>& rhs) -> bool {
      return lhs.second > rhs.second;
    };
    std::priority_queue<std::pair<int, Cost>, std::vector<std::pair<int, Cost>>,
                        decltype(comp)>
        pq(comp);
    Flow total_flow = 0;
    Cost total_cost = 0, curr_cost = 0;
    while (dist[sink] != INF_COST) {
      Flow delta = max_flow - total_flow;
      for (int v = sink; v != source;) {
        const auto& [u, e] = pred[v];
        delta = std::min(delta, e->cap - e->flow);
        v = u;
      }
      for (int v = sink; v != source;) {
        const auto& [u, e] = pred[v];
        e->flow += delta;
        graph_[v][e->rev].flow -= delta;
        v = u;
      }
      total_cost += delta * (curr_cost += dist[sink]);
      if ((total_flow += delta) == max_flow) {
        break;
      }
      for (int u = 0; u < n; ++u) {
        for (edge& e : graph_[u]) {
          e.cost += dist[u] - dist[e.to];
        }
      }
      std::fill(dist.begin(), dist.end(), INF_COST);
      dist[source] = 0;
      pq.emplace(source, 0);
      while (!pq.empty()) {  

        auto [u, d_u] = pq.top();
        pq.pop();
        if (d_u > dist[u]) {
          continue;
        }
        for (edge& e : graph_[u]) {
          if (e.flow < e.cap && dist[u] + e.cost < dist[e.to]) {
            pq.emplace(e.to, dist[e.to] = dist[u] + e.cost);
            pred[e.to] = {u, &e};
          }
        }
      }
    }
    return std::pair(total_flow, total_cost);
  }

 private:
  struct edge {
    int to, rev;
    Flow cap, flow;
    Cost orig_cost, cost;

    constexpr edge(int _to, int _rev, Flow _cap, Cost _cost)
        : to(_to), rev(_rev), cap(_cap), orig_cost(_cost) {}
  };

  std::vector<std::vector<edge>> graph_;
};






















































































































































































































































template <typename Cost>
std::pair<int, Cost> min_cost_assign(
    const std::vector<std::vector<Cost>>& costs) {
  int m = (int)costs.size(), n = (int)costs[0].size();
  int source = m + n, sink = m + n + 1;
  min_cost_flow<int, Cost> mc_flow(m + n + 2);
  for (int u = 0; u < m; ++u) {
    mc_flow.add_edge(source, u, 1, 0);
  }
  for (int v = 0; v < n; ++v) {
    mc_flow.add_edge(m + v, sink, 1, 0);
  }
  for (int u = 0; u < m; ++u) {
    for (int v = 0; v < n; ++v) {
      mc_flow.add_edge(u, m + v, 1, costs[u][v]);
    }
  }
  return mc_flow.solve(source, sink, std::min(m, n));
}

int N;
vector<long long> A, B, K;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N;
  A.resize(N);
  B.resize(N);
  K.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i] >> K[i];
  }
  vector<vector<long long>> costs(N, vector<long long>(N));
  for (int i = 0; i < N; i++) {
    for (long long position = 0; position < N; position++) {
      costs[i][position] = -(max(A[i] - min(K[i], position) * B[i], 0LL));
    }
  }
  cout << -min_cost_assign(costs).second << '\n';
  return 0;
}
