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











 











 









 
 









ll w[100005];
ll b[100005];
ll a[100005];
void init(ll n)
{for(int i=1;i<=n;i++) a[i]=i;}
ll root(ll x)
{
	while(a[x]!=x)
	{
		a[x]=a[a[x]];
		x=a[x];
	}
	return x;
}
ll u1(ll x,ll y)
{
	int p=root(x);
	int q=root(y);
	a[p]=a[q];
}
ll dp[1005][1005],memo[1005][1005];
vector<ll> comp[1005];
ll n;
ll solve(ll ind,ll lw){
	if(ind==n+1) return 0;
	if(lw<=0) return 0;
	if(memo[ind][lw]) return dp[ind][lw];
	memo[ind][lw]=1ll;
	ll res=0;
	res=solve(ind+1ll,lw);
	ll sw=0,sb=0;
	for(ll i=0;i<comp[ind].size();i++){
		if(w[comp[ind][i]]<=lw) {
			res=max(res,b[comp[ind][i]]+solve(ind+1,lw-w[comp[ind][i]]));
		}
		sw+=w[comp[ind][i]];
		sb+=b[comp[ind][i]];
	}
	if(sw<=lw) res=max(res,sb+solve(ind+1,lw-sw));
	return dp[ind][lw]=res;
}

int main(){

	ll wt,x,k,m,p,t,i,j;
	cin>>n>>m>>wt;
	init(n);
    for(i=1;i<=n;i++)cin>>w[i];
    for(i=1;i<=n;i++)cin>>b[i];
    while(m--){
    	ll x,y;
    	cin>>x>>y;
    	u1(x,y);
	}
	
	for(i=1;i<=n;i++) comp[root(i)].pb(i);
	
	
	
	cout<<solve(1,wt);
	

}

