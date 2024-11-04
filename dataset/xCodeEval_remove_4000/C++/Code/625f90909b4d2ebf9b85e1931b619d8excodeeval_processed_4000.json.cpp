




using namespace std;



struct Data
{
  int value;
  Data operator+(const Data &other)
  {
    return Data{value + other.value};
  }
  Data operator*(const int other)
  {
    return Data{value * other};
  }
};
const Data nil = Data{0};



template<class T>
struct id5
{
  int size;
  T nil;
  vector<T> data;
  vector<T> st;
  vector<T> lazy;
  vector<int> pending;
  id5() { }
  id5(int size, T nil) : size(size), nil(nil)
  {
    data.resize(size, nil);
    st.resize(4*size, nil);
    lazy.resize(4*size, nil);
    pending.resize(4*size, 0);
  }
  id5(vector<T> &data, T nil) : size(data.size()), data(data), nil(nil)
  {
    st.resize(4*size);
    lazy.resize(4*size);
    pending.resize(4*size);
    build();
  }
  void build() { build(1, 0, size - 1); }
  T query(int qlo, int qhi) { return query(qlo, qhi, 1, 0, size - 1); }
  void update(int op, int ulo, int uhi, T value) { update(op, ulo, uhi, value, 1, 0, size - 1); }
  void build(int i, int lo, int hi)
  {
    if (lo == hi)
    {
      st[i] = data[lo];
      return;
    }
    int mid = (lo + hi) >> 1;
    build(2*i, lo, mid), build(2*i + 1, mid + 1, hi);
    st[i] = st[2*i] + st[2*i + 1];
  }
  void lazyUpdate(int i, int lo, int hi)
  {
    if (pending[i])
    {
      st[i] = st[i] + (lazy[i] * (hi - lo + 1));
      if (lo != hi)
      {
        lazy[2*i] = lazy[2*i] + lazy[i];
        lazy[2*i + 1] = lazy[2*i + 1] + lazy[i];
        pending[2*i] = pending[i];
        pending[2*i + 1] = pending[i];
      }
      lazy[i] = nil, pending[i] = 0;
    }
  }
  T query(int qlo, int qhi, int i, int lo, int hi)
  {
    lazyUpdate(i, lo, hi);
    if (hi < qlo || lo > qhi) return nil;
    if (lo >= qlo && hi <= qhi) return st[i];
    int mid = (lo + hi) >> 1;
    return query(qlo, qhi, 2*i, lo, mid) + query(qlo, qhi, 2*i + 1, mid + 1, hi);
  }
  void update(int op, int ulo, int uhi, T &value, int i, int lo, int hi)
  {
    lazyUpdate(i, lo, hi);
    if (hi < ulo || lo > uhi) return;
    if (lo >= ulo && hi <= uhi)
    {
      lazy[i] = lazy[i] + value, pending[i] = op;
      lazyUpdate(i, lo, hi);
      return;
    }
    int mid = (lo + hi) >> 1;
    update(op, ulo, uhi, value, 2*i, lo, mid), update(op, ulo, uhi, value, 2*i + 1, mid + 1, hi);
    st[i] = st[2*i] + st[2*i + 1];
  }
};

template<class T>
struct id3
{
  int n;
  vector<vector<int>> tree;
  vector<int> subtreeSize, level, parent;
  vector<int> heavyPath, position, head, tail;
  vector<vector<int>> heavyPaths;
  id5<T> id1;

  id3() { }
  id3(int n, T nil) : n(n)
  {
    tree.resize(n);
    init();
  }
  id3(vector<vector<int>> &t, T nil) : tree(t)
  {
    n = tree.size();
    init();
  }
  void init()
  {
    subtreeSize.resize(n), level.resize(n), parent.resize(n);
    heavyPath.resize(n), position.resize(n), head.resize(n), tail.resize(n);
    heavyPaths.clear();
    id1 = id5<T>(n, nil);
  }
  void build()
  {
    hldPrecalculations();
    buildHeavyPaths();
    

    for (int i = 0, j = 0; i < heavyPaths.size(); i++)
      for (int u: heavyPaths[i])
      {
        heavyPath[u] = i, position[u] = j++;
        head[u] = heavyPaths[heavyPath[u]][0], tail[u] = heavyPaths[heavyPath[u]].back();
      }
  }

  void hldPrecalculations(int u = 0, int prv = -1)
  {
    subtreeSize[u] = 1;
    for (int v: tree[u])
      if (v != prv)
      {
        level[v] = level[u] + 1, parent[v] = u;
        hldPrecalculations(v, u);
        subtreeSize[u] += subtreeSize[v];
      }
  }
  void buildHeavyPaths(int u = 0, int prv = -1, int currIndex = 0)
  {
    if (heavyPaths.empty()) heavyPaths.push_back(vector<int>());
    heavyPaths[currIndex].push_back(u);

    for (int v: tree[u])
      if (v != prv && 2*subtreeSize[v] >= subtreeSize[u]) 

        buildHeavyPaths(v, u, currIndex);
    for (int v: tree[u])
      if (v != prv && 2*subtreeSize[v] < subtreeSize[u]) 

      {
        heavyPaths.push_back(vector<int>());
        buildHeavyPaths(v, u, heavyPaths.size() - 1);
      }
  }
  T queryNode(int u)
  { return id1.query(position[u], position[u]); }
  void updateNode(int u, T newValue)
  { id1.update(1, position[u], position[u], newValue); }
  T queryPath(int u, int v)
  {
    T ans = nil;
    for (; heavyPath[u] != heavyPath[v]; u = parent[head[u]])
    {
      if (level[head[u]] < level[head[v]]) swap(u, v);
      ans = ans + id1.query(position[head[u]], position[u]);
    }
    if (level[u] < level[v]) swap(u, v);
    return ans + id1.query(position[v], position[u]);
  }
  void updatePath(int u, int v, T newValue)
  {
    for (; heavyPath[u] != heavyPath[v]; u = parent[head[u]])
    {
      if (level[head[u]] < level[head[v]]) swap(u, v);
      id1.update(1, position[head[u]], position[u], newValue);
    }
    if (level[u] < level[v]) swap(u, v);
    id1.update(1, position[v], position[u], newValue);
  }
  T querySubtree(int u)
  { return id1.query(position[u], position[u] + subtreeSize[u] - 1); }
  void updateSubtree(int u, T newValue)
  { id1.update(1, position[u], position[u] + subtreeSize[u] - 1, newValue); }
};
id3<Data> hld;

const int maxN = 3e5, maxLog = 20;
vector<vector<int>> id8, tree;
int level[maxN], ancestor[maxN][maxLog], logDP[maxN + 1];
int n, logn, m;
void id0(int u, int prv = -1)
{
  for (int v: tree[u])
    if (v != prv)
    {
      level[v] = level[u] + 1, ancestor[v][0] = u;
      id0(v, u);
    }
}
void id7()
{
  level[0] = ancestor[0][0] = 0; id0(0);
  for (int i = 1; i < logn; i ++)
    for (int u = 0; u < n; u ++)
      ancestor[u][i] = ancestor[ancestor[u][i - 1]][i - 1];
}
int LCA(int u, int v)
{
  if (level[v] > level[u]) swap(u, v);

  for (int diff = level[u] - level[v], i = 0; diff; diff >>= 1, i ++)
    if (diff & 1) u = ancestor[u][i];

  if (u == v) return u;

  

  for (int i = logDP[level[u] - 1]; ancestor[u][0] != ancestor[v][0]; i --)
    if (ancestor[u][i] != ancestor[v][i])
      u = ancestor[u][i], v = ancestor[v][i];

  return ancestor[u][0];
}
vector<int> id2(int u, int v)
{
  vector<int> ans;
  if (level[v] > level[u]) swap(u, v);

  int aux = u;
  for (int diff = level[u] - level[v] - 1, i = 0; diff > 0; diff >>= 1, i++)
    if (diff & 1)
      u = ancestor[u][i];

  if (ancestor[u][0] == v)
  {
    ans.push_back(u);
    return ans;
  }

  u = aux;
  for (int diff = level[u] - level[v], i = 0; diff > 0; diff >>= 1, i++)
    if (diff & 1)
      u = ancestor[u][i];

  for (int i = logDP[level[u] - 1]; ancestor[u][0] != ancestor[v][0]; i --)
    if (ancestor[u][i] != ancestor[v][i])
      u = ancestor[u][i], v = ancestor[v][i];

  ans.push_back(u), ans.push_back(v);
  if (ans[0] > ans[1])
    swap(ans[0], ans[1]);
  return ans;
}

pair<int, int> paths[maxN];
vector<int> pathsSubtrees[maxN];
map<int, int> cntSubtreeByLca[maxN];
map<pair<int, int>, int> cntSubtreesByLca[maxN];
vector<int> pathsByLca[maxN];
int id10[maxN];
map<int, int> edgeMap[maxN];

int main()
{
  logDP[1] = 0; for (int i = 2; i <= maxN; i ++) logDP[i] = logDP[i >> 1] + 1;

  while (~scanf("%d", &n))
  {
    for (int i = 0; i < n; i++)
    {
      pathsByLca[i].clear(), pathsSubtrees[i].clear();
      cntSubtreeByLca[i].clear(), cntSubtreesByLca[i].clear();
      edgeMap[i].clear();
    }
    memset(id10, 0, sizeof(id10));

    logn = ceil(log2(n));
    tree.clear();
    tree.resize(n, vector<int>());
    id8.clear();
    id8.resize(n + n - 1, vector<int>());
    for (int i = 1; i < n; i++)
    {
      int u, v; scanf("%d %d", &u, &v); u--, v--;
      int e = n + i - 1;
      edgeMap[u][v] = edgeMap[v][u] = e;
      id8[u].push_back(e), id8[e].push_back(u);
      id8[v].push_back(e), id8[e].push_back(v);

      tree[u].push_back(v), tree[v].push_back(u);
    }

    

    id7();
    hld = id3<Data>(id8, nil);
    hld.build();

    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
      scanf("%d %d", &paths[i].first, &paths[i].second);
      paths[i].first--, paths[i].second--;
    }

    

    lli id4 = 0;
    lli id9 = 0;
    lli id6 = 0;

    

    for (int i = 0; i < m; i++)
      if (paths[i].first != paths[i].second)
      {
        hld.updatePath(paths[i].first, paths[i].second, Data{1});
        int lca = LCA(paths[i].first, paths[i].second);
        pathsByLca[lca].push_back(i);

        pathsSubtrees[i] = id2(paths[i].first, paths[i].second);
        for (int subtree: pathsSubtrees[i])
        {
          if (!cntSubtreeByLca[lca].count(subtree))
            cntSubtreeByLca[lca][subtree] = 0;
          cntSubtreeByLca[lca][subtree]++;
        }

        if (pathsSubtrees[i].size() == 2)
        {
          pair<int, int> subtrees = make_pair(pathsSubtrees[i][0], pathsSubtrees[i][1]);
          if (!cntSubtreesByLca[lca].count(subtrees))
            cntSubtreesByLca[lca][subtrees] = 0;
          cntSubtreesByLca[lca][subtrees]++;

          id10[lca]++;
        }

        

        if (pathsSubtrees[i].size() == 1)
        {
          DEBUG2 printf("\t\tSame LCA, 1 subtree: (%d, %d) %d || %d %d\n", paths[i].first + 1, paths[i].second + 1, lca + 1,
            (int)pathsByLca[lca].size(), cntSubtreeByLca[lca][pathsSubtrees[i][0]]);
          id9 += (pathsByLca[lca].size() - 1)
                            - (cntSubtreeByLca[lca][pathsSubtrees[i][0]] - 1);
        }
        else
        {
          pair<int, int> subtrees = make_pair(pathsSubtrees[i][0], pathsSubtrees[i][1]);
          id9 += (pathsByLca[lca].size() - 1)
                            - (cntSubtreeByLca[lca][pathsSubtrees[i][0]] - 1)
                            - (cntSubtreeByLca[lca][pathsSubtrees[i][1]] - 1)
                            + (cntSubtreesByLca[lca][subtrees] - 1);
        }
      }

    for (int i = 0; i < m; i++)
      if (paths[i].first != paths[i].second)
      {
        int lca = LCA(paths[i].first, paths[i].second);
        

        if (pathsSubtrees[i].size() == 1)
        {
          int e1 = edgeMap[lca][pathsSubtrees[i][0]];
          int toAdd = (hld.queryNode(lca).value - 1)
                    - (hld.queryNode(e1).value - 1)
                    - ((pathsByLca[lca].size() - 1)
                     - (cntSubtreeByLca[lca][pathsSubtrees[i][0]] - 1));

          DEBUG printf("\t\tDifferent LCA, 1 subtree: (%d, %d) %d: %d || %d %d %d || %d\n", paths[i].first + 1, paths[i].second + 1, lca + 1,
            e1,
            hld.queryNode(lca).value, hld.queryNode(e1).value, (int)pathsByLca[lca].size(),
            toAdd);

          id6 += toAdd;
        }
        else
        {
          pair<int, int> subtrees = make_pair(pathsSubtrees[i][0], pathsSubtrees[i][1]);
          int e1 = edgeMap[lca][subtrees.first], e2 = edgeMap[lca][subtrees.second];
          int toAdd = (hld.queryNode(lca).value - 1)
                    - (hld.queryNode(e1).value - 1)
                    - (hld.queryNode(e2).value - 1)
                    + (cntSubtreesByLca[lca][subtrees] - 1)
                    
                    - ((pathsByLca[lca].size() - 1)
                     - (cntSubtreeByLca[lca][pathsSubtrees[i][0]] - 1)
                     - (cntSubtreeByLca[lca][pathsSubtrees[i][1]] - 1)
                     + (cntSubtreesByLca[lca][subtrees] - 1));

          DEBUG printf("\t\tDifferent LCA, 2 subtrees: (%d, %d) %d: %d %d || %d %d %d %d || %d\n", paths[i].first + 1, paths[i].second + 1, lca + 1,
            e1, e2,
            hld.queryNode(lca).value, hld.queryNode(e1).value, hld.queryNode(e2).value, (int)pathsByLca[lca].size(),
            toAdd);

          id6 += toAdd;
        }
      }

    

    for (int i = 0; i < m; i++)
      if (paths[i].first == paths[i].second)
      {
        hld.updatePath(paths[i].first, paths[i].second, Data{1});
        id4 += (hld.queryNode(paths[i].first).value - 1);
      }

    lli ans = id4 + id9 + id6;
    DEBUG printf("\t%lld %lld %lld\n", id4, id9, id6);
    printf("%lld\n", ans);
  }

  return 0;
}
 