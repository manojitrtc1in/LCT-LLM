






























using namespace std;



















typedef long long ll;
typedef long double ld;
typedef pair < int, int > pi;
typedef pair < ll, ll > pll;
typedef pair < ld, ld > pld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<pld> vpld;
typedef list<int> li;
typedef list<ll> lll;
typedef list<ld> lld;
typedef list<pi> lpi;
typedef list<pll> lpll;
typedef list<pld> lpld;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vld> vvld;
typedef vector<vpi> vvpi;
typedef vector<vpll> vvpll;
typedef vector<vpld> vvpld;
typedef vector<li> vli;
typedef vector<lll> vlll;
typedef vector<lld> vlld;
typedef vector<lpi> vlpi;
typedef vector<lpll> vlpll;
typedef vector<lpld> vlpld;
typedef set<int> si;
typedef set<ll> sll;
typedef set<pi> spi;
typedef set<pll> spll;
typedef vector< list < pair < int, ll > > > AdjacencyLists;
typedef vvll AdjacencyMatrix;


template<class T> inline T sqr(const T &x) { return x * x; }
inline ll sqr(int x){return sqr<ll>(x);}
template<class T>T binpow(const T &a, ll n) { return n == 0 ? 1 : sqr(binpow(a, n / 2))* (n % 2 ? a : 1); }
ll binpow(ll a, ll n, ll modulo) { return n == 0 ? 1 : sqr(binpow(a, n / 2, modulo)) % modulo * (n % 2 ? a : 1) % modulo; }

ll gcd(ll a, ll b, ll &x, ll &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
inline ll phi (ll n) {
    ll result = n;
    for (ll i=2; i*i<=n; ++i)
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    if (n > 1)
        result -= result / n;
    return result;
}
inline vll inverseAll(ll m)
{
    vll r(m);
    r[1] = 1;
    for (int i=2; i<m; ++i)
        r[i] = (m - (m/i) * r[m%i] % m) % m;
    return r;
}
inline ll gcd(ll a, ll b) { return gcd(a, b, a, b); }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
inline ll llrand()
{
    const ll id5 = (sizeof(ll) << 3) - 1;
    const ll id0 = popcount(RAND_MAX);
    ll number = 0;
    
    for (ll id3 = 0; id3 <= id5; id3 += id0)
    {
        number ^= (((ll)rand()) << id3);
    }
    
    return number & numeric_limits<ll>::max();
}
inline ll llrand(ll begin, ll end)
{
    return begin + llrand() % (end - begin);
}

struct Dinic {
    struct Edge {
        int u, v;
        ll cap, flow;
        Edge() {}
        Edge(int u, int v, ll cap): u(u), v(v), cap(cap), flow(0) {}
    };
    
    int N;
    vector<Edge> E;
    vector<vector<int>> g;
    vector<int> d, pt;
    
    Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}
    
    void AddEdge(int u, int v, ll cap) {
        if (u != v) {
            E.emplace_back(Edge(u, v, cap));
            g[u].emplace_back(E.size() - 1);
            E.emplace_back(Edge(v, u, 0));
            g[v].emplace_back(E.size() - 1);
        }
    }
    
    bool BFS(int S, int T) {
        queue<int> q({S});
        fill(d.begin(), d.end(), N + 1);
        d[S] = 0;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            if (u == T) break;
            for (int k: g[u]) {
                Edge &e = E[k];
                if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
                    d[e.v] = d[e.u] + 1;
                    q.emplace(e.v);
                }
            }
        }
        return d[T] != N + 1;
    }
    
    ll DFS(int u, int T, ll flow = -1) {
        if (u == T || flow == 0) return flow;
        for (int &i = pt[u]; i < g[u].size(); ++i) {
            Edge &e = E[g[u][i]];
            Edge &oe = E[g[u][i]^1];
            if (d[e.v] == d[e.u] + 1) {
                ll amt = e.cap - e.flow;
                if (flow != -1 && amt > flow) amt = flow;
                if (ll pushed = DFS(e.v, T, amt)) {
                    e.flow += pushed;
                    oe.flow -= pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }
    
    ll MaxFlow(int S, int T) {
        ll total = 0;
        while (BFS(S, T)) {
            fill(pt.begin(), pt.end(), 0);
            while (ll flow = DFS(S, T))
                total += flow;
        }
        return total;
    }
};

vll Dijkstra(const AdjacencyLists &g, int s)
{
    vll d(SZ(g), numeric_limits<ll>::max() / 2LL);
    priority_queue < pair<ll, int> > q;

    d[s] = 0;
    q.emplace(-0, s);
    
    while (!q.empty())
    {
        while (q.top().first > d[q.top().second]) { q.pop(); }
        int v = q.top().second;
        
        q.pop();
        
        for (const auto &cw : g[v])
        {
            if (d[v] + cw.second < d[cw.first])
            {
                d[cw.first] = d[v] + cw.second;
                q.emplace(-d[cw.first], cw.first);
            }
        }
    }
    
    return d;
}

struct BinarySearchIterator : public std::iterator<std::forward_iterator_tag, bool>
{
    ll value;
    
    typename iterator_traits<BinarySearchIterator>::difference_type operator - (const BinarySearchIterator &it) const { return value - it.value; }
    
    BinarySearchIterator& operator ++() { ++value; return *this; }
    
    bool operator != (const BinarySearchIterator &it) const { return value != it.value; }
    
    bool operator*() const {  return true; }
};

template < int ALPHA >
class id2
{
public:
    static const int id1;
    static const int ROOT;
    
    struct Node
    {
        bool leaf;
        int parent;
        int parentCharacter;
        int link;
        
        int next[ALPHA];
        int go[ALPHA];
        int outputFunction;
        
        Node(int parent = id1, int parentCharacter = ALPHA) :
            leaf(false),
            parent(parent),
            parentCharacter(parentCharacter),
            link(id1),
            outputFunction(id1)
        {
            fill_n(next, ALPHA, id1);
            fill_n(go, ALPHA, id1);
        }
    };
    
    vector<Node> tree = vector<Node>(1);
    
    id2(){}
    id2(int id4)
    {
        tree.reserve(id4);
    }
    
    template < class Iterator >
    void add(int length, const Iterator begin)
    {
        int vertex = ROOT;
        
        for (int i = 0; i < length; ++i)
        {
            if (id1 == tree[vertex].next[begin[i]])
            {
                tree[vertex].next[begin[i]] = SZ(tree);
                tree.push_back(Node(vertex, begin[i]));
            }
            
            vertex = tree[vertex].next[begin[i]];
        }
        
        tree[vertex].leaf = true;
    }
    
    int getLink(int vertex)
    {
        assert(0 <= vertex && vertex < tree.size());
        
        if (id1 == tree[vertex].link)
        {
            if (ROOT == vertex || ROOT == tree[vertex].parent)
            {
                tree[vertex].link = ROOT;
            }
            else
            {
                tree[vertex].link = go(getLink(tree[vertex].parent), tree[vertex].parentCharacter);
            }
        }
        
        return tree[vertex].link;
    }
    
    int go(int vertex, int character)
    {
        assert(0 <= character && character < ALPHA);
        assert(0 <= vertex && vertex < tree.size());
        
        if (id1 == tree[vertex].go[character])
        {
            if (id1 == tree[vertex].next[character])
            {
                tree[vertex].go[character] = ROOT == vertex ? ROOT : go(getLink(vertex), character);
            }
            else
            {
                tree[vertex].go[character] = tree[vertex].next[character];
            }
        }
        
        return tree[vertex].go[character];
    }
    
    int getOutputFunction(int vertex)
    {
        assert(0 <= vertex && vertex < tree.size());
        
        if (id1 == tree[vertex].outputFunction)
        {
            if (tree[vertex].leaf || ROOT == vertex)
            {
                tree[vertex].outputFunction = vertex;
            }
            else
            {
                tree[vertex].outputFunction = getOutputFunction(getLink(vertex));
            }
        }
        
        return tree[vertex].outputFunction;
    }
};

template < int ALPHA > const int id2<ALPHA>::id1 = -1;
template < int ALPHA > const int id2<ALPHA>::ROOT = 0;

struct UnionFind {
    vi parent;
    vi rank;
    UnionFind(int n) : parent(n), rank(n) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int find_set (int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set (parent[v]);
    }
    void union_sets (int a, int b) {
        a = find_set (a);
        b = find_set (b);
        if (a != b) {
            if (rank[a] < rank[b])
                swap (a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                ++rank[a];
        }
    }
};

template < class T >
T assign(const T &a, const T &b) {
    return b;
}

struct SegmentTree {
    int n;
    int h;
    vector<ll> t;
    vector<ll> d;
    
    SegmentTree() {}
    
    SegmentTree(const int n) : n(n), h(sizeof(int) * 8 - __builtin_clz(n)), t(vector<ll>(2 * n, 0)), d(2 * n, 0){}
  
    void apply(int p, ll value) {
      t[p] += value;
      if (p < n) d[p] += value;
    }

    void build(int p) {
      while (p > 1) p >>= 1, t[p] = min(t[p<<1], t[p<<1|1]) + d[p];
    }

    void push(int p) {
      for (int s = h; s > 0; --s) {
        int i = p >> s;
        if (d[i] != 0) {
          apply(i<<1, d[i]);
          apply(i<<1|1, d[i]);
          d[i] = 0;
        }
      }
    }

    void inc(int l, int r, ll value) {
      l += n, r += n;
      int l0 = l, r0 = r;
      for (; l < r; l >>= 1, r >>= 1) {
        if (l&1) apply(l++, value);
        if (r&1) apply(--r, value);
      }
      build(l0);
      build(r0 - 1);
    }

    ll query(int l, int r) {
      l += n, r += n;
      push(l);
      push(r - 1);
      ll res = numeric_limits<ll>::max() / 2;
      for (; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = min(res, t[l++]);
        if (r&1) res = min(t[--r], res);
      }
      return res;
    }
};

ll add(ll a, ll b) {
  return a + b;
}

ll solve(const vi &p, const vll &a) {
  const int n = SZ(p);
  
  vi ip(n);
  
  FI(n) {
    ip[p[i]] = i;
  }
  
  ll answer = accumulate(ALL(a), 0LL);
  SegmentTree st(n + 1);
  ll current = 0;
  
  FI(n){

    cerr << current << " \n"[i + 1 == n];

    st.inc(i, i + 1, current);
    current += a[ip[i]];
  }

  st.inc(n, n + 1, current);
  
  for (int k = 0; k < n - 1; ++k) {
    st.inc(p[k] + 1, n + 1, -a[k]);
    st.inc(0, p[k] + 1, +a[k]);
    ll current = st.query(0, n + 1);
    

    vll expected(1 + n);
    
    for (int v = 0; v <= n; ++v) {
      cerr << st.query(v, v + 1) << " \n"[v == n];
      
      expected[v] = 0;
      for (int i = 0; i < n; ++i) {
        expected[v]  += ((i < k) != (p[i] < v)) * a[i];
      }
    }
    


    

    
    answer = min(current, answer);
  }
  
  return answer;
}


pair<vi, vll> generate() {
  const int n = 2 + rand() % 3;
  vi p(n);
  iota(ALL(p), 0);
  random_shuffle(ALL(p));
  
  vll a(n);
  
  FI(n) {
    a[i] = 1 + rand() % 10;
  }
  
  return {p, a};
}

ll bf(const vi &p, const vll &a) {
  const int n = SZ(p);
  ll answer = accumulate(ALL(a), 0LL);
  
  for (int k = 1; k < n; ++k) {
    for (int v = 0; v <= n; ++v) {
      ll current = 0;

      for (int i = 0; i < n; ++i) {
        current += ((i < k) != (p[i] < v)) * a[i];;
      }
      
      answer = min(answer, current);
    }
  }
  
  return answer;
}

void stress() {
  while (true) {
    const auto &[p, a] = generate();
    
    auto out = solve(p, a);
    auto ans = bf(p, a);
    
    cerr << out << ' ' << ans << endl;
    assert(out == ans);
  }
}


int main(int argc, const char * argv[]) {

  assert(solve({1, 2, 0}, {1, 4, 10}) == 1);
assert(bf({2, 0, 1}, {7, 1, 4}) == 4);
assert(bf({2, 4, 0, 5, 1, 3}, {9, 1, 9, 9, 1, 9}) == 2);
assert(bf({1, 3, 0, 2}, {5, 9, 8, 3}) == 3);
assert(solve({2, 4, 0, 5, 1, 3}, {9, 1, 9, 9, 1, 9}) == 2);
assert(solve({2, 0, 1}, {7, 1, 4}) == 4);
assert(solve({1, 3, 0, 2}, {5, 9, 8, 3}) == 3);
  stress();

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(13);
    cout.setf(ios::fixed);
    srand((unsigned int)time(NULL));

  int n;
  
  while (cin >> n) {
    vi p(n);
    FI(n) {
      cin >> p[i];
      --p[i];
    }
    
    vll a(n);
    FI(n) {
      cin >> a[i];
    }
    
    cout << solve(p, a) << endl;
  }

    return 0;
}
