


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
struct node
{
    int x,id;
    bool operator<(const node b) const
    {
        return x<b.x;
    }
}t[4];
int m;
int ok(int x)
{
    fup(i,1,m)
    if(x==t[i].x)
    {
        t[i].id++;
        return 0;
    }
    return 1;
}
int main()
{
    

    int n;
    while(~sd(n))
    {
        fill(t,0);
        m=0;
        fup(i,1,n)
        {
            int x;
            sd(x);
            if(ok(x)) t[++m].x=x,t[m].id++;
        }
        int flag=1;
        if(m==1)
        {
            pf(n);
            fup(i,1,m)
            {
                while(t[i].id--)
                {
                    if(!flag) printf(" ");
                    printf("%d",t[i].x);
                    flag=0;
                }
            }
        }
        else if(m==2)
        {
            if(abs(t[2].x-t[1].x)==2)
            {
                int l=min(t[1].id,t[2].id);
                t[3].x=(t[2].x+t[1].x)/2;
                t[3].id=l*2;
                t[1].id-=l;
                t[2].id-=l;
                pf(n-l*2);
                m++;
            }
            else pf(n);
            fup(i,1,m)
            {
                while(t[i].id--)
                {
                    if(!flag) printf(" ");
                    printf("%d",t[i].x);
                    flag=0;
                }
            }
        }
        else
        {
            sort(t+1,t+4);
            int l=min(t[1].id,t[3].id),r=t[2].id/2*2;
            if(l*2>=r)
            {
                t[1].id-=l;
                t[3].id-=l;
                t[2].id+=2*l;
                pf(n-2*l);
            }
            else
            {
                pf(n-r);
               t[1].id+=r/2;
               t[3].id+=r/2;
               t[2].id-=r;
            }
            fup(i,1,m)
            {
                while(t[i].id--)
                {
                    if(!flag) printf(" ");
                    printf("%d",t[i].x);
                    flag=0;
                }
            }
        }
        puts("");
    }
    return 0;
}