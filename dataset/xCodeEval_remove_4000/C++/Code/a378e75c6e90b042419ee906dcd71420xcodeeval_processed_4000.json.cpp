


using namespace std;
typedef long long ll;









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
const int maxn = 20010;
int a[maxn];
int vis[maxn];
int main()
{
    int i;
    int n;
    n = read();
    me(vis);
    for( i =2;i <= n;i ++)
    {
        a[i]  =read();
        vis[a[i]] = 1;
    }
    for( i = n;i >= 1;i --)
    {
        if(vis[i] == 0)
        {
            vis[a[i]] ++;
        }
    }
    for( i = 1;i <= n;i ++)
    {
        if(vis[i] && vis[i] < 4)
            break;
    }
    if(i > n)
    {
        puts("Yes");
    }
    else
    {
        puts("No");
    }
    return 0;
}
