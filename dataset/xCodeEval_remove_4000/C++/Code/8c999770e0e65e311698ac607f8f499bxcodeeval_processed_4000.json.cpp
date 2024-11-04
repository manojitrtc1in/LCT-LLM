




extern constexpr bool id4 = false;



























struct fast_ios {
  fast_ios() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cout.precision(10);
    std::cout << std::fixed;
  };
} id0;
namespace io {
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
  std::apply([&in](auto &... args) { ((in >> args), ...); }, t);
  return in;
}

template<class... Args> void scan(Args &... args) {
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

template<typename... Args> void pt(Args &&... args) {
  ((std::cout << args << ' '), ...);
}

template<typename First, typename... Args>
void pl(const First &first, const Args &... args) {
  std::cout << first;
  ((std::cout << ' ' << args), ...);
  std::cout << '\n';
}

template<typename... Args> void pn(const Args &... args) {
  ((std::cout << args << '\n'), ...);
}
}

inline int ri() {
  int x;
  std::cin >> x;
  return x;
}



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
template<typename T> class vv {
  std::vector<std::vector<T>> data;

 public:
  explicit vv(int n) {
    assert(n > 0);
    data.assign(n, std::vector<T>{});
  }
  vv(int n, int m, T init = T{}) {
    assert(n > 0 && m > 0);
    data.assign(n, std::vector<T>(m, init));
  }
  std::vector<T> &operator[](size_t i) {
    assert(i < data.size());
    return data[i];
  }
  void fill(T val) {
    for (auto &row : data)
      std::fill(row.begin(), row.end(), val);
  }
  friend std::istream &operator>>(std::istream &in, vv<T> &val) {
    return io::operator>>(in, val.data);
  }
  friend std::ostream &operator<<(std::ostream &out, const vv<T> &val) {
    return io::operator<<(out, val.data);
  }
  friend auto begin(vv<T> &val) { return val.data.begin(); }
  friend auto end(vv<T> &val) { return val.data.end(); }
  friend auto rbegin(vv<T> &val) { return val.data.rbegin(); }
  friend auto rend(vv<T> &val) { return val.data.rend(); }
};



  for (std::common_type<decltype(a), decltype(b)>::type                        \
           i = a,                                                              \
           id2(r_end_, __LINE__) = b;                                  \
       i < id2(r_end_, __LINE__); ++i)




  for (std::common_type<decltype(a), decltype(b)>::type                        \
           i = a,                                                              \
           id2(r_end_, __LINE__) = b;                                  \
       i <= id2(r_end_, __LINE__); ++i)

  for (std::common_type<decltype(a), decltype(b)>::type                        \
           i = b,                                                              \
           id2(r_end_, __LINE__) = a;                                  \
       i >= id2(r_end_, __LINE__); --i)

  for (auto id2(_iter_, __LINE__) = n;                                 \
       id2(_iter_, __LINE__) > 0; --id2(_iter_, __LINE__))














  for (auto id2(_n_, __LINE__) = n; i < id2(_n_, __LINE__); ++i)






inline void Yn(bool p) {
  std::cout << (p ? "Yes\n" : "No\n");
}
inline void YN(bool p) {
  std::cout << (p ? "YES\n" : "NO\n");
}
inline void yn(bool p) {
  std::cout << (p ? "yes\n" : "no\n");
}
template<typename T> T &inc(T &cont) {
  for (auto &e : cont)
    ++e;
  return cont;
}
template<typename T> T &dec(T &cont) {
  for (auto &e : cont)
    --e;
  return cont;
}
template<typename A, typename B> inline bool chkmin(A &a, const B &b) {
  return b < a ? a = b, true : false;
}

template<typename A, typename B> inline bool chkmax(A &a, const B &b) {
  return a < b ? a = b, true : false;
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

template<class F> struct id1 {
  template<class... TLs> struct ref {
    id1 &self;
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
template<class F> id1(F) -> id1<F>;






using namespace io;
using namespace std;









template<typename T> T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a;
    std::swap(a, m);
    u -= t * v;
    std::swap(u, v);
  }
  assert(m == 1);
  return u;
}

template<typename T> class Modular {
 public:
  using Type = typename std::decay<decltype(T::value)>::type;

  constexpr Modular() : value() {}

  template<typename U> Modular(const U &x) { value = normalize(x); }

  template<typename U> static Type normalize(const U &x) {
    Type v;
    if (-mod() <= x && x < mod())
      v = static_cast<Type>(x);
    else
      v = static_cast<Type>(x % mod());
    if (v < 0)
      v += mod();
    return v;
  }

  const Type &operator()() const { return value; }

  template<typename U> explicit operator U() const {
    return static_cast<U>(value);
  }

  constexpr static Type mod() { return T::value; }

  Modular &operator+=(const Modular &other) {
    if ((value += other.value) >= mod())
      value -= mod();
    return *this;
  }

  Modular &operator-=(const Modular &other) {
    if ((value -= other.value) < 0)
      value += mod();
    return *this;
  }

  template<typename U> Modular &operator+=(const U &other) {
    return *this += Modular(other);
  }

  template<typename U> Modular &operator-=(const U &other) {
    return *this -= Modular(other);
  }

  Modular &operator++() { return *this += 1; }

  Modular &operator--() { return *this -= 1; }

  Modular operator++(int) {
    Modular result(*this);
    *this += 1;
    return result;
  }

  Modular operator--(int) {
    Modular result(*this);
    *this -= 1;
    return result;
  }

  Modular operator-() const { return Modular(-value); }

  template<typename U = T>
  typename std::enable_if<std::is_same<typename Modular<U>::Type, int>::value,
                          Modular>::type &
  operator*=(const Modular &rhs) {

    uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
    uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x),
             d, m;
    asm("divl %4; \n\t" : "=a"(d), "=d"(m) : "d"(xh), "a"(xl), "r"(mod()));
    value = m;

    value = normalize(static_cast<int64_t>(value)
                      * static_cast<int64_t>(rhs.value));

    return *this;
  }

  template<typename U = T>
  typename std::enable_if<
      std::is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type &
  operator*=(const Modular &rhs) {
    int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value
                                     / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }

  template<typename U = T>
  typename std::enable_if<!std::is_integral<typename Modular<U>::Type>::value,
                          Modular>::type &
  operator*=(const Modular &rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }

  Modular &operator/=(const Modular &other) {
    return *this *= Modular(inverse(other.value, mod()));
  }

  template<typename U> friend const Modular<U> &abs(const Modular<U> &v) {
    return v;
  }

  template<typename U>
  friend bool operator==(const Modular<U> &lhs, const Modular<U> &rhs);

  template<typename U>
  friend bool operator<(const Modular<U> &lhs, const Modular<U> &rhs);

  template<typename U>
  friend std::istream &operator>>(std::istream &stream, Modular<U> &number);

 private:
  Type value;
};

template<typename T>
bool operator==(const Modular<T> &lhs, const Modular<T> &rhs) {
  return lhs.value == rhs.value;
}

template<typename T, typename U> bool operator==(const Modular<T> &lhs, U rhs) {
  return lhs == Modular<T>(rhs);
}

template<typename T, typename U> bool operator==(U lhs, const Modular<T> &rhs) {
  return Modular<T>(lhs) == rhs;
}

template<typename T>
bool operator!=(const Modular<T> &lhs, const Modular<T> &rhs) {
  return !(lhs == rhs);
}

template<typename T, typename U> bool operator!=(const Modular<T> &lhs, U rhs) {
  return !(lhs == rhs);
}

template<typename T, typename U> bool operator!=(U lhs, const Modular<T> &rhs) {
  return !(lhs == rhs);
}

template<typename T>
bool operator<(const Modular<T> &lhs, const Modular<T> &rhs) {
  return lhs.value < rhs.value;
}

template<typename T>
Modular<T> operator+(const Modular<T> &lhs, const Modular<T> &rhs) {
  return Modular<T>(lhs) += rhs;
}

template<typename T, typename U>
Modular<T> operator+(const Modular<T> &lhs, U rhs) {
  return Modular<T>(lhs) += rhs;
}

template<typename T, typename U>
Modular<T> operator+(U lhs, const Modular<T> &rhs) {
  return Modular<T>(lhs) += rhs;
}

template<typename T>
Modular<T> operator-(const Modular<T> &lhs, const Modular<T> &rhs) {
  return Modular<T>(lhs) -= rhs;
}

template<typename T, typename U>
Modular<T> operator-(const Modular<T> &lhs, U rhs) {
  return Modular<T>(lhs) -= rhs;
}

template<typename T, typename U>
Modular<T> operator-(U lhs, const Modular<T> &rhs) {
  return Modular<T>(lhs) -= rhs;
}

template<typename T>
Modular<T> operator*(const Modular<T> &lhs, const Modular<T> &rhs) {
  return Modular<T>(lhs) *= rhs;
}

template<typename T, typename U>
Modular<T> operator*(const Modular<T> &lhs, U rhs) {
  return Modular<T>(lhs) *= rhs;
}

template<typename T, typename U>
Modular<T> operator*(U lhs, const Modular<T> &rhs) {
  return Modular<T>(lhs) *= rhs;
}

template<typename T>
Modular<T> operator/(const Modular<T> &lhs, const Modular<T> &rhs) {
  return Modular<T>(lhs) /= rhs;
}

template<typename T, typename U>
Modular<T> operator/(const Modular<T> &lhs, U rhs) {
  return Modular<T>(lhs) /= rhs;
}

template<typename T, typename U>
Modular<T> operator/(U lhs, const Modular<T> &rhs) {
  return Modular<T>(lhs) /= rhs;
}

template<typename T, typename U>
Modular<T> power(const Modular<T> &a, const U &b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1)
      res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}

template<typename T> bool IsZero(const Modular<T> &number) {
  return number() == 0;
}

template<typename T> std::string to_string(const Modular<T> &number) {
  return std::to_string(number());
}

template<typename T>
std::ostream &operator<<(std::ostream &stream, const Modular<T> &number) {
  return stream << number();
}

template<typename T>
std::istream &operator>>(std::istream &stream, Modular<T> &number) {
  typename std::common_type<typename Modular<T>::Type, int64_t>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}

template<int md>
using Mint = Modular<
    std::integral_constant<typename std::decay<decltype(md)>::type, md>>;
using ModType = int;
struct VarMod {
  static ModType value;
};
ModType VarMod::value;
ModType &md = VarMod::value;

using mint = Mint<1000000007>;
mint operator""_m(unsigned long long v) {
  return mint(v);
}
void solve() {
  

  STR(s);
  int n = SZ(s);
  int beg = 0, end = n;
  while (beg < end && s[beg] == '0') {
    ++beg;
  }
  while (beg < end && s[end - 1] == '0') {
    --end;
  }
  if (beg == end) {
    rp(n);
  }
  vector<mint> aux(n + 1);
  mint sum_aux = 0;
  mint pre;
  int ones = 0;
  int zeros = 0;
  mint id3 = 0;
  for (int i = end - 1; i >= beg; i--) {
    if (s[i] == '0') {
      ++zeros;
      sum_aux -= aux[zeros];
      aux[zeros] = pre;
      sum_aux += aux[zeros];
      continue;
    }
    id3 += sum_aux;
    zeros = 0;
    ++ones;
    pre = ones + id3;
  }
  mint ans = pre * (beg + 1) * (n - end + 1);
  cout << ans << '\n';
}



int main() {
  solve();
  return 0;
}
