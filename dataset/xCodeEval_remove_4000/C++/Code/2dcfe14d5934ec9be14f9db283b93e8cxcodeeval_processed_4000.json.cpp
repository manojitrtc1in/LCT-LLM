

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<ll,ll> pll;






int n,tot=0,hd[N],t[N<<1],nxt[N<<1],wt[N<<1];
inline void add(int u,int v,int w){
	t[++tot]=v;
	nxt[tot]=hd[u];
	wt[tot]=w;
	hd[u]=tot;
}
inline ii dfs(int u,int fa,int sv){
	int v;
	ii ret=ii(sv,0),gt;
	for(int i=hd[u];i;i=nxt[i]){
		v=t[i];
		if(v==fa) continue;
		gt=dfs(v,u,wt[i]?sv+1:max(sv-1,0));
		ret.F=max(ret.F,gt.F);
		ret.S+=gt.S+wt[i];
	}
	return ret;
}
int main(){
	ii gt;
	int u,v,w,ans=INF;
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		add(u,v,0);
		add(v,u,1);
	}
	for(int i=1;i<=n;++i){
		gt=dfs(i,0,0);
		ans=min(ans,gt.S-gt.F);
	}
	printf("%d\n",ans);
    return 0;
}