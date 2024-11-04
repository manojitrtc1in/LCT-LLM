






























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
    const ll id9 = (sizeof(ll) << 3) - 1;
    const ll id0 = popcount(RAND_MAX);
    ll number = 0;
    
    for (ll id4 = 0; id4 <= id9; id4 += id0)
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
class id3
{
public:
    static const int id2;
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
        
        Node(int parent = id2, int parentCharacter = ALPHA) :
            leaf(false),
            parent(parent),
            parentCharacter(parentCharacter),
            link(id2),
            outputFunction(id2)
        {
            fill_n(next, ALPHA, id2);
            fill_n(go, ALPHA, id2);
        }
    };
    
    vector<Node> tree = vector<Node>(1);
    
    id3(){}
    id3(int id5)
    {
        tree.reserve(id5);
    }
    
    template < class Iterator >
    void add(int length, const Iterator begin)
    {
        int vertex = ROOT;
        
        for (int i = 0; i < length; ++i)
        {
            if (id2 == tree[vertex].next[begin[i]])
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
        
        if (id2 == tree[vertex].link)
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
        
        if (id2 == tree[vertex].go[character])
        {
            if (id2 == tree[vertex].next[character])
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
        
        if (id2 == tree[vertex].outputFunction)
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

template < int ALPHA > const int id3<ALPHA>::id2 = -1;
template < int ALPHA > const int id3<ALPHA>::ROOT = 0;



typedef ll T;
const T EPS = 1e-7;
struct PT {
    T x, y;
    PT() {}
    PT(T x, T y) : x(x), y(y) {}
    bool operator<(const PT &rhs) const { return make_pair(x,y) < make_pair(rhs.x,rhs.y); }
    bool operator==(const PT &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); }
};

T cross(PT p, PT q) { return p.x*q.y-p.y*q.x; }
T area2(PT a, PT b, PT c) { return cross(a,b) + cross(b,c) + cross(c,a); }


bool between(const PT &a, const PT &b, const PT &c) {
    return (fabs(area2(a,b,c)) < EPS && (a.x-b.x)*(c.x-b.x) <= 0 && (a.y-b.y)*(c.y-b.y) <= 0);
}


vector<PT> id8(vector<PT> pts) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    vector<PT> up, dn;
    for (int i = 0; i < pts.size(); i++) {
        while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
        while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
        up.push_back(pts[i]);
        dn.push_back(pts[i]);
    }
    pts = dn;
    for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
    

    if (pts.size() <= 2) return pts;
    dn.clear();
    dn.push_back(pts[0]);
    dn.push_back(pts[1]);
    for (int i = 2; i < pts.size(); i++) {
        if (between(dn[dn.size()-2], dn[dn.size()-1], pts[i])) dn.pop_back();
        dn.push_back(pts[i]);
    }
    if (dn.size() >= 3 && between(dn.back(), dn[0], dn[1])) {
        dn[0] = dn.back();
        dn.pop_back();
    }
    pts = dn;

    
    return pts;
}

ll solve(vector<PT> points) {
    const int n = SZ(points);
    
    FI(n)
    {
        ll x = points[i].x;
        ll y = points[i].y;
        
        points[i].x = x;
        points[i].y = y - x * x;
    }

    const auto pts = id8(points);
    auto cmp = [=](const PT &a, const PT &b){return a.x < b.x || (a.x == b.x && a.y < b.y);};
    PT leftBottom = *min_element(ALL(points), cmp);
    PT rightTop = *max_element(ALL(points), cmp);
    vector<PT> up;
    
    up.push_back(leftBottom);
    
    for (const PT &point : pts) {
        if (!(leftBottom == point) && !(rightTop == point) && area2(leftBottom, point, rightTop) < 0) {
            up.PB(point);
        }
    }
    
    up.push_back(rightTop);
    sort(ALL(up));
    
    ll answer = 0;

    FI(SZ(up) - 1) {
        answer += up[i].x != up[i + 1].x;
    }
    
    return answer;
}

struct Fraction {
    ll numerator, denominator;
    
    Fraction(ll n=0, ll d=1) : numerator(n), denominator(d) {
        ll id7 = gcd(numerator, denominator);
        
        numerator /= id7;
        denominator /= id7;
        
        if (denominator < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
    }
    
    bool operator < (const Fraction &fraction) const {
        return numerator * fraction.denominator < denominator * fraction.numerator;
    }
};

Fraction operator * (const Fraction &a, const Fraction &b) {
    return Fraction(a.numerator * b.numerator, a.denominator * b.denominator);
}

Fraction operator + (const Fraction &a, const Fraction &b) {
    ll denominator = lcm(a.denominator, b.denominator);
    ll numerator = denominator / a.denominator * a.numerator + denominator / b.denominator * b.numerator;
    
    return Fraction(numerator, denominator);
}

ll bf(vector<PT> points) {
    const int n = SZ(points);
    set < pair < Fraction, Fraction > > id1;
    
    FI(n) {
        FOR(j, n) {
            ll b = (points[i].y - sqr(points[i].x)) - (points[j].y - sqr(points[j].x));
            ll c = -points[j].x * (points[i].y - sqr(points[i].x)) + points[i].x * (points[j].y - sqr(points[j].x));
            ll d = points[i].x - points[j].x;
            
            if (d != 0) {
                id1.emplace(Fraction(b, d), Fraction(c, d));
            }
        }
    }
    
    ll answer = 0;
    
    for (const auto &id6 : id1) {
        bool ok = true;
        Fraction b = id6.first;
        Fraction c = id6.second;
        
        FI(n) {
            if (sqr(points[i].x) + b * points[i].x + c < points[i].y) {
                ok = false;
            }
        }
        
        if (ok) {
            ++answer;
        }
    }
    
    return answer;
}

vector<PT> generate() {
    const int MAX_X = 5;
    int n = 1 + rand() % 4;
    vector<PT> points(n);
    
    FI(n) {
        points[i].x = -MAX_X + rand() % (2 * MAX_X + 1);
        points[i].y = -MAX_X + rand() % (2 * MAX_X + 1);
    }
    
    return points;
}

void stress() {
    assert(2 == solve({
        {1, -4},
        {4, -2},
        {-3, -4},
        {-3, 1},
    }));
    assert(1 == solve({
        {-3, -2},
        {-3, 0},
        {-1, -3},
    }));
    assert(1 == solve({
        {-1, 1},
        {1, 0},
        {1, 2}
    }));
    assert(solve({
        {4, -4},
        {5, 2},
        {-1, 2},
    }) == 1);
    assert(bf({
        {4, -3},
        {-1, -4},
        {-1, -5},
    }) == 1);
    assert(bf({
        {-4, 5},
        {1, 3},
    }) == 1);
    assert(solve({
        {-1, 0},
        {0, 2},
        {1, 0},
    }) == 2);
    assert(bf({
        {-1, 0},
        {0, 2},
        {1, 0},
    }) == 2);
    assert(solve({
        {1, 0},
        {1, -1},
        {0, -1},
        {-1, 0},
        {-1, -1},
    }));
    
    while (true) {
        auto points = generate();
        auto o = solve(points);
        auto a = bf(points);
        
        assert(o == a);
    }
}

int main(int argc, const char * argv[]) {

    


    ios::sync_with_stdio(false);
    cin.tie(0);
    srand((unsigned int)time(NULL));

    int n;
    
    while (cin >> n) {
        vector < PT > points(n);
        
        FI(n) {
            ll x, y;
            
            cin >> x >> y;
            points[i].x = x;
            points[i].y = y;
        }
        
        ll answer = solve(points);
        
        cout << answer << endl;
    }
    
    return 0;
}
