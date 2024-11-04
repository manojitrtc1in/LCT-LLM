

















  












  


















using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1e9+7;
const ld error = 2e-6;
const ld PI = acosl(-1); 

















inline ll MOD(ll x, ll m = mod){
    ll y = x % m;
    return (y >= 0) ? y: y+m;
}

const int inf = 1e9;
const ll infl = 1061109567;
const int nmax = 1000+10;



ll dp[30][1005]; ll n,m;
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









































































