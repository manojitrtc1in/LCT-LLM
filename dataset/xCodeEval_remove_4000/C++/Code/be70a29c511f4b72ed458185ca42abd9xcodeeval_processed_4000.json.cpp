




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



struct point{
ll x,y;
};
int orientation(point p1, point p2, point p3)
{
    int val=(p2.y - p1.y)*(p3.x - p2.x)-(p2.x - p1.x) * (p3.y - p2.y);
    if (val==0){return 0;}
    return (val>0)? 1: 2;
}
bool check(point p1,point p2,point p3)
{
 ll val=(p2.y - p1.y)*(p3.x - p2.x)-(p2.x - p1.x) * (p3.y - p2.y);
 return (val==0);
}

int main()
{
    

    

    

    

      ll n;
      cin>>n;
      ll maxi=0;
      ll ans=0;
      ll cnt=0;

      for (int i=0;i<n;i++)
      {
          ll x;
          cin>>x;
         if (x>maxi){maxi=x;cnt=1;ans=0;ans=max(ans,cnt);}
         else if (x==maxi){cnt++;ans=max(ans,cnt);}
         else {cnt=0;}

      }
      cout<<ans<<endl;
      return 0;

}
