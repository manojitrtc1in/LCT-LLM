




using namespace std;
















double eps=1e-9;
double pi=acos(-1);


long double fastpower(long double b,ll p)
{
    long double ans=1;
    while(p){if (p%2){ans=(ans*b);}b=b*b;p/=2;}
    return ans;
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
const int sz=1e2+10;
ll add(ll a,ll b,ll m)
{
    return (a%m+b%m)%m;
}
ll mul(ll a,ll b,ll m)
{
    return (a%m*b%m)%m;
}
ll id0(ll b,ll p,ll m)
{
    ll ans=1;
    while(p)
    {
        if (p%2)
        {
            ans=mul(ans,b,m);
        }
        b=mul(b,b,m);
        p/=2;
    }
    return ans%m;
}
ll inv(ll num)
{
    return (id0(num,M-2,M));
}
ll NcR(ll n,ll r)
{


}

ll lcm(ll a,ll b)
{
    return (a/gcd(a,b))*b;
}
int arr[sz][sz];
int cnt[sz];
int main()
{
    

    

    

     ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
      int n,m,h;
      cin>>n>>m>>h;
      vector<int>v1,v2;
      for (int i=0;i<m;i++)
      {
       int x;
       cin>>x;
       v1.push_back(x);
      }
      for (int i=0;i<n;i++)
      {
       int x;
       cin>>x;
       v2.push_back(x);
      }

      for (int i=0;i<n;i++)
      {
          for (int j=0;j<m;j++)
          {
              cin>>arr[i][j];
              if (arr[i][j]){cnt[j]++;}
          }
      }
      for (int i=0;i<n;i++)
      {
        for (int j=0;j<m;j++)
        {

            if (arr[i][j]==1)
            {
             if (i<v2.size()&&j<v1.size())
                {

                    arr[i][j]=min(v2[i],v1[j]);

                }

            }
        }
      }
      for (int i=0;i<n;i++)
      {
          for (int j=0;j<m;j++)
          {
              cout<<arr[i][j]<<" ";
          }
          cout<<endl;
      }

       return 0;

}
