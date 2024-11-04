












using ll=long long;
using lli=long long int;
using ld=long double;
using ull=unsigned long long;












const ll mod=998244353;
const ll MAX=id0;
const ll MIN=id1;
const int as=2;
using namespace std;
int search(int c,int le,int a[])
{
   int l=0,r=le-1,m=0;
   while (l<=r)
   {
        m=l+(r-l)/2;
       if (a[m]==c)
       {
           return m;
       }
       else
        if (a[m]<c)
       {
           l=m+1;
       }
       else
       {
           r=m-1;
       }
   }
   return m;
}
void Solve()
{
    ll n;
    cin>>n;
    string s,q;
    cin>>s;
    q=s;
    ll y=0;
    sort(all(q));
    for (ll i=0;i<n;i++)
    {
        if (s[i]!=q[i])
            y++;
    }
    cout<<y<<'\n';
}
int main()
{
    FAST;
    ll tt;
    cin>>tt;
    while (tt-->0)
    {
        Solve();
    }

}


