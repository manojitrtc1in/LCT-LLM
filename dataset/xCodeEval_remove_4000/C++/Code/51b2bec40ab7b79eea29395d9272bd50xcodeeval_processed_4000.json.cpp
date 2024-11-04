

using namespace std;
typedef int ALL_OF_YOU_ARE_HANZHONGBALLS;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;









using namespace std;

int tot=0,dpx,hd[maxn],t[maxn<<1],nxt[maxn<<1],dep[maxn],sz[maxn],wson[maxn],\
bot[maxn],top[maxn],fa[maxn];
inline void add(int u,int v){
	t[++tot]=v;
	nxt[tot]=hd[u];
	hd[u]=tot;
}
inline void dfs1(int u){
	int v;
	sz[u]=1;
	for(int i=hd[u];i;i=nxt[i]){
		v=t[i];
		if(v==fa[u]) continue;
		dep[v]=dep[u]+1;
		fa[v]=u;
		dfs1(v);
		sz[u]+=sz[v];
		if(sz[wson[u]]<sz[v]) wson[u]=v;
	}
}
inline void dfs2(int u,int ch_tp){
	int v;
	top[u]=ch_tp;
	bot[ch_tp]=u;
	if(wson[u]) dfs2(wson[u],ch_tp);
	for(int i=hd[u];i;i=nxt[i]){
		v=t[i];
		if(v==fa[u]||v==wson[u]) continue;
		dfs2(v,v);
	}
}
int main(){
	int n,u,v,dpv;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	}
	puts("d 1");
	FF;
	scanf("%d",&dpx);
	dfs1(1);
	dfs2(1,1);
	u=1;
	while(dep[u]!=dpx){
		printf("d %d\n",bot[u]);
		FF;
		scanf("%d",&dpv);
		dpv=((dpx+dep[bot[u]]-dpv)>>1);
		while(dep[u]!=dpv) u=wson[u];
		if(dep[u]==dpx) break;
		printf("s %d\n",u);
		FF;
		scanf("%d",&u);
	}
	printf("! %d\n",u);
    return 0;
}