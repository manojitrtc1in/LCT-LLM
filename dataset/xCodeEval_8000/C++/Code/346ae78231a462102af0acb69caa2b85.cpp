#define LOCAL



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
#define REP_C_N(i, n) for (n____=int(n),i=0;i<n____;++i)
#define FOR_C_N(i, a, b) for (b____=int(b),i=a;i<b____;++i)
#define DWN_C_N(i, b, a) for (a____=int(a),i=b-1;i>=a____;--i)
#define REP_1_C_N(i, n) for (n____=int(n),i=1;i<=n____;++i)
#define FOR_1_C_N(i, a, b) for (b____=int(b),i=a;i<=b____;++i)
#define DWN_1_C_N(i, b, a) for (a____=int(a),i=b;i>=a____;--i)

#define ECH(it, A) for (typeof(A.begin()) it=A.begin(); it != A.end(); ++it)
#define DO(n) while(n--)
#define DO_C(n) int n____ = n; while(n____--)
#define TO(i, a, b) int s_=a<b?1:-1,b_=b+s_;for(int i=a;i!=b_;i+=s_)
#define TO_1(i, a, b) int s_=a<b?1:-1,b_=b;for(int i=a;i!=b_;i+=s_)
#define SQZ(i, j, a, b) for (int i=int(a),j=int(b)-1;i<j;++i,--j)
#define SQZ_1(i, j, a, b) for (int i=int(a),j=int(b);i<=j;++i,--j)
#define REP_2(i, j, n, m) REP(i, n) REP(j, m)
#define REP_2_1(i, j, n, m) REP_1(i, n) REP_1(j, m)

#define ALL(A) A.begin(), A.end()
#define LLA(A) A.rbegin(), A.rend()
#define CPY(A, B) memcpy(A, B, sizeof(A))
#define INS(A, P, B) A.insert(A.begin() + P, B)
#define ERS(A, P) A.erase(A.begin() + P)
#define BSC(A, X) fP(ALL(A), X) 

#define CTN(T, x) (T.fP(x) != T.end())
#define SZ(A) int(A.size())
#define PB push_back
#define MP(A, B) make_pair(A, B)

#define Rush int T____; RD(T____); DO(T____)
#pragma comment(linker, "/STACK:36777216")


#define Ruby system("ruby main.rb")
#define Haskell system("runghc main.hs")
#define Pascal system("fpc main.pas")

typedef long long LL;
typedef double DB;
typedef unsigned UINT;
typedef unsigned long long ULL;

typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<string> VS;
typedef vector<LL> VL;
typedef vector<DB> VD;
typedef set<int> SI;
typedef set<string> SS;
typedef set<LL> SL;
typedef set<DB> SD;
typedef map<int, int> MII;
typedef map<string, int> MSI;
typedef map<LL, int> MLI;
typedef map<DB, int> MDI;
typedef map<int, bool> MIB;
typedef map<string, bool> MSB;
typedef map<LL, bool> MLB;
typedef map<DB, bool> MDB;
typedef pair<int, int> PII;
typedef pair<int, bool> PIB;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef vector<VII> VVII;
typedef set<PII> SII;
typedef map<PII, int> MPIII;
typedef map<PII, bool> MPIIB;





template<class T> inline void RD(T &);
template<class T> inline void OT(const T &);

inline int RD(){ int x; RD(x); return x;}
template<class T> inline T& _RD(T &x){ RD(x); return x;}
inline void RC(char &c){scanf(" %c", &c);}
inline char RC(){ char x; RC(x); return x;}
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


template<class T> inline void CLR(priority_queue<T, vector<T>, less<T> > &Q){
    while (!Q.empty()) Q.pop();
}

template<class T> inline void CLR(priority_queue<T, vector<T>, greater<T> > &Q){
    while (!Q.empty()) Q.pop();
}

template<class T> inline void CLR(T &A){A.clear();}
template<class T0, class T1> inline void CLR(T0 &A0, T1 &A1){CLR(A0), CLR(A1);}
template<class T0, class T1, class T2> inline void CLR(T0 &A0, T1 &A1, T2 &A2){CLR(A0), CLR(A1), CLR(A2);}
template<class T0, class T1, class T2, class T3> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3){CLR(A0), CLR(A1), CLR(A2), CLR(A3);}
template<class T0, class T1, class T2, class T3, class T4> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4){CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5){CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4), CLR(A5);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6){CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4), CLR(A5), CLR(A6);}
template<class T> inline void CLR(T &A, int n){REP(i, n) CLR(A[i]);}
template<class T> inline void FLC(T &A, int x){memset(A, x, sizeof(A));}
template<class T0, class T1> inline void FLC(T0 &A0, T1 &A1, int x){FLC(A0, x), FLC(A1, x);}
template<class T0, class T1, class T2> inline void FLC(T0 &A0, T1 &A1, T2 &A2){FLC(A0), FLC(A1), FLC(A2);}
template<class T0, class T1, class T2, class T3> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3){FLC(A0), FLC(A1), FLC(A2), FLC(A3);}
template<class T0, class T1, class T2, class T3, class T4> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4){FLC(A0), FLC(A1), FLC(A2), FLC(A3), FLC(A4);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5){FLC(A0), FLC(A1), FLC(A2), FLC(A3), FLC(A4), FLC(A5);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6){FLC(A0), FLC(A1), FLC(A2), FLC(A3), FLC(A4), FLC(A5), FLC(A6);}

template<class T> inline void SRT(T &A){sort(ALL(A));}
template<class T, class C> inline void SRT(T &A, C B){sort(ALL(A), B);}



const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const DB EPS = 1e-9;
const DB OO = 1e15;
const DB PI = 3.14159265358979323846264; 





template<class T> inline void checkMin(T &a,const T b){if (b<a) a=b;}
template<class T> inline void checkMax(T &a,const T b){if (b>a) a=b;}
template <class T, class C> inline void checkMin(T& a, const T b, C c){if (c(b,a)) a = b;}
template <class T, class C> inline void checkMax(T& a, const T b, C c){if (c(a,b)) a = b;}
template<class T> inline T min(T a, T b, T c){return min(min(a, b), c);}
template<class T> inline T max(T a, T b, T c){return max(max(a, b), c);}
template<class T> inline T min(T a, T b, T c, T d){return min(min(a, b), min(c, d));}
template<class T> inline T max(T a, T b, T c, T d){return max(min(a, b), max(c, d));}
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline T cub(T a){return a*a*a;}
int Ceil(int x, int y){return (x - 1) / y + 1;}



inline bool _1(int x, int i){return x & 1<<i;}
inline bool _1(LL x, int i){return x & 1LL<<i;}
inline LL _1(int i){return 1LL<<i;}


inline LL _U(int i){return _1(i) - 1;};




template<class T> inline T low_bit(T x) {
    return x & -x;
}

template<class T> inline T high_bit(T x) {
    T p = low_bit(x);
    while (p != x) x -= p, p = low_bit(x);
    return p;
}

inline int count_bits(int x){
    x = (x & 0x55555555) + ((x & 0xaaaaaaaa) >> 1);
    x = (x & 0x33333333) + ((x & 0xcccccccc) >> 2);
    x = (x & 0x0f0f0f0f) + ((x & 0xf0f0f0f0) >> 4);
    x = (x & 0x00ff00ff) + ((x & 0xff00ff00) >> 8);
    x = (x & 0x0000ffff) + ((x & 0xffff0000) >> 16);
    return x;
}

inline int count_bits(LL x){
    x = (x & 0x5555555555555555LL) + ((x & 0xaaaaaaaaaaaaaaaaLL) >> 1);
    x = (x & 0x3333333333333333LL) + ((x & 0xccccccccccccccccLL) >> 2);
    x = (x & 0x0f0f0f0f0f0f0f0fLL) + ((x & 0xf0f0f0f0f0f0f0f0LL) >> 4);
    x = (x & 0x00ff00ff00ff00ffLL) + ((x & 0xff00ff00ff00ff00LL) >> 8);
    x = (x & 0x0000ffff0000ffffLL) + ((x & 0xffff0000ffff0000LL) >> 16);
    x = (x & 0x00000000ffffffffLL) + ((x & 0xffffffff00000000LL) >> 32);
    return x;
}

int reverse_bits(int x){
    x = ((x >> 1) & 0x55555555) | ((x << 1) & 0xaaaaaaaa);
    x = ((x >> 2) & 0x33333333) | ((x << 2) & 0xcccccccc);
    x = ((x >> 4) & 0x0f0f0f0f) | ((x << 4) & 0xf0f0f0f0);
    x = ((x >> 8) & 0x00ff00ff) | ((x << 8) & 0xff00ff00);
    x = ((x >>16) & 0x0000ffff) | ((x <<16) & 0xffff0000);
    return x;
}

LL reverse_bits(LL x){
    x = ((x >> 1) & 0x5555555555555555LL) | ((x << 1) & 0xaaaaaaaaaaaaaaaaLL);
    x = ((x >> 2) & 0x3333333333333333LL) | ((x << 2) & 0xccccccccccccccccLL);
    x = ((x >> 4) & 0x0f0f0f0f0f0f0f0fLL) | ((x << 4) & 0xf0f0f0f0f0f0f0f0LL);
    x = ((x >> 8) & 0x00ff00ff00ff00ffLL) | ((x << 8) & 0xff00ff00ff00ff00LL);
    x = ((x >>16) & 0x0000ffff0000ffffLL) | ((x <<16) & 0xffff0000ffff0000LL);
    x = ((x >>32) & 0x00000000ffffffffLL) | ((x <<32) & 0xffffffff00000000LL);
    return x;
}




inline void INC(int &a, int b){a += b; if (a >= MOD) a -= MOD;}
inline int sum(int a, int b){a += b; if (a >= MOD) a -= MOD; return a;}
inline void DEC(int &a, int b){a -= b; if (a < 0) a += MOD;}
inline int dff(int a, int b){a -= b; if (a < 0) a  += MOD; return a;}
inline void MUL(int &a, int b){a = (LL)a * b % MOD;}
inline int pdt(int a, int b){return (LL)a * b % MOD;}

inline int pow(int a, int b){
    int c = 1;
    while (b) {
        if (b&1) MUL(c, a);
        MUL(a, a), b >>= 1;
    }
    return c;
}

template<class T>
inline int pow(T a, int b){
    T c(1);
    while (b) {
        if (b&1) MUL(c, a);
        MUL(a, a), b >>= 1;
    }
    return c;
}

inline int _I(int b){
    int a = MOD, x1 = 0, x2 = 1, q;
    while (true){
        q = a / b, a %= b;
        if (!a) return (x2 + MOD) % MOD;
        DEC(x1, pdt(q, x2));

        q = b / a, b %= a;
        if (!b) return (x1 + MOD) % MOD;
        DEC(x2, pdt(q, x1));
    }
}

inline void DIA(int &a, int b){MUL(a, _I(b));}
inline int qtt(int a, int b){return pdt(a, _I(b));}

inline int sum(int a, int b, int MOD){
    a += b; if (a >= MOD) a -= MOD;
    return a;
}

inline int phi(int n){
    int res = n;
    for (int i=2;sqr(i)<=n;++i) if (!(n%i)){
        DEC(res, qtt(res, i));
        do{n /= i;} while(!(n%i));
    }
    if (n != 1)
        DEC(res, qtt(res, n));
    return res;
}




struct Po; struct Line; struct Seg;

inline int sgn(DB x){return x < -EPS ? -1 : x > EPS;}
inline int sgn(DB x, DB y){return sgn(x - y);}

struct Po{
    DB x, y;
    Po(DB _x = 0, DB _y = 0):x(_x), y(_y){}

    friend istream& operator >>(istream& in, Po &p){return in >> p.x >> p.y;}
    friend ostream& operator <<(ostream& out, Po p){return out << "(" << p.x << ", " << p.y << ")";}

    friend bool operator ==(Po, Po);
    friend bool operator !=(Po, Po);
    friend Po operator +(Po, Po);
    friend Po operator -(Po, Po);
    friend Po operator *(Po, DB);
    friend Po operator /(Po, DB);

    bool operator < (const Po &rhs) const{return sgn(x, rhs.x) < 0 || sgn(x, rhs.x) == 0 && sgn(y, rhs.y) < 0;}
    Po operator-() const{return Po(-x, -y);}
    Po& operator +=(Po rhs){x += rhs.x, y += rhs.y; return *this;}
    Po& operator -=(Po rhs){x -= rhs.x, y -= rhs.y; return *this;}
    Po& operator *=(DB k){x *= k, y *= k; return *this;}
    Po& operator /=(DB k){x /= k, y /= k; return *this;}

    DB length_sqr(){return sqr(x) + sqr(y);}
    DB length(){return sqrt(length_sqr());}

    DB atan(){
        return atan2(y, x);
    }

    void input(){
        scanf("%lf %lf", &x, &y);
    }
};

bool operator ==(Po a, Po b){return sgn(a.x - b.x) == 0 && sgn(a.y - b.y) == 0;}
bool operator !=(Po a, Po b){return sgn(a.x - b.x) != 0 || sgn(a.y - b.y) != 0;}
Po operator +(Po a, Po b){return Po(a.x + b.x, a.y + b.y);}
Po operator -(Po a, Po b){return Po(a.x - b.x, a.y - b.y);}
Po operator *(Po a, DB k){return Po(a.x * k, a.y * k);}
Po operator *(DB k, Po a){return a * k;}
Po operator /(Po a, DB k){return Po(a.x / k, a.y / k);}

struct Line{
    Po a, b;
    Line(Po _a = Po(), Po _b = Po()):a(_a), b(_b){}
    Line(DB x0, DB y0, DB x1, DB y1):a(Po(x0, y0)), b(Po(x1, y1)){}
    Line(Seg);

    friend ostream& operator <<(ostream& out, Line p){return out << p.a << "-" << p.b;}
};

struct Seg{
    Po a, b;
    Seg(Po _a = Po(), Po _b = Po()):a(_a), b(_b){}
    Seg(DB x0, DB y0, DB x1, DB y1):a(Po(x0, y0)), b(Po(x1, y1)){}
    Seg(Line l);

    friend ostream& operator <<(ostream& out, Seg p){return out << p.a << "-" << p.b;}
    DB length(){return (b - a).length();}
};

Line::Line(Seg l):a(l.a), b(l.b){}
Seg::Seg(Line l):a(l.a), b(l.b){}

#define innerProduct dot
#define scalarProduct dot
#define dotProduct dot
#define outerProduct det
#define crossProduct det

inline DB dot(DB x1, DB y1, DB x2, DB y2){return x1 * x2 + y1 * y2;}
inline DB dot(Po a, Po b){return dot(a.x, a.y, b.x, b.y);}
inline DB dot(Po p0, Po p1, Po p2){return dot(p1 - p0, p2 - p0);}
inline DB dot(Line l1, Line l2){return dot(l1.b - l1.a, l2.b - l2.a);}
inline DB det(DB x1, DB y1, DB x2, DB y2){return x1 * y2 - x2 * y1;}
inline DB det(Po a, Po b){return det(a.x, a.y, b.x, b.y);}
inline DB det(Po p0, Po p1, Po p2){return det(p1 - p0, p2 - p0);}
inline DB det(Line l1, Line l2){return det(l1.b - l1.a, l2.b - l2.a);}

template<class T1, class T2> inline DB dist(T1 x, T2 y){return sqrt(dist_sqr(x, y));}

inline DB dist_sqr(Po a, Po b){return sqr(a.x - b.x) + sqr(a.y - b.y);}
inline DB dist_sqr(Po p, Line l){Po v0 = l.b - l.a, v1 = p - l.a; return sqr(fabs(det(v0, v1))) / v0.length_sqr();}
inline DB dist_sqr(Po p, Seg l){
    Po v0 = l.b - l.a, v1 = p - l.a, v2 = p - l.b;
    if (sgn(dot(v0, v1)) * sgn(dot(v0, v2)) <= 0) return dist_sqr(p, Line(l));
    else return min(v1.length_sqr(), v2.length_sqr());
}

inline DB dist_sqr(Line l, Po p){return dist_sqr(p, l);}
inline DB dist_sqr(Seg l, Po p){return dist_sqr(p, l);}

inline DB dist_sqr(Line l1, Line l2){
    if (sgn(det(l1, l2)) != 0) return 0;
    return dist_sqr(l1.a, l2);
}
inline DB dist_sqr(Line l1, Seg l2){
    Po v0 = l1.b - l1.a, v1 = l2.a - l1.a, v2 = l2.b - l1.a; DB c1 = det(v0, v1), c2 = det(v0, v2);
    return sgn(c1) != sgn(c2) ? 0 : sqr(min(fabs(c1), fabs(c2))) / v0.length_sqr();
}

bool isIntersect(Seg l1, Seg l2){

    


    return
        min(l1.a.x, l1.b.x) <= max(l2.a.x, l2.b.x) &&
        min(l2.a.x, l2.b.x) <= max(l1.a.x, l1.b.x) &&
        min(l1.a.y, l1.b.y) <= max(l2.a.y, l2.b.y) &&
        min(l2.a.y, l2.b.y) <= max(l1.a.y, l1.b.y) &&
    sgn( det(l1.a, l2.a, l2.b) ) * sgn( det(l1.b, l2.a, l2.b) ) <= 0 &&
    sgn( det(l2.a, l1.a, l1.b) ) * sgn( det(l2.b, l1.a, l1.b) ) <= 0;

}

inline DB dist_sqr(Seg l1, Seg l2){
    if (isIntersect(l1, l2)) return 0;
    else return min(dist_sqr(l1.a, l2), dist_sqr(l1.b, l2), dist_sqr(l2.a, l1), dist_sqr(l2.b, l1));
}

inline bool isOnExtremePoint(const Po &p, const Seg &l){
    return p == l.a || p == l.b;
}

inline bool isOnseg(const Po &p, const Seg &l){

    


    return sgn(det(p, l.a, l.b)) == 0 &&
        sgn(l.a.x, p.x) * sgn(l.b.x, p.x) <= 0 && sgn(l.a.y, p.y) * sgn(l.b.y, p.y) <= 0;
}

inline Po intersect(const Line &l1, const Line &l2){
    return l1.a + (l1.b - l1.a) * (det(l2.a, l1.a, l2.b) / det(l2, l1));
}



inline Po intersect(const Po & p, const Line &l){
    return intersect(Line(p, p + Po(l.a.y - l.b.y, l.b.x - l.a.x)), l);
}

inline Po rotate(Po p, DB alpha, Po o = Po()){
    p.x -= o.x, p.y -= o .y;
    return Po(p.x * cos(alpha) - p.y * sin(alpha), p.y * cos(alpha) + p.x * sin(alpha)) + o;
}




inline int rand32(){return (bool(rand() & 1) << 30) | (rand() << 15) + rand();}
inline int random32(int l, int r){return rand32() % (r - l + 1) + l;}
inline int random(int l, int r){return rand() % (r - l + 1) + l;}
int dice(){return rand() % 6;}
bool coin(){return rand() % 2;}




template<class T> inline void RD(T &x){
    

    

    char c; for (c = getchar(); c < '0'; c = getchar()); x = c - '0'; for (c = getchar(); c >= '0'; c = getchar()) x = x * 10 + c - '0';
    

}

template<class T> inline void OT(const T &x){
    printf("%d\n", x);
}



const int N = 100009, M = N * 2;

int hd[N], prd[M], suc[M], to[M];


int size[N], head[N], F[N], D[N], Hid[N];


int n, nn;

#define black(x) H[x].B[1]

#define lx (x<<1)
#define rx (lx|1)
#define y (x>>1)

struct Heap{

    VI B; int *H, *P;
    int n;

private:

    inline int A(int x){return B[H[x]];}

    void Swap(int a, int b){
        swap(H[a], H[b]);
        P[H[a]] = a, P[H[b]] = b;
    }

    inline void Up(int x){
        while (A(y) > A(x)){
            Swap(x, y), x = y;
        }
    }

    inline void Down(int x){
        int h = x; while (true){
            if (lx <= n && A(lx) < A(h)) h = lx;
            if (rx <= n && A(rx) < A(h)) h = rx;
            if (h == x) break;
            Swap(h, x), x = h;
        }
    }

public:

    void Build(){
        n = SZ(B); H = new int[n], P = new int[n]; --n;
        FOR_1(i, 0, n) H[i] = P[i] = i; DWN_1(i, n>>1, 1) Down(i);
    }

    void Update(int x, int v){
        if (B[x] > v) B[x] = v, Up(P[x]);
        else B[x] = v, Down(P[x]);
    }

    int top(){
        return A(1);
    }

} H[N];

#undef y

#define root 1, 0, n-1
#define m ((l+r)>>1)
#define lc lx, l, m
#define rc rx, m+1, r

#define Update(x) ml[x] = min(ml[lx], d(l, m+1) + ml[rx]), mr[x] = min(mr[rx], d(m, r) + mr[lx])
#define Upleaf(x) ml[x] = mr[x] = h.top()

struct Interval_Tree{

    VI id; int *ml, *mr;
    int n, _x, offset;

private:

    int d(int l, int r){
        return r - l;
    }

#define h H[id[l]]
    void _B(int x, int l, int r){
        if (l == r) ml[x] = mr[x] = INF;
        else _B(lc), _B(rc), ml[x] = mr[x] = INF;
    }

    void _M(int x, int l, int r){
        if (l == r) Upleaf(x);
        else {if (_x <= m) _M(lc); if (m < _x) _M(rc); Update(x);}
    }

    int _MinL(int x, int l, int r){
        if (l == r) return ml[x];
        else return _x <= m ? _MinL(lc) : min(_MinL(rc), mr[lx] + d(m, _x));
    }

    int _MinR(int x, int l, int r){
        if (l == r) return mr[x];
        else return _x <= m ? min(_MinR(lc), d(_x, m+1) + ml[rx]) : _MinR(rc);
    }

#undef h

public:

    int d(int x){
        return d(0, D[x] - offset);
    }

    void Build(){
        n = SZ(id); offset = D[id[0]]; int t=1; while(t<n) t<<=1; t<<=1;
        ml = new int[t], mr = new int[t],  _B(root);
    }

    void Modify(int x){
        _x = D[x] - offset, _M(root);
    }

    int MinR(int x){
        _x = D[x] - offset; return _MinR(root);
    }

    int MinL(int x){
        _x = D[x] - offset; return _MinL(root);
    }

    int MinL(){return ml[1];}

} T[N];

#undef Update

inline void del(int x){
    if (x == hd[to[x^1]]) prd[hd[to[x^1]] = suc[x]] = 0;
    else suc[prd[suc[x]] = prd[x]] = suc[x];
}

#define TRA(i, x) for(int i=hd[x];i;i=suc[i])
#define u q[i]
#define v to[ii]

int q[N]; void bfs(){
    n = 0, q[n++] = 1; REP(i, n) TRA(ii, u) if(!F[v])
        q[n++] = v, F[v] = u, D[v] = D[u] + 1, del(ii^1);

    DWN(i, n, 0){
        size[u] = 1; TRA(ii, u)
            size[u] += size[v];
    }
}

void hld(){
    REP(i, n) if (!head[u]){
        int x = u, y; while (true){
            T[u].id.PB(x); y = 0; head[x] = u; TRA(ii, x){
                if(!y || size[v] > size[y]) y = v;
            }
            if (!y) break;
            x = y;
        }
    }
}

void init(){

    DWN(i, n, 0){

        int cnt = 1; H[u].B.PB(INF);

        TRA(ii, u) if(head[v] != head[u])
            Hid[v]=++cnt, H[u].B.PB(INF);

        H[u].Build(); if (head[u] == u)  

            T[u].Build();
    }
}

#undef u
#undef v

void Up(int& x){
    T[head[x]].Modify(x), x = head[x];
}

void Modify(int u){

    if (black(u)) H[u].Update(1, 0);
    else H[u].Update(1, INF);

    Up(u); int v = F[u]; while (v){
        H[v].Update(Hid[u], T[u].MinL() + 1);
        Up(v), v = F[u = v];
    }
}

int Query(int u){

    if (!black(u)) return 0;

    int res = INF, path = 0, t; while (u){
        t = min(T[head[u]].MinL(u), T[head[u]].MinR(u));
        checkMin(res, t + path); if (!t) break; 

        path += T[head[u]].d(u) + 1;
        u = F[head[u]];
    }
    return res == INF ? -1 : res;
}


int main(){

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int Q; RD(n, Q);
    FOR_C(i, 2, n << 1){
        RD(to[i], to[i|1]);
        prd[hd[to[i^1]]] = i, suc[i] = hd[to[i^1]], hd[to[i^1]] = i, ++i;
        prd[hd[to[i^1]]] = i, suc[i] = hd[to[i^1]], hd[to[i^1]] = i;
    }



    REP_1(i, n) H[i].B.PB(-INF); 




    bfs(); hld(); init(); 



        Modify(1);

    DO(Q){
        if (RD()==2) OT(Query(RD()));
        else Modify(RD());
    }
}
