


#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;



#define lp for (;;)
#define repf(i, a, b) for (int i = (a); i < (b); ++i)
#define ft(i, a, b) for (int i = (a); i <= (b); ++i)
#define fdt(i, a, b) for (int i = (a); i >= (b); --i)
#define rrepf(i, a, b) fdt(i, (a)-1, b)
#define rep(i, n) repf(i, 0, n)
#define rrep(i, n) rrepf(i, n, 0)
#define for_each(e, s) \
  for (__typeof__((s).begin()) e = (s).begin(); e != (s).end(); ++e)
#define for_nonempty_subsets(subset, set) \
  for (int subset = set; subset; subset = (subset - 1) & (set))
#define for_in_charset(i, charset) for (cstr i = (charset); *i; i++)
#define whl while
#define rtn return
#define fl(x, y) memset((x), char(y), sizeof(x))
#define clr(x) fl(x, char(0))
#define cpy(x, y) memcpy(x, y, sizeof(x))
#define sf scanf
#define pf printf
#define vec vector
#define pr pair
#define que queue
#define prq priority_queue
#define itr iterator
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define ins insert
#define ers erase
#define lb lower_bound
#define ub upper_bound
#define rnk order_of_key
#define sel find_by_order
#define ctz __builtin_ctz
#define clz __builtin_clz
#define bc __builtin_popcount
#define sz(x) (int((x).size()))
#define all(x) (x).begin(), (x).end()
#define srt(x) sort(all(x))
#define uniq(x) srt(x), (x).erase(unique(all(x)), (x).end())
#define rev(x) reverse(all(x))
#define shf(x) random_shuffle(all(x))
#define nxtp(x) next_permutation(all(x))



#ifndef DEBUG
#define prt(x) (cerr)
#define asrtWA(s)      \
  do                   \
    if (!(s)) exit(0); \
  whl(0)
#define asrtTLE(s)    \
  do                  \
    if (!(s)) whl(1); \
  whl(0)
#define asrtMLE(s)          \
  do                        \
    if (!(s)) whl(new int); \
  whl(0)
#define asrtOLE(s)                \
  do                              \
    if (!(s)) whl(1) puts("OLE"); \
  whl(0)
#define asrtRE(s)           \
  do                        \
    if (!(s)) *(int*)0 = 0; \
  whl(0)
#define runtime() (cerr)
#define input(in) freopen(in, "r", stdin)
#define output(out) freopen(out, "w", stdout)
#else
#define prt(x) cerr << "第" << __LINE__ << "行\t: " << #x "\t=" << (x) << endl
#define asrtWA(s)                               \
  do                                            \
    if (!(s)) cerr << "assert(" #s ")" << endl; \
  whl(0)
#define asrtTLE(s)                              \
  do                                            \
    if (!(s)) cerr << "assert(" #s ")" << endl; \
  whl(0)
#define asrtMLE(s)                              \
  do                                            \
    if (!(s)) cerr << "assert(" #s ")" << endl; \
  whl(0)
#define asrtOLE(s)                              \
  do                                            \
    if (!(s)) cerr << "assert(" #s ")" << endl; \
  whl(0)
#define asrtRE(s)                               \
  do                                            \
    if (!(s)) cerr << "assert(" #s ")" << endl; \
  whl(0)
#define runtime()                                                          \
  cout << flush, cerr << flush << "Used: " << db(clock()) / CLOCKS_PER_SEC \
                      << "s" << endl
#define input(in)
#define output(out)
#endif



typedef long long int lli;
typedef double db;
typedef const char* cstr;
typedef string str;
typedef vec<int> vi;
typedef vec<vi> vvi;
typedef vec<lli> vl;
typedef vec<vl> vvl;
typedef vec<bool> vb;
typedef vec<vb> vvb;
typedef vec<char> vc;
typedef vec<vc> vvc;
typedef vec<str> vs;
typedef pr<int, int> pii;
typedef pr<lli, lli> pll;
typedef pr<db, db> pdd;
typedef vec<pii> vpii;
typedef vec<pll> vpll;
typedef vec<pdd> vpdd;
typedef map<int, int> mii;
typedef map<str, int> msi;
typedef map<char, int> mci;
typedef set<int> si;
typedef set<str> ss;
typedef que<int> qi;



int oo = (~0u) >> 1;
lli ooll = (~0ull) >> 1;
db inf = 1e+10;
db eps = 1e-10;
db gam = 0.5772156649015328606;
db pi = acos(-1.0);
int dx[] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
int MOD = 1000000007;



template <typename type>
inline bool cmax(type& a, const type& b) {
  rtn a < b ? a = b, true : false;
}
template <typename type>
inline bool cmin(type& a, const type& b) {
  rtn b < a ? a = b, true : false;
}
template <typename type>
inline type sqr(const type& x) {
  rtn x* x;
}
template <typename type>
inline type mod(const type& x) {
  rtn x % MOD;
}
inline int sgn(const db& x) { rtn(x > +eps) - (x < -eps); }
inline int dbcmp(const db& a, const db& b) { rtn sgn(a - b); }
template <typename type>
inline pr<type, type> operator-(const pr<type, type>& x) {
  rtn mp(-x.x, -x.y);
}
template <typename type>
inline pr<type, type> operator+(const pr<type, type>& a,
                                const pr<type, type>& b) {
  rtn mp(a.x + b.x, a.y + b.y);
}
template <typename type>
inline pr<type, type> operator-(const pr<type, type>& a,
                                const pr<type, type>& b) {
  rtn mp(a.x - b.x, a.y - b.y);
}
template <typename type>
inline pr<type, type> operator*(const pr<type, type>& a, const type& b) {
  rtn mp(a.x * b, a.y * b);
}
template <typename type>
inline pr<type, type> operator/(const pr<type, type>& a, const type& b) {
  rtn mp(a.x / b, a.y / b);
}
template <typename type>
inline pr<type, type>& operator-=(pr<type, type>& a, const pr<type, type>& b) {
  rtn a = a - b;
}
template <typename type>
inline pr<type, type>& operator+=(pr<type, type>& a, const pr<type, type>& b) {
  rtn a = a + b;
}
template <typename type>
inline pr<type, type>& operator*=(pr<type, type>& a, const type& b) {
  rtn a = a * b;
}
template <typename type>
inline pr<type, type>& operator/=(pr<type, type>& a, const type& b) {
  rtn a = a / b;
}
template <typename type>
inline type cross(const pr<type, type>& a, const pr<type, type>& b) {
  rtn a.x* b.y - a.y* b.x;
}
template <typename type>
inline type dot(const pr<type, type>& a, const pr<type, type>& b) {
  rtn a.x* b.x + a.y* b.y;
}
template <typename type>
inline type gcd(type a, type b) {
  if (b) whl((a %= b) && (b %= a));
  rtn a + b;
}
template <typename type>
inline type lcm(type a, type b) {
  rtn a* b / gcd(a, b);
}
inline lli bin_pow(lli x, lli y) {
  lli z = 1;
  whl(y) {
    if (y & 1) z = mod(z * x);
    x = mod(sqr(x)), y >>= 1;
  }
  rtn z;
}
template <typename istream, typename first_type, typename second_type>
inline istream& operator>>(istream& cin, pr<first_type, second_type>& x) {
  rtn cin >> x.x >> x.y;
}
template <typename ostream, typename first_type, typename second_type>
inline ostream& operator<<(ostream& cout,
                           const pr<first_type, second_type>& x) {
  rtn cout << x.x << " " << x.y;
}
template <typename istream, typename type>
inline istream& operator>>(istream& cin, vec<type>& x) {
  rep(i, sz(x)) cin >> x[i];
  rtn cin;
}
template <typename ostream, typename type>
inline ostream& operator<<(ostream& cout, const vec<type>& x) {
  rep(i, sz(x)) cout << x[i] << (i + 1 == sz(x) ? "" : " ");
  rtn cout;
}
inline ostream& pdb(int prcs, db x) {
  rtn cout << setprecision(prcs) << fixed << (sgn(x) ? (x) : 0);
}
template <typename type>
inline void bit_inc(vec<type>& st, int x, type inc) {
  whl(x < sz(st)) st[x] += inc, x |= x + 1;
}
template <typename type>
inline type bit_sum(const vec<type>& st, int x) {
  type s = 0;
  whl(x >= 0) s += st[x], x = (x & (x + 1)) - 1;
  rtn s;
}
template <typename type>
inline type bit_kth(const vec<type>& st, int k) {
  int x = 0, y = 0, z = 0;
  whl((1 << (++y)) <= sz(st));
  rrep(i, y) {
    if ((x += 1 << i) > sz(st) || z + st[x - 1] > k)
      x -= 1 << i;
    else
      z += st[x - 1];
  }
  rtn x;
}
inline void make_set(vi& st) { rep(i, sz(st)) st[i] = i; }
inline int find_set(vi& st, int x) {
  int y = x, z;
  whl(y != st[y]) y = st[y];
  whl(x != st[x]) z = st[x], st[x] = y, x = z;
  rtn y;
}
inline bool union_set(vi& st, int a, int b) {
  a = find_set(st, a), b = find_set(st, b);
  rtn a != b ? st[a] = b, true : false;
}
inline void make_set(vpii& st) { rep(i, sz(st)) st[i] = mp(i, 1); }
inline int find_set(vpii& st, int x) {
  int y = x, z;
  whl(y != st[y].x) y = st[y].x;
  whl(x != st[x].x) z = st[x].x, st[x].x = y, x = z;
  rtn y;
}
inline bool union_set(vpii& st, int a, int b) {
  a = find_set(st, a), b = find_set(st, b);
  rtn a != b ? (st[a].y > st[b].y ? st[a].x = b,
                st[a].y += st[b].y : st[b].x = a, st[b].y += st[a].y),
      true : false;
}
template <typename type>
inline void merge(type& a, type& b) {
  if (sz(a) < sz(b)) swap(a, b);
  whl(sz(b)) a.ins(*b.begin()), b.ers(b.begin());
}



struct Initializer {
#ifndef DEBUG
  Initializer() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  }
#else
  ~Initializer() { runtime(); }
#endif
} initializer;



#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
typedef __gnu_cxx::rope<char> rope;
template <typename key, typename value>
class ext_map
    : public __gnu_pbds::tree<key, value, less<key>, __gnu_pbds::rb_tree_tag,
                              __gnu_pbds::tree_order_statistics_node_update> {};
int n, k;
vi adj[1 << 20];
struct ans {
  lli a[5];
};

int par[1 << 20];
unordered_map<int, ans> dp[200000];
ans RET[200000];
ans RRET[200000];
bool calced[200000];

lli ANS;

ans dfs__(int u, int p) {
  ans ret;
  rep(i, k) ret.a[i] = i == 0;
  lli sm = 1, d = 0;
  for (int v : adj[u]) {
    if (v != p) {
      ans get_ = dfs__(v, u), get;
      rep(i, k - 1) { get.a[i + 1] = get_.a[i]; }
      get.a[0] = get_.a[k - 1];
      if (k != 1) ANS += get.a[1] * sm, d += get.a[1] * sm;
      if (u == 0) {
        prt(get.a[1]), prt(sm);
      }
      rep(i, k) {
        ret.a[i] += get.a[i];
        sm += get.a[i];
      }
    }
  }
  if (k == 1) {
    ANS += sm * (n - sm);
  } else {
    ANS += ret.a[1] * (n - sm);
    d += ret.a[1] * (n - sm);
  }
  prt(u), prt(d);
  return ret;
}

ans dfs(int u, int p) {
  par[u] = p;
  ans ret;
  rep(i, k) ret.a[i] = i == 0;
  for (int v : adj[u]) {
    if (v != p) {
      ans& get_ = dp[u][v];
      get_ = dfs(v, u);
      ans get;
      rep(i, k - 1) { get.a[i + 1] = get_.a[i]; }
      get.a[0] = get_.a[k - 1];
      rep(i, k) { ret.a[i] += get.a[i]; }
    }
  }
  RET[u] = ret;
  return ret;
}
ans gao(int u, int p) {
  if (calced[p]) {
    return RRET[p];
  }
  calced[p] = true;
  ans ret = RET[u];
  ans& get_ = dp[u][p];
  ans get;
  rep(i, k - 1) { get.a[i + 1] = get_.a[i]; }
  get.a[0] = get_.a[k - 1];
  

  

  

  rep(i, k) {
    ret.a[i] -= get.a[i];
    

    

    

  }
  









  if (par[u] != -1) {
    ans t_ = gao(par[u], u);
    rep(i, k - 1) { get.a[i + 1] = t_.a[i]; }
    get.a[0] = t_.a[k - 1];
    

    rep(i, k) { ret.a[i] += get.a[i]; }
    

    

  }
  

  RRET[p] = ret;
  

  return ret;
}

int main() {
  cin >> n >> k;
  rep(i, n - 1) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  if (k == 1) {
    dfs__(0, -1);
  } else {
    dfs(0, -1);
    rep(u, n) {
      if (par[u] != -1) {
        lli sm = 0;
        rep(i, k) sm += RET[u].a[i];
                ANS += RET[u].a[0] * (n - sm);
        ANS += gao(par[u], u).a[0] * sm;


      }
    }
        ANS /= 2;
  }
  cout << ANS << endl;
}
