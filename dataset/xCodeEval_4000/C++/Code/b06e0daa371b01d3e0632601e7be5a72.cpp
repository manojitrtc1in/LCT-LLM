



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





INT dp[100007],dp2[100007];
INT MAXV=314000000;
int lgl[100007];
vector<vint> fl[100007];
bool hwam[100007];

void uwm(INT& a)
{if(a>MAXV)a=MAXV;}


INT dfsmin(int now)
{
	if(lgl[now]==1)
		hwam[now]=1;
	if(lgl[now]==2)
		return -1;
	if(dp[now]!=Inf)return dp[now];
	lgl[now]++;
	for(int i=0;i<SZ(fl[now]);i++)
	{
		INT ans=0;
		bool hwww=hwam[now];
		for(int j=0;j<SZ(fl[now][i]);j++)
		{
			INT nowans;
			if(fl[now][i][j]==-1)nowans=1;
			else nowans=dfsmin(fl[now][i][j]);
			if(nowans==-1)
			{
				ans=-1;
				break;
			}
			ans+=nowans;
			uwm(ans);
		}
		if(ans!=-1)
		{
			uwm(ans);
			if(dp[now]==-1)dp[now]=ans;
			else dp[now]=min(dp[now],ans);
		}
		else hwam[now]=hwww;
	}
	lgl[now]--;
	if(dp[now]==Inf)return dp[now]=-1;
	else return dp[now];
}

INT dfsmax(int now)
{
	if(lgl[now]==2)
		return -1;
	if(dp2[now]!=-Inf)return dp2[now];
	lgl[now]++;
	for(int i=0;i<SZ(fl[now]);i++)
	{
		INT ans=0;
		for(int j=0;j<SZ(fl[now][i]);j++)
		{
			INT nowans;
			if(fl[now][i][j]==-1)nowans=1;
			else nowans=dfsmax(fl[now][i][j]);
			if(nowans==-2)
				ans=-2;
			else if(nowans==-1)
			{
				ans=-1;
				break;
			}
			if(ans!=-2)ans+=nowans;
			uwm(ans);
		}
		if(ans!=-1&&ans!=-2)
		{
			uwm(ans);
			if(dp2[now]!=-2)dp2[now]=max(dp2[now],ans);
		}
		else if(ans==-2)dp2[now]=-2;
	}
	lgl[now]--;
	if(hwam[now])
	{
		if(dp[now]!=-1)return dp2[now]=-2;
		else return dp2[now]=-1;
	}
	if(dp2[now]==-Inf)
		return dp2[now]=-1;
	return dp2[now];
}

int n,m;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		fl[a].pb(vector<int>(b));
		for(int j=0;j<b;j++)
			scanf("%d",&fl[a][SZ(fl[a])-1][j]);
	}
	FILL0(lgl);
	FILL0(hwam);
	for(int i=0;i<100007;i++)dp[i]=Inf;
	for(int i=1;i<=m;i++)
		if(dp[i]==Inf)
			dfsmin(i);
	FILL0(lgl);
	for(int i=0;i<100007;i++)dp2[i]=-Inf;
	for(int i=1;i<=m;i++)
		if(dp2[i]==-Inf)
			dfsmax(i);
	#ifdef XUDADIAO
	for(int i=1;i<=m;i++)
		printf("%lld %lld\n",dp[i],dp2[i]);
	#else
	for(int i=1;i<=m;i++)
		printf("%I64d %I64d\n",dp[i],dp2[i]);
	#endif
	return 0;
}