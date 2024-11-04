




#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
#include <tuple> 
#include <random>
#include <cassert>
using namespace std;
typedef long long ll;





#define re(type, ...)type __VA_ARGS__;MACRO_VAR_Scan(__VA_ARGS__);
template<typename T> void MACRO_VAR_Scan(T& t) { cin >> t; }
template<typename First, typename...Rest>void MACRO_VAR_Scan(First& first, Rest&...rest) { cin >> first; MACRO_VAR_Scan(rest...); }
#define rv_row(type, n, ...)vector<type> __VA_ARGS__;MACRO_VEC_ROW_Init(n, __VA_ARGS__); for(int i=0; i<n; ++i){MACRO_VEC_ROW_Scan(i, __VA_ARGS__);}
template<typename T> void MACRO_VEC_ROW_Init(int n, T& t) { t.resize(n); }
template<typename First, typename...Rest>void MACRO_VEC_ROW_Init(int n, First& first, Rest&...rest) { first.resize(n); MACRO_VEC_ROW_Init(n, rest...); }
template<typename T> void MACRO_VEC_ROW_Scan(int p, T& t) { cin >> t[p]; }
template<typename First, typename...Rest>void MACRO_VEC_ROW_Scan(int p, First& first, Rest&...rest) { cin >> first[p]; MACRO_VEC_ROW_Scan(p, rest...); }
#define rv(type, c, n) vector<type> c(n);for(auto& i:c)cin>>i;
#define rMAT(type, c, n, m) vector<vector<type>> c(n, vector<type>(m));for(auto& r:c)for(auto& i:r)cin>>i;  
void _main(); signed main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }




#define pr(x) cout<<(x)<<endl
#define prv(v){for(int ii=0;ii<(int)v.size();ii++){if(ii)cout<<" ";cout<<v[ii];}cout << "\n";}
#define sankou(x,a,b) cout<<((x)?(a):(b))<<endl;
#define hihumi(x,a,y,b,c) cout<<(x?a:y?b:c)<<endl;
#define YESNO(x) cout<<(x?"YES":"NO")<<endl;
#define yesno(x) cout<<(x?"Yes":"No")<<endl;
#define ck(x)  cerr << #x << " = " << (x) << endl;
#define ckv(v) {std::cerr << #v << "\t:";for(const auto& xxx : v){std::cerr << xxx << " ";}std::cerr << "\n";}




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




#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define EXISTST(s,c) (((s).find(c)) != std::string::npos)
#define SORT(c) sort((c).begin(),(c).end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,val) (lower_bound(x.begin(),x.end(),val)-x.begin())
#define POSU(x,val) (upper_bound(x.begin(),x.end(),val)-x.begin())
#define X first
#define Y second
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define MEMINF(a) memset(a,0x3f,sizeof(a))





#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define FORll(i,a,b) for(long long i=(a);i<(b);++i)
#define repll(i,n) FORll(i,0,n)
#define rrep(i,a,b) for(int i=(int)(b)-1;i>=a;i--)
#define rrepll(i,a,b) for(long long i=(b)-1ll;i>=a;i--)
#define fo(x,c) for(auto &x : c)

#define repeat(i,a,b) for(int i=(a);i<=(b);++i)




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
#define ADD(a, b) a = (a + ll(b)) % MOD
#define MUL(a, b) a = (a * ll(b)) % MOD
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

using Weight = ll;

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

Matrix WarshallFloyd(const Graph &g) {
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

std::pair<Weight, Edges> kruskal(Graph const &g) {
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





class CumulativeSum {
public:
    vector<ll> sum;
    CumulativeSum() {}
    CumulativeSum(vector<ll> A) {
        ll n = A.size();
        sum.resize(n + 1, 0);
        for (ll i = 1;i <= n;i++) sum[i] += sum[i - 1] + A[i - 1];
    }
    ll get(ll l, ll r) { assert(l <= r && l >= 0 && r <= (ll)sum.size());return sum[r] - sum[l]; } 

};






std::vector<int> eratosthenes_sieve(int n) {
    std::vector<int> ps(n + 1);
    std::iota(ps.begin() + 2, ps.end(), 2);
    for (int i = 2; i * i <= n; ++i)
        if (ps[i])
            for (int j = i * i; j <= n; j += i) ps[j] = 0;
    return ps;
}
std::vector<int> make_primes(int n) {
    std::vector<int> ps = eratosthenes_sieve(n);
    ps.erase(std::remove(ps.begin(), ps.end(), 0), ps.end());
    return ps;
}



ll ans, ret, cnt, sum, cur, f, g;

void poss() { pr("Possible");return; }
void imposs() { pr("Impossible");return; }

void _main() {
    re(int, n, m);
    if (m < n - 1) {
        imposs();
        return;
    }
    vi v = make_primes(n);
    

    if (n <= 5000) {
        vpii u;
        FOR(i, 2, n + 1)u.PB(P(1, i));
        if (SZ(u) == m)goto OUT2;
        FOR(i, 2, n + 1) {
            FOR(j, 2, n + 1) {
                if (i < j) {
                    if (SZ(u) == m)goto OUT2;
                    if (gcd(i, j) == 1)u.PB(P(i, j));
                }
            }
        }
    OUT2:
        

        if (SZ(u) < m) {
            imposs();
            return;
        }
        else {
            poss();
            rep(i, m) {
                cout << u[i].X << " " << u[i].Y << endl;
            }
            return;
        }
    }
    else {
        vpii u;
        FOR(i, 2, n + 1)u.PB(P(1, i));
        if (SZ(u) == m)goto OUT;
        rep(i, SZ(v))rep(j, SZ(v)) if(i<j){
            if (SZ(u) == m)goto OUT;
            else u.PB(P(v[i], v[j]));
        }
    OUT:
        int i = 0;
        poss();
        ck(SZ(u));
        fo(x, u) {
            cout << x.X << " " << x.Y << endl;
        }
        return;
    }
}