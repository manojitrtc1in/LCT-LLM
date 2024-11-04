
#include <bits/stdc++.h>
using namespace std;
typedef int ALL_OF_YOU_ARE_HANZHONGBALLS;
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
#define N 21
#define M 20005
#define mod 1000000007
#define INF 0x3f3f3f3f
int n,n2,m,dp[(1<<N)+5],a[N][N],cnt[26],sum[26],mx[26],b[N][N],c[N][N];
char s[N][N];
int main(){
	scanf("%d%d",&n,&m);
	n2=1<<n;
	for(int i=0;i<n;++i) scanf("%s",s[i]);
	for(int i=0;i<n;++i) for(int j=0;j<m;++j) scanf("%d",a[i]+j);
	for(int j=0;j<m;++j){
		memset(cnt,0,sizeof(cnt));
		memset(sum,0,sizeof(sum));
		memset(mx,0,sizeof(mx));
		for(int i=0;i<n;++i){
			cnt[s[i][j]-'a']|=(1<<i);
			sum[s[i][j]-'a']+=a[i][j];
			mx[s[i][j]-'a']=max(mx[s[i][j]-'a'],a[i][j]);
		}
		for(int i=0;i<n;++i){
			b[i][j]=sum[s[i][j]-'a']-mx[s[i][j]-'a'];
			c[i][j]=cnt[s[i][j]-'a'];
		}
	}
	memset(dp,63,sizeof(dp));
	dp[0]=0;
	int lw;
	for(int msk=0;msk<n2;++msk){
		for(lw=0;lw<n;++lw) if(!(msk&1<<lw)) break;
		for(int j=0;j<m;++j){
			dp[msk|c[lw][j]]=min(dp[msk|c[lw][j]],dp[msk]+b[lw][j]);
			dp[msk|1<<lw]=min(dp[msk|1<<lw],dp[msk]+a[lw][j]);
		}
	}
	printf("%d\n",dp[n2-1]);
	return 0;
}