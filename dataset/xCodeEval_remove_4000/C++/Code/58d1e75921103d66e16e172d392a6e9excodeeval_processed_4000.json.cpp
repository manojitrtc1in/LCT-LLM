


























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



 
 
 



 
 


 




 














 











 









 
 










ll a[200005],b[200005];
pii sol[200005];
vector<ll>  c;
map<ll,ll> help;
vector<ll> seg[1000005];
vector<ll> v;
void build(ll node,ll l,ll r){
	if(l==r){
		seg[node].pb(a[l]);
		return ;
	}
	ll m=(l+r)/2ll;
    build(node*2ll,l,m);
	build(node*2ll+1ll,m+1,r);
	seg[node].resize(seg[node*2ll].size()+seg[node*2ll+1ll].size());
	merge(seg[node*2ll].begin(),seg[node*2ll].end(),seg[node*2ll+1ll].begin(),seg[node*2ll+1ll].end(),seg[node].begin());	
}
ll query(ll node,ll lo,ll hi,ll x,ll y,ll val){
	if(x>hi || y< lo) return 0ll;
	if(lo>=x && hi<=y){
		ll k=upper_bound(all(seg[node]),val)-seg[node].begin();
		return k;
	}
	ll m=(hi+lo)/2ll;
	return query(node*2ll,lo,m,x,y,val)+query(node*2ll+1ll,m+1,hi,x,y,val);
}



int main() 
{ 
   
  ll n,j;
  
  sc(n);
  
  for(ll i=1;i<=n;i++)sc(j),sol[i]=mpa(-j,i),help[i]=j;
  sort(sol+1,sol+n+1);
  
  for(ll i=1;i<=n;i++)a[i]=sol[i].ss,c.pb(a[i]);
  sort(all(c));
  
  
  for(ll i=1;i<=n;i++) a[i]=lower_bound(all(c),a[i])-c.begin()+1ll;
  build(1,1,n);
  
  ll q;
  cin>>q;
  while(q--){
  	 ll k,pos;
  	 sc(k);
  	 sc(pos);
  	
  	 ll lo=1ll;
  	 ll hi=n;
  	 ll ans;
  	while(hi>=lo){
  		ll m=(hi+lo)/2ll;
  
  		if(query(1,1,n,1,k,m)>=pos){
  		   ans=m;
  			hi=m-1ll;
		  }
		else{
		    
			lo=m+1ll;
		} 
  	  }
  	  pr(help[ans]); 
    }
   
	  
}
  
   
     

 