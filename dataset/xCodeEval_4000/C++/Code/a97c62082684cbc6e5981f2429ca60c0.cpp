#include<bits/stdc++.h>
using namespace std;
#define rep(i,s,t) for(int i=(s);i<(t);++i)
#define per(i,s,t) for(int i=((t)-1);i>=(s);--i)
#define repb(i,s,t) for(int i=(s);i<=(t);++i)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)x.size())
#define mst(a,b) memset(a,b,sizeof(a))
#define mstc(a,b,c) memset(a,b,c*sizeof(a[0]))
#define dd(x) cout<<#x<<'='<<x<<' '
#define de(x) cout<<#x<<'='<<x<<'\n'
#define fi first
#define se second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

const int inf = 0x3f3f3f3f;
const int inf_ = 0x7fffffff;
const ll inff = 4557430888798830399ll;
const double pi = acos(-1.0);
ll mod = 1e9+7;






#define maxn 100005

map<int,int> id[maxn];

struct DCC{
	DCC(){init(0,0);}
	int n,t,h,m,dfn[maxn],low[maxn],s[maxn],e[maxn],g[maxn];
	vector<int>*N,cut,D[maxn],F[maxn];bool mark[maxn];
	void init(int _n,vector<int>* _N){
		n=_n;N=_N;t=h=-1;m=0;mst(dfn,0);mst(low,0);mst(mark,0);cut.clear();}
	void dfs(int u,int d,int p){
		int sec=0,son=d>1,e;dfn[u]=low[u]=d;s[++t]=u;
		for(auto v:N[u]){
			if(!mark[e=id[u][v]])g[++h]=e,mark[e]=1;
			if(!dfn[v]){
				dfs(v,d+1,u);low[u]=min(low[u],low[v]);
				if(low[v]>=dfn[u]){
					if(++son==2)cut.pb(u);
					m+=1;D[m].clear();D[m].pb(u);F[m].clear();
					do F[m].pb(g[h]);while(g[h--]!=e);
					do D[m].pb(s[t]);while(s[t--]!=v);}}
			else if(v!=p||sec++)low[u]=min(low[u],dfn[v]);}}
	void run(){
		repb(i,1,n)if(!dfn[i])dfs(i,1,0);
		gen();
	}
	void gen(){
		vector<int> z;
	

		repb(i,1,m)if(sz(F[i])==sz(D[i])&&sz(D[i])>2)
			for(auto e:F[i])z.pb(e);
		sort(all(z));z.erase(unique(all(z)),z.end());
		cout<<sz(z)<<endl;
		rep(i,0,sz(z))cout<<z[i]<<" \n"[i==sz(z)-1];}};


vector<int> N[maxn];
DCC t;

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,u,v;
	cin>>n>>m;
	repb(i,1,m)
	{
		cin>>u>>v;
		N[u].pb(v);N[v].pb(u);
		id[u][v]=id[v][u]=i;
	}
	t.init(n,N);t.run();
}