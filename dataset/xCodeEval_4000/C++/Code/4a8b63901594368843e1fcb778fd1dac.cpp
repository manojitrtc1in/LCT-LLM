#include <bits/stdc++.h>
using namespace std;









#define MEMBER_FUNCTION_CHECKER(FUNCTION) \
  template <typename __class_t, typename... __args_t> \
  struct _has_##FUNCTION { \
    template <typename __class> \
    static constexpr auto check(__class*) -> \
      typename std::is_void<std::void_t< \
        decltype(std::declval<__class&>().FUNCTION(std::declval<__args_t>()...))>>::type; \
    template <typename __dummy> \
    static constexpr auto check(...) -> std::false_type; \
    using type = decltype(check<__class_t>(0)); \
    static constexpr bool value = type::value; \
  }




#include <complex>
#include <string>
#include <tuple>
#include <vector>

#define USING_FAST_INPUT

template <size_t buf_size = 10000>
struct fast_input {
  char buf[buf_size], *S, *T, c = 0;
  int positive;
  FILE* ifptr;
  fast_input(FILE* _in = stdin): S(buf), T(buf), ifptr(_in) {}

  explicit operator bool() const { return c != EOF; }

  inline char getc(void) {
    if (c == EOF) return EOF;
    if (S == T) {
      T = (S = buf) + fread(buf, 1, buf_size, ifptr);
      if (S == T) return c = EOF;
    }
    return *S++;
  }

  inline void get(char& x) {
    while (isspace(x = getc()) && x != EOF);
  }

  inline void get(std::string& x) {
    x.clear();
    while (isspace(c = getc()) && c != EOF);
    for (; !isspace(c) && c != EOF; c = getc()) {
      x.push_back(c);
    }
  }

  inline void get(decltype(std::ignore)) {
    while (isspace(c = getc()) && c != EOF);
    for (; !isspace(c) && c != EOF; c = getc());
  }

  template <typename var_t, std::enable_if_t<std::is_integral_v<var_t>, bool> = true>
  inline void get(var_t& x) {
    x = 0;
    positive = 1;
    while (!isdigit(c = getc()) && c != EOF) {
      positive = (c ^ '-');
    }
    for (; isdigit(c) && c != EOF; c = getc()) {
      x = x * 10 + c - '0';
    }
    if (!positive) {
      x = -x;
    }
  }

  template <typename var_t, std::enable_if_t<std::is_floating_point_v<var_t>, bool> = true>
  inline void get(var_t& x) {
    x = 0;
    positive = 1;
    while (!isdigit(c = getc()) && c != '.' && c != EOF) {
      positive = (c ^ '-');
    }
    if (c != '.') {
      for (; isdigit(c) && c != EOF; c = getc()) {
        x = x * 10 + c - '0';
      }
    }
    if (c == '.') {
      static var_t div;
      div = 1;
      while (isdigit(c = getc()) && c != EOF) {
        x = x * 10 + c - '0';
        div *= 10;
      }
      x /= div;
    }
    if (!positive) {
      x = -x;
    }
  }

  template <typename T>
  inline void get(std::complex<T>& x) {
    x.real(getv<T>());
    x.imag(getv<T>());
  }

  template <typename T, typename U>
  inline void get(std::pair<T, U>& x) {
    *this >> x.first >> x.second;
  }

  template <size_t index = 0, typename... T>
  inline void get(std::tuple<T...>& x) {
    if constexpr (index < sizeof...(T)) {
      *this >> (std::get<index>(x));
      get<index + 1>(x);
    }
  }

  MEMBER_FUNCTION_CHECKER(get);

  template <typename T>
  inline fast_input& operator >> (T& x) {
    if constexpr (_has_get<fast_input, T&>::value) {
      get(x);
    } else {
      x.fast_read(*this);
    }
    return *this;
  }

  std::string getline() {
    std::string out;
    while ((c = getc()) != '\n' && c != EOF) {
      out.push_back(c);
    }
    return out;
  }

  std::vector<std::string> readlines(int n) {
    std::vector<std::string> out;
    out.reserve(n);
    for (int i = 0; i < n; i++) {
      out.push_back(getline());
    }
    return out;
  }

  template <typename T>
  T getv() {
    T x;
    *this >> x;
    return x;
  }

  template <typename T, int pad_n = 0>
  std::vector<T> read(int n) {
    return readinit<T, pad_n>(n, T());
  }

  template <typename T, int pad_n = 0, int pad_m = 0>
  std::vector<std::vector<T>> read(int n, int m) {
    return readinit<T, pad_n, pad_m>(n, m, T());
  }

  template <typename T, int pad_n = 0, int pad_m = 0, int pad_h = 0>
  std::vector<std::vector<std::vector<T>>> read(int n, int m, int h) {
    return readinit<T, pad_n, pad_m, pad_h>(n, m, h, T());
  }

  template <typename T, int pad_n = 0>
  std::vector<T> readinit(int n, T init) {
    std::vector<T> out(n + 2 * pad_n, init);
    for (int i = 0; i < n; i++) {
      *this >> out[pad_n + i];
    }
    return out;
  }

  template <typename T, int pad_n = 0, int pad_m = 0>
  std::vector<std::vector<T>> readinit(int n, int m, T init) {
    std::vector out(n + 2 * pad_n, std::vector<T>(m + 2 * pad_m, init));
    for (int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        *this >> out[pad_n + i][pad_m + j];
      }
    }
    return out;
  }

  template <typename T, int pad_n = 0, int pad_m = 0, int pad_h = 0>
  std::vector<std::vector<std::vector<T>>> readinit(int n, int m, int h, T init) {
    std::vector out(n + 2 * pad_n, std::vector(m + 2 * pad_m,
          std::vector<T>(h + 2 * pad_h, init)));
    for (int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        for (int k = 0; k < h; k++) {
          *this >> out[pad_n + i][pad_m + j][pad_h + k];
        }
      }
    }
    return out;
  }
};






#include <ostream>
#include <set>
#include <tuple>
#include <unordered_set>
#include <vector>

template <template <typename> typename Container, typename T,
          typename = std::enable_if_t<std::disjunction_v<
            std::is_same<Container<T>, std::vector<T>>,
            std::is_same<Container<T>, std::set<T>>,
            std::is_same<Container<T>, std::unordered_set<T>>>>
         >
std::ostream& operator << (std::ostream& os, const Container<T>& v) {
  if (v.begin() == v.end()) return os;
  os << *v.begin();
  for (auto it = v.begin() + 1; it != v.end(); it++) {
    os << " " << *it;
  }
  return os;
}

template <typename Iterator>

struct container_view {
  const Iterator _begin, _end;
  container_view(const Iterator s, const Iterator t):
    _begin(s), _end(t) {}
  const Iterator begin() const { return _begin; }
  const Iterator end() const { return _end; }
  friend std::ostream& operator << (std::ostream& os, container_view v) {
    if (v.begin() == v.end()) return os;
    os << *v.begin();
    for (auto it = v.begin() + 1; it != v.end(); it++) {
      os << " " << *it;
    }
    return os;
  }
};

template <typename T>
struct subvector : container_view<typename std::vector<T>::const_iterator> {
  subvector(const std::vector<T>& v, int l, int r):
    container_view<typename std::vector<T>::const_iterator>(
        v.begin() + l, v.begin() + r + 1) {}
};

template <typename T, typename U>
std::ostream& operator << (std::ostream& os, const std::pair<T, U>& v) {
  return os << v.first << " " << v.second;
}

namespace {
  template <typename Tuple, size_t... Is>
  auto _skip_first(const Tuple& t, std::index_sequence<Is...>) {
    return std::make_tuple(std::get<Is + 1>(t)...);
  }
}

template <typename T>
std::ostream& operator << (std::ostream& os, const std::tuple<T>& v) {
  return os << std::get<0>(v);
}

template <typename... T>
std::ostream& operator << (std::ostream& os, const std::tuple<T...>& v) {
  return os << std::get<0>(v) << " "
    << _skip_first(v, std::make_index_sequence<sizeof...(T) - 1>{});
}







#include <limits>
#include <set>

template <typename T>
struct dynamic_hull_line {
  T m, b;
  mutable T last;
  dynamic_hull_line(const T& _m, const T& _b): m(_m), b(_b), last(0) {}
  bool operator < (const dynamic_hull_line& o) const { return m < o.m; }
  bool operator < (const T& x) const { return last < x; }
};

template <typename T>
struct dynamic_hull : std::multiset<dynamic_hull_line<T>, std::less<>> {
  using base = std::multiset<dynamic_hull_line<T>, std::less<>>;
  using base_it = typename base::iterator;
  static constexpr T inf = std::numeric_limits<T>::has_infinity ?
    std::numeric_limits<T>::infinity() : std::numeric_limits<T>::max();
  static T div(const T& a, const T& b) {
    if constexpr (std::is_integral_v<T>) {
      return a / b - ((a ^ b) < 0 && a % b != 0);
    } else {
      return a / b;
    }
  }
  T intersect(base_it it, base_it jt) {
    if (jt == base::end()) return inf;
    if (it->m == jt->m) return it->b < jt->b ? -inf : inf;
    return div(it->b - jt->b, jt->m - it->m);
  }
  

  void insert(const T& m, const T& b) {
    auto it = base::insert(dynamic_hull_line<T>(m, b));
    it->last = intersect(it, next(it));
    

    if (it != base::begin() && intersect(prev(it), it) >= it->last) {
      base::erase(it);
      return;
    }
    

    while (next(it) != base::end() && it->last >= next(it)->last) {
      base::erase(next(it));
      it->last = intersect(it, next(it));
    }
    

    if (it != base::begin()) {
      prev(it)->last = intersect(prev(it), it);
      for (it = prev(it); it != base::begin() && prev(it)->last >= it->last; it--) {
        it = base::erase(it);
        prev(it)->last = intersect(prev(it), it);
      }
    }
    

    while (base::begin()->last == -inf) {
      base::erase(base::begin());
    }
  }
  

  T query(const T& x) const {
    assert(!base::empty());
    auto line = base::lower_bound(x);
    return line->m * x + line->b;
  }
};

template <typename T>
using dynamic_hull_max = dynamic_hull<T>;

template <typename T>
struct dynamic_hull_min : dynamic_hull<T> {
  void insert(const T& m, const T& b) {
    return dynamic_hull<T>::insert(-m, -b);
  }
  T query(const T& x) const {
    return -dynamic_hull<T>::query(x);
  }
};












#include <type_traits>
#include <utility>

template <typename> struct graph_list;
template <typename> struct graph_matrix;

template <typename weight_t>
struct graph_adj {
  int to;
  weight_t weight;
  graph_adj(int v, weight_t w): to(v), weight(w) {}
};

template <>
struct graph_adj<void> {
  int to;
  graph_adj(int v): to(v) {}
  operator int() const { return to; }
};

template <typename weight_t>
struct graph_edge {
  int from, to;
  weight_t weight;
  graph_edge(int u, int v, weight_t w): from(u), to(v), weight(w) {}
  graph_edge(int u, graph_adj<weight_t> adj): from(u), to(adj.to), weight(adj.weight) {}
};

template <>
struct graph_edge<void> {
  int from, to;
  graph_edge(int u, int v): from(u), to(v) {}
  operator std::pair<int, int>() const { return std::pair(from, to); }
};

static_assert(sizeof(graph_edge<void>) == sizeof(std::pair<int, int>));
static_assert(sizeof(graph_adj<void>) == sizeof(int));

template <typename weight_t>
class list_edge_list_view {
  const graph_list<weight_t>* _graph;
  struct iterator {
    const graph_list<weight_t>* graph;
    int from, to;
    iterator(): graph(nullptr), from(-1), to(-1) {}
    iterator(const graph_list<weight_t>* g, int f, int t): graph(g), from(f), to(t) {}
    graph_edge<weight_t> operator * () const {
      return graph_edge<weight_t>(from, graph->adj[from][to]);
    }
    iterator& operator ++ () {
      while (from < (int)graph->adj.size()) {
        if (++to == (int)graph->adj[from].size()) {
          to = -1;
          from++;
          continue;
        }
        break;
      }
      return *this;
    }
    bool operator == (const iterator& o) const {
      return to == o.to && from == o.from;
    }
    bool operator != (const iterator& o) const { return !operator == (o); } 

  };
public:
  list_edge_list_view(const graph_list<weight_t>* g): _graph(g) {}
  iterator begin() const {
    return ++iterator(_graph, 0, -1);
  }
  iterator end() const {
    return iterator(_graph, (int)_graph->adj.size(), -1);
  }
};

template <typename weight_t>
class matrix_adj_list_view {
  const graph_matrix<weight_t>* _graph;
  int _from;
  struct iterator {
    const graph_matrix<weight_t>* graph;
    int from, to;
    iterator(): graph(nullptr), from(-1), to(-1) {}
    iterator(const graph_matrix<weight_t>* g, int f, int t): graph(g), from(f), to(t) {}
    graph_adj<weight_t> operator * () const {
      if constexpr (std::is_void_v<weight_t>) {
        return graph_adj<weight_t>(to);
      } else {
        return graph_adj<weight_t>(to, graph->adj[from][to]);
      }
    }
    iterator& operator ++ () {
      while (++to < (int)graph->adj[from].size()) {
        if constexpr (std::is_void_v<weight_t>) {
          if (graph->adj[from][to]) {
            break;
          }
        } else {
          if (graph->adj[from][to] != graph->inf) {
            break;
          }
        }
      }
      return *this;
    }
    bool operator == (const iterator& o) const {
      return to == o.to;
    }
    bool operator != (const iterator& o) const { return !operator == (o); } 

  };
public:
  matrix_adj_list_view(const graph_matrix<weight_t>* g, int u):
    _graph(g), _from(u) {}
  iterator begin() const {
    return ++iterator(_graph, _from, -1);
  }
  iterator end() const {
    return iterator(_graph, _from, (int)_graph->adj[_from].size());
  }
};

template <typename weight_t>
class matrix_edge_list_view {
  const graph_matrix<weight_t>* _graph;
  struct iterator {
    const graph_matrix<weight_t>* graph;
    int from, to;
    iterator(): graph(nullptr), from(-1), to(-1) {}
    iterator(const graph_matrix<weight_t>* g, int f, int t): graph(g), from(f), to(t) {}
    graph_edge<weight_t> operator * () const {
      if constexpr (std::is_void_v<weight_t>) {
        return graph_edge<weight_t>(from, to);
      } else {
        return graph_edge<weight_t>(from, to, graph->adj[from][to]);
      }
    }
    iterator& operator ++ () {
      while (from < (int)graph->adj.size()) {
        if (++to == (int)graph->adj[from].size()) {
          to = -1;
          from++;
          continue;
        }
        if constexpr (std::is_void_v<weight_t>) {
          if (graph->adj[from][to]) {
            break;
          }
        } else {
          if (graph->adj[from][to] != graph->inf) {
            break;
          }
        }
      }
      return *this;
    }
    bool operator == (const iterator& o) const {
      return to == o.to && from == o.from;
    }
    bool operator != (const iterator& o) const { return !operator == (o); } 

  };
public:
  matrix_edge_list_view(const graph_matrix<weight_t>* g): _graph(g) {}
  iterator begin() const {
    return ++iterator(_graph, 0, -1);
  }
  iterator end() const {
    return iterator(_graph, (int)_graph->adj.size(), -1);
  }
};




#include <ostream>
#include <vector>




template <typename _weight_t>  

struct graph_list {
  using weight_t = _weight_t;
  static constexpr bool weighted = true;
  std::vector<std::vector<graph_adj<weight_t>>> adj;
  std::vector<int> in_degree, out_degree;
  int num_edges, num_arcs;
  bool directed;
  graph_list(int n, bool d = false):
    adj(n), in_degree(n), out_degree(n), num_edges(0), num_arcs(0), directed(d) {}
  int size() const { return (int)adj.size(); }
  void add_edge(int a, int b, weight_t c) {
    num_edges++;
    add_arc(a, b, c);
    if (!directed) {
      add_arc(b, a, c);
    }
  }
  void add_arc(int a, int b, weight_t c) {
    num_arcs++;
    adj[a].emplace_back(b, c);
    in_degree[b]++;
    out_degree[a]++;
  }
  const std::vector<graph_adj<weight_t>>& operator [] (int u) const {
    return adj[u];
  }
  list_edge_list_view<weight_t> get_edges() const {
    return list_edge_list_view(this);
  }
};

template <>  

struct graph_list<void> {
  using weight_t = void;
  static constexpr bool weighted = false;
  std::vector<std::vector<int>> adj;
  std::vector<int> in_degree, out_degree;
  int num_edges, num_arcs;
  bool directed;
  graph_list(int n, bool d = false):
    adj(n), in_degree(n), out_degree(n), num_edges(0), num_arcs(0), directed(d) {}
  int size() const { return (int)adj.size(); }
  void add_edge(int a, int b) {
    num_edges++;
    add_arc(a, b);
    if (!directed) {
      add_arc(b, a);
    }
  }
  void add_arc(int a, int b) {
    num_arcs++;
    adj[a].emplace_back(b);
    in_degree[b]++;
    out_degree[a]++;
  }
  const std::vector<int>& operator [] (int u) const {
    return adj[u];
  }
  list_edge_list_view<void> get_edges() const {
    return list_edge_list_view(this);
  }
};




template <typename _weight_t>  

struct graph_matrix {
  using weight_t = _weight_t;
  static constexpr bool weighted = true;
  std::vector<std::vector<weight_t>> adj;
  std::vector<int> in_degree, out_degree;
  weight_t inf;
  bool directed;
  graph_matrix(int n, weight_t _inf, bool d = false):
    adj(n, std::vector<weight_t>(n, _inf)), in_degree(n), out_degree(n), inf(_inf), directed(d) {}
  int size() const { return (int)adj.size(); }
  void add_edge(int a, int b, weight_t c) {
    add_arc(a, b, c);
    if (!directed) {
      add_arc(b, a, c);
    }
  }
  void add_arc(int a, int b, weight_t c) {
    in_degree[b] += (adj[a][b] == inf);
    out_degree[a] += (adj[a][b] == inf);
    adj[a][b] = c;
  }
  matrix_adj_list_view<weight_t> operator [] (int u) const {
    return matrix_adj_list_view(this, u);
  }
  matrix_edge_list_view<weight_t> get_edges() const {
    return matrix_edge_list_view(this);
  }
};

template <>  

struct graph_matrix<void> {
  using weight_t = void;
  static constexpr bool weighted = false;
  std::vector<std::vector<bool>> adj;
  std::vector<int> in_degree, out_degree;
  bool directed;
  graph_matrix(int n, bool d = false):
    adj(n, std::vector<bool>(n)), in_degree(n), out_degree(n), directed(d) {}
  int size() const { return (int)adj.size(); }
  void add_edge(int a, int b) {
    add_arc(a, b);
    if (!directed) {
      add_arc(b, a);
    }
  }
  void add_arc(int a, int b) {
    in_degree[b] += !adj[a][b];
    out_degree[a] += !adj[a][b];
    adj[a][b] = true;
  }
  matrix_adj_list_view<void> operator [] (int u) const {
    return matrix_adj_list_view(this, u);
  }
  matrix_edge_list_view<void> get_edges() const {
    return matrix_edge_list_view(this);
  }
};




template <typename G> struct is_graph_checker {};
template <template <typename> typename G, typename T>
struct is_graph_checker<G<T>> {
  static constexpr bool is_graph_list = std::is_same_v<G<T>, graph_list<T>>;
  static constexpr bool is_graph_matrix = std::is_same_v<G<T>, graph_matrix<T>>;
  static constexpr bool value = is_graph_list || is_graph_matrix;
  using weight_t = T;
};
template <typename G>
constexpr bool is_graph_v = is_graph_checker<G>::value;
template <typename G>
constexpr bool is_graph_list_v = is_graph_checker<G>::is_graph_list;
template <typename G>
constexpr bool is_graph_matrix_v = is_graph_checker<G>::is_graph_matrix;
template <typename G>
using get_graph_weight_t = typename is_graph_checker<G>::weight_t;



template <template <typename> typename graph_t, typename T,
         std::enable_if_t<is_graph_v<graph_t<T>>, bool> = true>
std::ostream& operator << (std::ostream& os, const graph_t<T>& g) {
  for (int u = 0; u < g.size(); u++) {
    os << u << " -> [";
    if constexpr (std::is_void_v<T>) {
      for (int v : g[u]) {
        os << " " << v << ", ";
      }
    } else {
      for (auto [v, c] : g[u]) {
        os << " " << v << ":" << c << ", ";
      }
    }
    os << "]\n";
  }
  return os;
}






#include <vector>

struct graph_traversal {
  virtual const std::vector<int>& get_parents() const = 0;
  std::vector<int> get_path(int to) const {
    std::vector<int> path;
    if (get_parents()[to] != -1) {
      while (true) {
        path.push_back(to);
        if (to == get_parents()[to]) break;
        to = get_parents()[to];
      }
      reverse(path.begin(), path.end());
    }
    return path;
  }
};



#include <queue>

template <typename weight_t>
struct dijkstra_item {
  int u;
  weight_t d;
  dijkstra_item(int _u, weight_t _d): u(_u), d(_d) {}
  dijkstra_item(std::pair<int, weight_t> item): u(item.first), d(item.second) {}
  bool operator < (const dijkstra_item& o) const { return d > o.d; }
};

template <typename graph_t>
struct dijkstra : graph_traversal {
  using weight_t = get_graph_weight_t<graph_t>;
  vector<weight_t> dist;
  vector<int> parent;
  dijkstra(const graph_t& graph, int source, weight_t inf):
    dist(graph.size(), inf), parent(graph.size(), -1) {
    std::priority_queue<dijkstra_item<weight_t>> to_visit;
    to_visit.emplace(source, weight_t());
    dist[source] = weight_t();
    parent[source] = source;
    run(graph, inf, std::move(to_visit));
  }
  template <typename source_t>
  dijkstra(const graph_t& graph, const std::vector<source_t>& sources, weight_t inf):
    dist(graph.size(), inf), parent(graph.size(), -1) {
    for(auto [source, dist_to_source] : sources) {
      dist[source] = dist_to_source;
      parent[source] = source;
    }
    run(graph, inf,
        std::priority_queue<dijkstra_item<weight_t>>(sources.begin(), sources.end()));
  }

  void run(
      const graph_t& graph, weight_t inf,
      std::priority_queue<dijkstra_item<weight_t>>&& to_visit) {
    while (!to_visit.empty()) {
      auto [u, d] = to_visit.top();
      to_visit.pop();
      if (d != dist[u]) continue;
      for (const auto& [v, c] : graph[u]) {
        if (dist[v] != inf && dist[v] <= d + c) continue;
        dist[v] = d + c;
        parent[v] = u;
        to_visit.emplace(v, dist[v]);
      }
    }
  }
  const vector<weight_t>& get_dists() const { return dist; }
  const vector<int>& get_parents() const override { return parent; }
};




using ll = long long;
using ld = long double;

constexpr char nl = '\n';
constexpr int MOD = 998244353;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());


int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);
#ifdef USING_FAST_INPUT
  fast_input cin;
#endif

  int n, m, k;
  cin >> n >> m >> k;
  graph_list<ll> graph(n+1);
  for(int i=0; i<m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    graph.add_edge(a, b, c);
  }

  struct Item {
    int u;
    ll d;
    bool operator < (const Item& o) const {
      return d > o.d;
    }
  };
  vector<ll> dist = dijkstra(graph, 1, -1).get_dists();

  while(k--) {
    dynamic_hull_min<ll> hull;
    for(int i=1; i<=n; i++) {
      if(dist[i] == -1) continue;
      hull.insert(-2*i, dist[i] + (ll)i*i);
    }
    vector<dijkstra_item<ll>> sources;
    

    for(int i=1; i<=n; i++) {
      ll f = hull.query(i) + (ll)i*i;
      if(dist[i] != -1) f = min(f, dist[i]);
      sources.emplace_back(i, f);
      

    }
    dist = dijkstra(graph, sources, -1).get_dists();
    

  }

  cout << subvector(dist, 1, n) << nl;

  return 0;
}
