



























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


#define Max(a,b)                    (a>b?a:b)
#define Min(a,b)                    (a<b?a:b)
#define _Max(a,b,c)                 Max(a,Max(b,c))
#define _Min(a,b,c)                 Min(a,Min(b,c))
#define SQR(n)                      ((n)*(n))
#define all(a)                      a.begin(),a.end()
#define PB                          push_back
#define RPB(a,x,y)                  a[x].PB(y),a[y].PB(x)
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


#define countbit(x)     __builtin_popcount(x)
















#define  READ       freopen("C:\\Users\\unknown\\Desktop\\input.txt","r",stdin)
#define  WRITE      freopen("C:\\Users\\unknown\\Desktop\\output.txt","w",stdout)




template<typename T> T POW(T base,T power)              { T ret=1; while(power)  { if(power & 1) ret=(ret*base); base=(base*base);  power>>=1; }return ret; }
template<typename T> inline T GCD(T a,T b)              { if(a<0)return GCD(-a,b);  if(b<0)return GCD(a,-b);    return (b==0)?a:GCD(b,a%b);}
template<typename T> T LCM(T a,T b)                     { if(a<0)return LCM(-a,b);if(b<0)return LCM(a,-b);return a*(b/GCD(a,b));}
template<typename T> T EUCLIDE(T a,T b,T &x,T &y)       { if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}   if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template<typename T> T ABS(T a){    if(a<0)return -a;    else return a;}




template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T ModInv (T b,T m){return BigMod(b,m-2,m);}
















































#define  vi     vector<int>
#define  pii    pair<int,int>


#define Base1   10000019ULL
#define Base2   10000079ULL
#define Base3   10000103ULL
#define MOD1    1000000007ULL
#define MOD2    1000000009ULL
#define MOD3    1000000021ULL


#define  MOD    1000000007LL
#define  inf    1000000000
#define  INF    (1LL<<61)


#define  MX     500007
#define  maxn   MX

LL ar[MX];
LL br[MX];

LL xx[MX];
LL yy[MX];

LL dp[MX];

vector<LL>aa;
vector<LL>bb;


pair<int,LL> kacher_choto(vector<LL>&vec,LL v)
{
    pair<int,LL>ret(0,0);
    int low = 0;
    int high = vec.size()-1;
    while(low<=high){
        int mid =(low+high)>>1;
        if(vec[mid]<=v) ret.X=1,ret.Y=vec[mid] , low = mid+1;
        else high=mid-1;
    }
    return ret;
}

pair<int,LL>kacher_boro(vector<LL>&vec,LL v){
    pair<int,LL>ret(0,0);
    int low=0;
    int high=vec.size()-1;
    while(low<=high){
        int mid =(low+high)>>1;
        if(vec[mid]>=v) ret.X=1,ret.Y=vec[mid],high=mid-1;
        else low=mid+1;
    }
    return ret;
}


int main()
{
    DIII(n,m,q);

    LL tot = 0;
    LL mmm = 1;

    rep(i,1,n)
    {
         IL(ar[i]);
         tot+=mmm*ar[i];
         mmm*=-1;
    }

    LL a=-1;
    LL b=1;

    rep(i,1,m)
    {
        IL(br[i]);
        xx[i] = a*br[i]+xx[i-1];
        yy[i] = b*br[i]+yy[i-1];
        a*=-1;
        b*=-1;
    }

    int jj = m-n;

    rep(i,0,jj)
    {
        int pos = i+1;

        if(pos&1) dp[pos] = xx[pos+n-1]-xx[pos-1];
        else      dp[pos] = yy[pos+n-1]-yy[pos-1];


        if(dp[pos]<0)  aa.PB(-dp[pos]);
        else           bb.PB(dp[pos]);



    }

    int cnt = jj+1;

    sort( all(aa) );
    sort( all(bb) );




    rep(i,1,q+1)
    {
        LL x,y,v;
        v=0;
        x=0;
        y=0;

        if(i>1)
        {
             IIIL(x,y,v);
             if((y-x+1)%2==1)  {
                if(x&1) tot+=v;
                else    tot+=-v;
            }
        }






        LL ret=(1ULL<<63)-1;
        ret  =  1e18;










        











        if(tot>=0)
        {
            pair<int,LL> r   = kacher_choto(aa,tot);
            pair<int,LL> rr  = kacher_boro(aa,tot);

            if(r.X)  ret = min( ret, ABS(tot-r.Y) );
            if(rr.X) ret = min( ret, ABS(tot-rr.Y) );

            if(bb.size())ret = min(ret, ABS(tot+bb[0]) );
        }

        if(tot<=0)
        {
            pair<int,LL> r   = kacher_choto(bb,-tot);
            pair<int,LL> rr  = kacher_boro(bb,-tot);

            if(r.X)  ret = min( ret, ABS(tot+r.Y)  );
            if(rr.X) ret = min( ret, ABS(tot+rr.Y) );
            if(aa.size())ret = min(ret, ABS(tot-aa[ aa.size()-1 ] ) );
            if(aa.size())ret = min(ret, ABS(tot-aa[0])  );
        }




        PIL(ret);
    }



    return 0;
}
