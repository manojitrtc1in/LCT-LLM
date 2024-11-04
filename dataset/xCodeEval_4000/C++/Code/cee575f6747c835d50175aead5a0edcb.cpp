












































#include <assert.h>

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef long double lld;
typedef priority_queue<pii, vector<pii>, greater<pii>> pqi;
typedef priority_queue<pll, vector<pll>, greater<pll>> pql;



const int INF = 0x3f3f3f3f;
long long INFF = 1000000000000000005ll;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const int dx2[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy2[8] = {0, 1, 1, 1, 0, -1, -1, -1};





#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep1(i, n) for (int i = 1; i <= n; ++i)
#define rep2(i, k, n) for (int i = k; i <= n; ++i)
#define fastio()                    \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define nn "\n"
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define x first
#define y second
#define all(x) x.begin(), x.end()
#define minn(v) *min_element(all(v))
#define maxx(v) *max_element(all(v))
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))



















































#ifndef ONLINE_JUDGE
#define dd(x)        \
  cerr << #x << " "; \
  _print(x);         \
  cerr << endl;
#else
#define dd(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}





const int N = 200010;
ll n, m, k, q, d;
string s;







const double eps = 1e-8;
const double inf = 1e20;
const double pi = acos(-1.0);
const int maxp = 1010;


int sgn(double x) {
  if (fabs(x) < eps) return 0;
  if (x < 0)
    return -1;
  else
    return 1;
}


inline double sqr(double x) { return x * x; }
struct Point {
  double x, y;
  Point() {}
  Point(double _x, double _y) {
    x = _x;
    y = _y;
  }
  void input() { scanf("%lf%lf", &x, &y); }
  void output() { printf("%.10f %.10f\n", x, y); }
  bool operator==(Point b) const {
    return sgn(x - b.x) == 0 && sgn(y - b.y) == 0;
  }
  bool operator<(Point b) const {
    return sgn(x - b.x) == 0 ? sgn(y - b.y) < 0 : x < b.x;
  }
  Point operator-(const Point& b) const { return Point(x - b.x, y - b.y); }
  

  double operator^(const Point& b) const { return x * b.y - y * b.x; }
  

  double operator*(const Point& b) const { return x * b.x + y * b.y; }
  

  double len() {
    return hypot(x, y);  

  }
  

  double len2() { return x * x + y * y; }
  

  double distance(Point p) { return hypot(x - p.x, y - p.y); }
  Point operator+(const Point& b) const { return Point(x + b.x, y + b.y); }
  Point operator*(const double& k) const { return Point(x * k, y * k); }
  Point operator/(const double& k) const { return Point(x / k, y / k); }
  

  

  

  double rad(Point a, Point b) {
    Point p = *this;
    return fabs(atan2(fabs((a - p) ^ (b - p)), (a - p) * (b - p)));
  }
  

  Point trunc(double r) {
    double l = len();
    if (!sgn(l)) return *this;
    r /= l;
    return Point(x * r, y * r);
  }
  

  Point rotleft() { return Point(-y, x); }
  

  Point rotright() { return Point(y, -x); }
  

  Point rotate(Point p, double angle) {
    Point v = (*this) - p;
    double c = cos(angle), s = sin(angle);
    return Point(p.x + v.x * c - v.y * s, p.y + v.x * s + v.y * c);
  }
  

  Point projection(Point p1, Point p2) {
    auto p3 = p1 - p2;
    Point p = *this;
    auto p4 = p - p1;
    double proj_len = p4 * p3 / p3.len();
    return p1 + p3.trunc(proj_len);
  }
  

  Point reflection(Point p1, Point p2, Point p) {
    auto proj = p.projection(p1, p2);
    return proj * 2.0 - p;
  }
  

  double cross(Point A, Point B, Point C) { return (B - A) ^ (C - A); }
  

  double dot(Point A, Point B, Point C) { return (B - A) * (C - A); }
};






const ll mod = 998244353;
ll fac[N], ifac[N];

ll qpow(ll x, ll y) {
  x %= mod;
  ll res = 1ll;
  while (y) {
    if (y & 1) res *= x, res %= mod;
    x *= x;
    x %= mod;
    y >>= 1;
  }
  return res;
}

inline ll inv(ll x) { return qpow(x, mod - 2); }

void init_fac(ll n) {
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % mod;
  ifac[n] = inv(fac[n]);
  for (int i = n; i; --i) ifac[i - 1] = ifac[i] * i % mod;
}

inline ll comb(ll x, ll y) {
  if (x < y || y < 0) return 0;
  return fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}








int fa[N];
int find(int u) {
  

  if (u != fa[u]) fa[u] = find(fa[u]);
  return fa[u];
}



namespace atcoder {

int ceil_pow2(int n) {
  int x = 0;
  while ((1U << x) < (unsigned int)(n)) x++;
  return x;
}
template <class S, S (*op)(S, S), S (*e)()>
struct segtree {
 public:
  segtree() : segtree(0) {}
  explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
  explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
    log = ceil_pow2(_n);
    size = 1 << log;
    d = std::vector<S>(2 * size, e());
    for (int i = 0; i < _n; i++) d[size + i] = v[i];
    for (int i = size - 1; i >= 1; i--) {
      update(i);
    }
  }

  void set(int p, S x) {
    assert(0 <= p && p < _n);
    p += size;
    d[p] = x;
    for (int i = 1; i <= log; i++) update(p >> i);
  }

  S get(int p) const {
    assert(0 <= p && p < _n);
    return d[p + size];
  }

  S prod(int l, int r) const {
    assert(0 <= l && l <= r && r <= _n);
    S sml = e(), smr = e();
    l += size;
    r += size;

    while (l < r) {
      if (l & 1) sml = op(sml, d[l++]);
      if (r & 1) smr = op(d[--r], smr);
      l >>= 1;
      r >>= 1;
    }
    return op(sml, smr);
  }

  S all_prod() const { return d[1]; }

  template <bool (*f)(S)>
  int max_right(int l) const {
    return max_right(l, [](S x) { return f(x); });
  }
  template <class F>
  int max_right(int l, F f) const {
    assert(0 <= l && l <= _n);
    assert(f(e()));
    if (l == _n) return _n;
    l += size;
    S sm = e();
    do {
      while (l % 2 == 0) l >>= 1;
      if (!f(op(sm, d[l]))) {
        while (l < size) {
          l = (2 * l);
          if (f(op(sm, d[l]))) {
            sm = op(sm, d[l]);
            l++;
          }
        }
        return l - size;
      }
      sm = op(sm, d[l]);
      l++;
    } while ((l & -l) != l);
    return _n;
  }

  template <bool (*f)(S)>
  int min_left(int r) const {
    return min_left(r, [](S x) { return f(x); });
  }
  template <class F>
  int min_left(int r, F f) const {
    assert(0 <= r && r <= _n);
    assert(f(e()));
    if (r == 0) return 0;
    r += size;
    S sm = e();
    do {
      r--;
      while (r > 1 && (r % 2)) r >>= 1;
      if (!f(op(d[r], sm))) {
        while (r < size) {
          r = (2 * r + 1);
          if (f(op(d[r], sm))) {
            sm = op(d[r], sm);
            r--;
          }
        }
        return r + 1 - size;
      }
      sm = op(d[r], sm);
    } while ((r & -r) != r);
    return 0;
  }

 private:
  int _n, size, log;
  std::vector<S> d;

  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  







const int M = 2 * N;  



int vis[N];
ll dist[N];
ll deg[N];  




vector<pll> adj[N];



int h[N], e[M], ne[M], w[M], idx;




void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }
void add(int a, int b, int c) {
  e[idx] = b, ne[idx] = h[a], w[idx] = c;
  h[a] = idx++;
}







struct Edge {
  int a, b, c;
  bool operator<(const Edge& w) const { return c < w.c; }
} edges[N];











int main() {
  fastio();
  int T;
  cin >> T;
  init_fac(70);
  

  

  while (T--) {
    cin >> n;
    vector<vector<ll>> dp1(n + 4, vector<ll>(3));
    dp1[2][0] = 1;
    dp1[2][1] = 0;
    dp1[4][0] = 3;
    dp1[4][1] = 2;
    dp1[4][2] = 0;
    if (n == 2)
      cout << 1 << ' ' << 0 << ' ' << 1 << nn;
    else if (n == 4)
      cout << 3 << ' ' << 2 << ' ' << 1 << nn;
    

    

    

    

    else {
      for (int i = 6; i <= n; i += 2) {
        dp1[i][0] = comb(i - 1, i / 2 - 1);
        dp1[i][1] = (dp1[i - 2][0] % mod + dp1[i - 2][2] % mod +
                     comb(i - 2, i / 2 - 2) % mod) %
                    mod;
        dp1[i][2] = dp1[i - 2][1] % mod;
      }
      ll win = (dp1[n][0] % mod + dp1[n][2] % mod) % mod;
      ll tot = comb(n, n / 2);
      ll lose = tot - win - 1;
      if (lose < 0) lose += mod;
      cout << win << ' ' << lose << ' ' << 1 << nn;
    }
  }
  return 0;
}











