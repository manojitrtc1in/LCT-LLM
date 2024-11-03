
#pragma GCC optimize(2)
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;
const int Rea=1e5+3;
struct Rin
{
    char c;
    inline char gc()
    {
        static char rea[Rea];
        static char *head,*tail;
        return head==tail&&(tail=(head=rea)+fread(rea,1,Rea,stdin),head==tail)?EOF:*head++;
    }
    inline Rin&operator >>(int &x)
    {
        x=0;
        bool tag=false;
        for(c=gc();c>'9'||c<'0';c=gc())if(c=='-'){c=gc();tag=true;break;}
        for(;c>='0'&&c<='9';c=gc())x=(x<<1)+(x<<3)+(c^'0');
        if(tag)x=-x;
        return *this;
    }
    inline Rin&operator >>(LL &x)
    {
        x=0;
        bool tag=false;
        for(c=gc();c>'9'||c<'0';c=gc())if(c=='-'){c=gc();tag=true;break;}
        for(;c>='0'&&c<='9';c=gc())x=(x<<1)+(x<<3)+(c^'0');
        if(tag)x=-x;
        return *this;
    }
    inline Rin&operator >>(char &x){for(x=gc();x!='#'&&x!='.';x=gc());return *this;}
    inline Rin&operator >>(string &x){x.clear();for(c=gc();c>'z'||c<'a';c=gc());for(;c>='a'&&c<='z';c=gc())x.push_back(c);return *this;}
}rin;
inline void jh(int &x,int &y){if(x^y)x^=y^=x^=y;return;}
inline void jh(LL &x,LL &y){if(x^y)x^=y^=x^=y;return;}
inline int min(int x,int y){return x<y?x:y;}
inline int max(int x,int y){return x>y?x:y;}
inline LL min(LL x,LL y){return x<y?x:y;}
inline LL max(LL x,LL y){return x>y?x:y;}
const int N=4e5+3;

int ans;
int n,m;
int h[N];
vector<char>a[N];

#define re(x,y) ((x-1)*m+y)

int renumd;
int numd;
int tail;
int d[N];
int du[N];
int dfn[N];
int low[N];
int num[N];
int vit[N];
vector<int>nxt[N];
vector<int>bac[N];

int l[N];
int r[N];
void Tar(int now)
{
    dfn[now]=low[now]=++numd;d[++tail]=now;
    for(auto to:nxt[now])
    {
        if(!dfn[to])Tar(to),low[now]=min(low[now],low[to]);
        else if(!num[to])low[now]=min(low[now],dfn[to]);
    }
    if(dfn[now]==low[now]){renumd++;for(;d[tail]!=now;tail--)num[d[tail]]=renumd;num[d[tail--]]=renumd;}
    return;
}
void add(int x,int y){nxt[x].push_back(y);return;}
void link(int x,int y){bac[x].push_back(y);du[y]++;return;}

struct gyq
{
    int l,r;
    gyq(int x=0,int y=0){l=x;r=y;}
    inline bool operator <(gyq ath){return l<ath.l;}
}g[N];
int gt;
void work()
{
    rin>>n>>m;
    for(int i=1;i<=n;i++){a[i].clear();a[i].push_back('g');for(int j=1;j<=m;j++){char x;rin>>x;a[i].push_back(x);}}
    for(int i=1,j;i<=m;i++)rin>>h[i];
    for(int j=1;j<=m;j++)
    {
        int lst=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i][j]=='#'){if(lst){add(re(lst,j),re(i,j));if(lst==i-1)add(re(i,j),re(lst,j));}lst=i;}
            if(a[i][j-1]=='#'&&lst)add(re(lst,j),re(i,j-1));
            if(a[i][j+1]=='#'&&lst)add(re(lst,j),re(i,j+1));
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(!dfn[re(i,j)]&&a[i][j]=='#')Tar(re(i,j));tail=0;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j]=='#'){int now=re(i,j);for(auto to:nxt[now])if(num[now]!=num[to])link(num[now],num[to]);}
    
    for(int i=1;i<=renumd;i++)if(!du[i])d[++tail]=i;
    for(int head=1;head<=tail;){int now=d[head++];for(auto to:bac[now])if(!(--du[to]))d[++tail]=to;}
    
    for(int j=1,k;k=h[j],j<=m;j++)for(int i=n;i>=1;i--)if(a[i][j]=='#'&&(--k)==0){int now=num[re(i,j)];if(!l[now])l[now]=r[now]=j;}
    for(int i=1;i<=tail;i++){int now=d[i];if(l[now]||vit[now])for(auto to:bac[now])vit[to]=1;}
    for(int i=tail;i>=1;i--)l[d[i]]=r[d[i]]=0;
    for(int j=1,k;k=h[j],j<=m;j++)for(int i=n;i>=1;i--)if(a[i][j]=='#'&&(--k)==0)
    {
        int now=num[re(i,j)];if(vit[now]){h[j]=0;continue;}
        if(!l[now])l[now]=r[now]=j;else l[now]=min(l[now],j),r[now]=max(r[now],j); 
    }
    for(int i=tail;i>=1;i--){int now=d[i];if(!vit[now])for(auto to:bac[now])if(l[to]){if(!l[now])l[now]=l[to],r[now]=r[to];else l[now]=min(l[now],l[to]),r[now]=max(r[now],r[to]);}}
    for(int i=1;i<=renumd;i++)if(l[i])g[++gt].l=l[i],g[gt].r=r[i];sort(g+1,g+gt+1);
    
    for(int i=1,j=0;i<=m;i++)
    {
        if(!h[i])continue;
        int maxr=0;for(;j<gt&&g[j+1].l<=i;j++)maxr=max(maxr,g[j+1].r);
        ans++;i=maxr;
    }
    printf("%d\n",ans);
    return;
}
int main()
{
    work();
    return 0;
}
