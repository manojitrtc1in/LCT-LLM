














using namespace std; 

typedef long long LL; 
typedef unsigned long long ULL; 
typedef short int int16; 
typedef long double ldouble; 

typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = 1e9+1; 
const LL INF1 = 1e18 + 1; 
const int size = 1e5 + 2; 
const double eps = 0.0001; 
const ldouble PI = 3.1415926535897932384626433832795;

const int MOD = 1000000007;
const int INF2 = 0x3f3f3f3f;
const LL INFF = 1LL << 60;








void solution(); 
void include_file(); 
LL bin_search(LL left, LL right); 

int main(){ 
ios_base::sync_with_stdio(false);




solution(); 
return 0; 
} 
void include_file(){ 
freopen("input.txt","r",stdin); 
freopen("output.txt","w",stdout); 
} 

vector <vector<int> > g;
int was[100];
void dfs(int v)
{
	if (was[v]) return;
	was[v]=1;
	for (int i=0;i<g[v].size();++i)
	{
		dfs(g[v][i]);
	}
}
int bfs(int s,int toto)
{	
queue<int> q;
vector<bool> used (1001);
vector<int> d (1001), p (1001);

q.push (s);
used[s] = true;
p[s] = 1;
d[s]=0;
while (!q.empty()) {
	int v = q.front();
	q.pop();
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (!used[to]) {
			used[to] = true;
			q.push (to);
			d[to] = d[v] + 1;
			p[to] = v;
		}
	}
}

return d[toto];
}
void yes()
{
	cout<<"YES";
}
void no()
{
	cout<<"NO";
}
namespace bits
{
	template<typename X> inline X MAX(const X& a, const X& b) 
{ return b & ((a-b) >> 31) | a & (~(a-b) >> 31);}
template<typename X> inline X MIN(const X& a, const X& b) 
{ return a & ((a-b) >> 31) | b & (~(a-b) >> 31);}



bool check2(const LL n)
{
	return 	n > 0 && (n & (n - 1));
}


LL id4(const LL n, const LL m)
{
	return m & (n-1);
}
template<typename X> 
void SWAP(X &a, X &b)
{
	a^=b;
	b^=a;
	a^=b;
}
}


void solution() 
{ 
	int a,b,c,m;
	cin>>a>>b>>c>>m;
	if(m>0)
	{
	vector<int>valusb,valps;
	for(int i=0;i<m;++i)
	{
		int val;
		string s;
		cin>>val>>s;
		if(s=="USB")
		valusb.pb(val);
		else valps.pb(val);
	}
	sort(all(valusb));
	sort(all(valps));
		
	LL res=0, k=0;
	vector<int> zzz;
	if(a>valusb.size())
	{
		for(int i=0;i<valusb.size();++i)
		{
			k++;
			res+=valusb[i];
		}
	}
	else
	{
		int i=0;
		for(;i<a;++i)
		{
			k++;
			res+=valusb[i];
		}
		for(;i<valusb.size();++i)
		zzz.pb(valusb[i]);
	}
	
	if(b>valps.size())
	{
		for(int i=0;i<valps.size();++i)
		{
			k++;
			res+=valps[i];
		}
	}
	else
	{
		int i=0;
		for(;i<b;++i)
		{
			k++;
			res+=valps[i];
		}
		for(;i<valps.size();++i)
		zzz.pb(valps[i]);
	}
	
	sort(all(zzz));
	
	int j=0;
	if(c<=zzz.size())
	for(int i=0;i<c;++i)
	{
		k++;
		res+=zzz[j];
		j++;
	}
	
	else for(int i=0;i<zzz.size();++i)
	{
		k++;
		res+=zzz[i];
	}
	cout<<k<<" "<<res;
	}
	else cout<<"0 0";
}


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
inline int lg2(int a){return 31 - clz(a);}
inline int lg2(LL a){return 63 - clz(a);}
inline int count_bits(int x){return __builtin_popcount(x);}
inline int count_bits(LL x){return __builtin_popcountll(x);}

} using namespace BO;



namespace NT{
inline LL id3(LL a, LL b){return a*b/__gcd(a,b);}
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




 



namespace RNG{


inline unsigned int rand16(){return ((rand()) << 15) ^ rand();}
inline unsigned int rand32(){return (rand16() << 16) | rand16();}
inline ULL rand64(){return ((LL)rand32() << 32) | rand32();}
inline ULL random(LL l, LL r){return l == r ? l : rand64() % (r - l) + l;}
int dice(){return rand() % 6;}
bool coin(){return bool(rand() % 2);}
} using namespace RNG;
namespace Math{
	typedef long long typec;
	

	typec GCD(typec a, typec b)
	{
		return b ? GCD(b, a % b) : a;
	}
	typec id1(typec a, typec b, typec& x, typec& y)
	{
		if(!b) return x = 1, y = 0, a;
		typec res = id1(b, a % b, x, y), tmp = x;
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
	    y = id1(a, pt, x, y);
		return x < 0 ? x += pt : x;
	}
	
	typec id5(typec a, typec b, typec p, typec q)
	{
		typec x, y;
		y = id1(p, q, x, y);
		while(b < a) b += q / y;
		x *= b - a, x = p * x + a, x %= p * q;
		if(x < 0) x += p * q;
		return x;
	}
	
	const int id2 = 1000000;
	int prime[id2 + 1];
	int getPrime()
	{
		memset (prime, 0, sizeof (int) * (id2 + 1));
		for (int i = 2; i <= id2; i++)
		{
			if (!prime[i]) prime[++prime[0]] = i;
			for (int j = 1; j <= prime[0] && prime[j] <= id2 / i; j++)
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
		id1(b, p, x, y);
		if(x < 0) x += p;
		a *= x, a %= p;
		return a;
	}
};using namespace Math;
