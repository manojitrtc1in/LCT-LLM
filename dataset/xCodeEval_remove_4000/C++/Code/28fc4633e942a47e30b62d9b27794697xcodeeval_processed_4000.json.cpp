


using namespace std;

using ll = long long;
using ll8 = __int128;
using ld = long double;
using pi = pair<ll, ll>;
using vi = vector<ll>;
template <class T> using vc = vector<T>;
template <class T> using vvc = vector<vc<T>>;
template <class T> using vvvc = vector<vvc<T>>;
template <class T> using vvvvc = vector<vvvc<T>>;
template <class T> using vvvvvc = vector<vvvvc<T>>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;



    vector<type> name(size);                                                                                                                                   \
    IN(name)


    vector<vector<type>> name(h, vector<type>(w));                                                                                                             \
    IN(name)


    vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(id2))))







  for (ll s = (1 << k) - 1, tmp_var = 0; s < (1 << n); \
  tmp_var = s | (s - 1), s = (tmp_var + 1) | (((~tmp_var & -~tmp_var) - 1) >> (__builtin_ctz(s) + 1))) 






using ull = unsigned long long;
using uint = unsigned int;
int popcnt(uint x) {
  return __builtin_popcount(x);
}
int popcnt(int x) {
  return __builtin_popcount(x);
}
int popcnt(ull x) {
  return __builtin_popcountll(x);
}
int popcnt(ll x) {
  return __builtin_popcountll(x);
}
int bsr(uint x) {
  return 31 - __builtin_clz(x);
}
int bsr(ull x) {
  return 63 - __builtin_clzll(x);
}
int ctz(int x) {
  return __builtin_ctz(x);
}
int ctz(ll x) {
  return __builtin_ctzll(x);
}
int ctz(ull x) {
  return __builtin_ctzll(x);
}















ll ceil(ll x, ll y) {
    assert(y >= 1);
    return (x > 0 ? (x + y - 1) / y : x / y);
}

ll floor(ll x, ll y) {
    assert(y >= 1);
    return (x > 0 ? x / y : (x - y + 1) / y);
}

ll mod(ll x, ll y) {
  return x - y * floor(x, y);
}


  int id2; \
  IN(id2)

  ll id2; \
  IN(id2)

  string id2; \
  IN(id2)

  char id2; \
  IN(id2)

  long double id2; \
  IN(id2)
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(long double &a) { cin >> a; }
void scan(string &a) { cin >> a; }
template <class T, class S> void scan(pair<T, S> &p) { scan(p.first), scan(p.second); }
template <class T> void scan(vector<T> &a) {for(auto &i : a) scan(i);}
template <class T> void scan(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail> void IN(Head &head, Tail &...tail) {
  scan(head);
  IN(tail...);
}

ll isqrt(ll n) {
  ll x = n, y = (n + 1) / 2;
  while (y < x) { tie(x, y) = mp(y, (y + n / y) / 2); }
  return x;
}

vi id3(string S, char first_char='a'){
  vi A(S.size());
  FOR(i, S.size()){
    A[i] = S[i] - first_char;
  }
  return A;
}

template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& A) {
  os << A.fi << " " << A.se;
  return os;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& A) {
  for (size_t i = 0; i < A.size(); i++) {
    if(i) os << " ";
    os << A[i];
  }
  return os;
}

void print() {
  cout << "\n";
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(Tail)) cout << " ";
  print(forward<Tail>(tail)...);
}

const string YESNO[2] = {"NO", "YES"};
const string YesNo[2] = {"No", "Yes"};
const string yesno[2] = {"no", "yes"};
void YES(bool t = 1) { cout << YESNO[t] << endl; }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { cout << YesNo[t] << endl; }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { cout << yesno[t] << endl; }
void no(bool t = 1) { yes(!t); }

template <typename T>
vector<T> cumsum(vector<T> A) {
  ll N = A.size();
  vector<T> B(N + 1);
  B[0] = T(0);
  FOR(i, N) { B[i + 1] = B[i] + A[i]; }
  return B;
}

vi bin_count(vi& A, ll size) {
  vi C(size);
  for (auto&& x : A) {
    ++C[x];
  }
  return C;
}

template <typename T>
vi argsort(vector<T>& A){
  vi ids(A.size());
  iota(all(ids), 0);
  sort(all(ids), [&](ll i, ll j){
    return A[i] < A[j] || (A[i] == A[j] && i < j);
  });
  return ids;
}

ll binary_search(function<bool(ll)> check, ll ok, ll ng) {
  while (abs(ok - ng) > 1) {
    auto x = (ng + ok) / 2;
    if (check(x))
      ok = x;
    else
      ng = x;
  }
  return ok;
}

template <class T, class S> inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S> inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }

template <typename T>
vc<T> merge_sort(vc<T>& A, vc<T>& B) {
  vc<T> C;
  C.reserve(A.size() + B.size());
  merge(all(A), all(B), back_inserter(C));
  return C;
}






struct UnionFind {
  int num;
  int comp;
  vi size, par;
  UnionFind(int n) : num(n), comp(n), size(n, 1), par(n) { iota(par.begin(), par.end(), 0); }
  int find(int x) {
    while (par[x] != x) {
      par[x] = par[par[x]];
      x = par[x];
    }
    return x;
  }

  int operator[](int x) {
    return find(x);
  }


  bool merge(ll x, ll y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      return false;
    }
    comp--;
    if (size[x] < size[y]) swap(x, y);
    size[x] += size[y];
    size[y] = 0;
    par[y] = x;
    return true;
  }

  vi find_all() {
    vi A(num);
    FOR(i, num) A[i] = find(i);
    return A;
  }
};


template <typename T>
struct Edge {
  int frm, to;
  T cost;
  int id;
  Edge(int a, int b, T c, int d) : frm(a), to(b), cost(c), id(d) {}
};

template <typename T>
struct Graph {
  int N, M;
  using edge_t = Edge<T>;
  vector<edge_t> edges;
  vector<vector<edge_t>> G;
  bool directed;
  Graph(){}
  Graph(int N, bool bl = false) : N(N), M(0), G(N), directed(bl) {}

  void add(int frm, int to, T cost = 1, int i = -1) {
    if(i == -1) i = M;
    auto e = edge_t(frm, to, cost, i);
    edges.eb(e);
    G[frm].eb(e);
    if (!directed) {
      auto e_rev = edge_t(to, frm, cost, i);
      G[to].eb(e_rev);
    }
    ++M;
  }

  void debug(bool detail=false) {
    FOR(v, N) {
      cout << v << " :";
      for (auto e : G[v]) {
        if(detail) cout << " (" << e.frm << "," << e.to << "," << e.cost << "," << e.id << ")";
        else cout << " " << e.to;
      }
      cout << "\n";
    }
    cout.flush();
  }

  vector<int> degrees(){
    vector<int> deg(N);
    FORIN(e, edges) {
      deg[e.frm]++;
      deg[e.to]++;
    }
    return deg;
  }

  int size(){return N;}

  vector<edge_t>& operator[](int v) { return G[v]; }
};

template <typename Graph, typename E, typename OP, bool edge = false,
          bool id1 = false>
struct id0 {
  using F = function<E(E, E)>;
  using G = function<E(E, OP)>;
  using H = function<OP(OP, OP)>;
  Graph &g;
  int N, height;
  F seg_f;
  G seg_g;
  H seg_h;
  E E_unit;
  OP OP_unit;
  vector<int> sz, LID, RID, EID, head, V, parent;
  vector<E> dat;
  vector<OP> laz;

  id0(Graph &g, F seg_f, G seg_g, H seg_h, E E_unit, OP OP_unit,
           int root = 0)
      : g(g)
      , N(g.size())
      , seg_f(seg_f)
      , seg_g(seg_g)
      , seg_h(seg_h)
      , E_unit(E_unit)
      , OP_unit(OP_unit)
      , sz(g.size())
      , LID(g.size())
      , RID(g.size())
      , EID(g.size() - 1)
      , head(g.size(), root)
      , V(g.size())
      , parent(g.size(), -1)
      , dat(g.size() * 2, E_unit)
      , laz(g.size() * 2, OP_unit) {

    height = 0;
    while ((1 << height) < N) ++height;
    int t = 0;
    dfs_sz(root, -1);
    dfs_hld(root, -1, t);
    FOR(i, N - 1) {
      auto e = g.edges[i];
      EID[i] = LID[(parent[e.frm] == e.to ? e.frm : e.to)];
    }
  }

  void dfs_sz(int idx, int p) {
    parent[idx] = p;
    sz[idx] = 1;
    if (g[idx].size() && g[idx][0].to == p) swap(g[idx][0], g[idx].back());
    for (auto &e : g[idx]) {
      if (e.to == p) continue;
      dfs_sz(e.to, idx);
      sz[idx] += sz[e.to];
      if (sz[g[idx][0].to] < sz[e.to]) swap(g[idx][0], e);
    }
  }

  void dfs_hld(int idx, int par, int &times) {
    LID[idx] = times++;
    V[LID[idx]] = idx;
    for (auto &e : g[idx]) {
      if (e.to == par) continue;
      head[e.to] = (g[idx][0].to == e.to ? head[idx] : e.to);
      dfs_hld(e.to, idx, times);
    }
    RID[idx] = times;
  }

  
  int la(int v, int k) {
    while (1) {
      int u = head[v];
      if (LID[v] - k >= LID[u]) return V[LID[v] - k];
      k -= LID[v] - LID[u] + 1;
      v = parent[u];
    }
  }

  int lca(int u, int v) {
    for (;; v = parent[head[v]]) {
      if (LID[u] > LID[v]) swap(u, v);
      if (head[u] == head[v]) return u;
    }
  }

  void init(vc<E> &v) {
    

    if (!edge) {
      assert(len(v) == N);
      FOR(i, N) dat[N + LID[i]] = v[i];
    } else {
      assert(len(v) == N - 1);
      FOR(i, N - 1) { dat[N + EID[i]] = v[i]; }
    }
    FOR3_R(i, 1, N) dat[i] = seg_f(dat[i << 1 | 0], dat[i << 1 | 1]);
  }

  inline E reflect(int k) {
    return laz[k] == OP_unit ? dat[k] : seg_g(dat[k], laz[k]);
  }

  inline void propagate(int k) {
    if (laz[k] == OP_unit) return;
    laz[(k << 1) | 0] = seg_h(laz[(k << 1) | 0], laz[k]);
    laz[(k << 1) | 1] = seg_h(laz[(k << 1) | 1], laz[k]);
    dat[k] = reflect(k);
    laz[k] = OP_unit;
  }

  inline void thrust(int k) {
    for (int i = height; i; i--) propagate(k >> i);
  }

  inline void recalc(int k) {
    while (k >>= 1)
      dat[k] = seg_f(reflect((k << 1) | 0), reflect((k << 1) | 1));
  }

  void operate_range_(int a, int b, OP x) {
    if (a >= b) return;
    a += N;
    b += N - 1;
    if (!id1) {
      thrust(a);
      thrust(b);
    }
    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) laz[l] = seg_h(laz[l], x), l++;
      if (r & 1) --r, laz[r] = seg_h(laz[r], x);
    }
    recalc(a);
    recalc(b);
  }

  void set(int i, E x) {
    i = (edge ? EID[i] : LID[i]);
    dat[i += N] = x;
    while (i >>= 1) { dat[i] = seg_f(dat[i << 1 | 0], dat[i << 1 | 1]); }
  }

  E fold_seg_(int a, int b) {
    if (a >= b) return E_unit;
    thrust(a += N);
    thrust(b += N - 1);
    E vl = E_unit, vr = E_unit;
    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) vl = seg_f(vl, reflect(l++));
      if (r & 1) vr = seg_f(reflect(--r), vr);
    }
    return seg_f(vl, vr);
  }

  E fold_path(int u, int v) {
    E vl = E_unit, vr = E_unit;
    for (;; v = parent[head[v]]) {
      if (LID[u] > LID[v]) swap(u, v), swap(vl, vr);
      if (head[u] == head[v]) break;
      vl = seg_f(fold_seg_(LID[head[v]], LID[v] + 1), vl);
    }
    E vm = fold_seg_(LID[u] + edge, LID[v] + 1);
    return seg_f(seg_f(vl, vm), vr);
  }

  E fold_subtree(int v) { return fold_seg_(LID[v] + edge, RID[v]); }

  void operate_subtree(int v, OP x) {
    operate_range_(LID[v] + edge, RID[v], x);
  }

  void operate_path(int u, int v, OP x) {
    for (;; v = parent[head[v]]) {
      if (LID[u] > LID[v]) swap(u, v);
      if (head[u] == head[v]) break;
      operate_range_(LID[head[v]], LID[v] + 1, x);
    }
    operate_range_(LID[u] + edge, LID[v] + 1, x);
  }

  void debug() {
    vc<E> A(N);
    FOR(i, N) A[i] = fold_seg_(i, i + 1);
    print(A);
  }
};


void solve() {
  LL(N, M);
  using T = tuple<int, int, int>;
  vector<T> ED(M);
  FOR(i, M) {
    LL(a, b, c);
    ED[i] = mt(--a, --b, c);
  }

  UnionFind uf(N);
  Graph<int> G(N + 1);
  vector<bool> in_tree(M);
  FOR(i, M) {
    auto [a, b, c] = ED[i];
    if (uf.merge(a, b)) {
      in_tree[i] = true;
      G.add(a, b);
    }
  }

  FOR(v, N) if (uf[v] == v) G.add(v, N);
  ++N;

  

  using E = int;
  using OP = int;
  const bool is_edge = true;
  const bool id4 = true;
  id0<Graph<int>, E, OP, is_edge, id4> hld(
    G, [&](E x, E y) -> E { return x | y; },
    [&](E x, OP y) -> E { return x | y; },
    [&](OP x, OP y) -> OP { return x | y; }, E(0), OP(0), N - 1);
  


  auto& par = hld.parent;

  vi sgn(N);
  FOR(i, M) {
    if (in_tree[i]) {
      auto [a, b, c] = ED[i];
      if (par[a] == b)
        sgn[a] = c;
      else
        sgn[b] = c;
    }
  }
  FORIN(v, hld.V) {
    if (par[v] != -1) sgn[v] ^= sgn[par[v]];
  }

  FOR(i, M) {
    auto [a, b, c] = ED[i];
    if (in_tree[i]) {
      YES();
      continue;
    }
    if ((sgn[a] ^ sgn[b] ^ c) == 0) {
      NO();
      continue;
    }
    auto res = hld.fold_path(a, b);
    if (res != 0) {
      NO();
      continue;
    }
    YES();
    hld.operate_path(a, b, true);
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
