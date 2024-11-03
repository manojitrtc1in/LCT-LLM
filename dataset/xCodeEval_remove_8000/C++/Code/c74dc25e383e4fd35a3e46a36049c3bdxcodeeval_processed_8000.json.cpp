


























using namespace std;

struct Edge{
    int u, v, w;
}e[N];

inline bool operator<(Edge x, Edge y){
    return x.w<y.w;
}

int m, n, u, v, w, par[N], wG[N], sz[N], ans, root[N];

inline int find_root(int x){
    if(x==root[x]) return x;
    else return root[x]=find_root(root[x]);
}

inline int get(int u, int v, int w){
    while(u!=v){
        if((wG[u]==w)||(wG[v]==w)) return 1;
        u=par[u];
        v=par[v];
    }
    return 0;
}

inline void Unify(int u, int v, int w){
    if(u!=v){
        int x=par[v], t=wG[v];
        par[v]=u; wG[v]=w;
        root[v]=root[u];
        Unify(v, x, t);
    }
}

inline void id1(int u, int v, int w){
    int id2=find_root(u), id0=find_root(v);
    if (id2!=id0){
        if(sz[id2]>=sz[id0]){
            Unify(u,v,w);
            sz[id2]+=sz[id0];
        }
        else{
            Unify(v,u,w);
            sz[id0]+=sz[id2];
        }
    }
    else ans+=get(u, v, w);
}

inline void Read(){
    scanf("%d%d",&n, &m);
    rep(i,m){
        scanf("%d%d%d", &u, &v, &w);
        e[i].u=u;
        e[i].v=v;
        e[i].w=w;
    }
}

int main(){
    Read();
    sort(e, e+m);
    rep(i,n) {
        par[i+1]=i+1;
        sz[i+1]=1;
        root[i+1]=i+1;
    }
    rep(i,m) id1(e[i].u, e[i].v, e[i].w);
    printf("%d", ans);
    return 0;
}










