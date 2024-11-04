#include<cmath>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define LL long long
#define ll   long long
#define ull unsigned long long
#define ULL ull
#define mp make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define PB pop_back
#define p push
#define P pop
#define INF 2147483647
#define ull unsigned long long
#define vi vector < int >
#define vpii vector < pii >
#define pq priority_queue
#define rep(i,n) for (int (i)=0;(i)<n;(i)++)
#define End return 0
#define mi multiset <int>
#define si set <int>
#define sll set<ll>
#define mll multiset<ll>
#define vll vector <ll>
#define Rep(i,a,b) for (int (i)=(a);(i)<=(b);(i)++)







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
const int Maxn=666;
int n,m,mod;
vector<int> G[Maxn],Gr[Maxn];
int deg[Maxn];
int topo[Maxn];
int dp[Maxn][Maxn];
LL mat[Maxn][Maxn];
int from[Maxn];
vector<int> src,snk;
int k;
void Swap(int x,int y){
	for (int i=1;i<=k;i++){
		swap(mat[x][i],mat[y][i]);
	}
}
LL qp(LL x,LL p){
	if (!p) return 1;
	if (p==1) return x;
	if(p&1){
		LL y=qp(x,p/2);
		return y*y%mod*x%mod;
	}
	else{
		LL y=qp(x,p/2);
		return y*y%mod;
	}
}
int inv(int x){
	return (int)qp((LL)x,(LL)mod-2);
}
int main(){
	scanf("%d %d %d",&n,&m,&mod);
	for (int i=0;i<m;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		deg[v]++;
		G[u].pb(v);
		Gr[v].pb(u);
	}
	vector<int> vv;
	for (int i=1;i<=n;i++){
		if (!deg[i]) vv.pb(i);
		if (G[i].empty()) snk.pb(i);
	}
	src=vv;
	k=vv.size();
	int cnt=0;
	while (!vv.empty()){
		int x=vv.back();
		vv.pop_back();
		topo[++cnt]=x;
		from[x]=cnt;
		for (int i=0;i<G[x].size();i++){
			deg[G[x][i]]--;
			if (!deg[G[x][i]]) vv.push_back(G[x][i]);
		}
	}
	

	for (int i=1;i<=n;i++){
		dp[i][i]=1;
		for (int j=i+1;j<=n;j++){
			for (int kk=0;kk<Gr[topo[j]].size();kk++){
				if (from[Gr[topo[j]][kk]]>=i){
					dp[i][j]+=dp[i][from[Gr[topo[j]][kk]]];
					dp[i][j]%=mod;
				}
			}
		}
	}
	

	for (int i=1;i<=k;i++){
		for (int j=1;j<=k;j++){
			mat[i][j]=dp[from[src[i-1]]][from[snk[j-1]]];
			

		}
		

	}
	LL mul=1;
	int now=1;
	for (int i=1;i<=k;i++){
		int id=-1;
		for (int j=now;j<=k;j++){
			if (mat[j][i]!=0){
				id=j;
				break;
			}
		}
		if(id!=-1){
			if (id!=now)Swap(id,now),mul*=-1;
			int tmp=inv(mat[now][i]);
			mul*=mat[now][i];
			mul%=mod;
			for (int j=1;j<=k;j++){
				mat[now][j]=((LL)mat[now][j]*tmp%mod);
				

			}
			

			for (int j=now+1;j<=k;j++){
				if (mat[j][i]!=0){
					

					int tt=mat[j][i];
					for (int kk=1;kk<=k;kk++){
						mat[j][kk]-=(1ll*tt*mat[now][kk]%mod);
					

						if (mat[j][kk]<0) mat[j][kk]+=mod;
					}
					

				}
			}now++;
		}
	}
	LL ans=1;
	for (int i=1;i<=k;i++) ans*=(LL)mat[i][i],ans%=mod;
	ans*=mul;
	if (ans<0) ans+=mod;
	printf("%I64d\n",ans);
	return 0;
}