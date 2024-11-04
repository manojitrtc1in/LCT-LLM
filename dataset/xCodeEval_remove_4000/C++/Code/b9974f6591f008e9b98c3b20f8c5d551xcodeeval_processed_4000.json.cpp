

using namespace std;

typedef long long ll;
typedef unsigned long long ull;


























using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

using vpii = vector<pii>;
using vpll = vector<pll>;
using vpdd = vector<pdd>;

template<typename T>
void ckmin(T &a, const T &b) { a = min(a, b); }
template<typename T>
void ckmax(T &a, const T &b) { a = max(a, b); }

namespace __input {
template<class T1, class T2>
void re(pair<T1, T2> &p);
template<class T>
void re(vector<T> &a);
template<class T, size_t SZ>
void re(array<T, SZ> &a);

template<class T>
void re(T &x) { cin >> x; }
void re(double &x) {
  string t;
  re(t);
  x = stod(t);
}
template<class Arg, class... Args>
void re(Arg &first, Args &... rest) {
  re(first);
  re(rest...);
}

template<class T1, class T2>
void re(pair<T1, T2> &p) { re(p.f, p.s); }
template<class T>
void re(vector<T> &a) { F0R(i, sz(a)) re(a[i]); }
template<class T, size_t SZ>
void re(array<T, SZ> &a) { F0R(i, SZ) re(a[i]); }
}
using namespace __input;

namespace __output {
template<class T1, class T2>
void pr(const pair<T1, T2> &x);
template<class T, size_t SZ>
void pr(const array<T, SZ> &x);
template<class T>
void pr(const vector<T> &x);
template<class T>
void pr(const set<T> &x);
template<class T1, class T2>
void pr(const map<T1, T2> &x);

template<class T>
void pr(const T &x) { cout << x; }
template<class Arg, class... Args>
void pr(const Arg &first, const Args &... rest) {
  pr(first);
  pr(rest...);
}

template<class T1, class T2>
void pr(const pair<T1, T2> &x) {
  pr("{", x.f, ", ", x.s, "}");
}
template<class T, bool pretty = true>
void prContain(const T &x) {
  if (pretty) pr("{");
  bool fst = 1;
  for (const auto &a : x) pr(!fst ? pretty ? ", " : " " : "", a), fst = 0;
  if (pretty) pr("}");
}
template<class T>
void pc(const T &x) {
  prContain<T, false>(x);
  pr("\n");
}
template<class T, size_t SZ>
void pr(const array<T, SZ> &x) { prContain(x); }
template<class T>
void pr(const vector<T> &x) { prContain(x); }
template<class T>
void pr(const set<T> &x) { prContain(x); }
template<class T1, class T2>
void pr(const map<T1, T2> &x) { prContain(x); }

void ps() { pr("\n"); }
template<class Arg>
void ps(const Arg &first) {
  pr(first);
  ps();
}
template<class Arg, class... Args>
void ps(const Arg &first, const Args &... rest) {
  pr(first, " ");
  ps(rest...);
}
}
using namespace __output;





namespace __algorithm {
template<typename T>
void dedup(vector<T> &v) {
  sort(all(v));
  v.erase(unique(all(v)), v.end());
}
template<typename T>
typename vector<T>::const_iterator find(const vector<T> &v, const T &x) {
  auto it = lower_bound(all(v), x);
  return it != v.end() && *it == x ? it : v.end();
}
template<typename T>
size_t index(const vector<T> &v, const T &x) {
  auto it = find(v, x);
  assert(it != v.end() && *it == x);
  return it - v.begin();
}

template<typename T1, typename T2>
typename vector<pair<T1, T2>>::iterator lower_bound(
    const vector<pair<T1, T2>> &v, const T1 &x) {
  return lower_bound(all(v), x, [](pair<T1, T2> a, pair<T1, T2> b) { return a.f < b.f; });
}
template<typename T1, typename T2>
typename vector<pair<T1, T2>>::iterator upper_bound(
    const vector<pair<T1, T2>> &v, const T1 &x) {
  return upper_bound(all(v), x, [](pair<T1, T2> a, pair<T1, T2> b) { return a.f < b.f; });
}
}
using namespace __algorithm;










namespace __io {
void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(), "w", stdout); }
void setIO(string s = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(15);
  if (sz(s)) { setIn(s + ".in"), setOut(s + ".out"); }
}
}
using namespace __io;





template<typename T>
struct point {
  T x, y;
  point() : x(0), y(0) {}
  point(T _x, T _y) : x(_x), y(_y) {}
  friend istream &operator>>(istream &i, point &p) { return i >> p.x >> p.y; }
  friend ostream &operator<<(ostream &o, const point &p) {
    return o << "(" << p.x << ", " << p.y << ")";
  }

  T norm() const { return x * x + y * y; }
  double len() const { return sqrt(norm()); }
  double ang() const { return atan2(y, x); }
  point<T> conj() const { return {x, -y}; }

  point &operator+=(const point &o) {
    x += o.x;
    y += o.y;
    return *this;
  }
  point &operator-=(const point &o) {
    x -= o.x;
    y -= o.y;
    return *this;
  }
  point &operator*=(const T &c) {
    x *= c;
    y *= c;
    return *this;
  }
  point &operator/=(const T &c) {
    x /= c;
    y /= c;
    return *this;
  }
  friend point operator+(const point &a, const point &b) { return point(a) += b; }
  friend point operator-(const point &a, const point &b) { return point(a) -= b; }
  friend point operator*(const point &a, const T &c) { return point(a) *= c; }
  friend point operator*(const T &c, const point &a) { return point(a) *= c; }
  friend point operator/(const point &a, const T &c) { return point(a) /= c; }

  bool operator==(const point &o) const { return x == o.x && y == o.y; }
  bool operator!=(const point &o) const { return x != o.x || y != o.y; }
  bool operator<(const point &o) const { return (x != o.x) ? x < o.x : y < o.y; }
  bool operator>(const point &o) const { return (x != o.x) ? x > o.x : y > o.y; }
  bool operator<=(const point &o) const { return !(*this > o); }

  friend T dot(const point &a, const point &b) { return a.x * b.x + a.y * b.y; }
  friend T cross(const point &a, const point &b) { return a.x * b.y - a.y * b.x; }
  friend T cross(const point &p, const point &a, const point &b) { return cross(a - p, b - p); }

  friend point<T> operator*(const point &a, const point &b) {
    return {a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x};
  }
  friend point<T> operator/(const point &a, const point &b) {
    return a * b.conj() / b.norm();
  }

  point dir() const { return point(*this) / len(); }
  point rotate(const double &ang) const { return *this * point(cos(ang), sin(ang)); }

  T dist(const point &a) const { return (a - *this).len(); }
  T dist(const point &a, const point &b) {
    return abs(cross(*this, a, b)) / a.dist(b);
  }
  point reflect(const point &a, const point &b) const {
    return a + ((*this - a) / (b - a)).conj() * (b - a);
  }
  point foot(const point &a, const point &b) const {
    return (*this + this->reflect(a, b)) / 2;
  }
  friend point extension(const point &a, const point &b, const point &c, const point &d) {
    T x = cross(a, b, c), y = cross(a, b, d);
    return (d * x - c * y) / (x - y);
  }

  friend vector<point> id0(point a, point b, point c, point d) {
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);

    T a1 = cross(a, b, c), a2 = cross(a, b, d);
    if (a1 > a2) swap(a1, a2);
    if (!(a1 <= 0 && a2 >= 0)) return {};

    if (a1 == 0 && a2 == 0) {
      if (cross(a, c, d) != 0) return {};
      point<T> x1 = max(a, c), x2 = min(b, d);
      if (x1 > x2) return {};
      if (x1 == x2) return {x1};
      return {x1, x2};
    }

    point<T> z = extension(a, b, c, d);
    if (a <= z && z <= b) return {z};
    return {};
  }

  using polygon = vector<point<T>>;
  friend ostream &operator<<(ostream &o, const polygon &poly) {
    o << "{";
    for (auto pt : poly) o << " " << pt;
    return o << " }";
  }

  string classify(const polygon &p) const {
    bool ans = 0;
    for (int i = 0; i < p.size(); i++) {
      point<T> a = p[i], b = p[(i + 1) % p.size()];
      if (cross(a, b, *this) == 0 && min(a, b) <= *this && *this <= max(a, b))
        return "on";
      if (a.y > b.y) swap(a, b);
      if (a.y <= y && y < b.y && cross(*this, a, b) > 0) ans ^= 1;
    }
    return ans ? "in" : "out";
  }

  friend polygon id1(const vector<point> &pts) {
    point pivot = *min_element(all(pts));
    auto sorted = pts;
    sort(all(sorted), [&pivot](const point &p, const point &q) {
      T cp = cross(pivot, p, q);
      if (cp != 0) return cp > 0;
      return pivot.dist(p) < pivot.dist(q);
    });

    int j = 0;
    polygon res(pts.size());
    for (const point &p : sorted) {
      while (j > 1 && cross(res[j - 2], res[j - 1], p) <= 0)
        j--;
      res[j++] = p;
    }
    res.erase(res.begin() + j, res.end());
    return res;
  }

  

  friend T area(const polygon &p) {
    T a = 0;
    for (int i = 0; i < sz(p); i++)
      a += cross(p[i], p[i + 1 < sz(p) ? i + 1 : 0]);
    return a;
  }
};



template<typename T>
int SIZE(T(&t)) {
  return t.size();
}

template<typename T, size_t N>
int SIZE(T(&t)[N]) {
  return N;
}

string to_string(char t) {
  return "'" + string({t}) + "'";
}

string to_string(bool t) {
  return t ? "true" : "false";
}

string to_string(const string &t, int x1 = 0, int x2 = 1e9) {
  string ret = "";
  for (int i = min(x1, SIZE(t)), _i = min(x2, SIZE(t) - 1); i <= _i; ++i) {
    ret += t[i];
  }
  return '"' + ret + '"';
}

string to_string(const char *t) {
  string ret(t);
  return to_string(ret);
}

template<size_t N>
string to_string(const bitset<N> &t, int x1 = 0, int x2 = 1e9) {
  string ret = "";
  for (int i = min(x1, SIZE(t)); i <= min(x2, SIZE(t) - 1); ++i) {
    ret += t[i] + '0';
  }
  return to_string(ret);
}

template<typename T, typename... Coords>
string to_string(const T(&t), int x1 = 0, int x2 = 1e9, Coords... C);

template<typename T, typename S>
string to_string(const pair<T, S> &t) {
  return "(" + to_string(t.first) + ", " + to_string(t.second) + ")";
}

template<typename T, typename... Coords>
string to_string(const T(&t), int x1, int x2, Coords... C) {
  string ret = "[";
  x1 = min(x1, SIZE(t));
  auto e = begin(t);
  advance(e, x1);
  for (int i = x1, _i = min(x2, SIZE(t) - 1); i <= _i; ++i) {
    ret += to_string(*e, C...) + (i != _i ? ", " : "");
    e = next(e);
  }
  return ret + "]";
}

template<int Index, typename... Ts>
struct print_tuple {
  string operator()(const tuple<Ts...> &t) {
    string ret = print_tuple<Index - 1, Ts...>{}(t);
    ret += (Index ? ", " : "");
    return ret + to_string(get<Index>(t));
  }
};

template<typename... Ts>
struct print_tuple<0, Ts...> {
  string operator()(const tuple<Ts...> &t) {
    return to_string(get<0>(t));
  }
};

template<typename... Ts>
string to_string(const tuple<Ts...> &t) {
  const auto Size = tuple_size<tuple<Ts...>>::value;
  return print_tuple<Size - 1, Ts...>{}(t);
}

void dbgr() { ; }
template<typename Heads, typename... Tails>
void dbgr(Heads H, Tails... T) {
  cout << to_string(H) << " | ";
  dbgr(T...);
}

void dbgs() { ; }
template<typename Heads, typename... Tails>
void dbgs(Heads H, Tails... T) {
  cout << H << " ";
  dbgs(T...);
}



















const int MOD = 1e9 + 7;

struct mod_int {
  ll val;

  mod_int(ll v = 0) {
    if (v < 0) v = v % MOD + MOD;
    if (v >= MOD) v %= MOD;
    val = v;
  }

  static int mod_inv_gcdex(int a, int m = MOD) {
    

    int g = m, r = a, x = 0, y = 1;

    while (r != 0) {
      int q = g / r;
      g %= r;
      swap(g, r);
      x -= q * y;
      swap(x, y);
    }

    return x < 0 ? x + m : x;
  }

  static ll mod_inv(ll a, ll m = MOD) {
    if (a == 1) return 1;
    return (m - m / a * mod_inv(m % a) % m) % m;
  }

  explicit operator ll() const {
    return val;
  }

  mod_int &operator+=(const mod_int &other) {
    val += other.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }

  mod_int &operator-=(const mod_int &other) {
    val -= other.val;
    if (val < 0) val += MOD;
    return *this;
  }

  mod_int &operator*=(const mod_int &other) {
    val *= ll(other) % MOD;
    val %= MOD;
    return *this;
  }

  mod_int &operator/=(const mod_int &other) {
    return *this *= other.inv();
  }

  friend mod_int operator+(const mod_int &a, const mod_int &b) { return mod_int(a) += b; }
  friend mod_int operator-(const mod_int &a, const mod_int &b) { return mod_int(a) -= b; }
  friend mod_int operator*(const mod_int &a, const mod_int &b) { return mod_int(a) *= b; }
  friend mod_int operator/(const mod_int &a, const mod_int &b) { return mod_int(a) /= b; }

  mod_int &operator++() {
    val = val == MOD - 1 ? 0 : val + 1;
    return *this;
  }

  mod_int &operator--() {
    val = val == 0 ? MOD - 1 : val - 1;
    return *this;
  }

  mod_int operator++(int) {
    mod_int before = *this;
    ++*this;
    return before;
  }
  mod_int operator--(int) {
    mod_int before = *this;
    --*this;
    return before;
  }

  mod_int operator-() const {
    return val == 0 ? 0 : MOD - val;
  }

  bool operator==(const mod_int &other) const { return val == other.val; }
  bool operator!=(const mod_int &other) const { return val != other.val; }

  mod_int inv() const {
    return mod_inv(val);
  }

  friend ostream &operator<<(ostream &stream, const mod_int &m) {
    return stream << m.val;
  }
};

mod_int fact(ll n) {
  if (n <= 1) return 1;
  mod_int res(n);
  --n;
  while (n > 1) res *= n--;
  return res;
}

vi ZFunction(const string &s) {
  int n = s.size();
  vi z(n);
  z[0] = 0;

  return z;
}

vi SuffixArray() {
}

template<class T>
struct SegmentTree {
  vector<T> tree_;
  size_t size;

  SegmentTree(size_t n, const T &v) {
    size = 1;
    while (size < n) size *= 2;
    tree_.assign(size * 2 - 1, v);
  }

  void SetSumVal(int i, const T &v) {
    SetSumVal(i, v, 0, 0, size);
  }

  void SetSumVal(int i, const T &v, int x, int lx, int rx) {
    if (rx - lx == 1) {
      tree_[x] = v;
      return;
    }

    int m = (lx + rx) / 2;
    if (i < m) {
      SetSumVal(i, v, 2 * x + 1, lx, m);
    } else SetSumVal(i, v, 2 * x + 2, m, rx);

    tree_[x] = tree_[2 * x + 1] + tree_[2 * x + 2];
  }

  T Sum(int l, int r) {
    return Sum(l, r, 0, 0, size);
  }

  T Sum(int l, int r, int x, int lx, int rx) {
    if (lx >= l && rx <= r) {
      return tree_[x];
    }

    if (lx >= r || rx <= l) return 0;
    int m = (lx + rx) / 2;
    T left = Sum(l, r, 2 * x + 1, lx, m);
    T right = Sum(l, r, 2 * x + 2, m, rx);

    return left + right;
  }

  void SetMaxVal(int i, const T &v) {
    SetMaxVal(i, v, 0, 0, size);
  }

  void SetMaxVal(int i, const T &v, int x, int lx, int rx) {
    if (rx - lx == 1) {
      tree_[x] = v;
      return;
    }

    int m = (lx + rx) / 2;
    if (i < m) {
      SetSumVal(i, v, 2 * x + 1, lx, m);
    } else SetSumVal(i, v, 2 * x + 2, m, rx);

    tree_[x].first = max(tree_[2 * x + 1].first, tree_[2 * x + 2].first);
    tree_[x].second = max(tree_[2 * x + 1].first, tree_[2 * x + 2].first);
  }
};





int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  







  


  int test;
  cin >> test;
  while (test--) {

    int n; re(n);
    vll a(n); re(a);

    ll c = -1, d = -1;
    ll mx = a[0];

    bool f = true;
    for(int i = 1; i < n; ++i){
      if(a[i] >= a[i - 1]){
        if(c >= 0 && c != a[i] - a[i - 1]) f = 0;
        c = a[i] - a[i - 1];
      }

      if(a[i] <= a[i - 1]){
        if(d >= 0 && d != a[i - 1] - a[i]) f = 0;
        d = a[i - 1] - a[i];
      }
      mx = max(mx, a[i]);
    }

    if(!f) cout << -1 << endl;
    else if(c <= 0 || d <= 0) cout << 0 << endl;
    else if(c + d <= mx) cout << - 1 << endl;
    else cout << c + d << ' ' << c << endl;
  }


  

  return 0;
}