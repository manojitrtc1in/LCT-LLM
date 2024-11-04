

























































#include <bits/stdc++.h>












#define endl "\n"
#define amd and
#define pb push_back
#define f first
#define s second
#define ret return
#define cont continue
#define lcm(x,y) (x*y/__gcd(x,y))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
typedef long double ld;
typedef char ch;
typedef string str;
typedef bool bl;
typedef void vd;

ll binpow(ll a,ll n,ll mod)
{
    ll ans=1;
    while(n)
    {
        if(n&1)ans=(ans*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    ret ans;
}

ll binpow(ll a,ll n)
{
    ll ans=1;
    while(n)
    {
        if(n&1)ans*=a;
        a*=a;
        n>>=1;
    }
    ret ans;
}

vector<ll> pr;
vd PrDoX(ll x)
{
    if(pr.size()>0)ret;

    vector<ll> p(x+1);

    for(ll i=2;i<=x;i++)
    {
        if(p[i]==0)
        {
            pr.pb(i);
            for(ll j=i+i;j<=x;j+=i)p[j]=1;
        }
    }
}

vector<ll> fact(ll x)
{
    PrDoX(sqrt(1e9));

    vector<ll> ans;

    ll i=0,c=sqrt(x),n=pr.size();
    while(x>1 and pr[i]<=c and i<n)
    {
        if(x%pr[i]==0)
        {
            x/=pr[i];
            ans.pb(pr[i]);
            c=sqrt(x);
        }
        else i++;
    }

    if(x!=1)ans.pb(x);

    ret ans;
}


ll n,k[100005],ans[100005],dp[100005];
vector<ll> v,g[100005];

vd dfs(ll x)
{
    k[x]=v[x];
    if(g[x].size()==0)ans[x]=v[x],dp[x]=1;
    else ans[x]=0,dp[x]=0;

    ll n=g[x].size();
    for(ll i=0;i<n;i++)
    {
        ll a=g[x][i];
        dfs(a);
        dp[x]+=dp[a];
        k[x]+=k[a];
        ans[x]=max(ans[x],ans[a]);
    }

    ans[x]=max(k[x]/dp[x]+(k[x]%(dp[x]>0)),ans[x]);
}


int main()
{













    

    

    

    


    ll Q;
    cin >> Q;
    while (Q--)
    {
        ll n,m;
        cin >> n >> m;

        vector<vector<ll> > v1(n,vector<ll> (m)),v2(m,vector<ll> (n));
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)cin >> v1[i][j];
        }
        
        for(ll i=0;i<m;i++)
        {
            for(ll j=0;j<n;j++)cin >> v2[i][j];
        }

        ll x,y;
        for(ll i=0;i<n;i++)
        {
            bl fl=1;
            for(ll j=0;j<m;j++)
            {
                if(v1[i][j]==v2[0][0])
                {
                    x=i,y=j;                    
                    fl=0;
                    break;
                }
            }
            if(fl==0)break;
        }

        vector<pll> fl(m);
        for(ll i=0;i<m;i++)
        {
            for(ll j=0;j<m;j++)
            {
                if(v1[x][i]==v2[j][0]) 
                {
                    fl[i]={i,j};
                    

                    break;
                }
            }
        }

        

        

        sort(all(fl));
        

        


        vector<vector<ll> > ans(m,vector<ll> (n));
        for(ll i=0;i<m;i++)
        {
            for(ll j=0;j<n;j++)ans[i][j]=v2[fl[i].s][j];
        }

        

        

        

        

        

        



        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)cout << ans[j][i] << " ";
            cout << endl;
        }

        
    }
    

   ret 0;
}