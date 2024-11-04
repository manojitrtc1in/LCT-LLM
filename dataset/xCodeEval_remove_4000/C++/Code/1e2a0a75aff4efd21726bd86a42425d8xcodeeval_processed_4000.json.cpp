
using namespace std;






typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

template<typename T> inline void ckmax(T& x, T y) { x = (y > x ? y : x); }
template<typename T> inline void ckmin(T& x, T y) { x = (y < x ? y : x); }

 

namespace Fread {
const int SIZE = 1 << 21;
char buf[SIZE], *S, *T;
inline char getchar() {
	if (S == T) {
		T = (S = buf) + fread(buf, 1, SIZE, stdin);
		if (S == T) return '\n';
	}
	return *S++;
}
struct Reader {
	template<typename T>
	Reader& operator >> (T& x) {
		char c = getchar();
		T f = 1;
		while (c < '0' || c > '9') {
			if (c == '-') f = -1;
			c = getchar();
		}
		x = 0;
		while (c >= '0' && c <= '9') {
			x = x * 10 + (c - '0');
			c = getchar();
		}
		x *= f;
		return *this;
	}
	Reader& operator >> (char& c) {
		c = getchar();
		while (c == '\n' || c == ' ') c = getchar();
		return *this;
	}
	Reader& operator >> (char* str) {
		int len = 0;
		char c = getchar();
		while (c == '\n' || c == ' ') c = getchar();
		while (c != '\n' && c != ' ') {
			str[len++] = c;
			c = getchar();
		}
		str[len] = '\0';
		return *this;
	}
	Reader(){}
} cin;
} 

namespace Fwrite {
const int SIZE = 1 << 21;
char buf[SIZE], *S = buf, *T = buf + SIZE;
inline void flush() {
	fwrite(buf, 1, S - buf, stdout);
	S = buf;
}
inline void putchar(char c) {
	*S++ = c;
	if (S == T) flush();
}
struct NTR {
	~ NTR() { flush(); }
} ztr;
const char endl = '\n';
struct Writer {
	template<typename T>
	Writer& operator << (T x) {
		if (x == 0) { putchar('0'); return *this; }
		if (x < 0) { putchar('-'); x = -x; }
		static int sta[45];
		int top = 0;
		while (x) { sta[++top] = x % 10; x /= 10; }
		while (top) { putchar(sta[top] + '0'); --top; }
		return *this;
	}
	Writer& operator << (char c) {
		putchar(c);
		return *this;
	}
	Writer& operator << (char* str) {
		int cur = 0;
		while (str[cur]) putchar(str[cur++]);
		return *this;
	}
	Writer& operator << (const char* str) {
		int cur = 0;
		while (str[cur]) putchar(str[cur++]);
		return *this;
	}
	Writer(){}
} cout;
} 


	
	
	

 


namespace NTT {

typedef unsigned int uint;
typedef long long unsigned int uint64;

constexpr uint Max_size = 1 << 23 | 5;
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
	for(int i = 0; i < n; ++i) A[i].v = f[i];
	for(int i = 0; i < m; ++i) B[i].v = g[i];
	for (L = 2; L <= N + M - 2; L <<= 1)
		;
	init(L);
	
	id0(A, L), id0(B, L);
	for (int i = 0; i != L; ++i)
		A[i] *= B[i];
	id2(A, L);
	
	for(int i = 0; i <= (n - 1) + (n - 1); ++i) res[i] = A[i].v;
}

}

const int MAXN = 2500000;

int n, a[MAXN + 5], buc[MAXN * 2 + 5], res[MAXN * 2 + 5];
bool used[MAXN + 5];
void pa(int x, int y, int z, int w) {
	cout << "YES" << endl;
	for (int i = 1; i <= n; ++i) {
		if (!used[i] && a[i] == x) {
			used[i] = 1;
			cout << i << " ";
			break;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!used[i] && a[i] == y) {
			used[i] = 1;
			cout << i << " ";
			break;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!used[i] && a[i] == z) {
			used[i] = 1;
			cout << i << " ";
			break;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!used[i] && a[i] == w) {
			used[i] = 1;
			cout << i;
			break;
		}
	}
	cout << endl;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		buc[a[i]]++;
	}
	
	int tmp = 0;
	for (int i = 1; i <= MAXN; ++i) {
		if (buc[i] > 1) {
			if (buc[i] >= 4) {
				pa(i, i, i, i);
				return 0;
			}
			
			if (!tmp) tmp = i;
			else {
				pa(i, tmp, i, tmp);
				return 0;
			}
		}
	}
	
	if (tmp) {
		for (int i = 1; i <= n; ++i) {
			if (a[i] == tmp)
				continue;
			if (a[i] >= tmp * 2)
				continue;
			
			if (buc[tmp * 2 - a[i]]) {
				pa(tmp, tmp, a[i], tmp * 2 - a[i]);
				return 0;
			}
			
		}
		buc[tmp] = 1;
	}
	
	NTT :: work(buc, buc, MAXN + 1, MAXN + 1, res);
	
	for (int i = 2; i <= MAXN + MAXN; ++i) {
		if (i % 2 == 0) {
			res[i] -= buc[i / 2] * buc[i / 2];
		}
		assert(res[i] % 2 == 0);
		res[i] /= 2;
		
		if (res[i] <= 1) continue;
		
		for (int j = 1; j < i; ++j) {
			if (buc[j] && buc[i - j]) {
				for (int k = j + 1; k < i - j; ++k) {
					if (buc[k] && buc[i - k]) {
						pa(j, i - j, k, i - k);
						return 0;
					}
				}
				assert(0);
			}
		}
		assert(0);
	}
	
	cout << "NO" << endl;
	return 0;
}