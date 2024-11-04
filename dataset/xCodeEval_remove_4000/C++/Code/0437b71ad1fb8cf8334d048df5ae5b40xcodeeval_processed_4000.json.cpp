















































 








 

 
































 









 
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
    id0(sqrt(1e10));
 
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
 
    

    



 
 
    

    





    

    

 
    ll Q;
    cin >> Q;
    while(Q--)
    {
        ll n,p,k,a,b;
        str t;
        cin >> n >> p >> k >> t >> a >> b;

        reverse(all(t));

        ll ans=1e18;
        vector<ll> cnt(n+1);
        for(ll i=0;i<n;i++)
        {
            if(t[i]=='0')cnt[i%k]++;

            if(i+p<=n)ans=min(ans,cnt[i%k]*a+(n-i-p)*b);
        }

        cout << ans << endl;
    }   

  ret 0;
}