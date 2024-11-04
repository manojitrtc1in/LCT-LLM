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
#define MP make_pair




double eps= 0.0000001;
double pi=acos(-1);


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





























const int N=1e2+1;


long powcnt[N];
long ans;
void preprocess(long num)
{
    for (ll i=30;i>=0;i--)
    {
        if (num>=(1<<i))
        {
            num-=(1<<i);
            powcnt[i]++;
        }
    }
}
void solve(long curp)
{
    for (long i=curp;i<=30;i++)
    {
        if (powcnt[i]>0)
        {
         powcnt[i]--;
         ans++;
         for (long j=curp;j<i;j++)
          {
            powcnt[j]++;
          }
        break;
        }
    }


}
int main()
{


    

    

    

    time;
    int n,m;
    cin>>n>>m;
    vector<long>v;
    for (int i=0;i<n;i++)
    {
    long x;
    cin>>x;
    preprocess(x);
    }
    for (int i=0;i<m;i++)
    {
    long x;
    cin>>x;
    v.push_back(x);
    }
    sort(v.begin(),v.end());
    for (int i=0;i<v.size();i++)
    {
        solve(v[i]);
    }
    cout<<ans<<endl;
    return 0;
}
