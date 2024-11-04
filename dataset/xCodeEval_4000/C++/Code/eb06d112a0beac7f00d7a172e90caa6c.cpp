#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <vector>
#include<cstdio>
#include <math.h>
#include <vector>
#include <deque>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stdio.h>
#include <cstdlib>
#include <random>
#include <chrono>
#include <fstream>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cstring>
#include <cmath>
#include <functional>
#include <numeric>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <memory>
#include <queue>
#include <random>
#define ff first
#define se second
#define pb push_back
#define nn 1100
#define mt make_tuple
#define mp make_pair
#define ll long long int
#define db double
#define ldb long double
#define inf 1000000000000000000ll
#define logn 20
#define mod1 mod
#define M 1000000007
#define sqr(a) a*1ll*a
#define nullp mp(-1,-1)
#define set0(a) memset(a,0,sizeof a)
#define init(a) memset(a,-1,sizeof a)
#define cmp 1e-16
#define endl '\n'
#define ff first
#define se second
#define pb push_back
#define nn 1100
#define mt make_tuple
#define mp make_pair
#define ll long long int
#define db double
#define ldb long double
#define inf 1000000000000000000ll
#define logn 20
#define sqr(a) a*1ll*a
#define nullp mp(-1,-1)
#define set0(a) memset(a,0,sizeof a)
#define init(a) memset(a,-1,sizeof a)
#define cmp 1e-16
#define li long long int
#define f first
#define s second
#define ar array
#define pb push_back
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = l; i <r; i++)
#define readi(x) scanf("%d",&x)
#define  reads(x)  scanf("%s", x)
#define readl(x) scanf("%I64d",&x)
#define rep(i,n) for(i=0;i<n;i++)
#define revp(i,n) for(i=(n-1);i>=0;i--)
#define myrep1(i,a,b) for(i=a;i<=b;i++)
#define myrep2(i,a,b) for(i=b;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
#define MINN -1000000000000000000
#define INTMAX 1000001000
#define pic pair<int,char>
#define lgn 20
#define ddouble long double
#define minus minu
#define PI 3.1415926535
#define lgn 20
#define ff first
#define se second
#define pb push_back
#define nn 1100
#define mt make_tuple
#define mp make_pair
#define db double
#define ldb long double
#define inf 1000000000000000000ll
#define logn 20
#define sqr(a) a*1ll*a
#define nullp mp(-1,-1)
#define set0(a) memset(a,0,sizeof a)
#define init(a) memset(a,-1,sizeof a)
#define cmp 1e-16
#define p(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define sl(x) scanf("%lld", &x)
#define sf(x) scanf("%lf", &x)
#define bitcount __builtin_popcountll
#define INF 1e18+9
#define mp make_pair
#define fo(i,n) for(int i=0;i<n;i++)
#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))
#define SQR(a)          ((a)*(a))
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define ABS(x)          ((x)<0?-(x):(x))
#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())
#define fRead(x)        freopen(x,"r",stdin)
#define fWrite(x)       freopen (x,"w",stdout)
#define LL              long long
#define ULL             unsigned long long
#define sqr(a) a*1ll*a
#define nullp mp(-1,-1)
#define set0(a) memset(a,0,sizeof a)
#define init(a) memset(a,-1,sizeof a)
#define cmp 1e-16
#define input1(a) long long int a;cin>>a;
#define input2(p,q,r) long p,q,r;cin>>p>>q>>r;
#define input3(i,a) for(long long int i=a;i<=1e18;i++)
#define input4(i,p)for(int i=0;i<p.length();i++)
#define vll vector<ll>
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define getx 
#define putx putchar_unlocked
#define in(n) scanf("%d",&n)
#define inl(n) scanf("%lld",&n)
#define out(n) printf("%d",n);
#define outl(n) printf("%lld",n);
#define el putchar('\n')
#define sp putchar(' ')
#define fin  cin.ignore(numeric_limits<streamsize>::max(),'\n')
#define fout cout.flush()
#define google cout<<"Case #"<<countu<<": "
#define S(t) (ll)t.size()
#define bl '\n'
#define nl cout<<bl
#define cout1(a) cout<<a<<bl
#define cout2(a,b) cout<<a<<" "<<b<<bl
#define cout3(a,b,c) cout<<a<<" "<<b<<" "<<c<<bl
#define cout4(a,b,c,d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<bl
#define print(azz,szz,ezz) for(ll i=szz;i<=ezz;i++){ cout<<azz[i]<<" "; }
#define rprint(azz,szz,ezz) for(ll i=szz;i>=ezz;i--){ cout<<azz[i]<<" "; }
#define input(azz,szz,ezz) sfor(pzz,szz,ezz) cin>>azz[pzz]
#define ldb long double
#define db double
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define mk make_pair
#define pldb pair<ldb,ldb>
#define fi first
#define se second
#define vull vector<ull>
#define vll vector<ll>
#define vb vector<bool>
#define vldb vector<ldb>
#define vpll vector< pll >
#define vpldb vector< pldb >
#define mldb map<ldb,ldb>
#define umll unordered_map<ll,ll>
#define sll set<ll>
#define usll unordered_set<ll>
#define sfor(i,azz,bzz) for (ll i = (azz); i <= (bzz); ++i)
#define rfor(i,bzz,azz) for (ll i = (bzz); i >= (azz); --i)
#define sim template < class c
#define ris return * this
#define M2 998244353
#define ld long double
#define fl(i,a,b) for(ll i=a;i<b;i++)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define vll vector<ll>
#define sz(s) (int)s.size()
#define ldb long double
#define NINF        LLONG_MIN
#define PII         3.141592653589793238462643383279502884197169399375
#define vp(vi,x)        cin>>x;   vi.pb(x);  
#define bsearch(a,x)      binary_search(all(a),x)
#define LB(a,x)        (std::lower_bound(all(a),x)-a.B)
#define UB(a,x)        (std::upper_bound(all(a),x)-a.B)
#define smallest(a)       *min_element(a.begin(),a.end())
#define largest(a)        *max_element(a.begin(),a.end())
#define all(a)         a.begin(), a.end()
#define sortdesc(a)       sort(a.begin(),a.end(),greater<ll>())
#define ps(x, y)        fixed << setprecision(y) << x
#define E          end()
#define B          begin()
#define yes         cout<<"YES\n"
#define no          cout<<"NO\n"
#define gcd         __gcd
#define lcm(a,b)       ((a*b)/__gcd(a,b))
#define ff          first
#define ss          second
#define pb          push_back
#define mp          make_pair
#define mii         map<ll,ll>
#define mci         map<char,ll>
#define msi         map<string,ll>
#define pqb         priority_queue<ll>
#define sg string
#define emb emplace_back
#define my_love ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define bug(x) cout<<#x<<" "<<x<<"\n"
#define pqs         priority_queue<ll, vi, greater<ll>>
#define w(x)          int x;    cin >> x;  while (x--)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define for0(i, n)        for (ll i = 0; i < n; i++)
#define for1(i, n)        for (ll i = 1; i <= n; i++)
#define loop(i, a, b)       for (ll i = a; i < b; i++)
#define bloop(i, a, b)       for (ll i = a; i >= b; i--)   
#define trav(g,arr)       for(auto g: arr) {cout<<g<<sp;} cout<<endl;
#define MAX 1000001
#define sgraph 200100LL
#define segment 800100LL
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" |\
                                     "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" |\
                                     "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" |\
                                     "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<< c<<" |\
                                 "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
 
#define shandom_ruffle random_shuffle
#define mod2 100000009ll
#define endl '\n'
#define mod3  mod
#define printv(v) for(ll i=0;i<v.size();i++) \
                        out v[i]<<" ";\
                        out "\n";  

#define inv(v) for(ll i=0;i<v.size();i++)\
                        in v[i];
#define goog(tno) cout << "Case #" << tno <<": "
#define read(x) int x; cin >> x
#define fr(a,b) for(int i = a; i < b; i++)



using namespace std;
using namespace __gnu_pbds;
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << endl;
        
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define trace(...)
#endif




void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<ll,ll> pll;
typedef pair<long double,long double> pdd;
template<class T>
using max_pq = priority_queue<T>;
template<class T>
using min_pq = priority_queue<T,vector<T>,greater<T>>;
typedef tree<int, null_type, less<int>, rb_tree_tag, 
tree_order_statistics_node_update> OST;

template<class T> T gcd(T a,T b){return (b==0)?a:gcd(b,a%b);}
ll pow(ll a,ll p,ll m)
{ll res=1;while(p>0){if(p&1)res=(res*a)%m;a=(a*a)%M;p>>=1;}
return res;}


const ldb pi=3.141592653589793238462643383;
const int MAXN = (int)((1e5) + 10);
using vi = vector<int>;
template<typename T>
istream &operator>>(istream &in, vector<T> &vec) {
    for (auto &x : vec) {
        in >> x;
    }
    return in;
}

ll divide(string s, ll x){
    vector <ll> a;
    for(int i = 0; i < s.size(); ++i){
        a.pb((ll)s[i] - '0');
    }
    ll temp = 0;
    for(int i = 0; i < a.size(); ++i){
        temp = temp *10 + a[i];
        if(temp >= x){
            temp %= x;
        }
    }
    return temp;
}

int binexp1(int a, int b, int m){
    int result = 1;
    while(b>0){
        if(b & 1){
            result = (result  * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return result;
}

long long multiply(long long a, long long b, long long m){
    long long result = 0;
    while(b>0){
        if(b & 1){
            result = result + a;
            result %= m;
        }
        a <<= 1;
        a %= m;
        b >>= 1;
    }
    return result;
}

long long binexp2(long long a, long long b, long long m){
    long long result = 1;
    while(b>0){
        if(b & 1){
            result = multiply(result, a, m);
        }
        a = multiply(a, a, m);
        b >>= 1;
    }
    return result;
}


const int P = (1 << 21) + 5;
int  a[P];
LL cnt[P];
LL dp[P];

LL call(int mask,int m){
    if(mask == 0)return 0;
    if(dp[mask] != -1)return dp[mask];
    LL ret = 0;
    for(int i = 0;i < m;i++){
        if(mask & (1 << i)){
            ret = max(ret,(1LL << i) * cnt[mask] + call(mask ^ (1 << i),m));
        }
    }
    return dp[mask] = ret;
}
ll min(ll a,ll b)
{
    return (a<=b?a:b);
}
ll max(ll a,ll b)
{
    return (a>=b?a:b);
}
ll gd(ll a,ll b)
{
    if(b==0)
    return a;
    return gd(b,a%b);
}
ll pwr(ll a,ll b)
{
    ll res=0;
    while(b)
    {
        if(b%2==1)
        {
            res*=a;
        }
        a=a*a;
        b>>=1;
    }
    return res;
}



struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n),  t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};


#define V 5 






int minKey(int key[], bool mstSet[])  
{  
    

    int min = INT_MAX, min_index;  
  
    for (int v = 0; v < V; v++)  
        if (mstSet[v] == false && key[v] < min)  
            min = key[v], min_index = v;  
  
    return min_index;  
}  
  




void printMST(int parent[], int graph[V][V])  
{  
    cout<<"Edge \tWeight\n";  
    for (int i = 1; i < V; i++)  
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";  
}  
  






void primMST(int graph[V][V])  
{  
    

    int parent[V];  
      
    

    int key[V];  
      
    

    bool mstSet[V];  
  
    

    for (int i = 0; i < V; i++)  
        key[i] = INT_MAX, mstSet[i] = false;  
  
    

    

    key[0] = 0;  
    parent[0] = -1; 

  
    

    for (int count = 0; count < V - 1; count++) 
    {  
        

        

        int u = minKey(key, mstSet);  
  
        

        mstSet[u] = true;  
  
        

        

        

        

        for (int v = 0; v < V; v++)  
  
            

            

            

            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])  
                parent[v] = u, key[v] = graph[u][v];  
    }  
  
    

    printMST(parent, graph);  
}

void coder_himadri(){
     FIO;             
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
}



long long int n;

int32_t main(){
    FIO;
    coder_himadri();
    w(t)
    
    {    
    	 vector<ll> s1;
        vector<ll> s2;
        for(int axy=0; axy<n; axy++){
            int abcd = 1;
            int bcde = 0;
            int teemp;
            teemp  = abcd;
            abcd = bcde; 
            bcde = teemp;
            break;
        }
        int n;
        cin>>n;
        map<ll,ll> mp;
        for(int axy=0; axy<n; axy++){
            int abcd = 1;
            int bcde = 0;
            int teemp;
            teemp  = abcd;
            abcd = bcde; 
            bcde = teemp;
            break;
        }
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            while(true){
                int abc = 0;
                abc++;
                abc++;
                abc--;
                break;
            }
            if(mp[x]==1){
                s2.push_back(x);
            }
            else{
                mp[x]=1;
                s1.push_back(x);
            }
        }
        while(true){
            int abc = 0;
            abc++;
            abc++;
            abc--;
            break;
        }
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        for(auto x:s1){
            cout<<x<<" ";
        }
        for(auto x:s2){
            cout<<x<<" ";
        }
        cout<<endl;
    }




        
    
    
    return 0;
}