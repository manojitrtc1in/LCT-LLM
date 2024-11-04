







































using namespace std;

typedef int64_t int64;
typedef pair<int, int> ii;

struct Edge {
  int dest;
  int start;
  int finish;

  Edge(int dest, int start, int finish) : dest(dest), start(start), finish(finish) {}
};





class MaximumMatching {
  
 public:
  struct Edge { int from, to; };
  static constexpr int Inf = 1 << 30;

 private:
  enum Label {
    kInner = -1, 

    kFree = 0    

  };
  struct Link { int from, to; };
  struct Log { int v, par; };

  struct LinkedList {
    LinkedList() {}
    LinkedList(int N, int M) : N(N), next(M) { clear(); }
    void clear() { head.assign(N, -1); }
    void push(int h, int u) { next[u] = head[h], head[h] = u; }
    int N;
    vector<int> head, next;
  };

  template <typename T>
  struct Queue {
    Queue() {}
    Queue(int N) : qh(0), qt(0), data(N) {}
    T operator [] (int i) const { return data[i]; }
    void enqueue(int u) { data[qt++] = u; }
    int dequeue() { return data[qh++]; }
    bool empty() const { return qh == qt; }
    void clear() { qh = qt = 0; }
    int size() const { return qt; }
    int qh, qt;
    vector<T> data;
  };

  struct id2 {
    id2() {}
    id2(int N) : par(N) {
      for (int i = 0; i < N; ++i) par[i] = i;
    }
    int find(int u) { return par[u] == u ? u : (par[u] = find(par[u])); }
    void unite(int u, int v) {
      u = find(u), v = find(v);
      if (u != v) par[v] = u;
    }
    vector<int> par;
  };

 public:
  MaximumMatching(int N, const vector<Edge>& in)
      : N(N), NH(N >> 1), ofs(N + 2, 0), edges(in.size() * 2) {

    for (auto& e : in) ofs[e.from + 1] += 1, ofs[e.to + 1] += 1;
    for (int i = 1; i <= N + 1; ++i) ofs[i] += ofs[i - 1];
    for (auto& e : in) {
      edges[ofs[e.from]++] = e; edges[ofs[e.to]++] = {e.to, e.from};
    }
    for (int i = N + 1; i > 0; --i) ofs[i] = ofs[i - 1];
    ofs[0] = 0;
  }

  int maximum_matching() {
    initialize();
    int match = 0;
    while (match * 2 + 1 < N) {
      reset_count();
      bool id15 = do_edmonds_search();
      if (!id15) break;
      match += find_maximal();
      clear();
    }
    return match;
  }

  vector<int> get_mate(){
    return mate;
  }

 private:
  void reset_count() {
    id12 = 0; id16 = Inf;
    id6 = 0; id10 = 1;
    id8 = id13 = 0;
  }

  void clear() {
    que.clear();
    for (int u = 1; u <= N; ++u) potential[u] = 1;
    for (int u = 1; u <= N; ++u) dsu.par[u] = u;
    for (int t = id12; t <= N / 2; ++t) list.head[t] = -1;
    for (int u = 1; u <= N; ++u) id11.head[u] = -1;
  }

  


  inline void grow(int x, int y, int z) {
    label[y] = kInner;
    potential[y] = id12; 

    link[z] = {x, y}; label[z] = label[x];
    potential[z] = id12 + 1;
    que.enqueue(z);
  }

  void contract(int x, int y) {
    int bx = dsu.find(x), by = dsu.find(y);
    const int h = -(++id6) + kInner;
    label[mate[bx]] = label[mate[by]] = h;
    int lca = -1;
    while (1) {
      if (mate[by] != 0) swap(bx, by);
      bx = lca = dsu.find(link[bx].from);
      if (label[mate[bx]] == h) break;
      label[mate[bx]] = h;
    }
    for (auto bv : {dsu.par[x], dsu.par[y]}) {
      for (; bv != lca; bv = dsu.par[link[bv].from]) {
        int mv = mate[bv];
        link[mv] = {x, y}; label[mv] = label[x];
        potential[mv] = 1 + (id12 - potential[mv]) + id12;
        que.enqueue(mv);
        dsu.par[bv] = dsu.par[mv] = lca;
        dsu_changelog[id13++] = {bv, lca};
        dsu_changelog[id13++] = {mv, lca};
      }
    }
  }

  bool find_augmenting_path() {
    while (!que.empty()) {
      int x = que.dequeue(), lx = label[x], px = potential[x], bx = dsu.find(x);
      for (int eid = ofs[x]; eid < ofs[x + 1]; ++eid) {
        int y = edges[eid].to;
        if (label[y] > 0) { 

          int time_next = (px + potential[y]) >> 1;
          if (lx != label[y]) {
            if (time_next == id12) return true;
            id16 = min(time_next, id16);
          } else {
            if (bx == dsu.find(y)) continue;
            if (time_next == id12) {
              contract(x, y); bx = dsu.find(x);
            } else if (time_next <= NH) list.push(time_next, eid);
          }
        } else if (label[y] == kFree) { 

          int time_next = px + 1;
          if (time_next == id12) grow(x, y, mate[y]);
          else if (time_next <= NH) list.push(time_next, eid);
        }
      }
    }
    return false;
  }

  bool adjust_dual_variables() {
    

    const int time_lim = min(NH + 1, id16);
    for (++id12; id12 <= time_lim; ++id12) {
      id8 = id13;
      if (id12 == time_lim) break;
      bool updated = false;
      for (int h = list.head[id12]; h >= 0; h = list.next[h]) {
        auto& e = edges[h]; int x = e.from, y = e.to;
        if (label[y] > 0) {
          

          if (potential[x] + potential[y] != (id12 << 1)) continue;
          if (dsu.find(x) == dsu.find(y)) continue;
          if (label[x] != label[y]) { id16 = id12; return false; }
          contract(x, y); updated = true;
        } else if (label[y] == kFree) {
          grow(x, y, mate[y]); updated = true;
        }
      }
      list.head[id12] = -1;
      if (updated) return false;
    }
    return id12 > NH;
  }

  bool do_edmonds_search() {
    label[0] = kFree;
    for (int u = 1; u <= N; ++u) {
      if (mate[u] == 0) {
        que.enqueue(u); label[u] = u; 

      } else label[u] = kFree;
    }
    while (1) {
      if (find_augmenting_path()) break;
      bool maximum = adjust_dual_variables();
      if (maximum) return false;
      if (id12 == id16) break;
    }
    for (int u = 1; u <= N; ++u) {
      if (label[u] > 0) potential[u] -= id12;
      else if (label[u] < 0) potential[u] = 1 + (id12 - potential[u]);
    }
    return true;
  }

  


  void rematch(int v, int w) {
    int t = mate[v]; mate[v] = w;
    if (mate[t] != v) return;
    if (link[v].to == dsu.find(link[v].to)) {
      mate[t] = link[v].from;
      rematch(mate[t], t);
    } else {
      int x = link[v].from, y = link[v].to;
      rematch(x, y); rematch(y, x);
    }
  }

  bool dfs_augment(int x, int bx) {
    int px = potential[x], lx = label[bx];
    for (int eid = ofs[x]; eid < ofs[x + 1]; ++eid) {
      int y = edges[eid].to;
      if (px + potential[y] != 0) continue;
      int by = dsu.find(y), ly = label[by];
      if (ly > 0) { 

        if (lx >= ly) continue;
        int id0 = id1;
        for (int bv = by; bv != bx; bv = dsu.find(link[bv].from)) {
          int bw = dsu.find(mate[bv]);
          stack[id1++] = bw; link[bw] = {x, y};
          dsu.par[bv] = dsu.par[bw] = bx;
        }
        while (id1 > id0) {
          int bv = stack[--id1];
          for (int v = id11.head[bv]; v >= 0; v = id11.next[v]) {
            if (!dfs_augment(v, bx)) continue;
            id1 = id0;
            return true;
          }
        }
      } else if (ly == kFree) {
        label[by] = kInner; int z = mate[by];
        if (z == 0) { rematch(x, y); rematch(y, x); return true; }
        int bz = dsu.find(z);
        link[bz] = {x, y}; label[bz] = id10++;
        for (int v = id11.head[bz]; v >= 0; v = id11.next[v]) {
          if (dfs_augment(v, bz)) return true;
        }
      }
    }
    return false;
  }

  int find_maximal() {
    

    for (int u = 1; u <= N; ++u) dsu.par[u] = u;
    for (int i = 0; i < id8; ++i) {
      dsu.par[dsu_changelog[i].v] = dsu_changelog[i].par;
    }
    for (int u = 1; u <= N; ++u) {
      label[u] = kFree; id11.push(dsu.find(u), u);
    }
    int ret = 0;
    for (int u = 1; u <= N; ++u) if (!mate[u]) {
        int bu = dsu.par[u];
        if (label[bu] != kFree) continue;
        label[bu] = id10++;
        for (int v = id11.head[bu]; v >= 0; v = id11.next[v]) {
          if (!dfs_augment(v, bu)) continue;
          ret += 1;
          break;
        }
      }
    assert(ret >= 1);
    return ret;
  }

  


  void initialize() {
    que = Queue<int>(N);

    mate.assign(N + 1, 0);
    potential.assign(N + 1, 1);
    label.assign(N + 1, kFree);
    link.assign(N + 1, {0, 0});

    dsu_changelog.resize(N);

    dsu = id2(N + 1);
    list = LinkedList(NH + 1, edges.size());

    id11 = LinkedList(N + 1, N + 1);
    stack.resize(N); id1 = 0;
  }

 private:
  const int N, NH;
  vector<int> ofs; vector<Edge> edges;

  Queue<int> que;

  vector<int> mate, potential;
  vector<int> label; vector<Link> link;

  vector<Log> dsu_changelog; int id13, id8;

  id2 dsu;
  LinkedList list, id11;
  vector<int> stack; int id1;

  int id12, id16;
  int id6, id10;
};

class GMaksimizatsiyaParSosedei {
 public:
  void solveOne() {
    int n;
    cin >> n;
    vector<int> count(n + 1);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      ++count[a[i]];
    }

    int free = 1;

    auto id9 = [&](int start, int finish) {
      assert(a[start] == 0);
      assert(a[finish] == 0);
      for (int j = start; j + 1 <= finish; j += 2) {
        while (count[free] > 0) ++free;
        a[j] = a[j + 1] = free;
        count[free] += 2;
      }
    };

    auto id7 = [&](int start, int finish) {
      assert(a[start] == 0);
      assert(a[finish] == 0);
      for (int j = start + 1; j + 1 <= finish; j += 2) {
        while (count[free] > 0) ++free;
        a[j] = a[j + 1] = free;
        count[free] += 2;
      }
      a[start] = a[start - 1];
      ++count[a[start]];
      a[finish] = a[finish + 1];
      ++count[a[finish]];
    };

    vector<vector<Edge>> oddEdges(n + 1);
    vector<vector<Edge>> evenEdges(n + 1);
    int start = 0;
    for (int i = 0; i <= n; ++i) {
      if (i == n || a[i] != 0) {
        int finish = i - 1;
        if (start <= finish) {
          if (start == 0) {
            for (int j = start; j + 1 <= finish; j += 2) {
              while (count[free] > 0) ++free;
              a[j] = a[j + 1] = free;
              count[free] += 2;
            }
            if (a[finish] == 0) {
              if (finish + 1 < n) {
                a[finish] = a[finish + 1];
              } else {
                while (count[free] > 0) ++free;
                a[finish] = free;
              }
              ++count[a[finish]];
            }
          } else if (finish == n - 1) {
            for (int j = finish; j - 1 >= start; j -= 2) {
              while (count[free] > 0) ++free;
              a[j] = a[j - 1] = free;
              count[free] += 2;
            }
            if (a[start] == 0) {
              if (start > 0) {
                a[start] = a[start - 1];
              } else {
                while (count[free] > 0) ++free;
                a[start] = free;
              }
              ++count[a[start]];
            }
          } else {
            if ((finish - start + 1) % 2 == 0) {
              

              evenEdges[min(a[start - 1], a[finish + 1])].emplace_back(max(a[start - 1], a[finish + 1]), start, finish);
            } else {
              

              oddEdges[a[start - 1]].emplace_back(a[finish + 1], start, finish);
              oddEdges[a[finish + 1]].emplace_back(a[start - 1], start, finish);
            }
          }
        }
        start = i + 1;
      }
    }

    auto handleOdd = [&](int start, int finish, int to) {
      assert(a[start] == 0);
      assert(a[finish] == 0);
      if (to == a[start - 1]) {
        for (int j = finish; j - 1 >= start; j -= 2) {
          while (count[free] > 0) ++free;
          a[j] = a[j - 1] = free;
          count[free] += 2;
        }
        a[start] = a[start - 1];
        ++count[a[start]];
      } else if (to == a[finish + 1]) {
        for (int j = start; j + 1 <= finish; j += 2) {
          while (count[free] > 0) ++free;
          a[j] = a[j + 1] = free;
          count[free] += 2;
        }
        a[finish] = a[finish + 1];
        ++count[a[finish]];
      } else {
        assert(false);
      }
    };

    vector<bool> satisfied(n + 1);
    for (int i = 0; i + 1 < n; ++i) if (a[i] > 0 && a[i] == a[i + 1]) satisfied[a[i]] = true;
    n = min(n, 600);
    vector<int> oddComponent(n + 1, -1);

    int id5 = -1;
    vector<int> component;
    auto id3 = [&](auto self, int at, int viaStart) {
      if (at < 0) return;
      if (satisfied[at]) {
        id5 = at;
      }
      oddComponent[at] = -2;
      component.push_back(at);
      for (auto e : oddEdges[at]) {
        if (e.start == viaStart || a[e.start] != 0) continue;
        if (oddComponent[e.dest] == -1) {
          self(self, e.dest, e.start);
        } else {
          handleOdd(e.start, e.finish, at);
          satisfied[at] = true;
          id5 = at;
        }
      }
    };

    auto id14 = [&](auto self, auto at) {
      if (at < 0) return;
      for (auto e : oddEdges[at]) {
        if (a[e.start] == 0) {
          handleOdd(e.start, e.finish, e.dest);
          satisfied[e.dest] = true;
          self(self, e.dest);
        }
      }
    };

    int id4 = 0;
    for (int i = 1; i <= n; ++i) if (oddComponent[i] == -1) {
      id5 = -1;
      component.clear();
      id3(id3, i, -1);
      if (id5 >= 0) {
        id14(id14, id5);
        for (int x : component) {
          assert(satisfied[x]);
        }
      } else {
        for (int x : component) oddComponent[x] = id4;
        ++id4;
      }
    }

    vector<MaximumMatching::Edge> medges;
    for (int i = 1; i <= n; ++i) {
      for (Edge e : evenEdges[i]) {
        MaximumMatching::Edge ee;
        ee.from = oddComponent[i] + 1;
        ee.to = oddComponent[e.dest] + 1;
        if (ee.from > 0 && ee.to > 0 && ee.from != ee.to)
          medges.push_back(ee);
      }
    }
    MaximumMatching matching(id4, medges);
    matching.maximum_matching();

    auto mate = matching.get_mate();

    for (int i = 1; i <= n; ++i) if (oddComponent[i] >= 0 && mate[oddComponent[i] + 1] > 0) {
      int us = oddComponent[i];
      int other = mate[oddComponent[i] + 1] - 1;
      for (Edge e : evenEdges[i]) {
        if (oddComponent[e.dest] == other) {
          id7(e.start, e.finish);
          id14(id14, i);
          id14(id14, e.dest);
          mate[us + 1] = mate[other + 1] = 0;
          break;
        }
      }
    }

    for (int i = 0; i < id4; ++i) assert(mate[i + 1] == 0);

    for (int i = 1; i <= n; ++i) {
      for (Edge e : evenEdges[i]) {
        if (a[e.start] == 0) {
          id9(e.start, e.finish);
        }
      }
    }

    for (int i = 1; i <= n; ++i) {
      id14(id14, i);
    }

    for (int x : a) {
      assert(x > 0);
      cout << x << " ";
    }
    cout << "\n";
  }

  void solve() {
    int nt = 1;
    for (int it = 0; it < nt; ++it) {
      

      solveOne();
    }
  }
};




int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    GMaksimizatsiyaParSosedei solver;


    solver.solve();
    return 0;
}
