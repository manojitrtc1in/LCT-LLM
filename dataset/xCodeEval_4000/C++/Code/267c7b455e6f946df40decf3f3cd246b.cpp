

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ten5 100000+10
#define MOD 1000000007
#define rep(i,a,n) for (int i=a;i<n;i++)
#define iif(c,t,f) ((c)?(t):(f))
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define me(x) memset(x,0,sizeof(x))
#define ms(x) memset(x,0x3f3f3f3f,sizeof(x))
const int  inf = 0x3f3f3f3f;
int intcmp(const void *v1,const void *v2)
{
    return *(int *)v1-*(int *)v2;
}

inline int read()
{
    int x=0,f=1;
    char cc=getchar();
    while(cc<'0' || cc>'9')
    {
        if(cc=='-') f=-1;
        cc=getchar();
    }
    while(cc>='0' && cc<='9')
    {
        x=x*10+cc-'0';
        cc=getchar();
    }
    return x*f;
}
int n,k;
const int maxn = 1e5+100;
int a[maxn];

int main()
{
    n =read();
    k = read();
    int maxx = inf;
    int minn = -inf;
   rep(i,1,n+1)
   {
       scanf("%d",a+i);
       maxx = min(a[i],maxx);
       minn = max(a[i],minn);
   }
   if(n == 1)
   {
       cout <<a[1] << endl;
       return 0;
   }
   if(k == 1)
   {
       cout << maxx <<endl;
       return 0;
   }
   else if(k == 2)
   {
       cout <<max(a[1],a[n])<<endl;
   }else
   {
       cout << minn << endl;
   }


    return 0;
}
