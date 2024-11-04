



#ifndef ONLINE_JUDGE
#pragma clang diagnostic warning "-Wall"
#pragma clang diagnostic warning "-Wextra"
#pragma clang diagnostic warning "-Weverything"
#pragma clang diagnostic warning "-Wconversion"
#pragma clang diagnostic ignored "-Wvla"
#pragma clang diagnostic ignored "-Wvla-extension"
#pragma clang diagnostic ignored "-Wshadow"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wunused-macros"
#pragma clang diagnostic ignored "-Wmissing-prototypes"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wsign-compare"
#pragma clang diagnostic ignored "-Wold-style-cast"
#pragma clang diagnostic ignored "-Wmissing-variable-declarations"
#pragma clang diagnostic ignored "-Wglobal-constructors"
#pragma clang diagnostic ignored "-Wunused-const-variable"
#pragma clang diagnostic ignored "-Wpadded"
#pragma clang diagnostic ignored "-Wcomma"
#pragma clang diagnostic ignored "-Wfloat-equal"      

#pragma clang diagnostic ignored "-Wdouble-promotion" 

#endif

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <unistd.h>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;




#ifdef ONLINE_JUDGE
static bool debug = false;
#else
static bool debug = true;
#endif
#define db(x) #x << "=" << (x) << " "
#define dprintf debug &&printf

#define All(x) x.begin(), x.end()
#define Loop(i, n) for (int i = 0; i < int(n); ++i)
template <typename T, typename Q, typename S>
bool Bounded(const T &x, const Q &a, const S &b) {
  return a <= x && x <= b;
}

typedef long double Real;
const Real pi = 4 * atan(Real(1.0));
const Real Inf = numeric_limits<Real>::infinity();


Real isapprox(Real x, Real y, Real rtol = sqrt(numeric_limits<Real>::epsilon()),
              Real atol = Real(0.0), bool nans = false) {
  return x == y || (nans && isnan(x) && isnan(y)) ||
         (isfinite(x) && isfinite(y) &&
          abs(x - y) <= atol + rtol * max(abs(x), abs(y)));
}
typedef long long int ll;
typedef vector<Real> Vd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<bool> Vb;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

template <typename T> int sz(const T &x) { return (int)x.size(); }
template <typename T, typename Q> bool mem(const T &s, const Q &x) {
  return s.find(x) != s.end();
}
template <typename T> void push(vector<T> &c, const T &e) { c.push_back(e); }
template <typename T> void push(queue<T> &c, const T &e) { c.push(e); }
template <typename T> void push(set<T> &c, const T &e) { c.insert(e); }
template <typename T> T pop(vector<T> &v) {
  assert(!v.empty());
  T u = v.back();
  v.pop_back();
  return u;
}
template <typename T> T pop(queue<T> &v) {
  assert(!v.empty());
  T u = v.front();
  v.pop();
  return u;
}
template <typename T, typename... Args>
auto emplace(vector<T> &c, Args &&... args)
    -> decltype(c.emplace_back(args...)) {
  c.emplace_back(args...);
}
template <typename T, typename... Args>
auto emplace(queue<T> &c, Args &&... args) -> decltype(c.emplace(args...)) {
  c.emplace(args...);
}
template <typename T, typename... Args>
auto emplace(set<T> &c, Args &&... args) -> decltype(c.emplace(args...)) {
  c.emplace(args...);
}
template <typename T> void umin(T &x, const T &y) { x = min(x, y); }
template <typename T> void umax(T &x, const T &y) { x = max(x, y); }
template <typename T> int sign(const T &x) {
  return x == 0 ? 0 : x > 0 ? 1 : -1;
}
template <typename T> T square(const T &x) { return x * x; }




template <typename S, typename T>
istream &operator>>(istream &in, pair<S, T> &p) {
  return in >> p.first >> p.second;
}
template <typename T> T read() {
  T x;
  cin >> x;
  return x;
}
template <typename T, typename I = typename T::iterator> void read(T &cnt) {
  for (auto &x : cnt)
    cin >> x;
}
template <typename S, typename T>
ostream &operator<<(ostream &out, const pair<S, T> &p) {
  return out << "{" << p.first << ", " << p.second << "}";
}
template <typename T> struct show_container {
  const T &container;
  show_container(const T &container_) : container(container_) {}
};
template <typename T>
ostream &operator<<(ostream &o, const show_container<T> &thing) {
  bool first = true;
  o << "{";
  for (const auto &x : thing.container) {
    if (!first)
      o << ", ";
    first = false;
    o << x;
  }
  o << "}";
  return o;
}
template <typename T> show_container<T> show(const T &container) {
  return show_container<T>(container);
}

#define dprintf debug &&printf
struct dout_ {
} dout;
#ifdef ONLINE_JUDGE
template <typename T> dout_ &operator<<(dout_ &out, const T &thing) {
  return out;
}
dout_ &operator<<(dout_ &out, ostream &(*thing)(ostream &)) { return out; }
#else
template <typename T> dout_ &operator<<(dout_ &out, const T &thing) {
  if (debug)
    cerr << thing;
  return out;
}
dout_ &operator<<(dout_ &out, ostream &(*thing)(ostream &)) {
  if (debug)
    cerr << thing;
  return out;
}
#endif

struct outboth {
  ostream &a;
  ostream &b;
  outboth(ostream &a_, ostream &b_) : a(a_), b(b_) {}
};
template <typename T> outboth &operator<<(outboth &both, const T &thing) {
  both.a << thing;
  both.b << thing;
  return both;
}
outboth &operator<<(outboth &both, ostream &(*thing)(ostream &)) {
  both.a << thing;
  both.b << thing;
  return both;
}





struct Graph {
  typedef int T;
  static const ll MAXCAP = numeric_limits<ll>::max() >> 10;

  struct E;
  struct V {
    T data;
    int index;

    E* parent;
    V(T data, int index)
      : data(data), index(index),
        parent(nullptr)
    { }

    friend ostream& operator<<(ostream& o, const V& v) { return o << v.data; }
  };
  struct E {
    V *from, *to;
    int index;
    ll weight, cap, rescap;
    E* rev;
    E(V* from, V* to, int index, ll weight, ll cap)
      : from(from), to(to), index(index),
        weight(weight), cap(cap), rescap(cap), rev(nullptr)
    {
      assert(from); assert(to);
    }

    friend ostream& operator<<(ostream& o, const E& e) {
      o << "E(" << e.from->data << ", " << e.to->data << ")";
      if (e.weight != 0) o << "[" << e.weight << "]";
      if (e.cap != 0 || e.rescap != 0) {
        o << "[cap=" << e.cap;
        if (e.rescap != e.cap) o << "/" << e.rescap;
        o << "]";
      }
      return o;
    }
    string str() const { ostringstream o; o << *this; return o.str(); }
  };

  vector<unique_ptr<V>> vertices;
  vector<vector<E*>> adj;
  vector<unique_ptr<E>> edges;

  Graph() {
    vertices.reserve(1024);
    edges.reserve(1024);
  }

  


  bool empty() const { return sz(vertices) == 0; }
  int numV() const { return sz(vertices); }
  int numE() const { return sz(edges); }
  V* vertex(int index) { return vertices.at(index).get(); }
  const V* vertex(int index) const { return vertices.at(index).get(); }
  E* edge(int index) { return edges.at(index).get(); }
  const E* edge(int index) const { return edges.at(index).get(); }
  vector<E*>& outEdges(const V* u) { return adj[u->index]; }
  const vector<E*>& outEdges(const V* u) const { return adj[u->index]; }

  

  


  V* addVertex(T data) {
    vertices.push_back(unique_ptr<V>(new V(data, sz(vertices))));
    adj.push_back(vector<E*>());
    return vertices.back().get();
  }

  E* addEdge(V* from, V* to, ll weight = 0, ll cap = 0) {
    E *e = new E(from, to, sz(edges), weight, cap);
    edges.emplace_back(e);
    outEdges(from).push_back(edges.back().get());
    return edges[e->index].get();
  }

  E* addBidiEdge(V* from, V* to, ll weight = 0, ll cap = 0) {
    

    

    E *e1 = new E(from, to, sz(edges), weight, cap);
    E *e2 = new E(to, from, sz(edges)+1, weight, 0);
    e1->rev = e2;
    e2->rev = e1;
    e1->rev->weight *= -1;
    edges.emplace_back(e1);
    outEdges(from).push_back(edges.back().get());
    edges.emplace_back(e2);
    outEdges(to).push_back(edges.back().get());
    

    return e1;
  }

  

  


  void pp(ostream& o) const {
    o << "Graph on " << sz(vertices) << " vertices with " << sz(edges) << " edges.\n";
    for (auto& v : vertices) {
      o << " │ " << v->data << " [" << "] ⟹";
      for (auto& e : outEdges(v.get())) {
        o << " " << e->to->data;
        if (e->cap > 0) o << "(cap=" << e->cap << "/" << e->rescap << ")";
      }
      o << '\n';
    }
  }

  void dot(ostream& o, bool undirected = true) const {
    o << "graph {\n";
    for (const auto& e : edges)
      if (!undirected || e->from->index <= e->to->index)
        o << e->from->data << " -- " << e->to->data << "\n";
    o << "}\n";
  }

  


};

ostream& operator<<(ostream& o, const Graph& g) { g.pp(o); return o; }







ll mincostFlow_dijkstra(Graph& g, typename Graph::V *source, typename Graph::V *sink) {
  typedef Graph G; typedef typename G::V V; typedef typename G::E E;

  ll totalFlow = 0, totalCost = 0;
  const int N = g.numV();
  for (auto& e : g.edges) {
    e->rescap = e->cap;
    assert((e->cap > 0) == (e->rev->cap == 0));
    assert(e->weight == 0 || (e->cap > 0) == (e->weight > 0));
  }

  vector<E*> parent(N);
  Vll potential(N);
  auto weight = [&](E* e) { return e->weight + potential[e->from->index] - potential[e->to->index]; };
  typedef pair<ll, V*> ST;

  while (true) {
    Vb finished(N);
    const ll MAXDIST = LLONG_MAX >> 16;
    Vll dist(N, MAXDIST);
    priority_queue<ST, vector<ST>, std::greater<ST>> dijkstra;
    dijkstra.emplace(0, source);
    dist[source->index] = 0;
    while (!dijkstra.empty()) {
      ll d; V* u; tie(d, u) = dijkstra.top(); dijkstra.pop();
      assert(d >= dist[u->index]);
      if (finished[u->index]) continue;
      finished[u->index] = true;
      assert(dist[u->index] == d);
      for (E* e : g.outEdges(u)) {
        if (e->rescap == 0) continue;
        

        assert(e->rescap > 0);
        assert(weight(e) >= 0);
        ll f = d + weight(e);
        if (f < dist[e->to->index]) {
          dist[e->to->index] = f;
          parent[e->to->index] = e;
          dijkstra.emplace(f, e->to);
        }
      }
    }
    

    

    

    

    

    if (!finished[sink->index]) break;

    Loop(i,N) potential[i] += dist[i];

    ll cost = 0, flow = LLONG_MAX;
    for (E* e = parent[sink->index]; e; e = parent[e->from->index]) {
      

      umin(flow, e->rescap);
    }
    assert(flow > 0);

    for (E* e = parent[sink->index]; e; e = parent[e->from->index]) {
      e->rescap -= flow;
      e->rev->rescap += flow;
      

      

      cost += e->weight * flow;
    }
    


    totalFlow += flow;
    totalCost += cost;

    

    

    

    

    

    

    

    

  }

  dout << db(totalFlow) << db(totalCost) << endl;

  return totalCost;
}






const ll INF = LLONG_MAX / 4;

#ifdef ONLINE_JUDGE
void solve(ostream &rout)
#else
void solve(outboth rout)
#endif
{
  static int casenum = 0;
  ++casenum;

  int N, K; cin >> N >> K; if (!cin) return;
  Vll A(N), B(N); read(A); read(B);
  dout << "============================================================ " << casenum << endl;
  

  ll ans = 0;

  Graph g;
  typedef Graph::V V;
  V* source = g.addVertex(-1), *source2 = g.addVertex(-2), *sink = g.addVertex(-3);
  vector<V*> vertices(N); Loop(i, N) vertices[i] = g.addVertex(i);
  g.addBidiEdge(source, source2, 0, K);
  Loop(i, N) {
    g.addBidiEdge(source2, vertices[i], A[i], 1);
    g.addBidiEdge(vertices[i], sink, B[i], 1);
    if (i+1 < N)
      g.addBidiEdge(vertices[i], vertices[i+1], 0, N);
  }
  ans = mincostFlow_dijkstra(g, source, sink);

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  


  

  

  

  

  

  

  

  

  

  

  

  


  rout << ans << endl;
}






#ifdef ONLINE_JUDGE
int main() {
  

  

  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve(cout);
  return 0;
}
#else
int main(int argc, char **argv) {
  string fnIn = argc > 1 ? argv[1] : "N.test.in";
  string fnOut = fnIn.substr(0, sz(fnIn) - 3) + ".last";
  string fnTest = fnIn.substr(0, sz(fnIn) - 3) + ".out";
  assert(freopen(fnIn.c_str(), "r", stdin));
  if (getenv("NODEBUG"))
    debug = false;

  ofstream outfile(fnOut);
  auto startTime = std::chrono::high_resolution_clock::now();

  while (cin)
    solve(outboth(cout, outfile));
  outfile.flush();

  std::chrono::duration<double> elapsed =
      std::chrono::high_resolution_clock::now() - startTime;
  cout << "Time taken: [1m" << elapsed.count() << "[0m" << endl;
  string cmd = "bash -c 'colordiff <(nl -w3 -nln -s: \"" + fnOut +
               "\") <(nl -w3 -nln -s: \"" + fnTest + "\")'";
  int ret = system(cmd.c_str());
  ret = WEXITSTATUS(ret);
  if (ret)
    cout << "[41;1;4mdiff failed.[0m\n";
  else
    cout << "[44;1;4mdiff succeeded.[0m\n";
  return ret;
}
#endif














