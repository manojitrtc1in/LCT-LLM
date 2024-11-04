 


 





































using namespace std;




























































  REP(i, n){		                            \
        REP(j, m-1) cout << A[i][j] << " ";     \
        cout << A[i][m-1] << endl;		        \
	}						                    \
}

	id0(i, n){		                        \
        id0(j, m-1) cout << A[i][j] << " ";   \
        cout << A[i][m] << endl;		        \
	}						                    \
}

typedef long long LL;


typedef double DB;
typedef unsigned uint;
typedef unsigned long long uLL;

typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<string> VS;
typedef vector<LL> VL;
typedef vector<DB> VF;
typedef set<int> SI;
typedef set<string> SS;
typedef map<int, int> MII;
typedef map<string, int> MSI;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef vector<VII> VVII;

template<class T> inline T& RD(T &);
template<class T> inline void OT(const T &);


inline LL RD(){LL x; return RD(x);}
inline DB& RF(DB &);
inline DB RF(){DB x; return RF(x);}
inline char* RS(char *s);
inline char& RC(char &c);
inline char RC();
inline char& RC(char &c){scanf(" %c", &c); return c;}
inline char RC(){char c; return RC(c);}





template<class T> inline T& RDD(T &);
inline LL RDD(){LL x; return RDD(x);}

template<class T0, class T1> inline T0& RD(T0 &x0, T1 &x1){RD(x0), RD(x1); return x0;}
template<class T0, class T1, class T2> inline T0& RD(T0 &x0, T1 &x1, T2 &x2){RD(x0), RD(x1), RD(x2); return x0;}
template<class T0, class T1, class T2, class T3> inline T0& RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3){RD(x0), RD(x1), RD(x2), RD(x3); return x0;}
template<class T0, class T1, class T2, class T3, class T4> inline T0& RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4){RD(x0), RD(x1), RD(x2), RD(x3), RD(x4); return x0;}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline T0& RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5){RD(x0), RD(x1), RD(x2), RD(x3), RD(x4), RD(x5); return x0;}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline T0& RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5, T6 &x6){RD(x0), RD(x1), RD(x2), RD(x3), RD(x4), RD(x5), RD(x6); return x0;}
template<class T0, class T1> inline void OT(const T0 &x0, const T1 &x1){OT(x0), OT(x1);}
template<class T0, class T1, class T2> inline void OT(const T0 &x0, const T1 &x1, const T2 &x2){OT(x0), OT(x1), OT(x2);}
template<class T0, class T1, class T2, class T3> inline void OT(const T0 &x0, const T1 &x1, const T2 &x2, const T3 &x3){OT(x0), OT(x1), OT(x2), OT(x3);}
template<class T0, class T1, class T2, class T3, class T4> inline void OT(const T0 &x0, const T1 &x1, const T2 &x2, const T3 &x3, const T4 &x4){OT(x0), OT(x1), OT(x2), OT(x3), OT(x4);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void OT(const T0 &x0, const T1 &x1, const T2 &x2, const T3 &x3, const T4 &x4, const T5 &x5){OT(x0), OT(x1), OT(x2), OT(x3), OT(x4), OT(x5);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void OT(const T0 &x0, const T1 &x1, const T2 &x2, const T3 &x3, const T4 &x4, const T5 &x5, const T6 &x6){OT(x0), OT(x1), OT(x2), OT(x3), OT(x4), OT(x5), OT(x6);}
inline char& RC(char &a, char &b){RC(a), RC(b); return a;}
inline char& RC(char &a, char &b, char &c){RC(a), RC(b), RC(c); return a;}
inline char& RC(char &a, char &b, char &c, char &d){RC(a), RC(b), RC(c), RC(d); return a;}
inline char& RC(char &a, char &b, char &c, char &d, char &e){RC(a), RC(b), RC(c), RC(d), RC(e); return a;}
inline char& RC(char &a, char &b, char &c, char &d, char &e, char &f){RC(a), RC(b), RC(c), RC(d), RC(e), RC(f); return a;}
inline char& RC(char &a, char &b, char &c, char &d, char &e, char &f, char &g){RC(a), RC(b), RC(c), RC(d), RC(e), RC(f), RC(g); return a;}
inline DB& RF(DB &a, DB &b){RF(a), RF(b); return a;}
inline DB& RF(DB &a, DB &b, DB &c){RF(a), RF(b), RF(c); return a;}
inline DB& RF(DB &a, DB &b, DB &c, DB &d){RF(a), RF(b), RF(c), RF(d); return a;}
inline DB& RF(DB &a, DB &b, DB &c, DB &d, DB &e){RF(a), RF(b), RF(c), RF(d), RF(e); return a;}
inline DB& RF(DB &a, DB &b, DB &c, DB &d, DB &e, DB &f){RF(a), RF(b), RF(c), RF(d), RF(e), RF(f); return a;}
inline DB& RF(DB &a, DB &b, DB &c, DB &d, DB &e, DB &f, DB &g){RF(a), RF(b), RF(c), RF(d), RF(e), RF(f), RF(g); return a;}
inline void RS(char *s1, char *s2){RS(s1), RS(s2);}
inline void RS(char *s1, char *s2, char *s3){RS(s1), RS(s2), RS(s3);}
template<class T0,class T1>inline void RDD(T0&a, T1&b){RDD(a),RDD(b);}
template<class T0,class T1,class T2>inline void RDD(T0&a, T1&b, T2&c){RDD(a),RDD(b),RDD(c);}

template<class T> inline void RST(T &A){memset(A, 0, sizeof(A));}
template<class T> inline void FLC(T &A, int x){memset(A, x, sizeof(A));}
template<class T> inline void CLR(T &A){A.clear();}

template<class T0, class T1> inline void RST(T0 &A0, T1 &A1){RST(A0), RST(A1);}
template<class T0, class T1, class T2> inline void RST(T0 &A0, T1 &A1, T2 &A2){RST(A0), RST(A1), RST(A2);}
template<class T0, class T1, class T2, class T3> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3){RST(A0), RST(A1), RST(A2), RST(A3);}
template<class T0, class T1, class T2, class T3, class T4> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4){RST(A0), RST(A1), RST(A2), RST(A3), RST(A4);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5){RST(A0), RST(A1), RST(A2), RST(A3), RST(A4), RST(A5);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6){RST(A0), RST(A1), RST(A2), RST(A3), RST(A4), RST(A5), RST(A6);}
template<class T0, class T1> inline void FLC(T0 &A0, T1 &A1, int x){FLC(A0, x), FLC(A1, x);}
template<class T0, class T1, class T2> inline void FLC(T0 &A0, T1 &A1, T2 &A2, int x){FLC(A0, x), FLC(A1, x), FLC(A2, x);}
template<class T0, class T1, class T2, class T3> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, int x){FLC(A0, x), FLC(A1, x), FLC(A2, x), FLC(A3, x);}
template<class T0, class T1, class T2, class T3, class T4> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, int x){FLC(A0, x), FLC(A1, x), FLC(A2, x), FLC(A3, x), FLC(A4, x);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, int x){FLC(A0, x), FLC(A1, x), FLC(A2, x), FLC(A3, x), FLC(A4, x), FLC(A5, x);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6, int x){FLC(A0, x), FLC(A1, x), FLC(A2, x), FLC(A3, x), FLC(A4, x), FLC(A5, x), FLC(A6, x);}
template<class T> inline void CLR(priority_queue<T, vector<T>, less<T> > &Q){while (!Q.empty()) Q.pop();}
template<class T> inline void CLR(priority_queue<T, vector<T>, greater<T> > &Q){while (!Q.empty()) Q.pop();}
template<class T> inline void CLR(stack<T> &S){while (!S.empty()) S.pop();}

template<class T0, class T1> inline void CLR(T0 &A0, T1 &A1){CLR(A0), CLR(A1);}
template<class T0, class T1, class T2> inline void CLR(T0 &A0, T1 &A1, T2 &A2){CLR(A0), CLR(A1), CLR(A2);}
template<class T0, class T1, class T2, class T3> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3){CLR(A0), CLR(A1), CLR(A2), CLR(A3);}
template<class T0, class T1, class T2, class T3, class T4> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4){CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5){CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4), CLR(A5);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6){CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4), CLR(A5), CLR(A6);}
template<class T> inline void CLR(T &A, int n){REP(i, n) CLR(A[i]);}

template<class T> inline bool EPT(T &a){return a.empty();}
template<class T> inline T& SRT(T &A){sort(ALL(A)); return A;}
template<class T, class C> inline T& SRT(T &A, C B){sort(ALL(A), B); return A;}
template<class T> inline T& RVS(T &A){reverse(ALL(A)); return A;}
template<class T> inline T& UNQQ(T &A){A.resize(unique(ALL(A))-A.begin());return A;}
template<class T> inline T& UNQ(T &A){SRT(A);return UNQQ(A);}





 


int MOD = int(1e9) + 7;
const int INF = 0x3f3f3f3f;
const LL INFF = 0x3f3f3f3f3f3f3f3fLL;
const DB EPS = 1e-9;
const DB OO = 1e20;
const DB PI = acos(-1.0); 


const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};




 




template<class T> inline T& checkMin(T &a,const T b){if (b<a) a=b;return a;}
template<class T> inline T& checkMax(T &a,const T b){if (a<b) a=b;return a;}
template<class T> inline T& checkMin(T &a, T &b, const T x){checkMin(a, x), checkMin(b, x);return a;}
template<class T> inline T& checkMax(T &a, T &b, const T x){checkMax(a, x), checkMax(b, x);return a;}
template <class T, class C> inline T& checkMin(T& a, const T b, C c){if (c(b,a)) a = b;return a;}
template <class T, class C> inline T& checkMax(T& a, const T b, C c){if (c(a,b)) a = b;return a;}
template<class T> inline T min(T a, T b, T c){return min(min(a, b), c);}
template<class T> inline T max(T a, T b, T c){return max(max(a, b), c);}
template<class T> inline T min(T a, T b, T c, T d){return min(min(a, b), min(c, d));}
template<class T> inline T max(T a, T b, T c, T d){return max(max(a, b), max(c, d));}
template<class T> inline T min(T a, T b, T c, T d, T e){return min(min(min(a,b),min(c,d)),e);}
template<class T> inline T max(T a, T b, T c, T d, T e){return max(max(max(a,b),max(c,d)),e);}
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline T cub(T a){return a*a*a;}
template<class T> inline T ceil(T x, T y){return (x - 1) / y + 1;}
template<class T> T abs(T x){return x>0?x:-x;}
inline int sgn(DB x){return x < -EPS ? -1 : x > EPS;}
inline int sgn(DB x, DB y){return sgn(x - y);}

inline DB cos(DB a, DB b, DB c){return (sqr(a)+sqr(b)-sqr(c))/(2*a*b);}
inline DB cot(DB x){return 1./tan(x);};
inline DB sec(DB x){return 1./cos(x);};
inline DB csc(DB x){return 1./sin(x);};





namespace BO{

inline bool _1(int x, int i){return bool(x&1<<i);}
inline bool _1(LL x, int i){return bool(x&1LL<<i);}
inline LL _1(int i){return 1LL<<i;}
inline LL _U(int i){return _1(i) - 1;};

inline int reverse_bits(int x){
    x = ((x >> 1) & 0x55555555) | ((x << 1) & 0xaaaaaaaa);
    x = ((x >> 2) & 0x33333333) | ((x << 2) & 0xcccccccc);
    x = ((x >> 4) & 0x0f0f0f0f) | ((x << 4) & 0xf0f0f0f0);
    x = ((x >> 8) & 0x00ff00ff) | ((x << 8) & 0xff00ff00);
    x = ((x >>16) & 0x0000ffff) | ((x <<16) & 0xffff0000);
    return x;
}

inline LL reverse_bits(LL x){
    x = ((x >> 1) & 0x5555555555555555LL) | ((x << 1) & 0xaaaaaaaaaaaaaaaaLL);
    x = ((x >> 2) & 0x3333333333333333LL) | ((x << 2) & 0xccccccccccccccccLL);
    x = ((x >> 4) & 0x0f0f0f0f0f0f0f0fLL) | ((x << 4) & 0xf0f0f0f0f0f0f0f0LL);
    x = ((x >> 8) & 0x00ff00ff00ff00ffLL) | ((x << 8) & 0xff00ff00ff00ff00LL);
    x = ((x >>16) & 0x0000ffff0000ffffLL) | ((x <<16) & 0xffff0000ffff0000LL);
    x = ((x >>32) & 0x00000000ffffffffLL) | ((x <<32) & 0xffffffff00000000LL);
    return x;
}

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

inline LL lcm(LL a, LL b){return a*b/gcd(a,b);}

inline void INC(int &a, int b){a += b; if (a >= MOD) a -= MOD;}
inline int sum(int a, int b){a += b; if (a >= MOD) a -= MOD; return a;}


inline void DEC(int &a, int b){a -= b; if (a < 0) a += MOD;}
inline int dff(int a, int b){a -= b; if (a < 0) a  += MOD; return a;}
inline void MUL(int &a, int b){a = (LL)a * b % MOD;}
inline int pdt(int a, int b){return (LL)a * b % MOD;}

inline int gcd(int m, int n, int &x, int &y){

    x = 1, y = 0; int xx = 0, yy = 1, q;

    while (1){
        q = m / n, m %= n;
        if (!m){x = xx, y = yy; return n;}
        DEC(x, pdt(q, xx)), DEC(y, pdt(q, yy));
        q = n / m, n %= m;
        if (!n) return m;
        DEC(xx, pdt(q, x)), DEC(yy, pdt(q, y));
    }
}

inline int sum(int a, int b, int c){return sum(a, sum(b, c));}
inline int sum(int a, int b, int c, int d){return sum(sum(a, b), sum(c, d));}
inline int pdt(int a, int b, int c){return pdt(a, pdt(b, c));}
inline int pdt(int a, int b, int c, int d){return pdt(pdt(a, b), pdt(c, d));}

inline int pow(int a, LL b){
    int c(1); while (b){
        if (b&1) MUL(c, a);
        MUL(a, a), b >>= 1;
    }
    return c;
}

inline int poww(int a, LL b){
    int c(1); while (b){
        if (b&1) c *= a;
        a *= a, b >>= 1;
    }
    return c;
}

template<class T> inline T pow(T a, LL b){
    T c(1); while (b){
        if (b&1) c *= a;
        a *= a, b >>= 1;
    }
    return c;
}

template<class T> inline T pow(T a, int b){
    return pow(a, (LL)b);
}

inline int _I(int b){
    int a = MOD, x1 = 0, x2 = 1, q; while (1){
        q = a / b, a %= b;
        if (!a) return x2;
        DEC(x1, pdt(q, x2));

        q = b / a, b %= a;
        if (!b) return x1;
        DEC(x2, pdt(q, x1));
    }
}

inline void DIV(int &a, int b){MUL(a, _I(b));}
inline int qtt(int a, int b){return pdt(a, _I(b));}

struct Int{
    int val;

    operator int() const{return val;}

    Int(int val = 0):val(val){
        val %= MOD; if (val < 0) val += MOD;
    }
    Int(LL _val){
        _val %= MOD; if (_val < 0) _val += MOD;
        val = _val;
    }
    Int& operator +=(const int& rhs){INC(val, rhs);rTs;}
    Int operator +(const int& rhs) const{return sum(val, rhs);}
    Int& operator -=(const int& rhs){DEC(val, rhs);rTs;}
    Int operator -(const int& rhs) const{return dff(val, rhs);}
    Int& operator *=(const int& rhs){MUL(val, rhs);rTs;}
    Int operator *(const int& rhs) const{return pdt(val, rhs);}
    Int& operator /=(const int& rhs){DIV(val, rhs);rTs;}
    Int operator /(const int& rhs) const{return qtt(val, rhs);}
    Int operator-()const{return MOD-*this;}
};

} using namespace NT;




namespace CG{





inline DB dist2(DB x,DB y){return sqr(x)+sqr(y);}

struct Po{
    DB x,y;Po(DB x=0,DB y=0):x(x),y(y){}

    void in(){RF(x,y);}void out(){printf("(%.2f,%.2f)",x,y);}
    inline friend istream&operator>>(istream&i,Po&p){return i>>p.x>>p.y;}
    inline friend ostream&operator<<(ostream&o,Po p){return o<<"("<<p.x<<", "<<p.y<< ")";}

    Po operator-()const{return Po(-x,-y);}
    Po&operator+=(cPo p){x+=p.x,y+=p.y;rTs;}Po&operator-=(cPo p){x-=p.x,y-=p.y;rTs;}
    Po&operator*=(DB k){x*=k,y*=k;rTs;}Po&operator/=(DB k){x/=k,y/=k;rTs;}
    Po&operator*=(cPo p){rTs=Ts*p;}Po&operator/=(cPo p){rTs=Ts/p;}
    Po operator+(cPo p)const{return Po(x+p.x,y+p.y);}Po operator-(cPo p)const{return Po(x-p.x,y-p.y);}
    Po operator*(DB k)const{return Po(x*k,y*k);}Po operator/(DB k)const{return Po(x/k,y/k);}
    Po operator*(cPo p)const{return Po(x*p.x-y*p.y,y*p.x+x*p.y);}Po operator/(cPo p)const{return Po(x*p.x+y*p.y,y*p.x-x*p.y)/p.len2();}

    bool operator==(cPo p)const{return!sgn(x,p.x)&&!sgn(y,p.y);};bool operator!=(cPo p)const{return sgn(x,p.x)||sgn(y,p.y);}
    bool operator<(cPo p)const{return sgn(x,p.x)<0||!sgn(x,p.x)&&sgn(y,p.y)<0;}bool operator<=(cPo p)const{return sgn(x,p.x)<0||!sgn(x,p.x)&&sgn(y,p.y)<=0;}
    bool operator>(cPo p)const{return!(Ts<=p);}bool operator >=(cPo p)const{return!(Ts<p);}

    DB len2()const{return dist2(x,y);}DB len()const{return sqrt(len2());}DB arg()const{return atan2(y,x);}
    Po&_1(){rTs/=len();}Po&conj(){y=-y;rTs;}Po&lt(){swap(x,y),x=-x;rTs;}Po&rt(){swap(x,y),y=-y;rTs;}
    Po&rot(DB a,cPo o=Po()){Ts-=o;Ts*=Po(cos(a),sin(a));rTs+=o;}
};

inline DB dot(DB x1,DB y1,DB x2,DB y2){return x1*x2+y1*y2;}
inline DB dot(cPo a,cPo b){return dot(a.x,a.y,b.x,b.y);}
inline DB dot(cPo p0,cPo p1,cPo p2){return dot(p1-p0,p2-p0);}
inline DB det(DB x1,DB y1,DB x2,DB y2){return x1*y2-x2*y1;}
inline DB det(cPo a,cPo b){return det(a.x,a.y,b.x,b.y);}
inline DB det(cPo p0,cPo p1,cPo p2){return det(p1-p0,p2-p0);}
inline DB ang(cPo p0,cPo p1){return acos(dot(p0,p1)/p0.len()/p1.len());}
inline DB ang(cPo p0,cPo p1,cPo p2){return ang(p1-p0,p2-p0);}
inline DB ang(cPo p0,cPo p1,cPo p2,cPo p3){return ang(p1-p0,p3-p2);}
inline DB dist2(const Po &a, const Po &b){return dist2(a.x-b.x, a.y-b.y);}
template<class T1, class T2> inline int dett(const T1 &x, const T2 &y){return sgn(det(x, y));}
template<class T1, class T2, class T3> inline int dett(const T1 &x, const T2 &y, const T3 &z){return sgn(det(x, y, z));}
template<class T1, class T2, class T3, class T4> inline int dett(const T1 &x, const T2 &y, const T3 &z, const T4 &w){return sgn(det(x, y, z, w));}
template<class T1, class T2> inline int dott(const T1 &x, const T2 &y){return sgn(dot(x, y));}
template<class T1, class T2, class T3> inline int dott(const T1 &x, const T2 &y, const T3 &z){return sgn(dot(x, y, z));}
template<class T1, class T2, class T3, class T4> inline int dott(const T1 &x, const T2 &y, const T3 &z, const T4 &w){return sgn(dot(x, y, z, w));}
template<class T1, class T2> inline DB arg(const T1 &x, const T2 &y){DB a=ang(x,y);return~dett(x,y)?a:2*PI-a;}
template<class T1, class T2, class T3> inline DB arg(const T1 &x, const T2 &y, const T3 &z){DB a=ang(x,y,z);return~dett(x,y,z)?a:2*PI-a;}
template<class T1, class T2, class T3, class T4> inline DB arg(const T1 &x, const T2 &y, const T3 &z, const T4 &w){DB a=ang(x,y,z,w);return~dett(x,y,z,w)?a:2*PI-a;}
template<class T1, class T2> inline DB dist(const T1 &x, const T2 &y){return sqrt(dist2(x, y));}
template<class T1, class T2, class T3> inline DB dist(const T1 &x, const T2 &y, const T3 &z){return sqrt(dist2(x, y, z));}
inline Po _1(Po p){return p._1();}inline Po conj(Po p){return p.conj();}
inline Po lt(Po p){return p.lt();}inline Po rt(Po p){return p.rt();}
inline Po rot(Po p,DB a,cPo o=Po()){return p.rot(a,o);}
inline Po operator *(DB k,cPo p){return p*k;}
inline Po operator /(DB k,cPo p){return conj(p)*k/p.len2();}

typedef vector<Po> VP;

struct Line{
    Po a,b;Line(cPo a=Po(),cPo b=Po()):a(a),b(b){}
    Line(DB x0,DB y0,DB x1,DB y1):a(Po(x0,y0)),b(Po(x1,y1)){}
    Line(cLine l):a(l.a),b(l.b){}

    

    Line(DB A,DB B,DB C){
        C=-C;if(!::sgn(A))a=Po(0,C/B),b=Po(1,C/B);
        else if(!::sgn(B))a=Po(C/A,0),b=Po(C/A,1);
        else a=Po(0,C/B),b=Po(1,(C-A)/B);
    }

    void in(){a.in(),b.in();}
    inline friend istream&operator>>(istream&i,Line& p){return i>>p.a>>p.b;}
    inline friend ostream&operator<<(ostream&o,Line p){return o<<p.a<<"-"<< p.b;}

    Line operator+(cPo x)const{return Line(a+x,b+x);}
    Line operator-(cPo x)const{return Line(a-x,b-x);}
    Line operator*(DB k)const{return Line(a*k,b*k);}
    Line operator/(DB k)const{return Line(a/k,b/k);}

    Po operator*(cLine)const;
    Po d()const{return b-a;}DB len2()const{return d().len2();}DB len()const{return d().len();}DB arg()const{return d().arg();}

    int sgn(cPo p)const{return dett(a, b, p);}
    int sgn(cLine)const;

    bool sameSgn(cPo  p1,cPo  p2)const{return sgn(p1)==sgn(p2);}
    void getEquation(DB&K,DB&B)const{
        K = ::sgn(a.x, b.x) ? (b.y-a.y)/(b.x-a.x) : OO;
        B = a.y - K*a.x;
    }
    void getEquation(DB&A,DB&B,DB&C)const{A=a.y-b.y,B=b.x-a.x,C=det(a, b);}

    Line&push(DB r){ 

        Po v=d()._1().lt()*r;a+=v,b+=v; rTs;
    }
};

inline DB dot(cLine l1,cLine l2){return dot(l1.d(),l2.d());}
inline DB dot(cLine l,cPo p){return dot(l.a,l.b,p);}
inline DB dot(cPo p,cLine l){return dot(p,l.a,l.b);}
inline DB det(cLine l1,cLine l2){return det(l1.d(),l2.d());}
inline DB det(cLine l,cPo p){return det(l.a,l.b,p);}
inline DB det(cPo p,cLine l){return det(p,l.a,l.b);}
inline DB ang(cLine l0,cLine l1){return ang(l0.d(),l1.d());}
inline DB ang(cLine l,cPo p){return ang(l.a,l.b,p);}
inline DB ang(cPo p,cLine l){return ang(p,l.a,l.b);}

inline int Line::sgn(cLine l)const{return dett(Ts, l);}
inline Po Line::operator*(cLine l)const{return a+d()*det(a,l)/det(Ts,l);}
inline Po operator&(cPo p,cLine l){return l*Line(p,p+l.d().lt());}
inline Po operator%(cPo p,cLine l){return p&l*2-p;}
inline Line push(Line l, DB r){return l.push(r);}


struct Seg: public Line{
    Seg(cPo a=Po(),cPo b=Po()):Line(a,b){}
    Seg(DB x0,DB y0,DB x1,DB y1):Line(x0,y0,x1,y1){}
    Seg(cLine l):Line(l){}
    Seg(const Po &a,DB alpha):Line(a,alpha){}
    Seg(DB A,DB B,DB C):Line(A,B,C){}

    inline int sgn(cPo p)const;
    inline int sgn(cLine l)const;
    inline bool qrt(cSeg l)const;
    inline int sgn(cSeg l)const;
};

 


inline int Seg::sgn(cPo p)const{return -dott(p,a,b);}
inline int Seg::sgn(cLine l)const{return sgn(Ts*l);}



inline bool Seg::qrt(cSeg l)const{
    return min(a.x,b.x)<=max(l.a.x,l.b.x)&&min(l.a.x,l.b.x)<=max(a.x,b.x)&&
        min(a.y,b.y)<=max(l.a.y,l.b.y)&&min(l.a.y,l.b.y)<=max(a.y,b.y);
}


inline int Seg::sgn(cSeg l)const{
    if (!qrt(l)) return -1;

    

    int d1=dett(a,b,l.a),d2=dett(a,b,l.b),d3=dett(l.a,l.b,a),d4=dett(l.a,l.b,b);
    if ((d1^d2)==-2&&(d3^d4)==-2)return 1;
    return ((!d1&&dott(l.a-a,l.a-b)<=0)||(!d2&&dott(l.b-a,l.b-b)<=0)||
            (!d3&&dott(a-l.a,a-l.b)<=0)||(!d4&&dott(b-l.a,b-l.b)<=0))?0:-1;
}



inline DB dist2(cLine l,cPo p){return sqr(fabs(det(l.d(), p-l.a)))/l.len2();}

inline DB dist2(cLine l1,cLine l2){return dett(l1,l2)?0:dist2(l1,l2.a);}

inline DB dist2(cSeg l,cPo p){
    Po pa = p - l.a, pb = p - l.b;
    if (dott(l.d(), pa) <= 0) return pa.len2();
    if (dott(l.d(), pb) >= 0) return pb.len2();
    return dist2(Line(l), p);
}


inline DB dist2(cSeg s,cLine l){
    Po v1=s.a-l.a,v2=s.b-l.a;DB d1=det(l.d(),v1),d2=det(l.d(),v2);
    return sgn(d1)!=sgn(d2) ? 0 : sqr(min(fabs(d1), fabs(d2)))/l.len2();
}
inline DB dist2(cSeg l1,cSeg l2){
    if (~l1.sgn(l2)) return 0;
    else return min(dist2(l2,l1.a), dist2(l2,l1.b), dist2(l1,l2.a), dist2(l1,l2.b));
}
template<class T1, class T2> inline DB dist2(const T1& a, const T2& b){
    return dist2(b, a);
}

} using namespace CG;







 







template<class T> inline T& RD(T &x){
    char c;while(!d);x=c-'0';while(d)p;
    return x;
}
template<class T> inline T& RDD(T &x){
    char c;while(g,c!='-'&&!isdigit(c));
    if (c=='-'){x='0'-g;while(d)n;}
    else{x=c-'0';while(d)p;}
    return x;
}
inline DB& RF(DB &x){
    

    char c;while(g,c!='-'&&c!='.'&&!isdigit(c));
    if(c=='-')if(g=='.'){x=0;DB l=1;while(d)nn;x*=l;}
        else{x='0'-c;while(d)n;if(c=='.'){DB l=1;while(d)nn;x*=l;}}
    else if(c=='.'){x=0;DB l=1;while(d)pp;x*=l;}
        else{x=c-'0';while(d)p;if(c=='.'){DB l=1;while(d)pp;x*=l;}}
    return x;
}






inline char* RS(char *s){
    

    scanf("%s", s);
    return s;
}

LL last_ans; int Case; template<class T> inline void OT(const T &x){
    

    

    printf("%.6f\n", x);
    

    

    

}








const int N = int(2e5)+9, M = 2*N;

struct node{

    static node* NIL; node *c[2], *p;
    int w1, w2; bool r0;











    void reset(){
        l = r = p = NIL;
        w1 = w2 = r0 = 0;
    }

    inline node(){
        reset();
    }

    inline void rev(){
        r0 ^= 1, swap(l, r);
    }

    inline void upd(){
        w2 = max(l->w2, w1, r->w2);
    }

    inline void rls(){
        

        if (r0){
            l->rev(), r->rev();
            r0 = 0;
        }
    }

    


    inline int sgn(){return p->l==this?0:p->r==this?1:-1;}
    inline void setc(int d,node*x){c[d]=x,px=this;}

    inline void rot(int d){
        node *y = p, *z = py; if (~y->sgn()) z->setc(y->sgn(), this); else p = z;
        y->setc(!d, c[d]), setc(d, y), y->upd();
    }

    inline void rot(){rot(!sgn());}
    inline void zag(){rot(0);}
    inline void zig(){rot(1);}

    


    inline void fix(){if(~sgn()) p->fix(); rls();}

    
    inline node* splay(){
        fix(); while (sgn() != -1){
            node *y = p, *z = py; if (y->sgn() == -1){ rot(); break;}
            if (z->l == y){
                if (y->l == this) y->zig(), zig();
                else zag(), zig();
            }else{
                if (y->r == this) y->zag(), zag();
                else zig(), zag();
            }
        }
        upd();
        return this;
    } 


    inline node* acs(){
        node *x = this, *y = NIL; do{
            x->splay();
            rx = y, x->upd();
            y = x, x = px;
        } while (x != NIL);
        return splay();
    }

    node* rt(){node* x; for (x = acs(); x->rls(), lx != NIL; x = lx); return x->splay();}
    node* ert(){acs()->rev(); return this;}


    void Link(node *x){
        ert(); p = x;
    }

    void Cut(){
        acs(); l = l->p = NIL;

    }

    void Cut(node* x){
        ert(), x->Cut();
    }

    node* lca(node*x){
        node *z; acs(); node *y = NIL; do{
            x->splay(); if (px == NIL) z = x;
            rx = y, x->upd();
            y = x, x = px;
        } while (x != NIL);
        return z;
    }

    int query(node* x){
        

        int z = 0; acs(); node *y = NIL; do{
            x->splay(); if (px == NIL) z = max(rx->w2, y->w2);
            rx = y, x->upd();
            y = x, x = px;
        } while (x != NIL);
        return z;
    }

} *NIL, *T[N];

struct rec{
    int u, v;
    int id;
};

vector<rec> Q[N]; VII O, sign; bool res[N];
int n, m, qq;




int main(){


    freopen("in.txt", "r", stdin);
    




    RD(n, m); NIL = new node(); REP(i, n+1) T[i] = new node();

    REP(i, m){
        int t; RD(t);
        if (t == 1){
            PII tt;  RD(tt.fi, tt.se);
            O.PB(tt);
        }
        else if (t == 2){
            PII tt; tt.fi = SZ(O); RD(tt.se);
            sign.PB(tt);
        }
        else{
            rec tt; tt.id = qq;
            int x; RD(tt.u, x); --x; tt.v = sign[x].se;
            Q[sign[x].fi].PB(tt);
            ++qq;
        }
    }

    REP(i, SZ(O)+1){
        ECH(it, Q[i]){
            res[it->id] = (T[it->u]->lca(T[it->v]) == T[it->u]);
        }
        if (i != SZ(O) )T[O[i].fi]->Link(T[O[i].se]);
    }

    REP(i, qq){
        puts(res[i] ? "YES" : "NO");
    }
}
