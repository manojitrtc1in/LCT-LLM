 


 





































using namespace std;


























































  REP(i, n){		                            \
        REP(j, m-1) cout << A[i][j] << " ";     \
        cout << A[i][m-1] << endl;		        \
	}						                    \
}

	id5(i, n){		                        \
        id5(j, m-1) cout << A[i][j] << " ";   \
        cout << A[i][m] << endl;		        \
	}						                    \
}

string id3(){
    string res = id7;
    int r = SZ(res) - 1; while (res[r] !=  '.') --r;
    int l = r - 1; while (res[l] != '\\') --l; ++l;
    return res.substr(l, r-l);
}

void Exec(string a, string b, string c){
    if (b.empty()) b = id3();
    string cmd = a + ' ' + b + '.' + c;
    system(cmd.c_str());
}

void Ruby(string file = ""){Exec("ruby", file, "rb");}
void Python(string file = ""){Exec("python", file, "py");}
void Haskell(string file = ""){Exec("runghc", file, "hs");}
void Pascal(string file = ""){Exec("pascal", file, "pas");}
void Ocaml(string file = ""){Exec("ocaml", file, "ml");}

typedef long long LL;


typedef double DB;
typedef unsigned UINT;
typedef unsigned long long ULL;

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





 


const int MOD = int(1e9) + 7;


const int INF = 0x3f3f3f3f;
const LL INFF = 0x3f3f3f3f3f3f3f3fLL;
const DB EPS = 1e-9;
const DB OO = 1e20;
const DB PI = acos(-1.0); 


const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};




 



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
inline int sgn(DB x){return x < -EPS ? -1 : x > EPS;}
inline int sgn(DB x, DB y){return sgn(x - y);}

inline DB cos(DB a, DB b, DB c){return (sqr(a)+sqr(b)-sqr(c))/(2*a*b);}
inline DB cot(DB x){return 1./tan(x);};
inline DB sec(DB x){return 1./cos(x);};
inline DB csc(DB x){return 1./sin(x);};





namespace CG{

struct Po; struct Line; struct Seg;
typedef const Po&cPo; typedef const Line&cLine; typedef const Seg&cSeg;
typedef vector<Po> VP;

struct Po{
    DB x,y;Po(DB x=0,DB y=0):x(x),y(y){}

    void input(){RF(x,y);}void output(){printf("(%.2f,%.2f)",x,y);}
    inline friend istream&operator>>(istream&i,Po&p){return i>>p.x>>p.y;}
    inline friend ostream&operator<<(ostream&o,Po p){return o<<"("<<p.x<<", "<<p.y<< ")";}

    Po operator-()const{return Po(-x,-y);}
    Po&operator+=(cPo p){x+=p.x,y+=p.y;rTs;}Po&operator-=(cPo p){x-=p.x,y-=p.y;rTs;}
    Po&operator*=(DB k){x*=k,y*=k;rTs;}Po&operator/=(DB k){x/=k,y/=k;rTs;}
    Po operator+(cPo p)const{return Po(x+p.x,y+p.y);}Po operator-(cPo p)const{return Po(x-p.x,y-p.y);}
    Po operator*(DB k)const{return Po(x*k,y*k);}Po operator/(DB k)const{return Po(x/k,y/k);}
    Po operator*(cPo p)const{return Po(x*p.x-y*p.y,y*p.x+x*p.y);}Po operator/(cPo p)const{return Po(x*p.x+y*p.y,y*p.x-x*p.y)/p.len2();}

    bool operator==(cPo p)const{return!sgn(x,p.x)&&!sgn(y,p.y);};bool operator!=(cPo p)const{return sgn(x,p.x)||sgn(y,p.y);}
    bool operator<(cPo p)const{return sgn(x,p.x)<0||!sgn(x,p.x)&&sgn(y,p.y)<0;}bool operator<=(cPo p)const{return sgn(x,p.x)<0||!sgn(x,p.x)&&sgn(y,p.y)<=0;}
    bool operator>(cPo p)const{return!(*this<=p);}bool operator >=(cPo p)const{return!(*this<p);}

    DB len2()const{return sqr(x)+sqr(y);}DB len()const{return sqrt(len2());}DB arg()const{return atan2(y,x);}
    Po&unit(){rTs/=len();}Po&conj(){y=-y;rTs;}Po&lt(){swap(x,y),x=-x;rTs;}Po&rt(){swap(x,y),y=-y;rTs;}
    Po&rot(DB a,cPo o=Po()){x-=o.x,y-=o.y;rTs=Po(x*cos(a)-y*sin(a),y*cos(a)+x*sin(a))+o;}
};

inline DB dot(const DB &x1, const DB &y1, const DB &x2, const DB &y2){return x1 * x2 + y1 * y2;}
inline DB dot(const Po &a, const Po &b){return dot(a.x, a.y, b.x, b.y);}
inline DB dot(const Po &p0, const Po &p1, const Po &p2){return dot(p1 - p0, p2 - p0);}
inline DB det(const DB &x1, const DB &y1, const DB &x2, const DB &y2){return x1 * y2 - x2 * y1;}
inline DB det(const Po &a, const Po &b){return det(a.x, a.y, b.x, b.y);}
inline DB det(const Po &p0, const Po &p1, const Po &p2){return det(p1 - p0, p2 - p0);}
inline DB ang(cPo p0,cPo p1){return acos(dot(p0,p1)/p0.len()/p1.len());}
inline DB ang(cPo p0,cPo p1,cPo p2){return ang(p1-p0,p2-p0);}
inline DB ang(cPo p0,cPo p1,cPo p2,cPo p3){return ang(p1-p0,p3-p2);}
inline DB dist2(const DB &x, const DB &y){return sqr(x) + sqr(y);}
inline DB dist2(const DB &x, const DB &y, const DB &z){return sqr(x) + sqr(y) + sqr(z);}
inline DB dist2(const Po &a, const Po &b){return dist2(a.x - b.x, a.y - b.y);}
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
inline Po unit(Po p){return p.unit();}inline Po conj(Po p){return p.conj();}
inline Po lt(Po p){return p.lt();}inline Po rt(Po p){return p.rt();}
inline Po rot(Po p,DB a,cPo o=Po()){return p.rot(a,o);}
inline Po operator *(DB k,cPo p){return p*k;}
inline Po operator /(DB k,cPo p){return conj(p)*k/p.len2();}

struct Line{
    Po a,b;Line(cPo a=Po(),cPo b=Po()):a(a),b(b){}
    Line(DB x0,DB y0,DB x1,DB y1):a(Po(x0,y0)),b(Po(x1,y1)){}
    Line(cLine l):a(l.a),b(l.b){}

    

    Line(DB A,DB B,DB C){
        C=-C;if(!::sgn(A))a=Po(0,C/B),b=Po(1,C/B);
        else if(!::sgn(B))a=Po(C/A,0),b=Po(C/A,1);
        else a=Po(0,C/B),b=Po(1,(C-A)/B);
    }

    void input(){a.input(),b.input();}
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

        Po v=d().unit().lt()*r;a+=v,b+=v; rTs;
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

inline int Line::sgn(cLine l)const{return dett(*this, l);}
inline Po Line::operator*(cLine l)const{return a+d()*det(a,l)/det(*this,l);}
inline Po operator&(cPo p,cLine l){return l*Line(p,p+l.d().lt());}
inline Po operator%(cPo p,cLine l){return p&l*2-p;}

struct Seg: public Line{
    Seg(cPo a=Po(),cPo b=Po()):Line(a,b){}
    Seg(DB x0,DB y0,DB x1,DB y1):Line(x0,y0,x1,y1){}
    Seg(cLine l):Line(l){}
    Seg(const Po &a,DB alpha):Line(a,alpha){}
    Seg(DB A,DB B,DB C):Line(A,B,C){}

    inline int sgn(cPo p)const;
    inline bool qrt(cSeg l)const;
    inline int sgn(cSeg l)const;
};



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

inline int Seg::sgn(cPo p)const{return -dott(p,a,b);}

inline DB dist2(cLine l,cPo p){return sqr(fabs(det(l.d(), p-l.a)))/l.len2();}
inline DB dist2(cLine l1,cLine l2){return dett(l1,l2)?0:dist2(l1,l2.a);}
inline DB dist2(cSeg l,cPo p){
    Po v0 = l.b - l.a, v1 = p - l.a, v2 = p - l.b;
    if (sgn(dot(v0, v1)) * sgn(dot(v0, v2)) <= 0) return dist2(Line(l),p);
    else return min(v1.len2(), v2.len2());
}
inline DB dist2(cSeg l1,cLine l2){
    Po v0 = l2.b-l2.a, v1=l1.a-l2.a,v2=l1.b-l2.a;DB c1=det(v0,v1),c2=det(v0,v2);
    return sgn(c1)!=sgn(c2) ? 0 : sqr(min(fabs(c1), fabs(c2)))/v0.len2();
}
inline DB dist2(cSeg l1,cSeg l2){
    if (l1.sgn(l2)) return 0;
    else return min(dist2(l2,l1.a), dist2(l2,l1.b), dist2(l1,l2.a), dist2(l1,l2.b));
}

struct Triangle; struct Circle;

const int Disjoint = -2, Exscribe = -1, Cross = 0, Inscribe = 1, Contain = 2;

Po id8(cPo a, cPo b, cPo c){
    Po v0 = b-a, v1 = c-a; DB s0 = v0.len2(), s1 = v1.len2(), d = det(v0, v1);
    return Po(s0*v1.y-s1*v0.y, s1*v0.x-s0*v1.x)/d + a;
    

    

}

Po id9(cPo a, cPo b, cPo c){
    return Line(a,Line(b,c)*a)*Line(b,Line(a,c)*b);
}

struct Circle{
    Po o; DB r; Circle(cPo o=Po(),DB r=0):o(o),r(r){}
    


    Circle(cPo a,cPo b){
        o = (a+b)/2, r = dist(a,b)/2;
    }
    Circle(cPo a,cPo b,cPo c){
        o = id8(a,b,c), r = dist(o,a);
    }
    void input(){RF(o.x, o.y, r);}
    void output(){
        printf("%.2f %.2f %.2f\n", o.x, o.y, r);
    }
    bool operator <(const Circle&c)const{return r<c.r;}
    

    inline int sgn(cPo p)const{return ::sgn(r*r, dist2(o, p));}
    

    inline int sgn(cLine l)const{return ::sgn(r*r, dist2(l, o));}
    

    inline int sgn(const Circle&c)const{
        DB d=dist2(o,c.o);
        if (::sgn(sqr(r+c.r),d)<0) return Disjoint;
        if (!::sgn(sqr(r+c.r), d)) return Exscribe;
        if (!::sgn(sqr(r-c.r), d)) return Inscribe;
        if (::sgn(sqr(r-c.r), d)>0) return Contain;
        return Cross;
    }

    inline DB s(){return PI*sqr(r);}
    inline DB p(){return 2*PI*r;}

    inline Po operator^(const Circle&c)const{return Po(det(Po(o.x,r),Po(c.o.x,c.r)),det(Po(o.y,r),Po(c.o.y,c.r)))/(c.r-r);}

    inline void getIntersect(cLine l,Po&p0,Po&p1)const{
        Po m = o&l, d = (l.b-l.a).unit() * sqrt(sqr(r)-dist2(l, o));
        p0 = m + d, p1 = m - d;
    }
    inline void getTangency(cPo p,Po&p0,Po&p1)const{
        DB d = dist(o,p),a=acos(r/d); Po op=(p-o).unit()*r;
        p0=o+rot(op,a), p1=o+rot(op,-a);
    }
    inline void getTangency(const Circle&c,Po&p0,Po&p1,Po&p2,Po&p3)const{
        if (!::sgn(r,c.r)){Po d=(o-c.o).lt().unit()*r;p0=o+d,p1=o-d,p2=c.o+d,p3=c.o-d;}
        else{Po p=(*this)^c; getTangency(p,p0,p1), c.getTangency(p,p2,p3);}
    }
    inline DB arc(cPo a, cPo b){
        DB alpha = acos(cos(dist(a, o), dist(b, o), dist(a, b)));
        if (det(o,a,b)<0) alpha = 2*PI - alpha;
        return alpha * r;
    }
};

struct Triangle{
    Po A,B,C; DB a,b,c; DB alpha,beta,theta;
    DB r,R; DB S,P; Po I,G,O,H;

    void init(){
        a=dist(B,C),b=dist(a,c),c=dist(a,b);
        alpha=acos(cos(b,c,a)),beta=acos(cos(a,c,b)),theta=acos(cos(a,b,c));
        P=a+b+c; DB s=P/2; S=sqrt(s*(s-a)*(s-b)*(s-c));
        R=(a*b*c)/(4*S),r=2*S/P;
        I = Po(a*A.x+b*B.x+c*C.x,a*A.y+b*B.y+c*C.y)/P; G = (A+B+C)/3;
        O = id8(A,B,C), H = id9(A,B,C);
        assert(!sgn(dist(I,O), sqrt(R*(R-2*r))));
        assert(!sgn(dist(H,G), dist(O,H)*2/3));
    }

    void input(){
        A.input(),B.input(),C.input();init();
    }
};

Po getPo(){Po p;p.input();return p;}
Line getLine(){Line l;l.input();return l;}

DB getArea(const VP& P){DB z=0;FOR(i,1,SZ(P))z+=det(P[i-1],P[i]);return z;}
DB id10(const VP& P){DB z=0;FOR(i,1,SZ(P))z+=dist(P[i-1],P[i]);return z;}


VP id0(VP& P){ 


    int n=SZ(P);if(n<=3)return P.PB(P[0]),P;

    SRT(P); VP C; C.resize(n+9); int nn = -1; REP(i, n){ 

        while (nn > 0 && dett(C[nn-1], C[nn], P[i]) <= 0) --nn; 

        C[++nn] = P[i];
    }

    int _nn = nn; DWN(i, n-1, 0){
        while (nn > _nn && dett(C[nn-1], C[nn], P[i]) <= 0) --nn; 

        C[++nn] = P[i];
    }

    C.resize(nn+1);
    return C;
}

const int id1 = 109;

bool id4(cLine l,cLine r){
    int t = sgn(l.arg(), r.arg()); if (!t) t = dett(r.a,l);
    return t < 0;
}

Line Q[id1]; int cz, op;

void cut_b(cLine l){while(cz<op&&dett(l,Q[op]*Q[op-1])<0)--op;}
void cut_f(cLine l){while(cz<op&&dett(l,Q[cz]*Q[cz+1])<0)++cz;}
void cut(cLine l){cut_b(l),cut_f(l),Q[++op]=l;}

VP id2(vector<Line>&L){
    SRT(L, id4); int n = 1; FOR(i, 1, SZ(L)) if (sgn(L[i-1].arg(), L[i].arg())) L[n++] = L[i];
    VP P; cz = 0, op = 1, Q[0] = L[0], Q[1] = L[1]; FOR(i, 2, n){
        if (!dett(Q[op],Q[op-1])||!dett(Q[cz],Q[cz+1])) return P;
        cut(L[i]);
    }
    cut_b(Q[cz]);cut_f(Q[op]);

    if (op <= cz+1) return P;
    for (int i=cz;i<op;++i) P.PB(Q[i]*Q[i+1]);
    if (cz<op+1) P.PB(Q[cz]*Q[op]);
    UNQQ(P).PB(P[0]);
    return P;
}

Circle id6(VP& P){ 

    random_shuffle(ALL(P)); int n = SZ(P);
    Circle C(P[0]); FOR(i, 1, n) if (!~C.sgn(P[i])){
        C = Circle(P[i]); REP(j, i) if (!~C.sgn(P[j])){
            C = Circle(P[i], P[j]); REP(k, j) if (!~C.sgn(P[k])){
                C = Circle(P[i], P[j], P[k]);
            }
        }
    }
    return C;
}

struct Polygon{
    VP P;
    void input();
};

inline bool equal(const pair<DB, DB>& lhs, cSeg  rhs){
    DB k, b; rhs.getEquation(k, b);
    return !sgn(k, lhs.fi) && !sgn(b, lhs.se);
}

DB getUnion(vector<Polygon>& P, vector<Seg>& S){

    vector<pair<DB,DB> > L; ECH(Si, S){
        DB k, b; Si->getEquation(k, b);
        L.PB(MP(k, b));
    }

    UNQ(L); DB res = 0; ECH(Li, L){

        vector<pair<DB, int> > I;
        Line l0(0,Li->se,1,Li->fi+Li->se);

        ECH(Pi, P){
            int i; FOR_N(i, 1, SZ(Pi->P)) if (equal(*Li, Seg(Pi->P[i-1], Pi->P[i]))) break;
            if (i != SZ(Pi->P)) continue;

            VP cut; FOR_N(i, 1, SZ(Pi->P)){
                Seg l1(Pi->P[i-1], Pi->P[i]); if (!dett(l0,l1)) continue;
                Po p=l0*l1; if (~l1.sgn(p)) cut.PB(p);
            }

            if (SZ(UNQ(cut)) == 2){
                I.PB(MP(cut[0].x, 1));
                I.PB(MP(cut[1].x, -1));
            }
        }

        ECH(Si, S) if (equal(*Li, *Si)){
            I.PB(MP(min(Si->a.x, Si->b.x), 2));
            I.PB(MP(max(Si->a.x, Si->b.x), -2));
        }



        SRT(I); int c0 = 0, c1 = 0; REP(i, SZ(I)){
            if (!c0 && c1) res += (y0+y1)*h;
            if (abs(I[i].se)==1) c0 += I[i].se;
            else c1 += I[i].se;
        }



    }

    return res;
}

DB getUnion(vector<Polygon>& P){
    vector<Seg> up, down; ECH(it, P){
        FOR(i, 1, SZ(it->P)){
            Seg s(it->P[i-1], it->P[i]); int t = sgn(s.a.x, s.b.x);
            if (t > 0) up.PB(s); else if (t < 0) down.PB(s);
        }
    }
    return getUnion(P, up) - getUnion(P, down);
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
    printf("Case %d: ", ++Case);
    

     printf("%.2f\n", x/PI * 180);
    

    

    

}






const int N = int(1e5) + 9;

char buf[N]; int A[N], B[N];
void init(int A[]){
    RST(A); RS(buf); int n = strlen(buf);
    REP(i, n) A[n-i-1] = buf[i] == '1';
}

char gao(){

    DWN(i, N, 0){
        int d = min(A[i], B[i]);
        A[i] -= d, B[i] -= d;

        if (A[i] >= 2) return '>';
        if (B[i] >= 2) return '<';

        if (A[i] == 1){
            if (i-2<0) return '>';
            ++A[i-1],++A[i-2];
        }
        else if (B[i] == 1){
            if (i-2<0) return '<';
            ++B[i-1],++B[i-2];
        }
    }
    return '=';
}


int main(){


    freopen("in.txt", "r", stdin);
    



    init(A), init(B);
    cout << gao() << endl;
}
