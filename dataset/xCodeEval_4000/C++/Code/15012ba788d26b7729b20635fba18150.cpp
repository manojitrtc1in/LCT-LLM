#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define g0 get<0>
#define g1 get<1>
#define g2 get<2>
#define g3 get<3>
#define mill (int)(1e6)
#define bill (int)(1e9)
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vvvl vector<vector<vector<ll>>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vld vector<long double>
#define vvld vector<vector<long double>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vs vector<string>
#define vvs vector<vector<string>>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mt make_tuple
#define tii tuple<int, int>
#define vtii vector<tuple<int, int>>
#define tiii tuple<int, int, int>
#define vtiii vector<tuple<int, int, int>>
#define vtll vector<tuple<ll, ll>>
#define vtli vector<tuple<ll, int>>
#define vtil vector<tuple<int, ll>>
#define vtill vector<tuple<int, ll, ll>>
#define vtlll vector<tuple<ll, ll, ll>>
#define vvtii vector<vtii>
#define vvtiii vector<vtiii>
#define vvtll vector<vtll>
#define vvtli vector<vtli>
#define vvtil vector<vtil>
#define vvtill vector<vtill>
#define vvtlll vector<vtlll>
#define tll tuple<ll, ll>
#define tli tuple<ll, int>
#define til tuple<int, ll>
#define till tuple<int, ll, ll>
#define tlll tuple<ll, ll, ll>
#define qi queue<int>
#define qll queue<ll>
#define umap unordered_map
#define uset unordered_set
#define si set<int>
#define usi unordered_set<int>
#define stii set<tii>
#define ustii uset<tii>
#define mii map<int, int>
#define umii umap<int, int>
#define mli map<ll, int>
#define umli umap<ll, int>
#define mil map<int, ll>
#define umil umap<int, ll>
#define mll map<ll, ll>
#define umll umap<ll, ll>
#define vmii vector<mii>
#define pq priority_queue
#define iss istringstream
#define pf push_front
#define ef emplace_front
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define up upper_bound
#define MOD (int)(1e9 + 7)


#define sor(a) sort(all(a))
#define rev(a) reverse(all(a))
#define mine(a) (*min_element((a).begin(), (a).end()))
#define maxe(a) (*max_element((a).begin(), (a).end()))
#define mini(a) (min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a) (max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) (lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) (upper_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define repb(i, b) for (int i = 0; i < (b); ++i)
#define repab(i, a, b) for (int i = (a); i < (b); ++i)
#define repabd(i, a, b, d) for (int i = (a); i < (b); i += (d))
#define GET_REP(_1, _2, _3, _4, NAME, ...) NAME
#define re(...) GET_REP(__VA_ARGS__, repabd, repab, repb)(__VA_ARGS__)
#define repra(i, a) for (int i = (a)-1; i >= 0; i--)
#define reprab(i, a, b) for (int i = (a)-1; i >= (b); i--)
#define reprabd(i, a, b, d) for (int i = (a)-1; i >= (b); i -= d);
#define GET_REPR(_1, _2, _3, _4, NAME, ...) NAME
#define rer(...) GET_REPR(__VA_ARGS__, reprabd, reprab, repra)(__VA_ARGS__)
#define eachone(a, x) for (auto &a : x)
#define eachtwo(k, v, x) for (auto &[k, v] : x)
#define eachthree(a, b, c, x) for (auto &[a, b, c] : x)
#define GET_EACH(_1, _2, _3, _4, NAME, ...) NAME
#define ea(...) GET_EACH(__VA_ARGS__, eachthree, eachtwo, eachone)(__VA_ARGS__)
#define rvi(v, n) vi v = vi((n)); re(i, n) cin >> v[i];
#define rvl(v, n) vl v = vl((n)); re(i, n) cin >> v[i];
#define rvs(v, n) vs v = vs((n)); re(i, n) cin >> v[i];
#define fail() fflush(stdout); cout.flush(); assert(false);
#define YES cout << "YES\n"
#define YESR { cout << "YES\n"; return; }
#define Yes cout << "Yes\n"
#define Yesr { cout << "Yes\n"; return; }
#define yes cout << "yes\n"
#define yesr { cout << "yes\n"; return; }
#define NO cout << "NO\n"
#define NOR { cout << "NO\n"; return; }
#define No cout << "No\n"
#define Nor { cout << "No\n"; return; }
#define no cout << "no\n";
#define nor { cout << "no\n"; return; }
#define n0 cout << "0\n"
#define n0r { cout << "0\n"; return; }
#define n1 cout << "-1\n"
#define n1r { cout << "-1\n"; return; }
#ifdef LOCAL
#define dbg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args> void logger(string vars, Args &&...values) {
  cout << vars << " = ";
  string delim = "";
  (..., (cout << delim << values, delim = ", "));
  cout << endl;
}
#else
#define dbg(...) 0
#endif

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
constexpr int msk2(int x) { return p2(x) - 1; }

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

template <class F> F floordiv(F a, F d) { F res = a / d; if (res * d != a) res -= 1 & ((a>0)^(d>0)); return res; }
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

void initFacs() {
  facs[0] = 1;
  re(i, 1, MX) facs[i] = i * facs[i - 1];
  facInvs[MX - 1] = inv(facs[MX - 1]);
  rer(i, MX - 1) facInvs[i] = facInvs[i + 1] * (i + 1);
  facinit = true;
}

void solve() {
  int n, m; cin >> n >> m;

  vs v(n);
  re(i, n) {
    cin >> v[i];
  }

  vvi dp(n, vi(m, 0));
  re(j, m) {
    re(i, n) {
      dp[i][j] = max({
          (v[i][j] == '1') + (j > 1 ? dp[i][j-2] : 0),
          j > 0 && i > 0 ? dp[i-1][j-1] : 0,
          j > 0 && i < n-1 ? dp[i+1][j-1] : 0
        });
    }
  }

  int mxeven = 0, mxodd = 0;
  re(i, n) {
    re(j, m) {
      if ((i + j) % 2 == 0) {
        ckmax(mxeven, dp[i][j]);
      } else {
        ckmax(mxodd, dp[i][j]);
      }
    } 
  }

  int ans = mxeven + mxodd;
  cout << ans << '\n';
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout << fixed;

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
