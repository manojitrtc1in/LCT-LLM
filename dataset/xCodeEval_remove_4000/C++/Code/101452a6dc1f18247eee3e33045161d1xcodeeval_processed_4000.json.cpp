

















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
    inline Rin&operator >>(bool &x){for(c=gc();c!='0'&&c!='1';c=gc());x=c-'0';return *this;}
}rin;
inline void jh(int &x,int &y){if(x^y)x^=y^=x^=y;return;}
inline void jh(LL &x,LL &y){if(x^y)x^=y^=x^=y;return;}
inline int min(int x,int y){return x<y?x:y;}
inline int max(int x,int y){return x>y?x:y;}
inline LL min(LL x,LL y){return x<y?x:y;}
inline LL max(LL x,LL y){return x>y?x:y;}
const int N=3e5+3;
int n;
inline int check(int x,int y)
{
    if(x<=n&&y<=n)return 1;
    if(x>=n&&y>=n)return 2;
    return 0;
}

int ans[N];
inline void pri(bool *a,bool *b,int A,int B)
{
    int x=check(A,B),tail=0;
    if(x==1)
    {
        int les=min((n<<1)-A,(n<<1)-B),l=1,r=1;
        for(int i=1;i<=les;i++)
        {
            for(;a[l]==1;l++)ans[++tail]=1;
            for(;b[r]==1;r++)ans[++tail]=1;
            ans[++tail]=0;l++;r++;
        }
        for(;l<=(n<<1);l++)ans[++tail]=a[l];
        for(;r<=(n<<1);r++)ans[++tail]=b[r];
    }
    else
    {
        int les=min(A,B),l=1,r=1;
        for(int i=1;i<=les;i++)
        {
            for(;a[l]==0;l++)ans[++tail]=0;
            for(;b[r]==0;r++)ans[++tail]=0;
            ans[++tail]=1;l++;r++;
        }
        for(;l<=(n<<1);l++)ans[++tail]=a[l]-0;
        for(;r<=(n<<1);r++)ans[++tail]=b[r]-0;
    }
    for(int i=1;i<=tail;i++)printf("%d",ans[i]);puts("");return;
}
bool a[N];
bool b[N];
bool c[N];
int A,B,C;
inline void work()
{
    rin>>n;A=B=C=0;
    for(int i=1;i<=(n<<1);i++)rin>>a[i],A+=a[i];
    for(int i=1;i<=(n<<1);i++)rin>>b[i],B+=b[i];
    for(int i=1;i<=(n<<1);i++)rin>>c[i],C+=c[i];
    if(check(A,B)){pri(a,b,A,B);return;}
    if(check(B,C)){pri(b,c,B,C);return;}
    if(check(A,C)){pri(a,c,A,C);return;}
    return;
}
int main()
{
    int T;for(rin>>T;T;T--)work();
    return 0;
}
