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
#define fre     freopen("input.txt","r",stdin),freopen("output.txt","w",stdout)
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










 











 









 
 








char a[1005][1005];
ll lvl[1005][1005];
ll vis[1005][1005]; 
ll dx[5]={1,-1,0,0};
ll dy[5]={0,0,1,-1};

int main(){
	ll r,c,n,m,t,i,j,l;
	cin>>r>>c;
	for(i=0;i<=r+1;i++) for(j=0;j<=c+1;j++) a[i][j]='T';
	for(i=1;i<=r;i++)for(j=1;j<=c;j++)cin>>a[i][j];
	
	ll x1,y1,x2,y2;
	for(i=1;i<=r;i++)for(j=1;j<=c;j++) if(a[i][j]=='S') x1=i,y1=j;
	for(i=1;i<=r;i++)for(j=1;j<=c;j++) if(a[i][j]=='E') x2=i,y2=j;
	queue<pii> q;
	q.push(mpa(x2,y2));
	vis[x2][y2]=1;
	while(!q.empty()){
	    pii v=q.front();
	    ll x=v.ff;
	    ll y=v.ss;
	    q.pop();
	    for(ll i=0;i<4;i++){
	        if(!vis[x+dx[i]][y+dy[i]] && a[x+dx[i]][y+dy[i]]!='T'){
	            lvl[x+dx[i]][y+dy[i]]=lvl[x][y]+1;
	            vis[x+dx[i]][y+dy[i]]=1;
	            q.push(mpa(x+dx[i],y+dy[i]));
	        }
	   }
	}
	
	ll ans=0;
    for(i=1;i<=r;i++)for(j=1;j<=c;j++) if(a[i][j]>='0' && a[i][j]<='9' && lvl[x1][y1]>=lvl[i][j] && vis[i][j]>0) ans+=(a[i][j]-'0');
	cout<<ans; 
	
	
	
}
 
    
 
 
 