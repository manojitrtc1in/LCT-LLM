

using namespace std;



















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