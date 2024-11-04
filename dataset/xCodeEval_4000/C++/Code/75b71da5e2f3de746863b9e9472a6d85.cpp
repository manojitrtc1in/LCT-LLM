#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define vi             vector<ll> 
#define mi             map<ll,ll>
#define pi             pair<ll,ll>
#define pqueue         priority_queue<ll,vector<ll>,greater<ll>>
#define si             set<ll>
#define endl            "\n"
#define ins             insert 
#define hell             1000000007
#define PI              3.1415926535897932384
#define ll              long long 
#define f               first
#define s              second
#define pb             push_back
#define pp             pop_back
#define fr(n)          for(ll i=0;i<n;i++)
#define FAST           ios_base::sync_with_stdio(false); cin.tie(NULL);
#define narak             998244353 
#define decimal(n)  std::cout << std::fixed;std::cout << std::setprecision(n);
#define make make_pair
#define mem0(a)         memset(a,0,sizeof(a))
#define mem1(a)         memset(a,-1,sizeof(a))
#define ALL(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))  
#define REVERSE(v) reverse(ALL(v))
#define maxc(v) max_element(all(v))
#define minc(v) min_element(all(v))
#define GCD(m,n) __gcd(m,n)
#define LCM(m,n) m*(n/GCD(m,n))
#define sz(a) (ll)a.size()
#define loop(i,a,b) for(ll i=a;i<=b;i++)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>





const ll N=105;
vector<ll>g[N];
ll child[N][N];
ll has[N][N];
ll n;
ll vis[N];
ll dist[N];


ll power(ll x,ll y,ll p)
{
    ll res = 1; 

    x = x % p; 

    while (y > 0) 
    {
        

        if (y & 1)
            res = (res * x) % p;
        

        y = y >> 1; 

        x = (x * x) % p;
    }
    return res;
}
ll modInverse(ll n,ll p)
{
    return power(n, p - 2, p);
}



vector<ll>fac(105);
void build()
{
    fac[0]=1;
    fac[1]=1;
    for(ll i=2;i<=100;i++)
    {
        fac[i]=i*fac[i-1];
        fac[i]%=N;
    }

}






ll ncr(ll n,ll r,ll p)
{
    

    if (n < r)
        return 0;
    if(n==r)
        return 1;
    

    if (r == 0)
        return 1;
 
    

    

    

    
    ll val=(fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
    

    return val;
}



void dfs(ll x,ll y)
{
    child[x][0]++;
    vis[x]=1;
    has[x][0]++;
    for(ll y:g[x])
    {
        if(vis[y]) continue;
        dfs(y,x);
        for(ll j=0;j<=n;j++)
        {
            if(child[y][j])
            has[x][j+1]++;
            child[x][j+1]+=child[y][j];
        }
    }
    
}


void solve(ll nn)
{
    ll k;
    cin>>n>>k;
    string str;
    getline(cin,str);
    
    ll ans=0;
    mem0(child);
    mem0(has);
    mem0(vis);
    
    for(ll i=1;i<=n;i++)
    {
        g[i].clear();
    }
    for(ll i=1;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        g[x].pb(y); 
        g[y].pb(x);
    }
    
    
    if(k==2)
    {
        ans=(n)*(n-1)/2;
        cout<<ans<<endl;
        return;
    }
    
    for(ll i=1;i<=n;i++)
    {
        mem0(vis);
        mem0(child);
        dfs(i,0);
        
        ll temp=0;
        
        
        for(ll j=1;j<=n;j++)
        {
            ll dp[n+1];
            mem0(dp);
            dp[0]=1;
            
            for(ll kk=0;kk<g[i].size();kk++)
            {
                ll xx=g[i][kk];
                if(child[xx][j-1]==0)
                continue;
                
                for(ll l=k;l>0;l--)
                {
                    dp[l]+=dp[l-1]*child[xx][j-1];
                    dp[l]%=hell;
                }
                
                
            }
            
            ans+=dp[k];
            ans%=hell;
            
            
                
            
        }
        
        
        
        
        
        
    }
    
    cout<<ans<<endl;
}

 
int main()
{ 
   decimal(15);
   FAST;
   build();
   ll t;
   t=1;
   cin>>t;  
   for(ll i=1;i<=t;i++)
   solve(i);
   return 0;
}