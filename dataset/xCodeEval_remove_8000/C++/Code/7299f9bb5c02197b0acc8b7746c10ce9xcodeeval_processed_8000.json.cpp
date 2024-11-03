















using namespace std;














	
	
	
	

	
	
	
	

typedef long long int ll;
typedef unsigned long long int ull;

constexpr int kN = 21;
constexpr int kMod = 31607;
























bool id10 = false;
bool id16 = false;


static inline char id13() {
	static bool pre = id10 = true;
	static char buf[1 << 16], *p = buf, *end = buf;
	if (p == end) {
		if ((end = buf + fread(buf, 1, 1 << 16, stdin)) == buf) return '\0';
		p = buf;
	}
	return *p++;
}



template <typename T> static inline void Read_P(T &n) {
	static_assert(is_integral<T>::value, "Read_P requires an integral type");
	char c;
	while (!isdigit(c = id13())) ;
	n = int(c - '0');
	while (isdigit(c = id13())) n = n * 10 + int(c - '0');
	return ;
}

template <typename T> static inline void Read(T &n) {
	static_assert(is_integral<T>::value, "Read requires an integral type");
	char c;
	bool neg = false;
	while (!isdigit(c = id13())) if (c == '-') neg = true;
	n = int(c - '0');
	while (isdigit(c = id13())) n = n * 10 + int(c - '0');
	if (neg) n = -n;
	return ;
}

template <typename T> static inline void id6(T &n) {
	static_assert(is_integral<T>::value, "id6 requires an integral type");
	char c;
	while (!isdigit(c = id13())) ;
	n = int(c - '0');
	return ;
}

static inline void Read_String(string &s) {
	char c = id13();
	while (c == ' ' || c == '\n') c = id13();
	while (c != ' ' && c != '\n') {
		s += c;
		c = id13();
	}
	return ;
}



template <typename T, typename... Targs> static inline void Read(T &n, Targs&... Fargs) {Read(n); return Read(Fargs...);}
template <typename T, typename... Targs> static inline void id6(T &n, Targs&... Fargs) {id6(n); return id6(Fargs...);}
template <typename T, typename... Targs> static inline void Read_P(T &n, Targs&... Fargs) {Read_P(n); return Read_P(Fargs...);}
template <typename... Targs> static inline void Read_String(string &s, Targs&... Fargs) {Read_String(s); return Read_String(Fargs...);}



template <typename T> static inline void id3(int i, T *a) {return Read(a[i]);}
template <typename T, typename... Targs> static inline void id3(int i, T *a, Targs*... Fargs) {Read(a[i]); return id3(i, Fargs...);}
template <typename... Targs> static inline void id9(int n, Targs*... Fargs) {for (int i = 1; i <= n; i++) id3(i, Fargs...);}

template <typename T> static inline void id5(int i, T *a) {return id6(a[i]);}
template <typename T, typename... Targs> static inline void id5(int i, T *a, Targs*... Fargs) {id6(a[i]); return id5(i, Fargs...);}
template <typename... Targs> static inline void id8(int n, Targs*... Fargs) {for (int i = 1; i <= n; i++) id5(i, Fargs...);}

template <typename T> static inline void id7(int i, T *a) {return Read_P(a[i]);}
template <typename T, typename... Targs> static inline void id7(int i, T *a, Targs*... Fargs) {Read_P(a[i]); return id7(i, Fargs...);}
template <typename... Targs> static inline void id0(int n, Targs*... Fargs) {for (int i = 1; i <= n; i++) id7(i, Fargs...);}

static inline void id15(int i, string *a) {return Read_String(a[i]);}
template <typename... Targs> static inline void id15(int i, string *a, Targs*... Fargs) {Read_String(a[i]); return id15(i, Fargs...);}
template <typename... Targs> static inline void id2(int n, Targs*... Fargs) {for (int i = 1; i <= n; i++) id15(i, Fargs...);}



template <int mul, typename T> static inline void Read(T &n) {
	char c;
	bool neg = false;
	while (!isdigit(c = id13())) if (c == '-') neg = true;
	n = int(c - '0');
	while (isdigit(c = id13())) n = n * 10 + int(c - '0');

	int cnt = 0;

	if (c == '.') {
		while (isdigit(c = id13())) {
			n = n * 10 + int(c - '0');
			cnt++;
		}
	}

	while (cnt++ < mul) n = n * 10;

	if (neg) n = -n;
	return ;
}

template <int mul, typename T> static inline void Read_P(T &n) {
	char c;
	while (!isdigit(c = id13())) ;

	n = int(c - '0');
	while (isdigit(c = id13())) n = n * 10 + int(c - '0');

	int cnt = 0;

	if (c == '.') {
		while (isdigit(c = id13())) {
			n = n * 10 + int(c - '0');
			cnt++;
		}
	}

	while (cnt++ < mul) n = n * 10;
	return ;
}

template <int mul, typename T, typename... Targs> static inline void Read(T &n, Targs&... Fargs) {Read<mul>(n); return Read<mul>(Fargs...);}
template <int mul, typename T, typename... Targs> static inline void Read_P(T &n, Targs&... Fargs) {Read_P<mul>(n); return Read_P<mul>(Fargs...);}



inline void IOS() {
	id16 = true;
	ios::sync_with_stdio(false); cin.tie(0);
}
inline void Freopen(const char *in, const char *out) {freopen(in, "r", stdin); freopen(out, "w", stdout); return ;}



template <typename T> void Print(T x) {
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
template <typename T> inline void sort_r(vector<T> &v) {return sort(v.begin(), v.end(), greater<T>());}
inline void sort(string &s) {return sort(s.begin(), s.end());}
inline void sort_r(string &s) {return sort(s.begin(), s.end(), greater<char>());}

template <typename T> inline void reverse(vector<T> &v) {return reverse(v.begin(), v.end());}
inline void reverse(string &s) {return reverse(s.begin(), s.end());}

template <typename T> inline void Merge(vector<T> &a, vector<T> &b, vector<T> &c) {
	if (c.size() < a.size() + b.size()) c.resize(a.size() + b.size());
	merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
	return ;
}
template <typename T> inline void id18(vector<T> &a, vector<T> &b, vector<T> &c) {
	int a_size = int(a.size()), b_size = int(b.size());
	c.resize(a_size + b_size);
	for (int i = 0; i < a_size; i++) c[i] = a[i];
	for (int i = 0; i < b_size; i++) c[i + a_size] = b[i];
	return ;
}

template <typename T> inline void Discrete(vector<T> &v) {sort(v); v.resize(unique(v.begin(), v.end()) - v.begin()); return ;}
template <typename T> inline int Discrete_Id(vector<T> &v, T x) {return  lower_bound(v.begin(), v.end(), x) - v.begin();}

template <typename T> using PQ = priority_queue<T>;
template <typename T> using PQ_R = priority_queue<T, vector<T>, greater<T>>;

template <typename T> inline T ABS(T n) {return n >= 0 ? n : -n;}
template <typename T> __attribute__((target("bmi"))) inline T gcd(T a, T b) {
	if (a < 0) a = -a;
	if (b < 0) b = -b;
	if (a == 0 || b == 0) return a + b;
	int n = __builtin_ctzll(a);
	int m = __builtin_ctzll(b);
	a >>= n;
	b >>= m;
	while (a != b) {
		int m = __builtin_ctzll(a - b);
		bool f = a > b;
		T c = f ? a : b;
		b = f ? b : a;
		a = (c - b) >> m;
	}
	return a << min(n, m);
}
template <typename T> inline T lcm(T a, T b) {return a * (b / gcd(a, b));}
template <typename T, typename... Targs> inline T gcd(T a, T b, T c, Targs... args) {return gcd(a, gcd(b, c, args...));}
template <typename T, typename... Targs> inline T lcm(T a, T b, T c, Targs... args) {return lcm(a, lcm(b, c, args...));}
template <typename T, typename... Targs> inline T min(T a, T b, T c, Targs... args) {return min(a, min(b, c, args...));}
template <typename T, typename... Targs> inline T max(T a, T b, T c, Targs... args) {return max(a, max(b, c, args...));}
template <typename T, typename... Targs> inline void chmin(T &a, T b, Targs... args) {a = min(a, b, args...); return ;}
template <typename T, typename... Targs> inline void chmax(T &a, T b, Targs... args) {a = max(a, b, args...); return ;}

vector<int> Primes(int n) {
	if (n == 1) return {};
	

	vector<int> primes;
	vector<bool> isPrime(n + 1, true);

	primes.reserve(n / __lg(n));

	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) primes.push_back(i);
		for (int j : primes) {
			if (i * j > n) break;
			isPrime[i * j] = false;
			if (i % j == 0) break;
		}
	}
	return primes;
}

template <typename T> vector<T> factors(T x) {
	

	vector<T> ans;
	for (T i = 1; i * i <= x; i++) if (x % i == 0) ans.push_back(i);

	int id = int(ans.size()) - 1;
	if (ans[id] * ans[id] == x) id--;
	for (int i = id; i >= 0; i--) ans.push_back(x / ans[i]);

	return ans;
}

int mex(vector<int> vec) {
	int n = int(vec.size());
	vector<bool> have(n, false);
	for (int i : vec) if (i < n) have[i] = true;
	for (int i = 0; i < n; i++) if (!have[i]) return i;
	return n;
}

template <typename T> T SQ(T x) {return x * x;}

template <typename T> T Mdist(pair<T, T> lhs, pair<T, T> rhs) {return ABS(lhs.first - rhs.first) + ABS(lhs.second - rhs.second);}
template <typename T> T Dist2(pair<T, T> lhs, pair<T, T> rhs) {
	return SQ(lhs.F - rhs.F) + SQ(lhs.S - rhs.S);
}

template <typename T> T id12(T LB, T val, T UB) {return min(max(LB, val), UB);}

template <typename T, typename Comp> T Binary_Search(T L, T R, Comp f) {
	

	static_assert(is_integral<T>::value, "Binary_Search requires an integral type");
	while (R - L > 1) {
		T mid = (L + R) >> 1;
		if (f(mid)) L = mid;
		else R = mid;
	}
	return L;
}

template <typename Comp> double Binary_Search(double L, double R, Comp f, int n = 30) {
	for (int i = 1; i <= n; i++) {
		double mid = (L + R) / 2;
		if (f(mid)) L = mid;
		else R = mid;
	}
	return L;
}

template <typename T> T nearest(set<T> &se, T val) {
	static constexpr T kInf = numeric_limits<T>::max() / 2 - 10;

	if (se.empty()) return kInf;
	else if (val <= *se.begin()) return *se.begin() - val;
	else if (val >= *prev(se.end())) return val - *prev(se.end());
	else {
		auto u = se.lower_bound(val);
		auto v = prev(u);
		return min(*u - val, val - *v);
	}
}

namespace MR32 {
	using ull = unsigned long long int;
	using uint = unsigned int;
	ull PowMod(ull a, ull b, ull kMod) {
		ull ans = 1;
		for (; b; b >>= 1, a = a * a % kMod) if (b & 1) ans = ans * a % kMod;
		return ans;
	}

	bool IsPrime(uint x) {
		static constexpr bool low[8] = {false, false, true, true, false, true, false, true};
		static constexpr uint as = 3, a[3] = {2, 7, 61};
		if (x < 8) return low[x];

		uint t = x - 1;
		int r = 0;
		while ((t & 1) == 0) {
			t >>= 1;
			r++;
		}
		for (uint i = 0; i < as; i++) if (a[i] <= x - 2) {
			bool ok = false;
			ull tt = PowMod(a[i], t, x);
			if (tt == 1) continue;
			for (int j = 0; j < r; j++, tt = tt * tt % x) if (tt == x - 1) {
				ok = true;
				break;
			}
			if (!ok) return false;
		}
		return true;
	}
}


namespace MR64 {
	using uint128 = unsigned __int128;
	using ull = unsigned long long int;
	using uint = unsigned int;
	uint128 PowMod(uint128 a, uint128 b, uint128 kMod) {
		uint128 ans = 1;
		for (; b; b >>= 1, a = a * a % kMod) if (b & 1) ans = ans * a % kMod;
		return ans;
	}

	bool IsPrime(ull x) {
		static constexpr bool low[8] = {false, false, true, true, false, true, false, true};
		static constexpr uint as = 7, a[7] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
		if (x < 8) return low[x];
		ull t = x - 1;
		int r = 0;
		while ((t & 1) == 0) {
			t >>= 1;
			r++;
		}
		for (uint i = 0; i < as; i++) if (a[i] <= x - 2) {
			bool ok = false;
			uint128 tt = PowMod(a[i], t, x);
			if (tt == 1) continue;
			for (int j = 0; j < r; j++, tt = tt * tt % x) if (tt == x - 1) {
				ok = true;
				break;
			}
			if (!ok) return false;
		}
		return true;
	}
}


bool IsPrime(unsigned long long int x) {

	if ((x >> 32) == 0) return MR32::IsPrime(x);
	else return MR64::IsPrime(x);

	return MR32::IsPrime(x);
}


uint64_t id19(uint64_t x) {
	static mt19937 rng;
	if (!(x & 1)) return 2;
	if (IsPrime(x)) return x;
  int64_t a = rng() % (x - 2) + 2, b = a;
  uint64_t c = rng() % (x - 1) + 1, d = 1;
  while (d == 1) {
    a = (__int128(a) * a + c) % x;
    b = (__int128(b) * b + c) % x;
    b = (__int128(b) * b + c) % x;
    d = __gcd(uint64_t(abs(a - b)), x);
    if (d == x) return id19(x);
  }
  return d;
}


template <typename T> vector<T> factorize(T x) {
	if (x <= 1) return {};
	T p = id19(x);
	if (p == x) return {x};
	vector<T> ans, lhs = factorize(p), rhs = factorize(x / p);
	Merge(lhs, rhs, ans);
	return ans;
}

template <typename T> vector<pair<T, int>> Compress(vector<T> vec) {
	

	if (vec.empty()) return {};

	vector<pair<T, int>> ans;
	int cnt = 1, sz = int(vec.size());
	T lst = vec[0];
	for (int i = 1; i < sz; i++) {
		if (lst != vec[i]) {
			ans.push_back(make_pair(lst, cnt));
			lst = vec[i];
			cnt = 1;
		}
		else cnt++;
	}
	ans.push_back(make_pair(lst, cnt));
	return ans;
}





template <typename T> void _print(vector<T> v) ;
void _print(bool x) {printf("%d", x ? 1 : 0);}
void _print(char x) {printf("%c", x);}
void _print(short x) {printf("%hd", x);}
void _print(unsigned short x) {printf("%hu", x);}
void _print(int x) {printf("%d", x);}
void _print(unsigned int x) {printf("%u", x);}
void _print(long long int x) {printf("%lld", x);}
void _print(unsigned long long int x) {printf("%llu", x);}
void _print(float x) {printf("%f", x);}
void _print(double x) {printf("%lf", x);}
void _print(long double x) {printf("%Lf", x);}
template <size_t _size> void _print(bitset<_size> bs) {for (int i = 0; i < _size; i++) printf("%d", bs[i] ? 1 : 0);}

void _print(__int128 x) {
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
void _print(unsigned __int128 x) {
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

template <typename T1, typename T2> void _print(pair<T1, T2> x) {printf("("); _print(x.first); printf(", "); _print(x.second); printf(")");}
template <typename T1, typename T2, typename T3> void _print(tuple<T1, T2, T3> x) {printf("("); _print(get<0>(x)); printf(", "); _print(get<1>(x)); printf(", "); _print(get<2>(x)); printf(")");}
template <typename T> void _print(vector<T> v) {
	if (v.empty()) printf(" empty");
	else {
		bool first = true;
		for (T i : v) {
			if (first) first = false;
			else printf(", ");
			_print(i);
		}
	}
}
template <typename T> void _print(set<T> s) {
	if (s.empty()) printf(" empty");
	else {
		bool first = true;
		for (T i : s) {
			if (first) first = false;
			else printf(", ");
			_print(i);
		}
	}
}
template <typename T> void _print(stack<T> s) {
	if (s.empty()) printf(" empty");
	else {
		_print(s.top()); s.pop();
		while (!s.empty()) {printf(", "); _print(s.top()); s.pop();}
	}
}
template <typename T> void _print(queue<T> q) {
	if (q.empty()) printf(" empty");
	else {
		_print(q.front()); q.pop();
		while (!q.empty()) {printf(", "); _print(q.front()); q.pop();}
	}
}
template <typename T> void _print(deque<T> dq) {
	if (dq.empty()) printf(" empty");
	else {
		_print(dq.front()); dq.pop_front();
		while (!dq.empty()) {printf(", "); _print(dq.front()); dq.pop_front();}
	}
}
template <typename T1, typename T2, typename T3> void _print(priority_queue<T1, T2, T3> pq) {
	if (pq.empty()) printf(" empty");
	else {
		_print(pq.top()); pq.pop();
		while (!pq.empty()) {printf(", "); _print(pq.top()); pq.pop();}
	}
}
template <typename T1, typename T2> void _print(map<T1, T2> m) {
	if (m.empty()) printf(" empty");
	else {
		bool first = true;
		for (pair<T1, T2> i : m) {
			if (first) first = false;
			else printf(", ");
			_print(i);
		}
	}
}

template <typename T> void _print(T x) {return x.out();}
template <typename T, typename... Targs> void _print(T x, Targs... Fargs) {_print(x); printf(", "); _print(Fargs...);}





template <int kMod> struct Mod_Int;
template <int kMod, typename T> constexpr Mod_Int<kMod> Pow(Mod_Int<kMod> a, T b) {
	Mod_Int<kMod> ans = 1;
	while (b) {
		if (b & 1) ans *= a;
		a *= a;
		b >>= 1;
	}
	return ans;
}

template <int kMod> struct Mod_Int {
	static constexpr int Mod() {return kMod;}

	int val;
	constexpr Mod_Int() : val(0) {}
	template <typename T> constexpr Mod_Int(const T &x) : val(x) {}

	constexpr Mod_Int inv() const {return Pow(*this, kMod - 2);} 

	constexpr Mod_Int operator -() const {
		if (val) return Mod_Int(kMod - val);
		else return Mod_Int(0);
	}

	constexpr Mod_Int operator + (const Mod_Int &x) const {
		Mod_Int ans(val + x.val);
		if (ans.val >= kMod) ans.val -= kMod;
		return ans;
	}
	constexpr Mod_Int operator - (const Mod_Int &x) const {
		Mod_Int ans(val - x.val);
		if (ans.val < 0) ans.val += kMod;
		return ans;
	}
	constexpr Mod_Int operator * (const Mod_Int &x) const {return Mod_Int(1LL * val * x.val % kMod);}
	constexpr Mod_Int operator / (const Mod_Int &x) const {return *this * x.inv();}

	constexpr Mod_Int operator += (const Mod_Int &x) {return *this = *this + x;}
	constexpr Mod_Int operator -= (const Mod_Int &x) {return *this = *this - x;}
	constexpr Mod_Int operator *= (const Mod_Int &x) {return *this = *this * x;}
	constexpr Mod_Int operator /= (const Mod_Int &x) {return *this = *this / x;}

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

	constexpr bool operator < (const Mod_Int &x) const {return val < x.val;}
	constexpr bool operator > (const Mod_Int &x) const {return val > x.val;}
	constexpr bool operator <= (const Mod_Int &x) const {return val <= x.val;}
	constexpr bool operator >= (const Mod_Int &x) const {return val >= x.val;}
	constexpr bool operator == (const Mod_Int &x) const {return val == x.val;}
	constexpr bool operator != (const Mod_Int &x) const {return val != x.val;}

	void out() const {printf("%d", val);}
};

using Mint = Mod_Int<kMod>;

template <int kN> struct Factorial {
	Mint val[kN + 1];

	constexpr Factorial() : val() {
		val[0] = val[1] = 1;
		for (int i = 2; i <= kN; i++) val[i] = val[i - 1] * i;
	}

	constexpr Mint operator [] (int x) const {return val[x];}
};

template <int kN> struct id17 {
	Mint val[kN + 1];
	
	constexpr id17(const Factorial<kN> &f) : val() {
		val[0] = val[1] = 1;
		val[kN] = f[kN].inv();
		for (int i = kN; i > 2; i--) val[i - 1] = val[i] * i;
	}

	constexpr Mint operator [] (int x) const {return val[x];}
};


	constexpr Factorial<Pre_Factorial> f; \
	constexpr id17<Pre_Factorial> inf(f); \
	inline Mint C(int n, int m) {return f[n] * inf[m] * inf[n - m];}
	inline Mint Catalan(int n) {return f[n << 1] * inf[n + 1] * inf[n];}

	constexpr Factorial<Pre_Factorial_No_Inf> f; \
	inline Mint C(int n, int m) {return f[n] / f[m] / f[n - m];}
	inline Mint Catalan(int n) {return f[n << 1] / f[n + 1] / f[n];}






template <typename T> void id14(T *a, int n) {
	for (int i = 2; i <= n; i <<= 1)
		for (int j = i; j <= n; j += i)
			for (int l = j - i, r = j - (i >> 1); r < j; l++, r++)
				a[r] += a[l];
	return ;
}

template <typename T> void id11(T *a, int n) {
	for (int i = 2; i <= n; i <<= 1)
		for (int j = i; j <= n; j += i)
			for (int l = j - i, r = j - (i >> 1); r < j; l++, r++)
				a[r] -= a[l];
	return ;
}



int a[kN][kN], b[kN][kN];
Mint ab[kN][kN], ba[kN][kN];
Mint dp[1 << kN], p[kN][1 << kN], tmp[1 << kN], ori[1 << kN];
bool on_main[kN][kN], on_anti[kN][kN];
int n, tot;

Mint solve_all() {
	memcpy(dp, ori, sizeof(dp));

	for (int i = 0; i < n; i++) {
		memcpy(tmp, p[i], sizeof(tmp));
		id14(tmp, tot);
		for (int mask = 0; mask < tot; mask++) dp[mask] *= tmp[mask];
	}

	id11(dp, tot);
	return dp[tot - 1];
}

Mint id4() {
	memcpy(dp, ori, sizeof(dp));

	for (int i = 0; i < n; i++) {
		int id = 1 << i;

		for (int mask = 0; mask < tot; mask++) tmp[mask] = (mask & id) ? 0 : p[i][mask];

		id14(tmp, tot);
		for (int mask = 0; mask < tot; mask++) dp[mask] *= tmp[mask];
	}

	id11(dp, tot);
	return dp[tot - 1];
}

Mint id20() {
	memcpy(dp, ori, sizeof(dp));

	for (int i = 0; i < n; i++) {
		int id = 1 << (n - 1 - i);

		for (int mask = 0; mask < tot; mask++) tmp[mask] = (mask & id) ? 0 : p[i][mask];

		id14(tmp, tot);
		for (int mask = 0; mask < tot; mask++) dp[mask] *= tmp[mask];
	}

	id11(dp, tot);
	return dp[tot - 1];
}

Mint solve_none() {
	memcpy(dp, ori, sizeof(dp));

	for (int i = 0; i < n; i++) {
		int id = (1 << (n - 1 - i)) | (1 << i);

		for (int mask = 0; mask < tot; mask++) tmp[mask] = (mask & id) ? 0 : p[i][mask];

		id14(tmp, tot);
		for (int mask = 0; mask < tot; mask++) dp[mask] *= tmp[mask];
	}

	id11(dp, tot);
	return dp[tot - 1];
}

int main() {
	RP(n);
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) RP(a[i][j]);

	for (int i = 0; i < n; i++) on_main[i][i] = true;
	for (int i = 0; i < n; i++) on_anti[i][n - 1 - i] = true;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) b[i][j] = 10000 - a[i][j];
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) ab[i][j] = Mint(b[i][j]) / a[i][j];
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) ba[i][j] = Mint(a[i][j]) / b[i][j];


	tot = 1 << n;

	for (int i = 0; i < n; i++) {
		p[i][0] = 0;

		Mint cur = 1;
		for (int j = 0; j < n; j++) cur *= a[i][j];

		for (int j = 1, mask = 0; j < tot; j++) {
			int lowbit = j & -j;
			int id1 = __lg(lowbit);
			mask ^= lowbit;

			if (mask & lowbit) cur *= ab[i][id1];
			else cur *= ba[i][id1];

			p[i][mask] = cur;
		}
	}

	ori[0] = 1;
	id14(ori, tot);

	Mint ans = solve_all() - id4() - id20() + solve_none();
	ans /= Pow(Mint(10000), n * n);
	ans = Mint(1) - ans;

	printf("%d\n", ans);
}


