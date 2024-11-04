





















































using namespace std;



























































































template< class T, class X > inline bool checkbit(T a, X pos) { T t=1;return ((a&(t<<pos))>0);  }
template< class T, class X > inline T      setbit(T a, X pos) { T t=1;return (a|(t<<pos));      }
template< class T, class X > inline T    resetbit(T a, X pos) { T t=1;return (a&(~(t<<pos)));   }
template< class T, class X > inline T   togglebit(T a, X pos) { T t=1;return (a^(t<<pos));      }



template<typename T> inline T Bigmod(T base,T power,T mod) { T ret=1; while(power)  { if(power & 1) ret=(ret*base)%mod; base=(base*base)%mod;  power>>=1; }return ret; }
template<typename T> inline T ModInverse(T number,T mod) { return Bigmod(number,mod-2,mod); }
template<typename T> T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
template<typename T> T GCD(T a,T b){if(a<0)return GCD(-a,b);if(b<0)return GCD(a,-b);return (b==0)?a:GCD(b,a%b);}
template<typename T> T LCM(T a,T b) {if(a<0)return LCM(-a,b);if(b<0)return LCM(a,-b);return a*(b/GCD(a,b));}
template<typename T> T id1(T a,T b,T &x,T &y) {if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}   if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template<typename T> T ABS(T a) {if(a<0)return -a;else return a;}



double DEG(double x) { return (180.0*x)/(pi);}
double RAD(double x) { return (x*(double)pi)/(180.0);}
template<typename T> double DIS(T x1,T y1,T x2, T y2){return sqrt( (double)( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ) );}
template<typename T> T ANGLE(T x1,T y1,T x2, T y2){ return atan( double(y1-y2) / double(x1-x2));}
template<typename T> LL isLeft(T a,T b,T c) { return (c.x-a.x)*(b.y-a.y)-(b.x-a.x)*(c.y-a.y); }


template<class T> inline bool setmin(T& a, T b) { return a>b? a=b, true: false; }
template<class T> inline bool setmax(T& a, T b) { return a<b? a=b, true: false; }


void id0(int *ar,int a,int b) {  if(a>b) swap(a,b); if(a<=b) cout << ar[a]; for(int i=a+1;i<=b;i++) cout << " "<<ar[i];  cout << endl; }
template<typename T> T in(){ char ch; T n = 0; bool ng = false; while (1) { ch = getchar(); if (ch == '-') { ng = true; ch = getchar(); break;} if (ch>='0' && ch<='9') break; }    while (1) { n = n*10 + (ch - '0'); ch = getchar(); if (ch<'0' || ch>'9')   break;    }  return (ng?-n:n);  }







































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

int id2(int u,int v)
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









        int l = id2(u,v);










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
