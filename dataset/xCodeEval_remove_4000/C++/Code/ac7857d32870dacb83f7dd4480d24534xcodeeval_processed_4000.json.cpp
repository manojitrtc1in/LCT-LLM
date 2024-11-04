
using namespace std;



template <typename A, typename B> string to_string(pair<A, B> p);
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) { res += ", "; }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) { res += static_cast<char>('0' + v[i]); }
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) { res += ", "; }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")"; }
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")"; }
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }










template<typename F>
struct id0 : F {
  id0(F&& f) : F(forward<F>(f)) {}
  template<typename... Args>
  decltype(auto) operator()(Args&&... args) const { return F::operator()(*this, forward<Args>(args)...); }
};
template<typename F>
decltype(auto) id1(F&& f) { return id0<F> { forward<F>(f) }; }

template<typename D, typename R>
vector<R> maps(const vector<D> &d, function<R(D)> f) {
  vector<R> r(d.size());
  for (int i = 0; i < (int) d.size(); ++i) r[i] = f(d[i]);
  return r;
}

template<typename T>
vector<vector<T>> transpose(const vector<vector<T>> &m) {
  if (m.empty() || m[0].empty()) return m;
  vector<vector<T>> r(m[0].size(), vector<T>(m.size())); 
  for (int i = 0; i < (int) m.size(); ++i) {
    for (int j = 0; j < (int) m[0].size(); ++j) {
      r[j][i] = m[i][j];
    }
  }
  return r;
}

template<typename T>
vector<T> vadd(vector<T> a, vector<T> b) {
  a.insert(a.end(), b.begin(), b.end());
  return a;
}



template<typename T>
T concat(initializer_list<T> lists) {
  T a;
  for (auto &l : lists) a.insert(a.end(), l.begin(), l.end());
  return a;
}

template<typename T, size_t sz>
struct _Matrix_type { typedef vector<typename _Matrix_type<T, sz - 1>::type> type; };
template<typename T>
struct _Matrix_type<T, 1> { typedef T type; };
template<typename T>
struct _Matrix {
  static auto build(size_t s) { return vector<T>(s); }
  template<typename ...Args>
  static auto build(size_t f, Args... args) {
    return vector<typename _Matrix_type<T, 1 + sizeof...(args)>::type>(f, _Matrix<T>::build(args...));
  }
};
template<typename T, typename... Args>
auto buildMatrix(Args... args) { return _Matrix<T>::build(args...); }


template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}
 
template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;
 
  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
    value = normalize(x);
  }
 
  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
    else v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }
 
  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const { return static_cast<U>(value); }
  constexpr static Type mod() { return T::value; }
 
  Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
  Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
  template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
  template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
  Modular& operator++() { return *this += 1; }
  Modular& operator--() { return *this -= 1; }
  Modular operator++(int) { Modular result(*this); *this += 1; return result; }
  Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
  Modular operator-() const { return Modular(-value); }
 
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {

    uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
    uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
    asm(
      "divl %4; \n\t"
      : "=a" (d), "=d" (m)
      : "d" (xh), "a" (xl), "r" (mod())
    );
    value = m;

    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));

    return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, long long>::value, Modular>::type& operator*=(const Modular& rhs) {
    long long q = static_cast<long long>(static_cast<long double>(value) * rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }
 
  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }
 
  friend const Type& abs(const Modular& x) { return x.value; }
 
  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);
 
  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);
 
  template <typename V, typename U>
  friend V& operator>>(V& stream, Modular<U>& number);
 
 private:
  Type value;
};
 
template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }
 
template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
 
template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }
 
template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
 
template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
 
template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
 
template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
 
template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}
 
template <typename T>
bool IsZero(const Modular<T>& number) {
  return number() == 0;
}
 
template <typename T>
string to_string(const Modular<T>& number) {
  return to_string(number());
}
 


template <typename U, typename T>
U& operator<<(U& stream, const Modular<T>& number) {
  return stream << number();
}
 


template <typename U, typename T>
U& operator>>(U& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, long long>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}
 

 
constexpr int md = (int) 998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;
 


struct DSU {
  vector<int> fa;
  vector<int> sz;

  DSU(int n) : fa(n), sz(n, 1) { iota(fa.begin(), fa.end(), 0); }

  int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

  bool unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) return false;
    fa[fy] = fx;
    sz[fx] += sz[fy];
    return true;
  }
};

int main() {
  ios::sync_with_stdio(false);

  int T; {
    cin >> T;
  }

  for (int kase = 1; kase <= T; ++kase) {
    int N; {
      cin >> N;
    }

    vector<vector<int>> P(2*N, vector<int>(N)); {
      for (int i = 0; i < 2*N; ++i) {
        for (int j = 0; j < N; ++j) {
          cin >> P[i][j];
          --P[i][j];
        }
      }
    }

    vector<int> chosen; 
    vector<int> q;
    vector<vector<int>> g(N);
    DSU dsu(2*N);
    {
      vector<vector<vector<int>>> bag = buildMatrix<int>(N, N, 0); {
        for (int i = 0; i < 2*N; ++i) {
          for (int j = 0; j < N; ++j) {
            bag[j][P[i][j]].push_back(i);
          }
        }
      }
      vector<int> bye(2*N); {
        while (true) {
          bool rm = false;
          for (int j = 0; j < N; ++j) {
            for (int v = 0; v < N; ++v) {
              while (bag[j][v].size() && bye[bag[j][v].back()]) bag[j][v].pop_back();
              if (bag[j][v].empty()) continue;
              int i = bag[j][v].back();
              bag[j][v].pop_back();
              while (bag[j][v].size() && bye[bag[j][v].back()]) bag[j][v].pop_back();
              if (bag[j][v].empty()) {
                rm = true;
                bye[i] = 1;
                chosen.push_back(i);
                for (int k = 0; k < N; ++k) {
                  for (int s : bag[k][P[i][k]]) bye[s] = 1;
                  bag[k][P[i][k]].clear();
                }
              } else {
                bag[j][v].push_back(i);
              }
            }
          }
          if (!rm) break;
        }
      }
      for (int i = 0; i < 2*N; ++i) if (!bye[i]) {
        q.push_back(i);
      }
      
      
      
      
      

      for (int i : q) {
        if (bye[i]) continue;
        chosen.push_back(i);
        for (int j = 0; j < N; ++j) {
          int v = P[i][j];
          for (int k : bag[j][v]) {
            if (bye[k]) continue;
            if (k == i) continue;
            dsu.unite(i, k);
            bye[k] = 1;
          }
        }
      }
    }

    int cc_cnt = 0; {
      for (int i = 0; i < 2*N; ++i) if (dsu.find(i) == i) {
        cc_cnt += dsu.sz[i] > 1;
      }
    }

    Mint res = power(Mint(2), cc_cnt);

    cout << res << "\n";
    for (int i = 0; i < (int) chosen.size(); ++i) cout << chosen[i]+1 << " \n"[i+1==N];
  }
}

