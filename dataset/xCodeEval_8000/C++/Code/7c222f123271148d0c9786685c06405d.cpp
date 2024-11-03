





#include <bits/stdc++.h>
#define ff                 first
#define ss                 second
#define ll                 long long
#define ii                 int, int
#define pii                pair<ii>
#define vi                 vector<int>
#define vvi                vector<vi>
#define si                 set<int>
#define vpii               vector<pii>
#define vs                 vector<string>
#define gi                 greater<int>
#define mii                map<ii>
#define maxheap            priority_queue<int>
#define minheap            priority_queue<int, vi, gi>
#define all(x)             x.begin(), x.end()
#define reverse(a)         reverse(all(a))
#define setbits(x)         __builtin_popcountll(x)
#define zrobits(x)         __builtin_ctzll(x)
#define gcd                __gcd
#define PI                 3.14159265358979323846264338
#define inf                LONG_LONG_MAX
#define pcs(x,y)           fixed << setprecision(y) << x
#define lower(s)           transform(all(s), s.begin(),::tolower)
#define upper(s)           transform(all(s), s.begin(),::toupper)
#define FI(i,x,y,inc)      for(int i = x; i < y; i += inc)
#define F(i,x)             FI(i,0,x,1)
#define RF(i,n)            for(int i=n-1;i>=0;i--)
using namespace std;


void swap(int &x, int &y) {int temp = x; x = y; y = temp;}







bool funCycle(vector<ll>&vis,vector<ll>&viss,vector<ll>adj[],ll i,ll n){
  for(auto x:adj[i]){
      if(viss[x]) return 1;
      if(!vis[x]){
          viss[x]=1;
          vis[x]=1;
          bool t=funCycle(vis,viss,adj,x,n);
          if(t) return 1;
          viss[x]=0;
      }
      
  }
  return 0;
}  
bool isCycleDAG(vector<ll>adj[],ll n){
    vector<ll>vis(n+1,0);
    vector<ll>viss(n+1,0);
    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            viss[i]=1;
            if(funCycle(vis,viss,adj,i,n)) return 1;
            viss[i]=0;
        }
    }
    return 0;
}












void funLengthDAG(vector<ll>&dp,vector<ll>adj[],ll i,ll n){
  if(adj[i].size()==0) {dp[i]=1; return;}
  for(auto x:adj[i]){
      if(dp[x]==0) funLengthDAG(dp,adj,x,n); 
      dp[i]=max(dp[i],dp[x]+1);
  }
}
ll longestPathDAG(vector<ll>adj[],ll n){
    vector<ll>dp(n+1,0);
    ll ans=0;
    for(ll i=1;i<=n;i++){
      if(dp[i]==0){
          funLengthDAG(dp,adj,i,n);
          ans=max(ans,dp[i]);
      }
    }
  return ans;
}









vector<ll> buildTopo(vector<ll>adj[],ll n,vector<ll>indegree){
    vector<ll>topo;
    queue<ll>q;
    for(ll i=1;i<=n;i++){
        if(indegree[i]==0) q.push(i);
    }
    while(!q.empty()){
        ll i=q.front();
        q.pop();
        topo.push_back(i);
        for(auto x:adj[i]){
            indegree[x]--;
            if(indegree[x]==0) q.push(x);
        }
    }
    return topo;
}



vector<ll> nextGreater(vector<ll>& arr, int n) {
  stack<ll> s;	
    vector<ll> result(n, n);
  for (int i = 0; i < n; i++) {
    while (!s.empty() && arr[s.top()] < arr[i]) {
      result[s.top()] = i;	
      s.pop();
    }
    s.push(i);
  }
    return result;
}
 
vector<ll> prevGreater(vector<ll>& arr, int n) {
  stack<ll> s;	
    vector<ll> result(n, -1);
  for (int i = n - 1 ; i >= 0; i--) {
    while (!s.empty() && arr[s.top()] < arr[i]) {
      result[s.top()] = i;	
      s.pop();
    }
    s.push(i);
  }
    return result;
}




int isPrime(int N){
 if(N<2 || (!(N&1) && N!=2))
      return 0;
  for(int i=3; i*i<=N; i+=2){
     if(!(N%i))
         return 0;
 }
  return 1;
}




void fillPrimes(vector<int>& prime, int high)
{
    bool ck[high + 1];
    memset(ck, true, sizeof(ck));
    ck[1] = false;
    ck[0] = false;
    for (int i = 2; (i * i) <= high; i++) {
        if (ck[i] == true) {
            for (int j = i * i; j <= high; j = j + i) {
                ck[j] = false;
            }
        }
   }
    for (int i = 2; i * i <= high; i++) {
        if (ck[i] == true) {
            prime.push_back(i);
        }
    }
}

vector<bool> segmentedSieve(int low, int high)
{
    vector<bool>prime(high-low+1,true);
    vector<int> chprime;
    fillPrimes(chprime, high);
    for (int i : chprime) {
        int lower = (low / i);     
        if (lower <= 1) {
            lower = i + i;
        }
        else if (low % i) {
            lower = (lower * i) + i;
        }
        else {
            lower = (lower * i);
        }
        for (int j = lower; j <= high; j = j + i) {
            prime[j - low] = false;
        }
    }
    return prime;
}




const double eps = 1e-7;
const ll N = 5e5 + 7, mod = 1e9 + 7;
ll POW(ll a, ll b, ll mod)
{
    a %= mod;
    ll r = 1;
    for(ll i = b; i > 0; i >>= 1)
    {
        if(i & 1)
            r = (r * a) % mod;
        a = (a * a) % mod;
    }
    return r;
}




ll f[N];
void init(){
  f[0] = 1;
  for(ll  i = 1; i < N; i++)
  {
      f[i] = (f[i - 1] * i) % mod;
  }
}
ll nCr(ll n, ll r)
{
    if(n < r)
        return 0;
    return f[n] * POW(f[n - r] * f[r], mod - 2, mod) % mod;
}
ll nPr(ll n, ll r)
{
    return nCr(n, r) * f[r] % mod;
}




vector<ll> getFactors(ll n)
{
    vector<ll>v;
    for (ll i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            if (n/i == i) v.push_back(i);
            else {v.push_back(i); v.push_back(n/i);}    
        }
    }
    return v;
}




ll p=1e9+7;
ll modadd(ll a, ll b) {a = a % p; b = b % p; return (((a + b) % p) + p) % p;}
ll modmul(ll a, ll b) {a = a % p; b = b % p; return (((a * b) % p) + p) % p;}
ll modsub(ll a, ll b) {a = a % p; b = b % p; return (((a - b) % p) + p) % p;}





typedef unsigned long long ull;
typedef long double lld;
#define debug(x) cout << #x<<' '; _print(x); cout << endl;
void _print(ll t) {cout << t;}
void _print(int t) {cout << t;}
void _print(string t) {cout << t;}
void _print(char t) {cout << t;}
void _print(lld t) {cout << t;}
void _print(double t) {cout << t;}
void _print(ull t) {cout << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cout << '{'; _print(p.ff); cout << ','; _print(p.ss); cout << '}';}
template <class T> void _print(vector <T> v) {cout << '['<<' '; for (T i : v) {_print(i); cout << ' ';} cout << ']';}
template <class T> void _print(set <T> v) {cout << '['<<' '; for (T i : v) {_print(i); cout << ' ';} cout << ']';}
template <class T> void _print(multiset <T> v) {cout << '['<<' '; for (T i : v) {_print(i); cout << ' ';} cout << ']';}
template <class T, class V> void _print(map <T, V> v) {cout << '['<<' '; for (auto i : v) {_print(i); cout << ' ';} cout << ']';}









#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define os tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>













int bit[200005];
 
void update(int i, int x){
    for(; i < 200005; i += (i&-i))
        bit[i] += x;
}
 
int sum(int i){
    int ans = 0;
    for(; i > 0; i -= (i&-i))
        ans += bit[i];
    return ans;
}








struct SegTree
{
    ll N;
    vector<ll> st;
    
    void init(ll n)
    {
        N = n;
        st.resize(4 * N + 5);
    }

     

    void Build(ll node, ll L, ll R,ll arr[])
    {
        if (L == R)
        {
            st[node] = arr[L];
            return;
        }
        ll M = (L + R) / 2;
        Build(node * 2, L, M, arr);
        Build(node * 2 + 1, M + 1, R, arr);
        if(f==0) st[node] = st[node * 2] | st[node * 2 + 1];
        else st[node] = st[node * 2] ^ st[node * 2 + 1];
    }

    void Update(ll node, ll L, ll R, ll pos, ll val)
    {
        if (L == R)
        {
            st[node] = val;
            return;
        }
        int M = (L + R) / 2;
        if (pos <= M)
            Update(node * 2, L, M, pos, val);
        else
            Update(node * 2 + 1, M + 1, R, pos, val);

        if(f==0) st[node] = st[node * 2] | st[node * 2 + 1];
        else st[node] = st[node * 2] ^ st[node * 2 + 1];
    }
    ll Query(ll node, ll L, ll R, ll i, ll j)
    {
        if (j < L || i > R)
            return 0;
        if (i <= L && R <= j)
            return st[node];
        int M = (L + R) / 2; 
        return max(Query(node * 2, L, M, i, j), Query(node * 2 + 1, M + 1, R, i, j));
          
    }

     

    ll query(ll l, ll r) { return Query(1LL, 1LL, N, l, r); }

    void update(ll pos, ll val, ll f) { Update(1LL, 1LL, N, pos, val); }

    void build(ll arr[]) { Build(1LL, 1LL, N, arr); }

};

















ll dfs_child(ll i,map<ll,ll>&vis,map<ll,ll>&child,vector<ll>adj[]){
    vis[i]=1;
    for(auto x:adj[i]){
        if(!vis[x]) child[i]+=dfs_child(x,vis,child,adj);
    }
    return 1+child[i];
}


ll dfs(ll i,map<ll,ll>&vis,map<ll,ll>&child,vector<ll>adj[]){
    ll ans=0;
    ll children=0;
    for(auto x:adj[i]){
        if(!vis[x]){
            children++;
        }
    }
    vector<ll>v;
    if(children==2){
        for(auto x:adj[i]){
            if(!vis[x]){
                vis[x]=1;
                v.push_back(x);
            }
        }
        ans=max(ans,child[v[0]]+dfs(v[1],vis,child,adj));
        ans=max(ans,child[v[1]]+dfs(v[0],vis,child,adj));
        return ans;
    }
    else{
        for(auto x:adj[i]){
            if(!vis[x]){
                vis[x]=1;
                return child[x];
            }
        }
    } 
    return 0;
}


void solve() {


    ll n;
    cin>>n;
    vector<ll>adj[n+1];
    F(i,n-1){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(adj[1].size()==1) {cout<<n-2<<endl; return;}
    ll ans=0;
    map<ll,ll>vis,child;
    vis[1]=1;
    for(auto x:adj[1]) dfs_child(x,vis,child,adj);
    vis.clear();
    vis[1]=1;
    cout<<dfs(1,vis,child,adj)<<endl;


    return;


}




signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
