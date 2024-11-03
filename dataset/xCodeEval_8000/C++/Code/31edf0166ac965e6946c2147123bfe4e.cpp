

















  












  




#include <bits/stdc++.h>
#include<stdio.h>
#define pb(x) push_back(x)
#define XX first
#define YY second
#define cst 1000000007
#define nor_rad(x) ( ( PI*x )/180)
#define rad_nor(x)  ( (x/IP)*180 )
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define rev reverse
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1e9+7;
const ld error = 2e-6;
const ld PI = acosl(-1); 


#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define eq(x, y) (fabs((x)-(y))<error)
#define bt(i) (1LL<<(i))












inline ll MOD(ll x, ll m = mod){
    ll y = x % m;
    return (y >= 0) ? y: y+m;
}

const int inf = 1e9;
const ll infl = 1061109567;
const int nmax = 1000+10;



ll dp[200][10000]; ll n,m;
vector<ll>vc,poss,vall;

ll DP(ll pos, ll val){
if(pos<=1) return 1;
if(val>n) return 0;
if(dp[pos][val]!=-1) return dp[pos][val]%mod;

ll i; dp[pos][val]=0;
for(i=1;i<=val;i++){
    dp[pos][val]= (dp[pos][val]%mod + DP(pos-1,i)%mod)%mod;

                    }
  vc.pb(dp[pos][val]); poss.pb(pos); vall.pb(val);
    return dp[pos][val]%mod;
}


int main()
{
    memset(dp,-1,sizeof dp);
    cin>>n>>m;
    ll ans=0; ll i;
    for(ll i=1;i<=n;i++){
        ans= (ans+ DP(m*2,i))%mod;
    }
cout<<ans%mod<<endl;


    return 0;
}









































































