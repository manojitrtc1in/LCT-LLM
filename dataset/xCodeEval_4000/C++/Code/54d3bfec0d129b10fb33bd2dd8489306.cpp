

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
#define Mod 1000000007
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





int dt[800007],gt[800007];
int a[100007];
int n,m;

void cccp()
{
	for(int i=0;i<800007;i++)
	{
		dt[i]=0;
		gt[i]=-1;
	}
}

void ypa(int now,int nl,int nr,int tt,int ji)
{
	if(nl==tt)dt[now]=ji;
	if(nl==tt&&nr==tt)return;
	int m=(nl+nr)/2;
	if(m>=tt)ypa(now*2,nl,m,tt,ji);
	else ypa(now*2+1,m+1,nr,tt,ji);
}

void cobet(int now,int nl,int nr,int l,int r,int frm)
{
	int m=(nl+nr)/2;
	if(gt[now]!=-1)
	{
		dt[now]=a[gt[now]];
		gt[now*2]=gt[now];
		gt[now*2+1]=gt[now]+m+1-nl;
		gt[now]=-1;
	}
	if(nr<l||nl>r)return;
	if(nl>=l)dt[now]=a[frm+nl-l];
	if(nl>=l&&nr<=r)
	{
		gt[now]=frm+nl-l;
		return;
	}
	cobet(now*2,nl,m,l,r,frm);
	cobet(now*2+1,m+1,nr,l,r,frm);
	dt[now]=dt[now*2];
}

int soviet(int now,int nl,int nr,int tt)
{
	int m=(nl+nr)/2;
	if(gt[now]!=-1)
	{
		dt[now]=a[gt[now]];
		gt[now*2]=gt[now];
		gt[now*2+1]=gt[now]+m+1-nl;
		gt[now]=-1;
	}
	if(nl==tt)return dt[now];
	if(m>=tt)return soviet(now*2,nl,m,tt);
	else return soviet(now*2+1,m+1,nr,tt);
}

int main()
{
	scanf("%d%d",&n,&m);
	cccp();
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=0;i<n;i++)
	{
		int num;
		scanf("%d",&num);
		ypa(1,0,n-1,i,num);
	}
	for(int i=0;i<m;i++)
	{
		int md;
		scanf("%d",&md);
		if(md==1)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			a--;b--;
			cobet(1,0,n-1,b,b+c-1,a);
		}
		else
		{
			int xx;
			scanf("%d",&xx);
			xx--;
			printf("%d\n",soviet(1,0,n-1,xx));
		}
	}
	return 0;
}