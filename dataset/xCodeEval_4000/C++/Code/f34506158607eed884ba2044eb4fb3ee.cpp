#include <bits/stdc++.h>

using namespace std;

#define range(i, m, n) for(int i = m; i < n; i++)
#define husk(i, m, n) for(int i = m; i > n; i--)

template <typename T, class F = function<T(const T&, const T&)>>
class SparseTable {
 public:
  int n;
  vector<vector<T>> mat;
  F func;

  SparseTable(){};

  SparseTable(const vector<T>& a, const F& f) : func(f) {
    n = static_cast<int>(a.size());
    int max_log = 32 - __builtin_clz(n);
    mat.resize(max_log);
    mat[0] = a;
    for (int j = 1; j < max_log; j++) {
      mat[j].resize(n - (1 << j) + 1);
      for (int i = 0; i <= n - (1 << j); i++) {
        mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
      }
    }
  }

  T get(int from, int to) const {
    assert(0 <= from && from <= to && to <= n - 1);
    int lg = 32 - __builtin_clz(to - from + 1) - 1;
    return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
  }
};

class tree {
  public:;
  int n;
  vector<vector<int>> gr;
  vector<int> in, out, tour, dep, par, sub;
  SparseTable<int> st;

  tree(){};

  tree(int _n) {
    n = _n;
    gr.resize(n);
    in.resize(n);
    out.resize(n);
    dep.resize(n);
    par.resize(n);
    sub.resize(n, 1);
  }

  void add(int u, int v) {
    gr[u].push_back(v);
    gr[v].push_back(u);
  }

  void dfs(int v, int p) {
    in[v] = tour.size();
    tour.push_back(v);
    if(~p) dep[v] = dep[p] + 1;
    par[v] = p;
    for(int i : gr[v]) {
      if(i == p) continue;
      sub[v] += sub[i];
      dfs(i, v);
      tour.push_back(v);
    }
    out[v] = tour.size() - 1;
  }

  void prep() {
    dfs(0, -1);
    st = SparseTable<int>(tour, [&](int x, int y){return (dep[x] == dep[y] ? min(x, y) : (dep[x] > dep[y] ? y : x));});
  }

  int parent(int u, int v) {
    return st.get(min(in[u], in[v]), max(out[u], out[v]));
  }

  pair<map<int, int>, vector<int>> to_tree(vector<int> id) {
    sort(id.begin(), id.end(), [&](int x, int y){return in[x] < in[y];});
    int sz = id.size();
    range(i, 0, sz - 1) {
      id.push_back(parent(id[i], id[i + 1]));
    }
    sort(id.begin(), id.end(), [&](int x, int y){return in[x] < in[y];});
    id.resize(unique(id.begin(), id.end()) - id.begin());

    sz = id.size();
    vector<int> p(sz);
    map<int, int> to;
    range(i, 0, sz) to[id[i]] = i;

    vector<int> que;
    range(i, 0, sz) {
      while(!que.empty() && out[id[que.back()]] < in[id[i]]) que.pop_back();
      if(que.empty()) p[i] = -1;
      else p[i] = que.back();
      que.push_back(i);
    }
    return make_pair(to, p);
  }

};

class node {
  public:
  int id;
  node* l;
  node* r;
  node* p;
  bool rev;
  int sz;
  

  long long sum;
  long long dep;
  long long total_sum;
  long long total_dep;
  long long ad;

  node(int _id) {
    id = _id;
    l = r = p = NULL;
    rev = false;
    sz = 1;
    

    sum = 0;
    dep = 0;
    total_sum = 0;
    total_dep = 0;
    ad = 0;
  }

  void unsafe_reverse() {
    rev ^= 1;
    swap(l, r);
    pull();
  }

  

  void unsafe_apply(long long v) {
    total_sum += v * total_dep;
    sum += v * dep;
    ad += v;
  }

  void push() {
    if (rev) {
      if (l != NULL) {
        l->unsafe_reverse();
      }
      if (r != NULL) {
        r->unsafe_reverse();
      }
      rev = 0;
    }
    

    if (ad) {
      if (l != NULL) {
        l->unsafe_apply(ad);
      }
      if (r != NULL) {
        r->unsafe_apply(ad);
      }
      ad = 0;
    }
  }

  void pull() {
    sz = 1;
    

    total_sum = sum;
    total_dep = dep;

    if (l != NULL) {
      l->p = this;
      sz += l->sz;
      

      total_sum += l->total_sum;
      total_dep += l->total_dep;
    }
    if (r != NULL) {
      r->p = this;
      sz += r->sz;
      

      total_sum += r->total_sum;
      total_dep += r->total_dep;
    }
  }
};

namespace splay_tree {
  bool is_bst_root(node* v) {
    if (v == NULL) {
      return false;
    }
    return (v->p == NULL || (v->p->l != v && v->p->r != v));
  }

  void rotate(node* v) {
    node* u = v->p;
    assert(u != NULL);
    u->push();
    v->push();
    v->p = u->p;
    if (v->p != NULL) {
      if (v->p->l == u) {
        v->p->l = v;
      }
      if (v->p->r == u) {
        v->p->r = v;
      }
    }
    if (v == u->l) {
      u->l = v->r;
      v->r = u;
    } else {
      u->r = v->l;
      v->l = u;
    }
    u->pull();
    v->pull();
  }

  void splay(node* v) {
    if (v == NULL) {
      return;
    }
    

    

    

     

     

    

    

    

    while (!is_bst_root(v)) {
      node* u = v->p;
      if (!is_bst_root(u)) {
        if ((u->l == v) ^ (u->p->l == u)) {
          rotate(v);
        } else {
          rotate(u);
        }
      }
      rotate(v);
    }
  }

  pair<node*,int> find(node* v, const function<int(node*)> &go_to) {
    

    

    if (v == NULL) {
      return {NULL, 0};
    }
    splay(v);
    int dir;
    while (true) {
      v->push();
      dir = go_to(v);
      if (dir == 0) {
        break;
      }
      node* u = (dir == -1 ? v->l : v->r);
      if (u == NULL) {
        break;
      }
      v = u;
    }
    splay(v);
    return {v, dir};
  }

  node* get_leftmost(node* v) {
    return find(v, [&](node*) { return -1; }).first;
  }

  node* get_rightmost(node* v) {
    return find(v, [&](node*) { return 1; }).first;
  }

  node* get_kth(node* v, int k) { 

    pair<node*,int> p = find(v, [&](node* u) {
      if (u->l != NULL) {
        if (u->l->sz > k) {
          return -1;
        }
        k -= u->l->sz;
      }
      if (k == 0) {
        return 0;
      }
      k--;
      return 1;
    });
    return (p.second == 0 ? p.first : NULL);
  }

  int get_position(node* v) { 

    splay(v);
    return (v->l != NULL ? v->l->sz : 0);
  }

  node* get_bst_root(node* v) {
    splay(v);
    return v;
  }

  pair<node*,node*> split(node* v, const function<bool(node*)> &is_right) {
    if (v == NULL) {
      return {NULL, NULL};
    }
    pair<node*,int> p = find(v, [&](node* u) { return is_right(u) ? -1 : 1; });
    v = p.first;
    v->push();
    if (p.second == -1) {
      node* u = v->l;
      if (u == NULL) {
        return {NULL, v};
      }
      v->l = NULL;
      u->p = v->p;
      u = get_rightmost(u);
      v->p = u;
      v->pull();
      return {u, v};
    } else {
      node* u = v->r;
      if (u == NULL) {
        return {v, NULL};
      }
      v->r = NULL;
      v->pull();
      return {v, u};
    }
  }

  pair<node*,node*> split_leftmost_k(node* v, int k) {
    return split(v, [&](node* u) {
      int left_and_me = (u->l != NULL ? u->l->sz : 0) + 1;
      if (k >= left_and_me) {
        k -= left_and_me;
        return false;
      }
      return true;
    });
  }

  node* merge(node* v, node* u) {
    if (v == NULL) {
      return u;
    }
    if (u == NULL) {
      return v;
    }
    v = get_rightmost(v);
    assert(v->r == NULL);
    splay(u);
    v->push();
    v->r = u;
    v->pull();
    return v;
  }

  int count_left(node* v, const function<bool(node*)> &is_right) {
    if (v == NULL) {
      return 0;
    }
    pair<node*,int> p = find(v, [&](node* u) { return is_right(u) ? -1 : 1; });
    node* u = p.first;
    return (u->l != NULL ? u->l->sz : 0) + (p.second == 1);
  }

  node* add(node* r, node* v, const function<bool(node*)> &go_left) {
    pair<node*,node*> p = split(r, go_left);
    return merge(p.first, merge(v, p.second));
  }

  node* remove(node* v) { 

    splay(v);
    v->push();
    node* x = v->l;
    node* y = v->r;
    v->l = v->r = NULL;
    node* z = merge(x, y);
    if (z != NULL) {
      z->p = v->p;
    }
    v->p = NULL;
    v->push();
    v->pull(); 

    return z;
  }

  node* next(node* v) {
    splay(v);
    v->push();
    if (v->r == NULL) {
      return NULL;
    }
    v = v->r;
    while (v->l != NULL) {
      v->push();
      v = v->l;
    }
    splay(v);
    return v;
  }

  node* prev(node* v) {
    splay(v);
    v->push();
    if (v->l == NULL) {
      return NULL;
    }
    v = v->l;
    while (v->r != NULL) {
      v->push();
      v = v->r;
    }
    splay(v);
    return v;
  }

  int get_size(node* v) {
    splay(v);
    return (v != NULL ? v->sz : 0);
  }

  template<typename... T>
  void apply(node* v, T... args) {
    splay(v);
    v->unsafe_apply(args...);
  }

  void reverse(node* v) {
    splay(v);
    v->unsafe_reverse();
  }
}

using namespace splay_tree;

template<bool rooted>
class link_cut_tree {
  public:
  int n;
  vector<node*> nodes;

  link_cut_tree(){};

  link_cut_tree(int _n) : n(_n) {
    nodes.resize(n);
    for (int i = 0; i < n; i++) {
      nodes[i] = new node(i);
    }
  }

  int add_node() {
    int id = (int) nodes.size();
    nodes.push_back(new node(id));
    return id;
  }

  void expose(node* v) {
    node* r = NULL;
    node* u = v;
    while (u != NULL) {
      splay(u);
      u->push();
      u->r = r;
      u->pull();
      r = u;
      u = u->p;
    }
    splay(v);
    assert(v->p == NULL);
  }

  int get_root(int i) {
    node* v = nodes[i];
    expose(v);
    return get_leftmost(v)->id;
  }

  bool link(int i, int j) { 

    if (i == j) {
      return false;
    }
    node* v = nodes[i];
    node* u = nodes[j];
    if (rooted) {
      splay(v);
      assert(v->p == NULL && v->l == NULL); 

    } else {
      make_root(i);
    }
    expose(u);
    if (v->p != NULL) {
      return false;
    }
    v->p = u;
    return true;
  }

  bool cut(int i, int j) { 

    if (i == j) {
      return false;
    }
    node* v = nodes[i];
    node* u = nodes[j];
    expose(u);
    splay(v);
    if (v->p != u) {
      if (rooted) {
        return false;
      }
      swap(u, v);
      expose(u);
      splay(v);
      if (v->p != u) {
        return false;
      }
    }
    v->p = NULL;
    return true;
  }

  bool connected(int i, int j) {
    if (i == j) {
      return true;
    }
    node* v = nodes[i];
    node* u = nodes[j];
    expose(v);
    assert(v->p == NULL);
    expose(u);
    return v->p != NULL;
  }

  int lca(int i, int j) {
    if (i == j) {
      return i;
    }
    node* v = nodes[i];
    node* u = nodes[j];
    expose(v);
    assert(v->p == NULL);
    expose(u);
    if (v->p == NULL) {
      return -1;
    }
    splay(v);
    if (v->p == NULL) {
      return v->id;
    }
    return v->p->id;
  }

  bool is_ancestor(int i, int j) {
    if (i == j) {
      return true;
    }
    node* v = nodes[i];
    node* u = nodes[j];
    expose(u);
    assert(u->p == NULL);
    splay(v);
    return v->p == NULL && u->p != NULL;
  }

  void make_root(int i) {
    assert(!rooted);
    node* v = nodes[i];
    expose(v);
    assert(v->r == NULL);
    reverse(v);
  }

  node* get_path_from_root(int i) {
    node* v = nodes[i];
    expose(v);
    return v;
  }

  template<typename... T>
  void apply(int i, T... args) {
    node* v = nodes[i];
    splay_tree::apply(v, args...);
  }
};

int n, m, q;
long long C;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(15);
  cin >> n >> m >> q >> C;
  vector<int> f(n);
  range(i, 0, n) {
    cin >> f[i];
    f[i]--;
  }
  tree g(n);
  range(i, 1, n) {
    int u;
    cin >> u;
    u--;
    g.add(u, i);
  }
  vector<int> c(m);
  range(i, 0, m) {
    cin >> c[i];
  }

  g.prep();
  vector<vector<int>> id(m, vector<int>(1, 0));
  range(i, 0, n) id[f[i]].push_back(i);
  vector<vector<int>> que;
  range(i, 0, q) {
    int t;
    cin >> t;
    if(t == 1) {
      int x, w;
      cin >> x >> w;
      w--; x--;
      id[w].push_back(x);
      que.push_back({t, x, w});
    } else {
      int w;
      cin >> w;
      w--;
      que.push_back({t, w});
    }
  }

  vector<link_cut_tree<true>> cur(m);
  vector<map<int, int>> to(m);
  vector<long long> res(m);
  vector<long long> total(m);
  vector<vector<int>> bbug(m);

  range(i, 0, m) {
    auto foo = g.to_tree(id[i]);
    vector<int> par = foo.second;
    bbug[i] = par;
    to[i] = foo.first;
    int sz = par.size();
    cur[i] = link_cut_tree<true>(sz);
    vector<int> ps(sz);
    for(auto it : to[i]) ps[it.second] = it.first;
    vector<int> cnt(sz);

    husk(j, sz - 1, -1) {
      cnt[j] += f[ps[j]] == i;
      int mu = g.dep[ps[j]] - (par[j] == -1 ? -1 : g.dep[ps[par[j]]]);
      res[i] += 1LL * cnt[j] * cnt[j] * mu;
      total[i] += 1LL * cnt[j] * mu;
      if(~par[j]) cnt[par[j]] += cnt[j];
      cur[i].nodes[j]->dep = mu;
      cur[i].nodes[j]->total_dep = mu;
      cur[i].nodes[j]->sum = 1LL * cnt[j] * mu;
      cur[i].nodes[j]->total_sum = 1LL * cnt[j] * mu;
    }

    husk(j, sz - 1, 0) {
      cur[i].link(j, par[j]);
    }
  }

  for(auto q : que) {
    int t = q[0];
    if(t == 1) {
      int x = q[1], w = q[2];

      res[f[x]] += g.dep[x] + 1;
      total[f[x]] -= g.dep[x] + 1;
      int i = f[x];

      node *v = cur[i].get_path_from_root(to[i][x]);
      assert(g.dep[x] + 1 == v->total_dep);
      res[i] -= v->total_sum * 2;
      cur[i].apply(v->id, -1);

      f[x] = w;
      res[f[x]] += g.dep[x] + 1;
      total[f[x]] += g.dep[x] + 1;

      node *u = cur[w].get_path_from_root(to[w][x]);
      assert(g.dep[x] + 1 == u->total_dep);
      res[w] += u->total_sum * 2;
      cur[w].apply(u->id, 1);
    } else {
      int w = q[1];
      double ans = res[w] * c[w] * c[w] - 2LL * c[w] * total[w] * C + n * C * C;
      ans /= n;
      cout << ans << "\n";
    }
  }
  return 0;
}
