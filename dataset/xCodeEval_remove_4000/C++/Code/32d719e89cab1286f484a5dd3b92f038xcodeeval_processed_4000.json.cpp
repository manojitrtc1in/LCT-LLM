
using namespace std;
typedef long double ld;


typedef long long INT;
typedef long long ll;
typedef unsigned long long ull;
const ld eps=1e-11;
typedef complex<ll> pt;
const int inf=1e9+99;




istream &operator>>(istream &in,INT &x) {
	string s; in>>s;
	assert(s.size());
	bool n=s[0]=='-';
	if(n) s=s.substr(1);
	x=0;
	for(char c:s) x=x*10+(c-'0');
	if(n) x=-x;
	return in;
}
ostream &operator<<(ostream &out,INT x) {
	if(x<0) out<<"-", x=-x;
	int D=10;
	vector<int> v;
	for(;x;) v.push_back(x%D), x/=D;
	reverse(v.begin(),v.end());
	for(int x:v) out<<x;
	return out;
}

int da[1<<20],rk[1<<20];
int rt(int u) {
	if(da[u]==u) return u;
	return da[u]=rt(da[u]);
}
int un(int u,int v) {
	u=rt(u),v=rt(v);
	if(u==v) return 0;
	if(rk[u]>rk[v]) swap(u,v);
	if(rk[u]==rk[v]) ++rk[v];
	da[u]=v;
	return 1;
}

typedef vector<int> VI;
typedef vector<VI> VVI;
bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
for (int j = 0; j < (int)w[i].size(); j++) {
if (w[i][j] && !seen[j]) {
 seen[j] = true;
if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
 mr[i] = j;
 mc[j] = i;
return true;
 }
 }
 }
 return false;
}
int id0(const VVI &w, VI &mr, VI &mc) {
 mr = VI(w.size(), -1);
 mc = VI(w[0].size(), -1);
int ct = 0;
for (int i = 0; i < (int)w.size(); i++) {
 VI seen(w[0].size());
if (FindMatch(i, w, mr, mc, seen)) ct++;
 }
return ct;
}






























pair<int,int> operator+(const pair<int,int> &a,const pair<int,int> &b) {
	return {a.first+b.first,a.second+b.second};
}
struct ptcmp {
bool operator()(const pt&a,const pt&b) const {
	if(real(a)!=real(b)) return real(a)<real(b);
	return imag(a)<imag(b);
}
};
struct Q {
	int L,R,i;
} qs[100<<10];
const int SR=300;
bool operator<(const Q&a,const Q&b) {
	if(a.L/SR!=b.L/SR) return a.L<b.L;
	return a.R<b.R;
}
struct mocmp {
bool operator()(const pair<int,int>&a,const pair<int,int>&b) const {
	if(a.fi/SR!=b.fi/SR) return a.fi<b.fi;
	return a.se<b.se;
}
};
const pt hexdd[]={1,pt(0,1),pt(-1,1),-1,pt(0,-1),pt(1,-1)};
ll c0(ll x) {
	return x?!(x%10)+c0(x/10):0;
}
ll g(ll x) {
	if(x<=10) return 0;
	if(x%10) return x%10*c0(x/10)+1+g(x-x%10);
	return x/10-1+10*g(x/10);
}





































  





























int par[MAXN][MAXK];  


int nth(int a, int n) {  

  for(int k=0;n;n>>=1,++k) if (n&1) a = par[a][k];
  return a;
}

int depth(int a) {       

  int ans = 0;
  for(int k=MAXK-1;k>=0;--k)
  if (par[a][k] >= 0) a = par[a][k], ans += (1<<k);
  return ans;
}

int lca(int a, int b) {  

  int da = depth(a), db = depth(b);
  if (da < db) swap(a,b), swap(da,db);

  a = nth(a, da-db);
  for(int k=MAXK-1;k>=0;--k)
    if (par[a][k] != par[b][k])
      a = par[a][k], b = par[b][k];
      
  if (a!=b) a = b = par[a][0];  
  return a;
}

bool id2(int a, int b) {  

  return lca(a,b) == a;
}







void id4(int n, int* p) {
  for(int i=0; i<=n; ++i) par[i][0] = p[i];
  for(int k=1; k<MAXK; ++k) {
    for (int i=0; i<=n; ++i) {
      int j = (par[i][k-1]>=0?par[i][k-1]:i);
      par[i][k] = par[j][k-1];
    }
  }
}

int p[200<<10],sz[200<<10];
vector<int> adj[200<<10];
int dfs(int u) {
	if(sz[u]) return sz[u];
	sz[u]=1;
	for(int v:adj[u]) sz[u]+=dfs(v);
	return sz[u];
}

string esc(string s,int n) {
	if(!n) return s;
	string t="";
	for(char c:s) {
		if('!'<=c&&c<='*' || '['<=c&&c<=']') t+='\\';
		t+=c;
	}
	return esc(t,n-1);
}

bool gg(vector<int> v) {
	sort(v.begin(),v.end());
	int d=v[1]-v[0];
	return v[2]-v[1]==d && v[3]-v[2]==d;
}

struct cmp {
	int s;
	void fix(int &x,int &y) {
		if(!(x>s)&&!(y>s)) swap(x,y);
		if(x>s&&y>s) x-=s, y-=s;
		if(y>s) y-=s;
		if(x>s) x-=s, x=s-x,y=s-y, swap(x,y);
	}
	bool operator()(const pair<int,int> &a,const pair<int,int> &b) {
		if(a==b) return 0;
		int x=a.fi,y=a.se,xx=b.fi,yy=b.se;
		x+=x, xx+=xx, y+=y, yy+=yy;
		for(;(x>s)==(xx>s)&&(y>s)==(yy>s);) {
			fix(x,y); fix(xx,yy);
			x+=x, xx+=xx, y+=y, yy+=yy;
		}
		if((x>s)!=(xx>s)) return xx>s;
		if((y>s)!=(yy>s)) return (x>s)?(y>s):(yy>s);
		assert(0);
	}
};

ld g(int e,int es,int ef) {
	static int dp[10<<20];
	if(ef>es) ef^=es^=ef^=es;
	

	int mk=1<<30;
	int *it=dp;
	int *b=dp+e-es+1;
	if(b<=it) b=it+1;
	for(;++it!=b;) {
		++it;
		*(it+ef)+=*it;
		*(it+es)+=*it;
		if(*it&mk) return *it;
	}
	if(e-es<0) es=e;
	int *c=dp+e-ef+1;
	it=dp+e-es;
	if(c<=it) c=it+1;
	for(;++it!=c;) {
		++*it;
		*(it+ef)+=*it;
		if(*it&mk) return *it;
	}
	return *it+1;
}

ld _main() {
	int e,es,ef; scanf("%d%d%d",&e,&es,&ef);

	ld z=g(e,es,ef);
	if(z>=8) return 200/z;
	

	ld xc=1/z+1;
	ld x=225/xc;
	return 225-x;
}
string s;
int n;
int dp[256][256];
int g(int l,int r) { 

	

	assert(l<=r);
	int &ans=dp[l][r];
	if(~ans) return ans;
	if(l==r) return ans=0;
	ans=3+g(l+1,r);
	for(int m=l+1;m<r;++m) {
		if(s[m]!=s[l]) continue;
		

		ans=min(ans,g(l+1,m)+g(m,r)+1);
	}
	return ans;
}

int ri() {
	static char c[4];
	scanf("%s",c);
	if(*c=='?') return -1;
	int n=strlen(c);
	assert(0<n&&n<=3);
	switch(n) {
		case 3: return 100*(c[0]-'0')+10*(c[1]-'0')+(c[2]-'0');
		case 2: return 10*(c[0]-'0')+(c[1]-'0');
		case 1: return (c[0]-'0');
	}
}
typedef tuple<int,int,int,int,int> card;
ll h(const card &c) {
	ll x=0;
	x|=get<0>(c);
	x<<=7;
	x|=get<1>(c);
	x<<=7;
	x|=get<2>(c);
	x<<=7;
	x|=get<3>(c);
	x<<=7;
	x|=get<4>(c);
	return x;
}
bool eq(const card &a,const card &b) {
	if(get<0>(a)!=127 && get<0>(a)!=get<0>(b)) return 0;
	if(get<1>(a)!=127 && get<1>(a)!=get<1>(b)) return 0;
	if(get<2>(a)!=127 && get<2>(a)!=get<2>(b)) return 0;
	if(get<3>(a)!=127 && get<3>(a)!=get<3>(b)) return 0;
	if(get<4>(a)!=127 && get<4>(a)!=get<4>(b)) return 0;
	return 1;
}


ld go1(int);
map<int,ld> dp2;
ld go2(int x) {
	if(!x) return 0;
	if(dp2.count(x)) return dp2[x];
	dp2[x]=0;
	ld &ans=dp2[x];
	ans=go1(x-1)/x + (x-1)*go2(x-1)/x;
	return ans;
}
map<int,ld> dp1;
ld go1(int x) {
	if(!x) return 0;
	if(dp1.count(x)) return dp1[x];
	dp1[x]=0;
	ld &ans=dp1[x];
	ans=1./x + (x-1)*go2(x-1)/x;
	

	return ans;
}

bool id3(string s,string t) {
	return t.size()>=s.size() && t.substr(t.size()-s.size())==s;
}

const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};



void PI(int x) {
	if(!x) return;
	PI(x/1000);
	if(x/1000) printf(".%03d",x%1000);
	else printf("%d",x%1000);
}

struct pp {
	int x;
	int y;
	int i;
};
pt dir,bas;
ll dot(pt x,pt y) {
	return real(x*conj(y));
}
ll eval(pt x) {
	x-=bas;
	return dot(x,dir);
}
bool cc(const pt &a,const pt &b) {
	ll da=eval(a);
	da=abs(da);
	ll db=eval(b);
	db=abs(db);
	if(!da) da=1e18;
	if(!db) db=1e18;
	return da<db;
}
bool dd(const pt &a,const pt &b) {
	return norm(a-bas)<norm(b-bas);
}

struct QQ {
	int L,R,i,ans;
} qqs[100<<10];


const int SQ2=3500;
bool QC(const QQ &a,const QQ &b) {
	if(a.L/SQ2 != b.L/SQ2) return a.L<b.L;
	return a.R<b.R;
}
bool i9(const QQ &a,const QQ &b) {
	return a.i<b.i;
}

int id1() {
	static char s[1<<20];
	scanf("%s",s);
	int n=strlen(s);
	static int mat[1<<20];
	stack<int> st;
	for(int i=0;i<n;i++) mat[i]=-1;
	for(int i=0;i<n;i++) {
		if(s[i]=='(') st.push(i);
		else {
			assert(s[i]==')');
			if(!st.empty()) {
				mat[st.top()]=i;
				mat[i]=st.top();
				st.pop();
			}
		}
	}
	


	int m; scanf("%d",&m);
	for(int i=0;i<m;i++) scanf("%d%d",&qqs[i].L,&qqs[i].R), qqs[i].i=i;
	for(int i=0;i<m;i++) --qqs[i].L, --qqs[i].R;
	sort(qqs,qqs+m,QC);
	


	int L=0,R=-1;
	deque<int> lo,ro;
	int bad=0;
	int ans=0;
	for(int i=0;i<m;i++) {
		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		for(;R<qqs[i].R;) {
			++R;
			if(L<=mat[R]&&mat[R]<=R) ++ans;
		}
		for(;L>qqs[i].L;) {
			--L;
			if(L<=mat[L]&&mat[L]<=R) ++ans;
		}
		for(;R>qqs[i].R;) {
			if(L<=mat[R]&&mat[R]<=R) --ans;
			--R;
		}
		for(;L<qqs[i].L;) {
			if(L<=mat[L]&&mat[L]<=R) --ans;
			++L;
		}

		assert(L==qqs[i].L);
		assert(R==qqs[i].R);
		

		qqs[i].ans=ans;
		

	}

	sort(qqs,qqs+m,i9);
	for(int i=0;i<m;i++) printf("%d\n",qqs[i].ans+qqs[i].ans);
}

int mainz() {
	int n; scanf("%d",&n);
	const int N=1.1e5;
	static ll x[N],y[N];
	for(int i=0;i<n;i++) scanf("%lld%lld",x+i,y+i);
	static pt p[N];
	for(int i=0;i<n;i++) p[i]={x[i],y[i]};
	bas=p[0];
	int cl=min_element(p+1,p+n,dd)-p;
	if(cl!=1) swap(p[cl],p[1]);
	dir=(p[1]-p[0])*pt(0,1);
	bas=p[0];
	int ans=min_element(p+2,p+n,cc)-p;
	if(ans==cl) ans=1;
	printf("%d %d %d\n",1,cl+1,ans+1);
	return 22;
}

int qqmain() {

	int n; scanf("%d",&n);
	static bool q[1<<20];
	int x; for(int i=0;i<n;i++) scanf("%d",&x), q[x]=1;

	int ct=0;
	vector<int> ans;
	const int MILL=1e6;
	for(int i=1;i<=5e5;i++) {
		if(q[i]&&q[MILL+1-i]) ++ct; else
		if(q[i]) ans.pb(MILL+1-i); else
		if(q[MILL+1-i]) ans.pb(i); else
		continue;
	}
	for(int i=1;ct;i++) {
		assert(i<=5e5);
		if(!q[i] && !q[MILL+1-i]) ans.pb(i), ans.pb(MILL+1-i), --ct;
	}

	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	assert((int)ans.size()==n);
	for(int i=0;i<n;i++) printf("%d%c",ans[i]," \n"[i==n-1]);


	return 0;
}


int notmain() {


	string s; cin>>s; s+="z";
	int i=0;
	ll ans=0;
	for(;i+1<(int)s.size();) {
		int cur=0;
		int len=0;
		bool seen=0;
		for(;'a'<=s[i]&&s[i]<='z';) ++i;
		for(;!('a'<=s[i]&&s[i]<='z');) {
			if(s[i]=='.') len=0, seen=1;
			else ++len, cur*=10, cur+=s[i]-'0';

			++i;
		}
		assert(len<=3);
		if(seen) assert(len>=2);
		if(seen && len==2);
		else cur*=100;
		ans+=cur;
	}

	if(ans/100) PI(ans/100);
	else printf("0");
	if(ans%100) printf(".%02d",int(ans%100));
	printf("\n");

	return 0;

}

int main() {
	int n; scanf("%d",&n);
	static char grid[128][128];
	for(int i=0;i<n;i++) scanf("%s",grid[i]);
	static valarray<int> A[128];
	for(int i=0;i<n;i++) A[i]=valarray<int>(n);
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) A[i][j]=grid[i][j]-'0';
	valarray<int> a(n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	vector<int> ans;
	for(;;) {
		bool q=0;
		for(int i=0;i<n;i++) if(!a[i]) {
			ans.pb(i);
			a-=A[i];
			q=1;
		}
		if(!q) break;
	}
	printf("%d\n",(int)ans.size());
	for(int i=0;i<(int)ans.size();i++)
		printf("%d%c",ans[i]+1," \n"[i==(int)ans.size()-1]);
}


