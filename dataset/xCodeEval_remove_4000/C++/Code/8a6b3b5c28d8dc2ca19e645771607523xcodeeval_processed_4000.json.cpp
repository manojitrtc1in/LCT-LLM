







namespace {

template<typename T> void minify(T& a, T b) { if (a > b) a = b; }
template<typename T> void enlarge(T& a, T b) { if (a < b) a = b; }

template<int id12>
struct Dsu {
  std::vector<int> dsu;
  std::vector<int> weight;

  explicit Dsu(int n) : dsu(n), weight(n) {
    std::iota(dsu.begin(), dsu.end(), 0);
  }

  int find(int x) { return dsu[x] == x ? x : dsu[x] = find(dsu[x]); }

  int get_weight(int x) {
    return weight[find(x)];
  }

  bool same(int x, int y) {
    x = find(x);
    y = find(y);
    return x == y;
  }

  bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if constexpr (id12) {
      enlarge(weight[x], weight[y]);
    } else {
      minify(weight[x], weight[y]);
    }
    dsu[y] = x;
    return true;
  }
};

const int INF = 0x3f3f3f3f;

template<typename Edge, bool id14>
struct id4 {
  int n = 0;
  std::vector<std::vector<Edge>> graph;

  std::vector<int> parent, sz, balance;
  std::vector<bool> vis;
  std::vector<int> que;

  std::vector<std::vector<int>> level_caps, level_tolls;

  std::vector<Dsu<true>> level_dsus;
  std::vector<std::map<int, std::multiset<int>>> level_sets;
  std::vector<std::vector<int>> level_regs;
  std::vector<std::vector<bool>> level_conns;

  struct Entry {
    int level = -1;
    int centroid = -1;
    int subtree = -1;
  };

  std::vector<std::vector<Entry>> entries;

  explicit id4(int n) : n(n), graph(n), parent(n), sz(n), balance(n), vis(n), entries(n) {}

  int query_toll(const Entry& entry, int start) {
    if (start != entry.centroid && (!level_dsus[entry.level].same(start, entry.subtree) || !level_conns[entry.level][entry.subtree])) {
      return 0;
    }
    if (level_sets[entry.centroid][entry.level].empty()) {
      return 0;
    }
    auto iter = level_sets[entry.centroid][entry.level].rbegin();
    if (entry.subtree != -1 && *iter == level_regs[entry.level][entry.subtree]) {
      ++iter;
      if (iter == level_sets[entry.centroid][entry.level].rend()) {
        return 0;
      }
    }
    return std::max(*iter, level_tolls[entry.level][start]);
  }

  void merge(int x, int y) {
    for (int i = (int)entries[x].size() - 1, j = (int)entries[y].size() - 1; i >= 0; --i) {
      while (j >= 0 && entries[y][j].level > entries[x][i].level) --j;
      if (j >= 0 && entries[y][j].level == entries[x][i].level && entries[y][j].centroid == entries[x][i].centroid) {
        int level = entries[y][j].level;
        int centroid = entries[y][j].centroid;
        int id13 = entries[x][i].subtree;
        int id11 = entries[y][j].subtree;
        if (id13 == -1) {
          CHECK(id11 != -1);
          level_regs[level][id11] = level_dsus[level].get_weight(id11);
          level_conns[level][id11] = true;
          if (level_regs[level][id11] != -1) {
            DUMP("insert1", level, centroid, level_regs[level][id11]);
            level_sets[centroid][level].emplace(level_regs[level][id11]);
          }
        } else if (id11 == -1) {
          CHECK(id13 != -1);
          level_regs[level][id13] = level_dsus[level].get_weight(id13);
          level_conns[level][id13] = true;
          if (level_regs[level][id13] != -1) {
            DUMP("insert2", level, centroid, level_regs[level][id13]);
            level_sets[centroid][level].emplace(level_regs[level][id13]);
          }
        } else {
          CHECK(id13 == id11);
          if (level_regs[level][id13] != -1 && level_conns[level][id13]) {
            DUMP("erase", level, centroid, level_regs[level][id13]);
            level_sets[centroid][level].erase(level_sets[centroid][level].find(level_regs[level][id13]));
          }
          level_dsus[level].merge(x, y);
          level_regs[level][id13] = level_dsus[level].get_weight(id13);
          if (level_regs[level][id13] != -1 && level_conns[level][id13]) {
            DUMP("insert3", level, centroid, level_regs[level][id13]);
            level_sets[centroid][level].emplace(level_regs[level][id13]);
          }
        }
      }
    }
  }

  int query_cap(int x, int y) const {
    for (int i = (int)entries[x].size() - 1, j = (int)entries[y].size() - 1; i >= 0; --i) {
      while (j >= 0 && entries[y][j].level > entries[x][i].level) --j;
      if (j >= 0 && entries[y][j].level == entries[x][i].level && entries[y][j].centroid == entries[x][i].centroid) {
        int level = entries[y][j].level;
        return std::min(level_caps[level][x], level_caps[level][y]);
      }
    }
    assert(false);
  }

  int query_toll(int x, int y) const {
    for (int i = (int)entries[x].size() - 1, j = (int)entries[y].size() - 1; i >= 0; --i) {
      while (j >= 0 && entries[y][j].level > entries[x][i].level) --j;
      if (j >= 0 && entries[y][j].level == entries[x][i].level && entries[y][j].centroid == entries[x][i].centroid) {
        int level = entries[y][j].level;
        return std::max(level_tolls[level][x], level_tolls[level][y]);
      }
    }
    assert(false);
  }

  int bfs(int source, int fa = -1) {
    int qf = 0;
    que.clear();
    que.emplace_back(source);
    parent[source] = fa;
    while (qf < que.size()) {
      int u = que[qf++];
      sz[u] = 1;
      balance[u] = 0;
      for (const Edge& e : graph[u]) {
        int v = e.v;
        if (!vis[v] && parent[u] != v) {
          parent[v] = u;
          que.emplace_back(v);
        }
      }
    }
    for (int i = (int)que.size() - 1; i >= 0; --i) {
      int u = que[i];
      if (i) {
        sz[parent[u]] += sz[u];
        balance[parent[u]] = std::max(balance[parent[u]], sz[u]);
      }
      balance[u] = std::max(balance[u], (int)que.size() - sz[u]);
    }
    return que.size();
  }

  void divide_core(int root, int tot, int level) {
    while (level_caps.size() <= level) {
      level_caps.emplace_back(std::vector<int>(n));
      level_tolls.emplace_back(std::vector<int>(n));
      if constexpr (id14) {
        level_dsus.emplace_back(Dsu<true>(n));
        level_sets.resize(n);
        level_regs.emplace_back(std::vector<int>(n, -1));
        level_conns.emplace_back(std::vector<bool>(n));
      }
    }
    level_caps[level][root] = INF;
    level_tolls[level][root] = 0;
    for (int i = 0; i < tot; ++i) {
      int u = que[i];
      int subtree = -1;
      if (u == root) {
        

      } else if (parent[u] == root) {
        subtree = u;
      } else {
        subtree = entries[parent[u]].back().subtree;
      }
      entries[u].emplace_back(Entry{.level = level, .centroid = root, .subtree = subtree});
      for (const Edge& e : graph[u]) if (e.v != parent[u]) {
        level_caps[level][e.v] = std::min(level_caps[level][u], e.cap);
        level_tolls[level][e.v] = std::max(level_tolls[level][u], e.toll);
      }
    }
  }

  void divide(int root, int level) {
    int tot = bfs(root);
    for (int i = tot - 1; i > 0; --i) if (balance[que[i]] < balance[root]) root = que[i];
    bfs(root);

    divide_core(root, tot, level);

    vis[root] = true;
    for (const Edge& e : graph[root]) if (!vis[e.v]) divide(e.v, level + 1);
  }
};

template<typename Edge>
struct VirtualGraph {
  const std::vector<int>& dfn;

  int n;
  std::vector<std::vector<Edge>> edges;
  std::vector<Edge> edge_set;
  std::vector<int> original_points;
  std::vector<int> point_weight;

  

  

  

  static int get_index(const std::vector<int>& dfn, const std::vector<int>& points, int u) {
    const int index = std::lower_bound(points.begin(), points.end(), u, [&](int x, int y) {
      return dfn[x] < dfn[y];
    }) - points.begin();
    CHECK(index >= 0 && index < points.size());
    return index;
  }

  

  template<typename GetLca, typename GetPointWeight, typename GetEdgeCap, typename GetEdgeToll>
  explicit VirtualGraph(const std::vector<int>& dfn,
                        std::vector<int> points,
                        GetLca&& id9,
                        GetPointWeight&& id0,
                        GetEdgeCap&& id2,
                        GetEdgeToll&& id5) : dfn(dfn) {
      std::sort(points.begin(), points.end(), [&](int x, int y) {
        return dfn[x] < dfn[y];
      });
      points.erase(std::unique(points.begin(), points.end()), points.end());
      for (int i = (int)points.size() - 1; i > 0; --i) {
        points.emplace_back(id9(points[i], points[i - 1]));
      }
      std::sort(points.begin(), points.end(), [&](int x, int y) {
        return dfn[x] < dfn[y];
      });
      points.erase(std::unique(points.begin(), points.end()), points.end());

      original_points = points;
      n = original_points.size();
      edges.resize(n);
      point_weight.resize(n);

      for (int i = 0; i < points.size(); ++i) {
        point_weight[i] = id0(points[i]);
      }

      for (int i = (int)points.size() - 1; i > 0; --i) {
        int u = original_points[i];
        int v = original_points[i - 1];
        int lca = id9(u, v);
        int cap = id2(u, lca);
        int toll = id5(u, lca);
        int x = get_index(dfn, original_points, lca);
        int y = i;
        edges[x].emplace_back(Edge{.u = x, .v = y, .cap = cap, .toll = toll});
        edges[y].emplace_back(Edge{.u = y, .v = x, .cap = cap, .toll = toll});
        edge_set.emplace_back(Edge{.u = y, .v = x, .cap = cap, .toll = toll});
      }
    }

  int get_index(int x) const {
    return get_index(dfn, original_points, x);
  }

  int size() const { return n; }
};

struct BinaryLiftLCA {
  std::vector<std::vector<int>> pjump;
  std::vector<int> depth;

  void init(int size, int* parent, int* dist) {
    int L = 1;
    while ((1 << L) < size) ++L;
    pjump.resize(L, std::vector<int>(size, -1));
    std::vector<int>(parent, parent + size).swap(pjump[0]);
    std::vector<int>(dist, dist + size).swap(depth);
    for (int i = 0; i + 1 < L; ++i)
      for (int u = 0; u < size; ++u)
        pjump[i + 1][u] = pjump[i][u] == -1 ? -1 : pjump[i][pjump[i][u]];
  }

  int id9(int a, int b) const {
    if (depth[a] < depth[b]) std::swap(a, b);
    for (int i = (int)pjump.size() - 1; i >= 0; --i)
      if ((depth[a] - depth[b]) >> i & 1)
        a = pjump[i][a];
    if (a == b) return a;
    for (int i = (int)pjump.size() - 1; i >= 0; --i)
      if (pjump[i][a] != pjump[i][b])
        a = pjump[i][a], b = pjump[i][b];
    return pjump[0][a];
  }
  int get_dist(int a, int b) const { return depth[a] + depth[b] - 2 * depth[id9(a, b)]; }
  int jump(int a, int step) const {
    if (step >= (1 << pjump.size())) return -1;
    for (int i = (int)pjump.size() - 1; i >= 0; --i)
      if (step >> i & 1)
        a = pjump[i][a];
    return a;
  }
  int walk(int a, int b, int step) const {
    int lca = id9(a, b);
    if (depth[a] - depth[lca] < step) {
      step = depth[a] + depth[b] - 2 * depth[lca] - step;
      std::swap(a, b);
    }
    return jump(a, step);
  }
} id8;

struct Edge {
  int u, v;
  int cap, toll;
};

struct Query {
  int cap;
  int start;
  int id;
};

struct Result {
  int highest_enjoyment = 0;
  int maximum_toll = 0;
};

struct Solver {
  int n, q;
  std::vector<int> id3;
  std::vector<Result> results;
  std::vector<std::vector<Edge>> graph;

  std::vector<int> dfn;
  std::vector<int> depth;
  std::vector<int> parent;
  int stmp = 0;

  void dfs(int u, int fa) {
    parent[u] = fa;
    dfn[u] = stmp++;
    for (const Edge& e : graph[u]) if (e.v != fa) {
      depth[e.v] = depth[u] + 1;
      dfs(e.v, u);
    }
  }

  void solve(int ca, std::istream& reader) {
    reader >> n >> q;
    id3.resize(n);
    for (int i = 0; i < n; ++i) {
      reader >> id3[i];
    }
    graph.resize(n);
    dfn.resize(n);
    depth.resize(n);
    parent.resize(n);
    std::vector<Edge> input_edges;
    for (int i = 0; i < n - 1; ++i) {
      int x, y, cap, toll;
      reader >> x >> y >> cap >> toll; --x; --y;
      graph[x].emplace_back(Edge{.u = x, .v = y, .cap = cap, .toll = toll});
      graph[y].emplace_back(Edge{.u = y, .v = x, .cap = cap, .toll = toll});
      input_edges.emplace_back(Edge{.u = y, .v = x, .cap = cap, .toll = toll});
    }
    dfs(0, -1);
    id8.init(n, &parent[0], &depth[0]);
    std::vector<Query> queries;
    for (int i = 0; i < q; ++i) {
      int cap, start;
      reader >> cap >> start; --start;
      queries.emplace_back(Query{.cap = cap, .start = start, .id = i});
    }
    results.resize(q);

    

    {
      std::sort(queries.begin(), queries.end(), [](const Query& lhs, const Query& rhs) {
        return lhs.cap < rhs.cap;
      });
      std::sort(input_edges.begin(), input_edges.end(), [](const Edge& lhs, const Edge& rhs) {
        return lhs.cap < rhs.cap;
      });
      Dsu<true> dsu(n);
      dsu.weight = id3;
      for (int i = q - 1, j = n - 2; i >= 0; --i) {
        while (j >= 0 && input_edges[j].cap >= queries[i].cap) {
          dsu.merge(input_edges[j].u, input_edges[j].v);
          --j;
        }
        results[queries[i].id].highest_enjoyment = dsu.weight[dsu.find(queries[i].start)];
      }
    }

    

    {
      std::map<int, std::vector<int>> id6;
      std::map<int, std::vector<Query>> id7;
      for (int i = 0; i < n; ++i) {
        id6[id3[i]].emplace_back(i);
      }
      for (const Query& query : queries) {
        id7[results[query.id].highest_enjoyment].emplace_back(query);
      }
      id4<Edge, false> id10(n);
      id10.graph = graph;
      id10.divide(0, 0);
      for (const auto& [id1, sub_queries] : id7) {
        solve_toll(id10, id1, sub_queries, id6[id1]);
      }
    }

    for (int i = 0; i < q; ++i) {
      printf("%d %d\n", results[i].highest_enjoyment, results[i].maximum_toll);
    }
  }

  void solve_toll(const id4<Edge, false>& id10, int id1, std::vector<Query> queries, std::vector<int> vertices) {
    for (const Query& query : queries) {
      vertices.emplace_back(query.start);
    }
    VirtualGraph<Edge> vgraph(
        dfn,
        vertices,
        [](int x, int y) -> int { return id8.id9(x, y); },
        [&](int x) -> int { return id1 == id3[x]; },
        [&id10](int x, int y) { return id10.query_cap(x, y); },
        [&id10](int x, int y) { return id10.query_toll(x, y); });

    DUMP(vgraph.original_points);
    DUMP(vgraph.point_weight);
    for (const Edge& e : vgraph.edge_set) {
      DUMP(e.u, e.v, e.cap, e.toll);
    }

    id4<Edge, true> vtree(vgraph.size());
    vtree.graph = vgraph.edges;
    vtree.divide(0, 0);
    for (int l = 0; l < vtree.level_dsus.size(); ++l) {
      vtree.level_dsus[l].weight = vtree.level_tolls[l];
      for (int i = 0; i < vgraph.size(); ++i) if (vgraph.point_weight[i] == 0) {
        vtree.level_dsus[l].weight[i] = -1;
      }
    }
    for (int u = 0; u < vgraph.size(); ++u) if (vgraph.point_weight[u] == 1) {
      for (const auto& entry : vtree.entries[u]) if (entry.centroid == u) {
        vtree.level_sets[entry.centroid][entry.level].emplace(0);
      }
    }
    std::sort(queries.begin(), queries.end(), [](const Query& lhs, const Query& rhs) {
      return lhs.cap < rhs.cap;
    });
    std::vector<Edge>& edge_set = vgraph.edge_set;
    std::sort(edge_set.begin(), edge_set.end(), [](const Edge& lhs, const Edge& rhs) {
      return lhs.cap < rhs.cap;
    });
    for (int i = (int)queries.size() - 1, j = (int)edge_set.size() - 1; i >= 0; --i) {
      while (j >= 0 && edge_set[j].cap >= queries[i].cap) {
        int x = edge_set[j].u;
        int y = edge_set[j].v;
        vtree.merge(x, y);
        --j;
      }
      int start = vgraph.get_index(queries[i].start);
      DUMP(queries[i].cap);
      for (const auto& entry : vtree.entries[start]) {
        DUMP(start, id1, entry.level, entry.centroid, entry.subtree, vtree.query_toll(entry, start));
        enlarge(results[queries[i].id].maximum_toll, vtree.query_toll(entry, start));
      }
    }
  }
};

}  


int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::istream& reader = std::cin;

  int cas = 1;
  

  for (int ca = 1; ca <= cas; ++ca) {
    auto solver = std::make_unique<Solver>();
    solver->solve(ca, reader);
  }
}

