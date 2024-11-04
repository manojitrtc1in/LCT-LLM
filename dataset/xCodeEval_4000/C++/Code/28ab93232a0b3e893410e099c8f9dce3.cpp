


#include<stdio.h>
#include<string.h>
#include<string>
#include<math.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<stdlib.h>
#include<time.h>
#include <iomanip>
#define lowbit(x) (x&(-x))
#define inf  0x7fffffff
#define linf 0x7fffffffffffffff
#define fill(x,y) memset(x,y,sizeof(x))
#define fup(i,x,y) for(int i=(x);i<=(y);i++)
#define fdn(i,x,y) for(int i=(x);i>=(y);i--)
#define sp(x) setprecision(x)
#define sd(n) scanf("%d",&n)
#define sdd(n,m) scanf("%d%d",&n,&m)
#define sddd(n,m,k) scanf("%d%d%d",&n,&m,&k)
#define sld(n) scanf("%lld",&n)
#define sldd(n,m) scanf("%lld%lld",&n,&m)
#define slddd(n,m,k) scanf("%lld%lld%lld",&n,&m,&k)
#define sf(n) scanf("%lf",&n)
#define sff(n,m) scanf("%lf%lf",&n,&m)
#define sfff(n,m,k) scanf("%lf%lf%lf",&n,&m,&k)
#define sc(n) scanf("%s",&n)
#define pf(x) printf("%d\n",x)
#define pfl(x) printf("%lld\n",x)
#define pff(x) printf("%lf\n",x)
#define N 200005
#define M 4000009
#define mod 9973
#define pi acos(-1)




using namespace std;
typedef long long ll;
typedef double db;
inline int scan(int &n)
{
    int res=0,ch,flag=0;
    if((ch=getchar())=='-')flag=1;
    else if(ch>='0' && ch<='9')res=ch-'0';
    while((ch=getchar())>='0'&&ch<='9')res=res*10+ch-'0';
    n= flag ? -res : res;
}
int a[1005];
int main()
{
    

    int n;
    while(~sd(n))
    {
        int x;
        db l=-inf,r=inf;
        fup(i,1,n)
        {
            sd(x);
            db a,b;
            a=x*10.0/i;
            b=(x*10.0+10)/i;
            l=max(a,l);
            r=min(b,r);
        }
        db p=(n+1)*r-x*10;
        db q=(n+1)*l-x*10;
  

        int a=floor(q)/10;
        int b=floor(p)/10;
        if(a==b||(abs(a-b)==1&&p-b*10==0))
        {
            puts("unique");
            pf(x+(int)floor(q)/10);
        }
        else
        {
          puts("not unique");
        }
    }
    return 0;
}
