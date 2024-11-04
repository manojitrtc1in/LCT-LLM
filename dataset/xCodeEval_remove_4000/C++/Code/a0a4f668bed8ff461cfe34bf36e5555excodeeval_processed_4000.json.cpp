





















using namespace std;


  
  

  
  

 







typedef long long i64;
typedef unsigned long long u64;
const double EPS = 1e-12;
const int INF = 1e9 + 10;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> PI;

template <typename T>
using MinPQ = priority_queue<T, vector<T>, greater<T>>;

struct id2 {
  int n;
  VI f;

  id2(int n) { Reset(n); }

  void Reset(int n) {
    this->n = n;
    f.resize(n);
    iota(f.begin(), f.end(), 0);
  }

  int Find(int u) {
    if (f[u] == u) return u;
    return f[u] = Find(f[u]);
  }

  

  bool Merge(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u != v) {
      f[u] = v;
      return 1;
    }
    return 0;
  }
};



template <typename T>
class id0 {
 public:
  int max_node;

  id0() {}
  inline virtual T default_value() const = 0;
  virtual T CombineValue(const T& lv, const T& rv) = 0;

  void Init(const vector<T> &a) {
    Init(SIZE(a) - 1);
    if(max_node >= 0) Build(0, max_node, 0, a);
  }

  void Init(int max_node) {
    assert(max_node >= -1);
    this->max_node = max_node;
    if(max_node < 0) {
      value.clear();
    } else {
      int v = max_node;
      int c = 1;
      while (v) {
        ++c;
        v >>= 1;
      }
      value.assign((1 << c) - 1, default_value());
    }
    InitCustom();
  }

  void Set(int i, T v) {
    assert(i >= 0 && i <= max_node);
    Set(i, v, 0, max_node, 0);
  }

  T Get(int i) {
    assert(i >= 0 && i <= max_node);
    return Get(i, 0, max_node, 0);
  }

  T Query(int l, int r) {
    return Query(l, r, 0, max_node, 0);
  }

  T QueryAll() {
    return Query(0, max_node);
  }

 protected:
  vector<T> value;

  

  virtual void InitCustom() {}

  virtual void PropgateCustom(int p, int p1, int p2) {
  }

  

  void Propgate(int p, int &p1, int &p2) {
    p1 = (p << 1) | 1;
    p2 = p1 + 1;
    PropgateCustom(p, p1, p2);
  }

  

  void CombineChildren(int p, int p1, int p2) {
    value[p] = CombineValue(value[p1], value[p2]);
  }

 private:
  void Build(int l, int r, int p, const vector<T> &a) {
    if (l == r) {
      value[p]=a[l];
      return;
    }
    int p1 = (p << 1) | 1, p2 = p1 + 1;
    int m = (l + r) >> 1;
    Build(l, m, p1, a);
    Build(m+1, r, p2, a);
    CombineChildren(p, p1, p2);
  }

  void Set(int i, T v, int l, int r, int p) {
    if (l == r) {
      value[p] = v;
      return;
    }
    int p1, p2;
    Propgate(p, p1, p2);
    int m = (l + r) >> 1;
    if (i<=m) Set(i, v, l, m, p1);
    else Set(i, v, m + 1, r, p2);
    CombineChildren(p, p1, p2);
  }

  T Get(int i, int l, int r, int p) {
    if (l == r) return value[p];
    int p1, p2;
    Propgate(p, p1, p2);
    int m = (l + r) >> 1;
    T res;
    if (i<=m) res=Get(i, l, m, p1);
    else res=Get(i, m + 1, r, p2);
    CombineChildren(p, p1, p2);
    return res;
  }

  T Query(int ql, int qr, int l, int r, int p) {
    if (ql > qr) return default_value();
    if (ql <= l && qr >= r) {
      return value[p];
    }
    int p1, p2;
    Propgate(p, p1, p2);
    int m = (l + r) >> 1;
    T res = CombineValue(Query(ql, min(qr, m), l, m, p1),
                         Query(max(ql, m + 1), qr, m + 1, r, p2));
    CombineChildren(p, p1, p2);
    return res;
  }
};



template <typename T>
class MinSegTree : public id0<T> {
 public:
  inline virtual T default_value() const {
    return numeric_limits<T>::max();
  }

  virtual T CombineValue(const T& lv, const T& rv) {
    return min(lv, rv);
  }
};



template <typename T>
class MinSegTreeSetRange: public MinSegTree<T> {
 public:
  void SetRange(int ql, int qr, T v) {
    SetRange(ql, qr, v, 0, this->max_node, 0);
  }

 protected:
  vector<char> lazy_set;

  virtual void InitCustom() {
    lazy_set.assign(SIZE(this->value), 0);
  }

  virtual void PropgateCustom(int p, int p1, int p2) {
    if(lazy_set[p]) {
      this->value[p1]=this->value[p];
      this->value[p2]=this->value[p];
      lazy_set[p1]=1;
      lazy_set[p2]=1;
      lazy_set[p]=0;
    }
  }

 private:
  void SetRange(int ql, int qr, T v, int l, int r, int p) {
    if (ql > qr) return;
    if (ql <= l && qr >= r) {
      this->value[p] = v;
      lazy_set[p] = 1;
      return;
    }
    int p1, p2;
    this->Propgate(p, p1, p2);
    if (ql > r || qr < l) return;
    int m = (l + r) >> 1;
    SetRange(ql, min(qr, m), v, l, m, p1);
    SetRange(max(ql, m + 1), qr, v, m + 1, r, p2);
    this->CombineChildren(p, p1, p2);
  }
};







class id1 {
 public:
  using E = int;
  struct Node {
    int par;  

    int par_edge;  

    int dep=-1;  

    int size;  

    int dfn;  

    int hson;  

    int head;  

    int hpath;
  };

  struct HPath {
    int head_dfn, tail_dfn;
  };

  int n;
  vector<vector<PI>> adj;
  vector<E> edges;
  vector<Node> nodes;
  VI dfsq;
  vector<HPath> hpaths;

  id1(int n=0) {
    Reset(n);
  }

  void Reset(int n) {
    this->n=n;
    edges.clear();
    adj.assign(n, vector<PI>());
  }

  void AddEdge(int u,int v,E e) {
    dpf("Edge: %d %d %d\n", u,v, e);
    int ei=SIZE(edges);
    edges.pb(e);
    adj[u].eb(v, ei);
    adj[v].eb(u, ei);
  }

  void Build() {
    nodes.assign(n, Node());
    dfsq.clear();
    hpaths.clear();
    for(int i=0;i<n;++i) if(nodes[i].dep<0) {
      nodes[i].dep = 0;
      nodes[i].par_edge = -1;
      Dfs(i,-1);
      Decomp(i, i);
    }
    BuildCustom();

    if(dbg) {
      for(int i=0;i<n;++i) {
        int u=dfsq[i];
        dpf("Node %d: %d\n",u, nodes[u].hpath);
      }
      for(int i=0;i<SIZE(hpaths);++i) {
        dpf("HPath %d: %d %d\n",i, hpaths[i].head_dfn, hpaths[i].tail_dfn);
      }
    }
  }

  int QueryKthAncestor(int u, int k) {
    int cu=0;
    while(u>=0) {
      int hu = nodes[u].head;
      int cu0=cu;
      cu+=nodes[u].dfn - nodes[hu].dfn;
      if(cu>=k) return dfsq[nodes[u].dfn-(k-cu0)];
      u = nodes[hu].par;
      cu++;
      if (cu >= k) return u;
    }
    return -1;
  }

  int QueryKthNodeOnPath(int u, int v, int k) {
    int u0=u,v0=v;
    int cu=0,cv=0;  

    while(1) {
      int hu=nodes[u].head, hv=nodes[v].head;
      if(hu==hv) break;
      if(nodes[hu].dep > nodes[hv].dep) {
        int cu0=cu;
        cu+=nodes[u].dfn - nodes[hu].dfn;
        if(cu>=k) return dfsq[nodes[u].dfn-(k-cu0)];
        u=nodes[hu].par;
        cu++;
        if(cu>=k) return u;
      } else {
        cv+=nodes[v].dfn - nodes[hv].dfn;
        v=nodes[hv].par;
        cv++;
      }
    }
    int lca;
    if (nodes[u].dep > nodes[v].dep) {
      int cu0=cu;
      cu+=nodes[u].dfn - nodes[v].dfn;
      if(cu>=k) return dfsq[nodes[u].dfn-(k-cu0)];
      lca=v;
    } else {
      cv+=nodes[v].dfn - nodes[u].dfn;
      lca=u;
    }

    int v_up=cv-(k-cu);
    assert(v_up>=0);
    return QueryKthAncestor(v0, v_up);
  }

 protected:
  virtual void BuildCustom() {}

 private:
  void Dfs(int u,int pu) {
    Node &node = nodes[u];
    node.par = pu;
    node.size = 1;
    node.hson = -1;
    REP(e, adj[u]) {
      int v=e.first;
      if(v==pu) continue;
      nodes[v].par_edge = e.second;
      nodes[v].dep = nodes[u].dep+1;
      Dfs(v,u);
      node.size += nodes[v].size;
      if(node.hson < 0 || nodes[v].size > nodes[node.hson].size) node.hson = v;
    }
  }

  void Decomp(int u, int hu) {
    Node &node = nodes[u];
    node.head = hu;
    node.dfn = SIZE(dfsq);
    dfsq.pb(u);
    if(u==hu) {
      node.hpath=SIZE(hpaths);
      hpaths.eb();
      hpaths.back().head_dfn = node.dfn;
    } else {
      node.hpath = nodes[hu].hpath;
    }
    hpaths[node.hpath].tail_dfn = node.dfn;
    if(node.hson<0) return;
    Decomp(node.hson, hu);
    REP(e, adj[u]) {
      int v=e.first;
      if(v==node.hson || v==node.par) continue;
      Decomp(v, v);
    }
  }
};





class id4 : public id1 {
 public:
  vector<E> c_sum;
  vector<MinSegTreeSetRange<E>> edge_min_st;

  id4(int n = 0) : id1(n) {}

  void Query(int u, int v, int& lca, int& edge_sum, int& edge_min) {
    edge_sum = 0;
    edge_min = 0;
    while(1) {
      int hu=nodes[u].head, hv=nodes[v].head;
      if(hu==hv) break;
      if(nodes[hu].dep < nodes[hv].dep) {
        swap(u,v);
        swap(hu, hv);
      }

      edge_sum += c_sum[nodes[u].dfn+1] - c_sum[nodes[hu].dfn]; 
      edge_min = min(edge_min,
        edge_min_st[nodes[u].hpath].Query(0, nodes[u].dfn - nodes[hu].dfn));

      u=nodes[hu].par;
    }
    if (nodes[u].dep < nodes[v].dep) swap(u,v);

    lca = v;
    edge_sum += c_sum[nodes[u].dfn+1] - c_sum[nodes[v].dfn+1]; 
    {
      int id3 = hpaths[nodes[u].hpath].head_dfn;
      edge_min = min(edge_min,
        edge_min_st[nodes[u].hpath].Query(
          nodes[v].dfn - id3 + 1,
          nodes[u].dfn - id3));
    }
  }

  void Update(int u, int ru) {
    dpf("Update %d %d\n",u,ru);
    int hru=nodes[ru].head;
    while(1) {
      int hu=nodes[u].head;
      if(hu==hru) break;
      dpf("SetRange %d %d\n", nodes[u].hpath, nodes[u].dfn - nodes[hu].dfn);
      edge_min_st[nodes[u].hpath].SetRange(0, nodes[u].dfn - nodes[hu].dfn, -1);
      u=nodes[hu].par;
    }

    {
      int id3 = hpaths[nodes[u].hpath].head_dfn;
      edge_min_st[nodes[u].hpath].SetRange(
        nodes[ru].dfn+1-id3, nodes[u].dfn - id3, -1);
    }
  }

 protected:
  virtual void BuildCustom() {
    c_sum.resize(n + 1);
    c_sum[0] = 0;
    for (int i = 0; i < n; ++i) {
      int ei = nodes[dfsq[i]].par_edge;
      int c = (ei < 0) ? 0 : edges[ei];
      c_sum[i + 1] = c_sum[i] + c;
    }

    edge_min_st.resize(SIZE(hpaths));
    for (int i = 0; i < SIZE(hpaths); ++i) {
      edge_min_st[i].Init(hpaths[i].tail_dfn - hpaths[i].head_dfn);
    }
  }
};
void Solve() {
  int n,m;
  scanf("%d%d",&n,&m);

  vector<PI> qu(m);
  VI qc(m);
  for(int i=0;i<m;++i) {
    int u,v,c;
    scanf("%d%d%d",&u,&v,&c);
    u--;v--;
    qu[i]={u,v};
    qc[i]=c;
  }

  id2 ds(n);
  id4 td(n);
  VI ans(m);
  for(int i=0;i<m;++i) {
    ans[i]=-1;
    if(ds.Merge(qu[i].fi,qu[i].se)) {
      td.AddEdge(qu[i].fi, qu[i].se, qc[i]);
      ans[i]=1;
    }
  }
  td.Build();

  for(int i=0;i<m;++i) {
    if(ans[i]!=-1) continue;
    int u=qu[i].fi,v=qu[i].se;
    dpf("Check %d: %d %d\n", i, u,v);

    int lca;
    int edge_sum;
    int in_cycle;
    td.Query(u, v, lca, edge_sum, in_cycle);
    dpf("Result: %d %d %d\n", lca, edge_sum, in_cycle);

    if(in_cycle < 0 || (edge_sum+qc[i])%2==0)  {
      ans[i]=0;
      continue;
    }

    td.Update(u, lca);
    td.Update(v, lca);
    ans[i]=1;
  }

  REP(x, ans) {
    if(x) printf("YES\n"); else printf("NO\n");
  }
}

int main() {
  int t=1;
  

  for (int i = 1; i <= t; ++i) {
    Solve();
  }

  return 0;
}
