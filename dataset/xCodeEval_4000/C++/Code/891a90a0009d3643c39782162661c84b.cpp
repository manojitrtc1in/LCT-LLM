

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





string a,b;
int n;
int na,nb;
int tr[27][27][27];
int cnt[27][27];
int cana[57][57][27],canb[57][57][27];
int dp[57][57];



int main()
{
	cin>>a>>b;
	na=SZ(a);
	nb=SZ(b);
	cin>>n;
	string S;
	for(int i=0;i<n;i++)
	{
		cin>>S;
		tr[S[3]-'a'][S[4]-'a'][cnt[S[3]-'a'][S[4]-'a']++]=S[0]-'a';
	}
	for(int i=0;i<na;i++)
		cana[i][i][a[i]-'a']=1;
	for(int l=2;l<=na;l++)
		for(int i=0;i<=na-l;i++)
		{
			int j=i+l-1;
			for(int k=i;k<j;k++)
				for(int l1=0;l1<26;l1++)
					if(cana[i][k][l1])
						for(int l2=0;l2<26;l2++)
							if(cana[k+1][j][l2])
								for(int I=0;I<cnt[l1][l2];I++)
									cana[i][j][tr[l1][l2][I]]=1;
		}
	for(int i=0;i<nb;i++)
		canb[i][i][b[i]-'a']=1;
	for(int l=2;l<=nb;l++)
		for(int i=0;i<=nb-l;i++)
		{
			int j=i+l-1;
			for(int k=i;k<j;k++)
				for(int l1=0;l1<26;l1++)
					if(canb[i][k][l1])
						for(int l2=0;l2<26;l2++)
							if(canb[k+1][j][l2])
								for(int I=0;I<cnt[l1][l2];I++)
									canb[i][j][tr[l1][l2][I]]=1;
		}
	FILLBIG(dp);
	for(int i=0;i<na;i++)
		for(int j=0;j<nb;j++)
			for(int c=0;c<26;c++)
			{
				if(cana[0][i][c]&&canb[0][j][c])
					dp[i][j]=1;
				for(int k=1;k<=i;k++)
					if(cana[k][i][c])
						for(int l=1;l<=j;l++)
							if(canb[l][j][c])
								dp[i][j]=min(dp[i][j],dp[k-1][l-1]+1);
			}
	if(dp[na-1][nb-1]==Inf)OVER("-1");
	else OVER("%d\n",dp[na-1][nb-1]);
	return 0;
}