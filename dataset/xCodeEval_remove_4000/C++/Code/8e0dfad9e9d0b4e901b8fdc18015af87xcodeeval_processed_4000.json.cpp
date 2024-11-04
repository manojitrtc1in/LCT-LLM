


















using namespace std;






















































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
const int INF = 0x7fffffff;
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
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline T cub(T a){return a*a*a;}
int Ceil(int x, int y){return (x - 1) / y + 1;}




inline bool _1(int x, int i){return x & 1<<i;}
inline int _1(int i){return 1<<i;}
inline int _U(int i){return _1(i) - 1;};

inline int count_bits(int x){
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




inline void INC(int &a, int b){a += b; if (a >= MOD) a -= MOD;}
inline int sum(int a, int b){a += b; if (a >= MOD) a -= MOD; return a;}
inline void DEC(int &a, int b){a -= b; if (a < 0) a += MOD;}
inline int dff(int a, int b){a -= b; if (a < 0) a  += MOD; return a;}
inline void MUL(int &a, int b){a = int((LL)a * b % MOD);}
inline int pdt(int a, int b){return int((LL)a * b % MOD);}




struct Po; struct Line; struct Seg;

inline int sgn(DB x){return x < -EPS ? -1 : x > EPS;}
inline int sgn(DB x, DB y){return sgn(x - y);}

struct Po{
    DB x, y;
    Po(DB _x = 0, DB _y = 0):x(_x), y(_y){}

    friend istream& operator >>(istream& in, Po &p){return in >> p.x >> p.y;}
    friend ostream& operator <<(ostream& out, Po p){return out << "(" << p.x << ", " << p.y << ")";}

    friend bool operator ==(Po, Po);
    friend Po operator +(Po, Po);
    friend Po operator -(Po, Po);
    friend Po operator *(Po, DB);
    friend Po operator /(Po, DB);

    bool operator < (const Po &rhs) const{return sgn(x, rhs.x) < 0 || sgn(x, rhs.x) == 0 && sgn(y, rhs.y) < 0;}
    Po& operator +=(Po rhs){x += rhs.x, y += rhs.y;}
    Po& operator -=(Po rhs){x -= rhs.x, y -= rhs.y;}
    Po& operator *=(DB k){x *= k, y *= k;}
    Po& operator /=(DB k){x /= k, y /= k;}

    DB length_sqr(){return sqr(x) + sqr(y);}
    DB length(){return sqrt(length_sqr());}

    DB atan(){
        return atan2(y, x);
    }

    void input(){
        int _x, _y; scanf("%d %d", &_x, &_y);
        x = _x, y = _y;
    }
};

bool operator ==(Po a, Po b){return sgn(a.x - b.x) == 0 && sgn(a.y - b.y) == 0;}
Po operator +(Po a, Po b){return Po(a.x + b.x, a.y + b.y);}
Po operator -(Po a, Po b){return Po(a.x - b.x, a.y - b.y);}
Po operator *(Po a, DB k){return Po(a.x * k, a.y * k);}
Po operator /(Po a, DB k){return Po(a.x / k, a.y / k);}

struct Line{
    Po a, b;
    Line(Po _a = Po(), Po _b = Po()):a(_a), b(_b){}
    Line(DB x0, DB y0, DB x1, DB y1):a(Po(x0, y0)), b(Po(x1, y1)){}
    Line(Seg);
};

struct Seg{
    Po a, b;
    Seg(Po _a = Po(), Po _b = Po()):a(_a), b(_b){}
    Seg(DB x0, DB y0, DB x1, DB y1):a(Po(x0, y0)), b(Po(x1, y1)){}
    Seg(Line l);

    DB length(){return (b - a).length();}
};

Line::Line(Seg l):a(l.a), b(l.b){}
Seg::Seg(Line l):a(l.a), b(l.b){}







inline DB dot(DB x1, DB y1, DB x2, DB y2){return x1 * x2 + y1 * y2;}
inline DB dot(Po a, Po b){return dot(a.x, b.y, b.x, b.y);}
inline DB dot(Po p0, Po p1, Po p2){return dot(p1 - p0, p2 - p0);}
inline DB dot(Line l1, Line l2){return dot(l1.b - l1.a, l2.b - l2.a);}
inline DB det(DB x1, DB y1, DB x2, DB y2){return x1 * y2 - x2 * y1;}
inline DB det(Po a, Po b){return det(a.x, a.y, b.x, b.y);}
inline DB det(Po p0, Po p1, Po p2){return det(p1 - p0, p2 - p0);}
inline DB det(Line l1, Line l2){return det(l1.b - l1.a, l2.b - l2.a);}

template<class T1, class T2> inline DB dist(T1 x, T2 y){return sqrt(id0(x, y));}

inline DB id0(Po a, Po b){return sqr(a.x - b.x) + sqr(a.y - b.y);}
inline DB id0(Po p, Line l){Po v0 = l.b - l.a, v1 = p - l.a; return sqr(fabs(det(v0, v1))) / v0.length_sqr();}
inline DB id0(Po p, Seg l){
    Po v0 = l.b - l.a, v1 = p - l.a, v2 = p - l.b;
    if (sgn(dot(v0, v1)) * sgn(dot(v0, v2)) <= 0) return id0(p, Line(l));
    else return min(v1.length_sqr(), v2.length_sqr());
}

inline DB id0(Line l, Po p){
    return id0(p, l);
}

inline DB id0(Line l1, Line l2){
    if (sgn(det(l1, l2)) != 0) return 0;
    return id0(l1.a, l2);
}
inline DB id0(Line l1, Seg l2){
    Po v0 = l1.b - l1.a, v1 = l2.a - l1.a, v2 = l2.b - l1.a; DB c1 = det(v0, v1), c2 = det(v0, v2);
    return sgn(c1) != sgn(c2) ? 0 : sqr(min(fabs(c1), fabs(c2))) / v0.length_sqr();
}

inline DB id0(Seg l, Po p){
    return id0(p, l);
}

inline DB id0(Seg l1, Line l2){
    return id0(l2, l1);
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

inline DB id0(Seg l1, Seg l2){
    if (isIntersect(l1, l2)) return 0;
    else return min(id0(l1.a, l2), id0(l1.b, l2), id0(l2.a, l1), id0(l2.b, l1));
}

inline bool id1(const Po &p, const Seg &l){
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
    p.x -= o.x, p.y -= o.y;
    return Po(p.x * cos(alpha) - p.y * sin(alpha), p.y * cos(alpha) + p.x * sin(alpha)) + o;
}




template<class T> inline void RD(T &x){
    

    scanf("%d", &x);
    

    


}

const DB no_solution = -1;

int ____Case;
template<class T> inline void OT(const T &x){

    printf("Case %d: ", ++____Case);

    if (x == no_solution){
        puts("Impossible");
    }
    else {
        printf("%.2lf\n", x / PI * 180);
    }
}



const int N = 4009;




int f[N][N], t[N], d[N];
int n, m, ans;





int main(){
    RD(n, m); REP(i, n) RD(t[i], d[i]); t[n] = 86401;
    f[0][0] = t[0] + d[0], f[0][1] = 1, ans = t[m] - 1;

    FOR(i, 1, n) FOR_1(j, 0, min(m, i + 1)){
        f[i][j] = max(t[i], f[i-1][j]) + d[i];
        if (j) checkMin(f[i][j], f[i-1][j-1]);
        checkMax(ans, t[min(n, i+m-j) + 1] - f[i][j]);
    }

    cout << ans  << endl;
}

















