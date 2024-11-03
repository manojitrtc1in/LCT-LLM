
 

 




















 
using namespace std;
 
























 










 














 

 

	REP(i, n){		                            \
        REP(j, m) cout << A[i][j] << " ";       \
        cout << endl;				            \
	}						                    \
}
 

	id1(i, n){		                        \
        id1(j, m) cout << A[i][j] << " ";     \
		cout << endl;		            		\
	}						                    \
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
typedef pair<int, int> PII;
typedef pair<int, bool> PIB;
typedef pair<LL, LL> PLL;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef vector<VII> VVII;
 
template<class T> inline T& RD(T &);
template<class T> inline void OT(const T &);
inline LL RD(){LL x; return RD(x);}
inline char& RC(char &c){scanf(" %c", &c); return c;}
inline char RC(){char c; return RC(c);}




inline DB& RF(DB &x){scanf("%lf", &x); return x;}
inline DB RF(){DB x; return RF(x);}
inline char* RS(char *s){scanf("%s", s); return s;}
 
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
 
template<class T> inline void RST(T &A){memset(A, 0, sizeof(A));}
template<class T0, class T1> inline void RST(T0 &A0, T1 &A1){RST(A0), RST(A1);}
template<class T0, class T1, class T2> inline void RST(T0 &A0, T1 &A1, T2 &A2){RST(A0), RST(A1), RST(A2);}
template<class T0, class T1, class T2, class T3> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3){RST(A0), RST(A1), RST(A2), RST(A3);}
template<class T0, class T1, class T2, class T3, class T4> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4){RST(A0), RST(A1), RST(A2), RST(A3), RST(A4);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5){RST(A0), RST(A1), RST(A2), RST(A3), RST(A4), RST(A5);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6){RST(A0), RST(A1), RST(A2), RST(A3), RST(A4), RST(A5), RST(A6);}
template<class T> inline void FLC(T &A, int x){memset(A, x, sizeof(A));}
template<class T0, class T1> inline void FLC(T0 &A0, T1 &A1, int x){FLC(A0, x), FLC(A1, x);}
template<class T0, class T1, class T2> inline void FLC(T0 &A0, T1 &A1, T2 &A2, int x){FLC(A0, x), FLC(A1, x), FLC(A2, x);}
template<class T0, class T1, class T2, class T3> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, int x){FLC(A0, x), FLC(A1, x), FLC(A2, x), FLC(A3, x);}
template<class T0, class T1, class T2, class T3, class T4> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, int x){FLC(A0, x), FLC(A1, x), FLC(A2, x), FLC(A3, x), FLC(A4, x);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, int x){FLC(A0, x), FLC(A1, x), FLC(A2, x), FLC(A3, x), FLC(A4, x), FLC(A5, x);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6, int x){FLC(A0, x), FLC(A1, x), FLC(A2, x), FLC(A3, x), FLC(A4, x), FLC(A5, x), FLC(A6, x);}
template<class T> inline void CLR(priority_queue<T, vector<T>, less<T> > &Q){while (!Q.empty()) Q.pop();}
template<class T> inline void CLR(priority_queue<T, vector<T>, greater<T> > &Q){while (!Q.empty()) Q.pop();}
template<class T> inline void CLR(T &A){A.clear();}
template<class T0, class T1> inline void CLR(T0 &A0, T1 &A1){CLR(A0), CLR(A1);}
template<class T0, class T1, class T2> inline void CLR(T0 &A0, T1 &A1, T2 &A2){CLR(A0), CLR(A1), CLR(A2);}
template<class T0, class T1, class T2, class T3> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3){CLR(A0), CLR(A1), CLR(A2), CLR(A3);}
template<class T0, class T1, class T2, class T3, class T4> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4){CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5){CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4), CLR(A5);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6){CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4), CLR(A5), CLR(A6);}
template<class T> inline void CLR(T &A, int n){REP(i, n) CLR(A[i]);}
 
template<class T> inline T& SRT(T &A){sort(ALL(A)); return A;}
template<class T, class C> inline T& SRT(T &A, C B){sort(ALL(A), B); return A;}
 

 
const int dx4[] = {-1, 0, 1, 0};
const int dy4[] = {0, 1, 0, -1};
 
const int dx8[] = {-1, 0, 1, 0 , -1 , -1 , 1 , 1};
const int dy8[] = {0, 1, 0, -1 , -1 , 1 , -1 , 1};
 
const int dxhorse[] = {-2 , -2 , -1 , -1 , 1 , 1 , 2 , 2};
const int dyhorse[] = {1 ,  -1 , 2  , -2 , 2 ,-2 , 1 ,-1};
 
const int ___MOD = 1000000007;


const int ___INF = 0x3f3f3f3f;
const LL id4 = 1LL << 60;
const DB ___EPS = 1e-9;
const DB ___OO = 1e15;
const DB ___PI = acos(-1.0); 

 


 
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
inline int Ceil(int x, int y){return (x - 1) / y + 1;}
 


 
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
template<class T> inline T low_bit(T x) {return x & -x;}
template<class T> inline T high_bit(T x) {T p = low_bit(x);while (p != x) x -= p, p = low_bit(x);return p;}
template<class T> inline T cover_bit(T x){T p = 1; while (p < x) p <<= 1;return p;}
inline int low_idx(int x){return __builtin_ffs(x);}
inline int low_idx(LL x){return __builtin_ffsll(x);}
inline int high_idx(int x){return low_idx(reverse_bits(x));}
inline int high_idx(LL x){return low_idx(reverse_bits(x));}
inline int clz(int x){return __builtin_clz(x);}
inline int clz(LL x){return __builtin_clzll(x);}
inline int ctz(int x){return __builtin_ctz(x);}
inline int ctz(LL x){return __builtin_ctzll(x);}
inline int parity(int x){return __builtin_parity(x);}
inline int parity(LL x){return __builtin_parityll(x);}
inline int lg2(int a){return 31 - __builtin_clz(a);}
inline int count_bits(int x){return __builtin_popcount(x);}
inline int count_bits(LL x){return __builtin_popcountll(x);}
 
} ;

 
 


 
namespace NT{
 
inline void INC(int &a, int b){a += b; if (a >= ___MOD) a -= ___MOD;}
inline int sum(int a, int b){a += b; if (a >= ___MOD) a -= ___MOD; return a;}
inline void DEC(int &a, int b){a -= b; if (a < 0) a += ___MOD;}
inline int dff(int a, int b){a -= b; if (a < 0) a  += ___MOD; return a;}
inline void MUL(int &a, int b){a = (LL)a * b % ___MOD;}
inline int pdt(int a, int b){return (LL)a * b % ___MOD;}
 
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
 
inline int _I(int b){
    int a = ___MOD, x1 = 0, x2 = 1, q;
    while (true){
        q = a / b, a %= b;
        if (!a) return (x2 + ___MOD) % ___MOD;
        DEC(x1, pdt(q, x2));
 
        q = b / a, b %= a;
        if (!b) return (x1 + ___MOD) % ___MOD;
        DEC(x2, pdt(q, x1));
    }
}
 
inline void DIA(int &a, int b){MUL(a, _I(b));}
inline int qtt(int a, int b){return pdt(a, _I(b));}
 
 
inline int phi(int n){
    int res = n; for (int i=2;sqr(i)<=n;++i) if (!(n%i)){
        DEC(res, qtt(res, i));
        do{n /= i;} while(!(n%i));
    }
    if (n != 1)
        DEC(res, qtt(res, n));
    return res;
}
template <class T>
T GCD(T a, T b)
{
    return b ? GCD(b, a % b) : a;
}
template <class T>
T id2(T a, T b, T& x, T& y)
{
    if(!b) return x = 1, y = 0, a;
    T res = id2(b, a % b, x, y), tmp = x;
    x = y, y = tmp - (a / b) * y;
    return res;
}
template <class T>
inline T inv(T w , T M){
    if (M <= 0) return -1;
    T x , y , d;
    d = id2(w , M , x , y);
    if (d != 1) return -1;
    x = ((x % M) + M) % M;
    return x;
}
} ;

 


 
namespace RNG{


inline unsigned int rand16(){return (bool(rand()&1) << 15) | rand();}
inline unsigned int rand32(){return (rand16() << 16) | rand16();}
inline ULL rand64(){return ((LL)rand32() << 32) | rand32();}
inline ULL random(LL l, LL r){return rand64() % (r - l) + l;}
int dice(){return rand() % 6;}
bool coin(){return bool(rand() % 2);}
} ;

 


 
namespace CLOCK{
DB s0, s1, rd, k, T;
inline DB getTime(){

    return 1.0 * clock() / CLOCKS_PER_SEC;

    timeval tv;
    gettimeofday(&tv, 0);
    return tv.tv_sec + tv.tv_usec * 1e-6;

}
 
inline void st0(DB _T = 0.98){T = _T, s0 = getTime();}
inline void st1(DB _k = 1.618){k = _k, s1 = getTime();}
inline void ed1(){rd = getTime() - s1;}
inline DB elapsed(){return getTime() - s0;}
inline bool safe(){return elapsed() + rd * k < T;}
} 

 


 
template<class T> PTT operator+(const PTT &p1, const PTT &p2) {
	return PTT(p1.fi + p2.fi, p1.se + p2.se);
}
 
template<class T> PTT operator-(const PTT &p1, const PTT &p2) {
	return PTT(p1.fi - p2.fi, p1.se - p2.se);
}
 
template<class T> PTT operator*(const PTT &lhs, T k){
    return PTT(lhs.fi * k, lhs.se * k);
}
 
namespace Math{
	typedef long long typec;
	

	typec GCD(typec a, typec b)
	{
		return b ? GCD(b, a % b) : a;
	}
	typec id2(typec a, typec b, typec& x, typec& y)
	{
		if(!b) return x = 1, y = 0, a;
		typec res = id2(b, a % b, x, y), tmp = x;
		x = y, y = tmp - (a / b) * y;
		return res;
	}
	

	typec power(typec x, typec k)
	{
		typec res = 1;
		while(k)
		{
			if(k&1) res *= x;
			x *= x, k >>= 1;
		}
		return res;
	}
	

	typec powerMod(typec x, typec k, typec m)
	{
		typec res = 1;
		while(x %= m, k)
		{
			if(k&1) res *= x, res %= m;
			x *= x, k >>=1;
		}
		return res;
	}
	
	typec inverse(typec a, typec p, typec t = 1)
	{
		typec pt = power(p, t);
		typec x, y;
	    y = id2(a, pt, x, y);
		return x < 0 ? x += pt : x;
	}
	
	typec id5(typec a, typec b, typec p, typec q)
	{
		typec x, y;
		y = id2(p, q, x, y);
		while(b < a) b += q / y;
		x *= b - a, x = p * x + a, x %= p * q;
		if(x < 0) x += p * q;
		return x;
	}
	
	const int id3 = 1000000;
	int prime[id3 + 1];
	int getPrime()
	{
		memset (prime, 0, sizeof (int) * (id3 + 1));
		for (int i = 2; i <= id3; i++)
		{
			if (!prime[i]) prime[++prime[0]] = i;
			for (int j = 1; j <= prime[0] && prime[j] <= id3 / i; j++)
			{
				prime[prime[j]*i] = 1;
				if (i % prime[j] == 0) break;
			}
		}
		return prime[0];
	}
	
	

	int factor[100][3], facCnt;
	int getFactors(int x)
	{
		facCnt = 0;
		int tmp = x;
		for(int i = 1; prime[i] <= tmp / prime[i]; i++)
		{
			factor[facCnt][1] = 1, factor[facCnt][2] = 0;
			if(tmp % prime[i] == 0)
				factor[facCnt][0] = prime[i];
			while(tmp % prime[i] == 0)
				factor[facCnt][2]++, factor[facCnt][1] *= prime[i], tmp /= prime[i];
			if(factor[facCnt][1] > 1) facCnt++;
		}
		if(tmp != 1)
			factor[facCnt][0] = tmp, factor[facCnt][1] = tmp, factor[facCnt++][2] = 1;
		return facCnt;
	}
	typec id0(typec n, typec k, typec p)
	{
		if(k > n) return 0;
		if(n - k < k) k = n - k;
		typec a = 1, b = 1, x, y;
		int pcnt = 0;
		for(int i = 1; i <= k; i++)
		{
			x = n - i + 1, y = i;
			while(x % p == 0) x /= p, pcnt++;
			while(y % p == 0) y /= p, pcnt--;
			x %= p, y %= p, a *= x, b *= y;
			b %= p, a %= p;
		}
		if(pcnt) return 0;
		id2(b, p, x, y);
		if(x < 0) x += p;
		a *= x, a %= p;
		return a;
	}
};



 
namespace Geo{
	
    const typec eps=1e-8;
    int dblcmp(double d){
        if (fabs(d)<eps)return 0;
        return d>eps?1:-1;
    }
    int sgn(double a) {return a<-eps?-1:a>eps;}
    inline double sqr(double x){return x*x;}
    struct id6{
		typec x,y;
		id6(){}
		id6(typec _x,typec _y):x(_x),y(_y){};
		void input(){
			scanf("%lf%lf",&x,&y);
		}
		void output(){
			printf("%.2f %.2f\n",x,y);
		}
		bool operator==(id6 a)const{
			return dblcmp(a.x-x)==0&&dblcmp(a.y-y)==0;
		}
		bool operator<(id6 a)const{
			return dblcmp(a.x-x)==0?dblcmp(y-a.y)<0:x<a.x;
		}
		typec len(){
			return hypot(x,y);
		}
		typec len2(){
			return x*x+y*y;
		}
		id6 operator + (const id6 &A) const{
			return id6(x + A.x , y + A.y);
		}
		id6 operator - (const id6 &A) const{
			return id6(x - A.x , y - A.y);
		}
		id6 operator * (const typec _x) const{
			return id6(x * _x , y * _x);
		}
		typec operator * (const id6 &A) const{
			return x * A.x + y * A.y;
		}
		typec operator ^ (const id6 &A) const{
			return x * A.y - y * A.x;
		}
		id6 operator / (const typec _p) const{
			return id6(x / _p , y / _p);
		}
		typec distance(id6 p){
			return hypot(x-p.x,y-p.y);
		}
		id6 add(id6 p){
			return id6(x+p.x,y+p.y);
		}
		id6 sub(id6 p){
			return id6(x-p.x,y-p.y);
		}
		id6 mul(typec b){
			return id6(x*b,y*b);
		}
		id6 div(typec b){
			return id6(x/b,y/b);
		}
		typec dot(id6 p){
			return x*p.x+y*p.y;
		}
		typec det(id6 p){
			return x*p.y-y*p.x;
		}
		typec rad(id6 a,id6 b){
			id6 p=*this;
			return fabs(atan2(fabs(a.sub(p).det(b.sub(p))),a.sub(p).dot(b.sub(p))));
		}
		id6 trunc(typec r){
			typec l=len();
			if (!dblcmp(l))return *this;
			r/=l;
			return id6(x*r,y*r);
		}
		id6 rotleft(){
			return id6(-y,x);
		}
		id6 rotright(){
			return id6(y,-x);
		}
		id6 rotate(id6 p,typec angle)

		{
			id6 v=this->sub(p);
			typec c=cos(angle),s=sin(angle);
			return id6(p.x+v.x*c-v.y*s,p.y+v.x*s+v.y*c);
		}
	};
 
	typec cross(id6 a,id6 b,id6 c){
		return (b.sub(a)).det(c.sub(a));
	}
}using namespace Geo;
 
template<class T> inline T& RD(T &x){
    

    

    char c; for (c = getchar(); c < '0'; c = getchar()); x = c - '0'; for (c = getchar(); '0' <= c && c <= '9'; c = getchar()) x = x * 10 + c - '0';
    

    return x;
}
 
int ____Case; template<class T> inline void OT(const T &x){
    

    

    

    

    printf("%d\n", x);
    

}
 






typedef long long ll;
using namespace std;
typedef vector<ll> vec;
typedef pair<int,int> pii;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int IINF=0x3f3f3f3f;

const int sz=3e5+9;

ll dp[sz][20];
ll use[sz][20],cnt[sz];
ll col[sz],tot;
ll n,m,k;

ll lef[sz];
ll righ[sz];
ll topmost;


vec findPos(ll l,ll r){
	

	vec v;
	ll p=upper_bound(col,col+tot,l)-col;
	if(p+1<tot) v.push_back(col[p+1]);
	if(p<tot) v.push_back(col[p]);
	if(p-1>=0) v.push_back(col[p-1]);
	if(p-2>=0) v.push_back(col[p-2]);
	p=upper_bound(col,col+tot,r)-col;
	if(p+1<tot) v.push_back(col[p+1]);
	if(p<tot) v.push_back(col[p]);
	if(p-1>=0) v.push_back(col[p-1]);
	if(p-2>=0) v.push_back(col[p-2]);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()),v.end());
	

	

		

	return v;
}
ll calcdis(int row,int cur,int to){
	if(cur>to){
		ll ans=abs(righ[row]-cur)+righ[row]-lef[row]+abs(lef[row]-to);
		return ans;
	}else{
		ll ans=abs(lef[row]-cur)+righ[row]-lef[row]+abs(righ[row]-to);
		return ans;
	}
}
ll solve(){
	if(lef[1]<IINF){
		use[0][0]=1;cnt[0]=1;
		dp[0][0]=0;
	}else{
		use[0][0]=(col[0]);cnt[0]=1;
		dp[0][0]=(col[0]-1);
	}
	ll last=0;
	ll globalans=INF;
	rep(i,1,n+1){
		if(lef[i]>=IINF) continue;
		

		

		vec posv=findPos(lef[i],righ[i]);
		cnt[i]=posv.size();
		rep(k,0,posv.size()){
			dp[i][k]=INF;
			ll pos=posv[k];
			use[i][k]=pos;
			rep(j,0,cnt[last]){
				ll cur=use[last][j];
				ll to=pos;
				

				

				

				dp[i][k]=min(dp[i][k],dp[last][j]+calcdis(i,cur,to));
				if(i==topmost){
					globalans=min(globalans,dp[last][j]+calcdis(i,cur,lef[i]));
					globalans=min(globalans,dp[last][j]+calcdis(i,cur,righ[i]));
				}
			}
				

		}
		last=i;
	}
	

	

	

	

	return globalans+last-1;
	


}

int main(){
	cin>>n>>m>>k>>tot;
	rep(i,0,n+1) lef[i]=IINF,righ[i]=-IINF;
	rep(i,0,k){
		ll x,y;
		cin>>x>>y;
		

		lef[x]=min(lef[x],y);
		righ[x]=max(righ[x],y);
		topmost=max(topmost,x);
	}
	

	rep(i,0,tot) cin>>col[i];
	sort(col,col+tot);
	ll ans=solve();
	cout<<ans<<endl;

	return 0;
}
