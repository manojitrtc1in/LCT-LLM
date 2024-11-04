




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
#ifdef ONLINE_JUDGE
	#define Debug(x) ;
	#define Debugln(x) ;
	#define Debug_Array(n,x) ;
	#define Debugln_Array(n,x) ;
	#define NL ;
#else
	#define Debug(x) printf("%s :", (#x)), _Debug(x)
	#define Debugln(x) printf("%s :", (#x)), _Debugln(x)
	#define Debug_Array(n,x) printf("%s :", (#x)), _Debug_Array((n), (x))
	#define Debugln_Array(n,x) printf("%s :", (#x)), _Debugln_Array((n), (x))
	#define NL printf("\n")
#endif
typedef long long int ll;
typedef unsigned long long int ull;

constexpr int kN = int(3E5 + 10);


















static inline char Get_Raw_Char() {
	static char buf[1 << 16], *p = buf, *end = buf;
	if (p == end) {
		if ((end = buf + fread(buf, 1, 1 << 16, stdin)) == buf) return '\0';
		p = buf;
	}
	return *p++;
}



template <typename T> static inline void Read_P(T &n) {
	static_assert(is_integral<T>::value);
	char c;
	while (!isdigit(c = Get_Raw_Char())) ;
	n = int(c - '0');
	while (isdigit(c = Get_Raw_Char())) n = n * 10 + int(c - '0');
	return ;
}

template <typename T> static inline void Read(T &n) {
	static_assert(is_integral<T>::value);
	char c;
	bool neg = false;
	while (!isdigit(c = Get_Raw_Char())) if (c == '-') neg = true;
	n = int(c - '0');
	while (isdigit(c = Get_Raw_Char())) n = n * 10 + int(c - '0');
	if (neg) n = -n;
	return ;
}

template <typename T> static inline void Read_Digit(T &n) {
	static_assert(is_integral<T>::value);
	char c;
	while (!isdigit(c = Get_Raw_Char())) ;
	n = int(c - '0');
	return ;
}



template <typename T, typename... Targs> static inline void Read(T &n, Targs&... Fargs) {Read(n); return Read(Fargs...);}
template <typename T, typename... Targs> static inline void Read_Digit(T &n, Targs&... Fargs) {Read_Digit(n); return Read_Digit(Fargs...);}
template <typename T, typename... Targs> static inline void Read_P(T &n, Targs&... Fargs) {Read_P(n); return Read_P(Fargs...);}



template <typename T> static inline void Read_Loop_i(int i, T *a) {return Read(a[i]);}
template <typename T, typename... Targs> static inline void Read_Loop_i(int i, T *a, Targs*... Fargs) {Read(a[i]); return Read_Loop_i(i, Fargs...);}
template <typename... Targs> static inline void Read_Loop(int n, Targs*... Fargs) {for (int i = 1; i <= n; i++) Read_Loop_i(i, Fargs...);}

template <typename T> static inline void Read_Loop_Digit_i(int i, T *a) {return Read_Digit(a[i]);}
template <typename T, typename... Targs> static inline void Read_Loop_Digit_i(int i, T *a, Targs*... Fargs) {Read_Digit(a[i]); return Read_Loop_Digit_i(i, Fargs...);}
template <typename... Targs> static inline void Read_Loop_Digit(int n, Targs*... Fargs) {for (int i = 1; i <= n; i++) Read_Loop_Digit_i(i, Fargs...);}

template <typename T> static inline void Read_Loop_P_i(int i, T *a) {return Read_P(a[i]);}
template <typename T, typename... Targs> static inline void Read_Loop_P_i(int i, T *a, Targs*... Fargs) {Read_P(a[i]); return Read_Loop_P_i(i, Fargs...);}
template <typename... Targs> static inline void Read_Loop_P(int n, Targs*... Fargs) {for (int i = 1; i <= n; i++) Read_Loop_P_i(i, Fargs...);}



template <int mul, typename T> static inline void Read(T &n) {
	char c;
	bool neg = false;
	while (!isdigit(c = Get_Raw_Char())) if (c == '-') neg = true;
	n = int(c - '0');
	while (isdigit(c = Get_Raw_Char())) n = n * 10 + int(c - '0');
	
	int cnt = 0;

	if (c == '.') {
		while (isdigit(c = Get_Raw_Char())) {
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
	while (!isdigit(c = Get_Raw_Char())) ;
	
	n = int(c - '0');
	while (isdigit(c = Get_Raw_Char())) n = n * 10 + int(c - '0');
	
	int cnt = 0;

	if (c == '.') {
		while (isdigit(c = Get_Raw_Char())) {
			n = n * 10 + int(c - '0');
			cnt++;
		}
	}

	while (cnt++ < mul) n = n * 10;
	return ;
}

template <int mul, typename T, typename... Targs> static inline void Read(T &n, Targs&... Fargs) {Read<mul>(n); return Read<mul>(Fargs...);}
template <int mul, typename T, typename... Targs> static inline void Read_P(T &n, Targs&... Fargs) {Read_P<mul>(n); return Read_P<mul>(Fargs...);}



inline void IOS() {ios::sync_with_stdio(false); cin.tie(0);}
inline void Freopen(const char *in, const char *out) {freopen(in, "r", stdin); freopen(out, "w", stdout);}



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

template <typename T> inline void reverse(vector<T> &v) {return reverse(v.begin(), v.end());}

template <typename T> inline void Merge(vector<T> &a, vector<T> &b, vector<T> &c) {
	if (c.size() < a.size() + b.size()) c.resize(a.size() + b.size());
	merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
	return ;
}

template <typename T> inline void Discrete(vector<T> &v) {sort(v); v.resize(unique(v.begin(), v.end()) - v.begin());}

template <typename T> using PQ = priority_queue<T>;
template <typename T> using PQ_R = priority_queue<T, vector<T>, greater<T>>;

template <typename T> inline T ABS(T n) {return n >= 0 ? n : -n;}
template <typename T> __attribute__((target("bmi"))) inline T gcd(T a, T b) {
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
template <typename T> inline T lcm(T a, T b) {return a * b / gcd(a, b);}
template <typename T, typename... Targs> inline T gcd(T a, T b, T c, Targs... args) {return gcd(a, gcd(b, c, args...));}
template <typename T, typename... Targs> inline T lcm(T a, T b, T c, Targs... args) {return lcm(a, lcm(b, c, args...));}
template <typename T, typename... Targs> inline T min(T a, T b, T c, Targs... args) {return min(a, min(b, c, args...));}
template <typename T, typename... Targs> inline T max(T a, T b, T c, Targs... args) {return max(a, max(b, c, args...));}
template <typename T, typename... Targs> inline void chmin(T &a, T b, Targs... args) {a = min(a, b, args...); return ;}
template <typename T, typename... Targs> inline void chmax(T &a, T b, Targs... args) {a = max(a, b, args...); return ;}

template <typename T> inline int Digit_Sum(T a) {
	int ans = 0;
	while (a) {
		ans += a % 10;
		a /= 10;
	}
	return ans;
}
template <typename T> inline int Num_Length(T a) {
	if (a == 0) return 1;
	int ans = 0;
	while (a /= 10) ans++;
	return ans;
}





void _print(int x) {printf("%d", x);}
void _print(long long int x) {printf("%lld", x);}
void _print(double x) {printf("%lf", x);}
template <typename T> void _print(T x) {return x.out();}
template <typename T1, typename T2> void _print(pair<T1, T2> x) {printf("("); _print(x.first); printf(", "); _print(x.second); printf(")");}

template <typename T> void _Debug(T x) {_print(x); printf("\n");}
template <typename T> void _Debug(vector<T> v) {
	if (v.empty()) printf(" empty");
	else for (T i : v) printf(" "), _print(i); 
	printf("\n");
}

template <typename T1, typename T2, typename T3> void _Debug(priority_queue<T1, T2, T3> pq) {
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

template <typename T> void _Debug(queue<T> q) {
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

template <typename T> void _Debug(stack<T> st) {
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

template <typename T> void _Debug(deque<T> dq) {
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

template <typename T> void _Debugln(vector<T> v) {
	if (v.empty()) printf(" empty\n");
	else {
		for (T i : v) printf("\n"), _print(i); 
		printf("\n");
	}
}

template <typename T1, typename T2, typename T3> void _Debugln(priority_queue<T1, T2, T3> pq) {
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

template <typename T> void _Debugln(queue<T> q) {
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

template <typename T> void _Debugln(stack<T> st) {
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

template <typename T> void _Debugln(deque<T> dq) {
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

template <typename T> void _Debug_Array(int n, const T *x) {for (int i = 1; i <= n; i++) printf(" "), _print(x[i]); printf("\n");}
template <typename T> void _Debugln_Array(int n, const T *x) {printf("\n"); for (int i = 1; i <= n; i++) _print(x[i]), printf("\n");}







struct DSU {
	int *p;
	int size;
	
	DSU() {p = nullptr;}
	
	void init(int n) {
		size = n;
		delete [] p; p = new int[n];
		memset(p, -1, sizeof(int) * n);
		return ;
	}

	int Find(int n) {return p[n] < 0 ? n : p[n] = Find(p[n]);}

	inline int union_size(int n) {return -p[Find(n)];}
	inline bool same(int l, int r) {return Find(l) == Find(r);}

	bool Merge(int l, int r) {
		l = Find(l), r = Find(r);
		if (l != r) {
			if (p[l] > p[r]) swap(l, r);
			p[l] += p[r];
			p[r] = l;
			return true;
		}
		else return false;
	}
};



ll a[kN];
int l[kN], r[kN];
vector<int> graph[kN], ans;
int p[kN], ntop[kN], p_edge[kN]; 
DSU dsu;

void dfs(int cur, int from) {
	p[cur] = from;
	for (int i : graph[cur]) {
		int nxt = l[i] ^ r[i] ^ cur;
		if (nxt != from) {
			p_edge[nxt] = i;
			dfs(nxt, cur);
		}
	}
	return ;
}

void dfs2(int cur, int from) {
	for (int i : graph[cur]) {
		int nxt = l[i] ^ r[i] ^ cur;
		if (dsu.Merge(cur, nxt)) ans.PB(i);
		if (nxt != from) dfs2(nxt, cur);
	}
	return ;
}

int main() {
	int n, m, x; RP(n, m, x);
	RLP(n, a);
	RLP(m, l, r);

	ll sum = 0;
	for (int i = 1; i <= n; i++) sum += a[i];

	if (sum < ll(x) * (n - 1)) {
		printf("NO\n");
		return 0;
	}

	dsu.init(n + 1);
	for (int i = 1; i <= m; i++) {
		if (dsu.Merge(l[i], r[i])) {
			graph[l[i]].PB(i);
			graph[r[i]].PB(i);
		}
	}
	dsu.init(n + 1);

	dfs(1, 1);
	for (int i = 1; i <= n; i++) ntop[i] = i;

	for (int i = 1; i <= n; i++) {
		while (a[dsu.Find(i)] + a[dsu.Find(p[ntop[dsu.Find(i)]])] >= x && ntop[dsu.Find(i)] != 1) {
			ans.PB(p_edge[ntop[dsu.Find(i)]]);
			int lid = dsu.Find(i), rid = dsu.Find(p[ntop[dsu.Find(i)]]);
			dsu.Merge(lid, rid);
			int nid = dsu.Find(i);
			ntop[nid] = ntop[rid];
			a[nid] = a[lid] + a[rid] - x;
		}
	}

	dfs2(1, 1);

	printf("YES\n");
	for (int i : ans) printf("%d\n", i);
}


