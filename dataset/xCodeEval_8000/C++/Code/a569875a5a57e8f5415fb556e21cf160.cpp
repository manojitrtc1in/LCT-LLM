















































































































































































#include<bits/stdc++.h>
#include<iomanip>
#include<cmath>
#define lld long long int
#define ld long double
#define mod 998244353
#define all(v) (v).begin(),(v).end()
#define rep(i,a,b)	for(lld i=a;i<b;i++)
#define repr(i,a,b) for(lld i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define	endl '\n'
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
vector<lld> fac(200009,1);
int main()
{
     ios;
     lld n;
     cin>>n;
     vector<lld> deg(n+1);
     rep(i,1,200009)
     {
         fac[i]=(fac[i-1]*i)%mod;
     }
     rep(i,1,n)
     {
         lld x,y;
         cin>>x>>y;
         deg[x]++;
         deg[y]++;
     }
     lld ans=n;
     rep(i,1,n+1)
     {
        ans=(ans*fac[deg[i]])%mod;
     }
     cout<<ans<<endl;
    return 0;
}

