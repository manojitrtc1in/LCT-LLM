






















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











 











 









 
 









vector<vector<ll> > data;
int main(){
  ll i,j,k,l,m,n;
  cin>>n;
  ll tot=0;
  for(ll i=1;i<=n;i++){
  	ll k,a,x,y,m;
  	cin>>k>>a>>x>>y>>m;
  	tot+=k;
  	vector<ll> tmp;
  	tmp.pb(a);
  	for(j=2;j<=k;j++) tmp.pb((tmp[tmp.size()-1ll]*x+y)%m);
	data.pb(tmp);  
  }
  set<pair<ll,pii> > q;
  for(ll i=0;i<n;i++) q.insert(mpa(data[i][0],mpa(i,0)));
  vector<ll> ans;
  vector<pii> sol;
  ll p=0;
  while(ans.size()<tot){
  	set<pair<ll,pii>>::iterator it=q.lower_bound(mpa(p,mpa(-1ll,-1ll)));
  	if(it==q.end()) it=q.begin();
  	ll v=(*it).ff;
  	p=v;
  	pii o=(*it).ss;
  	ans.pb(v);
  	sol.pb(mpa(v,o.ff+1ll));
  	q.erase(*it);
  	if(o.ss+1ll<data[o.ff].size()) q.insert(mpa(data[o.ff][o.ss+1ll],mpa(o.ff,o.ss+1ll)));
  }
  
  ll bad=0;
  for(i=1;i<ans.size();i++) if(ans[i-1]>ans[i]) bad++;
  cout<<bad<<endl;
  if(tot<=200000) for(i=0;i<sol.size();i++)cout<<sol[i].ff<<" "<<sol[i].ss<<endl;
}
  