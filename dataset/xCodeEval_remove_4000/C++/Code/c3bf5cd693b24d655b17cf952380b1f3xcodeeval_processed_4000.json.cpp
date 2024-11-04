




extern const bool id5 = false;
extern const bool id2 = false;



























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
  using std::vector<ndarray<dimension - 1, T>>::vector;
  template<typename... Args>
  ndarray(unsigned d, Args... args)
      : std::vector<ndarray<dimension - 1, T>>(
          d, ndarray<dimension - 1, T>(args...)) {}
};
template<typename T> class ndarray<1, T> : public std::vector<T> {
 public:
  using std::vector<T>::vector;
  template<typename... Args>
  ndarray<1, T>(Args &&...args) : std::vector<T>(std::forward<Args>(args)...) {}
};



























  id1(SELECT_SECOND_ARG, COMMA peek arg1, arg2)



  function(arg1, arg2) TERMINATE_OR(peek, FOR_EACH_2_IMPL1)                    \
      PAUSE(function, peek, __VA_ARGS__)


  function(arg1, arg2) TERMINATE_OR(peek, FOR_EACH_2_IMPL0)                    \
      PAUSE(function, peek, __VA_ARGS__)


  EXPAND_13(FOR_EACH_2_IMPL0(function, __VA_ARGS__, ()))




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

  for (auto &&[i, JOIN(iter_, __LINE__), JOIN(end_, __LINE__)] =               \
           range_tuple<std::common_type<decltype(a), decltype(b)>::type>(a,    \
                                                                         b);   \
       i < JOIN(end_, __LINE__); JOIN(iter_, __LINE__) += c)








  for (auto &&[i, JOIN(iter_, __LINE__), JOIN(end_, __LINE__)] =               \
           range_tuple<std::common_type<decltype(a), decltype(b)>::type>(b,    \
                                                                         a);   \
       i >= JOIN(end_, __LINE__); JOIN(iter_, __LINE__) -= c)



  for (auto JOIN(_iter_, __LINE__) = n; JOIN(_iter_, __LINE__) > 0;            \
       --JOIN(_iter_, __LINE__))



  id4(peek, FOR_LAST_OPERATION_IMPL, FOR_NORMAL_OPERATION_IMPL)        \
  (arg1, arg2) TERMINATE_OR(peek, FOR_IMPL1) PAUSE(arg2, peek, __VA_ARGS__)

  id4(peek, FOR_LAST_OPERATION_IMPL, FOR_NORMAL_OPERATION_IMPL)        \
  (arg1, arg2) TERMINATE_OR(peek, FOR_IMPL0) PAUSE(arg2, peek, __VA_ARGS__)

  id4(peek, for (auto && arg1 : arg2),                                 \
  for (auto && [EXPAND_13(FOR_IMPL0(arg1, arg2, peek, __VA_ARGS__))))













  for (auto JOIN(_n_, __LINE__) = n; i < JOIN(_n_, __LINE__); ++i)

  for (auto JOIN(_n_, __LINE__) = n; i > JOIN(_n_, __LINE__); --i)

  int __VA_ARGS__;                                                             \
  scan(__VA_ARGS__)

  long long __VA_ARGS__;                                                       \
  scan(__VA_ARGS__)

  std::string __VA_ARGS__;                                                     \
  scan(__VA_ARGS__)

  char __VA_ARGS__;                                                            \
  scan(__VA_ARGS__)

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
  assert(std::size(c) > 0);
  return *std::max_element(std::begin(c), std::end(c));
}

template<typename Container> auto min(const Container &c) {
  assert(std::size(c) > 0);
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

template<class F> struct id3 {
  template<class... TLs> struct ref {
    id3 &self;
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
template<class F> id3(F) -> id3<F>;






using namespace io;
using namespace std;




void solve() {
  INT(n);
  VI(a, n, b, n);
  ll sum = 0;
  rng (i, n)
    sum += abs(a[i] - b[i]);
  int delta = 0;

  

  

  

  

  

  auto solve = [&](vi a, vi b) {
    vi ib(n);
    sort(iota(ib), [&](int i, int j) { return b[i] < b[j]; });
    multiset<int> s;
    pq<int> q;
    FOR (i, ib) {
      while (not q.empty()) {
        auto [val, j] = q.top();
        if (val < b[i]) {
          s.erase(s.find(b[j]));
          q.pop();
        } else
          break;
      }
      auto it = s.lower_bound(a[i]);
      if (it != s.end() and *it < b[i]) {
        chkmax(delta, b[i] - *it);
      }
      s.insert(b[i]);
      q.ep(a[i], i);
    }
  };
  solve(a, b);
  solve(b, a);
  

  auto solve2 = [&](vi a, vi b) {
    vii outer, inner;
    rng (i, n) {
      if (a[i] < b[i])
        outer.eb(a[i], b[i]);
      else if (b[i] < a[i])
        inner.eb(b[i], a[i]);
    }
    auto compare = [](in p1, in p2) {
      return p1.first < p2.first;
    };
    sort(outer, compare);
    sort(inner, compare);
    auto ptr = begin(outer);
    int max_r = 0;
    FOR (l, r, inner) {
      while (ptr != end(outer) and ptr->first <= l) {
        chkmax(max_r, ptr->second);
        ++ptr;
      }
      if (r <= max_r)
        chkmax(delta, r - l);
    }
  };
  debug(delta);
  solve2(a, b);
  solve2(b, a);
  pl(sum - 2 * delta);
}



int main() {

  freopen(FILE_IO ".in", "r", stdin);
  freopen(FILE_IO ".out", "w", stdout);

  solve();
  return 0;
}
