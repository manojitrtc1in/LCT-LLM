#include <bits/stdc++.h>
 
#define M_PI       3.14159265358979323846
 
using namespace std;
 
 




 
#define M_PI       3.14159265358979323846
 
using namespace std;
 




inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }
inline int readInt() { int x; scanf("%d", &x); return x; }
 




typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
 
 


 


#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) ((a)*(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
 




#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
 
 
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const double EPS = 1E-8;
 
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
const int INF = 100000000;
 
class UnionFind {
public:
    vector <ll> par; 
    vector <ll> siz; 
    
    vector <ll> maxv;
    UnionFind(ll sz_): par(sz_), siz(sz_, 1LL) {
        for (ll i = 0; i < sz_; ++i) par[i] = i;
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1LL);
        for (ll i = 0; i < sz_; ++i) par[i] = i;
    }
 
    ll root(ll x) { 
        while (par[x] != x) {
            x = par[x] = par[par[x]];
        }
        return x;
    }
 
    bool merge(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }
 
    bool issame(ll x, ll y) { 
        return root(x) == root(y);
    }
 
    ll size(ll x) { 
        return siz[root(x)];
    }
};
 
 
ll mod_pow(ll x, ll n, ll mod){
    ll res = 1;
    bool c = false;
    while(n){
        if(n&1) res = res * x;
 
        if(res > mod){
            c = true;
            res %= mod;
        }
        x = x * x %mod;
        n >>= 1;
    }
    if(c) return mod;
    return res;
}
 
#define SIEVE_SIZE 5000000+10
bool sieve[SIEVE_SIZE];
void make_sieve(){
    for(int i=0; i<SIEVE_SIZE; ++i) sieve[i] = true;
    sieve[0] = sieve[1] = false;
    for(int i=2; i*i<SIEVE_SIZE; ++i) if(sieve[i]) for(int j=2; i*j<SIEVE_SIZE; ++j) sieve[i*j] = false;
}
 
bool isprime(ll n){
    if(n == 0 || n == 1) return false;
    for(ll i=2; i*i<=n; ++i) if(n%i==0) return false;
    return true;
}
 
template<typename T>
vector<T> gauss_jordan(const vector<vector<T>>& A, const vector<T>& b){
    int n = A.size();
    vector<vector<T>> B(n, vector<T>(n+1));
 
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            B[i][j] = A[i][j];
        }
    }
 
    for(int i=0; i<n; ++i) B[i][n] = b[i];
 
    for(int i=0; i<n; ++i){
        int pivot = i;
        for(int j=i; j<n; ++j){
            if(abs(B[j][i]) > abs(B[pivot][i])) pivot = j;
        }
        swap(B[i], B[pivot]);
 
        if(abs(B[i][i]) < EPS) return vector<T>(); 

 
        for(int j=i+1; j<=n; ++j) B[i][j] /= B[i][i];
        for(int j=0; j<n; ++j){
            if(i != j){
                for(int k=i+1; k<=n; ++k) B[j][k] -= B[i][j] * B[i][k];
            }
        }
    }
 
    vector<T> x(n);
 
    for(int i=0; i<n; ++i) x[i] = B[i][n];
    return x;
    
}
 
 
 
 
typedef vector<ll> vec;
typedef vector<vec> mat;
 
mat mul(mat &A, mat &B) {
    mat C(A.size(), vec((int)B[0].size()));
    for(int i=0; i<A.size(); ++i){
        for(int k=0; k<B.size(); ++k){
            for(int j=0; j<B[0].size(); ++j){
                C[i][j] = (C[i][j] + A[i][k] * B[k][j] %MOD) % MOD;
            }
        }
    }
    return C;
}
mat mat_pow(mat A, ll n) {
    mat B(A.size(), vec((int)A.size()));
 
    for(int i=0; i<A.size(); ++i){
        B[i][i] = 1;
    }
 
    while(n > 0) {
        if(n & 1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}
 
bool operator<(const pii& a, const pii& b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
 
const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];
 


void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
 


long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
 
int bit[1000010];
int sums(int i){
    i++;
    int s = 0;
    while(i > 0){
        s += bit[i];
        i -= i & -i;
    }
    return s;
}
void add(int i, int x){
    i++;
    while(i <= 1000010){
        bit[i] += x;
        i += i & -i;
    }
}
long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}


inline long long mod(long long a, long long m) {
    return (a % m + m) % m;
}



long long modinv(long long a, long long m) {
    long long x, y;
    extGCD(a, m, x, y);
    return mod(x, m); 

}
ll GCD(ll a, ll b){
    
    if(b == 0) return a;
    return GCD(b, a%b);
}
 
struct BipartiteMatching {
  vector< vector< int > > graph;
  vector< int > match, alive, used;
  int timestamp;
 
  BipartiteMatching(int n) : graph(n), alive(n, 1), used(n, 0), match(n, -1), timestamp(0) {}
 
  void add_edge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
 
  bool dfs(int idx) {
    used[idx] = timestamp;
    for(auto &to : graph[idx]) {
      int to_match = match[to];
      if(alive[to] == 0) continue;
      if(to_match == -1 || (used[to_match] != timestamp && dfs(to_match))) {
        match[idx] = to;
        match[to] = idx;
        return true;
      }
    }
    return false;
  }
 
  int bipartite_matching() {
    int ret = 0;
    for(int i = 0; i < graph.size(); i++) {
      if(alive[i] == 0) continue;
      if(match[i] == -1) {
        ++timestamp;
        ret += dfs(i);
      }
    }
    return ret;
  }
 
  void output() {
    for(int i = 0; i < graph.size(); i++) {
      if(i < match[i]) {
        cout << i << "-" << match[i] << endl;
      }
    }
  }
};

struct PartiallyPersistentUnionFind {

    using pint = pair<int, int>;

    

    

    


    

    

    vector<int> par, last;
    vector<vector<pint>> history;

    PartiallyPersistentUnionFind(int n) : par(n, -1), last(n, -1), history(n) {
        for(auto &vec : history) vec.emplace_back(-1, -1);
    }

    void init(int n){
        par.assign(n, -1); last.assign(n, -1); history.assign(n, vector<pint>());
        for(auto &vec: history) vec.emplace_back(-1, -1);
    }

    int root(int t, int x){
        if(last[x] == -1 || t < last[x]) return x;
        return root(t, par[x]);
    }

    bool issame(int t, int x, int y){
        return root(t, x) == root(t, y);
    }

    bool merge(int t, int x, int y){
        x = root(t, x);
        y = root(t, y);

        if(x == y) return false;
        

        if( par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        

        last[y] = t; 
        history[x].emplace_back(t, par[x]);
        return true;
    }

    int size(int t, int x){
        x = root(t, x);
        
        return -prev(lower_bound(history[x].begin(), history[x].end(), make_pair(t, 0)))->second;
    }
};
struct LazySegmentTree {
private:
    int n;
    vector<ll> node, lazy;

public:
    LazySegmentTree(vector<ll> v) {
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);

        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = node[i*2+1] + node[i*2+2];
    }

    void eval(int k, int l, int r) {
        if(lazy[k] != 0) {
            node[k] += lazy[k];
            if(r - l > 1) {
                lazy[2*k+1] += lazy[k] / 2;
                lazy[2*k+2] += lazy[k] / 2;
            }
            lazy[k] = 0;
        }
    }

    void add(int a, int b, ll x, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        }
        else {
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = node[2*k+1] + node[2*k+2];
        }
    }

    ll getsum(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return 0;
        if(a <= l && r <= b) return node[k];
        ll vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }
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
Edge double_sweep(const Graph &g, int s = 0) {
    static const Weight INF = std::numeric_limits<Weight>::max() / 8;
    static const auto bfs = [](const Graph &g, int s, std::queue<int> &q, std::vector<int> &dist) {
        while (q.size()) q.pop();
        q.push(s);
        int n = g.size();
        dist.assign(n, INF);
        dist[s] = 0;
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (auto &e : g[u]) {
                int v = e.dst;
                if (dist[v] == INF) {
                    dist[v] = dist[u] + e.weight;
                    q.push(v);
                }
            }
        }
        return dist;
    };
    std::vector<Weight> dist;
    std::queue<int> q;
    bfs(g, s, q, dist);
    int n = g.size(), u = -1, v = -1;
    for (int i = 0; i < n; i++)
        if (dist[i] != INF && (u == -1 || dist[i] > dist[u])) u = i;
    bfs(g, u, q, dist);
    for (int i = 0; i < n; i++)
        if (dist[i] != INF && (v == -1 || dist[i] > dist[v])) v = i;
    Weight d = dist[v];
    if (u > v) std::swap(u, v);
    return Edge(u, v, d);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    


    int a, n, m; cin >> a >> n >> m;

    vector<int> israin(a+1,0);
    vector<pii> umb(a+1, make_pair(INT_MAX, -1));
    vector<int> costs(m);

    REP(i,n){
        int l, r; cin >> l >> r;
        
        for(int j=l; j<r; j++){
            israin[j] = 1;
        }
    }
    REP(i,m){
        int x, p; cin >> x >> p;
        costs[i] = p;

        umb[x] = min(umb[x], make_pair(p, i));
    }

    vector<vector<ll>> dp(a+1, vector<ll>(m+1, INT_MAX));

    dp[0][m] = 0;
    for(int i=0; i<a; i++){
        for(int j=0; j<=m; j++){
            
            if(dp[i][j] == INT_MAX) continue;

            if(israin[i] == 0){
                dp[i+1][m] = min(dp[i+1][m], dp[i][j]);
            }

            if(j < m){
                dp[i+1][j] = min(dp[i+1][j], dp[i][j] + costs[j]);
            }

            if(umb[i].first != INT_MAX){
                dp[i+1][umb[i].second] = min(dp[i+1][umb[i].second], dp[i][j] + umb[i].first);
            }
        }
    }

    ll ans = INT_MAX;
    for(int i=0; i<=m; i++){
        ans = min(ans, dp[a][i]);
    }

    if(ans == INT_MAX) ans = -1;
    cout << ans << endl;
    return 0;
}
