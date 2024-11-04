#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;
  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {value = normalize(x);}
  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
    else v = static_cast<Type>(x % mod());if (v < 0) v += mod();return v;
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
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
    return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type& operator*=(const Modular& rhs) {
    int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }
  Modular inverse() const {
    Type a = value, b = mod(), u = 0, v = 1;
    while (a != 0) {Type t = b / a;b -= t * a; swap(a, b);u -= t * v; swap(u, v);}
    assert(b == 1);
    return Modular(u);
  }
  Modular& operator/=(const Modular& other) { return *this *= other.inverse(); }
  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);
  template <typename U>
  friend std::istream& operator>>(std::istream& stream, Modular<U>& number);
 private:
  Type value;
};
template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }
template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
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
string to_string(const Modular<T>& number) {
  return to_string(number());
}
template <typename T>
std::ostream& operator<<(std::ostream& stream, const Modular<T>& number) {
  return stream << number();
}
template <typename T>
std::istream& operator>>(std::istream& stream, Modular<T>& number) {
  stream >> number.value;
  number.value = Modular<T>::normalize(number.value);
  return stream;
}
struct VarMod { static int value; };
int VarMod::value;


using Mint = Modular<std::integral_constant<int, 998244353>>;

template <typename T>
class NTT {
 public:
  using Type = typename decay<decltype(T::value)>::type;

  static Type md;
  static Modular<T> root;
  static int base;
  static int max_base;
  static vector<Modular<T>> roots;
  static vector<int> rev;

  static void clear() {
    root = 0;
    base = 0;
    max_base = 0;
    roots.clear();
    rev.clear();
  }

  static void init() {
    md = T::value;
    assert(md >= 3 && md % 2 == 1);
    auto tmp = md - 1;
    max_base = 0;
    while (tmp % 2 == 0) {
      tmp /= 2;
      max_base++;
    }
    root = 2;
    while (power(root, (md - 1) >> 1) == 1) {
      root++;
    }
    assert(power(root, md - 1) == 1);
    root = power(root, (md - 1) >> max_base);
    base = 1;
    rev = {0, 1};
    roots = {0, 1};
  }

  static void ensure_base(int nbase) {
    if (md != T::value) {
      clear();
    }
    if (roots.empty()) {
      init();
    }
    if (nbase <= base) {
      return;
    }
    assert(nbase <= max_base);
    rev.resize(1 << nbase);
    for (int i = 0; i < (1 << nbase); i++) {
      rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
    }
    roots.resize(1 << nbase);
    while (base < nbase) {
      Modular<T> z = power(root, 1 << (max_base - 1 - base));
      for (int i = 1 << (base - 1); i < (1 << base); i++) {
        roots[i << 1] = roots[i];
        roots[(i << 1) + 1] = roots[i] * z;
      }
      base++;
    }
  }

  static void fft(vector<Modular<T>> &a) {
    int n = (int) a.size();
    assert((n & (n - 1)) == 0);
    int zeros = __builtin_ctz(n);
    ensure_base(zeros);
    int shift = base - zeros;
    for (int i = 0; i < n; i++) {
      if (i < (rev[i] >> shift)) {
        swap(a[i], a[rev[i] >> shift]);
      }
    }
    for (int k = 1; k < n; k <<= 1) {
      for (int i = 0; i < n; i += 2 * k) {
        for (int j = 0; j < k; j++) {
          Modular<T> x = a[i + j];
          Modular<T> y = a[i + j + k] * roots[j + k];
          a[i + j] = x + y;
          a[i + j + k] = x - y;
        }
      }
    }
  }

  static vector<Modular<T>> multiply(vector<Modular<T>> a, vector<Modular<T>> b) {
    if (a.empty() || b.empty()) {
      return {};
    }
    int eq = (a.size() == b.size() && a == b);
    int need = (int) a.size() + (int) b.size() - 1;
    int nbase = 0;
    while ((1 << nbase) < need) nbase++;
    ensure_base(nbase);
    int sz = 1 << nbase;
    a.resize(sz);
    b.resize(sz);
    fft(a);
    if (eq) b = a; else fft(b);
    Modular<T> inv_sz = 1 / static_cast<Modular<T>>(sz);
    for (int i = 0; i < sz; i++) {
      a[i] *= b[i] * inv_sz;
    }
    reverse(a.begin() + 1, a.end());
    fft(a);
    a.resize(need);
    return a;
  }
};

template <typename T> typename NTT<T>::Type NTT<T>::md;
template <typename T> Modular<T> NTT<T>::root;
template <typename T> int NTT<T>::base;
template <typename T> int NTT<T>::max_base;
template <typename T> vector<Modular<T>> NTT<T>::roots;
template <typename T> vector<int> NTT<T>::rev;

template <typename T>
vector<Modular<T>> inverse(vector<Modular<T>> a) {
  int n = (int) a.size();
  if (n == 1) {
    return {1 / a[0]};
  }
  int m = (n + 1) >> 1;
  vector<Modular<T>> b = inverse(vector<Modular<T>>(a.begin(), a.begin() + m));
  int need = n << 1;
  int nbase = 0;
  while ((1 << nbase) < need) {
    ++nbase;
  }
  NTT<T>::ensure_base(nbase);
  int size = 1 << nbase;
  a.resize(size);
  b.resize(size);
  NTT<T>::fft(a);
  NTT<T>::fft(b);
  Modular<T> inv = 1 / static_cast<Modular<T>>(size);
  for (int i = 0; i < size; ++i) {
    a[i] = (2 - a[i] * b[i]) * b[i] * inv;
  }
  reverse(a.begin() + 1, a.end());
  NTT<T>::fft(a);
  a.resize(n);
  return a;
}

template <typename T>
vector<Modular<T>>& operator*=(vector<Modular<T>>& a, const vector<Modular<T>>& b) {
  if (a.empty() || b.empty()) {
    a.clear();
  } else {
    if (min(a.size(), b.size()) < 150) {
      vector<Modular<T>> c = a;
      a.assign(a.size() + b.size() - 1, 0);
      for (int i = 0; i < (int) c.size(); i++) {
        for (int j = 0; j < (int) b.size(); j++) {
          a[i + j] += c[i] * b[j];
        }
      }
    } else {
      a = NTT<T>::multiply(a, b);
    }
  }
  return a;
}

template <typename T>
vector<Modular<T>> operator*(const vector<Modular<T>>& a, const vector<Modular<T>>& b) {
  vector<Modular<T>> c = a;
  return c *= b;
}

template <typename T>
vector<T>& operator+=(vector<T>& a, const vector<T>& b) {
  if (a.size() < b.size()) {
    a.resize(b.size());
  }
  for (int i = 0; i < (int) b.size(); i++) {
    a[i] += b[i];
  }
  return a;
}

template <typename T>
vector<T> operator+(const vector<T>& a, const vector<T>& b) {
  vector<T> c = a;
  return c += b;
}

template <typename T>
vector<T>& operator-=(vector<T>& a, const vector<T>& b) {
  if (a.size() < b.size()) {
    a.resize(b.size());
  }
  for (int i = 0; i < (int) b.size(); i++) {
    a[i] -= b[i];
  }
  return a;
}

template <typename T>
vector<T> operator-(const vector<T>& a, const vector<T>& b) {
  vector<T> c = a;
  return c -= b;
}

template <typename T>
vector<T>& operator*=(vector<T>& a, const vector<T>& b) {
  if (a.empty() || b.empty()) {
    a.clear();
  } else {
    vector<T> c = a;
    a.assign(a.size() + b.size() - 1, 0);
    for (int i = 0; i < (int) c.size(); i++) {
      for (int j = 0; j < (int) b.size(); j++) {
        a[i + j] += c[i] * b[j];
      }
    }
  }
  return a;
}

template <typename T>
vector<T> operator*(const vector<T>& a, const vector<T>& b) {
  vector<T> c = a;
  return c *= b;
}

template <typename T>
vector<T> inverse(const vector<T>& a) {
  vector<T> h(a);
  int n = (int) h.size();
  T invh0 = 1 / h[0];
  vector<T> u(1, invh0);
  while ((int) u.size() < n) {
    int t = (int) u.size();
    vector<T> h0;
    for (int i = 0; i < t; i++) {
      h0.push_back(i < (int) h.size() ? h[i] : 0);
    }
    vector<T> c = h0 * u;
    vector<T> h1;
    for (int i = t; i < 2 * t; i++) {
      h1.push_back(i < (int) h.size() ? h[i] : 0);
    }
    vector<T> aux = u * h1;
    aux.resize(t);
    for (int i = 0; i < t; i++) {
      aux[i] += (i + t < (int) c.size() ? c[i + t] : 0);
    }
    vector<T> v = aux * u;
    v.resize(t);
    for (int i = 0; i < t; i++) {
      u.push_back(-v[i]);
    }
  }
  u.resize(n);
  return u;
}

template <typename T>
vector<T>& operator/=(vector<T>& a, const vector<T>& b) {
  int n = (int) a.size();
  int m = (int) b.size();
  if (n < m) {
    a.clear();
  } else {
    vector<T> d = b;
    reverse(a.begin(), a.end());
    reverse(d.begin(), d.end());
    d.resize(n - m + 1);
    a *= inverse(d);
    a.erase(a.begin() + n - m + 1, a.end());
    reverse(a.begin(), a.end());
  }
  return a;
}

template <typename T>
vector<T> operator/(const vector<T>& a, const vector<T>& b) {
  vector<T> c = a;
  return c /= b;
}

template <typename T>
vector<T>& operator%=(vector<T>& a, const vector<T>& b) {
  int n = (int) a.size();
  int m = (int) b.size();
  if (n >= m) {
    vector<T> c = (a / b) * b;
    a.resize(m - 1);
    for (int i = 0; i < m - 1; i++) {
      a[i] -= c[i];
    }
  }
  return a;
}

template <typename T>
vector<T> operator%(const vector<T>& a, const vector<T>& b) {
  vector<T> c = a;
  return c %= b;
}

template <typename T>
vector<T> derivative(const vector<T>& a) {
  vector<T> c = a;
  for (int i = 0; i < (int) c.size(); i++) {
    c[i] *= i;      
  }
  if (!c.empty()) {
    c.erase(c.begin());
  }
  return c;
}
 
template <typename T>
vector<T> primitive(const vector<T>& a) {
  vector<T> c = a;
  c.insert(c.begin(), 0);
  for (int i = 1; i < (int) c.size(); i++) {
    c[i] /= i;
  }
  return c;
}

template <typename T>
vector<T> logarithm(const vector<T>& a) {
  assert(a[0] == 1);
  vector<T> u = primitive(derivative(a) * inverse(a));
  u.resize(a.size());
  return u;
}
 
template <typename T>
vector<T> exponent(const vector<T>& a) {
  assert(a[0] == 0);
  int n = (int) a.size();
  vector<T> res = {1};
  int k = 1;
  while (k <= 2 * n) {
    k *= 2;
    vector<T> tmp(a.begin(), a.begin() + min(k, (int) a.size()));
    tmp[0] += 1;
    tmp -= logarithm(res);
    res *= tmp;
    res.resize(k);
  }
  res.resize(n);
  return res;
}

template <typename T>
vector<T> multiply(const vector<vector<T>>& a) {
  if (a.empty()) {
    return {0};
  }
  function<vector<T>(int, int)> mult = [&](int l, int r) {
    if (l == r) {
      return a[l];
    }
    int y = (l + r) >> 1;
    return mult(l, y) * mult(y + 1, r);
  };
  return mult(0, (int) a.size() - 1);
}

template <typename T>
T evaluate(const vector<T>& a, const T& x) {
  T res = 0;
  for (int i = (int) a.size() - 1; i >= 0; i--) {
    res = res * x + a[i];
  }
  return res;
}

template <typename T>
vector<T> evaluate(const vector<T>& a, const vector<T>& x) {
  if (x.empty()) {
    return {};
  }
  if (a.empty()) {
    return vector<T>(x.size(), 0);
  }
  int n = (int) x.size();
  vector<vector<T>> st((n << 1) - 1);
  function<void(int, int, int)> build = [&](int v, int l, int r) {
    if (l == r) {
      st[v] = vector<T> {-x[l], 1};
    } else {
      int y = (l + r) >> 1;
      int z = v + ((y - l + 1) << 1);
      build(v + 1, l, y);
      build(z, y + 1, r);
      st[v] = st[v + 1] * st[z];
    }
  };
  build(0, 0, n - 1);
  vector<T> res(n);
  function<void(int, int, int, vector<T>)> eval = [&](int v, int l, int r, vector<T> f) {
    f %= st[v];
    if ((int) f.size() < 150) {
      for (int i = l; i <= r; i++) {
        res[i] = evaluate(f, x[i]);
      }
      return;
    }
    if (l == r) {
      res[l] = f[0];
    } else {
      int y = (l + r) >> 1;
      int z = v + ((y - l + 1) << 1);
      eval(v + 1, l, y, f);
      eval(z, y + 1, r, f);
    }
  };
  eval(0, 0, n - 1, a);
  return res;
}

template <typename T>
vector<T> interpolate(const vector<T>& x, const vector<T>& y) {
  if (x.empty()) {
    return {};
  }
  assert(x.size() == y.size());
  int n = (int) x.size();
  vector<vector<T>> st((n << 1) - 1);
  function<void(int, int, int)> build = [&](int v, int l, int r) {
    if (l == r) {
      st[v] = vector<T> {-x[l], 1};
    } else {
      int w = (l + r) >> 1;
      int z = v + ((w - l + 1) << 1);
      build(v + 1, l, w);
      build(z, w + 1, r);
      st[v] = st[v + 1] * st[z];
    }
  };
  build(0, 0, n - 1);
  vector<T> m = st[0];
  vector<T> dm = derivative(m);
  vector<T> val(n);
  function<void(int, int, int, vector<T>)> eval = [&](int v, int l, int r, vector<T> f) {
    f %= st[v];
    if ((int) f.size() < 150) {
      for (int i = l; i <= r; i++) {
        val[i] = evaluate(f, x[i]);
      }
      return;
    }
    if (l == r) {
      val[l] = f[0];
    } else {
      int w = (l + r) >> 1;
      int z = v + ((w - l + 1) << 1);
      eval(v + 1, l, w, f);
      eval(z, w + 1, r, f);
    }
  };
  eval(0, 0, n - 1, dm);
  for (int i = 0; i < n; i++) {
    val[i] = y[i] / val[i];
  }
  function<vector<T>(int, int, int)> calc = [&](int v, int l, int r) {
    if (l == r) {
      return vector<T> {val[l]};
    }
    int w = (l + r) >> 1;
    int z = v + ((w - l + 1) << 1);
    return calc(v + 1, l, w) * st[z] + calc(z, w + 1, r) * st[v + 1];
  };
  return calc(0, 0, n - 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  long long k;
  cin >> n >> k;
  vector<Mint> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ns=n,ss=0;
  for(int i=0;i<n;i++){
    if(a[i]==a[(i+1)%n]){
        ns--;ss++;
    }
  }
  long long m=ns;
  vector<Mint> c = {1, k-2,1};
  vector<Mint> res = {1};
  while (m > 0) {
    if (m & 1) {
      res = res * c ;
    }
    c = c * c ;
    m >>= 1;
  }
  Mint ans = 0;
  for (int i = ns+1; i < (int) res.size(); i++) {
    ans += res[i];
  }
  Mint xx= k;
  ans=ans*power(xx,ss);
  cout << ans << '\n';
  return 0;
}
