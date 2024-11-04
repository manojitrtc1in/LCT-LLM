




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




const int sz=1e2+20;
ll cnt[sz];
int main()
{
     

    

    

      time;
     

     ll n,k;
     cin>>n>>k;
     ll ans=0;
     for (int i=0;i<n;i++)
     {
         ll x;
         cin>>x;
         ll now=x%k;
        if (cnt[(k-now)%k]){ans++; cnt[(k-now)%k]--;}
        else{cnt[now]++;}
     }
     cout<<ans*2;
     return 0;

}
