








using namespace std;

namespace Solve1
{
    const int _N=55;
    const int _M=310;
    const int _L=20;
    
    int n,m,numE,Min,Max,Fir[_N];
    int ed[_M],val[_M],Next[_M];
    int to[_N][_L][2],D[_N];
    double dis[_N][_L],ans;
    int now[_N];
    
    void AddE(int X,int Y,int Z)
    {
        ed[++numE]=Y,val[numE]=Z,Next[numE]=Fir[X],Fir[X]=numE;
        Min=min(Min,Z),Max=max(Max,Z),++D[Y];
    }
    
    double Sqr(double s0)
    {
        return s0*s0;
    }
    
    void Find(double v0)
    {
        static int Queue[_N],L,R;
        for(int i=1;i<=n;i++)
            now[i]=D[i];
        for(int i=1;i<=n;i++)
            for(int j=0;j<_L;j++)
                dis[i][j]=-1;
        L=R=0,dis[1][0]=1;
        for(int i=1;i<=n;i++)
            if(!now[i])
                Queue[++R]=i;
        while(true)
        {
            static int u;
            u=Queue[++L];
            if(u==n)
                break;
            for(int e=Fir[u];e;e=Next[e])
            {
                static int v;
                v=ed[e];
                --now[v];
                for(int i=1;i<_L;i++)
                    if(dis[u][i-1]!=-1&&(dis[u][i-1]+Sqr(v0-val[e])<dis[v][i]||dis[v][i]==-1))
                        dis[v][i]=dis[u][i-1]+Sqr(v0-val[e]),to[v][i][0]=u,to[v][i][1]=e;
                if(!now[v])
                    Queue[++R]=v;
            }
        }
        static int Stack[_L],top;
        for(int i=1;i<_L;i++)
        {
            top=0;
            if(dis[n][i]!=-1)
            {
                static int at;
                static double sum,re;
                at=n,sum=0;
                for(int j=i;j>=1;j--)
                {
                    Stack[++top]=val[to[at][j][1]];
                    sum+=Stack[top];
                    at=to[at][j][0];
                }
                re=sum/i,sum=0;
                for(int j=1;j<=top;j++)
                    sum+=Sqr(re-Stack[j]);
                sum=sum/i;
                ans=min(ans,sum);
            }
        }
    }
    
    int main()
    {
        scanf("%d%d",&n,&m);
        static int x,y,z;
        Min=_N,Max=0;
        for(int i=1;i<=m;i++)
            scanf("%d%d%d",&x,&y,&z),AddE(x,y,z);
        ans=1000000000;
        for(double v0=Min;v0<=Max;v0+=0.00125)
            Find(v0);
        printf("%.4lf",ans);
        return 0;
    }
}

namespace Solve2
{
    const int _N=55;
    const int _M=310;
    const int _L=20;
    
    int n,m,numE,Min,Max,Fir[_N];
    int ed[_M],val[_M],Next[_M];
    int to[_N][_L][2],D[_N];
    double dis[_N][_L],ans;
    int now[_N];
    
    void AddE(int X,int Y,int Z)
    {
        ed[++numE]=Y,val[numE]=Z,Next[numE]=Fir[X],Fir[X]=numE;
        Min=min(Min,Z),Max=max(Max,Z),++D[Y];
    }
    
    double Sqr(double s0)
    {
        return s0*s0;
    }
    
    double Find(double v0)
    {
        static int Queue[_N],L,R;
        for(int i=1;i<=n;i++)
            now[i]=D[i];
        for(int i=1;i<=n;i++)
            for(int j=0;j<_L;j++)
                dis[i][j]=-1;
        L=R=0,dis[1][0]=1;
        for(int i=1;i<=n;i++)
            if(!now[i])
                Queue[++R]=i;
        while(true)
        {
            static int u;
            u=Queue[++L];
            if(u==n)
                break;
            for(int e=Fir[u];e;e=Next[e])
            {
                static int v;
                v=ed[e];
                --now[v];
                for(int i=1;i<_L;i++)
                    if(dis[u][i-1]!=-1&&(dis[u][i-1]+Sqr(v0-val[e])<dis[v][i]||dis[v][i]==-1))
                        dis[v][i]=dis[u][i-1]+Sqr(v0-val[e]),to[v][i][0]=u,to[v][i][1]=e;
                if(!now[v])
                    Queue[++R]=v;
            }
        }
        static int Stack[_L],top;
        ans=1000000000;
        for(int i=1;i<_L;i++)
        {
            top=0;
            if(dis[n][i]!=-1)
            {
                static int at;
                static double sum,re;
                at=n,sum=0;
                for(int j=i;j>=1;j--)
                {
                    Stack[++top]=val[to[at][j][1]];
                    sum+=Stack[top];
                    at=to[at][j][0];
                }
                re=sum/i,sum=0;
                for(int j=1;j<=top;j++)
                    sum+=Sqr(re-Stack[j]);
                sum=sum/i;
                ans=min(ans,sum);
            }
        }
        return ans;
    }
    
    int main()
    {
        scanf("%d%d",&n,&m);
        static int x,y,z;
        Min=_N,Max=0;
        for(int i=1;i<=m;i++)
            scanf("%d%d%d",&x,&y,&z),AddE(x,y,z);
        static double L,R;
        L=Min,R=Max;
        for(int times=1;times<=500;times++)
        {
            static double M1,M2;
            M1=(2*L+R)/3,M2=(L+2*R)/3;
            if(Find(M1)>Find(M2))
                L=M1;
            else
                R=M2;
        }
        printf("%.4lf",min(Find(L),Find(R)));
        return 0;
    }
}

namespace Solve3
{
    const int _N=100010;
    
    int num[_N<<1];
    int n,v0,s[_N];
    
    int main()
    {
        scanf("%d%d",&n,&v0);
        static int pla;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",s+i);
            if(s[i]==v0)
                pla=i;
        }
        for(int i=1;i<=n;i++)
        {
            if(i==pla)
                s[i]=s[i-1];
            else if(s[i]>v0)
                s[i]=s[i-1]+1;
            else
                s[i]=s[i-1]-1;
        }
        for(int i=pla;i<=n;i++)
            ++num[s[i]+n];
        static int ans;
        ans=0;
        for(int i=0;i<pla;i++)
            ans+=num[s[i]+n];
        printf("%d\n",ans);
        return 0;
    }
}

namespace Solve4
{
    const int _N=110;
    
    int n,m;
    int s[_N][_N];
    
    void Change(int type)
    {
        static int f[_N][_N];
        static double x0,y0,d0;
        x0=(double)(n+1)/2,y0=(double)(m+1)/2,d0=(double)(n-m)/2;
        if(type==0)
        {
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                    f[(int)(x0-y0+j-d0)][(int)(x0+y0-i+d0)]=s[i][j];
            swap(n,m);
        }
        if(type==1)
        {
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                    f[(int)(y0+x0-j-d0)][(int)(y0-x0+i+d0)]=s[i][j];
            swap(n,m);
        }
        if(type==2)
        {
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                    f[i][(int)(y0*2-j)]=s[i][j];
        }
        if(type==3)
        {
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                    f[(int)(x0*2-i)][j]=s[i][j];
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                s[i][j]=f[i][j];
    }
    
    int main()
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",s[i]+j);
        static char Get[_N];
        scanf("%s",Get+1);
        for(int i=1;Get[i];i++)
            Change(Get[i]-'A');
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                printf("%d%c",s[i][j],j^m?' ':'\n');
        return 0;
    }
}

namespace Solve5
{
    int main()
    {
        srand((unsigned)time(NULL));
        printf("%d\n",rand()%8);
        return 0;
    }
}

namespace Solve6
{
    const int _N=100010;
    const int _M=_N<<1;
    const int INF=1000000000;
    
    int n,m,s,t,numE,Fir[_N];
    int ed[_M],top[_M],Next[_M];
    
    void AddE(int X,int Y,int Z)
    {
        ed[++numE]=Y,top[numE]=Z,Next[numE]=Fir[X],Fir[X]=numE;
        ed[++numE]=X,top[numE]=0,Next[numE]=Fir[Y],Fir[Y]=numE;
    }
    
    int id0()
    {
        static int lastE[_N],nowE[_N],Floor[_N],numF[_N];
        for(int i=s;i<=t;i++)
            lastE[i]=Floor[i]=numF[i]=0,nowE[i]=Fir[i];
        static int u,re;
        re=0,u=s,numF[0]=n+m+2;
        while(Floor[s]^n+m+1)
        {
            static int e,v;
            for(e=nowE[u];e;e=Next[e])
            {
                v=ed[e];
                if(Floor[u]==Floor[v]+1)
                    break;
            }
            if(e)
            {
                nowE[u]=lastE[v]=e,u=v;
                if(u==t)
                {
                    static int more;
                    more=INF;
                    while(u^s)
                        more=min(more,top[lastE[u]^1]),u=ed[lastE[u]^1];
                    u=t;
                    while(u^s)
                        top[lastE[u]^1]-=more,top[lastE[u]]+=more,u=ed[lastE[u]^1];
                    re+=more;
                }
            }
            else
            {
                --numF[Floor[u]];
                if(!numF[Floor[u]])
                    break;
                Floor[u]=n+m,nowE[u]=Fir[u];
                for(e=nowE[u];e;e=Next[e])
                {
                    v=ed[e];
                    if(Floor[u]>Floor[v]+1)
                        Floor[u]=Floor[v]+1;
                }
                ++numF[Floor[u]];
                if(u^s)
                    u=ed[lastE[u]^1];
            }
        }
        return re;
    }
    
    int main()
    {
        scanf("%d%d",&n,&m);
        s=0,t=n+m+1;
        for(int i=1;i<=n;i++)
            AddE(s,i,2);
        for(int i=1;i<=m;i++)
            AddE(i+n,t,1);
        static int x,y;
        for(int i=1;i<=m;i++)
            scanf("%d%d",&x,&y),AddE(x,i,INF),AddE(y,i,INF);
        return 0;
    }
}

namespace Solve7
{
    int main()
    {
        while(1)
            printf("%u\n",(unsigned)time(NULL)*10000);
        return 0;
    }
}

namespace Solve8
{
    const int N=510;
    const int M=124800;
    
    int numE,link[N];
    int ans,match[N],fa[N],typ[N];
    int n,m,T[N],next[2*M],ed[2*M];
    
    void Add(int X,int Y)
    {
        next[++numE]=T[X],ed[numE]=Y,T[X]=numE;
        return;
    }
    
    void Read_in()
    {
        int x,y;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
            scanf("%d%d",&x,&y),Add(x,y),Add(y,x);
        return;
    }
    void Put_out()
    {
        printf("%d\n",ans);
        for(int i=1;i<=n;i++)
            printf("%d%c",match[i],i^n?' ':'\n');
        return;
    }
    
    int Queue[N],qL,qR;
    bool vis[N];
    
    int id1(int X,int Y)
    {
        X=fa[X],Y=fa[Y];
        for(int i=1;i<=n;i++)
            vis[i]=false;
        while(true)
        {
            if(X)
            {
                if(vis[X])
                    return X;
                vis[X]=true;
                X=match[X]?fa[link[match[X]]]:0;
            }
            swap(X,Y);
        }
    }
    
    void Shrink(int X,int Y,int Z)
    {
        while(fa[X]!=Z)
        {
            link[X]=Y;
            if(typ[match[X]])
                typ[match[X]]=0,Queue[++qR]=match[X];
            if(fa[X]==X)
                fa[X]=Z;
            if(fa[match[X]]==match[X])
                fa[match[X]]=Z;
            Y=match[X];
            X=link[match[X]];
        }
        return;
    }
    
    void Change()
    {
        for(int i=1;i<=n;i++)
            fa[i]=fa[fa[i]];
        return;
    }
    
    bool Check(int S)
    {
        for(int i=1;i<=n;i++)
            typ[i]=-1,fa[i]=i;
        qL=1,qR=0;
        Queue[++qR]=S,typ[S]=0;
        while(qL<=qR)
        {
            int X=Queue[qL++];
            for(int e=T[X];e;e=next[e])
            {
                int Y=ed[e];
                if(typ[Y]==-1)
                {
                    link[Y]=X,typ[Y]=1;
                    if(!match[Y])
                    {
                        int now=Y;
                        while(now)
                        {
                            int save=match[link[now]];
                            match[now]=link[now],match[link[now]]=now;
                            now=save;
                        }
                        return true;
                    }
                    typ[match[Y]]=0,Queue[++qR]=match[Y];
                    continue;
                }
                if(fa[X]!=fa[Y]&&typ[Y]^1)
                {
                    int Z=id1(X,Y);
                    Shrink(X,Y,Z);
                    Shrink(Y,X,Z);
                    Change();
                }
            }
        }
        return false;
    }
    
    void id2()
    {
        for(int i=1;i<=n;i++)
            if(!match[i]&&Check(i))
                ans++;
        return;
    }
    
    int main()
    {
        Read_in();
        id2();
        Put_out();
        return 0;
    }
}

namespace Solve9
{
    int main()
    {
        static int p[15];
        srand(4073);
        for(int i=1;i<=7;i++)
            p[i]=i,swap(p[i],p[rand()%i+1]);
        for(int i=1;i<=7;i++)
            printf("%d\n",p[i]);
        return 0;
    }
}

namespace Solve10
{
    const int _N=100010;
    const int INF=1000000000;
    const double Alpha=0.75;
    
    int n,h[_N],a[_N],b[_N];
    
    namespace Scapegoat_Tree
    {
        int son[_N][2],v[_N],s[_N];
        int Size[_N],SizeAll,root;
        
        int _p[_N],_size;
        
        void Dfs(int pla)
        {
            if(!pla)
                return;
            Dfs(son[pla][0]);
            _p[++_size]=pla;
            Dfs(son[pla][1]);
        }
        
        void Build(int &pla,int L,int R)
        {
            if(L>R)
            {
                pla=0;
                return;
            }
            int M=L+R>>1;
            pla=_p[M],Size[pla]=1;
            Build(son[pla][0],L,M-1);
            Build(son[pla][1],M+1,R);
            Size[pla]+=Size[son[pla][0]]+Size[son[pla][1]];
        }
        
        void Rebuild(int &pla)
        {
            _size=0,Dfs(pla);
            Build(pla,1,_size);
        }
        
        void Insert(int &pla,int val,int save)
        {
            if(!pla)
            {
                pla=++SizeAll,v[pla]=val,s[pla]=save,Size[pla]=1;
                return;
            }
            ++Size[pla];
            if(val<v[pla])
                Insert(son[pla][0],val,save);
            else
                Insert(son[pla][1],val,save);
            if(max(Size[son[pla][0]],Size[son[pla][1]])>(int)(Alpha*Size[pla]))
                Rebuild(pla);
        }
        
        int Query(int pla,int val)
        {
            if(val==v[pla])
                return Size[son[pla][0]]+1;
            if(val<v[pla])
                return Query(son[pla][0],val);
            return Query(son[pla][1],val)+Size[son[pla][0]]+1;
        }
        
        int Find(int pla,int rank)
        {
            if(rank==Size[son[pla][0]]+1)
                return s[pla];
            if(rank<Size[son[pla][0]]+1)
                return Find(son[pla][0],rank);
            return Find(son[pla][1],rank-Size[son[pla][0]]-1);
        }
        
        void Add(int val,int save)
        {
            Insert(root,val,save);
        }
        
        int Ask(int val)
        {
            return Query(root,val);
        }
        
        int Get(int rank)
        {
            if(rank<1||rank>SizeAll)
                return 0;
            return Find(root,rank);
        }
    }
    
    namespace Treap
    {
        int son[_N][2],v[_N],s[_N],e[_N];
        int Size[_N],SizeAll,root;
        
        void pushup(int pla)
        {
            Size[pla]=Size[son[pla][0]]+Size[son[pla][1]]+1;
        }
        
        void Rotate(int &pla,int type)
        {
            static int save;
            save=son[pla][type];
            son[pla][type]=son[save][type^1];
            son[save][type^1]=pla;
            pushup(pla),pushup(save);
            pla=save;
        }
        
        void Insert(int &pla,int val,int save)
        {
            if(!pla)
            {
                pla=++SizeAll,v[pla]=val,s[pla]=save,e[pla]=rand(),Size[pla]=1;
                return;
            }
            static int type;
            ++Size[pla];
            if(val<v[pla])
                Insert(son[pla][0],val,save),type=0;
            else
                Insert(son[pla][1],val,save),type=1;
            if(e[son[pla][type]]>e[pla])
                Rotate(pla,type);
        }
        
        int Query(int pla,int val)
        {
            if(val==v[pla])
                return Size[son[pla][0]]+1;
            if(val<v[pla])
                return Query(son[pla][0],val);
            return Query(son[pla][1],val)+Size[son[pla][0]]+1;
        }
        
        int Find(int pla,int rank)
        {
            if(rank==Size[son[pla][0]]+1)
                return s[pla];
            if(rank<Size[son[pla][0]]+1)
                return Find(son[pla][0],rank);
            return Find(son[pla][1],rank-Size[son[pla][0]]-1);
        }
        
        void Add(int val,int save)
        {
            Insert(root,val,save);
        }
        
        int Ask(int val)
        {
            return Query(root,val);
        }
        
        int Get(int rank)
        {
            if(rank<1||rank>SizeAll)
                return 0;
            return Find(root,rank);
        }
    }
    
    int base;
    
    inline bool see(const int &i,const int &j)
    {
        if(abs(h[i]-base)==abs(h[j]-base))
            return h[i]<h[j];
        return abs(h[i]-base)<abs(h[j]-base);
    }
    
    void Init0()
    {
        srand((long long)n*INF%2333333);
        for(int i=n;i>=1;i--)
        {
            Treap::Add(h[i],i);
            if(i==n)
                a[i]=b[i]=0;
            else if(i==n-1)
                a[i]=0,b[i]=n;
            else
            {
                static int pla[5];
                pla[4]=Treap::Ask(h[i]);
                pla[0]=Treap::Get(pla[4]-2);
                pla[1]=Treap::Get(pla[4]-1);
                pla[2]=Treap::Get(pla[4]+1);
                pla[3]=Treap::Get(pla[4]+2);
                base=h[i],sort(pla,pla+4,see);
                a[i]=pla[1],b[i]=pla[0];
            }
        }
       

           

    }
    
    int f[_N][20],g[2][_N][20];
    
    void Init1()
    {
        for(int i=n;i>=1;i--)
        {
            f[i][0]=b[a[i]],g[0][i][0]=abs(h[i]-h[a[i]]),g[1][i][0]=abs(h[a[i]]-h[b[a[i]]]);
            for(int j=1;;j++)
            {
                if(!f[f[i][j-1]][j-1])
                    break;
                f[i][j]=f[f[i][j-1]][j-1],g[0][i][j]=g[0][i][j-1]+g[0][f[i][j-1]][j-1],g[1][i][j]=g[1][i][j-1]+g[1][f[i][j-1]][j-1];
            }
        }
    }
    
    pair<int,int> Calc(int now,int Limit)
    {
        static int re_a,re_b;
        re_a=re_b=0;
        for(int i=18;i>=0;i--)
            if(f[now][i]&&g[0][now][i]+g[1][now][i]<=Limit)
                re_a+=g[0][now][i],re_b+=g[1][now][i],Limit-=g[0][now][i]+g[1][now][i],now=f[now][i];
        if(a[now]&&abs(h[now]-h[a[now]])<=Limit)
            re_a+=abs(h[now]-h[a[now]]);
        return make_pair(re_a,re_b);
    }
    
    void Solve0()
    {
        static int Limit,re;
        scanf("%d",&Limit);
        static double Ans,id3;
        Ans=INF+10;
        for(int i=1;i<=n;i++)
        {
            static pair<int,int> Get;
            Get=Calc(i,Limit),id3=Get.second?(double)Get.first/Get.second:INF;
            if(id3<Ans)
                Ans=id3,re=i;
        }
        printf("%d\n",re);
    }
    
    void Solve1()
    {
        static int Limit,st,m;
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&st,&Limit);
            static pair<int,int> Get;
            Get=Calc(st,Limit),printf("%d %d\n",Get.first,Get.second);
        }
    }
    
    int main()
    {
        scanf("%d",&n),h[0]=INF;
        for(int i=1;i<=n;i++)
            scanf("%d",h+i);
        Init0();
        Init1();
        Solve0();
        Solve1();
        return 0;
    }
}

namespace Solve11
{
    int n,m,f[1100][1100];
    
    int main()
    {
        scanf("%d%d",&n,&m);
        f[1][1]=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i-j<n-m)
                    f[i][j]+=f[i-1][j]+f[i][j-1];
        printf("%d\n",f[n][n]);
        return 0;
    }
}

namespace Solve12
{
    int main()
    {
        freopen("233.txt","w",stdout);
        printf("0\n100000\n");
        for(int i=1;i<=100000;i++)
        {
            static int now;
            if(i==1)
                now=0;
            else if(i<4)
                now=1;
            else
                now=i-3;
            

            printf("%d %d %d\n",now,i==1?0:10000,0);
        }
    }
}

namespace Solve13
{
    const int maxn = 1000001;
    
    struct edge {
    	int v, num;
    	edge *next;
    	edge(int _v, int _num, edge *_next)
    	: v(_v), num(_num), next(_next)  { }
    };
    
    int n, m, p = 0, num = 0, ans = 0,
    	color[maxn], prt[maxn], dep[maxn], cnt1[maxn], cnt2[maxn];
    bool flag[maxn];
    edge *E[maxn];
    
    void dfs(int u, int c) {
    	color[u] = c;
    	for (edge *e = E[u]; e; e = e->next)
    		if (!color[e->v]) {
    			dep[e->v] = dep[u] + 1;
    			prt[e->v] = e->num;
    			dfs(e->v, -c);
    			cnt1[u] += cnt1[e->v];
    			cnt2[u] += cnt2[e->v];
    		} else if (dep[e->v] +1 < dep[u]) {
    			if (color[e->v] == c) {
    				++ p;
    				num = e->num;
    				++ cnt1[u],  -- cnt1[e->v];
    			} else {
    				++ cnt2[u],  -- cnt2[e->v];
    			}
    		}
    }
    
    int main() {
    	scanf("%d%d", &n, &m);
    	for (int i = 1, u, v; i <= m; ++ i) {
    		scanf("%d%d", &u, &v);
    		E[u] = new edge(v, i, E[u]);
    		if(u^v)
    		E[v] = new edge(u, i, E[v]);
    	}
    	for (int i = 1; i <= n; ++ i)
    		if (!color[i])  dfs(i, 1);
    	if (!p) {
    		for (int i = 1; i <= m; ++ i)  flag[i] = true;
    	} else {
    		if (p == 1)  flag[num] = true;
    		for (int i = 1; i <= n; ++ i)
    			if (cnt1[i] == p && !cnt2[i])  flag[prt[i]] = true;
    	}
    	for (int i = 1; i <= m; ++ i)
    		if (flag[i])  ++ ans;
    	printf("%d\n", ans);
    	static int QAQ;
    	for (int i = 1; i <= m; ++ i)
    		if (flag[i]&&!QAQ)  
    			printf("%d",i),QAQ=1;
    		else if(flag[i]&&QAQ)
    			printf(" %d",i);
    	if(ans)
            printf("\n");
    	return 0;
    }
}

namespace Solve14
{
    
    
    
    
    
    
    
    
    using namespace std;
    
    const int len=200000;
    inline char nc(){
    	static char buf[len],*b=buf+len;
    	if (b==buf+len) fread(buf,1,len,stdin),b=buf;
    	return *b++;
    }
    int IN(){
    	int c,f,x;
    	while (!isdigit(c=nc())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
    	while (isdigit(c=nc())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
    }
    void write(int x){
    	if (x>=10) write(x/10);
    	putchar(x%10+'0');
    }
    
    typedef long long ll;
    typedef double db;
    typedef pair<int,int> pii;
    typedef vector<int> Vi;
    
    const int N=1000000+19;
    
    Vi V;
    struct edge {int x,y;} e[N];
    int top,n,m;
    
    struct USet{
    	int fa[N],rk[N],d[N],S[2*N];
    	int getf(int x){
    		return fa[x]==x?x:getf(fa[x]);
    	}
    	int getdis(int x){
    		int res=0;
    		while (fa[x]!=x) res^=d[x],x=fa[x];
    		return res;
    	}
    	void Union(int x,int y,int dis){
    		x=getf(x),y=getf(y);
    		if (rk[x]>rk[y]) swap(x,y);
    		if (rk[x]==rk[y]) rk[y]++,S[++top]=-y;
    		fa[x]=y;d[x]=dis;S[++top]=x;
    	}
    	void Resume(int pre){
    		while (top!=pre){
    			int x=S[top--];
    			if (x>0) fa[x]=x,d[x]=0;else rk[-x]--;
    		}
    	}
    } U;
    
    bool calc(int L,int R){
    	For(i,L,R+1){
    		int x=e[i].x,y=e[i].y,d;
    		d=U.getdis(x)^U.getdis(y);
    		if (U.getf(x)==U.getf(y)){
    			if (!d) return 0;
    		} else{
    			U.Union(x,y,d^1);
    		}
    	}
    	return 1;
    }
    void work(int L,int R){
    	if (L==R){
    		V.pb(L);return;
    	}
    	int pre=top;
    	if (calc(Mid+1,R)) work(L,Mid);
    	U.Resume(pre);
    	if (calc(L,Mid)) work(Mid+1,R);
    	U.Resume(pre);
    }
    
    int main(){
        freopen("use_in.txt","r",stdin);
    	n=IN(),m=IN();
    	For(i,1,m+1) e[i]=(edge){IN(),IN()};
    	For(i,1,n+1) U.fa[i]=i;
    	if (m==0) return puts("0"),0;
    	work(1,m);
    	printf("%d\n",V.size());
    	For(i,0,V.size()){
    		write(V[i]);
    		putchar(" \n"[i==V.size()-1]);
    	}
    }
}

namespace Solve15
{
    const int _N=1000010;
    
    int Fir[_N],ed[_N],Next[_N],numE;
    int n,m,color[_N],num0[_N],num1[_N];
    int fa[_N],last[_N],numP,re,stack[_N];
    bool flag[_N],vis[_N];
    
    void AddE(int x,int y)
    {
        ed[++numE]=y,Next[numE]=Fir[x],Fir[x]=numE;
        ed[++numE]=x,Next[numE]=Fir[y],Fir[y]=numE;
    }
    
    void Dfs(int u,int colNow)
    {
        color[u]=colNow;
        for(int e=Fir[u];e;e=Next[e])
        {
            int v=ed[e];
            if(v==fa[u]||vis[e])
                continue;
            vis[e]=vis[e^1]=true;
            if(!color[v])
                last[v]=e>>1,fa[v]=u,Dfs(v,-colNow),num0[u]+=num0[v],num1[u]+=num1[v];
            else if(color[v]==colNow)
                ++numP,re=e>>1,++num0[u],--num0[v];
            else
                ++num1[u],--num1[v];
        }
    }
    
    int main()
    {
        scanf("%d%d",&n,&m),numE=1;
        static int x,y;
        for(int i=1;i<=m;i++)
            scanf("%d%d",&x,&y),AddE(x,y);
        for(int i=1;i<=n;i++)
            if(!color[i])
                Dfs(i,1);
        if(!numP)
            for(int i=1;i<=m;i++)
                flag[i]=true;
        else
        {
            if(numP==1)
                flag[re]=true;
            for(int i=1;i<=n;i++)
                if(num0[i]==numP&&!num1[i])
                    flag[last[i]]=true;
        }
        re=0;
        for(int i=1;i<=m;i++)
            if(flag[i])
                stack[++re]=i;
        printf("%d\n",re);
        for(int i=1;i<=re;i++)
            printf("%d%c",stack[i],i^re?' ':'\n');
        return 0;
    }
}

int main()
{
   

   

   

   

   

   

   

   

   

   

   

   

   

   

    return Solve15::main();
}