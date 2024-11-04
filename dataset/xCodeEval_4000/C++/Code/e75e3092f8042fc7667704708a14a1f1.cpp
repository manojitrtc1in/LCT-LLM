
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
#define IN inline
#define RE register
#define F first
#define S second 
#define FF fflush(stdout)
#define random(x) (rand()%x)
#define LOG(m,n) 1.0*log(n)/log(m)
#define lc(p) (p<<1)
#define rc(p) (p<<1|1)
#define cmin(a,b) (a=min(a,b))
#define cmax(a,b) (a=max(a,b))
using namespace std;
#define N 1000005
#define mod 998244353
#define INF 0x3f3f3f3f
int n,l,k,a[N];
char s[N];
ii dp[N];
inline int calc(int x){
	for(int i=1;i<=n;++i) dp[i]=ii(INF,INF);
	for(int i=0;i<n;++i){
		cmin(dp[i+1],ii(dp[i].F+a[i+1],dp[i].S));
		cmin(dp[min(i+l,n)],ii(dp[i].F+x,dp[i].S+1));
	}
	return dp[n].S;
}
inline int solve(){
	int l=0,r=n,mid;
	while(l<=r){
		mid=l+r>>1;
		if(calc(mid)<=k) r=mid-1;
		else l=mid+1;
	}
	calc(l);
	return dp[n].F-1ll*k*l;
}
int main(){
	int ans=INF;
	scanf("%d%d%d%s",&n,&k,&l,s+1);
	for(int i=1;i<=n;++i) a[i]=(s[i]>='A'&&s[i]<='Z');
	cmin(ans,solve());
	for(int i=1;i<=n;++i) a[i]=(s[i]>='a'&&s[i]<='z');
	cmin(ans,solve());
	printf("%d\n",ans);
    return 0;
}