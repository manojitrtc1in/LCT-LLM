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











 











 









 
 









ll dp[20][2][2][10][10];
ll memo[20][2][2][10][10];
ll n;
vector<ll> num;
ll solve(ll ind,ll ti,ll st,ll f,ll pd){
	if(ind==n){
		return ((st>0ll) && (f==pd));
	}
	if(memo[ind][ti][st][f][pd]) return dp[ind][ti][st][f][pd];
	ll res=0;
	memo[ind][ti][st][f][pd]=1ll;
	if(ti){
		for(ll i=0;i<num[ind];i++){
			if(i==0)res+=solve(ind+1,0ll,st,f,i);
			if(i>0){
				if(st==0) res+=solve(ind+1ll,0ll,1ll,i,i);
				else res+=solve(ind+1ll,0ll,st,f,i);
			}
		}
		if(num[ind]==0) res+=solve(ind+1ll,1ll,st,f,0ll);
		else{
			if(st==0) res+=solve(ind+1ll,1ll,1ll,num[ind],num[ind]);
			else res+=solve(ind+1ll,1ll,st,f,num[ind]);
		}
	}
	
	else{
		for(ll i=0;i<10;i++){
			if(i==0)res+=solve(ind+1,0ll,st,f,i);
			if(i>0){
				if(st==0) res+=solve(ind+1ll,0ll,1ll,i,i);
				else res+=solve(ind+1ll,0ll,st,f,i);
			}
		}
	}
	return dp[ind][ti][st][f][pd]=res;
}
int main(){
  ll i,j,k,l,m,r;
  cin>>l>>r;
 
  while(r) num.pb(r%10),r/=10;
  reverse(all(num));
  n=num.size();
  ll ans=0;
  memset(dp,0,sizeof(dp));
  memset(memo,0,sizeof(memo));
  ans=solve(0,1,0,0,0);
  
  num.clear();
  memset(dp,0,sizeof(dp));
  memset(memo,0,sizeof(memo));
  k=l;
  while(l) num.pb(l%10),l/=10;
  reverse(all(num));
  n=num.size();
  ans-=solve(0,1,0,0,0);
  
  num.clear();
  while(k) num.pb(k%10),k/=10;
  ans+=(num[0]==num[num.size()-1ll]);
  cout<<ans;
}
  
