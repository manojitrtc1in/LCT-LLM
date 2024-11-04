
















































































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
vd id0(ll x)
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
    id0(sqrt(1e9));

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
        ll n;
        cin >> n;
        
        vector<ll> v(n);
        for(ll i=0;i<n;i++)cin >> v[i];

        for(ll i=0;i<n;i+=2)
        {
            ll a=v[i],b=v[i+1];
            
            cout << b << " " << -a << " ";
        }
        
        cout << endl;
    }
    

   ret 0;
}