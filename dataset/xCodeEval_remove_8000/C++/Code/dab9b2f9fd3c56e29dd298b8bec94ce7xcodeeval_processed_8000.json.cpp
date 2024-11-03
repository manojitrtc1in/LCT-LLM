






















































































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
const int Maxn=50005;
struct node{
	node* nxt[26],*par;
	int len,dp1[14],dp2;
	int use;
	node(int l){
		len=l;
		memset(nxt,0,sizeof(nxt));
		par=NULL;
		use=0;
		memset(dp1,-1,sizeof(dp1));
		dp2=-1;
	}
};
struct SAM{
	node* root;
	SAM(){
		root=new node(0);
	}
	node* add(node* last,int c){
		node* p=new node(last->len+1);
		node* tmp=last;
		while (tmp && !tmp->nxt[c]){
			tmp->nxt[c]=p;
			tmp=tmp->par;
		}
		if (!tmp){
			p->par=root;
			return p;
		}
		node* q=tmp->nxt[c];
		if (q->len==tmp->len+1){
			p->par=q;
			return p;
		}
		node* nq=new node(tmp->len+1);
		for (int i=0;i<26;i++){
			nq->nxt[i]=q->nxt[i];
		}
		nq->par=q->par;
		q->par=nq;
		p->par=nq;
		while (tmp && tmp->nxt[c]==q){
			tmp->nxt[c]=nq;
			tmp=tmp->par;
		}
		return p;
	}
	void build(vector<string> v){
		for (int i=0;i<v.size();i++){
			node* tmp=root;
			for (int j=0;j<v[i].size();j++){
				tmp=add(tmp,v[i][j]-'a');
			}
		}
	}
};
char ch[Maxn];
SAM sam;
vector<string> tt;
int n;
int lb[15],rb[15];
void dfs1(node* x){
	if (x->dp1[0]!=-1) return ;
	for (int i=0;i<=n;i++){
		if (x->use & (1<<i)){
			x->dp1[i]=1;
		}
		else x->dp1[i]=0;
	}
	

	for (int i=0;i<26;i++){
		if (x->nxt[i]){
			dfs1(x->nxt[i]);
			for(int j=0;j<=n;j++) x->dp1[j]+=x->nxt[i]->dp1[j];
		}
	}
}
void dfs2(node* x){
	if (x->dp2!=-1) return;
	bool flag=true;
	for (int i=0;i<=n;i++){
		if (x->dp1[i]<lb[i] || x->dp1[i]>rb[i]) flag=false;
	}
	if (x==sam.root) flag=false;
	if (flag)x->dp2=1; else x->dp2=0;
	for (int i=0;i<26;i++){
		if (x->nxt[i]){
			dfs2(x->nxt[i]);
			x->dp2+=x->nxt[i]->dp2;
		}
	}
}
int main(){
	scanf("%s",ch);
	string dd=(string)ch;
	tt.pb(dd);

	scanf("%d",&n);
	lb[0]=1;rb[0]=1e9;
	for (int i=1;i<=n;i++){
		scanf("%s",ch);
		dd=(string)ch;
		tt.pb(dd);
		scanf("%d %d",&lb[i],&rb[i]);
	}

	sam.build(tt);
	

	for (int i=0;i<=n;i++){
		node* now=sam.root;
		for (int j=0;j<tt[i].size();j++){
			assert(now);

			now=now->nxt[tt[i][j]-'a'];
		}
		assert(now);
		

		while (now){
			

			now->use|=(1<<i);
			now=now->par;
		}
	

	}


	dfs1(sam.root);


	dfs2(sam.root);
	printf("%d\n",sam.root->dp2);
	return 0;
}