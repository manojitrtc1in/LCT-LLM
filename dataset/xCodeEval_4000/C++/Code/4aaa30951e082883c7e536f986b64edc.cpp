

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
#include <complex.h>
#include <fenv.h>
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

int n;
struct sq
{
	int x1, y1, x2, y2;
};
vector<sq> R;


int X, Y;
map<int, int> mx, my;
int xm[2018], ym[2018];


int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
bool ziw[2007][2007], lgl[2007][2007];
INT ans;

void dfs(int x,int y)
{
	if(x<0||x>=X||y<0||y>=Y||ziw[x][y]||lgl[x][y])
		return;
	lgl[x][y] = 1;
	FOR(i,4)
		dfs(x + dx[i], y + dy[i]);
}

int main()
{
	cin >> n;
	int x = 0, y = 0;
	FOR(i,n)
	{
		string dir;
		int d;
		cin >> dir >> d;
		if(dir=="L")
		{
			sq bb = {x - d, y, x + 1, y + 1};
			R.push_back(bb);
			x -= d;
		}
		if(dir=="R")
		{
			sq bb = {x, y, x + d + 1, y + 1};
			R.push_back(bb);
			x += d;
		}
		if(dir=="U")
		{
			sq bb = {x, y, x + 1, y + d + 1};
			R.push_back(bb);
			y += d;
		}
		if(dir=="D")
		{
			sq bb = {x, y - d, x + 1, y + 1};
			R.push_back(bb);
			y -= d;
		}
	}
	FOR(i,n)
	{
		mx[R[i].x1] = mx[R[i].x2] = 0;
		my[R[i].y1] = my[R[i].y2] = 0;
	}
	foreach(it,mx)
	{
		it->second = X;
		xm[X] = it->first;
		X++;
	}
	X--;
	foreach(it,my)
	{
		it->second = Y;
		ym[Y] = it->first;
		Y++;
	}
	Y--;
	FOR(i,n)
	{
		int x1 = mx[R[i].x1], y1 = my[R[i].y1], x2 = mx[R[i].x2], y2 = my[R[i].y2];
		FFOR(j,x1,x2)
			FFOR(k,y1,y2)
				ziw[j][k] = 1;
	}
	FOR(i,X)
		FOR(j,Y)
			if(i==0||i==X-1||j==0||j==Y-1)
				dfs(i, j);
	FOR(i,X)
		FOR(j,Y)
			if(!lgl[i][j])
			{
				INT disx = xm[i + 1] - xm[i], disy = ym[j + 1] - ym[j];
				ans += disx * disy;
			}
	cout << ans << endl;
	return 0;
}