
#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#define int long long
#define LL long long
using namespace std;
inline LL rin()
{
    LL x=0;
    char c;
    bool tag=false;
    for(c=getchar();c>'9'||c<'0';c=getchar())if(c=='-'){c=getchar();tag=true;break;}
    for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^'0');
    if(tag)x=-x;
    return x;
}
inline void jh(int &x,int &y){if(x^y)x^=y^=x^=y;return;}
inline int min(int x,int y){return x<y?x:y;}
inline int max(int x,int y){return x>y?x:y;}
const int M=1e5+3;
const int N=2e2+3;
const int MM=1e5;
int n,m;
vector<int>d;
vector<int>now[M];

int q[M<<5];
int vis[M];
int vit[M];
int ans[M];
int tag[M];
inline void work()
{
    n=rin();m=rin();d.push_back(0);
    for(int i=1;i<=m;i++)ans[i]=0x3f3f3f3f3f3f3f3f;
    for(int i=1;i<=n;i++)
    {
        memset(vit,0,sizeof(vit));
        memset(vis,0x3f,sizeof(vis));
        int typ,x,y,head,tail;typ=rin();x=rin();y=rin();head=1;tail=0;
        for(int j=0;j<=m;j++)now[j].clear();
        for(vector<int>::iterator i=d.begin();i!=d.end();i++)q[++tail]=*i,vit[*i]=true,vis[*i]=0;
        LL sk=(x/MM)+((x%MM)>0);
        for(int j=0;j<=m;j++)
        {
            LL nows=(typ==1)?(sk+j):(1LL*j*x/MM+((1LL*j*x%MM)>0));
            if(nows<=m)now[j].push_back(nows);
        }
        for(;head<=tail;)
        {
            int nows=q[head++];
            for(vector<int>::iterator i=now[nows].begin();i!=now[nows].end();i++)
            {
                if(vit[*i])continue;
                q[++tail]=*i;vit[*i]=true;vis[*i]=vis[nows]+1;
            }
        }
        for(int j=0;j<=m;j++)if(vis[j]<=y&&vit[j]){ans[j]=min(ans[j],i);if(!tag[j])tag[j]=true,d.push_back(j);}
    }
    for(int i=1;i<=m;i++)if(!tag[i])printf("-1 ");else printf("%lld ",ans[i]);puts("");
    return;
}
signed main()
{
    work();
    return 0;
}




