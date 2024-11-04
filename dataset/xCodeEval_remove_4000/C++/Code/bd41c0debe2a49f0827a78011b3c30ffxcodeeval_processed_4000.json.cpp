


















using namespace std;










typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }








ll perf[100];

struct BalancedBinaryForest {
	int n;
	vector<bool> isblack;
	vector<int> blackheight; 

	vector<int> lft,rgt,par;
	
	void init(int _n) {
		n=_n; isblack=vector<bool>(n,true); blackheight=vector<int>(n,1); lft=rgt=par=vector<int>(n,-1);
	}
	pair<int,int> split(int a) { 

		

		++perf[0];
		int l=lft[a],r=rgt[a]; lft[a]=rgt[a]=-1; if(l!=-1) par[l]=-1; if(r!=-1) par[r]=-1; if(l!=-1&&!isblack[l]) isblack[l]=true,++blackheight[l]; if(r!=-1&&!isblack[r]) isblack[r]=true,++blackheight[r];
		while(par[a]!=-1) {
			++perf[1];
			int p=par[a],pl=lft[p],pr=rgt[p]; lft[p]=rgt[p]=-1; par[a]=par[p]; par[p]=-1; if(par[a]!=-1) (lft[par[a]]==p?lft[par[a]]:rgt[par[a]])=a; if(pl!=a&&pl!=-1) par[pl]=-1; if(pr!=a&&pr!=-1) par[pr]=-1;
			if(pl!=a&&pl!=-1&&!isblack[pl]) isblack[pl]=true,++blackheight[pl]; if(pr!=a&&pr!=-1&&!isblack[pr]) isblack[pr]=true,++blackheight[pr];
			if(a==pl) r=join3(r,p,pr);
			if(a==pr) l=join3(pl,p,l);
			

			

		}
		isblack[a]=true; blackheight[a]=1;
		

		return MP(l,r);
	}
	int rotatelft(int a) { ++perf[2]; assert(par[a]==-1); int c=rgt[a],d=lft[c]; rgt[a]=d; if(d!=-1) par[d]=a; lft[c]=a; par[a]=c; par[c]=-1; return c; }
	int rotatergt(int c) { ++perf[3]; assert(par[c]==-1); int a=lft[c],d=rgt[a]; lft[c]=d; if(d!=-1) par[d]=c; rgt[a]=c; par[c]=a; par[a]=-1; return a; }
	int height(int x) { return x==-1?0:blackheight[x]; }
	

	int joinlft(int a,int x,int b) {
		

		++perf[4];
		if(height(a)==height(b)&&(a==-1||isblack[a])) { isblack[x]=false; blackheight[x]=height(a); lft[x]=a; rgt[x]=b; if(a!=-1) par[a]=x; if(b!=-1) par[b]=x; return x; }
		int r=rgt[a]; if(r!=-1) par[r]=-1; rgt[a]=joinlft(r,x,b); par[rgt[a]]=a;
		if(!isblack[a]&&!isblack[rgt[a]]) { isblack[a]=true; ++blackheight[a]; return a; }
		if(isblack[a]&&isblack[rgt[a]]&&blackheight[a]==blackheight[rgt[a]]) { assert(!isblack[rgt[rgt[a]]]); a=rotatelft(a); isblack[a]=false; isblack[rgt[a]]=true; ++blackheight[rgt[a]]; return a; }
		return a;
	}
	

	int joinrgt(int a,int x,int b) {
		++perf[5];
		if(height(a)==height(b)&&(b==-1||isblack[b])) { isblack[x]=false; blackheight[x]=height(a); lft[x]=a; rgt[x]=b; if(a!=-1) par[a]=x; if(b!=-1) par[b]=x; return x; }
		int l=lft[b]; if(l!=-1) par[l]=-1; lft[b]=joinrgt(a,x,l); par[lft[b]]=b;
		if(!isblack[b]&&!isblack[lft[b]]) { isblack[b]=true; ++blackheight[b]; return b; }
		if(isblack[b]&&isblack[lft[b]]&&blackheight[b]==blackheight[lft[b]]) { assert(!isblack[lft[lft[b]]]); b=rotatergt(b); isblack[b]=false; isblack[lft[b]]=true; ++blackheight[lft[b]]; return b; }
		return b;
	}
	

	int join3(int a,int x,int b) {
		++perf[6];
		

		int ret=height(a)>=height(b)?joinlft(a,x,b):joinrgt(a,x,b); if(!isblack[ret]) isblack[ret]=true,++blackheight[ret];
		

		return ret;
	}
	int join2(int a,int b) {
		assert(a==-1&&b==-1||a!=b);
		++perf[7];
		

		if(a==-1) return b; else if(b==-1) return a;
		int c=lft[b],d=rgt[b]; lft[b]=rgt[b]=-1; if(c!=-1) par[c]=-1; if(d!=-1) par[d]=-1; if(c!=-1&&!isblack[c]) isblack[c]=true,++blackheight[c]; if(d!=-1&&!isblack[d]) isblack[d]=true,++blackheight[d];
		return join3(join2(a,c),b,d);
	}
	int merge(int a,int b) { 

		++perf[8];
		

		int ret=join2(getroot(a),getroot(b));
		perf[11]=max(perf[11],(ll)height(ret));
		

		return ret;
	}
	int getroot(int a) { 

		++perf[9];
		while(a!=-1&&par[a]!=-1) ++perf[10],a=par[a]; return a;
	}
	void myassert(bool cond,const char *s,int who) {
		if(cond) return;
		printf("fail: %s for %d\n",s,who+1);
		assert(cond);
	}
	void verify() {
		

		REP(i,n) if(par[i]!=-1) myassert(lft[par[i]]==i||rgt[par[i]]==i,"parent with incorrect child",i);
		REP(i,n) if(lft[i]!=-1) myassert(par[lft[i]]==i,"lft incorrect parent",i);
		REP(i,n) if(rgt[i]!=-1) myassert(par[rgt[i]]==i,"rgt incorrect parent",i);
		REP(i,n) if(par[i]!=-1&&!isblack[i]) myassert(isblack[par[i]],"red with red parent",i);
		REP(i,n) myassert(height(lft[i])==height(rgt[i]),"diff heights",i);
		REP(i,n) myassert(height(i)==height(lft[i])+(isblack[i]?1:0),"incorrect height",i);
	}
};

struct ForestDynamicConnectivity {
	int n;
	BalancedBinaryForest bbf;
	queue<int> pool;
	
	void init(int _n) {
		n=_n; bbf.init(n+2*(n-1));
		FOR(i,n,bbf.n) pool.push(i);
	}
	int getnode() { assert(!pool.empty()); int ret=pool.front(); pool.pop(); return ret; }
	void releasenode(int x) { pool.push(x); }
	void reroot(int a) { 

		

		int b,c; tie(b,c)=bbf.split(a);
		bbf.merge(a,bbf.merge(c,b));
	}
	pair<int,int> addedge(int a,int b) {
		

		reroot(a);
		reroot(b);
		int ab=getnode(),ba=getnode();
		bbf.merge(bbf.merge(a,ab),bbf.merge(b,ba));
		return MP(ab,ba);
	}
	void remedge(pair<int,int> e) {
		int a,b,c; tie(a,b)=bbf.split(e.first);
		if(bbf.getroot(a)==bbf.getroot(e.second)) { c=b; tie(a,b)=bbf.split(e.second); } else { tie(b,c)=bbf.split(e.second); }
		releasenode(e.first),releasenode(e.second);
		bbf.merge(a,c);
	}
	int getrepresentative(int a) {
		return bbf.getroot(a);
	}
};

struct SegTreeMinCounter {
	int n;
	vector<int> smn,id1,slazy;
	void sapply(int x,int by) {
		smn[x]+=by; slazy[x]+=by;
	}
	void spush(int x) {
		if(slazy[x]!=0) sapply(2*x+1,slazy[x]),sapply(2*x+2,slazy[x]),slazy[x]=0;
	}
	void spull(int x) {
		smn[x]=min(smn[2*x+1],smn[2*x+2]);
		id1[x]=(smn[2*x+1]==smn[x]?id1[2*x+1]:0)+(smn[2*x+2]==smn[x]?id1[2*x+2]:0);
	}
	void sinit(int x,int l,int r) {
		slazy[x]=0;
		if(l==r) {
			smn[x]=0,id1[x]=1;
		} else {
			int m=l+(r-l)/2;
			sinit(2*x+1,l,m); sinit(2*x+2,m+1,r);
			spull(x);
		}
	}
	void smod(int x,int l,int r,int L,int R,int BY) {
		if(L<=l&&r<=R) {
			sapply(x,BY);
		} else {
			int m=l+(r-l)/2; spush(x);
			if(L<=m) smod(2*x+1,l,m,L,R,BY);
			if(m+1<=R) smod(2*x+2,m+1,r,L,R,BY);
			spull(x);
		}
	}
	int sget(int x,int l,int r,int L,int R,int VAL) {
		if(L<=l&&r<=R) {
			assert(smn[x]>=VAL);
			return smn[x]==VAL?id1[x]:0;
		} else {
			int m=l+(r-l)/2; spush(x); int ret=0;
			if(L<=m) ret+=sget(2*x+1,l,m,L,R,VAL);
			if(m+1<=R) ret+=sget(2*x+2,m+1,r,L,R,VAL);
			return ret;
		}
	}
	
	void init(int _n) { n=_n; smn=id1=slazy=vector<int>(4*n); sinit(0,0,n-1); }
	void mod(int l,int r,int by) { smod(0,0,n-1,l,r,by); }
	int get(int l,int r,int val) { return sget(0,0,n-1,l,r,val); }
};

const int MAXH=1000;
const int MAXW=1000;
const int MAXN=200000;
const int DX[]={-1,0,+1,0},DY[]={0,+1,0,-1};

int h,w,n;
int g[MAXH][MAXW];

pair<int,int> pos[MAXN];
ForestDynamicConnectivity conn;
vector<pair<int,int>> connedges[MAXN];
SegTreeMinCounter id0;

ll solve() {
	REP(x,h) REP(y,w) pos[g[x][y]]=MP(x,y);
	conn.init(n);
	id0.init(n);
	ll ret=0;
	int l=0;
	REP(r,n) {
		int rx=pos[r].first,ry=pos[r].second;
		while(true) {
			vector<int> adj;
			REP(k,4) {
				int nx=rx+DX[k],ny=ry+DY[k]; if(nx<0||nx>=h||ny<0||ny>=w||g[nx][ny]<l||g[nx][ny]>r) continue;
				adj.PB(conn.getrepresentative(g[nx][ny]));
			}
			sort(adj.begin(),adj.end()); bool duplicate=false; FORSZ(i,1,adj) if(adj[i-1]==adj[i]) duplicate=true; if(!duplicate) break;
			REPSZ(i,connedges[l]) conn.remedge(connedges[l][i]);
			++l;
		}
		id0.mod(0,r,+1);
		REP(k,4) {
			int nx=rx+DX[k],ny=ry+DY[k]; if(nx<0||nx>=h||ny<0||ny>=w||g[nx][ny]<l||g[nx][ny]>r) continue;
			connedges[g[nx][ny]].PB(conn.addedge(g[nx][ny],r));
			id0.mod(0,g[nx][ny],-1);
		}
		int cur=id0.get(l,r,1);
		

		ret+=cur;
	}
	return ret;
}

void run() {
	scanf("%d%d",&h,&w); n=h*w;
	REP(x,h) REP(y,w) scanf("%d",&g[x][y]),--g[x][y];
	printf("%lld\n",solve());
}

void stress() {
	

	std::mt19937 rnd(1237891);
	REP(rep,1) {
		h=992,w=191,n=h*w;
		memset(g,-1,sizeof(g)); int at=0; REP(xx,h) { int x=(2*xx)%h+(2*xx>=h?1:0); REP(y,w) g[x][y]=at++; } REP(x,h) REP(y,w) assert(g[x][y]!=-1);
		ll have=solve();
		printf("%lld\n",have);
	}
	REPE(i,11) printf("perf[%d]=%lld\n",i,perf[i]);
}

int main() {
	run();
	

	return 0;
}