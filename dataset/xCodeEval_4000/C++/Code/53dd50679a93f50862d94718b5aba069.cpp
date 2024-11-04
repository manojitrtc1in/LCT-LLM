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
#define pdd pair<dd,dd>
#define prec(x) cout<<fixed<<setprecision(x)
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
ll getbit(ll j,ll i){
	return ((i>>(j-1ll))&1ll);
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
 



 
 


 




 













 











 





 
ll xo(ll i) {
	if ((i&3)==0) return i;
	if ((i&3)==1) return 1;
	if ((i&3)==2) return i+1;
	return 0;
}



 
 
 



 
 


 




 














 











 









 
 









vector<ll> adj[200005];
bool isc[200005];
ll col[200005];
ll sz[200005];
ll vis[200005];
ll pa[2000005];
ll sz1[200005];
void dfs(ll v,ll p){
	ll val=1ll;
	pa[v]=p;
	set<ll> co;
	sz[v]++;
	co.insert(col[v]);
	for(ll i=0;i<adj[v].size();i++){
		if(adj[v][i]==p)continue;
		dfs(adj[v][i],v);
		sz[v]+=sz[adj[v][i]];
		val&=isc[adj[v][i]];
		co.insert(col[adj[v][i]]);
	}
    if(val==1ll && co.size()==1ll)isc[v]=1ll; 
}
ll cn=0;

void dfs2(ll v,ll p){
	vis[v]=1ll;
	cn++;
	sz1[v]++;
	for(ll i=0;i<adj[v].size();i++){
		if(adj[v][i]!=p && col[adj[v][i]]==col[1])dfs2(adj[v][i],v),sz1[v]+=sz1[adj[v][i]];
	}
}
int main(){
	ll i,j,k,l,m,n,z;
	cin>>n;
	for(ll i=1;i<n;i++){
		ll x,y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	for(ll i=1;i<=n;i++)cin>>col[i];
	dfs(1,-1);
    if(isc[1]){
    	cout<<"YES\n1";
    	return 0;
	}
	dfs2(1,-1);
	ll ans=-1;
	
	for(ll i=1;i<=n;i++){
	   if(cn+sz[i]-sz1[i]==n ){
	   	ll f=1;
	   	for(ll j=0;j<adj[i].size();j++){
	   		if(isc[adj[i][j]]==0ll && adj[i][j]!=pa[i] ) {f=0;break;}
	   	   }
	   	   if(f) {ans=i;break;}
	   }
	}
	if(ans==-1)cout<<"NO";
	else{
		cout<<"YES\n";
		cout<<ans;
	}
	
	

}

