

















  












  


















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


 


void solve(){
int n,m,k; cin>>n>>m>>k;
int i; vector<int>vc; k= min(k, m-1);  

for(i=0;i<n;i++){
    int xx; cin>>xx; vc.pb(xx);
}

int sz= n-m+1; int j;
int ans=0;
for(i=0;i<=k;i++){
int ot=1e9 + 7;
    for(j=0;j<=m-1-k;j++){
        ot= min( max( vc[0+i+j],vc[0+i+j+n-m] ),ot);
    }
    ans= max(ans,ot);
}

cout<<ans<<endl;




}

int main()
{
    int t; cin>>t;
    while(t--){
     solve();
    }

    return 0;
}









































































