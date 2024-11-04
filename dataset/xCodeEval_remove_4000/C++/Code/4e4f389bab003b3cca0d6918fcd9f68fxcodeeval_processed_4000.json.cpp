




extern const bool id8 = false;
extern const bool id7 = false;

template<typename T> std::vector<T> id0(T n) {
  std::vector<T> res;
  T i = 1;
  for (; (unsigned long long) i * i < n; ++i) {
    if (n % i == 0) {
      res.push_back(i);
    }
  }
  int j = (int) res.size() - 1;
  if ((unsigned long long) i * i == n)
    res.push_back(i);
  while (j >= 0) {
    res.push_back(n / res[j]);
    --j;
  }
  return res;
}

template<typename T> std::vector<std::pair<T, int>> id2(T n) {
  std::vector<std::pair<T, int>> res;
  for (T i = 2; (unsigned long long) i * i <= n; ++i) {
    int cnt = 0;
    while (n % i == 0) {
      n /= i;
      ++cnt;
    }
    if (cnt) {
      res.emplace_back(i, cnt);
    }
  }
  if (n > 1) {
    res.emplace_back(n, 1);
  }
  return res;
}

template<typename T> std::vector<T> factorize(T n) {
  std::vector<T> res;
  for (T i = 2; (unsigned long long) i * i <= n; ++i) {
    T t = 1;
    while (n % i == 0) {
      t *= i;
      n /= i;
    }
    if (t > 1)
      res.push_back(t);
  }
  if (n > 1)
    res.push_back(n);
  return res;
}

std::vector<int> get_prime(int n) {
  std::vector<int> mpf(n + 1);
  std::vector<int> primes;
  for (int i = 2; i <= n; i++) {
    if (mpf[i] == 0) {
      mpf[i] = i;
      primes.push_back(i);
    }
    const int max_p = std::min(mpf[i], n / i);
    for (auto p : primes) {
      if (p <= max_p)
        mpf[p * i] = p;
      else
        break;
    }
  }
  return primes;
}

std::vector<int> id6(int n) {
  std::vector<int> mpf(n + 1);
  std::vector<int> primes;
  for (int i = 2; i <= n; i++) {
    if (mpf[i] == 0) {
      mpf[i] = i;
      primes.push_back(i);
    }
    const int max_p = std::min(mpf[i], n / i);
    for (int p : primes) {
      if (p <= max_p)
        mpf[p * i] = p;
      else
        break;
    }
  }
  return mpf;
}

long long gcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long t = gcd(b, a % b, y, x);
  

  

  

  y -= x * (a / b);
  return t;
}










































struct fast_ios {
  fast_ios() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cout.precision(10);
    std::cout << std::fixed;
  };
} id1;
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
  ndarray() = default;
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






  f(x, y) MAP_NEXT(peek, MAP1)(f, peek, id4)

  f(x, y) MAP_NEXT(peek, MAP0)(f, peek, id4)





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

  for (auto &&[i, id5(iter_, __LINE__), id5(end_, __LINE__)] = \
           range_tuple<std::common_type<decltype(a), decltype(b)>::type>(a,    \
                                                                         b);   \
       i < id5(end_, __LINE__); id5(iter_, __LINE__) += c)








  for (auto &&[i, id5(iter_, __LINE__), id5(end_, __LINE__)] = \
           range_tuple<std::common_type<decltype(a), decltype(b)>::type>(b,    \
                                                                         a);   \
       i >= id5(end_, __LINE__); id5(iter_, __LINE__) -= c)



  for (auto id5(_iter_, __LINE__) = n;                                 \
       id5(_iter_, __LINE__) > 0; --id5(_iter_, __LINE__))













  for (auto id5(_n_, __LINE__) = n; i < id5(_n_, __LINE__); ++i)

  for (auto id5(_n_, __LINE__) = n; i > id5(_n_, __LINE__); --i)

  int id4;                                                             \
  scan(id4)

  long long id4;                                                       \
  scan(id4)

  std::string id4;                                                     \
  scan(id4)

  char id4;                                                            \
  scan(id4)

  type name(id4);                                                      \
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
  const int max_n = 20000000;
  auto mpf = id6(max_n);
  

  vi npf(max_n + 1);
  up (i, 2, max_n) {
    int j = i / mpf[i];
    npf[i] = npf[j] + (mpf[i] != mpf[j]);
  }
  INT(ncase);
  rep (ncase) {
    INT(c, d, x);
    auto g = gcd(c, d);
    if (x % g) {
      pl(0);
      continue;
    }
    c /= g, d /= g, x /= g;
    ll ans = 0;
    auto check = [&](int y) {
      int t = d + y;
      if (t % c)
        return;
      ans += 1LL << npf[t / c];
    };
    int i = 1;
    for (; i * i < x; ++i) {
      if (x % i == 0)
        check(i), check(x / i);
    }
    if (i * i == x)
      check(i);
    pl(ans);
  }
}



int main() {

  freopen(FILE_IO ".in", "r", stdin);
  freopen(FILE_IO ".out", "w", stdout);

  solve();
  return 0;
}
