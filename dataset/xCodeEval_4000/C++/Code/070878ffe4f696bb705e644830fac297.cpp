

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

#define S scanf
#define PP printf

#define  F(i,a,b) for(int i=a;i<b; i++)
#define FF(i,a,b) for(i=a;i<=b;i++)
#define FI(i,a,b) for((typeof(b)) i=a;i<=b;i++)
#define FR(i, a, b,inc) for(  i = (a); i <= (b); i+=inc )
#define RFR(i, a, b,dec) for(  i = (a); i >= (b); i-=dec )
#define FS(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define PR(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++) cout << *it << " "; cout << endl;

#define LL long long int
#define ULL unsigned long long int
#define D double

#define Max(a,b)    (a>b?a:b)
#define Min(a,b)    (a<b?a:b)
#define _Max(a,b,c) Max(a,Max(b,c))
#define _Min(a,b,c) Min(a,Min(b,c))
#define SQR(n)      (n*n)
#define PI          2.0*acos(0.0)

#define all(a) a.begin(),a.end()
#define X  first
#define Y  second
#define MP make_pair

#define PCC        cout<<"Case "<<cas++<<": ";
#define PC         printf("Case %d:",cas++);
#define PCN        printf("Case %d:\n",cas++);
#define NL         printf("\n");
#define cp         printf("here\n");

#define open       freopen("input.txt","r",stdin)
#define close      freopen ("output.txt","w",stdout)
#define Case(a)    printf("Case %d:",a)
#define caseh(a)   printf("Case #%d: ",a)
#define S1(a)      scanf("%d",&a)
#define S2(a,b)    scanf("%d%d",&a,&b)
#define S3(a,b,c)  scanf("%d%d%d",&a,&b,&c)
#define SL1(a)     scanf("%lld",&a)
#define SL2(a,b)   scanf("%lld%lld",&a,&b)
#define SL3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define CHR        getchar()
#define PB(x)      push_back(x)
#define pb         push_back


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

int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
int toLlint(string s) { long long int sm; stringstream ss(s); ss>>sm; return sm;}
int cdigittoint(char ch){return ch-'0';}
bool isVowel(char ch){ ch=toupper(ch); if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true; return false;}
bool isConst(char ch){if (isalpha(ch) && !isVowel(ch)) return true; return false;}

double DEG(double x) { return (180.0*x)/(PI);}
double RAD(double x) { return (x*(double)PI)/(180.0);}

#define VI  vector< int >
#define VII vector< VI >
#define VLL vector< LL >
#define PII pair< int , int >
#define PLL pair< LL , LL >
#define VPI vector< PII >



#define MX  300007
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

char s[MX],a[MX];
VI   adj[MX];
int  L[MX],T[MX];
int  chainID[MX],chainNo,ptr;
int  Start[MX],subTree[MX];
int  pos[MX];

const int N = int(6e5)+10;

int cmp(int *r,int a,int b,int l){
    return (r[a]==r[b]) && (r[a+l]==r[b+l]);
}
int wa[N],wb[N],wws[N],wv[N];
int rnk[N],height[N];

void DA(int *r,int *sa,int n,int m){
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;i++) wws[i]=0;
    for(i=0;i<n;i++) wws[x[i]=r[i]]++;
    for(i=1;i<m;i++) wws[i]+=wws[i-1];
    for(i=n-1;i>=0;i--) sa[--wws[x[i]]]=i;
    for(j=1,p=1;p<n;j*=2,m=p)
    {
        for(p=0,i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0;i<n;i++) wv[i]=x[y[i]];
        for(i=0;i<m;i++) wws[i]=0;
        for(i=0;i<n;i++) wws[wv[i]]++;
        for(i=1;i<m;i++) wws[i]+=wws[i-1];
        for(i=n-1;i>=0;i--) sa[--wws[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
}
void calheight(int *r,int *sa,int n){
    int i,j,k=0;
    for(i=1;i<=n;i++) rnk[sa[i]]=i;
    for(i=0;i<n;height[rnk[i++]]=k)
        for(k?k--:0,j=sa[rnk[i]-1];r[i+k]==r[j+k];k++);
}

int sa[N],data[N],n,p,q;
char str[N];
int  DP[22][N];

int Deal ()
{
    DA(data,sa,n+1,128);
    calheight(data,sa,n);

    for(int i=1;i<=n;i++)   DP[0][i] = height[i];

    for (int i=1;(1<<i) <= n;i++)
        for (int j=1;j+(1<<i)-1 <= n;j++)
            DP[i][j] = min( DP[i-1][j],DP[i-1][j+(1<<(i-1))] );
}

int lcp(int st,int ed){
    if (st == ed)       return n-st+1;

    st = rnk[ st-1 ];
    ed = rnk[ ed-1 ];

    if (st > ed)        swap(st,ed);
    st++;

    int b = 31 - __builtin_clz(ed-st+1);

    return min( DP[b][st],DP[b][ed-(1<<b)+1] );
}

void Dfs(int u,int p,int l=0){
    T[u] = p;
    L[u] = l;

    subTree[u] = 1;

    for (int i=0;i<adj[u].size();i++){
        int v = adj[u][i];

        if (v == p) continue;

        Dfs(v,u,l+1);
        subTree[u] += subTree[v];
    }
}

void Decompose(int u,int p){
    if (Start[chainNo] == 0)
        Start[chainNo] = u;

    chainID[u] = chainNo;
    pos[u] = ++ptr;
    a[ptr] = s[u];

    int SC = -1,mx = -1;

    for (int i=0;i<adj[u].size();i++){
        int v= adj[u][i];

        if (v == p)     continue;

        if (subTree[v] > mx){
            mx = subTree[v];
            SC = i;
        }
    }

    if (SC != -1)       Decompose(adj[u][SC],u);

    for (int i=0;i<adj[u].size();i++){
        if(i == SC)     continue;

        int v = adj[u][i];

        if (v != p){
            chainNo++;
            Decompose(v,u);
        }
    }
}

void HLD(){
    chainNo = 1;
    Dfs(1,-1);
    Decompose(1,-1);
}

int  rID[MX];
PII  seg[2][MX];
PII  up[MX],down[MX];

int lca(int u,int v){
    while(1){
        int uChain = chainID[u],vChain = chainID[v];
        int uSt = Start[uChain], vSt = Start[vChain];

        if (uChain == vChain)       return L[u]<L[v]?u:v;
        else if (L[uSt] > L[vSt])   u = T[uSt];
        else                        v = T[vSt];
    }
}

int FindSeg(int u,int v,int f){
    int p = 0,q = 0;
    int w = lca(u,v);

    while(1){
        int uChain = chainID[u],wChain = chainID[w];
        int uSt = Start[uChain];

        if (uChain == wChain){
            if (u != w)     up[++p] = MP( rID[ pos[u] ],rID[ pos[w] ] );
            break;
        }

        up[++p] = MP( rID[ pos[u] ],rID[ pos[uSt] ] );
        u = T[uSt];
    }

    while(1){
        int vChain = chainID[v],wChain = chainID[w];
        int vSt = Start[vChain];

        if (vChain == wChain){
            if (v != w)     down[++q] = MP( pos[w],pos[v] );
            break;
        }

        down[++q] = MP( pos[vSt],pos[v] );
        v = T[vSt];
    }

    if (u == v && v == w)       down[++q] = MP( pos[w],pos[w] );

    int l = 0;

    for (int i=1;i<=p;i++)      seg[f][++l] = up[i];
    for (int i=q;i;i--)         seg[f][++l] = down[i];

    return l;
}

int main(){
    DI(m);
    S("%s",s+1);

    rep(i,2,m){
        DII(u,v);

        adj[u].PB(v);
        adj[v].PB(u);
    }

    HLD();

    rep(i,1,m)      data[n++] = a[i];   data[n++] = '#';
    rev(i,m,1)      data[n++] = a[i],   rID[ i ] = n;

    Deal();

    DI(q);

    while(q--){
        DII(u1,v1);
        DII(u2,v2);

        int l1 = FindSeg(u1,v1,0);
        int l2 = FindSeg(u2,v2,1);

        int pt1 = 1,pt2 = 1,ans = 0;

        while(pt1 <= l1 && pt2 <= l2){
            PII &aa = seg[0][pt1], &bb = seg[1][pt2];
            int len = min( aa.Y-aa.X,bb.Y-bb.X )+1;
            int LCP = lcp( aa.X, bb.X );

            if (LCP < len)      { ans += LCP; break; }

            ans  += len;
            aa.X += len;        if (aa.X > aa.Y)    pt1++;
            bb.X += len;        if (bb.X > bb.Y)    pt2++;
        }

        PP("%d\n",ans);
    }
return 0;
}