

















  












  


















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



ll bigmod(ll a, ll b, ll m= mod){
if(b==0) return 1;
ll x= bigmod(a,b/2,mod);
x= (x*x)%mod;
if(b%2==1) x= (x*a)%mod;

return x;
}


ll modinv(ll b, ll m=mod){
return bigmod(b,m-2,mod);
}



int main()
{
    vector<ll>vc; vc.pb(1);
    ll i;
    for(i=1;i<=1030;i++){
        ll xx= (vc[i-1]*i)%mod; vc.pb(xx);
    }

    ll n,m; cin>>n>>m;

    ll ot= ( (vc[m+m+n-1]* modinv(vc[m+m]))%mod * modinv(vc[n-1])%mod )%mod ;
    cout<<ot<<endl;

    return 0;
}









































































