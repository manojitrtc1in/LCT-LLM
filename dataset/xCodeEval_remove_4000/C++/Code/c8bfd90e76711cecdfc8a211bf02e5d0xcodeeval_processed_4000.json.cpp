





using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(const char c) {
  string s = "'";
  s += c;
  s += "'";
  return s;
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < (int) v.size(); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  

  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void id1() {
}

template <typename Head, typename... Tail>
void id1(Head H, Tail... T) {
  

  cerr << ", " << to_string(H);
  id1(T...);
}

template <typename Head, typename... Tail>
void id6(Head H, Tail... T) {
  cerr << "[" << to_string(H);
  id1(T...);
  cerr << "]" << endl;
}





  cerr << "[" << 
  id6(__VA_ARGS__)




template <typename T>
class Graph {
 public:
  struct Edge {
    int from;
    int to;
    T cost;
  };

  int n;
  vector<vector<int>> g;
  vector<Edge> edges;

  function<bool(int)> ignore;

  Graph(int _n) : n(_n) {
    g.resize(n);
    ignore = nullptr;
  }

  virtual int add(int from, int to, T cost) = 0;

  virtual void set_ignore_edge_rule(const function<bool(int)>& f) {
    ignore = f;
  }

  virtual void reset_ignore_edge_rule() {
    ignore = nullptr;
  }
};

template <typename T>
class Forest : public Graph<T> {
 public:
  using Graph<T>::n;
  using Graph<T>::g;
  using Graph<T>::edges;

  Forest(int _n) : Graph<T>(_n) {
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
class id2 : public Forest<T> {
 public:
  using Forest<T>::n;
  using Forest<T>::g;
  using Forest<T>::edges;
  using Forest<T>::ignore;

  vector<int> pv;
  vector<int> pe;
  vector<int> order;
  vector<int> pre;
  vector<int> post;
  vector<int> sz;
  vector<int> root;
  vector<int> depth;
  vector<T> dist;

  id2(int _n) : Forest<T>(_n) {
  }

  void init() {
    pv = vector<int>(n, -1);
    pe = vector<int>(n, -1);
    order.clear();
    pre = vector<int>(n, -1);
    post = vector<int>(n, -1);
    sz = vector<int>(n, -1);
    root = vector<int>(n, -1);
    depth = vector<int>(n, -1);
    dist = vector<T>(n);
  }

  void clear() {
    pv.clear();
    pe.clear();
    order.clear();
    pre.clear();
    post.clear();
    sz.clear();
    root.clear();
    depth.clear();
    dist.clear();
  }

 private:
  void do_dfs(int v) {
    pre[v] = (int) order.size();
    order.push_back(v);
    sz[v] = 1;
    for (int id : g[v]) {
      if (id == pe[v] || (ignore != nullptr && ignore(id))) {
        continue;
      }
      auto& e = edges[id];
      int to = e.from ^ e.to ^ v;
      depth[to] = depth[v] + 1;
      dist[to] = dist[v] + e.cost;
      pv[to] = v;
      pe[to] = id;
      root[to] = (root[v] != -1 ? root[v] : to);
      do_dfs(to);
      sz[v] += sz[to];
    }
    post[v] = (int) order.size() - 1;
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
class id3 : public id2<T> {
 public:
  using id2<T>::edges;
  using id2<T>::g;
  using id2<T>::n;
  using id2<T>::pv;
  using id2<T>::pre;
  using id2<T>::post;
  using id2<T>::depth;

  int h;
  vector<vector<int>> pr;

  id3(int _n) : id2<T>(_n) {
  }

  inline void build_lca() {
    assert(!pv.empty());
    int max_depth = 0;
    for (int i = 0; i < n; i++) {
      max_depth = max(max_depth, depth[i]);
    }
    h = 32 - __builtin_clz(max_depth);
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
    assert(0 <= x && x < n && 0 <= y && y < n);
    return (pre[x] <= pre[y] && post[y] <= post[x]);
  }

  inline int lca(int x, int y) {
    assert(0 <= x && x < n && 0 <= y && y < n);
    debug(x, y);
    assert(!pr.empty());
    if (anc(x, y)) {
      return x;
    }
    if (anc(y, x)) {
      return y;
    }
    if (depth[x] > depth[y]) {
      swap(x, y);
    }
    for (int j = 31 - __builtin_clz(depth[x]); j >= 0; j--) {
      debug(j);
      if (pr[x][j] != -1 && !anc(pr[x][j], y)) {
        x = pr[x][j];
      }
    }
    return pr[x][0];
  }
};

mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

namespace persistent_segtree {




struct Node {
  Node* l = NULL;
  Node* r = NULL;
  

  unsigned long long x = 0;

  void apply(int from, int to, unsigned long long v) {
    

    x ^= v;
  }
};

Node* clone(const Node* const v) {
  if (v == NULL) {
    return NULL;
  }
  Node* u = new Node;
  u->l = v->l;
  u->r = v->r;
  

  u->x = v->x;
  return u;
}




Node unite(const Node& a, const Node& b) {
  Node res;
  res.x = a.x ^ b.x;
  return res;
}

void pull(Node* const res, const Node* const a, const Node* const b) {
  

  

  res->x = 0;
  if (a != NULL) {
    

    res->x ^= a->x;
  }
  if (b != NULL) {
    

    res->x ^= b->x;
  }
}

void pull(Node* const x) {
  pull(x, x->l, x->r);
}

void push(Node* const x, int l, int r) {
  

  


  

  

  

  

  

  

  

  

  

  

  

  

  

  

}

void build(Node* x, int l, int r) {
  if (l == r) {
    return;
  }
  int y = (l + r) >> 1;
  x->l = new Node;
  x->r = new Node;
  build(x->l, l, y);
  build(x->r, y + 1, r);
  pull(x);
}

template <typename T>
void build(Node* x, int l, int r, const vector<T>& v) {
  if (l == r) {
    x->apply(l, r, v[l]);
    return;
  }
  int y = (l + r) >> 1;
  x->l = new Node;
  x->r = new Node;
  build(x->l, l, y);
  build(x->r, y + 1, r);
  pull(x);
}

Node get(Node* x, int l, int r, int ll, int rr) {
  if (ll <= l && r <= rr) {
    return *x;
  }
  int y = (l + r) >> 1;
  push(x, l, r);
  Node res{};
  if (rr <= y) {
    res = get(x->l, l, y, ll, rr);
  } else if (ll > y) {
    res = get(x->r, y + 1, r, ll, rr);
  } else {
    res = unite(get(x->l, l, y, ll, rr), get(x->r, y + 1, r, ll, rr));
  }
  pull(x);
  return res;
}

template <typename... T>
void modify(Node* x, int l, int r, int ll, int rr, Node* n, const T&... v) {
  if (ll <= l && r <= rr) {
    n->apply(l, r, v...);
    return;
  }
  int y = (l + r) >> 1;
  push(n, l, r);
  if (ll <= y) {
    n->l = clone(x->l);
    modify(x->l, l, y, ll, rr, n->l, v...);
  }
  if (rr > y) {
    n->r = clone(x->r);
    modify(x->r, y + 1, r, ll, rr, n->r, v...);
  }
  pull(n);
}

int id0(Node* x, int l, int r, const function<bool(const Node* const)>& f) {
  if (l == r) {
    return l;
  }
  int y = (l + r) >> 1;
  push(x, l, r);
  int res;
  if (f(x->l)) {
    res = id0(x->l, l, y, f);
  } else {
    res = id0(x->r, y + 1, r, f);
  }
  pull(x);
  return res;
}

int find_first(Node* x, int l, int r, int ll, int rr, const function<bool(const Node* const)>& f) {
  if (ll <= l && r <= rr) {
    if (f(x)) {
      return id0(x, l, r, f);
    }
    return -1;
  }
  int y = (l + r) >> 1;
  push(x, l, r);
  int res = -1;
  if (ll <= y) {
    res = find_first(x->l, l, y, ll, rr, f);
  }
  if (res == -1 && rr > y) {
    res = find_first(x->r, y + 1, r, ll, rr, f);
  }
  pull(x);
  return res;
}

int id4(Node* x, int l, int r, const function<bool(const Node* const)>& f) {
  if (l == r) {
    return l;
  }
  int y = (l + r) >> 1;
  push(x, l, r);
  int res;
  if (f(x->r)) {
    res = id4(x->r, y + 1, r, f);
  } else {
    res = id4(x->l, l, y, f);
  }
  pull(x);
  return res;
}

int find_last(Node* x, int l, int r, int ll, int rr, const function<bool(const Node* const)>& f) {
  if (ll <= l && r <= rr) {
    if (f(x)) {
      return id4(x, l, r, f);
    }
    return -1;
  }
  int y = (l + r) >> 1;
  push(x, l, r);
  int res = -1;
  if (rr > y) {
    res = find_first(x->r, y + 1, r, ll, rr, f);
  }
  if (res == -1 && ll <= y) {
    res = find_first(x->l, l, y, ll, rr, f);
  }
  pull(x);
  return res;
}

Node* build(int n) {
  Node* root = new Node;
  build(root, 0, n - 1);
  return root;
}

template <typename T>
Node* build(const vector<T>& v) {
  int n = (int) v.size();
  Node* root = new Node;
  build(root, 0, n - 1, v);
  return root;
}

Node get(Node* root, int n, int ll, int rr) {
  assert(0 <= ll && ll <= rr && rr < n);
  return get(root, 0, n - 1, ll, rr);
}

Node get(Node* root, int n, int p) {
  assert(0 <= p && p < n);
  return get(root, 0, n - 1, p, p);
}

template <typename... T>
Node* modify(Node* root, int n, int ll, int rr, const T&... v) {
  assert(0 <= ll && ll <= rr && rr < n);
  Node* new_root = clone(root);
  modify(root, 0, n - 1, ll, rr, new_root, v...);
  return new_root;
}

int find_first(Node* root, int n, int ll, int rr, const function<bool(const Node* const)>& f) {
  assert(0 <= ll && ll <= rr && rr < n);
  return find_first(root, 0, n - 1, ll, rr, f);
}

int find_last(Node* root, int n, int ll, int rr, const function<bool(const Node* const)>& f) {
  assert(0 <= ll && ll <= rr && rr < n);
  return find_first(root, 0, n - 1, ll, rr, f);
}

}  


using namespace persistent_segtree;

int id5(Node* n1, Node* n2, int l, int r) {
  if (l == r) {
    return l;
  }
  int y = (l + r) >> 1;
  if (n1->l->x != n2->l->x) {
    return id5(n1->l, n2->l, l, y);
  } else {
    return id5(n1->r, n2->r, y + 1, r);
  }
}

int Solve(Node* n1, Node* n2, int l, int r, int ll, int rr) {
  if (ll <= l && r <= rr) {
    if (n1->x == n2->x) {
      return -1;
    }
    return id5(n1, n2, l, r);
  }
  int y = (l + r) >> 1;
  int res = -1;
  if (ll <= y) {
    res = Solve(n1->l, n2->l, l, y, ll, rr);
  }
  if (res == -1 && rr > y) {
    res = Solve(n1->r, n2->r, y + 1, r, ll, rr);
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);


  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);


  int n, tt;
  cin >> n >> tt;
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    --c[i];
  }
  id3<int> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g.add(u, v);
  }

  vector<unsigned long long> value(n);
  for (int i = 0; i < n; i++) {
    value[i] = rng();
  }

  

  g.dfs(0);
  g.build_lca();
  debug(g.order);
  debug(g.pre);
  debug(g.post);
  vector<Node*> roots(n);
  Node* empty = build(n);
  roots[0] = modify(empty, n, c[0], c[0], value[c[0]]);
  for (int z = 1; z < n; z++) {
    int v = g.order[z];
    roots[v] = modify(roots[g.pv[v]], n, c[v], c[v], value[c[v]]);
  }

  while (tt--) {
    int u, v, ll, rr;
    cin >> u >> v >> ll >> rr;
    --u;
    --v;
    --ll;
    --rr;

    debug(u, v);

    int L = g.lca(u, v);
    Node* x = modify(roots[u], n, c[L], c[L], value[c[L]]);
    int ans = Solve(x, roots[v], 0, n - 1, ll, rr);
    cout << (ans != -1 ? ans + 1 : -1) << '\n';
  }

  return 0;
}
