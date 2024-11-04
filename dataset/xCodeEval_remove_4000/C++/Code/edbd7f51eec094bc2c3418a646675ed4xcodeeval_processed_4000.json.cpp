







namespace atcoder {
namespace internal {

template <class E> struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    explicit csr(int n, const std::vector<std::pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};

}  


}  







namespace atcoder {

namespace internal {

template <class T> struct simple_queue {
    std::vector<T> payload;
    int pos = 0;
    void reserve(int n) { payload.reserve(n); }
    int size() const { return int(payload.size()) - pos; }
    bool empty() const { return pos == int(payload.size()); }
    void push(const T& t) { payload.push_back(t); }
    T& front() { return payload[pos]; }
    void clear() {
        payload.clear();
        pos = 0;
    }
    void pop() { pos++; }
};

}  


}  





namespace atcoder {

template <class Cap, class Cost> struct id2 {
  public:
    id2() {}
    explicit id2(int n) : _n(n) {}

    int add_edge(int from, int to, Cap cap, Cost cost) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cap);
        assert(0 <= cost);
        int m = int(_edges.size());
        _edges.push_back({from, to, cap, 0, cost});
        return m;
    }

    struct edge {
        int from, to;
        Cap cap, flow;
        Cost cost;
    };

    edge get_edge(int i) {
        int m = int(_edges.size());
        assert(0 <= i && i < m);
        return _edges[i];
    }
    std::vector<edge> edges() { return _edges; }

    std::pair<Cap, Cost> flow(int s, int t) {
        return flow(s, t, std::numeric_limits<Cap>::max());
    }
    std::pair<Cap, Cost> flow(int s, int t, Cap flow_limit) {
        return slope(s, t, flow_limit).back();
    }
    std::vector<std::pair<Cap, Cost>> slope(int s, int t) {
        return slope(s, t, std::numeric_limits<Cap>::max());
    }
    std::vector<std::pair<Cap, Cost>> slope(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);
        assert(s != t);

        int m = int(_edges.size());
        std::vector<int> edge_idx(m);

        auto g = [&]() {
            std::vector<int> degree(_n), id1(m);
            std::vector<std::pair<int, _edge>> elist;
            elist.reserve(2 * m);
            for (int i = 0; i < m; i++) {
                auto e = _edges[i];
                edge_idx[i] = degree[e.from]++;
                id1[i] = degree[e.to]++;
                elist.push_back({e.from, {e.to, -1, e.cap - e.flow, e.cost}});
                elist.push_back({e.to, {e.from, -1, e.flow, -e.cost}});
            }
            auto _g = internal::csr<_edge>(_n, elist);
            for (int i = 0; i < m; i++) {
                auto e = _edges[i];
                edge_idx[i] += _g.start[e.from];
                id1[i] += _g.start[e.to];
                _g.elist[edge_idx[i]].rev = id1[i];
                _g.elist[id1[i]].rev = edge_idx[i];
            }
            return _g;
        }();

        auto result = slope(g, s, t, flow_limit);

        for (int i = 0; i < m; i++) {
            auto e = g.elist[edge_idx[i]];
            _edges[i].flow = _edges[i].cap - e.cap;
        }

        return result;
    }

  private:
    int _n;
    std::vector<edge> _edges;

    

    struct _edge {
        int to, rev;
        Cap cap;
        Cost cost;
    };

    std::vector<std::pair<Cap, Cost>> slope(internal::csr<_edge>& g,
                                            int s,
                                            int t,
                                            Cap flow_limit) {
        

        

        


        

        std::vector<std::pair<Cost, Cost>> dual_dist(_n);
        std::vector<int> prev_e(_n);
        std::vector<bool> vis(_n);
        struct Q {
            Cost key;
            int to;
            bool operator<(Q r) const { return key > r.key; }
        };
        std::vector<int> que_min;
        std::vector<Q> que;
        auto dual_ref = [&]() {
            for (int i = 0; i < _n; i++) {
                dual_dist[i].second = std::numeric_limits<Cost>::max();
            }
            std::fill(vis.begin(), vis.end(), false);
            que_min.clear();
            que.clear();

            

            size_t heap_r = 0;

            dual_dist[s].second = 0;
            que_min.push_back(s);
            while (!que_min.empty() || !que.empty()) {
                int v;
                if (!que_min.empty()) {
                    v = que_min.back();
                    que_min.pop_back();
                } else {
                    while (heap_r < que.size()) {
                        heap_r++;
                        std::push_heap(que.begin(), que.begin() + heap_r);
                    }
                    v = que.front().to;
                    std::pop_heap(que.begin(), que.end());
                    que.pop_back();
                    heap_r--;
                }
                if (vis[v]) continue;
                vis[v] = true;
                if (v == t) break;
                

                

                

                Cost dual_v = dual_dist[v].first, dist_v = dual_dist[v].second;
                for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                    auto e = g.elist[i];
                    if (!e.cap) continue;
                    

                    

                    Cost cost = e.cost - dual_dist[e.to].first + dual_v;
                    if (dual_dist[e.to].second - dist_v > cost) {
                        Cost dist_to = dist_v + cost;
                        dual_dist[e.to].second = dist_to;
                        prev_e[e.to] = e.rev;
                        if (dist_to == dist_v) {
                            que_min.push_back(e.to);
                        } else {
                            que.push_back(Q{dist_to, e.to});
                        }
                    }
                }
            }
            if (!vis[t]) {
                return false;
            }

            for (int v = 0; v < _n; v++) {
                if (!vis[v]) continue;
                

                

                

                

                

                dual_dist[v].first -= dual_dist[t].second - dual_dist[v].second;
            }
            return true;
        };
        Cap flow = 0;
        Cost cost = 0, id3 = -1;
        std::vector<std::pair<Cap, Cost>> result = {{Cap(0), Cost(0)}};
        while (flow < flow_limit) {
            if (!dual_ref()) break;
            Cap c = flow_limit - flow;
            for (int v = t; v != s; v = g.elist[prev_e[v]].to) {
                c = std::min(c, g.elist[g.elist[prev_e[v]].rev].cap);
            }
            for (int v = t; v != s; v = g.elist[prev_e[v]].to) {
                auto& e = g.elist[prev_e[v]];
                e.cap += c;
                g.elist[e.rev].cap -= c;
            }
            Cost d = -dual_dist[s].first;
            flow += c;
            cost += c * d;
            if (id3 == d) {
                result.pop_back();
            }
            result.push_back({flow, cost});
            id3 = d;
        }
        return result;
    }
};

}  





template <typename T, typename = void>
struct is_dereferenceable : std::false_type {};
template <typename T>
struct is_dereferenceable<T, std::void_t<decltype(*std::declval<T>())>>
    : std::true_type {};

template <typename T, typename = void>
struct is_iterable : std::false_type {};
template <typename T>
struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T>())),
                                  decltype(std::end(std::declval<T>()))>>
    : std::true_type {};

template <typename T, typename = void>
struct is_applicable : std::false_type {};
template <typename T>
struct is_applicable<T, std::void_t<decltype(std::tuple_size<T>::value)>>
    : std::true_type {};

template <typename T, typename... Ts>
void debug(const T& value, const Ts&... args);
template <typename T>
void debug(const T& v) {
  if constexpr (is_dereferenceable<T>::value) {
    std::cerr << "{";
    if (v) {
      debug(*v);
    } else {
      std::cerr << "nil";
    }
    std::cerr << "}";
  } else if constexpr (is_iterable<T>::value &&
                       !std::is_same<T, std::string>::value) {
    std::cerr << "{";
    for (auto it = std::begin(v); it != std::end(v); ++it) {
      if (it != std::begin(v)) std::cerr << ", ";
      debug(*it);
    }
    std::cerr << "}";
  } else if constexpr (is_applicable<T>::value) {
    std::cerr << "{";
    std::apply([](const auto&... args) { debug(args...); }, v);
    std::cerr << "}";
  } else {
    std::cerr << v;
  }
}
template <typename T, typename... Ts>
void debug(const T& value, const Ts&... args) {
  debug(value);
  std::cerr << ", ";
  debug(args...);
}


  do {                                  \
    cerr << 
    debug(id4);                 \
    cerr << " (L" << __LINE__ << ")\n"; \
  } while (0)




void id6() {}
template <typename T, typename... Ts>
void id6(T& value, Ts&... args) {
  std::cin >> value;
  id6(args...);
}

  type id4;   \
  id6(id4);







const char *yes_str = "Yes", *no_str = "No";

template <typename T>
void id0(const T& value) {
  if constexpr (std::is_same<T, bool>::value) {
    std::cout << (value ? yes_str : no_str);
  } else if constexpr (is_iterable<T>::value &&
                       !std::is_same<T, std::string>::value) {
    for (auto it = std::begin(value); it != std::end(value); ++it) {
      if (it != std::begin(value)) std::cout << " ";
      std::cout << *it;
    }
  } else {
    std::cout << value;
  }
}
template <typename T, typename... Ts>
void id0(const T& value, const Ts&... args) {
  id0(value);
  std::cout << ' ';
  id0(args...);
}

  do {                          \
    id0(id4); \
    cout << '\n';               \
  } while (0)








  (                                                                        \
      [] {                                                                 \
        static_assert(                                                     \
            std::is_integral<                                              \
                typename std::remove_reference<decltype(x)>::type>::value, \
            "rep macro supports std integral types only");                 \
      },                                                                   \
      static_cast<int64_t>(x))















template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v) {
  for (T& vi : v) is >> vi;
  return is;
}

template <typename T, typename U>
std::istream& operator>>(std::istream& is, std::pair<T, U>& p) {
  is >> p.first >> p.second;
  return is;
}

template <typename T, typename U>
bool chmax(T& a, U b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template <typename T, typename U>
bool chmin(T& a, U b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <typename T, typename U>
auto max(T a, U b) {
  return a > b ? a : b;
}

template <typename T, typename U>
auto min(T a, U b) {
  return a < b ? a : b;
}

template <typename T>
int64_t sz(const T& v) {
  return std::size(v);
}

template <typename T>
int64_t popcount(T i) {
  return std::bitset<std::numeric_limits<T>::digits>(i).count();
}

template <typename T>
bool hasbit(T s, int i) {
  return std::bitset<std::numeric_limits<T>::digits>(s)[i];
}

template <typename T, typename U>
auto div_floor(T n, U d) {
  if (d < 0) {
    n = -n;
    d = -d;
  }
  if (n < 0) {
    return -((-n + d - 1) / d);
  }
  return n / d;
};

template <typename T, typename U>
auto id5(T n, U d) {
  if (d < 0) {
    n = -n;
    d = -d;
  }
  if (n < 0) {
    return -(-n / d);
  }
  return (n + d - 1) / d;
}

template <typename T>
bool even(T x) {
  return x % 2 == 0;
}

std::array<std::pair<int64_t, int64_t>, 4> adjacent(int64_t i, int64_t j) {
  return {{{i + 1, j}, {i, j + 1}, {i - 1, j}, {i, j - 1}}};
}

bool inside(int64_t i, int64_t j, int64_t I, int64_t J) {
  return 0 <= i && i < I && 0 <= j && j < J;
}

const int64_t big = std::numeric_limits<int64_t>::max() / 4;

using i64 = int64_t;
using i32 = int32_t;

template <typename T>
using low_priority_queue =
    std::priority_queue<T, std::vector<T>, std::greater<T>>;

template <typename T>
using V = std::vector<T>;
template <typename T>
using VV = V<V<T>>;

void Main();

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout << std::fixed << std::setprecision(20);
  yes_str = "YES", no_str = "NO";
  Main();
  return 0;
}

using namespace std;



void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<int> next(n);
  rrep(i, n) {
    if (a[i] == 0) {
      next[i] = i;
    } else {
      if (i + 1 < n) {
        next[i] = next[i + 1];
      } else {
        next[i] = big;
      }
    }
  }
  vector dp(n + 1, vector(n + 1, big));
  dp[0][0] = 0;
  rep(i, n) rep(j, n) {
    if (dp[i][j] == big) continue;
    chmin(dp[i][j + 1], dp[i][j]);
    if (a[i] == 0) {
      chmin(dp[i + 1][j], dp[i][j]);
    } else {
      int k = next[j];
      chmin(dp[i + 1][k + 1], dp[i][j] + abs(i - k));
    }
  }
  rrep(i, n) if (a[i] == 1) {
    wt(*min_element(all(dp[i + 1])));
    return;
  }
  wt(0);
}
