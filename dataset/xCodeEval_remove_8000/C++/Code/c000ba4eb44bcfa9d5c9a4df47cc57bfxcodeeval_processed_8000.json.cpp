
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
















































































































































template <typename A> using pqmax = priority_queue<A>;
template <typename A> using pqmin = priority_queue<A, vector<A>, greater<A>>;

const int MOD = (int) 1e9 + 7;


const ld PI = acos((ld) -1);
const int e1 = (int)1e1, e2 = (int)1e2, e3 = (int)1e3, e4 = (int)1e4, e5 = (int)1e5, e6 = (int)1e6, e7 = (int)1e7, e8 = (int)1e8, e9 = (int) 1e9;
const ll e10 = (ll)1e10, e11 = (ll)1e11, e12 = (ll)1e12, e13 = (ll)1e13, e14 = (ll)1e14, e15 = (ll)1e15, e16 = (ll) 1e16, e17 = (ll)1e17, e18 = (ll) 1e18;



template <typename... Args> void logger(string vars, Args &&...values) {
  cout << "| " << vars << " = ";
  string delim = "";
  (..., (cout << delim << values, delim = ", "));
  cout << endl;
}




struct mi {
  ll v;
  explicit operator ll() const { return v; }
  mi() { v = 0; }
  mi(ll _v) {
    v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
    if (v < 0) v += MOD;
  }
  friend bool operator==(const mi& a, const mi& b) { return a.v == b.v; }
  friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }
  friend bool operator<(const mi& a, const mi& b) { return a.v < b.v; }
  mi& operator+=(const mi& m) { if ((v += m.v) >= MOD) v -= MOD; return *this; }
  mi& operator-=(const mi& m) { if ((v -= m.v) < 0) v += MOD; return *this; }
  mi& operator*=(const mi& m) { v = v * m.v % MOD; return *this; }
  mi& operator/=(const mi& m) { return (*this) *= inv(m); }
  friend mi pow(mi a, ll p) {
    mi ans = 1; assert(p >= 0);
    for (; p; p /= 2, a *= a) if (p&1) ans *= a;
    return ans;}
  friend mi inv(const mi& a) {
    assert(a.v != 0);
    return pow(a, MOD - 2);}
  mi operator-() const { return mi(-v); }
  mi &operator++() { return *this += 1; }
  mi &operator--() { return *this -= 1; }
  mi operator++(int) {
    mi temp = *this += 1;
    return temp;}
  mi operator--(int) {
    mi temp = *this -= 1;
    return temp;}
  friend mi operator+(mi a, const mi &b) { return a += b; }
  friend mi operator-(mi a, const mi &b) { return a -= b; }
  friend mi operator*(mi a, const mi &b) { return a *= b; }
  friend mi operator/(mi a, const mi &b) { return a /= b; }
  friend ostream &operator<<(ostream &os, const mi &m) {
    os << m.v;
    return os;
  }
  friend istream &operator>>(istream &is, mi &m) {
    ll x;
    is >> x;
    m.v = x;
    return is;
  }
};

mi operator"" _mi(ull x) { return x; }
string to_string(mi x) { return to_string(x.v); }

typedef vector<mi> vmi;
typedef vector<vector<mi>> vvmi;
typedef vector<vector<vector<mi>>> vvvmi;
typedef tuple<mi, mi> tmimi;
typedef tuple<mi, mi, mi> tmimimi;
typedef vector<tmimi> vmimi;
typedef vector<tmimimi> vmimimi;
typedef queue<mi> qmi;

template <typename T, typename = void> struct is_container {
  static constexpr bool value = false;
};
template <typename T>
struct is_container<T, void_t<decltype(T{}.begin()), decltype(T{}.end())>> {
  static constexpr bool value = true;
};
template <typename T, typename = void> struct is_tuple_like {
  static constexpr bool value = false;
};
template <typename T>
struct is_tuple_like<T, void_t<typename tuple_size<T>::type>> {
  static constexpr bool value = true;
};
template <typename T, typename = void> struct is_hashable {
  static constexpr bool value = false;
};
template <typename T> struct is_hashable<T, void_t<decltype(hash<T>{}(T{}))>> {
  static constexpr bool value = true;
};

vector<size_t> VALS;
struct custom_hash {
  static size_t getfixed(int i) {
    while ((int) VALS.size() < i + 1)
      if (VALS.empty())
        VALS.push_back((size_t) chrono::steady_clock::now().time_since_epoch().count());
      else
        VALS.push_back(splitmix64(VALS.back()));
    return VALS[i];
  }
  static size_t splitmix64(size_t x) {
    x += (size_t)0x9e3779b97f4a7c15;
    x = (x ^ (x >> (size_t)30)) * (size_t)0xbf58476d1ce4e5b9;
    x = (x ^ (x >> (size_t)27)) * (size_t)0x94d049bb133111eb;
    return x ^ (x >> (size_t)31);
  }
  size_t operator()(size_t x) const { return splitmix64(x + getfixed(0)); }
  template <typename T>
  enable_if_t<is_tuple_like<T>::value, size_t> operator()(const T &t) const {
    int ic = 0;
    size_t rh = 0;
    apply([&](auto &&...args) {
      ((rh ^= splitmix64(hash<decay_t<decltype(args)>>{}(args) + getfixed(ic++))), ...);
    }, t);
    dbg(rh);
    return rh;
  }
  template <typename T>
  enable_if_t<is_container<T>::value, size_t> operator()(const T &t) const {
    int ic = 0; size_t rh = getfixed(0);
    for (auto& x : t) rh &= splitmix64(x + getfixed(ic++));
    return rh;
  }
};

template <typename A, typename B> using umap = unordered_map<A, B, custom_hash>;
template <typename A> using uset = unordered_set<A, custom_hash>;

template <class F> struct y_combinator {
  F f;
  template <class... Args> decltype(auto) operator()(Args &&...args) const {
    return f(*this, forward<Args>(args)...);
  }
};

template <class F> y_combinator<decay_t<F>> lam(F &&f) {
  return {forward<F>(f)};
}

constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int pct(long long x) { return __builtin_popcountll(x); }
constexpr int bits(int x) { return x == 0 ? -1 : 31 - __builtin_clz(x); }
constexpr int bits(long long x) { return x == 0 ? -1 : 63 - __builtin_clzll(x); }
constexpr int p2(int x) { return 1 << x; }
constexpr int id6(int x) { return x == 31 ? 0xFFFFFFFF : ((uint32_t)1 << (x + 1)) - 1; }
constexpr bool test(int x, int i) { return (x & (1 << i)) != 0; }
constexpr bool test(long long x, int i) { return (x & (1LL << i)) != 0; }
int bitsrange(int l, int u) { assert(l <= u); return id6(u) & ~id6(l - 1); }

template <class T, class U> T ipow(T a, U p) {
  T ans = 1; assert(p >= 0);
  for (; p; p /= 2, a *= a) if (p&1) ans *= a;
  return ans;
}
template <class T, class U> T ipow(T a, U p, T m) {
  T ans = 1; assert(p >= 0);
  for (; p; p /= 2, a = (a * a) % m) if (p&1) ans = (ans * a) % m;
  return ans;
}

template <class T, class U> T fstTrue(T lo, T hi, U f) {
  hi++;
  assert(lo <= hi); 

  while (lo < hi) { 

    T mid = lo + (hi - lo) / 2;
    f(mid) ? hi = mid : lo = mid + 1;
  }
  return lo;
}

template <class T, class U> T lstTrue(T lo, T hi, U f) {
  lo--;
  assert(lo <= hi); 

  while (lo < hi) { 

    T mid = lo + (hi - lo + 1) / 2;
    f(mid) ? lo = mid : hi = mid - 1;
  }
  return lo;
}



template <class T, class U>
T id4(T lo, T hi, U f, bool find_min = false) {
  assert(lo <= hi);
  return fstTrue(lo, hi - 1, [&](T n) { return find_min ? f(n) <= f(n + 1) : f(n) >= f(n + 1); });
}

template <class T> T sum(vector<T> &v) {
  if (v.empty()) return 0LL;
  T sum = v[0];
  for (int i = 1; i < (int) v.size(); i++) {
    sum += v[i];
  }
  return sum;
}

template <class F> F posmod(F a, F b) { return ((a % b) + b) % b; }



template <class F>
struct Point {
  F x, y;
  Point(): x(0), y(0) {}
  Point(const F& cx, const F& cy): x(cx), y(cy) {}
};

template <class F> F id7(F a, F d) { F res = a / d; if (res * d != a) res -= 1 & ((a>0)^(d>0)); return res; }
template <class F> F ceildiv(F a, F d) { F res = a / d; if (res * d != a) res += 1 & ((a<0)^(d>0)); return res; }
template <class F> F sq(F a) { return a * a; }

long long inv(long long a, long long b) {
  return 1 < a ? b - inv(b % a, a) * b / a : 1;
}

template <class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
vtii id10(int i, int j) {
  vtii v;
  re(d, 4) v.pb({i + dx[d], j + dy[d]});
  return v;
}

vtii id13(int i, int j) {
  static const int dxdiag[4] = {1, 1, -1, -1}, dydiag[4] = {1, -1, -1, 1};
  vtii v;
  re(d, 4) v.pb({i + dxdiag[d], j + dydiag[d]});
  return v;
}

double time() { return (double)chrono::steady_clock::now().time_since_epoch().count() / 1e9; }


mt19937 rng(2222);

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

int rint(int a, int b) { 

  return uniform_int_distribution<int>(a, b)(rng);
}
double rdouble(double a, double b) {
  return uniform_real_distribution<double>(a, b)(rng);
}
template <class T> void shuffle(vector<T> &v) {
  auto r0 = [](int x) { return rint(0, x-1); };
  random_shuffle(all(v), r0);
}

template <class T> void remdup(vector<T> &v, bool do_sort = true) { 

  if (do_sort) sort(all(v));
  v.erase(unique(all(v)), end(v));
}

template <class F> void print(const Point<F>& point) {
  cout << "x: " << point.x << "\ty: " << point.y << '\n';
}

template <class F> void print(const F a[], int n) {
  for (int i = 0; i < n; i++) {
    if (i > 0) cout << ' ';
    cout << a[i];
  }
  cout << '\n';
}

template <class F> void print(const vector<F> &a) {
  for (int i = 0; i < (int) a.size(); i++) {
    if (i > 0) cout << ' ';
    cout << a[i];
  }
  cout << '\n';
}

template <class F> void print2(const vector<vector<F>> &a) {
  for (int i = 0; i < (int) a.size(); i++) {
    for (int j = 0; j < (int) a[i].size(); j++) {
      if (j > 0) cout << ' ';
      cout << a[i][j];
    }
    cout << '\n';
  }
}

template <class F> void fill2(vector<vector<F>> &a, F val) {
  for (int i = 0; i < (int) a.size(); i++) {
    for (int j = 0; j < (int) a[i].size(); j++) {
      a[i][j] = val;
    }
  }
}

template <class F> void fill3(vector<vector<vector<F>>> &a, F val) {
  for (int i = 0; i < (int) a.size(); i++) {
    for (int j = 0; j < (int) a[i].size(); j++) {
      for (int k = 0; k < (int) a[i][j].size(); k++) {
        a[i][j][k] = val;
      }
    }
  }
}

template <class F> void r90(vector<vector<F>> &a) { 

  int n = sz(a), m = sz(a[0]);
  vector<vector<F>> copy(m, vector<F>(n));
  re(i, n) {
    re(j, m) { copy[j][n - 1 - i] = a[i][j]; }
  }
  a = copy;
}

template <class F> void r180(vector<vector<F>> &a) {
  int n = sz(a), m = sz(a[0]);
  vector<vector<F>> copy(n, vector<F>(m));
  re(i, n) {
    re(j, m) { copy[n - 1 - i][m - 1 - j] = a[i][j]; }
  }
  a = copy;
}

template <class F> void r270(vector<vector<F>> &a) {
  int n = sz(a), m = sz(a[0]);
  vector<vector<F>> copy(m, vector<F>(n));
  re(i, n) {
    re(j, m) { copy[m - 1 - j][i] = a[i][j]; }
  }
  a = copy;
}

string reps(string s, int t) {
  string res = ""; res.reserve(sz(s) * t);
  re(i, t) res += s;
  return res;
}

string reps(char c, int t) { return string(t, c); }

ll id1(string s) { return stoll(s, nullptr, 2); }
string id12(ll x) {
  assert(x >= 0);
  return !x ? "0" : bitset<64>(x).to_string().substr(63 - bits(x), 1 + bits(x));
}

vector<string> split(string s, string delimiter) {
  size_t pos_start = 0, pos_end, id11 = delimiter.length();
  string token;
  vector<string> res;
  while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
    token = s.substr(pos_start, pos_end - pos_start);
    pos_start = pos_end + id11;
    res.push_back(token);
  }
  res.push_back(s.substr(pos_start));
  return res;
}

vector<string> split(string s, char delimiter) { return split(s, string(1, delimiter)); }

string to_string(string s) { return s; }
string to_string(char c) { return string(1, c); }

template <typename... Ts> string to_string(const tuple<Ts...> t) {
  string out;
  out += '(';
  apply([&](auto &&...args) { ((out += to_string(args) + ", "), ...); }, t);
  out.pop_back();
  out.pop_back();
  out += ')';
  return out;
}

template <typename... Ts>
ostream &operator<<(ostream &output, const tuple<Ts...> t) {
  output << to_string(t);
  return output;
}

template <class T> string to_string(vector<T> v) {
  string out = "[";
  re(i, sz(v)) { if (i > 0) out += ", "; out += to_string(v[i]); }
  out += ']';
  return out;
}

template <class T> ostream &operator<<(ostream &output, const vector<T> v) {
  output << to_string(v);
  return output;
}

int gen_base(const int before, const int after) {
  int base = rint(before + 1, after);
  return base % 2 == 0 ? base - 1 : base;
}

struct phash {
  static const int mod = (int) 1e9 + 123;
  static vi pow1; 

  static vector<ull> pow2; 

  static int base;

  vi pref1;
  vector<ull> pref2;

  phash(const string &s): pref1(sz(s) + 1u, 0), pref2(sz(s) + 1u, 0) {
    assert(base < mod);
    const int n = sz(s); 

    while (sz(pow1) <= n) {
      pow1.pb((int) ((ll) pow1.back() * base % mod));
      pow2.pb(pow2.back() * base);
    }
    for (int i = 0; i < n; i++) {
      assert(base > s[i]);
      pref1[i + 1] = (int) ((pref1[i] + (ll) s[i] * pow1[i]) % mod);
      pref2[i + 1] = pref2[i] + s[i] * pow2[i];
    }
  }

  

  inline tuple<int, ull> operator()(const int pos, const int len, int mxPow = -1) const {
    if (mxPow == -1) mxPow = (int) pref1.size() - 1;
    int hash1 = pref1[pos + len] - pref1[pos];
    ull hash2 = pref2[pos + len] - pref2[pos];
    if (hash1 < 0) hash1 += mod;
    if (mxPow != 0) {
      hash1 = (int) ((ll) hash1 * pow1[mxPow - (pos + len - 1)] % mod);
      hash2 *= pow2[mxPow - (pos + len - 1)];
    }
    return {hash1, hash2};
  }
};

vi phash::pow1{1};
vector<ull> phash::pow2{1};
int phash::base = gen_base(256, phash::mod);


const int MX = 1e6 + 30;
bool facinit = false;
mi facs[MX];
mi facInvs[MX];

mi ncr(ll a, ll b) {
  assert(facinit && a < MX && b < MX);
  assert(a >= 0 && b >= 0 && b <= a); 

  if (b > a || a < 0 || b < 0)
    return 0;
  mi cur = facs[a];
  cur = cur * facInvs[b];
  cur = cur * facInvs[a - b];
  return cur;
}

void id8() {
  facs[0] = 1;
  re(i, 1, MX) facs[i] = i * facs[i - 1];
  facInvs[MX - 1] = inv(facs[MX - 1]);
  rer(i, MX - 1) facInvs[i] = facInvs[i + 1] * (i + 1);
  facinit = true;
}

void setIO() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout << fixed << setprecision(15);
  
  
  
  string basename = STRINGIZE_VALUE_OF(FNAME);
  basename = basename.substr(1, sz(basename)-2);
  string file_in = basename + ".in";
  string file_out = basename + ".out";
  freopen(file_in.c_str(), "r", stdin);
  freopen(file_out.c_str(), "w", stdout);
  
}

class dsu {
private:
  vi p, _size;

public:
  int distinct;
  dsu(int n) {
    distinct = n;
    _size.assign(n, 1);
    p.assign(n, 0);
    for (int i = 0; i < n; i++) {
      p[i] = i;
    }
  }

  int find(int i) {
    if (p[i] == i) {
      return i;
    }
    p[i] = find(p[i]);
    return p[i];
  }

  int size(int i) { return _size[find(i)]; }

  int num_sets() { return distinct; }

  int same(int i, int j) { return find(i) == find(j); }

  void merge(int i, int j) {
    if (!same(i, j)) {
      distinct--;
      int repi = find(i);
      int repj = find(j);

      if (_size[repi] < _size[repj]) {
        swap(repi, repj);
      }

      p[repj] = repi;
      _size[repi] += _size[repj];
    }
  }
};

template<typename T, bool maximum_mode = false>
struct RMQ {
  int n = 0;
  vector<T> values;
  vector<vector<int>> range_low;

  RMQ(const vector<T> &_values = {}) {
    if (!_values.empty())
      build(_values);
  }

  static int largest_bit(int x) {
    return x == 0 ? -1 : 31 - __builtin_clz(x);
  }

  

  int better_index(int a, int b) const {
    return (maximum_mode ? values[b] < values[a] : values[a] < values[b]) ? a : b;
  }

  void build(const vector<T> &_values) {
    values = _values;
    n = int(values.size());
    int levels = largest_bit(n) + 1;
    range_low.resize(levels);

    for (int k = 0; k < levels; k++)
      range_low[k].resize(n - (1 << k) + 1);

    for (int i = 0; i < n; i++)
      range_low[0][i] = i;

    for (int k = 1; k < levels; k++)
      for (int i = 0; i <= n - (1 << k); i++)
        range_low[k][i] = better_index(range_low[k - 1][i], range_low[k - 1][i + (1 << (k - 1))]);
  }

  

  int query_index(int a, int b) const {
    assert(0 <= a && a < b && b <= n); 

    int level = largest_bit(b - a);
    return better_index(range_low[level][a], range_low[level][b - (1 << level)]);
  }

  T query_value(int a, int b) const {
    return values[query_index(a, b)];
  }
};





struct LCA {
  int n = 0;
  vector<vector<int>> adj;
  vector<int> parent, depth, subtree_size;
  vector<int> euler, first_occurrence;
  vector<int> tour_start, tour_end, postorder;
  vector<int> tour_list, id9;
  vector<int> heavy_root;
  RMQ<int> rmq;
  bool built;

  LCA(int _n = 0) {
    init(_n);
  }

  

  LCA(const vector<vector<int>> &_adj) {
    init(_adj);
  }

  void init(int _n) {
    n = _n;
    adj.assign(n, {});
    parent.resize(n);
    depth.resize(n);
    subtree_size.resize(n);
    first_occurrence.resize(n);
    tour_start.resize(n);
    tour_end.resize(n);
    postorder.resize(n);
    tour_list.resize(n);
    heavy_root.resize(n);
    built = false;
  }

  

  void init(const vector<vector<int>> &_adj) {
    init(int(_adj.size()));
    adj = _adj;
  }

  void add_edge(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int degree(int v) const {
    return int(adj[v].size()) + (built && parent[v] >= 0);
  }

  void dfs(int node, int par) {
    parent[node] = par;
    depth[node] = par < 0 ? 0 : depth[par] + 1;
    subtree_size[node] = 1;

    

    adj[node].erase(remove(adj[node].begin(), adj[node].end(), par), adj[node].end());

    for (int child : adj[node]) {
      dfs(child, node);
      subtree_size[node] += subtree_size[child];
    }

    

    sort(adj[node].begin(), adj[node].end(), [&](int a, int b) {
      return subtree_size[a] > subtree_size[b];
    });
  }

  int tour, id0;

  void tour_dfs(int node, bool heavy) {
    heavy_root[node] = heavy ? heavy_root[parent[node]] : node;
    first_occurrence[node] = int(euler.size());
    euler.push_back(node);
    tour_list[tour] = node;
    tour_start[node] = tour++;
    bool heavy_child = true;

    for (int child : adj[node]) {
      tour_dfs(child, heavy_child);
      euler.push_back(node);
      heavy_child = false;
    }

    tour_end[node] = tour;
    postorder[node] = id0++;
  }

  void build(int root = -1, bool id2 = true) {
    parent.assign(n, -1);

    if (0 <= root && root < n)
      dfs(root, -1);

    for (int i = 0; i < n; i++)
      if (i != root && parent[i] < 0)
        dfs(i, -1);

    tour = id0 = 0;
    euler.clear();
    euler.reserve(2 * n);

    for (int i = 0; i < n; i++)
      if (parent[i] < 0) {
          tour_dfs(i, false);
          

          euler.push_back(-1);
      }

    id9 = tour_list;
    reverse(id9.begin(), id9.end());
    assert(int(euler.size()) == 2 * n);
    vector<int> id5;
    id5.reserve(euler.size());

    for (int node : euler)
      id5.push_back(node < 0 ? node : depth[node]);

    if (id2)
      rmq.build(id5);

    built = true;
  }

  pair<int, array<int, 2>> get_diameter() const {
    assert(built);

    

    pair<int, int> u_max = {-1, -1};
    pair<int, int> ux_max = {-1, -1};
    pair<int, array<int, 2>> id14 = {-1, {-1, -1}};

    for (int node : euler) {
      if (node < 0) break;
      u_max = max(u_max, {depth[node], node});
      ux_max = max(ux_max, {u_max.first - 2 * depth[node], u_max.second});
      id14 = max(id14, {ux_max.first + depth[node], {ux_max.second, node}});
    }

    return id14;
  }

  

  int get_lca(int a, int b) const {
    a = first_occurrence[a];
    b = first_occurrence[b];

    if (a > b)
      swap(a, b);

    return euler[rmq.query_index(a, b + 1)];
  }

  bool is_ancestor(int a, int b) const {
    return tour_start[a] <= tour_start[b] && tour_start[b] < tour_end[a];
  }

  bool on_path(int x, int a, int b) const {
    return (is_ancestor(x, a) || is_ancestor(x, b)) && is_ancestor(get_lca(a, b), x);
  }

  int get_dist(int a, int b) const {
    return depth[a] + depth[b] - 2 * depth[get_lca(a, b)];
  }

  

  int child_ancestor(int a, int b) const {
    assert(a != b);
    assert(is_ancestor(a, b));

    

    int child = euler[rmq.query_index(first_occurrence[a], first_occurrence[b] + 1) + 1];
    assert(parent[child] == a);
    assert(is_ancestor(child, b));
    return child;
  }

  int get_kth_ancestor(int a, int k) const {
    while (a >= 0) {
      int root = heavy_root[a];

      if (depth[root] <= depth[a] - k)
        return tour_list[tour_start[a] - k];

      k -= depth[a] - depth[root] + 1;
      a = parent[root];
    }

    return a;
  }

  int get_kth_node_on_path(int a, int b, int k) const {
    int anc = get_lca(a, b);
    int first_half = depth[a] - depth[anc];
    int second_half = depth[b] - depth[anc];
    assert(0 <= k && k <= first_half + second_half);

    if (k < first_half)
      return get_kth_ancestor(a, k);
    else
      return get_kth_ancestor(b, first_half + second_half - k);
  }

  

  

  int get_common_node(int a, int b, int c) const {
      

      int x = get_lca(a, b);
      int y = get_lca(b, c);
      int z = get_lca(c, a);
      x = depth[y] > depth[x] ? y : x;
      x = depth[z] > depth[x] ? z : x;
      return x;
  }

  

  

  vector<pair<int, int>> compress_tree(vector<int> nodes) const {
    if (nodes.empty())
      return {};

    auto &&id3 = [&](int a, int b) { return tour_start[a] < tour_start[b]; };
    sort(nodes.begin(), nodes.end(), id3);
    int k = int(nodes.size());

    for (int i = 0; i < k - 1; i++)
      nodes.push_back(get_lca(nodes[i], nodes[i + 1]));

    sort(nodes.begin() + k, nodes.end(), id3);
    inplace_merge(nodes.begin(), nodes.begin() + k, nodes.end(), id3);
    nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
    vector<pair<int, int>> result = {{nodes[0], -1}};

    for (int i = 1; i < int(nodes.size()); i++)
      result.emplace_back(nodes[i], get_lca(nodes[i], nodes[i - 1]));

    return result;
  }
};

str solve(int n, vtii edges) {
  vvi adj(n);
  vtii free;
  dsu dsu(n);
  LCA lca(n);
  ea(u, v, edges) {
    if (dsu.same(u, v)) {
      free.pb({u, v});
    } else {
      dsu.merge(u, v);
      adj[u].pb(v);
      adj[v].pb(u);
      lca.add_edge(u, v);
    }
  }

  vi sum(n, 0);
  vi postsum(n, 0);
  lca.build();

  ea(x, y, free) {
    

    int l = lca.get_lca(x, y);
    if (l == y) swap(x, y);
    


    if (x == l) {
      int nx = lca.get_kth_node_on_path(x, y, 1);
      sum[nx]++;
      sum[y]--;
    } else {
      sum[0]++;
      sum[x]--; sum[y]--;
    }
  }

  vi tots(n, 0);
  auto ds = [&](auto&& self, int u, int p, int t) -> void {
    t += sum[u];
    tots[u] = t;
    ea(v, adj[u]) {
      if (v != p) self(self, v, u, t + postsum[u]);
    }
  };

  ds(ds, 0, 0, 0);

  str ans = "";
  re(i, n) {
    if (tots[i] == 0) ans += "1";
    else ans += "0";
  }
  return ans;
}

str brute(int n, vtii edges) {
  str ans = "";

  vvtii adj(n);
  ll cost = 0;
  dsu dsu(n);
  {
    int i = 0;
    ea(u, v, edges) {
      i++;
      adj[u].pb({v, i});
      adj[v].pb({u, i});
      if (!dsu.same(u, v)) {
        cost += i;
        dsu.merge(u, v);
      }
    }
  }
  ll goal = cost;

  re(i, n) sor(adj[i], [](tii a, tii b) { return g1(a) < g1(b); });

  auto ds = [&](auto&& self, int u, vb &vis) -> void {
    vis[u] = true;
    ea(v, w, adj[u]) {
      if (!vis[v]) {
        cost += w;
        self(self, v, vis);
      }
    }
  };

  re(i, n) {
    vb vis(n, false);
    cost = 0;
    ds(ds, i, vis);
    if (cost == goal) ans += "1";
    else ans += "0";
  }

  return ans;
}

void sol() {
  int n, m; cin >> n >> m;
  vtii edges;
  re(i, m) {
    int u, v; cin >> u >> v;
    u--; v--;
    edges.pb({u, v});
  }
  cout << solve(n, edges) << '\n';
  return;

  

  


  

  

  

  

  

  


  

  

  

  

  

  

  

  

  

  

  


  

  

  

  

  

  

  

  

  


  


  

  

  

  

  

  

  

  

}

int32_t main() {
  setIO();
  int t = 1;
  


  
  double time_start = time();
  
  while (t--) {
    sol();
  }
  
  cout << "done. elapsed: " << setprecision(2) << time() - time_start << endl;
  
  return 0;
}
