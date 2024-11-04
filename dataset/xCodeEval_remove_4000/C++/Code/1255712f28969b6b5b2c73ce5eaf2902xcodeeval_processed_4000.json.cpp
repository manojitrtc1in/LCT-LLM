

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;




































































































































template <typename... Args> void logger(string vars, Args &&...values) {
  cout << "| " << vars << " = ";
  string delim = "";
  (..., (cout << delim << values, delim = ", "));
  cout << endl;
}




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
constexpr int bits(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x); }
constexpr int bits(long long x) { return x == 0 ? 0 : 63 - __builtin_clzll(x); }
constexpr int p2(int x) { return 1 << x; }
constexpr int id1(int x) { return p2(x + 1) - 1; }
constexpr bool test(int x, int i) { return (x & (1 << i)) != 0; }
int bitsrange(int l, int u) { assert(l <= u); return id1(u) & (l == 0 ? 0 : id1(l - 1)); }

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

template <class F> F id2(F a, F d) { F res = a / d; if (res * d != a) res -= 1 & ((a>0)^(d>0)); return res; }
template <class F> F ceildiv(F a, F d) { F res = a / d; if (res * d != a) res += 1 & ((a<0)^(d>0)); return res; }
template <class F> F sq(F a) { return a * a; }

long long inv(long long a, long long b) {
  return 1 < a ? b - inv(b % a, a) * b / a : 1;
}

template <class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
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

  int n = sz(a); assert(a.empty() || sz(a) == sz(a[0]));
  vector<vector<F>> copy(n, vector<F>(n));
  re(i, n) {
    re(j, n) { copy[j][n - 1 - i] = a[i][j]; }
  }
  re(i, n) re(j, n) a[i][j] = copy[i][j];
}

template <class F> void r180(vector<vector<F>> &a) {
  int n = sz(a); assert(a.empty() || sz(a) == sz(a[0]));
  vector<vector<F>> copy(n, vector<F>(n));
  re(i, n) {
    re(j, n) { copy[n - 1 - i][n - 1 - j] = a[i][j]; }
  }
  re(i, n) re(j, n) a[i][j] = copy[i][j];
}

template <class F> void r270(vector<vector<F>> &a) {
  int n = sz(a); assert(a.empty() || sz(a) == sz(a[0]));
  vector<vector<F>> copy(n, vector<F>(n));
  re(i, n) {
    re(j, n) { copy[n - 1 - j][i] = a[i][j]; }
  }
  re(i, n) re(j, n) a[i][j] = copy[i][j];
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
    mi temp;
    temp.v = v++;
    return temp;}
  mi operator--(int) {
    mi temp;
    temp.v = v--;
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

void id0() {
  facs[0] = 1;
  re(i, 1, MX) facs[i] = i * facs[i - 1];
  facInvs[MX - 1] = inv(facs[MX - 1]);
  rer(i, MX - 1) facInvs[i] = facInvs[i + 1] * (i + 1);
  facinit = true;
}

template <class F> struct bit {
  int n, l, r;
  vector<F> bt;

  bit(int _l, int _r) : l(_l), r(_r) {
    n = r - l + 1;
    bt.assign(n + 1, -1e9);
  }

  bit(int _n) : n(_n + 1) {
    l = 0, r = n;
    bt.assign(n + 1, -1e9);
  }

  void up(int x, F v) {
    x = x - l + 1;
    assert(1 <= x && x <= n);
    for (; x <= n; x += x & (-x))
      ckmax(bt[x], v);
  }

  F _pre(int x) {
    assert(1 <= x && x <= n);
    F ans = -1e9;
    for (; x > 0; x -= x & (-x))
      ckmax(ans, bt[x]);
    return ans;
  }

  F pre(int x) { return _pre(x - l + 1); }

  F sum(int _l, int _r) { return pre(_r) - (_l == l ? 0 : pre(_l - 1)); }
};

void solve() {
  int n; cin >> n;
  rvl(a, n);

  vl pref(n, 0);
  re(i, n) {
    if (i > 0) pref[i] += pref[i-1];
    pref[i] += a[i];
  }

  sl s;
  s.insert(0);
  re(i, n) s.insert(pref[i]);
  mli m;
  int z = 0;
  ea(x, s) {
    m[x] = z++;
  }

  a[0] = m[a[0]] - m[0];
  re(i, 1, n) {
    a[i] = m[pref[i]] - m[pref[i-1]];
  }

  bit<int> bt(sz(m));
  bt.up(m[0], 0);
  int lastv = 0;
  int cur = m[0];

  re(i, n) {
    cur += a[i];

    int v = -1e9;
    int q;
    if (cur > 0 && (q = bt.pre(cur - 1)) != -1e9) {
      v = bt.pre(cur - 1) + i + 1;
    }
    ckmax(v, lastv - (a[i] != 0));

    bt.up(cur, v - i - 1);
    lastv = v;
  }

  cout << lastv << '\n';
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout << fixed;

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  dbg("done");
  return 0;
}
