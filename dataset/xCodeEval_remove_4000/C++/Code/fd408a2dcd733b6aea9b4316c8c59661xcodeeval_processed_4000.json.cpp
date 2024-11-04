






















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











 











 









 
 









ll a[100005];
ll b[100005];
ll pri[32000];
map<ll,ll> help;
void sieve(){
	pri[0]=pri[1]=1;
	for(ll i=2;i<=32000;i++){
		if(pri[i]==0){
			for(ll j=2*i;j<=32000;j+=i) pri[j]=1;
		}
	}
}
int main(){
	ll k,n,x,t,i,j,l;
	a[0]=1;
	sieve();
	vector<ll> pr;
	cin>>n;
	for(ll i=2;i<=32000;i++)if(1-pri[i])pr.pb(i);
	b[0]=1;
	for(i=1;i<=100000;i++)a[i]=(a[i-1]*i)%mod,b[i]=modpow(a[i],mod-2,mod);
	
	for(i=1;i<=n;i++){
		cin>>j;
		for(k=0;k<pr.size();k++){
			while(j%pr[k]==0){
				help[pr[k]]++;
				j/=pr[k];
			}
		}
		if(j>1)help[j]++;
	}
	ll ans=1ll;
	map<ll,ll>::iterator it;
	for(it=help.begin();it!=help.end();it++){
		ll j=it->ss;
		ll o=a[n+j-1];
		o=(o*b[j])%mod;
		o=(o*b[n-1])%mod;
		
		ans=(ans*o)%mod;
	}
	cout<<ans;
}
