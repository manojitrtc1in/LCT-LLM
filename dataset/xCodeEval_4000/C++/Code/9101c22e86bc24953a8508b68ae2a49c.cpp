
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ten5 100000+10
#define MOD 1000000007
#define rep(i,a,n) for (int i=a;i<=n;i++)
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
const int maxn = 200001;
int per[maxn];
int dis[maxn];
bool vis[maxn];
int n;
vector<int>ve[maxn];
priority_queue<pair<int , int > > q;

void dfs(int cur,int fa)
{
    per[cur] = fa;
    rep(i,0,ve[cur].size()-1)
    {
        int v = ve[cur][i];
        if(v == fa) continue;
        dis[v] = dis[cur] + 1;
        if(dis[v] > 2)
            q.push(make_pair(dis[v],v));
        else
            vis[v] = 1;
        dfs(v,cur);

    }
}
int main()
{
    me(dis);
    me(vis);
    me(per);
    int u,v;
    n = read();
    rep(i,1,n-1)
    {
        u = read();
        v = read();
        ve[u].pb(v);
        ve[v].pb(u);
    }
    dfs(1,-1);
    int res = 0;
    while(q.size())
    {
        int v = q.top().second;
        q.pop();
        if(vis[v] == 1) continue;
        int fa = per[v];
        vis[fa] = 1;
        res ++;
        rep(i,0,ve[fa].size()-1)
        {
            vis[ve[fa][i]] = 1;
        }
    }
    cout << res << endl;
    return 0;
}
