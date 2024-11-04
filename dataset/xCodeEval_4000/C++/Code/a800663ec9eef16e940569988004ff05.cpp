

















  












  




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


 


void solve(){
int n,m,k; cin>>n>>m>>k;
int i; vector<int>vc; k= min(k, m-1);  vc.pb(3500);
for(i=0;i<n;i++){
    int xx; cin>>xx; vc.pb(xx);
}

int sz= n-m+1; int j;
int ans=0;
for(i=0;i<=k;i++){
int ot=1e9 + 7;
    for(j=0;j<=m-1-k;j++){
        ot= min( max( vc[1+i+j],vc[1+i+j+n-m] ),ot);
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









































































