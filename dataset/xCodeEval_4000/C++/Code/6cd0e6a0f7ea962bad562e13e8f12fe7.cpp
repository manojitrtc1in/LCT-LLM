

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





INT dt[1600007];
int n;
INT wp[1600007];
char inp[107];


void pls(int djg,int l,int r,int nl,int nr,int num)
{
	

	wp[djg*2]+=wp[djg];
	wp[djg*2+1]+=wp[djg];
	dt[djg*2]+=wp[djg];
	dt[djg*2+1]+=wp[djg];
	wp[djg]=0;
	if(nl>=l&&nr<=r)
	{
		

		dt[djg]+=num;
		wp[djg]+=num;
		return;
	}
	if(nr<=l||nl>=r)return;

	pls(djg*2,l,r,nl,(nl+nr)/2,num);
	pls(djg*2+1,l,r,(nl+nr)/2,nr,num);
	dt[djg]=min(dt[djg*2],dt[djg*2+1]);
}

INT find(int djg,int l,int r,int nl,int nr)
{
	

	wp[djg*2]+=wp[djg];
	wp[djg*2+1]+=wp[djg];
	dt[djg*2]+=wp[djg];
	dt[djg*2+1]+=wp[djg];
	wp[djg]=0;
	

	if(nl>=l&&nr<=r)return dt[djg];

	if(nr<=l||nl>=r)return INF;
	return min(find(djg*2,l,r,nl,(nl+nr)/2),find(djg*2+1,l,r,(nl+nr)/2,nr));
}

void INC(int a,int b,int c)
{
	if(a<=b)pls(1,a,b+1,0,n,c);
	else
	{
		pls(1,0,b+1,0,n,c);
		pls(1,a,n,0,n,c);
	}
}

INT RMQ(int a,int b)
{
	if(a<=b)return find(1,a,b+1,0,n);
	else return min(find(1,0,b+1,0,n),find(1,a,n,0,n));
}

int main()
{
	scanf("%d",&n);
	FILLBIG(dt);
	for(int i=0;i<n;i++)
	{
		int xx;
		scanf("%d",&xx);
		int l=0,r=n,m,mm=1;
		if(r-l==1)dt[mm]=xx;
		while(r-l>1)
		{
			m=(l+r)/2;
			if(m>i)r=m,mm=mm*2;
			else if(m<=i)l=m,mm=mm*2+1;
			if(r-l==1)dt[mm]=xx;
		}
		while(mm>1)
		{
			mm/=2;
			dt[mm]=min(dt[mm*2],dt[mm*2+1]);
		}
	}
	

	int q;
	scanf("%d",&q);
	gets(inp);
	while(q--)
	{
		gets(inp);
		int x,y,z;
		if(sscanf(inp,"%d%d%d",&x,&y,&z)==3)
			INC(x,y,z);
		else
		{
			sscanf(inp,"%d%d",&x,&y);
			printf("%I64d\n",RMQ(x,y));
		}
	}
	return 0;
}