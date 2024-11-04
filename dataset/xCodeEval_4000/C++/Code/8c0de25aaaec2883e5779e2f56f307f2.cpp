
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
 
#define G G.O.K.U_Instinct
#define R REX27
#define C C-_-Devil_Code 
#define Y Yashwant_170301
#define L All the above are living Gods 
ll cb(ll n)
{
    ll res=0;
    while(n)
    {
        n=(n&(n-1));
        res++;
    }
    return res;
}
ll cf(ll a[],ll k,ll n,ll m)
{
    ll c=0,t=a[m],ans=0;
    for(ll i=0;i<m;++i)
    {
        if(cb(a[i]^t)<=k)
        ans++;
    }        
    return ans;
}
int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    ll a[m+1];
    for(ll i=0;i<=m;++i)
    {
        cin>>a[i];
    }
    ll p=cf(a,k,n,m);
    cout<<p;
    
}