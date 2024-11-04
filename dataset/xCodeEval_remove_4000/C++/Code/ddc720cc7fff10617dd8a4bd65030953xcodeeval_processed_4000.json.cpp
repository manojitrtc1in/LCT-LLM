




























using namespace std;




























































































































































































































int sz[MX];
int removed[MX];
int rm;
vector<int>adj[MX];
vector<int>cst[MX];

int tot;
void dfs_sz(int u,int papa) {
    sz[u]=1;
    tot++;
    for(auto v:adj[u]) {
        if(v==papa || removed[v]==rm) continue;
        dfs_sz(v,u);
        sz[u]+=sz[v];
    }
}

int find_center(int u,int papa) {
    for(auto v:adj[u]) {
        if(v==papa||removed[v]==rm) continue;
        if(sz[v]>(tot/2)) return find_center(v,u);
    }
    return u;
}

int n,l,r;
int need,suru,ses;

int val[MX];
int nam[MX];

int tree[2*MX];

void update(int idx,int val) {
    idx--;
    for(tree[idx+=n]=val; idx>1; idx>>=1) {
        tree[idx>>1] = Max(tree[idx],tree[idx^1]);
    }
}

int query(int x,int y) {
    int ret = -inf;
    x--;
    for(x+=n,y+=n; x<y; x>>=1,y>>=1) {
        if(x&1) ret=Max(ret,tree[x]),x++;
        if(y&1) --y,ret=Max(ret,tree[y]);
    }
    return ret;
}

int mxlev;
int root;
int ret;


void go(int u,int papa,int lev,int c) {

    if(lev>r) return;

     if(lev>mxlev) {
        mxlev=lev;
        val[lev]=c;
        nam[lev]=u;
        update(lev,c);
    } else if(val[lev]<c) {
        val[lev]=c;
        nam[lev]=u;
        update(lev,c);
    }

    repv(i,adj[u]) {
        int v  = adj[u][i];
        int cc = cst[u][i];
        if(v==papa || removed[v]==rm) continue;
        go(v,u,lev+1,c+(cc>=need?1:-1));
    }
}

inline void find(int u,int papa,int lev,int c)
{
    if(lev>r) return;

    if(lev>=l && lev<=r && c>=0) {
        ret = 1;
        ses  = u;
        return;
    }

    if(lev<l) {
        int x = l-lev;
        int y = min(r-lev,mxlev);
        if(x<=y) {
            int mx = query(x,y);
            if(mx+c>=0) {
                ret=1;
                ses = u;
                return;
            }
        }
    }
    else
    {
        int x = 1;
        int y = r-lev;
        y = Min(y,mxlev);
        if(x<=y) {
            int mx = query(x,y);
            if(mx+c>=0) {
                ret=1;
                ses = u;
                return;
            }
        }
    }

    repv(i,adj[u])    {
        int v  = adj[u][i];
        int cc = cst[u][i];
        if(v==papa || removed[v]==rm) continue;
        find(v,u,lev+1,c+(cc>=need?1:-1));
        if(ret) return;
    }
}

inline void calculate(int u) {
    root  = u;
    mxlev = 0;
    repv(i,adj[u]) {
        int  v = adj[u][i];
        if(removed[v]==rm) continue;
        find(v,u,1,(cst[u][i]>=need)?1:-1);   if(ret) return;
        go(v,u,1,(cst[u][i]>=need)?1:-1);     if(ret) return;
    }
}


void dfs(int center) {
    tot=0;
    dfs_sz(center,-1);
    center = find_center(center,-1);
    removed[center] = rm;
    calculate(center);
    if(ret) return;
    for(auto v:adj[center]){
        if(removed[v]==rm) continue;
        dfs(v);
        if(ret) return;
    }
}

int median;

void show(int u,int papa,int lev,int c) {
    if(papa!=-1 && lev>=l && lev<=r && c>=0) {
        PII(ses,u);
        exit(0);
    }
    repv(i,adj[u]) {
        int v = adj[u][i];
        if(v==papa) continue;
        int cc = cst[u][i];
        if(cc>=median) cc= 1;
        else           cc=-1;
        show(v,u,lev+1,c+cc);
    }
}


int main() {

    III(n,l,r);

    rep(i,0,2*n)
    {
        tree[i]=-inf;
         val[i]=-inf;
    }

    int mx = 0;
    rep(i,1,n-1) {
        DIII(x,y,c);
        adj[x].PB(y);
        adj[y].PB(x);
        cst[x].PB(c);
        cst[y].PB(c);
        mx=Max(c,mx);
    }
    int low  = 0;
    int high = mx;




    while(low<=high) {
        int mid = (low+high)>>1;
        need=mid;
        ret = 0;
        rm++;
        dfs(1);
        if(ret) {
            median = mid;
            low = mid+1;
        } else {
            high = mid-1;
        }
    }






    show(ses,-1,0,0);



    return 0;
}
