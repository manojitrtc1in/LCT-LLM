


#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdlib>
#include <deque>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <optional>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

using namespace std;

template <class C>
constexpr auto ssize(const C& c)
    -> std::common_type_t<std::ptrdiff_t,
                          std::make_signed_t<decltype(c.size())>> {
  using R = std::common_type_t<std::ptrdiff_t,
                               std::make_signed_t<decltype(c.size())>>;
  return (R)c.size();
}

template <class T, std::ptrdiff_t N>
constexpr std::ptrdiff_t ssize(const T (&)[N]) noexcept {
  return N;
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, bool> has_single_bit(
    T x) noexcept {
  return x != 0 && (x & (x - 1)) == 0;
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, int> countl_zero(
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
constexpr std::enable_if_t<std::is_unsigned_v<T>, int> countr_zero(
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
  return (T)(std::numeric_limits<T>::digits - countl_zero(x));
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, T> bit_ceil(T x) noexcept {
  return (T)(x <= 1 ? 1 : (T)1 << bit_width((T)(x - 1)));
}

template <typename T>
constexpr std::enable_if_t<std::is_unsigned_v<T>, T> bit_floor(T x) noexcept {
  return (T)(x == 0 ? 0 : (T)1 << (bit_width(x) - 1));
}

template <typename Fun>
class y_combinator_result {
 public:
  template <typename T>
  explicit y_combinator_result(T&& fun) : fun_(std::forward<T>(fun)) {}

  template <typename... Args>
  decltype(auto) operator()(Args&&... args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }

 private:
  Fun fun_;
};

template <typename Fun>
decltype(auto) y_combinator(Fun&& fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::optional<T>& opt);

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p);

template <typename... Ts>
std::ostream& operator<<(std::ostream& os, const std::tuple<Ts...>& t);

template <typename Container,
          std::enable_if_t<!std::is_convertible_v<Container, std::string_view>,
                           typename Container::const_iterator>* = nullptr>
std::ostream& operator<<(std::ostream& os, const Container& c);

template <typename ContainerAdaptor,
          typename ContainerAdaptor::container_type* = nullptr>
std::ostream& operator<<(std::ostream& os, const ContainerAdaptor& a);

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::optional<T>& opt) {
  return opt ? os << *opt : os << "nullopt";
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) {
  return os << '{' << p.first << ", " << p.second << '}';
}

template <typename... Ts>
std::ostream& operator<<(std::ostream& os, const std::tuple<Ts...>& t) {
  return std::apply(
      [&os](const Ts&... args) -> std::ostream& {
        os << '{';
        int i = 0;
        ((os << (i++ == 0 ? "" : ", ") << args), ...);
        return os << '}';
      },
      t);
}

template <typename Container,
          std::enable_if_t<!std::is_convertible_v<Container, std::string_view>,
                           typename Container::const_iterator>*>
std::ostream& operator<<(std::ostream& os, const Container& c) {
  os << '{';
  for (auto it = c.begin(); it != c.end(); ++it) {
    os << (it == c.begin() ? "" : ", ") << *it;
  }
  return os << '}';
}

template <typename ContainerAdaptor, typename ContainerAdaptor::container_type*>
std::ostream& operator<<(std::ostream& os, const ContainerAdaptor& a) {
  class subadaptor : public ContainerAdaptor {
   public:
    const auto& c() const { return ContainerAdaptor::c; }
  };
  return os << static_cast<const subadaptor&>(a).c();
}

namespace detail {

template <typename... Ts>
void print(std::ostream& os, int line, std::string_view keys,
           const Ts&... vals) {
  if constexpr (sizeof...(Ts) == 0) {
    os << "  " << line << " |" << std::endl;
  } else {
    std::vector<std::string_view> key_list;
    key_list.reserve(sizeof...(Ts));
    int first = 0, paren = 0;
    for (int i = 0; i < (int)keys.size(); ++i) {
      switch (keys[i]) {
        case '(':
        case '[':
        case '{':
          ++paren;
          break;
        case ')':
        case ']':
        case '}':
          --paren;
          break;
        case ',':
          if (paren == 0) {
            key_list.push_back(keys.substr(first, i - first));
            first = i;
          }
          break;
      }
    }
    key_list.push_back(keys.substr(first));
    assert(key_list.size() == sizeof...(Ts));
    os << "  " << line << " | ";
    int i = 0;
    ((os << key_list[i++] << " = " << vals), ...);
    os << std::endl;
  }
}

}  


#if defined(TYLER) && defined(__clang__)
#define debug(...) \
  detail::print(std::cerr, __LINE__, #__VA_ARGS__, ##__VA_ARGS__)
#elif defined(TYLER) && defined(__GNUC__)
#define debug(...) \
  detail::print(std::cerr, __LINE__, #__VA_ARGS__ __VA_OPT__(, ) __VA_ARGS__)
#else
#define debug(...) ((void)0)
#endif

template <typename Flow>
class max_flow {
 public:
  max_flow(int n) : graph_(n) {}

  void add_edge(int from, int to, Flow cap, Flow rev_cap = 0) {
    graph_[from].emplace_back(to, (int)graph_[to].size(), cap);
    graph_[to].emplace_back(from, (int)graph_[from].size() - 1, rev_cap);
  }

  Flow solve(int source, int sink) {
    for (std::vector<edge>& edges : graph_) {
      for (edge& e : edges) {
        e.flow = 0;
      }
    }
    int n = (int)graph_.size();
    std::vector<int> height(n, 0), count(n, 0);
    height[source] = n;
    count[0] = n - 1;
    std::vector<Flow> excess(n, 0);
    std::vector<typename std::vector<edge>::iterator> curr;
    curr.reserve(n);
    for (std::vector<edge>& edges : graph_) {
      curr.push_back(edges.begin());
    }
    auto comp = [&height](int lhs, int rhs) {
      return height[lhs] < height[rhs];
    };
    std::priority_queue<int, std::vector<int>, decltype(comp)> pq(comp);
    for (edge& e : graph_[source]) {
      if (e.cap > 0) {
        excess[source] -= excess[e.to] = e.flow = e.cap;
        graph_[e.to][e.rev].flow = -e.cap;
        pq.push(e.to);
      }
    }
    while (!pq.empty()) {
      int u = pq.top();
      pq.pop();
      while (excess[u] > 0) {
        if (curr[u] == graph_[u].end()) {                  

          if (height[u] < n && --count[height[u]] == 0) {  

            for (int& h : height) {
              if (height[u] < h && h < n) {
                --count[h];
                h = n + 1;
              }
            }
          }
          height[u] = 2 * n;
          for (auto e = graph_[u].begin(); e != graph_[u].end(); ++e) {
            if (e->flow < e->cap && height[u] > height[e->to] + 1) {
              height[u] = height[e->to] + 1;
              curr[u] = e;
            }
          }
          if (height[u] < n) {
            ++count[height[u]];
          }
        } else if (edge& e = *curr[u];
                   e.flow < e.cap && height[u] == height[e.to] + 1) {  

          if (e.to != sink && excess[e.to] == 0) {
            pq.push(e.to);
          }
          Flow delta = std::min(excess[u], e.cap - e.flow);
          e.flow += delta;
          graph_[e.to][e.rev].flow -= delta;
          excess[u] -= delta;
          excess[e.to] += delta;
        } else {
          ++curr[u];
        }
      }
    }
    return excess[sink];
  }

 private:
  struct edge {
    int to, rev;
    Flow cap, flow;

    constexpr edge(int _to, int _rev, Flow _cap)
        : to(_to), rev(_rev), cap(_cap) {}
  };

  std::vector<std::vector<edge>> graph_;
};

int main_ac() {
  auto start_time = std::chrono::steady_clock::now();
  std::mt19937 thanos(
      (std::uint_fast32_t)start_time.time_since_epoch().count());
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.precision(24);
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }
  int src = n * m, dst = n * m + 1;
  max_flow<int> flow(n * m + 2);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '#') {
        if (i > 0 && grid[i - 1][j] == '#') {
          flow.add_edge((i - 1) * m + j, i * m + j, 1);
        } else {
          flow.add_edge(src, i * m + j, 1);
        }
        if (j > 0 && grid[i][j - 1] == '#') {
          flow.add_edge(i * m + j, i * m + (j - 1), 1);
        } else {
          flow.add_edge(i * m + j, dst, 1);
        }
      }
    }
  }
  cout << flow.solve(src, dst) << '\n';
  return 0;
}






















































































































class bipartite_match {
 public:
  bipartite_match(int m, int n)
      : graph_(m), succ_(m, -1), pred_(n, -1), dist_(m), matches_(0) {}

  void add_edge(int from, int to) { graph_[from].push_back(to); }

  void reset() {
    std::fill(succ_.begin(), succ_.end(), -1);
    std::fill(pred_.begin(), pred_.end(), -1);
    matches_ = 0;
  }

  int solve() {
    while (bfs()) {
      for (int u = 0; u < (int)graph_.size(); ++u) {
        if (succ_[u] == -1 && dfs(u)) {
          ++matches_;
        }
      }
    }
    return matches_;
  }

  const std::vector<int>& succ() const { return succ_; }

  const std::vector<int>& pred() const { return pred_; }

 private:
  static constexpr int INF = std::numeric_limits<int>::max();
  std::vector<std::vector<int>> graph_;
  std::vector<int> succ_, pred_, dist_;
  int matches_;

  bool bfs() {
    std::queue<int> q;
    for (int u = 0; u < (int)graph_.size(); ++u) {
      if (succ_[u] == -1) {
        dist_[u] = 0;
        q.push(u);
      } else {
        dist_[u] = INF;
      }
    }
    for (int d = 1; !q.empty(); ++d) {
      bool found = false;
      for (int k = (int)q.size(); k > 0; --k) {
        int u = q.front();
        q.pop();
        for (int v : graph_[u]) {
          if (pred_[v] == -1) {
            found = true;
          } else if (dist_[pred_[v]] == INF) {
            dist_[pred_[v]] = d;
            q.push(pred_[v]);
          }
        }
      }
      if (found) {
        return true;
      }
    }
    return false;
  }

  bool dfs(int u) {
    for (int v : graph_[u]) {
      if (pred_[v] == -1 ||
          (dist_[pred_[v]] == dist_[u] + 1 && dfs(pred_[v]))) {
        succ_[u] = v;
        pred_[v] = u;
        return true;
      }
    }
    dist_[u] = INF;
    return false;
  }
};

int main() {
  auto start_time = std::chrono::steady_clock::now();
  std::mt19937 thanos(
      (std::uint_fast32_t)start_time.time_since_epoch().count());
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.precision(24);
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '#') {
        ++ans;
        if (i > 0 && grid[i - 1][j] == '#') {
          --ans;
        }
        if (j > 0 && grid[i][j - 1] == '#') {
          --ans;
        }
      }
    }
  }
  bipartite_match match(n * m, n * m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '#') {
        if (i < n - 1 && j < m - 1 && grid[i + 1][j] == '#' &&
            grid[i][j + 1] == '#') {
          match.add_edge(i * m + j, i * m + j);
        }
        if (i > 0 && j < m - 1 && grid[i - 1][j] == '#' &&
            grid[i][j + 1] == '#') {
          match.add_edge((i - 1) * m + j, i * m + j);
        }
        if (i < n - 1 && j > 0 && grid[i + 1][j] == '#' &&
            grid[i][j - 1] == '#') {
          match.add_edge(i * m + j, i * m + (j - 1));
        }
        if (i > 0 && j > 0 && grid[i - 1][j] == '#' && grid[i][j - 1] == '#') {
          match.add_edge((i - 1) * m + j, i * m + (j - 1));
        }
      }
    }
  }
  cout << ans + match.solve() << '\n';
  return 0;
}
