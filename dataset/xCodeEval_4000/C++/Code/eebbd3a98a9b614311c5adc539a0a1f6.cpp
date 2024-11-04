
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
    inline Rin&operator >>(string &x){x.clear();for(c=gc();c>'z'||c<'a';c=gc());for(;c>='a'&&c<='z';c=gc())x.push_back(c);return *this;}
}rin;
inline void jh(int &x,int &y){if(x^y)x^=y^=x^=y;return;}
inline void jh(LL &x,LL &y){if(x^y)x^=y^=x^=y;return;}
inline int min(int x,int y){return x<y?x:y;}
inline int max(int x,int y){return x>y?x:y;}
inline LL min(LL x,LL y){return x<y?x:y;}
inline LL max(LL x,LL y){return x>y?x:y;}
const int N=5e5+3;

int n,m,q;
int ans;
int cut[N];
set<int>g[N];
void work()
{
    rin>>n>>m;ans=n;
    for(int i=1,x,y;i<=m;i++)
    {
        rin>>x>>y;if(x>y)jh(x,y);
        if(!cut[x])ans--;cut[x]++;
    }
    rin>>q;
    for(;q;q--)
    {
        int opt,x,y;rin>>opt;
        if(opt==1)
        {
            rin>>x>>y;if(x>y)jh(x,y);
            if(!cut[x])ans--;cut[x]++;
        }
        if (opt==2)
        {
            rin>>x>>y;if(x>y)jh(x,y);
            if(cut[x]==1)ans++;cut[x]--;
        }
        if(opt==3)printf("%d\n",ans);
    }
    return;
}
int main()
{
    work();
    return 0;
}
