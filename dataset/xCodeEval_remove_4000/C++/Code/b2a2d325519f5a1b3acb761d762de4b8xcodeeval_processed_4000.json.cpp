




























































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

		cin >> Y;

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

		cout << Y;

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
int capK, id0;
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
			while (i != tree2[curr].end() && i->first <= K + id0)
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
 


template<typename T> class id2 {
private:
	T x, y;
public:
	id2() : x(0.0), y(0.0) {}
	id2(T a) : x(a), y(0.0) {}
	id2(T a, T b) : x(a), y(b) {}
	T get_real() { return this->x; }
	T get_img() { return this->y; }
	id2 conj() { return id2(this->x, -(this->y)); }
	id2 operator = (const id2& a) { this->x = a.x; this->y = a.y; return *this; }
	id2 operator + (const id2& b) { return id2(this->x + b.x, this->y + b.y); }
	id2 operator - (const id2& b) { return id2(this->x - b.x, this->y - b.y); }
	id2 operator * (const T& num) { return id2(this->x * num, this->y * num); }
	id2 operator / (const T& num) { return id2(this->x / num, this->y / num); }
	id2 operator * (const id2& b) {
		return id2(this->x * b.x - this->y * b.y, this->y * b.x + this->x * b.y);
	}
	id2 operator / (const id2& b) {
		id2 temp(b.x, -b.y); id2 n = (*this) * temp;
		return n / (b.x * b.x + b.y * b.y);
	}
};
 




template<typename T, typename S> struct FFT {
	S PI;
	int n, L, *rev, last;
	id2<S> ONE, ZERO;
	id2<S> *id1;
 
	FFT() {
		PI = acos(-1.0);
		ONE = id2<S>(1.0, 0.0);
		ZERO = id2<S>(0.0, 0.0);
		last = -1;
		int req = 1 << LOG;
		rev = new int[req];
		id1 = new id2<S>[req];
	}
 
	~FFT() {
		delete rev;
		delete id1;
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
 
	void DFT(vector<id2<S>> &A, bool inverse = false) {
		for (int i = 0; i < n; ++i)
			if (rev[i] > i) swap(A[i], A[rev[i]]);
		for (int s = 1; s <= L; s++) {
			int m = 1 << s, half = m / 2;
			id2<S> wm(cosl(2.0 * PI / m), sinl(2.0 * PI / m));
			if (inverse) wm = ONE / wm;
			id1[0] = ONE;
			for (int k = 1; k < half; ++k) {
				id1[k] = id1[k - 1] * wm;
			}
			for (int k = 0; k < n; k += m) {
				for (int j = 0; j < half; j++) {
					id2<S> t = id1[j] * A[k + j + half];
					id2<S> u = A[k + j];
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
		vector<id2<S>> aa(n, ZERO), bb(n, ZERO), cc;
		for (int i = 0; i < sa; ++i) aa[i] = id2<S>(a[i], 0);
		for (int i = 0; i < sb; ++i) bb[i] = id2<S>(b[i], 0);
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
		vector<id2<S>> aa(n, ZERO), cc;
		for (int i = 0; i < sa; ++i) aa[i] = id2<S>(a[i], 0);
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
	long long n,k,m;
public:
	solve()
	{
		cin >> m >> n;
		ve<int> v(n);
		
		
		for(int i=0;i<n;i++)
		{
			cout << 1 << endl;
			cin >> v[i];
			if(v[i]==0)
				exit(0);
			if(v[i]==-1)
				v[i]=1;
			else
				v[i]=-1;
		}
		int rot=0;
		int curr=29;
		long long num=0;
		while(curr>=0)
		{
			int r=num+(1<<curr);
			if(r<=m)
			{
			cout << r << endl;
			int x;
			cin >> x;
			if(x==0)
				exit(0);
			x*=v[rot];
			rot++;
			if(rot>=n)
				rot-=n;
			if(x==-1)
				num^=(1<<curr);
			}
			--curr;
		}
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
			printf("Case 
		new solve;
	}

	cout << "\n";

	return 0;
}