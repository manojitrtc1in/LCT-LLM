#define _USE_MATH_DEFINES
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <memory.h>
#include <algorithm>
#include <bitset>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
typedef long long     ll;
typedef unsigned int  UInt;
#define ALL(a)          (a).begin(), (a).end()
#define FOR(i,a,b)      for(int i = a;   i <  (int)(b); ++i)
#define FOR_REV(i,a,b)  for(int i = b-1; i >= (int)(a); --i)
#define FOR_EACH(it,a)  for(remove_reference<decltype(a)>::type::iterator it = (a).begin(); it != (a).end(); ++it)
#define FOR_EACH_REV(it,a) for(remove_reference<decltype(a)>::type::reverse_iterator it = (a).rbegin(); it != (a).rend(); ++it)
#define FOR_EACH_CONST(it,a) for(remove_reference<decltype(a)>::type::const_iterator it = (a).begin(); it != (a).end(); ++it)
#define FOR_EACH_CONST_REV(it,a) for(remove_reference<decltype(a)>::type::const_reverse_iterator it = (a).rbegin(); it != (a).rend(); ++it)
template<class T> inline T   sqr(T v)  { return v * v; }
template<class T> inline int sign(T v) { return v == 0 ? 0 : (v > 0 ? 1 : -1); }
template<class T> inline int round_i(T t) { return int(t < 0 ? t-0.5f : t+0.5f); } 

template<class T> inline int get_bit(T v, int bit_index) { return (v >> bit_index) & 1; } 

template<class T> inline T   gcd(T a, T b) { while(b) { T t = b; b   = a % b; a   = t; } return a; }
#define IN_INT(a)            int a;       is >> a;
#define IN_INT2(a,b)         int a,b;     is >> a >> b;
#define IN_INT3(a,b,c)       int a,b,c;   is >> a >> b >> c;
#define IN_INT4(a,b,c,d)     int a,b,c,d; is >> a >> b >> c >> d;
#define IN_LL(a)             ll a;        is >> a;
#define IN_LL2(a,b)          ll a,b;      is >> a >> b;
#define IN_LL3(a,b,c)        ll a,b,c;    is >> a >> b >> c;
#define IN_LL4(a,b,c,d)      ll a,b,c,d;  is >> a >> b >> c >> d;
#define IN_CHAR(c)           char c;      is >> c;
#define IN_STR(s)            string s;    is >> s;




istream& input(bool release_tie = false)
{
  ios_base::sync_with_stdio(false);
#ifdef INPUT_FROM_FILE
  static ifstream is("CodeForces/input.txt");
  return is;
#endif
  if (release_tie)
    cin.tie(NULL);
  return cin;
}

ostream& output(bool release_tie = false)
{
  cout << setprecision(15);
  if (release_tie)
    cout.tie(NULL);
  return cout;
}

template <typename T>
void init_v2(vector<vector<T>>& v, int lx, int ly, const T& val = T())
{
  v.resize(lx);
  FOR (i,0,lx)
    v[i].resize(ly, val);
};




class GraphAdjacentList
{
public:
  GraphAdjacentList(int vertex_num) : m_adj_list (vertex_num) {}

  void add_edge(int u, int v) 

  {
    m_adj_list[u].push_back(v);
    m_adj_list[v].push_back(u);
  }

  void remove_edge(int u, int v) 

  {
    remove_from_vector(m_adj_list[u], v);
    remove_from_vector(m_adj_list[v], u);
  }

  void load(istream& is, int edges_num) 

  {
    FOR (i, 0, edges_num)
    {
      int u, v;
      is >> u >> v;
      add_edge(u-1, v-1);
    }
  }

  

  size_t             vertexes_num() const                  { return m_adj_list.size(); }
  const vector<int>& adjacent_list(int vertex_index) const { return m_adj_list[vertex_index]; } 


private:
  void remove_from_vector(vector<int>& v, int val) const
  {
    FOR_EACH (it, v)
      if (*it == val)
      {
        *it = v.back();
        v.pop_back();
        break; 

      }
  }

public:
  vector<vector<int>> m_adj_list;
};

template<class WeightT>
class GraphDirWeightedAdjacentList
{
public:
  GraphDirWeightedAdjacentList(int vertex_num) : m_adj_list (vertex_num) {}

  void add_edge(int u, int v, const WeightT& w) 

  {
    m_adj_list[u].push_back(make_pair(v,w));
  }

  void load(istream& is, int edges_num) 

  {
    

    FOR (i, 0, edges_num)
    {
      int u,v;
      WeightT w;
      is>>u>>v>>w;
      add_edge(u-1, v-1, w);
    }
  }

  const vector<pair<int,WeightT>>& adjacent_list(int vertex_index) const { return m_adj_list[vertex_index]; } 


public:
  vector<vector<pair<int,WeightT>>> m_adj_list;
  

};















class FindBridges
{
public:
  FindBridges(const vector<vector<int>>& g)
    : m_g (g)
  {
    const size_t n = g.size();
    m_used.resize(n, false);
    m_tin.resize(n, 0);
    m_fup.resize(n, 0);
    m_timer = 0;
    for (int i=0; i<n; ++i)
      if (!m_used[i])
        dfs(i);
  }

  const vector<pair<int,int>>& bridges() const { return m_bridges; }

private:
  void dfs (int v, int p = -1) 
  {
    m_used[v] = true;
    m_tin[v] = m_fup[v] = m_timer++;
    for (size_t i=0; i<m_g[v].size(); ++i) {
      int to = m_g[v][i];
      if (to == p) continue;
      if (m_used[to])
        m_fup[v] = min (m_fup[v], m_tin[to]);
      else {
        dfs (to, v);
        m_fup[v] = min (m_fup[v], m_fup[to]);
        if (m_fup[to] > m_tin[v])
          m_bridges.push_back(make_pair(v,to));
      }
    }
  }

private:
  const vector<vector<int>>& m_g;
  vector<pair<int,int>>      m_bridges;
  vector<bool>               m_used;
  vector<int>                m_tin, m_fup;
  int                        m_timer;
};










class FindCutpoints
{
public:
  typedef map<int, vector<int>> CutPoints; 


public:
  FindCutpoints(const vector<vector<int>>& g)
    : m_g (g)
  {
    const size_t n = g.size();
    m_tin.resize(n, 0);
    m_fup.resize(n, 0);
    m_used.resize(n, false);
    m_timer = 0;
    FOR (i,0,n)
      if (!m_used[i])
        dfs(i);
  }

  const CutPoints& cutpoints() const { return m_cutpoints; }

private:
  void dfs (int v, int p = -1) 
  {
    m_used[v] = true;
    m_tin[v] = m_fup[v] = m_timer++;

    map<int,int> time_to_region;
    int regions_num = p >= 0 ? 1:0;

    for (size_t i = 0; i < m_g[v].size(); ++i) {
      int to = m_g[v][i];
      if (to == p) continue;
      if (m_used[to])
        m_fup[v] = min (m_fup[v], m_tin[to]);
      else 
      {
        dfs (to, v);
        m_fup[v] = min (m_fup[v], m_fup[to]);
        time_to_region[m_tin[to]] = p >= 0 ? (m_fup[to] >= m_tin[v] ? regions_num++ : 0) : regions_num++;
      }
    }

    if (regions_num > 1)
    {
      vector<int>& regions = m_cutpoints[v];
      regions.resize(m_g[v].size());
      for (size_t i = 0; i < m_g[v].size(); ++i) 
      {
        int to = m_g[v][i];
        regions[i] = m_tin[to] < m_tin[v] ? 0 : (--time_to_region.upper_bound(m_tin[to]))->second;
      }
    }
  }

private:
  const vector<vector<int>>& m_g;
  CutPoints                  m_cutpoints;
  vector<bool>               m_used;
  vector<int>                m_tin, m_fup;
  int                        m_timer;
};

template<class EdgeFlow, class EdgeCost>
class MinCostFlow
{
public:
  MinCostFlow (const GraphDirWeightedAdjacentList<pair<EdgeFlow, EdgeCost>>& g_orig, const size_t s, const size_t t, const EdgeFlow flow_max)
  {
    const EdgeCost INF = std::numeric_limits<EdgeCost>::max(); 

    const size_t n = g_orig.m_adj_list.size();
    g.resize(n);
    edge_indexes.resize(n);
    FOR (i,0,n)
      FOR_EACH_CONST (edge_it, g_orig.adjacent_list(i))
      add_rib(g, i, edge_it->first, edge_it->second.first, edge_it->second.second);

    m_flow = 0;
    m_cost = 0;
    while (m_flow < flow_max) 
    {
      vector<int> id (n, 0);
      vector<EdgeCost> d (n, INF);
      vector<int> q (n);
      vector<int> p (n);
      vector<size_t> p_rib (n);
      int qh=0, qt=0;
      q[qt++] = s;
      d[s] = 0;
      while (qh != qt) {
        int v = q[qh++];
        id[v] = 2;
        if (qh == n) qh = 0;
        for (size_t i=0; i<g[v].size(); ++i) {
          Rib & r = g[v][i];
          if (r.f < r.u && d[v] != INF && d[v] + r.c < d[r.b]) 
          {
            d[r.b] = d[v] + r.c;
            if (id[r.b] == 0) {
              q[qt++] = r.b;
              if (qt == n) qt = 0;
            }
            else if (id[r.b] == 2) {
              if (--qh == -1) qh = n-1;
              q[qh] = r.b;
            }
            id[r.b] = 1;
            p[r.b] = v;
            p_rib[r.b] = i;
          }
        }
      }
      if (d[t] == INF) break;
      EdgeFlow addflow = flow_max - m_flow;
      for (int v=t; v!=s; v=p[v]) {
        int pv = p[v]; size_t pr = p_rib[v];
        addflow = min (addflow, g[pv][pr].u - g[pv][pr].f);
      }
      for (int v=t; v!=s; v=p[v]) {
        int pv = p[v]; size_t pr = p_rib[v], r = g[pv][pr].back;
        g[pv][pr].f += addflow;
        g[v][r].f -= addflow;
        m_cost += g[pv][pr].c * addflow;
      }
      m_flow += addflow;
    }
  }

public:
  const EdgeFlow& flow() const {return m_flow;}
  const EdgeCost& cost() const {return m_cost;}
  const EdgeFlow& flow(size_t v, size_t edge_index) const { return g[v][edge_indexes[v][edge_index]].f; }

private:
  struct Rib;
  void add_rib (vector<vector<Rib>>& g, const size_t a, const size_t b, const EdgeFlow& u, const EdgeCost& c) {
    Rib r1 = { b,  c, u, 0, g[b].size() };
    Rib r2 = { a, -c, 0, 0, g[a].size() };
    edge_indexes[a].push_back(g[a].size());
    g[a].push_back (r1);
    g[b].push_back (r2);
  }

private:
  struct Rib {
    size_t b;
    EdgeCost c;
    EdgeFlow u;  

    EdgeFlow f;  

    size_t back; 

  };

  vector<vector<Rib>> g;
  vector<vector<size_t>> edge_indexes;
  EdgeFlow m_flow;
  EdgeCost m_cost;
};







































































































































































































































































typedef pair<vector<int>,int> Group; 

bool err = false;

Group dfsx(const GraphAdjacentList& g, int v, int p, vector<int>& nx,vector<Group>& grx,vector<int>& vtogx)
{
  Group gfree;
  gfree.first.push_back(v);
  FOR_EACH_CONST (it, g.adjacent_list(v))
  {
    int to = *it;
    if (to != p)
    {
      Group g1 = dfsx (g,to,v,nx,grx,vtogx);
      gfree.second += g1.second;
      gfree.first.insert(gfree.first.end(), ALL(g1.first));
    }
  }
  if (nx[v]>=0)
  {
    grx.push_back(Group(gfree.first,nx[v] - gfree.second));
    if (grx.back().first.size() < grx.back().second || grx.back().second < 0)
      err = true;
    FOR_EACH (it,grx.back().first)
      vtogx[*it] = grx.size()-1;
    gfree.first.clear();
    gfree.second = nx[v];
  }
  return gfree;
}


void main()
{
  istream& is = input();
  ostream& os = output();

  IN_INT3(n,x,y);
  vector<int> nx,ny;
  vector<Group> grx,gry;
  vector<int> vtogx,vtogy(n,-1);
  nx.resize(n,-1);
  ny.resize(n,-1);
  vtogx.resize(n,-1);
  --x,--y;
  vector<int> a(n);
  FOR (i,0,n)
    is >> a[i];


  GraphAdjacentList gx(n),gy(n);
  gx.load(is,n-1);
  gy.load(is,n-1);

  IN_INT(qx);
  FOR (i,0,qx)
  {
    IN_INT2(k,x);;
    --k;
    nx[k]=x;
  }

  IN_INT(qy);
  FOR (i,0,qy)
  {
    IN_INT2(k,x);;
    --k;
    ny[k]=x;
  }

  dfsx(gx,x,-1,nx,grx,vtogx);
  dfsx(gy,y,-1,ny,gry,vtogy);

  if (err||nx[x]!=ny[y])
  {
    os<<-1;
    return;
  }

  GraphDirWeightedAdjacentList<pair<int,int>> g(2+n+grx.size()+gry.size());
  FOR (i,0,grx.size())
  {
    g.add_edge(0,2 + i,make_pair(grx[i].second,0));
    FOR_EACH (it,grx[i].first)
      g.add_edge(2 + i,2+grx.size()+gry.size()+*it,make_pair(1,-a[*it]));
  }
  FOR (i,0,gry.size())
  {
    g.add_edge(2 + grx.size() + i,1,make_pair(gry[i].second,0));
    FOR_EACH (it,gry[i].first)
      g.add_edge(2+grx.size()+gry.size()+*it, 2 + grx.size() + i,make_pair(1,0));
  }


  MinCostFlow<int,int> flow (g, 0, 1, n);
  if (flow.flow() == nx[x])
    os<<-flow.cost();
  else
    os<<-1;
}


































