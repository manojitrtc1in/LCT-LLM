


























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
ll p2(ll n){
	return (1ll<<n);
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
ll mod=1000000007;
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



 
 
 



 
 


 




 














 











 









 
 














ll a[200005];
int main(){
  ll q,t,n,k,m,j,l;
  cin>>n>>k>>l;
  for(ll i=1;i<=n*k;i++)cin>>a[i];
  sort(a+1,a+n*k+1);
  ll ans=0;
  ll u=1;
  for(ll i=1;i<=n*k;i++) if(a[i]<=a[1]+l)u=i;
  if(u<n){
  	cout<<0;
  	return 0;
  }
  ll o=1ll;
  for(ll i=1;i<=n;i++){
  	ans+=a[o];
  	for(ll j=1;j<=k;j++){
  	    
  		if(u-(o+1)>=n-i-1)o++;
  		else break;
	}
  }
  cout<<ans;
}
	
	
	
	