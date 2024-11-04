#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ff first
#define ss second
#define ii insert
#define fastio ios::sync_with_stdio(false), cin.tie(NULL);
const int N=1e6+5;
const int mod=1e9+7;
#define rep(i,j,k) for(ll i=j;i<=k;i++)
#define repr(i,j,k) for(ll i=j;i>=k;i--)
using namespace std;
vector<int>v[N];
ll row4[]={0,1,-1,0};

ll col4[]={-1,0,0,1};

int row8[] = {-1,-1,-1,0,0,0,1,1,1};

int col8[] = {-1,0,1,-1,0,1,-1,0,1};

ll vis[N]={0},parent[N],par[N],sz[N],mn[N],mx[N];
ll dp[N];
int n;
bool prime[100005];
ll ans;
bool isvalid(int i,int j)
{
    if(i>=0 && i<n && j>=0 && j<n)
    return true;
    return false;
}


void SieveOfEratosthenes(int n) 

{ dp[1]=0;
dp[2]=1;

    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }
    for (int p=3; p<=n; p++)
       {if (prime[p])
         dp[p]=dp[p-1]+1;
         else
         dp[p]=dp[p-1];
       }
}
bool checkprime(ll n)

{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
void dfs(ll k)
{
    vis[k]=1;
    for(ll i:v[k])
    {
        if(!vis[i])
        {
            ans++;
            dfs(i);
        }
    }
}
void findParents(int u, int par){

    parent[u] = par;
    for(auto x: v[u])
        if(x != par)
            findParents(x, u);
}
int funpar(int x)

{
   if(x!=par[x])
   {
      par[x]=funpar(par[x]);
   }
   return par[x];
}
void uniona(int x,int v)

{
   int a=funpar(x);
   int b=funpar(v);
   if(a==b)
   return;
   if(sz[a]>=sz[b])
   {
      sz[a]=sz[a]+sz[b];

      mx[a]=max(mx[a],mx[b]);

      mn[a]=min(mn[a],mn[b]);

      par[b]=a;

   }
   

   else
   {
      sz[b]=sz[b]+sz[a];

      mx[b]=max(mx[b],mx[a]);

      mn[b]=min(mn[b],mn[a]);

      par[a]=b;

   }
}
ll power(ll a,ll b){
    if(b==0){
        return 1;
    }
    ll temp=power(a,b/2)%mod;
    if(b%2==0){
        return (temp*temp)%mod;
    }
    else{
        return ((a*temp)%mod*temp)%mod;
    }
}
ll lcm(ll a,ll b)
{
    return (a*b)/__gcd(a,b);
}
int main() {
    fastio
 int t;
 cin>>t;
 while(t--)
 {
    ll n,m;
    cin>>n>>m;
    string s[n+2];
    rep(i,1,n)
    {
        cin>>s[i];
    }
    ll a[n+2][m+2];
    rep(i,1,n)
    {
        rep(j,0,m-1)
        {
            a[i][j+1]=s[i][j]-'0';
        }
    }
    
    vector<pair<ll,ll>>v1;
    vector<pair<ll,ll>>v0;
    ll cnt0=0,cnt1=0;
    ll ans=0;
    vector<pair<ll,ll>>fans;
    for(int i=1;i<n;i+=2)
    {
        for(int j=1;j<m;j+=2)
        {
            if(a[i][j]==1)
            {v1.pb({i,j});
            cnt1++;}
            else
            {v0.pb({i,j});
            cnt0++;
            }
            if(a[i][j+1]==1)
            {
                v1.pb({i,j+1});
                cnt1++;
            }
            else
            {
                v0.pb({i,j+1});
                cnt0++;
            }
            if(a[i+1][j]==1)
            {
                cnt1++;
                v1.pb({i+1,j});
            }
            else
            {
                cnt0++;
                v0.pb({i+1,j});
            }
            if(a[i+1][j+1]==1)
            {
                cnt1++;
                v1.pb({i+1,j+1});
            }
            else
            {
                cnt0++;
                v0.pb({i+1,j+1});
            }
            if(cnt1==3 && cnt0==1)
            {
                for(auto i:v1)
                {
                    fans.pb({i.ff,i.ss});
                }
                
                ans++;
            }
            else if(cnt1==2 && cnt0==2)
            {
                fans.pb({v1[0].ff,v1[0].ss});
                fans.pb({v0[0].ff,v0[0].ss});
                fans.pb({v0[1].ff,v0[1].ss});
                 fans.pb({v1[1].ff,v1[1].ss});
                fans.pb({v0[0].ff,v0[0].ss});
                fans.pb({v0[1].ff,v0[1].ss});
                ans+=2;
            }
            else if(cnt1==1 && cnt0==3)
            {
                fans.pb({v1[0].ff,v1[0].ss});
                fans.pb({v0[0].ff,v0[0].ss});
                fans.pb({v0[1].ff,v0[1].ss});
                fans.pb({v1[0].ff,v1[0].ss});
                fans.pb({v0[0].ff,v0[0].ss});
                fans.pb({v0[2].ff,v0[2].ss});
                fans.pb({v1[0].ff,v1[0].ss});
                fans.pb({v0[1].ff,v0[1].ss});
                fans.pb({v0[2].ff,v0[2].ss});
                ans+=3;
            }
            else if(cnt1==4 && cnt0==0)
            {
                fans.pb({v1[0].ff,v1[0].ss});
                fans.pb({v1[1].ff,v1[1].ss});
                fans.pb({v1[2].ff,v1[2].ss});
                fans.pb({v1[1].ff,v1[1].ss});
                fans.pb({v1[2].ff,v1[2].ss});
                fans.pb({v1[3].ff,v1[3].ss});
                fans.pb({v1[0].ff,v1[0].ss});
                fans.pb({v1[3].ff,v1[3].ss});
                fans.pb({v1[1].ff,v1[1].ss});
                fans.pb({v1[0].ff,v1[0].ss});
                fans.pb({v1[2].ff,v1[2].ss});
                fans.pb({v1[3].ff,v1[3].ss});
                ans+=4;
            }
            a[i][j]=0;
                a[i+1][j+1]=0;
                a[i][j+1]=0;
                a[i+1][j]=0;
            v1.clear();
            v0.clear();
            cnt0=0;
            cnt1=0;
        }
    }
    cnt0=0,cnt1=0;
    v0.clear();
    v1.clear();
    if(m%2)
    {
        for(int k=1;k<n;k+=2)
        {
            
            ll i=k,j=m-1;
            if(a[i][j]==1)
            {v1.pb({i,j});
            cnt1++;}
            else
            {v0.pb({i,j});
            cnt0++;
            }
            if(a[i][j+1]==1)
            {
                v1.pb({i,j+1});
                cnt1++;
            }
            else
            {
                v0.pb({i,j+1});
                cnt0++;
            }
            if(a[i+1][j]==1)
            {
                cnt1++;
                v1.pb({i+1,j});
            }
            else
            {
                cnt0++;
                v0.pb({i+1,j});
            }
            if(a[i+1][j+1]==1)
            {
                cnt1++;
                v1.pb({i+1,j+1});
            }
            else
            {
                cnt0++;
                v0.pb({i+1,j+1});
            }
            if(cnt1==3 && cnt0==1)
            {
                for(auto i:v1)
                {
                    fans.pb({i.ff,i.ss});
                }
                ans++;
            }
            else if(cnt1==2 && cnt0==2)
            {
                fans.pb({v1[0].ff,v1[0].ss});
                fans.pb({v0[0].ff,v0[0].ss});
                fans.pb({v0[1].ff,v0[1].ss});
                 fans.pb({v1[1].ff,v1[1].ss});
                fans.pb({v0[0].ff,v0[0].ss});
                fans.pb({v0[1].ff,v0[1].ss});
                ans+=2;
            }
            else if(cnt1==1 && cnt0==3)
            {
                fans.pb({v1[0].ff,v1[0].ss});
                fans.pb({v0[0].ff,v0[0].ss});
                fans.pb({v0[1].ff,v0[1].ss});
                fans.pb({v1[0].ff,v1[0].ss});
                fans.pb({v0[0].ff,v0[0].ss});
                fans.pb({v0[2].ff,v0[2].ss});
                fans.pb({v1[0].ff,v1[0].ss});
                fans.pb({v0[1].ff,v0[1].ss});
                fans.pb({v0[2].ff,v0[2].ss});
                ans+=3;
            }
              else if(cnt1==4 && cnt0==0)
            {
                fans.pb({v1[0].ff,v1[0].ss});
                fans.pb({v1[1].ff,v1[1].ss});
                fans.pb({v1[2].ff,v1[2].ss});
                fans.pb({v1[1].ff,v1[1].ss});
                fans.pb({v1[2].ff,v1[2].ss});
                fans.pb({v1[3].ff,v1[3].ss});
                fans.pb({v1[0].ff,v1[0].ss});
                fans.pb({v1[3].ff,v1[3].ss});
                fans.pb({v1[1].ff,v1[1].ss});
                fans.pb({v1[0].ff,v1[0].ss});
                fans.pb({v1[2].ff,v1[2].ss});
                fans.pb({v1[3].ff,v1[3].ss});
                ans+=4;
            }
            a[i][j]=0;
                a[i+1][j+1]=0;
                a[i][j+1]=0;
                a[i+1][j]=0;
            v1.clear();
            v0.clear();
            cnt0=0;
            cnt1=0;
        }
    }
    v1.clear();
            v0.clear();
            cnt0=0;
            cnt1=0;
    if(n%2)
    {
        for(int k=1;k<m;k+=2)
        {
         ll i=n-1,j=k;
            if(a[i][j]==1)
            {v1.pb({i,j});
            cnt1++;}
            else
            {v0.pb({i,j});
            cnt0++;
            }
            if(a[i][j+1]==1)
            {
                v1.pb({i,j+1});
                cnt1++;
            }
            else
            {
                v0.pb({i,j+1});
                cnt0++;
            }
            if(a[i+1][j]==1)
            {
                cnt1++;
                v1.pb({i+1,j});
            }
            else
            {
                cnt0++;
                v0.pb({i+1,j});
            }
            if(a[i+1][j+1]==1)
            {
                cnt1++;
                v1.pb({i+1,j+1});
            }
            else
            {
                cnt0++;
                v0.pb({i+1,j+1});
            }
            if(cnt1==3 && cnt0==1)
            {
                for(auto i:v1)
                {
                    fans.pb({i.ff,i.ss});
                }
                ans++;
            }
            else if(cnt1==2 && cnt0==2)
            {
                fans.pb({v1[0].ff,v1[0].ss});
                fans.pb({v0[0].ff,v0[0].ss});
                fans.pb({v0[1].ff,v0[1].ss});
                 fans.pb({v1[1].ff,v1[1].ss});
                fans.pb({v0[0].ff,v0[0].ss});
                fans.pb({v0[1].ff,v0[1].ss});
                ans+=2;
            }
            else if(cnt1==1 && cnt0==3)
            {
                fans.pb({v1[0].ff,v1[0].ss});
                fans.pb({v0[0].ff,v0[0].ss});
                fans.pb({v0[1].ff,v0[1].ss});
                fans.pb({v1[0].ff,v1[0].ss});
                fans.pb({v0[0].ff,v0[0].ss});
                fans.pb({v0[2].ff,v0[2].ss});
                fans.pb({v1[0].ff,v1[0].ss});
                fans.pb({v0[1].ff,v0[1].ss});
                fans.pb({v0[2].ff,v0[2].ss});
                ans+=3;
            }
              else if(cnt1==4 && cnt0==0)
            {
                fans.pb({v1[0].ff,v1[0].ss});
                fans.pb({v1[1].ff,v1[1].ss});
                fans.pb({v1[2].ff,v1[2].ss});
                fans.pb({v1[1].ff,v1[1].ss});
                fans.pb({v1[2].ff,v1[2].ss});
                fans.pb({v1[3].ff,v1[3].ss});
                fans.pb({v1[0].ff,v1[0].ss});
                fans.pb({v1[3].ff,v1[3].ss});
                fans.pb({v1[1].ff,v1[1].ss});
                fans.pb({v1[0].ff,v1[0].ss});
                fans.pb({v1[2].ff,v1[2].ss});
                fans.pb({v1[3].ff,v1[3].ss});
                ans+=4;
            }
            a[i][j]=0;
                a[i+1][j+1]=0;
                a[i][j+1]=0;
                a[i+1][j]=0;
            v1.clear();
            v0.clear();
            cnt0=0;
            cnt1=0;
        }
    }
    if(n%2 && m%2)
    {
        v1.clear();
            v0.clear();
            cnt0=0;
            cnt1=0;
     ll i=n-1,j=m-1;
            if(a[i][j]==1)
            {v1.pb({i,j});
            cnt1++;}
            else
            {v0.pb({i,j});
            cnt0++;
            }
            if(a[i][j+1]==1)
            {
                v1.pb({i,j+1});
                cnt1++;
            }
            else
            {
                v0.pb({i,j+1});
                cnt0++;
            }
            if(a[i+1][j]==1)
            {
                cnt1++;
                v1.pb({i+1,j});
            }
            else
            {
                cnt0++;
                v0.pb({i+1,j});
            }
            if(a[i+1][j+1]==1)
            {
                cnt1++;
                v1.pb({i+1,j+1});
            }
            else
            {
                cnt0++;
                v0.pb({i+1,j+1});
            }
            if(cnt1==3 && cnt0==1)
            {
                for(auto i:v1)
                {
                    fans.pb({i.ff,i.ss});
                }
                ans++;
            }
            else if(cnt1==2 && cnt0==2)
            {
                fans.pb({v1[0].ff,v1[0].ss});
                fans.pb({v0[0].ff,v0[0].ss});
                fans.pb({v0[1].ff,v0[1].ss});
                 fans.pb({v1[1].ff,v1[1].ss});
                fans.pb({v0[0].ff,v0[0].ss});
                fans.pb({v0[1].ff,v0[1].ss});
                ans+=2;
            }
            else if(cnt1==1 && cnt0==3)
            {
                fans.pb({v1[0].ff,v1[0].ss});
                fans.pb({v0[0].ff,v0[0].ss});
                fans.pb({v0[1].ff,v0[1].ss});
                fans.pb({v1[0].ff,v1[0].ss});
                fans.pb({v0[0].ff,v0[0].ss});
                fans.pb({v0[2].ff,v0[2].ss});
                fans.pb({v1[0].ff,v1[0].ss});
                fans.pb({v0[1].ff,v0[1].ss});
                fans.pb({v0[2].ff,v0[2].ss});
                ans+=3;
            }
              else if(cnt1==4 && cnt0==0)
            {
                fans.pb({v1[0].ff,v1[0].ss});
                fans.pb({v1[1].ff,v1[1].ss});
                fans.pb({v1[2].ff,v1[2].ss});
                fans.pb({v1[1].ff,v1[1].ss});
                fans.pb({v1[2].ff,v1[2].ss});
                fans.pb({v1[3].ff,v1[3].ss});
                fans.pb({v1[0].ff,v1[0].ss});
                fans.pb({v1[3].ff,v1[3].ss});
                fans.pb({v1[1].ff,v1[1].ss});
                fans.pb({v1[0].ff,v1[0].ss});
                fans.pb({v1[2].ff,v1[2].ss});
                fans.pb({v1[3].ff,v1[3].ss});
                ans+=4;
            }
            a[i][j]=0;
                a[i+1][j+1]=0;
                a[i][j+1]=0;
                a[i+1][j]=0;
            
    }
    ll sz=fans.size();
    cout<<ans<<'\n';
    for(int i=0;i<sz;i+=3)
    {
        cout<<fans[i].ff<<' '<<fans[i].ss<<' ';
        cout<<fans[i+1].ff<<' '<<fans[i+1].ss<<' ';
        cout<<fans[i+2].ff<<' '<<fans[i+2].ss<<' ';
        cout<<'\n';
    }
}
}