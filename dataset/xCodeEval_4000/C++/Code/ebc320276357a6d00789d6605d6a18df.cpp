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
#include<tr1\unordered_map>
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
using namespace tr1;
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
const int Maxn=50005;
map<pair<LL,LL>,int> use[12];
int cur;
struct node{
	node* nxt[26],*par[20];
	int len,siz,id;
	node(int L,int S=0){
		len=L;
		id=++cur;
		memset(nxt,0,sizeof(nxt));
		memset(par,0,sizeof(par));
		siz=S;
	}
};
node* ref[Maxn*40];
vector<int> G[Maxn*40];
bool vis[Maxn*40];
struct SAM{
	vector<int> nodes;
	node* root,*last;
	SAM(){
		root=last=new node(0);
		ref[root->id]=root;
		nodes.clear();
		nodes.pb(root->id);
	}
	void add(int c){
		node* p=new node(last->len+1,1);
		nodes.pb(p->id);
		ref[p->id]=p;
		node* tmp=last;
		while (tmp && !tmp->nxt[c]){
			tmp->nxt[c]=p;
			tmp=tmp->par[0];
		}
		if (!tmp){
			p->par[0]=root;
		}
		else{
			node* q=tmp->nxt[c];
			if (q->len==tmp->len+1){
				p->par[0]=q;
			}
			else{
				node* nq=new node(tmp->len+1);
				nodes.pb(nq->id);
				ref[nq->id]=nq;
				for (int i=0;i<26;i++){
					nq->nxt[i]=q->nxt[i];
				}
				nq->par[0]=q->par[0];
				q->par[0]=nq;
				p->par[0]=nq;
				while(tmp &&tmp->nxt[c]==q){
					tmp->nxt[c]=nq;
				}
			}
		}
		last=p;
	}
	void dfs1(int x){
		

		vis[x]=true;
		if (ref[x]->par[0]){
			G[ref[x]->par[0]->id].pb(ref[x]->id);
		}
		for (int i=0;i<26;i++){
			if (ref[x]->nxt[i] && !vis[ref[x]->nxt[i]->id]){
				dfs1(ref[x]->nxt[i]->id);
			}
		}
	}
	void dfs2(int x){
		for(int i=0;i<G[x].size();i++){
			dfs2(G[x][i]);
			ref[x]->siz+=ref[G[x][i]]->siz;
		}
	}
	void build_lca(){
		for (int i=1;i<20;i++){
			for (int j=0;j<nodes.size();j++){
				node* now=ref[nodes[j]];
				if (now->par[i-1]){
					now->par[i]=now->par[i-1]->par[i-1];
				}
			}
		}
	}
	void build1(string s){
		for (int i=0;i<s.size();i++){
			add(s[i]-'a');
		}
		
		dfs1(root->id);
		dfs2(root->id);
		build_lca();
	}
};
char ch[Maxn];
SAM sam[15];
int ub[Maxn],lb[Maxn];
set<string> ss;
const long long mul=20160116;
const LL mul2=20160110;
const long long mod=1e9+9;
const LL mod2=1e9+7;
int main(){
	scanf("%s",ch);
	string t=(string)ch;
	for (int i=0;i<t.size();i++){
		LL nh=0,nh2=0;
		for (int j=i;j<t.size();j++){
			nh=nh*mul+t[j];
			nh2=nh2*mul2+t[j];
			nh%=mod;nh2%=mod2;
			use[0][mp(nh,nh2)]++;
		}
	}
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%s",ch);
		string tt=(string)ch;
		for (int j=0;j<tt.size();j++){
			LL nh=0,nh2=0;
			for (int k=j;k<tt.size();k++){
				nh=nh*mul+tt[k];
				nh2=nh2*mul2+tt[k];
				nh%=mod;nh2%=mod2;
				use[i+1][mp(nh,nh2)]++;
			}
		}
		scanf("%d %d",&lb[i+1],&ub[i+1]);
		
	}
	int ans=0;
	for (map<pair<LL,LL>,int>::iterator it=use[0].begin();it!=use[0].end();it++){
		pair<LL,LL> v=it->first;
		bool flag=true;
		for (int i=1;i<=n;i++){
			int tm;
			if (use[i].count(v)) tm=use[i][v]; else tm=0;
			if (lb[i]>tm || ub[i]<tm) flag=false;
		}
		if (flag) ans++;
	}
	printf("%d\n",ans);
	
	
}
