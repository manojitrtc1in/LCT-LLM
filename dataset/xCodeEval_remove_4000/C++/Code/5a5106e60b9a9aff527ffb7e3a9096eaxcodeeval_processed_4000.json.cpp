






















































































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
vector<pair<int,int> > G[Maxn];
int n;
LL M;
int siz[Maxn];
bool ban[Maxn];
void id0(long long a,long long b,long long &x,long long &y){
	if (b!=0){
		id0(b,a%b,y,x);
		y-=(a/b)*x;
	}
	else{
		x=1;
		y=0;
	}
}
long long inv(long long x,long long mod){
	LL t1,t2;
	id0(x,mod,t1,t2);
	t1%=mod;
	t1+=mod;
	t1%=mod;
	return t1;
}
void dfs(int x,int p){
	siz[x]=0;
	for (int i=0;i<G[x].size();i++){
		if (G[x][i].first!=p && !ban[G[x][i].first]){
			dfs(G[x][i].first,x);
			siz[x]+=siz[G[x][i].first];
		}
	}
	siz[x]++;
}
int nr;
int findc(int x,int p){
	int id1=0,id=-1;
	for (int i=0;i<G[x].size();i++){
		if (G[x][i].first!=p && !ban[G[x][i].first]){
			if (siz[G[x][i].first]>id1){
				id1=siz[G[x][i].first];
				id=G[x][i].first;
			}
		}
	}
	
	if (id1*2<=siz[nr]){
		return x;
	}
	return findc(id,x);
}
void dfs2(int x,int p,LL dep1,LL dep2,LL base,vector<LL> &tot1,vector<LL> &tot2,int sdep,vector<int> & d1,vector<int> &d2){
	tot1.pb(dep1);
	tot2.pb(dep2);
	d1.pb(sdep);
	d2.pb(sdep);
	for(int i=0;i<G[x].size();i++){
		if (G[x][i].first!=p && !ban[G[x][i].first]){
			dfs2(G[x][i].first,x,(dep1+1ll*G[x][i].second*base*10)%M,(dep2*10+1ll*G[x][i].second)%M,base*10%M,tot1,tot2,sdep+1,d1,d2);
		}
	}
}
long long ans;
long long p10[Maxn];
void solve(int root){
	dfs(root,-1);
	nr=root;
	int cent=findc(root,-1);
	ban[cent]=true;
	root=cent;
	vector<LL> now1,now2;
	vector<int> dep1,dep2;
	vector<pair<vector<LL>,vector<int> > > all1,all2;
	for (int i=0;i<G[root].size();i++){
		if (!ban[G[root][i].first]) solve(G[root][i].first);
		else continue;
		now1.clear();
		now2.clear();
		dep1.clear();
		dep2.clear();
		dfs2(G[root][i].first,root,G[root][i].second%M,G[root][i].second%M,1,now1,now2,1,dep1,dep2);
		all1.push_back(mp(now1,dep1));
		all2.push_back(mp(now2,dep2));
	}
	

	LL delta=0;
	map<LL,int> tmp;
	tmp[0]=1;
	for (int i=0;i<all2.size();i++){
		for (int j=0;j<all2[i].first.size();j++){
			LL k=all2[i].first[j];
			int base_k=all2[i].second[j];
			LL Mul=p10[base_k];
			k=M-k;
			k=k*inv(Mul,M)%M;
			delta+=tmp[k];
			

			

			

		}
		for (int j=0;j<all1[i].first.size();j++){
			tmp[all1[i].first[j]%M]++;
		

		}
	}
	

	tmp.clear();
	

	reverse(all1.begin(),all1.end());
	reverse(all2.begin(),all2.end());
	

	for (int i=0;i<all2.size();i++){
		for (int j=0;j<all2[i].first.size();j++){
			LL k=all2[i].first[j];
			int base_k=all2[i].second[j];
			LL Mul=p10[base_k];
			k=M-k;
			k=k*inv(Mul,M)%M;
			delta+=tmp[k];
			

			

			

		}
		for (int j=0;j<all1[i].first.size();j++){
			tmp[all1[i].first[j]%M]++;
		

		}
	}
	delta+=tmp[0];
	ban[cent]=false;
	

	ans+=delta;
}
int main(){
	scanf("%d %I64d",&n,&M);
	p10[0]=1;
	for (int i=1;i<Maxn;i++){
		p10[i]=p10[i-1]*10%M;
	}
	for (int i=0;i<n-1;i++){
		int u,v,c;
		u=read();v=read();c=read();u++;v++;
		G[u].pb(mp(v,c));
		G[v].pb(mp(u,c));
	}
	solve(1);
	printf("%I64d\n",ans);
}
