#include<bits/stdc++.h>




using namespace std;
#define time ios_base::sync_with_stdio(0);cin.tie(0);
#define dpp(arr,val) memset(arr,val,sizeof (arr))
#define ll long long
#define ull unsigned long long
#define ld long double
#define PQ priority_queue
#define pii pair<int,int>
#define pll pair<ll,ll>
#define S second
#define F first



double eps= 0.0000001;




ll fastpower(ll b,ll p)
{
    ll ans=1;
    while(p)
    {
        if (p%2)
        {
            ans=(ans*b);
        }
        b=b*b;
        p/=2;
    }
    return ans;
}
ll fastpowermod(ll b,ll p,ll m)
{
    ll ans=1;
    while(p)
    {
        if (p%2)
        {
            ans=((ans%m)*(b%m))%m;
        }
        b=((b%m)*(b%m))%m;
        p/=2;
    }
    return ans%m;
}
string  makeitstring(ll n)
{
    string ans;
    bool ch=0;
    if (n<0)
    {
        n*=-1;
        ch=1;
    }
    if (n==0)
    {
        ans="0";
    };
    while (n)
    {
        ll mo=n%10;
        mo+=48;
        char m=mo;
        ans=m+ans;
        n/=10;
    }
    if (ch)
    {
        ans='-'+ans;
    }
    return ans;
}




























bool compare(double f,double s)
{
    return  (abs(f-s)<eps);
}
ll gcd(ll a,ll b)
{
    while(b!=0)
    {
        ll a2=a;
        a=b;
        b=a2%b;
    }
    return a;
}


























const int N=1e6+10;
ll M=998244353;
ll fact[N];
ll invfact[N];
ll modInverse(ll a,ll m)
{
    int m0 = m;
    int y = 0, x = 1;

    if (m == 1)
      return 0;

    while (a > 1)
    {
        

        int q = a / m;
        int t = m;

        

        

        m = a % m, a = t;
        t = y;

        

        y = x - q * y;
        x = t;
    }

    

    if (x < 0)
       x += m0;

    return x;
}
void init()
{
    fact[0]=1;
    for (int i=1;i<N;i++)
    {
        fact[i]=fact[i-1]*i;
        fact[i]%=M;
    }
    for (int i=0;i<N;i++)
    {
        invfact[i]=modInverse(fact[i],M)%M;

    }
}
ll npr(ll n,ll r)
{
    return (fact[n]*invfact[n-r])%M;
}
int main()
{
    

    

    

    

    

    time;
    int n;
    cin>>n;
    init();
    ll ans=0;

      for (int i=1;i<=n;i++)
      {
       ans+=((fact[n-i])*npr(n,i));
       if(i!=n){ans-=(npr(n,i))%M;ans+=M;ans%=M;}

      }

      cout<<ans%M;
    return 0;

}
