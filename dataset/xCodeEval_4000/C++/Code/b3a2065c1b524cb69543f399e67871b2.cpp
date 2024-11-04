
#include<bits/stdc++.h>
using namespace std;


#define ll                  long long
#define md                  1000000007
#define pb                  push_back
#define mp                  make_pair
#define fr(i,n)             for(ll i=0;i<n;i++)
#define fr1(i,k,n)          for(ll i=k;i<n;i++)
#define re(v,n)             v.resize(n)
#define inp(v)              for(auto &x: v) cin>>x           
#define dsort(a)            sort(a,a+n,greater<int>())
#define fast_io             ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io             freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);






ll m,n,p,x,y;
vector<ll> edges[1000005];
bool vis[500005];
void solve(){
cin>>n>>m;
vector<ll> v;
fr(i,n*m){
    
    cin>>x;
    v.pb(x);
}
ll ct=0;
fr1(i,1,n*m){
     fr(j,i){
        if(v[i]>v[j]) ct++;
     }
}
cout<<ct<<endl;
return;
}
int main()
{ 
ll n;


cin>>n;
fr(i,n){
  solve();
}
return 0;
}