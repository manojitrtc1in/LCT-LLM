 

#define LOCAL
 
#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>
 
using namespace std;
 
#define DO(n) for ( int ____n ## __line__ = n; ____n ## __line__ -- ; )
 
#define ALL(A) A.begin(), A.end()
#define SZ(A) int(A.size())
#define PB push_back
#define MP(A, B) make_pair(A, B)
#define fi first
#define se second
 
#define Rush for(int ____T=RD(); ____T--;)
 
#pragma comment(linker, "/STACK:36777216")


#define Ruby system("ruby main.rb")
#define Haskell system("runghc main.hs")
#define Python system("python main.py")
#define Pascal system("fpc main.pas")
 
typedef long long LL;


typedef long double DB;
typedef unsigned UINT;
typedef unsigned long long ULL;
typedef pair<int , int> PII;
 
typedef vector<int> VI;
template<class T> inline T& RD(T &);
template<class T> inline void OT(const T &);
inline LL RD(){LL x; return RD(x);}
inline DB& RF(DB &);
inline DB RF(){DB x; return RF(x);}
inline char* RS(char *s);
 
 
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
inline DB& RF(DB &a, DB &b){RF(a), RF(b); return a;}
inline DB& RF(DB &a, DB &b, DB &c){RF(a), RF(b), RF(c); return a;}
inline DB& RF(DB &a, DB &b, DB &c, DB &d){RF(a), RF(b), RF(c), RF(d); return a;}
inline DB& RF(DB &a, DB &b, DB &c, DB &d, DB &e){RF(a), RF(b), RF(c), RF(d), RF(e); return a;}
inline DB& RF(DB &a, DB &b, DB &c, DB &d, DB &e, DB &f){RF(a), RF(b), RF(c), RF(d), RF(e), RF(f); return a;}
inline DB& RF(DB &a, DB &b, DB &c, DB &d, DB &e, DB &f, DB &g){RF(a), RF(b), RF(c), RF(d), RF(e), RF(f), RF(g); return a;}
inline void RS(char *s1, char *s2){RS(s1), RS(s2);}
inline void RS(char *s1, char *s2, char *s3){RS(s1), RS(s2), RS(s3);}
 
template<class T> inline void RST(T &A){memset(A, 0, sizeof(A));}
template<class T> inline void FLC(T &A, int x){memset(A, x, sizeof(A));}
 
template<class T> inline T& SRT(T &A){sort(ALL(A)); return A;}
template<class T, class C> inline T& SRT(T &A, C B){sort(ALL(A), B); return A;}
template<class T> inline T& UNQ(T &A){A.resize(unique(ALL(SRT(A)))-A.begin());return A;}
 


 
 

 
const int dx4[] = {-1, 0, 1, 0};
const int dy4[] = {0, 1, 0, -1};
 
const int dx8[] = {-1, 0, 1, 0 , -1 , -1 , 1 , 1};
const int dy8[] = {0, 1, 0, -1 , -1 , 1 , -1 , 1};
 
const int dxhorse[] = {-2 , -2 , -1 , -1 , 1 , 1 , 2 , 2};
const int dyhorse[] = {1 ,  -1 , 2  , -2 , 2 ,-2 , 1 ,-1};
 
const int MOD = 1e9;


const int INF = 0x3f3f3f3f;
const LL INFF = 1LL << 60;
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




namespace BO{
 
inline bool _1(int x, int i){return bool(x&1<<i);}
inline bool _1(LL x, int i){return bool(x&1LL<<i);}
inline LL _1(int i){return 1LL<<i;}
 
template<class T> inline bool odd(T x){return x&1;}
template<class T> inline bool even(T x){return !odd(x);}
template<class T> inline T low_bit(T x) {return x & -x;}
inline int count_bits(int x){return __builtin_popcount(x);}
inline int count_bits(LL x){return __builtin_popcountll(x);}
 
} using namespace BO;



namespace NT{


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
 
inline int pow(int a, int b){
    int c(1); while (b){
        if (b&1) MUL(c, a);
        MUL(a, a), b >>= 1;
    }
    return c;
}
 
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



 




 
 



 
namespace Math{
	typedef long long typec;
	

	typec GCD(typec a, typec b)
	{
		return b ? GCD(b, a % b) : a;
	}
	typec extendGCD(typec a, typec b, typec& x, typec& y)
	{
		if(!b) return x = 1, y = 0, a;
		typec res = extendGCD(b, a % b, x, y), tmp = x;
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
	    y = extendGCD(a, pt, x, y);
		return x < 0 ? x += pt : x;
	}
	
	typec linearCongruence(typec a, typec b, typec p, typec q)
	{
		typec x, y;
		y = extendGCD(p, q, x, y);
		while(b < a) b += q / y;
		x *= b - a, x = p * x + a, x %= p * q;
		if(x < 0) x += p * q;
		return x;
	}
	
	const int PRIMERANGE = 1000000;
	int prime[PRIMERANGE + 1];
	int getPrime()
	{
		memset (prime, 0, sizeof (int) * (PRIMERANGE + 1));
		for (int i = 2; i <= PRIMERANGE; i++)
		{
			if (!prime[i]) prime[++prime[0]] = i;
			for (int j = 1; j <= prime[0] && prime[j] <= PRIMERANGE / i; j++)
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
	typec combinationModP(typec n, typec k, typec p)
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
		extendGCD(b, p, x, y);
		if(x < 0) x += p;
		a *= x, a %= p;
		return a;
	}
};





namespace Geo{
	#define typec double
    const typec eps=1e-8;
    int dblcmp(double d){
        return d < -eps ? -1 : d > eps;
    }
    int sgn(double a) {return a<-eps?-1:a>eps;}
    inline double sqr(double x){return x*x;}
};






 

template<class T> inline T& RD(T &x){
    

    

    char c; for (c = getchar(); c < '-'; c = getchar());
    if (c == '-'){x = '0' - getchar(); for (c = getchar(); '0' <= c && c <= '9'; c = getchar()) x = x * 10 + '0' - c;}
    else {x = c - '0'; for (c = getchar(); '0' <= c && c <= '9'; c = getchar()) x = x * 10 + c - '0';}
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


 
#include <unordered_map>
#include <unordered_set>
 

const int N = 1e6 + 9;
int a[N] , b[N] , ca[N];
int n , m;
LL cyc;
vector<LL> meet;
LL k;
bool check(LL x) {
	LL r = x;
	for (int i = 0 ; i < SZ(meet) ; ++i) {
		LL u = meet[i] , v = cyc;
		if (x < u) continue;
		LL uu = (x - u) / v ;
		r -= uu + 1;
	}
	return r >= k;
}


void solve(){
	RD(n , m);
	RD(k);
	FLC(ca , -1);
	for (int i = 0 ; i < n ; ++i) {
		ca[RD(a[i])] = i;
	}
	for (int i = 0 ; i < m ; ++i) {
		RD(b[i]);
	}
	LL x , y;
	LL r = Math::extendGCD(n , m , x , y);
	cyc = 1ll * n * m / r;
	meet.clear();
	for (int i = 0 ; i < m ; ++i) if (ca[b[i]] != -1){
		LL p = ca[b[i]] , q = i;
		LL xx = x , yy = y;
		if (abs(p - q) % r != 0) continue;
		xx *= (q - p) / r;
		yy *= -(q - p) / r;
		if (xx < 0) {
			LL add = (-xx + m / r - 1) / (m / r);
			xx += add * m / r;
			yy += add * n / r;
		}
		if (yy < 0) {
			LL add = (-yy + n / r - 1) / (n / r);
			xx += add * m / r;
			yy += add * n / r;
		}
		if (xx > 0 && yy > 0) {
			LL sub = min(xx / (m / r) , yy / (n / r));
			xx -= m / r * sub;
			yy -= n / r * sub;
		}
		meet.PB(xx * n + p + 1);
		

	}

	LL low = 1 , high = k * (n + m) * 2 , mid;
	LL ans = high;
	do {
		mid = low + high >> 1;
		if (check(mid)) {
			checkMin(ans , mid);
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	} while (low <= high);
	OT(ans);
}
int main(){
	solve();
}