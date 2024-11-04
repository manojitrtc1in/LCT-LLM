


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
#define pf printf
#define sf scanf
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
#define N 100005
#define M 4000009
#define mod 1000000
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
int t[M][2],sum[M],tot=0;
void add(int x)
{
    int now=0;
    for(int i=1<<30; i; i>>=1)
    {
        int w;
        w=(x&i)?1:0;
        if(!t[now][w]) t[now][w]=++tot;
        now=t[now][w];
        sum[now]++;
    }
}
void del(int x)
{
    int now=0;
    for(int i=1<<30; i; i>>=1)
    {
        int w;
        w=(x&i)?1:0;
        now=t[now][w];
        sum[now]--;
    }
}
int cal(int x)
{
    int now=0,ans=0;
    for(int i=1<<30; i; i>>=1)
    {
        int w;
        w=(x&i) ? 0:1;
        if(sum[t[now][w]]>0) ans|=i,now=t[now][w];
        else now=t[now][!w];
    }
    return ans;
}
int main()
{
    int n,now=0;
    while(~sd(n))
    {
        tot=0;
        fill(sum,0);
        fill(t,0);
        add(0);
        while(n--)
        {
            char c[3];
            int x;
            cin>>c;
            sd(x);
            if(c[0]=='+') add(x);
            else if(c[0]=='-') del(x);
            else pf(cal(x));
        }
    }
    return 0;
}