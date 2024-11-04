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











 











 









 
 









vector<ll> adj[200005],nadj[200005];
ll comp[200005],vis[200005];
ll col[200005];
ll nc;
void dfs(ll v,ll p){
	comp[v]=nc;
	vis[v]=1;
	for(ll i=0;i<adj[v].size();i++){
		if(col[adj[v][i]]==col[v] && adj[v][i]!=p && vis[adj[v][i]]==0) dfs(adj[v][i],v);
	}
}
ll nv,ans=0;
ll dfs2(ll v,ll p,ll lvl){
	if(lvl>ans){
		ans=lvl;
		nv=v;
	}
	for(ll i=0;i<nadj[v].size();i++){
		if(nadj[v][i]!=p){
			dfs2(nadj[v][i],v,lvl+1);
		}
	}
}
int main(){
	ll n,p,t,i,j,l;
	cin>>n;
	for(i=1;i<=n;i++)cin>>col[i];
	for(i=1;i<n;i++){
		ll x,y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	for(i=1;i<=n;i++) if(!vis[i]) dfs(i,-1),nc++;
	for(i=1;i<=n;i++){
		for(j=0;j<adj[i].size();j++){
			ll v=adj[i][j];
			if(comp[v]!=comp[i]) nadj[comp[i]].pb(comp[v]);
		}
	}
	dfs2(0,-1,0);
	dfs2(nv,-1,0);
	cout<<(ans+1ll)/2ll;
}
