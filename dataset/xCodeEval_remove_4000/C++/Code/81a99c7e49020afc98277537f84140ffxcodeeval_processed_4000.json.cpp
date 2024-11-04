


































using namespace std;

template <class C>
constexpr auto ssize(const C& c)
    -> std::common_type_t<std::ptrdiff_t,
                          std::make_signed_t<decltype(c.size())>> {
  return (std::common_type_t<std::ptrdiff_t,
                             std::make_signed_t<decltype(c.size())>>)c.size();
}

template <class T, std::ptrdiff_t N>
constexpr std::ptrdiff_t ssize(const T (&)[N]) noexcept {
  return N;
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, bool> id6(
    T x) noexcept {
  return x != 0 && (x & (x - 1)) == 0;
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, int> id1(
    T x) noexcept {
  if constexpr (sizeof(T) <= sizeof(unsigned)) {
    return __builtin_clz(x) - (std::numeric_limits<unsigned>::digits -
                               std::numeric_limits<T>::digits);
  } else if constexpr (sizeof(T) <= sizeof(unsigned long)) {
    return __builtin_clzl(x) - (std::numeric_limits<unsigned long>::digits -
                                std::numeric_limits<T>::digits);
  } else {
    static_assert(sizeof(T) <= sizeof(unsigned long long));
    return __builtin_clzll(x) -
           (std::numeric_limits<unsigned long long>::digits -
            std::numeric_limits<T>::digits);
  }
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, int> id2(
    T x) noexcept {
  if constexpr (sizeof(T) <= sizeof(unsigned)) {
    return __builtin_ctz(x);
  } else if constexpr (sizeof(T) <= sizeof(unsigned long)) {
    return __builtin_ctzl(x);
  } else {
    static_assert(sizeof(T) <= sizeof(unsigned long long));
    return __builtin_ctzll(x);
  }
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, int> popcount(T x) noexcept {
  if constexpr (sizeof(T) <= sizeof(unsigned)) {
    return __builtin_popcount(x);
  } else if constexpr (sizeof(T) <= sizeof(unsigned long long)) {
    return __builtin_popcountl(x);
  } else {
    static_assert(sizeof(T) <= sizeof(unsigned long long));
    return __builtin_popcountll(x);
  }
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, T> bit_width(T x) noexcept {
  return (T)(std::numeric_limits<T>::digits - id1(x));
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, T> id0(T x) noexcept {
  return (T)(x <= 1 ? 1 : (T)1 << bit_width((T)(x - 1)));
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, T> bit_floor(T x) noexcept {
  return (T)(x == 0 ? 0 : (T)1 << (bit_width(x) - 1));
}

template <class Fun>
class id7 {
 public:
  template <class T>
  explicit id7(T&& fun) : fun_(std::forward<T>(fun)) {}

  template <class... Args>
  decltype(auto) operator()(Args&&... args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }

 private:
  Fun fun_;
};

template <class Fun>
decltype(auto) id3(Fun&& fun) {
  return id7<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

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
  for (auto it = c.begin(); it != c.end(); ++it) {
    if (it != c.begin()) {
      os << ", ";
    }
    os << *it;
  }
  return os << '}';
}

template <typename T, typename Container>
std::ostream& operator<<(std::ostream& os, std::stack<T, Container> s) {
  std::vector<T> v(s.size());
  for (auto it = v.rbegin(); it != v.rend(); ++it) {
    *it = s.top();
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

template <typename T1, typename... Ts>
void debug_print(std::string_view keys, const T1& val1, const Ts&... vals) {
  if constexpr (sizeof...(Ts) == 0) {
    std::cerr << keys << " = " << val1 << std::endl;
  } else {
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
}

template <typename... Ts>
void debug_print(int line, const Ts&... keyvals) {
  if constexpr (sizeof...(Ts) <= 1) {
    std::cerr << "  " << line << " |" << std::endl;
  } else {
    std::cerr << "  " << line << " | ";
    debug_print(keyvals...);
  }
}

}  




  detail::debug_print(__LINE__, 






int k;

template <typename Flow, typename Cost>
class id8 {
 public:
  id8(int n) : graph_(n) {}

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
        e.recost = e.cost;
      }
    }
    int n = (int)graph_.size();
    std::vector<Cost> dist(n, INF_COST);
    dist[source] = 0;
    std::vector<std::pair<int, int>> pred(n);
    std::queue<int> q;
    q.push(source);
    std::vector<bool> active(n, false);
    active[source] = true;
    while (!q.empty()) {  

      int u = q.front();
      q.pop();
      active[u] = false;
      for (int i = 0; i < (int)graph_[u].size(); ++i) {
        if (const edge& e = graph_[u][i];
            e.flow < e.cap && dist[e.to] > dist[u] + e.cost) {
          dist[e.to] = dist[u] + e.cost;
          pred[e.to] = {u, i};
          if (!active[e.to]) {
            q.push(e.to);
            active[e.to] = true;
          }
        }
      }
    }
    constexpr auto compare = [](const std::pair<int, Cost>& lhs,
                                const std::pair<int, Cost>& rhs) -> bool {
      return lhs.second > rhs.second;
    };
    std::priority_queue<std::pair<int, Cost>, std::vector<std::pair<int, Cost>>,
                        decltype(compare)>
        pq(compare);
    Flow total_flow = 0;
    Cost total_cost = 0, curr_cost = 0;
    while (dist[sink] != INF_COST) {
      Flow delta = max_flow - total_flow;
      for (int v = sink; v != source;) {
        const auto& [u, i] = pred[v];
        const edge& e = graph_[u][i];
        delta = std::min(delta, e.cap - e.flow);
        v = u;
      }
      for (int v = sink; v != source;) {
        const auto& [u, i] = pred[v];
        edge& e = graph_[u][i];
        e.flow += delta;
        graph_[v][e.rev].flow -= delta;
        v = u;
      }
      total_cost += delta * (curr_cost += dist[sink]);
      if ((total_flow += delta) == max_flow) {
        break;
      }
      for (int u = 0; u < n; ++u) {
        for (edge& e : graph_[u]) {
          e.recost += dist[u] - dist[e.to];
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
        for (int i = 0; i < (int)graph_[u].size(); ++i) {
          if (const edge& e = graph_[u][i];
              e.flow < e.cap && dist[e.to] > dist[u] + e.recost) {
            pq.emplace(e.to, dist[e.to] = dist[u] + e.recost);
            pred[e.to] = {u, i};
          }
        }
      }
    }
    n = (n - 2) >> 1;
    for (int u = 0; u < k - 1; ++u) {
      for (edge& e : graph_[u]) {
        if (e.flow == e.cap) {
          cout << e.to - n + 1 << ' ';
        }
      }
    }
    for (int u = k - 1; u < n - 1; ++u) {
      for (edge& e : graph_[u]) {
        if (e.flow == e.cap) {
          cout << e.to - n + 1 << ' ' << -e.to + n - 1 << ' ';
        }
      }
    }
    for (edge& e : graph_[n - 1]) {
      if (e.flow == e.cap) {
        cout << e.to - n + 1 << '\n';
      }
    }
    return std::pair(total_flow, total_cost);
  }

 private:
  struct edge {
    int to, rev;
    Flow cap, flow;
    Cost cost, recost;

    constexpr edge(int _to, int _rev, Flow _cap, Cost _cost)
        : to(_to), rev(_rev), cap(_cap), cost(_cost) {}
  };

  std::vector<std::vector<edge>> graph_;
};
















































template <typename Cost>
std::pair<Cost, std::vector<int>> min_cost_assign(
    const std::vector<std::vector<Cost>>& costs) {
  int m = (int)costs.size(), n = (int)costs[0].size();
  assert(m <= n);
  Cost total_cost = 0;
  std::vector<bool> tight(n);
  std::vector<int> col_match(n, -1), pred(n);
  std::vector<Cost> id4(m, 0), id5(n, 0), slack(n);
  for (int i = 0; i < m; ++i) {
    std::fill(tight.begin(), tight.end(), false);
    int y = -1;
    for (int x = i; x != -1; x = col_match[y]) {
      Cost delta = 0;
      int yy = -1;
      for (int j = 0; j < n; ++j) {
        if (tight[j]) {
          continue;
        }
        Cost t = costs[x][j] - id4[x] - id5[j];
        if (y == -1 || t < slack[j]) {
          slack[j] = t;
          pred[j] = y;
        }
        if (yy == -1 || slack[j] < delta) {
          delta = slack[j];
          yy = j;
        }
      }
      y = yy;
      total_cost += delta;
      id4[i] += delta;
      for (int j = 0; j < n; ++j) {
        if (tight[j]) {
          id4[col_match[j]] += delta;
          id5[j] -= delta;
        } else {
          slack[j] -= delta;
        }
      }
      tight[y] = true;
    }
    while (pred[y] != -1) {
      col_match[y] = col_match[pred[y]];
      y = pred[y];
    }
    col_match[y] = i;
  }
  std::vector<int> row_match(m);
  for (int j = 0; j < n; ++j) {
    if (col_match[j] != -1) {
      row_match[col_match[j]] = j;
    }
  }
  return std::pair(total_cost, row_match);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.precision(12);
  std::cerr.precision(12);
  std::mt19937 rng((std::uint_fast32_t)std::chrono::high_resolution_clock::now()
                       .time_since_epoch()
                       .count());
  int num_cases;
  cin >> num_cases;
  while (num_cases--) {
    int n;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i];
    }
    vector<vector<int>> costs(n, vector<int>(n));
    for (int j = 0; j < n; ++j) {
      for (int i = 0; i < k - 1; ++i) {
        costs[i][j] = -(a[j] + i * b[j]);
      }
      for (int i = k - 1; i < n - 1; ++i) {
        costs[i][j] = -(k - 1) * b[j];
      }
      costs[n - 1][j] = -(a[j] + (k - 1) * b[j]);
    }
    cout << n + (n - k) << '\n';
    auto match = min_cost_assign(costs).second;
    for (int i = 0; i < k - 1; ++i) {
      cout << match[i] + 1 << ' ';
    }
    for (int i = k - 1; i < n - 1; ++i) {
      cout << match[i] + 1 << ' ' << -match[i] - 1 << ' ';
    }
    cout << match[n - 1] + 1 << '\n';
  }
  return 0;
}
