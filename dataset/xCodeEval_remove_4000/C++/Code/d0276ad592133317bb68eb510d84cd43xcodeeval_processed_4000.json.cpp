






















using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<vi> vvi; 
typedef vector<vl> vvl; 
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<char> vc;

typedef vector<int>::iterator vi_it;
typedef vector<long>::iterator vl_it;
typedef vector<ll>::iterator vll_it;

typedef set<int> si;
typedef set<long> sl;
typedef set<char> sc;
typedef set<int>::iterator si_it;
typedef set<long>::iterator sl_it;
typedef set<string> ss;
typedef set<char> sc;
typedef vector<si> vsi;

typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<pii>::iterator vpii_it;
typedef pair<long,long> pll;
typedef vector<pll> vpll;
typedef map<int,int> mii;
typedef map<string,string> mss;
typedef map<string,long> msl;
typedef map<string,int> msi;
typedef map<long,long> mll;
typedef vector<mll> vmll;
typedef map<char,int> mci;
typedef vector<mci> vmci;
typedef vector<msi> vmsi;
typedef map<char,long> mcl;
typedef pair<char,long> pcl;
typedef vector<pcl> vpcl;
typedef map<char,char> mcc;
typedef pair<char,char> pcc;
typedef vector<pcc> vpcc;




















typedef std::map<std::string, int> M;


































class Graph
{
long _V;
long _E;
vvl _adj;

public:
    Graph()
    {
        _V = _E = 0;
    }
    void readV()
    {
        r(_V);
        _adj.resize(_V);
    }
    void setV(long V)
    {
        _V = V;
        _adj.resize(_V);
    }
    void setE(long E)
    {
        _E = E;
    }
    void readE()
    {
        r(_E);
    }
    long V()
    {
        return _V;
    }
    long E()
    {
        return _E;
    }
    void readEdges()
    {
    long v, w;

        FOR(i,(long)0,_E)
        {
            r(v);
            r(w);
            addEdge(v, w);
        }
    }
    void addEdge(long v, long w)
    {
        _adj[v].insert(_adj[v].begin(),w);
        _adj[w].insert(_adj[w].begin(),v);
    }
    vl adj(long v)
    {
        return _adj[v];
    }
    long degree(long v)
    {
        return sz(_adj[v]);
    }
    long maxDegree()
    {
    long maxD = 0;

        FOR(v,(long)0,_V) maxD = max(maxD,degree(v));
        return maxD;
    }
    long avgDegree()
    {
        return 2 * _E / _V;
    }
    long numberOfSelfLoops()
    {
    long count = 0;

        FOR(v,(long)0,_V) tr(_adj[v],it) if (v == *it) count++;
        return count/2;
    }
    void print()
    {
        cout << _V << " vertices, " << _E << " edges" << endl;
        cout << "max degree : " << maxDegree() << endl;
        cout << "avg degree : " << avgDegree() << endl;
        cout << "number of self loops : " << numberOfSelfLoops() << endl;
        FOR(v,(long)0,_V)
        {
            cout << v << "(" << degree(v) << ") : ";
            tr(_adj[v],it) cout << *it << " ";
            cout << endl;
        }
    }
};

class id5
{
vb _marked;
long _count;

public:
    id5(Graph G, long s)
    {
        _marked.resize(G.V(),false);
        _count = 0;
        dfs(G, s);
    }
    void dfs(Graph G, long v)
    {
        _marked[v] = true;
        _count++;
        vl x = G.adj(v);
        tr(x,it) if (!_marked[*it]) dfs(G, *it);
    }
    bool marked(long w)
    {
        return _marked[w];
    }
    long count()
    {
        return _count;
    }
};

class id6
{
vb _marked;
vl _edgeTo;
long _s;

public:
    id6(Graph G, long s)
    {
        _marked.resize(G.V());
        _edgeTo.resize(G.V());
        _s = s;
        dfs(G, s);
    }
    void dfs(Graph G, long v)
    {
        _marked[v] = true;
        vl x = G.adj(v);
        tr(x,it)
        {
            if (!_marked[*it])
            {
                _edgeTo[*it] = v;
                dfs(G, *it);
            }
        }
    }
    bool hasPathTo(long v)
    {
        return _marked[v];
    }
    vl pathTo(long v)
    {
    vl path;
        
        if (hasPathTo(v))
        {
            for (long x = v; x != _s; x = _edgeTo[x]) path.insert(path.begin(),x);
            path.insert(path.begin(),_s);
        }
        return path;
    }
};

class id4
{
vb _marked;
vl _edgeTo;
long _s;

public:
    id4(Graph G, long s)
    {
        _marked.resize(G.V());
        _edgeTo.resize(G.V());
        _s = s;
        bfs(G, s);
    }
    void bfs(Graph G, long s)
    {
        vl Q;
        _marked[s] = true;
        Q.pb(s);
        while (!Q.empty())
        {
            long v = Q[0];
            Q.erase(Q.begin());
            vl x = G.adj(v);
            tr(x,it)
            {
                if (!_marked[*it])
                {
                    _edgeTo[*it] = v;
                    _marked[*it] = true;
                    Q.pb(*it);
                }
            }
        }
    }
    bool hasPathTo(long v)
    {
        return _marked[v];
    }
    vl pathTo(long v)
    {
    vl path;
        
        if (hasPathTo(v))
        {
            for (long x = v; x != _s; x = _edgeTo[x]) path.insert(path.begin(),x);
            path.insert(path.begin(),_s);
        }
        return path;
    }
};

class CC
{
vb _marked;
vl _id;
long _count;

public:
    CC(Graph G)
    {
        _count = 0;
        _marked.resize(G.V());
        _id.resize(G.V());
        FOR(s,(long)0,G.V())
            if (!_marked[s])
            {
                dfs(G, s);
                _count++;
            }
    }
    void dfs(Graph G, long v)
    {
        _marked[v] = true;
        _id[v] = _count;
        vl x = G.adj(v);
        tr(x,it) if (!_marked[*it]) dfs(G, *it);
    }
    bool connected(long v, long w)
    {
        return _id[v] == _id[w];
    }
    long id(long v)
    {
        return _id[v];
    }
    long count()
    {
        return _count;
    }
};

class Cycle
{
vb _marked;
bool _hasCycle;

public:
    Cycle(Graph G)
    {
        _hasCycle = false;
        _marked.resize(G.V());
        FOR(s,(long)0,G.V()) if (!_marked[s]) dfs(G, s, s);
    }
    void dfs(Graph G, long v, long u)
    {
        _marked[v] = true;
        vl x = G.adj(v);
        tr(x,it)
        {
            if (!_marked[*it]) dfs(G, *it, v);
            else if (*it != u) _hasCycle = true;
        }
    }
    bool hasCycle()
    {
        return _hasCycle;
    }
};

class TwoColor
{
vb _marked;
vb _color;
bool id0;
public:
    TwoColor(Graph G)
    {
        id0 = true;
        _marked.resize(G.V());
        _color.resize(G.V());
        FOR(s,(long)0,G.V()) if (!_marked[s]) dfs(G, s);
    }
    void dfs(Graph G, long v)
    {
        _marked[v] = true;
        vl x = G.adj(v);
        tr(x,it)
            if (!_marked[*it])
            {
                _color[*it] = !_color[v];
                dfs(G, *it);
            }
            else if (_color[*it] == _color[v]) id0 = false;
    }
    bool isBipartite()
    {
        return id0;
    }
    vb color()
    {
        return _color;
    }
};

class SymbolGraph
{
msl _st;
vs _keys;
Graph _G;
long _count;

public:
    SymbolGraph()
    {
        _count = 0;
    }
    void readSymbolPair()
    {
    string a,b;
        
        r(a);
        r(b);
        processSymbolPair(a,b);
    }
    void processSymbolPair(string a, string b)
    {
    long v = _st[a];
    long w = _st[b];

        if (v == 0)
        {
            _count++;
            _keys.pb(a);
            _st[a] = _count;
            v = _count;
        }
        if (w == 0)
        {
            _count++;
            _keys.pb(b);
            _st[b] = _count;
            w = _count;
        }
        _G.setV(_count);
        _G.addEdge(v-1, w-1);
    }
    bool contains(string s)
    {
        return _st[s] > 0;
    }
    long index(string s)
    {
        return _st[s];
    }
    string name(long v)
    {
        return _keys[v];
    }
    long count()
    {
        return _count;
    }
    Graph G()
    {
        return _G;
    }
    void readGraphEdge()
    {
    long E;
        
        r(E);
        _G.setE(E);
    }
};

class Digraph
{
long _V;
long _E;
vvl _adj;

public:
    Digraph()
    {
        _V = _E = 0;
    }
    void readV()
    {
        r(_V);
        _adj.resize(_V);
    }
    void setV(long V)
    {
        _V = V;
        _adj.resize(_V);
    }
    void setE(long E)
    {
        _E = E;
    }
    void readE()
    {
        r(_E);
    }
    long V()
    {
        return _V;
    }
    long E()
    {
        return _E;
    }
    void readEdges()
    {
    long v, w;

        FOR(i,(long)0,_E)
        {
            r(v);
            r(w);
            addEdge(v, w);
        }
    }
    void addEdge(long v, long w)
    {
        _adj[v].insert(_adj[v].begin(),w);
    }
    vl adj(long v)
    {
        return _adj[v];
    }
    long degree(long v)
    {
        return sz(_adj[v]);
    }
    long maxDegree()
    {
    long maxD = 0;

        FOR(v,(long)0,_V) maxD = max(maxD,degree(v));
        return maxD;
    }
    long avgDegree()
    {
        return 2 * _E / _V;
    }
    long numberOfSelfLoops()
    {
    long count = 0;

        FOR(v,(long)0,_V) tr(_adj[v],it) if (v == *it) count++;
        return count/2;
    }
    void print()
    {
        cout << _V << " vertices, " << _E << " edges" << endl;
        cout << "max degree : " << maxDegree() << endl;
        cout << "avg degree : " << avgDegree() << endl;
        cout << "number of self loops : " << numberOfSelfLoops() << endl;
        FOR(v,(long)0,_V)
        {
            cout << v << "(" << degree(v) << ") : ";
            tr(_adj[v],it) cout << *it << " ";
            cout << endl;
        }
    }
    Digraph reverse()
    {
        Digraph R;
        R.setE(_E);
        R.setV(_V);
        FOR(v,(long)0,_V) tr(_adj[v],it) R.addEdge(*it, v);
        return R;
    }
};

class DirectedDFS
{
vb _marked;

public:
    DirectedDFS(Digraph G, long s)
    {
        _marked.resize(G.V());
        dfs(G, s);
    }
    DirectedDFS(Digraph G, vl sources)
    {
        _marked.resize(G.V());
        FOR(s,(long)0,sz(sources)) if (!_marked[sources[s]]) dfs(G, sources[s]);
    }
    void dfs(Digraph G, long v)
    {
        _marked[v] = true;
        vl x = G.adj(v);
        tr(x,it) if (!_marked[*it]) dfs(G, *it);
    }
    bool marked(long v)
    {
        return _marked[v];
    }
};

class DirectedCycle
{
vb _marked;
vl _edgeTo;
vl _cycle;
vb _onStack;

public:
    DirectedCycle(Digraph G)
    {
        _onStack.resize(G.V());
        _edgeTo.resize(G.V());
        _marked.resize(G.V());
        FOR(v,(long)0,G.V()) if (!_marked[v]) dfs(G, v);
    }
    void dfs(Digraph G, long v)
    {
        _onStack[v] = true;
        _marked[v] = true;
        vl x = G.adj(v);
        tr(x,it)
        {
            if (hasCycle()) return;
            else if (!_marked[*it])
            {
                _edgeTo[*it] = v;
                dfs(G, *it);
            }
            else if (_onStack[*it])
            {
                for (long x = v; x != *it; x = _edgeTo[x]) _cycle.insert(_cycle.begin(),x);
                _cycle.insert(_cycle.begin(),*it);
                _cycle.insert(_cycle.begin(),v);
            }
        }
        _onStack[v] = false;
    }
    bool hasCycle()
    {
        return !_cycle.empty();
    }
    vl cycle()
    {
        return _cycle;
    }
};

class id3
{
vb _marked;
vl _pre;
vl _post;
vl _reversePost;

public:
    id3(Digraph G)
    {
        _marked.resize(G.V());
        FOR(v,(long)0,G.V()) if (!_marked[v]) dfs(G, v);
    }
    void dfs(Digraph G, long v)
    {
        _pre.pb(v);
        _marked[v] = true;
        vl x = G.adj(v);
        tr(x,it) if (!_marked[*it]) dfs(G, *it);
        _post.pb(v);
        _reversePost.insert(_reversePost.begin(), v);
    }
    vl pre()
    {
        return _pre;
    }
    vl post()
    {
        return _post;
    }
    vl reversePost()
    {
        return _reversePost;
    }
};

class id1
{
msl _st;
vs _keys;
Digraph _G;
long _count;

public:
    id1()
    {
        _count = 0;
    }
    void readSymbolPair()
    {
    string a,b;
        
        r(a);
        r(b);
        processSymbolPair(a,b);
    }
    void processSymbolPair(string a, string b)
    {
    long v = _st[a];
    long w = _st[b];

        if (v == 0)
        {
            _count++;
            _keys.pb(a);
            _st[a] = _count;
            v = _count;
        }
        if (w == 0)
        {
            _count++;
            _keys.pb(b);
            _st[b] = _count;
            w = _count;
        }
        _G.setV(_count);
        

        _G.addEdge(v-1, w-1);
    }
    bool contains(string s)
    {
        return _st[s] > 0;
    }
    long index(string s)
    {
        return _st[s];
    }
    string name(long v)
    {
        return _keys[v];
    }
    long count()
    {
        return _count;
    }
    Digraph G()
    {
        return _G;
    }
    void readDigraphEdge()
    {
    long E;
        
        r(E);
        _G.setE(E);
    }
};

class id2
{
mcl _st;
vc _keys;
Digraph _G;
long _count;

public:
    id2()
    {
        _count = 0;
    }
    void readSymbolPair()
    {
    char a,b;
        
        r(a);
        r(b);
        processSymbolPair(a,b);
    }
    void processSymbolPair(char a, char b)
    {
    long v = _st[a];
    long w = _st[b];

        if (v == 0)
        {
            _count++;
            _keys.pb(a);
            _st[a] = _count;
            v = _count;
        }
        if (w == 0)
        {
            _count++;
            _keys.pb(b);
            _st[b] = _count;
            w = _count;
        }
        _G.setV(_count);
        

        _G.addEdge(v-1, w-1);
    }
    bool contains(char s)
    {
        return _st[s] > 0;
    }
    long index(char s)
    {
        return _st[s];
    }
    char name(long v)
    {
        return _keys[v];
    }
    long count()
    {
        return _count;
    }
    Digraph G()
    {
        return _G;
    }
    void readDigraphEdge()
    {
    long E;
        
        r(E);
        _G.setE(E);
    }
};

class Topological
{
vl _order;

public:
    Topological(Digraph G)
    {
        DirectedCycle cyclefinder(G);
        if (!cyclefinder.hasCycle())
        {
            id3 dfs(G);
            _order = dfs.reversePost();
        }
    }
    vl order()
    {
        return _order;
    }
    bool isDAG()
    {
        return !_order.empty();
    }
};

void sample()
{
    

    

    
    
    id1 sd;
    long q;
    r(q);
    FOR(i,(long)0,q) sd.readSymbolPair();

    Topological top(sd.G());
    vl x = top.order();
    tr(x,it) wl(sd.name(*it));
}

int main() {
int n;
string q = "abcdefghijklmnopqrstuvwxyz";

    


    r(n);
    vs x(n);
    FOR(i,0,n) { r(x[i]); x[i]+=" "; }

    id2 sd;

    vpcc w;

    FOR(i,1,n)
    {
        FOR(j,0,min(sz(x[i-1]),sz(x[i])))
        {
            if (x[i-1][j]!=x[i][j])
            {
                if (x[i][j]==' ')
                {
                    wl("Impossible");
                    return 0;
                }
                w.pb(pcc(x[i-1][j], x[i][j]));
                break;
            }
            
        }
    }

    tr(w,it) sd.processSymbolPair(it->first,it->second);
    
    Topological top(sd.G());
    vl y = top.order();
    if (sz(w)>0 && !top.isDAG()) wl("Impossible");
    else
    {
        tr(w,it) tr(q,it2) if (it->first==*it2) { q.erase(it2); break; }
        tr(w,it) tr(q,it2) if (it->second==*it2) { q.erase(it2); break; }
        w(q);
        tr(y,it) if (sd.name(*it)!=' ') w(sd.name(*it));
    }

    return 0;
}