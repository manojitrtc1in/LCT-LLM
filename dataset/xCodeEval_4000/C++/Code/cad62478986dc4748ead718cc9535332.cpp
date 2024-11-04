#include <bits/stdc++.h>

using namespace std;

template <typename T>
void debug_out(T t) {
  cerr << t;
}

template <typename A, typename B>
void debug_out(pair<A, B> u) {
  cerr << "(" << u.first << " " << u.second << ")";
}

template <typename T>
void debug_out(vector<T> t) {
  int sz = t.size();
  for(int i = 0; i < sz; i++) {
    debug_out(t[i]);
    if(i != sz - 1) cerr << ", ";
  }
}

template <typename T>
void debug_out(vector<vector<T>> t) {
  int sz = t.size();
  for(int i = 0; i < sz; i++) {
    debug_out(t[i]);
    if(i != sz - 1) cerr << endl;
  }
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  debug_out(H);
  cerr << " ";
  debug_out(T...);
}

template <typename T>
void debug_out(set<T> a) {
  vector<T> _a;
  for(T t : a) _a.push_back(t);
  debug_out(_a);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:" << endl, debug_out(__VA_ARGS__), cerr << endl;

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



constexpr int md = (int) 1e9 + 7;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

class segtree {
  public:

  struct node {
    int val = 0;
    int second_val = INT_MAX;
    int sval = 0;
    int p = INT_MIN;
    long long sum = 0;
    void apply(int l, int r, int v) {
      if(v < 0) {
        v = ~v;
        sval = v;
      } else {
        assert(v < second_val);
        p = max(p, v);
        if(v <= val) return;
        sum += 1LL * sval * (v - val);
        val = v;
      }
    }

    bool tag(int v) {
      return v < second_val;
    }
  };

  node unite(const node &a, const node &b) const {
    node res;
    res.val = min(a.val, b.val);
    if(a.val == b.val) {
      res.sval = a.sval + b.sval;
    } else {
      res.sval = (a.val < b.val ? a.sval : b.sval);
    }
    if(a.val == b.val) {
      res.second_val = min(a.second_val, b.second_val);
    } else {
      int add = max(a.val, b.val);
      res.second_val = min(add, min(a.second_val, b.second_val));
    }
    res.sum = a.sum + b.sum;
    return res;
  }

  inline void push(int x, int l, int r) {
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    if(tree[x].p > INT_MIN) {
      tree[x + 1].apply(l, y, tree[x].p);
      tree[z].apply(y + 1, r, tree[x].p);
      tree[x].p = INT_MIN;
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

  void build(int x, int l, int r, const vector<int> &v) {
    if (l == r) {
      tree[x].apply(l, r, v[l]);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y, v);
    build(z, y + 1, r, v);
    pull(x, z);
  }

  segtree(const vector<int> &v) {
    n = v.size();
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1, v);
  }

  segtree(int _n) : n(_n) {
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1);
  }

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

  void modify(int x, int l, int r, int ll, int rr, int v) {
    if (ll <= l && r <= rr && tree[x].tag(v)) {
      tree[x].apply(l, r, v);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    if (ll <= y) {
      modify(x + 1, l, y, ll, rr, v);
    }
    if (rr > y) {
      modify(z, y + 1, r, ll, rr, v);
    }
    pull(x, z);
  }

  void modify(int ll, int rr, int v) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    modify(0, 0, n - 1, ll, rr, v);
  }

};

struct point {
  int x, y, c;
  bool operator < (const point &a) const {
    return make_pair(y, -x) < make_pair(a.y, -a.x);
  }
};

void debug_out(point a) {
  debug_out(make_pair(a.x, a.y));
}

int n, k, L;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k >> L;
  vector<point> a(n);
  vector<int> x_axis;
  vector<int> y_axis = {0};
  for(int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y >> a[i].c;
    a[i].c--;
    x_axis.push_back(a[i].x);
    y_axis.push_back(a[i].y);
    y_axis.push_back(a[i].y + 1);
  }
  sort(x_axis.begin(), x_axis.end());
  x_axis.resize(unique(x_axis.begin(), x_axis.end()) - x_axis.begin());
  sort(y_axis.begin(), y_axis.end());
  y_axis.resize(unique(y_axis.begin(), y_axis.end()) - y_axis.begin());
  x_axis.push_back(L);
  if(y_axis.back() != L) y_axis.push_back(L);
  map<int, int> id;
  for(int i = 0; i < (int) y_axis.size(); i++) id[y_axis[i]] = i;
  Mint res = 0;
  vector<int> get_over;
  for(int i = 0; i < (int) y_axis.size() - 1; i++) {
    get_over.push_back(~(y_axis[i + 1] - y_axis[i]));
  }
  get_over.push_back(~1);
  for(int now = 0; now < (int) x_axis.size() - 1; now++) {
    Mint mul = x_axis[now] - (now > 0 ? x_axis[now - 1] : -1);
    vector<point> cur;
    vector<set<point>> segs(k);
    for(auto p : a) {
      if(p.x >= x_axis[now]) {
        cur.push_back(p);
        segs[p.c].insert(p);
      }
    }
    sort(cur.begin(), cur.end(), [&](point u, point v){return u.x < v.x;});
    segtree over(get_over);
    bool skip = false;
    for(int i = 0; i < k; i++) {
      for(auto it = segs[i].begin(); it != segs[i].end(); it++) {
        int l = (it == segs[i].begin() ? 0 : id[prev(it)->y + 1]);
        int r = id[it->y];
        if(l > r) continue;
        int v = it->y + 1;
        over.modify(l, r, v);
      }
      if(segs[i].empty()) {
        skip = true;
        break;
      }
      over.modify(id[prev(segs[i].end())->y + 1], id[L], L + 1);
    }
    if(skip) continue;
    for(int i = cur.size() - 1; i >= 0; i--) {
      Mint g = (i == (int) cur.size() - 1 ? L : cur[i + 1].x) - cur[i].x;
      res += (Mint(L + 1) * (L + 1) - Mint(over.get(0, over.n - 1).sum)) * mul * g;
      point p = cur[i];
      int c = p.c;
      auto it = segs[c].find(p);
      assert(it != segs[c].end());
      int l = it == segs[c].begin() ? 0 : id[prev(it)->y + 1];
      int r = id[it->y];
      assert(l <= r);
      int v = it == prev(segs[c].end()) ? L + 1 : next(it)->y + 1;
      over.modify(l, r, v);
      segs[c].erase(it);
    }
  }
  cout << res;
  return 0;
}
