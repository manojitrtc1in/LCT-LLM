
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 2005
#define maxm 200005
#define INF 1234567890
#define eps 1e-15
#define p 1000000007
const double pi=acos(-1);
template<class T>inline bool read(T &x)
{
    x=0;register char c=getchar();register bool f=0;
    while(!isdigit(c)){if(c==EOF)return false;f^=c=='-',c=getchar();}
    while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
    if(f)x=-x;
    return true;
}
template<class T>inline void print(T x)
{
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);
    putchar(x%10^48);
}
template<class T>inline void printc(T x){putchar(x);}
template<class T>inline void print(T x,char c){print(x),putchar(c);}
template<class T>inline void printc(T x,T c){printc(x),putchar(c);}
template<class T,class ...S>inline bool read(T &x,S &...y){return read(x)&&read(y...);}
ll n,a[maxn],cnt,aa,bb,x;
set<pair<ll,ll>>ans;
inline void query(ll x)
{
    printc('?',' ');
    print(x,'\n');
    fflush(stdout);
}
int main()
{
    read(n);
    query(1);
    for(ll i=1;i<=n;i++)
    {
        read(a[i]);
        if(a[i]==1)ans.insert(make_pair(1ll,i));
        if(!a[i])continue;
        if(a[i]&1)aa++;
        else bb++;
    }
    if(aa<bb)
    {
        for(ll i=1;i<=n;i++)
        {
            if(!a[i])continue;
            if(a[i]&1)
            {
                query(i);
                for(ll j=1;j<=n;j++)
                {
                    read(x);
                    if(x==1)ans.insert(make_pair(min(i,j),max(i,j)));
                }
            }
        }
    }
    else
    {
        for(ll i=1;i<=n;i++)
        {
            if(!a[i])continue;
            if(a[i]&1^1)
            {
                query(i);
                for(ll j=1;j<=n;j++)
                {
                    read(x);
                    if(x==1)ans.insert(make_pair(min(i,j),max(i,j)));
                }
            }
        }
    }
    printc('!','\n');
    for(auto it:ans)
    {
        print(it.first,' ');
        print(it.second,'\n');
    }
    return 0;
}

