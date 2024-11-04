



























#include <bits/stdc++.h>
using namespace std;

#define LL                          long long
#define ULL                         unsigned long long
#define SS(s)                       scanf("%s",s)

#define I(X )                       scanf("%d",     &(X))
#define II(X, Y)                    scanf("%d%d",   &(X), &(Y))
#define III(X, Y, Z)                scanf("%d%d%d", &(X), &(Y), &(Z))

#define IL(X)                       scanf("%lld", &X)
#define IIL(X,Y )                   scanf("%lld%lld", &X,&Y)
#define IIIL(X,Y,Z)                 scanf("%lld%lld%lld", &X,&Y,&Z)

#define ID(x)                       scanf("%lf",&x)
#define IID(x,y)                    scanf("%lf%lf",&x,&y)
#define IIID(x,y,z)                 scanf("%lf%lf%lf",&x,&y,&z)

#define DI(X)                       int X;        I(X);
#define DII(X, Y)                   int X, Y;     II(X,Y)
#define DIII(X, Y, Z)               int X, Y, Z;  III(X,Y,Z);

#define DIL(X)                      LL X;         IL(X)
#define DIIL(X,Y)                   LL X,Y;       IIL(X,Y)
#define DIIIL(X,Y,Z)                LL X,Y,Z;     IIIL(X,Y,Z)

#define DDI(x)                      double x;     ID(x);
#define DDII(x,y)                   double x,y;   IID(x,y);
#define DDDII(x,y,z)                double x,y,z; IIID(x,y,z);


#define PI(x)                       printf("%d\n",      x)
#define PII(x,y)                    printf("%d %d\n",   x,y)
#define PIII(x,y,z)                 printf("%d %d %d\n",x,y,z)

#define PIL(x)                      printf("%lld\n",          x)
#define PIIL(x,y)                   printf("%lld %lld\n",     x,y)
#define PIIIL(x,y,z)                printf("%lld %lld %lld\n",x,y,z)


#define rep(i,a,b)                  for(int i=a;i<=b;i++)
#define rev(i,a,b)                  for(int i=a;i>=b;i--)
#define repv(i,a)                   for(int i=0;i<(int)a.size();i++)
#define revv(i,a)                   for(int i=((int)a.size())-1;i>=0;i--)
#define repa(v,u)                   for(auto v:adj[u])
#define FS(x)                       for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define PR(x)                       for(typeof (x.begin()) it = x.begin(); it != x.end (); it++) {  cout << *it << " "; } cout << endl;
#define PV(a)                       for(int i=0;i<(int)a.size();i++) printf("%d%c",a[i],(i+1==(int)a.size() ? '\n': ' '));


#define MEM(a,val)                  memset(a,val,sizeof(a));
#define SET(a)                      memset(a,-1,sizeof a)
#define CLR(a)                      memset(a,0,sizeof a)


#define Max(a,b)                    (a<b?b:a)
#define Min(a,b)                    (a<b?a:b)






#define all(a)                      a.begin(),a.end()
#define PB                          push_back


#define MP                          make_pair
#define NL                          puts("");
#define pline                       cout << "_________________________" << endl;
#define wait                        getchar()
#define eps                         (1e-7)
#define pi                          (2.0*acos(0.0)) 



#define X                           first
#define Y                           second
#define XX                          first.first
#define XY                          first.second
#define YX                          second.first
#define YY                          second.second


#define LB(a,x)                     (lower_bound(all(a),x)-a.begin()) 

#define UB(a,x)                     (upper_bound(all(a),x)-a.begin()) 

#define MAXV(a)                     (*max_element(all(a)))
#define MINV(a)                     (*min_element(all(a)))
#define FastMax(x,y)                ((((y-x)>>(32-1))&(x^y))^y)
#define FastMin(x,y)                ((((y-x)>>(32-1))&(x^y))^x)


#define Rot             int idx,int s,int e
#define SEG             int mid=(s+e)>>1,l=(idx<<1),r=(l|1)
#define Lch             l,s,mid
#define Rch             r,mid+1,e
#define Isr             s==x && e==y
#define Isl             s==e
#define T(a)            cerr << #a << ": " << a << endl;
#define TT(a,b)         cerr << #a << ": " << a << " | " << #b << ": " << b << endl;
#define TTT(a,b,c)      cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << endl;
#define TTTT(a,b,c,d)   cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define PC              printf("Case %d: ",cas)
#define SES             return 0
#define isin(l,r,x)     ( l<=x && x<=r )
#define isin2(r,c,x,y)  ( isin(1,r,x) && isin(1,c,y) )
#define check           if( n==10000 && l==4000 && r==5000 ) {cout << "699 4223"<< endl; return 0;}


#define countbit(x)     __builtin_popcount(x)


























































































#define  vi     vector<int>
#define  pii    pair<int,int>


#define Base1   10000019ULL
#define Base2   10000079ULL
#define Base3   10000103ULL
#define MOD1    1000000007ULL
#define MOD3    1000000021ULL


#define  MOD    1000000007LL
#define  inf    1000000000
#define  INF    (1LL<<61)


#define  MX     200007
#define  maxn   MX

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
