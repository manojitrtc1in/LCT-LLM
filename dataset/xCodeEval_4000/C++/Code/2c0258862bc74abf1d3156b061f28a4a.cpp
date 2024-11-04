#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define rng(i,a,n) for (int i=a;i<=n;i++)
#define gnr(i,a,n) for (int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define one(x) memset(x,-1,sizeof(x))
#define zero(x) memset(x,0,sizeof(x))
typedef long long ll;
typedef double db;
const int inf = INT_MAX / 2 - 100;
const ll infLL=LLONG_MAX/3;

mt19937 irand(random_device{}());
mt19937_64 lrand(random_device{}());
default_random_engine drand(random_device{}());
int rnd(int x) { return irand() % x; }
int rand_int(int l, int r) { return uniform_int_distribution<>(l, r)(irand); }
ll rand_ll(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(lrand); }
db rand_db(db l, db r) { return uniform_real_distribution<> (l, r)(drand); }

inline int add(int a, int b) { a += b; return a >= mod ? a - mod : a; }
inline int sub(int a, int b) { a -= b; return a < 0 ? a + mod : a; }
inline void inc(int& a, int b) { a = add(a, b); }
inline int mul(int a, int b) { return 1LL * a * b % mod; }
template<class t>
inline t ksm(t a, t b) { t r = 1; for (; b; b >>= 1, a = mul(a, a)) if (b & 1) r = mul(r, a); return r; }
inline int inv(int a) {
int b = mod, u = 0, v = 1, t;
while (a) {
t = b / a;
b -= t * a, swap(a, b);
u -= t * v, swap(u, v);
}
return u < 0 ? u + mod : u;
}

template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
using pii=pair<int,int>;
using vi=vc<int>;

template<class t,class u> ostream& operator<<(ostream& os,const pair<t,u>& p)
{ return os<<"{"<<p.a<<","<<p.b<<"}"; }

template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
os<<"{";
for(auto e:v)os<<e<<",";
return os<<"}";
}

template<class T>
T sq(const T& t){ return t*t; }


int topbit(signed t){
return t==0?-1:31-__builtin_clz(t);
}
int topbit(ll t){
return t==0?-1:63-__builtin_clzll(t);
}
int botbit(signed a){
return a==0?32:__builtin_ctz(a);
}
int botbit(ll a){
return a==0?64:__builtin_ctzll(a);
}
int popcount(signed t){
return __builtin_popcount(t);
}
int popcount(ll t){
return __builtin_popcountll(t);
}
bool ispow2(int i){
return i&&(i&-i)==i;
}
ll mask(int i){
return (ll(1)<<i)-1;
}

bool inc(int a,int b,int c){
return a<=b&&b<=c;
}

template<class t> void mkuni(vc<t>&v){
sort(all(v));
v.erase(unique(all(v)),v.ed);
}

template<class t>
void myshuffle(vc<t>&a){
rep(i, 0, SZ(a))swap(a[i],a[rand_int(0,i)]);
}

template<class t>
int lwb(const vc<t>&v,const t&a){
return lower_bound(all(v),a)-v.bg;
}



const int N = 300005;

vc<pii> G[N];
int dft, top[N], dfn[N], fa[N], sz[N], dep[N], hs[N], pf[N];

void dfs(int x, int f) {
	fa[x] = f;
	dep[x] = dep[f] + 1;
	sz[x] = 1;
	for (auto u : G[x]) if (u.fi != f) {
		pf[u.fi] = u.se;
		dfs(u.fi, x);
		sz[x] += sz[u.fi];
		if (sz[u.fi] > sz[hs[x]]) hs[x] = u.fi;
	}
}
void build(int x, int t) {
	top[x] = t;
	dfn[x] = ++ dft;
	if (hs[x]) build(hs[x], t);
	for (auto u : G[x]) if (u.fi != fa[x] && u.fi != hs[x])
		build(u.fi, u.fi);
}
int lca(int x, int y) {
	while (top[x] != top[y])
		if (dep[top[x]] > dep[top[y]]) x = fa[top[x]];
		else y = fa[top[y]];
	return dep[x] < dep[y] ? x : y;
}

void apply(int x, int y, function<void(int, int)> f) {
	while (top[x] != top[y]) {
		if (dep[top[x]] > dep[top[y]]) {
			f(dfn[top[x]], dfn[x]);
			x = fa[top[x]];
		}
		else {
			f(dfn[top[y]], dfn[y]);
			y = fa[top[y]];
		}
	}
	if (x == y) return;
	if (dep[x] > dep[y]) f(dfn[y] + 1, dfn[x]);
	else f(dfn[x] + 1, dfn[y]);
}

#define ls p << 1
#define rs p << 1 | 1
int sum[N * 3], la[N * 3];

void setv(int p, int d, int l) {
	la[p] += d, sum[p] += l * d;
}
void push(int p, int l, int r) {
	if (!la[p]) return;
	int mid = l + r >> 1;
	setv(ls, la[p], mid - l + 1);
	setv(rs, la[p], r - mid);
	la[p] = 0;
}
void modify(int p, int l, int r, int x, int y, int d) {
	if (x <= l && r <= y) return setv(p, d, r - l + 1);
	push(p, l, r); int mid = l + r >> 1;
	if (x <= mid) modify(ls, l, mid, x, y, d);
	if (mid < y) modify(rs, mid + 1, r, x, y, d);
	sum[p] = sum[ls] + sum[rs];
}
int query(int p, int l, int r, int x, int y) {
	if (x <= l && r <= y) return sum[p];
	push(p, l, r); int mid = l + r >> 1, ret = 0;
	if (x <= mid) ret += query(ls, l, mid, x, y);
	if (mid < y) ret += query(rs, mid + 1, r, x, y);
	return ret;
}

class segtree {
 public:
  struct node {
    int add = 0;
    int sum = 0;
 
    void apply(int l, int r, int v) {
      add += v;
      sum += v * (r - l + 1);
    }
  };
 
  node unite(const node &a, const node &b) const {
    node res;
    res.sum = a.sum + b.sum;
    return res;
  }
 
  inline void push(int x, int l, int r) {
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    if (tree[x].add != 0) {
      tree[x + 1].apply(l, y, tree[x].add);
      tree[z].apply(y + 1, r, tree[x].add);
      tree[x].add = 0;
    }
  }
 
  inline void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }
 
  int n;
  vector<node> tree;
 
  void build(int x, int l, int r) {
    if (l == r) {
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y);
    build(z, y + 1, r);
    pull(x, z);
  }
 
  template <typename M>
  void build(int x, int l, int r, const vector<M> &v) {
    if (l == r) {
      tree[x].apply(l, r, v[l]);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y, v);
    build(z, y + 1, r, v);
    pull(x, z);
  }
 
  node get(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x];
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    node res{};
    if (rr <= y) {
      res = get(x + 1, l, y, ll, rr);
    } else {
      if (ll > y) {
        res = get(z, y + 1, r, ll, rr);
      } else {
        res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
      }
    }
    pull(x, z);
    return res;
  }
 
  template <typename... M>
  void modify(int x, int l, int r, int ll, int rr, const M&... v) {
    if (ll <= l && r <= rr) {
      tree[x].apply(l, r, v...);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    if (ll <= y) {
      modify(x + 1, l, y, ll, rr, v...);
    }
    if (rr > y) {
      modify(z, y + 1, r, ll, rr, v...);
    }
    pull(x, z);
  }
 
  int find_first_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[x + 1])) {
      res = find_first_knowingly(x + 1, l, y, f);
    } else {
      res = find_first_knowingly(z, y + 1, r, f);
    }
    pull(x, z);
    return res;
  }
 
  int find_first(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_first_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (ll <= y) {
      res = find_first(x + 1, l, y, ll, rr, f);
    }
    if (rr > y && res == -1) {
      res = find_first(z, y + 1, r, ll, rr, f);
    }
    pull(x, z);
    return res;
  }
 
  int find_last_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[z])) {
      res = find_last_knowingly(z, y + 1, r, f);
    } else {
      res = find_last_knowingly(x + 1, l, y, f);
    }
    pull(x, z);
    return res;
  }
 
  int find_last(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_last_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (rr > y) {
      res = find_last(z, y + 1, r, ll, rr, f);
    }
    if (ll <= y && res == -1) {
      res = find_last(x + 1, l, y, ll, rr, f);
    }
    pull(x, z);
    return res;
  }
 
  segtree(int _n) : n(_n) {
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1);
  }
 
  template <typename M>
  segtree(const vector<M> &v) {
    n = v.size();
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1, v);
  }
 
  node get(int ll, int rr) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return get(0, 0, n - 1, ll, rr);
  }
 
  node get(int p) {
    assert(0 <= p && p <= n - 1);
    return get(0, 0, n - 1, p, p);
  }
 
  template <typename... M>
  void modify(int ll, int rr, const M&... v) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    modify(0, 0, n - 1, ll, rr, v...);
  }
 
  

  

 
  int find_first(int ll, int rr, const function<bool(const node&)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_first(0, 0, n - 1, ll, rr, f);
  }
 
  int find_last(int ll, int rr, const function<bool(const node&)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_last(0, 0, n - 1, ll, rr, f);
  }
};

template <typename T>
class graph {
 public:
  struct edge {
    int from;
    int to;
    T cost;
  };
 
  vector<edge> edges;
  vector<vector<int>> g;
  int n;
 
  graph(int _n) : n(_n) {
    g.resize(n);
  }
 
  virtual int add(int from, int to, T cost) = 0;
};
 
template <typename T>
class forest : public graph<T> {
 public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;
 
  forest(int _n) : graph<T>(_n) {
  }
 
  int add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    assert(id < n - 1);
    g[from].push_back(id);
    g[to].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }
};
 
template <typename T>
class dfs_forest : public forest<T> {
 public:
  using forest<T>::edges;
  using forest<T>::g;
  using forest<T>::n;
 
  vector<int> pv;
  vector<int> pe;
  vector<int> order;
  vector<int> pos;
  vector<int> end;
  vector<int> sz;
  vector<int> root;
  vector<int> depth;
  vector<T> dist;
 
  dfs_forest(int _n) : forest<T>(_n) {
  }
 
  void init() {
    pv = vector<int>(n, -1);
    pe = vector<int>(n, -1);
    order.clear();
    pos = vector<int>(n, -1);
    end = vector<int>(n, -1);
    sz = vector<int>(n, 0);
    root = vector<int>(n, -1);
    depth = vector<int>(n, -1);
    dist = vector<T>(n);
  }
 
  void clear() {
    pv.clear();
    pe.clear();
    order.clear();
    pos.clear();
    end.clear();
    sz.clear();
    root.clear();
    depth.clear();
    dist.clear();
  }
 
 private:
  void do_dfs(int v) {
    pos[v] = (int) order.size();
    order.push_back(v);
    sz[v] = 1;
    for (int id : g[v]) {
      if (id == pe[v]) {
        continue;
      }
      auto &e = edges[id];
      int to = e.from ^ e.to ^ v;
      depth[to] = depth[v] + 1;
      dist[to] = dist[v] + e.cost;
      pv[to] = v;
      pe[to] = id;
      root[to] = (root[v] != -1 ? root[v] : to);
      do_dfs(to);
      sz[v] += sz[to];
    }
    end[v] = (int) order.size() - 1;
  }
 
  void do_dfs_from(int v) {
    depth[v] = 0;
    dist[v] = T{};
    root[v] = v;
    pv[v] = pe[v] = -1;
    do_dfs(v);
  }
 
 public:
  void dfs(int v, bool clear_order = true) {
    if (pv.empty()) {
      init();
    } else {
      if (clear_order) {
        order.clear();
      }
    }
    do_dfs_from(v);
  }
 
  void dfs_all() {
    init();
    for (int v = 0; v < n; v++) {
      if (depth[v] == -1) {
        do_dfs_from(v);
      }
    }
    assert((int) order.size() == n);
  }
};
 
template <typename T>
class lca_forest : public dfs_forest<T> {
 public:
  using dfs_forest<T>::edges;
  using dfs_forest<T>::g;
  using dfs_forest<T>::n;
  using dfs_forest<T>::pv;
  using dfs_forest<T>::pos;
  using dfs_forest<T>::end;
  using dfs_forest<T>::depth;
 
  int h;
  vector<vector<int>> pr;
 
  lca_forest(int _n) : dfs_forest<T>(_n) {
  }
 
  inline void build_lca() {
    assert(!pv.empty());
    int max_depth = 0;
    for (int i = 0; i < n; i++) {
      max_depth = max(max_depth, depth[i]);
    }
    h = 1;
    while ((1 << h) <= max_depth) {
      h++;
    }
    pr.resize(n);
    for (int i = 0; i < n; i++) {
      pr[i].resize(h);
      pr[i][0] = pv[i];
    }
    for (int j = 1; j < h; j++) {
      for (int i = 0; i < n; i++) {
        pr[i][j] = (pr[i][j - 1] == -1 ? -1 : pr[pr[i][j - 1]][j - 1]);
      }
    }
  }
 
  inline bool anc(int x, int y) {
    return (pos[x] <= pos[y] && end[y] <= end[x]);
  }
 
  inline int go_up(int x, int up) {
    assert(!pr.empty());
    up = min(up, (1 << h) - 1);
    for (int j = h - 1; j >= 0; j--) {
      if (up & (1 << j)) {
        x = pr[x][j];
        if (x == -1) {
          break;
        }
      }
    }
    return x;
  }
 
  inline int lca(int x, int y) {
    assert(!pr.empty());
    if (anc(x, y)) {
      return x;
    }
    if (anc(y, x)) {
      return y;
    }
    for (int j = h - 1; j >= 0; j--) {
      if (pr[x][j] != -1 && !anc(pr[x][j], y)) {
        x = pr[x][j];
      }
    }
    return pr[x][0];
  }
};
 
template <typename T>
class hld_forest : public lca_forest<T> {
 public:
  using lca_forest<T>::edges;
  using lca_forest<T>::g;
  using lca_forest<T>::n;
  using lca_forest<T>::pv;
  using lca_forest<T>::sz;
  using lca_forest<T>::pos;
  using lca_forest<T>::order;
  using lca_forest<T>::depth;
  using lca_forest<T>::dfs;
  using lca_forest<T>::dfs_all;
  using lca_forest<T>::lca;
  using lca_forest<T>::build_lca;
 
  vector<int> head;
  vector<int> visited;
 
  hld_forest(int _n) : lca_forest<T>(_n) {
    visited.resize(n);
  }
 
  void build_hld(const vector<int> &vs) {
    for (int tries = 0; tries < 2; tries++) {
      if (vs.empty()) {
        dfs_all();
      } else {
        order.clear();
        for (int v : vs) {
          dfs(v, false);
        }
        assert((int) order.size() == n);
      }
      if (tries == 1) {
        break;
      }
      for (int i = 0; i < n; i++) {
        if (g[i].empty()) {
          continue;
        }
        int best = -1, bid = 0;
        for (int j = 0; j < (int) g[i].size(); j++) {
          int id = g[i][j];
          int v = edges[id].from ^ edges[id].to ^ i;
          if (pv[v] != i) {
            continue;
          }
          if (sz[v] > best) {
            best = sz[v];
            bid = j;
          }
        }
        swap(g[i][0], g[i][bid]);
      }
    }
    build_lca();
    head.resize(n);
    for (int i = 0; i < n; i++) {
      head[i] = i;
    }
    for (int i = 0; i < n - 1; i++) {
      int x = order[i];
      int y = order[i + 1];
      if (pv[y] == x) {
        head[y] = head[x];
      }
    }
  }
 
  void build_hld(int v) {
    build_hld(vector<int>(1, v));
  }
 
  void build_hld_all() {
    build_hld(vector<int>());
  }
 
  bool apply_on_path(int x, int y, bool with_lca, function<void(int,int,bool)> f) {
    

    assert(!head.empty());
    int z = lca(x, y);
    if (z == -1) {
      return false;
    }
    {
      int v = x;
      while (v != z) {
        if (depth[head[v]] <= depth[z]) {
          f(pos[z] + 1, pos[v], true);
          break;
        }
        f(pos[head[v]], pos[v], true);
        v = pv[head[v]];
      }
    }
    if (with_lca) {
      f(pos[z], pos[z], false);
    }
    {
      int v = y;
      int cnt_visited = 0;
      while (v != z) {
        if (depth[head[v]] <= depth[z]) {
          f(pos[z] + 1, pos[v], false);
          break;
        }
        visited[cnt_visited++] = v;
        v = pv[head[v]];
      }
      for (int at = cnt_visited - 1; at >= 0; at--) {
        v = visited[at];
        f(pos[head[v]], pos[v], false);
      }
    }
    return true;
  }
};
int f[N];
int gf(int x) { return x == f[x] ? x : (f[x] = gf(f[x])); }
bool merge(int x, int y) {
	x = gf(x), y = gf(y);
	if (x == y) return 0;
	f[x] = y;
	return 1;
}
int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);
	int n, q;
	cin >> n >> q;
	vi u(q+1), v(q+1), w(q+1);
	vc<bool> ans(q+1, 0);
	rng(i, 1, n) f[i] = i;

  hld_forest<int> g(n);
	rep(i, 0, q) {
		cin >> u[i] >> v[i] >> w[i]; u[i] --, v[i] --;
		if (merge(u[i]+1, v[i]+1)) {
			ans[i] = 1;
      		g.add(u[i], v[i], w[i]);
		}
	}
  g.build_hld_all();
  vector<int> a(n);
  segtree st(n);
  for (int i = 0; i < n; i++) {
    int e = g.pe[i];
    a[g.pos[i]] = (e == -1 ? 0 : g.edges[e].cost);
  }
  vector<int> pref(n + 1);
  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + a[i];
  }
  for (int i = 0; i < q; i++) {
    if (ans[i]) {
      cout << "YES" << '\n';
      continue;
    }
    bool fail = false;
    int sum = 0;
    g.apply_on_path(u[i], v[i], false, [&](int from, int to, bool) {
      if (fail) {
        return;
      }
      if (st.get(from, to).sum > 0) {
        fail = true;
        return;
      }
      sum += pref[to + 1] - pref[from];
    });
    if (!fail && (sum + w[i]) % 2 == 1) {
      cout << "YES" << '\n';
      g.apply_on_path(u[i], v[i], false, [&](int from, int to, bool) {
        st.modify(from, to, 1);
      });
    } else {
      cout << "NO" << '\n';
    }
  }
}