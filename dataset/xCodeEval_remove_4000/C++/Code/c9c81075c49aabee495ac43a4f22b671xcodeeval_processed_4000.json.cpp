

































using namespace std;
typedef long long ll;
typedef long double ld;






template<typename T> void id4(T& t) { cin >> t; }
template<typename First, typename...Rest>void id4(First& first, Rest&...rest) { cin >> first; id4(rest...); }

template<typename T> void id2(int n, T& t) { t.resize(n); }
template<typename First, typename...Rest>void id2(int n, First& first, Rest&...rest) { first.resize(n); id2(n, rest...); }
template<typename T> void id1(int p, T& t) { cin >> t[p]; }
template<typename First, typename...Rest>void id1(int p, First& first, Rest&...rest) { cin >> first[p]; id1(p, rest...); }


void _main(); signed main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
















inline ll toInt(std::string s) { ll v; std::istringstream sin(s);sin >> v;return v; }
template<class T> inline string toString(T x) { ostringstream sout;sout << x;return sout.str(); }




template<class T> inline T sqr(T x) { return x*x; }
template<typename A, typename B>inline void chmin(A &a, B b) { if (a>b)a = b; }
template<typename A, typename B>inline void chmax(A &a, B b) { if (a<b)a = b; }
ll qp(ll a, ll b) { ll ans = 1ll;do { if (b & 1)ans = 1ll * ans*a;a = 1ll * a*a; } while (b >>= 1);return ans; }
ll qpmod(ll a, ll b, ll mo) { ll ans = 1ll;do { if (b & 1)ans = 1ll * ans*a%mo;a = 1ll * a*a%mo; } while (b >>= 1);return ans; }
inline ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
inline ll bit(ll x) { return (1ll << x); }
inline bool valid(int x, int h) { return 0 <= x && x < h; }






































typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef pair<pair<int, int>, int> PT;
typedef vector<pair<int, int>> vpii;




const double EPS = 1e-8;
const double PI = acos(-1.0);
const int INF = (int)(1e9) + 7;
const ll MOD = ll(1e9) + 7;
const ll MOD2 = (ll)(1e18) + 9;


const ll INF2 = (ll)(1e18);
const ll INTMAX = (0x7FFFFFFFL);
const ll LLMAX = (0x7FFFFFFFFFFFFFFFL);
const int N4 = (int)1e4 + 10;
const int N5 = (int)1e5 + 10;
const ll N9 = (ll)1e9;
int dx[9] = { 1, 0, -1, 0 , 1, -1, -1, 1, 0 };
int dy[9] = { 0, 1, 0, -1, -1, -1,  1, 1, 0 };




struct uf_tree {
    std::vector<int> parent;
    int __size;
    uf_tree(int size_) : parent(size_, -1), __size(size_) {}
    void unite(int x, int y) {
        if ((x = find(x)) != (y = find(y))) {
            if (parent[y] < parent[x]) std::swap(x, y);
            parent[x] += parent[y];
            parent[y] = x;
            __size--;
        }
    }
    bool is_same(int x, int y) { return find(x) == find(y); }
    int find(int x) { return parent[x] < 0 ? x : parent[x] = find(parent[x]); }
    int size(int x) { return -parent[find(x)]; }
    int size() { return __size; }
};

ll digitsum(ll x) {
    ll dig;
    ll summ = 0;
    while (x) {
        dig = x % 10;
        summ = summ + dig;
        x = x / 10;
    }
    return summ;
}

template <class T>
struct BIT {
    int n;
    std::vector<T> x;
    BIT(int n_ = 0) : n(n_), x(n + 1, 0) {}
    int size() const { return n; }
    T sum(int r) const {
        T S = 0;
        for (r = r - 1; r >= 0; r = (r & (r + 1)) - 1) S += x[r];
        return S;
    }
    T sum(int l, int r) const { return sum(r) - sum(l); }
    void add(int k, const T &a) {
        for (; k < n; k |= k + 1) x[k] += a;
    }
    void set(int k, const T &a) { add(k, a - sum(k, k + 1)); }
};

using Weight = int;

using Flow = int;
struct Edge {
    int src, dst;
    Weight weight;
    Flow cap;
    Edge() : src(0), dst(0), weight(0) {}
    Edge(int s, int d, Weight w) : src(s), dst(d), weight(w) {}
};
using Edges = std::vector<Edge>;
using Graph = std::vector<Edges>;
using Array = std::vector<Weight>;
using Matrix = std::vector<Array>;

void add_edge(Graph &g, int a, int b, Weight w = 1) {
    g[a].emplace_back(a, b, w);
    g[b].emplace_back(b, a, w);
}
void add_arc(Graph &g, int a, int b, Weight w = 1) { g[a].emplace_back(a, b, w); }

Matrix id5(const Graph &g) {
    auto const INF = std::numeric_limits<Weight>::max() / 8;
    int n = g.size();
    Matrix d(n, Array(n, INF));
    rep(i, n) d[i][i] = 0;
    rep(i, n) for (auto &e : g[i]) d[e.src][e.dst] = std::min(d[e.src][e.dst], e.weight);
    rep(k, n) rep(i, n) rep(j, n) {
        if (d[i][k] != INF && d[k][j] != INF) d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
    }
    return d;
}

std::vector<Weight> dijkstra(const Graph &g, int s) {
    const Weight INF = std::numeric_limits<Weight>::max() / 8;
    using state = std::tuple<Weight, int>;
    std::priority_queue<state> q;
    std::vector<Weight> dist(g.size(), INF);
    dist[s] = 0;
    q.emplace(0, s);
    while (q.size()) {
        Weight d;
        int v;
        std::tie(d, v) = q.top();
        q.pop();
        d *= -1;
        
        if (dist[v] < d) continue;
        for (auto &e : g[v]) {
            if (dist[e.dst] > dist[v] + e.weight) {
                dist[e.dst] = dist[v] + e.weight;
                q.emplace(-dist[e.dst], e.dst);
            }
        }
    }
    return dist;
}

std::pair<Weight, Edges> id3(Graph const &g) {
    uf_tree uf(g.size());
    Edges es;
    for (auto &adj : g)
        for (auto &e : adj) es.emplace_back(e);
    std::sort(es.begin(), es.end(),
        [](const Edge &e, const Edge &f) { return e.weight < f.weight; });
    Weight total = 0;
    Edges T;
    for (auto &e : es)
        if (!uf.is_same(e.src, e.dst)) {
            T.push_back(e);
            total += e.weight;
            uf.unite(e.src, e.dst);
        }
    return std::make_pair(total, T);
}

bool aof(ll a, ll b) {
    return a < LLMAX - b;
}
bool mof(ll a, ll b) {
    return a < LLMAX / b;
}

template< typename Monoid >
struct SegmentTree
{
    using F = function< Monoid(Monoid, Monoid) >;

    int sz;
    vector< Monoid > seg;

    const F f;
    const Monoid M1;

    SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1)
    {
        sz = 1;
        while (sz < n) sz <<= 1;
        seg.assign(2 * sz, M1);
    }

    void set(int k, const Monoid &x)
    {
        seg[k + sz] = x;
    }

    void build()
    {
        for (int k = sz - 1; k > 0; k--) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    void update(int k, const Monoid &x)
    {
        k += sz;
        seg[k] = x;
        while (k >>= 1) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    Monoid query(int a, int b)
    {
        Monoid L = M1, R = M1;
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if (a & 1) L = f(L, seg[a++]);
            if (b & 1) R = f(seg[--b], R);
        }
        return f(L, R);
    }

    Monoid operator[](const int &k) const
    {
        return seg[k + sz];
    }
};





class id0 {
public:
    vector<ll> sum;
    id0() {}
    id0(vector<ll> A) {
        ll n = A.size();
        sum.resize(n + 1, 0);
        for (ll i = 1;i <= n;i++) sum[i] += sum[i - 1] + A[i - 1];
    }
    ll get(ll l, ll r) { assert(l <= r && l >= 0 && r <= (ll)sum.size());return sum[r] - sum[l]; } 

};








ll ans, ret, cnt, sum, cur, f, g;
ll N, A, B, p[300009];

void _main() {
    cin >> N;
    ret = LLMAX;
    for (ll i = 1;i <= N;i++) {
        ll ok = 1e10, ng = 0;
        while (abs(ng - ok) > 1) {
            ll mi = (ng + ok) / 2;
            if (mi*i >= N) ok = mi;
            else ng = mi;
        }
        if (i + ok - 1 > N)continue;
        if (ret > i + ok)A = i, B = ok, ret = i + ok;
    }
    ck(A);
    ck(B);
    for (int i = 0; i <= N - B; i++) {
        long long L = A - i; if (L <= 0) continue;
        long long R = N - i;
        if (R > L*B || R < L + (B - 1)) continue;

        for (int j = 0; j < i; j++) p[j] = j + 1;
        int cx = N;
        for (int j = N - B; j <= N - 1; j++) { p[j] = cx; cx--; }
        int res = N - B - (L - 1);
        cx = N - B;
        for (int j = L - 2; j >= 0; j--) {
            long long G = res; if (G >= B - 1) G = B - 1;
            res -= G;
            int F = cx - 1;
            for (int k = cx - (G + 1); k <= cx - 1; k++) { p[k] = F + 1; F--; }
            cx -= (G + 1);
        }
        for (int j = 0; j < N; j++) {
            if (j) cout << " "; cout << p[j];
        }
        cout << endl;
        return;
    }
}