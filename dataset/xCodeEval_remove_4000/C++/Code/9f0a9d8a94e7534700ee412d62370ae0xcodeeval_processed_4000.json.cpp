






















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











 











 









 
 









ll a[1005][1005];
ll row[1005],col[1005];
ll sqr(ll x){
	return x*x;
}
int main(){
	ll i,j,k,l,m,n;
	boost;
    cin>>n>>m;
    for(i=0;i<n;i++){
    	for(j=0;j<m;j++){
    		cin>>a[i][j];
    		row[i]+=a[i][j];
    		col[j]+=a[i][j];
		}
	}
	mod=2e18;
	ll x=0,y=0;
	ll mx=mod,my=mod;
	for(ll i=0;i<=n;i++){
		ll tmp=0;
		for(j=0;j<i;j++) tmp+=(row[j])*sqr(abs(i-j-1)*4+2);
		for(j=i;j<n;j++) tmp+=(row[j])*sqr(abs(i-j)*4+2);
		if(tmp<mx){
			mx=tmp;
			x=i;
		}
    }
    for(ll i=0;i<=m;i++){
		ll tmp=0;
		for(j=0;j<i;j++) tmp+=(col[j])*sqr(abs(i-j-1)*4+2);
		for(j=i;j<m;j++) tmp+=(col[j])*sqr(abs(i-j)*4+2);
		if(tmp<my){
			my=tmp;
			y=i;
		}
    }
    cout<<mx+my<<endl;
    cout<<x<<" "<<y;
}