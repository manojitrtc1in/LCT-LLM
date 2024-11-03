






















































































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
const int Maxn=100005;
vector<int> ans[Maxn];
vector<int> ev,od;
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	

	

	if (n==1 && m==1){
		printf("YES\n");
		printf("1\n");
		return 0;
	}
	if (n==3 && m==3){
		printf("YES\n");
		printf("1 3 4\n");
		printf("5 7 6\n");
		printf("9 2 8\n");
		return 0;
	}
	if (n<=3 && m<=3){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	if (m>3){
		for (int i=1;i<=m;i++){
			if (i<=m/2){
				od.push_back(2*i);
			}
			else{
				od.push_back(2*(i-(m/2))-1);
			}
		}
		ev=od;
		reverse(ev.begin(),ev.end());
		if (m&1){
			reverse(ev.begin(),ev.begin()+((m+1)/2));
			reverse(ev.begin()+(m+1)/2,ev.end());
		}
		

		

		

		

		for (int i=1;i<=n;i++){
			ans[i].pb(-1);
			for (int j=1;j<=m;j++){
				if (i&1){
					ans[i].pb((i-1)*m+od[j-1]);
				}
				else{
					ans[i].pb((i-1)*m+ev[j-1]);
				}
			}
		}
	}
	else{
		

		for (int i=1;i<=n;i++){
			if (i<=n/2){
				od.push_back(2*i);
			}
			else{
				od.push_back(2*(i-(n/2))-1);
			}
		}
		ev=od;
		reverse(ev.begin(),ev.end());
		if (n&1){
			reverse(ev.begin(),ev.begin()+((n+1)/2));
			reverse(ev.begin()+(n+1)/2,ev.end());
		}
		for (int i=1;i<=n;i++){
			ans[i].pb(-1);
		}
		for (int i=1;i<=m;i++){
			for (int j=1;j<=n;j++){
				if (i&1){
					ans[j].pb((od[j-1]-1)*m+i);
				}
				else{
					ans[j].pb((ev[j-1]-1)*m+i);
				}
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
