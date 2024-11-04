

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



int n, m, d, r;
int x[307], y[307];
char s[1007][1007];
int filled[1007][1007];

queue<int> q;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
bool used[20][20];

vpii neigh(int xx,int yy)
{
    vpii ans;
    for (int i = 10 - d; i <= 10 + d; i++)
        for (int j = 10 - d; j <= 10 + d; j++)
            used[i][j] = 0;
    
    q.push(xx);
    q.push(yy);
    q.push(0);
    used[10][10] = 1;
    
    while(SZ(q))
    {
        int mx = q.front();
        q.pop();
        int my = q.front();
        q.pop();
        int mz = q.front();
        q.pop();

        ans.pb(mp(mx, my));
        if(mz+1<=d)
            for (int i = 0; i < 4; i++)
            {
                int nx = mx + dx[i], ny = my + dy[i];
                if(s[nx][ny]!='X'&&!used[nx-xx+10][ny-yy+10])
                {
                    q.push(nx);
                    q.push(ny);
                    q.push(mz + 1);
                    used[nx - xx + 10][ny - yy + 10] = 1;
                }
            }
    }
    return ans;
}

void fillneigh(int xx,int yy,int val)
{
    vpii ans;
    for (int i = 10 - d; i <= 10 + d; i++)
        for (int j = 10 - d; j <= 10 + d; j++)
            used[i][j] = 0;
    
    q.push(xx);
    q.push(yy);
    q.push(0);
    used[10][10] = 1;
    
    while(SZ(q))
    {
        int mx = q.front();
        q.pop();
        int my = q.front();
        q.pop();
        int mz = q.front();
        q.pop();

        filled[mx][my] += val;
        if(mz+1<=d)
            for (int i = 0; i < 4; i++)
            {
                int nx = mx + dx[i], ny = my + dy[i];
                if(s[nx][ny]!='X'&&!used[nx-xx+10][ny-yy+10])
                {
                    q.push(nx);
                    q.push(ny);
                    q.push(mz + 1);
                    used[nx - xx + 10][ny - yy + 10] = 1;
                }
            }
    }
}

bool check()
{
    for (int i = 0; i < r; i++)
        if(!filled[x[i]][y[i]])
            return 0;
    return 1;
}

bool func(int xx,int yy)
{
    vpii poss = neigh(xx, yy);
    fillneigh(xx, yy, 1);
    if(check())
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (i != xx && j != yy && s[i][j] != 'X')
                {
                    printf("%d %d %d %d\n", xx + 1, yy + 1, i + 1, j + 1);
                    return 1;
                }
    }
    int nextone;
    for (nextone = 0; nextone < r;nextone++)
        if(!filled[x[nextone]][y[nextone]])
            break;
    vpii npos = neigh(x[nextone], y[nextone]);
    for (int i = 0; i < SZ(npos);i++)
    {
        int mx = npos[i].first, my = npos[i].second;
        fillneigh(mx, my, 1);
        if(check())
        {
            printf("%d %d %d %d\n", xx + 1, yy + 1, mx + 1, my + 1);
            return 1;
        }
        fillneigh(mx, my, -1);
    }
    fillneigh(xx, yy, -1);
    return 0;
}

int main()
{
    #ifndef XUDADIAO
    filei("input.txt");
    fileo("output.txt");
    #endif
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 0; i < n;i++)
        scanf("%s", s[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if(s[i][j]=='R')
            {
                x[r] = i;
                y[r] = j;
                r++;
                if(r>300)
                    OVER("-1");
            }
    vpii bb = neigh(x[0], y[0]);
    for (int i = 0; i < SZ(bb);i++)
        if(func(bb[i].first, bb[i].second))
            return 0;
    OVER("-1");
}