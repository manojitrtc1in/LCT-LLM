




























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


#define X                           first
#define Y                           second
#define XX                          first.first
#define XY                          first.second
#define YX                          second.first
#define YY                          second.second











































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
#define  wait       getchar()
#define  eps        (1e-7)
#define  pi         (2.0*acos(0.0)) 



#define  READ       freopen("C:\\Users\\BackBencher\\Desktop\\input.txt","r",stdin)
#define  WRITE      freopen("C:\\Users\\BackBencher\\Desktop\\output.txt","w",stdout)
#define  _cin       ios_base::sync_with_stdio(0); cin.tie(0);




































































#define  VI     vector<int>
#define  pii    pair<int,int>


#define Base1   10000019ULL
#define Base2   10000079ULL
#define Base3   10000103ULL
#define MOD1    1000000007ULL
#define MOD2    1000000009ULL
#define MOD3    1000000021ULL


#define  MOD    1000000007LL
#define  inf    2000000007
#define  INF    (1LL<<61)


#define  MX     300007
#define  maxn   MX


int ar[MX];

char ss[MX];


struct Manacher {
    char text[MX*2];
    int     p[MX*2];
    int lcp,lcp_cen;
    int tot;
    vector< pair<int,int> > pal;

    void init() {
        pal.clear();
        lcp=0;
        tot=0;
        memset(p,0,sizeof p);
    }

    void generate(char *s) {
        init();
        int len = 0 , i=0 ;
        text[len++] = '^';
        while(s[i]) text[len++]=  '#' , text[ len++ ] = s[i++] ;
        text[len++]=  '#';
        text[len++]=  '$';
        int c = 0; 

        int r = 0; 

        for(i=1; i<len-1; i++) {
            int j = (c<<1)-i; 

            p[i] = (r>i)?min(r-i,p[j]):0;
            while(text[i+1+p[i]]==text[i-1-p[i]]) p[i]++;
            if(i+p[i]>r) c=i,r=i+p[i];
        }
        for(i=1; i<len-1; i++) {






            if(p[i]>lcp) {
                lcp     = p[i];
                lcp_cen = i;
            }













        }

        for(int i=2;i<len-1;i+=2){


            ar[i/2] = p[i];
        }


    }

    void BUG(char *s) {
        for(int i=0; i<pal.size(); i++) {
            for(int j=pal[i].X; j<pal[i].Y; j++) {
                cout << s[j];
            }
            cout << endl;
        }
    }

}man;

char ms[MX];

int n;

int mil[MX];

void z_function(int *z,char *s) {
    int len = strlen(s);
    rep(i,0,len) z[i] = 0;
    for (int i = 1, l = 0, r = 0; i < len; ++i) {
        if (i <= r)  z[i] = min (r - i + 1, z[i - l]);
        while ( i + z[i] < len && s[z[i]] == s[i + z[i]] )   ++z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    z[0] = len;
    int id = 1;
    rep(i,n+1,len-1) {
        mil[id++] = z[i];
    }
}

int  zz[MX];

struct Seg_Point_update_range_Max {

    int tree[2*MX];
    int n;

    void init(int *ar) {
        rev(i,n,1)   tree[i-1+n] = ar[i];
        rev(i,n-1,1) tree[i]     = Max(tree[(i<<1)],tree[(i<<1)|1]);
    }

    void update(int idx,int val) {
        idx--;
        for(tree[idx+=n]=val; idx>1; idx>>=1) {
            tree[idx>>1] = Max(tree[idx],tree[idx^1]);
        }
    }


    int query(int x,int y) {
        int ret = 0;
        x--;
        for(x+=n,y+=n; x<y; x>>=1,y>>=1) {
            if(x&1) ret=Max(ret,tree[x]),x++;
            if(y&1) --y,ret=Max(ret,tree[y]);
        }
        return ret;
    }

} smax;


int main() {
    SS(ss);
    man.init();
    man.generate(ss);
    n=strlen(ss);
    rep(i,1,n) {
        if(ar[i]==n) {
            cout << 1 << endl;
            cout << 1 << " " << n << endl;
            return 0;
        }
    }

    int id=n-1;
    rep(i,0,n-1) {
        ms[i] = ss[id--];
    }
    ms[n] = '#';

    rep(i,0,n-1) {
        ms[n+1+i] = ss[i];
    }

    ms[n+1+n] = 0;

    z_function(zz,ms);

    smax.n = n;
    smax.init(mil);

    int ret = -1;
    int majpos  = -1;
    int sufflen = -1;
    int majlen  = 0;

    rep(i,2,n-1) {
        int low  = i;
        int high = i+(ar[i]/2);
        if(high==n) high--;
        int pos = -1;
        while( low<=high ) {
            int mid = (low+high)>>1;
            int lt = (i-(mid-i));
            if(lt-1 < 1) {
                high = mid-1;
                continue;
            }
            

            int v = smax.query(1,lt-1);
            if(v>0) pos = mid, low = mid+1;
            else   high = mid-1;
        }


        if(pos==-1) continue; 

        

        int lpos = i-(pos-i);
        low = 1;
        high = Min( n-pos , lpos);
        int mxlen = 0;


        while(low<=high) {
            int mid = (low+high)>>1;
            if(lpos-mid<1) {
                high = mid-1;
                continue;
            }
            int mx = smax.query(1,lpos-mid);
            if(mx>=mid) mxlen = mid , low=mid+1;
            else   high =  mid-1;
        }


        if(mxlen) {
            int tot = (pos-i)*2+1 + mxlen*2;


            if(ret<tot) {
                ret = tot;
                majpos = i-(pos-i);
                majlen = (pos-i)*2+1;
                sufflen = mxlen;
            }
        }


    }
    int flag = 0;
    int mxsuff = 0;
    int spos = -1;
    rep(i,1,n) {
        int e=i+(ar[i]/2);
        if(e==n && ar[i]>=ret) {
            if(mxsuff<ar[i]) {
                mxsuff=ar[i];
                spos = i;
            }
        }
    }

    int midmx = 0;

    rep(i,1,n)
    {
        if(ar[i]>=ret)
        {
            ret = ar[i];
            midmx = i;
        }
    }

    if(midmx)
    {


        cout << 1 << endl;
        cout << (midmx-(ret/2)) << " " << ret << endl;
        return 0;
    }


    if(spos!=-1) {
        cout << 1 << endl;
        cout << (spos-(n-spos)) << " " << mxsuff << endl;
        return 0;
    }








    cout << 3 << endl;
    rep(i,1,n) {
        if(mil[i]>=sufflen ) {
            cout << i << " " << sufflen << endl;
            break;
        }
    }
    cout << majpos << " " << majlen << endl;
    cout << (n-sufflen+1) << " " << sufflen << endl;


    return 0;
}