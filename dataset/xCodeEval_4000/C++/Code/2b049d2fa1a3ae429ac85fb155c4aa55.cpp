#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define modulo 1000000007
#define PI 3.141592653589793238462643
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
fstream inp("input.txt",ios::in);
fstream out("output.txt",ios::out);


ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
template<class T> using orderedset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;







ll stringTointeger(string str)
{
    ll temp = 0;
    for (ll i = 0; i < str.length(); i++) {


        temp = temp * 10 + (str[i] - '0');
    }
    return temp;
}

bool comp(pair<pair<ll,ll>,ll>&p,pair<pair<ll,ll>,ll>&p1)
{
 if(p1.first.first!=p.first.first)
 {
  return p.first.first<p1.first.first;
 }
 return p.first.second>p1.first.second;
}
 long long getcount(long long n, int k)
{
    

    

    long long res = (n >> (k + 1)) << k;
    

    

    if ((n >> k) & 1)

        

        

        res += n & ((1ll << k) - 1);

    

    return res;
}



















 
 
 
 

 
 

 

 

 

 

 

 ll dp[1002][2];
 ll solve(ll arr[],ll n,ll ind,ll f)
 {
    if(ind==n-1)
        return 0;
    ll mini=1e9;
    if(f==0)
    {
     if(arr[ind+1]%2!=arr[ind]%2)
     {
      mini=min(mini,1+solve(arr,n,ind+1,f^1));
     }
     if(arr[ind+1]%2==arr[ind]%2)
     {
      mini=min(mini,1+solve(arr,n,ind+1,f));
     }
    }
    else
    {
     if(arr[ind+1]%2==arr[ind]%2)
        mini=min(mini,1+solve(arr,n,ind+1,f));
    }
    cout<<mini<<"\n";
    return mini;
 }
 int main()
 {
    fast
    ll t;
    cin>>t;
   

    while(t--)
    {
      ll n,k;
      cin>>n>>k;
      ll arr[n];
      for(int i=0;i<n;i++)
      {
        cin>>arr[i];
      }
      ll mp[34];
      for(int i=0;i<34;i++)
        mp[i]=0;
      for(int i=0;i<n;i++)
      {
        ll val=arr[i];
        ll ind=0;
        while(val>0)
        {
         if(val&1)
         {
            mp[ind]++;
         }
         val=val/2;
         ind++;
        }
      }
      ll lastsetb=0;
      for(ll i=31;i>=0;i--)
      {
        if(mp[i]>0)
        {
         lastsetb=i;
         break;
        }
      }
      

      ll ans=0;

      for(ll i=30;i>=0;i--)
      {
        ll diff=n-mp[i];
        if(diff==0)
            ans+=(ll)1<<(i);
        else if(diff<=k)
        {
         k=k-diff;
         ans+=(ll)1<<(i);
        }
      }
      cout<<ans<<"\n";

    }
}
