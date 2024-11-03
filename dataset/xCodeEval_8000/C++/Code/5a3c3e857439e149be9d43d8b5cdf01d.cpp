
#pragma GCC optimize(2)
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <random>
#include <chrono>
#include <vector>
#include <string>
#include <time.h>
#include <stdio.h>


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
    inline Rin&operator >>(string &x){x.clear();for(c=gc();c>'z'||c<'a';c=gc());for(;c>='a'&&c<='z';c=gc())x.push_back(c);return *this;}
}rin;
inline void jh(int &x,int &y){if(x^y)x^=y^=x^=y;return;}
inline void jh(LL &x,LL &y){if(x^y)x^=y^=x^=y;return;}
inline int min(int x,int y){return x<y?x:y;}
inline int max(int x,int y){return x>y?x:y;}
inline LL min(LL x,LL y){return x<y?x:y;}
inline LL max(LL x,LL y){return x>y?x:y;}
const int N=4e5+3;
const int M=998244353;

int n,m;

int root;

mt19937 engine(chrono::_V2::steady_clock::now().time_since_epoch().count());
inline int rand(int l,int r){return uniform_int_distribution<int>(l,r)(engine);}
struct nod
{
    int v,w;
    int ls,rs,tag;
    void addtag(int val){tag+=val;v+=val;return;}
    void init(int v_){v=v_;w=rand(1,2e9);ls=rs=tag=0;return;}
}nod[N<<1];
int nodecutt;
void down(int i)
{
    if(nod[i].tag)
    {
        if(nod[i].ls)nod[nod[i].ls].addtag(nod[i].tag);
        if(nod[i].rs)nod[nod[i].rs].addtag(nod[i].tag);
        nod[i].tag=0;
    }
    return;
}
void slim(int &x,int &y,int now,int k)
{
    if(!now){x=y=0;return;}down(now);
    if(nod[now].v<=k)x=now,slim(nod[now].rs,y,nod[now].rs,k);
    else y=now,slim(x,nod[now].ls,nod[now].ls,k);
    return;
}
int joojoo(int x,int y)
{
    if(!x||!y)return x+y;
    if(nod[x].w>nod[y].w){down(x);nod[x].rs=joojoo(nod[x].rs,y);return x;}
    down(y);nod[y].ls=joojoo(x,nod[y].ls);return y;
}

pair<int,int>a[N];

int sl[N];
int sr[N];
int prpr(int x,int y){return 1LL*x*y%M;}
int ksm(int x,int y){int ans=1;for(;y;y>>=1){if(y&1)ans=prpr(ans,x);x=prpr(x,x);}return ans;}
int C(int a,int b){return a<b?0:prpr(sl[a],prpr(sr[b],sr[a-b]));}

void init()
{
    sl[0]=1;for(int i=1;i<N;i++)sl[i]=prpr(sl[i-1],i);sr[N-1]=ksm(sl[N-1],M-2);
    sr[0]=1;for(int i=N-2;i>=1;i--)sr[i]=prpr(sr[i+1],i+1);
    return;
}
void check(int now)
{
    down(now);
    if(nod[now].ls&&(nod[nod[now].ls].v>=nod[now].v))throw;
    if(nod[now].rs&&(nod[nod[now].rs].v<=nod[now].v))throw;
    if(nod[now].ls)check(nod[now].ls);if(nod[now].rs)check(nod[now].rs);
    return;
}
void work()
{
    rin>>n>>m;root=nodecutt=0;
    for(int i=1;i<=m;i++)rin>>a[i].first>>a[i].second;
    for(int i=1;i<=m;i++)
    {
        int x,y,now;slim(x,y,root,a[i].second-1);
        for(now=y;nod[now].ls;now=nod[now].ls)down(now);
        
        if(nod[now].v==a[i].second){if(y)nod[y].addtag(1);root=joojoo(x,y);continue;}
        nod[++nodecutt].init(a[i].second);y=joojoo(nodecutt,y);nod[y].addtag(1);root=joojoo(x,y);
        

    }
    

    nodecutt=n-nodecutt-1;
    printf("%d\n",C(n+nodecutt,nodecutt));
    return;
}
int main()
{
    

    init();
    int T;for(rin>>T;T;T--)work();
    return 0;
}
