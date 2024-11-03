














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
    inline Rin&operator >>(char &x){for(x=gc();x!='
    inline Rin&operator >>(string &x){x.clear();for(c=gc();c>'z'||c<'a';c=gc());for(;c>='a'&&c<='z';c=gc())x.push_back(c);return *this;}
}rin;
inline void jh(int &x,int &y){if(x^y)x^=y^=x^=y;return;}
inline void jh(LL &x,LL &y){if(x^y)x^=y^=x^=y;return;}
inline int min(int x,int y){return x<y?x:y;}
inline int max(int x,int y){return x>y?x:y;}
inline LL min(LL x,LL y){return x<y?x:y;}
inline LL max(LL x,LL y){return x>y?x:y;}
const int N=4e5+3;

int ans;
int n,m;
int h[N];
vector<char>a[N];



int renumd;
int numd;
int tail;
int d[N];
int du[N];
int dfn[N];
int low[N];
int num[N];
vector<int>nxt[N];
void Tar(int now)
{
    dfn[now]=low[now]=++numd;d[++tail]=now;
    for(auto to:nxt[now])
    {
        if(!dfn[to])Tar(to),low[now]=min(low[now],low[to]);
        else if(!num[to])low[now]=min(low[now],dfn[to]);
    }
    if(dfn[now]==low[now]){renumd++;for(;d[tail]!=now;tail--)num[d[tail]]=renumd;num[d[tail--]]=renumd;}
    return;
}
void add(int x,int y){nxt[x].push_back(y);return;}
void work()
{
    rin>>n>>m;
    for(int i=1;i<=n;i++){a[i].clear();a[i].push_back('g');for(int j=1;j<=m;j++){char x;rin>>x;a[i].push_back(x);}}
    for(int i=1,j;i<=m;i++)rin>>h[i];
    for(int j=1;j<=m;j++)
    {
        int lst=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i][j]=='
            if(a[i][j-1]=='
            if(a[i][j+1]=='
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(!dfn[re(i,j)]&&a[i][j]=='
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j]=='
    for(int i=1;i<=renumd;i++)if(!du[i])ans++;printf("%d\n",ans);
    return;
}
int main()
{
    work();
    return 0;
}
