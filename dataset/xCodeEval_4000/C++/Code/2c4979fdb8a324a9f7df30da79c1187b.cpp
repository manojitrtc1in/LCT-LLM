

#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
#define fr(i, n)    for(int i=0; i<n;i++)
#define ll long long
#define el '\n'
#define sz(s) s.size()
#define all(s)  s.begin(), s.end()
#define u   unsigned int
using namespace std;



void solve(){
    ll a, b, c, x, y;
    bool f=0;
    cin>>a>>b>>c>>x>>y;
    if(x>a)c-=(x-a);
    if(y>b)c-=(y-b);
    if(c<0)cout<<"NO\n";
    else    cout<<"YES\n";
}




int main(){
    fast;
    int t=1;
    cin>>t;
    while(t--)solve();

     }


