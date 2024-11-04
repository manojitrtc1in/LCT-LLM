

#include <bits/stdc++.h>





#define __GRAPH







using namespace std;




typedef long long ll;

namespace codeforces {






#ifdef __DEBUG






#define ___debug_1(var) codeforces::printVariable(#var, (var), {0, true});
#define ___debug_2(var, w) codeforces::printVariable(#var, (var), {(w), true});
#define ___debug_3(var, i, j)                                                  \
  codeforces::printArray(#var, (var), (i), (j), {0, true}); 

#define ___debug_4(var, i, j, w)                                               \
  codeforces::printArray(#var, (var), (i), (j),                                \
                         {(w), true}); 

#define ___debug_5(var, i, j, p, q)                                            \
  codeforces::printMatrix(#var, (var), (i), (j), (p), (q),                     \
                          {0, false}); 

#define ___debug_6(var, i, j, p, q, w)                                         \
  codeforces::printMatrix(#var, (var), (i), (j), (p), (q),                     \
                          {(w), false}); 


#define ___get_macro(_1, _2, _3, _4, _5, _6, N, ...) N

#define debug(...)                                                             \
  ___get_macro(__VA_ARGS__, ___debug_6, ___debug_5, ___debug_4, ___debug_3,    \
               ___debug_2, ___debug_1, ...)(__VA_ARGS__)

#define warning(message)                                                       \
  {                                                                            \
    string __msg = message;                                                    \
    debug(__msg);                                                              \
  }

inline void printDebugHeader(const string &name) {
  cout << "\n>>> " << name << " start:\n";
}

inline void printDebugFooter(const string &name) {
  cout << "--- end of " << name << endl;
}

template <typename _T>
inline void printVariable(const string &name, const _T &_x,
                          const pair<int, bool> &ctrl) {
  const int &width = ctrl.first;
  const bool &endline = ctrl.second;
  cout << "\" " << name << " \": ";
  if (width) {
    cout << setw(width);
  }
  cout << _x << " ";
  if (endline) {
    cout << endl;
  }
}

template <typename _T>
inline void printArray(const string &name, const _T &_x, const int &_l,
                       const int &_r, const pair<int, bool> &ctrl) {
  codeforces::printDebugHeader(name);
  for (int i = _l; i <= _r; i++) {
    cout << "  ";
    printVariable("[" + to_string(i) + "]", _x[i], ctrl);
  }
  codeforces::printDebugFooter(name);
}

template <typename _T>
inline void printMatrix(const string &name, const _T &_x, const int &_l1,
                        const int &_r1, const int &_l2, const int &_r2,
                        const pair<int, bool> &ctrl) {
  codeforces::printDebugHeader(name);
  const int &width = ctrl.first;
  const bool &endline = ctrl.second;
  for (int i = _l1; i <= _r1; i++) {
    if (!endline)
      cout << "  ";
    for (int j = _l2; j <= _r2; j++) {
      if (endline) {
        cout << "  ";
      }
      printVariable("[" + to_string(i) + ", " + to_string(j) + "]", _x[i][j],
                    {width, endline});
    }
    if (!endline)
      cout << endl;
  }
  codeforces::printDebugFooter(name);
}

#else

#define debug(...)
#define warning(...)

#endif




template <typename _T, typename _RET = ll> _RET square(const _T &x) {
  return (_RET)x * x;
}

#ifdef __TRIPLE

template <typename _T1, typename _T2, typename _T3>
class triple : public pair<_T1, pair<_T2, _T3>> {
  typedef pair<_T1, pair<_T2, _T3>> super;
  typedef pair<_T2, _T3> _;

public:
  triple() = default;
  triple(const _T1 &_1, const _T2 &_2, const _T3 &_3) : super(_1, _(_2, _3)) {}
  _T1 &first = super::first;
  _T2 &second = super::second.first;
  _T3 &third = super::second.second;
};

template <typename _T = int> class point2 : public pair<_T, _T> {
  typedef pair<_T, _T> super;

public:
  point2() = default;
  point2(const _T &x, const _T &y) : super(x, y) {}
  _T &x = super::first;
  _T &y = super::second;
};

template <typename _T = int> class point3 : public triple<_T, _T, _T> {
  typedef triple<_T, _T, _T> super;

public:
  point3() = default;
  point3(const _T &x, const _T &y, const _T &z) : super(x, y, z) {}
  _T &x = super::first;
  _T &y = super::second;
  _T &z = super::third;
};

#endif

#ifdef __BIT

template <typename Data_T> class BiT {

  inline static int lowbit(int x) { return x & -x; }

  template <typename Src_T, typename Size_T>
  static void init(Src_T src, Size_T len, shared_ptr<vector<Data_T>> &dst_ptr) {
    auto &dst = *dst_ptr;
    for (int i = 1; i <= len; i++) {
      dst[i] += src[i];
      int j = i + lowbit(i);
      if (j < len)
        dst[j] += dst[i];
    }
  }

public:
  shared_ptr<vector<Data_T>> data;

  BiT(int len) : data(new vector<Data_T>(len + 1)) {}

  BiT(Data_T *arr, int len) : data(new vector<Data_T>(len + 1)) {
    init(arr, len, data);
  }

  BiT(const vector<Data_T> &d) : data(new vector<Data_T>(d.size())) {
    init(d, d.size() - 1, data);
  }

  BiT(const BiT &that) : data(new vector<Data_T>(*that.data)) {}

  void add(int pos, const int &k) {
    for (; pos < data->size(); pos += lowbit(pos)) {
      data->at(pos) = data->at(pos) + k;
    }
  }

  Data_T getPrefixSum(int pos) {
    Data_T ans = 0;
    for (; pos >= 1; pos -= lowbit(pos)) {
      ans = ans + data->at(pos);
    }
    return ans;
  }

  Data_T getSum(int l, int r) {
    if (r < l) {
      warning("bit.getSum");
      debug(l);
      debug(r);
    }
    return getPrefixSum(r) - getPrefixSum(l);
  }
};

#endif

#ifdef __DISCRETIZER

template <typename Data_T> class Discretizer {
  Data_T *arr;
  int len;

public:
  Discretizer(Data_T *a, const int &l) {
    arr = new int[len + 1];
    copy(a, a + len + 1, arr);
    sort(arr + 1, arr + len + 1);
    len = unique(arr + 1, arr + len + 1) - arr;
  }
  ~Discretizer() { delete[] arr; }
  int count() { return len; }
  int rank(const Data_T &orgin) {
    return lower_bound(arr + 1, arr + len + 1, orgin) - arr;
  }
  Data_T orgin(int rank) { return arr[rank]; }
};

#endif

#ifdef __GRAPH

typedef int nodeId;
typedef int edgeId;

template <typename Weight_T = void, typename Capability_T = void> class Edge;

template <> class Edge<void, void> {

protected:
  nodeId t;
  edgeId n;

public:
  typedef void _Weight;
  typedef void _Capability;
  Edge() = default;
  Edge(const nodeId &t, const edgeId &n) : t(t), n(n) {}

  nodeId to() const { return t; }
  edgeId next() const { return n; }

  void setTo(const nodeId &id) { t = id; }
  void setNext(const edgeId &id) { n = id; }
};

template <typename Weight_T>
class Edge<Weight_T> : virtual public Edge<void, void> {
  typedef Edge<void, void> Base;

protected:
  Weight_T w;

public:
  typedef Weight_T _Weight;
  typedef void _Capability;
  Edge(const nodeId &t, const edgeId &n, const Weight_T &w)
      : Base(t, n), w(w) {}
  Edge(const Weight_T &w) : w(w) {}
  Weight_T weight() const { return w; }
  void setWeight(const Weight_T &weight) { w = weight; }
};

template <typename Capability_T>
class Edge<void, Capability_T> : virtual public Edge<void, void> {
  typedef Edge<void, void> Base;

protected:
  Capability_T c;

public:
  typedef void _Weight;
  typedef Capability_T _Capability;
  Edge(const nodeId &t, const edgeId &n, const Capability_T &c)
      : Base(t, n), c(c) {}
  Edge(const Capability_T &c) : c(c) {}
  Capability_T cap() const { return c; }
  void setCap(const Capability_T &cap) { c = cap; }
  void capAdd(const Capability_T &cap) { c += cap; }
};

template <typename Weight_T, typename Capability_T>
class Edge : virtual public Edge<Weight_T>,
             virtual public Edge<void, Capability_T> {
  typedef Edge<void, void> Base;
  typedef Edge<Weight_T> Base1;
  typedef Edge<void, Capability_T> Base2;

public:
  typedef Weight_T _Weight;
  typedef Capability_T _Capability;
  Edge(const nodeId &t, const edgeId &n, const Weight_T &w,
       const Capability_T &c)
      : Base(t, n), Base1(w), Base2(c) {}
};

template <typename Edge_T> class Graph {

protected:
  int en; 

  shared_ptr<vector<nodeId>> head;
  shared_ptr<vector<shared_ptr<Edge_T>>> edges;
  Graph(const int &en, vector<shared_ptr<Edge_T>> *e, vector<nodeId> *h)
      : en(en), head(h), edges(e) {}

public:
  Graph(int max_node, int max_edge)
      : en(0), head(new vector<nodeId>(max_node + 1)),
        edges(new vector<shared_ptr<Edge_T>>(max_edge + 1)) {}

  shared_ptr<Graph> copy() {
    auto new_head = new vector<nodeId>(*head);
    auto new_edges = new vector<shared_ptr<Edge_T>>(*edges);
    for (auto &p : *new_edges) {
      if (p)
        p.reset(new Edge_T(*p));
    }
    return shared_ptr<Graph>(new Graph(en, new_edges, new_head));
  }

  pair<int, int> size() {
    return make_pair(head->size() - 1, edges->size() - 1);
  }

  template <typename T = Edge_T>
  typename enable_if<is_same<T, Edge<>>::value>::type add(const nodeId &from,
                                                          const nodeId &to) {
    en++;
    auto &E = *edges;
    auto &H = *head;
    E[en].reset(new Edge_T(to, H[from]));
    H[from] = en;
  }

  template <typename T = Edge_T>
  typename enable_if<is_same<T, Edge<>>::value>::type
  addBoth(const nodeId &from, const nodeId &to) {
    add(from, to);
    add(to, from);
  }

  template <typename T = Edge_T>
  typename enable_if<is_same<T, Edge<typename Edge_T::_Weight>>::value>::type
  add(const nodeId &from, const nodeId &to, const typename T::_Weight &w) {
    en++;
    auto &E = *edges;
    auto &H = *head;
    E[en].reset(new Edge_T(to, H[from], w));
    H[from] = en;
  }

  template <typename T = Edge_T>
  typename enable_if<is_same<T, Edge<typename Edge_T::_Weight>>::value>::type
  addBoth(const nodeId &from, const nodeId &to, const typename T::_Weight &w) {
    add(from, to, w);
    add(to, from, w);
  }

  template <typename T = Edge_T>
  typename enable_if<
      is_same<T, Edge<void, typename Edge_T::_Capability>>::value>::type
  add(const nodeId &from, const nodeId &to, const typename T::_Capability &c) {
    en++;
    auto &E = *edges;
    auto &H = *head;
    E[en].reset(new Edge_T(to, H[from], c));
    H[from] = en;
  }

  template <typename T = Edge_T>
  typename enable_if<
      is_same<T, Edge<void, typename Edge_T::_Capability>>::value>::type
  addBoth(const nodeId &from, const nodeId &to,
          const typename T::_Capability &c) {
    add(from, to, c);
    add(to, from, 0);
  }

  template <typename T = Edge_T>
  typename enable_if<
      is_same<T, Edge<typename Edge_T::_Weight,
                      typename Edge_T::_Capability>>::value>::type
  add(const nodeId &from, const nodeId &to, const typename T::_Weight &w,
      const typename T::_Capability &c) {
    en++;
    auto &E = *edges;
    auto &H = *head;
    E[en].reset(new Edge_T(to, H[from], w, c));
    H[from] = en;
  }

  template <typename T = Edge_T>
  typename enable_if<
      is_same<T, Edge<typename Edge_T::_Weight,
                      typename Edge_T::_Capability>>::value>::type
  addBoth(const nodeId &from, const nodeId &to, const typename T::_Weight &w,
          const typename T::_Capability &c) {
    add(from, to, w, c);
    add(to, from, w, 0);
  }

  edgeId from(const nodeId &u) { return head->at(u); }
  Edge_T &edge(const edgeId &id) { return *edges->at(id); }
  Edge_T &redge(const edgeId &id) { return *edges->at(((id - 1) ^ 1) + 1); }

  template <typename E = Edge_T>
  typename enable_if<!is_same<typename E::_Weight, void>::value,
                     shared_ptr<vector<typename E::_Weight>>>::type
  dijkstra(const nodeId &source) {
    priority_queue<pair<typename Edge_T::_Weight, nodeId>,
                   vector<pair<typename Edge_T::_Weight, nodeId>>,
                   greater<pair<typename Edge_T::_Weight, nodeId>>>
        heap;
    shared_ptr<vector<typename Edge_T::_Weight>> res(
        new vector<typename Edge_T::_Weight>(head->size(), INT_MAX));
    auto &dis = *res;
    vector<bool> vis(head->size(), 0);
    dis[source] = 0;
    heap.push(make_pair(dis[source], source));
    while (!heap.empty()) {
      auto now = heap.top();
      heap.pop();
      auto &d = now.first;
      auto &i = now.second;
      if (vis[i])
        continue;
      vis[i] = 1;
      for (auto e = from(i); e; e = edge(e).next()) {
        const auto &ed = edge(e);
        const nodeId &to = ed.to();
        if (vis[to])
          continue;
        auto _new = d + ed.weight();
        auto &_old = dis[to];
        if (_new < _old) {
          _old = _new;
          heap.push({_old, to});
        }
      }
    }
    return res;
  }

  template <typename E = Edge_T>
  typename enable_if<!is_same<typename E::_Weight, void>::value,
                     shared_ptr<vector<typename E::_Weight>>>::type
  spfa(const edgeId &source) {
    queue<edgeId> que;
    shared_ptr<vector<typename E::_Weight>> res(
        new vector<typename E::_Weight>(head->size(), INT_MAX));
    auto &dis = *res;
    vector<bool> in(head->size(), 0);
    vector<int> cnt(head->size(), 0);
    dis[source] = 0;
    que.push(source);
    in[source] = 1;
    cnt[source] = 1;
    while (!que.empty()) {
      auto now = que.front();
      que.pop();
      in[now] = 0;
      for (auto e = from(now); e; e = edge(e).next()) {
        const auto &ed = edge(e);
        auto to = ed.to();
        auto _new = dis[now] + ed.weight();
        auto &_old = dis[to];
        if (_new < _old) {
          _old = _new;
          if (!in[to]) {
            que.push(to);
            in[to] = 1;
            cnt[to]++;
            if (cnt[to] > head->size() - 1)
              return nullptr;
          }
        }
      }
    }
    return res;
  }

  template <typename E = Edge_T>
  typename enable_if<!is_same<typename E::_Capability, void>::value,
                     typename E::_Capability>::type
  Ford_Fulkerson_dfs(vector<bool> &vis, const nodeId &start, const nodeId &end,
                     typename E::_Capability flow) {
    if (start == end) {
      return flow;
    }
    vis[start] = true;
    for (auto i = from(start); i; i = edge(i).next()) {
      auto &ed = edge(i);
      auto &red = redge(i);
      if (!vis[ed.to()] && ed.cap() > 0) {
        int d = Ford_Fulkerson_dfs(vis, ed.to(), end, min(flow, ed.cap()));
        if (d > 0) {
          ed.capAdd(-d);
          red.capAdd(d);
          return d;
        }
      }
    }
    return 0;
  }

  template <typename E = Edge_T>
  typename enable_if<!is_same<typename E::_Capability, void>::value,
                     typename E::_Capability>::type
  Ford_Fulkerson(const nodeId &start, const nodeId &end) {
    typename E::_Capability flow = 0;
    auto tmp = copy();
    while (true) {
      vector<bool> vis(size().first);
      typename E::_Capability f = tmp->Ford_Fulkerson_dfs(
          vis, start, end, numeric_limits<typename E::_Capability>::max());
      if (fabsl(f - numeric_limits<typename E::_Capability>::denorm_min()) <=
          1e-5) {
        return flow;
      }
      flow += f;
    }
  }
};




#endif
}; 







int n, m, k;
shared_ptr<codeforces::Graph<codeforces::Edge<ll>>> g;
shared_ptr<vector<pair<int, int>>> edges;
shared_ptr<vector<pair<int, int>>> routines;
void input() {
  cin >> n >> m >> k;
  g.reset(new codeforces::Graph<codeforces::Edge<ll>>(n, m * 2));
  edges.reset(new vector<pair<int, int>>(1));
  routines.reset(new vector<pair<int, int>>(1));
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges->push_back({u, v});
    g->addBoth(u, v, w);
  }
  for (int i = 1; i <= k; i++) {
    int u, v;
    cin >> u >> v;
    routines->push_back({u, v});
  }
  

}

void work() {
  vector<vector<ll>> dis;
  dis.push_back(vector<ll>());
  for (int i = 1; i <= n; i++) {
    dis.push_back(*g->dijkstra(i));
  }
  debug(dis, 1, n, 1, n);
  ll ans = __INT64_MAX__;
  for (int i = 1; i <= m; i++) {
    ll sum = 0;
    for (int j = 1; j <= k; j++) {
      sum += min(dis[(*routines)[j].first][(*edges)[i].first] +
                     dis[(*edges)[i].second][(*routines)[j].second],
                 min(dis[(*routines)[j].first][(*edges)[i].second] +
                         dis[(*edges)[i].first][(*routines)[j].second],
                     dis[(*routines)[j].first][(*routines)[j].second]));
    }
    ans = min(ans, sum);
  }
  cout << ans << endl;
  

}

void clean() {
  

}

int main() {

#ifdef __CASES
  int T;
  cin >> T;
  while (T--) {
#endif

    input();
    work();
    clean();

#ifdef __CASES
  }
#endif
  return 0;
}
