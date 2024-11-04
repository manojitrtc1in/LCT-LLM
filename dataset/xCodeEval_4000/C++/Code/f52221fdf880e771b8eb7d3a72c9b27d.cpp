
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
#define IN inline
#define RE register
#define F first
#define S second 
#define FF fflush(stdout)
#define random(x) (rand()%x)
#define LOG(m,n) 1.0*log(n)/log(m)
using namespace std;
#define maxn 305
ll ans=-0x7fffffffffffffffll,sum=0,dis,dp[150005];
pli dq[150005];
int main(){
	int hd,tl,n,m,d,a,b,tcur,tpre=1;
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a,&b,&tcur);
		sum+=b;
		dis=min(1ll*n,1ll*d*(tcur-tpre));
		hd=1;tl=0;
		for(int j=1;j<=n+dis;j++){
			if(hd<=tl&&dq[hd].S<=j-dis*2-1) ++hd;
			if(j<=n){while(hd<=tl&&dq[tl].F>=dp[j]) --tl;dq[++tl]=pli(dp[j],j);}
			if(j>dis) dp[j-dis]=dq[hd].F+abs(a-j+dis);
		}
		tpre=tcur;
	}
	for(int i=1;i<=n;i++) ans=max(ans,sum-dp[i]);
	printf("%lld\n",ans);
    return 0;
}