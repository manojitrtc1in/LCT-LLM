






















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










 











 









 
 









pair<ll,ll> edges[100005];

vector<ll> adj[100005];
ll n;

ll check(ll mid){
	
	ll i,j,k,l,s;
	ll indg[100005]={0},pr[100005]={0};
    for(i=1;i<=n;i++) adj[i].clear();
    for(i=1;i<=mid;i++) adj[edges[i].ff].pb(edges[i].ss),pr[edges[i].ff]=1,pr[edges[i].ss]=1,indg[edges[i].ss]++;
    queue<ll> q;
    j=0;
    for(i=1;i<=n;i++) if(pr[i] && indg[i]==0) q.push(i);
    while(q.size()){
    	if(q.size()>1) return 0;
		ll v=q.front();
		j++;
		q.pop();
		for(ll i=0;i<adj[v].size();i++) {
			indg[adj[v][i]]--;
			if(indg[adj[v][i]]==0) q.push(adj[v][i]);
		} 
    }
    return (j==n);
}
int main(){
	ll q,i,j,k,l,m;
    cin>>n>>m;
    for(i=1;i<=m;i++) cin>>edges[i].ff>>edges[i].ss;
    ll hi=m;
    ll lo=1;
    ll ans=mod;
    while(hi>=lo){
    	ll mid=(hi+lo)/2;
    	if(check(mid)) ans=min(ans,mid),hi=mid-1;
    	else lo=mid+1;
    }
    if(ans==mod)cout<<-1;
    else cout<<ans;
}
    

