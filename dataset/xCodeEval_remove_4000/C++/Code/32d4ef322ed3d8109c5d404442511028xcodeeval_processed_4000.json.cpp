




extern const bool id6 = false;
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
class vec : public std::vector<vec<dimension - 1, T>> {
 public:
  template<typename... Args>
  vec(unsigned d, Args... args)
      : std::vector<vec<dimension - 1, T>>(d, vec<dimension - 1, T>(args...)) {}
};
template<typename T> class vec<1, T> : public std::vector<T> {
 public:
  template<typename... Args>
  vec<1, T>(Args &&...args) : std::vector<T>(std::forward<Args>(args)...) {}
};



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
template<typename T, typename U = std::less<T>>
using pq = std::priority_queue<T, std::vector<T>, U>;
template<typename... Ts> using vt = std::vector<std::tuple<Ts...>>;
template<typename T> using vv = vec<2, T>;
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
template<typename T, typename U> T ceil(T x, U y) {
  assert(y > 0);
  if (x > 0)
    x += y - 1;
  return x / y;
}

template<typename T, typename U> T floor(T x, U y) {
  assert(y > 0);
  if (x < 0)
    x -= y - 1;
  return x / y;
}

template<class...> struct typelist {};

template<class T, class... Ts>
constexpr bool any_same = (std::is_same_v<T, Ts> || ...);

template<class F> struct id2 {
  template<class... TLs> struct ref {
    id2 &self;
    template<class... Args> decltype(auto) operator()(Args &&... args) const {
      using G = std::conditional_t<any_same<typelist<Args...>, TLs...>,
                                   ref<TLs...>, ref<TLs..., typelist<Args...>>>;
      return self.f(G{self}, std::forward<Args>(args)...);
    }
  };
  F f;
  template<class... Args> decltype(auto) operator()(Args &&... args) {
    return ref<>{*this}(std::forward<Args>(args)...);
  }
};
template<class F> id2(F) -> id2<F>;






using namespace io;
using namespace std;


































template<typename Int> constexpr Int midpoint(Int a, Int b) noexcept {
  using U = std::make_unsigned_t<Int>;
  int sign = 1;
  U m = a;
  U M = b;
  if (a > b) {
    sign = -1;
    m = b;
    M = a;
  }
  return a + sign * Int(U(M - m) >> 1);
}



template<typename Compare>
int id1(int L, int R, const Compare &compare) {
  assert(L <= R);
  

  

  while (L < R) {
    int mid = L + (R - L) / 2, mm = mid + 1 + (R - mid - 1) / 2;
    if (compare(mid, mm)) {
      

      R = mm - 1;
    } else {
      

      L = mid + 1;
    }
  }
  assert(L == R);
  return L;
}








template<typename Int, typename Check>
std::optional<Int> bin_search(Int L, Int R, const Check &check, int type = 0,
                              bool knowingly = false) {
  Int l = L, r = R;
  std::optional<Int> ans;
  while (l <= r) {
    if (l == r and knowingly) {
      ans = l;
      break;
    }
    Int m = midpoint(l, r);
    int res = check(m);
    if (res == -1) {
      if (m == R)
        break;
      l = m + 1;
    } else if (res == 1) {
      if (m == L)
        break;
      r = m - 1;
    } else {
      ans = m;
      if (type == 0)
        break;
      knowingly = false;
      if (type == -1) {
        if (m == L)
          break;
        else
          r = m - 1;
      } else {
        if (m == R)
          break;
        else
          l = m + 1;
      }
    }
  }
  return ans;
}
template<typename Int, typename Check>
std::optional<Int> find_first(Int L, Int R, const Check &check) {
  std::optional<Int> ans;
  Int l = L, r = R;
  while (l <= r) {
    Int m = midpoint(l, r);
    if (check(m)) {
      ans = m;
      if (m == L)
        break;
      r = m - 1;
    } else {
      if (m == R)
        break;
      l = m + 1;
    }
  }
  return ans;
}
template<typename Int, typename Check>
std::optional<Int> find_last(Int L, Int R, const Check &check) {
  std::optional<Int> ans;
  Int l = L, r = R;
  while (l <= r) {
    Int m = midpoint(l, r);
    if (check(m)) {
      ans = m;
      if (m == R)
        break;
      l = m + 1;
    } else {
      if (m == L)
        break;
      r = m - 1;
    }
  }
  return ans;
}



void solve() {
  INT(n, k);

  int m = min(320, n / 2 - 1);
  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  auto ask = [&](int q) {
    cout << "? " << q << endl;
    

    

    

    

    return ri();
  };
  rep (m)
    ask(1);
  up (i, 1, n, m)
    if (ask(i) > k) {
      int ans = i - *find_first(1, m, [&, i = i](int x) {
                  int t = i - x;
                  if (t <= 0)
                    t += n;
                  return ask(t) <= k;
                });
      if (ans <= 0)
        ans += n;
      rp("!", ans);
    }
}



int main() {

  freopen(FILE_IO ".in", "r", stdin);
  freopen(FILE_IO ".out", "w", stdout);

  solve();
  return 0;
}
