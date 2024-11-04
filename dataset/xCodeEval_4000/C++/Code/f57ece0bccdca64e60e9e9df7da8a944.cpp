
#include<bits/stdc++.h>
#define LL long long
#define ull unsigned long long
#define ULL ull
#define mp make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define big 20160116
#define INF 2147483647
#define pq priority_queue
#define rank rk124232
#define y1 y20160116
#define y0 y20160110
#define _ 0
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
namespace Mymath{
	LL qp(LL x,LL p,LL mod){
		LL ans=1;
		while (p){
			if (p&1) ans=ans*x%mod;
			x=x*x%mod;
			p>>=1;
		}
		return ans;
	}
	LL inv(LL x,LL mod){
		return qp(x,mod-2,mod);
	}
	LL C(LL N,LL K,LL fact[],LL mod){
		return fact[N]*inv(fact[K],mod)%mod*inv(fact[N-K],mod)%mod;
	}
	template <typename Tp> Tp gcd(Tp A,Tp B){
		if (B==0) return A;
		return gcd(B,A%B);
	}
	template <typename Tp> Tp lcm(Tp A,Tp B){
		return A*B/gcd(A,B);
	}
};
namespace fwt{
	using namespace Mymath;
	void FWT(int a[],int n,LL mod)
	{
	    for(int d=1;d<n;d<<=1)
	        for(int m=d<<1,i=0;i<n;i+=m)
	            for(int j=0;j<d;j++)
	            {
	                int x=a[i+j],y=a[i+j+d];
	                a[i+j]=(x+y)%mod,a[i+j+d]=(x-y+mod)%mod;
	                

	                

	                

	            }
	}

	void UFWT(int a[],int n,LL mod)
	{
		LL rev=inv(2,mod);
	    for(int d=1;d<n;d<<=1)
	        for(int m=d<<1,i=0;i<n;i+=m)
	            for(int j=0;j<d;j++)
	            {
	                int x=a[i+j],y=a[i+j+d];
	                a[i+j]=1LL*(x+y)*rev%mod,a[i+j+d]=(1LL*(x-y)*rev%mod+mod)%mod;
	                

	                

	                

	            }
	}
	void solve(int a[],int b[],int n,LL mod)
	{
	    FWT(a,n,mod);
	    FWT(b,n,mod);
	    for(int i=0;i<n;i++) a[i]=1LL*a[i]*b[i]%mod;
	    UFWT(a,n,mod);
	}
};
namespace Maxflow{
	const int Maxn=1005;
	struct edge{
		int to,rev,cap;
		edge(int _to,int _rev,int _cap){
			to=_to,rev=_rev,cap=_cap;
		}
	};
	int src=1002,snk=1003;
	vector<edge> G[Maxn];
	int dist[Maxn],seen[Maxn];
	int n;
	void Clear(){
		for (int i=0;i<Maxn;i++) G[i].clear();
	}
	void bfs(int s){
		for (int i=0;i<Maxn;i++) dist[i]=-1;
		dist[s]=0;
		queue<int> Q;
		Q.push(s);
		while (!Q.empty()){
			int x=Q.front();
			Q.pop();
			for (int i=0;i<G[x].size();i++){
				edge &e=G[x][i];
				if (e.cap && dist[e.to]==-1){
					dist[e.to]=dist[x]+1;
					Q.push(e.to);
				}
			}
		}
	}
	int dfs(int now,int dest,int fl){
		if (now==dest) return fl;
		for (int &i=seen[now];i<G[now].size();i++){
			edge &ed=G[now][i];
			if (ed.cap && dist[ed.to]==dist[now]+1){
				int f=dfs(ed.to,dest,min(fl,ed.cap));
				if (f){
					ed.cap-=f;
					G[ed.to][ed.rev].cap+=f;
					return f;
				}
			}
		}
		return 0;
	}
	int dinic(int s=src,int t=snk){
		int ret=0;
		while (1){
			memset(seen,0,sizeof(seen));
			bfs(s);
			if (dist[t]==-1) return ret;
			int f=dfs(s,t,INF);
			while(f){
				ret+=f;
				f=dfs(s,t,INF);
			}
		}
	}
};
namespace Geometry{
	struct iP{
		LL x,y;
		iP(LL _x,LL _y){
			x=_x,y=_y;
		}
		iP(){
			x=y=0;
		}
		iP operator +(iP p){
			return iP(x+p.x,y+p.y);
		}
		iP operator -(iP p){
			return iP(x-p.x,y-p.y);
		}
		iP operator *(LL k){
			return iP(x*k,y*k);
		}
		LL det(iP p){
			return x*p.y-y*p.x;
		}
		LL dot(iP p){
			return x*p.x+y*p.y;
		}
		LL dist(){
			return x*x+y*y;
		}
		bool operator <(const iP &p)const{
			if (x!=p.x) return x<p.x;
			return y<p.y;
		}
	};
	struct dP{
		double x,y;
		dP(double _x,double _y){
			x=_x,y=_y;
		}
		dP(){
			x=y=0.0;
		}
		dP operator +(dP p){
			return dP(x+p.x,y+p.y);
		}
		dP operator -(dP p){
			return dP(x-p.x,y-p.y);
		}
		dP operator *(double k){
			return dP(x*k,y*k);
		}
		double det(dP p){
			return x*p.y-y*p.x;
		}
		double dot(dP p){
			return x*p.x+y*p.y;
		}
		double dist(){
			return x*x+y*y;
		}
		bool operator <(const dP &p)const{
			if (x!=p.x) return x<p.x;
			return y<p.y;
		}
	};
	vector<iP> convex_hull(iP X[],int l){
		#define sz ret.size()
		vector<iP> ret;
		sort(X+1,X+1+l);
		ret.pb(X[1]);
		for (int i=2;i<=l;i++){
			while (sz>=2 && (ret[sz-2]-X[i]).det(ret[sz-1]-X[i])>=0){
				ret.pop_back();
			}
			ret.pb(X[i]);
		}
		int rs=ret.size()+1;
		for (int i=l-1;i>=1;i--){
			while (sz>=rs && (ret[sz-2]-X[i]).det(ret[sz-1]-X[i])>=0){
				ret.pop_back();
			}
			ret.pb(X[i]);
		}
		return ret;
	}
};
const int Maxn=2e5+5;
const int Maxm=5500005;
int n,q;
int a[Maxn];
bool isp[Maxm];
vector<int> P;
vector<int> p[Maxn];
void _init(){
	memset(isp,true,sizeof(isp));
	isp[0]=isp[1]=false;
	for (int i=2;i<Maxm;i++){
		if (isp[i]){
			P.pb(i);
			for (int j=i+i;j<Maxm;j+=i){
				isp[j]=false;
			}
		}
	}
}
LL Ha(vector<int> &V){
	LL ret=12384722;
	for (int i=0;i<V.size();i++){
		ret=ret*94333337+V[i];
	}
	return ret;
}
vector<LL> H[Maxn];
struct node{
	vector<pair<int,int> > st; 

	LL hh; 

	node* nxt;
	node(LL _hh){
		hh=_hh;
		nxt=NULL;
		st.clear();
	}
};
const int ss=5000000;
node* Mp[ss];
void Add(LL HH,int Siz,int Pos){
	LL pp=HH%(LL)ss;
	if (pp<0) pp+=ss;
	

	if (Mp[pp]==NULL){
		Mp[pp]=new node(HH);
		Mp[pp]->st.pb(mp(Siz,Pos));
		return;
	}
	node* tmp=Mp[pp];
	bool Find=false;
	while (tmp){
		if (tmp->hh==HH){
			Find=true;
			break;
		}
		if (tmp->nxt==NULL) break;
		tmp=tmp->nxt;
	}
	if (Find){
		while (!tmp->st.empty() && tmp->st.back().first>=Siz){
			tmp->st.pop_back();
		}
		tmp->st.pb(mp(Siz,Pos));
		return;
	}
	tmp->nxt=new node(HH);
	tmp->nxt->st.pb(mp(Siz,Pos));
}
vector<pair<int,int> > Get(LL HH){
	LL pp=HH%ss;
	if (pp<0) pp+=ss;
	vector<pair<int,int> > ept;
	if (!Mp[pp]) return ept;
	node* tmp=Mp[pp];
	while (tmp){
		if (tmp->hh==HH) return tmp->st;
		if (tmp->nxt==NULL) return ept;
		tmp=tmp->nxt;
	}
	return ept;
}
void Ckm(int &x,int y){
	if (y<x) x=y;
}
int imp[Maxn][19];
vector<pair<int,int> > Q[Maxn];
int ans[2000000];
int tree[Maxn*4],tag[Maxn*4];
void Push(int p){
	tag[p*2]=min(tag[p*2],tag[p]);
	tag[p*2+1]=min(tag[p*2+1],tag[p]);
	tree[p*2]=min(tree[p*2],tag[p]);
	tree[p*2+1]=min(tree[p*2+1],tag[p]);
	tag[p]=1e9;
}
void modify(int p,int l,int r,int lo,int hi,int val){
	if (lo>hi) return;
	if (hi>r) hi=r;
	if (lo<=l && r<=hi){
		

		tag[p]=min(tag[p],val);
		tree[p]=min(tree[p],val);
		return;
	}
	

	Push(p);
	int mid=l+r>>1;
	if (lo<=mid){
		modify(p*2,l,mid,lo,min(hi,mid),val);
	}
	if (hi>mid){
		modify(p*2+1,mid+1,r,max(lo,mid+1),hi,val);
	}
	tree[p]=min(tree[p*2],tree[p*2+1]);
}
int query(int p,int l,int r,int lo,int hi){
	if (lo>hi) return 1e9;
	if (lo<=l && r<=hi){
		return tree[p];
	}
	Push(p);
	int mid=l+r>>1;
	int ans=1e9;
	if (lo<=mid){
		ans=min(ans,query(p*2,l,mid,lo,min(hi,mid)));
	}
	if (hi>mid){
		ans=min(ans,query(p*2+1,mid+1,r,max(lo,mid+1),hi));
	}
	tree[p]=min(tree[p*2],tree[p*2+1]);
	return ans;
}
int main(){
	

	

	_init();


	n=read();q=read();
	for (int i=1;i<=n;i++){
		a[i]=read();
		int tmp=a[i];
		for (int j=0;j<P.size();j++){
			if (P[j]*P[j]>tmp) break;
			int f=0;
			while (tmp%P[j]==0){
				tmp/=P[j];f^=1;
			}
			if (f) p[i].pb(P[j]);
		}
		if (tmp!=1) p[i].pb(tmp);
		int s=p[i].size();
		

		vector<int> T;
		for (int j=0;j<(1<<s);j++){
			T.clear();
			for (int k=0;k<s;k++){
				if (j>>k&1) T.pb(p[i][k]);
			}
			H[i].pb(Ha(T));
		}
	}
	

	for (int i=n;i>=1;i--){
		

		

		int s=p[i].size();
		vector<int> T;
		for (int j=0;j<16;j++) imp[i][j]=1e9;
		

		
		for (int j=0;j<(1<<s);j++){
			
			int vv=__builtin_popcount(j);
			vector<pair<int,int> > GG=Get(H[i][j]);
			
			

			for (int k=0;k<GG.size();k++){
				Ckm(imp[i][s-vv*2+GG[k].first],GG[k].second);
			}
		}
		

		for (int j=0;j<H[i].size();j++){
			

			Add(H[i][j],s,i);
		}
		for (int j=1;j<16;j++){
			imp[i][j]=min(imp[i][j],imp[i][j-1]);
		}
	}
	

	for (int i=0;i<q;i++){
		int l,r;
		l=read();r=read();
		Q[l].pb(mp(r,i));
	}
	for (int i=0;i<4*Maxn;i++){
		tag[i]=1e9;
		tree[i]=1e9;
	}
	

	for (int i=n;i>=1;i--){
		if (i!=n){
			int lst=i+1;
			for (int j=14;j>=0;j--){
				if (imp[i][j]==imp[i][j+1]) continue;
				modify(1,1,n,lst,imp[i][j]-1,j+1);
				lst=imp[i][j];
			}
			modify(1,1,n,lst,n,0);
		}
		for (int j=0;j<Q[i].size();j++){
			int id=Q[i][j].second,r=Q[i][j].first;
			ans[id]=query(1,1,n,i+1,r);
		}
		
	}
	for (int i=0;i<q;i++){
		printf("%d\n",ans[i]);
	}
	return ~~(0^_^0);
}



