














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
const int N=3e6+19;
const int M=1e9+7;
int prpr(int x,int y){return 1LL*x*y%M;}
int ksm(int x,int y){int ans=1;for(;y;y>>=1){if(y&1)ans=prpr(ans,x);x=prpr(x,x);}return ans;}

int sl[N];
int sr[N];
int sk[N];
int inv[N];
void init()
{
    sl[0]=1;for(int i=1;i<N;i++)sl[i]=prpr(sl[i-1],i);sr[N-1]=ksm(sl[N-1],M-2);
    sr[0]=1;for(int i=N-2;i>0;i--)sr[i]=prpr(sr[i+1],i+1);
    sk[0]=sk[1]=1;for(int i=2;i<N;i++)sk[i]=prpr(M-M/i,sk[M%i]);
    inv[0]=1;for(int i=1;i<N;i++)inv[i]=prpr(sr[i],sl[i-1]);
    

    return;
}

int n,q;
int f[N][4];
void work()
{
    rin>>n>>q;
    int S=prpr(sk[2],n);
    f[1][1]=prpr((n*3)-1,S);
    f[1][2]=prpr((n*3)+1,S);
    f[1][3]=prpr((n+1)*3,S);
    

    

    for(int i=2,ed=(n*3);i<=ed;i++)
    {
        int ls=prpr(f[i-1][1],i),rs=prpr(f[i-1][2],i);S=prpr(sl[ed+1],prpr(sr[ed-i],sk[i+1]));
        

        

        f[i][1]=S;
        f[i][1]-=ls;if(f[i][1]<0)f[i][1]+=M;
        f[i][1]-=ls;if(f[i][1]<0)f[i][1]+=M;
        f[i][1]-=rs;if(f[i][1]<0)f[i][1]+=M;
        f[i][1]=prpr(f[i][1],sk[3]);
        if(f[i][1]<0)f[i][1]+=M;if(f[i][1]>=M)f[i][1]-=M;
        f[i][2]=f[i][1];f[i][2]+=ls;if(f[i][2]>=M)f[i][2]-=M;
        f[i][3]=f[i][2];f[i][3]+=rs;if(f[i][3]>=M)f[i][3]-=M;
        

    }
    for(;q;q--){rin>>S;printf("%d\n",prpr(sr[S],f[S][3]));}
    return;
}
int main()
{
    init();
    work();
    return 0;
}
