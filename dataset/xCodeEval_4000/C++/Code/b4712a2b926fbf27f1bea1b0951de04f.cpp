#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B> string to_string(pair<A, B> p);
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) { res += ", "; }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) { res += static_cast<char>('0' + v[i]); }
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) { res += ", "; }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")"; }
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")"; }
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif



class segtree {
 public:
  struct node {
    int cnt0 = 0;
    int cnt1 = 0;
    int64_t eall = 0;
    int64_t ecur = 0;
    int flip_tag = 0;

    void apply(int l, int r, int act, int eact = 0) {
      if (act) {
        assert(l == r);
        cnt0 = 1;
        eall = eact;
        ecur = 0;
      } else {
        swap(cnt0, cnt1);
        ecur = eall - ecur;
        flip_tag = 1;
      }
    }
  };

  node unite(const node &a, const node &b) const {
    node res;
    res.cnt0 = a.cnt0 + b.cnt0;
    res.cnt1 = a.cnt1 + b.cnt1;
    res.eall = a.eall + b.eall;
    res.ecur = a.ecur + b.ecur;
    return res;
  }

  inline void push(int x, int l, int r) {
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    if (tree[x].flip_tag != 0) {
      tree[x + 1].apply(l, y, 0);
      tree[z].apply(y + 1, r, 0);
      tree[x].flip_tag = 0;
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
    if (n == 0) return;
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1);
  }

  template <typename M>
    segtree(const vector<M> &v) {
      n = v.size();
      if (n == 0) return;
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
  vector< vector<int> > g;
  int n;
  function<bool(int)> ignore;
  graph(int _n) : n(_n) {
    g.resize(n);
    ignore = nullptr;
  }
  virtual int add(int from, int to, T cost) = 0;
  virtual void set_ignore_edge_rule(const function<bool(int)> &f) {
    ignore = f;
  }
  virtual void reset_ignore_edge_rule() {
    ignore = nullptr;
  }
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
  using forest<T>::ignore;
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
      if (id == pe[v] || (ignore != nullptr && ignore(id))) {
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
  vector< vector<int> > pr;
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
  using lca_forest<T>::ignore;
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
    for (int tries = 0; tries < 1; tries++) { 

      if (vs.empty()) {
        dfs_all();
      } else {
        order.clear();
        for (int v : vs) {
          assert(depth[v] == -1);
          dfs(v, false);
        }
        assert((int) order.size() == n);
      }
      
      
      
      for (int i = 0; i < n; i++) {
        if (g[i].empty()) {
          continue;
        }
        int best = -1, bid = 0;
        for (int j = 0; j < (int) g[i].size(); j++) {
          int id = g[i][j];
          if (ignore != nullptr && ignore(id)) {
            continue;
          }
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

  bool apply_on_path(int x, int y, bool with_lca, function<void(int, int, bool)> f) {
    

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

int main() {
  ios::sync_with_stdio(false);

  int N; { cin >> N; }

  map<pair<int, int>, int> eid;
  hld_forest<int> hld(N); {
    hld.init();
    for (int i = 0; i < N - 1; ++i) {
      int U, V; { cin >> U >> V; --U, --V; }
      hld.add(U, V);
      eid[make_pair(U, V)] = i + 1;
      eid[make_pair(V, U)] = i + 1;
    }
    hld.build_hld(0);
  }

  segtree segt(N);
  hld.apply_on_path(0, 0, true, [&](int x, int y, bool _) { segt.modify(x, y, 1); });
  hld.apply_on_path(0, 0, true, [&](int x, int y, bool _) { segt.modify(x, y, 0); });

  vector<vector<int>> active_g(N);
  
  while (true) {
    int P; { cin >> P; }

    if (P == 1) {
      int V; { cin >> V; --V; }
      int pv = hld.pv[V];

      active_g[pv].push_back(V);

      hld.apply_on_path(V, V, true, [&](int x, int y, bool _) { segt.modify(x, y, 1, eid[make_pair(V, pv)]); });
      hld.apply_on_path(V, 0, true, [&](int x, int y, bool _) { segt.modify(x, y, 0); });

      auto r = segt.get(0, N - 1);

      if (r.cnt0 == r.cnt1) {
        cout << r.ecur << endl;
      } else {
        cout << 0 << endl;
      }
    } else if (P == 2) {
      auto r = segt.get(0, N - 1);
      if (r.cnt0 == r.cnt1) {
        vector<int> res; {
          vector<int> sz(N);
          function<int(int)> dfs = [&](int u) {
            sz[u] = 1;
            for (int v : active_g[u]) sz[u] += dfs(v);
            if (sz[u] % 2 == 0) {
              for (int v : active_g[u]) if (sz[v] & 1) res.push_back(eid[make_pair(u, v)]);
            }
            return sz[u];
          };
          dfs(0);
          sort(res.begin(), res.end());
        }

        cout << res.size();
        for (int e : res) cout << " " << e;
        cout << endl;
      } else {
        cout << 0 << endl;
      }
    } else {
      break;
    }
  }
}

