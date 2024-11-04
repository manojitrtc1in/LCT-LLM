 


 
























using namespace std;























































	REP(i, n){		                            \
        REP(j, m) cout << A[i][j] << " ";       \
        cout << endl;				            \
	}						                    \
}


	id0(i, n){		                        \
        id0(j, m) cout << A[i][j] << " ";     \
		cout << endl;		            		\
	}						                    \
}









typedef int LL;


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
template<class T0,class T1>inline void RDD(const T0&a, const T1&b){RDD(a),RDD(b);}
template<class T0,class T1,class T2>inline void RDD(const T0&a, const T1&b, const T2&c){RDD(a),RDD(b),RDD(c);}

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

template<class T> inline T& SRT(T &A){sort(ALL(A)); return A;}
template<class T, class C> inline T& SRT(T &A, C B){sort(ALL(A), B); return A;}
template<class T> inline T& UNQ(T &A){A.resize(unique(ALL(SRT(A)))-A.begin());return A;}




 


const int dx4[] = {-1, 0, 1, 0};
const int dy4[] = {0, 1, 0, -1};

const int dx8[] = {-1, 0, 1, 0 , -1 , -1 , 1 , 1};
const int dy8[] = {0, 1, 0, -1 , -1 , 1 , -1 , 1};

const int dxhorse[] = {-2 , -2 , -1 , -1 , 1 , 1 , 2 , 2};
const int dyhorse[] = {1 ,  -1 , 2  , -2 , 2 ,-2 , 1 ,-1};

const int MOD = 1000000007;


const int INF = 0x3f3f3f3f;
const DB EPS = 1e-9;
const DB OO = 1e15;
const DB PI = acos(-1.0); 





 



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

int Case; template<class T> inline void OT(const T &x){
    

    

    

    cout << x << endl;
}



const int N = 309;

int a[N][N];
LL t , tt;
LL tp , tu , td;
int n , m;
LL U[N][N] , D[N][N] , L[N][N] , R[N][N];
struct ANS{
    LL T;
    int lx , ly , rx , ry;
}ans;
void upd(int lx , int rx , int ly , int ry , LL T){
    if (ans.T == -1 || abs(T - t) < abs(ans.T - t)){

        ans.T = T;
        ans.lx = lx;
        ans.ly = ly;
        ans.rx = rx;
        ans.ry = ry;
    }
}
set< pair<LL , LL> > hh;

LL f(LL pre , LL now){
    if (pre < now) return tu;
    if (pre > now) return td;
    return tp;
}
int main(){






    RD(n , m);
    RD(t , tp , tu , td);
    for (int i = 1 ; i <= n ; ++i)
        for (int j = 1 ; j <= m ; ++j)
            RD(a[i][j]);

    RST(U , D , L , R);
    ans.T = -1;
    for (int i = 1 ; i <= n ; ++i){
        for (int j = 2 ; j <= m ; ++j){
            L[i][j] = L[i][j - 1];
            if (a[i][j] > a[i][j - 1])
                L[i][j] += tu;
            else if (a[i][j] == a[i][j - 1]) L[i][j] += tp;
            else L[i][j] += td;
        }
    }
    for (int i = 2 ; i <= n ; ++i){
        for (int j = 1 ; j <= m ; ++j){
            U[i][j] = U[i - 1][j];
            if (a[i][j] < a[i - 1][j])
                U[i][j] += tu;
            else if (a[i][j] == a[i - 1][j]) U[i][j] += tp;
            else U[i][j] += td;
        }
    }
    for (int i = n - 1 ; i >= 1 ; --i){
        for (int j = 1 ; j <= m ; ++j){
            D[i][j] = D[i + 1][j];
            if (a[i][j] < a[i + 1][j])
                D[i][j] += tu;
            else if (a[i][j] == a[i + 1][j]) D[i][j] += tp;
            else D[i][j] += td;
        }
    }
    for (int i = 1 ; i <= n ; ++i){
        for (int j = m - 1 ; j >= 1 ; --j){
            R[i][j] = R[i][j + 1];
            if (a[i][j] > a[i][j + 1])
                R[i][j] += tu;
            else if (a[i][j] == a[i][j + 1]) R[i][j] += tp;
            else R[i][j] += td;
        }
    }


    for (int lx = 1 ; lx <= n ; ++lx)
    for (int rx = lx + 3 - 1; rx <= n ; ++rx){
        hh.clear();
        int head = 1;
        LL tot = 0 , now;
        for (int ry = 1 ; ry <= m ; ++ry){
            if (ry != 1){
                 tot += f(a[lx][ry - 1] , a[lx][ry]);
                 tot += f(a[rx][ry] , a[rx][ry - 1]);
            }
            now = tot + D[lx][ry] - D[rx][ry];






            if (!hh.empty()){
                static set< pair<LL , LL> > ::iterator iter , liter , riter;
                iter = hh.lower_bound(MP(t - now , 0));
                liter = iter , riter = iter;
                if (liter != hh.begin()) liter--;
                if (riter != hh.end()) riter++;
                if (iter != hh.end()){
                    pair<LL , LL> me = *iter;


                    upd(lx , rx , me.se , ry , now + me.fi);
                }
                if (liter != hh.end()){
                    pair<LL , LL> me = *liter;


                    upd(lx , rx , me.se , ry , now + me.fi);
                }
                if (riter != hh.end()){
                    pair<LL , LL> me = *riter;


                    upd(lx , rx , me.se , ry , now + me.fi);
                }
            }
            while(ry + 1 - head + 1 >= 3){
                pair<LL , LL> me;
                me.fi = 0;
                me.se = head;
                me.fi += U[rx][head] - U[lx][head];
                me.fi -= L[lx][head];
                me.fi -= R[rx][1] - R[rx][head];
                hh.insert(me);
                ++head;
            }
        }
    }
    cout << ans.lx << ' ' << ans.ly << ' ' << ans.rx << ' ' << ans.ry << endl;


}
