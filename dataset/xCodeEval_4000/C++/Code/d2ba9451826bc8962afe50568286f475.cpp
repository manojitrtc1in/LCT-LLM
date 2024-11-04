

#include <bits/stdc++.h>
#include <algorithm>
#include <string>
using namespace std;










#define vi             vector<ll> 
#define mi             map<ll,ll>
#define pi             pair<ll,ll>
#define si             set<ll>
#define endl            "\n"
#define ins             insert 
#define hell             1000000007
#define PI              3.1415926535897932384
#define ll              long long 
#define f               first
#define s              second
#define pb             push_back
#define pp             pop_back
#define dash()         cout<<"--------"<<endl
#define see(x)         cout<<#x<<" = "<<x<<endl
#define see2(x,y)      cout<<#x<<" = "<<x<<"::"<<#y<<" = "<<y<<endl
#define fr(n)          for(ll i=0;i<n;i++)
#define FAST           ios_base::sync_with_stdio(false); cin.tie(NULL);
#define narak             998244353 
#define decimal(n)  std::cout << std::fixed;std::cout << std::setprecision(n);
#define make make_pair
#define mem0(a)         memset(a,0,sizeof(a))
#define mem1(a)         memset(a,-1,sizeof(a))
#define ALL(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))  
#define REVERSE(v) reverse(ALL(v))
#define maxc(v) max_element(all(v))
#define minc(v) min_element(all(v))
#define GCD(m,n) __gcd(m,n)
#define LCM(m,n) m*(n/GCD(m,n))
#define sz(a) (ll)a.size()
#define loop(i,a,b) for(ll i=a;i<=b;i++)





 
  
ll dist(ll x1,ll y1,ll x2,ll y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

void solve()
{
    ll n;
    cin>>n;
    ll x[n],y[n];
    for(ll i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
    }

    ll i=0;
    vi ans;
    vector<ll>vis(n);
    ll cnt=0;
    while(cnt<n)
    {
        ans.pb(i+1);
        vis[i]=1;
        ll id=-1,d=0;
        for(ll j=0;j<n;j++)
        {
            ll dd=dist(x[i],y[i],x[j],y[j]);
            if(!vis[j] and d<dd)
            {
                d=dd;
                id=j;
            }
        }
        if(id==-1)
            break;
        i=id;
        vis[id]=1;
        cnt++;
    }


    for(ll x:ans)
        cout<<x<<" ";

    return ;
}
  
int main() 
{ 
   

   FAST;
   

   ll t;
   t=1;
   

   while(t--)
   solve();
   return 0;
}
