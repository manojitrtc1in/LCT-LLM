


#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

#ifdef GOLIKOV
    #define debug(x) cerr << (#x) << ":\t" << (x) << endl
#else
    #define debug(x) 238;
#endif

template <class A, class B>
bool smin(A &x, B &&y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}

template <class A, class B>
bool smax(A &x, B &&y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}



struct MaximumMatching {
  
  struct Edge { int from, to; };
  static constexpr int Inf = 1 << 30;

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

  struct DisjointSetUnion {
    DisjointSetUnion() {}
    DisjointSetUnion(int N) : par(N) {
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
  MaximumMatching(int N, vector<int> ofs_, vector<Edge> edges_)
          : N(N), NH(N >> 1), ofs(move(ofs_)), edges(move(edges_)) {}

  int maximum_matching() {
    initialize();
    int match = 0;
    while (match * 2 + 1 < N) {
      reset_count();
      bool has_augmenting_path = do_edmonds_search();
      if (!has_augmenting_path) break;
      match += find_maximal();
      clear();
    }
    return match;
  }

  void reset_count() {
    time_current_ = 0; time_augment_ = Inf;
    contract_count_ = 0; outer_id_ = 1;
    dsu_changelog_size_ = dsu_changelog_last_ = 0;
  }

  void clear() {
    que.clear();
    for (int u = 1; u <= N; ++u) potential[u] = 1;
    for (int u = 1; u <= N; ++u) dsu.par[u] = u;
    for (int t = time_current_; t <= N / 2; ++t) list.head[t] = -1;
    for (int u = 1; u <= N; ++u) blossom.head[u] = -1;
  }

  


  inline void grow(int x, int y, int z) {
    label[y] = kInner;
    potential[y] = time_current_; 

    link[z] = {x, y}; label[z] = label[x];
    potential[z] = time_current_ + 1;
    que.enqueue(z);
  }

  void contract(int x, int y) {
    int bx = dsu.find(x), by = dsu.find(y);
    const int h = -(++contract_count_) + kInner;
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
        potential[mv] = 1 + (time_current_ - potential[mv]) + time_current_;
        que.enqueue(mv);
        dsu.par[bv] = dsu.par[mv] = lca;
        dsu_changelog[dsu_changelog_last_++] = {bv, lca};
        dsu_changelog[dsu_changelog_last_++] = {mv, lca};
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
            if (time_next == time_current_) return true;
            time_augment_ = min(time_next, time_augment_);
          } else {
            if (bx == dsu.find(y)) continue;
            if (time_next == time_current_) {
              contract(x, y); bx = dsu.find(x);
            } else if (time_next <= NH) list.push(time_next, eid);
          }
        } else if (label[y] == kFree) { 

          int time_next = px + 1;
          if (time_next == time_current_) grow(x, y, mate[y]);
          else if (time_next <= NH) list.push(time_next, eid);
        }
      }
    }
    return false;
  }

  bool adjust_dual_variables() {
    

    const int time_lim = min(NH + 1, time_augment_);
    for (++time_current_; time_current_ <= time_lim; ++time_current_) {
      dsu_changelog_size_ = dsu_changelog_last_;
      if (time_current_ == time_lim) break;
      bool updated = false;
      for (int h = list.head[time_current_]; h >= 0; h = list.next[h]) {
        auto& e = edges[h]; int x = e.from, y = e.to;
        if (label[y] > 0) {
          

          if (potential[x] + potential[y] != (time_current_ << 1)) continue;
          if (dsu.find(x) == dsu.find(y)) continue;
          if (label[x] != label[y]) { time_augment_ = time_current_; return false; }
          contract(x, y); updated = true;
        } else if (label[y] == kFree) {
          grow(x, y, mate[y]); updated = true;
        }
      }
      list.head[time_current_] = -1;
      if (updated) return false;
    }
    return time_current_ > NH;
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
      if (time_current_ == time_augment_) break;
    }
    for (int u = 1; u <= N; ++u) {
      if (label[u] > 0) potential[u] -= time_current_;
      else if (label[u] < 0) potential[u] = 1 + (time_current_ - potential[u]);
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
        int stack_beg = stack_last_;
        for (int bv = by; bv != bx; bv = dsu.find(link[bv].from)) {
          int bw = dsu.find(mate[bv]);
          stack[stack_last_++] = bw; link[bw] = {x, y};
          dsu.par[bv] = dsu.par[bw] = bx;
        }
        while (stack_last_ > stack_beg) {
          int bv = stack[--stack_last_];
          for (int v = blossom.head[bv]; v >= 0; v = blossom.next[v]) {
            if (!dfs_augment(v, bx)) continue;
            stack_last_ = stack_beg;
            return true;
          }
        }
      } else if (ly == kFree) {
        label[by] = kInner; int z = mate[by];
        if (z == 0) { rematch(x, y); rematch(y, x); return true; }
        int bz = dsu.find(z);
        link[bz] = {x, y}; label[bz] = outer_id_++;
        for (int v = blossom.head[bz]; v >= 0; v = blossom.next[v]) {
          if (dfs_augment(v, bz)) return true;
        }
      }
    }
    return false;
  }

  int find_maximal() {
    

    for (int u = 1; u <= N; ++u) dsu.par[u] = u;
    for (int i = 0; i < dsu_changelog_size_; ++i) {
      dsu.par[dsu_changelog[i].v] = dsu_changelog[i].par;
    }
    for (int u = 1; u <= N; ++u) {
      label[u] = kFree; blossom.push(dsu.find(u), u);
    }
    int ret = 0;
    for (int u = 1; u <= N; ++u) if (!mate[u]) {
        int bu = dsu.par[u];
        if (label[bu] != kFree) continue;
        label[bu] = outer_id_++;
        for (int v = blossom.head[bu]; v >= 0; v = blossom.next[v]) {
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

    dsu = DisjointSetUnion(N + 1);
    list = LinkedList(NH + 1, edges.size());

    blossom = LinkedList(N + 1, N + 1);
    stack.resize(N); stack_last_ = 0;
  }

  const int N, NH;
  vector<int> ofs;

  vector<Edge> edges;

  Queue<int> que;

  vector<int> mate, potential;
  vector<int> label; vector<Link> link;

  vector<Log> dsu_changelog; int dsu_changelog_last_, dsu_changelog_size_;

  DisjointSetUnion dsu;
  LinkedList list, blossom;
  vector<int> stack; int stack_last_;

  int time_current_, time_augment_;
  int contract_count_, outer_id_;
};




#ifndef FAST_RANDOM
#ifdef GOLIKOV
mt19937_64 rng(566);
#else
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#endif

template <typename T>
T rnd_helper(T from, T to, true_type) {
  return uniform_int_distribution<T>(from, to)(rng);
}

template <typename T>
T rnd_helper(T from, T to, false_type) {
  return uniform_real_distribution<T>(from, to)(rng);
}

template <typename T>
T rnd(T from, T to) {
  return rnd_helper(from, to, is_integral<T>{});
}
#else
  using ui32 = uint32_t;
  ui32 SEED = 471241271;

  ui32 xorshift32() {
    SEED ^= SEED << 13u;
    SEED ^= SEED >> 17u;
    SEED ^= SEED << 5u;
    return SEED;
  }

  template <class T>
  T rnd_helper(T from, T to, false_type) {
    return from + (to - from) * (T(1) * xorshift32() / numeric_limits<ui32>::max());
  }

  template <class T>
  T rnd_helper(T from, T to, true_type) {
    return from + xorshift32() % (to - from + 1);
  }

  template <class T>
  T rnd(T from, T to) {
    return rnd_helper(from, to, is_integral<T>{});
  }
#endif

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;

  vector<bool> have(n);

  for (int i = 0; i + 1 < n; ++i) {
    if (a[i] > 0 && a[i + 1] > 0 && a[i] == a[i + 1]) {
      have[a[i] - 1] = true;
    }
  }

  vector<pair<int, int>> gaps;

  for (int i = 0; i < n; ++i) {
    if (a[i] != 0) {
      continue;
    }
    int j = i;
    while (j < n && a[j] == 0) {
      ++j;
    }
    gaps.emplace_back(i - 1, j);
    i = j;
  }

  vector<int> vid(n, -1);
  int id = 0;
  for (int i = 0; i < n; ++i) {
    if (!have[i]) {
      vid[i] = id++;
    }
  }

  int ngap = int(gaps.size());
  int nvs = id + ngap;

  vector<int> ofs(nvs + 2);
  vector<pair<int, int>> edges;

  auto addEdge = [&](int u, int v) {
    assert(0 <= u && u < nvs && 0 <= v && v < nvs && u != v);
    edges.emplace_back(u, v);
    ofs[u + 2]++;
    ofs[v + 2]++;
  };

  int cid = id;
  for (auto[l, r] : gaps) {
    int len = r - l - 1;
    if (len % 2 == 0) {
      if (l >= 0 && r < n) {
        int x = vid[a[l] - 1];
        int y = vid[a[r] - 1];
        if (x >= 0 && y >= 0 && x != y) {
          addEdge(x, y);
        }
      }
    } else {
      if (l >= 0) {
        int x = vid[a[l] - 1];
        if (x >= 0) {
          addEdge(cid, x);
        }
      }
      if (r < n) {
        int y = vid[a[r] - 1];
        if (y >= 0) {
          addEdge(cid, y);
        }
      }
    }
    cid++;
  }

  for (int i = 1; i <= nvs + 1; ++i) {
    ofs[i] += ofs[i - 1];
  }

  int nedges = int(edges.size());
  vector<MaximumMatching::Edge> medges(2 * nedges);
  for (auto[u, v] : edges) {
    MaximumMatching::Edge e{u + 1, v + 1};
    medges[ofs[e.from]++] = e; medges[ofs[e.to]++] = {e.to, e.from};
  }
  for (int i = nvs + 1; i > 0; --i) ofs[i] = ofs[i - 1];
  ofs[0] = 0;
  MaximumMatching matching(nvs, move(ofs), move(medges));
  matching.maximum_matching();

  cid = id;
  for (auto[l, r] : gaps) {
    int len = r - l - 1;
    if (len % 2 == 0) {
      if (l >= 0 && r < n) {
        int x = vid[a[l] - 1];
        int y = vid[a[r] - 1];
        if (x >= 0 && y >= 0 && x != y) {
          if (!have[a[l] - 1] && !have[a[r] - 1]) {
            int mt = matching.mate[x + 1];
            if (mt == y + 1) {
              a[l + 1] = a[l];
              a[r - 1] = a[r];
              have[a[l] - 1] = true;
              have[a[r] - 1] = true;
            }
          }
        }
      }
    } else {
      if (l >= 0) {
        int x = vid[a[l] - 1];
        if (x >= 0) {
          int mt = matching.mate[cid + 1];
          if (mt == x + 1 && !have[a[l] - 1]) {
            a[l + 1] = a[l];
            have[a[l] - 1] = true;
          }
        }
      }
      if (r < n) {
        int y = vid[a[r] - 1];
        if (y >= 0) {
          int mt = matching.mate[cid + 1];
          if (mt == y + 1 && !have[a[r] - 1]) {
            a[r - 1] = a[r];
            have[a[r] - 1] = true;
          }
        }
      }
    }
    cid++;
  }

  int ptr = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] != 0) {
      continue;
    }
    int j = i;
    while (j < n && a[j] == 0) {
      ++j;
    }
    int len = j - i;
    int fr = i;
    if (len % 2 == 1) {
      a[fr++] = 1;
    }
    for (int cur = fr; cur < j; cur += 2) {
      while (ptr < n && have[ptr]) {
        ++ptr;
      }
      if (ptr == n) {
        a[cur] = a[cur + 1] = 1;
      } else {
        a[cur] = a[cur + 1] = ptr + 1;
        have[ptr] = true;
      }
    }
    i = j;
  }

  for (auto x : a) cout << x << ' ';
  cout << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}
