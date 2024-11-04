






















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











 











 









 
 









vector<pii> tp,mar;
char a[105][105];
int main(){
	ll i,j,k,l,m,n;
	cin>>n;
	char ch;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			cin>>ch;
			tp.pb(mpa(i,j));
			a[i][j]=ch;
		}
	}
    vector<pii> ans;
	
	while(tp.size()>0){
		ll nx=-1,ny=-1,c=0;
		map<ll,ll> row,col;
	    for(i=0;i<tp.size();i++) row[tp[i].ff]++,col[tp[i].ss]++;
		for(i=1;i<=n;i++)for(j=1;j<=n;j++){
			if(a[i][j]!='E' && row[i]+col[j]>=c) c=row[i]+col[j],nx=i,ny=j;
		}
	    if(c==0) break;
		ans.pb(mpa(nx,ny));
		vector<pii> temp;
		for(i=0;i<tp.size();i++) if(tp[i].ff!=nx && tp[i].ss!=ny) temp.pb(tp[i]);
		tp=temp;
    }
    

    
	if(tp.size()>0)cout<<-1;
	else{
		
		for(i=0;i<ans.size();i++)cout<<ans[i].ff<<" "<<ans[i].ss<<endl;
	}
}