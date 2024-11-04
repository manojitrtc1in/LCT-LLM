






















































































using namespace std;
inline void cmax(int &a,int b){
	a=max(a,b);
}
inline void cmin(int &a,int b){
	a=min(a,b);
}
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
struct edge{
	int to,cap,rev;
	edge(int x,int y,int z){
		to=x,cap=y,rev=z;
	}
};
struct Max_flow{
	int Siz;
	int src,snk;
	vector<vector<edge> >G;
	vector<int> dist,seen;
	Max_flow(){
		Siz=0;
		src=-1;snk=-1;
		G.clear();
		dist.clear();seen.clear();
	}
	void Set(int x,int y){
		src=x,snk=y;
	}
	void resize(int s){
		Siz=s;
		G.resize(s+1);
		dist.resize(s+1);
		seen.resize(s+1);
	}
	void add_edge(int u,int v,int c){
		edge t1(v,c,G[v].size()),t2(u,0,G[u].size());
		G[u].push_back(t1);
		G[v].push_back(t2);
	}
	void bfs(int s){
		for (int i=0;i<dist.size();i++) dist[i]=-1;
		queue<int> Q;
		dist[s]=0;
		Q.push(s);
		while (!Q.empty()){
			int x=Q.front();
			Q.pop();
			for (int i=0;i<G[x].size();i++){
				int v=G[x][i].to;
				if (G[x][i].cap && dist[v]==-1){
					dist[v]=dist[x]+1;
					Q.push(v);
				}
			}
		}
	}
	int dfs(int x,int dest,int flow){
		if (x==dest) return flow;
		for (int &i=seen[x];i<G[x].size();i++){
			edge &e=G[x][i];
			if (e.cap && dist[e.to]==dist[x]+1){
				int ff=dfs(e.to,dest,min(flow,e.cap));
				if (ff){
					e.cap-=ff;
					G[e.to][e.rev].cap+=ff;
					return ff;
				}
			}
		}
		return 0;
	}
	int dinic(int u,int v){
		int ans=0;
		while (1){
			for (int i=0;i<seen.size();i++) seen[i]=0;
			bfs(u);
			if (dist[v]==-1) break;
			int f;
			while (f=dfs(u,v,INF)){
				ans+=f;
			}
		}
		return ans;
	}
	int Maxflow(){
		return dinic(src,snk);
	}
};
const int Maxn=188;
int D[Maxn];
int dp[Maxn][Maxn][2];
int pre[Maxn][Maxn];
int ppre[Maxn][Maxn];
int g[Maxn]; 

int id[Maxn];
int par[Maxn];
vector<int> G[Maxn],son[Maxn];
bool vis[Maxn];
int n,k;
void dfs(int x){
	vis[x]=true;
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if (!vis[v]){
			dfs(v);
			son[x].pb(v);
		}
	}
	dp[x][0][0]=k;
	dp[x][0][1]=k;
	for (int i=0;i<son[x].size();i++){
		int v=son[x][i];
		dp[x][0][0]+=min(g[v],dp[v][1][1]);
		dp[x][0][1]+=min(g[v],dp[v][1][1]);
		

		if (g[v]<dp[v][1][1]){
			ppre[v][1]=-1;
			
		}
	}
	for (int d=1;d<=n;d++){
		int tot=0;
		for (int i=0;i<son[x].size();i++){
			int v=son[x][i];
			tot+=min(g[v],dp[v][d+1][1]);
			if (g[v]<dp[v][d+1][1]){
				ppre[v][d+1]=-1;
			}
		}
		dp[x][d][0]=INF;
		for (int i=0;i<son[x].size();i++){
			int v=son[x][i];
			int curcost=dp[v][d-1][0]+tot-min(g[v],dp[v][d+1][1])+D[d];
			if (curcost<dp[x][d][0]){
				dp[x][d][0]=curcost;
				pre[x][d]=v;
			}
		}
		dp[x][d][1]=D[d];
		for (int i=0;i<son[x].size();i++){
			int v=son[x][i];
			dp[x][d][1]+=min(dp[v][d+1][1],g[v]);
		}
	}
	g[x]=INF;
	for (int i=0;i<=n;i++){
		if (dp[x][i][0]<g[x]){
			g[x]=dp[x][i][0];
			id[x]=i;
		}
	}
	

}
void _init(){
	for (int i=0;i<Maxn;i++){
		for (int j=0;j<Maxn;j++){
			dp[i][j][0]=dp[i][j][1]=INF;
		}
	}
}
int curpa;
void go(int x,int d,int tp,int pp){
	if (tp==0){
		if (d==0){
			for (int i=0;i<son[x].size();i++){
				int v=son[x][i];
				if (ppre[v][1]!=-1){
					go(v,1,1,x);
				}
				else{
					int tt=id[v];
					go(v,tt,0,-1);
				}
			}
		

			par[x]=x;
			curpa=x;
			
			return;
		}
		int idd=pre[x][d];
		go(idd,d-1,0,pp);
		pp=curpa;
		par[x]=pp;
	

		for (int i=0;i<son[x].size();i++){
			int v=son[x][i];
			if (v==idd) continue;
			if (ppre[v][d+1]!=-1){
				go(v,d+1,1,pp);
			}
			else{
				int tt=id[v];
				go(v,tt,0,-1);
			}
		}
		curpa=pp;
	}
	else{
		par[x]=pp;
		for (int i=0;i<son[x].size();i++){
			int v=son[x][i];
			if (ppre[v][d+1]!=-1){
				go(v,d+1,1,pp);
			}
			else{
				int tt=id[v];
				go(v,tt,0,-1);
			}
		}
	}
}
int main(){
	_init();
	scanf("%d %d",&n,&k);
	for (int i=1;i<=n-1;i++){
		scanf("%d",&D[i]);
	}
	for (int i=0;i<n-1;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1);
	printf("%d\n",g[1]);


	go(1,id[1],0,-1);
	for (int i=1;i<=n;i++){
		printf("%d ",par[i]);
	}
	printf("\n");
	return 0;
}