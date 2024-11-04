























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











 











 









 
 









vector<ll> adj[100005];
ll col[10005];
ll graph[105][105];
ll val=1ll,n;
void dfs(ll v,ll c){
	if(col[v]!=-1 && col[v]!=c)val=0ll;
	if(val && col[v]==-1){
		col[v]=c;
		for(ll j=1;j<=n;j++){
			if(graph[v][j]!=-1) dfs(j,c^graph[v][j]);
		}
	}
}
bool chk(){
	for(ll i=1;i<=n;i++)if(col[i]==-1) dfs(i,0);
	return val;
}
int main(){
  ll s,k,no,m,i,j,sc,n1,m1,n2,m2;
  cin>>n>>m;
  for(ll i=1;i<=n;i++)for(j=1;j<=n;j++)graph[i][j]=-1;
  for(ll i=1;i<=n;i++)col[i]=-1;
  while(m--){
  	ll x,y,c;
  	cin>>x>>y>>c;
  	adj[x].pb(y);
  	adj[y].pb(x);
  	graph[x][y]=graph[y][x]=1ll^c;
  }
  if(!chk()){
  	cout<<"Impossible";
  	return 0;
  }
  ll ans=0;
  for(ll i=1;i<=n;i++)ans+=(col[i]==1ll);
  cout<<ans<<endl;
  for(i=1;i<=n;i++)if(col[i]==1) cout<<i<<" ";
  

  

}


