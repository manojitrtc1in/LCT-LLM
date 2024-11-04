

#include <bits/stdc++.h>

using namespace std;

struct fast_ios {
  fast_ios() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
  };
} fast_ios_;

template <typename A, typename B> bool chkmin(A &a, const B &b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}

template <typename A, typename B> bool chkmax(A &a, const B &b) {
  if (b > a) {
    a = b;
    return true;
  }
  return false;
}

template <typename T> istream &operator>>(istream &stream, vector<T> &vec) {
  for (auto &x : vec)
    stream >> x;
  return stream;
}

void scan() {}

template <class T, class... Args> void scan(T &a, Args &... rest) {
  cin >> a;
  scan(rest...);
}

using ll = long long;
using vl = vector<ll>;
using vb = vector<bool>;
using vi = vector<int>;
using pii = pair<int, int>;
template <typename T> using vv = vector<vector<T>>;
#define rng(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define up(i, a, b) for (int i = int(a); i <= int(b); ++i)
#define down(i, b, a) for (int i = int(b); i >= int(a); i--)
#define TOKENPASTE(x, y) x##y
#define TOKENPASTE2(x, y) TOKENPASTE(x, y)
#define rep(n)                                                                 \
  for (int TOKENPASTE2(_iter_, __LINE__) = 0,                                  \
                               TOKENPASTE2(_num_, __LINE__) = (int)(n);        \
       TOKENPASTE2(_iter_, __LINE__) < TOKENPASTE2(_num_, __LINE__);           \
       ++TOKENPASTE2(_iter_, __LINE__))
#define FOR(x, cont) for (const auto &x : cont)
#define For(x, cont) for (auto &x : cont)
#define all(x) begin(x), end(x)
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ep emplace
#define SZ(x) (int)(x).size()
#define UNIQ(vec) (vec).erase(unique(all(vec)), end(vec))
#define LB(cont, x) int(lower_bound(all(cont), x) - begin(cont))
#define UB(cont, x) int(upper_bound(all(cont), x) - begin(cont))

template <typename T>
ostream &operator<<(ostream &stream, const vector<T> &vec) {
  if (!vec.empty()) {
    stream << vec[0];
    for (size_t i = 1; i != vec.size(); ++i)
      stream << ' ' << vec[i];
  }
  return stream;
}

template <typename T> void print(const vector<T> &t) { cout << t << '\n'; }

template <typename T> void print(const vector<vector<T>> &t) {
  for (const auto &row : t) {
    print(row);
  }
}

template <typename T> void print(const T &t) { cout << t << ' '; }

template <typename T, typename... Args>
void print(const T &t, const Args &... rest) {
  print(t);
  print(rest...);
}

template <typename T> void println(const T &t) { cout << t << '\n'; }

template <typename T, typename... Args>
void println(const T &t, const Args &... rest) {
  print(t);
  println(rest...);
}



template <typename T> T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a;
    swap(a, m);
    u -= t * v;
    swap(u, v);
  }
  assert(m == 1);
  return u;
}

template <typename T> class Modular {
public:
  using Type = typename decay<decltype(T::value)>::type;

  constexpr Modular() : value() {}

  template <typename U> Modular(const U &x) { value = normalize(x); }

  template <typename U> static Type normalize(const U &x) {
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

  template <typename U> explicit operator U() const {
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

  template <typename U> Modular &operator+=(const U &other) {
    return *this += Modular(other);
  }

  template <typename U> Modular &operator-=(const U &other) {
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

  template <typename U = T>
  enable_if_t<is_same<typename Modular<U>::Type, int>::value, Modular> &
  operator*=(const Modular &rhs) {
#ifdef _WIN32
    uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
    uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x),
             d, m;
    asm("divl %4; \n\t" : "=a"(d), "=d"(m) : "d"(xh), "a"(xl), "r"(mod()));
    value = m;
#else
    value = normalize(static_cast<int64_t>(value) *
                      static_cast<int64_t>(rhs.value));
#endif
    return *this;
  }

  template <typename U = T>
  enable_if_t<is_same<typename Modular<U>::Type, int64_t>::value, Modular> &
  operator*=(const Modular &rhs) {
    int64_t q = static_cast<int64_t>(static_cast<long double>(value) *
                                     rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }

  template <typename U = T>
  enable_if_t<!is_integral<typename Modular<U>::Type>::value, Modular> &
  operator*=(const Modular &rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }

  Modular &operator/=(const Modular &other) {
    return *this *= Modular(inverse(other.value, mod()));
  }

  template <typename U> friend const Modular<U> &abs(const Modular<U> &v) {
    return v;
  }

  template <typename U>
  friend bool operator==(const Modular<U> &lhs, const Modular<U> &rhs);

  template <typename U>
  friend bool operator<(const Modular<U> &lhs, const Modular<U> &rhs);

  template <typename U>
  friend std::istream &operator>>(std::istream &stream, Modular<U> &number);

private:
  Type value;
};

template <typename T>
bool operator==(const Modular<T> &lhs, const Modular<T> &rhs) {
  return lhs.value == rhs.value;
}

template <typename T, typename U>
bool operator==(const Modular<T> &lhs, U rhs) {
  return lhs == Modular<T>(rhs);
}

template <typename T, typename U>
bool operator==(U lhs, const Modular<T> &rhs) {
  return Modular<T>(lhs) == rhs;
}

template <typename T>
bool operator!=(const Modular<T> &lhs, const Modular<T> &rhs) {
  return !(lhs == rhs);
}

template <typename T, typename U>
bool operator!=(const Modular<T> &lhs, U rhs) {
  return !(lhs == rhs);
}

template <typename T, typename U>
bool operator!=(U lhs, const Modular<T> &rhs) {
  return !(lhs == rhs);
}

template <typename T>
bool operator<(const Modular<T> &lhs, const Modular<T> &rhs) {
  return lhs.value < rhs.value;
}

template <typename T>
Modular<T> operator+(const Modular<T> &lhs, const Modular<T> &rhs) {
  return Modular<T>(lhs) += rhs;
}

template <typename T, typename U>
Modular<T> operator+(const Modular<T> &lhs, U rhs) {
  return Modular<T>(lhs) += rhs;
}

template <typename T, typename U>
Modular<T> operator+(U lhs, const Modular<T> &rhs) {
  return Modular<T>(lhs) += rhs;
}

template <typename T>
Modular<T> operator-(const Modular<T> &lhs, const Modular<T> &rhs) {
  return Modular<T>(lhs) -= rhs;
}

template <typename T, typename U>
Modular<T> operator-(const Modular<T> &lhs, U rhs) {
  return Modular<T>(lhs) -= rhs;
}

template <typename T, typename U>
Modular<T> operator-(U lhs, const Modular<T> &rhs) {
  return Modular<T>(lhs) -= rhs;
}

template <typename T>
Modular<T> operator*(const Modular<T> &lhs, const Modular<T> &rhs) {
  return Modular<T>(lhs) *= rhs;
}

template <typename T, typename U>
Modular<T> operator*(const Modular<T> &lhs, U rhs) {
  return Modular<T>(lhs) *= rhs;
}

template <typename T, typename U>
Modular<T> operator*(U lhs, const Modular<T> &rhs) {
  return Modular<T>(lhs) *= rhs;
}

template <typename T>
Modular<T> operator/(const Modular<T> &lhs, const Modular<T> &rhs) {
  return Modular<T>(lhs) /= rhs;
}

template <typename T, typename U>
Modular<T> operator/(const Modular<T> &lhs, U rhs) {
  return Modular<T>(lhs) /= rhs;
}

template <typename T, typename U>
Modular<T> operator/(U lhs, const Modular<T> &rhs) {
  return Modular<T>(lhs) /= rhs;
}

template <typename T, typename U>
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

template <typename T> bool IsZero(const Modular<T> &number) {
  return number() == 0;
}

template <typename T> string to_string(const Modular<T> &number) {
  return to_string(number());
}

template <typename T>
std::ostream &operator<<(std::ostream &stream, const Modular<T> &number) {
  return stream << number();
}

template <typename T>
std::istream &operator>>(std::istream &stream, Modular<T> &number) {
  typename common_type<typename Modular<T>::Type, int64_t>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}



string to_string(const string &s) { return '"' + s + '"'; }

string to_string(const char *s) { return to_string((string)s); }

string to_string(bool b) { return (b ? "true" : "false"); }

template <typename A, typename B> string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A> string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#if defined LOCAL && !defined DUIPAI
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

class UnionFind {
  vi par, sz;
  int nTree;

public:
  explicit UnionFind(int n) : par(n), sz(n, 1), nTree(n) { 

    iota(par.begin(), par.end(), 0);
  }

  int n_tree() const { return nTree; }

  int size(int x) { return sz[root(x)]; }

  int root(int x) { return x == par[x] ? x : par[x] = root(par[x]); }

  bool unite(int x, int y) {
    int rx = root(x), ry = root(y);
    if (rx != ry) {
      par[rx] = ry;
      --nTree;
      sz[ry] += sz[rx];
      return true;
    }
    return false;
  }

  bool is_root(int x) const { return par[x] == x; }
  bool same(int x, int y) { return root(x) == root(y); }
};

template <typename T> class BIT {
  using BinOp = function<T(T, T)>;
  BinOp bin_op;
  const T init;
  

  vector<T> a;

public:
  explicit BIT(
      int n, BinOp op = [](T x, T y) { return x + y; }, T init = T{})
      : bin_op(std::move(op)), init(init), a(n, init) {}

  T prefix(int x) const {
    auto res = init;
    while (x >= 0) {
      res = bin_op(a[x], res);
      x = (x & (x + 1)) - 1;
    }
    return res;
  }

  void modify(int x, T v) {
    while (x < SZ(a)) {
      a[x] = bin_op(a[x], v);
      x |= (x + 1);
    }
  }

  void clear() { fill(a.begin(), a.end(), init); }
};

template <typename int_t> inline int_t lowbit(int_t x) { return x & -x; }

inline unsigned h_bit(unsigned long long x) {
  return sizeof(unsigned long long) * 8 - __builtin_clzll(x);
}

unsigned long long pow2(unsigned long long x) { 

  return x == lowbit(x) ? x : 1ull << h_bit(x);
}

template <typename T> int get_bit(T a, int i) { return a >> i & 1; }
template <typename T> T get_mid(T l, T r) {
  assert(l <= r);
  return l + (r - l) / 2;
}

#define popcnt(x) __builtin_popcountll((x))
constexpr int md = 1000000007;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;


template <int N, int C> struct AhoCorasick {
  AhoCorasick() : n(1) {
    memset(weight, 0, sizeof(weight));
    memset(go, -1, sizeof(go));
  }

  void insert(const char *s, int w = 1) {
    int p = 0;
    for (int i = 0; s[i]; ++i) {
      int c = s[i] - 'a';
      if (go[p][c] == -1) {
        go[p][c] = n++;
      }
      p = go[p][c];
    }
    weight[p] += w;
  }

  void initialize() {
    std::queue<int> queue;
    for (int c = 0; c < C; ++c) {
      int &v = go[0][c];
      if (~v) {
        queue.push(v);
      }
      (~v ? fail[v] : v) = 0;
    }
    while (!queue.empty()) {
      int u = queue.front();
      queue.pop();
      weight[u] += weight[fail[u]];
      for (int c = 0; c < C; ++c) {
        int &v = go[u][c];
        if (~v) {
          queue.push(v);
        }
        (~v ? fail[v] : v) = go[fail[u]][c];
      }
    }
  }

  int n, weight[N]{}, go[N][C]{}, fail[N]{};
};

class GLettersAndQuestionMarks {
  static void SOLVE() {
    const int N = 1001;
    const int M = 14;
    AhoCorasick<N, M> ac;
    int k;
    scan(k);
    int max_length = 0;
    rep(k) {
      string s;
      int c;
      scan(s, c);
      chkmax(max_length, SZ(s));
      ac.insert(s.c_str(), c);
    }
    ac.initialize();
    int n = ac.n;
    debug(n);
    

    

    vv<ll> dp(n, vl(1 << M, LLONG_MIN));
    

    vl gain(n);
    

    

    vi dest(n);
    iota(all(dest), 0);
    

    int m = 0;
    string s;
    scan(s);
    dp[0][0] = 0;
    int sole_dest;
    ll sole_gain;
    int len = 0;
    auto get_dest = [&](int i) {
      return len >= max_length ? sole_dest : dest[i];
    };
    auto get_gain = [&](int i) {
      return len >= max_length ? sole_gain + gain[i] : gain[i];
    };
    FOR(x, s) {
      if (x == '?') {
        rng(mask, 0, 1 << M) {
          if (popcnt(mask) == m) {
            rng(i, 0, n) {
              if (dp[i][mask] != LLONG_MIN) {
                

                rng(c, 0, M) {
                  if (!get_bit(mask, c)) {
                    int j = ac.go[get_dest(i)][c];
                    chkmax(dp[j][mask | 1 << c],
                           dp[i][mask] + get_gain(i) + ac.weight[j]);
                  }
                }
              }
            }
          }
        }
        ++m;
        fill(all(gain), 0);
        iota(all(dest), 0);
        len = 0;
      } else {
        int c = x - 'a';
        ++len;
        if (len < max_length) {
          rng(i, 0, n) {
            dest[i] = ac.go[dest[i]][c];
            gain[i] += ac.weight[dest[i]];
          }
        } else {
          if (len == max_length) {
            sole_dest = dest[0];
            sole_gain = 0;
          }
          sole_dest = ac.go[sole_dest][c];
          sole_gain += ac.weight[sole_dest];
        }
      }
    }
    ll ans = LLONG_MIN;
    rng(mask, 0, 1 << M) {
      if (popcnt(mask) == m) {
        rng(i, 0, n) {
          if (dp[i][mask] != LLONG_MIN) {
            chkmax(ans, dp[i][mask] + get_gain(i));
          }
        }
      }
    }
    println(ans);






















  }

public:
  static void solve(std::istream &in, std::ostream &out) {
    auto cin_buff = std::cin.rdbuf(in.rdbuf());
    auto cerr_buff = std::cerr.rdbuf(cout.rdbuf(out.rdbuf()));
    SOLVE();
    std::cout.rdbuf(cerr.rdbuf(cerr_buff));
    std::cin.rdbuf(cin_buff);
  }
};


int main() {
  GLettersAndQuestionMarks solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
