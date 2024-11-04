

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;






int n,dp[N][3][2];
struct Edge{
	int v,i,w;
	Edge(){}
	Edge(int V,int I,int W){v=V;i=I;w=W;}
};
vector<Edge> g[N];
inline int dfs(int u,int x,int f,int fa,int c){
	if(g[u].size()==c){
		if(!x&&!f) return INF;
		return 0;
	}
	if(g[u][c].v==fa) return dfs(u,x,f,fa,c+1);
	if(dp[g[u][c].i][x][f]!=-1) return dp[g[u][c].i][x][f];
	int &res=dp[g[u][c].i][x][f];
	res=INF;
	if(x) res=dfs(u,x-1,f,fa,c);
	for(int i=0;i<=x;++i){
		res=min(res,dfs(g[u][c].v,i,1,u,0)+dfs(u,x-i,f,fa,c+1)+g[u][c].w);
		res=min(res,dfs(g[u][c].v,i,0,u,0)+dfs(u,x-i,1,fa,c+1)+(g[u][c].w^1));
	}
	return res;
}
int main(){
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		g[u].push_back(Edge(v,i,0));
		g[v].push_back(Edge(u,i,1));
	}
	memset(dp,-1,sizeof(dp));
	printf("%d\n",dfs(1,2,0,0,0));
	return 0;
}