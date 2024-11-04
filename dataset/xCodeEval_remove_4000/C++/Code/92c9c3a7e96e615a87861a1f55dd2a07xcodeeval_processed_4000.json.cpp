






















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











 











 









 
 









vector<pii> adj[200005];
priority_queue<ll> q;
ll vis[200005];
ll n,m,t,c=0;
void solve(ll ind){
	if(ind==n){
		q.push(c);
		if(q.size()>t) q.pop();
		return ;
	}
	solve(ind+1);
	for(ll i=0;i<adj[ind].size();i++){
		if(vis[adj[ind][i].ff]==0){
			vis[adj[ind][i].ff]=1;
			c+=adj[ind][i].ss;
			if(q.size()<t || c<q.top())solve(ind+1);
			c-=adj[ind][i].ss;
			vis[adj[ind][i].ff]=0;
		}
	}
}
int main(){
	ll r,s=0,x,i,j,k,l,m;
	cin>>n>>m>>t;
	while(m--){
		ll x,y,w;
		cin>>x>>y>>w;
		x--,y--;
		adj[x].pb(mpa(y,w));
	}
	solve(0);
	cout<<q.top();
	
}
