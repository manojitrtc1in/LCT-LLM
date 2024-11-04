#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <limits>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef set<int> si;
typedef set<ll> sll;
typedef set<ull> sull;
typedef map<string, int> msi;

#define REP(i, a, b) \
  for (int i = int(a); i <= int(b); ++i)
#define REPd(i, a, b) \
  for (int i = int(a); i >= int(b); --i)
#define FOR(i, n) \
  for (int i = 0; i < n; i++)
#define FORull(i, n) \
  for (ull i = 0; i < n; i++)
#define TRvi(c, it) \
  for (vi::iterator it = (c).begin(); it != (c).end(); ++it)
#define TRvii(c, it) \
  for (vii::iterator it = (c).begin(); it != (c).end(); ++it)
#define TRvull(c, it) \
  for (vull::iterator it = (c).begin(); it != (c).end(); ++it)
#define TRsi(c, it) \
    for (si::iterator it = (c).begin(); it != (c).end(); ++it)
#define TRsull(c, it) \
  for (sull::iterator it = (c).begin(); it != (c).end(); ++it)
#define TRmsi(c, it) \
  for (msi::iterator it = (c).begin(); it != (c).end(); ++it)
#define all(c) \
  (c).begin(), (c).end()
#define vsort(c) \
  sort(all(c))
#define cvsort(c, f) \
  sort(all(c), f)
#define vreverse(c) \
  reverse(all(c))
#define viprint(c) \
  TRvi(c, it) cout << *it << " "; cout << endl;
#define sz(c) \
  (c).size()
#define mp(a, b) \
  make_pair(a, b)
#define MAX_INT \
  numeric_limits<int>::max()
#define MIN_INT \
  numeric_limits<int>::min()








class Graph {
  private:
    vector<vi> al;

  public:
    Graph() {}
    Graph(int a) {
      al.resize(a);
    }
    bool adjacent(int x, int y) {
      return (find(all(al[x]), y) != al[x].end()) || (find(all(al[y]), x) != al[y].end());
    }
    void add(int x, int y) {
      if (max(x, y) + 1 > al.size())
        al.resize(max(x, y) + 1);
      al[x].push_back(y);
      al[y].push_back(x);
    }
    int nodes() {
      return al.size();
    }
    vi neighbours(int x) {
      return al[x];
    }
};



class Digraph {
  private:
    vector<vi> al;

  public:
    Digraph() {}
    Digraph(int a) {
      al.resize(a);
    }
    bool adjacent(int x, int y) {
      return (find(all(al[x]), y) != al[x].end());
    }
    void add(int x, int y) {
      if (x + 1 > al.size())
        al.resize(x + 1);
      al[x].push_back(y);
    }
    int nodes() {
      return al.size();
    }
    vi neighbours(int x) {
      return al[x];
    }
};





class WeightedGraph {
  private:
    vector<vi> m;

  public:
    WeightedGraph() {}
    WeightedGraph(int a) {
      m.resize(a);
      FOR(i, a)
        m[i].resize(a);
    }
    void add(int x, int y, int weight) {
      m[x][y] = weight;
      m[y][x] = weight;
    }
    int get_edge_value(int x, int y) {
      return m[x][y];
    }
    int nodes() {
      return m.size();
    }
    vi neighbours(int x) {
      vi res;
      FOR(i, sz(m[x])) {
        if (m[x][i])
          res.push_back(i);
      }
      return res;
    }
};



class WeightedDigraph {
  private:
    vector<vi> m;

  public:
    WeightedDigraph() {}
    WeightedDigraph(int a) {
      m.resize(a);
      FOR(i, a)
        m[i].resize(a);
    }
    void add(int x, int y, int weight) {
      m[x][y] = weight;
    }
    int get_edge_value(int x, int y) {
      return m[x][y];
    }
    int nodes() {
      return m.size();
    }
    vi neighbours(int x) {
      vi res;
      FOR(i, sz(m[x])) {
        if (m[x][i])
          res.push_back(i);
      }
      return res;
    }
};





vi dijkstra(Graph g, int source, int dest) {
  vi dist(g.nodes(), 0);
  vi prev(g.nodes(), 0);
  vi q;
  FOR(i, g.nodes()) {
    if (i != source) {
      dist[i] = INT_MAX;
      prev[i] = INT_MAX;
    }
    q.insert(q.begin(), i);
  }
  while (!q.empty()) {
    int min_dist = INT_MAX;
    int min_ind = INT_MAX;
    FOR(i, q.size()) {
      if (dist[q[i]] < min_dist) {
        min_dist = dist[q[i]];
        min_ind = q[i];
      }
    }
    int u = min_ind;
    if (u == INT_MAX)
      break;
    if (u == dest) {
      vi s;
      while (prev[u] != INT_MAX && u != prev[u]) {
        s.push_back(u);
        u = prev[u];
      }
      return s;
    }
    q.erase(find(all(q), u));
    vi v = g.neighbours(u);
    FOR(i, sz(v)) {
      int alt = dist[u] + 1;
      if (alt < dist[v[i]]) {
        dist[v[i]] = alt;
        prev[v[i]] = u;
      }
    }
  }
  return vi (0);
}





vi dijkstra(Digraph g, int source, int dest) {
  vi dist(g.nodes(), 0);
  vi prev(g.nodes(), 0);
  vi q;
  FOR(i, g.nodes()) {
    if (i != source) {
      dist[i] = INT_MAX;
      prev[i] = INT_MAX;
    }
    q.insert(q.begin(), i);
  }
  while (!q.empty()) {
    int min_dist = INT_MAX;
    int min_ind = INT_MAX;
    FOR(i, q.size()) {
      if (dist[q[i]] < min_dist) {
        min_dist = dist[q[i]];
        min_ind = q[i];
      }
    }
    int u = min_ind;
    if (u == INT_MAX)
      break;
    if (u == dest) {
      vi s;
      while (prev[u] != INT_MAX && u != prev[u]) {
        s.push_back(u);
        u = prev[u];
      }
      return s;
    }
    q.erase(find(all(q), u));
    vi v = g.neighbours(u);
    FOR(i, sz(v)) {
      int alt = dist[u] + 1;
      if (alt < dist[v[i]]) {
        dist[v[i]] = alt;
        prev[v[i]] = u;
      }
    }
  }
  return vi (0);
}





vi dijkstra(WeightedGraph g, int source, int dest) {
  vi dist(g.nodes(), 0);
  vi prev(g.nodes(), 0);
  vi q;
  FOR(i, g.nodes()) {
    if (i != source) {
      dist[i] = INT_MAX;
      prev[i] = INT_MAX;
    }
    q.insert(q.begin(), i);
  }
  while (!q.empty()) {
    int min_dist = INT_MAX;
    int min_ind = INT_MAX;
    FOR(i, q.size()) {
      if (dist[q[i]] < min_dist) {
        min_dist = dist[q[i]];
        min_ind = q[i];
      }
    }
    int u = min_ind;
    if (u == INT_MAX)
      break;
    if (u == dest) {
      vi s;
      while (prev[u] != INT_MAX && u != prev[u]) {
        s.push_back(u);
        u = prev[u];
      }
      return s;
    }
    q.erase(find(all(q), u));
    vi v = g.neighbours(u);
    FOR(i, sz(v)) {
      int alt = dist[u] + g.get_edge_value(u, v[i]);
      if (alt < dist[v[i]]) {
        dist[v[i]] = alt;
        prev[v[i]] = u;
      }
    }
  }
  return vi (0);
}





vi dijkstra(WeightedDigraph g, int source, int dest) {
  vi dist(g.nodes(), 0);
  vi prev(g.nodes(), 0);
  vi q;
  FOR(i, g.nodes()) {
    if (i != source) {
      dist[i] = INT_MAX;
      prev[i] = INT_MAX;
    }
    q.insert(q.begin(), i);
  }
  while (!q.empty()) {
    int min_dist = INT_MAX;
    int min_ind = INT_MAX;
    FOR(i, q.size()) {
      if (dist[q[i]] < min_dist) {
        min_dist = dist[q[i]];
        min_ind = q[i];
      }
    }
    int u = min_ind;
    if (u == INT_MAX)
      break;
    if (u == dest) {
      vi s;
      while (prev[u] != INT_MAX && u != prev[u]) {
        s.push_back(u);
        u = prev[u];
      }
      return s;
    }
    q.erase(find(all(q), u));
    vi v = g.neighbours(u);
    for (int i = 0; i < v.size(); i++) {
      int alt = dist[u] + g.get_edge_value(u, v[i]);
      if (alt < dist[v[i]]) {
        dist[v[i]] = alt;
        prev[v[i]] = u;
      }
    }
  }
  return vi (0);
}

pair< vector< vector<int> >, vector< vector<int> > > floydWarshall(Graph g) {
  vector< vector<int> > dist (g.nodes(), vector<int>(g.nodes(), INT_MAX / 2));
  vector< vector<int> > next (g.nodes(), vector<int>(g.nodes(), -1));
  for(int i = 0; i < g.nodes(); i++) {
    dist[i][i] = 0;
  }
  for (int i = 0; i < g.nodes(); i++) {
    vector<int> v = g.neighbours(i);
    for (int j = 0; j < v.size(); j++) {
      dist[i][v[j]] = 1;
      next[i][v[j]] = v[j];
    }
  }
  for (int k = 0; k < g.nodes(); k++) {
    for (int i = 0; i < g.nodes(); i++) {
      for (int j = 0; j < g.nodes(); j++) {
        if (dist[i][k] + dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
          next[i][j] = next[i][k];
        }
      }
    }
  }
  return mp(dist, next);
}

pair< vector< vector<int> >, vector< vector<int> > > floydWarshall(Digraph g) {
  vector< vector<int> > dist (g.nodes(), vector<int>(g.nodes(), INT_MAX / 2));
  vector< vector<int> > next (g.nodes(), vector<int>(g.nodes(), -1));
  for(int i = 0; i < g.nodes(); i++) {
    dist[i][i] = 0;
  }
  for (int i = 0; i < g.nodes(); i++) {
    vector<int> v = g.neighbours(i);
    for (int j = 0; j < v.size(); j++) {
      dist[i][v[j]] = 1;
      next[i][v[j]] = v[j];
    }
  }
  for (int k = 0; k < g.nodes(); k++) {
    for (int i = 0; i < g.nodes(); i++) {
      for (int j = 0; j < g.nodes(); j++) {
        if (dist[i][k] + dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
          next[i][j] = next[i][k];
        }
      }
    }
  }
  return mp(dist, next);
}

pair< vector< vector<int> >, vector< vector<int> > > floydWarshall(WeightedGraph g) {
  vector< vector<int> > dist (g.nodes(), vector<int>(g.nodes(), INT_MAX / 2));
  vector< vector<int> > next (g.nodes(), vector<int>(g.nodes(), -1));
  for(int i = 0; i < g.nodes(); i++) {
    dist[i][i] = 0;
  }
  for (int i = 0; i < g.nodes(); i++) {
    vector<int> v = g.neighbours(i);
    for (int j = 0; j < v.size(); j++) {
      dist[i][v[j]] = g.get_edge_value(i, v[j]);
      next[i][v[j]] = v[j];
    }
  }
  for (int k = 0; k < g.nodes(); k++) {
    for (int i = 0; i < g.nodes(); i++) {
      for (int j = 0; j < g.nodes(); j++) {
        if (dist[i][k] + dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
          next[i][j] = next[i][k];
        }
      }
    }
  }
  return mp(dist, next);
}

pair< vector< vector<int> >, vector< vector<int> > > floydWarshall(WeightedDigraph g) {
  vector< vector<int> > dist (g.nodes(), vector<int>(g.nodes(), INT_MAX / 2));
  vector< vector<int> > next (g.nodes(), vector<int>(g.nodes(), -1));
  for(int i = 0; i < g.nodes(); i++) {
    dist[i][i] = 0;
  }
  for (int i = 0; i < g.nodes(); i++) {
    vector<int> v = g.neighbours(i);
    for (int j = 0; j < v.size(); j++) {
      dist[i][v[j]] = g.get_edge_value(i, v[j]);
      next[i][v[j]] = v[j];
    }
  }
  for (int k = 0; k < g.nodes(); k++) {
    for (int i = 0; i < g.nodes(); i++) {
      for (int j = 0; j < g.nodes(); j++) {
        if (dist[i][k] + dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
          next[i][j] = next[i][k];
        }
      }
    }
  }
  return mp(dist, next);
}

vector<int> pathReconstruct(vector< vector<int> > next, int u, int v) {
  vector<int> path;
  if (next[u][v] == -1)
    return path;
  path.push_back(u);
  while (u != v) {
    u = next[u][v];
    path.push_back(u);
  }
  return path;
}





      

      

      

vi kadane_sum(vi A) {
  int c_max = 0, o_max = 0;
  int low = 0, high = 0;
  vi ret(3);
  FOR(i, sz(A)) {
    c_max += A[i];
    high++;
    if (c_max < 0) {
      c_max = 0;
      low = i;
      high = i;
    }
    o_max = max(c_max, o_max);
  }
  ret[0] = low;
  ret[1] = high;
  ret[2] = o_max;
  return ret;
}





int non_negative_sum(vi A) {
  int sum = 0;
  FOR(i, sz(A)) {
    if (A[i] > 0)
      sum += A[i];
  }
  return sum;
}





bool prime(int n) {
  if (n <= 1)
    return false;
  if (n <= 3)
    return true;
  if (n % 2 == 0 || n % 3 == 0)
    return false;
  for (int i = 5; i <= sqrt(n); i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}





int primes_less_than(int n) {
  int t = 0;
  REP(i, 1, n)
    if (prime(i))
      t++;
  return t;
}

vull eratosthenes(ull n) {
  vull a(n);
  vull primes;
  a.push_back(0);
  a.push_back(0);
  for(ull i = 2; i <= n; i++)
    a[i] = 1;
  ull p = 2;
  while (p*p <= n) {
    ull j = p*p;
    while (j <= n) {
      a[j] = 0;
      j += p;
    }
    while (a[p++] != 1) {}
    primes.push_back(p-1);
  }
  return primes;
}

ull gcd(ull a, ull b)
{
    if (a == 0)
        return b;
    else if (b == 0)
        return a;

    if (a < b)
        return gcd(a, b % a);
    else
        return gcd(b, a % b);
}

vector<string> room;
int n;

void sweep(int c) {
  FOR(i, n) {
    room[i][c] == '0' ? room[i][c] = '1' : room[i][c] = '0';
  }
}

void printBoard() {
  FOR(i, n) {
    cout << room[i] << endl;
  }
}

int cleanRows() {
  int ans = 0;
  FOR(i, n) {
    bool good = true;
    FOR(j, n) {
      if (room[i][j] == '0') {
        good = false;
        break;
      }
    }
    if (good)
      ans++;
  }
  return ans;
}

int main() {
  cin >> n;
  room.resize(n);
  vi columnval(n, 0);
  FOR(i, n) {
    cin >> room[i];
  }
  int c, m = 0;
  FOR(i, n) {
    c = 0;
    FOR(j, n) {
      if (room[i] == room[j]) {
        c++;
      }
    }
    m = max(c, m);
  }
  cout << m << endl;
  
  return 0;
}
