





using namespace std;












	
	

	
	

typedef long long int ll;
typedef unsigned long long int ull;

constexpr int kN = int(5E5 + 10);
constexpr int kMod = 998244353;
















static inline char id2() {
	static char buf[1 << 16], *p = buf, *end = buf;
	if (p == end) {
		if ((end = buf + fread(buf, 1, 1 << 16, stdin)) == buf) return '\0';
		p = buf;
	}
	return *p++;
}



template <typename T> static inline void Read_P(T &n) {
	static_assert(is_integral<T>::value);
	char c = id2();
	while (!isdigit(c)) c = id2();
	n = int(c - '0');
	while (isdigit(c = id2())) n = n * 10 + int(c - '0');
	return ;
}

template <typename T> static inline void Read(T &n) {
	static_assert(is_integral<T>::value);
	char c = id2();
	bool neg = false;
	while (!isdigit(c)) {
		if (c == '-') neg = true;
		c = id2();
	}
	n = int(c - '0');
	while (isdigit(c = id2())) n = n * 10 + int(c - '0');
	if (neg) n = -n;
	return ;
}

template <typename T> static inline void id3(T &n) {
	static_assert(is_integral<T>::value);
	char c = id2();
	while (!isdigit(c)) c = id2();
	n = int(c - '0');
	return ;
}



template <typename T, typename... Targs> static inline void Read(T &n, Targs&... Fargs) {Read(n); return Read(Fargs...);}
template <typename T, typename... Targs> static inline void id3(T &n, Targs&... Fargs) {id3(n); return id3(Fargs...);}
template <typename T, typename... Targs> static inline void Read_P(T &n, Targs&... Fargs) {Read_P(n); return Read_P(Fargs...);}



template <typename T> static inline void id5(int i, T *a) {return Read(a[i]);}
template <typename T, typename... Targs> static inline void id5(int i, T *a, Targs*... Fargs) {Read(a[i]); return id5(i, Fargs...);}
template <typename... Targs> static inline void id8(int n, Targs*... Fargs) {for (int i = 1; i <= n; i++) id5(i, Fargs...);}

template <typename T> static inline void id1(int i, T *a) {return id3(a[i]);}
template <typename T, typename... Targs> static inline void id1(int i, T *a, Targs*... Fargs) {id3(a[i]); return id1(i, Fargs...);}
template <typename... Targs> static inline void id6(int n, Targs*... Fargs) {for (int i = 1; i <= n; i++) id1(i, Fargs...);}

template <typename T> static inline void id4(int i, T *a) {return Read_P(a[i]);}
template <typename T, typename... Targs> static inline void id4(int i, T *a, Targs*... Fargs) {Read_P(a[i]); return id4(i, Fargs...);}
template <typename... Targs> static inline void id0(int n, Targs*... Fargs) {for (int i = 1; i <= n; i++) id4(i, Fargs...);}



template <int mul, typename T> static inline void Read(T &n) {
	char c = id2();
	bool neg = false;
	while (!isdigit(c)) {
		if (c == '-') neg = true;
		c = id2();
	}
	n = int(c - '0');
	while (isdigit(c = id2())) n = n * 10 + int(c - '0');
	
	int cnt = 0;

	if (c == '.') {
		while (isdigit(c = id2())) {
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
	char c = id2();
	while (!isdigit(c)) c = id2();
	
	n = int(c - '0');
	while (isdigit(c = id2())) n = n * 10 + int(c - '0');
	
	int cnt = 0;

	if (c == '.') {
		while (isdigit(c = id2())) {
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

template <int mul, typename T, typename... Targs> static inline void Read(T &n, Targs&... Fargs) {Read<mul>(n); return Read<mul>(Fargs...);}

template <int mul, typename T, typename... Targs> static inline void Read_P(T &n, Targs&... Fargs) {Read_P<mul>(n); return Read_P<mul>(Fargs...);}

inline void IOS() {ios::sync_with_stdio(false); cin.tie(0);}



inline void Freopen(const char *in, const char *out) {	freopen(in, "r", stdin); freopen(out, "w", stdout);}




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
template <typename T> inline void sort(int n, T *a) {return sort(a + 1, a + n + 1);}
template <typename T> inline void sort_r(vector<T> &v) {return sort(v.begin(), v.end(), greater<T>());}
template <typename T> inline void sort_r(int n, T *a) {return sort(a + 1, a + n + 1, greater<T>());}

template <typename T> inline void Merge(vector<T> &a, vector<T> &b, vector<T> &c) {
	if (c.size() < a.size() + b.size()) c.resize(a.size() + b.size());
	merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
	return ;
}

template <typename T> inline void Discrete(vector<T> &v) {sort(v); v.resize(unique(v.begin(), v.end()) - v.begin());}

template <typename T> using PQ = priority_queue<T>;
template <typename T> using PQ_R = priority_queue<T, vector<T>, greater<T>>;

template <typename T> inline T ABS(T n) {return n >= 0 ? n : -n;}
template <typename T> inline T gcd(T a, T b) {return b ? gcd(b, a % b) : a;}
template <typename T> inline T lcm(T a, T b) {return a * b / gcd(a, b);}
template <typename T> inline void chmin(T &a, T b) {
	a = min(a, b);
	return ;
}
template <typename T> inline void chmax(T &a, T b) {
	a = max(a, b);
	return ;
}

template <typename T> inline int id12(T a) {
	int ans = 0;
	while (a) {
		ans += a % 10;
		a /= 10;
	}
	return ans;
}






void _print(int x) {printf("%d", x);}
void _print(long long int x) {printf("%lld", x);}
void _print(double x) {printf("%lf", x);}
template <typename T1, typename T2> void _print(pair<T1, T2> x) {printf("("); _print(x.first); printf(", "); _print(x.second); printf(")");}

template <typename T> void _Debug(const char *s, T x) {printf("%s = ", s); _print(x); printf("\n");}
template <typename T> void _Debug(const char *s, vector<T> v) {
	printf("%s :", s); 
	if (v.empty()) printf(" empty");
	else for (T i : v) printf(" "), _print(i); 
	printf("\n");
}

template <typename T1, typename T2, typename T3> void _Debug(const char *s, priority_queue<T1, T2, T3> pq) {
	printf("%s :", s);
	if (pq.empty()) printf(" empty");
	else {
		while (!pq.empty()) {
			printf(" ");
			_print(pq.top());
			pq.pop();
		}
	}
	printf("\n");
}

template <typename T> void _Debug(const char *s, queue<T> q) {
	printf("%s :", s);
	if (q.empty()) printf(" empty");
	else {
		while (!q.empty()) {
			printf(" ");
			_print(q.front());
			q.pop();
		}
	}
	printf("\n");
}

template <typename T> void _Debug(const char *s, stack<T> st) {
	printf("%s :", s);
	if (st.empty()) printf(" empty");
	else {
		while (!st.empty()) {
			printf(" ");
			_print(st.top());
			st.pop();
		}
	}
	printf("\n");
}

template <typename T> void _Debug(const char *s, deque<T> dq) {
	printf("%s :", s);
	if (dq.empty()) printf(" empty");
	else {
		while (!dq.empty()) {
			printf(" ");
			_print(dq.front());
			dq.pop_front();
		}
	}
	printf("\n");
}

template <typename T> void _Debugln(const char *s, vector<T> v) {
	printf("%s :", s); 
	if (v.empty()) printf(" empty\n");
	else {
		for (T i : v) printf("\n"), _print(i); printf("\n");
	}
}

template <typename T1, typename T2, typename T3> void _Debugln(const char *s, priority_queue<T1, T2, T3> pq) {
	printf("%s :", s);
	if (pq.empty()) printf(" empty");
	else {
		while (!pq.empty()) {
			printf("\n");
			_print(pq.top());
			pq.pop();
		}
	}
	printf("\n");
}

template <typename T> void _Debugln(const char *s, queue<T> q) {
	printf("%s :", s);
	if (q.empty()) printf(" empty");
	else {
		while (!q.empty()) {
			printf("\n");
			_print(q.front());
			q.pop();
		}
	}
	printf("\n");
}

template <typename T> void _Debugln(const char *s, stack<T> st) {
	printf("%s :", s);
	if (st.empty()) printf(" empty");
	else {
		while (!st.empty()) {
			printf("\n");
			_print(st.top());
			st.pop();
		}
	}
	printf("\n");
}

template <typename T> void _Debugln(const char *s, deque<T> dq) {
	printf("%s :", s);
	if (dq.empty()) printf(" empty");
	else {
		while (!dq.empty()) {
			printf("\n");
			_print(dq.front());
			dq.pop_front();
		}
	}
	printf("\n");
}

template <typename T> void _Debug_Array(int n, const char *s, const T *x) {printf("%s :", s); for (int i = 1; i <= n; i++) printf(" "), _print(x[i]); printf("\n");}
template <typename T> void id11(int n, const char *s, const T *x) {printf("%s :\n", s); for (int i = 1; i <= n; i++) _print(x[i]), printf("\n");}






template <typename T> T safe_mod(T a, int kMod) {
	a %= kMod;
	if (a < 0) a += kMod;
	return a;
}

template <typename T1, typename T2> T1 Pow(T1 a, T2 b) {
	T1 ans(1);
	while (b) {
		if (b & 1) ans *= a;
		a *= a;
		b >>= 1;
	}
	return ans;
}

template <int kMod> struct Mod_Int {
	constexpr static int Mod() {return kMod;}

	int val;
	Mod_Int() {val = 0;}
	template <typename T> Mod_Int(const T &x) {val = x;}
	template <int nMod> Mod_Int(const Mod_Int<nMod> &x) {val = x.val;}

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
	Mod_Int operator * (const Mod_Int &x) const {return Mod_Int(1LL * val * x.val % kMod);}
	Mod_Int operator / (const Mod_Int &x) const {return *this * x.inv();}
	Mod_Int operator ^ (const Mod_Int &x) const {return Pow(*this, x.val);}
	Mod_Int operator << (const int &x) const {return ((1LL * val) << x) % kMod;}

	Mod_Int operator += (const Mod_Int &x) {return *this = *this + x;}
	Mod_Int operator -= (const Mod_Int &x) {return *this = *this - x;}
	Mod_Int operator *= (const Mod_Int &x) {return *this = *this * x;}
	Mod_Int operator /= (const Mod_Int &x) {return *this = *this / x;}
	Mod_Int operator ^= (const Mod_Int &x) {return *this = Pow(*this, x.val);}
	Mod_Int operator <<= (const int &x) {return *this = *this << x;}

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

	bool operator < (const Mod_Int &x) const {return val < x.val;}
	bool operator > (const Mod_Int &x) const {return val > x.val;}
	bool operator <= (const Mod_Int &x) const {return val <= x.val;}
	bool operator >= (const Mod_Int &x) const {return val >= x.val;}
	bool operator == (const Mod_Int &x) const {return val == x.val;}
	bool operator != (const Mod_Int &x) const {return val != x.val;}
};

using Mint = Mod_Int<kMod>;

namespace Factorial {
	Mint *f, *inf;
	bool id9;
	void id7(const int &sz) {
		if (id9) return ;
		id9 = true;
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
	void id7(const int &sz) {
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
	void id10(const int &sz) {
		inv = new Mint[sz + 1];
		inv[1] = 1;
		id7(sz);
		for (int i = 1; i <= sz; i++) inv[i] = f[i - 1] * inf[i];
		return ;
	}
};




Mint tot[kN], s[2][kN];
int a[kN];

int main() {
	int n; RP(n);
	RLP(n, a);

	tot[1] = a[1];
	s[1][1] = a[1];
	s[0][1] = 0;

	stack<int> st;
	st.push(1);

	for (int i = 2; i <= n; i++) {

		


		if (a[i] >= a[i - 1]) tot[i] = tot[i - 1] * (a[i] - 1);
		else {

			int idx = 0;
			while (!st.empty()) {
				if (a[st.top()] <= a[i]) {
					idx = st.top();
					break;
				}
				else st.pop();
			}

			tot[i] = (s[(i ^ 1) & 1][i - 1] - s[(i ^ 1) & 1][idx]) * a[i]
						 - (s[i & 1][i - 1] - s[i & 1][idx]) * a[i];

			if ((i - idx) & 1) {
				if (idx == 0) tot[i] += a[i];
				else tot[i] += tot[idx] * (a[i] - 1);
			}
			else {
				if (idx == 0) tot[i] -= a[i];
				else tot[i] -= tot[idx] * (a[i] - 1);
			}

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

		}

		st.push(i);

		s[0][i] = s[0][i - 1];
		s[1][i] = s[1][i - 1];
		s[i & 1][i] += tot[i];
	}

	Mint ans(tot[n]);
	printf("%d\n", ans.val % kMod);
}



