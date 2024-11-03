






















































































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
const int Maxn=300005;
vector<pair<int,int> > G[Maxn],GG[Maxn],Gr[Maxn],tg[Maxn];
bool vis[Maxn];
vector<pair<pair<int,int>,int> > e;
set<pair<int,int> > use;
int num[Maxn];
void dfs(int x){
	vis[x]=true;
	for (int i=0;i<G[x].size();i++){
		pii tmp=mp(x,G[x][i].first);
		if (tmp.first>tmp.second) swap(tmp.first,tmp.second);
		if (use.find(tmp)==use.end()){
			use.insert(tmp);
			GG[x].push_back(G[x][i]);
			Gr[G[x][i].first].push_back(mp(x,G[x][i].second));
			if (!vis[G[x][i].first]) dfs(G[x][i].first);
		}
	}
}
int tim;
bool can[Maxn];
int id[Maxn];
vector<int> ord;
vector<int> com;
void dfs2(int x){
	vis[x]=true;
	num[x]=++tim;
	ord.push_back(x);
	for (int i=0;i<GG[x].size();i++){
		int v=GG[x][i].first;
		if (!vis[v]){
			dfs2(v);
		}
	}
}
void dfsr(int x){
	com.push_back(x);
	vis[x]=true;
	for (int i=0;i<Gr[x].size();i++){
		int v=Gr[x][i].first;
		if (!vis[v]){
			dfsr(v);
		}
	}
}
int s,t;
bool flag;
void dfst(int x,int d){
	vis[x]=true;
	d+=(int)can[x];
	if (x==id[t]){
		flag=(d>0);
		return;
	}
	for (int i=0;i<tg[x].size();i++){
		if(!vis[tg[x][i].first]){
			dfst(tg[x][i].first,d+tg[x][i].second);
		}
	}
}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int u,v,w;
		u=read();v=read();w=read();
		e.pb(mp(mp(u,v),w));
		G[u].pb(mp(v,w));
		G[v].pb(mp(u,w));
	}

	scanf("%d %d",&s,&t);
	dfs(s);
	memset(vis,false,sizeof(vis));
	dfs2(s);
	memset(vis,false,sizeof(vis));
	int cur=0;
	for (int i=0;i<ord.size();i++){
		if (!vis[ord[i]]){
			com.clear();
			dfsr(ord[i]);
			++cur;
			for (int j=0;j<com.size();j++){
				id[com[j]]=cur;
			}
		}
	}
	for (int i=0;i<e.size();i++){
		int u=e[i].first.first,v=e[i].first.second,w=e[i].second;
		if (id[u]==id[v]){
			if(w) can[id[u]]=true;
		}
		else{
			

			tg[id[u]].push_back(mp(id[v],w));
			tg[id[v]].push_back(mp(id[u],w));
		}
	}
	if (id[s]==id[t]){
		if (can[id[s]]){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
		return 0;
	}
	memset(vis,false,sizeof(vis));
	dfst(id[s],0);
	if (flag){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}
