

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

























































































































template <typename... Args> void logger(string vars, Args &&...values) {
  cout << vars << " = ";
  string delim = "";
  (..., (cout << delim << values, delim = ", "));
  cout << endl;
}




constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int pct(long long x) { return __builtin_popcountll(x); }
constexpr int bits(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x); }
constexpr int bits(long long x) { return x == 0 ? 0 : 63 - __builtin_clzll(x); }
constexpr int p2(int x) { return 1 << x; }
constexpr int id1(int x) { return p2(x) - 1; }

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

template<class T> void remdup(vector<T> &v) { 

  sort(all(v)); v.erase(unique(all(v)), end(v));
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

typedef vector<mi> vmi;
typedef vector<vector<mi>> vvmi;
typedef vector<vector<vector<mi>>> vvvmi;
typedef tuple<mi, mi> tmimi;
typedef tuple<mi, mi, mi> tmimimi;
typedef vector<tmimi> vmimi;
typedef vector<tmimimi> vmimimi;
typedef queue<mi> qmi;

const int MX = 1e6;
bool facinit = false;
mi facs[MX];
mi facInvs[MX];

mi ncr(mi _a, mi _b) {
  ll a = (ll)_a;
  ll b = (ll)_b;
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



struct data {
  int mh;
  int mhind;
  ll sum = 0;
};

using sd = struct data;

struct opdata {
  ll v;
  bool id = false;
};



struct opdata id3 = {0, true};

class id2 {
  int n; 

  vector<sd> seg;
  vector<opdata> lazy; 


private:
  void combine(sd &pd, const sd &ld, const sd &rd) { 

    if (ld.mh < rd.mh) {
      pd.mh = ld.mh;
      pd.mhind = ld.mhind;
    } else {
      pd.mh = rd.mh;
      pd.mhind = rd.mhind;
    }
    pd.sum = ld.sum + rd.sum;
  }

  

  

  void apply(sd &pd, const opdata &x) {
    if (x.id) return;
    pd.sum = x.v;
  }

  

  void compose(opdata &z, const opdata &f) {
    if (f.id) return;
    if (z.id) { z = f; return; }
    z.v = z.v + f.v;
  }

  void build(vl &v, vi &height, int p, int l, int r) {
    if (l == r) {
      struct data &pd = seg[p];
      pd.sum = v[l];
      pd.mh = height[l];
      pd.mhind = l;
    } else {
      int m = (l + r) / 2;
      build(v, height, 2 * p, l, m);
      build(v, height, 2 * p + 1, m + 1, r);
      combine(seg[p], seg[2 * p], seg[2 * p + 1]);
    }
  }

  void push(int p) { 

    apply(seg[2 * p], lazy[p]);
    compose(lazy[2 * p], lazy[p]);
    apply(seg[2 * p + 1], lazy[p]);
    compose(lazy[2 * p + 1], lazy[p]);

    lazy[p] = id3;
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
      int m = (l + r) / 2;
      strictpointup(2 * p, t, l, m, x);
      strictpointup(2 * p + 1, t, m + 1, r, x);
      combine(seg[p], seg[2 * p], seg[2 * p + 1]);
    }
  }

  sd q(int p, int tl, int tr, int l, int r) { 

    if (r < tl || tr < l) {
      dbg(l, r, tl, tr);
      cout.flush();
    } else if (tl <= l && r <= tr) {
      return seg[p];
    } else {
      push(p);
      int m = (l + r) / 2;
      if (tl <= m && m + 1 <= tr) {
        sd lsd = q(2 * p, tl, tr, l, m);
        sd rsd = q(2 * p + 1, tl, tr, m + 1, r);
        sd res; combine(res, lsd, rsd);
        return res;
      } else if (tl <= m) {
        return q(2 * p, tl, tr, l, m);
      } else {
        return q(2 * p + 1, tl, tr, m + 1, r);
      }
    }
  }

public:
  id2(vl &v, vi &height) {
    n = sz(v);
    seg.assign(4*n + 30, {});
    lazy.assign(4*n + 30, id3);
    build(v, height, 1, 0, n - 1);
  }

  id2(int _n) : n(_n) {
    seg.assign(4 * n + 30, {});
    lazy.assign(4 * n + 30, id3);
  }

  void up(int tl, int tr, const opdata &x) { lazyup(1, tl, tr, 0, n - 1, x); }

  void pup(int t, const opdata &x) { strictpointup(1, t, 0, n - 1, x); }

  sd query(int tl, int tr) {
    return q(1, tl, tr, 0, n - 1);
  }
};

typedef id2 st;
typedef vector<id2> vst;

const int nmx = 2*1e5+5;
vvi adj(nmx);
vl a(nmx);
vi start(nmx), exi(nmx), height(nmx), inverse(2*nmx), parent(nmx);
int ply = 0;
vi tour;

void dfs(int u, int p, int h) {
  height[u] = h;
  parent[u] = p;
  start[u] = sz(tour);
  exi[u] = sz(tour);
  inverse[sz(tour)] = u;
  tour.pb(u);
  ea(v, adj[u]) {
    if (v != p) {
      dfs(v, u, h + 1);
      exi[u] = sz(tour);
      inverse[sz(tour)] = u;
      tour.pb(u);
    }
  }
}


void solve() {
  int n, q; cin >> n >> q;
  re(i, n) cin >> a[i];
  re(i, n - 1) {
    int s, t; cin >> s >> t;
    s--; t--;
    adj[s].pb(t);
    adj[t].pb(s);
  }

  ply = 0;
  dfs(0, -1, 0);

  vl v(2 * n);
  vi h(2 * n);
  re(i, n) {
    v[start[i]] = abs(a[i]);
    v[exi[i] + 1] = -abs(a[i]);
  }

  re(i, sz(tour)) {
    h[i] = height[tour[i]];
  }

  id2 seg(v, h);

  auto dist = [&](int u, int w) {
    if (u == w) return 0LL;

    if (start[u] > start[w]) swap(u, w);
    int mhind = seg.query(start[u], start[w]).mhind;
    int lca = inverse[mhind];
    ll rem = 0;
    if (lca != 0) {
      rem = seg.query(start[0], start[parent[lca]]).sum; 
    }

    ll du = seg.query(start[0], start[u]).sum;
    ll dv = seg.query(start[0], start[w]).sum;
    if (lca == u) {
      return 2*dv - 2 * rem - v[start[u]] - v[start[w]];
   }
    if (lca == w) {
      return 2*du - 2 * rem - v[start[u]] - v[start[w]];
    }
    return 2 * du + 2 * dv - 4 * rem - v[start[u]] - v[start[w]] - 2 * v[start[lca]];
  };

  re(qq, q) {
    int t, u, w; cin >> t >> u >> w;
    u--;
    if (t == 1) {
      v[start[u]] = abs(w);
      v[exi[u] + 1] = -abs(w);
      seg.pup(start[u], {abs(w)});
      seg.pup(exi[u] + 1, {-abs(w)});
    } else {
      w--;
      cout << dist(u, w) << '\n';
    }
  }
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 1;
  

  while (t--) {
    solve();
  }
  return 0;
}