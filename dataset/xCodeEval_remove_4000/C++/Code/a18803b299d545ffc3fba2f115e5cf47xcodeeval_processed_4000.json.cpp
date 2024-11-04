



















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
const DB EPS = 1e-6;
const DB OO = 1e15;
const DB PI = acos(-1.0);




template<class T> inline void checkMin(T &a,const T b){if (b<a) a=b;}
template<class T> inline void checkMax(T &a,const T b){if (b>a) a=b;}
template <class T, class C> inline void checkMin(T& a, const T b, C c){if (c(b,a)) a = b;}
template <class T, class C> inline void checkMax(T& a, const T b, C c){if (c(a,b)) a = b;}
template<class T> inline T min(T a, T b, T c){return min(min(a, b), c);}
template<class T> inline T max(T a, T b, T c){return max(max(a, b), c);}
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





template<class T> inline void RD(T &x){
    

    

    char c; for (c = getchar(); c < '0'; c = getchar()); x = c - '0'; for (c = getchar(); c >= '0'; c = getchar()) x = x * 10 + c - '0';
    


}

int ____Case;
template<class T> inline void OT(const T &x){
    

    printf("%d\n", x);
    

    

}



    
    
    
    
    
    
    typedef pair<int, int> pii;
    typedef vector<int> vi;
    typedef long long ll;

    namespace acm {

    const int N = 510;
    const int M = 6;
    const double eps = 1e-8;

    int dcmp(double x) {
        if (x < -eps) return -1;
        else return x > eps;
    }

    struct cpoint {
        double x, y;
        cpoint(){}
        cpoint(double x, double y) : x(x), y(y) {}
        cpoint operator + (const cpoint& u) const {
            return cpoint(x + u.x, y + u.y);
        }
        cpoint operator - (const cpoint& u) const {
            return cpoint(x - u.x, y - u.y);
        }
        cpoint operator * (const double& s) const {
            return cpoint(x * s, y * s);
        }
        cpoint operator / (const double& s) const {
            return cpoint(x / s, y / s);
        }
        double operator * (const cpoint& u) const {
            return x * u.y - y * u.x;
        }
        double operator ^ (const cpoint& u) const {
            return x * u.x + y * u.y;
        }
        bool operator == (const cpoint& u) const {
            return dcmp(x - u.x) == 0 && dcmp(y - u.y) == 0;
        }
        bool operator < (const cpoint& u) const {
            if (dcmp(x - u.x)) return x < u.x;
            else return dcmp(y - u.y) < 0;
        }
        void get() { scanf("%lf%lf", &x, &y); }
    };


    

    struct poly {
        int n;
        cpoint cp[M];
        void get() {
    

            n = 4;
            forn (i, n) cp[i].get();
        }
        bool check() {
            cp[n] = cp[0];
            double area = 0;
            forn (i, n) area += cp[i] * cp[i + 1];
            if (dcmp(area) == 0) return false;
            if (area < 0) reverse(cp, cp + n);
            cp[n] = cp[0];
            return true;
        }
    }ply[N];

    int n;
    typedef pair<cpoint, cpoint> segment;
    
    segment seg1[N * M], seg2[N * M];
    line lin[N * M]; 


    line getline(cpoint u, cpoint v) {
        double k;
        if (dcmp(u.x - v.x) == 0) k = 1e20;
        else k = (u.y - v.y) / (u.x - v.x);
        return line(k, u.y - k * u.x);
    }

    bool getcut(line lin, cpoint a, cpoint b, cpoint& cp) {
        double t = lin.x * (a.x - b.x) - (a.y - b.y);
        if (dcmp(t) == 0) return false;
        double x = ((a * b) - (a.x - b.x) * lin.y) / t;
        cp = cpoint(x, lin.x * x + lin.y);
        return true;
    }

    double calc(segment seg[], int m) {
        int ln = 0; double ans = 0;
        cpoint A, B, cp;
        forn (i, m) lin[ln++] = getline(seg[i].first, seg[i].second);
        sort(lin, lin + ln);
        ln = unique(lin, lin + ln) - lin;

        forn (i, ln) {
            vector<pair<double, int> > mark;
            forn (j, n) {
                bool touch = 0;


                forn (k, ply[j].n)
                    if (lin[i] == getline(ply[j].cp[k], ply[j].cp[k + 1])) {
                        touch = 1; break;
                    }
                if (touch) continue; 



                vector<cpoint> cut;
                forn (k, ply[j].n) {
                    A = ply[j].cp[k];
                    B = ply[j].cp[k + 1];
                    if (!getcut(lin[i], A, B, cp)) continue;
                    if (dcmp((A - cp) ^ (B - cp)) <= 0)
                        cut.push_back(cp);
                }

                




                if (SZ(cut) == 2) {
                    sort(cut.begin(), cut.end());
                    mark.push_back(MP(cut[0].x, 0));
                    mark.push_back(MP(cut[1].x, 1));
                }

            }

            forn (j, m)
                if (lin[i] == getline(seg[j].first, seg[j].second)) {
                    double mn = min(seg[j].first.x, seg[j].second.x);
                    double mx = max(seg[j].first.x, seg[j].second.x);
                    mark.push_back(MP(mn, 2));
                    mark.push_back(MP(mx, 3));
                }
            sort(mark.begin(), mark.end());
            double last = mark[0].first;
            int in = 0, ct = 0;
            forn (j, SZ(mark)) {
                double y0 = lin[i].x * last + lin[i].y;
                double y1 = lin[i].x * mark[j].first + lin[i].y;
                if (!in && ct)
                    ans += (y0 + y1) * (mark[j].first - last);
                last = mark[j].first;
                if (mark[j].second == 0) in++;
                if (mark[j].second == 1) in--;
                if (mark[j].second == 2) ct++;
                if (mark[j].second == 3) ct--;
            }
        }
        return ans / 2;
    }

    double PolyUnion(poly ply[], int n) {
        int n1, n2, tot = n;
        n1 = n2 = n = 0;
        forn (i, tot) if (ply[i].check())
            ply[n++] = ply[i]; 

        forn (i, n) forn (j, ply[i].n) {
            cpoint A = ply[i].cp[j];
            cpoint B = ply[i].cp[j + 1];
            if (dcmp(A.x - B.x) > 0) seg1[n1++] = MP(A, B);
            if (dcmp(A.x - B.x) < 0) seg2[n2++] = MP(A, B);
        }
        return calc(seg1, n1) - calc(seg2, n2);
    }

    void solve() {
        forn (i, n) ply[i].get();
        double area = PolyUnion(ply, n);
        double tot = 0;
        forn (i, n) forn (j, ply[i].n)
            tot += ply[i].cp[j] * ply[i].cp[j + 1];
        tot /= 2;
        printf("%.10lf\n", tot / area);
    }


    void icpc() {
        while (~scanf("%d", &n)) {
            solve();
        }
    }

    }

    int main() {
    
        freopen("in", "r", stdin);
    
        acm::icpc();
        return 0;
    }
