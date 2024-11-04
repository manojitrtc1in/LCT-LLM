
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




vector<uint64_t> id9;
struct custom_hash { 

  static uint64_t getfixed(int i) {
    while (sz(id9) < i+1) {
      if (id9.empty()) {
        id9.pb(chrono::steady_clock::now().time_since_epoch().count());
      } else {
        id9.pb(splitmix64(id9.back()));
      }
    }
    return id9[i];
  }

  static uint64_t splitmix64(uint64_t x) {
    

    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    return (size_t) splitmix64(x + getfixed(0));
  }

  template <typename... Ts> size_t operator()(const tuple<Ts...> t) const {
    int ic = 0; uint64_t rh = 0;
    apply([&](auto &&...args) { ((rh ^= splitmix64(args + getfixed(ic++))), ...); }, t);
    return (size_t) rh;
  }

  template <typename T> size_t operator()(const vector<T> v) const {
    uint64_t rh = getfixed(0);
    re(i, sz(v)) rh ^= splitmix64(v[i] + getfixed(i+1));
    return (size_t) rh;
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
constexpr int id2(int x) { return x == 31 ? 0xFFFFFFFF : ((uint32_t)1 << (x + 1)) - 1; }
constexpr bool test(int x, int i) { return (x & (1 << i)) != 0; }
constexpr bool test(long long x, int i) { return (x & (1LL << i)) != 0; }
int bitsrange(int l, int u) { assert(l <= u); return id2(u) & ~id2(l - 1); }

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
T id1(T lo, T hi, U f, bool find_min = false) {
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

template <class F> F id3(F a, F d) { F res = a / d; if (res * d != a) res -= 1 & ((a>0)^(d>0)); return res; }
template <class F> F ceildiv(F a, F d) { F res = a / d; if (res * d != a) res += 1 & ((a<0)^(d>0)); return res; }
template <class F> F sq(F a) { return a * a; }

long long inv(long long a, long long b) {
  return 1 < a ? b - inv(b % a, a) * b / a : 1;
}

template <class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
vtii id5(int i, int j) {
  vtii v;
  re(d, 4) v.pb({i + dx[d], j + dy[d]});
  return v;
}

vtii id8(int i, int j) {
  static const int dxdiag[4] = {1, 1, -1, -1}, dydiag[4] = {1, -1, -1, 1};
  vtii v;
  re(d, 4) v.pb({i + dxdiag[d], j + dydiag[d]});
  return v;
}

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

ll id0(string s) { return stoll(s, nullptr, 2); }
string id7(ll x) {
  assert(x >= 0);
  return !x ? "0" : bitset<64>(x).to_string().substr(63 - bits(x), 1 + bits(x));
}

vector<string> split(string s, string delimiter) {
  size_t pos_start = 0, pos_end, id6 = delimiter.length();
  string token;
  vector<string> res;
  while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
    token = s.substr(pos_start, pos_end - pos_start);
    pos_start = pos_end + id6;
    res.push_back(token);
  }
  res.push_back(s.substr(pos_start));
  return res;
}

vector<string> split(string s, char delimiter) { return split(s, string(1, delimiter)); }

string to_string(string s) { return s; }
string to_string(char c) { return string(1, c); }
template <class T> string to_string(vector<T> v) {
  string out = "[";
  re(i, sz(v)) { if (i > 0) out += ", "; out += to_string(v[i]); }
  out += ']';
  return out;
}

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

  inline std::pair<int, ull> operator()(const int pos, const int len, int mxPow = -1) const {
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

typedef vector<mi> vmi;
typedef vector<vector<mi>> vvmi;
typedef vector<vector<vector<mi>>> vvvmi;
typedef tuple<mi, mi> tmimi;
typedef tuple<mi, mi, mi> tmimimi;
typedef vector<tmimi> vmimi;
typedef vector<tmimimi> vmimimi;
typedef queue<mi> qmi;

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

void id4() {
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

void solve() {
  int n; cin >> n;
  vvtii adj(n);
  re(i, n-1) {
    int u, v, x; cin >> u >> v >> x;
    u--; v--; x--;
    adj[u].pb({v, x});
    adj[v].pb({u, x});
  }

  ll ans = 0;
  vi ts(n);
  vi prim(n), sec(n);
  auto ds = [&](auto&& self, int u, int p) -> void {
    ts[u] = 1;
    ea(v, w, adj[u]) {
      if (p == v) continue;
      int oprim = prim[w]; int osec = sec[w];
      prim[w] = 0; sec[w] = 0;

      self(self, v, u);
      ts[u] += ts[v];
      ans += (ll) (ts[v] - prim[w]) * (prim[w] - sec[w]);

      sec[w] = prim[w];
      prim[w] = ts[v];

      prim[w] += oprim; sec[w] += osec;
    }
  };

  ds(ds, 0, 0);

  re(w, n) {
    ans += (ll) (n - prim[w]) * (prim[w] - sec[w]);
  }

  cout << ans << '\n';
}

int32_t main() {
  setIO();
  int t = 1;
  

  while (t--) {
    solve();
  }
  dbg("done");
  return 0;
}
