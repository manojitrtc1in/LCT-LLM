




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




































const int M=1e9+7;
ll add(ll a,ll b)
{
    return (a%M+b%M)%M;
}
ll mul(ll a,ll b)
{
    return (a%M*b%M)%M;

}
const int sz=2e5+10;
int cnt[sz];
int main()
{
    

    

    

    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<ll>v;

    int num=0;
    int maxi=-1;
    int pos=-1;
    for (int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        cnt[x]++;
        if (cnt[x]>maxi)
        {
            maxi=cnt[x];
            num=x;
            pos=i;
        }
        v.push_back(x);
    }
    cout<<n-maxi<<endl;
    for (int i=pos;i>=0;i--)
    {

     if (v[i]==v[pos]){continue;}
     if (v[i]<v[pos])
     {
         cout<<1<<" "<<i+1<<" "<<i+2<<endl;
     }
     else if (v[i]>v[pos])
     {
         cout<<2<<" "<<i+1<<" "<<i+2<<endl;
     }
    }

    for (int i=pos;i<n;i++)
    {
     if (v[i]==v[pos]){continue;}
     if (v[i]<v[pos])
     {
         cout<<1<<" "<<i+1<<" "<<i<<endl;
     }
     else if (v[i]>v[pos])
     {
         cout<<2<<" "<<i+1<<" "<<i<<endl;
     }
    }
    return 0;

}
