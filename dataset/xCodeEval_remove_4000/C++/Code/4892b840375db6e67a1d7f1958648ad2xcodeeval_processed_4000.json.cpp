






















































































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
const int Maxn=200005;
char c[Maxn];
set<int> pos[66];
int de(char x){
	if (x>='A' && x<='Z'){
		return x-'A';
	}
	if (x>='a' && x<='z') return x-'a'+26;
	return x-'0'+52;
}
int tree[Maxn*4];
void build(int p,int l,int r){
	if (l==r){
		tree[p]=1;return;
	}
	int mid=l+r>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	tree[p]=tree[p*2]+tree[p*2+1];
}
void modify(int p,int l,int r,int pos){
	if (l==r){
		tree[p]=0;
		return;
	}
	int mid=l+r>>1;
	if (pos<=mid){
		modify(p*2,l,mid,pos);
	}
	else{
		modify(p*2+1,mid+1,r,pos);
	}
	tree[p]=tree[p*2]+tree[p*2+1];
}
int query(int p,int l,int r,int lo,int hi){
	if (lo<=l && r<=hi){
		return tree[p];
	}
	int mid=l+r>>1;
	int ans=0;
	if (lo<=mid){
		ans+=query(p*2,l,mid,lo,min(hi,mid));
	}
	if (hi>mid){
		ans+=query(p*2+1,mid+1,r,max(lo,mid+1),hi);
	}
	return ans;
}
int findk(int p,int l,int r,int k){
	if (l==r){
		return l;
	}
	int mid=l+r>>1;
	if (tree[p*2]>=k){
		return findk(p*2,l,mid,k);
	}
	else{
		return findk(p*2+1,mid+1,r,k-tree[p*2]);
	}
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	scanf("%s",c);
	for(int i=0;i<n;i++){
		pos[de(c[i])].insert(i+1);
	}
	build(1,1,n);
	for (int i=0;i<m;i++){
		int lo,hi;
		char tmp;
		scanf("%d %d %c",&lo,&hi,&tmp);
		int id=de(tmp);
		int st=findk(1,1,n,lo);
		

		set<int>::iterator it=pos[id].lower_bound(st);
		vector<int> ss;
		for (;it!=pos[id].end();it++){
			int val=*it;
			

			if (query(1,1,n,1,val)<=hi){
				ss.pb(val);
			}
			else{
				break;
			}
		}
		for (int j=0;j<ss.size();j++){
			modify(1,1,n,ss[j]);
			pos[id].erase(ss[j]);
		}
	}
	string ans;
	for (int i=1;i<=n;i++){
		if (query(1,1,n,i,i)==1){
			ans+=c[i-1];
		}
	}
	printf("%s\n",ans.c_str());
	return 0;
}
