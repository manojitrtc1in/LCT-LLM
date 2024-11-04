






















using namespace std;


















































typedef long long LL;
typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<string> VS;
typedef vector<LL> VL;
typedef vector<double> VD;
typedef set<int> SI;
typedef set<string> SS;
typedef map<int, int> MII;
typedef map<string, int> MSI;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef vector<VII> VVII;
template<class T> inline void RST(T &A){memset(A, 0, sizeof(A));}
template<class T> inline void FLC(T &A, int x){memset(A, x, sizeof(A));}
template<class T> inline void CLR(T &A){A.clear();}

 

const int dx4[] = {-1, 0, 1, 0};
const int dy4[] = {0, 1, 0, -1};
const int dx8[] = {-1, 0, 1, 0 , -1 , -1 , 1 , 1};
const int dy8[] = {0, 1, 0, -1 , -1 , 1 , -1 , 1};
const int dxhorse[] = {-2 , -2 , -1 , -1 , 1 , 1 , 2 , 2};
const int dyhorse[] = {1 ,  -1 , 2  , -2 , 2 ,-2 , 1 ,-1};
const int mod = 1000000007;


const int inf = 0x3f3f3f3f;
const LL inff = 1LL << 60;
const double eps = 1e-9;
const double oo = 1e25;
const double pi = acos(-1.0); 



 



template<class T> inline void checkMin(T &a,const T b){if (b<a) a=b;}
template<class T> inline void checkMax(T &a,const T b){if (a<b) a=b;}
template<class T> inline void checkMin(T &a, T &b, const T x){checkMin(a, x), checkMin(b, x);}
template<class T> inline void checkMax(T &a, T &b, const T x){checkMax(a, x), checkMax(b, x);}
template <class T, class C> inline void checkMin(T& a, const T b, C c){if (c(b,a)) a = b;}
template <class T, class C> inline void checkMax(T& a, const T b, C c){if (c(a,b)) a = b;}
template<class T> inline T min(T a, T b, T c){return min(min(a, b), c);}
template<class T> inline T max(T a, T b, T c){return max(max(a, b), c);}
template<class T> inline T min(T a, T b, T c, T d){return min(min(a, b), min(c, d));}
template<class T> inline T max(T a, T b, T c, T d){return max(max(a, b), max(c, d));}
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline T cub(T a){return a*a*a;}
template<class T> inline T ceil(T x, T y){return (x - 1) / y + 1;}
inline int sgn(double x){return x < -eps ? -1 : x > eps;}
inline int sgn(double x, double y){return sgn(x - y);}
inline double cot(double x){return 1./tan(x);};
inline double sec(double x){return 1./cos(x);};
inline double csc(double x){return 1./sin(x);};




namespace BO{
inline bool _1(int x, int i){return bool(x&1<<i);}
inline bool _1(LL x, int i){return bool(x&1LL<<i);}
inline LL _1(int i){return 1LL<<i;}
inline LL _U(int i){return _1(i) - 1;};
inline int reverse_bits(int x){x = ((x >> 1) & 0x55555555) | ((x << 1) & 0xaaaaaaaa);x = ((x >> 2) & 0x33333333) | ((x << 2) & 0xcccccccc);x = ((x >> 4) & 0x0f0f0f0f) | ((x << 4) & 0xf0f0f0f0);x = ((x >> 8) & 0x00ff00ff) | ((x << 8) & 0xff00ff00);x = ((x >>16) & 0x0000ffff) | ((x <<16) & 0xffff0000);return x;}
inline LL reverse_bits(LL x){x = ((x >> 1) & 0x5555555555555555LL) | ((x << 1) & 0xaaaaaaaaaaaaaaaaLL);x = ((x >> 2) & 0x3333333333333333LL) | ((x << 2) & 0xccccccccccccccccLL);x = ((x >> 4) & 0x0f0f0f0f0f0f0f0fLL) | ((x << 4) & 0xf0f0f0f0f0f0f0f0LL);x = ((x >> 8) & 0x00ff00ff00ff00ffLL) | ((x << 8) & 0xff00ff00ff00ff00LL);x = ((x >>16) & 0x0000ffff0000ffffLL) | ((x <<16) & 0xffff0000ffff0000LL);x = ((x >>32) & 0x00000000ffffffffLL) | ((x <<32) & 0xffffffff00000000LL);return x;}
template<class T> inline bool odd(T x){return x&1;}
template<class T> inline bool even(T x){return !odd(x);}
template<class T> inline T low_bit(T x) {return x & -x;}
template<class T> inline T high_bit(T x) {T p = low_bit(x);while (p != x) x -= p, p = low_bit(x);return p;}
template<class T> inline T cover_bit(T x){T p = 1; while (p < x) p <<= 1;return p;}
template<class T> inline int cover_idx(T x){int p = 0; while (_1(p) < x ) ++p; return p;}

inline int clz(int x){return __builtin_clz(x);}
inline int clz(LL x){return __builtin_clzll(x);}
inline int ctz(int x){return __builtin_ctz(x);}
inline int ctz(LL x){return __builtin_ctzll(x);}
inline int lg2(int x){return !x ? -1 : 31 - clz(x);}
inline int lg2(LL x){return !x ? -1 : 63 - clz(x);}
inline int low_idx(int x){return !x ? -1 : ctz(x);}
inline int low_idx(LL x){return !x ? -1 : ctz(x);}
inline int high_idx(int x){return lg2(x);}
inline int high_idx(LL x){return lg2(x);}
inline int parity(int x){return __builtin_parity(x);}
inline int parity(LL x){return __builtin_parityll(x);}
inline int count_bits(int x){return __builtin_popcount(x);}
inline int count_bits(LL x){return __builtin_popcountll(x);}

} using namespace BO;



namespace NT{
template<class T> inline T lowbit(T x) {return x & -x;}

template <class T>inline T GCD(T A,T B){T C;while(B!=0)C=B,B=A%B,A=C;return A;}

template <class T>inline T LCM(T A,T B){return A*(B/GCD(A,B));}

template<class T>inline T Mod(T a,T b){a%=b;return a<0?a+b:a;}

template<class T>inline T MulMod(T a,T b,T c){if(c==1)return 0;if(c<=0)return -1;T ret=0,tmp;tmp=a=Mod(a,c);b=Mod(b,c);while(b){if(b&0x1)if((ret+=tmp)>=c)ret-=c;if((tmp<<=1)>=c)tmp-=c;b>>=1;}return ret;}
template<class T,class Tb> inline T PowMod(Tb a,T b,T c){if(c==1)return 0;if(c<=0)return -1;a=Mod(a,(Tb)c);Tb ret(1L%c);while(b){if(b&0x1)ret=ret*a%c;a=a*a%c;b>>=1;}return (T)ret;}
template<class T> inline T id0(T a,T b,T c){if(c==1)return 0;if(c<=0)return -1;a=Mod(a,c);T ret(1L%c);while(b){if(b&0x1)ret=MulMod(ret,a,c);a=MulMod(a,a,c);b>>=1;}return ret;}
template<class T,class Tb> inline T Pow(T a, Tb b){T c(1); while (b){if (b&1) c *= a;a *= a, b >>= 1;}return c;}
template <class T>inline T id2(T a,T b,T& x,T& y){T t,ret;if (!b){x=1,y=0;return a;}ret=id2(b,a%b,x,y);t=x,x=y,y=t-a/b*y;return ret;}
template <class T>inline T Inv(T a,T n){if(n<=0)return -1;T d,x,y;d=id2(a,n,x,y);if(d!=1)return -1;return Mod(x,n);}
template<class T, int MAXN, T MOD=-1>class Matrix {public:T m[MAXN][MAXN];Matrix(){}void init(T num[MAXN][MAXN]){for(int i = 0 ; i < MAXN ; i++){for(int j = 0 ; j < MAXN ; j++){m[i][j] = num[i][j];if (MOD!=-1)  m[i][j] %= MOD;}}}
friend Matrix operator*(const Matrix &m1 ,const Matrix &m2) {int i, j, k;Matrix ret;memset(ret.m, 0, sizeof(ret.m));for (i = 0; i < MAXN; i++) {for (j = 0; j < MAXN; j++)if ( m1.m[i][j] ){for(k = 0 ; k < MAXN ; k++){ret.m[i][k] += m1.m[i][j] * m2.m[j][k];if (MOD!=-1) ret.m[i][k] %= MOD;}}}return ret;}
friend Matrix operator+(const Matrix &m1 ,const Matrix &m2) {int i, j;Matrix ret;for (i = 0; i < MAXN; i++) {for (j = 0; j < MAXN; j++) {ret.m[i][j] = 0;ret.m[i][j] = m1.m[i][j]+m2.m[i][j];if (MOD!=-1)  ret.m[i][j] %= MOD;}}return ret;}
friend Matrix operator^(const Matrix &_M , LL nx){Matrix ret,M(_M);for(int i = 0 ; i < MAXN ; i++){for(int j = 0 ; j < MAXN ; j++){if(i == j)ret.m[i][j] = 1;else ret.m[i][j] = 0;}}while(nx){if(nx & 1)ret = ret * M;nx = nx >> 1;M = M * M;}return ret;}
};

const int PMAX = 1000;VI Prime; bitset<PMAX> isPrime;

void sieve(){if (!Prime.empty()) return ;FOR(i, 2, PMAX){if (!isPrime[i]) Prime.PB(i);for (int j=0;j<SZ(Prime)&&i*Prime[j]<PMAX;++j){isPrime[i*Prime[j]]=1; if (!(i%Prime[j])) break;}}}
template<class T>T phi(T n){T ret=1,i;for (i=2;i*i<=n;i++)if (n%i==0){n/=i,ret*=i-1;while (n%i==0)n/=i,ret*=i;}if (n>1)ret*=n-1;return ret;}

} using namespace NT;





namespace Date{
int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
struct date{int year,month,day;};
inline int leap(int year){return (year%4==0&&year%100!=0)||year%400==0;}
inline int legal(date a){if (a.month<0||a.month>12) return 0;if (a.month==2)return a.day>0&&a.day<=28+leap(a.year);return a.day>0&&a.day<=days[a.month-1];}
inline int datecmp(date a,date b){if (a.year!=b.year)return a.year-b.year;if (a.month!=b.month)return a.month-b.month;return a.day-b.day;}
int weekday(date a){int tm=a.month>=3?(a.month-2):(a.month+10);int ty=a.month>=3?a.year:(a.year-1);return (ty+ty/4-ty/100+ty/400+(int)(2.6*tm-0.2)+a.day)%7;}
int id3(date a){int ret=a.year*365+(a.year-1)/4-(a.year-1)/100+(a.year-1)/400,i;days[1]+=leap(a.year);for (i=0;i<a.month-1;ret+=days[i++]);days[1]=28;return ret+a.day;}
date id1(int a){date ret;ret.year=a/146097*400;for (a%=146097;a>=365+leap(ret.year);a-=365+leap(ret.year),ret.year++);days[1]+=leap(ret.year);for (ret.month=1;a>=days[ret.month-1];a-=days[ret.month-1],ret.month++);days[1]=28;ret.day=a+1;return ret;}
}





const int N = 1001;
int n,m,g[N][N],b[N];
bitset<N> s[N],t;
int work(int k){
    REP(i,n)
      REP(j,m){
        s[i][j] = (g[i][j]>=k);
      }
    REP(i,n){
        b[i] = s[i].count();
    }
    FOR(i,0,n){
      if (b[i]<2) continue;
      FOR(j,i+1,n){
        if (b[j]<2) continue;
        if ( b[i]+b[j]>=n+2 ) return true;
        t = s[i] & s[j];
        if (t.count()>=2) return true;
      }

    }
    return false;
}
int main(){
    int i,j;
    scanf("%d%d", &n, &m);
    for (i=0; i<n; i++)
        for (j=0; j<m; j++){
          scanf("%d", &g[i][j]);
        }
    int l=0, r=1e9+7, mid, res;
    while ( l<r ){
        mid = (l+r+1)>>1;
        res = work(mid);
        if ( res ) l = mid;
        else r = mid-1;
    }
    printf("%d\n", l);
    return 0;
}


