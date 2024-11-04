



using namespace std;

struct fast_ios {
  fast_ios() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
  };
} id0;

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






  for (int id1(_iter_, __LINE__) = 0,                                  \
                               id1(_num_, __LINE__) = (int)(n);        \
       id1(_iter_, __LINE__) < id1(_num_, __LINE__);           \
       ++id1(_iter_, __LINE__))












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

    uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
    uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x),
             d, m;
    asm("divl %4; \n\t" : "=a"(d), "=d"(m) : "d"(xh), "a"(xl), "r"(mod()));
    value = m;

    value = normalize(static_cast<int64_t>(value) *
                      static_cast<int64_t>(rhs.value));

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



class GNoMonotoneTriples {
  void SOLVE() {
    int n, q;
    scan(n, q);
    vi a(n);
    scan(a);
    vi smx, smn;
    vv<int> f4(n, {-1, -1, -1, -1}), f3(n, {-1, -1, -1});
    

    

    vi cnt(n, 2);
    set<int> pos, mxs, mns;

    for (int i = 0; i < n; ++i) {
      

      

      while (!smx.empty() && a[i] > a[smx.back()]) {
        if (--cnt[smx.back()] == 0)
          pos.insert(smx.back());
        

        mxs.insert(smx.back());
        smx.pop_back();
      }
      while (!smn.empty() && a[i] < a[smn.back()]) {
        if (--cnt[smn.back()] == 0)
          pos.insert(smn.back());
        mns.insert(smn.back());
        smn.pop_back();
      }
      if (i > 0) {
        f3[i] = f3[i - 1];
        f4[i] = f4[i - 1];
      }

      auto iter1 =
          lower_bound(all(smx), a[i], [&](int x, int y) { return a[x] > y; });
      auto iter2 =
          lower_bound(all(smn), a[i], [&](int x, int y) { return a[x] < y; });
      int id2 = iter1 == smx.begin() ? -1 : *prev(iter1);
      int left_less = iter2 == smn.begin() ? -1 : *prev(iter2);
      if (id2 != -1) {
        auto it = mxs.lower_bound(id2);
        if (it != mxs.begin()) {
          

          

          std::vector g{*std::prev(it), id2, i};
          if (g[0] > f3[i][0])
            f3[i] = g;
        }
      }
      debug(mns);
      if (left_less != -1) {
        auto it = mns.lower_bound(left_less);
        if (it != mns.begin()) {
          std::vector g{*std::prev(it), left_less, i};
          if (g[0] > f3[i][0])
            f3[i] = g;
        }
      }
      if (left_less != -1 and id2 != -1) {
        
        auto it = pos.lower_bound(min(left_less, id2));
        if (it != pos.begin()) {
          

          

          int p0 = *std::prev(it);
          int p1 = *upper_bound(all(smx), p0);
          int p2 = *upper_bound(all(smn), p0);
          std::vector g{p0, p1, p2, i};
          if (g[1] > g[2])
            std::swap(g[1], g[2]);
          if (g[0] > f4[i][0])
            f4[i] = g;
        }
      }
      smx.push_back(i);
      smn.push_back(i);
    }
    while (q--) {
      int l, r;
      std::cin >> l >> r;
      --l;
      --r;
      if (f4[r][0] >= l) {
        std::cout << 4 << "\n";
        for (int i = 0; i < 4; ++i)
          std::cout << f4[r][i] + 1 << " \n"[i == 3];
      } else if (f3[r][0] >= l) {
        std::cout << 3 << "\n";
        for (int i = 0; i < 3; ++i)
          std::cout << f3[r][i] + 1 << " \n"[i == 2];
      } else {
        std::cout << 0 << "\n\n";
      }
    }
  }

public:
  void solve(std::istream &in, std::ostream &out) {
    auto cin_buff = std::cin.rdbuf(in.rdbuf());
    auto cerr_buff = std::cerr.rdbuf(cout.rdbuf(out.rdbuf()));
    SOLVE();
    std::cout.rdbuf(cerr.rdbuf(cerr_buff));
    std::cin.rdbuf(cin_buff);
  }
};


int main() {
  GNoMonotoneTriples solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
