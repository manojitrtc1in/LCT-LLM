






















using namespace std;





















































	REP(i, n){		                          \
        REP(j, m) cout << A[i][j] << " ";\
		cout << endl;				\
	}						\
}


	id1(i, n){		\
        id1(j, m) cout << A[i][j] << " ";\
		cout << endl;				\
	}						\
}



typedef long long LL;
typedef double DB;
typedef long double LDB;
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
typedef pair<DB, int> PDI;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef vector<VII> VVII;
typedef set<PII> SII;
typedef map<PII, int> MPIII;
typedef map<PII, bool> MPIIB;





template<class T> inline void RD(T &);
template<class T> inline void OT(const T &);


template<class T> inline T& _RD(T &x){ RD(x); return x;}
inline int RD(){int x; return _RD(x);}
inline void RF(DB &x){scanf("%lf", &x);}
inline DB _RF(DB &x){scanf("%lf", &x); return x;}
inline DB RF(){ DB x; return _RF(x);}
inline void RC(char &c){scanf(" %c", &c);}
inline char _RC(char &c){scanf(" %c", &c); return c;}
inline char RC(){ char c; return _RC(c);}
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
const LL id0 = 0x3f3f3f3f3f3f3f3fLL;
const DB EPS = 1e-8;
const DB OO = 1e15;
const DB PI = acos(-1.0); 





template<class T> inline void checkMin(T &a,const T b){if (b<a) a=b;}
template<class T> inline void checkMax(T &a,const T b){if (b>a) a=b;}
template <class T, class C> inline void checkMin(T& a, const T b, C c){if (c(b,a)) a = b;}
template <class T, class C> inline void checkMax(T& a, const T b, C c){if (c(a,b)) a = b;}

template<class T> inline T min(T a, T b, T c){return min(min(a, b), c);}
template<class T> inline T max(T a, T b, T c){return max(max(a, b), c);}
template<class T> inline T min(T a, T b, T c, T d){return min(min(a, b), min(c, d));}
template<class T> inline T max(T a, T b, T c, T d){return max(min(a, b), max(c, d));}
template<class T, class C> inline T min_cp(T a, T b, C cp){return min(a, b, cp);}
template<class T, class C> inline T min_cp(T a, T b, T c, C cp){return min_cp(min_cp(a, b, cp), c, cp);}
template<class T, class C> inline T min_cp(T a, T b, T c, T d, C cp){return min_cp(min_cp(a, b, cp), min_cp(c, d, cp), cp);}
template<class T, class C> inline T max_cp(T a, T b, C cp){return max(a, b, cp);}
template<class T, class C> inline T max_cp(T a, T b, T c, C cp){return max_cp(max_cp(a, b, cp), c, cp);}
template<class T, class C> inline T max_cp(T a, T b, T c, T d, C cp){return max_cp(max_cp(a, b, cp), max_cp(c, d, cp), cp);}

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

template<class T> inline T cover_bit(T x){
    T p = 1; while (p < x) p <<= 1;
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






using namespace std;

class id2{
          friend istream& operator>>(istream&, id2&);
          friend ostream& operator<<(ostream&, const id2&);
          friend id2 operator +(const id2&, const id2&);
          friend id2 operator -(const id2&, const id2&);
          friend id2 operator *(const id2&, const id2&);
          friend id2 operator /(const id2&, const id2&);
          friend id2 operator %(const id2&, const id2&);
          friend id2 operator +(const id2&, const int&);
          friend id2 operator -(const id2&, const int&);
          friend id2 operator *(const id2&, const int&);
          friend id2 operator /(const id2&, const int&);
          friend id2 operator %(const id2&, const int&);
          friend bool operator ==(const id2&, const id2&);
          friend bool operator !=(const id2&, const id2&);
          friend bool operator <(const id2&, const id2&);
          friend bool operator >(const id2&, const id2&);
          friend bool operator <=(const id2&, const id2&);
          friend bool operator >=(const id2&, const id2&);
          friend bool operator ==(const id2&, const int&);
          friend bool operator !=(const id2&, const int&);
          friend bool operator <(const id2&, const int&);
          friend bool operator >(const id2&, const int&);
          friend bool operator <=(const id2&, const int&);
          friend bool operator >=(const id2&, const int&);
          friend int do_comp(const id2&, const int&);
          friend int do_comp(const id2&, const id2&);
          friend void divide(const id2&, const id2&, id2&, id2&);
          friend id2 pow(id2, int);
    public:
        inline id2(){};
        inline id2(int s){
            while (s!=0){
                data.push_back(s%100000000); s/=100000000;
            }
            if (data.empty()) data.push_back(0);
        }
    inline id2(long long s){
        while (s!=0){
            data.push_back(int(s%100000000)); s/=100000000;
        }
        if (data.empty()) data.push_back(0);
    }
        inline id2(string s){
            int t, i; data.clear();
            for (i=int(s.size())-8;i>0;i-=8){
                istringstream(s.substr(i, 8)) >> t;
                data.push_back(t);
            }
            istringstream(s.substr(0, i+8)) >> t;
            data.push_back(t);
        }
        void operator =(const int);
        void operator =(const string);
        void operator =(const id2);
        id2& operator +=(const id2&);
        id2& operator -=(const id2&);
        id2& operator *=(const id2&);
        id2& operator /=(const id2&);
        id2& operator %=(const id2&);
        id2& operator +=(const int&);
        id2& operator -=(const int&);
        id2& operator *=(const int&);
        id2& operator /=(const int&);
        id2& operator %=(const int&);
        id2& operator %=(const LL&);
        bool undefined();
        int do_try(const int&);
        int do_try(const id2&);
        void do_trim();
        list<int> data;

    void add (const int a){
        list<int>::iterator it = data.end();
        it --;
        if ( (*it) < 10 ) (*it) = a ;
        else if ( (*it) < 100 ) (*it) = (*it) % 10 + 10*a ;
        else if ( (*it) < 1000 ) (*it) = (*it) % 100 + 100*a ;
        else if ( (*it) < 10000 ) (*it) = (*it) % 1000 + 1000*a ;
        else if ( (*it) < 100000 ) (*it) = (*it) % 10000 + 10000*a ;
        else if ( (*it) < 1000000 ) (*it) = (*it) % 100000 + 100000*a ;
        else if ( (*it) < 10000000 ) (*it) = (*it) % 1000000 + 1000000*a ;
        else if ( (*it) < 100000000 ) (*it) = (*it) % 10000000 + 10000000*a ;

        
    }

    void clear(){
        data.clear();
    }

    LL t(){
        if (data.size() == 1) return *data.begin();
        else {
            list<int>::iterator it = data.begin(), jt = data.begin(); ++it;
            return (LL)(*it) * 100000000 + (*jt);
        }
    }

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

    void output(){
        list<int>::reverse_iterator i=data.rbegin();
        printf("%d", *i); for (i++;i!=data.rend();i++)
            printf("%08d", *i);
    }
};

inline void id2::operator =(const id2 a){
    data.clear();
    for (list<int>::const_iterator i=a.data.begin();i!=a.data.end();i++){
        data.push_back(*i);
    }
}
inline void id2::operator =(const string a){
    (*this) = id2(a);
}
inline void id2::operator =(const int a){
    (*this) = id2(a);
}


inline istream& operator>>(istream& input, id2& a){
    string s; int t, i; input >> s; a.data.clear();
    for (i=int(s.size())-8;i>0;i-=8){
        istringstream(s.substr(i, 8)) >> t;
        a.data.push_back(t);
    }
    istringstream(s.substr(0, i+8)) >> t;
    a.data.push_back(t);
    return input;
}

inline ostream& operator<<(ostream& output, const id2& a){
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


inline bool id2::undefined(){
    return data.empty();
}

inline int do_comp(const id2& a, const id2& b){
    if (a.data.size()<b.data.size()) return -1; if (a.data.size()>b.data.size()) return 1;
    list<int>::const_reverse_iterator i; list<int>::const_reverse_iterator j;
    for (i=a.data.rbegin(),j=b.data.rbegin(); j!=b.data.rend(); i++,j++){
        if (*i<*j) return -1;              

        if (*i>*j) return 1;
    }
    return 0;
}
inline int do_comp(const id2& a, const int& b){
    return do_comp(a, id2(b));
}

inline bool operator ==(const id2& a, const id2& b){
    return do_comp(a, b) == 0;
}
inline bool operator !=(const id2& a, const id2& b){
    return do_comp(a, b) != 0;
}
inline bool operator <(const id2& a, const id2& b){
    return do_comp(a, b) == -1;
}
inline bool operator >(const id2& a, const id2& b){
    return do_comp(a, b) == 1;
}
inline bool operator <=(const id2& a, const id2& b){
    return do_comp(a, b) != 1;
}
inline bool operator >=(const id2& a, const id2& b){
    return do_comp(a, b) != -1;
}

inline bool operator ==(const id2& a, const int& b){
    return do_comp(a, b) == 0;
}
inline bool operator !=(const id2& a, const int& b){
    return do_comp(a, b) != 0;
}
inline bool operator <(const id2& a, const int& b){
    return do_comp(a, b) == -1;
}
inline bool operator >(const id2& a, const int& b){
    return do_comp(a, b) == 1;
}
inline bool operator <=(const id2& a, const int& b){
    return do_comp(a, b) != 1;
}
inline bool operator >=(const id2& a, const int& b){
    return do_comp(a, b) != -1;
}

inline void id2::do_trim(){
    while (data.size()>1&&data.back()==0) data.pop_back();
}


inline id2& id2::operator +=(const id2& a){
    list<int>::iterator i; list<int>::const_iterator j; int t = 0;
    for (i=data.begin(),j=a.data.begin(); i!=data.end()&&j!=a.data.end(); i++,j++){
        *i+=*j+t; t=*i/100000000; *i%=100000000;
    }
    while (i!=data.end()) {*i+=t; t=*i/100000000; *i%=100000000; i++;}
    while (j!=a.data.end()) {data.push_back(t+*j); t=data.back()/100000000; data.back()%=100000000; j++;}
    if (t!=0) data.push_back(t);
    return *this;
}


inline id2& id2::operator -=(const id2& a){
    list<int>::iterator i; list<int>::const_iterator j; int t = 0;
    for (i=data.begin(),j=a.data.begin(); j!=a.data.end(); i++,j++){
        *i -= t+*j; if (*i>=0) t=0; else *i+=100000000, t=1;
    }
    while (i!=data.end()) {*i-=t; if (*i>=0) t=0;else *i+=100000000, t=1; i++;}
    (*this).do_trim();
    return *this;
}


inline id2& id2::operator +=(const int& a){
    return (*this)+=id2(a);
}

inline id2& id2::operator -=(const int& a){
    return (*this)-=id2(a);
}




inline id2 operator +(const id2& a, const id2& b){
    list<int>::const_iterator i, j; id2 c; int t = 0;
    for (i=a.data.begin(),j=b.data.begin(); i!=a.data.end()&&j!=b.data.end(); i++,j++){
        c.data.push_back(t+*i+*j);
        t=c.data.back()/100000000; c.data.back()%=100000000;
    }
    while (i!=a.data.end()) {c.data.push_back(t+*i); t=c.data.back()/100000000; c.data.back()%=100000000; i++;}
    while (j!=b.data.end()) {c.data.push_back(t+*j); t=c.data.back()/100000000; c.data.back()%=100000000; j++;}
    if (t!=0) c.data.push_back(t);
    return c;
}

inline id2 operator -(const id2& a, const id2& b){
    list<int>::const_iterator i, j; id2 c; int t = 0;
    for (i=a.data.begin(),j=b.data.begin(); j!=b.data.end(); i++,j++){
        t = *i - t;
        if (t>=*j) c.data.push_back(t-*j), t=0;
        else c.data.push_back(t+100000000-*j), t=1;
    }
    while (i!=a.data.end()) {t=*i-t; if (t>=0) c.data.push_back(t), t=0;else c.data.push_back(t+100000000), t=1; i++;}
    c.do_trim();
    return c;
}

inline id2 operator *(const id2& a, const id2& b){
    list<int>::const_iterator i, j; list<int>::iterator k, kk; id2 c; long long t = 0;

    for (int i=0;i<a.data.size()+b.data.size();i++) c.data.push_back(0);
    for (i=a.data.begin(),k=c.data.begin(); i!=a.data.end(); i++,k++){
        for (j=b.data.begin(),kk=k; j!=b.data.end(); j++,kk++){
            t+=(long long)(*i)*(*j)+(*kk);
            *kk=int(t%100000000); t/=100000000;
        }
        *kk+=t; t=0;
    }
    c.do_trim();
    return c;
}

inline int id2::do_try(const id2& a){
    int l = 1, r = 99999999, m, t;
    while (l+2<r){
        m = (l + r) / 2;
        t = do_comp(*this, a*id2(m));
        if (t==0) return m;
        if (t<0) r = m - 1;
        else l = m;
    }
    while (do_comp(*this, a*id2(r))<0) r--;
    return r;
}

inline void divide(const id2& a, const id2& b, id2& d, id2& r){
    list<int>::const_reverse_iterator i = a.data.rbegin(); int t;
    d = id2(0); r = id2(0);
    do {
        while (r<b&&i!=a.data.rend()){d.data.push_front(0);r.data.push_front(*i);r.do_trim();i++;}
        if (r>=b){
            t = r.do_try(b); d.data.front() = t;
            r-=(b*id2(t));
        }
    } while (i!=a.data.rend());
    d.do_trim();
}

inline id2 operator /(const id2& a, const id2& b){
    id2 d, r;
    divide(a, b, d, r);
    return d;
}

inline id2 operator %(const id2& a, const id2& b){
    id2 d, r;
    divide(a, b, d, r);
    return r;
}

inline id2 operator +(const id2& a, const int& b){
    return a+id2(b);
}

inline id2 operator -(const id2& a, const int& b){
    return a-id2(b);
}

inline id2 operator *(const id2& a, const int& b){
    return a*id2(b);
}

inline id2 operator /(const id2& a, const int& b){
    return a/id2(b);
}


inline id2& id2::operator *=(const id2& a){
    (*this) = (*this) * a;
    return *this;
}

inline id2& id2::operator /=(const id2& a){
    (*this) = (*this) / a;
    return *this;
}

inline id2& id2::operator %=(const id2& a){
    (*this) = (*this) % a;
    return *this;
}

inline id2& id2::operator *=(const int& a){
    return (*this)*=id2(a);
}

inline id2& id2::operator /=(const int& a){
    return (*this)/=id2(a);
}

inline id2& id2::operator %=(const LL& b){
    return (*this)%=id2(b);
}


inline id2 pow(id2 a,int b){
    id2 c(1);
    while (b!=0) {
        if (b&1) c *= a;
        a = a * a; b >>= 1;
    }
    return c;
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




const int maxn=2;

LL modo;
class Mat
{
public:
       int Matn,Matm;
       typec a[maxn][maxn];
       Mat()
       {
            Matn=0;
            Matm=0;
            memset(a,0,sizeof(a));
       }
       void output();
       void init();
       void initI();
       Mat mul(const Mat &a);
       Mat power(const Mat&a,LL k);
};
void Mat::output()
{
     for (int i=0;i<Matn;++i)
     {
         for (int j=0;j<Matm;++j)
         {
             if (j!=0) printf(" ");
             printf("%d",a[i][j]);
         }
         printf("\n");
     }
}
void Mat::init()
{
    Matn=0;
    Matm=0;
    memset(a,0,sizeof(a));
}
Mat Mat::mul(const Mat &A)
{
    Mat c;
    c.Matn=Matn;
    c.Matm=A.Matm;
    for (int i=0;i<Matn;++i)
        for (int j=0;j<A.Matm;++j)
        {
            for (int k=0;k<Matm;++k)
            {
                c.a[i][j]=(c.a[i][j]+(a[i][k]*A.a[k][j])%modo)%modo;
            }
        }
    return c;
}
void Mat::initI()
{
     memset(a,0,sizeof(a));
     for (int i=0;i<Matn;++i) a[i][i]=1LL;
}
Mat Mat::power(const Mat& a,LL  k)
{
    Mat c=a,b;
    b.init();
    b.Matn=a.Matn;b.Matm=a.Matm;
    b.initI();
    while (k)
    {
         if (k & 1LL)
            b=b.mul(c);
         c=c.mul(c);
         k>>=1LL;
    }
    return b;
}
LL gao(LL t){
    if (t <= 1) return 1LL;
    Mat a;
    a.Matm = a.Matn = 2;
    a.a[0][0] = 1LL , a.a[1][0] = 1LL , a.a[0][1] = 1LL;
    a = a.power(a , t - 1LL);
    return a.a[0][0];
}
LL l , r , k;

LL check(LL x){
    return r / x - (l - 1LL) / x;
}
void solve(){
    LL ans = 1;
    for (LL i = 1 ; i * i <= r ; ++i){
        if (check(i) >= k && i > ans) ans = i;
        LL j = r / i;
        if (check(j) >= k && j > ans) ans = j;
    }
    cout << gao(ans) % modo <<endl;
}
int main(){
    while(cin >> modo >> l >> r >> k) solve();
}