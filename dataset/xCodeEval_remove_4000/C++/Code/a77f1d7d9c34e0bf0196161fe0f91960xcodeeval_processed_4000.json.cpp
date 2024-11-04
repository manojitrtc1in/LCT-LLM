


























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
const double eps = 6*1e-8;
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



 
 
 



 
 


 




 














 











 









 
 










set<ll> adj[30];
ll vis[30];
vector<ll> sol;
ll f=1ll;
ll dfs(ll v,ll p){
	vis[v]=1;
	sol.pb(v);
	if(adj[v].size()>2) {f=0;return 1;}
	set<ll>::iterator it;
	for(it=adj[v].begin();it!=adj[v].end();it++){
		ll u=*it;
			
	    if(u!=p && vis[u]==0) dfs(u,v);
		else if(u!=p and vis[u])f=0;
	}
	return 0;
}
int main() 
{  
    ll t;
    cin>>t;
    ll f=0;
    while(t--){
    	string s;
    	cin>>s;
    	sol.clear();
    	f=1;
    	for(ll i=0;i<26;i++)adj[i].clear(),vis[i]=0;
    	ll n=s.size();
    	for(ll i=0;i<n;i++){
    		if(i+1<n)adj[s[i]-'a'].insert(s[i+1]-'a');
    		if(i-1>=0)adj[s[i]-'a'].insert(s[i-1]-'a');
    		
		}
		for(ll i=0;i<26;i++)if(adj[i].size()>2)f=0;
	
		for(ll i=0;i<26;i++){
			if(vis[i]==0 && adj[i].size()==1) dfs(i,i);
		    else if(vis[i]==0 && adj[i].size()==0)sol.pb(i);
		}
		
		for(ll i=0;i<26;i++){
		    	if(vis[i]==0 && adj[i].size()==2)f=0;
		}
		if(f){
			cout<<"YES\n";
			for(ll i=0;i<26;i++)cout<<char('a'+sol[i]),vis[sol[i]]=1;
			for(ll i=0;i<26;i++)if(vis[i]==0) cout<<char('a'+i);
			cout<<endl;
		}
		else cout<<"NO\n";
		
    	
    	
	}
 
      
	
    
 
     
     
}
  
  
  