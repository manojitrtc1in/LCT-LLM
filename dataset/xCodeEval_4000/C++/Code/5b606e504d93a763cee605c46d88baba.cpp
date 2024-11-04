




#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define MTP make_tuple
#define R Read
#define RD Read_Digit
#define RP Read_P
#define RL Read_Loop
#define RLD Read_Loop_Digit
#define RLP Read_Loop_P
typedef long long int ll;
typedef unsigned long long int ull;

constexpr int kN = int(6E2 + 10);
constexpr int kMod = 998244353;
















static inline char Get_Raw_Char() {
	static char buf[1 << 16], *p = buf, *end = buf;
	if (p == end) {
		if ((end = buf + fread(buf, 1, 1 << 16, stdin)) == buf) return '\0';
		p = buf;
	}
	return *p++;
}

static inline int Get_Digit() {
	char c = Get_Raw_Char();
	while (!isdigit(c)) c = Get_Raw_Char();
	return int(c - '0');
}

template <typename T> static inline int Get_P() {
	static_assert(is_integral<T>::value);
	char c = Get_Raw_Char();
	while (!isdigit(c)) c = Get_Raw_Char();
	T ret = int(c - '0');
	while (isdigit(c = Get_Raw_Char())) ret = ret * 10 + int(c - '0');
	return ret;
}

template <typename T> static inline int Get() {
	static_assert(is_integral<T>::value);
	char c = Get_Raw_Char();
	bool neg = false;
	while (!isdigit(c)) {
		if (c == '-') neg = true;
		c = Get_Raw_Char();
	}
	T ret = int(c - '0');
	while (isdigit(c = Get_Raw_Char())) ret = ret * 10 + int(c - '0');
	if (neg) return -ret;
	return ret;
}



template <typename T> static inline void Read_P(T &n) {
	static_assert(is_integral<T>::value);
	char c = Get_Raw_Char();
	while (!isdigit(c)) c = Get_Raw_Char();
	n = int(c - '0');
	while (isdigit(c = Get_Raw_Char())) n = n * 10 + int(c - '0');
	return ;
}

template <typename T> static inline void Read(T &n) {
	static_assert(is_integral<T>::value);
	char c = Get_Raw_Char();
	bool neg = false;
	while (!isdigit(c)) {
		if (c == '-') neg = true;
		c = Get_Raw_Char();
	}
	n = int(c - '0');
	while (isdigit(c = Get_Raw_Char())) n = n * 10 + int(c - '0');
	if (neg) n = -n;
	return ;
}

template <typename T> static inline void Read_Digit(T &n) {
	static_assert(is_integral<T>::value);
	char c = Get_Raw_Char();
	while (!isdigit(c)) c = Get_Raw_Char();
	n = int(c - '0');
	return ;
}



template <typename T, typename... Targs> static inline void Read(T &n, Targs&... Fargs) {
	Read(n);
	return Read(Fargs...);
}

template <typename T, typename... Targs> static inline void Read_Digit(T &n, Targs&... Fargs) {
	Read_Digit(n);
	return Read_Digit(Fargs...);
}

template <typename T, typename... Targs> static inline void Read_P(T &n, Targs&... Fargs) {
	Read_P(n);
	return Read_P(Fargs...);
}



template <typename T> static inline void Read_Loop_i(int i, T *a) {return Read(a[i]);}
template <typename T, typename... Targs> static inline void Read_Loop_i(int i, T *a, Targs*... Fargs) {
	Read(a[i]);
	return Read_Loop_i(i, Fargs...);
}
template <typename... Targs> static inline void Read_Loop(int n, Targs*... Fargs) {
	for (int i = 1; i <= n; i++) Read_Loop_i(i, Fargs...);
	return ;
}

template <typename T> static inline void Read_Loop_Digit_i(int i, T *a) {return Read_Digit(a[i]);}
template <typename T, typename... Targs> static inline void Read_Loop_Digit_i(int i, T *a, Targs*... Fargs) {
	Read_Digit(a[i]);
	return Read_Loop_Digit_i(i, Fargs...);
}
template <typename... Targs> static inline void Read_Loop_Digit(int n, Targs*... Fargs) {
	for (int i = 1; i <= n; i++) Read_Loop_Digit_i(i, Fargs...);
	return ;
}

template <typename T> static inline void Read_Loop_P_i(int i, T *a) {return Read_P(a[i]);}
template <typename T, typename... Targs> static inline void Read_Loop_P_i(int i, T *a, Targs*... Fargs) {
	Read_P(a[i]);
	return Read_Loop_P_i(i, Fargs...);
}
template <typename... Targs> static inline void Read_Loop_P(int n, Targs*... Fargs) {
	for (int i = 1; i <= n; i++) Read_Loop_P_i(i, Fargs...);
	return ;
}




template <int mul, typename T> static inline void Read(T &n) {
	char c = Get_Raw_Char();
	bool neg = false;
	while (!isdigit(c)) {
		if (c == '-') neg = true;
		c = Get_Raw_Char();
	}
	n = int(c - '0');
	while (isdigit(c = Get_Raw_Char())) n = n * 10 + int(c - '0');
	
	int cnt = 0;

	if (c == '.') {
		while (isdigit(c = Get_Raw_Char())) {
			n = n * 10 + int(c - '0');
			cnt++;
		}
	}

	while (cnt < mul) {
		n = n * 10;
		cnt++;
	}

	if (neg) n = -n;
	return ;
}

template <int mul, typename T> static inline void Read_P(T &n) {
	char c = Get_Raw_Char();
	while (!isdigit(c)) c = Get_Raw_Char();
	
	n = int(c - '0');
	while (isdigit(c = Get_Raw_Char())) n = n * 10 + int(c - '0');
	
	int cnt = 0;

	if (c == '.') {
		while (isdigit(c = Get_Raw_Char())) {
			n = n * 10 + int(c - '0');
			cnt++;
		}
	}

	while (cnt < mul) {
		n = n * 10;
		cnt++;
	}
	return ;
}

template <int mul, typename T, typename... Targs> static inline void Read(T &n, Targs&... Fargs) {
	Read<mul>(n);
	return Read<mul>(Fargs...);
}

template <int mul, typename T, typename... Targs> static inline void Read_P(T &n, Targs&... Fargs) {
	Read_P<mul>(n);
	return Read_P<mul>(Fargs...);
}



void IOS() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	return ;
}



void Freopen(const char *in, const char *out) {	
	freopen(in, "r", stdin);
	freopen(out, "w", stdout);
	return ;
}




template <typename T> void Print128(T x) {
	if (x < 0) {
		printf("-");
		x = -x;
	}
	if (x == 0) printf("0");
	else {
		static int val[100];
		int idx = -1;
		while (x) {
			val[++idx] = x % 10;
			x /= 10;
		}
		while (idx >= 0) printf("%d", val[idx--]);
	}
} 









template <typename T> inline void sort(vector<T> &v) {return sort(v.begin(), v.end());}
template <typename T> inline void sort(int n, T *a) {return sort(a + 1, a + n + 1);}
template <typename T> inline void sort_r(vector<T> &v) {return sort(v.begin(), v.end(), greater<T>());}
template <typename T> inline void sort_r(int n, T *a) {return sort(a + 1, a + n + 1, greater<T>());}



template <typename T> inline void Merge_Vec(vector<T> &a, vector<T> &b, vector<T> &c) {
	if (c.size() < a.size() + b.size()) c.resize(a.size() + b.size());
	merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
	return ;
}



template <typename T> inline void Discrete(vector<T> &v) {
	sort(v);
	v.resize(unique(v.begin(), v.end()) - v.begin());
	return ;
}



template <typename T> inline void relabel(int n, T *val, T *dist) {
	if (!dist) dist = val;
	T *tmp = new T[n + 1];
	memcpy(tmp, val, sizeof(T) * (n + 1));
	sort(n, tmp);
	int sz = unique(tmp + 1, tmp + n + 1) - (tmp + 1);
	for (int i = 1; i <= n; i++) dist[i] = lower_bound(tmp + 1, tmp + sz + 1, val[i]) - tmp;
	delete [] tmp;
	return ;
}



template <typename T> using PQ = priority_queue<T>;
template <typename T> using PQ_R = priority_queue<T, vector<T>, greater<T>>;




template <typename T> inline T ABS(T n) {return n >= 0 ? n : -n;}
template <typename T> inline T gcd(T a, T b) {return b ? gcd(b, a % b) : a;}
template <typename T> inline T lcm(T a, T b) {return a * b / gcd(a, b);}
template <typename T> inline T mex(T a, T b) {return (a == 0 || b == 0) ? ((a == 1 || b == 1) ? 2 : 1) : 0;}
template <typename T> inline void chmin(T &a, T b) {
	a = min(a, b);
	return ;
}
template <typename T> inline void chmax(T &a, T b) {
	a = max(a, b);
	return ;
}



const inline vector<int> _range(int l, int r) {
	vector<int> ret(r - l + 1);
	for (int i = 0, val = l; val <= r; val++, i++) ret[i] = val;
	return ret;
}






void print(const int &x) {printf("%d", x);}
void print(const long long int &x) {printf("%lld", x);}
void print(const double &x) {printf("%.20lf", x);}
void print(const char *x) {printf("%s", x);}

void print(const int n, const int *x) {
	printf("%d", x[1]); for (int i = 2; i <= n; i++) printf(" %d", x[i]); printf("\n");
	return ;
}

void print(const int n, const long long int *x) {
	printf("%lld", x[1]); for (int i = 2; i <= n; i++) printf(" %lld", x[i]); printf("\n");
	return ;
}






template <typename T> T Pow(T a, long long int b) {
	T ans(1);
	while (b) {
		if (b & 1) ans *= a;
		a *= a;
		b >>= 1;
	}
	return ans;
}

template <int kMod> struct Mod_Int {
	constexpr static int Mod() {return kMod;}

	long long int val;
	Mod_Int() {val = 0;}
	template <typename T> Mod_Int(const T &x) {val = x;}
	template <int nMod> Mod_Int(const Mod_Int<nMod> &x) {val = x.val % kMod;}

	Mod_Int inv() const {return Pow(*this, kMod - 2);} 

	Mod_Int operator + (const Mod_Int &x) const {
		Mod_Int ans(val + x.val);
		if (ans.val >= kMod) ans.val -= kMod;
		return ans;
	}
	Mod_Int operator - (const Mod_Int &x) const {
		Mod_Int ans(val - x.val);
		if (ans.val < 0) ans.val += kMod;
		return ans;
	}
	Mod_Int operator * (const Mod_Int &x) const {return Mod_Int(val * x.val % kMod);}
	Mod_Int operator / (const Mod_Int &x) const {return *this * x.inv();}
	Mod_Int operator ^ (const Mod_Int &x) const {return Pow(*this, x.val);}
	Mod_Int operator << (const int &x) const {return (val << x) % kMod;}

	Mod_Int operator += (const Mod_Int &x) {
		val += x.val;
		if (val >= kMod) val -= kMod;
		return *this;
	}
	Mod_Int operator -= (const Mod_Int &x) {
		val -= x.val;
		if (val < 0) val += kMod;
		return *this;
	}
	Mod_Int operator *= (const Mod_Int &x) {
		val = val * x.val % kMod;
		return *this;
	}
	Mod_Int operator /= (const Mod_Int &x) {
		val = val * x.inv().val % kMod;
		return *this;
	}
	Mod_Int operator ^= (const Mod_Int &x) {
		val = Pow(*this, x.val).val;
		return *this;
	}
	Mod_Int operator <<= (const int &x) {
		val = (val << x) % kMod;
		return *this;
	}

	Mod_Int operator ++(int) {
		val++;
		if (val >= kMod) val -= kMod;
		return *this;
	}
	Mod_Int operator --(int) {
		val--;
		if (val < 0) val += kMod;
		return *this;
	}

	bool operator == (const Mod_Int &x) const {return val == x.val;}
	bool operator != (const Mod_Int &x) const {return val != x.val;}
};

using Mint = Mod_Int<kMod>;

namespace Factorial {
	Mint *f, *inf;
	bool preprocessed_factorial;
	void Pre_Factorial(const int &sz) {
		if (preprocessed_factorial) return ;
		preprocessed_factorial = true;
		f = new Mint[sz + 1];
		inf = new Mint[sz + 1];
		f[0] = f[1] = inf[0] = inf[1] = 1;
		for (int i = 2; i <= sz; i++) f[i] = f[i - 1] * i;
		inf[sz] = f[sz].inv();
		for (int i = sz; i > 2; i--) inf[i - 1] = inf[i] * i;
		return ;
	}
	inline Mint P(const int &n, const int &m) {return f[n] * inf[m];}
	inline Mint C(const int &n, const int &m) {return f[n] * inf[m] * inf[n - m];}
	inline Mint H(const int &n, const int &m) {return f[n + m - 1] * inf[m] * inf[n - 1];}
	inline Mint Catalan(const int &n) {return f[n << 1] * inf[n] * inf[n + 1];}
}

namespace Factorial_No_Inf {
	Mint *f;
	void Pre_Factorial(const int &sz) {
		f = new Mint[sz + 1];
		f[0] = f[1] = 1;
		for (int i = 2; i <= sz; i++) f[i] = f[i - 1] * i;
		return ;
	}
	inline Mint P(const int &n, const int &m) {return f[n] / f[m];}
	inline Mint C(const int &n, const int &m) {return f[n] / (f[m] * f[n - m]);}
	inline Mint H(const int &n, const int &m) {return f[n + m - 1] / (f[m] * f[n - 1]);}
	inline Mint Catalan(const int &n) {return f[n << 1] / (f[n] * f[n + 1]);}
}

namespace Inverse {
	using namespace Factorial;
	Mint *inv;
	void Pre_Inverse(const int &sz) {
		inv = new Mint[sz + 1];
		inv[1] = 1;
		Pre_Factorial(sz);
		for (int i = 1; i <= sz; i++) inv[i] = f[i - 1] * inf[i];
		return ;
	}
};




int a[kN], b[kN];
int dis[kN][kN], p[kN];

vector<int> graph[kN];
bitset<kN> went;

int main() {
	int n, m; RP(n, m);
	RLP(m, a, b);

	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= m; i++) dis[a[i]][b[i]] = dis[b[i]][a[i]] = 1;
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) 
		chmin(dis[i][j], dis[i][k] + dis[k][j]);

	for (int i = 1; i <= m; i++) {
		graph[a[i]].PB(b[i]);
		graph[b[i]].PB(a[i]);
	}

	for (int x = 1; x <= n; x++, printf("\n")) for (int y = 1; y <= n; y++) {
		if (y != 1) printf(" ");
		int cnt = 0;
		for (int j = 1; j <= n; j++) if (dis[x][y] == dis[x][j] + dis[j][y]) cnt++;
		if (cnt != dis[x][y] + 1) printf("0");
		else {
			Mint ans = 1;
			for (int i = 1; i <= n; i++) if (dis[x][i] + dis[i][y] != dis[x][y]) {
				int tmp = 0;
				for (int j : graph[i]) if (dis[x][j] + 1 == dis[x][i] && dis[y][j] + 1 == dis[y][i]) tmp++;
				ans *= tmp;
			}
			printf("%lld", ans);
		}
	}

}



