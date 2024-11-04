





using namespace std;
const long long N = 3e5+1, M = 101, INF = 1e9+1;























 

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
typedef vvll matrix; 
 


 
template<class T> inline T sqr(const T &x) { return x * x; }
inline ll sqr(int x){return sqr<ll>(x);}
template<class T>T binpow(const T &a, ll n) { return n == 0 ? 1 : sqr(binpow(a, n / 2))* (n % 2 ? a : 1); }
ll binpow(ll a, ll n, ll modulo) { return n == 0 ? 1 : sqr(binpow(a, n / 2, modulo)) % modulo * (n % 2 ? a : 1) % modulo; }



int add(int x, int y) {
    x += y;
    if (x >= MOD) return x - MOD;
    return x;
}
int sub(int x, int y) {
    x -= y;
    if (x < 0) return x + MOD;
    return x;
}
int mult(int x, int y) {
    return ((ll)x * y) % MOD;
}
int bin_pow(int x, int p) {
    if (p == 0) return 1;
    if (p & 1) return mult(x, bin_pow(x, p - 1));
    return bin_pow(mult(x, x), p / 2);
}
int rev(int x) {
    return bin_pow(x, MOD - 2);
}
 
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




inline ll llrand()
{
    const ll id9 = (sizeof(ll) << 3) - 1;
    const ll id1 = popcount(RAND_MAX);
    ll number = 0;
    
    for (ll id6 = 0; id6 <= id9; id6 += id1)
    {
        number ^= (((ll)rand()) << id6);
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
class id5
{
public:
    static const int id4;
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
        
        Node(int parent = id4, int parentCharacter = ALPHA) :
            leaf(false),
            parent(parent),
            parentCharacter(parentCharacter),
            link(id4),
            outputFunction(id4)
        {
            fill_n(next, ALPHA, id4);
            fill_n(go, ALPHA, id4);
        }
    };
    
    vector<Node> tree = vector<Node>(1);
    
    id5(){}
    id5(int id7)
    {
        tree.reserve(id7);
    }
    
    template < class Iterator >
    void add(int length, const Iterator begin)
    {
        int vertex = ROOT;
        
        for (int i = 0; i < length; ++i)
        {
            if (id4 == tree[vertex].next[begin[i]])
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
        
        if (id4 == tree[vertex].link)
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
        
        if (id4 == tree[vertex].go[character])
        {
            if (id4 == tree[vertex].next[character])
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
        
        if (id4 == tree[vertex].outputFunction)
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
 
template < int ALPHA > const int id5<ALPHA>::id4 = -1;
template < int ALPHA > const int id5<ALPHA>::ROOT = 0;
 
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
 
template < class T >
struct SegmentTree {
    int n;
    vector<T> t;
    function<T(const T&, const T&)> operation;
    T default_value;
    function<T(const T&, const T&)> modification;
    
    SegmentTree() {}
    
    SegmentTree(const int n,
                const function<T(T, T)> &operation,
                const T &default_value=T(),
                const function<T(T, T)> &modification=assign<T>
    ) : SegmentTree(vector<T>(n, default_value), operation, default_value, modification)
    {}
    
    SegmentTree(const vector<T> &a,
                const function<T(T, T)> &operation,
                const T &default_value=T(),
                const function<T(T, T)> &modification=assign<T>
    ) :
            n((int)a.size()),
            t(n << 1),
            operation(operation),
            default_value(default_value),
            modification(modification)
    {
        copy(a.begin(), a.end(), t.begin() + n);
        
        for (int i = n - 1; i > 0; --i) t[i] = operation(t[i<<1], t[i<<1|1]);
    }
    
    void modify(int p, T value) {  

        p += n;
        
        for (t[p] = modification(t[p], value); p > 1; p >>= 1) t[p>>1] = operation(t[p], t[p^1]);
    }
    
    T query(int l, int r) const {  

        T res = default_value;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = operation(res, t[l++]);
            if (r&1) res = operation(res, t[--r]);
        }
        return res;
    }
};






struct point 
{ 
    ll x, y; 
    point(){}
    point(ll _x, ll _y) { x = _x; y = _y; }
    const point operator - (point _b) { return point(x-_b.x, y-_b.y); }
    point operator + (const point &a) const {return point(x + a.x, y + a.y);}
    int operator * (const point &a) const {return x * a.y - y * a.x;}
    const friend bool operator < (const point _c, const point _d)
    {   return _c.x < _d.x || _c.x == _d.x && _c.y < _d.y;  }
};





struct triple 
{
    ll x, y, z;
    triple(){}
    triple(ll _x, ll _y, ll _z) { x = _x; y = _y; z = _z; } 
    const triple operator+(triple _c) { return triple(x+_c.x, y+_c.y, z+_c.z); }
    const friend bool operator<(const triple _c, const triple _d)
    {   return _c.x < _d.x || _c.x == _d.x && _c.y < _d.y || _c.x == _d.x && _c.y == _d.y && _c.z < _d.z;  }
}; 








struct line
{
    ld a, b, c;
    line(){}
    line(point p1, point p2)
    {
        a = p2.y - p1.y;
        b = p1.x - p2.x;
        c = -a * p2.x - b * p2.y;
    }

    void norm()
    {
        ld d = sqrt(a*a + b*b);
        a /= d; b /= d; c /= d;
    }

    ld dist(point p)
    {
        norm();
        return abs(a*p.x+b*p.y+c);
    }

    point projection(point p)
    {
        ld d = dist(p);
        return point(p.x + a * d, p.y + b * d);
    }
};

const matrix operator*(matrix a, matrix b) 
{
    

    ll na = a.size(), nb = b.size(), 
    ma = a[0].size(), mb = b[0].size();
    matrix c(na, (vector <ll> (mb)));
    for (int i = 0; i < nb; i++)
        if (na != b[i].size())
            return c;

    for (int i = 0; i < na; i++)
        if (nb != a[i].size())
            return c;
    
    for (int i = 0; i < ma; i++)
        for (int j = 0; j < nb; j++)
            for (int k = 0; k < na; k++)
                c[i][j] += a[i][k] * b[k][j];

    return c; 
}

ll mul(ll a, ll b) 
{
    ll q = ld(a) * b / MOD;
    ll result = a * b - q * MOD;
    while (result < 0)
        result += MOD;
    while (result >= MOD)
        result -= MOD;

    return result;
}



ll pow(ll a, ll n) 
{



    ll res = 1;
    while (n) 
    {
        if (n & 1) res *= a;
        a *= a; n >>= 1; 

    }

    return res;
}



matrix pow(matrix a, ll n)
{
    matrix res(2, vector <ll> (2));
    res[0][0] = res[0][1] = res[1][0] = 1;
    while (n)
    {
        if (n & 1) res = res * a;
        a = a * a; n >>= 1;
    }

    return res;
}

ll gcd(ll a, ll b) 
{
    while (a > 0 && b > 0) 
    {
        if (b > a) swap(a, b);
        a %= b;
    }
    
    return a + b;
}

ll lcm(ll a, ll b) 
{ 
    ll g = gcd(a, b);
    if (!g) g++;
    return a / g * b;
}

vector <int> Pi(string s)
{
    

    int n = s.size();

    vector <int> p(n, 0);

    for (size_t i = 1; i < n; i++)
    {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j])
            j = p[j - 1];

        if (s[i] == s[j])
            p[i] = j + 1;

        

        

    }

    return p;
}

vector <int> Z(string s)
{
    int n = s.length(), l = 0, r = 0;
    vector <int> z(n, 0);

    for (int i = 1; i < n; ++i)
    {
        if (i <= r)
            z[i] = min(r-i+1, z[i-1]);
        
        while (i + z[i] < n && s[z[i]] == s[i+z[i]])       
            z[i]++;
        
        if (i + z[i] - l > r)
        {
            l = i;
            r = i + z[i] - l;
        }
    }
    return z;
}

inline bool id2 (ld a, ld b, ld c) {
    if (a > b)  swap (a, b);
    return a <= c && c <= b;
}
 
bool intersect (point a, point b, point c)
{
    return id2 (a.x, b.x, c.x) && id2 (a.y, b.y, c.y);
}

ll dotproduct(point a, point b)
{
    return a.x * b.x + a.y * b.y;
}

ll crossproduct(point a, point b)
{
    return a.x * b.y - b.x * a.y;
}

ld id8(point a, point b, point c) 
{
    

    return ((a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y)) / 2.0;
}

int decomposition(int n)
{
    ll ans = 0;
    int degree = 0;
    int i = 2;
    while (i * i <= n)
        if (n % i == 0)
            degree++;
        else
        {
            

            ans += degree;
            i++;
        }

    return ans;
}

void id3(bool *a, int n)
{
    a[0] = a[1] = false;
    for (int i = 2; i <= n; ++i)
       a[i] = true;
    
    for (int i = 2; i <= n; ++i)
        if (a[i])
            for (int j = i*i; j <= n; j+=i)
                a[j] = false;
}

ll C(ll n, ll m)
{
    if (m > n) return 0;
    if (n > 0 && n > m) 
        return C(n - 1, m - 1) + C(n - 1, m) % MOD;
    else
        return 1;
}

vector <bool> u;
vvll g;
ll n, m, s[N];

ll dfs(int v)
{
    u[v] = 1; 
    ll m = s[v];
    for (auto to : g[v])
        if (!u[to])
            m = min(m, dfs(to));

    return m;
}

vvll depth, matr;
void bfs(int it) 
{
    queue <int> q;
    q.push(it);
    u[it] = 1;
    while (!q.empty())
    {
        int i = q.front(); q.pop();
        for (int j = 0; j < n; j++)
            if (!u[j] && matr[i][j])
            {
                q.push(j);
                u[j] = 1;
                depth[it][j] = depth[it][i] + 1;
            }
    }
}

void dijkstra(int n, int start)
{
    

    vvpi g;
    

    vector <ll> d(n, INF), u(n, 0);

    d[start] = 0;
    

    

    set < pair<int,int> > q;
    q.insert (make_pair (d[start], start));
    while (!q.empty()) 
    {
        int v = q.begin()->r;
        q.erase(q.begin());

        for (int j = 0; j < g[v].size(); ++j)
        {
            int to = g[v][j].l, len = g[v][j].r;
            if (d[v] + len < d[to])
            {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                

                q.insert({d[to], to});
            }
        }
    }
}












ll id0(vll &a, ll x)
{
    
    ll n = a.size(), l = 0;
    for (ll count = n-1; count; count /= 2)
    {   

        if (a[l + count/2] < x)     

        {
            l+= count/2 + 1;
            count--;
        }
    }
    return l;
}

ll binsearch(vll &a, ll x)
{
    
    ll l = 0, r = a.size() - 1, m;
    while (l < r)
    {   
        m = (l + r) / 2;
        
        

        if (a[m] < x)  

            l = m+1;
        else
            r = m;

    }
    return l;
}

void solve1()
{
    ll n, sum = 0, mx = 0, ans = 0;
    cin >> n;
    bool ok = true;
    vpll at(n);
    

    FI(n) {cin >> at[i].X;}

    FI(n) {cin >> at[i].Y;}
    

    sort(ALL(at));
    

    FI(n-1)
    {
        if (at[i].X == at[i+1].X)
        {
            sum = 0; mx = at[i].Y;
            ll newi = i;
            FORS(j, i, n)
            {
                if (at[j].X - at[j+1].X > 1)
                    break;
                mx = min(mx, at[j].Y);
                if (at[j].X != at[i].X)
                    sum += mx;
                else 
                {
                    newi = j;
                    sum = mx;
                }
            }
            i = newi;
            ans += sum;
        }
    }
    

    cout << ans << endl;
}

void solve()
{
    ll n;
    cin>>n;
    string s(n, '2');
    s[n-1] = '3';
    ll sum = 2 * n + 1;
    if (sum % 3 == 0) s[0] = '4';
    if (n < 2) cout << -1 << endl; else cout << s << endl;
}

int main()
{
   

    FastIO
    ll test = 1; cin >> test;
    for (int it = 0; it < test; it++)
    {
        solve();
    }
    return 0;
}