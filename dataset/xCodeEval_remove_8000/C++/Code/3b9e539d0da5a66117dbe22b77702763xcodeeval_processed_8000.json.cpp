





using namespace std;














	
	
	
	

	
	
	
	

typedef long long int ll;
typedef unsigned long long int ull;

constexpr int kN = int(2E5 + 10);
























[[maybe_unused]] static bool id10 = false;
[[maybe_unused]] static bool id14 = false;


static inline char id12() {
	[[maybe_unused]] static bool pre = id10 = true;
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
	while (!isdigit(c = id12())) ;
	n = int(c - '0');
	while (isdigit(c = id12())) n = n * 10 + int(c - '0');
	return ;
}

template <typename T> static inline void Read(T &n) {
	static_assert(is_integral<T>::value, "Read requires an integral type");
	char c;
	bool neg = false;
	while (!isdigit(c = id12())) if (c == '-') neg = true;
	n = int(c - '0');
	while (isdigit(c = id12())) n = n * 10 + int(c - '0');
	if (neg) n = -n;
	return ;
}

template <typename T> static inline void id5(T &n) {
	static_assert(is_integral<T>::value, "id5 requires an integral type");
	char c;
	while (!isdigit(c = id12())) ;
	n = int(c - '0');
	return ;
}

static inline void Read_String(string &s) {
	s.clear();
	char c = id12();
	while (c == ' ' or c == '\n') c = id12();
	while (c != ' ' and c != '\n') {
		s += c;
		c = id12();
	}
	return ;
}



template <typename T, typename... Targs> static inline void Read(T &n, Targs&... Fargs) {Read(n); return Read(Fargs...);}
template <typename T, typename... Targs> static inline void id5(T &n, Targs&... Fargs) {id5(n); return id5(Fargs...);}
template <typename T, typename... Targs> static inline void Read_P(T &n, Targs&... Fargs) {Read_P(n); return Read_P(Fargs...);}
template <typename... Targs> static inline void Read_String(string &s, Targs&... Fargs) {Read_String(s); return Read_String(Fargs...);}



template <typename T> static inline void id2(int i, T *a) {return Read(a[i]);}
template <typename T, typename... Targs> static inline void id2(int i, T *a, Targs*... Fargs) {Read(a[i]); return id2(i, Fargs...);}
template <typename... Targs> static inline void id9(int n, Targs*... Fargs) {for (int i = 1; i <= n; i++) id2(i, Fargs...);}

template <typename T> static inline void id4(int i, T *a) {return id5(a[i]);}
template <typename T, typename... Targs> static inline void id4(int i, T *a, Targs*... Fargs) {id5(a[i]); return id4(i, Fargs...);}
template <typename... Targs> static inline void id7(int n, Targs*... Fargs) {for (int i = 1; i <= n; i++) id4(i, Fargs...);}

template <typename T> static inline void id6(int i, T *a) {return Read_P(a[i]);}
template <typename T, typename... Targs> static inline void id6(int i, T *a, Targs*... Fargs) {Read_P(a[i]); return id6(i, Fargs...);}
template <typename... Targs> static inline void id0(int n, Targs*... Fargs) {for (int i = 1; i <= n; i++) id6(i, Fargs...);}

static inline void id13(int i, string *a) {return Read_String(a[i]);}
template <typename... Targs> static inline void id13(int i, string *a, Targs*... Fargs) {Read_String(a[i]); return id13(i, Fargs...);}
template <typename... Targs> static inline void id1(int n, Targs*... Fargs) {for (int i = 1; i <= n; i++) id13(i, Fargs...);}



template <int mul, typename T> static inline void Read(T &n) {
	char c;
	bool neg = false;
	while (!isdigit(c = id12())) if (c == '-') neg = true;
	n = int(c - '0');
	while (isdigit(c = id12())) n = n * 10 + int(c - '0');

	int cnt = 0;

	if (c == '.') {
		while (isdigit(c = id12())) {
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
	while (!isdigit(c = id12())) ;

	n = int(c - '0');
	while (isdigit(c = id12())) n = n * 10 + int(c - '0');

	int cnt = 0;

	if (c == '.') {
		while (isdigit(c = id12())) {
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
	id14 = true;
	ios::sync_with_stdio(false); cin.tie(0);
}
inline void Freopen(const char *in, const char *out) {freopen(in, "r", stdin); freopen(out, "w", stdout); return ;}




void Print(__int128 x) {
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






template <typename T, typename T1> void id16(vector<T>& vec, T1 c) {return vec.push_back(T(c));}
template <typename T, typename T1, typename... Targs> void id16(vector<T> &vec, T1 c, Targs... targs) {
	vec.push_back(T(c));
	return id16(vec, targs...);
}
template <typename T, typename... Targs> vector<T> make_vector(Targs... targs) {
	vector<T> vec;
	id16(vec, targs...);
	return vec;
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
template <typename T> inline void id15(vector<T> &a, vector<T> &b, vector<T> &c) {
	int a_size = int(a.size()), b_size = int(b.size());
	c.resize(a_size + b_size);
	for (int i = 0; i < a_size; i++) c[i] = a[i];
	for (int i = 0; i < b_size; i++) c[i + a_size] = b[i];
	return ;
}
template <typename T> inline void Append(vector<T> &lhs, vector<T> rhs) {
	int lsz = int(lhs.size()), rsz = int(rhs.size());
	lhs.reserve(lsz + rsz);
	for (int i = 0; i < rsz; i++) lhs.push_back(rhs[i]);
	return ;
}

template <typename T> inline void Erase(vector<T> &vec, T x) {
	int sz = int(vec.size());
	for (int i = 0; i < sz; i++) if (vec[i] == x) {
		swap(vec[i], vec.back());
		vec.pop_back();
		break;
	}
	return ;
}

template <typename T> inline void Discrete(vector<T> &v) {sort(v); v.resize(unique(v.begin(), v.end()) - v.begin()); return ;}
template <typename T> inline int Discrete_Id(vector<T> &v, T x) {return lower_bound(v.begin(), v.end(), x) - v.begin();}

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
	if (n <= 1) return {};
	

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



template <typename T> T Dist2(pair<T, T> lhs, pair<T, T> rhs) {return SQ(lhs.F - rhs.F) + SQ(lhs.S - rhs.S);}
template <typename T> T Dist2(T x1, T y1, T x2, T y2) {return SQ(x1 - x2) + SQ(y1 - y2);}



template <typename T> T Mdist(pair<T, T> lhs, pair<T, T> rhs) {return ABS(lhs.first - rhs.first) + ABS(lhs.second - rhs.second);}
template <typename T> T Mdist(T x1, T y1, T x2, T y2) {return ABS(x1 - x2) + ABS(y1 - y2);}

template <typename T> bool Adj(pair<T, T> lhs, pair<T, T> rhs) {return Mdist(lhs, rhs) == 1;}

template <typename T> T id11(T LB, T val, T UB) {return min(max(LB, val), UB);}

template <typename T, typename Comp> T Binary_Search(T L, T R, Comp f) {
	

	static_assert(is_integral<T>::value, "Binary_Search requires an integral type");
	while (R - L > 1) {
		T mid = (L + R) >> 1;
		if (f(mid)) L = mid;
		else R = mid;
	}
	return L;
}

template <typename Comp> double Binary_Search(double L, double R, Comp f, int loop = 30) {
	for (int i = 1; i <= loop; i++) {
		double mid = (L + R) / 2;
		if (f(mid)) L = mid;
		else R = mid;
	}
	return L;
}

template <typename T> T nearest_dist(set<T> &se, T val) {
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

template <typename T> T nearest_elem(set<T> &se, T val) {
	static constexpr T kInf = numeric_limits<T>::max() / 2 - 10;

	if (se.empty()) return kInf;
	else if (val <= *se.begin()) return *se.begin();
	else if (val >= *prev(se.end())) return *prev(se.end());
	else {
		auto u = se.lower_bound(val);
		auto v = prev(u);

		if (*u - val > val - *v) return *v;
		else return *u;
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


uint64_t id17(uint64_t x) {
	static mt19937 rng;
	if (!(x & 1)) return 2;
	if (IsPrime(x)) return x;
  int64_t a = rng() % (x - 2) + 2, b = a;
  uint64_t c = rng() % (x - 1) + 1, d = 1;
  while (d == 1) {
    a = (__int128(a) * a + c) % x;
    b = (__int128(b) * b + c) % x;
    b = (__int128(b) * b + c) % x;
    d = gcd(uint64_t(abs(a - b)), x);
    if (d == x) return id17(x);
  }
  return d;
}

template <typename T> vector<T> factorize(T x) {
	if (x <= 1) return vector<T>();
	T p = id17(x);
	if (p == x) return vector<T>(1, x);
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

template <typename T> int id3(T x) {
	vector<pair<T, int>> fac = Compress(factorize(x));

	int ans = 1;
	for (pair<T, int> i : fac) ans *= i.second + 1;

	return ans;
}

template <typename T> T phi(T x) {
	vector<pair<T, int>> fac = Compress(factorize(x));

	T ans = 1;
	for (pair<T, int> i : fac) {
		ans *= i.first - 1;
		for (int j = 1; j < i.second; j++) ans *= i.first;
	}

	return ans;
}

template <typename T> vector<pair<T, T>> id18(T l, T r) {
	vector<pair<T, T>> lhs, rhs;
	while (l + (l & -l) - 1 <= r) {
		lhs.push_back(make_pair(l, l + (l & -l) - 1));
		l += (l & -l);
	}

	while (r - ((r + 1) & -(r + 1)) + 1 >= l) {
		rhs.push_back(make_pair(r - ((r + 1) & -(r + 1)) + 1, r));
		r -= (r + 1) & -(r + 1);
	}

	reverse(rhs);
	for (pair<ll, ll> i : rhs) lhs.push_back(i);
	return lhs;
}





template <typename T> void _print(vector<T> v) ;
void _print(bool x) {printf("%s", x ? "True" : "False");}
void _print(char x) {printf("%c", x);}
void _print(short x) {printf("%hd", x);}
void _print(unsigned short x) {printf("%hu", x);}
void _print(int x) {printf("%d", x);}
void _print(unsigned int x) {printf("%u", x);}
void _print(long int x) {printf("%ld", x);}
void _print(unsigned long int x) {printf("%lu", x);}
void _print(long long int x) {printf("%lld", x);}
void _print(unsigned long long int x) {printf("%llu", x);}
void _print(float x) {printf("%f", x);}
void _print(double x) {printf("%lf", x);}
void _print(long double x) {printf("%Lf", x);}
void _print(const char* c) {int n = strlen(c); for (int i = 0; i < n; i++) printf("%c", c[i]);}
void _print(string s) {for (char c : s) printf("%c", c);}
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
template <typename T1, typename T2, typename T3, typename T4> void _print(tuple<T1, T2, T3, T4> x) {printf("("); _print(get<0>(x)); printf(", "); _print(get<1>(x)); printf(", "); _print(get<2>(x)); printf(", "); _print(get<3>(x)); printf(")");}
template <typename T1, typename T2, typename T3, typename T4, typename T5> void _print(tuple<T1, T2, T3, T4, T5> x) {printf("("); _print(get<0>(x)); printf(", "); _print(get<1>(x)); printf(", "); _print(get<2>(x)); printf(", "); _print(get<3>(x)); printf(", "); _print(get<4>(x)); printf(")");}
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

template <typename T> void _print(T& x) {return x.out();}
template <typename T, typename... Targs> void _print(T x, Targs... Fargs) {_print(x); printf(", "); _print(Fargs...);}





template <typename T, typename T1 = vector<T>, typename T2 = less<T>> class id8 {
	private:
		priority_queue<T, T1, T2> _pq, _xpq;
		void pull();

	public:
		id8();
		~id8();

		bool empty() const; 
		int size() const;
		void clear();

		void push(T x);
		void pop();
		T top();

		void erase(T x);

		void out() const;
};

template <typename T, typename T1, typename T2> void id8<T, T1, T2>::pull() {
	while (!_xpq.empty() && _xpq.top() == _pq.top()) _xpq.pop(), _pq.pop();
	return ;
}

template <typename T, typename T1, typename T2> id8<T, T1, T2>::id8() {}
template <typename T, typename T1, typename T2> id8<T, T1, T2>::~id8() {}

template <typename T, typename T1, typename T2> bool id8<T, T1, T2>::empty() const {return int(_pq.size()) - int(_xpq.size()) == 0;}
template <typename T, typename T1, typename T2> int id8<T, T1, T2>::size() const {return int(_pq.size()) - int(_xpq.size());}
template <typename T, typename T1, typename T2> void id8<T, T1, T2>::clear() {
	priority_queue<T, T1, T2> pq, xpq;
	swap(pq, _pq);
	swap(xpq, _xpq);
	return ;
}

template <typename T, typename T1, typename T2> void id8<T, T1, T2>::push(T x) {return _pq.push(x);}
template <typename T, typename T1, typename T2> void id8<T, T1, T2>::pop() {return _pq.pop();}
template <typename T, typename T1, typename T2> T id8<T, T1, T2>::top() {
	pull();
	return _pq.top();
}

template <typename T, typename T1, typename T2> void id8<T, T1, T2>::erase(T x) {
	_xpq.push(x);
	return ;
}

template <typename T, typename T1, typename T2> void id8<T, T1, T2>::out() const {
	if (this -> size() == 0) printf("empty");
	else {
		priority_queue<T, T1, T2> pq(_pq), xpq(_xpq);
		bool first = true;
		printf("(");
		while (!pq.empty()) {
			while (!xpq.empty() && xpq.top() == pq.top()) xpq.pop(), pq.pop();
			if (!pq.empty()) {
				if (first) first = false;
				else printf(", ");
				_print(pq.top());

				pq.pop();
			}
		}
		printf(")");
	}
	return ;
}

template <typename T> using EPQ = id8<T, vector<T>, less<T>>;
template <typename T> using EPQ_R = id8<T, vector<T>, greater<T>>;



int a[kN], b[kN];
int p[kN], x[kN];

ll ans[kN];

void subSolve( int n, int q, int k )
{
    for( int i = 1; i <= n; i++ ) a[i] = b[i];

    vector<ll> vec( k );
    for( int i = 1; i <= n; i++ ) vec[i % k] += a[i];

    EPQ<ll> pq;

    for( ll j : vec ) pq.push( j );

    chmax( ans[0], pq.top() * k );

    for( int i = 1; i <= q; i++ )
    {
        pq.erase( vec[p[i] % k] );

        vec[p[i] % k] -= a[p[i]] - x[i];
        a[p[i]] = x[i];

        pq.push( vec[p[i] % k] );

        chmax( ans[i], pq.top() * k );
    }

    return ;
}

void solve()
{
    int n, q; RP( n, q );
    RLP( n, a );
    RLP( q, p, x );

    int tn = n;
    vector<int> factors;
    factors.PB( 1 );
    for( int i = 2; i < n; i++ ) if( tn % i == 0 )
    {
        factors.PB( i );
        

    }

    for( int i = 0; i <= q; i++ ) ans[i] = 0;
    for( int i = 1; i <= n; i++ ) b[i] = a[i];

    for( int k : factors ) subSolve( n, q, k );

    for( int i = 0; i <= q; i++ ) printf( "%lld\n", ans[i] );
    return ;
}

int main() {
    int t; RP( t );
    for( int i = 1; i <= t; i++ )
    {
        solve();
    }

}

