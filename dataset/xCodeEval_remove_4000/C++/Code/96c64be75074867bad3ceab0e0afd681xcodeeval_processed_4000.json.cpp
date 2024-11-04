
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
decltype(auto) id2(F&& f) { return id0<F> { forward<F>(f) }; }

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
 

 
constexpr int md = (int) 1e9 + 31;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;
 
vector<Mint> fact(1, 1);
vector<Mint> inv_fact(1, 1);
 
Mint C(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  while ((int) fact.size() < n + 1) {
    fact.push_back(fact.back() * (int) fact.size());
    inv_fact.push_back(1 / fact.back());
  }
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}







Mint id1(const vector<Mint> ys, int x) {
  const int n = ys.size();
  Mint res; {
    if (x >= 0) {
      C(x, 0);
      if (x < n) return ys[x];
      for (int i = 0; i < n; ++i) {
        int sgn = n-1-i & 1 ? -1 : +1;
        res += sgn * ys[i] * fact[x] * inv_fact[x-n] / (x-i) * inv_fact[i] * inv_fact[n-1-i];
      }
    } else {
      C(n-1-x, 0);
      for (int i = 0; i < n; ++i) {
        int sgn = 2*n-i & 1 ? -1 : +1;
        res += sgn * ys[i] * fact[n-1-x] * inv_fact[-x-1] / (-x+i) * inv_fact[i] * inv_fact[n-1-i];
      }
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);

  int N, M; {
    cin >> N >> M;
  }

  vector<vector<int>> C(M, vector<int>(N)); {
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        cin >> C[i][j];
      }
    }
  }

  vector<int> s(M); {
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        s[i] += C[i][j];
      }
    }
  }

  map<int, int> diff_cnt; {
    for (int i = 0; i+1 < M; ++i) {
      diff_cnt[s[i+1]-s[i]] += 1;
    }
  }

  int diff = -1; {
    int maxc = 0; {
      for (auto [d, c] : diff_cnt) {
        if (c > maxc) {
          maxc = c;
          diff = d;
        }
      }
    }
  }

  vector<Mint> s2(M); {
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        s2[i] += Mint(C[i][j]) * C[i][j];
      }
      assert(s2[i] != 0);
    }
  }

  for (int i = 1; i+3 <= M; ++i) {
    if (i+3 < M && s[i]+diff != s[i+1] && s[i]+2*diff != s[i+2]) {
      Mint p = id1({ s2[i+1], s2[i+2], s2[i+3] }, -1);
      Mint q = id1({ s[i+1], s[i+2] }, -1);
      Mint u = p - s2[i];
      Mint v = q - s[i];
      Mint w = u/v;
      Mint r = (w + v) / 2;
      cout << i << " " << r << endl;
      return 0;
    }
    if (s[i+2] != s[i]+2*diff && s[i+2] != s[i+1]+diff) {
      Mint p = id1({ s2[i-1], s2[i], s2[i+1] }, 3);
      Mint q = id1({ s[i], s[i+1] }, 2);
      Mint u = p - s2[i+2];
      Mint v = q - s[i+2];
      Mint w = u/v;
      Mint r = (w + v) / 2;
      cout << i+2 << " " << r << endl;
      return 0;
    }
  }

  assert(false);
}

