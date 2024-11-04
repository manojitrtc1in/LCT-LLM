

#include<bits/stdc++.h>












































#define S scanf
#define P printf

#define LL long long int
#define ULL unsigned long long int
#define D double

#define SQR(n)      (n*n)
#define PI          2.0*acos(0.0)

#define all(a) a.begin(),a.end()
#define X  first
#define Y  second
#define MP make_pair
#define NL P("\n")

#define open       freopen("input.txt","r",stdin)
#define close      freopen ("output.txt","w",stdout)
#define S1(a)      scanf("%d",&a)
#define S2(a,b)    scanf("%d%d",&a,&b)
#define S3(a,b,c)  scanf("%d%d%d",&a,&b,&c)
#define SL1(a)     scanf("%lld",&a)
#define SL2(a,b)   scanf("%lld%lld",&a,&b)
#define SL3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define CHR        getchar()
#define PB(x)      push_back(x)
#define pb         push_back
#define PP         pop_back()
#define PF(x)      push_front(x)
#define PPF(x)     pop_front()
#define PS(x)      push(x)
#define sz()       size()
#define UB         upper_bound
#define LB         lower_bound
#define mxe(a,n)   (*max_element(a,a+n))
#define mne(a,n)   (*min_element(a,a+n))
#define SUM(a,n)   (accumulate(a,a+n,0))
#define countbit(x) __builtin_popcount(x)
#define DBG(n)      P("Done %d\n",n);



#define I(X)                       scanf("%d", &(X))
#define II(X, Y)                   scanf("%d%d", &(X), &(Y))
#define III(X, Y, Z)               scanf("%d%d%d", &(X), &(Y), &(Z))
#define DI(X) int (X);             scanf("%d", &X)
#define DII(X, Y) int X, Y;        scanf("%d%d", &X, &Y)
#define DIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)

#define ILL(X)          scanf("%lld", &(X))
#define DILL(X) LL (X); scanf("%lld", &X)



#define repv(i,a) for(int i=0;i<(int)a.size();i++)
#define revv(i,a) for(int i=((int)a.size())-1;i>=0;i--)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,a,b) for(int i=a;i>=b;i--)

#define FS(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)

#define MEM(a,val) memset(a,val,sizeof(a));
#define SET(a)     memset(a,-1,sizeof a)
#define CLR(a)     memset(a,0,sizeof a)
#define CMPL       cerr<< "Compilation Process Finished\n";cerr<< "----------------------------\n"

using namespace std;

template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T ModInv (T b,T m){return BigMod(b,m-2,m);}
template <typename T> T in(){char ch;T n = 0;bool ng = false;while (1){ch = getchar();if (ch == '-'){ng = true;ch = getchar();break;}if (ch>='0' && ch<='9')     break;}while (1){n = n*10 + (ch - '0');ch = getchar();if (ch<'0' || ch>'9')   break;}return (ng?-n:n);}
template <typename T> T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
template <typename T> T Bigmod(T b,T p,T m){ if(p==0) return 1; else if (!(p&1)) return SQR(Bigmod(b,p/2,m)) % m;else return ((b % m) * Bigmod(b,p-1,m)) % m;}
template <typename T> T Dis(T x1,T y1,T x2, T y2){return sqrt( SQR(x1-x2) + SQR(y1-y2) );}
template <typename T> T Angle(T x1,T y1,T x2, T y2){ return atan( double(y1-y2) / double(x1-x2));}
template <typename T> T DIFF(T a,T b) { T d = a-b;if(d<0)return -d;else return d;}
template <typename T> T ABS(T a) {if(a<0)return -a;else return a;}
template <typename T> T gcd(T a,T b){if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template <typename T> T euclide(T a,T b,T &x,T &y) {if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}   if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template <typename T> void ia (T a[],int n){for (int i=0; i<n; i++) cin >> a[i];}
template <typename T> void pa (T a[],int n){for (int i=0; i<n-1; i++) cout << a[i] << " ";cout << a[n-1] << endl;}
template <typename T> LL isLeft(T a,T b,T c) { return (a.x-b.x)*(b.y-c.y)-(b.x-c.x)*(a.y-b.y); }

int    Set(int N,int pos){ return N=N | (1<<pos);}
int  Reset(int N,int pos){return N= N & ~(1<<pos);}
bool Check(int N,int pos){return (bool)(N & (1<<pos));}
template< class T, class X > inline T   togglebit(T a, X i) { T t=1;return (a^(t<<i)); }

double DEG(double x) { return (180.0*x)/(PI);}
double RAD(double x) { return (x*(double)PI)/(180.0);}

#define VI  vector< int >
#define VII vector< VI >
#define VLL vector< LL >
#define PII pair< int , int >
#define PLL pair< LL , LL >
#define VPI vector< PII >



#define MX  200007
#define MOD 1000000007
#define INF (1<<30)-1+(1<<30)
#define eps 1e-9

#define base ((1<<l)-1)
#define lft (idx<<1)
#define rgt (lft|1)
#define mid ((l+r)>>1)





#define Base1 10000019ULL
#define Base2 10000079ULL
#define Base3 10000103ULL
#define MOD1  1000000007ULL
#define MOD2  1000000009ULL
#define MOD3  1000000021ULL
#define LOGX  17

const int N = (int)6e5 + 7;

pair< pair<int,int> , int> Suffix[N],tmpSuffix[N];
int Rank[N];
char s[N];
int cnt[N];
int stp;
int LCP[N];
string ss[N/10];
int l;

void RadixSort(int n,int m){
    for (int i=0;i<=m;i++)  cnt[ i ] = 0;

    for (int i=0;i<=n;i++)  cnt[ Suffix[i].X.Y ]++;
    for (int i=1;i<=m;i++)  cnt[i] += cnt[i-1];
    for (int i=n;i>=0;i--)  tmpSuffix[ --cnt[ Suffix[i].X.Y]  ] = Suffix[i];

    for (int i=0;i<=m;i++)  cnt[ i ] = 0;

    for (int i=0;i<=n;i++)  cnt[ tmpSuffix[i].X.X ]++;
    for (int i=1;i<=m;i++)  cnt[i] += cnt[i-1];
    for (int i=n;i>=0;i--)  Suffix[ --cnt[ tmpSuffix[i].X.X]  ] = tmpSuffix[i];
}

void SortSuffix(int n){
    for(int i=0;i<=n;i++)   Rank[i] = (int)s[i];

    stp = 1;
    for (int l=1;l<n;l<<=1,stp++){
        int mx = 0;

        for (int i=0;i<=n;i++){
            Suffix[i].X.X = Rank[ i ];
            Suffix[i].X.Y = (i+l<n?Rank[i+l]:0);
            Suffix[i].Y = i;

            mx = max( mx,Suffix[i].X.X );
            mx = max( mx,Suffix[i].X.Y );
        }

        RadixSort(n,mx);

        for (int i=0;i<=n;i++){
            if (!i)                                 Rank[ Suffix[i].Y ] = i;
            else if (Suffix[i].X != Suffix[i-1].X)  Rank[ Suffix[i].Y ] = i;
            else                                    Rank[ Suffix[i].Y ] = Rank[ Suffix[i-1].Y ];
        }
    }
}

void CalcLCP(int n){
    int i,j,k=0;
    for(i=0;i<n;LCP[Rank[i++]]=k)
        for(k?k--:0,j=Suffix[Rank[i]-1].Y;s[i+k]==s[j+k];k++);
}

int sqz;

struct Query{
    int l,r,id;
    int ll,rr;

    Query(){}

    Query(int _l,int _r,int _id,int _ll,int _rr){
        l = _l;
        r = _r;
        id= _id;
        ll= _ll;
        rr= _rr;
    }

    bool operator< (const Query& p)const{
        if (l/sqz < p.l/sqz)    return true;
        else if (l/sqz == p.l/sqz)
            return r<p.r;
    }
};

Query q[N],tq[N];
int countt[N];
PII ans[N];
int id[N];

struct SegmentTree{
    int l;
    VI Tree;
    int lf[30],rg[30];
    int p,q;

    SegmentTree(){}

    SegmentTree(int n){
        for(l=0;;l++){
            if (1<<l >= n){
                break;
            }
        }

        Tree.resize(base+base+10);
    }

    SegmentTree(int n,int a[],int f){
        for(l=0;;l++){
            if (1<<l >= n){
                break;
            }
        }

        Tree.resize(base+base+10);

        for (int i=1;i<=n;i++)  Tree[i+base] = a[i];
        for (int idx=base;idx;idx--){
            if (!f) Tree[idx] = min(Tree[lft],Tree[rgt]);
            else    Tree[idx] = max(Tree[lft],Tree[rgt]);
        }
    }

    void Update(int idx,int v){
        idx += base;
        Tree[idx] += v;
        idx >>= 1;

        while(idx){
            Tree[idx] = max(Tree[lft],Tree[rgt]);
            idx >>= 1;
        }
    }

    int LeftIdx(int idx,int v){
        while(idx <= base){
            if (Tree[rgt] < v) idx = rgt;
            else               idx = lft;
        }

        return idx-base;
    }

    int RightIdx(int idx,int v){
        while(idx <= base){
            if (Tree[lft] < v)  idx = lft;
            else                idx = rgt;
        }

        return idx-base;
    }

    void FindSeg(int a,int b){
        p = q = 0;
        a += base;
        b += base;

        while(a <= b){
            if (a%2 == 1)   lf[++p] = a;
            if (b%2 == 0)   rg[++q] = b;

            a = (a+1)>>1;
            b = (b-1)>>1;
        }
    }

    int FindLeft(int a,int b,int v){
        if (a > b)      return -1;

        FindSeg(a,b);

        for (int i=1;i<=q;i++){
            if (Tree[ rg[i] ] < v)
                return LeftIdx(rg[i],v);
        }

        for (int i=p;i>0;i--){
            if (Tree[ lf[i] ] < v)
                return LeftIdx(lf[i],v);
        }

        return -1;
    }

    int FindRight(int a,int b,int v){
        if (a > b)      return MOD;

        FindSeg(a,b);

        for (int i=1;i<=p;i++){
            if (Tree[ lf[i] ] < v)
                return RightIdx(lf[i],v);
        }

        for (int i=q;i>0;i--){
            if (Tree[ rg[i] ] < v)
                return RightIdx(rg[i],v);
        }

        return MOD;
    }

    int GoDown(int idx,int v){
        while(idx <= base){
            if (Tree[lft] == v) idx = lft;
            else                idx = rgt;
        }

        return idx-base;
    }

    PII Query(int a,int b){
        a += base;
        b += base;
        p = q = 0;

        int mx = 0;

        while(a <= b){
            if (a%2 == 1)   mx = max(Tree[a],mx),lf[++p] = a;
            if (b%2 == 0)   mx = max(Tree[b],mx),rg[++q] = b;

            a = (a+1)>>1;
            b = (b-1)>>1;
        }

        for (int i=1;i<=p;i++)
            if (Tree[ lf[i] ] == mx)
                return MP(GoDown( lf[i],mx ),mx);

        for (int i=q;i;i--)
            if (Tree[ rg[i] ] == mx)
                return MP(GoDown( rg[i],mx ),mx);
    }
};

void RadixSort2(int n,int m){
    for (int i=0;i<=m;i++)  countt[i] = 0;
    for (int i=1;i<=n;i++)  countt[ q[i].r ]++;
    for (int i=1;i<=m;i++)  countt[i] += countt[i-1];
    for (int i=n;i>=1;i--)  tq[ countt[ q[i].r ]-- ] = q[i];
    
    for (int i=0;i<=m;i++)  countt[i] = 0;
    for (int i=1;i<=n;i++)  countt[ tq[i].l/sqz ]++;
    for (int i=1;i<=m;i++)  countt[i] += countt[i-1];
    for (int i=n;i>=1;i--)  q[ countt[ tq[i].l/sqz ]-- ] = tq[i];
}

int main(){
    S("%s",s);
    ss[0] = s;

    DI(n);

    for (int i=1;i<=n;i++){
        S("%s",s);
        ss[i] = s;
    }

    int l = 0;

    for (int i=0;i<=n;i++){
        for (int j=0;j<ss[i].length();j++,l++){
            s[l] = ss[i][j];
            id[l] = i;
        }

        s[l] = '#';
        l++;
    }

    s[l] = 0;

    SortSuffix(l);
    CalcLCP(l);
    SegmentTree st = SegmentTree(l,LCP,0);
















    DI(m);
    sqz = sqrt(l)+3;

    for (int i=1;i<=m;i++){
        DII(l2,r2);
        DII(l1,r1);

        int len =r1-l1+1;
        l1--;

        int x = st.FindLeft(1,Rank[l1],len);         x = max(x,1);
        int y = st.FindRight(Rank[l1]+1,l,len)-1;

        y = min(l,y);

        q[i] = Query(x,y,i,l2,r2);
        

    }

    

    RadixSort2(m,l+5);

    st = SegmentTree(n);


    int ii = 1,jj = 0;

    for (int i=1;i<=m;i++){
        

        while(jj < q[i].r){
            jj++;
            if (id[Suffix[jj].Y]) st.Update(id[Suffix[jj].Y],1);
        }

        while(jj > q[i].r){
            if (id[Suffix[jj].Y]) st.Update(id[Suffix[jj].Y],-1);
            jj--;
        }

        while(ii < q[i].l){
            if (id[Suffix[ii].Y]) st.Update(id[Suffix[ii].Y],-1);
            ii++;
        }

        while(ii > q[i].l){
            ii--;
            if (id[Suffix[ii].Y]) st.Update(id[Suffix[ii].Y],1);
        }

        ans[q[i].id] = st.Query(q[i].ll,q[i].rr);
    }

    for (int i=1;i<=m;i++)  P("%d %d\n",ans[i].X,ans[i].Y);
return 0;
}