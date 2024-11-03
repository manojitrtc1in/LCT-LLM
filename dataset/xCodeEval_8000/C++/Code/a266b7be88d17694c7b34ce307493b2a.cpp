
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
const int Maxn=200005;
LL bit[Maxn];
LL a[Maxn]; 
void Add(int pos,LL val){
	while (pos<Maxn){
		bit[pos]+=val;
		pos+=pos&-pos;
	}
}
LL query(int pos){
	LL ret=0;
	while (pos){
		ret+=bit[pos];
		pos-=pos&-pos;
	}
	return ret;
}
set<int> S[34];
int main(){
	int n,q;
	n=read();q=read();
	for (int i=1;i<=n;i++){
		a[i]=read();
		Add(i,a[i]);
		LL lo=a[i];
		

		int dd=lo?((int)((log(lo)/log(2.0)-0.0000001))):32;
		

		S[dd].insert(i);
	}
	for (int i=0;i<q;i++){
		int pos;
		LL y;
		pos=read();y=read();
		LL dlt=y-a[pos];
		Add(pos,dlt);
		LL lo=a[pos];
		int dd=lo?((int)((log(lo)/log(2.0)+0.0000001))):32;
		

		S[dd].erase(pos);
		a[pos]+=dlt;
		
		lo=a[pos];
		dd=lo?((int)((log(lo)/log(2.0)+0.0000001))):32;
		

		S[dd].insert(pos);
		bool flag=true;
		for (int j=0;j<33;j++){
			set<int>::iterator v=S[j].begin();
			for (int k=0;k<2;k++){
				if (v==S[j].end()) break;
				int pp=*v;
				

				if (a[pp]==query(pp-1)){
					printf("%d\n",pp);
					flag=false;
					break;
				}
				v++;
			}
			if (!flag) break;
		}
		if (flag){
			printf("-1\n");
		}
	}
	return ~~(0^_^0);
}
