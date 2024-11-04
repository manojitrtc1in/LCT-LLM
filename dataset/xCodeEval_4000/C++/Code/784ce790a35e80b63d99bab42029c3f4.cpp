
#include <set>          
#include <map>           
#include <list>
#include <ctime>
#include <deque>   
#include <queue>      
#include <bitset>        
#include <vector>
#include <list>
#include <stack>
#include <random>		 
#include <string>       
#include <numeric>      
#include <utility>     
#include <iterator> 
#include <fstream>
#include <iostream> 
#include <iomanip>  
#include <algorithm> 
#include <functional>  
#include <unordered_map>  
#include <unordered_set>
#include <cmath>   
#include <cstring>  
#include <cstdio>    
#if !defined Header_DR
#define Header_DR
#pragma warning(disable:4996)
#define intt long long
#define cin user_input
#define cout output


#define code_jam 0
#define code_chef 0
#define rep(i,a,b) for(long long i=a;i<b;i++)
#define all(v) v.begin(),v.end() 
#define ve vector
#define pb push_back                    
#define srt(x) sort(x.begin(),x.end())         
#define mod static_cast<long long> (1000000007)     
#define sumx(x) accumulate(x.begin(),x.end(),0LL)
#define endl "\n"
#endif
#ifdef _WIN32
#define getcx _getchar_nolock
#endif
#ifdef __unix__
#define getcx getchar_unlocked
#endif
#ifdef __APPLE__
#define getcx getchar_unlocked
#endif
#if!defined FAST_IO
#undef cin
#undef cout
#define FAST_IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define cin user_input
#define cout output
#endif
using namespace std;
namespace Xrocks {}
using namespace Xrocks;
namespace Xrocks
{
	class in {}user_input;
	class out {}output;
	in& operator >> (in& X, int &Y)
	{
		scanf("%d", &Y);
		return X;
	}
	in& operator >> (in& X, char *Y)
	{
		scanf("%s", Y);
		return X;
	}
	in& operator >> (in& X, float &Y)
	{
		scanf("%f", &Y);
		return X;
	}
	in& operator >> (in& X, double &Y)
	{
		scanf("%lf", &Y);
		return X;
	}
	in& operator >> (in& X, char &C)
	{
		scanf("%c", &C);
		return X;
	}
	in& operator >> (in& X, string &Y)
	{
#undef cin
		cin >> Y;
#define cin user_input
		return X;
	}
	in& operator >> (in& X, long long &Y)
	{
		scanf("%lld", &Y);
		return X;
	}
	template<typename T>
	in& operator >> (in& X, vector<T> &Y)
	{
		for (auto &x : Y)
			cin >> x;
		return X;
	}

	template<typename T>
	out& operator << (out& X, const  T &Y)
	{
#undef cout
		cout << Y;
#define cout output
		return X;
	}
	template<typename T>
	out& operator << (out& X, vector<T> &Y)
	{
		for (auto &x : Y)
			cout << x << " ";
		return X;
	}
	out& operator <<(out& X, const int &Y)
	{
		printf("%d", Y);
		return X;
	}
	out& operator <<(out& X, const char &C)
	{
		printf("%c", C);
		return X;
	}
	out& operator <<(out& X, const string &Y)
	{
		printf("%s", Y.c_str());
		return X;
	}
	out& operator <<(out& X, const long long &Y)
	{
		printf("%lld", Y);
		return X;
	}
	out& operator <<(out& X, const float &Y)
	{
		printf("%f", Y);
		return X;
	}
	out& operator <<(out& X, const double &Y)
	{
		printf("%lf", Y);
		return X;
	}
	out& operator <<(out& X, const char Y[])
	{
		printf("%s", Y);
		return X;
	}
	template<typename T>
	T max(T A)
	{
		return A;
	}
	template<typename T, typename... args>
	T max(T A, T B, args... S)
	{
		return max(A > B ? A : B, S...);
	}
	template<typename T>
	T min(T A)
	{
		return A;
	}
	template<typename T, typename... args>
	T min(T A, T B, args... S)
	{
		return min(A < B ? A : B, S...);
	}
	template<typename T>
	void vectorize(int y, ve<T> &A)
	{
		A.resize(y);
	}
	template<typename T, typename... args>
	void vectorize(int y, ve<T> &A, args&&... S)
	{
		A.resize(y);
		vectorize(y, S...);
	}
	long long fast(long long a, long long b, long long pr)
	{
		if (b == 0)
			return 1 % pr;
		long long ans = 1 % pr;
		while (b)
		{
			if (b & 1)
				ans = (ans * a) % pr;
			b >>= 1;
			a = (a * a) % pr;
		}
		return ans;
	}
	int readInt()
	{
		int n = 0;
		

		

		int ch = getcx();
		int sign = 1;
		while (ch < '0' || ch > '9') { if (ch == '-')sign = -1; ch = getcx(); }

		while (ch >= '0' && ch <= '9')
			n = (n << 3) + (n << 1) + ch - '0', ch = getcx();
		n = n * sign;
		return n;
	}
	long long readLong()
	{
		long long n = 0;
		

		

		int ch = getcx(); int sign = 1;
		while (ch < '0' || ch > '9') { if (ch == '-')sign = -1; ch = getcx(); }

		while (ch >= '0' && ch <= '9')
			n = (n << 3) + (n << 1) + ch - '0', ch = getcx();
		n = n * sign;
		return n;
	}
	long long readBin()
	{
		long long n = 0;
		

		

		int ch = getcx(); int sign = 1;
		while (ch < '0' || ch > '1') { if (ch == '-')sign = -1; ch = getcx(); }

		while (ch >= '0' && ch <= '1')
			n = (n << 1) + (ch - '0'), ch = getcx();
		return n;
	}
	long long inv_(long long val, long long pr = mod)
	{
		return fast(val, pr - 2, pr);
	}
}
int capK, capK2;
class seg_tree
{
	ve<int> tree;
	ve<map<int, int>> tree2;
	int n;
	inline int get_size(int R)
	{
		R--;
		int Z = 1;
		while (R)
		{
			Z <<= 1;
			R >>= 1;
		}
		return Z * 2;
	}
public:
	void construct(int s)
	{
		tree2.resize(get_size(s));
		n = s - 1;
	}

	int find_max(int l, int r, int K)
	{
		return find_max2(l, r, K, 0, n, 1);
	}
	int find_max2(int l, int r, int K, int L, int R, int curr)
	{
		if (r<L || l>R || tree2[curr].lower_bound(K) == tree2[curr].end())
			return 0;
		if (L >= l && R <= r)
		{
			int ans = 0;
			auto i = tree2[curr].lower_bound(K);
			while (i != tree2[curr].end() && i->first <= K + capK2)
			{
				ans += i->second;
				++i;
			}
			return ans;
		}
		int c = curr;
		return (find_max2(l, r, K, L, (L + R) / 2, 2 * curr) + find_max2(l, r, K, (L + R) / 2 + 1, R, 2 * curr + 1));
	}
	void update(int pos, int val)
	{
		update(pos, val, 1, 0, n);
	}
	void update(int pos, int val, int c, int L, int R)
	{
		int curr = c;
		if (pos<L || pos>R)
			return;
		if (L == R)
		{
			tree2[c][val]++;
			return;
		}
		update(pos, val, curr << 1, L, (L + R) >> 1);
		update(pos, val, (curr << 1) + 1, ((L + R) >> 1) + 1, R);
		tree2[c][val]++;
		return;
	}
	void update2(int pos, int val)
	{
		update2(pos, val, 1, 0, n);
	}
	void update2(int pos, int val, int c, int L, int R)
	{
		int curr = c;
		if (pos<L || pos>R)
			return;
		if (L == R)
		{
			tree2[c][val]--;
			return;
		}
		update2(pos, val, curr << 1, L, (L + R) >> 1);
		update2(pos, val, (curr << 1) + 1, ((L + R) >> 1) + 1, R);
		tree2[c][val]--;
		return;
	}
};
int MOD = 1e9 + 7;
using namespace std;



 


const int MAX = 10;
const int LOG = 2;
 


template<typename T> class cmplx {
private:
	T x, y;
public:
	cmplx() : x(0.0), y(0.0) {}
	cmplx(T a) : x(a), y(0.0) {}
	cmplx(T a, T b) : x(a), y(b) {}
	T get_real() { return this->x; }
	T get_img() { return this->y; }
	cmplx conj() { return cmplx(this->x, -(this->y)); }
	cmplx operator = (const cmplx& a) { this->x = a.x; this->y = a.y; return *this; }
	cmplx operator + (const cmplx& b) { return cmplx(this->x + b.x, this->y + b.y); }
	cmplx operator - (const cmplx& b) { return cmplx(this->x - b.x, this->y - b.y); }
	cmplx operator * (const T& num) { return cmplx(this->x * num, this->y * num); }
	cmplx operator / (const T& num) { return cmplx(this->x / num, this->y / num); }
	cmplx operator * (const cmplx& b) {
		return cmplx(this->x * b.x - this->y * b.y, this->y * b.x + this->x * b.y);
	}
	cmplx operator / (const cmplx& b) {
		cmplx temp(b.x, -b.y); cmplx n = (*this) * temp;
		return n / (b.x * b.x + b.y * b.y);
	}
};
 




template<typename T, typename S> struct FFT {
	S PI;
	int n, L, *rev, last;
	cmplx<S> ONE, ZERO;
	cmplx<S> *omega_powers;
 
	FFT() {
		PI = acos(-1.0);
		ONE = cmplx<S>(1.0, 0.0);
		ZERO = cmplx<S>(0.0, 0.0);
		last = -1;
		int req = 1 << LOG;
		rev = new int[req];
		omega_powers = new cmplx<S>[req];
	}
 
	~FFT() {
		delete rev;
		delete omega_powers;
	}
 
	void ReverseBits() {
		int SZ=n;
		rev[0] = 0;
		rev[1] = SZ >> 1;
		for (int i = 1; i + 1<SZ; i++)
		{
			if ((i << 1)<SZ)
				rev[i << 1] = rev[i] >> 1;
			if ((i & 1) == 0)
			{
				rev[i + 1] = rev[i] | (SZ >> 1);
			}
		}
	}
 
	void DFT(vector<cmplx<S>> &A, bool inverse = false) {
		for (int i = 0; i < n; ++i)
			if (rev[i] > i) swap(A[i], A[rev[i]]);
		for (int s = 1; s <= L; s++) {
			int m = 1 << s, half = m / 2;
			cmplx<S> wm(cosl(2.0 * PI / m), sinl(2.0 * PI / m));
			if (inverse) wm = ONE / wm;
			omega_powers[0] = ONE;
			for (int k = 1; k < half; ++k) {
				omega_powers[k] = omega_powers[k - 1] * wm;
			}
			for (int k = 0; k < n; k += m) {
				for (int j = 0; j < half; j++) {
					cmplx<S> t = omega_powers[j] * A[k + j + half];
					cmplx<S> u = A[k + j];
					A[k + j] = u + t;
					A[k + j + half] = u - t;
				}
			}
		}
		if (inverse) {
			for (int i = 0; i < n; i++) A[i] = A[i] / n;
		}
	}
 
	

	vector<T> multiply(const vector<T> &a, const vector<T> &b) {
		L = 0;
		int sa = a.size(), sb = b.size(), sc = sa + sb - 1;
		while ((1 << L) < sc) L++;
		n = 1 << L;
		ReverseBits();
		last = n;
		vector<cmplx<S>> aa(n, ZERO), bb(n, ZERO), cc;
		for (int i = 0; i < sa; ++i) aa[i] = cmplx<S>(a[i], 0);
		for (int i = 0; i < sb; ++i) bb[i] = cmplx<S>(b[i], 0);
		DFT(aa, false); DFT(bb, false);
		for (int i = 0; i < n; ++i) cc.push_back(aa[i] * bb[i]);
		DFT(cc, true);
		vector<T> ans(sc);
		for (int i = 0; i < sc; ++i) ans[i] = static_cast<long long>(cc[i].get_real() + 0.5) % MOD;
		return ans;
	}
	
	vector<T> pm(const vector<T> &a,const vector<T> &b)
	{
		vector<T> c(a.size()-1+b.size());
		for(int i=0;i<a.size();i++)
		{
			for(int j=0;j<b.size();j++)
			{
				c[i+j]=(c[i+j]+a[i]*b[j])%MOD;
			}
		}
		return c;
	}
	

	vector<T> multiply(const vector<T> &a) {
		L = 0;
		int sa = a.size(), sc = sa + sa - 1;
		while ((1 << L) < sc) L++;
		n = 1 << L;
		ReverseBits();
		last = n;
		vector<cmplx<S>> aa(n, ZERO), cc;
		for (int i = 0; i < sa; ++i) aa[i] = cmplx<S>(a[i], 0);
		DFT(aa, false);
		for (int i = 0; i < n; ++i) cc.push_back(aa[i] * aa[i]);
		DFT(cc, true);
		vector<T> ans(sc);
		for (int i = 0; i < sc; ++i) ans[i] = static_cast<long long>(cc[i].get_real() + 0.5) % MOD;
		return ans;
	}
};
FFT<int, double> Ft;
class solve
{
	int n,m;
	ve<int> cnt;
	ve<ve<int> > price;
	ve<ve<int> > taken;
public:
	solve()
	{
		cin >> n >> m;
		cnt.resize(m);
		price.resize(m);
		taken.resize(m);
		ve<pair<int,int> > P;
		map<int,map<int,int> > M;
		for(int i=0;i<n;i++)
		{
			int x,y;
			cin >> x >> y;
			--x;
			cnt[x]++;
			price[x].pb(y);
			taken[x].pb(0);
			if(x)
			{
				P.push_back({y,x});
				M[x][y]++;
			}
		}
		for(int i=0;i<m;i++)
		{
			srt(price[i]);
		}
		srt(P);
		long long ans=1e17;
		for(int i=cnt[0];i<=n;i++)
		{
			long long cst=0;
			int take=i-cnt[0];
			ve<int> val(m);
			map<int,map<int,int> > M2(M);
			for(int j=1;j<m;j++)
			{
				while(take>0 && ((cnt[j]-val[j])>=i))
				{
					cst+=price[j][val[j]];
					M2[j][price[j][val[j]]]--;
					--take;
					val[j]++;
				}
				if((cnt[j]-val[j])>=i)
					cst=1e18;
			}
			if(cst>ans)
				continue;
			for(auto &x:P)
			{
				if(take<=0)
					break;
				if(M2[x.second][x.first]>0)
				{
					cst+=x.first;
					M2[x.second][x.first]--;
					--take;
				}
			}
			ans=min(ans,cst);
		}
		cout << ans;
		
	}
	long long _gcd(long long a, long long b)
	{
		if (b == 0)
			return a;
		return _gcd(b, a%b);
	}
	int area(pair<int,int> p,pair<int,int> q,pair<int,int> r)
	{
		return abs((p.first-r.first)*(q.second-r.second)-(p.second-r.second)*(q.first-r.first));
	}

};

int32_t main()
{
	int t = 1, i = 1;
	

	

	if (code_chef || code_jam)
		scanf("%d", &t);
	while (t--)
	{
		if (code_jam)
			printf("Case #%d: ", i++);
		new solve;
	}
#ifdef __unix__
	cout << "\n";
#endif
	return 0;
}