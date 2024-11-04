




using namespace std;













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
ll id1(ll b,ll p,ll m)
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
string  id4(ll n)
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
ll id0(string s)
{
    ll ans=0;
    for (ll i=0; i<s.size(); i++)
    {
        if(s[i]!='-')
        {
            ll num=s[i]-'0';
            ans+=(num*fastpower(10,(ll)s.size()-i-1));
        }
    }
    if(s[0]=='-')
    {
        return ans*-1;
    }
    else
    {
        return ans;
    }
}
string id2(ll num)
{
    string s;
    while(num>0)
    {
        ll m=num%2;
        char a=m+'0';
        s=a+s;
        num/=2;
    }
    return s;
}
ll id3(string s)
{
    ll ans=0;
    for (ll i=0; i<s.size(); i++)
    {
        if (s[i]=='1')
        {
            ans+=fastpower(2,i);
        }
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
ll t[N];
ll v[N];
double ans[N];
int main()
{
    

    

    

    

    

    time;
    ll n,a,d;
    cin>>n>>a>>d;
    for (int i=0;i<n;i++)
    {
        cin>>t[i]>>v[i];
    }
    for (int i=0;i<n;i++)
    {
        double tt=(double)v[i]/a;
        double dd=(double)a*tt*tt*0.5;
        if (dd>d)
        {
         ans[i]=t[i]+sqrt(2*(double)d/a);
        }
        else {
            ans[i]=t[i]+tt+(d-dd)/v[i];
        }
        if (i>0&&ans[i]<ans[i-1])
        {
            ans[i]=ans[i-1];
        }
    }
    cout<<fixed;
    for (int i=0;i<n;i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;

}


