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
const int Maxn=200005;
int n,g,r;
int l[Maxn];
LL sum[Maxn];
int t[Maxn];
long long ans[Maxn];
int firsp[Maxn];
int ficost[Maxn];
LL cost[Maxn];
set<pair<int,int> > qu;
int main(){
	scanf("%d %d %d",&n,&g,&r);
	int dur=g+r;
	for (int i=1;i<=n+1;i++){
		scanf("%d",&l[i]);
		sum[i]=sum[i-1]+l[i];
	}
	for (int i=0;i<Maxn;i++) firsp[i]=-1;
	int q;
	scanf("%d",&q);
	for (int i=1;i<=q;i++){
		scanf("%d",&t[i]);
		ans[i]=sum[n+1]+t[i];
		qu.insert(mp(t[i]%dur,i));
	}
	for (int i=1;i<=n;i++){
		

		
		int now=sum[i]%dur;
		

		

		pii tmp=mp(g-now,-1);
		set<pair<int,int> > ::iterator it=qu.lower_bound(tmp),it2;
		

		

		while (1){
			if (it==qu.end()) break;
			if (((*it).first+now)%dur<g) break;
			firsp[(*it).second]=i;
			ficost[(*it).second]=dur-(((*it).first+now)%dur);
			it2=it;
			
			it++;
			qu.erase(it2);
		}
		

		if (g-now<0){
			tmp=mp(g-now+dur,-1);
			it=qu.lower_bound(tmp);
			while (1){
				if (it==qu.end()) break;
				if (((*it).first+now)%dur<g) break;
				firsp[(*it).second]=i;
				ficost[(*it).second]=dur-(((*it).first+now)%dur);
				it2=it;
				
				it++;
				qu.erase(it2);
			}
		}

		qu.insert(mp(((-sum[i])%dur+dur)%dur,q+i));
	}
	

	for (int i=n;i>=1;i--){
		if (firsp[i+q]==-1){
			cost[i]=0;
		}
		else{
			cost[i]=ficost[i+q]+cost[firsp[i+q]];
		}
	}
	for (int i=1;i<=q;i++){
		ans[i]+=ficost[i];
		if (firsp[i]!=-1){
			ans[i]+=cost[firsp[i]];
		}
		printf("%I64d\n",ans[i]);
	}

	return 0;
}
