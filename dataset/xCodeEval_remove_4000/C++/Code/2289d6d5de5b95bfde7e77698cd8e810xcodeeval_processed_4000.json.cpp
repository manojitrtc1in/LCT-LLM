






















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











 











 









 
 









dd dp[205][205][205],pro[205];
ll a[205];
int main(){
   ll n,i,j,k,l;
   cout<<setprecision(10);
   cout<<fixed;
   cin>>n>>l>>k;
   for(i=1;i<=n;i++)cin>>pro[i],pro[i]/=100.00;
   for(i=1;i<=n;i++)cin>>a[i],a[i]++;
   if(k<n)dp[0][0][k]=1;
   else dp[0][0][n]=1;
   for(i=0;i<n;i++){
   	  for(j=0;j<=i;j++){
   	  	   for(k=0;k<=n;k++){
   	  	   	    dp[i+1][j+1][min(n,k+a[i+1])]+=pro[i+1]*dp[i][j][k];
   	  	   	    dp[i+1][j][k]+=(1.00-pro[i+1])*dp[i][j][k];
   	  	   	    }
		 }
   }
   dd ans=0.0;
   for(i=l;i<=n;i++)for(j=i;j<=n;j++) ans+=dp[n][i][j];
   cout<<ans;
}
