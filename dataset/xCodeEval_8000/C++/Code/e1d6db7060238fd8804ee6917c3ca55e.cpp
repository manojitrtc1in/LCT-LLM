
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
const int N=3e5+3;

inline int Gcd(int a,int b){return (b==0)?(a):(Gcd(b,a%b));}
inline void work()
{
    int n,k;rin>>n>>k;if(k%2==0&&(n&1)){puts("-1");fflush(stdout);return;}
    int ans=0;
    if(n%k==0)
    {
        for(int i=1;i<=n;i+=k)
        {
            printf("? ");
            for(int j=i,_=1;_<=k;j++,_++)printf("%d ",j);
            printf("\n");fflush(stdout);int s;rin>>s;ans^=s;
        }
        printf("! %d\n",ans);fflush(stdout);return;
    }
    if(n/k>1&&(n%k+k)%2==0)
    {
        int j=1,m=n/k;
        for(int i=1;i<m;i++)
        {
            printf("? ");for(int _=1;_<=k;j++,_++)printf("%d ",j);
            printf("\n");fflush(stdout);int s;rin>>s;ans^=s;
        }

        int les=(n-(m-1)*k)>>1,s;
        printf("? ");for(int i=1;i<=les;i++,j++)printf("%d ",j);for(int i=1;i<=k-les;i++)printf("%d ",i);printf("\n");fflush(stdout);
        rin>>s;ans^=s;
        printf("? ");for(int i=1;i<=les;i++,j++)printf("%d ",j);for(int i=1;i<=k-les;i++)printf("%d ",i);printf("\n");fflush(stdout);
        rin>>s;ans^=s;
        printf("! %d\n",ans);fflush(stdout);return;
    }
    if((n%k)&1)
    {
        int m=n/k,j=1,s;
        if(m==1)
        {
            for(;(n-j+1>>1)+(j-1)<k;)
            {
                printf("? ");for(int _=1,ed=j+(n-k)-1;_<=n;_++)if(_<j||_>ed)printf("%d ",_);printf("\n");fflush(stdout);
                rin>>s;ans^=s;j+=(n-k);
                printf("? ");for(int _=1,ed=j+(n-k)-1;_<=n;_++)if(_<j||_>ed)printf("%d ",_);printf("\n");fflush(stdout);
                rin>>s;ans^=s;j+=(n-k);
            }
            

            int les=n-j+1>>1;
            printf("? ");for(int i=1;i<=les;i++,j++)printf("%d ",j);for(int i=1;i<=k-les;i++)printf("%d ",i);printf("\n");fflush(stdout);
            rin>>s;ans^=s;

            printf("? ");for(int i=1;i<=les;i++,j++)printf("%d ",j);for(int i=1;i<=k-les;i++)printf("%d ",i);printf("\n");fflush(stdout);
            rin>>s;ans^=s;
        }
    }
    else
    {
        int m=n/k,j=1,les=(n-m*k)>>1,s;
        for(int i=1;i<=m;i++){printf("? ");for(int _=1;_<=k;j++,_++)printf("%d ",j);printf("\n");fflush(stdout);rin>>s;ans^=s;}
        
        printf("? ");for(int i=1;i<=les;i++,j++)printf("%d ",j);for(int i=1;i<=k-les;i++)printf("%d ",i);printf("\n");fflush(stdout);
        rin>>s;ans^=s;

        printf("? ");for(int i=1;i<=les;i++,j++)printf("%d ",j);for(int i=1;i<=k-les;i++)printf("%d ",i);printf("\n");fflush(stdout);
        rin>>s;ans^=s;
    }
    
    printf("! %d\n",ans);fflush(stdout);return;
}
int main()
{
    work();
    return 0;
}

