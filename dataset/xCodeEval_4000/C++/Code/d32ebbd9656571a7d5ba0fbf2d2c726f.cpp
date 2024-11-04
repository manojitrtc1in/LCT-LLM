














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

using namespace std;

#define LL                          long long
#define ULL                         unsigned long long



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


#define SS(s)                       scanf("%s",s)
#define S                           scanf
#define P                           printf

#define PI(x)                       printf("%d\n",      x)
#define PII(x,y)                    printf("%d %d\n",   x,y)
#define PIII(x,y,z)                 printf("%d %d %d\n",x,y,z)

#define PIL(x)                      printf("%lld\n",          x)
#define PIIL(x,y)                   printf("%lld %lld\n",     x,y)
#define PIIIL(x,y,z)                printf("%lld %lld %lld\n",x,y,z)



#define repv(i,a)                   for(int i=0;i<(int)a.size();i++)
#define revv(i,a)                   for(int i=((int)a.size())-1;i>=0;i--)
#define rep(i,a,b)                  for(int i=a;i<=b;i++)
#define rev(i,a,b)                  for(int i=a;i>=b;i--)

#define FS(x)                       for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define PR(x)                       for(typeof (x.begin()) it = x.begin(); it != x.end (); it++) {  cout << *it << " "; } cout << endl;



#define MEM(a,val)                  memset(a,val,sizeof(a));
#define SET(a)                      memset(a,-1,sizeof a)
#define CLR(a)                      memset(a,0,sizeof a)



#define Max(a,b)                    (a>b?a:b)
#define _Max(a,b,c)                 Max(a,Max(b,c))
#define Min(a,b)                    (a<b?a:b)
#define _Min(a,b,c)                 Min(a,Min(b,c))
#define MAX(a)                      (*max_element(all(a)))
#define MIN(a)                      (*min_element(all(a)))

#define FastMax(x,y)                ((((y-x)>>(32-1))&(x^y))^y)
#define FastMin(x,y)                ((((y-x)>>(32-1))&(x^y))^x)

#define SQR(n)          (n*n)

#define all(a)          a.begin(),a.end()
#define pb              push_back
#define NL              puts("");
#define pline           cout << "_________________________" << endl;


#define XX              first
#define YY              second


#define LB(a,x)         (lower_bound(all(a),x)-a.begin())
#define UB(a,x)         (upper_bound(all(a),x)-a.begin())


#define READ            freopen("C:\\Users\\backbencher\\Desktop\\input.txt","r",stdin)
#define WRITE           freopen("C:\\Users\\backbencher\\Desktop\\output.txt","w",stdout)

#define _cin            ios_base::sync_with_stdio(0); cin.tie(0);

#define SI(X)           X=in<int>()
#define SII(X,Y)        X=in<int>(),Y=in<int>()
#define SIII(X,Y,Z)     X=in<int>(),Y=in<int>(),Z=in<int>()

#define SL(X)           X=in<LL>()
#define SLL(X,Y)        X=in<LL>(),Y=in<LL>()
#define SLLL(X,Y,Z)     X=in<LL>(),Y=in<LL>(),Z=in<LL>()

#define VI              vector< int >
#define VII             vector< VI >
#define VLL             vector< LL >
#define PPI             pair< int , int >
#define PPL             pair< LL , LL >
#define VPI             vector< PPI >

#define SEG             int mid=(s+e)>>1,l=(idx<<1),r=(l|1);
#define in(x,l,r)       ( l<=x && x<=r )



#define countbit(x)     __builtin_popcount(x)
template< class T, class X > inline bool checkbit(T a, X pos) { T t=1;return ((a&(t<<pos))>0);  }
template< class T, class X > inline T      setbit(T a, X pos) { T t=1;return (a|(t<<pos));      }
template< class T, class X > inline T    resetbit(T a, X pos) { T t=1;return (a&(~(t<<pos)));   }
template< class T, class X > inline T   togglebit(T a, X pos) { T t=1;return (a^(t<<pos));      }


template<typename T> T POW(T base,T power)              { T ret=1; while(power)  { if(power & 1) ret=(ret*base); base=(base*base);  power>>=1; }return ret; }
template<typename T> T PPOW(T B,T P)                    { if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
template<typename T> T Bigmod(T base,T power,T mod)     { T ret=1; while(power)  { if(power & 1) ret=(ret*base)%mod; base=(base*base)%mod;  power>>=1; }return ret; }
template<typename T> T ModInverse(T number,T mod)       { return Bigmod(number,mod-2,mod); }
template<typename T> T GCD(T a,T b)                     { if(a<0)return GCD(-a,b);if(b<0)return GCD(a,-b);return (b==0)?a:GCD(b,a%b);}
template<typename T> T LCM(T a,T b)                     { if(a<0)return LCM(-a,b);if(b<0)return LCM(a,-b);return a*(b/GCD(a,b));}
template<typename T> T EUCLIDE(T a,T b,T &x,T &y)       { if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}   if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template<typename T> T ABS(T a)                         { if(a<0)return -a;else return a;}


template<typename T> double DIS(T x1,T y1,T x2, T y2)   { return sqrt( (double)( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ) );}
template<typename T> T ANGLE(T x1,T y1,T x2, T y2)      { return atan( double(y1-y2) / double(x1-x2));}
template<typename T> LL isLeft(T a,T b,T c)             { return (c.x-a.x)*(b.y-a.y)-(b.x-a.x)*(c.y-a.y); }


double DEG(double x) { return (180.0*x)/(M_PI*1.0);}
double RAD(double x) { return (x*(M_PI*1.0))/(180.0);}



void P_ARR(int *ar,int a,int b) {  if(a>b) swap(a,b); if(a<=b) cout << ar[a]; for(int i=a+1;i<=b;i++) cout << " "<<ar[i];  cout << endl; }
template<typename T> T In(){ char ch; T n = 0; bool ng = false; while (1) { ch = getchar(); if (ch == '-') { ng = true; ch = getchar(); break;} if (ch>='0' && ch<='9') break; }    while (1) { n = n*10 + (ch - '0'); ch = getchar(); if (ch<'0' || ch>'9')   break;    }  return (ng?-n:n);  }



int dir[5][2] = { {0,0},{1,0},{0,1},{-1,0},{0,-1} };                                  













#define  debug  0
#define  DD     if(debug)

#define eps     (1e-9)
#define pi      (2.0*acos(0.0)) 




#define  MX     5007
#define  MOD    1000000007
#define  inf    1000000000


const int N = 5007;

struct SUFFIX_ARRAY
{
    int wa[N],wb[N],ws[N],wv[N],r[N];
    int len; 


    int rank[N]; 

    int height[N]; 

    int sa[N]; 


    int dp[N][21]; 


    int cmp(int *ar,int a,int b,int l)
    {
        return (ar[a]==ar[b]) && (ar[a+l]==ar[b+l]);
    }

    void DA(int n,int m)
    {
        int i,j,p,*x=wa,*y=wb,*t;
        for(i=0; i<m; i++) ws[i]=0;
        for(i=0; i<n; i++) ws[x[i]=r[i]]++;
        for(i=1; i<m; i++) ws[i]+=ws[i-1];
        for(i=n-1; i>=0; i--) sa[--ws[x[i]]]=i;
        for(j=1,p=1; p<n; j*=2,m=p)
        {
            for(p=0,i=n-j; i<n; i++) y[p++]=i;
            for(i=0; i<n; i++) if(sa[i]>=j) y[p++]=sa[i]-j;
            for(i=0; i<n; i++) wv[i]=x[y[i]];
            for(i=0; i<m; i++) ws[i]=0;
            for(i=0; i<n; i++) ws[wv[i]]++;
            for(i=1; i<m; i++) ws[i]+=ws[i-1];
            for(i=n-1; i>=0; i--) sa[--ws[wv[i]]]=y[i];
            for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++)
                x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
            

        }
    }

    void calheight(int n)
    {
        

        

        int i,j,k=0;
        for(i=1; i<=n; i++) rank[sa[i]]=i;
        for(i=0; i<n; height[rank[i++]] = k )
            for(k?k--:0,j=sa[rank[i]-1]; r[i+k]==r[j+k]; k++);
    }

    void generate(char *s)
    {
        int n;
        for (n=0; s[n] ;n++) r[n]=(int)s[n];
		r[n]=0;

		this->len  = n;

        DA(n+1,128);
        calheight(n);
    }
    

    void sparse_table()
    {
        int n =  len+1;

        for(int i=0;i<n;i++) dp[i][0]=height[i];

        for (int j=1; (1 << j) <= n; j++)
            for (int i = 0; i+(1 << j)-1<n; i++)
                dp[i][j] = (dp[i][j-1]<=dp[ i+(1<<(j-1)) ][j-1] )? dp[i][j-1]:dp[i+(1<<(j-1))][j-1];
    }

    

    

    int find_lcp(int start,int end)
    {
        if(start>end) swap(start,end); start++;
        int diff=end-start;
        diff=31 - __builtin_clz(diff+1);
        return dp[start][diff]<=dp[end-(1<<diff)+1][diff]?dp[start][diff]:dp[end-(1<<diff)+1][diff];
    }

    

    int get_lcp(int s,int e){
        return find_lcp( rank[s] ,rank[e] );
    }

    void print()
    {
        cout << "length :  " << len << endl;
        cout << "s[n] = '$' " << endl;
        cout << "sorted suffix index(0 based) : " << endl;
        rep(i,0,len) cout << sa[i] << " , "; cout << endl;
        cout << "rank of suffix " << endl;
        rep(i,0,len) cout << rank[i] << " , "; cout << endl;
        cout << "LCP between i and i-1 " << endl;
        rep(i,0,len) cout << height[i] << " , "; cout << endl;
    }

}SA;



char ss[5007];
int n;

LL dp[MX][MX];


LL call(int pre,int pos)
{
   if(pos==n) return 1;

   if(pos>n) return 0;

   LL &ret = dp[pos][pre] ;
   if(ret!=-1) return ret;

   ret = 0;

   int prelen =  pos - pre;

   if( n-pos < prelen ) return ret;
   if( ss[pos]=='0' )     return ret;


   int nxt = pos - pre + pos;

   int ptr =SA.find_lcp( SA.rank[pos] , SA.rank[pre] );


   int nm = ptr + pos;

   if( nm<=nxt && ss[ptr+pos]<ss[ptr+pre] ) nxt++;

   if(nxt>n) return ret;











   rep(i,nxt,n)
   {
       ret  = ( ret + call(pos, i) ) % MOD;
   }

   return ret;
}


LL csum[MX][MX];




bool vis[MX][MX];
bool rrr[MX][MX];

bool check(int pre,int pos)
{
    if(vis[pre][pos]) return rrr[pre][pos];

    vis[pre][pos]=1;

    int s = 0;

    rrr[pre][pos]=0;

    bool flag = 1;

    rep(i,pre,pos-1)
    {
        if( ss[i] != ss[pos+s] ){
            if( ss[pos+s] > ss[i] )  rrr[pre][pos] = 1;
            break;
        }
        s++;
    }

    return rrr[pre][pos];

}



int main()
{

    I(n);

    n++;

    ss[0] = '0' ;

    SS(ss+1);

    SA.generate(ss);
    SA.sparse_table();


    rev(pre,n-1,0)
    {
        rev(pos,n,pre+1)
        {
            csum[pre][pos] = csum[pre][pos+1];

            if(pos==n)
            {
                dp[pre][pos]   = 1;
                csum[pre][pos] = 1;
            }
            else
            {
                


                int prelen =  pos - pre;

                if( n-pos < prelen )   continue;
                if( ss[pos]=='0' )     continue;


                int nxt = pos - pre + pos;




                int lcp = SA.get_lcp(pre,pos);

                if(lcp>=prelen) nxt++;
                else if(  ss[ pre+lcp ] > ss[pos+lcp] ) nxt++;


                dp[pre][pos]    = csum[pos][nxt];
                csum[pre][pos]  = (csum[pre][pos] + dp[pre][pos] ) %MOD;
            }
        }

        rev(pos,pre,0) csum[pre][pos]=csum[pre][pos+1];
    }

    PIL(dp[0][1]);


    return 0;
}
