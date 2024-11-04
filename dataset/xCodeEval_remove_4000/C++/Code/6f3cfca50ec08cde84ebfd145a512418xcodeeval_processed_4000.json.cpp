
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
vtii id6(int i, int j) {
  vtii v;
  re(d, 4) v.pb({i + dx[d], j + dy[d]});
  return v;
}

vtii id10(int i, int j) {
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

ll id0(string s) { return stoll(s, nullptr, 2); }
string id9(ll x) {
  assert(x >= 0);
  return !x ? "0" : bitset<64>(x).to_string().substr(63 - bits(x), 1 + bits(x));
}

vector<string> split(string s, string delimiter) {
  size_t pos_start = 0, pos_end, id8 = delimiter.length();
  string token;
  vector<string> res;
  while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
    token = s.substr(pos_start, pos_end - pos_start);
    pos_start = pos_end + id8;
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

  template<typename A> phash(const A &s): pref1(sz(s) + 1u, 0), pref2(sz(s) + 1u, 0) {
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
int phash::base = gen_base(e6, phash::mod);


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



struct data {
  int mn = e9;
  int size = 1;
};

using sd = struct data;

struct opdata {
  int v;
  bool id = false;
};



struct opdata id7 = {e9, true};

class id5 {
  int n; 

  vector<sd> seg;
  vector<opdata> lazy; 


private:
  void combine(sd &pd, const sd &ld, const sd &rd) { 

    pd.mn = min(ld.mn, rd.mn);
    pd.size = ld.size + rd.size;
  }

  

  

  void apply(sd &pd, const opdata &x) {
    if (x.id) return;
    ckmin(pd.mn, x.v);
  }

  

  void compose(opdata &z, const opdata &f) {
    if (f.id) return;
    if (z.id) { z = f; return; }
    ckmin(z.v, f.v);
  }

  void build(vi &v, int p, int l, int r) {
    if (l == r) {
      struct data &pd = seg[p];
      pd.size = 1;
    } else {
      int m = (l + r) / 2;
      build(v, 2 * p, l, m);
      build(v, 2 * p + 1, m + 1, r);
      combine(seg[p], seg[2 * p], seg[2 * p + 1]);
    }
  }

  void build(int p, int l, int r) {
    if (l < r) {
      int m = (l + r) / 2;
      build(2 * p, l, m);
      build(2 * p + 1, m + 1, r);
      combine(seg[p], seg[2 * p], seg[2 * p + 1]);
    }
  }

  void push(int p) { 

    apply(seg[2 * p], lazy[p]);
    compose(lazy[2 * p], lazy[p]);
    apply(seg[2 * p + 1], lazy[p]);
    compose(lazy[2 * p + 1], lazy[p]);

    lazy[p] = id7; assert(id7.id == 1);
  }

  void lazyup(int p, int tl, int tr, int l, int r, const opdata &x) { 

    if (r < tl || tr < l)
      return;
    else if (tl <= l && r <= tr) {
      apply(seg[p], x);
      compose(lazy[p], x);
    } else {
      push(p);
      int m = (l + r) / 2;
      lazyup(2 * p, tl, tr, l, m, x);
      lazyup(2 * p + 1, tl, tr, m + 1, r, x);
      combine(seg[p], seg[2 * p], seg[2 * p + 1]);
    }
  }

  void strictpointup(int p, int t, int l, int r,
                     const opdata &x) { 

    if (r < t || t < l)
      return;
    else if (l == t && r == t) {
      apply(seg[p], x);
    } else {
      push(p);
      int m = (l + r) / 2;
      strictpointup(2 * p, t, l, m, x);
      strictpointup(2 * p + 1, t, m + 1, r, x);
      combine(seg[p], seg[2 * p], seg[2 * p + 1]);
    }
  }

  sd _q(int p, int tl, int tr, int l, int r) { 

    if (r < tl || tr < l) {
      fail();
    } else if (tl <= l && r <= tr) {
      return seg[p];
    } else {
      push(p);
      int m = (l + r) / 2;
      if (tl <= m && m + 1 <= tr) {
        sd lsd = _q(2 * p, tl, tr, l, m);
        sd rsd = _q(2 * p + 1, tl, tr, m + 1, r);
        sd res; combine(res, lsd, rsd);
        return res;
      } else if (tl <= m) {
        return _q(2 * p, tl, tr, l, m);
      } else {
        return _q(2 * p + 1, tl, tr, m + 1, r);
      }
    }
  }

public:
  id5(vi &v) {
    n = sz(v);
    seg.assign(4*n + 30, {});
    lazy.assign(4*n + 30, id7);
    build(v, 1, 0, n - 1);
  }

  id5(int _n) : n(_n) {
    seg.assign(4 * n + 30, {});
    lazy.assign(4 * n + 30, id7);
    build(1, 0, n - 1);
  }

  void up(int tl, int tr, const opdata &x) { lazyup(1, tl, tr, 0, n - 1, x); }

  void pup(int t, const opdata &x) { strictpointup(1, t, 0, n - 1, x); }

  sd q(int tl, int tr) {
    return _q(1, tl, tr, 0, n - 1);
  }
};

typedef id5 st;
typedef vector<id5> vst;

void solve() {
  int n, q; cin >> n >> q;

  id5 seg(n+2);
  si unknown;
  re(i, n+2) unknown.ins(i);

  re(_q, q) {
    int t; cin >> t;
    if (t == 0) {
      int l, r, x; cin >> l >> r >> x;
      if (x == 0) {
        auto it = unknown.lb(l);
        while (*it <= r) {
          it = unknown.erase(it);
        }
      } else if (x == 1) {
        seg.up(l, l, {r});
      } else {
        fail();
      }
    } else if (t == 1) {
      int j; cin >> j;
      if (!unknown.count(j)) {
        cout << "NO\n";
        continue;
      }
      auto it = unknown.find(j);
      auto lit = prev(it);
      auto rit = next(it);

      int l = 1 + *lit;
      int r = -1 + *rit;

      int mx = seg.q(l, j).mn;
      if (mx <= r) {
        cout << "YES\n";
      } else {
        cout << "N/A\n";
      }
    } else {
      fail();
    }
  }
}

int32_t main() {
  setIO();
  int t = 1;
  


  
  double time_start = time();
  
  re(_t, t) solve();
  
  cout << "done. elapsed: " << setprecision(2) << time() - time_start << endl;
  
  return 0;
}
