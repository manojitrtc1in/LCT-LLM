




extern const bool id7 = false;
extern const bool id5 = false;









































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
  if (x > 0)
    x += y - 1;
  return x / y;
}

template<typename T, typename U> T floor_div(T x, U y) {
  assert(y > 0);
  if (x < 0)
    x -= y - 1;
  return x / y;
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

template<class F> struct id1 {
  template<class... TLs> struct ref {
    id1 &self;
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
template<class F> id1(F) -> id1<F>;






using namespace io;
using namespace std;














template<typename int_t> inline int_t lowbit(int_t x) {
  return x & -x;
}

inline int h_bit(unsigned long long x) {
  return int(sizeof(unsigned long long) * 8 - __builtin_clzll(x));
}

unsigned long long pow2(unsigned long long x) {

  if (x == 0)
    return 1;
  return x == lowbit(x) ? x : 1ull << h_bit(x);
}

template<typename T> inline int bit(T a, int i) {
  return a >> i & 1;
}

inline bool is_subset(int sub, int s) {
  return (sub & s) == sub;
}



template<typename T> struct subset_tuple {
  explicit subset_tuple(T u) : s(u), u(u) {}
  const T &ref = s;
  T s;
  const T u;
};


  for (auto &&[s, id4(subset_, __LINE__),                              \
               id4(set_, __LINE__)] = subset_tuple(u);                 \
       s > 0;                                                                  \
       id4(subset_, __LINE__) = (s - 1) & id4(set_, __LINE__))


class lca_tree {
  const int n;
  const int h;
  const std::vector<int> &depth;
  std::vector<std::vector<int>> a;

 public:
  lca_tree(const std::vector<int> &p, const std::vector<int> &depth)
      : n((int) p.size()), h(h_bit(*max_element(depth.begin(), depth.end()))),
        depth(depth), a(n, std::vector<int>(h)) {
    for (int i = 0; i < n; ++i)
      a[i][0] = p[i];
    for (int j = 1; j < h; ++j)
      for (int i = 0; i < n; ++i)
        a[i][j] = a[i][j - 1] == -1 ? -1 : a[a[i][j - 1]][j - 1];
  }

  int ancestor(int u, int d) const {
    assert(0 <= d and d < 1 << h);
    for (int i = 0; i < h; ++i) {
      if (bit(d, i))
        u = a[u][i];
    }
    return u;
  }

  int lca(int u, int v) const {
    if (depth[u] < depth[v])
      std::swap(u, v);
    u = ancestor(u, depth[u] - depth[v]);
    if (u == v)
      return u;
    for (int i = h - 1; i >= 0; i--)
      if (a[u][i] != a[v][i])
        u = a[u][i], v = a[v][i];
    return a[u][0];
  }
};




void solve() {
  

  

  

  

  

  

  


  INT(n);
  vv<int> g(n);
  rep (n - 1) {
    INT(u, v);
    --u, --v;
    g[u].pb(v);
    g[v].pb(u);
  }
  vi cnt_end(n);

  vi cnt2(n);


  vi depth(n, -1);
  depth[0] = 0;
  vi p(n, -1);
  id1{[&](auto dfs, int u) -> void {
    FOR (v, g[u]) {
      if (depth[v] == -1) {
        depth[v] = depth[u] + 1;
        p[v] = u;
        dfs(v);
      }
    }
  }}(0);

  lca_tree t(p, depth);
  INT(m);
  vv<pii> id6(n);
  rep (m) {
    INT(u, v);
    --u, --v;
    cnt_end[u]++;
    cnt_end[v]++;
    id6[t.lca(u, v)].eb(u, v);
  }

  id1{[&](auto dfs, int u, int p) -> void {
    cnt2[u] = SZ(id6[u]);
    FOR (v, g[u]) {
      if (v != p) {
        dfs(v, u);
        cnt2[u] += cnt2[v];
        cnt_end[u] += cnt_end[v];
      }
    }
  }}(0, -1);

  auto n_pair = [](int x) {
    return 1LL * x * (x - 1);
  };

  ll ans = 0;
  vi id2(n);

  rng (i, n) {
    map<pii, int> cnt;
    for (auto [x, y] : id6[i]) {
      int _x = -1, _y = -1;
      if (x != i) {
        _x = t.ancestor(x, depth[x] - depth[i] - 1);
        id2[_x]++;
      }
      if (y != i) {
        _y = t.ancestor(y, depth[y] - depth[i] - 1);
        id2[_y]++;
      }
      if (_x != -1 and _y != -1) {
        debug(_x, _y);
        int X = min(_x, _y);
        int Y = max(_x, _y);
        cnt[{X, Y}]++;
      }
    }
    for (auto &&[x, y] : cnt) {
      ans += n_pair(y);
      debug(i, y);
    }
  }

  rng (i, n) {
    int cnt1 = cnt_end[i] - 2 * cnt2[i];
    int cnt_pass = cnt1 + SZ(id6[i]);
    ans += n_pair(cnt_pass);
    ans -= n_pair(cnt1);
    ans -= n_pair(cnt1);
    ans += n_pair(cnt1 - id2[i]);
  }
  pl(ans / 2);
}



int main() {

  freopen(FILE_IO ".in", "r", stdin);
  freopen(FILE_IO ".out", "w", stdout);

  solve();
  return 0;
}
