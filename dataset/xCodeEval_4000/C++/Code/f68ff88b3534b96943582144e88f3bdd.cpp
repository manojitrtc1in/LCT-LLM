

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







vector<int> nei[100007];
map<pii, int> xub;
int par[27][100007];
int dep[100007];

void dfs(int v,int p,int d)
{
	par[0][v] = p;
	dep[v] = d;
	for (int i = 0; i < SZ(nei[v]); i++)if(nei[v][i]!=p)
			dfs(nei[v][i], v, d + 1);
}



void init(int all)
{
	dfs(1, -1, 0);
	for (int i = 0; i + 1 < 27; i++)
		for (int j = 1; j <= all; j++)
			if(par[i][j]<0)
				par[i + 1][j] = -1;
			else
				par[i + 1][j] = par[i][par[i][j]];
}



int lca(int a,int b)
{
	if(dep[a]>dep[b])
		swap(a, b);
	for (int i = 0; i < 27; i++)
		if ((dep[a] - dep[b]) >> i & 1)
			b = par[i][b];
	if(a==b)
		return a;
	for (int i = 26; i >= 0; i--)
		if(par[i][a]!=par[i][b])
		{
			a = par[i][a];
			b = par[i][b];
		}
	return par[0][a];
}



int gao1[100007], gao2[100007], gao3[100007];
int n, k;

void killxu(int v,int p)
{
	int sum = gao1[v];
	for (int i = 0; i < SZ(nei[v]); i++)
		if(nei[v][i]!=p)
		{
			killxu(nei[v][i], v);
			sum += gao2[nei[v][i]];
		}
	gao2[v] = sum;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		nei[a].pb(b);
		nei[b].pb(a);
		xub[mp(a, b)] = i;
		xub[mp(b, a)] = i;
	}
	init(n);
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		gao1[a]++;
		gao1[b]++;
		gao1[lca(a, b)] -= 2;
	}
	killxu(1, -1);
	for (int i = 2; i <= n; i++)
		gao3[xub[mp(i, par[0][i])]] = gao2[i];
	for (int i = 0; i < n - 1; i++)
		printf("%d%c", gao3[i], i == n - 2 ? '\n' : ' ');
	return 0;
}