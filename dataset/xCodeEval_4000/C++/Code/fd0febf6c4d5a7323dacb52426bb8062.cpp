#include<bits/stdc++.h>
#include <iostream>
#include <numeric>
#define ll  long long
#define ull unsigned long long
#define mpa make_pair
#define pb push_back
#define ff first
#define dd double
#define trace(x) cerr << #x << " : " << x << endl
#define ss second
#define boost ios_base::sync_with_stdio(0)
#define forp(i,a,b) for(ll i=a;i<=b;i++)
#define rep(i,n)    for(ll i=0;i<n;++i)
#define ren(i,n)    for(ll i=n-1;i>=0;i--)
#define forn(i,a,b) for(ll i=a;i>=b;i--)
#define fre     freopen("input.in","r",stdin),freopen("output.txt","w",stdout)
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end();
#define sc(x) scanf("%lld",&x)
#define clr(x,val) memset(x,val,sizeof(x))
#define pr(x) printf("%lld\n",x) 
#define gc getchar
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






 
#define sz(x) x.size()
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











 











 









 
 









pair<pii,ll> a[100005];
ll ans[100005];
queue<pii> qu[10005];

int main(){
   ll n,i,b,m,r,j;
   cin>>n>>m;
   ll tim=0;
   for(i=1;i<=n;i++){
   	  ll t,x;
   	  cin>>a[i].ff.ff>>a[i].ff.ss;
   	  a[i].ss=i;
   }
   
   sort(a+1,a+n+1);
  
   
   
   for(i=1;i<=n;i=i+m){
   	    ll ma=0;
   	    tim=max(tim,a[min(n,i+m-1)].ff.ff);
	    ll pr=0;
		for(j=i;j<=min(n,i+m-1);j++) a[j].ff.ff=a[j].ff.ss;
   	 	sort(a+i,a+min(n+1,i+m));
   	 	

   	 	for(j=i;j<=min(n,i+m-1);){
   	 	    ll nos=0;
   	 	    ll k=j;
   	 	    ma=max(ma,a[j].ff.ss);
   	 	    tim+=(a[j].ff.ss-pr);
   	 	    pr=a[j].ff.ss;
   	 	    while(k<=min(n,i+m-1) && a[j].ff.ss==a[k].ff.ss)nos++,ans[a[k].ss]=tim,k++;
   	 	    j=k;
   	 	    tim+=(1+(nos)/2);
   	 	    
   	 	}
   	    tim+=ma;	 
   }
   
   for(i=1;i<=n;i++)cout<<ans[i]<<" ";
}