

using namespace std;

typedef long long ll;
typedef unsigned long long ull;





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
int SIZE(T(&t)) { return t.size(); }
template<typename T, size_t N>
int SIZE(T(&t)[N]) { return N; }
string to_string(char t) { return "'" + string({t}) + "'"; }
string to_string(bool t) { return t ? "true" : "false"; }
string to_string(const string &t, int x1 = 0, int x2 = 1e9) {
  string ret = "";
  for (int i = min(x1, SIZE(t)), _i = min(x2, SIZE(t) - 1); i <= _i; ++i) { ret += t[i]; }
  return '"' + ret + '"';
}
string to_string(const char *t) {
  string ret(t);
  return to_string(ret);
}
template<size_t N>
string to_string(const bitset<N> &t, int x1 = 0, int x2 = 1e9) {
  string ret = "";
  for (int i = min(x1, SIZE(t)); i <= min(x2, SIZE(t) - 1); ++i) { ret += t[i] + '0'; }
  return to_string(ret);
}
template<typename T, typename... Coords>
string to_string(const T(&t), int x1 = 0, int x2 = 1e9, Coords... C);
template<typename T, typename S>
string to_string(const pair<T, S> &t) { return "(" + to_string(t.first) + ", " + to_string(t.second) + ")"; }
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
struct print_tuple<0, Ts...> { string operator()(const tuple<Ts...> &t) { return to_string(get<0>(t)); }};
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

  static mod_int fact(ll n) {
    if (n <= 1) return 1;
    mod_int res(n);
    --n;
    while (n > 1) res *= n--;
    return res;
  }

  mod_int pow(int64_t p) const {
    if (p < 0)
      return inv().pow(-p);

    mod_int a = *this, result = 1;

    while (p > 0) {
      if (p & 1)
        result *= a;

      p >>= 1;

      if (p > 0)
        a *= a;
    }

    return result;
  }

  friend ostream &operator<<(ostream &stream, const mod_int &m) {
    return stream << m.val;
  }
};

vector<int> ZFunction(const string &s) {
  int n = s.size();
  vector<int> z(n);
  z[0] = 0;

  return z;
}

vector<int> SuffixArray() {
  return {};
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

class DSU {
  vector<int> parent;

 public:
  DSU(int n) {
    parent.resize(n);
    for (int i = 0; i < n; ++i) parent[i] = i;
  }

  int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
  }

  void merge(int u, int v) {
    parent[find(v)] = find(u);
  }
};

void tutorial() {
  int n, q;
  cin >> n >> q;
  SegmentTree<int> seg(n, 0);

  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    seg.SetSumVal(i, k);
  }

  dbg(seg.tree_);

  for (int i = 0; i < q; ++i) {
    int type;
    cin >> type;
    if (type == 1) {
      int l, r;
      cin >> l >> r;
    } else {
      int j, v;
      cin >> j >> v;
      seg.SetSumVal(j, v);
    }
  }

}



void run_tests(int tc = 0) {
  int n; cin >> n;
  unordered_map<int, vector<int>> umap;
  vector<int> u(n);
  for(auto& x : u) cin >> x;
  for(int i = 0; i < n; ++i){
    int x; cin >> x;
    umap[u[i]].push_back(x);
  }

  for(auto& [x, v] : umap) sort(v.rbegin(), v.rend());

  for(auto& [x, v] : umap){
    ll sum = 0;
    for(int i = 0; i < v.size(); ++i){
      sum += v[i];
      v[i] = sum;
    }
  }




  for(int i = 1; i <= n; ++i){
    ll s = 0;
    for(auto& [x, v] : umap){
      if(i > v.size()) continue;
      int k = v.size() % i;
      s += v[v.size() - k - 1];
    }
    cout << s << ' ';
  }
  cout << endl;

}

void solve() {
  ll n, m, k; cin >> n >> m >> k;
  if(n < 2 && (m - 1)== k) cout << "YES" << endl;
  else if(m < 2 && (n - 1) == k) cout << "YES" << endl;
  else if((n - 1) + n * (m - 1) == k) cout << "YES" << endl;
  else cout << "NO" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);



  int test = 1;
  cin >> test;
  while (test--) solve();

  return 0;
}