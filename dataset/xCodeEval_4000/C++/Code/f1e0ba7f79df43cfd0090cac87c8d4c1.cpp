#include <algorithm>
#include <array>
#include <bitset>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstdint>
#include <deque>
#include <float.h>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MC_DIV 1048576
#define MC_WIDTH 7



typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<vi> vvi; 
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<char> vc;

typedef set<int> si;
typedef set<char> sc;
typedef set<string> ss;
typedef set<char> sc;
typedef vector<si> vsi;

typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<pii>::iterator vpii_it;
typedef map<int,int> mii;
typedef map<string,string> mss;
typedef map<string,int> msi;
typedef map<char,int> mci;
typedef vector<mci> vmci;
typedef vector<msi> vmsi;
typedef map<char,char> mcc;
typedef pair<char,char> pcc;
typedef vector<pcc> vpcc;

#define sz(a) int((a).size()) 
#define sl(a) int((a).length()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define rall(c) (c).rbegin(),(c).rend() 
#define tr(container, it) for (auto it = container.begin(); it != container.end(); it++) 
#define rtr(container, it) for (auto it = container.rbegin(); it != container.rend(); it++) 
#define exist(c,x) ((c).find(x) != (c).end()) 
#define existv(c,x) (find(all(c),x) != (c).end())
#define loc(c,x) ((c).find(x) - (c).begin()) 
#define locv(c,x) (find(all(c),x) - (c).begin())
#define wl(x) (cout << (x) << endl)
#define w(x) (cout << (x))
#define r(x) (cin >> x);
#define FOR(i,a,b) for (auto i = (a); i < (b); i++)
#define RFOR(i,a,b) for (auto i = (a); i > (b); i--)
#define PP(x) tr(x,it) cout << it->first << " " << it->second << endl
#define mp(x,y) make_pair((x),(y))
#define fi first
#define se second

clock_t start = clock();






































typedef double Key;
#define KEY_MAX DBL_MAX

class IndexMinPQ
{
int _N;
vi _pq;
vi _qp;
vector<Key> _keys;

public:
    IndexMinPQ()
    {
    }
    IndexMinPQ(const int &maxN)
    {
        _N = 0;
        _keys.resize(maxN + 1);
        _pq.resize(maxN + 1);
        _qp.resize(maxN + 1, -1);
    }
    int size()
    {
        return _N;
    }
    bool isEmpty()
    {
        return _N == 0;
    }
    bool contains(const int &k)
    {
        return _qp[k] != -1;
    }
    void insert(const int &k, const Key &key)
    {
        _N++;
        _qp[k] = _N;
        _pq[_N] = k;
        _keys[k] = key;
        swim(_N);
    }
    void change(int &i, const Key &key)
    {
        _keys[i] = key;
        swim(_qp[i]);
        sink(_qp[i]);
    }
    int delMin()
    {
        int indexOfMin = _pq[1];
        exch(1, _N--);
        sink(1);
        _qp[indexOfMin] = -1;
        _keys[_pq[_N+1]] = NULL;
        _pq[_N+1] = -1;
        return indexOfMin;
    }
    void swim(int k)
    {
        while (k > 1 && greater(k/2,k))
        {
            exch(k, k/2);
            k = k/2;
        }
    }
    bool greater(const int &i, const int &j)
    {
        return _keys[_pq[i]] > _keys[_pq[j]];
    }
    void exch(const int &i, const int &j)
    {
        swap(_pq[i],_pq[j]);
        _qp[_pq[i]] = i;
        _qp[_pq[j]] = j;
    }
    void sink(int k)
    {
        while (2*k <= _N)
        {
            int j = 2*k;
            if (j < _N && greater(j, j+1)) j++;
            if (!greater(k, j)) break;
            exch(k, j);
            k = j;
        }
    }
};

class DirectedEdge
{
int _v;
int _w;
Key _weight;

public:
    DirectedEdge()
    {
        _v = _w = -1;
        _weight = 0;
    }
    DirectedEdge(const int &v, const int &w, const Key &weight)
    {
        _v = v;
        _w = w;
        _weight = weight;
    }
    Key weight()
    {
        return _weight;
    }
    int from() const
    {
        return _v;
    }
    int to()
    {
        return _w;
    }
    void print()
    {
        cout << _v << "->" << _w << " " << _weight;
    }
};

class EdgeWeightedDigraph
{
int _V;
int _E;
vector<vector<DirectedEdge>> _adj;

public:
    EdgeWeightedDigraph(const int &V)
    {
        _V = V;
        _E = 0;
        _adj.resize(V);
    }
    int V() const
    {
        return _V;
    }
    int E()
    {
        return _E;
    }
    void addEdge(const DirectedEdge &e)
    {
        _adj[e.from()].pb(e);
        _E++;
    }
    vector<DirectedEdge> adj(const int &v) const
    {
        return _adj[v];
    }
};

class DijkstraSP
{
vector<DirectedEdge> _edgeTo;
vector<Key> _distTo;
IndexMinPQ _pq;

public:
    DijkstraSP()
    {
    }
    DijkstraSP(const EdgeWeightedDigraph &G, const int &s)
    {
        _edgeTo.resize(G.V());
        _distTo.resize(G.V(),KEY_MAX);
        _pq = IndexMinPQ(G.V());
        _distTo[s] = 0;
        _pq.insert(s, 0);
        while (!_pq.isEmpty()) relax(G, _pq.delMin());
    }
    void relax(const EdgeWeightedDigraph &G, const int &v)
    {
        vector<DirectedEdge> e = G.adj(v);
        tr(e,it)
        {
            int w = it->to();
            if (_distTo[w] - _distTo[v] > it->weight())
            

            {
                _distTo[w] = _distTo[v] + it->weight();
                

                _edgeTo[w] = *it;
                

                if (_pq.contains(w)) _pq.change(w, _distTo[w]);
                else _pq.insert(w, _distTo[w]);
            }
        }
    }
    Key distTo(const int &v)
    {
        return _distTo[v];
    }
    bool hasPathTo(const int &v)
    {
        return _distTo[v] < KEY_MAX;
    }
    vector<DirectedEdge> pathTo(const int &v)
    {
    vector<DirectedEdge> path;

        if (hasPathTo(v)) for (DirectedEdge e = _edgeTo[v]; e.from()!=-1; e = _edgeTo[e.from()]) path.pb(e);
        return path;
    }
};

class Graph
{
int _V;
int _E;
vvi _adj;

public:
    Graph(const int &V)
    {
        _V = V;
        _E = 0;
        _adj.resize(V);
    }
    int V() const
    {
        return _V;
    }
    int E()
    {
        return _E;
    }
    void addEdge(const int &v, const int &w)
    {
        _adj[v].pb(w);
        _adj[w].pb(v);
        _E++;
    }
    vi adj(const int &v) const
    {
        return _adj[v];
    }
};

class BreadthFirstPaths
{
vb _marked;
vi _edgeTo;
int _s;

public:
    BreadthFirstPaths(const Graph &G, const int &s)
    {
        _marked.resize(G.V());
        _edgeTo.resize(G.V());
        _s = s;
        bfs(G, s);
    }
    void bfs(const Graph &G, const int &s)
    {
        vi queue;
        _marked[s] = true;
        queue.pb(s);
        while (!queue.empty())
        {
            int v = queue[0];
            queue.erase(queue.begin());
            vi x = G.adj(v);
            tr(x,it)
            {
                if (!_marked[*it])
                {
                    _edgeTo[*it] = v;
                    _marked[*it] = true;
                    queue.pb(*it);
                }
            }
        }
    }
    bool hasPathTo(const int &v)
    {
        return _marked[v];
    }
    vi pathTo(const int &v)
    {
    vi path;

        if (hasPathTo(v))
        {
            for (int x = v; x != _s; x = _edgeTo[x]) path.pb(x);
            path.pb(_s);
        }
        return path;
    }
};

class Edge
{
int _v;
int _w;
Key _weight;

public:
    Edge()
    {
        _v = _w = -1;
        _weight = 0;
    }
    Edge(const int &v, const int &w, const Key &weight)
    {
        _v = v;
        _w = w;
        _weight = weight;
    }
    Key weight() const
    {
        return _weight;
    }
    int either() const
    {
        return _v;
    }
    int other(const int &vertex) const
    {
        if (vertex == _v) return _w;
        else if (vertex == _w) return _v;
        else throw "Inconsistent edge";
    }
};

class EdgeWeightedGraph
{
int _V;
int _E;
vector<vector<Edge>> _adj;

public:
    EdgeWeightedGraph(const int &V)
    {
        _V = V;
        _E = 0;
        _adj.resize(V);
    }
    int V() const
    {
        return _V;
    }
    int E()
    {
        return _E;
    }
    void addEdge(const Edge &e)
    {
        _adj[e.either()].pb(e);
        _adj[e.other(e.either())].pb(e);
        _E++;
    }
    vector<Edge> adj(const int &v) const
    {
        return _adj[v];
    }
};

class PrimMST
{
vector<Edge> _edgeTo;
vector<Key> _distTo;
vb _marked;
IndexMinPQ _pq;

public:
    PrimMST(const EdgeWeightedGraph &G)
    {
        _edgeTo.resize(G.V());
        _distTo.resize(G.V(),KEY_MAX);
        _marked.resize(G.V());
        _pq = IndexMinPQ(G.V());
        _distTo[0] = 0;
        _pq.insert(0, 0);
        while (!_pq.isEmpty()) visit(G, _pq.delMin());
    }
    void visit(const EdgeWeightedGraph &G, const int &v)
    {
        _marked[v] = true;
        vector<Edge> x = G.adj(v);
        tr(x,it)
        {
            int w = it->other(v);
            if (_marked[w]) continue;
            if (it->weight() < _distTo[w])
            {
                _edgeTo[w] = *it;
                _distTo[w] = it->weight();
                if (_pq.contains(w)) _pq.change(w, _distTo[w]);
                else _pq.insert(w, _distTo[w]);
            }
        }
    }
    Key weight()
    {
        Key tw = 0;
        FOR(v,1,sz(_edgeTo)) tw += _edgeTo[v].weight();
        return tw;
    }
};

class DijkstraAllPairsSP
{
vector<DijkstraSP> _all;

public:
    DijkstraAllPairsSP(const EdgeWeightedDigraph &G)
    {
        _all.resize(G.V());
        FOR(v,0,G.V()) _all[v] = DijkstraSP(G,v);
    }
    vector<DirectedEdge> path(const int &s, const int &t)
    {
        return _all[s].pathTo(t);
    }
    bool hasPathTo(const int &s, const int &t)
    {
        return _all[s].hasPathTo(t);
    }
    Key dist(const int &s, const int &t)
    {
        return _all[s].distTo(t);
    }
};

class TwoColor
{
vb _marked;
vb _color;
bool _isTwoColorable;

public:
    TwoColor(const Graph &G)
    {
        _isTwoColorable = true;
        _marked.resize(G.V());
        _color.resize(G.V());
        FOR(s,0,G.V()) if (!_marked[s]) dfs(G, s);
    }
    void dfs(const Graph &G, const int &v)
    {
        _marked[v] = true;
        vi x = G.adj(v);
        tr(x,it)
        {
            if (!_marked[*it])
            {
                _color[*it] = !_color[v];
                dfs(G, *it);
            }
            else if (_color[*it] == _color[v]) _isTwoColorable = false;
        }
    }
    bool isBipartite()
    {
        return _isTwoColorable;
    }
};

class CC
{
vb _marked;
vi _id;
int _count;
vi _counts;

public:
    CC(const Graph &G)
    {
        _count = 0;
        _marked.resize(G.V());
        _id.resize(G.V());
        _counts.resize(G.V());
        FOR(s,0,G.V())
        {
            if (!_marked[s])
            {
                dfs(G, s);
                _count++;
            }
        }
    }
    void dfs(const Graph &G, const int &v)
    {
        _marked[v] = true;
        _id[v] = _count;
        _counts[_count]++;
        vi x = G.adj(v);
        tr(x,it) if (!_marked[*it]) dfs(G, *it);
    }
    bool connected(const int &v, const int &w)
    {
        return _id[v] == _id[w];
    }
    int id(const int &v)
    {
        return _id[v];
    }
    int count()
    {
        return _count;
    }
    vi counts()
    {
        return _counts;
    }
};

class Cycle
{
vb _marked;
bool _hasCycle;
int _cycleCount;

public:
    Cycle(const Graph &G)
    {
        _cycleCount = 0;
        _hasCycle = false;
        _marked.resize(G.V());
        FOR(s,0,G.V()) if (!_marked[s]) dfs(G, s, s);
    }
    void dfs(const Graph &G, const int &v, const int &u)
    {
        _marked[v] = true;
        vi x = G.adj(v);
        tr(x,it) if (!_marked[*it]) dfs(G, *it, v);
        else if (*it != u) { _cycleCount++; _hasCycle = true; }
    }
    bool hasCycle()
    {
        return _hasCycle;
    }
    int cycleCount()
    {
        return _cycleCount;
    }
};

class Digraph
{
int _V;
int _E;
vvi _adj;

public:
    Digraph(const int &V)
    {
        _V = V;
        _E = 0;
        _adj.resize(V);
    }
    int V() const
    {
        return _V;
    }
    int E()
    {
        return _E;
    }
    void addEdge(const int &v, const int &w)
    {
        _adj[v].pb(w);
        _E++;
    }
    vi adj(const int &v) const
    {
        return _adj[v];
    }
    Digraph reverse() const
    {
        Digraph R(_V);
        FOR(v,0,_V) tr(_adj[v],it) R.addEdge(*it, v);
        return R;
    }
    void print()
    {
        cout << _V << " vertices, " << _E << " edges" << endl;
        FOR(v,0,_V)
        {
            tr(_adj[v],it) cout << *it << " ";
            cout << endl;
        }
    }
};

class DepthFirstOrder
{
vb _marked;
vi _pre;
vi _post;
vi _reversePost;

public:
    DepthFirstOrder(const Digraph &G)
    {
        _marked.resize(G.V());
        FOR(v,0,G.V()) if (!_marked[v]) dfs(G, v);
    }
    void dfs(const Digraph &G, const int &v)
    {
        _pre.pb(v);
        _marked[v] = true;
        vi x = G.adj(v);
        tr(x,it) if (!_marked[*it]) dfs(G, *it);
        _post.pb(v);
        _reversePost.insert(_reversePost.begin(), v);

    }
    vi pre()
    {
        return _pre;
    }
    vi post()
    {
        return _post;
    }
    vi reversePost()
    {
        return _reversePost;
    }
};

class KosarajuSCC
{
vb _marked;
vi _id;
int _count;

public:
    KosarajuSCC(const Digraph &G)
    {
        _count = 0;
        _marked.resize(G.V());
        _id.resize(G.V());
        DepthFirstOrder order(G.reverse());
        vi x = order.reversePost();
        tr(x,it) if (!_marked[*it]) { dfs(G, *it); _count++; }
    }
    void dfs(Digraph G, int v)
    {
        _marked[v] = true;
        _id[v] = _count;
        vi x = G.adj(v);
        tr(x,it) if (!_marked[*it]) dfs(G, *it);
    }
    bool stronglyConnected(const int &v, const int &w)
    {
        return _id[v] == _id[w];
    }
    int id(const int &v)
    {
        return _id[v];
    }
    int count()
    {
        return _count;
    }
};

class DepthFirstPaths
{
vb _marked;
vi _edgeTo;
int _s;

public:
    DepthFirstPaths(const Graph &G, const int &s)
    {
        _marked.resize(G.V());
        _edgeTo.resize(G.V());
        _s = s;
        dfs(G, s);
    }
    void dfs(const Graph &G, const int &v)
    {
        _marked[v] = true;
        vi x = G.adj(v);
        tr(x,it) if (!_marked[*it])
        {
            _edgeTo[*it] = v;
            dfs(G, *it);
        }
    }
    bool hasPathTo(const int &v)
    {
        return _marked[v];
    }
    vi pathTo(const int &v)
    {
    vi path;

        if (hasPathTo(v))
        {
            for (int x = v; x != _s; x = _edgeTo[x]) path.pb(x);
            path.pb(_s);
        }
    return path;
    }
};

map<pii,int> xx;
vi res;

class DepthFirstPaths2
{
vb _marked;
vi _edgeTo;
int _s;

public:
    DepthFirstPaths2(const Graph &G, const int &s)
    {
        _marked.resize(G.V());
        _edgeTo.resize(G.V());
        _s = s;
        dfs(G, s, s);
    }
    bool dfs(const Graph &G, const int &w, const int &v)
    {
    bool c;

        _marked[v] = true;
        vi x = G.adj(v);
        c=false;
        tr(x,it) if (!_marked[*it])
        {
            _edgeTo[*it] = v;
            if (dfs(G, v, *it)) c=true;
        }
        if (!c && xx[mp(v,w)]) res.pb(v);
        return c || xx[mp(v,w)];
    }
    bool hasPathTo(const int &v)
    {
        return _marked[v];
    }
    vi pathTo(const int &v)
    {
    vi path;

        if (hasPathTo(v))
        {
            for (int x = v; x != _s; x = _edgeTo[x]) path.pb(x);
            path.pb(_s);
        }
    return path;
    }
};

int main() {
int n,a,b,c;

    #ifndef ONLINE_JUDGE
        FILE *in, *out;freopen_s(&in, "in.txt", "r", stdin);freopen_s(&out, "out.txt", "w", stdout);
    #endif

    r(n);
    Graph g(n);
    FOR(i,0,n-1)
    {
        r(a);r(b);r(c);
        g.addEdge(--a,--b);
        if (c==2) xx[mp(a,b)]=xx[mp(b,a)]=1;
    }
    DepthFirstPaths2 dfp(g,0);
    wl(sz(res));
    tr(res,it) cout << 1+*it << " ";

    
    return 0;
}
