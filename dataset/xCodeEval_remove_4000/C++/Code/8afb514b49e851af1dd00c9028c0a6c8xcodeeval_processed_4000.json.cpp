






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
}rin;
inline void jh(int &x,int &y){if(x^y)x^=y^=x^=y;return;}
inline int min(int x,int y){return x<y?x:y;}
inline int max(int x,int y){return x>y?x:y;}

const int K=323;
const int N=1e5+K;
int n,m,L,ks;
int a[N];
int f[N];
int del[K];
bool tag[K];
int lasten;
inline int bel(int x){if(x==1)return 0;return (x-2)/L+1;}
inline int step(int x){return tag[bel(x)]?max(1,a[x]-del[bel(x)]):f[x];}
inline void build(int l,int r,int num){tag[num]=true;for(int i=l;i<=r;i++)f[i]=(a[i]<l)?(a[i]):(tag[num]=false,f[a[i]]);return;}
inline void init(){L=sqrt(n-1);ks=(n-1)/L;if((n-1)%L)ks++;for(int l=2,r,i=1;r=min(l+L-1,n),l<=n;l=r+1,i++)build(l,r,i);return;}
inline void Gura(int &x){x^=lasten;return;}
inline void Ame(int l,int r,int num,int x)
{
    if(!tag[num]){for(int i=l;i<=r;i++)a[i]=max(a[i]-x,1);build((num-1)*L+2,num*L+1,num);}
    else for(int i=l;i<=r;i++)f[i]=a[i]=max(a[i]-x,1);return;
}
inline void work()
{
    int typ,l,r,x;rin>>typ;
    if(typ==1)
    {
        rin>>l>>r>>x;l=max(l,2);if(l>r)return;
        int ls=bel(l),rs=bel(r);
        if(ls==rs){Ame(l,r,ls,x);return;}
        Ame(l,ls*L+1,ls,x);Ame((rs-1)*L+2,r,rs,x);
        for(int i=ls+1;i<rs;i++)if(tag[i]){del[i]+=x;if(del[i]>=(n<<1))del[i]-=n;}else Ame((i-1)*L+2,i*L+1,i,x);
    }
    else
    {
        rin>>l>>r;if(l>r)jh(l,r);
        for(;step(r)!=step(l);){r=step(r);if(bel(l)>bel(r))jh(l,r);}
        if(l>r)jh(l,r);for(;r!=l;r=max(1,a[r]-del[bel(r)]))if(l>r)jh(l,r);
        printf("%d\n",lasten=l);
    }
    
    return;
}
int main()
{
    rin>>n>>m;a[1]=f[1]=1;for(int i=2;i<=n;i++)rin>>a[i];init();for(;m;m--)work();
    return 0;
}