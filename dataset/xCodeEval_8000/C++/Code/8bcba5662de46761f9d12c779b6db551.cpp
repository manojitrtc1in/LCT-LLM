
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
const int N=2e5+3;
const int S=1e6+3;

bool pri[S];
vector<int>prime;
vector<int>pm[225];
void init()
{
    for(int i=2,ed=sqrt(S<<1);i<=ed;i++)
    {
        if(!pri[i])prime.push_back(i);
        for(auto j:prime)
        {
            int now=j*i;if(now>=ed)break;
            pri[now]=true;if(i%j==0)break;
        }
    }
    

    return;
}
int n,q;
int a[N];
inline int Gcd(int x,int y){return !y?x:Gcd(y,x%y);}

int f[N];
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}

int cb;
pair<int,int>b[N];

int num[N];
set<int>pk[N];
map<int,int>to;

set<int>nxt[N];

int st;

set<int>nt;
vector<int>nnt;
set<pair<int,int> >ans;
void work()
{
    rin>>n>>q;
    for(int i=1;i<=n;i++)rin>>a[i],f[i]=i;
    for(int i=1;i<=n;i++)
    {
        int now=a[i];
        for(int j=0;j<prime.size();j++)
        {
            int pw=prime[j];
            if(now%pw)continue;
            for(;now%pw==0;now/=pw);pm[j].push_back(i);
        }
        if(now!=1)b[++cb]=make_pair(now,i);
    }
    if(cb)
    {
        sort(b+1,b+cb+1);
        for(int i=1,j;i<=cb;i=j){for(j=i+1;j<=cb&&b[j].first==b[i].first;j++)f[find(b[j].second)]=find(b[i].second);}
    }
    for(int i=0;i<224;i++)if(pm[i].size()){int lst=0;for(auto j:pm[i]){if(lst)f[find(j)]=find(lst);lst=j;}}
    
    

    

    

    

    int cutt=0;
    for(int i=1;i<=n;i++)if(find(i)==i)num[i]=++cutt;
    for(int i=1;i<=n;i++)
    {
        int now=a[i];
        for(int j=0;j<prime.size();j++)
        {
            int pw=prime[j];
            if(now%pw)continue;
            for(;now%pw==0;now/=pw);pk[num[find(i)]].insert(pw);
        }
        if(now!=1)pk[num[find(i)]].insert(now);
    }
    

    for(int i=1;i<=cutt;i++)for(auto j:pk[i])to[j]=i;
    

    for(int i=1;i<=n;i++)
    {
        int now=a[i]+1;nt.clear();
        for(int j=0;j<prime.size();j++)
        {
            int pw=prime[j];
            if(now%pw)continue;
            for(;now%pw==0;now/=pw);
            map<int,int>::iterator fd=to.find(pw);if(fd==to.end())continue;
            if(fd->second!=num[find(i)])nxt[num[find(i)]].insert(fd->second),nt.insert(fd->second);
        }
        if(now!=1)
        {
            int pw=now;
            map<int,int>::iterator fd=to.find(pw);
            if(fd!=to.end()&&fd->second!=num[find(i)])nxt[num[find(i)]].insert(fd->second),nt.insert(fd->second);
        }
        nt.insert(num[find(i)]);
        if(nt.size()>1)
        {
            nnt.clear();
            for(auto i:nt)nnt.push_back(i);
            for(int i=0;i<nnt.size();i++)for(int j=i+1;j<nnt.size();j++)ans.insert(make_pair(min(nnt[i],nnt[j]),max(nnt[i],nnt[j])));
        }
    }
    

    for(int i=1;i<=q;i++)
    {
        int x,y;rin>>x>>y;
        if(find(x)==find(y)){puts("0");continue;}
        if(a[x]%2==0||a[y]%2==0){puts("1");continue;}
        x=num[find(x)];y=num[find(y)];
        if(nxt[x].find(y)!=nxt[x].end()){puts("1");continue;}
        if(nxt[y].find(x)!=nxt[y].end()){puts("1");continue;}
        if(ans.find(make_pair(min(x,y),max(x,y)))!=ans.end()){puts("1");continue;}
        puts("2");
    }
    return;
}
int main()
{
    init();
    work();
    return 0;
}
