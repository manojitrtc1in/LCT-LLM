




using namespace std;















double eps=1e-9;
double pi=acos(-1);


ll fastpower(ll b,ll p)
{
    ll ans=1;
    while(p){if (p%2){ans=(ans*b);}b=b*b;p/=2;}
    return ans;
}

ll id0(ll b,ll p,ll m)
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
string  id1(ll n)
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












bool checksqrt(ll f){ll num=sqrt(f);return (num*num==f);}














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





























const int N=1e6+1;




const int sz=5e3+20;
ll cum[sz];
vector<pll>v;
ll n,q;
ll solve(int idx)
{
    ll ans=0;
    dpp(cum,0);
    for (int i=0;i<v.size();i++)
    {
      if (idx==i){continue;}
      cum[v[i].F]++;
      cum[v[i].S+1]--;
    }
    for (int i=1;i<=n;i++)
    {
        cum[i]+=cum[i-1];
    }
    for (int i=1;i<=n;i++)
    {
        if (cum[i]>0){ans++;}
    }
    for (int i=1;i<=n;i++)
    {
        if (cum[i]!=1){cum[i]=0;}
    }
    for (int i=1;i<=n;i++)
    {
        cum[i]+=cum[i-1];
    }
    ll fans=0;
    for (int i=0;i<v.size();i++)
    {
        if (idx==i){continue;}
        fans=max(fans,ans-(cum[v[i].S]-cum[v[i].F-1]));
    }
    return fans;
}
int main()
{
     

    

    

     

     

     cin>>n>>q;
     for (int i=0;i<q;i++)
     {
         ll x,y;
         cin>>x>>y;
         v.push_back({x,y});
     }
     ll ans=-1e18;
     for (int i=0;i<q;i++)
     {
         ans=max(ans,solve(i));
     }
     cout<<ans;
     return 0;

}
