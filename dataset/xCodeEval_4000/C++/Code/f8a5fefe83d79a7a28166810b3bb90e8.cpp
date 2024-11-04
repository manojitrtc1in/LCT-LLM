#include<bits/stdc++.h>
#include <iostream>
#include <numeric>
#define ll  long long
#define ull unsigned long long
#define mpa make_pair
#define pb push_back
#define ff first
#define dd double
#define trace(x) cerr << #x << " : " << x << endl
#define ss second
#define boost ios_base::sync_with_stdio(0)
#define forp(i,a,b) for(ll i=a;i<=b;i++)
#define rep(i,n)    for(ll i=0;i<n;++i)
#define ren(i,n)    for(ll i=n-1;i>=0;i--)
#define forn(i,a,b) for(ll i=a;i>=b;i--)
#define fre     freopen("input.in","r",stdin),freopen("output.txt","w",stdout)
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end();
#define sc(x) scanf("%lld",&x)
#define clr(x,val) memset(x,val,sizeof(x))
#define pr(x) printf("%lld\n",x) 
#define gc getchar
using namespace std;
template<class T> inline void umax(T &a,T b) {
	if(a<b) a = b ;
}
template<class T> inline void umin(T &a,T b) {
	if(a>b) a = b ;
}
template<class T> inline T abs(T a) {
	return a>0 ? a : -a;
}
template<class T> inline T gcd(T a,T b) {
	return __gcd(a, b);
}
template<class T> inline T lcm(T a,T b) {
	return a/gcd(a,b)*b;
}
ll modpow(ll a,ll n,ll temp) {
	ll res=1,y=a;
	while(n>0) {
		if(n&1)res=(res*y)%temp;
		y=(y*y)%temp;
		n/=2;
	}
	return res%temp;
}






 
#define sz(x) x.size()
ll ison(ll mask,ll pos) {
	return (mask&(1<<pos));
}
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;
ll cbit(ll n) {
	ll k=0;
	while(n) n&=(n-1),k++;
	return k;
}
ll nbit(ll n) {
	ll k=0;
	while(n) n/=2,k++;
	return k;
}
ll mod=1e9+7;
int sgn(ll x) {
	return x < 0 ? -1 : !!x;
}
const double eps = 1e-7;
const double pi = acos(-1.0);
inline void inc(ll &x, ll y){
	x+=y;
	if(x>=mod)x-=mod;
}
inline void dec(ll &x, ll y){
	x-=y;
	if(x<0) x+=mod;
}
inline void chmax(ll &x,ll y){
	if(y>x) x=y;
}
 
inline void mulm(ll &x,ll y){
	x*=y;
	if(x>=mod) x-=mod;
}
 



 
 


 




 

typedef pair<ll,pair<ll,ll> >ver;










 











 





 
ll xo(ll i) {
	if ((i&3)==0) return i;
	if ((i&3)==1) return 1;
	if ((i&3)==2) return i+1;
	return 0;
}



 
 
 



 
 


 




 

typedef pair<ll,pair<ll,ll> >ver;











 











 









 
 









vector<ll> in[105];
ll a[1005];
ll nxt[9][1015][1015];
ll dp[1ll<<8+5][1010];
ll memo[1ll<<8+5][1010];
ll n,x;
ll solve(ll mask,ll ind){
	if(mask==(1ll<<8)-1ll) return 0;
	if(memo[mask][ind]) return dp[mask][ind];
	ll res=-mod;
	memo[mask][ind]=1ll;
	for(ll i=0;i<8;i++){
		if(mask&(1ll<<i)) continue;
		ll pos1=nxt[i][ind][x];
		if(pos1!=-1) res=max(res,solve(mask|(1ll<<i),pos1+1ll));
		ll pos2=nxt[i][ind][x+1];
		if(pos2!=-1) res=max(res,1ll+solve(mask|(1ll<<i),pos2+1ll));
	}
	return dp[mask][ind]=res;
}
bool can(){
	memset(dp,0,sizeof(dp));
	memset(memo,0,sizeof(memo));
	if(solve(0,0)<0) return 0;
	else return 1ll;
}
int main(){
   ll i,j,k,l,m; 
   set<ll> u;
   cin>>n;
   for(ll i=0;i<n;i++)cin>>a[i],a[i]--,u.insert(a[i]);
   ll ans=u.size();
   
   for(ll i=0;i<8;i++){
   	  for(ll k=1;k<=n+10;k++){
   	       nxt[i][n][k]=-1;	
		 }
   }
   
   for(i=n-1;i>=0;i--){
   	   for(ll c=0;c<8;c++){
   	   	     if(a[i]==c) nxt[c][i][1]=i;
   	   	     else nxt[c][i][1]=nxt[c][i+1][1];
   	   	     for(ll k=2;k<=n+10;k++){
   	   	     	if(a[i]==c) nxt[c][i][k]=nxt[c][i+1][k-1];
			    else nxt[c][i][k]=nxt[c][i+1][k];   
			 }
   	      }
   }
   l=1;
   ll r=n;
   ll best=0;
   while(r>=l){
   	ll mid=(l+r)/2ll;
   	x=mid;
   	if(can()) best=mid,l=mid+1ll;
   	else r=mid-1ll;
   }
   if(best){
   	 x=best;
   	 memset(dp,0,sizeof(dp));
	 memset(memo,0,sizeof(memo));
     ans=8*x+solve(0,0);		  
   }
   cout<<ans;
}
   