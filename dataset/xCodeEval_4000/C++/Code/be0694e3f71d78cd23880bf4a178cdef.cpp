

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




const int MAXN=400007;



struct matrix
{
    vector<vector<INT> > _Matrix;
    matrix(){}
    matrix(int x,int y){_Matrix=vector<vector<INT> >(x,vector<INT>(y));}
    void resize(int x,int y){_Matrix=vector<vector<INT> >(x,vector<INT>(y));}
    vector<INT>& operator[](int num)
    {return _Matrix[num];}
    inline matrix operator+(const matrix& ma)
    {
        matrix NewMatrix=*this;
        for(int i=0;i<SZ(_Matrix);i++)
            for(int j=0;j<SZ(_Matrix[0]);j++)
                NewMatrix[i][j]=(_Matrix[i][j]+ma._Matrix[i][j])%Mod;
        return NewMatrix;
    }
    inline matrix operator+=(const matrix& ma)
    {
        return *this=*this+ma;
    }
    inline matrix operator*(const matrix& ma)
    {
        matrix NewMatrix(SZ(_Matrix),SZ(ma._Matrix[0]));
        for(int i=0;i<SZ(_Matrix);i++)
            for(int j=0;j<SZ(_Matrix[0]);j++)
                for(int k=0;k<SZ(ma._Matrix[0]);k++)
                    NewMatrix[i][k]=(NewMatrix[i][k]+_Matrix[i][j]*ma._Matrix[j][k]%Mod)%Mod;
        return NewMatrix;
    }
    inline matrix operator*=(const matrix& ma)
    {
        return *this=*this*ma;
    }
    inline matrix pow(int pnum)
    {
        if(pnum==1)return *this;
        matrix NewMatrix=pow(pnum/2);
        NewMatrix*=NewMatrix;
        if(pnum%2)NewMatrix*=*this;
        return NewMatrix;
    }
};





matrix fibinc(2,2),fibincof0(2,2),resof0(2,1);

void INITfibinc()
{
    fibinc[0][0]=1;
    fibinc[0][1]=1;
    fibinc[1][0]=1;
    fibinc[1][1]=0;
    fibincof0[0][0]=1;
    fibincof0[0][1]=0;
    fibincof0[1][0]=0;
    fibincof0[1][1]=1;
    resof0[0][0]=0;
    resof0[1][0]=0;
}





matrix dt[MAXN],ic[MAXN];
void INITdtic()
{
    for(int i=0;i<MAXN;i++)
    {
        dt[i].resize(2,1);
        ic[i].resize(2,1);
        dt[i][0][0]=dt[i][1][0]=ic[i][0][0]=ic[i][1][0]=0;
    }
}

void assg(int now,int nl,int nr,int ai,int vi)

{
    if(nl==nr&&nr==ai)
    {
        dt[now][0][0]=vi;
        return;
    }
    int m=(nl+nr)/2;
    if(m>=ai)assg(now*2,nl,m,ai,vi);
    else assg(now*2+1,m+1,nr,ai,vi);
    dt[now]=fibinc.pow(m-nl+1)*(dt[now*2+1]+ic[now*2+1])+(dt[now*2]+ic[now*2]);
}

void pls(int now,int nl,int nr,int l,int r,int vi)

{
    if(nl>=l&&nr<=r)
    {
        ic[now][0][0]+=vi;
        return;
    }
    if(nl>r||nr<l)return;
    int m=(nl+nr)/2;
    pls(now*2,nl,m,l,r,vi);
    pls(now*2+1,m+1,nr,l,r,vi);
    dt[now]=fibinc.pow(m-nl+1)*(dt[now*2+1]+ic[now*2+1])+(dt[now*2]+ic[now*2]);
}

matrix calc(int now,int nl,int nr,int l,int r)
{
    dt[now]+=ic[now];
    ic[now*2]+=ic[now];
    ic[now*2+1]+=ic[now];
    ic[now]=resof0;
    if(nl>=l&&nr<=r)return dt[now]+ic[now];
    int m=(nl+nr)/2;
    matrix res=resof0,fibb=fibincof0;
    if(m>=l)
    {
        res+=calc(now*2,nl,m,l,r);
        fibb=fibinc.pow(m-max(l,nl)+1);
    }
    if(m<r)
        res+=fibb*calc(now*2+1,m+1,nr,l,r);
    res+=ic[now];
    return res;
}

int n,m;

void _1()
{
    int a,b;
    scanf("%d%d",&a,&b);
    a--;
    assg(1,0,n-1,a,b);
}

void _2()
{
    int a,b;
    scanf("%d%d",&a,&b);
    a--;b--;
    matrix mm=calc(1,0,n-1,a,b);
    printf("%I64d\n",mm[0][0]);
}

void _3()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    a--;b--;
    pls(1,0,n-1,a,b,c);
}

void init()
{
    INITfibinc();
    INITdtic();
}

int main()
{
    init();
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        assg(1,0,n-1,i,a);
    }
    for(int i=0;i<m;i++)
    {
        int a;
        scanf("%d",&a);
        if(a==1)_1();
        else if(a==2)_2();
        else _3();
    }
    return 0;
}