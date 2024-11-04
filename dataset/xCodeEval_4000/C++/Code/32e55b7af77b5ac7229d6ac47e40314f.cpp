

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
const int maxn = 1e5+5;
int a[maxn];
int b[maxn];
int vis[maxn];
int dfs(int s,int e,int res)
{
    if(e == s) return res;

    if(!vis[e])
    {
        vis[e] = 1;
       return  dfs(s,a[e],res + 1);
    }
    
}
int main()
{
    int n;
    n = read();
    for(int i = 1;i <= n;i ++)
    {
        scanf("%d",a +i);

    }
    me(vis);
    int cnt = 0;
    for(int i = 1;i <= n;i ++)
    {
        if(vis[i] == 0)
        {
            vis[i] = 1;
        

          b[cnt++] = dfs(i,a[i],1);
        }
    }
    sort(b,b+cnt);
    ll ans  = 0;
    ans = 1ll*(b[cnt -1] + b[cnt-2])*(b[cnt -1] + b[cnt-2]);
    for(int i = 0;i < cnt - 2;i ++)
        ans += (1ll* b[i] * b[i]);
        cout <<ans <<endl;
    return 0;

}
