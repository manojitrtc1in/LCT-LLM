




extern const bool id10 = true;
extern const bool id6 = false;









































struct fast_ios {
  fast_ios() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cout.precision(10);
    std::cout << std::fixed;
  };
} id0;
namespace io {
template<typename T, typename U>
std::ostream &operator<<(std::ostream &out, const std::pair<T, U> &p);
template<typename... Ts>
std::istream &operator>>(std::istream &in, std::tuple<Ts...> &t);
template<typename T, typename U>
std::istream &operator>>(std::istream &in, std::pair<T, U> &p) {
  in >> p.first >> p.second;
  return in;
}

template<typename T>
std::istream &operator>>(std::istream &stream, std::vector<T> &vec) {
  for (auto &x : vec)
    stream >> x;
  return stream;
}

template<typename... Ts>
std::istream &operator>>(std::istream &in, const std::tuple<Ts...> &t) {
  std::apply([&in](auto &...args) { ((in >> args), ...); }, t);
  return in;
}

template<class... Args> void scan(Args &...args) {
  ((std::cin >> args), ...);
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vec) {
  bool first = true;
  for (const T &t : vec) {
    if (first)
      first = false;
    else
      out << ' ';
    out << t;
  }
  return out;
}

template<typename T, typename U>
std::ostream &operator<<(std::ostream &out, const std::pair<T, U> &p) {
  out << p.first << ' ' << p.second;
  return out;
}

template<typename T>
std::ostream &operator<<(std::ostream &out,
                         const std::vector<std::vector<T>> &t) {
  bool is_first = true;
  for (const auto &row : t) {
    if (is_first)
      is_first = false;
    else
      out << '\n';
    out << row;
  }
  return out;
}

template<typename... Args> void pt(Args &&...args) {
  ((std::cout << args << ' '), ...);
}

template<typename First, typename... Args>
void pl(const First &first, const Args &...args) {
  std::cout << first;
  ((std::cout << ' ' << args), ...);
  std::cout << '\n';
}

template<typename... Args> void pn(const Args &...args) {
  ((std::cout << args << '\n'), ...);
}
}

inline int ri() {
  int x;
  std::cin >> x;
  return x;
}




























template<unsigned dimension, typename T>
class ndarray : public std::vector<ndarray<dimension - 1, T>> {
 public:
  template<typename... Args>
  ndarray(unsigned d, Args... args)
      : std::vector<ndarray<dimension - 1, T>>(
          d, ndarray<dimension - 1, T>(args...)) {}
};
template<typename T> class ndarray<1, T> : public std::vector<T> {
 public:
  template<typename... Args>
  ndarray<1, T>(Args &&...args) : std::vector<T>(std::forward<Args>(args)...) {}
};
























  do {                                                                         \
  } while (0)






  f(x, y) MAP_NEXT(peek, MAP1)(f, peek, id3)

  f(x, y) MAP_NEXT(peek, MAP0)(f, peek, id3)





using ll = long long;
using ull = unsigned long long;
using vl = std::vector<ll>;
using vb = std::vector<bool>;
using vi = std::vector<int>;
using vs = std::vector<std::string>;
using pii = std::pair<int, int>;
using pli = std::pair<ll, int>;
using pil = std::pair<int, ll>;
using pll = std::pair<ll, ll>;
using vii = std::vector<pii>;
template<typename T>
using pq = std::priority_queue<std::pair<T, int>,
                               std::vector<std::pair<T, int>>, std::greater<>>;
template<typename... Ts> using vt = std::vector<std::tuple<Ts...>>;
template<typename T> using vv = ndarray<2, T>;
template<typename T> struct range_tuple {
  const T &ref = beg;
  T beg;
  const T end;
  range_tuple(T b, T e) : beg(b), end(e) {}
};

  for (auto &&[i, id4(iter_, __LINE__), id4(end_, __LINE__)] = \
           range_tuple<std::common_type<decltype(a), decltype(b)>::type>(a,    \
                                                                         b);   \
       i < id4(end_, __LINE__); id4(iter_, __LINE__) += c)








  for (auto &&[i, id4(iter_, __LINE__), id4(end_, __LINE__)] = \
           range_tuple<std::common_type<decltype(a), decltype(b)>::type>(b,    \
                                                                         a);   \
       i >= id4(end_, __LINE__); id4(iter_, __LINE__) -= c)



  for (auto id4(_iter_, __LINE__) = n;                                 \
       id4(_iter_, __LINE__) > 0; --id4(_iter_, __LINE__))













  for (auto id4(_n_, __LINE__) = n; i < id4(_n_, __LINE__); ++i)

  for (auto id4(_n_, __LINE__) = n; i > id4(_n_, __LINE__); --i)

  int id3;                                                             \
  scan(id3)

  long long id3;                                                       \
  scan(id3)

  std::string id3;                                                     \
  scan(id3)

  char id3;                                                            \
  scan(id3)

  type name(id3);                                                      \
  scan(name)

  [] {                                                                         \
    std::cout << '\n';                                                         \
  }()

  std::vector<int> NAME(LEN);                                                  \
  scan(NAME);


  std::vector<long long> NAME(LEN);                                            \
  scan(NAME);


  std::vector<std::string> NAME(LEN);                                          \
  scan(NAME);




inline void Yn(bool p) {
  std::cout << (p ? "Yes\n" : "No\n");
}
inline void YN(bool p) {
  std::cout << (p ? "YES\n" : "NO\n");
}
inline void yn(bool p) {
  std::cout << (p ? "yes\n" : "no\n");
}
template<typename Container> Container inc(Container &&c) {
  for (auto &e : c)
    ++e;
  return c;
}
template<typename Container> Container dec(Container &&c) {
  for (auto &e : c)
    --e;
  return c;
}
template<typename A, typename B> inline bool chkmin(A &a, const B &b) {
  return b < a ? a = b, true : false;
}

template<typename A, typename B> inline bool chkmax(A &a, const B &b) {
  return a < b ? a = b, true : false;
}

template<typename Container> Container rev(Container &&c) {
  std::reverse(std::begin(c), std::end(c));
  return c;
}


template<typename Sequence> Sequence uniq(Sequence &&s) {
  s.erase(std::unique(std::begin(s), std::end(s)), std::end(s));
  return s;
}

template<typename Container> auto max(const Container &c) {
  return *std::max_element(std::begin(c), std::end(c));
}

template<typename Container> auto min(const Container &c) {
  return *std::min_element(std::begin(c), std::end(c));
}

template<typename Container> Container iota(Container &&c, int v = 0) {
  std::iota(std::begin(c), std::end(c), v);
  return c;
}

template<typename Container, typename Compare = void *>
Container sort(Container &&c, Compare comp = nullptr) {
  if constexpr (std::is_same_v<Compare, void *>)
    std::sort(std::begin(c), std::end(c));
  else
    std::sort(std::begin(c), std::end(c), comp);
  return c;
}

template<typename iterator> struct range {
  iterator beg_, end_;
  iterator begin() const { return beg_; }
  iterator end() const { return end_; }
  

  range(iterator beg, iterator end) : beg_(beg), end_(end) {}
};

template<typename T> struct reversion_wrapper { T &iterable; };
template<typename T> auto begin(reversion_wrapper<T> w) {
  using std::rbegin;
  return rbegin(w.iterable);
}
template<typename T> auto end(reversion_wrapper<T> w) {
  using std::rend;
  return rend(w.iterable);
}
template<typename T> reversion_wrapper<T> reverse(T &&iterable) {
  return {iterable};
}
template<typename T, typename U> T ceil_div(T x, U y) {
  assert(y > 0);
  T q = x / y;
  return q + (q * y < x);
}

template<typename T, typename U> T floor_div(T x, U y) {
  assert(y > 0);
  T q = x / y;
  return q - (q * y > x);
}

template<typename T, typename U> T ceil(T x, U y) {
  assert(y > 0);
  return ceil_div(x, y) * y;
}

template<typename T, typename U> T floor(T x, U y) {
  assert(y > 0);
  return floor_div(x, y) * y;
}

template<class...> struct typelist {};

template<class T, class... Ts>
constexpr bool any_same = (std::is_same_v<T, Ts> || ...);

template<class F> struct id2 {
  template<class... TLs> struct ref {
    id2 &self;
    template<class... Args> decltype(auto) operator()(Args &&...args) const {
      using G = std::conditional_t<any_same<typelist<Args...>, TLs...>,
                                   ref<TLs...>, ref<TLs..., typelist<Args...>>>;
      return self.f(G{self}, std::forward<Args>(args)...);
    }
  };
  F f;
  template<class... Args> decltype(auto) operator()(Args &&...args) {
    return ref<>{*this}(std::forward<Args>(args)...);
  }
};
template<class F> id2(F) -> id2<F>;






using namespace io;
using namespace std;



































class graph {
 protected:
  const int n;
  std::vector<std::vector<int>> g;

 public:
  explicit graph(int n) : n(n), g(n) { assert(n > 0); }
  int v_size() const { return n; }
  virtual void add_edge(int u, int v) = 0;
};



class undigraph : public graph {
  struct edge {
    int u, v;
    bool enabled = true;
  };
  int m = 0;
  int enabled_m = 0;
  std::vector<int> deg;
  std::vector<edge> edges;

 public:
  explicit undigraph(int n) : graph(n), deg(n) {}
  int e_size() const { return m; }
  int enabled_e_size() const { return enabled_m; }
  void add_edge(int u, int v) override {
    int id = (int) edges.size();
    g[u].push_back(id);
    g[v].push_back(id);
    edges.push_back({u, v});
    ++deg[u];
    ++deg[v];
    ++m;
    ++enabled_m;
  }
  void enable_edge(int i) {
    if (not edges[i].enabled) {
      edges[i].enabled = true;
      ++enabled_m;
      ++deg[edges[i].u];
      ++deg[edges[i].v];
    }
  }
  void disable_edge(int i) {
    if (edges[i].enabled) {
      edges[i].enabled = false;
      --enabled_m;
      --deg[edges[i].u];
      --deg[edges[i].v];
    }
  }
  const std::vector<int> &adjacent_edges(int u) const {
    assert(0 <= u and u < n);
    return g[u];
  }
  const edge &edge(int i) const { return edges[i]; }
  int degree(int i) const { return deg[i]; }
  bool is_enabled(int i) const {
    return edges[i].enabled;
  }
};





std::optional<std::vector<int>> id5(int u,
                                                        const undigraph &g) {
  int n = g.v_size(), m = g.e_size();
  std::vector<bool> used(m);
  std::vector<int> ptr(n);
  std::vector<int> res(g.enabled_e_size() + 1);
  int stack_ptr = 0;
  int write_ptr = g.enabled_e_size();
  res[0] = u;
  while (true) {
    bool found = false;
    while (ptr[u] < (int) g.adjacent_edges(u).size()) {
      int id = g.adjacent_edges(u)[ptr[u]++];
      if (not g.is_enabled(id) or used[id])
        continue;
      used[id] = true;
      auto &e = g.edge(id);
      u ^= e.u ^ e.v;
      res[++stack_ptr] = u;
      found = true;
      break;
    }
    if (not found) {
      res[write_ptr--] = u;
      if (stack_ptr == 0)
        break;
      u = res[--stack_ptr];
    }
  }
  if (write_ptr != -1)
    return nullopt;
  return res;
}

std::optional<std::vector<int>> id8(const undigraph &g) {
  int n = g.v_size();
  int odd = 0;
  int first = -1;
  for (int i = 0; i < n; ++i) {
    if (g.degree(i) & 1) {
      if (first == -1)
        first = i;
      odd++;
    }
  }
  if (odd > 2)
    return nullopt;
  return id5(first == -1 ? 0 : first, g);
}













































































































































































































































void solve() {
  INT(n, m);
  undigraph g(n);
  set<pii> E;
  rep (m) {
    INT(x, y);
    g.add_edge(x - 1, y - 1);
    E.ep(min(x, y), max(x, y));
  }
  assert(SZ(E) == m);
  auto res = id8(g);
  if (not res) {
    int id1 = 0;
    rng (i, n)
      id1 += g.degree(i) & 1;
    rng (i, n) {
      int id9 = g.degree(i) & 1;
      FOR (j, g.adjacent_edges(i)) {
        auto e = g.edge(j);
        int k = i ^ e.u ^ e.v;
        id9 += g.degree(k) & 1;
      }
      int id7 = id1 - id9;
      if (id7 >= 2)
        continue;
      FOR (j, g.adjacent_edges(i)) {
        auto &e = g.edge(j);
        int k = i ^ e.u ^ e.v;
        if (g.degree(k) & 1)
          g.disable_edge(j);
      }
      res = id5(i, g);
      if (not res and id7 == 0) {
        FOR (j, g.adjacent_edges(i)) {
          if (not g.is_enabled(j)) {
            g.enable_edge(j);
            res = id5(i, g);
            if (res)
              break;
            g.disable_edge(j);
          }
        }
      }
      if (res) {
        rev(*res).pb(-2);
        FOR (j, g.adjacent_edges(i)) {
          if (not g.is_enabled(j)) {
            auto e = g.edge(j);
            int k = i ^ e.u ^ e.v;
            res->pb(k);
            res->pb(i);
          }
        }
        break;
      }
      FOR (j, g.adjacent_edges(i))
        g.enable_edge(j);
    }
  }
  if (res) {
    pl(SZ(*res));
    pl(inc(*res));
    auto &s = *res;
    int c1 = 0;
    FOR (x, s)
      c1 += x == -1;
    assert(c1 <= 1);
    int u = s[0];
    int t = 0;
    int mode = 0;
    rng (i, 1, SZ(s)) {
      int v = s[i];
      if (v == -1) {
        mode = 1;
        continue;
      }
      auto it = E.find({min(u, v), max(u, v)});
      assert(it != E.end());
      if (mode == 0) {
        E.erase(it);
      } else {
        if (t) {
          E.erase(it);
        }
        t ^= 1;
      }
      u = v;
    }
    assert(E.empty());
  } else
    pl(0);
}



int main() {

  freopen(FILE_IO ".in", "r", stdin);
  freopen(FILE_IO ".out", "w", stdout);

  solve();
  return 0;
}
