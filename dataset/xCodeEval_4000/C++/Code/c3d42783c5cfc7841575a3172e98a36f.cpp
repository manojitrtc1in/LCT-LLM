
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define fo(i, n) for (i = 0; i < n; i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define m_p make_pair
const ll mod=1000000007;


void solve()
{
   string s ;
   cin >> s ;
   ll i ;
   ll n=s.length();
   for(i=0;i<n;i++)
   {
      if(i%2==0)
      {
        if(s[i]=='a')
            s[i]='b';
        else
            s[i]='a';
      }
      else
      {
        if(s[i]=='z')
            s[i]='y';
        else
            s[i]='z';
      }
   }
   cout<<s<<"\n";
}
 int main()
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t;
    cin>>t;
    

    while(t--)
    {
        solve();
    }
}