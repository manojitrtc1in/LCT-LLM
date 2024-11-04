






























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
    const ll id6 = (sizeof(ll) << 3) - 1;
    const ll id0 = popcount(RAND_MAX);
    ll number = 0;
    
    for (ll id4 = 0; id4 <= id6; id4 += id0)
    {
        number ^= (((ll)rand()) << id4);
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
    id2(int id5)
    {
        tree.reserve(id5);
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























































































ll id3(const vi &a, const ll k, const ll &best_answer) {
    const int n = SZ(a);
    ll total = 0;
    ll answer = 0;
    ll left_count = 0;
    int left = -1;
    int j = -1;


    
    FOR(right, n) {
        if (total * 2 < k) {
            j = right;
        }
        
        total += a[right];
        
        if (total >= k) {
            ll right_count = (int)(k - (total - a[right]));

            assert(j != -1);
            
            ll change = right_count * (right - j) + left_count * (j - left);
            
            if (answer + change >= best_answer) {
                return answer + change;
            }


            cerr << left << ' ' << j << ' ' << right << ' ' << change << ' ';

            
            for (++left; left < right; ++left) {
                if (answer + (change += 1LL * abs(left - j) * a[left]) >= best_answer) {
                    return answer + change;
                }
            }
                

            cerr << change << endl;

            answer += change;
                        
            left_count = (a[right] - right_count) % k;;
            total = left_count;
            left_count = total;
            j = left;
            left = right;
        }
    }
    
    return answer;
}

ll solve_large(const vi &a, const vll &pa, const vll &pai, const ll k, const ll &best_answer) {

    const auto expected = id3(a, k, best_answer);

    const int n = SZ(pa) - 1;
    ll answer = 0;
    ll left_count = 0;


    
    for (int left = -1; left + 1 < n; ) {
        int j = upper_bound(pa.begin() + left + 1, pa.end(), k / 2 + pa[left + 1] - left_count) - pa.begin() - 1;






        int right = int(lower_bound(pa.begin() + j, pa.end(), k + pa[left + 1] - left_count) - pa.begin() - 1);


        ll total = left_count + pa[right + 1] - pa[left + 1];
        assert(total >= k);
    
        ll right_count = (int)(k - (total - a[right]));
        
        assert(j != -1);
        
        ll change = right_count * (right - j)
            + left_count * (j - left);
        

        cerr << left << ' ' << j << ' ' << right << ' ' << change << ' ';

                    
        change += j * (pa[j] - pa[left+1])
            - (pai[j] - pai[left+1])
            - j * (pa[right] - pa[j])
            + (pai[right] - pai[j]);
        

        cerr << change << endl;

        
        if ((answer += change) >= best_answer) {
            return answer;
        }
            
        left_count = (a[right] - right_count) % k;
        total = left_count;
        left = right;
    }
    

    assert(expected == answer);

    
    return answer;
}

ll solve_large(const vi &a) {
    const ll INF = numeric_limits<ll>::max() / 2;
    const int n = SZ(a);
    
    vll pa(1 + n);
    vll pai(1 + n);
    
    FI(n) {
        pai[1 + i] = pai[i] + 1LL * a[i] * i;
        pa[1 + i] = pa[i] + a[i];
    }
    
    ll sa = pa[n];
    
    if (1 == sa) {
        return -1;
    }

    ll answer = solve_large(a, pa, pai, sa, INF);
    
    for (ll d = 2; d * d <= sa; ++d) {
        if (sa % d == 0) {
            while (sa % d == 0) {
                sa /= d;
            }
            
            answer = min(answer, solve_large(a, pa, pai, d, answer));
        }
    }
    
    if (sa > 1) {
        answer = min(answer, solve_large(a, pa, pai, sa, answer));
    }
    
    return answer;
}


ll solve_large(const vi &a, const ll &k, const ll &best_answer) {
    const int n = SZ(a);
    vll pa(1 + n);
    partial_sum(ALL(a), pa.begin() + 1);
    
    vll pai(1 + n);
    
    FI(n) {
        pai[1 + i] = pai[i] + 1LL * a[i] * i;
    }
        
    return solve_large(a, pa, pai, k, best_answer);
}


int main(int argc, const char * argv[]) {

    {
        vi a(1000000, 720720);
        --a[0];
        ++a[1];


    }
    assert(90 == solve_large({3, 3, 3, 5, 6, 9, 3, 1, 7, 3}, 43, (ll)1e18));
    assert(90 == solve_large({3, 3, 3, 5, 6, 9, 3, 1, 7, 3}));
    assert(2 == id3({3, 10, 2, 1, 5}, 3, (ll)1e18));
    assert(2 == solve_large({3, 10, 2, 1, 5}, 3, (ll)1e18));
    assert(9 == solve_large({4, 8, 5}, 17, (ll)1e18));
    assert(2 == solve_large({1, 0, 1}));
    assert(-1 == solve_large({1}));

    ios::sync_with_stdio(false);
    cin.tie(0);
    srand((unsigned int)time(NULL));
    
    int n;
    
    while (~scanf("%d", &n)) {
        vi a(n);
        
        FI(n) {
            scanf("%d", &a[i]);
        }
        
        printf("%lld\n", solve_large(a));
    }

    return 0;
}
