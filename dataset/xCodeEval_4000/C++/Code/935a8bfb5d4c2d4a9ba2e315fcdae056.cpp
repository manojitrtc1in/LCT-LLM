#include <bits/stdc++.h>

using namespace std;

class segtree {
  public:
  struct node {

    int mx = 0;
    int ad = 0;
    void apply(int l, int r, int v) {
      if ((v % 2) == 0) {
        mx = v / 2;
      } else {
        v = (v - 1) / 2;
        mx += v;
        ad += v;
      }
    }
  };

  node unite(const node &a, const node &b) const {
    node res;
    res.mx = max(a.mx, b.mx);
    return res;
  }

  inline void push(int x, int l, int r) {
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    if (tree[x].ad != 0) {
      tree[x + 1].apply(l, y, ~tree[x].ad);
      tree[z].apply(y + 1, r, ~tree[x].ad);
      tree[x].ad = 0;
    }
  }

  inline void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }

  int n;
  vector<node> tree;

  void build(int x, int l, int r) {
    if (l == r) {
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y);
    build(z, y + 1, r);
    pull(x, z);
  }

  template <typename M, typename... T>
  void build(int x, int l, int r, const vector<M> &v, const T&... t) {
    if (l == r) {
      tree[x].apply(l, r, v[l], t...);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y, v, t...);
    build(z, y + 1, r, v, t...);
    pull(x, z);
  }

  template <typename M, typename... T>
  segtree(const vector<M> &v, const T&... t) {
    n = v.size();
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1, v, t...);
  }

  segtree(int _n) : n(_n) {
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1);
  }

  segtree(){};

  node get(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x];
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    node res{};
    if (rr <= y) {
      res = get(x + 1, l, y, ll, rr);
    } else {
      if (ll > y) {
        res = get(z, y + 1, r, ll, rr);
      } else {
        res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
      }
    }
    pull(x, z);
    return res;
  }

  node get(int ll, int rr) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return get(0, 0, n - 1, ll, rr);
  }

  node get(int p) {
    assert(0 <= p && p <= n - 1);
    return get(0, 0, n - 1, p, p);
  }

  template <typename... M>
  void modify(int x, int l, int r, int ll, int rr, const M&... v) {
    if (ll <= l && r <= rr) {
      tree[x].apply(l, r, v...);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    if (ll <= y) {
      modify(x + 1, l, y, ll, rr, v...);
    }
    if (rr > y) {
      modify(z, y + 1, r, ll, rr, v...);
    }
    pull(x, z);
  }

  template <typename... M>
  void modify(int ll, int rr, const M&... v) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    modify(0, 0, n - 1, ll, rr, v...);
  }

  

  


  int find_first_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[x + 1])) {
      res = find_first_knowingly(x + 1, l, y, f);
    } else {
      res = find_first_knowingly(z, y + 1, r, f);
    }
    pull(x, z);
    return res;
  }

  int find_first(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_first_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (ll <= y) {
      res = find_first(x + 1, l, y, ll, rr, f);
    }
    if (rr > y && res == -1) {
      res = find_first(z, y + 1, r, ll, rr, f);
    }
    pull(x, z);
    return res;
  }

  int find_first(int ll, int rr, const function<bool(const node&)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_first(0, 0, n - 1, ll, rr, f);
  }

  int find_last_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[z])) {
      res = find_last_knowingly(z, y + 1, r, f);
    } else {
      res = find_last_knowingly(x + 1, l, y, f);
    }
    pull(x, z);
    return res;
  }

  int find_last(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_last_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (rr > y) {
      res = find_last(z, y + 1, r, ll, rr, f);
    }
    if (ll <= y && res == -1) {
      res = find_last(x + 1, l, y, ll, rr, f);
    }
    pull(x, z);
    return res;
  }

  int find_last(int ll, int rr, const function<bool(const node&)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_last(0, 0, n - 1, ll, rr, f);
  }

};

template <typename T>
class fenwick {
  public:
  vector<T> fenw;
  int n;
  int log_n;

  fenwick(int _n) : n(_n) {
    fenw.resize(n);
    log_n = 0;
    while ((1 << log_n) <= n) log_n++;
  }

  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }

  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }

  int find(T v) {
    int x = 0;
    for (int bit = log_n - 1; bit >= 0; bit--) {
      if (x + (1 << bit) > n) continue;
      if (fenw[x + (1 << bit) - 1] <= v) {
        v -= fenw[x + (1 << bit) - 1];
        x ^= 1 << bit;
      }
    }
    x--;
    return x;
  }
};

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
#ifdef _WIN32
    uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
    uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
    asm(
      "divl %4; \n\t"
      : "=a" (d), "=d" (m)
      : "d" (xh), "a" (xl), "r" (mod())
    );
    value = m;
#else
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
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

  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }

  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);

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
string to_string(const Modular<T>& number) {
  return to_string(number());
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Modular<T>& number) {
  return stream << number();
}

template <typename T>
std::istream& operator>>(std::istream& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, int64_t>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}



constexpr int md = 998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
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

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__);

int n;

int main() {
  cin >> n;
  vector<Mint> fact(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = fact[i - 1] * i;
  }

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> pos;
  vector<int> neg;
  for (int i = 0; i < n; i++) {
    int b;
    cin >> b;
    (b ? pos : neg).push_back(a[i]);
  }

  sort(pos.begin(), pos.end());
  sort(neg.begin(), neg.end());
  Mint ret = 1;
  for (int rot = 0; rot < 2; rot++) {
    vector<int> cur = (rot ? pos : neg);
    int L = 0, R = 0;
    while (L < (int) cur.size()) {
      while (R < (int) cur.size() && cur[R] == cur[L]) {
        R++;
      }
      ret *= fact[R - L];
      L = R;
    }
  }
  if (*min_element(a.begin(), a.end()) == *max_element(a.begin(), a.end())) {
    ret = fact[n];
    cout << ret;
    return 0;
  }

  int det = -1;
  int added = 0;
  if (pos.empty()) {
    if (*min_element(neg.begin(), neg.end()) != *max_element(neg.begin(), neg.end())) {
      cout << 0;
      return 0;
    }
    cout << ret;
    return 0;
  } else {
    det = pos[0];
    int cnt = 0;
    for (int i : pos) {
      cnt += i > det;
    }
    for (int i : neg) {
      if (i <= det) {
        cout << 0;
        return 0;
      }
      cnt++;
    }
    det += cnt;
    cnt = 0;
    if (pos.back() > det) {
      cout << 0;
      return 0;
    }
    if (pos.back() == det) {
      while (pos.size() && pos.back() == det) {
        cnt++;
        added++;
        pos.pop_back();
      }
      ret *= fact[n] / (fact[n - cnt] * fact[cnt]);
    }
  }
  
  if (n > 2000) {
      segtree st(3 * n + 1);
      fenwick<int> cnt(3 * n + 1);
      vector<int> cur(3 * n + 1);
      for (int i : pos) {
        cnt.modify(i, 1);
        cur[i]++;
      }
      for (int i : neg) {
        cnt.modify(i, 1);
        cur[i]++;
      }
      auto eval = [&](int v, int b) {
        int lower = cnt.get(v - 1);
        return v + (b ? (n - lower - cur[v]) : lower);
      };
     

     

      auto rev = [&](int v) {
       

        cur[v]--;
        cnt.modify(v, -1);
        if (v < det) {
          st.modify(v, det - 1, 2 * 1 + 1);
        }
        if (cur[v] == 0) {
          st.modify(v, v, 0);
        }
        return st.get(0, 3 * n).mx <= det;
      };
      

      for (int i = 0; i < (int) pos.size(); i++) {
        if (i == 0 || pos[i] != pos[i - 1]) {
          int v = eval(pos[i], 1);
          if (v > det) {
           

            cout << 0;
            return 0;
          }
          st.modify(pos[i], pos[i], v * 2);
        }
      }
      reverse(neg.begin(), neg.end());
      int re = pos.size() + neg.size();
     

      while (re) {
        int pi = st.find_last(0, 2 * n, [&](const segtree::node &a) {return a.mx >= det;} );
        int ni = (neg.size() ? neg.back() : -1);
      

      

        if (ni != -1 && eval(ni, 0) < det) {
          cout << 0;
          return 0;
        }
        if (ni != -1 && eval(ni, 0) > det) {
          ni = -1;
        }
     

        if (ni == -1 && pi == -1) {
          cout << 0;
          return 0;
        }
        if (pi == -1) {
          if (!rev(ni)) {
            cout << 0;
            return 0;
          }
          re--;
          neg.pop_back();
          continue;
        }
        if (ni == -1) {
          if (!rev(pi)) {
            cout << 0;
            return 0;
          }
          re--;
          continue;
        }
        if (ni > pi) {
          if (!rev(ni)) {
            cout << 0;
            return 0;
          }
          neg.pop_back();
          re--;
        } else {
          if (!rev(pi)) {
            cout << 0;
            return 0;
          }
          re--;
        }
      }
      cout << ret;
    return 0;
  }
  
  reverse(neg.begin(), neg.end());
  auto eval = [&](int v, int b) {
    int c = v;
    for (int i : pos) {
      c += b ? (i > v) : (i < v);
    }
    for (int i : neg) {
      c += b ? (i > v) : (i < v);
    }
    c += b * added;
    return c;
  };
  int re = pos.size() + neg.size();
  while (re) {
    int ptr = pos.size() - 1;
    int pi = -1;
    while (ptr > -1) {
      int c = eval(pos[ptr], 1);
      if (c > det) {
        cout << 0;
        return 0;
      }
      if (c == det) {
        pi = ptr;
        break;
      }
      ptr--;
    }
    int ni = -1;
    if (neg.size()) {
      int c = eval(neg.back(), 0);
      if (c < det) {
        cout << 0;
        return 0;
      }
      if (c == det) {
        ni = neg.back();
      }
    }
    if ((pi == -1) && (ni == -1)) {
      cout << 0;
      return 0;
    }
    if (pi == -1 || (ni != -1 && neg.back() > pos[pi])) {
      neg.pop_back();
      added++;
      re--;
      continue;
    }
    if (ni == -1 || (pi != -1 && pos[pi] >= neg.back())) {
      pos.erase(pos.begin() + pi);
      added++;
      re--;
      continue;
    }
  }
  cout << ret;
  return 0;
}
