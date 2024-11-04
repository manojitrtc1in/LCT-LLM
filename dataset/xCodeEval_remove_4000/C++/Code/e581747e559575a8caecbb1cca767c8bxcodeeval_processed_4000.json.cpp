




extern const bool id15 = true;
extern const bool id9 = false;








































template<typename T> T type();

template<typename Container> auto id7() {
  if constexpr (std::is_array_v<Container>)
    return type<std::remove_extent_t<Container>>();
  else
    return type<typename Container::value_type>();
}
template<typename Container>
using value_type_of =
    decltype(id7<std::remove_reference_t<Container>>());



namespace is_iterable_impl {
using std::begin, std::end;
template<typename T>
using check_specs = std::void_t<
    std::enable_if_t<
        std::is_same_v<decltype(begin(std::declval<T &>())),

                       decltype(end(std::declval<T &>()))   

                       >>,

    decltype(*begin(std::declval<T &>()))>;

template<typename, typename = void> struct is_iterable : std::false_type {};


template<class T> struct is_iterable<T, check_specs<T>> : std::true_type {};
}

template<class T> using is_iterable = is_iterable_impl::is_iterable<T>;
template<typename T> constexpr bool id12 = is_iterable<T>::value;



template<typename T>
using is_string =
    std::disjunction<std::is_same<char *, typename std::decay_t<T>>,
                     std::is_same<const char *, typename std::decay_t<T>>,
                     std::is_same<std::string, typename std::decay_t<T>>>;
template<typename T> constexpr bool id14 = is_string<T>::value;



template<template<typename...> typename Target, typename Aux, typename... Ts>
struct is_specialized_for_impl : std::false_type {};

template<template<typename...> typename Target, typename... Args>
struct is_specialized_for_impl<Target, decltype(sizeof(Target<Args...>)),
                               Args...> : std::true_type {};

template<template<typename...> typename Target, typename... Args>
using is_specialized_for =
    is_specialized_for_impl<Target, std::size_t, Args...>;
template<template<typename...> typename Target, typename... Args>
constexpr bool id2 =
    is_specialized_for<Target, Args...>::value;

template<typename T>
using is_tuple_like = is_specialized_for<std::tuple_size, T>;
template<typename T> constexpr bool id5 = is_tuple_like<T>::value;

template<typename T, typename = void> struct remove_all_extents_ {
  typedef std::remove_reference_t<T> type;
};

template<typename T>
struct remove_all_extents_<T, std::void_t<decltype(std::declval<T>()[0])>> {
  typedef
      typename remove_all_extents_<decltype(std::declval<T>()[0])>::type type;
};

template<typename T, typename = void>
struct rank_ : public std::integral_constant<std::size_t, 0> {};

template<typename T>
struct rank_<T, std::void_t<decltype(std::declval<T>()[0])>>
    : public std::integral_constant<
          std::size_t, rank_<decltype(std::declval<T>()[0])>::value + 1> {};




struct fast_ios {
  fast_ios() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cout.precision(10);
    std::cout << std::fixed;
  };
} const id1;

namespace io {
template<typename T, typename U>
std::ostream &operator<<(std::ostream &out, const std::pair<T, U> &p);
template<typename... Ts>
std::istream &operator>>(std::istream &in, std::tuple<Ts...> &t);
template<typename... Ts>
std::ostream &operator<<(std::ostream &, const std::tuple<Ts...> &);

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
std::istream &operator>>(std::istream &in, std::tuple<Ts...> &t) {
  std::apply([&in](auto &...args) { ((in >> args), ...); }, t);
  return in;
}

template<class... Args> void scan(Args &...args) {
  ((std::cin >> args), ...);
}

template<typename Container,
         typename = std::enable_if_t<std::conjunction_v<
             is_iterable<Container>, std::negation<is_string<Container>>>>>
std::ostream &operator<<(std::ostream &out, const Container &container) {
  using std::begin;
  using value_type =
      std::remove_reference_t<decltype(*begin(std::declval<Container &>()))>;
  constexpr char delimiter =
      id12<value_type> or id5<value_type> ? '\n' : ' ';
  bool first = true;
  for (auto &element : container) {
    if (first)
      first = false;
    else
      out << delimiter;
    out << element;
  }
  return out;
}



template<typename... Ts>
std::ostream &operator<<(std::ostream &out, const std::tuple<Ts...> &theTuple) {
  std::apply(
      [&out](Ts const &...tupleArgs) {
        std::size_t n{0};
        ((out << tupleArgs << (++n != sizeof...(Ts) ? " " : "")), ...);
      },
      theTuple);
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
  explicit ndarray(Args&&... args)
      : std::vector<T>(std::forward<Args>(args)...) {}
};



























  id13(SELECT_SECOND_ARG, COMMA peek arg1, arg2)



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

  ([] {                                                                        \
    int x;                                                                     \
    std::cin >> x;                                                             \
    return x;                                                                  \
  })()

  std::vector<int> NAME(LEN);                                                  \
  scan(NAME);


  std::vector<std::pair<int, int>> NAME(LEN);                                  \
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
  return std::forward<Container>(c);
}
template<typename Container> Container dec(Container &&c) {
  for (auto &e : c)
    --e;
  return std::forward<Container>(c);
}
template<typename A, typename B> inline bool chkmin(A &a, const B &b) {
  return b < a ? a = b, true : false;
}

template<typename A, typename B> inline bool chkmax(A &a, const B &b) {
  return a < b ? a = b, true : false;
}

template<typename Container> Container rev(Container &&c) {
  std::reverse(std::begin(c), std::end(c));
  return std::forward<Container>(c);
}


template<typename Sequence> Sequence uniq(Sequence &&s) {
  assert(std::is_sorted(std::begin(s), std::end(s)));
  s.erase(std::unique(std::begin(s), std::end(s)), std::end(s));
  return std::forward<Sequence>(s);
}

template<typename Container> auto max(const Container &c) {
  assert(std::size(c) > 0);
  return *std::max_element(std::begin(c), std::end(c));
}

template<typename Container> auto min(const Container &c) {
  assert(std::size(c) > 0);
  return *std::min_element(std::begin(c), std::end(c));
}

template<typename Array> int maxi(const Array &a) {
  assert(a.size() > 0);
  return int(std::max_element(std::begin(a), std::end(a)) - std::begin(a));
}

template<typename Array> int mini(const Array &a) {
  assert(a.size() > 0);
  return int(std::min_element(std::begin(a), std::end(a)) - std::begin(a));
}

template<typename Array, typename Value> auto lb(const Array &a, Value v) {
  assert(std::size(a) > 0);
  return std::lower_bound(std::begin(a), std::end(a), v);
}

template<typename Array, typename Value> auto ub(const Array &a, Value v) {
  assert(std::size(a) > 0);
  return std::upper_bound(std::begin(a), std::end(a), v);
}

template<typename Array, typename Value> int lbi(const Array &a, Value v) {
  return int(lb(a, v) - std::begin(a));
}

template<typename Iter, typename Value> int lbi(Iter beg, int count, Value v) {
  assert(count > 0);
  return int(std::lower_bound(beg, beg + count, v) - beg);
}

template<typename Iter, typename Value> int ubi(Iter beg, int count, Value v) {
  assert(count > 0);
  return int(std::upper_bound(beg, beg + count, v) - beg);
}

template<typename Array, typename Value> int ubi(const Array &a, Value v) {
  return int(ub(a, v) - std::begin(a));
}

template<typename Container>
Container iota(Container &&c, value_type_of<Container> v) {
  std::iota(std::begin(c), std::end(c), v);
  return std::forward<Container>(c);
}

template<typename Container, typename Compare = void *>
Container sort(Container &&c, Compare comp = nullptr) {
  if constexpr (std::is_same_v<Compare, void *>)
    std::sort(std::begin(c), std::end(c));
  else
    std::sort(std::begin(c), std::end(c), comp);
  return std::forward<Container>(c);
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
  return {std::forward<T>(iterable)};
}



template<typename T, typename U> T qceil(T x, U y) {
  assert(y > 0);
  T q = x / y;
  return q + (q * y < x);
}



template<typename T, typename U> T qfloor(T x, U y) {
  assert(y > 0);
  T q = x / y;
  return q - (q * y > x);
}



template<typename T, typename U> T mceil(T x, U y) {
  assert(y > 0);
  return qceil(x, y) * y;
}



template<typename T, typename U> T mfloor(T x, U y) {
  assert(y > 0);
  return qfloor(x, y) * y;
}

template<class...> struct typelist {};

template<class T, class... Ts>
constexpr bool any_same = (std::is_same_v<T, Ts> || ...);

template<class F> struct id6 {
  template<class... TLs> struct ref {
    id6 &self;
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
template<class F> id6(F) -> id6<F>;
std::mt19937_64
    RNG(std::chrono::steady_clock::now().time_since_epoch().count());

template<typename T> constexpr T INF = std::numeric_limits<T>::max() / 2;



template<typename T, typename U> T acc(const U& array) {
  return std::accumulate(std::begin(array), std::end(array), T(0));
}







using namespace io;
using namespace std;






template<typename T> std::vector<T> id11(T n) {
  std::vector<T> res;
  for (T i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      res.push_back(i);
      do {
        n /= i;
      } while (n % i == 0);
    }
  }
  if (n > 1)
    res.push_back(n);
  return res;
}

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

template<typename T> std::vector<std::pair<T, int>> id3(T n) {
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



std::vector<int> id10(int n) {
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

std::vector<int> id8(int n) {
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

template<typename T> T phi(T n) {
  assert(n > 0);
  T result = 1;
  for (T i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      n /= i;
      T t = 1;
      while (n % i == 0) {
        n /= i;
        t *= i;
      }
      result *= t * (i - 1);
    }
  }
  if (n > 1)
    result *= n - 1;
  return result;
}







std::vector<int> get_mu(int n) {
  assert(n > 0);
  std::vector<int> mu(n + 1, 1);
  mu[0] = 0;
  for (int i = 2; i * i <= n; i++) {
    if (mu[i] == 1) {

      for (int j = i; j <= n; j += i) {
        mu[j] *= -i;
      }
      for (int k = i * i, j = k; j <= n; j += k) {
        mu[j] = 0;
      }
    }
  }
  for (int i = 2; i <= n; i++) {
    if (mu[i] == i)
      mu[i] = 1;
    else if (mu[i] == -i)
      mu[i] = -1;
    else if (mu[i] > 0)
      mu[i] = -1;
    else if (mu[i] < 0)
      mu[i] = 1;
    

  }
  return mu;
}


template<typename Int> struct randint {
  std::uniform_int_distribution<Int> dist;
  randint(Int a = std::numeric_limits<Int>::min(),
          Int b = std::numeric_limits<Int>::max())
      : dist(a, b) {}
  Int operator()() { return dist(RNG); }
};

void solve() {
  INT(n);
  vector<ull> h(n + 1);
  vb is_prime(n + 1, true);

  randint<ull> rand;

  up (i, 2, n)
    if (is_prime[i]) {
      h[i] = rand();
      up (j, 2 * i, n, i) {
        is_prime[j] = false;
        int k = j;
        while (k % i == 0)
          h[j] ^= h[i], k /= i;
      }
    }

  vector<ull> hf(n + 1);
  up (i, 2, n)
    hf[i] = h[i] xor hf[i - 1];
  ull sum = 0;
  up (i, 1, n)
    sum ^= hf[i];
  if (sum == 0) {
    pl(n);
    up (i, 1, n)
      pt(i);
    NL;
    return;
  }
  up (i, 1, n)
    if (hf[i] == sum) {
      pl(n - 1);
      up (j, 1, n)
        if (j != i)
          pt(j);
      NL;
      return;
    }

  map<ull, int> which;
  up (i, 1, n)
    which[hf[i]] = i;
  up (i, 1, n) {
    ull t = sum xor hf[i];
    auto it = which.find(t);
    if (it != which.end()) {
      pl(n - 2);
      up (j, 1, n)
        if (j != i and j != it->second)
          pt(j);
      NL;
      return;
    }
  }
  pl(n - 3);
  vi ex = {n, 2, (n - 1) / 2};
  up (i, 1, n) {
    bool ok = true;
    FOR (x, ex)
      if (i == x) {
        ok = false;
        break;
      }
    if (ok)
      pt(i);
  }
  NL;
}




int main() {

  freopen(FILE_IO ".in", "r", stdin);
  freopen(FILE_IO ".out", "w", stdout);

  solve();
  return 0;
}
