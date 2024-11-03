#ifdef _MSC_VER
#pragma comment(linker, "/STACK:1024000000,1024000000")
#endif
#pragma GCC optimize ("O3")
#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>
using namespace std;

#define REP(i, n) for (int i=0;i<int(n);++i)
#define FOR(i, a, b) for (int i=int(a);i<int(b);++i)
#define DWN(i, b, a) for (int i=int(b-1);i>=int(a);--i)
#define REP_1(i, n) for (int i=1;i<=int(n);++i)
#define FOR_1(i, a, b) for (int i=int(a);i<=int(b);++i)
#define DWN_1(i, b, a) for (int i=int(b);i>=int(a);--i)
#define REP_C(i, n) for (int n____=int(n),i=0;i<n____;++i)
#define FOR_C(i, a, b) for (int b____=int(b),i=a;i<b____;++i)
#define DWN_C(i, b, a) for (int a____=int(a),i=b-1;i>=a____;--i)
#define REP_N(i, n) for (i=0;i<int(n);++i)
#define FOR_N(i, a, b) for (i=int(a);i<int(b);++i)
#define DWN_N(i, b, a) for (i=int(b-1);i>=int(a);--i)
#define REP_1_C(i, n) for (int n____=int(n),i=1;i<=n____;++i)
#define FOR_1_C(i, a, b) for (int b____=int(b),i=a;i<=b____;++i)
#define DWN_1_C(i, b, a) for (int a____=int(a),i=b;i>=a____;--i)
#define REP_1_N(i, n) for (i=1;i<=int(n);++i)
#define FOR_1_N(i, a, b) for (i=int(a);i<=int(b);++i)
#define DWN_1_N(i, b, a) for (i=int(b);i>=int(a);--i)
#define REP_C_N(i, n) for (int n____=(i=0,int(n));i<n____;++i)
#define FOR_C_N(i, a, b) for (int b____=(i=0,int(b);i<b____;++i)
#define DWN_C_N(i, b, a) for (int a____=(i=b-1,int(a));i>=a____;--i)
#define REP_1_C_N(i, n) for (int n____=(i=1,int(n));i<=n____;++i)
#define FOR_1_C_N(i, a, b) for (int b____=(i=1,int(b);i<=b____;++i)
#define DWN_1_C_N(i, b, a) for (int a____=(i=b,int(a));i>=a____;--i)

#define ECH(it, A) for (__typeof(A.begin()) it=A.begin(); it != A.end(); ++it)
#define REP_S(i, str) for (char*i=str;*i;++i)
#define REP_L(i, hd, nxt) for (int i=hd;i;i=nxt[i])
#define REP_G(i, u) REP_L(i,hd[u],suc)
#define REP_SS(x, s) for (int x=s;x;x=(x-1)&s)
#define DO(n) for ( int ____n ## __line__ = n; ____n ## __line__ -- ; )
#define REP_2(i, j, n, m) REP(i, n) REP(j, m)
#define REP_2_1(i, j, n, m) REP_1(i, n) REP_1(j, m)
#define REP_3(i, j, k, n, m, l) REP(i, n) REP(j, m) REP(k, l)
#define REP_3_1(i, j, k, n, m, l) REP_1(i, n) REP_1(j, m) REP_1(k, l)
#define REP_4(i, j, k, ii, n, m, l, nn) REP(i, n) REP(j, m) REP(k, l) REP(ii, nn)
#define REP_4_1(i, j, k, ii, n, m, l, nn) REP_1(i, n) REP_1(j, m) REP_1(k, l) REP_1(ii, nn)

#define ALL(A) A.begin(), A.end()
#define BSC(A, x) (lower_bound(ALL(A), x) - A.begin())
#define CTN(T, x) (T.find(x) != T.end())
#define SZ(A) int(A.size())
#define PB push_back
#define MP(A, B) make_pair(A, B)
#define fi first
#define se second
#define Rush for(int ____T=(scanf("%d",&____T),____T), ____cas=0;++____cas, ____T--;)

typedef long long LL;
typedef double DB;
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
#ifdef __GNUC__
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
#endif
} using namespace BO;



namespace NT{
template<class T> inline T lowbit(T x) {return x & -x;}

template <class T>inline T GCD(T A,T B){T C;while(B!=0)C=B,B=A%B,A=C;return A;}

template <class T>inline T LCM(T A,T B){return A*(B/GCD(A,B));}

template<class T>inline T Mod(T a,T b){a%=b;return a<0?a+b:a;}

template<class T>inline T MulMod(T a,T b,T c){if(c==1)return 0;if(c<=0)return -1;T ret=0,tmp;tmp=a=Mod(a,c);b=Mod(b,c);while(b){if(b&0x1)if((ret+=tmp)>=c)ret-=c;if((tmp<<=1)>=c)tmp-=c;b>>=1;}return ret;}
template<class T,class Tb> inline T PowMod(Tb a,T b,T c){if(c==1)return 0;if(c<=0)return -1;a=Mod(a,(Tb)c);Tb ret(1L%c);while(b){if(b&0x1)ret=ret*a%c;a=a*a%c;b>>=1;}return (T)ret;}
template<class T> inline T HPowMod(T a,T b,T c){if(c==1)return 0;if(c<=0)return -1;a=Mod(a,c);T ret(1L%c);while(b){if(b&0x1)ret=MulMod(ret,a,c);a=MulMod(a,a,c);b>>=1;}return ret;}
template<class T,class Tb> inline T Pow(T a, Tb b){T c(1); while (b){if (b&1) c *= a;a *= a, b >>= 1;}return c;}
template <class T>inline T EXT_GCD(T a,T b,T& x,T& y){T t,ret;if (!b){x=1,y=0;return a;}ret=EXT_GCD(b,a%b,x,y);t=x,x=y,y=t-a/b*y;return ret;}
template <class T>inline T Inv(T a,T n){if(n<=0)return -1;T d,x,y;d=EXT_GCD(a,n,x,y);if(d!=1)return -1;return Mod(x,n);}
template<class T, int MAXN, T MOD=-1>class Matrix {public:T m[MAXN][MAXN];Matrix(){}void init(T num[MAXN][MAXN]){for(int i = 0 ; i < MAXN ; i++){for(int j = 0 ; j < MAXN ; j++){m[i][j] = num[i][j];if (MOD!=-1)  m[i][j] %= MOD;}}}
friend Matrix operator*(const Matrix &m1 ,const Matrix &m2) {int i, j, k;Matrix ret;memset(ret.m, 0, sizeof(ret.m));for (i = 0; i < MAXN; i++) {for (j = 0; j < MAXN; j++)if ( m1.m[i][j] ){for(k = 0 ; k < MAXN ; k++){ret.m[i][k] += m1.m[i][j] * m2.m[j][k];if (MOD!=-1) ret.m[i][k] %= MOD;}}}return ret;}
friend Matrix operator+(const Matrix &m1 ,const Matrix &m2) {int i, j;Matrix ret;for (i = 0; i < MAXN; i++) {for (j = 0; j < MAXN; j++) {ret.m[i][j] = 0;ret.m[i][j] = m1.m[i][j]+m2.m[i][j];if (MOD!=-1)  ret.m[i][j] %= MOD;}}return ret;}
friend Matrix operator^(const Matrix &_M , LL nx){Matrix ret,M(_M);for(int i = 0 ; i < MAXN ; i++){for(int j = 0 ; j < MAXN ; j++){if(i == j)ret.m[i][j] = 1;else ret.m[i][j] = 0;}}while(nx){if(nx & 1)ret = ret * M;nx = nx >> 1;M = M * M;}return ret;}
};

const int PMAX = 1e3+7;VI Prime; bitset<PMAX> isnotPrime;

void sieve(){if (!Prime.empty()) return ;FOR(i, 2, PMAX){
    if (!isnotPrime[i]) Prime.PB(i);
    for (int j=0;j<SZ(Prime)&&i*Prime[j]<PMAX;++j){isnotPrime[i*Prime[j]]=1; if (!(i%Prime[j])) break;}}
}
inline bool isPrime(int n){return !isnotPrime[n];}
template<class T>T phi(T n){T ret=1,i;for (i=2;i*i<=n;i++)if (n%i==0){n/=i,ret*=i-1;while (n%i==0)n/=i,ret*=i;}if (n>1)ret*=n-1;return ret;}

inline void _INC(int &a, int b){a += b; a=Mod(a,mod);}
inline int _sum(int a, int b){a += b; a=Mod(a,mod); return a;}
inline void _DEC(int &a, int b){a -= b; a=Mod(a,mod);}
inline int _dff(int a, int b){a -= b; a=Mod(a,mod); return a;}
inline void _MUL(int &a, int b){a = (LL)a * b % mod;}
inline int _pdt(int a, int b){return (LL)a * b % mod;}
inline int _I(int b){
    int a = mod, x1 = 0, x2 = 1, q;
    while (true){q = a / b, a %= b;
    if (!a) return (x2 + mod) % mod;
    _DEC(x1, _pdt(q, x2));q = b / a, b %= a;if (!b) return (x1 + mod) % mod;_DEC(x2, _pdt(q, x1));} }
inline void _DIV(int &a, int b){_MUL(a, _I(b));}
inline int _qtt(int a, int b){return _pdt(a, _I(b));}
struct Int{
    int val;
    operator int() const{return val;}
    Int(int val = 0):val(val){ if (val>=0 && val<mod) return ; val %= mod; if (val < 0) val += mod; }
    inline Int& operator +=(const int& rhs){ _INC(val, rhs); return *this; }
    inline Int operator +(const int& rhs) const{ return _sum(val, rhs); }
    inline Int& operator -=(const int& rhs){_DEC(val, rhs);return *this;}
    inline Int operator -(const int& rhs) const{return _dff(val, rhs);}
    inline Int& operator *=(const int& rhs){_MUL(val, rhs);return *this;}
    inline Int operator *(const int& rhs) const{return _pdt(val, rhs);}
    inline Int& operator /=(const int& rhs){_DIV(val, rhs);return *this;}
    inline Int operator /(const int& rhs) const{return _qtt(val, rhs);}
};
} using namespace NT;




namespace Date{
int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
struct date{int year,month,day;};
inline int leap(int year){return (year%4==0&&year%100!=0)||year%400==0;}
inline int legal(date a){if (a.month<0||a.month>12) return 0;if (a.month==2)return a.day>0&&a.day<=28+leap(a.year);return a.day>0&&a.day<=days[a.month-1];}
inline int datecmp(date a,date b){if (a.year!=b.year)return a.year-b.year;if (a.month!=b.month)return a.month-b.month;return a.day-b.day;}
int weekday(date a){int tm=a.month>=3?(a.month-2):(a.month+10);int ty=a.month>=3?a.year:(a.year-1);return (ty+ty/4-ty/100+ty/400+(int)(2.6*tm-0.2)+a.day)%7;}
int date2int(date a){int ret=a.year*365+(a.year-1)/4-(a.year-1)/100+(a.year-1)/400,i;days[1]+=leap(a.year);for (i=0;i<a.month-1;ret+=days[i++]);days[1]=28;return ret+a.day;}
date int2date(int a){date ret;ret.year=a/146097*400;for (a%=146097;a>=365+leap(ret.year);a-=365+leap(ret.year),ret.year++);days[1]+=leap(ret.year);for (ret.month=1;a>=days[ret.month-1];a-=days[ret.month-1],ret.month++);days[1]=28;ret.day=a+1;return ret;}
}



namespace BIGNUM{

const int __base = 1e8;
const int P10[] = {1, 10, int(1e2), int(1e3), int(1e4), int(1e5), int(1e6), int(1e7), int(1e8), int(1e9)};
const int MAX_BUF_SIZE = 10009;
char __buf[MAX_BUF_SIZE];
inline char* RS(char *s){
    scanf("%s", s);
    return s;
}
class bignum{
          friend istream& operator>>(istream&, bignum&);
          friend ostream& operator<<(ostream&, const bignum&);
          friend bignum operator +(const bignum&, const bignum&);
          friend bignum operator -(const bignum&, const bignum&);
          friend bignum operator *(const bignum&, const bignum&);
          friend bignum operator /(const bignum&, const bignum&);
          friend bignum operator %(const bignum&, const bignum&);
          friend bignum operator +(const bignum&, const int&);
          friend bignum operator -(const bignum&, const int&);
          friend bignum operator *(const bignum&, const int&);
          friend bignum operator /(const bignum&, const int&);
          friend bignum operator %(const bignum&, const int&);
          friend bool operator ==(const bignum&, const bignum&);
          friend bool operator !=(const bignum&, const bignum&);
          friend bool operator <(const bignum&, const bignum&);
          friend bool operator >(const bignum&, const bignum&);
          friend bool operator <=(const bignum&, const bignum&);
          friend bool operator >=(const bignum&, const bignum&);
          friend bool operator ==(const bignum&, const int&);
          friend bool operator !=(const bignum&, const int&);
          friend bool operator <(const bignum&, const int&);
          friend bool operator >(const bignum&, const int&);
          friend bool operator <=(const bignum&, const int&);
          friend bool operator >=(const bignum&, const int&);
          friend int do_comp(const bignum&, const int&);
          friend int do_comp(const bignum&, const bignum&);
          friend void divide(const bignum&, const bignum&, bignum&, bignum&);
          friend bignum pow(bignum, int);
          friend bignum pow(int, int);
    public:
        inline bignum(){};
        inline bignum(int s){
            while (s) data.PB(s%__base), s/=__base;
            if (data.empty()) data.PB(0);
        }
        inline bignum(LL s){
            while (s) data.PB(int(s%__base)), s/=__base;
            if (data.empty()) data.PB(0);
        }
        inline bignum(string s){
            int t, i; CLR(data);
            for (i=int(s.size())-8;i>0;i-=8){
                istringstream(s.substr(i, 8)) >> t;
                data.PB(t);
            }
            istringstream(s.substr(0, i+8)) >> t;
            data.PB(t);
        }
        void input(){
            CLR(data); RS(__buf); int t = 0, c = 0;
            DWN(i, strlen(__buf), 0){
                t += P10[c] * (int(__buf[i]) - '0'), ++c;
                if (c == 8) data.PB(t), c = t = 0;
            }
            if (c) data.PB(t);
        }
        void operator =(const int);
        void operator =(const string);
        void operator =(const bignum);
        bignum& operator +=(const bignum&);
        bignum& operator -=(const bignum&);
        bignum& operator *=(const bignum&);
        bignum& operator /=(const bignum&);
        bignum& operator %=(const bignum&);
        bignum& operator +=(const int&);
        bignum& operator -=(const int&);
        bignum& operator *=(const int&);
        bignum& operator /=(const int&);
        bignum& operator %=(const int&);
        bool undefined();
        int do_try(const int&);
        int do_try(const bignum&);
        void do_trim();
        deque<int> data;
    int size(){
        deque<int>::iterator it; int res = 0;
        for (it=data.begin(); it!=data.end();it++)
            res += 8;
        it--;
        if (*it >= 10000) {
            if ( (*it) >= 1000000) {if (*it >=10000000) ; else res--;}
            else {if ((*it) >= 100000) res-=2; else res-=3;}
        }
        else
            if ( (*it) >= 100) {if (*it >=1000) res-=4; else res-=5;}
            else {if ((*it) >= 10) res-=6; else res-=7;}
        return res;
    }

    void do_reserve(int a){
        if (a <= 0) return;
        deque<int>::iterator it;
        for (it=data.begin(); it!=data.end() && a>0; it++) a-=8;
        if (it == data.end() && a>=0) return;
        a+=8, it--; int f = 1;
        for (int i=0;i<a;i++) f *= 10; (*it) %= f;
        data.erase(++it, data.end());
        do_trim();
    }
};

inline void bignum::operator =(const bignum a){
    data.clear();
    for (deque<int>::const_iterator i=a.data.begin();i!=a.data.end();i++){
        data.PB(*i);
    }
}
inline void bignum::operator =(const string a){
    (*this) = bignum(a);
}
inline void bignum::operator =(const int a){
    (*this) = bignum(a);
}

inline istream& operator>>(istream& input, bignum& a){
    string s; int t, i; input >> s; a.data.clear();
    for (i=int(s.size())-8;i>0;i-=8){
        istringstream(s.substr(i, 8)) >> t;
        a.data.PB(t);
    }
    istringstream(s.substr(0, i+8)) >> t;
    a.data.PB(t);
    return input;
}

inline ostream& operator<<(ostream& output, const bignum& a){
    deque<int>::const_reverse_iterator i=a.data.rbegin();
    output << *i;
    for (i++;i!=a.data.rend();i++){
        if (*i >= 10000) {
            if (*i >= 1000000) {if (*i>=10000000) cout << *i; else cout << 0 << *i;}
            else {if (*i>=100000) cout << "00" << *i; else cout << "000" << *i;}
        }
        else {
            if (*i >= 100) {if (*i>=1000)  cout << "0000" << *i; else cout << "00000" << *i;}
            else { if (*i>=10) cout << "000000" << *i; else cout << "0000000" << *i;}
        }
    }
    return output;
}

inline bool bignum::undefined(){
    return data.empty();
}

inline int do_comp(const bignum& a, const bignum& b){
    if (a.data.size()<b.data.size()) return -1; if (a.data.size()>b.data.size()) return 1;
    deque<int>::const_reverse_iterator i; deque<int>::const_reverse_iterator j;
    for (i=a.data.rbegin(),j=b.data.rbegin(); j!=b.data.rend(); i++,j++){
        if (*i<*j) return -1;              

        if (*i>*j) return 1;
    }
    return 0;
}
inline int do_comp(const bignum& a, const int& b){
    return do_comp(a, bignum(b));
}

inline bool operator ==(const bignum& a, const bignum& b){
    return do_comp(a, b) == 0;
}
inline bool operator !=(const bignum& a, const bignum& b){
    return do_comp(a, b) != 0;
}
inline bool operator <(const bignum& a, const bignum& b){
    return do_comp(a, b) == -1;
}
inline bool operator >(const bignum& a, const bignum& b){
    return do_comp(a, b) == 1;
}
inline bool operator <=(const bignum& a, const bignum& b){
    return do_comp(a, b) != 1;
}
inline bool operator >=(const bignum& a, const bignum& b){
    return do_comp(a, b) != -1;
}

inline bool operator ==(const bignum& a, const int& b){
    return do_comp(a, b) == 0;
}
inline bool operator !=(const bignum& a, const int& b){
    return do_comp(a, b) != 0;
}
inline bool operator <(const bignum& a, const int& b){
    return do_comp(a, b) == -1;
}
inline bool operator >(const bignum& a, const int& b){
    return do_comp(a, b) == 1;
}
inline bool operator <=(const bignum& a, const int& b){
    return do_comp(a, b) != 1;
}
inline bool operator >=(const bignum& a, const int& b){
    return do_comp(a, b) != -1;
}

inline void bignum::do_trim(){
    while (data.size()>1&&data.back()==0) data.pop_back();
}

inline bignum& bignum::operator +=(const bignum& a){
    deque<int>::iterator i; deque<int>::const_iterator j; int t = 0;
    for (i=data.begin(),j=a.data.begin(); i!=data.end()&&j!=a.data.end(); i++,j++){
        *i+=*j+t; t=*i/__base; *i%=__base;
    }
    while (i!=data.end()) {*i+=t; t=*i/__base; *i%=__base; i++;}
    while (j!=a.data.end()) {data.PB(t+*j); t=data.back()/__base; data.back()%=__base; j++;}
    if (t!=0) data.PB(t);
    return *this;
}

inline bignum& bignum::operator -=(const bignum& a){
    deque<int>::iterator i; deque<int>::const_iterator j; int t = 0;
    for (i=data.begin(),j=a.data.begin(); j!=a.data.end(); i++,j++){
        *i -= t+*j; if (*i>=0) t=0; else *i+=__base, t=1;
    }
    while (i!=data.end()) {*i-=t; if (*i>=0) t=0;else *i+=__base, t=1; i++;}
    (*this).do_trim();
    return *this;
}

inline bignum& bignum::operator +=(const int& a){
    return (*this)+=bignum(a);
}

inline bignum& bignum::operator -=(const int& a){
    return (*this)-=bignum(a);
}

inline bignum operator +(const bignum& a, const bignum& b){
    deque<int>::const_iterator i, j; bignum c; int t = 0;
    for (i=a.data.begin(),j=b.data.begin(); i!=a.data.end()&&j!=b.data.end(); i++,j++){
        c.data.PB(t+*i+*j);
        t=c.data.back()/__base; c.data.back()%=__base;
    }
    while (i!=a.data.end()) {c.data.PB(t+*i); t=c.data.back()/__base; c.data.back()%=__base; i++;}
    while (j!=b.data.end()) {c.data.PB(t+*j); t=c.data.back()/__base; c.data.back()%=__base; j++;}
    if (t!=0) c.data.PB(t);
    return c;
}

inline bignum operator -(const bignum& a, const bignum& b){
    deque<int>::const_iterator i, j; bignum c; int t = 0;
    for (i=a.data.begin(),j=b.data.begin(); j!=b.data.end(); i++,j++){
        t = *i - t;
        if (t>=*j) c.data.PB(t-*j), t=0;
        else c.data.PB(t+__base-*j), t=1;
    }
    while (i!=a.data.end()) {t=*i-t; if (t>=0) c.data.PB(t), t=0;else c.data.PB(t+__base), t=1; i++;}
    c.do_trim();
    return c;
}

inline bignum operator *(const bignum& a, const bignum& b){
    deque<int>::const_iterator i, j; deque<int>::iterator k, kk; bignum c; LL t = 0;
    for (int i=0;i<(int)(a.data.size()+b.data.size());i++) c.data.PB(0);
    for (i=a.data.begin(),k=c.data.begin(); i!=a.data.end(); i++,k++){
        for (j=b.data.begin(),kk=k; j!=b.data.end(); j++,kk++){
            t+=(LL)(*i)*(*j)+(*kk);
            *kk=int(t%__base); t/=__base;
        }
        *kk+=t; t=0;
    }
    c.do_trim();
    return c;
}

inline int bignum::do_try(const bignum& a){
    int l = 1, r = 99999999, m, t;
    while (l+2<r){
        m = (l + r) / 2;
        t = do_comp(*this, a*bignum(m));
        if (t==0) return m;
        if (t<0) r = m - 1;
        else l = m;
    }
    while (do_comp(*this, a*bignum(r))<0) r--;
    return r;
}
inline void divide(const bignum& a, const bignum& b, bignum& d, bignum& r){
    deque<int>::const_reverse_iterator i = a.data.rbegin(); int t;
    d = bignum(0); r = bignum(0);
    do {
        while (r<b&&i!=a.data.rend()){d.data.push_front(0);r.data.push_front(*i);r.do_trim();i++;}
        if (r>=b){
            t = r.do_try(b); d.data.front() = t;
            r-=(b*bignum(t));
        }
    } while (i!=a.data.rend());
    d.do_trim();
}
inline bignum operator /(const bignum& a, const bignum& b){
    bignum d, r;
    divide(a, b, d, r);
    return d;
}
inline bignum operator %(const bignum& a, const bignum& b){
    bignum d, r;
    divide(a, b, d, r);
    return r;
}
inline bignum operator +(const bignum& a, const int& b){
    return a+bignum(b);
}
inline bignum operator -(const bignum& a, const int& b){
    return a-bignum(b);
}
inline bignum operator *(const bignum& a, const int& b){
    return a*bignum(b);
}
inline bignum operator /(const bignum& a, const int& b){
    return a/bignum(b);
}
inline bignum operator %(const bignum& a, const int& b){
    return a%bignum(b);
}
inline bignum& bignum::operator *=(const bignum& a){
    (*this) = (*this) * a;
    return *this;
}
inline bignum& bignum::operator /=(const bignum& a){
    (*this) = (*this) / a;
    return *this;
}
inline bignum& bignum::operator %=(const bignum& a){
    (*this) = (*this) % a;
    return *this;
}
inline bignum& bignum::operator *=(const int& a){
    return (*this)*=bignum(a);
}
inline bignum& bignum::operator /=(const int& a){
    return (*this)/=bignum(a);
}
inline bignum& bignum::operator %=(const int& a){
    return (*this)%=bignum(a);
}
inline bignum pow(bignum a,int b){
    bignum c(1);
    while (b!=0) {
        if (b&1) c *= a;
        a = a * a; b >>= 1;
    }
    return c;
}
inline bignum pow(int a, int b){
    return pow(bignum(a), b);
}

}




namespace IO{
template<class T> inline T RD(T &x){
    char c; for (c = getchar(); c < '-'; c = getchar());
    if (c == '-'){x = '0' - getchar(); for (c = getchar(); '0' <= c && c <= '9'; c = getchar()) x = x * 10 + '0' - c;}
    else {x = c - '0'; for (c = getchar(); '0' <= c && c <= '9'; c = getchar()) x = x * 10 + c - '0';}
    return x;
}
inline LL RD(){LL x; return RD(x);}
}using namespace IO;




const int N = 1e6+7;
int lk[N];
int cnt[N];
bool can[N];
int a[N];
vector<int> ans[N];
int mmm;
void solve(int x, int p){
    if ( lk[x]==p-1 ){
        lk[x] = p;
        cnt[x]++;
    }else{
        lk[x] = p;
        cnt[x] = 0;
        can[x] = 0;
    }
    if ( a[p]==x ) can[x] = 1;
    if ( cnt[x]>=mmm ){
        if ( can[x] ) {
            ans[ cnt[x] ].PB( p-cnt[x] );
            mmm = max(mmm, cnt[x]);
        }
    }
}
vector<int> fact[N];
void se(int n){
    if ( SZ(fact[n]) ) return ;
    int i;
    for (i=1; i*i<n; i++){
        if ( n%i ) continue;
        int x;
        x=i;
        fact[n].PB(x);

        x=n/i;
        fact[n].PB(x);
    }
    if ( i*i==n ){
        int x = i;
        fact[n].PB(x);
    }
}
void work(int n, int p){
    se(n);
    int i;
    for (i=SZ(fact[n])-1; i>=0; i--){
        solve( fact[n][i], p);
    }
}
int main(){
    

    

    

    

    memset(lk, -1, sizeof(lk) );
    int n;
    cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>a[i];
    }
    {
        for (int i=1; i<=n; i++){
            work(a[i], i);
        }
        
    }
    int i;
    for (i=n; i>=0; i--){
        if ( SZ(ans[i]) ) break;
    }
    sort(ans[i].begin(), ans[i].end() );
    ans[i].erase( unique(ans[i].begin(), ans[i].end() ) , ans[i].end() );
    cout<<SZ(ans[i])<<" "<<i<<endl;
    for (int j=0; j<SZ(ans[i]); j++) cout<<ans[i][j]<<" ";

    return 0;
}



