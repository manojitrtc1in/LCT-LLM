









































using namespace std;


	


















































struct debugger
{
 template<typename T> debugger& operator,(const T& v)
 {
  cerr<<v<<" ";
  return *this;
 }
} dbg;


	
	
	template<class T> void DISP(const char *s, T x, int n) {cerr << "[" << s << ": "; FOR(i,0,n) cerr << x[i] << " "; cerr << "]" << endl;}
	

	
	
	


typedef long long LL;
typedef unsigned long long ULL;
typedef long long int64;
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


int64 pow(int64 b, int64 e, int64 m) { int64 t = 1; for (; e; e >>= 1, b = b * b % m) e & 1 ? t = t * b % m : 0; return t; }
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

long long id2(long long n, long long p)
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



long long id4(long long n, long long k, long long p)
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



long long id6(long long n, long long k, long long p)
{
    

    if (k < p) return id4(n,k,p);
    long long q_n, r_n, q_k, r_k, choose;
    q_n = n / p;
    r_n = n % p;
    q_k = k / p;
    r_k = k % p;
    choose = id4(r_n, r_k, p);
    

    

    
    choose *= id6(q_n, q_k, p);
    return choose % p;
}


long long choose_mod(long long n, long long k, long long p)
{
    

    if (k < 0 || n < k) return 0;
    if (k == 0 || k == n) return 1;
    

    if (id2(n,p) > id2(k,p) + id2(n-k,p))
		return 0;
    

    return id6(n,k,p);
}

LL fact(ULL n)
{
    return static_cast<LL>(tgammal(n + 1));
}

inline LL id0(LL n, LL k, LL p)
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
typename T::const_iterator id1(const T &A)
{
    typedef typename T::value_type pair_type;
    return max_element(A.begin(), A.end(), pairCompare<typename T::value_type>);
}
template<class T>
typename T::const_iterator id3(const T &A)
{
    typedef typename T::value_type pair_type;
    return min_element(A.begin(), A.end(), pairCompare<typename T::value_type>);
}



template<class edge> struct Graph
{
	vector<vector<edge> > adj;
	Graph(int n) {adj.clear (); adj.resize (n + 5);}
	Graph() {adj.clear (); }
	void resize(int n) {adj.resize (n + 5); }
	void add(int s, edge e){adj[s].push_back (e);}
	void del(int s, edge e) {adj[s].erase (find (iter (adj[s]), e)); }
	vector<edge>& operator [](int t) {return adj[t];}
};

struct Point
{
	int X,Y;
};
bool operator <(Point A,Point B)
{
	return (A.X==B.X)?(A.Y<B.Y):(A.X<B.X);
}

template <typename T> class id7
{
private:
    T x;
    T y;

public:
    explicit id7(const T& x=0, const T& y=0) : x(x), y(y) {}
    id7(const id7<T>& src) : x(src.x), y(src.y) {}
    virtual ~id7() {}

    

    inline T X() const { return x; }
    inline T Y() const { return y; }
    inline T X(const T& x) { this->x = x; }
    inline T Y(const T& y) { this->y = y; }

    

    inline id7<T> operator-() const
        { return id7<T>(-x, -y); }

    inline id7<T> operator+() const
        { return id7<T>(+x, +y); }

    inline id7<T> operator+(const id7<T>& v) const
        { return id7<T>(x+v.x, y+v.y); }

    inline id7<T> operator-(const id7<T>& v) const
        { return id7<T>(x-v.x, y-v.y); }

    inline id7<T> operator*(const T& s) const
        { return id7<T>(x*s, y*s); }

    

    inline T operator*(const id7<T>& v) const
        { return x*v.x + y*v.y; }

    

    inline T norm() const { return sqrt(x*x + y*y); }

    

    static T angle(const id7<T>& v1, const id7<T>& v2)
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
int id5(string s, string delim=" ") {int count=0; for(int i=0; i<s.size(); i++) if( (i!=0 || delim.find(s[i-1])!= -1) && delim.find(s[i])== -1) count++; return count;}
string getWord(string s, int j, string delim=" ") {int count=0; string t; for(int i=0; i<s.size(); i++) {if (delim.find(s[i]) == -1) t+=s[i]; else {if (i!=0 && delim.find(s[i-1]) == -1) count++; if (count>j) return t; t="";}} return t;}
string getDelimiter(string s, int j, string delim=" ") {int count=0; string t; for(int i=0; i<s.size(); i++) {if (delim.find(s[i]) == -1) t+=s[i]; else {if (i==0 || delim.find(s[i-1]) != -1) count++; if (count>j) return t; t="";}} return t;}



	void compare(int test_number, stringstream& input, stringstream& output,
	 stringstream& solution)
	{
		if (solution.str() != output.str())
		{
			cout << "Test 
				 << "    Expected: 
				 << "    Received: 
		}
	}


	if (!(x)) \
	{ \
		cout << "ERROR!! Assert " << 
			 << " value = " << var << endl \
			 << " on line " << __LINE__  << endl \
			 << " in file " << __FILE__ << endl;  \
		exit(1); \
	}



void readonly_vector(const vector<int>& v) {}
void modify_vector(vector<int>& v) {  }










static int m,n;


int main(int argc, char** argv)
{
	srand ( unsigned ( time(NULL) ) );
	ios_base::sync_with_stdio(false);





	scanf("%d", &m);
	int q[m]; CLR(q);
	FOR(i,0,m)	scanf("%d", &q[i]);
	sort(q,q+m);
	int smallest = q[0];
	
	scanf("%d", &n);
	int a[n]; CLR(a);
	FOR(i,0,n)	scanf("%d", &a[i]);
	sort(a,a+n);	
	
	LL cost = 0;
	int index = n;
	while (index-smallest-2 > 0)
	{
		cost += accumulate(a+index-smallest, a+index, 0);
		index -= smallest + 2;
	}
	cost += accumulate(a+MAX(0,index-smallest), a+index, 0);
	printf("%lld", cost);
	










    return 0;
}
