






































using namespace std;

template<typename T>inline bool upmin(T &x,T y) { return y<x?x=y,1:0; }
template<typename T>inline bool upmax(T &x,T y) { return x<y?x=y,1:0; }

typedef long long ll;
typedef unsigned long long ull;
typedef long double lod;
typedef pair<int,int> PR;
typedef vector<int> VI;

const lod eps=1e-11;
const lod pi=acos(-1);
const int oo=1<<30;
const ll loo=1ll<<62;
const int MAXN=3000005;
const int INF=0x3f3f3f3f;
const ll mods=1231453023109121ll,G=3ll,Gi=(mods+1)/G;

inline int read()
{
	int f=1,x=0; char c=getchar();
	while (c<'0'||c>'9') { if (c=='-') f=-1; c=getchar(); }
	while (c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar(); }
	return x*f;
}
char st[MAXN];
int limit,L,rev[MAXN];
namespace SuperNTT
{
	typedef unsigned int uint;
	typedef long long unsigned int uint64;
	
	constexpr uint Max_size = 1 << 21 | 5;
	constexpr uint g = 3, Mod = 998244353;
	
	inline uint id1(const uint x)
	{
		return x < Mod * 2 ? x : x - Mod * 2;
	}
	
	inline uint norm(const uint x)
	{
		return x < Mod ? x : x - Mod;
	}
	
	struct Z
	{
		uint v;
		Z() { }
		Z(const uint _v) : v(_v) { }
	};
	
	inline Z operator+(const Z &x1, const Z &x2) { return x1.v + x2.v < Mod ? x1.v + x2.v : x1.v + x2.v - Mod; }
	inline Z operator-(const Z &x1, const Z &x2) { return x1.v >= x2.v ? x1.v - x2.v : x1.v + Mod - x2.v; }
	inline Z operator*(const Z &x1, const Z &x2) { return static_cast<uint64>(x1.v) * x2.v % Mod; }
	inline Z &operator*=(Z &x1, const Z &x2) { x1.v = static_cast<uint64>(x1.v) * x2.v % Mod; return x1; }
	
	Z Power(Z Base, int Exp)
	{
		Z res = 1;
		for (; Exp; Base *= Base, Exp >>= 1)
			if (Exp & 1)
				res *= Base;
		return res;
	}
	
	inline uint mf(uint x)
	{
		return (static_cast<uint64>(x) << 32) / Mod;
	}
	
	int size;
	uint w[Max_size], w_[Max_size];
	
	inline uint id3(const uint x, const uint y, const uint y_)
	{
		uint q = static_cast<uint64>(x) * y_ >> 32;
		return x * y - q * Mod;
	}
	
	inline uint id4(const uint x, const uint y, const uint y_)
	{
		return norm(id3(x, y, y_));
	}
	
	inline void init(int n)
	{
		for (size = 2; size < n; size <<= 1)
			;
		Z pr = Power(g, (Mod - 1) / size);
		size >>= 1;
		w[size] = 1, w_[size] = (static_cast<uint64>(w[size]) << 32) / Mod;
		if (size <= 8)
		{
			for (int i = 1; i < size; ++i)
				w[size + i] = (w[size + i - 1] * pr).v, w_[size + i] = (static_cast<uint64>(w[size + i]) << 32) / Mod;
		}
		else
		{
			for (int i = 1; i < 8; ++i)
				w[size + i] = (w[size + i - 1] * pr).v, w_[size + i] = (static_cast<uint64>(w[size + i]) << 32) / Mod;
			pr *= pr, pr *= pr, pr *= pr;
			for (int i = 8; i < size; i += 8)
			{ 
				w[size + i + 0] = (w[size + i - 8] * pr).v, w_[size + i + 0] = (static_cast<uint64>(w[size + i + 0]) << 32) / Mod;
				w[size + i + 1] = (w[size + i - 7] * pr).v, w_[size + i + 1] = (static_cast<uint64>(w[size + i + 1]) << 32) / Mod;
				w[size + i + 2] = (w[size + i - 6] * pr).v, w_[size + i + 2] = (static_cast<uint64>(w[size + i + 2]) << 32) / Mod;
				w[size + i + 3] = (w[size + i - 5] * pr).v, w_[size + i + 3] = (static_cast<uint64>(w[size + i + 3]) << 32) / Mod;
				w[size + i + 4] = (w[size + i - 4] * pr).v, w_[size + i + 4] = (static_cast<uint64>(w[size + i + 4]) << 32) / Mod;
				w[size + i + 5] = (w[size + i - 3] * pr).v, w_[size + i + 5] = (static_cast<uint64>(w[size + i + 5]) << 32) / Mod;
				w[size + i + 6] = (w[size + i - 2] * pr).v, w_[size + i + 6] = (static_cast<uint64>(w[size + i + 6]) << 32) / Mod;
				w[size + i + 7] = (w[size + i - 1] * pr).v, w_[size + i + 7] = (static_cast<uint64>(w[size + i + 7]) << 32) / Mod;
			} 
		}
		for (int i = size - 1; i; --i)
			w[i] = w[i * 2], w_[i] = w_[i * 2];
		size <<= 1;
	}
	
	inline void id0(Z _A[], const int L)
	{
		if (L == 1)
			return;
		uint *A = reinterpret_cast<uint *>(_A);
	
		do\
		{\
			uint _a = a, _b = b;\
			uint x = id1(_a + _b), y = id1(_a + Mod * 2 - _b);\
			a = x, b = y;\
		} while (0)
		if (L == 2)
		{
			butterfly1(A[0], A[1]);
			return;
		}
	
		do\
		{\
			uint _a = a, _b = b;\
			uint x = id1(_a + _b), y = id3(_a + Mod * 2 - _b, _w, _w_);\
			a = x, b = y;\
		} while (0)
		if (L == 4)
		{
			butterfly1(A[0], A[2]);
			butterfly(A[1], A[3], w[3], w_[3]);
			butterfly1(A[0], A[1]);
			butterfly1(A[2], A[3]);
			return; 
		}
		for (int d = L >> 1; d != 4; d >>= 1)
			for (int i = 0; i != L; i += d << 1)
				for (int j = 0; j != d; j += 4)
				{
					butterfly(A[i + j], A[i + d + j], w[d + j], w_[d + j]);
					butterfly(A[i + j + 1], A[i + d + j + 1], w[d + j + 1], w_[d + j + 1]);
					butterfly(A[i + j + 2], A[i + d + j + 2], w[d + j + 2], w_[d + j + 2]);
					butterfly(A[i + j + 3], A[i + d + j + 3], w[d + j + 3], w_[d + j + 3]);
				}
		for (int i = 0; i != L; i += 8)
		{
			butterfly1(A[i], A[i + 4]);
			butterfly(A[i + 1], A[i + 5], w[5], w_[5]);
			butterfly(A[i + 2], A[i + 6], w[6], w_[6]);
			butterfly(A[i + 3], A[i + 7], w[7], w_[7]);
		}
		for (int i = 0; i != L; i += 8)
		{
			butterfly1(A[i], A[i + 2]);
			butterfly(A[i + 1], A[i + 3], w[3], w_[3]);
			butterfly1(A[i + 4], A[i + 6]);
			butterfly(A[i + 5], A[i + 7], w[3], w_[3]);
		}
		for (int i = 0; i != L; i += 8)
		{
			butterfly1(A[i], A[i + 1]);
			butterfly1(A[i + 2], A[i + 3]);
			butterfly1(A[i + 4], A[i + 5]);
			butterfly1(A[i + 6], A[i + 7]);
		}
	
	
	}
	
	inline void id2(Z _A[], const int L)
	{
		if (L == 1)
			return;
		uint *A = reinterpret_cast<uint *>(_A);
	
		do\
		{\
			uint _a = a, _b = b;\
			uint x = id1(_a), t = id1(_b);\
			a = x + t, b = x + Mod * 2 - t;\
		} while (0)
		if (L == 2)
		{
			butterfly1(A[0], A[1]);
			A[0] = norm(id1(A[0])), A[0] = A[0] & 1 ? A[0] + Mod : A[0], A[0] /= 2;
			A[1] = norm(id1(A[1])), A[1] = A[1] & 1 ? A[1] + Mod : A[1], A[1] /= 2;
			return;
		}
	
		do\
		{\
			uint _a = a, _b = b;\
			uint x = id1(_a), t = id3(_b, _w, _w_);\
			a = x + t, b = x + Mod * 2 - t;\
		} while (0)
		if (L == 4)
		{
			butterfly1(A[0], A[1]);
			butterfly1(A[2], A[3]);
			butterfly1(A[0], A[2]);
			butterfly(A[1], A[3], w[3], w_[3]);
			std::swap(A[1], A[3]);
			for (int i = 0; i != L; ++i)
			{
				uint64 m = -A[i] & 3;
				A[i] = norm((A[i] + m * Mod) >> 2);
			}
			return; 
		}
		for (int i = 0; i != L; i += 8)
		{
			butterfly1(A[i], A[i + 1]);
			butterfly1(A[i + 2], A[i + 3]);
			butterfly1(A[i + 4], A[i + 5]);
			butterfly1(A[i + 6], A[i + 7]);
		}
		for (int i = 0; i != L; i += 8)
		{
			butterfly1(A[i], A[i + 2]);
			butterfly(A[i + 1], A[i + 3], w[3], w_[3]);
			butterfly1(A[i + 4], A[i + 6]);
			butterfly(A[i + 5], A[i + 7], w[3], w_[3]);
		}
		for (int i = 0; i != L; i += 8)
		{
			butterfly1(A[i], A[i + 4]);
			butterfly(A[i + 1], A[i + 5], w[5], w_[5]);
			butterfly(A[i + 2], A[i + 6], w[6], w_[6]);
			butterfly(A[i + 3], A[i + 7], w[7], w_[7]);
		}
		for (int d = 8; d != L; d <<= 1)
			for (int i = 0; i != L; i += d << 1)
				for (int j = 0; j != d; j += 4)
				{
					butterfly(A[i + j], A[i + d + j], w[d + j], w_[d + j]);
					butterfly(A[i + j + 1], A[i + d + j + 1], w[d + j + 1], w_[d + j + 1]);
					butterfly(A[i + j + 2], A[i + d + j + 2], w[d + j + 2], w_[d + j + 2]);
					butterfly(A[i + j + 3], A[i + d + j + 3], w[d + j + 3], w_[d + j + 3]);
				}
	
	
		std::reverse(A + 1, A + L);
		int k = __builtin_ctz(L);
		for (int i = 0; i != L; ++i)
		{
			uint64 m = -A[i] & (L - 1);
			A[i] = norm((A[i] + m * Mod) >> k);
		}
	}
	
	int N, M, L;
	Z A[Max_size], B[Max_size];
	
	void work(int f[], int g[], int n, int m, int res[]) {
		N = n; M = m;
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		for(int i = 0; i < n; ++i) A[i].v = f[i];
		for(int i = 0; i < m; ++i) B[i].v = g[i];
		for (L = 2; L <= N + M - 2; L <<= 1)
			;
		init(L);
		
		id0(A, L), id0(B, L);
		for (int i = 0; i != L; ++i)
			A[i] *= B[i];
		id2(A, L);
		
		for(int i = 0; i < n + m - 1; ++i) res[i] = A[i].v;
	}
};
struct Number
{
	int a[MAXN],len;
	void sqr()
	{
		SuperNTT::work(a,a,len+1,len+1,a);
		len=len+len+1;
		for (int i=0;i<len;i++) if (a[i]) a[i+1]+=a[i]/10,a[i]%=10;
		while (len&&!a[len-1]) len--;
	}
	bool operator <= (const Number &y)
	{
		if (y.len!=len) return len<y.len;
		for (int i=y.len-1;i>=0;i--)
		{
			if (a[i]<y.a[i]) return 1;
			else if (a[i]>y.a[i]) return 0;
		}
		return 1;
	}
} x,y,z,ret,tmp,p;
void Mul(Number &x,const Number &y)
{
	p.len=y.len; 
	for (int i=0;i<y.len;i++) p.a[i]=y.a[i]; 
	for (int i=y.len;i<limit;i++) p.a[i]=0;
	SuperNTT::work(x.a,p.a,x.len+1,p.len+1,x.a);
	x.len=x.len+y.len+1;
	for (int i=0;i<x.len;i++) if (x.a[i]) x.a[i+1]+=x.a[i]/10,x.a[i]%=10;
	while (x.len&&!x.a[x.len-1]) x.len--;
}
void Mul(Number &x,const int y)
{
	for (int i=0;i<x.len;i++) x.a[i]=x.a[i]*y;
	for (int i=0;i<x.len;i++) if (x.a[i]) x.a[i+1]+=x.a[i]/10,x.a[i]%=10;
	if (x.a[x.len]) x.len++;
}
void quick_pow(Number &ret,int y)
{
	z.len=ret.len=ret.a[0]=1,z.a[0]=3;
	for (;y;y>>=1)
	{
		if (y&1) Mul(ret,z);
		z.sqr();
	}
}
bool check(int r)
{
	tmp.len=x.len;
	for (int i=0;i<=tmp.len;i++) tmp.a[i]=x.a[i];
	Mul(tmp,r);
	return y<=tmp;
}
signed main()
{
	scanf("%s",st);
	int len=strlen(st);
	if (len==1&&st[0]=='1') { puts("1"); return 0; }
	y.len=-1;
	for (int i=len-1;i>=0;i--) 
	{
		y.len++;
		for (int j=i,pw=1;j>=max(i,0);j--,pw=pw*10) y.a[y.len]+=(st[j]-'0')*pw;
	}
	if (y.a[y.len]) y.len++;
	
	lod t=log(10)/log(3)*(len-1)+(log(st[0]-'0')/log(3))/3-1;
	int r=max((int)t,0);
	quick_pow(x,r);
	while (1) 
	{
		if (check(2)) { printf("%d\n",r*3+2); return 0; }
		if (check(3)) { printf("%d\n",r*3+3); return 0; }
		if (check(4)) { printf("%d\n",r*3+4); return 0; }
		Mul(x,3),r++;
	}
	return 0;
}