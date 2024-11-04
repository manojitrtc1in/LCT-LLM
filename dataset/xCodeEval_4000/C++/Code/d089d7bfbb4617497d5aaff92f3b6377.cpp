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











 











 









 
 












int main(){
    ll n,i,j,k,a,b;
    cin>>n>>k>>a>>b;
    string ans;
    
    ll d=max(a,b);
    ll c=min(a,b);
    if(a==0 || b==0){
    	if(k==n){
    		for(ll i=0;i<n;i++) {
    			if(a>0)cout<<"G";
    			else cout<<"B";
			}
		}
		else{
			cout<<"NO";
		}
		return 0;
	}
    vector<ll> black,green;
	for(ll i=1;i<=d;i++){
        if((d+i-1ll)/i<=k && c>=(i-1) && c-(i-1)*k<=2ll*k){
    	    
				for(j=1;j<=i;j++)black.pb(d/i);
    	        for(j=0;j<d%i;j++)black[j]++;
    	        
				for(j=0;j<=i+1;j++)green.pb(0);
    	        for(j=1;j<i;j++)green[j]++,c--;
    	        for(j=1;j<i;j++)green[j]+=min(c,k-1ll),c-=min(c,k-1ll);
    	        
				if(c>0) green[0]+=min(k,c),c-=min(c,k);
    	        if(c>0) green[i]=c;
    	        
				break;
        }
    }
    string u;
    
    if(green.size()==0 || black.size()==0){
    	cout<<"NO\n";
    	return 0;
	}
	
    for(ll i=0;i<black.size();i++){
          while(black[i]) ans+='B',black[i]--;
		  while(green[i+1]) ans+='G',green[i+1]--;
    }
    while(green[0]>0) u+='G',green[0]--;
    while(green[green.size()-1]>0 && green.size()>=2) ans+='G',green[green.size()-1]--;
	ans=u+ans;
	ll c1=0,c2=0;
	for(ll i=0;i<n;i++)c1+=(ans[i]=='G'),c2+=(ans[i]=='B');
	
	if(c1!=a){
		for(ll i=0;i<n;i++){
			if(ans[i]=='G') ans[i]='B';
			else ans[i]='G';
		}
	}
	
	if(ans=="") ans="NO";
	cout<<ans;
    



}


	

