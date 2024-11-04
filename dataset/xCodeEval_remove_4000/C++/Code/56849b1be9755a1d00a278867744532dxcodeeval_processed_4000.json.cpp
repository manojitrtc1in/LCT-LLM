






























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

template <class T>
T assign(const T &, const T &t) {
    return t;
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
    ) :
        n(n),
        t(n << 1),
        operation(operation),
        default_value(default_value),
        modification(modification)
    {}
    
    SegmentTree(const vector<T> &a,
                const function<T(T, T)> &operation,
                const T &default_value=T(),
                const function<T(T, T)> &modification=assign<T>
    ) :
            SegmentTree(SZ(a), operation, default_value, modification)
    {
        copy(ALL(a), t.begin() + n);
        
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

template <const int modulo>
struct IntegerModulo {
    int value;
    
    IntegerModulo(int value) : value(value % modulo) {}
};

template <const int modulo>
IntegerModulo<modulo>& operator += (IntegerModulo<modulo> &left, const IntegerModulo<modulo> &right) {
    left.value += right.value;
    left.value %= modulo;
    
    return left;
}

template <const int modulo>
IntegerModulo<modulo> operator - (const IntegerModulo<modulo> &i) {
    return IntegerModulo<modulo>((modulo - i.value) % modulo);
}

template <const int modulo>
IntegerModulo<modulo>& operator -= (IntegerModulo<modulo> &left, const IntegerModulo<modulo> &right) {
    return left += (-right);
}

template <const int modulo>
IntegerModulo<modulo> operator + (const IntegerModulo<modulo> &left, const IntegerModulo<modulo> &right) {
    auto lleft = IntegerModulo<modulo>(left);
    return lleft += right;
}

template <const int modulo>
IntegerModulo<modulo> operator - (const IntegerModulo<modulo> &left, const IntegerModulo<modulo> &right) {
    auto lleft = IntegerModulo<modulo>(left);
    return lleft -= right;
}

enum {
    EMPTY = '.',
    ROCK = 'R',
};

enum {
    DOWN,
    RIGHT,
    DIRECTIONS,
};

const int DI[DIRECTIONS] = {+1, 0};
const int DJ[DIRECTIONS] = {0, +1};

int solve(const vector<string> &field) {
    const int n = SZ(field);
    const int m = SZ(field[0]);
    
    if (1 == n && 1 == m) {
        return 1;
    }
    
    vvi number_of_rocks_in_direction[DIRECTIONS];
    vvi previous[DIRECTIONS];
    vector<vector<IntegerModulo<MODULO>>> dp[DIRECTIONS];
    vector<vector<IntegerModulo<MODULO>>> psdp[DIRECTIONS];
    
    FOR(d, DIRECTIONS) {
        number_of_rocks_in_direction[d].assign(1 + n, vi(1 + m, 0));
        previous[d].assign(1 + n, vi(1 + m, 0));
        dp[d].assign(n, vector<IntegerModulo<MODULO>>(m, 0));
        psdp[d].assign(1 + n, vector<IntegerModulo<MODULO>>(1 + m, 0));
    }
    
    RFI(n) {
        RFOR(j, m) {
            FOR(d, DIRECTIONS) {
                number_of_rocks_in_direction[d][i][j] = number_of_rocks_in_direction[d][i + DI[d]][j + DJ[d]] + (ROCK == field[i][j]);
            }
        }
    }
    
    FI(n) {
        FOR(j, m) {
            previous[DOWN][i][number_of_rocks_in_direction[RIGHT][i][j]] = j;
            previous[RIGHT][number_of_rocks_in_direction[DOWN][i][j]][j] = i;
        }
    }
    
    dp[DOWN][0][0] = 1;
    dp[RIGHT][0][0] = 1;
    
    FI(n) {
        FOR(j, m) {
            FOR(d, DIRECTIONS) {
                int dd = DIRECTIONS - d - 1;
                int ii = i;
                int jj = j;
                
                if (d == DOWN) {
                    jj = previous[d][i][m - j];
                } else {
                    ii = previous[d][n - i][j];
                }
                
                if (i > 0 || j > 0) {
                    dp[d][i][j] = psdp[dd][i][j] - psdp[dd][ii][jj];

                    auto expected = IntegerModulo<MODULO>(0);
                    
                    if (d == DOWN) {
                        for (int jjj = jj; jjj < j; ++jjj) {
                            expected += dp[dd][i][jjj];
                        }
                    } else {
                        for (int iii = ii; iii < i; ++iii) {
                            expected += dp[dd][iii][j];
                        }
                    }
                    
                    assert(expected.value == dp[d][i][j].value);

                }
                
                if (d == DOWN) {
                    psdp[d][i + 1][j] = psdp[d][i][j] + dp[d][i][j];
                } else {
                    psdp[d][i][j + 1] = psdp[d][i][j] + dp[d][i][j];
                }
            }
        }
    }
    

    FOR(d, DIRECTIONS) {
        cout << "Came from " << (d ? "up" : "left") << ". Going " << (d ? "right" : "down") << endl;
        
        FI(n) {
            FOR(j, m) {
                cout << dp[d][i][j].value << ' ';
            }
            cout << endl;
        }
        
        cout << endl;
    }

    
    int answer = (dp[DOWN][n - 1][m - 1] + dp[RIGHT][n - 1][m - 1]).value;
    
    return answer;
}


int main(int argc, const char * argv[]) {

    assert(0 == solve({
        "...",
        "..R"
    }));
    assert(4 == solve({
        "...R",
        ".RR.",
        ".RR.",
        "R..."
    }));
    assert(1 == solve({
        ".R",
        ".."
    }));
    
    assert(1 == solve({
        "..",
        "R."
    }));
    assert(2 == solve({
        "..",
        ".."
    }));

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(13);
    cout.setf(ios::fixed);
    srand((unsigned int)time(NULL));

    int n, m;
    
    while(cin >> n >> m) {
        vector<string> field(n);
        
        FI(n) {
            cin >> field[i];
        }
        
        cout << solve(field) << endl;
    }

    return 0;
}
