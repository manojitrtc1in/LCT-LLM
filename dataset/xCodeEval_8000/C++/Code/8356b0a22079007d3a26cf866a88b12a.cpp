
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
const int Maxn=9;
int x,k,n,q;
int tl;
struct mat{
	LL dist[77][77];
	mat(){
		for (int i=0;i<77;i++){
			for (int j=0;j<77;j++){
				dist[i][j]=1e18;
			}
		}
	}
};
int id[256];
mat T1;
int cc=0;
LL c[Maxn];
void _init(){
	for (int i=0;i<(1<<k);i++){
		int cnt=0;
		for (int j=0;j<k;++j){
			if (i>>j&1) cnt++;
		}
		if (cnt!=x) continue;
		

		id[i]=++cc;
	}
	for (int i=0;i<(1<<k);i++){
		int cnt=0;
		for (int j=0;j<k;++j){
			if (i>>j&1) cnt++;
		}
		if (cnt!=x) continue;
		

		int v=i>>1;
		int u=i&1;
		if (!u){
			T1.dist[id[i]][id[v]]=0;
			

		}
		else{
			for (int j=0;j<k;j++){
				if (v&(1<<j)) continue;
				T1.dist[id[i]][id[v^(1<<j)]]=c[j+1];
				

			}
		}
	}
}
int p[30],wp[30];
LL dp[77],dp2[77];
mat Build(int pos){
	mat ret=T1;
	for (int i=0;i<(1<<k);i++){
		if (!id[i]) continue;
		for (int j=1;j<=q;j++){
			if (p[j]<=pos && pos-p[j]<k){
				int pp=pos-p[j];
				pp=k-1-pp;
				if (i>>(pp+1)&1) continue;
			

				for (int l=0;l<(1<<k);l++){
					if (!id[l]) continue;
					if (l>>pp&1){
					

						if (ret.dist[id[i]][id[l]]!=1e18) ret.dist[id[i]][id[l]]+=wp[j];
					}
				}
			}
		}
	}
	return ret;
}
mat mul(mat x,mat y){
	mat ret;
	for (int i=1;i<=cc;i++){
		for (int j=1;j<=cc;j++){
			for (int k=1;k<=cc;k++){
				ret.dist[i][j]=min(ret.dist[i][j],x.dist[i][k]+y.dist[k][j]);
			}
		}
	}
	return ret;
}

void Mul(mat X){
	for (int i=1;i<=cc;i++){
		dp2[i]=1e18;
	}
	for (int i=1;i<=cc;i++){
		for (int j=1;j<=cc;j++){
			dp2[j]=min(dp2[j],dp[i]+X.dist[i][j]);
		}
	}
	for (int i=1;i<=cc;i++) dp[i]=dp2[i];
}
mat mqp(mat x,LL p){
	mat R;
	for (int i=1;i<=cc;i++) R.dist[i][i]=0;
	while (p){
		if (p&1) R=mul(R,x);
		x=mul(x,x);
		p>>=1;
	}
	return R;
}
bool normal(int pos){
	for (int i=1;i<=q;i++){
		if (p[i]<=pos && pos-p[i]<k) return false;
	}
	return true;
}
int main(){
	x=read();k=read();n=read();q=read();
	n+=k-x;
	for (int i=1;i<=k;i++){
		c[i]=read();
	}
	_init();
	 
	

	for (int i=1;i<=q;i++){
		p[i]=read();wp[i]=read();
	}
	for (int i=1;i<=cc;i++) dp[i]=1e18;
	dp[id[(1<<x)-1]]=0;
	int now=k;
	while (now<n){
		if (!normal(now+1)){
			mat Tra=Build(now+1);
			Mul(Tra);
			 
			now++;
			continue;
		} 
		int Nxt=n+1;
		for (int i=1;i<=q;i++){
			if (p[i]>now){
				Nxt=min(Nxt,p[i]);
			}
		}
		int di=Nxt-now-1;
		mat Tra=mqp(T1,di);
		Mul(Tra);
		now=Nxt-1;
	}
	printf("%I64d\n",dp[id[(1<<x)-1]]);
	return ~~(0^_^0);
}
