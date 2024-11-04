


#define _CRT_SECURE_NO_DEPRECATE

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fcntl.h>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory.h>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unistd.h>
#include <tr1/unordered_map>
#include <tr1/unordered_set>
#include <utility>
#include <vector>
#pragma comment(linker, "/STACK:128000000")

using namespace std;

#ifndef ONLINE_JUDGE
	#define DEBUG
#endif

#define INF (1LL<<32)
#define LINF (long long) (1E18)
#define NINF (-1*1E9)
#define EPS (1E-9)
#define RAND ((rand()<<15)+rand())

#define FO(i,s,e,p)  for(int i=(s);i<(e);i+=p)
#define FOD(i,s,e,p) for(int i=(s);i>(e);i-=p)

#define FOR(_a,_f,_t) for(int _a=(_f),__t=(_t);_a<__t;_a++)
#define FOREQ(_a,_f,_t) for(int _a=(_f),__t=(_t);_a<=__t;_a++)
#define FORZ(__i,__n) FOR(__i,0,__n)
#define RFOR(i,a,b)  for(int(i)=(a),_b(b);(i)>=_b;--(i))
#define FOREACH(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define TR(c,itr)    for (typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)
#define TRN(c,itr,n)    for (typeof((c).begin()) itr=(c).begin(), int(i)=0; itr!=(c).end() && (i)<int(n); itr++,(i)++)

#define present(c,x)  ((c).find(x) != (c).end())    

#define cpresent(c,x) (find(all(c),x) != (c).end())

#define ABS(x)   ((x)<0?-(x):(x))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define SQR(a)   ((a)*(a))
#define SUM(a)   accumulate(all(a),string())

#define FILL(arr,val) memset((arr),(val),sizeof(arr))
#define CLR(a)        memset((a),0,sizeof(a))
#define CPY(dest,src) memcpy((dest),(src),sizeof(dest))

#define ALL(a)       (a).begin(),(a).end()
#define SZ(a)        ((int)(a).size())
#define UNIQ(a)      sort(all(a)); (a).erase(unique(all(a)),(a).end())
#define IDX(arr,ind) (lower_bound(all(arr),ind)-arr.begin())

#define fst first
#define snd second
#define X   first
#define Y   second
#define pb  push_back
#define mp  make_pair
#define tri(a,b,c) mp(a,mp(b,c))

#define LOG(a) (cerr<<__LINE__<<": "#a" = "<<(a)<<endl)
#define DBG(...) (__VA_ARGS__)
#define debug(args...) {dbg,args; cerr<<endl;}
#define dline cerr<<endl
struct debugger
{
 template<typename T> debugger& operator,(const T& v)
 {
  cerr<<v<<" ";
  return *this;
 }
} dbg;
#define oo 0x3F3F3F3F
#ifdef DEBUG
	#define cvar(x) cerr << "<" << #x << ": " << x << ">"
	#define evar(x) cvar (x) << endl
	template<class T> void DISP(const char *s, T x, int n) {cerr << "[" << s << ": "; FOR(i,0,n) cerr << x[i] << " "; cerr << "]" << endl;}
	#define disp(x,n) DISP(#x " to " #n, x, n)
#else
	#define cvar(...) ({})
	#define evar(...) ({})
	#define disp(...) ({})
#endif

typedef long long LL;
typedef long long int64;
typedef unsigned long long ULL;
typedef unsigned long long uint64;
typedef unsigned int uint;
typedef long double LD;

typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef pair<int,double> PID;
typedef pair<LL,LL> PLL;
typedef pair<int,PII> TRI;

typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<PID> VID;
typedef vector<PLL> VLL;
typedef vector<TRI> VT;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VII> VVII;
typedef vector<VLL> VVLL;
typedef vector<VT> VVT;

typedef complex<double> pt;
typedef complex<LL> pti;

const long double PI = acos(-1);

template<class T> inline T sqr(T x)      {return x * x;}
template<class T> inline T min(T a, T b) {return (a<b)?a:b;}
template<class T> inline T max(T a, T b) {return (a>b)?a:b;}
template<class T> inline bool chkmin(T &a, T b) {return a > b ? a = b, true : false;}
template<class T> inline bool chkmax(T &a, T b) {return a < b ? a = b, true : false;}
template<class T> void swap(const T &x, const T &y) {T z=x; x=y; y=z;}


template <typename T> T gcd(T x, T y) {for (T t; x; t = x, x = y % x, y = t); return y; }
LL lcm(LL n1, LL n2) {return n1==0 && n2==0? 0 : ABS(n1*n2/gcd(n1,n2));}
bool is_equal(LD v1, LD v2) {return ABS(v1-v2)<EPS;}
bool is_less(LD v1, LD v2) {return v1-v2<=EPS;}

template <class T>
int num_digits(T number)
{
    int digits = 0;
	

    if (number < 0)
		digits = 1;
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}

LL pow(LL b, LL e, LL m) {
    LL t = 1;
    for (; e; e >>= 1, b = b * b % m) e & 1 ? t = t * b % m : 0;
    return t;
}

bool is_prime(int m) {
	int u=sqrt(m);
	for (int i=2; i<=u+1; i++)
	{
		if (m%i==0)
		{
			return false;
		}
	}
	return true;
}

long long factorial_exponent(long long n, long long p)
{
    long long ex = 0;
    do
    {
        n /= p;
        ex += n;
    } while(n > 0);
    return ex;
}

long long invert_mod(long long k, long long m)
{
    if (m == 0) return (k == 1 || k == -1) ? k : 0;
    if (m < 0) m = -m;
    k %= m;
    if (k < 0) k += m;
    int neg = 1;
    long long p1 = 1, p2 = 0, k1 = k, m1 = m, q, r, temp;
    while(k1 > 0) {
        q = m1 / k1;
        r = m1 % k1;
        temp = q*p1 + p2;
        p2 = p1;
        p1 = temp;
        m1 = k1;
        k1 = r;
        neg = !neg;
    }
    return neg ? m - p2 : p2;
}



long long choose_mod_two(long long n, long long k, long long p)
{
    

    n %= p;
    

    if (n < k) return 0;
    if (k == 0 || k == n) return 1;
    

    if (k > n/2) k = n-k;
    

    long long num = n, den = 1;
    for(n = n-1; k > 1; --n, --k)
    {
        num = (num * n) % p;
        den = (den * k) % p;
    }
    

    den = invert_mod(den,p);
    return (num * den) % p;
}



long long choose_mod_one(long long n, long long k, long long p)
{
    

    if (k < p) return choose_mod_two(n,k,p);
    long long q_n, r_n, q_k, r_k, choose;
    q_n = n / p;
    r_n = n % p;
    q_k = k / p;
    r_k = k % p;
    choose = choose_mod_two(r_n, r_k, p);
    

    

    
    choose *= choose_mod_one(q_n, q_k, p);
    return choose % p;
}


long long choose_mod(long long n, long long k, long long p)
{
    

    if (k < 0 || n < k) return 0;
    if (k == 0 || k == n) return 1;
    

    if (factorial_exponent(n,p) > factorial_exponent(k,p) + factorial_exponent(n-k,p))
		return 0;
    

    return choose_mod_one(n,k,p);
}

LL fact(ULL n)
{
    return static_cast<LL>(tgammal(n + 1));
}

inline LL permute_mod(LL n, LL k, LL p)
{
	return (choose_mod(n,k,p) * fact(k)%p)%p;
}


int RandomNumber () { return (rand()%100); }
struct c_unique {
  int current;
  c_unique() {current=0;}
  int operator()() {return ++current;}
} UniqueNumber;



template<class T>
bool pairCompare(const T & x, const T & y)
{
  return x.second < y.second;
}
template<class T>
typename T::const_iterator map_max_element(const T &A)
{
    typedef typename T::value_type pair_type;
    return max_element(A.begin(), A.end(), pairCompare<typename T::value_type>);
}
template<class T>
typename T::const_iterator map_min_element(const T &A)
{
    typedef typename T::value_type pair_type;
    return min_element(A.begin(), A.end(), pairCompare<typename T::value_type>);
}



template<class Edge> struct Graph
{
	vector<vector<Edge> > adj;
	Graph(int n) {adj.clear (); adj.resize (n + 5);}
	Graph() {adj.clear (); }
	void resize(int n) {adj.resize (n + 5); }
	void add(int s, Edge e){adj[s].push_back (e);}
	void del(int s, Edge e) {adj[s].erase (find (iter (adj[s]), e)); }
	vector<Edge>& operator [](int t) {return adj[t];}
};

struct Point { int X,Y; };
bool operator<(Point A,Point B)
{
	return (A.X==B.X)?(A.Y<B.Y):(A.X<B.X);
}

template <typename T> class Vector2D
{
private: T x, y;
public:
    explicit Vector2D(const T& x=0, const T& y=0) : x(x), y(y) {}
    Vector2D(const Vector2D<T>& src) : x(src.x), y(src.y) {}
    virtual ~Vector2D() {}

    

    inline T X() const { return x; }
    inline T Y() const { return y; }
    inline T X(const T& x) { this->x = x; }
    inline T Y(const T& y) { this->y = y; }

    

    inline Vector2D<T> operator-() const
        { return Vector2D<T>(-x, -y); }

    inline Vector2D<T> operator+() const
        { return Vector2D<T>(+x, +y); }

    inline Vector2D<T> operator+(const Vector2D<T>& v) const
        { return Vector2D<T>(x+v.x, y+v.y); }

    inline Vector2D<T> operator-(const Vector2D<T>& v) const
        { return Vector2D<T>(x-v.x, y-v.y); }

    inline Vector2D<T> operator*(const T& s) const
        { return Vector2D<T>(x*s, y*s); }

    

    inline T operator*(const Vector2D<T>& v) const
        { return x*v.x + y*v.y; }

    

    inline T norm() const { return sqrt(x*x + y*y); }

    

    static T angle(const Vector2D<T>& v1, const Vector2D<T>& v2)
    {
        return acos( (v1 * v2) / (v1.norm() * v2.norm()) );
    }
};




LL toInt(string s) {stringstream in(s, ios_base::in); LL result; in >> result; return result;}
LD toDouble(string s) {stringstream in(s, ios_base::in); LD result; in >> result; return result;}
string toString(LL n) {stringstream out(ios_base::out); out << n; return out.str();}
string toString(LD d, int precision = -1) {stringstream out(ios_base::out); if (precision >= 0) {out.precision(precision); out.setf(ios::fixed);} out << d; string s = out.str();
	bool nonZero = false; for(int i=0; i<s.size(); ++i) if (s[i]!='0' && s[i]!='.' && s[i]!='-') nonZero = true; if (s[0]=='-' && !nonZero) return s.substr(1); else return s;}
string toString(int n) {return toString((LL)n);}
string toString(const string &s) {return s;}
template <class U, class V> string toString(pair<U,V> u) {return toString("(") + toString(u.first) + toString(",") + toString(u.second) + ")";}
template <class T> string toString(const vector<T> &v, string delim=",") {string s="("; for(int i=0;i<v.size();i++) {if(i!=0)s+=delim; s += toString(v[i]);} return s+")";}
template <class T> string toString(const set<T> &t, string delim=",") {string s="{"; for(typename set<T>::const_iterator it=t.begin(); it!=t.end(); it++) {if(it!=t.begin()) s+=delim+" "; s += toString(*it);} return s+"}";}
template <class U, class V> string toString(const map<U,V> &t, string delim=",") {string s="{"; for(typename map<U,V>::const_iterator it=t.begin(); it!=t.end(); it++) {if(it!=t.begin()) s+=delim+" "; s += toString(it->first) + "->" + toString(it->second);} return s+"}";}
int getNumWords(string s, string delim=" ") {int count=0; for(int i=0; i<s.size(); i++) if( (i!=0 || delim.find(s[i-1])!= -1) && delim.find(s[i])== -1) count++; return count;}
string getWord(string s, int j, string delim=" ") {int count=0; string t; for(int i=0; i<s.size(); i++) {if (delim.find(s[i]) == -1) t+=s[i]; else {if (i!=0 && delim.find(s[i-1]) == -1) count++; if (count>j) return t; t="";}} return t;}
string getDelimiter(string s, int j, string delim=" ") {int count=0; string t; for(int i=0; i<s.size(); i++) {if (delim.find(s[i]) == -1) t+=s[i]; else {if (i==0 || delim.find(s[i-1]) != -1) count++; if (count>j) return t; t="";}} return t;}

#ifndef ONLINE_JUDGE
	void compare(int test_number, stringstream& input, stringstream& output,
	 stringstream& solution)
	{
		if (solution.str() != output.str())
		{
			cout << "Test #" << test_number << ": " << input.str() << endl
				 << "    Expected: #" << solution.str() << "#" << endl
				 << "    Received: #" << output.str() << "#" << endl;
		}
	}
#endif
#define ASSERT(x,var) \
	if (!(x)) \
	{ \
		cout << "ERROR!! Assert " << #x << " failed" << endl \
			 << " value = " << var << endl \
			 << " on line " << __LINE__  << endl \
			 << " in file " << __FILE__ << endl;  \
		exit(1); \
	}



void readonly_vector(const vector<int>& v) {}
void modify_vector(vector<int>& v) {  }
template <class T>
inline void process_digits(T number)
{
	do {
		int digit = number%10;
		

		number /= 10;
	} while (number > 0);
}














struct triplet
{
	int x,y;
	LL z;
	triplet(int _x,int _y,LL _z) : x(_x),y(_y),z(_z) {}
};

inline LL gcd_iter(int a, int b) {
	LL cnt;
	int t;
	while (b != 0) {
		cnt += a/b;
		t = b;
		b = a % b;
		a = t;
	}
	return cnt;
}

inline LL gcd_fast(int a, int b)
{
	LL cnt;
    while (true)
    {
		cnt+=MAX(a,b)/MIN(a,b);
		if ((a %= b) == 0) return b;
        if ((b %= a) == 0) return a;
    }
	return cnt;
}

int main(int argc, char** argv)
{
	srand(unsigned(time(NULL)));
	ios_base::sync_with_stdio(false);





	int n;
	scanf("%d", &n);
	vector<triplet> lookup;
	FOR(i,0,n)
	{
		int a,b;
		scanf("%d%d", &a,&b);
		printf("%lld\n", gcd_iter(a,b));
		continue;
		
		bool found = false;
		FOREACH(lookup,itr)
		{
			int X = MIN(a,b), Y = MAX(a,b);
			if (itr->x == X && itr->y == Y)
			{
				printf("%lld\n", itr->z);
				found = true;
			}
			break;
		}
		if (found) continue;
		
		LL ans = 0LL;
		int X = MIN(a,b), Y = MAX(a,b);
		while (X>0 && Y>0)
		{
			if (X==Y)
			{
				X-=Y;
				ans++;
				continue;
			}
			int tmpa = MIN(X,Y);
			int tmpb = MAX(X,Y);
			X = tmpa; Y=tmpb;
			Y-=X;
			ans++;
		}
		lookup.pb(triplet(MIN(a,b),MAX(a,b),ans));
		printf("%lld\n", ans);
	}


    return 0;
}
