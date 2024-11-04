

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
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <tgmath.h>
#include <numeric>
#include <list>
#define LL long long
#define pb push_back
#define pob pop_back
#define mp make_pair
#define FILL(a,v) memset((void*)a,v,sizeof(a))
#define FILL0(a) FILL(a,0)
#define FILL1(a) FILL(a,-1)
#define FILLBIG(a) FILL(a,0x7f)
#define ALL(a) (a).begin(),(a).end()
#define Inf ((int)0x7f7f7f7f)
#define INF ((long long)0x7f7f7f7f7f7f7f7f)
#define Mod 1000000000
#define foreach(it,x) for(__typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define FOR(i,x) for(int i=0;i<x;i++)
#define RFOR(i,x) for(int i=x-1;i>=0;i--)
#define FFOR(i,a,b) for(int i=a;i<b;i++)
#define FRFOR(i,a,b) for(int i=a-1;i>=b;i--)
#define SZ(a) ((int)(a).size())
#define FI first
#define SE second
#define OVER(a) return puts(a),0
#define fastio ios::sync_with_stdio(0)
#define filei(f) freopen(f,"r",stdin)
#define fileo(f) freopen(f,"w",stdout)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define MASK(a) (1<<(a))
#define MASKX(x,a) ((x)<<(a))
#define BIT(a,b) ((a>>b)&1)
#define cddx(a) priority_queue<a >
#define cxdd(a) priority_queue<a,vector<a >,greater<a > >
#define deval(a) {cerr<<#a<<" = "<<a<<endl;}
#define dearr(be,en) {cerr<<#be;cerr<<" = {";for(auto i=be;i!=en;i++)cerr<<' '<<*i;cerr<<" }\n";}
#define reg register
#define prtime eprintf("\n\nTime used: %dms\n",clock());
#define PI 3.1415926535897932384626
#define TODEG(a) (a*180/PI)




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








inline int readint()
{
	int num=0;
	char c=getchar();
	while(c>='0'&&c<='9')
	{
		num=(num<<3)+(num<<1)+c-'0';
		c=getchar();
	}
	return num;
}

struct matrix
{
	int m[2][2];
	inline matrix(){}
	inline matrix(int a){m[0][0]=m[0][1]=m[1][0]=m[1][1]=a;}
	inline matrix(int a,int b,int c,int d)
	{
		m[0][0]=a;
		m[0][1]=b;
		m[1][0]=c;
		m[1][1]=d;
	}
	inline matrix(int a,int b)
	{
		m[0][0]=a;
		m[1][0]=b;
	}
};

inline matrix Plus(const matrix& a,const matrix& b,int mode)

{
	if(mode==2)return matrix((a.m[0][0]+b.m[0][0])%Mod,(a.m[0][1]+b.m[0][1])%Mod,(a.m[1][0]+b.m[1][0])%Mod,(a.m[1][1]+b.m[1][1])%Mod);
	else return matrix((a.m[0][0]+b.m[0][0])%Mod,(a.m[1][0]+b.m[1][0])%Mod);
}

inline void Plusto(matrix& a,const matrix& b,int mode)

{
	if(mode==2)
	{
		a.m[0][0]=(a.m[0][0]+b.m[0][0])%Mod;
		a.m[0][1]=(a.m[0][1]+b.m[0][1])%Mod;
		a.m[1][0]=(a.m[1][0]+b.m[1][0])%Mod;
		a.m[1][1]=(a.m[1][1]+b.m[1][1])%Mod;
	}
	else
	{
		a.m[0][0]=(a.m[0][0]+b.m[0][0])%Mod;
		a.m[1][0]=(a.m[1][0]+b.m[1][0])%Mod;
	}
}

inline matrix times(const matrix& a,const matrix& b,int mode)

{
	if(mode==2)return matrix((1LL*a.m[0][0]*b.m[0][0]+1LL*a.m[0][1]*b.m[1][0])%Mod,
							(1LL*a.m[0][0]*b.m[0][1]+1LL*a.m[0][1]*b.m[1][1])%Mod,
							(1LL*a.m[1][0]*b.m[0][0]+1LL*a.m[1][1]*b.m[1][0])%Mod,
							(1LL*a.m[1][0]*b.m[0][1]+1LL*a.m[1][1]*b.m[1][1])%Mod);
	else return matrix((1LL*a.m[0][0]*b.m[0][0]+1LL*a.m[0][1]*b.m[1][0])%Mod,
						(1LL*a.m[1][0]*b.m[0][0]+1LL*a.m[1][1]*b.m[1][0])%Mod);
}

matrix fibs[200007]={matrix(1,0,0,1),matrix(1,1,1,0)},fibq[200007]={matrix(0),matrix(1,0,0,1)};
matrix dt[2000007],ic[2000007];

int n,k;

inline void LiSimon()
{
	for(int i=2;i<200007;i++)
		fibs[i]=times(fibs[i-1],fibs[1],2);
	for(int i=2;i<200007;i++)
		fibq[i]=Plus(fibq[i-1],fibs[i-1],2);
}

inline void YangAnnie(int now,int nl,int nr,int djg,int what)
{
	int m=(nl+nr)>>1;
	

	if(ic[now].m[0][0])
	{
		Plusto(dt[now<<1],times(fibq[m-nl+1],ic[now],1),1);
		Plusto(dt[now<<1|1],times(fibq[nr-m],ic[now],1),1);
		Plusto(ic[now<<1],ic[now],1);
		Plusto(ic[now<<1|1],ic[now],1);
		ic[now].m[0][0]=0;
	}
	

	if(nl==djg&&nr==djg)
	{
		dt[now].m[0][0]=what;
		return;
	}
	if(m>=djg)YangAnnie(now<<1,nl,m,djg,what);
	else YangAnnie(now<<1|1,m+1,nr,djg,what);
	dt[now]=Plus(times(fibs[m-nl+1],dt[now<<1|1],1),dt[now<<1],1);
}

inline matrix YanZack(int now,int nl,int nr,int l,int r)
{
	int m=(nl+nr)>>1;
	if(ic[now].m[0][0])
	{
		Plusto(dt[now<<1],times(fibq[m-nl+1],ic[now],1),1);
		Plusto(dt[now<<1|1],times(fibq[nr-m],ic[now],1),1);
		Plusto(ic[now<<1],ic[now],1);
		Plusto(ic[now<<1|1],ic[now],1);
		ic[now]=matrix(0,0);
	}
	if(nl>r||nr<l)return matrix(0);
	

	if(nl>=l&&nr<=r)
	{
		return times(fibs[nl-l],dt[now],1);
	}
	return Plus(YanZack(now<<1,nl,m,l,r),YanZack(now<<1|1,m+1,nr,l,r),1);
}

inline void SunSandy(int now,int nl,int nr,int l,int r,int what)

{
	int m=(nl+nr)>>1;
	if(ic[now].m[0][0])
	{
		Plusto(dt[now<<1],times(fibq[m-nl+1],ic[now],1),1);
		Plusto(dt[now<<1|1],times(fibq[nr-m],ic[now],1),1);
		Plusto(ic[now<<1],ic[now],1);
		Plusto(ic[now<<1|1],ic[now],1);
		ic[now].m[0][0]=0;
	}
	if(nl>r||nr<l)return;
	

	if(nl>=l&&nr<=r)
	{
		ic[now].m[0][0]=what;
		Plusto(dt[now],times(fibq[nr-nl+1],ic[now],1),1);
		return;
	}
	SunSandy(now<<1,nl,m,l,r,what);
	SunSandy(now<<1|1,m+1,nr,l,r,what);
	dt[now]=Plus(times(fibs[m-nl+1],dt[now<<1|1],1),dt[now<<1],1);
}

inline void LiAmy()
{
	int a=readint(),b=readint();
	a--,b--;
	printf("%d\n",YanZack(1,0,n-1,a,b).m[0][0]);
}

inline void SunTom()
{
	int a=readint(),b=readint(),c=readint();
	a--,b--;
	SunSandy(1,0,n-1,a,b,c);
}

inline void ZhuMary()
{
	int a=readint(),b=readint();
	a--;
	YangAnnie(1,0,n-1,a,b);
}

inline void XuanAlex()
{
	n=readint();
	k=readint();
	for(int i=0;i<n;i++)
	{
		int a=readint();
		YangAnnie(1,0,n-1,i,a);
	}
	for(int i=0;i<k;i++)
	{
		int mode=readint();
		if(mode==1)ZhuMary();
		else if(mode==2)LiAmy();
		else SunTom();
	}
}

int main()

{
	#ifdef XUDADIAO
	freopen("R:/TEMP/Xu13virus.out","r",stdin);
	freopen("R:/TEMP/Xudu.out","w",stdout);
	#endif
	LiSimon();
	XuanAlex();
	#ifdef XUDADIAO
	prtime;
	#endif
	return 0;
}