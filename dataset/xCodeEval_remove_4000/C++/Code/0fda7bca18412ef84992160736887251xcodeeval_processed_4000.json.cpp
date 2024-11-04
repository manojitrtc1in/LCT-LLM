
















































































using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=2e5+5;
const LL mod=1e9+7;
LL qp(LL x,LL p){
	LL ans=1;
	while (p){
		if (p&1) ans=ans*x%mod;
		x=x*x%mod;
		p>>=1;
	}
	return ans;
}
LL inv(LL x){
	return qp(x,mod-2);
}
LL dp[Maxn];
LL ans[Maxn];
int n;
vector<int> G[Maxn];
int p[Maxn];
void dfs(int x){
	dp[x]=1;
	for (int i=0;i<G[x].size();i++){
		dfs(G[x][i]);
		dp[x]=dp[x]*(dp[G[x][i]]+1)%mod;
	}
	

}
void dfs2(int x,LL pv){
	

	if (G[x].empty()) return;
	vector<LL> sum1,sum2;
	sum1.resize(G[x].size()+5);
	sum2.resize(G[x].size()+5);
	sum1[0]=dp[G[x][0]]+1;
	for (int i=1;i<G[x].size();i++){
		sum1[i]=sum1[i-1]*(dp[G[x][i]]+1)%mod;
	}
	sum2[G[x].size()]=1;
	sum2[G[x].size()-1]=dp[G[x][G[x].size()-1]]+1;
	for (int i=G[x].size()-2;i>=0;i--){
		sum2[i]=sum2[i+1]*(dp[G[x][i]]+1)%mod;
	}
	for (int i=0;i<G[x].size();i++){
		LL t=pv;
		if (i) t=t*sum1[i-1]%mod;
		if (i!=G[x].size()-1) t=t*sum2[i+1]%mod;
		ans[G[x][i]]=(t+1)*dp[G[x][i]]%mod;
	}
	for (int i=0;i<G[x].size();i++){
		LL t=pv;
		if (i) t=t*sum1[i-1]%mod;
		if (i!=G[x].size()-1) t=t*sum2[i+1]%mod;
		dfs2(G[x][i],t+1);
	}
}
int main(){
	scanf("%d",&n);
	for (int i=2;i<=n;i++){
		scanf("%d",&p[i]);
		G[p[i]].pb(i);
	}
	dfs(1);
	dfs2(1,1);
	ans[1]=dp[1];
	for (int i=1;i<=n;i++){
		printf("%I64d ",ans[i]);
	}
	printf("\n");
	return 0;
}