
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
const int N=6e3+3;
const int S=16;
const int t[S][3]=
{
	{0,0,0},
    {0,0,1},{0,0,2},{0,0,3},
    {0,1,1},{0,2,2},{0,3,3},
    {1,1,1},{1,1,2},{1,1,3},
    {1,2,2},{1,3,3},{2,2,2},
    {2,2,3},{2,3,3},{3,3,3}
};
int n;
LL a[S];
LL b[N][2];
void work()
{
    rin>>n;LL ans=0;
	for(int i=1;i<=n;i++)rin>>b[i][0]>>b[i][1];
    for(int i=1;i<=n;i++)a[(((b[i][0]>>1)&1)<<1)+((b[i][1]>>1)&1)]++;
	for(int i=0;i<S;i++)
    {
        bool tag1=(t[i][1]==t[i][2]),tag2=(t[i][0]==t[i][1]);
		if(tag1&&tag2)ans+=(a[t[i][0]]*(a[t[i][0]]-1)>>1)*(a[t[i][0]]-2)/3;
		else if(tag1)ans+=(a[t[i][1]]*(a[t[i][1]]-1)>>1)*a[t[i][0]];
		else if(tag2)ans+=(a[t[i][0]]*(a[t[i][0]]-1)>>1)*a[t[i][2]];
		else ans+=a[t[i][0]]*a[t[i][1]]*a[t[i][2]];
    }
	printf("%lld\n",ans);
    return;
}
int main()
{
    work();
    return 0;
}
