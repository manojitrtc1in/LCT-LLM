

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




#define see(x)         cout<<#x<<" = "<<x<<endl
#define see2(x,y)      cout<<#x<<" = "<<x<<"::"<<#y<<" = "<<y<<endl






 

void solve()
{
    ll n,m;
    cin>>n>>m;
    ll a[n],b[n],c[m];
    vector<ll>req[n+1];

    fr(n)   
    cin>>a[i];
    fr(n)  
    { 
        cin>>b[i]; 
        if(b[i]!=a[i])
         req[b[i]].pb(i+1);
    }
    fr(m)  
    { 
        cin>>c[i]; 
    }

        ll last=-1;
        if(req[c[m-1]].size()>0)
        {
            last=req[c[m-1]].back();
            req[c[m-1]].pop_back();
        }
        else
        {
            for(ll i=0;i<n;i++)
            {
                if(b[i]==c[m-1])
                {
                    last=i+1;
                    break;
                }
            }
        }
        if(last==-1)
        {
            cout<<"NO"<<endl;
            return;
        }
        
            
        vi ans;
        for(ll i=0;i<m-1;i++)
        {
            if(req[c[i]].size()==0)
            {
                ans.pb(last);
            }
            else
            {
                ans.pb(req[c[i]].back());
                req[c[i]].pop_back();
            }
        }
        ans.pb(last);

        for(ll i=1;i<=n;i++)
        {
            if(req[i].size()>0)
            {
                cout<<"NO"<<endl;
                return ;
            }
        }
        cout<<"YES"<<endl;
        for(ll x:ans)
            cout<<x<<" ";
        cout<<endl;

        
    
} 

  
int main() 
{ 
   

   FAST;
   

   ll t;
   t=1;
   cin>>t;  
   while(t--)
   solve();
   return 0;
}























