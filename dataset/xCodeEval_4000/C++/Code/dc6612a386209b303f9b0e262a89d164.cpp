


#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <locale>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <wctype.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cerrno>
#include <clocale>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <limits>
#include <map>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <istream>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <utility>
#include <vector>
#include <cwchar>
#include <cwctype>
#include <numeric>
#include <list>
#define LL long long
#define pb push_back
#define pob pop_back
#define mp make_pair
#define FILL(a,v) memset((void*)a,v,sizeof(a))
#define FILL0(a) FILL(a,0)
#define FILL1(a) FILL(a,-1)
#define FILLBIG(a) FILL(a,0x3f)
#define ALL(a) (a).begin(),(a).end()
#define Inf ((int)0x3f3f3f3f)
#define INF ((long long)0x3f3f3f3f3f3f3f3f)
#define Mod 1000000007
#define foreach(it,x) for(__typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define FOR(i,x) for(int i=0;i<x;i++)
#define RFOR(i,x) for(int i=x-1;i>=0;i--)
#define FFOR(i,a,b) for(int i=a;i<b;i++)
#define FRFOR(i,a,b) for(int i=a-1;i>=b;i--)
#define SZ(a) ((int)(a).size())
#define FI first
#define SE second
#define OVER(...) return printf(__VA_ARGS__),0
#define fastio ios::sync_with_stdio(0)
#define filei(f) freopen(f,"r",stdin)
#define fileo(f) freopen(f,"w",stdout)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define MASK(a) (1<<(a))
#define MASKX(x,a) ((x)<<(a))
#define BIT(a,b) (((a)>>(b))&1)
#define cddx(a) priority_queue<a >
#define cxdd(a) priority_queue<a,vector<a >,greater<a > >
#define deval(a) {cerr<<#a<<" = "<<a<<endl;}
#define dearr(be,en) {cerr<<#be;cerr<<" = {";for(auto i=be;i!=en;i++)cerr<<' '<<*i;cerr<<" }\n";}
#define reg register
#define prtime eprintf("\n\nTime used: %dms\n",clock());
#define PI 3.1415926535897932384626
#define TODEG(a) (a*180/PI)
#define y0 ykangjimutigeidiqiuyipianjingtu
#define y1 yxiaomiexuduhuanrenleiwannianankang




using namespace std;
typedef pair<int,int> pii;
typedef unsigned long long UINT;
typedef unsigned int uint;
typedef long long INT;
typedef long double ldouble;
typedef pair<INT,INT> PII;
typedef stringstream sst;
typedef istringstream iss;
typedef vector<int> vint;
typedef vector<INT> VINT;
typedef vector<pii> vpii;
typedef vector<PII> VPII;
typedef priority_queue<int> pqi;
typedef priority_queue<INT> PQI;
typedef priority_queue<pii> pqp;
typedef priority_queue<PII> PQP;
typedef priority_queue<int,vint,greater<int> > xqi;
typedef priority_queue<INT,VINT,greater<INT> > XQI;
typedef priority_queue<pii,vpii,greater<pii> > xqp;
typedef priority_queue<PII,VPII,greater<PII> > XQP;
inline int read()
{
	int num=0;
	char c=getchar();
	if(c=='-')return -read();
	while(c>='0'&&c<='9')
	{
		num=(num<<3)+(num<<1)+c-'0';
		c=getchar();
	}
	return num;
}
inline INT READ()
{
	INT num=0;
	char c=getchar();
	if(c=='-')return -READ();
	while(c>='0'&&c<='9')
	{
		num=(num<<3)+(num<<1)+c-'0';
		c=getchar();
	}
	return num;
}





int l[200007],r[200007];
int deg[200007];
int tps[200007],tppppppppppfxxk;
vector<int> nei[200007],fnei[200007];
bool lgl[200007],lgl2[200007];
vector<int> dsf;
set<pii> ugl;
int n,m,k;
int rr[200007];
set<int> cnu;
int n1[200007];
int chs[200007];
queue<int> q;
priority_queue<pair<pii,int> > qb;
pair<pii,int> bb[200007];
bool FxxK(pair<pii,int> a,pair<pii,int> b){return a.first.second<b.first.second;}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",rr+i);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(!ugl.count(mp(a,b)))
		{
			nei[a].pb(b);
			fnei[b].pb(a);
		}
		deg[b]++;
	}
	for(int i=1;i<=n;i++)
		if(!deg[i])
			q.push(i);
	if(!SZ(q))OVER("-1");
	while(SZ(q))
	{
		int x=q.front();
		tps[x]=++tppppppppppfxxk;
		dsf.pb(x);
		q.pop();
		for(int i=0;i<SZ(nei[x]);i++)if(!tps[nei[x][i]])
		{
			deg[nei[x][i]]--;
			if(!deg[nei[x][i]])
				q.push(nei[x][i]);
		}
	}
	if(tppppppppppfxxk<n)OVER("-1");
	for(int ii=n-1;ii>=0;ii--)
	{
		int i=dsf[ii];
		int maxv=0;
		for(int j=0;j<SZ(nei[i]);j++)
			maxv=max(maxv,l[nei[i][j]]);
		if(rr[i])
		{
			if(rr[i]<=maxv)OVER("-1\n");
			l[i]=rr[i];
		}
		else l[i]=maxv+1;
	}
	for(int ii=0;ii<n;ii++)
	{
		int i=dsf[ii];
		int maxv=k+1;
		for(int j=0;j<SZ(fnei[i]);j++)
			maxv=min(maxv,r[fnei[i][j]]);
		if(rr[i])
		{
			if(rr[i]>=maxv)OVER("-1\n");
			r[i]=rr[i];
		}
		else r[i]=maxv-1;
	}
	for(int i=1;i<=n;i++)
		bb[i]=(mp(mp(-r[i],l[i]),i));
	sort(bb+1,bb+n+1,FxxK);
	int cur=1;
	

	

	

	

	for(int i=1;i<=k;i++)
	{
		while(cur<=n&&bb[cur].first.second==i)
		{
			qb.push(bb[cur]);
			cur++;
		}
		if(!SZ(qb))OVER("-1\n");
		bool deled=0;
		while(SZ(qb)&&qb.top().first.first==-i)
		{
			chs[qb.top().second]=i;
			qb.pop();
			deled=1;
		}
		if(!deled)
		{
			

			if(!SZ(qb))OVER("-1\n");
			chs[qb.top().second]=i;
			qb.pop();
		}
	}
	for(int i=1;i<=n;i++)if(!chs[i])OVER("-1");
	for(int i=1;i<=n;i++)
		printf("%d%c",chs[i],i==n?'\n':' ');
	return 0;
}
