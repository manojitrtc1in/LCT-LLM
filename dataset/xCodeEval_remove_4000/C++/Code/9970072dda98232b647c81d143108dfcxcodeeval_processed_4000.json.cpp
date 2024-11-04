

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;









using namespace std;



int n,tot=0,t[N],nxt[N],wt[N],hd[N],sz[N];
inline void add(int u,int v,int w){
	t[++tot]=v;
	wt[tot]=w;
	nxt[tot]=hd[u];
	hd[u]=tot;
}
inline void id1(int u,int fa){
	int v;
	sz[u]=1;
	for(int i=hd[u];i;i=nxt[i]){
		v=t[i];
		if(v==fa) continue;
		id1(v,u);
		sz[u]+=sz[v];
	}
}
inline int id0(int u,int fa){
	int v;
	for(int i=hd[u];i;i=nxt[i]){
		v=t[i];
		if(v==fa)continue;
		if(sz[v]>(n>>1)){
			return id0(v,u);
		}
	}
	return u;
}
inline pll dfsmin(int u,int fa){
	int v;
	pll gt,ret;
	ret.S=1;
	for(int i=hd[u];i;i=nxt[i]){
		v=t[i];
		if(v==fa) continue;
		gt=dfsmin(v,u);
		ret.F+=gt.F;
		if(gt.S){
			ret.F+=wt[i];
			ret.S^=1;
		}
	}
	

	return ret;
}
inline ll dfsmax(int u,int fa){
	int v;
	ll gt,ret=0;
	sz[u]=1;
	for(int i=hd[u];i;i=nxt[i]){
		v=t[i];
		if(v==fa) continue;
		gt=dfsmax(v,u);
		sz[u]+=sz[v];
		ret+=gt+1ll*sz[v]*wt[i];
	}
	return ret;
}
int main(){
	int T,zx,u,v,w;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		n=n*2;
		tot=0;
		for(int i=1;i<=n;++i) hd[i]=0;
		for(int i=1;i<n;++i){
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
			add(v,u,w);
		}
		id1(1,0);
		zx=id0(1,0);
		

		printf("%lld %lld\n",dfsmin(zx,0).F,dfsmax(zx,0));
	}
    return 0;
}
