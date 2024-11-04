
using namespace std;





template <class Node_t, typename Query_t, bool push = true, bool break_cond = false>
struct segment_tree {
  int lim, length;
  vector<Node_t> data;
  Node_t& operator [] (int i) { return data[i]; }

  segment_tree(int n, bool init_build = false): lim(n),
    length(1 << (lim == 1 ? 0 : 32 - __builtin_clz(lim - 1))), data(2*length) {
    if (init_build) build();
  }
  template <class Input_t>
  segment_tree(const vector<Input_t>& a, int offset = 0): lim((int)size(a)),
    length(1 << (lim == 1 ? 0 : 32 - __builtin_clz(lim - 1))), data(2*length) {
    for (int i = offset; i < lim; i++) {
      data[length + i] = Node_t(a[i]);
    }
    build();
  }
  void build() {
    for (int i = length - 1; i > 0; i--) {
      data[i].pull(data[2*i], data[2*i + 1]);
    }
  }

  template <class... Args>
  void update_range(int l, int r, const Args&... args) {
    update(l, r, args...);
  }
  template <class... Args>
  void update(int l, int r, const Args&... args) {
    if (r < l) return;
    assert(0 <= l && r < lim);
    __update(l, r, 1, 0, length - 1, args...);
  }
  template <class... Args>
  void __update(int l, int r, int i, int first, int last, const Args&... args) {
    if constexpr (break_cond) {
      if (data[i].break_condition(args...)) return;
      if (l <= first && last <= r && data[i].put_condition(args...)) {
        return data[i].put(args...);
      }
      assert(i < length);
    } else {
      if (l <= first && last <= r) {
        return data[i].put(args...);
      }
    }
    if constexpr (push) data[i].push(data[2*i], data[2*i + 1]);
    int mid = (first + last) / 2;
    if(l <= mid) __update(l, r, 2*i, first, mid, args...);
    if(mid < r) __update(l, r, 2*i + 1, mid + 1, last, args...);
    data[i].pull(data[2*i], data[2*i + 1]);
  }

  template <class... Args>
  Query_t query_range(int l, int r, const Args&... args) {
    return query(l, r, args...);
  }
  template <class... Args>
  Query_t query(int l, int r, const Args&... args) {
    if (r < l) return Node_t::default_value();
    assert(0 <= l && r < lim);
    return __query(l, r, 1, 0, length - 1, args...);
  }
  template <class... Args>
  Query_t __query(int l, int r, int i, int first, int last, const Args&... args) {
    if (l <= first && last <= r) return data[i].get(args...);
    if constexpr (push) data[i].push(data[2*i], data[2*i + 1]);
    int mid = (first + last) / 2;
    if(r <= mid) return __query(l, r, 2*i, first, mid, args...);
    if(mid < l) return __query(l, r, 2*i + 1, mid + 1, last, args...);
    return Node_t::merge(
        __query(l, r, 2*i, first, mid, args...),
        __query(l, r, 2*i + 1, mid + 1, last, args...));
  }

  template <class... Args>
  void update_point(int x, const Args&... args) {
    assert(0 <= x && x < lim);
    id7(x, 1, 0, length - 1, args...);
  }
  template <class... Args>
  void id7(int x, int i, int first, int last, const Args&... args) {
    if (first == last) return data[i].put(args...);
    if constexpr (push) data[i].push(data[2*i], data[2*i + 1]);
    int mid = (first + last) / 2;
    if (x <= mid) id7(x, 2*i, first, mid, args...);
    else id7(x, 2*i + 1, mid + 1, last, args...);
    data[i].pull(data[2*i], data[2*i + 1]);
  }

  template <class... Args>
  Query_t query_point(int x, const Args&... args) {
    assert(0 <= x && x < lim);
    return id11(x, 1, 0, length - 1, args...);
  }
  template <class... Args>
  Query_t id11(int x, int i, int first, int last, const Args&... args) {
    if (first == last) return data[i].get(args...);
    if constexpr (push) data[i].push(data[2*i], data[2*i + 1]);
    int mid = (first + last) / 2;
    if (x <= mid) return id11(x, 2*i, first, mid, args...);
    else return id11(x, 2*i + 1, mid + 1, last, args...);
  }

  template <class... Args>
  Query_t query_up(int x, const Args&... args) {
    assert(0 <= x && x < lim);
    return id3(x, 1, 0, length - 1, args...);
  }
  template <class... Args>
  Query_t id3(int x, int i, int first, int last, const Args&... args) {
    if (first == last) return data[i].get(args...);
    if constexpr (push) data[i].push(data[2*i], data[2*i + 1]);
    int mid = (first + last) / 2;
    if (x <= mid) {
      return Node_t::merge(data[i].get(args...), id3(x, 2*i, first, mid, args...));
    } else {
      return Node_t::merge(data[i].get(args...), id3(x, 2*i + 1, mid + 1, last, args...));
    }
  }

  template <class... Args>
  int search_left(int l, int r, Args... args) {
    if (r < l) return lim;
    assert(0 <= l && r < lim);
    return id6(l, r, 1, 0, length - 1, forward_as_tuple(args...));
  }
  template <class... Args>
  int id0(int l, int r, Args&... args) {
    if (r < l) return lim;
    assert(0 <= l && r < lim);
    return id6(l, r, 1, 0, length - 1, forward_as_tuple(args...));
  }
  template <class... Args>
  int id6(int l, int r, int i, int first, int last, tuple<Args&...> args) {
    if (l <= first && last <= r
        && !apply(&Node_t::contains, tuple_cat(tuple(data[i]), args))) return lim;
    if (first == last) return first;
    if constexpr (push) data[i].push(data[2*i], data[2*i + 1]);
    int mid = (first + last) / 2;
    int res = (l <= mid ? id6(l, r, 2*i, first, mid, args) : lim);
    if (res == lim && mid < r) res = id6(l, r, 2*i + 1, mid + 1, last, args);
    return res;
  }

  template <class... Args>
  int search_right(int l, int r, Args... args) {
    if (r < l) return lim;
    assert(0 <= l && r < lim);
    return id5(l, r, 1, 0, length - 1, forward_as_tuple(args...));
  }
  template <class... Args>
  int id2(int l, int r, Args&... args) {
    if (r < l) return lim;
    assert(0 <= l && r < lim);
    return id5(l, r, 1, 0, length - 1, forward_as_tuple(args...));
  }
  template <class... Args>
  int id5(int l, int r, int i, int first, int last, tuple<Args&...> args) {
    if (l <= first && last <= r
        && !apply(&Node_t::contains, tuple_cat(tuple(data[i]), args))) return lim;
    if (first == last) return first;
    if constexpr (push) data[i].push(data[2*i], data[2*i + 1]);
    int mid = (first + last) / 2;
    int res = (mid < r ? id5(l, r, 2*i + 1, mid + 1, last, args) : lim);
    if (res == lim && l <= mid) res = id5(l, r, 2*i, first, mid, args);
    return res;
  }
};









struct id8 {
  vector<vector<int>> adj;
  vector<int> parent, depth, subtree, start, preorder, in, out;
  vector<int>& operator [] (int i) { return adj[i]; }
  id8(const vector<vector<int>>& adj_list, int root): adj(adj_list),
    parent(adj.size(), -1), depth(adj.size()), subtree(adj.size()), start(adj.size()),
    in(adj.size()), out(adj.size()) {
    preorder.reserve(adj.size());
    build(root, -1, 0);
  }
  id8(vector<vector<int>>&& adj_list, int root): adj(move(adj_list)),
    parent(adj.size(), -1), depth(adj.size()), subtree(adj.size()), start(adj.size()),
    in(adj.size()), out(adj.size()) {
    preorder.reserve(adj.size());
    build(root, -1, 0);
  }

private:
  int build(int u, int par, int idx) {
    in[u] = idx++;
    start[u] = (int)preorder.size();
    preorder.push_back(u);
    parent[u] = par;
    subtree[u] = 1;
    if (par != -1) {
      depth[u] = depth[par] + 1;
      vector<int>::iterator it = find(adj[u].begin(), adj[u].end(), par);
      if (it != adj[u].end()) {
        adj[u].erase(it);
      }
    }
    for (int v : adj[u]) {
      idx = build(v, u, idx);
      subtree[u] += subtree[v];
    }
    out[u] = idx++;
    return idx;
  }
};




template <class DS, typename Query_t>
struct id9 : id8 {
  DS range_ds;
  vector<int> top; 

  id9(const vector<vector<int>>& adj_list, int root):
    id8(adj_list, root), range_ds((int)adj.size()), top(adj.size()) {
    preorder.clear();
    top[root] = root;
    build(root, 0);
  }
  id9(vector<vector<int>>&& adj_list, int root):
    id8(move(adj_list), root), range_ds((int)adj.size()), top(adj.size()) {
    preorder.clear();
    top[root] = root;
    build(root, 0);
  }

  int lca(int u, int v) const {
    while (top[u] != top[v]) {
      if (depth[top[u]] < depth[top[v]]) swap(u, v);
      u = parent[top[u]];
    }
    return depth[u] < depth[v] ? u : v;
  }

  template <class... Args>
  void update_point(int u, const Args&... args) {
    range_ds.update_point(start[u], args...);
  }
  template <class... Args>
  Query_t query_point(int u, const Args&... args) {
    return range_ds.query_point(start[u], args...);
  }

  template <class... Args>
  void id10(int u, const Args&... args) {
    range_ds.update_range(start[u], start[u] + subtree[u] - 1, args...);
  }
  template <class... Args>
  Query_t id4(int u, const Args&... args) {
    return range_ds.query_range(start[u], start[u] + subtree[u] - 1, args...);
  }

  template <class... Args>
  int update_path(int u, int v, bool id1, const Args&... args) {
    while (top[u] != top[v]) {
      if (depth[top[u]] < depth[top[v]]) swap(u, v);
      range_ds.update_range(start[top[u]], start[u], args...);
      u = parent[top[u]];
    }
    if (id1 || u != v) {
      if (depth[u] < depth[v]) swap(u, v);
      range_ds.update_range(start[v] + !id1, start[u], args...);
    }
    return v; 

  }
  template <class Combine, class... Args>
  Query_t query_path(int u, int v, bool id1, Query_t res,
                     const Combine& merge, const Args&... args) {
    while (top[u] != top[v]) {
      if (depth[top[u]] < depth[top[v]]) swap(u, v);
      res = merge(res, range_ds.query_range(start[top[u]], start[u], args...));
      u = parent[top[u]];
    }
    if (id1 || u != v) {
      if (depth[u] < depth[v]) swap(u, v);
      res = merge(res, range_ds.query_range(start[v] + !id1, start[u], args...));
    }
    return res;
  }

  template <class... Args>
  int search_path(int u, int v, bool id1, Args... args) {
    bool rev = false;
    vector<pair<int, int>> down;
    while (top[u] != top[v]) {
      if (depth[top[u]] < depth[top[v]]) {
        swap(u, v);
        rev ^= 1;
      }
      int left = start[top[u]];
      int right = start[u];
      if (rev) {
        down.emplace_back(left, right);
      } else {
        int res = range_ds.id2(left, right, args...);
        if (res != range_ds.lim) return preorder[res];
      }
      u = parent[top[u]];
    }
    if (id1 || u != v) {
      if (depth[u] < depth[v]) {
        swap(u, v);
        rev ^= 1;
      }
      int left = start[v] + !id1;
      int right = start[u];
      if (rev) {
        down.emplace_back(left, right);
      } else {
        int res = range_ds.id2(left, right, args...);
        if (res != range_ds.lim) return preorder[res];
      }
    }
    for (auto it = down.rbegin(); it != down.rend(); it++) {
      int res = range_ds.id0(it->first, it->second, args...);
      if (res != range_ds.lim) return preorder[res];
    }
    return -1;
  }

private:
  int build(int u, int idx) {
    in[u] = idx++;
    start[u] = (int)preorder.size();
    preorder.push_back(u);
    if (!adj[u].empty()) {
      pair<int, size_t> big;
      for (size_t i = 0; i < adj[u].size(); i++) {
        big = max(big, pair(subtree[adj[u][i]], i));
      }
      if (big.second > 0) {
        swap(adj[u][0], adj[u][big.second]);
      }
      

      top[adj[u].front()] = top[u];
      idx = build(adj[u].front(), idx);
      

      for (size_t i = 1; i < adj[u].size(); i++) {
        int v = adj[u][i];
        top[v] = v;
        idx = build(v, idx);
      }
    }
    out[u] = idx++;
    return idx;
  }
};









using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

constexpr char nl = '\n';
constexpr ll INF = 0x3f3f3f3f;
constexpr ll INFLL = 0x3f3f3f3f3f3f3f3f;
constexpr ll MOD = 998244353;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());

struct Node {
  bool sum;
  void put(bool v) { sum = v; }
  int get() const { return sum; }
  void push(Node&, Node&) {}
  void pull(const Node& a, const Node& b) {
    sum = a.sum || b.sum;
  }
  bool contains() const { return sum; }
  static bool merge(bool a, bool b) { return a || b; }
  static bool default_value() { assert(false); }
};
using HLD = id9<segment_tree<Node, int>, int>;

int solve(int u, int ans, const vector<vector<int>>& adj, HLD& hld) {
  int rem = -1;
  bool down = hld.id4(u);
  bool up = hld.query_path(u, 1, true, 0, Node::merge);
  if (!down) {
    if(!up) {
      ans++;
    } else {
      rem = hld.search_path(u, 1, true);
      hld.update_point(rem, 0);
    }
    hld.update_point(u, 1);
  }
  int res = ans;
  for(int v : adj[u]) {
    res = max(res, solve(v, ans, adj, hld));
  }
  if (!down) {
    if (rem != -1) {
      hld.update_point(rem, 1);
    }
    hld.update_point(u, 0);
  }
  return res;
}







int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);

  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);


  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1), other(n+1);
    for(int i=2; i<=n; i++) {
      int p;
      cin >> p;
      adj[p].push_back(i);
    }
    for(int i=2; i<=n; i++) {
      int p;
      cin >> p;
      other[p].push_back(i);
    }
    HLD hld(move(other), 1);
    cout << solve(1, 0, adj, hld) << nl;
  }

  return 0;
}
