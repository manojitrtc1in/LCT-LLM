































#include<algorithm>
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#include<deque>
#include<climits>
#include<complex>

using namespace std;

#define LL long long
#define ULL unsigned long long



#define I(X)                        scanf("%d",     &(X))
#define II(X, Y)                    scanf("%d%d",   &(X), &(Y))
#define III(X, Y, Z)                scanf("%d%d%d", &(X), &(Y), &(Z))

#define DI(X) int (X);              scanf("%d",     &X)
#define DII(X, Y) int X, Y;         scanf("%d%d",   &X, &Y)
#define DIII(X, Y, Z) int X, Y, Z;  scanf("%d%d%d", &X, &Y, &Z)

#define IL(x)                       scanf("%lld", &x)
#define IIL(x,y )                   scanf("%lld", &x,&y)
#define IIIL(x,y,z)                 scanf("%lld", &x,&y,&z)

#define DIL(x)       LL x;          scanf("%lld", &x)
#define DIIL(x,y)    LL x,y;        scanf("%lld", &x,&y)
#define DIIIL(x,y,z) LL x,y,z;      scanf("%lld", &x,&y,&z)

#define SS(s)                       scanf("%s",s)
#define S                           scanf
#define P                           printf

#define PI(x)                       printf("%d\n",      x)
#define PII(x,y)                    printf("%d %d\n",   x,y)
#define PIII(x,y,z)                 printf("%d %d %d\n",x,y,z)

#define PIL(x)                      printf("%lld\n",          x)
#define PIIL(x,y)                   printf("%lld %lld\n",     x,y)
#define PIIIL(x,y,z)                printf("%lld %lld %lld\n",x,y,z)



#define repv(i,a)  for(int i=0;i<(int)a.size();i++)
#define revv(i,a)  for(int i=((int)a.size())-1;i>=0;i--)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,a,b) for(int i=a;i>=b;i--)

#define FS(x)      for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define PR(x)      for(typeof (x.begin()) it = x.begin(); it != x.end (); it++) {  cout << *it << " "; } cout << endl;



#define MEM(a,val) memset(a,val,sizeof(a));
#define SET(a)     memset(a,-1,sizeof a)
#define CLR(a)     memset(a,0,sizeof a)



#define Max(a,b)     (a>b?a:b)
#define _Max(a,b,c)  Max(a,Max(b,c))
#define Min(a,b)     (a<b?a:b)
#define _Min(a,b,c)  Min(a,Min(b,c))
#define MAX(a)       (*max_element(all(a)))
#define MIN(a)       (*min_element(all(a)))

#define FastMax(x,y) ((((y-x)>>(32-1))&(x^y))^y)
#define FastMin(x,y) ((((y-x)>>(32-1))&(x^y))^x)

#define SQR(n) (n*n)
#define eps    (1e-9)
#define pi     (2.0*acos(0.0)) 


#define all(a) a.begin(),a.end()
#define pb     push_back
#define NL     puts("");


#define X first
#define Y second



#define LB(a,x) (lower_bound(all(a),x)-a.begin())
#define UB(a,x) (upper_bound(all(a),x)-a.begin())



#define READ  freopen("C:\\Users\\back_bencher\\Desktop\\input.txt","r",stdin)
#define WRITE freopen("C:\\Users\\back_bencher\\Desktop\\output.txt","w",stdout)
#define _cin  ios_base::sync_with_stdio(0); cin.tie(0);

#define pline cout << "_________________________" << endl;



#define countbit(x) __builtin_popcount(x)
template< class T, class X > inline bool checkbit(T a, X pos) { T t=1;return ((a&(t<<pos))>0);  }
template< class T, class X > inline T      setbit(T a, X pos) { T t=1;return (a|(t<<pos));      }
template< class T, class X > inline T    resetbit(T a, X pos) { T t=1;return (a&(~(t<<pos)));   }
template< class T, class X > inline T   togglebit(T a, X pos) { T t=1;return (a^(t<<pos));      }



template<typename T> inline T Bigmod(T base,T power,T mod) { T ret=1; while(power)  { if(power & 1) ret=(ret*base)%mod; base=(base*base)%mod;  power>>=1; }return ret; }
template<typename T> inline T ModInverse(T number,T mod) { return Bigmod(number,mod-2,mod); }
template<typename T> T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
template<typename T> T GCD(T a,T b){if(a<0)return GCD(-a,b);if(b<0)return GCD(a,-b);return (b==0)?a:GCD(b,a%b);}
template<typename T> T LCM(T a,T b) {if(a<0)return LCM(-a,b);if(b<0)return LCM(a,-b);return a*(b/GCD(a,b));}
template<typename T> T EUCLIDE(T a,T b,T &x,T &y) {if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}   if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template<typename T> T ABS(T a) {if(a<0)return -a;else return a;}



double DEG(double x) { return (180.0*x)/(pi);}
double RAD(double x) { return (x*(double)pi)/(180.0);}
template<typename T> double DIS(T x1,T y1,T x2, T y2){return sqrt( (double)( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ) );}
template<typename T> T ANGLE(T x1,T y1,T x2, T y2){ return atan( double(y1-y2) / double(x1-x2));}
template<typename T> LL isLeft(T a,T b,T c) { return (c.x-a.x)*(b.y-a.y)-(b.x-a.x)*(c.y-a.y); }


template<class T> inline bool setmin(T& a, T b) { return a>b? a=b, true: false; }
template<class T> inline bool setmax(T& a, T b) { return a<b? a=b, true: false; }


void P_ARR(int *ar,int a,int b) {  if(a>b) swap(a,b); if(a<=b) cout << ar[a]; for(int i=a+1;i<=b;i++) cout << " "<<ar[i];  cout << endl; }
template<typename T> T in(){ char ch; T n = 0; bool ng = false; while (1) { ch = getchar(); if (ch == '-') { ng = true; ch = getchar(); break;} if (ch>='0' && ch<='9') break; }    while (1) { n = n*10 + (ch - '0'); ch = getchar(); if (ch<'0' || ch>'9')   break;    }  return (ng?-n:n);  }
#define SI(X) X=in<int>()
#define SL(X) X=in<LL>()


#define VI  vector< int >
#define VII vector< VI >
#define VLL vector< LL >
#define PPI pair< int , int >
#define PPL pair< LL , LL >
#define VPI vector< PPI >

















#define  debug  0
#define  DD     if(debug)



#define  MX     100007
#define  MOD    100711433LL
#define  inf    1000000000

#define maxn MX


set<int>tree[4*MX];
int ts[4*MX];


void update(int idx,int s,int e,int pos,int v)
{
     if(s==e)
     {
         tree[idx].insert(v);
         if(tree[idx].size()>10) tree[idx].erase( *tree[idx].rbegin() );


         ts[idx]++;
         return;
     }

     int mid  = (s+e)>>1  , l = (idx<<1) , r =  (l|1);

     if(pos<=mid) update(l,s,mid,pos,v);
     else         update(r,mid+1,e,pos,v);



     if(ts[idx]<=10)  tree[idx].insert(v);
     tree[idx].insert(v);
     if(tree[idx].size()>10) tree[idx].erase( *tree[idx].rbegin() );
}



set<int>res;
bool flag;
int aa;

void query(int idx,int s,int e,int x,int y)
{
    if(x>y) return;

     if(s==x && e==y)
     {
          for(set<int>:: iterator it = tree[idx].begin();it!=tree[idx].end();it++)
          {
              res.insert(*it);
              if(res.size()>aa) res.erase(*res.rbegin());
          }
         return;
     }
     int mid  = (s+e)>>1  , l = (idx<<1) , r =  (l|1);
     if(y<=mid)     query(l,s,mid,x,y);
     else if(x>mid) query(r,mid+1,e,x,y);
     else
     {
         query(l,s,mid,x,mid);
         query(r,mid+1,e,mid+1,y);
     }
}

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

int pos[MX];

void DFS(int u,int papa,int lev)
{
    par[u] = papa;
    level[u] = lev;
    ssize[u] = 1;
    schild[u] = -1;

    int mx = -1;

    repv(i,adj[u])
    {
        int v = adj[u][i];

        if(v!=papa)
        {
            DFS(v,u,lev+1);
            ssize[u] += ssize[v];
            if(mx<ssize[v])
            {
                mx = ssize[v];
                schild[u] = v;
            }
        }
    }
}

int ptr;

void HLD(int u)
{
    if( chainHead[chainNo]==0 ) chainHead[chainNo]=u;

    chainId[u] = chainNo;
    chainPos[u]=++ptr;

    pos[ptr]=u;

    if(schild[u]!=-1)
    {
        HLD(schild[u]);

        repv(i,adj[u])
        {
            int v = adj[u][i];

            if( v!=schild[u] && v!=par[u] )
            {
                chainNo++;
                HLD(v);
            }
        }
    }
}





int n;

int LCA2(int u,int v)
{
    int uhead,vhead,uchain,vchain;

    flag   = 1;
    res.clear();



    while(true)
    {



        uchain = chainId[u];
        vchain = chainId[v];

        uhead  = chainHead[uchain];
        vhead  = chainHead[vchain];

        if(uchain==vchain)
        {
            if(level[u]<level[v])
            {








                query(1,1,ptr,min(chainPos[u],chainPos[u]), max(chainPos[u],chainPos[u])  );




                query(1,1,ptr,min(chainPos[v],chainPos[u]),max(chainPos[v],chainPos[u]) );


            }
            else if(level[u]>level[v])
            {







                query(1,1,ptr,min(chainPos[u],chainPos[v])  ,  max(chainPos[u],chainPos[v])  );
                query(1,1,ptr,min(chainPos[v],chainPos[v]) , max(chainPos[v],chainPos[v]) ) ;
            }
            else
            {







                query(1,1,ptr,min(chainPos[u],chainPos[u]),max(chainPos[u],chainPos[u]));
                query(1,1,ptr,min(chainPos[v],chainPos[v]),max(chainPos[v],chainPos[v]));
            }











            return (level[u]<level[v]?u:v);




        }
        else if( level[uhead]<level[vhead] )
        {


            query(1,1,ptr,min(chainPos[v],chainPos[vhead]),max(chainPos[v],chainPos[vhead])  ) ;
            v = par[ vhead ];
        }
        else
        {


            query(1,1,ptr,min( chainPos[u],chainPos[uhead]),max( chainPos[u],chainPos[uhead]) ) ;
            u = par[ uhead ];
        }






    }



}



int LCA(int u,int v)
{
    int uhead,vhead,uchain,vchain;
    while(true)
    {
        uchain = chainId[u];
        vchain = chainId[v];

        uhead  = chainHead[uchain];
        vhead  = chainHead[vchain];

        if(uchain==vchain)  return (level[u]<level[v]?u:v);
        else if( level[uhead]<level[vhead] ) v = par[ vhead ];
        else u = par[ uhead ];
    }
}


void query_up(int papa,int u)
{
     int uchain,pchain=chainId[papa],ret=0;
     int uhead;

     while(true)
     {
         uchain = chainId[u];

         if(uchain==pchain)
         {


             int a = chainPos[u];
             int b = chainPos[papa];
             if(a>b) swap(a,b);




             query(1,1,ptr,a,b);

             break;
         }

         uhead = chainHead[uchain];




        int a = chainPos[uhead];
        int b = chainPos[u];
        if(a>b) swap(a,b);




        query(1,1,ptr,a,b);

         u = par[uhead];
     }

     return ;
}

void init(int n)
{
    chainNo = 1;
    ptr=0;
}

vector<int>per[MX];

int main() {

    int m,q;
    int u,v;

    III(n,m,q);

    rep(i,1,n-1)
    {
        II(u,v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    init(n);

    DFS(1,-1,1);
    HLD(1);

    int a;









    rep(i,1,m)
    {
        I(a);
        update(1,1,ptr,chainPos[a],i);


    }




    rep(qq,1,q)
    {
        II(u,v);
        I(aa);











        flag =  1;
        res.clear();









        int l = LCA2(u,v);










        {
            printf("%d",res.size());
            int cnt = 0;

            for(set<int>:: iterator it = res.begin();it!=res.end();it++)
            {
                printf(" %d",*it);
            }
            NL;
        }
    }




    return 0;
}
