


























































































using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
typedef long double ld;
typedef char ch;
typedef string str;
typedef bool bl;

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



int main()
{













    

    






    ll n;
    cin >> n;
    vector<pll> v(n);
    for(ll i=0;i<n;i++)cin >> v[i].f >> v[i].s;
    sort(v.begin(),v.end());

    vector<ll> dp(n+1);
    for(ll i=n-1;i>=0;i--)
    {   
        dp[i]=1e18;
        ll ans=v[i].s;
        

        

        for(ll j=i;j<n;j++)
        {
            

            ans+=v[j].f-v[i].f;
            if(ans+dp[j+1]<dp[i])dp[i]=ans+dp[j+1];
        }
    }

    

    


    cout << dp[0] << endl;

    ret 0;
}
