



























































































using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
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

ll lcm(vector<ll> an)
{
    ll n=1e6;

    vector<ll> de(n+1);
    for(ll i=0;i<an.size();i++)
    {
        ll k=2,ans=0,a=an[i];
        while(a>1)
        {
            if(a%k==0)ans++,a/=k;
            else de[k]=max(de[k],ans),ans=0,k++;
        }
        de[k]=max(de[k],ans);

    }

    ll ans=1;
    for(ll i=2;i<=n;i++)
    {
        ans*=binpow(i,de[i]);
    }
    ret ans;
}





int main()
{






















    ll n,p,mn=1e18,mx=0;
    cin >> n >> p;

    vector<ll> v(n),a;
    for(ll i=0;i<n;i++)
    {
        cin >> v[i];
        mn=min(v[i],mn);
        mx=max(v[i],mx);
    }
    sort(v.begin(),v.end());

    for(ll i=mn;i<=mx;i++)
    {
        ll x=i,an=1,ans=1;
        for(ll j=1;j<=n;j++)
        {
            while(an<=n and v[an-1]<=x)an++;
            x++;
            ans=(ans*(an-j))%p;
        }
        if(ans>0)a.pb(i);
    }

    cout << a.size() << endl;
    for(ll i=0;i<a.size();i++)cout << a[i] << " ";
    cout << endl;


    ret 0;
}
