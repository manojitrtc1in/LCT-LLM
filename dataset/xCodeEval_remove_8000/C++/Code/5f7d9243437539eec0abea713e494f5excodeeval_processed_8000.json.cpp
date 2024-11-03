






















using namespace std;




















































	REP(i, n){		                          \
        REP(j, m) cout << A[i][j] << " ";\
		cout << endl;				\
	}						\
}


	id0(i, n){		\
        id0(j, m) cout << A[i][j] << " ";\
		cout << endl;				\
	}						\
}








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
const DB EPS = 1e-8;
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





inline int rand32(){return (bool(rand() & 1) << 30) | (rand() << 15) + rand();}
inline int random32(int l, int r){return rand32() % (r - l + 1) + l;}
inline int random(int l, int r){return rand() % (r - l + 1) + l;}
int dice(){return rand() % 6;}
bool coin(){return rand() % 2;}






using namespace std;

class id1{
          friend istream& operator>>(istream&, id1&);
          friend ostream& operator<<(ostream&, const id1&);
          friend id1 operator +(const id1&, const id1&);
          friend id1 operator -(const id1&, const id1&);
          friend id1 operator *(const id1&, const id1&);
          friend id1 operator /(const id1&, const id1&);
          friend id1 operator %(const id1&, const id1&);
          friend id1 operator +(const id1&, const int&);
          friend id1 operator -(const id1&, const int&);
          friend id1 operator *(const id1&, const int&);
          friend id1 operator /(const id1&, const int&);
          friend id1 operator %(const id1&, const int&);
          friend bool operator ==(const id1&, const id1&);
          friend bool operator !=(const id1&, const id1&);
          friend bool operator <(const id1&, const id1&);
          friend bool operator >(const id1&, const id1&);
          friend bool operator <=(const id1&, const id1&);
          friend bool operator >=(const id1&, const id1&);
          friend bool operator ==(const id1&, const int&);
          friend bool operator !=(const id1&, const int&);
          friend bool operator <(const id1&, const int&);
          friend bool operator >(const id1&, const int&);
          friend bool operator <=(const id1&, const int&);
          friend bool operator >=(const id1&, const int&);
          friend int do_comp(const id1&, const int&);
          friend int do_comp(const id1&, const id1&);
          friend void divide(const id1&, const id1&, id1&, id1&);
          friend id1 pow(id1, int);
    public:
        inline id1(){};
        inline id1(int s){
            while (s!=0){
                data.push_back(s%100000000); s/=100000000;
            }
            if (data.empty()) data.push_back(0);
        }
    inline id1(long long s){
        while (s!=0){
            data.push_back(int(s%100000000)); s/=100000000;
        }
        if (data.empty()) data.push_back(0);
    }
        inline id1(string s){
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
        void operator =(const id1);
        id1& operator +=(const id1&);
        id1& operator -=(const id1&);
        id1& operator *=(const id1&);
        id1& operator /=(const id1&);
        id1& operator %=(const id1&);
        id1& operator +=(const int&);
        id1& operator -=(const int&);
        id1& operator *=(const int&);
        id1& operator /=(const int&);
        id1& operator %=(const int&);
        id1& operator %=(const LL&);
        bool undefined();
        int do_try(const int&);
        int do_try(const id1&);
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
};

inline void id1::operator =(const id1 a){
    data.clear();
    for (list<int>::const_iterator i=a.data.begin();i!=a.data.end();i++){
        data.push_back(*i);
    }
}
inline void id1::operator =(const string a){
    (*this) = id1(a);
}
inline void id1::operator =(const int a){
    (*this) = id1(a);
}


inline istream& operator>>(istream& input, id1& a){
    string s; int t, i; input >> s; a.data.clear();
    for (i=int(s.size())-8;i>0;i-=8){
        istringstream(s.substr(i, 8)) >> t;
        a.data.push_back(t);
    }
    istringstream(s.substr(0, i+8)) >> t;
    a.data.push_back(t);
    return input;
}

inline ostream& operator<<(ostream& output, const id1& a){
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

inline bool id1::undefined(){
    return data.empty();
}

inline int do_comp(const id1& a, const id1& b){
    if (a.data.size()<b.data.size()) return -1; if (a.data.size()>b.data.size()) return 1;
    list<int>::const_reverse_iterator i; list<int>::const_reverse_iterator j;
    for (i=a.data.rbegin(),j=b.data.rbegin(); j!=b.data.rend(); i++,j++){
        if (*i<*j) return -1;              

        if (*i>*j) return 1;
    }
    return 0;
}
inline int do_comp(const id1& a, const int& b){
    return do_comp(a, id1(b));
}

inline bool operator ==(const id1& a, const id1& b){
    return do_comp(a, b) == 0;
}
inline bool operator !=(const id1& a, const id1& b){
    return do_comp(a, b) != 0;
}
inline bool operator <(const id1& a, const id1& b){
    return do_comp(a, b) == -1;
}
inline bool operator >(const id1& a, const id1& b){
    return do_comp(a, b) == 1;
}
inline bool operator <=(const id1& a, const id1& b){
    return do_comp(a, b) != 1;
}
inline bool operator >=(const id1& a, const id1& b){
    return do_comp(a, b) != -1;
}

inline bool operator ==(const id1& a, const int& b){
    return do_comp(a, b) == 0;
}
inline bool operator !=(const id1& a, const int& b){
    return do_comp(a, b) != 0;
}
inline bool operator <(const id1& a, const int& b){
    return do_comp(a, b) == -1;
}
inline bool operator >(const id1& a, const int& b){
    return do_comp(a, b) == 1;
}
inline bool operator <=(const id1& a, const int& b){
    return do_comp(a, b) != 1;
}
inline bool operator >=(const id1& a, const int& b){
    return do_comp(a, b) != -1;
}

inline void id1::do_trim(){
    while (data.size()>1&&data.back()==0) data.pop_back();
}


inline id1& id1::operator +=(const id1& a){
    list<int>::iterator i; list<int>::const_iterator j; int t = 0;
    for (i=data.begin(),j=a.data.begin(); i!=data.end()&&j!=a.data.end(); i++,j++){
        *i+=*j+t; t=*i/100000000; *i%=100000000;
    }
    while (i!=data.end()) {*i+=t; t=*i/100000000; *i%=100000000; i++;}
    while (j!=a.data.end()) {data.push_back(t+*j); t=data.back()/100000000; data.back()%=100000000; j++;}
    if (t!=0) data.push_back(t);
    return *this;
}


inline id1& id1::operator -=(const id1& a){
    list<int>::iterator i; list<int>::const_iterator j; int t = 0;
    for (i=data.begin(),j=a.data.begin(); j!=a.data.end(); i++,j++){
        *i -= t+*j; if (*i>=0) t=0; else *i+=100000000, t=1;
    }
    while (i!=data.end()) {*i-=t; if (*i>=0) t=0;else *i+=100000000, t=1; i++;}
    (*this).do_trim();
    return *this;
}


inline id1& id1::operator +=(const int& a){
    return (*this)+=id1(a);
}

inline id1& id1::operator -=(const int& a){
    return (*this)-=id1(a);
}




inline id1 operator +(const id1& a, const id1& b){
    list<int>::const_iterator i, j; id1 c; int t = 0;
    for (i=a.data.begin(),j=b.data.begin(); i!=a.data.end()&&j!=b.data.end(); i++,j++){
        c.data.push_back(t+*i+*j);
        t=c.data.back()/100000000; c.data.back()%=100000000;
    }
    while (i!=a.data.end()) {c.data.push_back(t+*i); t=c.data.back()/100000000; c.data.back()%=100000000; i++;}
    while (j!=b.data.end()) {c.data.push_back(t+*j); t=c.data.back()/100000000; c.data.back()%=100000000; j++;}
    if (t!=0) c.data.push_back(t);
    return c;
}

inline id1 operator -(const id1& a, const id1& b){
    list<int>::const_iterator i, j; id1 c; int t = 0;
    for (i=a.data.begin(),j=b.data.begin(); j!=b.data.end(); i++,j++){
        t = *i - t;
        if (t>=*j) c.data.push_back(t-*j), t=0;
        else c.data.push_back(t+100000000-*j), t=1;
    }
    while (i!=a.data.end()) {t=*i-t; if (t>=0) c.data.push_back(t), t=0;else c.data.push_back(t+100000000), t=1; i++;}
    c.do_trim();
    return c;
}

inline id1 operator *(const id1& a, const id1& b){
    list<int>::const_iterator i, j; list<int>::iterator k, kk; id1 c; long long t = 0;

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

inline int id1::do_try(const id1& a){
    int l = 1, r = 99999999, m, t;
    while (l+2<r){
        m = (l + r) / 2;
        t = do_comp(*this, a*id1(m));
        if (t==0) return m;
        if (t<0) r = m - 1;
        else l = m;
    }
    while (do_comp(*this, a*id1(r))<0) r--;
    return r;
}

inline void divide(const id1& a, const id1& b, id1& d, id1& r){
    list<int>::const_reverse_iterator i = a.data.rbegin(); int t;
    d = id1(0); r = id1(0);
    do {
        while (r<b&&i!=a.data.rend()){d.data.push_front(0);r.data.push_front(*i);r.do_trim();i++;}
        if (r>=b){
            t = r.do_try(b); d.data.front() = t;
            r-=(b*id1(t));
        }
    } while (i!=a.data.rend());
    d.do_trim();
}

inline id1 operator /(const id1& a, const id1& b){
    id1 d, r;
    divide(a, b, d, r);
    return d;
}

inline id1 operator %(const id1& a, const id1& b){
    id1 d, r;
    divide(a, b, d, r);
    return r;
}

inline id1 operator +(const id1& a, const int& b){
    return a+id1(b);
}

inline id1 operator -(const id1& a, const int& b){
    return a-id1(b);
}

inline id1 operator *(const id1& a, const int& b){
    return a*id1(b);
}

inline id1 operator /(const id1& a, const int& b){
    return a/id1(b);
}


inline id1& id1::operator *=(const id1& a){
    (*this) = (*this) * a;
    return *this;
}

inline id1& id1::operator /=(const id1& a){
    (*this) = (*this) / a;
    return *this;
}

inline id1& id1::operator %=(const id1& a){
    (*this) = (*this) % a;
    return *this;
}

inline id1& id1::operator *=(const int& a){
    return (*this)*=id1(a);
}

inline id1& id1::operator /=(const int& a){
    return (*this)/=id1(a);
}

inline id1& id1::operator %=(const LL& b){
    return (*this)%=id1(b);
}


inline id1 pow(id1 a,int b){
    id1 c(1);
    while (b!=0) {
        if (b&1) c *= a;
        a = a * a; b >>= 1;
    }
    return c;
}




struct Int {
	int x;
	Int() :
			x(0) {
	}
	Int(int _x) :
			x(_x) {
		x %= MOD;
		if (x < 0)
			x += MOD;
	}
	Int(LL _x) {
		x = _x % MOD;
		if (x < 0)
			x += MOD;
	}
	static Int get(int x) {
		Int a;
		a.x = x;
		return a;
	}

	Int operator+(const Int&o) const {
		int t = x + o.x;
		if (t >= MOD)
			t -= MOD;
		return get(t);
	}
	Int operator*(const Int&o) const {
		return get(1LL * x * o.x % MOD);
	}
	Int operator-(const Int&o) const {
		int t = x - o.x;
		if (t < 0)
			t += MOD;
		return get(t);
	}
	Int operator/(const Int&o) const {
		return (*this) * o.inv();
	}
	Int&operator+=(const Int&o) {
		return (*this) = *this + o;
	}
	Int&operator-=(const Int&o) {
		return (*this) = *this - o;
	}
	Int&operator*=(const Int&o) {
		return (*this) = *this * o;
	}
	Int&operator/=(const Int&o) {
		return (*this) = *this / o;
	}

	Int power(LL n) const {
		if (!n)
			return get(1);
		const Int&a = *this;
		if (n & 1)
			return power(n - 1) * a;
		else
			return (a * a).power(n >> 1);
	}

	Int inv() const {
		return power(MOD - 2);
	}
};







template<class T> inline void RD(T &x){
    

    scanf("%d", &x);
    

    

}

template<class T> inline void OT(const T &x){
    

    printf("%d\n", x);
}



int main()
{
	int i,j,k,n;


	n = 500,k = 2000,j = 0;
	printf("%d\n",n);
	printf("1 1000000\n");
	for (i = 2; i < n; ++i)
		printf("%d %d\n",100000+i * 1000,n-i);
	printf("998001 999999\n");
}

