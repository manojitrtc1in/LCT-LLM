

















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
int n,m;
int u[N];
int v[N];
int w[N];
int f[N];
int du[N];
int num[N];
map<int,bool>qy[N];
vector<pair<int,int> >d;
inline bool id0(int x,int y){return w[x]<w[y];}
inline int find(int i){return f[i]==i?i:(f[i]=find(f[i]));}
inline void work()
{
    rin>>n>>m;for(int i=1;i<=n;i++)f[i]=i,du[i]=n-1;
    int val=0;bool tag=false;
    for(int i=1;i<=m;i++)
    {
        rin>>u[i]>>v[i]>>w[i];qy[u[i]][v[i]]=qy[v[i]][u[i]]=true;
        val^=w[i];num[i]=i;du[u[i]]--;du[v[i]]--;
    }
    sort(num+1,num+m+1,id0);
    
    if((1LL*n*(n-1)>>1)>=n+m)
    {
        int st=0;
        for(int i=1;i<=n;i++)if(du[i]>du[st])st=i;
        for(int i=1;i<=n;i++)if(!qy[i][st])f[find(i)]=st;
        for(int i=1;i<=n;i++)
        if(find(i)!=st)
        {
            for(int j=1;j<=n&&find(i)!=st;j++)if(find(j)!=find(i)&&!qy[i][j])f[find(i)]=find(j);
        }
        LL ans=0;
        for(int i=1;i<=m;i++){int now=num[i];if(find(u[now])!=find(v[now]))ans+=w[now],f[find(u[now])]=find(v[now]);}
        printf("%lld\n",ans);
        return;
    }

    LL ans=0x3f3f3f3f3f3f3f3f;
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(!qy[i][j])d.push_back(make_pair(i,j));
    for(vector<pair<int,int> >::iterator to=d.begin(),i;to!=d.end();to++)
    {
        LL sum=0;for(int j=1;j<=n;j++)f[j]=j;
        for(i=d.begin();i!=d.end();i++)if(i!=to)f[find(i->first)]=find(i->second);
        int j;for(j=1;j<=m;j++){int now=num[j];if(w[now]>=val)break;if(find(u[now])!=find(v[now]))f[find(u[now])]=find(v[now]),sum+=w[now];}
        if(find(to->first)!=find(to->second))f[find(to->first)]=find(to->second),sum+=val;
        for(;j<=m;j++){int now=num[j];if(find(u[now])!=find(v[now]))f[find(u[now])]=find(v[now]),sum+=w[now];}
        ans=min(ans,sum);
    }
    printf("%lld\n",ans);
    return;
}
int main()
{
    work();
    return 0;
}
