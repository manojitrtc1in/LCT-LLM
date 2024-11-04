

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





struct segtree
{
	INT dt[1600007];
	INT wp[1600007];
	int len;
	void turn(int now,int to,int nl,int nr,INT num)
	{
		dt[now]+=wp[now]*(nr-nl+1);
		wp[now*2]+=wp[now];
		wp[now*2+1]+=wp[now];
		wp[now]=0;
		if(nl>to||nr<to)return;
		if(nl==to&&nr==to)
		{
			dt[now]=num;
			return;
		}
		int m=(nl+nr)>>1;
		turn(now<<1,to,nl,m,num);
		turn(now<<1|1,to,m+1,nr,num);
		dt[now]=dt[now*2]+dt[now*2+1];
	}
	void plus(int now,int l,int r,int nl,int nr,INT num)
	{
		dt[now]+=wp[now]*(nr-nl+1);
		wp[now*2]+=wp[now];
		wp[now*2+1]+=wp[now];
		wp[now]=0;
		if(nl>r||nr<l)return;
		if(nl>=l&&nr<=r)
		{
			dt[now]+=num*(nr-nl+1);
			wp[now*2]+=num;
			wp[now*2+1]+=num;
			return;
		}
		int m=(nl+nr)>>1;
		plus(now<<1,l,r,nl,m,num);
		plus(now<<1|1,l,r,m+1,nr,num);
		dt[now]=dt[now*2]+dt[now*2+1];
	}
	INT sum(int now,int l,int r,int nl,int nr)
	{
		dt[now]+=wp[now]*(nr-nl+1);
		wp[now*2]+=wp[now];
		wp[now*2+1]+=wp[now];
		wp[now]=0;
		if(nl>r||nr<l)return 0;
		if(nl>=l&&nr<=r)
			return dt[now];
		int m=(nl+nr)>>1;
		return sum(now<<1,l,r,nl,m)+sum(now<<1|1,l,r,m+1,nr);
	}
}sg;

int n;

int main()
{
	sg.len=1;
	n=read();
	int mode;
	for(int i=0;i<n;i++)
	{
		mode=read();
		if(mode==1)
		{
			int a=read();
			INT b=READ();
			sg.plus(1,1,a,1,200007,b);
		}
		else if(mode==2)
		{
			INT a=READ();
			sg.len++;
			sg.turn(1,sg.len,1,200007,a);
		}
		else
		{
			sg.turn(1,sg.len,1,200007,0);
			sg.len--;
		}
		printf("%.10lf\n",1.00*sg.sum(1,1,sg.len,1,200007)/sg.len);
	}
	return 0;
}