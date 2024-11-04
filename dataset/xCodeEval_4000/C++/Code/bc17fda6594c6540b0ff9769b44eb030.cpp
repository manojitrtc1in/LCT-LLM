
#include <bits/stdc++.h>
using namespace std;
typedef int ALL_OF_YOU_ARE_HANZHONGBALLS;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef pair<ii,ii> iiii;
#define F first
#define S second
#define IN inline
#define RE register
#define random(x) (rand()%x)
#define N 205
#define M 26817
#define INF 0x3f3f3f3f
int n,ans=0,a[N],dis[N],cur[N],vis[N];
vi res[N];
struct EDGE{
	int tot,t[M],nxt[M],wt[M],hd[N];
	EDGE(){tot=1;}
	inline void add(int u,int v,int w){
		t[++tot]=v;
		wt[tot]=w;
		nxt[tot]=hd[u];
		hd[u]=tot;
	}
}e,bi;
inline bool isP(int x){
	for(int i=2;i*i<=x;++i) if(x%i==0) return 0;
	return 1;
}
inline bool bfs(){
	int u,v;
	queue<int> q;
	memset(dis,63,sizeof(dis));
	dis[0]=0;
	q.push(0);
	while(!q.empty()){
		u=q.front();
		

		q.pop();
		for(int i=e.hd[u];i;i=e.nxt[i]){
			v=e.t[i];
			if(e.wt[i]&&dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	return dis[n+1]!=INF;
}
inline int dfs(int u,int lw){
	if(u==n+1) return lw;
	int v,gt,ret=0;
	for(int &i=cur[u];i;i=e.nxt[i]){
		v=e.t[i];
		if(e.wt[i]&&dis[v]==dis[u]+1){
			if(gt=dfs(v,min(lw,e.wt[i]))){
				ret+=gt;
				lw-=gt;
				e.wt[i]-=gt;
				e.wt[i^1]+=gt;
				if(!lw) break;
			}
		}
	}
	if(!ret)dis[u]=INF;
	return ret;
}
inline int Dinic(){
	int mxf=0;
	while(bfs()){
		for(int i=0;i<=n+1;++i) cur[i]=e.hd[i];
		mxf+=dfs(0,INF);
	}
	return mxf;
}
inline void dfs2(int u,int fa){
	if(vis[u]) return;
	int v;
	vis[u]=1;
	res[ans].push_back(u);
	for(int i=bi.hd[u];i;i=bi.nxt[i]){
		v=bi.t[i];
		if(v==fa) continue;
		dfs2(v,u);
	}
}
int main(){
	int mxf;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",a+i);
		if(a[i]&1){e.add(0,i,2);e.add(i,0,0);}
		else{e.add(i,n+1,2);e.add(n+1,i,0);}
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(isP(a[i]+a[j])){
				if(a[i]&1){e.add(i,j,1);e.add(j,i,0);}
				else{e.add(j,i,1);e.add(i,j,0);}
			}
		}
	}
	mxf=Dinic();
	

	if(mxf!=n){
		puts("Impossible");
		return 0;
	}
	for(int i=1;i<=n;++i){
		if(a[i]&1){
			for(int j=e.hd[i];j;j=e.nxt[j]){
				

				if(e.t[j]&&!e.wt[j]){
					bi.add(i,e.t[j],0);
					bi.add(e.t[j],i,0);
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			++ans;
			dfs2(i,0);
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;++i){
		printf("%d ",res[i].size());
		for(int j=0;j<res[i].size();++j){
			printf("%d ",res[i][j]);
		}
		putchar('\n');
	}
    return 0;
}