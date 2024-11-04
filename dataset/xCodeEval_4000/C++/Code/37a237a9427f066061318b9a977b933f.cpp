#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>
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

#define REP(i, n) for (LL i=0;i<LL(n);++i)
#define FOR(i, a, b) for (LL i=LL(a);i<LL(b);++i)
#define DWN(i, b, a) for (LL i=LL(b-1);i>=LL(a);--i)
#define REP_1(i, n) for (LL i=1;i<=LL(n);++i)
#define FOR_1(i, a, b) for (LL i=LL(a);i<=LL(b);++i)
#define DWN_1(i, b, a) for (LL i=LL(b);i>=LL(a);--i)
#define REP_C(i, n) for (LL n____=LL(n),i=0;i<n____;++i)
#define FOR_C(i, a, b) for (LL b____=LL(b),i=a;i<b____;++i)
#define DWN_C(i, b, a) for (LL a____=LL(a),i=b-1;i>=a____;--i)
#define REP_N(i, n) for (i=0;i<LL(n);++i)
#define FOR_N(i, a, b) for (i=LL(a);i<LL(b);++i)
#define DWN_N(i, b, a) for (i=LL(b-1);i>=LL(a);--i)
#define REP_1_C(i, n) for (LL n____=LL(n),i=1;i<=n____;++i)
#define FOR_1_C(i, a, b) for (LL b____=LL(b),i=a;i<=b____;++i)
#define DWN_1_C(i, b, a) for (LL a____=LL(a),i=b;i>=a____;--i)
#define REP_1_N(i, n) for (i=1;i<=LL(n);++i)
#define FOR_1_N(i, a, b) for (i=LL(a);i<=LL(b);++i)
#define DWN_1_N(i, b, a) for (i=LL(b);i>=LL(a);--i)
#define REP_C_N(i, n) for (n____=LL(n),i=0;i<n____;++i)
#define FOR_C_N(i, a, b) for (b____=LL(b),i=a;i<b____;++i)
#define DWN_C_N(i, b, a) for (a____=LL(a),i=b-1;i>=a____;--i)
#define REP_1_C_N(i, n) for (n____=LL(n),i=1;i<=n____;++i)
#define FOR_1_C_N(i, a, b) for (b____=LL(b),i=a;i<=b____;++i)
#define DWN_1_C_N(i, b, a) for (a____=LL(a),i=b;i>=a____;--i)

#define DO(n) while(n--)
#define DO_C(n) LL n____ = n; while(n____--)
#define TO(i, a, b) LL s_=a<b?1:-1,b_=b+s_;for(LL i=a;i!=b_;i+=s_)
#define TO_1(i, a, b) LL s_=a<b?1:-1,b_=b;for(LL i=a;i!=b_;i+=s_)
#define SQZ(i, j, a, b) for (LL i=LL(a),j=LL(b)-1;i<j;++i,--j)
#define SQZ_1(i, j, a, b) for (LL i=LL(a),j=LL(b);i<=j;++i,--j)
#define REP_2(i, j, n, m) REP(i, n) REP(j, m)
#define REP_2_1(i, j, n, m) REP_1(i, n) REP_1(j, m)

#define ALL(A) A.begin(), A.end()
#define LLA(A) A.rbegin(), A.rend()
#define CPY(A, B) memcpy(A, B, sizeof(A))
#define INS(A, P, B) A.insert(A.begin() + P, B)
#define ERS(A, P) A.erase(A.begin() + P)
#define BSC(A, X) find(ALL(A), X) 

#define CTN(T, x) (T.find(x) != T.end())
#define SZ(A) LL(A.size())
#define PB push_back
#define MP(A, B) make_pair(A, B)

#define Rush LL T____; RD(T____); DO(T____)
#pragma comment(linker, "/STACK:36777216")
#pragma GCC optimize ("O2")
#define Ruby system("ruby main.rb")
#define Haskell system("runghc main.hs")
#define Pascal system("fpc main.pas")

typedef long long LL;
typedef double DB;
typedef unsigned ULL;


typedef vector<LL> VI;
typedef vector<char> VC;
typedef vector<string> VS;
typedef vector<LL> VL;
typedef vector<DB> VD;
typedef set<LL> SI;
typedef set<string> SS;
typedef set<LL> SL;
typedef set<DB> SD;
typedef map<LL, LL> MII;
typedef map<string, LL> MSI;
typedef map<LL, LL> MLI;
typedef map<DB, LL> MDI;
typedef map<LL, bool> MIB;
typedef map<string, bool> MSB;
typedef map<LL, bool> MLB;
typedef map<DB, bool> MDB;
typedef pair<LL, LL> PII;
typedef pair<LL, bool> PIB;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef vector<VII> VVII;
typedef set<PII> SII;
typedef map<PII, LL> MPIII;
typedef map<PII, bool> MPIIB;






template<class T> inline void RD(T &);
template<class T> inline void OT(const T &);

inline LL RD(){ LL x; RD(x); return x;}
template<class T> inline T& _RD(T &x){ RD(x); return x;}
inline void RC(char &c){scanf(" %c", &c);}
inline void RS(char *s){scanf("%s", s);}

template<class T0, class T1> inline void RD(T0 &x0, T1 &x1){RD(x0), RD(x1);}
template<class T0, class T1, class T2> inline void RD(T0 &x0, T1 &x1, T2 &x2){RD(x0), RD(x1), RD(x2);}
template<class T0, class T1, class T2, class T3> inline void RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3){RD(x0), RD(x1), RD(x2), RD(x3);}
template<class T0, class T1, class T2, class T3, class T4> inline void RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4){RD(x0), RD(x1), RD(x2), RD(x3), RD(x4);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5){RD(x0), RD(x1), RD(x2), RD(x3), RD(x4), RD(x5);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5, T6 &x6){RD(x0), RD(x1), RD(x2), RD(x3), RD(x4), RD(x5), RD(x6);}
template<class T0, class T1> inline void OT(T0 &x0, T1 &x1){OT(x0), OT(x1);}
template<class T0, class T1, class T2> inline void OT(T0 &x0, T1 &x1, T2 &x2){OT(x0), OT(x1), OT(x2);}
template<class T0, class T1, class T2, class T3> inline void OT(T0 &x0, T1 &x1, T2 &x2, T3 &x3){OT(x0), OT(x1), OT(x2), OT(x3);}
template<class T0, class T1, class T2, class T3, class T4> inline void OT(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4){OT(x0), OT(x1), OT(x2), OT(x3), OT(x4);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void OT(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5){OT(x0), OT(x1), OT(x2), OT(x3), OT(x4), OT(x5);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void OT(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5, T6 &x6){OT(x0), OT(x1), OT(x2), OT(x3), OT(x4), OT(x5), OT(x6);}

template<class T> inline void RST(T &A){memset(A, 0, sizeof(A));}
template<class T0, class T1> inline void RST(T0 &A0, T1 &A1){RST(A0), RST(A1);}
template<class T0, class T1, class T2> inline void RST(T0 &A0, T1 &A1, T2 &A2){RST(A0), RST(A1), RST(A2);}
template<class T0, class T1, class T2, class T3> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3){RST(A0), RST(A1), RST(A2), RST(A3);}
template<class T0, class T1, class T2, class T3, class T4> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4){RST(A0), RST(A1), RST(A2), RST(A3), RST(A4);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5){RST(A0), RST(A1), RST(A2), RST(A3), RST(A4), RST(A5);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6){RST(A0), RST(A1), RST(A2), RST(A3), RST(A4), RST(A5), RST(A6);}

template<class T> inline void CLR(T &A){A.clear();}
template<class T0, class T1> inline void CLR(T0 &A0, T1 &A1){CLR(A0), CLR(A1);}
template<class T0, class T1, class T2> inline void CLR(T0 &A0, T1 &A1, T2 &A2){CLR(A0), CLR(A1), CLR(A2);}
template<class T0, class T1, class T2, class T3> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3){CLR(A0), CLR(A1), CLR(A2), CLR(A3);}
template<class T0, class T1, class T2, class T3, class T4> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4){CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5){CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4), CLR(A5);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6){CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4), CLR(A5), CLR(A6);}
template<class T> inline void CLR(T &A, LL n){REP(i, n) CLR(A[i]);}
template<class T> inline void FLC(T &A, LL x){memset(A, x, sizeof(A));}
template<class T0, class T1> inline void FLC(T0 &A0, T1 &A1, LL x){FLC(A0, x), FLC(A1, x);}
template<class T0, class T1, class T2> inline void FLC(T0 &A0, T1 &A1, T2 &A2){FLC(A0), FLC(A1), FLC(A2);}
template<class T0, class T1, class T2, class T3> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3){FLC(A0), FLC(A1), FLC(A2), FLC(A3);}
template<class T0, class T1, class T2, class T3, class T4> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4){FLC(A0), FLC(A1), FLC(A2), FLC(A3), FLC(A4);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5){FLC(A0), FLC(A1), FLC(A2), FLC(A3), FLC(A4), FLC(A5);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6){FLC(A0), FLC(A1), FLC(A2), FLC(A3), FLC(A4), FLC(A5), FLC(A6);}

template<class T> inline void SRT(T &A){sort(ALL(A));}
template<class T, class C> inline void SRT(T &A, C B){sort(ALL(A), B);}




const LL MOD = 1000000007;
const LL INF = 0x7fffffff;
const DB EPS = 1e-3;
const DB OO = 1e15;




template<class T> inline void checkMin(T &a,const T b){if (b<a) a=b;}
template<class T> inline void checkMax(T &a,const T b){if (b>a) a=b;}
template <class T, class C> inline void checkMin(T& a, const T b, C c){if (c(b,a)) a = b;}
template <class T, class C> inline void checkMax(T& a, const T b, C c){if (c(a,b)) a = b;}
template<class T> inline T min(T a, T b, T c){return min(min(a, b), c);}
template<class T> inline T max(T a, T b, T c){return max(max(a, b), c);}
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline T cub(T a){return a*a*a;}
LL Ceil(LL x, LL y){return (x - 1) / y + 1;}




inline bool _1(LL x, LL i){return x & 1<<i;}
inline LL _1(LL i){return 1<<i;}
inline LL _U(LL i){return _1(i) - 1;};

inline LL count_bits(LL x){
    x = (x & 0x55555555) + ((x & 0xaaaaaaaa) >> 1);
    x = (x & 0x33333333) + ((x & 0xcccccccc) >> 2);
    x = (x & 0x0f0f0f0f) + ((x & 0xf0f0f0f0) >> 4);
    x = (x & 0x00ff00ff) + ((x & 0xff00ff00) >> 8);
    x = (x & 0x0000ffff) + ((x & 0xffff0000) >> 16);
    return x;
}

template<class T> inline T low_bit(T x) {
    return x & -x;
}

template<class T> inline T high_bit(T x) {
    T p = low_bit(x);
    while (p != x) x -= p, p = low_bit(x);
    return p;
}




inline void INC(LL &a, LL b){a += b; if (a >= MOD) a -= MOD;}
inline LL sum(LL a, LL b){a += b; if (a >= MOD) a -= MOD; return a;}
inline void DEC(LL &a, LL b){a -= b; if (a < 0) a += MOD;}
inline LL dff(LL a, LL b){a -= b; if (a < 0) a  += MOD; return a;}
inline void MUL(LL &a, LL b){a = LL((LL)a * b % MOD);}
inline LL pdt(LL a, LL b){return LL((LL)a * b % MOD);}





template<class T> inline void RD(T &x){
    cin >> x;
    

    

    


}

LL ____Case;
template<class T> inline void OT(const T &x){
    

    prLLf("%d\n", x);
    

    

}


#define For_each(it, A) for (SII::iterator it = A.begin(); it != A.end(); ++it)



int A[1000] ;
bool    used[1000] ;
int N , K , M ;

double  fmax( double x , double y ) { return x - EPS >= y ? x : y ; }
double  fmin( double x , double y ) { return x + EPS <= y ? x : y ; }

int     main()
{
    cin >> N >> K ;
    M = N / K ;
    
    for ( int i = 1 ; i <= N ; i ++ ) cin >> A[i] ;
    for ( int i = 1 ; i <= N ; i ++ ) used[i] = false ;
    
    int Q ; cin >> Q ;
    double Max = 0.000 , Min = 101.000 ;
    for ( int i = 1 ; i <= Q ; i ++ )
    {
        double sA = 0.000 ;
        for ( int j = 1 ; j <= M ; j ++ )
        {
            int x ; cin >> x ;
            sA += A[x] ;
            used[x] = true ;
        }
        sA /= M ;
        Max = fmax( Max , sA );
        Min = fmin( Min , sA ) ;
    }
    
    vector <double> St ; St.clear() ;
    for ( int i = 1 ; i <= N ; i ++ ) if ( !used[i] ) St.push_back( A[i] ) ;
    sort( St.begin() , St.end() ) ;
    
    double sA = 0.00 ;
    if ( St.size() >= M && N-St.size() < K*M )
    {
        sA = 0.000 ;
        for ( int i = 0 ; i < M ; i ++ ) sA += St[i] ;
        sA /= M ;
        Max = fmax( Max , sA );
        Min = fmin( Min , sA ) ;
        sA = 0.000 ;
        for ( int i = St.size() - 1 ; i >= (int)St.size() - M ; i -- ) sA += St[i] ;
        sA /= M ;
        Max = fmax( Max , sA );
        Min = fmin( Min , sA ) ;
    }
    
    cout.precision(10) ;
    cout << fixed << Min << " " << Max << "\n" ;
}
