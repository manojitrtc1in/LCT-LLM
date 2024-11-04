
















































































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
        if(n&1)ans=(ans*a);
        a=(a*a);
        n>>=1;
    }
    ret ans;
}

vector<ll> pr;
vd id0(ll x)
{
    if(pr.size()>0)ret;

    vector<ll> p(x+1);

    for(ll i=2; i<=x; i++)
    {
        if(p[i]==0)
        {
            pr.pb(i);
            for(ll j=i+i; j<=x; j+=i)p[j]=1;
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


ll n,t,b,k,l,o,m,q1,q2,top,a[1000001];
pair<ll,ll>q[1000001];
const ll oo=1e18;

int main()
{
    


    cin >> t;
    while(t--)
    {
        cin >> n >> m >>k >> q1;

        cout << max(abs(n-k)+abs(m-q1),max(abs(1-k)+abs(1-q1),max(abs(n-k)+abs(1-q1),abs(1-k)+abs(m-q1)))) << endl;
    }

    return 0;
}
