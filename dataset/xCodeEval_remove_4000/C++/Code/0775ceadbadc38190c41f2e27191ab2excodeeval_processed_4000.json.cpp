














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
const int N=1e2+3;
const int M=1e9+7;

int n,q;
int b[N];
int c[N];
LL d[N];

int smb[N];
int smc[N];

int x;
int ans;
int f[N][N*N];
int g[N][N*N];


inline void work()
{
    

    rin>>n;for(int i=1;i<=n;i++)rin>>c[i];for(int i=1;i<n;i++)rin>>b[i];
    rin>>q>>x;for(int i=1;i<=n;i++)smb[i]=smb[i-1]+b[i],smc[i]=smc[i-1]+c[i];
    for(int i=1;i<=n;i++){d[i]=d[i-1]+x+smb[i-1];if(d[i]>smc[i]){puts("0");return;}}
    for(int i=1;i<=n;i++)d[i]=max(d[i],0LL);
    

    for(int i=0;i<=smc[1];i++)g[0][i]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=d[i];j<=smc[i];j++){f[i][j]=g[i-1][j]-((j-c[i]-1<0)?0:g[i-1][j-c[i]-1]);lmod(f[i][j]);}
        if(i==n)for(int j=d[i];j<=smc[i];j++){ans+=f[i][j];rmod(ans);}
        else for(int j=0;j<=smc[i+1];j++){g[i][j]=((j==0)?f[i][j]:g[i][j-1]+f[i][j]);rmod(g[i][j]);}

        

    }
    printf("%d\n",ans);
    return;
}
int main()
{
    work();
    return 0;
}
