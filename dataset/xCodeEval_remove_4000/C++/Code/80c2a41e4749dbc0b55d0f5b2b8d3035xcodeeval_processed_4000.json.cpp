






















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











 











 









 
 









map<ll,ll> help1,help2;
pii a[100005];
int main(){
  ll n,i,j,k,l,m,r;
  cin>>n;
  for(ll i=1;i<=n;i++){
  	cin>>a[i].ff>>a[i].ss;
	help1[a[i].ff]++;
	if(a[i].ff!=a[i].ss)help2[a[i].ss]++;
  }
  ll ans=mod;
  for(ll i=1;i<=n;i++){
  	if(help1[a[i].ff]>=(n+1ll)/2ll){
  		cout<<0;
  		return 0;
	  }
	ll req=(n+1ll)/2ll;
	req-=help1[a[i].ff];
	if(req<=help2[a[i].ff]) ans=min(ans,req);  
  }
  help1.clear();
  help2.clear();
  for(ll i=1;i<=n;i++){
  	help1[a[i].ss]++;
  	if(a[i].ss!=a[i].ff) help2[a[i].ff]++;
  }
  for(ll i=1;i<=n;i++){
  	if(help1[a[i].ss]>=(n+1ll)/2ll) ans=min(ans,(n+1ll)/2ll);
	  
	ll req=(n+1ll)/2ll;
	req-=help1[a[i].ss];
	if(req<=help2[a[i].ss]) ans=min(ans,help1[a[i].ss]);  
  }
  if(ans==mod)cout<<-1;
  else cout<<ans;
  
  
  
  
}
  
