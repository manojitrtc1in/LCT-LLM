























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











 











 









 
 









ll csum[100005];
ll a[100005];
ll n;
ll gsum(ll l,ll r){
	r=min(r,n-1ll);
	return csum[r]-csum[l-1];
}
int main(){
  ll s,k,x,no,m,i,j,sc;
  cin>>n;
  for(i=0;i<n;i++)cin>>a[i];
  
  sort(a,a+n);
  reverse(a,a+n);
  csum[0]=a[0];
  
  for(ll i=1;i<n;i++)csum[i]=csum[i-1]+a[i];
  ll q;
  cin>>q;
  ll res1=0;
  for(ll i=1;i<n;i++)res1+=(i*a[i]);
  while(q--){
  	cin>>k;
  	if(k==1){
  		cout<<res1<<" ";
  		continue;
	}
	ll sz=1ll,res=0;
	for(ll j=1,t=1;j<n;j+=sz,t++){
		sz*=k;
		res+=gsum(j,j+sz-1ll)*t;
	}
	cout<<res<<" ";
  }
}


