
#include <bits/stdc++.h>
using namespace std;
typedef int ALL_OF_YOU_ARE_HANZHONGBALLS;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef pair<ii,ii> iiii;
#define F first
#define S second
#define IN inline
#define RE register
#define random(x) (rand()%x)
#define N 100005
#define SQM 450
#define INF 0x3f3f3f3f
int n,m,fa[N],used[N],ib[N],ba[SQM][N];
inline int fnd(int x){return fa[x]==x?x:fa[x]=fnd(fa[x]);}
inline void jn(int u,int v){fa[fnd(u)]=fnd(v);}
vii adj[N];
vi tmp[N],app[N],bg;
vvi fl;
int main(){
	int u,v,w,q;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&u,&v,&w);
		adj[w].push_back(ii(u,v));
	}
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=m;++i){
		for(int j=0;j<adj[i].size();++j) jn(adj[i][j].F,adj[i][j].S);
		for(int j=0;j<adj[i].size();++j){
			u=adj[i][j].F;v=adj[i][j].S;
			if(!used[u]){tmp[fnd(u)].push_back(adj[i][j].F);used[u]=1;}
			if(!used[v]){tmp[fnd(v)].push_back(adj[i][j].S);used[v]=1;}
		}
		for(int j=0;j<adj[i].size();++j){
			u=fnd(adj[i][j].F);v=fnd(adj[i][j].S);
			if(!tmp[u].empty()){fl.push_back(tmp[u]);tmp[u].clear();}
			if(!tmp[v].empty()){fl.push_back(tmp[v]);tmp[v].clear();}
			u=adj[i][j].F;v=adj[i][j].S;
			fa[u]=u;fa[v]=v;
			used[u]=0;used[v]=0;
		}
	}
	
	for(int i=0;i<fl.size();++i) for(int j=0;j<fl[i].size();++j) app[fl[i][j]].push_back(i);
	for(int i=1;i<=n;++i) if(app[i].size()>=450){
		bg.push_back(i);
		ib[i]=bg.size();
	}
	for(int i=1;i<=bg.size();++i){
		u=bg[i-1];
		for(int j=0;j<app[u].size();++j){
			v=app[u][j];
			for(int k=0;k<fl[v].size();++k) ++ba[i][fl[v][k]];
		}
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&u,&v);
		if(!ib[u]) swap(u,v);
		if(ib[u]){
			printf("%d\n",ba[u][v]);
		}else{
			w=0;
			for(int c1=0,c2=0;c1<app[u].size()&&c2<app[v].size();){
				if(app[u][c1]==app[v][c2]){++w;++c1;++c2;}
				else if(app[u][c1]<app[v][c2]) ++c1;
				else ++c2;
			}
			printf("%d\n",w);
		}
	}
    return 0;
}