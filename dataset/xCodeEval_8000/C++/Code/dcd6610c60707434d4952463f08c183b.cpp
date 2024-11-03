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
const int Maxn=2097152;
const double pi=3.1415926535897;
struct cpl{
	double a,b;
	inline cpl(double x=0.0,double y=0.0){
		a=x;b=y;
	}
	inline cpl operator +(cpl &p){
		return cpl(a+p.a,b+p.b);
	}
	inline cpl operator -(cpl &p){
		return cpl(a-p.a,b-p.b);
	}
	inline cpl operator *(cpl &p){
		return cpl(a*p.a-b*p.b,a*p.b+b*p.a);
	}
	inline cpl operator =(cpl p){
		a=p.a,b=p.b;
		return *this;
	}
	inline cpl operator /(double x){
		return cpl(a/x,b/x);
	}
};
cpl A[Maxn],tmp[Maxn];
cpl C[Maxn],B[Maxn];
void FFT(cpl x[],int n,int fl=1){
	for (int i=0;i<n;i++){
		int d=0;
		for (int j=1;j<n;j<<=1){
			if (i&j){
				d+=((n/j)>>1);
			}
		}
		if (d<i) swap(x[i],x[d]);
	}
	for (int m=2;m<=n;m<<=1){
		cpl w(cos(-2.0*pi*fl/m),sin(-2.0*pi*fl/m));
		for (int i=0;i<n;i+=m){
			cpl cur(1,0);
			for (int j=i;j<i+(m>>1);j++){
				cpl u=x[j],v=x[j+(m>>1)]*cur;
				x[j]=u+v;x[j+(m>>1)]=u-v;
				cur=cur*w;
			}
		}
	}
}
const double eps=1e-5;
bool hav[Maxn];
vector<int> ans;
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++){
		int x;
		x=read();
		hav[x]=true;
	} 
	for (int i=1;i<=m;i++){
		if (hav[i]){
			for (int j=i+i;j<=m;j+=i){
				if (!hav[j]){
					

					printf("NO\n");
					return 0;
				}
			}
		}
	}
	A[0]=cpl(1,0);
	for (int i=1;i<=m;i++){
		if (hav[i]) A[i]=cpl(1,0);
	}
	int l=m+m+1+1;
	int ss=1;
	while (ss<l)ss*=2;
	

	FFT(A,ss,1);
	for (int i=0;i<ss;i++){
		A[i]=A[i]*A[i];
	}
	FFT(A,ss,-1);
	for (int i=0;i<ss;i++){
		A[i]=A[i]/ss;
	}
	for (int i=1;i<=m;i++){
		if (!hav[i]){
			if (abs(A[i].a)>eps){
				

				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	for (int i=1;i<=m;i++){
		if (hav[i]){
			

			if (abs(A[i].a-2.0)<eps){
				ans.pb(i);
			}
		}
	}
	printf("%d\n",ans.size());
	for (int i=0;i<ans.size();i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
} 