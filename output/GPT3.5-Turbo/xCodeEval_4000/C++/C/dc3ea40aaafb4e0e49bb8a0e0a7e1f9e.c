#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define LL long long
#define pb push_back
#define pob pop_back
#define mp make_pair
#define FILL(a,v) memset((void*)a,v,sizeof(a))
#define FILL0(a) FILL(a,0)
#define FILL1(a) FILL(a,-1)
#define FILLBIG(a) FILL(a,0x3f)
#define ALL(a) (a).begin(),(a).end()
#define Inf ((int)0x3f3f3f3f)
#define INF ((long long)0x3f3f3f3f3f3f3f3f)
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
#define y0 ykangjimutigeidiqiuyipianjingtu
#define y1 yxiaomiexuduhuanrenleiwannianankang

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

#define MAX_SIZE 77

struct matrix
{
    INT mat[MAX_SIZE][MAX_SIZE];
};

matrix ksmii(matrix x,int y)
{
    if(y==1) return x;
    matrix mat2=ksmii(x,y/2);
    mat2=mat2*mat2;
    if(y%2) mat2=mat2*x;
    return mat2;
}

matrix matrix_multiply(matrix a, matrix b, int size)
{
    matrix mat2;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            mat2.mat[i][j] = INF;
            for(int k=0;k<size;k++)
            {
                mat2.mat[i][j] = fmin(mat2.mat[i][j], a.mat[i][k] + b.mat[k][j]);
            }
        }
    }
    return mat2;
}

int main()
{
    matrix zyj, zyj2;
    int x, k, n, q;
    int c[15];
    int dy[257], cntdy=0;
    int yd[MAX_SIZE];
    int p[27], wp[27];
    map<int,int> wpp;
    pii ws_[27];

    zyj2.mat[0][0]=0;
    scanf("%d%d%d%d",&x,&k,&n,&q);
    for(int i=1;i<=k;i++)
        scanf("%d",c+i);
    for(int i=0;i<q;i++)
        scanf("%d%d",&ws_[i].first,&ws_[i].second);
    sort(ws_,ws_+q);
    for(int i=0;i<q;i++)
    {
        p[i]=ws_[i].first;
        wp[i]=ws_[i].second;
        wpp[p[i]]=wp[i];
    }
    for(int i=0;i<MASK(k);i++)
        if(__builtin_popcount(i)==x)
        {
            yd[cntdy]=i;
            dy[i]=cntdy++;
        }
    for(int ii=0;ii<cntdy;ii++)
    {
        int j=yd[ii];
        if(j&1)
        {
            for(int l=1;l<=k;l++)
                if(!BIT(j,l))
                    zyj.mat[ii][dy[(j+MASK(l))>>1]]=c[l];
        }
        else
            zyj.mat[ii][dy[j>>1]]=0;
    }
    int nowpos=1;
    for(int i=0;i<q;i++)
    {
        int to=min(n-x+1,p[i]-k-1);
        if(to-nowpos>0) zyj2=matrix_multiply(zyj2, ksmii(zyj,to-nowpos), cntdy);

        matrix nm=zyj;
        for(int j=max(nowpos,to);j<min(n-x+1,p[i]);j++)
        {
            for(int ii=0;ii<cntdy;ii++)
            {
                int jj=yd[ii];
                if(jj&1)
                {
                    for(int l=1;l<=k;l++)
                        if(!BIT(jj,l))
                            nm.mat[ii][dy[(jj+MASK(l))>>1]]+=wpp[j+l];
                }
            }
            zyj2=matrix_multiply(zyj2, nm, cntdy);
            nm=zyj;
        }
        nowpos=min(n-x+1,p[i]);
    }
    if(n-x+1-nowpos>0) zyj2=matrix_multiply(zyj2, ksmii(zyj,n-x+1-nowpos), cntdy);

    printf("%lld\n",zyj2.mat[0][0]);
    return 0;
}
