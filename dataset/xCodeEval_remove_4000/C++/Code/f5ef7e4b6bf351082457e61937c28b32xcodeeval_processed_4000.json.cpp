
















using namespace std;
typedef long long ll;
const ll INF = 1000000000000000000;
const ll MOD = 1000000007;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;


ll POW(ll x,ll n){
  x%=MOD;
  if(n==0)return 1;
  if(n%2==0)return POW(x*x,n/2)%MOD;
  return x%MOD*POW(x,n-1)%MOD;
}
 
ll id3(ll x,ll n){
  if(n==0)return 1;
  if(n%2==0)return id3(x*x,n/2);
  return x*id3(x,n-1);
}
 
ll id0(ll x,ll n,ll m){
  x%=m;
  if(n==0)return 1;
  if(n%2==0)return id0(x*x,n/2,m)%m;
  return x*id0(x,n-1,m)%m;
}

ll gcd(ll u, ll v) {
  ll r;
  while (0 != v) {
    r = u % v; u = v; v = r;
  }
  return u;
}
 
ll lcm(ll u, ll v) {
  return u/gcd(u,v)*v;
}

ll kaikai[510000]={};
ll KAI(ll m)
{
  if(kaikai[m])return kaikai[m];
  if(m<0) return 0;
  if(m==0) return 1;
  kaikai[m]=m*KAI(m-1)%MOD;
  return kaikai[m];
}
 
ll id1(ll m)
{
  if(m<0) return 0;
  if(m==0) return 1;
  return m*id1(m-1);
}
 
ll id2(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = id2(b, a%b, y, x);
    y -= a / b * x;
    return d;
}
 
inline ll mod(ll a, ll m) {
    return (a % m + m) % m;
}
 
ll modinv(ll a) {
    ll x, y;
    id2(a, MOD, x, y);
    return mod(x, MOD);
}

ll PER(ll m,ll n){
  if(n<0)return 0;
  ll ans=1;
  per(i,n)ans=ans*(m-i)%MOD;
  return ans;
}

ll PER2(ll m,ll n){
  if(n<0)return 0;
  ll ans=1;
  per(i,n)ans*=m-i;
  return ans;
}

ll COM(ll m,ll n)
{
  if(m<n) return 0;
  if(n<0) return 0;
  if(n==0) return 1;
  if(m==n) return 1;
  ll kai=1;
  rep(i,n){
    kai*=(i+1);
    kai%=MOD;
  }
  return PER(m,n)*modinv(kai)%MOD;
}



ll COM2(ll m,ll n)
{
  if(m<n) return 0;
  if(n<0) return 0;
  if(n==0) return 1;
  if(m==n) return 1;
  return id1(m)/id1(n)/id1(m-n);
}
 
ll DEC(ll x,ll m,ll n)

{
  
  return x%id3(m,n+1)/id3(m,n);
}
 
ll keta(ll x,ll n)

{
  if(x==0)return 0;
  return keta(x/n,n)+1;
}
 
ll DIV(ll x,ll n)

{
  if(x==0)return 0;
  return x/n+DIV(x/n,n);
}
 
ll ORD(ll x,ll n)

{
  if(x==0)return INF;
  if(x%n!=0)return 0;
  return 1+ORD(x/n,n);
}
 
ll SUP(ll x,ll n)

{
  if(x==0)return 0;
  if(x%n!=0)return x;
  return SUP(x/n,n);
}
 
ll DigSum(ll n)

{
  if(n==0)return 0;
  return n%10+DigSum(n/10);
}

ll digsum(ll n,ll m)

{
  if(n==0)return 0;
  return n%m+digsum(n/m,m);
}

ll SGS(ll x,ll y, ll m)

{
  if(y==0)return 0;
  if(y%2==0){
    return (1+id0(x,y/2,m))*SGS(x,y/2,m)%m;
  }
  return (1+x*SGS(x,y-1,m))%m;
}
 
ll SSGS(ll x,ll y,ll m)

{
  if(y==0)return 0;
  if(y==1)return 1;
  if(y%2==0){
    return (SSGS(x,y/2,m)*(id0(x,y/2,m)+1)%m+SGS(x,y/2,m)*y/2%m)%m;
  }
  return (SSGS(x,y-1,m)*x%m+y)%m;
}
 
void shuffle(ll array[], ll size) {
    for(ll i = 0; i < size; i++) {
        ll j = rand()%size;
        ll t = array[i];
        array[i] = array[j];
        array[j] = t;
    }
}
 
ll SQRT(ll n){
  ll ok,ng,mid;
  ng=n+1;
  if(303700500<ng)ng=303700500;
  ok=0;
  while(abs(ok-ng)>1){
    mid=(ok+ng)/2;
    if(mid*mid<=n){
      ok=mid;
    }
    else{
      ng=mid;
    }
  }
  return ok;
}
 
struct UnionFind
{
  vector<int> par;
  vector<int> sizes;
  UnionFind(int n) : par(n), sizes(n, 1) {
    rep(i,n) par[i] = i;
  }
  int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
  }
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (sizes[x] < sizes[y]) swap(x, y);
    par[y] = x;
    sizes[x] += sizes[y];
  }
  bool same(int x, int y) {
    return find(x) == find(y);
  }
  int size(int x) {
    return sizes[find(x)];
  }
};
 
map< int64_t, int > prime_factor(int64_t n) {
  map< int64_t, int > ret;
  for(int64_t i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}
 
bool is_prime(int64_t x) {
  if(x==1)return false;
  for(int64_t i = 2; i * i <= x; i++) {
    if(x % i == 0) return false;
  }
  return true;
}
 
struct edge{ll to, cost;};
struct Dij{
  ll V;
  vector<vector<edge> > G;
  vector<ll> d;
 
  Dij(ll n){
    init(n);
  }
 
  void init(ll n){
    V = n;
    G.resize(V);
    d.resize(V);
    rep(i,V){
      d[i] = INF;
    }
  }
 
  void add(ll s, ll t, ll cost){
    edge e;
    e.to = t, e.cost = cost;
    G[s].push_back(e);
  }
 
  void find(ll s){
    rep(i,V){
      d[i] = INF;
    }
    d[s] = 0;
    priority_queue<LP,vector<LP>, greater<LP> > que;
    que.push(LP(0,s));
    while(!que.empty()){
      LP p = que.top(); que.pop();
      ll v = p.second;
      if(d[v]<p.first) continue;
      for(auto e : G[v]){
        if(d[e.to]>d[v]+e.cost){
          d[e.to] = d[v]+e.cost;
          que.push(LP(d[e.to],e.to));
        }
      }
    }
  }
};

struct BF{
  ll V;
  vector<vector<edge>> G;
  vector<ll> d;

  BF(ll n){
    init(n);
  }
  
  void init(ll n){
    V = n;
    G.resize(V);
    d.resize(V);
    rep(i,V){
      d[i]=INF;
    }
  }
  
  void add(ll s, ll t, ll cost){
    edge e;
    e.to=t,e.cost=cost;
    G[s].push_back(e);
  }
  bool find(ll s){
    rep(i,V){
      d[i]=INF;
    }
    d[s]=0;
    rep(i,V){
      rep(j,V){
        ll m=G[j].size();
        rep(k,m){
          edge e=G[j][k];
          if(d[j]!=INF&&d[e.to]>d[j]+e.cost){
            d[e.to]=d[j]+e.cost;
            if(i==V-1)return true;
          }
        }
      }
    }
    return false;
  }
  
  bool find2(ll s,ll t){
    rep(i,V){
      d[i]=INF;
    }
    d[s]=0;
    rep(i,V*2){
      rep(j,V){
        ll m=G[j].size();
        rep(k,m){
          edge e=G[j][k];
          if(d[j]!=INF&&d[e.to]>d[j]+e.cost){
            if(i>=V-1&&e.to==t)return true;
            else if(i>=V-1)d[e.to]=-INF;
            else d[e.to]=d[j]+e.cost;
          }
        }
      }
    }
    return false;
  }
};

ll dist[400][400];

void WF(ll n){  
  rep(i,n)rep(j,n)rep(k,n)dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
}
 
struct bit{
  ll m;
  vector<ll> b;
  bit(ll i){
    m=i;
    b.resize(m+1);
  }
  ll num(ll i){
    return b[i];
  }
  ll sum(ll i){
    ll s=0;
    while(i>0){ 
      s+=b[i];
      i-=i&-i;
    }
    return s;
  }
  void add(ll i, ll x){
    while(i<=m){
      b[i]+=x;
      i+=i&-i;
    }
  }
};

struct Segtree{
  ll N=1;
  ll elem;
  vector<ll> value;
  ll calc(ll s,ll t){
    return min(s,t); 

  }
  Segtree(ll n,ll Elem){
    elem=Elem;
    while(N<n)N*=2;
    value.assign(2*N-1,elem);
  }
  void update(ll i,ll x) {
    i+=N-1;
    value[i]=x;
    while(i>0){
      i=(i-1)/2;
      value[i]=calc(value[i*2+1],value[i*2+2]);
    }
  }
  ll query(ll a,ll b,ll k,ll l,ll r){
    if(r<=a||b<=l)return elem;
    if(a<=l&&r<=b)return value[k];
    else{
      ll c1=query(a,b,2*k+1,l,(l+r)/2);
      ll c2=query(a,b,2*k+2,(l+r)/2,r);
      return calc(c1,c2);
    }
  }
  ll find(ll s,ll t){
    return query(s,t+1,0,0,N);
  }
  ll v(ll s){
    return query(s,s+1,0,0,N);
  }
};

string LCS(string s,string t){
  ll x=s.size();
  ll dp[x+1][x+1]={},m[x+1][x+1]={},a,b;
  string h;
  stack<char>p;
  a=s.size();
  b=t.size();
  rep(i,a){
    rep(j,b){
      if(s[i]==t[j]){
        dp[i+1][j+1]=dp[i][j]+1;
        m[i+1][j+1]=0;
      }
      dp[i+1][j+1]=max({dp[i+1][j],dp[i][j+1],dp[i+1][j+1]});
      if(dp[i+1][j+1]==dp[i+1][j]){
        m[i+1][j+1]=1;
      }
      if(dp[i+1][j+1]==dp[i][j+1]){
        m[i+1][j+1]=2;
      }
    }
  }        
  while(a>=1&&b>=1){
    if(m[a][b]==0){
      p.push(s[a-1]);
      a--;
      b--;
    }
    else if(m[a][b]==1)b--;
    else a--;
  }
  while(p.size()){
    h+=p.top();
    p.pop();
  }
  return h;
}

struct Edge{
    ll src, dst;
    ll cap;
    Edge(ll src_, ll dst_, ll cap_) :
        src(src_), dst(dst_), cap(cap_) { }
};

struct EK{
    ll n;
    vector<ll> prev, dist;
    vector<vector<ll>> cap, flow;
    vector<vector<ll>> g;
    ll inf;
    EK(ll n)
        : n(n), cap(n, vector<ll>(n)), flow(n, vector<ll>(n)),
          g(n, vector<ll>()), inf(INF){}
    EK(const vector<vector<Edge>> &graph){
        *this = EK(graph.size());
        rep(i,n) for(auto &e : graph[i]) add(e.src, e.dst, e.cap);
    }
    void add(ll u, ll v, ll c){
        cap[u][v] += c; cap[v][u] += c; flow[v][u] += c;
        g[u].push_back(v); g[v].push_back(u);
    }
    ll find(ll s, ll t){
        ll res = 0, aug = 1;
        while(aug > 0){
            prev.assign(n, -1); dist.assign(n, inf); dist[s] = 0;
            res += (aug = augment(s,t));
        }
        return res;
    }
    ll augment(ll s, ll t){
        queue<pair<ll,ll>> q;
        q.emplace(s,inf);
        ll aug = 0;
        while(q.size()){
            ll v; ll f;
            tie(v,f) = q.front(); q.pop();
            if(v == t){ aug = f; break; }
            for(const ll& d : g[v]){
                if(dist[d] <= dist[v] + 1 || cap[v][d] - flow[v][d] == 0) continue;
                dist[d] = dist[v] + 1; prev[d] = v;
                q.emplace(d, min(f, cap[v][d] - flow[v][d]));
            }
        }
        if(aug == 0) return 0;
        ll c = t;
        while(c != s){
            ll p = prev[c];
            flow[p][c] += aug; flow[c][p] -= aug;
            c = p;
        }
        return aug;
    }
};

ll LIS(vector<ll>a) {
  ll n=a.size();
  ll dp[n];
  fill(dp,dp+n,INF);
  rep(i,n)*lower_bound(dp,dp+n,a[i])=a[i];
  return lower_bound(dp,dp+n,INF)-dp;
}

struct RMQ{
  ll N=1;
  ll elem=INF;
  vector<LP> value;
  RMQ(ll n){
    while(N<n)N*=2;
    rep(i,2*N-1)value.PB(MP(elem,INF));
  }
  void update(ll i,ll x) {
    i+=N-1;
    value[i]=MP(x,i+1-N);
  }
  void UPDATE(){
    per(i,N-1)value[i]=min(value[i*2+1],value[i*2+2]);
  }
  LP query(ll a,ll b,ll k,ll l,ll r){
    if(r<=a||b<=l)return MP(INF,INF);
    if(a<=l&&r<=b)return value[k];
    return min(query(a,b,2*k+1,l,(l+r)/2),query(a,b,2*k+2,(l+r)/2,r));
  }
  ll find(ll s,ll t){
    return query(s,t+1,0,0,N).S;
  }
};

struct LCA{
  vector<vector<ll>>v;
  vector<ll>vs;
  vector<ll>id;
  vector<ll>depth;
  vector<RMQ>r;
  ll k;
  ll N;
  LCA(ll n){
    v.resize(n);
    id.resize(n);
    r.PB((RMQ){2*n-1});
    N=n;
  }
  void add(ll s,ll t){
    v[s].PB(t);
  }
  void root(ll n){
    k=0;
    dfs(n,0);
    r[0].UPDATE();
  }
  void dfs(ll n,ll d){
    id[n]=k;
    ll m=v[n].size();
    rep(i,m){
      vs.PB(n);
      depth.PB(d);
      r[0].update(k,d);
      k++;
      dfs(v[n][i],d+1);
    }
    vs.PB(n);
    depth.PB(d);
    r[0].update(k,d);
    k++;
  }
  ll find(ll s,ll t){
    return vs[r[0].find(min(id[s],id[t]),max(id[s],id[t]))];
  }
  ll dist(ll s,ll t){
    return depth[id[s]]+depth[id[t]]-2*depth[r[0].find(min(id[s],id[t]),max(id[s],id[t]))];
  }
};



int main(){
  ll t;
  cin >> t;
  rep(_,t){
    ll n,k;
    cin >> n >> k;
    vector<ll>ans;
    vector<ll>v;
    if(n<=63&&id3(2,n-1)<k){
      printf("-1\n");
      goto A;
    }
    rep(i,n){
      v.PB(n-i);
      if(i>=63||DEC(k-1,2,i)==0){
        reverse(all(v));
        rep(j,v.size())ans.PB(v[j]);
        v.clear();
      }
    }
    reverse(all(ans));
    rep(i,n)printf("%lld ",ans[i]);
    printf("\n");
    A:;
  }
}