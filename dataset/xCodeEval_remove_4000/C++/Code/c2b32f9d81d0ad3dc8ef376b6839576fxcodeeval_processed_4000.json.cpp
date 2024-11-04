 


 
































using namespace std;























































	REP(i, n){		                            \
        REP(j, m) cout << A[i][j] << " ";       \
        cout << endl;				            \
	}						                    \
}


	id2(i, n){		                        \
        id2(j, m) cout << A[i][j] << " ";     \
		cout << endl;		            		\
	}						                    \
}





string id1(){
    string res = id3;
    int r = SZ(res) - 1; while (res[r] !=  '.') --r;
    int l = r - 1; while (res[l] != '\\') --l; ++l;
    return res.substr(l, r-l);
}

void Exec(string a, string b, string c){
    if (b.empty()) b = id1();
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





template<class T> inline T& RDD(T &x){
    char c; for (c = getchar(); c < '-'; c = getchar());
    if (c == '-'){x = '0' - getchar(); for (c = getchar(); '0' <= c && c <= '9'; c = getchar()) x = x * 10 + '0' - c;}
    else {x = c - '0'; for (c = getchar(); '0' <= c && c <= '9'; c = getchar()) x = x * 10 + c - '0';}
    return x;
}

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
template<class T0, class T1> inline void CLR(T0 &A0, T1 &A1){CLR(A0), CLR(A1);}
template<class T0, class T1, class T2> inline void CLR(T0 &A0, T1 &A1, T2 &A2){CLR(A0), CLR(A1), CLR(A2);}
template<class T0, class T1, class T2, class T3> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3){CLR(A0), CLR(A1), CLR(A2), CLR(A3);}
template<class T0, class T1, class T2, class T3, class T4> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4){CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5){CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4), CLR(A5);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6){CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4), CLR(A5), CLR(A6);}
template<class T> inline void CLR(T &A, int n){REP(i, n) CLR(A[i]);}

template<class T> inline bool EPT(T &a){return a.empty();}
template<class T> inline T& SRT(T &A){sort(ALL(A)); return A;}
template<class T> inline T& RVS(T &A){reverse(ALL(A)); return A;}
template<class T> inline T& UNQ(T &A){A.resize(unique(ALL(SRT(A)))-A.begin());return A;}

template<class T, class C> inline T& SRT(T &A, C B){sort(ALL(A), B); return A;}




 


const int MOD = int(1e9) + 7;


const int INF = 0x3f3f3f3f;
const LL INFF = 1LL << 60;
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
inline int ceil(int x, int y){return (x - 1) / y + 1;}
inline int sgn(DB x){return x < -EPS ? -1 : x > EPS;}
inline int sgn(DB x, DB y){return sgn(x - y);}

inline DB cot(DB x){return (DB)1/tan(x);};
inline DB sec(DB x){return (DB)1/cos(x);};
inline DB csc(DB x){return (DB)1/sin(x);};






 



namespace BIGNUM{

const int __base = 1e8;
const int P10[] = {1, 10, int(1e2), int(1e3), int(1e4), int(1e5), int(1e6), int(1e7), int(1e8), int(1e9)};
const int id8 = 109;
char __buf[id8];

class id4{
          friend istream& operator>>(istream&, id4&);
          friend ostream& operator<<(ostream&, const id4&);
          friend id4 operator +(const id4&, const id4&);
          friend id4 operator -(const id4&, const id4&);
          friend id4 operator *(const id4&, const id4&);
          friend id4 operator /(const id4&, const id4&);
          friend id4 operator %(const id4&, const id4&);
          friend id4 operator +(const id4&, const int&);
          friend id4 operator -(const id4&, const int&);
          friend id4 operator *(const id4&, const int&);
          friend id4 operator /(const id4&, const int&);
          friend id4 operator %(const id4&, const int&);
          friend bool operator ==(const id4&, const id4&);
          friend bool operator !=(const id4&, const id4&);
          friend bool operator <(const id4&, const id4&);
          friend bool operator >(const id4&, const id4&);
          friend bool operator <=(const id4&, const id4&);
          friend bool operator >=(const id4&, const id4&);
          friend bool operator ==(const id4&, const int&);
          friend bool operator !=(const id4&, const int&);
          friend bool operator <(const id4&, const int&);
          friend bool operator >(const id4&, const int&);
          friend bool operator <=(const id4&, const int&);
          friend bool operator >=(const id4&, const int&);
          friend int do_comp(const id4&, const int&);
          friend int do_comp(const id4&, const id4&);
          friend void divide(const id4&, const id4&, id4&, id4&);
          friend id4 pow(id4, int);
          friend id4 pow(int, int);
    public:
        inline id4(){};
        inline id4(int s){
            while (s) data.PB(s%__base), s/=__base;
            if (data.empty()) data.PB(0);
        }

        inline id4(long long s){
            while (s) data.PB(int(s%__base)), s/=__base;
            if (data.empty()) data.PB(0);
        }

        inline id4(string s){
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
        void operator =(const id4);
        id4& operator +=(const id4&);
        id4& operator -=(const id4&);
        id4& operator *=(const id4&);
        id4& operator /=(const id4&);
        id4& operator %=(const id4&);
        id4& operator +=(const int&);
        id4& operator -=(const int&);
        id4& operator *=(const int&);
        id4& operator /=(const int&);
        id4& operator %=(const int&);
        bool undefined();
        int do_try(const int&);
        int do_try(const id4&);
        void do_trim();
        list<int> data;

    int size(){
        list<int>::iterator it; int res = 0;
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
        list<int>::iterator it;
        for (it=data.begin(); it!=data.end() && a>0; it++) a-=8;
        if (it == data.end() && a>=0) return;
        a+=8, it--; int f = 1;
        for (int i=0;i<a;i++) f *= 10; (*it) %= f;
        data.erase(++it, data.end());
        do_trim();
    }
};

inline void id4::operator =(const id4 a){
    data.clear();
    for (list<int>::const_iterator i=a.data.begin();i!=a.data.end();i++){
        data.PB(*i);
    }
}
inline void id4::operator =(const string a){
    (*this) = id4(a);
}
inline void id4::operator =(const int a){
    (*this) = id4(a);
}

inline istream& operator>>(istream& input, id4& a){
    string s; int t, i; input >> s; a.data.clear();
    for (i=int(s.size())-8;i>0;i-=8){
        istringstream(s.substr(i, 8)) >> t;
        a.data.PB(t);
    }
    istringstream(s.substr(0, i+8)) >> t;
    a.data.PB(t);
    return input;
}

inline ostream& operator<<(ostream& output, const id4& a){
    list<int>::const_reverse_iterator i=a.data.rbegin();
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

inline bool id4::undefined(){
    return data.empty();
}

inline int do_comp(const id4& a, const id4& b){
    if (a.data.size()<b.data.size()) return -1; if (a.data.size()>b.data.size()) return 1;
    list<int>::const_reverse_iterator i; list<int>::const_reverse_iterator j;
    for (i=a.data.rbegin(),j=b.data.rbegin(); j!=b.data.rend(); i++,j++){
        if (*i<*j) return -1;              

        if (*i>*j) return 1;
    }
    return 0;
}
inline int do_comp(const id4& a, const int& b){
    return do_comp(a, id4(b));
}

inline bool operator ==(const id4& a, const id4& b){
    return do_comp(a, b) == 0;
}
inline bool operator !=(const id4& a, const id4& b){
    return do_comp(a, b) != 0;
}
inline bool operator <(const id4& a, const id4& b){
    return do_comp(a, b) == -1;
}
inline bool operator >(const id4& a, const id4& b){
    return do_comp(a, b) == 1;
}
inline bool operator <=(const id4& a, const id4& b){
    return do_comp(a, b) != 1;
}
inline bool operator >=(const id4& a, const id4& b){
    return do_comp(a, b) != -1;
}

inline bool operator ==(const id4& a, const int& b){
    return do_comp(a, b) == 0;
}
inline bool operator !=(const id4& a, const int& b){
    return do_comp(a, b) != 0;
}
inline bool operator <(const id4& a, const int& b){
    return do_comp(a, b) == -1;
}
inline bool operator >(const id4& a, const int& b){
    return do_comp(a, b) == 1;
}
inline bool operator <=(const id4& a, const int& b){
    return do_comp(a, b) != 1;
}
inline bool operator >=(const id4& a, const int& b){
    return do_comp(a, b) != -1;
}

inline void id4::do_trim(){
    while (data.size()>1&&data.back()==0) data.pop_back();
}

inline id4& id4::operator +=(const id4& a){
    list<int>::iterator i; list<int>::const_iterator j; int t = 0;
    for (i=data.begin(),j=a.data.begin(); i!=data.end()&&j!=a.data.end(); i++,j++){
        *i+=*j+t; t=*i/__base; *i%=__base;
    }
    while (i!=data.end()) {*i+=t; t=*i/__base; *i%=__base; i++;}
    while (j!=a.data.end()) {data.PB(t+*j); t=data.back()/__base; data.back()%=__base; j++;}
    if (t!=0) data.PB(t);
    return *this;
}

inline id4& id4::operator -=(const id4& a){
    list<int>::iterator i; list<int>::const_iterator j; int t = 0;
    for (i=data.begin(),j=a.data.begin(); j!=a.data.end(); i++,j++){
        *i -= t+*j; if (*i>=0) t=0; else *i+=__base, t=1;
    }
    while (i!=data.end()) {*i-=t; if (*i>=0) t=0;else *i+=__base, t=1; i++;}
    (*this).do_trim();
    return *this;
}

inline id4& id4::operator +=(const int& a){
    return (*this)+=id4(a);
}

inline id4& id4::operator -=(const int& a){
    return (*this)-=id4(a);
}

inline id4 operator +(const id4& a, const id4& b){
    list<int>::const_iterator i, j; id4 c; int t = 0;
    for (i=a.data.begin(),j=b.data.begin(); i!=a.data.end()&&j!=b.data.end(); i++,j++){
        c.data.PB(t+*i+*j);
        t=c.data.back()/__base; c.data.back()%=__base;
    }
    while (i!=a.data.end()) {c.data.PB(t+*i); t=c.data.back()/__base; c.data.back()%=__base; i++;}
    while (j!=b.data.end()) {c.data.PB(t+*j); t=c.data.back()/__base; c.data.back()%=__base; j++;}
    if (t!=0) c.data.PB(t);
    return c;
}

inline id4 operator -(const id4& a, const id4& b){
    list<int>::const_iterator i, j; id4 c; int t = 0;
    for (i=a.data.begin(),j=b.data.begin(); j!=b.data.end(); i++,j++){
        t = *i - t;
        if (t>=*j) c.data.PB(t-*j), t=0;
        else c.data.PB(t+__base-*j), t=1;
    }
    while (i!=a.data.end()) {t=*i-t; if (t>=0) c.data.PB(t), t=0;else c.data.PB(t+__base), t=1; i++;}
    c.do_trim();
    return c;
}

inline id4 operator *(const id4& a, const id4& b){
    list<int>::const_iterator i, j; list<int>::iterator k, kk; id4 c; long long t = 0;

    for (int i=0;i<a.data.size()+b.data.size();i++) c.data.PB(0);
    for (i=a.data.begin(),k=c.data.begin(); i!=a.data.end(); i++,k++){
        for (j=b.data.begin(),kk=k; j!=b.data.end(); j++,kk++){
            t+=(long long)(*i)*(*j)+(*kk);
            *kk=int(t%__base); t/=__base;
        }
        *kk+=t; t=0;
    }
    c.do_trim();
    return c;
}

inline int id4::do_try(const id4& a){
    int l = 1, r = 99999999, m, t;
    while (l+2<r){
        m = (l + r) / 2;
        t = do_comp(*this, a*id4(m));
        if (t==0) return m;
        if (t<0) r = m - 1;
        else l = m;
    }
    while (do_comp(*this, a*id4(r))<0) r--;
    return r;
}

inline void divide(const id4& a, const id4& b, id4& d, id4& r){
    list<int>::const_reverse_iterator i = a.data.rbegin(); int t;
    d = id4(0); r = id4(0);
    do {
        while (r<b&&i!=a.data.rend()){d.data.push_front(0);r.data.push_front(*i);r.do_trim();i++;}
        if (r>=b){
            t = r.do_try(b); d.data.front() = t;
            r-=(b*id4(t));
        }
    } while (i!=a.data.rend());
    d.do_trim();
}

inline id4 operator /(const id4& a, const id4& b){
    id4 d, r;
    divide(a, b, d, r);
    return d;
}

inline id4 operator %(const id4& a, const id4& b){
    id4 d, r;
    divide(a, b, d, r);
    return r;
}

inline id4 operator +(const id4& a, const int& b){
    return a+id4(b);
}

inline id4 operator -(const id4& a, const int& b){
    return a-id4(b);
}

inline id4 operator *(const id4& a, const int& b){
    return a*id4(b);
}

inline id4 operator /(const id4& a, const int& b){
    return a/id4(b);
}

inline id4 operator %(const id4& a, const int& b){
    return a%id4(b);
}

inline id4& id4::operator *=(const id4& a){
    (*this) = (*this) * a;
    return *this;
}

inline id4& id4::operator /=(const id4& a){
    (*this) = (*this) / a;
    return *this;
}

inline id4& id4::operator %=(const id4& a){
    (*this) = (*this) % a;
    return *this;
}

inline id4& id4::operator *=(const int& a){
    return (*this)*=id4(a);
}

inline id4& id4::operator /=(const int& a){
    return (*this)/=id4(a);
}

inline id4& id4::operator %=(const int& a){
    return (*this)%=id4(a);
}

inline id4 pow(id4 a,int b){
    id4 c(1);
    while (b!=0) {
        if (b&1) c *= a;
        a = a * a; b >>= 1;
    }
    return c;
}
inline id4 pow(int a, int b){
    return pow(id4(a), b);
}

} using namespace BIGNUM;





 

template<class T> inline T& RD(T &x){
    

    

    char c; for (c = getchar(); c < '0'; c = getchar()); x = c - '0'; for (c = getchar(); '0' <= c && c <= '9'; c = getchar()) x = x * 10 + c - '0';
    

    return x;
}

inline DB& RF(DB &x){
    

    scanf("%lf", &x);
    
    return x;
}

inline char* RS(char *s){
    

    scanf("%s", s);
    return s;
}

LL last_ans; int Case; template<class T> inline void OT(const T &x){
    

    

    printf("%.9lf\n", x);
    

    

}






const int _N = 409;
int x[_N], y[_N];



const int N = 1099, M = int(1e6) + 9;

typedef DB cost_t;
typedef int flow_t;
const cost_t DOO = OO; cost_t D[N];
int hd[N], suc[M], to[M]; flow_t cap[M]; cost_t cst[M];
int n, m, s, t; flow_t flow; cost_t cost; int mask = 1023;

inline void add_edge(int x, int y, flow_t c, cost_t w){
    suc[m] = hd[x], to[m] = y, cap[m] = c, cst[m] =  w, hd[x] = m++;
    suc[m] = hd[y], to[m] = x, cap[m] = 0, cst[m] = -w, hd[y] = m++;
}

inline void id9(int x, int y, int c, int w){
    
        add_edge(x, y, c, w);
        add_edge(y, x, c, w);
    

}

int Q[N], pre[N], cz, op;
bool inQ[N]; cost_t H[N];







void id0(int u, int i){
    if (c && D[v] > D[u] + ww){
        D[v] = D[u] + ww, pre[v] = i;
        if (!inQ[v]) Q[op++ & mask] = v, inQ[v] = 1;
    }
}


bool id5(){
    cz = 0, op = 1; fill(inQ, inQ + n, 0), fill(D, D + n, DOO);
    D[Q[cz] = s] = 0; while (cz < op){
        int u = Q[cz++ & mask]; inQ[u] = 0;
        REP_G(i, u) id0(u, i);
    }
    return D[t] != DOO;
}

priority_queue<pair<cost_t, int>, vector<pair<cost_t, int> >, greater<pair<cost_t, int> > > QQ;

void id7(int u, int i){
    if (c && D[v] > D[u] + ww){
        D[v] = D[u] + ww, pre[v] = i;
        QQ.push(MP(D[v], v));
    }
}

bool dijkstra(){

    CLR(QQ); fill(inQ, inQ + n, 0), fill(D, D + n, DOO), QQ.push(MP(D[s] = 0, s));

    while(!EPT(QQ)){
        int u = QQ.top().se; QQ.pop(); if (inQ[u]) continue; inQ[u] = 1;
        

        REP_G(i, u) if (!inQ[v]) id7(u, i);
    }

    return inQ[t];
}


void add_path(){


    flow_t d = INF; for (int u=t;u!=s;u=to[pre[u]^1]){
        checkMin(d, c);
    }

    

    


    flow += d;

    for (int u=t;u!=s;u=to[i^1]){
        f += d, c -= d, cost += d*w;
    }


    REP(i, n) H[i] += D[i];
}

pair<cost_t, flow_t> id6(){

    to[m] = s;
    fill(H, H + n, 0);
    flow = 0, cost = 0;

    while (dijkstra()){
        add_path();
    }

    return MP(cost, flow);
}







DB dist(int a, int b){
    return sqrt(sqr(x[a]-x[b]) + sqr(y[a]-y[b]));
}

int main(){


    freopen("in.txt", "r", stdin);
    




    int n; RD(n); t = 2 * n + 1; ::n = t + 1; m = 2;

    id2(i, n){
        add_edge(s, i, 2, 0);
        add_edge(i+n, t, 1, 0);
        RDD(x[i], y[i]);
    }

    REP_2_1(i, j, n, n) if (y[i] > y[j]){
        add_edge(i, j+n, 1, dist(i, j));
    }

    pair<DB, int> res = id6();
    if (res.se != n-1) puts("-1");
    else OT(res.fi);
}
