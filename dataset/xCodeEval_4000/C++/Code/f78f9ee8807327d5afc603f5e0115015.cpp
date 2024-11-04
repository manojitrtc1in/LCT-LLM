

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
    string s, t; cin>>s>>t;
    if(t=="a")cout<<"1\n";
    else {
        sort(all(t));
        if(t[0]=='a')cout<<"-1\n";
        else  {
           cout<<(1ll<<(s.length()))<<el;
        }
    }


}




int main(){
    fast;
    int t=1;
    cin>>t;
    while(t--)solve();

     }


