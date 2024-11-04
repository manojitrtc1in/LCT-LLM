

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
#define Mod 1000003
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





char ins[2007],s[2007];
int szins,n=0;
int num[2007],pos[2007],cntnum=0;
int chr[2007],cpos[2007],cntchr=0;
int dp[2007][2007];

inline bool jiajian(char c){return c=='+'||c=='-';}
inline bool chengchu(char c){return c=='*'||c=='/';}
inline bool jjcc(char c){return jiajian(c)||chengchu(c);}

int main()
{
	scanf("%s",ins+1);
	ins[0]='+';
	szins=strlen(ins);
	if(!isdigit(ins[szins-1]))
		OVER("0");
	for(int i=0;i<szins-1;i++)
		if(jjcc(ins[i])&&chengchu(ins[i+1]))
			OVER("0");
	FILL1(num);
	FILL1(chr);
	for(int i=0;i<szins;i++)
	{
		if(i&&isdigit(ins[i-1])&&isdigit(ins[i]))continue;
		if(isdigit(ins[i]))s[n]='0',num[n]=cntnum,pos[cntnum]=n,n++,cntnum++;
		else s[n]=ins[i],chr[n]=cntchr,cpos[cntchr]=n,n++,cntchr++;
	}
	for(int i=1;i<n;i++)
		if(num[i]!=-1)
			dp[chr[i-1]][num[i]]=1;
	INT fxck;
	for(int i=cntchr-1;i>=0;i--)
		for(int j=0;j<cntnum;j++)
		{
			if(pos[j]<=cpos[i]+1)continue;
			if(jjcc(s[cpos[i]+1]))
				dp[i][j]=dp[i+1][j];
			else
				dp[i][j]=0;
			fxck=0;
			for(int k=j-1;pos[k]>cpos[i]&&k>=0;k--)
				fxck+=(INT)dp[i][k]*dp[chr[pos[k]+1]][j];
			dp[i][j]=(dp[i][j]+fxck)%Mod;
		}
	OVER("%d\n",dp[0][cntnum-1]);
}