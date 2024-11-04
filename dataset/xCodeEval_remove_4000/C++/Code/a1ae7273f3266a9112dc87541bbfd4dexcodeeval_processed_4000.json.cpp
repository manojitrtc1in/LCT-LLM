


using namespace std;
const int mxn=5e5+5;
int n,q,root;
int val[mxn];
int bg[mxn],ed[mxn],top[mxn],sz[mxn],dep[mxn],dfsc;
int pa[mxn],ord[mxn],P[mxn][22],xo[mxn][22];
vector<int>g[mxn];
int par_val[mxn];
inline int dfs1(int x,int par=0,int deep=1){   

	dep[x]=deep;
	sz[x]=1;pa[x]=par;
	P[x][0]=par;
	for(int i=0;i<g[x].size();++i){
		int y=g[x][i];
		if(y==par)continue;
		sz[x]+=dfs1(y,x,deep+1);
	}
	return sz[x];
}
inline void dfs(int x,int tpf=root,int par=0){
	bg[x]=++dfsc;
	top[x]=tpf;
	ord[dfsc]=x;
	int mx=-1,pos;
	for(int i=0;i<g[x].size();++i){
		int y=g[x][i];
		if(y==par)continue;
		if(sz[y]>mx){
			mx=sz[y];
			pos=y;
		}
	}
	if(mx==-1){
		ed[x]=dfsc;
		return;
	}
	dfs(pos,tpf,x);
	for(int i=0;i<g[x].size();++i){
		int y=g[x][i];
		if(y==par or y==pos)continue;
		dfs(y,y,x);
	}
	ed[x]=dfsc;
}
struct segt{                         

	int sum[mxn<<3];
	int laz[mxn<<3];
	int siz[mxn<<3];
	inline void init(){
		memset(siz,0,sizeof(siz));
		memset(laz,0,sizeof(laz));
		memset(sum,0,sizeof(sum));
	}
	inline void pushup(int x){sum[x]=sum[x<<1]+sum[x<<1|1];}
	inline void pushdown(int x){
		if(laz[x]){
			sum[x]+=1ll*laz[x]*siz[x];
			laz[x<<1]+=laz[x];
			laz[x<<1|1]+=laz[x];
			laz[x]=0;
		}
	}
	inline void build(int x,int l,int r){
		siz[x]=r-l+1;
		if(l==r){
			sum[x]=val[ord[l]];
			return;
		}
		int md=l+r>>1;
		build(x<<1,l,md);
		build(x<<1|1,md+1,r);
		pushup(x);
	}
	inline void add(int x,int l,int r,int a,int b,int d){
		pushdown(x);
		if(a<=l and r<=b){
			laz[x]+=d;
			pushdown(x);
			return;
		}
		if(r<a or b<l)return;
		int md=l+r>>1;
		add(x<<1,l,md,a,b,d);
		add(x<<1|1,md+1,r,a,b,d);
		pushup(x);
	}
	inline int ask(int x,int l,int r,int a,int b){
		pushdown(x);
		if(a<=l and r<=b)return sum[x];
		if(r<a or b<l)return 0;
		int md=l+r>>1;
		return ask(x<<1,l,md,a,b)+ask(x<<1|1,md+1,r,a,b);
	}
}seg;
inline void updRange(int x,int y,int d){   

	for(;top[x]!=top[y];){
		if(dep[top[x]]>dep[top[y]])swap(x,y);
		seg.add(1,1,n,bg[top[y]],bg[y],d);
		y=top[y];
		y=pa[y];
	}
	if(dep[x]>dep[y])swap(x,y);
	seg.add(1,1,n,bg[x],bg[y],d);
}
inline int qryRange(int x,int y){       

	int ans=0;
	for(;top[x]!=top[y];){
		if(dep[top[x]]>dep[top[y]])swap(x,y);
		ans+=seg.ask(1,1,n,bg[top[y]],bg[y]);
		y=top[y];
		y=pa[y];
	}
	if(dep[x]>dep[y])swap(x,y);
	ans+=seg.ask(1,1,n,bg[x],bg[y]);
	return ans;
}
inline void addSub(int x,int d){     

	seg.add(1,1,n,bg[x],ed[x],d);
}
inline int qrySub(int x){return seg.ask(1,1,n,bg[x],ed[x]);}
struct dsu{                   

	int fa[mxn];
	inline void init(){for(int i=1;i<mxn;++i)fa[i]=i;}
	inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	inline int merge(int x,int y){
		x=find(x),y=find(y);
		if(x==y)return 0;
		fa[x]=y;
		return 1;
	}
}d;
int u[mxn],v[mxn],w[mxn];
int ans[mxn];
int roots[mxn];
inline void id2(int x,int P=0){          

	xo[x][0]=par_val[x];
	for(int i=0;i<g[x].size();++i){
		int y=g[x][i];
		if(y==P)continue;
		id2(y,x);
	}
}
inline void id0(){
	for(int j=1;j<=20;++j){
		for(int i=1;i<=n;++i){
			P[i][j]=P[P[i][j-1]][j-1];
			xo[i][j]=xo[i][j-1]^xo[P[i][j-1]][j-1];
		}
	}
}
inline int id1(int x,int y){
	int rt=0;
	if(dep[x]>dep[y])swap(x,y);
	for(int i=20;~i;--i)if(dep[P[y][i]]>=dep[x])rt^=xo[y][i],y=P[y][i];
	for(int i=20;~i;--i)if(P[x][i]!=P[y][i])rt^=xo[x][i],rt^=xo[y][i],x=P[x][i],y=P[y][i];
	if(x!=y){
		rt^=xo[x][0],rt^=xo[y][0];
		x=P[x][0],y=P[y][0];
	}
	return rt;
}
inline int lca(int x,int y){              

	if(dep[x]>dep[y])swap(x,y);
	for(int i=20;~i;--i)if(dep[P[y][i]]>=dep[x])y=P[y][i];
	for(int i=20;~i;--i)if(P[x][i]!=P[y][i])x=P[x][i],y=P[y][i];
	if(x!=y)x=P[x][0],y=P[y][0];
	return x;
}
inline void solve(){
	cin>>n>>q;
	d.init();
	for(int i=1;i<=q;++i){               

		cin>>u[i]>>v[i]>>w[i];
		ans[i]=d.merge(u[i],v[i]);
		if(ans[i])g[u[i]].push_back(v[i]),g[v[i]].push_back(u[i]);
	}
	for(int i=1;i<=n;++i)if(!top[i]){       

		roots[i]=1;
		dfs1(i);
		dfs(i,i);
	}
	for(int i=1;i<=q;++i){ 
		if(!ans[i])continue;
		if(u[i]==pa[v[i]])par_val[v[i]]=w[i];
		else par_val[u[i]]=w[i];
	}
	for(int i=1;i<=n;++i)
		if(roots[i])
			id2(i);
	id0();
	seg.build(1,1,n);
	for(int i=1;i<=q;++i){                

		if(ans[i]){ 
			if(u[i]==pa[v[i]])val[v[i]]=w[i];
			else val[u[i]]=w[i];
		}
	}
	for(int i=1;i<=q;++i){
		if(ans[i])continue;
		int X=id1(u[i],v[i])^w[i];
		if(X==0)continue;
		int LCA=lca(u[i],v[i]);




		int t=qryRange(u[i],v[i])-qryRange(LCA,LCA);   



		if(t!=0);
		else{
			ans[i]=1;
			updRange(u[i],v[i],1);    

			updRange(LCA,LCA,-1); 
		}
	}
	for(int i=1;i<=q;++i){
		if(ans[i])cout<<"YES\n";
		else cout<<"NO\n";
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;T=1;


	for(;T--;)solve();
	return 0;
}