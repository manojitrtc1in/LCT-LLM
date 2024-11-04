#include<bits/stdc++.h>
#define ll long long
#define li long long
#define ull unsigned long long
#define pb push_back
#define ins insert
#define er erase
#define f(i,a,b) for(li i=a;i<b;++i)
#define rf(i,a,b) for(i=a;i>=b;--i)
#define tc int t;cin>>t;while(t--)
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vc vector<char>
#define vst vector<string>
#define bs bitset
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int ,int>
#define pll pair<ll,ll>
#define mll map<ll,ll>
#define umll unordered_map<ll,ll>
#define pqi priority_queue<int>
#define pqll priority_queue<ll>
#define all(v) v.begin(),v.end()
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define lb lower_bound
#define ub upper_bound
#define mxe max_element
#define mne min_element
#define nl "\n"
#define sp " "

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ok order_of_key
#define fo find_by_order

ll md=1000*1000*1000+7;




ll pw(ll a, ll b){
    ll c=1, m=a;
    while(b){
        if(b&1)c=(c*m)%md;
        m=(m*m)%md;b/=2;
    }
    return c;
}

ll mmi(ll a)
{ 
    ll inverse = pw(a, md-2); 

    return inverse ;
}

 bool prime(ll n)
 {
     if(n==2)return true;
     if(!(n%2))
         return false;
     else{
         for(ll i=3;i<n;i+=2)
         {
             if(!(n%i))
                 return false;
         }
     }
return true;
 }


ll n;

ll const N = 200099;
ll p[N];
ll a[N];
ll ind[N];
ll t[4*N];
ll add[4*N];
ll b[N];


void build(ll v,ll l,ll r)
{
if((r-l)==1)
{
    t[v]=b[l];
    return;
}
ll mid=(l+r)/2;
build(2*v+1,l,mid);
build(2*v+2,mid,r);
t[v]=min(t[2*v+1],t[2*v+2]);
}

void push(ll v,ll l,ll r)
{
    if(add[v]!=0)
    {
        if(r-l>1)
      f(i,v+v+1,v+v+3)
      {
          add[i]+=add[v];
          t[i]+=add[v];
      }
      add[v]=0;
    }
}

void upd(ll v,ll l, ll r, ll L,ll R,ll x)
{   
    if(L>=R)return ;
   if(l==L && r==R)
   {
       t[v]+=x;
       add[v]+=x;
       push(v,l,r);
       return;
   }
   push(v,l,r);
   ll mid =(l+r)/2;
   upd(2*v+1,l, mid,L,min(mid,R), x);
   upd( 2*v+2, mid,r, max(mid,L), R, x);
   t[v]=min(t[2*v+1],t[2*v+2]);
}

void upd(ll l,ll r, ll x)
{
 upd(0,0,n,l,r,x);
}

ll get(ll v,ll l,ll r,ll L,ll R)
{
    if(L>=R)return 1e18;
    push(v,l,r);
    if(l==L && r==R)
    return t[v];
    ll mid=(l+r)/2;
    return min(get(2*v+1,l,mid,L,min(R,mid)),get(2*v+2,mid,r,max(L,mid),R));
}

ll get(ll l,ll r)
{
    return get(0,0,n,l,r);
}

int main()
{
cin>>n;

f(i,0,n){cin>>p[i];p[i]--;ind[p[i]]=i;}
f(i,0,n)cin>>a[i];
b[0]=a[0];
f(i,1,n)b[i]=a[i]+b[i-1];
build(0,0,n);
ll res=get(0,n-1);
f(i,0,n)
{
ll pos = ind[i];
upd(pos,n,-a[pos]);
upd(0,pos,a[pos]);
 res= min (res, get(0, n-1));
}
cout<<res<<nl;
return 0;
}
