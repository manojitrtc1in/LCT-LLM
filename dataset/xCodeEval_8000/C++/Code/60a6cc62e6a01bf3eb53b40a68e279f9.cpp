
#pragma GCC optimize(3)
#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
    inline char gc(){return getchar();}
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
const int N=1e2+3;
int n;
int sl,sr;
int zjj,gyq;
int a[N][N];
inline bool check(int x,int y){for(;x<=n&&y<=n;x++,y++)if(!a[x][y])return true;return false;}
inline void Gura(int x,int y,int z){printf("%d %d %d\n",z,x,y);fflush(stdout);a[x][y]=z;if(z==2&&(x==n)+(y==n)>0)gyq++;if(z==1&&(x==n)+(y==n)>0)zjj++;return;}
inline void solve()
{
    int x;
    rin>>x;
    if(zjj==sl)for(int j=1;j<=n;j++)for(int _=1;_<=n;_++)if(!a[j][_]){Gura(j,_,x!=2?2:3);return;}
    if(gyq==sr)for(int j=1;j<=n;j++)for(int _=1;_<=n;_++)if(!a[j][_]){Gura(j,_,x!=1?1:3);return;}
    if(x!=1)
    {
        for(int j=1,x,y;j<=n;j+=2)
        {
            if(check(1,j)){x=1,y=j;for(;a[x][y];x++,y++);Gura(x,y,1);return;}
            if(check(j,1)){x=j,y=1;for(;a[x][y];x++,y++);Gura(x,y,1);return;}
        }
    }
    else
    {
        for(int j=2,x,y;j<=n;j+=2)
        {
            if(check(1,j)){x=1,y=j;for(;a[x][y];x++,y++);Gura(x,y,2);return;}
            if(check(j,1)){x=j,y=1;for(;a[x][y];x++,y++);Gura(x,y,2);return;}
        }
    }
}
inline void work()
{
    rin>>n;
    sl=n-(!(n&1));sr=n-(n&1);
    for(int i=1,ed=n*n;i<=ed;i++)solve();
    return;
}
int main()
{
    work();
    return 0;
}
