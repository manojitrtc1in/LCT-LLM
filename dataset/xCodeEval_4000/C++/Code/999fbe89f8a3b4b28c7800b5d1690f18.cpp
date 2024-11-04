

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
char grap[55][55];
char s[110];
int ex,ey,sx,sy;
int eex,eey,vis[5],sum;
int dx[] = {0,1,-1,0};
int dy[] ={1,0,0,-1};
int a[110];
int n,m,len;


void dfs(int cnt)
{
    if(cnt == 4)
    {
         eex = sx;
         eey = sy;
        for(int i=0; i<len; i++)
        {
            eex+=dx[a[s[i]-'0']];
            eey+=dy[a[s[i]-'0']];
            if(eex<1||eex>n||eey<1||eey>m||grap[eex][eey]=='#') return;
            if(eex == ex && eey == ey)
            {
                sum++;
                return;
            }
        }

    }
    else
    {
         for(int i=0; i<4; i++)
        {
            if(vis[i]==0)
            {
                a[cnt]=i;
                vis[i]=1;
                dfs(cnt+1);
                vis[i]=0;
            }
        }

    }

}

int main()
{
    me(vis);
    n = read();m = read();
    for(int i = 1;i <= n;i ++)
    {
        scanf("%s",grap[i] + 1);
        for(int j = 1;j <= m ;j ++)
        {
            if(grap[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
            else if(grap[i][j]  == 'E')
            {
                ex = i;
                ey = j;

            }
        }
    }
    scanf("%s",s);
    sum = 0;
    len=strlen(s);
    dfs(0);
    cout <<sum << endl;

    return 0;
}
