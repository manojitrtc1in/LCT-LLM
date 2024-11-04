

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





int dpa[57][57],dpb[57][57],dp[57][57];
int trn[27][27];
int k;
string A,B;
string s;
int a[57],b[57];

int main()
{
	cin>>A>>B;
	int n=SZ(A),m=SZ(B);
	for(int i=1;i<=n;i++)
	{
		a[i]=A[i-1]-'a';
		dpa[i][i]|=MASK(a[i]);
	}
	for(int j=1;j<=m;j++)
	{
		b[j]=B[j-1]-'a';
		dpb[j][j]|=MASK(b[j]);
	}
	cin>>k;
	for(int i=0;i<k;i++)
	{
		cin>>s;
		trn[s[3]-'a'][s[4]-'a']|=MASK(s[0]-'a');
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<26;j++)
			if(BIT(trn[a[i]][a[i+1]],j))
				dpa[i][i+1]|=MASK(j);
	for(int i=1;i<=m;i++)
		for(int j=0;j<26;j++)
			if(BIT(trn[b[i]][b[i+1]],j))
				dpb[i][i+1]|=MASK(j);
	

	for(int len=3;len<=n;len++)
		for(int i=1;i<=n-len+1;i++)
		{
			int j=i+len-1;
			for(int k=i;k<j;k++)
				for(int l1=0;l1<26;l1++)if(BIT(dpa[i][k],l1))
					for(int l2=0;l2<26;l2++)if(BIT(dpa[k+1][j],l2))
						dpa[i][j]|=trn[l1][l2];
		}
	for(int len=3;len<=m;len++)
		for(int i=1;i<=m-len+1;i++)
		{
			int j=i+len-1;
			for(int k=i;k<j;k++)
				for(int l1=0;l1<26;l1++)if(BIT(dpb[i][k],l1))
					for(int l2=0;l2<26;l2++)if(BIT(dpb[k+1][j],l2))
						dpb[i][j]|=trn[l1][l2];
		}
	

	FILLBIG(dp);
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int a=0;a<i;a++)
				for(int b=0;b<j;b++)
					if(dpa[a+1][i]&dpb[b+1][j])
						dp[i][j]=min(dp[i][j],dp[a][b]+1);
	if(dp[n][m]==Inf)OVER("-1");
	else OVER("%d\n",dp[n][m]);
	return 0;
}