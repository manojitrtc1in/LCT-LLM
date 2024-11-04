

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







const ll N=200005;
ll BITree[N];
ll n;
ll getSum(ll index)
{
    ll sum = 0; 

    
    

    while (index > 0)
    {
        
        

        sum += BITree[index];

        

        index -= (index & (-index));
    }
    return sum;
}

void updateBIT(ll index, ll val)
{
    

    
    while (index <= n)
    {
        
    

    BITree[index] += val;

    

    index += (index & (-index));
    }
}
void solve()
{
    
    ll t,k;
    cin>>n>>t;
   
    map<ll,ll>mp;
    while(t--)
    {  
         
        ll ans=-1;
        ll l=1,r=n;
    
        cin>>k;
        while(l<=r)
        {
            ll cnt0;
            ll mid=(l+r)/2;
            if(mp.find(mid)!=mp.end())
            {
                ll y=mp[mid]+getSum(mid);
                cnt0=mid-y;
            }
            else
            {
                cout<<"? "<<1<<" "<<mid<<endl;
                cout.flush();
                ll x;
                cin>>x;
                mp[mid]=x-getSum(mid);
                cnt0=mid-x;
                
            }
            
            if(cnt0>=k)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        cout<<"! "<<ans<<endl;
        cout.flush();
        updateBIT(ans,1);
        
    }
    return ;
}
  
int main() 
{ 
   

   

   

   ll t;
   t=1;
   

   while(t--)
   solve();
   return 0;
}
