#include<algorithm>
#include<assert.h>
#include<bitset>
#include<complex>
#include<ctype.h>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<limits.h>
#include<list>
#include<map>
#include<math.h>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<time.h>
#include<utility>
#include<vector>


using namespace std;
#define rep(i,n) for (int i=0;i<n;++i)
#define For(i,l,r) for(int i=l;i<=r;++i)
#define foreach(i,x) for(typeof((x).begin()) i=(x).begin();i!=(x).end();++i)
#define all(x) x.begin(),x.end()
#define SORT(x) sort(all(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))
#define SZ(x) ((int)(x.size()))
#define DREP(x) sort(all(x));x.erase(unique(x.begin(),x.end()),x.end())
#define INDEX(arr,index) (lower_bound(arr.begin(),arr.end(),index)-arr.begin())
#define Debug(x) cout<<#x<<"="<<x<<endl
#define debug(args...) {dbg,args; cerr<<endl;}
#define dline cerr<<endl
#define mp make_pair
#define pb push_back
#define FF first
#define SS second
#define tri(a,b,c) make_pair((a),make_pair((b),(c)))
#define XX first
#define YY second.first
#define ZZ second.second
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sf(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define maX(a,b) ((a)>(b)?(a):(b))
#define miN(a,b) ((a)<(b)?(a):(b))
#define abS(x) ((x)<0?-(x):(x))
const int inf=~0U>>1;
const long long linf=(long long)1e18;
const double eps=1e-6;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long double ld;
typedef vector<int>::iterator eit;
typedef pair<int,int> pi;
typedef pair<int,pair<int,int> > tri;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
typedef set<int> si;
typedef set<int>::iterator sit;
typedef map<int,int> mii;
typedef map<int,int>::iterator mit;
typedef istringstream ISS;
typedef ostringstream OSS;
template<class T> string tostr(T a){
	OSS out;out<<a;return out.str();
}
struct debugger{
	template<typename T> debugger& operator ,(const T &x)
	{
		cerr<<x<<endl;
		return *this;
	}
}dbg;
namespace fastIO{
	#define BUF_SIZE 100000
	#define OUT_SIZE 100000
	#define ll long long
	

	bool IOerror=0;
	inline char nc(){
		static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
		if (p1==pend){
			p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin);
			if (pend==p1){IOerror=1;return -1;}
			

		}
		return *p1++;
	}
	inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
	inline void read(int &x){
		bool sign=0; char ch=nc(); x=0;
		for (;blank(ch);ch=nc());
		if (IOerror)return;
		if (ch=='-')sign=1,ch=nc();
		for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
		if (sign)x=-x;
	}
	inline void read(ll &x){
		bool sign=0; char ch=nc(); x=0;
		for (;blank(ch);ch=nc());
		if (IOerror)return;
		if (ch=='-')sign=1,ch=nc();
		for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
		if (sign)x=-x;
	}
	inline void read(double &x){
		bool sign=0; char ch=nc(); x=0;
		for (;blank(ch);ch=nc());
		if (IOerror)return;
		if (ch=='-')sign=1,ch=nc();
		for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
		if (ch=='.'){
			double tmp=1; ch=nc();
			for (;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0');
		}
		if (sign)x=-x;
	}
	inline void read(char *s){
		char ch=nc();
		for (;blank(ch);ch=nc());
		if (IOerror)return;
		for (;!blank(ch)&&!IOerror;ch=nc())*s++=ch;
		*s=0;
	}
	inline void read(char &c){
		for (c=nc();blank(c);c=nc());
		if (IOerror){c=-1;return;}
	}
	

	inline void read1(int &x){
		char ch;int bo=0;x=0;
		for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
		for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
		if (bo)x=-x;
	}
	inline void read1(ll &x){
		char ch;int bo=0;x=0;
		for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
		for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
		if (bo)x=-x;
	}
	inline void read1(double &x){
		char ch;int bo=0;x=0;
		for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
		for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
		if (ch=='.'){
			double tmp=1;
			for (ch=getchar();ch>='0'&&ch<='9';tmp/=10.0,x+=tmp*(ch-'0'),ch=getchar());
		}
		if (bo)x=-x;
	}
	inline void read1(char *s){
		char ch=getchar();
		for (;blank(ch);ch=getchar());
		for (;!blank(ch);ch=getchar())*s++=ch;
		*s=0;
	}
	inline void read1(char &c){for (c=getchar();blank(c);c=getchar());}
	

	inline void read2(int &x){scanf("%d",&x);}
	inline void read2(ll &x){
		#ifdef _WIN32
			scanf("%I64d",&x);
		#else
		#ifdef __linux
			scanf("%lld",&x);
		#else
			puts("error:can't recognize the system!");
		#endif
		#endif
	}
	inline void read2(double &x){scanf("%lf",&x);}
	inline void read2(char *s){scanf("%s",s);}
	inline void read2(char &c){scanf(" %c",&c);}
	inline void readln2(char *s){gets(s);}
	

	struct Ostream_fwrite{
		char *buf,*p1,*pend;
		Ostream_fwrite(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;}
		void out(char ch){
			if (p1==pend){
				fwrite(buf,1,BUF_SIZE,stdout);p1=buf;
			}
			*p1++=ch;
		}
		void print(int x){
			static char s[15],*s1;s1=s;
			if (!x)*s1++='0';if (x<0)out('-'),x=-x;
			while(x)*s1++=x%10+'0',x/=10;
			while(s1--!=s)out(*s1);
		}
		void println(int x){
			static char s[15],*s1;s1=s;
			if (!x)*s1++='0';if (x<0)out('-'),x=-x;
			while(x)*s1++=x%10+'0',x/=10;
			while(s1--!=s)out(*s1); out('\n');
		}
		void print(ll x){
			static char s[25],*s1;s1=s;
			if (!x)*s1++='0';if (x<0)out('-'),x=-x;
			while(x)*s1++=x%10+'0',x/=10;
			while(s1--!=s)out(*s1);
		}
		void println(ll x){
			static char s[25],*s1;s1=s;
			if (!x)*s1++='0';if (x<0)out('-'),x=-x;
			while(x)*s1++=x%10+'0',x/=10;
			while(s1--!=s)out(*s1); out('\n');
		}
		void print(double x,int y){
			static ll mul[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,
				1000000000,10000000000LL,100000000000LL,1000000000000LL,10000000000000LL,
				100000000000000LL,1000000000000000LL,10000000000000000LL,100000000000000000LL};
			if (x<-1e-7)out('-'),x=-x;x*=mul[y];
			ll x1=(ll)floor(x); if (x-floor(x)>=0.5)++x1; ll x2=x1/mul[y];
			print(x2);if (y>0){out('.');print(x1-x2*mul[y]);}
		}
		void println(double x,int y){print(x,y);out('\n');}
		void print(char *s){while (*s)out(*s++);}
		void println(char *s){while (*s)out(*s++);out('\n');}
		void flush(){if (p1!=buf){fwrite(buf,1,p1-buf,stdout);p1=buf;}}
		~Ostream_fwrite(){flush();}
	}Ostream;
	inline void print(int x){Ostream.print(x);}
	inline void println(int x){Ostream.println(x);}
	inline void print(char x){Ostream.out(x);}
	inline void println(char x){Ostream.out(x);Ostream.out('\n');}
	inline void print(ll x){Ostream.print(x);}
	inline void println(ll x){Ostream.println(x);}
	inline void print(double x,int y){Ostream.print(x,y);}
	inline void println(double x,int y){Ostream.println(x,y);}
	inline void print(char *s){Ostream.print(s);}
	inline void println(char *s){Ostream.println(s);}
	inline void println(){Ostream.out('\n');}
	inline void flush(){Ostream.flush();}
	

	char Out[OUT_SIZE],*o=Out;
	inline void print1(int x){
		static char buf[15];
		char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x;
		while(x)*p1++=x%10+'0',x/=10;
		while(p1--!=buf)*o++=*p1;
	}
	inline void println1(int x){print1(x);*o++='\n';}
	inline void print1(ll x){
		static char buf[25];
		char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x;
		while(x)*p1++=x%10+'0',x/=10;
		while(p1--!=buf)*o++=*p1;
	}
	inline void println1(ll x){print1(x);*o++='\n';}
	inline void print1(char c){*o++=c;}
	inline void println1(char c){*o++=c;*o++='\n';}
	inline void print1(char *s){while (*s)*o++=*s++; }
	inline void println1(char *s){print(s);*o++='\n';}
	inline void println1(){*o++='\n';}
	inline void flush1(){if (o!=Out&&*(o-1)=='\n')*--o=0;puts(Out);}
	struct puts_write{
		~puts_write(){flush1();}
	};
	inline void print2(int x){printf("%d",x);}
	inline void println2(int x){printf("%d\n",x);}
	inline void print2(char x){printf("%c",x);}
	inline void println2(char x){printf("%c\n",x);}
	inline void print2(ll x){
		#ifdef _WIN32
			printf("%I64d",x);
		#else
		#ifdef __linux
			printf("%lld",x);
		#else
			puts("error:can't recognize the system!");
		#endif
		#endif
	}
	inline void println2(ll x){print2(x);printf("\n");}
	inline void println2(){printf("\n");}
	#undef ll
	#undef OUT_SIZE
	#undef BUF_SIZE
};
using namespace fastIO;
string name="", in=".in", out=".out";
#define J (")
#ifdef NALP_PROJECT
#pragma hdrstop
#else
#define _SECURE_SCL 0
#endif

#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:200000000")

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <utility>

#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <memory.h>

#include <iostream>
#include <sstream>

using namespace std;

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define y1 YYYYYYYYYYYY1
#define rall(a) (a).rbegin(), (a).rend()

template<typename T> inline T Abs(T x) { return (x >= 0) ? x : -x; }
template<typename T> inline T sqr(T x) { return x * x; }
template<typename T> string toStr(T x) { stringstream st; st << x; string s; st >> s; return s; }

const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const long double EPS = 1E-9;
const long double PI = 3.1415926535897932384626433832795;

const int MAXN = 100100;
const int LOG = 17;

struct range {
	int x, y1, y2;
	range(int x = 0, int y1 = 0, int y2 = 0) : x(x), y1(y1), y2(y2) {}
};

struct persistenttree {
	struct node {
		node * lf, * rg;
		int value, len;

		node(int len) {
			this->len = len;
			lf = rg = 0;
			value = 0;
		}
	};

	vector<pair<int, node *> > versions;
	int size;

	node * build(int l, int r) {
		node * v = new node(r - l + 1);
		if (l != r) {
			int mid = (l + r) >> 1;
			v->lf = build(l, mid);
			v->rg = build(mid + 1, r);
		}

		return v;
	}

	void build(int size) {
		this->size = size;
		versions.pb(mp(-INF, build(0, size - 1)));
	}

	node * update(node * v, int l, int r, int x) {
		if (x < l || x > r)
			return v;

		node * ans = new node(r - l + 1);
		ans->value = 1;
		if (l != r) {
			int mid = (l + r) >> 1;
			ans->lf = update(v->lf, l, mid, x);
			ans->rg = update(v->rg, mid + 1, r, x);
			ans->value = ans->lf->value + ans->rg->value;
		}

		return ans;
	}
	
	void update(int x, int time) {
		node * root = versions.back().second;
		versions.pb(mp(time, update(root, 0, size - 1, x)));
	}

	int get(node * v, node * old, int l, int r, int ll, int rr) {
		if (l > rr || ll > r || ll > rr) return 0;
		if (ll <= l && r <= rr) return v->value - old->value;

		int mid = (l + r) >> 1;
		return get(v->lf, old->lf, l, mid, ll, rr) + get(v->rg, old->rg, mid + 1, r, ll, rr);
	}

	int get(int l, int r, int time) {
		int pos = (int)(lower_bound(all(versions), mp(time + 1, (node *)0)) - versions.begin() - 1);
		return r - l + 1 - get(versions.back().second, versions[pos].second, 0, size - 1, l, r);
	}

	int find_k_zero(node * v, node * old, int l, int r, int k) {
		if (l == r) return l;
		int mid = (l + r) >> 1;
		int lzero = v->lf->len - (v->lf->value - old->lf->value);
		if (lzero > k)
			return find_k_zero(v->lf, old->lf, l, mid, k);
		else
			return find_k_zero(v->rg, old->rg, mid + 1, r, k - lzero);
	}

	int find(int y1, int k, int time) {
		int pos = (int)(lower_bound(all(versions), mp(time + 1, (node *)0)) - versions.begin() - 1);
		int before = y1 - get(versions.back().second, versions[pos].second, 0, size - 1, 0, y1 - 1);
		return find_k_zero(versions.back().second, versions[pos].second, 0, size - 1, before + k);
	}
};

int n, m, root, d[MAXN], x[MAXN], y[MAXN], hls;
int tin[MAXN], tout[MAXN], T = 0;
vector<int> g[MAXN], hl[MAXN];
persistenttree tree[MAXN];
int next[LOG][MAXN];

int get(int v) {
	int &ans = d[v];
	if (ans != -1) return ans;

	ans = 1;
	forn(i, g[v].size())
		ans += get(g[v][i]);

	return ans;
}

void build(int v, int pos) {
	x[v] = pos;
	y[v] = (int)hl[pos].size();
	hl[pos].pb(v);
	forn(i, g[v].size()) {
		int u = g[v][i];
		if (get(u) * 2 > get(v))
			build(u, pos);
		else {
			hls++;
			build(u, hls - 1);
		}
	}
}

void DFS(int v, int prev) {
	tin[v] = T++;
	next[0][v] = prev;
	for(int i = 1; i < LOG; i++)
		next[i][v] = next[i - 1][next[i - 1][v]];

	forn(i, g[v].size())
		DFS(g[v][i], v);

	tout[v] = T++;
}

bool isprev(int v, int u) {
	return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int getLCA(int v, int u) {
	if (isprev(v, u)) return v;
	if (isprev(u, v)) return u;

	ford(i, LOG)
		if (!isprev(next[i][u], v))
			u = next[i][u];

	return next[0][u];
}

void update(int v, int time) {
	tree[x[v]].update(y[v], time);
}

vector<range> getPath(int v, int u) {
	vector<range> ans;
	while (x[v] != x[u]) {
		ans.pb(range(x[v], 0, y[v]));
		v = next[0][ hl[x[v]][0] ];
	}

	ans.pb(range(x[v], y[u], y[v]));
	return ans;
}

int solve(int v, int u, int k, int y) {
	int lca = getLCA(v, u);
	vector<range> p1 = getPath(v, lca);
	vector<range> p2 = getPath(u, lca);

	p1[0].y2--;
	if (lca == u) p1.back().y1++;
	forn(i, p1.size()) {
		range r = p1[i];
		if (r.y1 <= r.y2) {
			int cur = tree[r.x].get(r.y1, r.y2, y);
			if (cur <= k)
				k -= cur;
			else {
				int yy = tree[r.x].find(r.y1, cur - k - 1, y);
				return hl[r.x][yy];
			}
		}
	}

	p2[0].y2--;
	p2.back().y1++;
	ford(i, p2.size()) {
		range r = p2[i];
		if (r.y1 <= r.y2) {
			int cur = tree[r.x].get(r.y1, r.y2, y);
			if (cur <= k)
				k -= cur;
			else {
				int yy = tree[r.x].find(r.y1, k, y);
				return hl[r.x][yy];
			}
		}
	}

	return -2;
}
#define read read2
int main() {
	read(n);
	memset(d, 255, sizeof d);
	forn(u, n) {
		int v;
		read(v);
		v--;

		if (v == -1)
			root = u;
		else
			g[v].pb(u);
	}

	hls = 1;
	build(root, 0);
	DFS(root, root);

	forn(i, hls)
		tree[i].build((int)hl[i].size());

	read(m);
	forn(i, m) {
		int type;
		read(type);
		if (type == 1) {
			int v;
			read(v);
			update(v - 1, i);
		} else {
			int v, u, k, y;
			read(v), read(u), read(k), read(y);
			printf("%d\n", 1 + solve(v - 1, u - 1, k - 1, y - 1));
		}
	}
	return 0;
}


