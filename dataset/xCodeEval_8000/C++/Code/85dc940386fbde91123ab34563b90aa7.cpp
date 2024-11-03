

#include <map>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#define LL long long
using namespace std;
const int Rea=1e5+3;
struct Rin
{
    char c;
    char gc()
    {
        static char rea[Rea];
        static char *head,*tail;
        return head==tail&&(tail=(head=rea)+fread(rea,1,Rea,stdin),head==tail)?EOF:*head++;
    }
    Rin&operator >>(int &x)
    {
        bool tag=false;x=0;
        for(c=gc();c>'9'||c<'0';c=gc())if(c=='-'){c=gc();tag=true;break;}
        for(;c>='0'&&c<='9';c=gc())x=(x<<1)+(x<<3)+(c^'0');if(tag)x=-x;return *this;
    }
    Rin&operator >>(LL &x)
    {
        bool tag=false;x=0;
        for(c=gc();c>'9'||c<'0';c=gc())if(c=='-'){c=gc();tag=true;break;}
        for(;c>='0'&&c<='9';c=gc())x=(x<<1)+(x<<3)+(c^'0');if(tag)x=-x;return *this;
    }
    Rin&operator >>(string &x){x.clear();x.push_back('?');for(c=gc();c>'z'||c<'a';c=gc());for(;c>='a'&&c<='z';c=gc())x.push_back(c);return *this;}
}rin;
void jh(int &x,int &y){if(x^y)x^=y^=x^=y;return;}
void jh(LL &x,LL &y){if(x^y)x^=y^=x^=y;return;}
int min(int x,int y){return x<y?x:y;}
int max(int x,int y){return x>y?x:y;}
LL min(LL x,LL y){return x<y?x:y;}
LL max(LL x,LL y){return x>y?x:y;}

const int N=2e3+3;
const int INFW=0x3f3f3f3f;
const LL INFV=1e14;
int nd;
struct node
{
    int x,y,w;
    void Read(){rin>>x>>y>>w;return;}
}nod[N];
map<pair<int,int>,int>q;
int ck(int x,int y){return q.find(make_pair(x,y))!=q.end()?q[make_pair(x,y)]:0;}

struct edge
{
    int to,nxt;
    LL w;
    edge(int to_=0,int nxt_=0,LL w_=0){to=to_;nxt=nxt_;w=w_;}
}E[N<<8];
int hea[N<<1];
int lst[N<<1];
int Ecutt=1;
void add(int x,int y,LL w){E[++Ecutt]=edge(y,hea[x],w);hea[x]=Ecutt;E[++Ecutt]=edge(x,hea[y],0);hea[y]=Ecutt;return;}
void insert(int A,int B,int C,int D){add(A+nd,B,INFV);add(B+nd,C,INFV);add(C+nd,D,INFV);return;}
namespace Flew
{
    int S,T,n;
    int dis[N<<1];

    int d[N<<1];
    int tail;
    bool finddis()
    {
        for(int i=1;i<=n;i++)dis[i]=INFW;dis[S]=0;d[tail=1]=S;
        for(int head=1;head<=tail;)
        {
            int now=d[head++];
            for(int i=hea[now];i;i=E[i].nxt)if(E[i].w)
            {
                if(dis[E[i].to]>dis[now]+1)dis[E[i].to]=dis[now]+1,d[++tail]=E[i].to;
            }
        }
        for(int i=1;i<=n;i++)lst[i]=hea[i];
        return dis[T]!=INFW;
    }
    bool vit[N<<1];
    LL flew(int now,LL w)
    {
        if(!w||now==T)return w;
        vit[now]=true;
        LL les=w,ans=0;
        for(int i=lst[now];i;lst[now]=i=E[i].nxt)if(!vit[E[i].to]&&dis[now]+1==dis[E[i].to])
        {
            LL used=flew(E[i].to,min(les,E[i].w));
            ans+=used;les-=used;E[i].w-=used;E[i^1].w+=used;if(!les)break;
        }
        vit[now]=false;
        return ans;
    }
    LL flewall()
    {
        LL ans=0;
        for(LL sum;finddis();ans+=sum)sum=flew(S,INFV);
        return ans;
    }
}

void Read()
{
    rin>>nd;
    for(int i=1;i<=nd;i++)nod[i].Read();
    return;
}
void Init()
{
    using namespace Flew;S=(nd<<1)+1;T=S+1;n=T;
    for(int i=1;i<=nd;i++)q[make_pair(nod[i].x,nod[i].y)]=i;
    for(int i=1;i<=nd;i++)add(i,i+nd,nod[i].w);
    

    

    

    

    

    

    

    

    


    

    

    

    

    

    for(int i=1;i<=nd;i++)
    {
        int x=nod[i].x,y=nod[i].y,A,B,C,D;
        if((nod[i].x&1)&&(nod[i].y&1))
        {
            add(S,i,INFV);A=i;
            if((B=ck(x-1,y)))add(A+nd,B,INFV);
            if((B=ck(x+1,y)))add(A+nd,B,INFV);
        }
        if(nod[i].x%2==0&&(nod[i].y&1))
        {
            B=i;
            if(C=ck(x,y-1))add(B+nd,C,INFV);
            if(C=ck(x,y+1))add(B+nd,C,INFV);
        }
        if(nod[i].x%2==0&&nod[i].y%2==0)
        {
            C=i;
            if(D=ck(x-1,y))add(C+nd,D,INFV);
            if(D=ck(x+1,y))add(C+nd,D,INFV);
        }
        if((nod[i].x&1)&&nod[i].y%2==0)add(i+nd,T,INFV);
    }
    

    return;
}
void Work()
{
    using namespace Flew;
    LL sum=0;for(int i=1;i<=nd;i++)sum+=nod[i].w;
    printf("%lld\n",sum-flewall());
    return;
}
int main()
{
    Read();
    Init();
    Work();
    return 0;
}