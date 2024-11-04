
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
const int N=1e5+3;
const int M=998244353;
inline int prpr(int x,int y){return 1LL*x*y%M;}
inline int ksm(int x,int y){int ans=1;for(;y;y>>=1){if(y&1)ans=prpr(ans,x);x=prpr(x,x);}return ans;}
inline int Gcd(int a,int b){return (!b)?a:Gcd(b,a%b);}
int n,m;
vector<int>nxt[N];

int k,val;
int ans[N];
bool kakaa;
inline int dfs(int now,int fa)
{
    if(!kakaa)return 0;
    int sum=nxt[now].size();for(auto to:nxt[now])if(to!=fa)sum-=dfs(to,now);
    if(sum%k>0&&(sum-1)%k>0)kakaa=false;
    if (!(sum % k)){val=Gcd(val,sum);return 1;}
    else {val=Gcd(val,sum-1);return 0;}
}
bool check(int k_){val=0;kakaa=true;int s=(n-1)/k_;k=k_;dfs(1,0);return kakaa;}
void work()
{
    rin>>n;m=ksm(2,n-1);
    for(int i=1;i<=n;i++)nxt[i].clear();
    for(int i=1,x,y;i<n;i++){rin>>x>>y;nxt[x].push_back(y);nxt[y].push_back(x);}
    for(int i=1;i<=n;i++)ans[i]=0;ans[1]=m;
    int les=n-1;
    for(int i=2;i*i<=les;i++)if(les%i==0)
    {
        if(check(i))ans[val]=1;
        for(;les%i==0;les/=i);
    }
    if(les>1&&check(les))ans[val]=1;
    for(int i=2;i<=n;i++)ans[1]-=ans[i];if(ans[1]<0)ans[1]+=M;
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);puts("");
    return;
}
int main()
{
    int T;for(rin>>T;T;T--)work();
    return 0;
}
