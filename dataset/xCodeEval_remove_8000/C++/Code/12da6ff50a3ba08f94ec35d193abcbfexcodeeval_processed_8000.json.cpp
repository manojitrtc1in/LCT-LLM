 


 




































using namespace std;























































REP(i, n){  	                            \
REP(j, m-1) cout << A[i][j] << " ";     \
cout << A[i][m-1] << endl;		        \
}						                    \
}

id1(i, n){		                        \
id1(j, m-1) cout << A[i][j] << " ";   \
cout << A[i][m] << endl;		        \
}						                    \
}

string id0(){
    string res = id3;
    int r = SZ(res) - 1; while (res[r] !=  '.') --r;
    int l = r - 1; while (res[l] != '\\') --l; ++l;
    return res.substr(l, r-l);
}

void Exec(string a, string b, string c){
    if (b.empty()) b = id0();
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
typedef unsigned int UINT;
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
template<class T> inline T& RVS(T &A){reverse(ALL(A)); return A;}
template<class T> inline T& UNQ(T &A){A.resize(unique(ALL(SRT(A)))-A.begin());return A;}

template<class T, class C> inline T& SRT(T &A, C B){sort(ALL(A), B); return A;}




 


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
    inline LL id2(LL a, LL b){return a*b/__gcd(a,b);}
    inline void INC(int &a, int b){a += b; if (a >= MOD) a -= MOD;}
    inline int sum(int a, int b){a += b; if (a >= MOD) a -= MOD; return a;}
    inline void DEC(int &a, int b){a -= b; if (a < 0) a += MOD;}
    inline int dff(int a, int b){a -= b; if (a < 0) a  += MOD; return a;}
    inline void MUL(int &a, int b){a = (LL)a * b % MOD;}
    inline int pdt(int a, int b){return (LL)a * b % MOD;}
    
    inline int sum(int a, int b, int c){return sum(sum(a, b), c);}
    inline int sum(int a, int b, int c, int d){return sum(sum(a, b), sum(c, d));}
    inline int pdt(int a, int b, int c){return pdt(pdt(a, b), c);}
    inline int pdt(int a, int b, int c, int d){return pdt(pdt(pdt(a, b), c), d);}
    
    inline int pow(int a, LL b){
        int c(1); while (b){
            if (b&1) MUL(c, a);
            MUL(a, a), b >>= 1;
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
    
    inline void DIV(int &a, int b){MUL(a, _I(b));}
    inline int qtt(int a, int b){return pdt(a, _I(b));}
    
    struct Int{
        int val;
        
        operator int() const{return val;}
        
        Int(int val = 0):val(val){
            

        }
        inline Int& operator +=(const int& rhs){
            INC(val, rhs);
            return *this;
        }
        inline Int operator +(const int& rhs) const{
            return sum(val, rhs);
        }
        inline Int& operator -=(const int& rhs){
            DEC(val, rhs);
            return *this;
        }
        inline Int operator -(const int& rhs) const{
            return dff(val, rhs);
        }
        inline Int& operator *=(const int& rhs){
            MUL(val, rhs);
            return *this;
        }
        inline Int operator *(const int& rhs) const{
            return pdt(val, rhs);
        }
        inline Int& operator /=(const int& rhs){
            DIV(val, rhs);
            return *this;
        }
        inline Int operator /(const int& rhs) const{
            return qtt(val, rhs);
        }
    };
    
    const int PMAX = 1;
    VI P; bitset<PMAX> isP;
    void sieve(){
        FOR(i, 2, PMAX){
            if (!isP[i]) P.PB(i);
            for (int j=0;j<SZ(P)&&i*P[j]<PMAX;++j){
                isP[i*P[j]]=1; if (!(i%P[j])) break;
            }
        }
    }
    
    inline int phi(int n){
        int res = n; for (int i=2;sqr(i)<=n;++i) if (!(n%i)){
            DEC(res, qtt(res, i));
            do{n /= i;} while(!(n%i));
        }
        if (n != 1)
            DEC(res, qtt(res, n));
        return res;
    }
    
} using namespace NT;




 

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
    

    

    printf("%u\n", x);
    

    

}









const int N = 100009;
bool C[N]; int A[N]; int B[N];

bool bj[N]; int to[N]; VI adj[N];

int n;


void gao(int u = 0){
    C[u] = 1;
    if (u == 1){
        printf("0 1");
        
    }
    else {
        if (u&1){
            if (!C[n+u-1>>1]) gao(n+u-1>>1);
            else gao(u-1>>1);
        }
        else {
            if (!C[n+u>>1]) gao(n+u>>1);
            else gao(u>>1);
        }
        
        printf(" %d", u);
    }
    
}


int main(){
    

    

    


    
    while (cin >> n){
        
        if (n&1) puts("-1");
        else {
            
            RST(bj);
        
        REP(i, n) CLR(adj[i]);
        REP(i, n) adj[2*i%n].PB(i), adj[(2*i+1)%n].PB(i);
        REP(i, n) if (SZ(adj[i])==1) bj[i] = 1, to[i] = adj[i][0];
        
        
        
            RST(C); 

            
            gao(0);
            cout << endl;
            
        }
    }
    

}