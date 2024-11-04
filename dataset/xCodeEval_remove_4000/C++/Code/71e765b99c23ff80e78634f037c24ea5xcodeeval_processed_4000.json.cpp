



using namespace std;
const int NV=105;
const int LNV=11;

const int NE=5015;
const int NQ=1000005;
const int intmax=0x7fffffff;
int f[2005];
int a[2005];
int n,m;
struct Edge
{
    int ne,y,v;
};
struct Edge2
{
    int x,y,v;
};
bool cmp(Edge2 a,Edge2 b)
{
    return a.v<b.v;
}
struct DisSet
{
    int fa[NV],nv;
    void init(int n)
    {
        nv=n;
        for(int i=0;i<n;i++) fa[i]=i;
    }
    int find(int x)
    {
        if (fa[x]==x) return x;
        return fa[x]=find(fa[x]);
    }
    void uni(int x,int y)
    {
        fa[find(x)]=find(y);
    }
};

struct Graph
{
    Edge e[NE];
    int ep,h[NV],nv,ne;
    void init(int n,int m=NE)
    {
        ne=m;
        nv=n;
        ep=2;
        memset(h,0,4*nv);
    }
    void add(int a,int b,int v=1)
    {
        e[ep].ne=h[a];
        e[ep].y=b;
        e[ep].v=v;
        h[a]=ep;
        ep++;
    }



























































































































































































































































































































































































































































































































































































































































































































































































































































































































    bool dfs(int now,int d,int t)
    {
        

        if (t==m+1)
        {
            if (d) return 1;
            return 0;
        }
        int ans=intmax;
        vector<pair<int,int> > p;
        for(int i=h[now];i;i=e[i].ne)
        {
            if (!d) if(e[i].y<f[t]) continue;
            if (e[i].v) continue;
            p.push_back(make_pair(e[i].y,i));
        }
        sort(p.begin(),p.end());
        for(int i=0;i<p.size();i++)
        {
            int key=p[i].second;
            e[key].v=1;
            e[key^1].v=1;
            if (dfs(e[key].y,(e[key].y>f[t])|d,t+1))
            {
                a[t]=e[key].y;
                return 1;
            }
            e[key].v=0;
            e[key^1].v=0;
        }

        return 0;
    }
};
Graph g;
int main()
{
    scanf("%d%d",&n,&m);
    g.init(n,m);
    int la;
    scanf("%d",&la);
    f[0]=la;
    for(int i=1;i<=m;i++)
    {
        int a;
        scanf("%d",&a);
        g.add(la,a,0);
        g.add(a,la,0);
        la=a;
        f[i]=a;
    }
    if (g.dfs(f[0],0,1))
    {
        printf("%d",f[0]);
        for(int i=1;i<=m;i++) printf(" %d",a[i]);
        puts("");
    }
    else puts("No solution");
}
