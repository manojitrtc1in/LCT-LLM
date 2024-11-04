




#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <deque>
#include <climits>
#include <complex>
#include <bitset>
#include <limits>

using namespace std;

#define LL                          long long
#define ULL                         unsigned long long


#define SS(s)                       scanf("%s",s)

#define I(X)                        scanf("%d",     &(X))
#define II(X, Y)                    scanf("%d%d",   &(X), &(Y))
#define III(X, Y, Z)                scanf("%d%d%d", &(X), &(Y), &(Z))

#define IL(X)                       scanf("%lld", &X)
#define IIL(X,Y )                   scanf("%lld%lld", &X,&Y)
#define IIIL(X,Y,Z)                 scanf("%lld%lld%lld", &X,&Y,&Z)

#define ID(x)                       scanf("%lf",&x)
#define IID(x,y)                    scanf("%lf%lf",&x,&y)
#define IIID(x,y,z)                 scanf("%lf%lf%lf",&x,&y,&z)

#define DI(X)         int X;        I(X);
#define DII(X, Y)     int X, Y;     II(X,Y)
#define DIII(X, Y, Z) int X, Y, Z;  III(X,Y,Z);

#define DIL(X)        LL X;         IL(X)
#define DIIL(X,Y)     LL X,Y;       IIL(X,Y)
#define DIIIL(X,Y,Z)  LL X,Y,Z;     IIIL(X,Y,Z)

#define DDI(x)        double x;     ID(x);
#define DDII(x,y)     double x,y;   IID(x,y);
#define DDDII(x,y,z)  double x,y,z; IIID(x,y,z);

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

#define FS(x)                       for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define PR(x)                       for(typeof (x.begin()) it = x.begin(); it != x.end (); it++) {  cout << *it << " "; } cout << endl;
#define PV(a)                       for(int i=0;i<(int)a.size();i++) printf("%d%c",a[i],(i+1==(int)a.size() ? '\n': ' '));


#define MEM(a,val)                  memset(a,val,sizeof(a));
#define SET(a)                      memset(a,-1,sizeof a)
#define CLR(a)                      memset(a,0,sizeof a)


#define Max(a,b)                    (a>b?a:b)
#define Min(a,b)                    (a<b?a:b)
#define _Max(a,b,c)                 Max(a,Max(b,c))
#define _Min(a,b,c)                 Min(a,Min(b,c))
#define MAXV(a)                     (*max_element(all(a)))
#define MINV(a)                     (*min_element(all(a)))
#define FastMax(x,y)                ((((y-x)>>(32-1))&(x^y))^y)
#define FastMin(x,y)                ((((y-x)>>(32-1))&(x^y))^x)

#define SQR(n)                      ((n)*(n))

#define all(a)                      a.begin(),a.end()
#define PB                          push_back
#define MP                          make_pair
#define NL                          puts("");
#define pline                       cout << "_________________________" << endl;


#define X                           first
#define Y                           second


#define LB(a,x)                     (lower_bound(all(a),x)-a.begin()) 

#define UB(a,x)                     (upper_bound(all(a),x)-a.begin()) 

















#define rot             int idx,int s,int e
#define SEG             int mid=(s+e)>>1,l=(idx<<1),r=(l|1)
#define lch             l,s,mid
#define rch             r,mid+1,e

#define T(a)            cerr << #a << ": " << a << endl;
#define TT(a,b)         cerr << #a << ": " << a << " | " << #b << ": " << b << endl;
#define TTT(a,b,c)      cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << endl;
#define TTTT(a,b,c,d)   cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;

#define PC              printf("Case %d: ",cas)
#define SES             return 0

#define isin(l,r,x)     ( l<=x && x<=r )
#define isin2(r,c,x,y)  ( isin(1,r,x) && isin(1,c,y) )


#define countbit(x)     __builtin_popcount(x)
    template< class T, class X > inline bool checkbit(T a, X pos) { T t=1;return ((a&(t<<pos))>0);  }
    template< class T, class X > inline T      setbit(T a, X pos) { T t=1;return (a|(t<<pos));      }
    template< class T, class X > inline T    resetbit(T a, X pos) { T t=1;return (a&(~(t<<pos)));   }
    template< class T, class X > inline T   togglebit(T a, X pos) { T t=1;return (a^(t<<pos));      }
    #define  ctone(a)   ( ( (~a)==0 )?32: __builtin_ctz( ~a ) ) 


    #define  debug      0
    #define  AA         if(debug)
    #define  eps        (1e-7)
    #define  pi         (2.0*acos(0.0)) 


    

    #define  READ   freopen("C:\\Users\\shaheen\\Desktop\\input.txt","r",stdin)
    #define  WRITE  freopen("C:\\Users\\shaheen\\Desktop\\output.txt","w",stdout)
    #define  _cin   ios_base::sync_with_stdio(0); cin.tie(0);
    

    

    

    template<typename T> T POW(T base,T power)              { T ret=1; while(power)  { if(power & 1) ret=(ret*base); base=(base*base);  power>>=1; }return ret; }
    template<typename T> inline T GCD(T a,T b)              { if(a<0)return GCD(-a,b);  if(b<0)return GCD(a,-b);    return (b==0)?a:GCD(b,a%b);}
    template<typename T> T LCM(T a,T b)                     { if(a<0)return LCM(-a,b);if(b<0)return LCM(a,-b);return a*(b/GCD(a,b));}
    template<typename T> T EUCLIDE(T a,T b,T &x,T &y)       { if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}   if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
    template<typename T> T ABS(T a)                         { if(a<0)return -a;else return a;}
    LL Bigmod(LL base,LL power,LL _MOD)                      { LL ret=1;while(power){if(power & 1)ret=(ret*base)%_MOD;base=(base*base)%_MOD;power>>=1;}return ret;}
    LL ModInverse(LL number,LL _MOD)                         { return Bigmod(number,_MOD-2LL,_MOD); }
    

    template<typename T> double DIS(T x1,T y1,T x2, T y2)   { return sqrt( (double)( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ) );}
    template<typename T> T ANGLE(T x1,T y1,T x2, T y2)      { return atan( double(y1-y2) / double(x1-x2));}
    template<typename T> LL isLeft(T a,T b,T c)             { return (c.x-a.x)*(b.y-a.y)-(b.x-a.x)*(c.y-a.y); }
    

    

    

    

    

    void BINARY(int n){  bitset<31>a=n;  cout << a << endl;}
    void P_ARR(int *ar,int a,int b) {  if(a>b) swap(a,b); if(a<=b) cout << ar[a]; for(int i=a+1;i<=b;i++) cout << " "<<ar[i];  cout << endl; }
    template<class T> inline void make_unique_vec( vector<T> &vec ){ sort( vec.begin(), vec.end() ); vec.erase( unique( vec.begin(), vec.end() ), vec.end() ); }
    template<class T> inline void make_unique_arr( T *ar,int &n)   { sort(ar + 1, ar + n + 1); n = unique(ar + 1, ar + n + 1) - ar - 1; }
    

    

    

    

    

    

    

    

    


#define  VI     vector<int>
#define  pii    pair<int,int>


#define Base1   10000019ULL
#define Base2   10000079ULL
#define Base3   10000103ULL
#define MOD1    1000000007ULL
#define MOD2    1000000009ULL
#define MOD3    1000000021ULL


#define  MX     100007
#define  MOD    1000000007
#define  inf    1000000000000007LL
#define  INF    (1LL<<62)
    


struct data {

    int lone,tone;
    int sz;
    int sum;

} tree[2][4*MX];

int _map[MX];

void build(rot) {
    if(s==e) {

        rep(i,0,1)    {
        tree[i][idx].lone = 0;
        tree[i][idx].tone = 0;
        tree[i][idx].sum  = 0;
        tree[i][idx].sz   = 1;
        }
        return;
    }
    SEG;
    build(lch);
    build(rch);

    rep(i,0,1)    {
        tree[i][idx].lone = 0;
        tree[i][idx].tone = 0;
        tree[i][idx].sum  = 0;
        tree[i][idx].sz   = tree[i][l].sz+tree[i][r].sz;
    }
}




































data Merge(data a,data b) {
    data ret;
    ret.sz = a.sz + b.sz;

    if(a.sz==0) {
        ret = b;
        return ret;
    }
    if(b.sz==0) {
        ret = a;
        return ret;
    }
    if(a.lone==a.sz && b.lone==b.sz) {
        ret.lone = ret.tone = ret.sz;
        ret.sum = 0;
    } else if(a.lone==a.sz) {

        ret.lone = a.lone + b.lone;
        ret.tone = b.tone;

        ret.sum = b.sum;

    } else if(b.lone==b.sz) {
        ret.lone = a.lone;
        ret.tone = a.tone + b.lone;
        ret.sum = a.sum;
    } else {

        ret.sum = a.sum + b.sum;
        if(a.tone && b.lone) {
            ret.sum += _map[a.tone + b.lone];
        } else {
            ret.sum += _map[a.tone] + _map[b.lone];
        }
        ret.lone = a.lone;
        ret.tone = b.tone;
    }
    return ret;
}


void update(int idx,int s,int e,int pos) {
    if(s==e) {
        rep(i,0,1)    {
            tree[i][idx].lone = tree[i][idx].tone = 1;
            tree[i][idx].sum = 0;
        }
        return;
    }
    SEG;
    if(pos<=mid) update(lch,pos);
    else         update(rch,pos);

    tree[0][idx] = Merge(tree[0][l],tree[0][r]);
    tree[1][idx] = Merge(tree[1][r],tree[1][l]);
}

data query(int id,int idx,int s,int e,int x,int y) {
    if(s==x && e==y) return tree[id][idx];
    SEG;
    if(y<=mid)    return query(id,lch,x,y);
    else if(mid<x) return query(id,rch,x,y);
    else {
        data lt = query(id,lch,x,mid);
        data rt = query(id,rch,mid+1,y);
        data ret;
        if(id==0) ret = Merge(lt,rt);
        else      ret = Merge(rt,lt);
        return ret;
    }
}

int cal(data a) {
    if(a.sz==a.lone) return _map[ a.sz ];
    int ret = 0;
    ret = a.sum;
    ret += _map[ a.lone ];
    ret += _map[ a.tone ];
    return ret;
}




#define maxn MX

int chainNo;
int chainPos[maxn];
int chainHead[maxn];
int chainId[maxn];
int chainSize[maxn];
int ssize[maxn];
int schild[maxn];
int level[maxn];

vector<int>adj[maxn];

int par[maxn];
int ptr;


int stk[MX];
int vis[MX];

void HLD(int n) {
    int top =0;
    stk[++top]=1;
    par[1]=-1;
    level[1]=1;
    ssize[1]=1;
    schild[1]=-1;
    while(top) {
        int u = stk[top];
        if(!vis[u]) {
            vis[u]=1;
            repv(i,adj[u]) {
                int v = adj[u][i];
                if(v==par[u]) continue;
                stk[++top]=v;
                level[v]=level[u]+1;
                par[v]=u;
                schild[v]=-1;
                ssize[v]=1;
            }
        } else {
            top--;
            if(par[u]==-1) continue;
            ssize[ par[u] ] += ssize[u];
            if(par[u]==-1 || ssize[ schild[ par[u] ] ] < ssize[u]) {
                schild[ par[u] ] = u;
            }
        }
    }
    chainNo = 0;
    ptr = 0;
    rep(i,1,n) {
        if(par[i]==-1 || schild[ par[i] ]!=i) {
            chainNo++;
            chainHead[chainNo]=i;
            for(int  j =i; j!=-1; j=schild[j]) {
                chainId[j]=chainNo;
                chainPos[j]=++ptr;
                

            }
        }
    }
}

vector< pair<int ,int> > lt , rt;

void LCA(int u,int v) {
    lt.clear();
    rt.clear();
    int uhead,vhead,uchain,vchain;
    while(true) {
        uchain = chainId[u];
        vchain = chainId[v];
        uhead  = chainHead[uchain];
        vhead  = chainHead[vchain];
        if(uchain==vchain) {
            if(level[u]<level[v]) {
                lt.push_back(make_pair(chainPos[u],  chainPos[u]));
                rt.push_back(make_pair(chainPos[u]+1,chainPos[v]));
            } else if(level[v]<level[u]) {
                lt.push_back(make_pair(chainPos[v],chainPos[u]));
            } else {
                lt.push_back(make_pair(chainPos[u],chainPos[u]));
            }
            return;
            

        } else if(level[uhead]<level[vhead]) {
            rt.push_back(make_pair(chainPos[vhead],chainPos[v]));
            v = par[ vhead ];
        } else {
            lt.push_back(make_pair(chainPos[uhead],chainPos[u]));
            u = par[ uhead ];
        }
    }
}


struct info {
    int x,y,l;
    int id;

    bool operator < (const info &p) const {
        return (l>p.l);
    }

} qq[MX];


struct edge {
    int x,y,c;
    bool operator < (const edge &p) const {
        return (c>p.c);
    }
} ee[MX];

int ans[MX];

int main() {
    DII(n,q);
    rep(i,1,n-1) I(_map[i]);
    int x,y,c;
    rep(i,1,n-1) {
        III(x,y,c);
        adj[x].PB(y);
        adj[y].PB(x);
        ee[i].x = x;
        ee[i].y = y;
        ee[i].c = c;
    }
    

    HLD(n);
    rep(i,1,q) {
        III(qq[i].x,qq[i].y,qq[i].l);
        qq[i].id = i;
    }
    sort(qq+1,qq+1+q);
    sort(ee+1,ee+1+n-1);
    build(1,1,n);
    

    int id = 1;
    rep(i,1,q) {
        int v = qq[i].l;
        while(id<=n-1 && ee[id].c>=v) {
            int pos;
            if(par[ee[id].x] == ee[id].y)  pos = chainPos[ ee[id].x ];
            else                           pos = chainPos[ ee[id].y ];
            update(1,1,n,pos);
            id++;
        }
        

        LCA(qq[i].x , qq[i].y);
        data ret;
        ret.lone = ret.tone = ret.sz =  ret.sum = 0;
        int l = lt.size()-1;
        lt[l].X++;
        int flag = 0;
        repv(ii,lt) {
            int x = lt[ii].X;
            int y = lt[ii].Y;
            if(x>y) continue;
            data tm = query(0,1,1,n,x,y);
            

            

            ret = Merge(tm,ret);
            

        }

        data ret2;
        ret2.lone = ret2.tone = ret2.sz =  ret2.sum = 0;

        repv(ii,rt) {
            int x = rt[ii].X;
            int y = rt[ii].Y;
            if(x>y) continue;
            data tm = query(0,1,1,n,x,y);
            

            

            ret2 = Merge(tm,ret2);
            

        }

        swap( ret.lone,ret.tone );


        ret = Merge(ret,ret2);


        ans[ qq[i].id ] = cal(ret);
    }
    rep(i,1,q) {
        PI(ans[i]);
    }
    return 0;
}
