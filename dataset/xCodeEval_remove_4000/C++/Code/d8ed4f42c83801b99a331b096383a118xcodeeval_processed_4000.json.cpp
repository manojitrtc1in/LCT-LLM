 


 





































using namespace std;



























































  REP(i, n){		                            \
        REP(j, m-1) cprint << A[i][j] << " ";     \
        cprint << A[i][m-1] << endl;		        \
	}						                    \
}

	id0(i, n){		                        \
        id0(j, m-1) cprint << A[i][j] << " ";   \
        cprint << A[i][m] << endl;		        \
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





 


const int MOD = int(1e9) + 7;


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
inline bool _1(uint x, int i){return bool(x&1u<<i);}
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
    

    

    

    printf("%d\n", x);
    

    

}








const int N = int(7.1e4) + 9;

uint dpp[(N>>5)+1], dp[(N>>5)+1]; int p[N]; bool fa[N];

int A[N], n, s; PII B[N];

int main(){


    freopen("in.txt", "r", stdin);
    



    RD(n, s); id0(i, n) B[i] = MP(RD(A[i]), i);
    sort(B+1, B+n+1, greater<PII>());
    s -= B[1].fi; if (s < 0){puts("-1"); exit(0);}

    int nn = ceil(s, 32) + 5; dp[0] = 1;

    FOR_1(i, 2, n){

        memset(dpp, 0, sizeof(int)*nn);

        int o1 = B[i].fi >> 5, o2 = B[i].fi & 31;

        REP(ii, nn-o1){
            dpp[ii+o1] |= dp[ii] << o2;
            if (o2) dpp[ii+o1+1] |= dp[ii] >> (32 - o2);
        }

        REP(ii, nn) if ((dpp[ii]|dp[ii]) != dp[ii]){
            REP(j, 32) if (_1(dpp[ii], j) && !_1(dp[ii], j)){
                p[(ii<<5)+j] = B[i].se;
            }
            dp[ii] |= dpp[ii];
        }
    }

    


    if (s && !p[s]){puts("-1");exit(0);} do{
        fa[p[s]] = 1; 

    }while (s -= A[p[s]]);

    RST(p); int ii = B[1].se; FOR_1(i, 2, n) if (!fa[B[i].se]){
        p[ii] = B[i].se, ii = B[i].se;
    }

    id0(i, n){
        if (p[i]) printf("%d 1 %d\n", A[i]-A[p[i]], p[i]);
        else printf("%d 0\n", A[i]);
    }
}
