





using namespace std;












	
	
	
	
	

	
	
	
	
	

typedef long long int ll;
typedef unsigned long long int ull;

constexpr int kN = int(1E5 + 10);




constexpr int kInf = 0x3f3f3f3f;












static inline char id3() {
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
	while (!isdigit(c = id3())) ;
	n = int(c - '0');
	while (isdigit(c = id3())) n = n * 10 + int(c - '0');
	return ;
}

template <typename T> static inline void Read(T &n) {
	static_assert(is_integral<T>::value);
	char c;
	bool neg = false;
	while (!isdigit(c = id3())) if (c == '-') neg = true;
	n = int(c - '0');
	while (isdigit(c = id3())) n = n * 10 + int(c - '0');
	if (neg) n = -n;
	return ;
}

template <typename T> static inline void id4(T &n) {
	static_assert(is_integral<T>::value);
	char c;
	while (!isdigit(c = id3())) ;
	n = int(c - '0');
	return ;
}



template <typename T, typename... Targs> static inline void Read(T &n, Targs&... Fargs) {Read(n); return Read(Fargs...);}
template <typename T, typename... Targs> static inline void id4(T &n, Targs&... Fargs) {id4(n); return id4(Fargs...);}
template <typename T, typename... Targs> static inline void Read_P(T &n, Targs&... Fargs) {Read_P(n); return Read_P(Fargs...);}



template <typename T> static inline void id6(int i, T *a) {return Read(a[i]);}
template <typename T, typename... Targs> static inline void id6(int i, T *a, Targs*... Fargs) {Read(a[i]); return id6(i, Fargs...);}
template <typename... Targs> static inline void id8(int n, Targs*... Fargs) {for (int i = 1; i <= n; i++) id6(i, Fargs...);}

template <typename T> static inline void id1(int i, T *a) {return id4(a[i]);}
template <typename T, typename... Targs> static inline void id1(int i, T *a, Targs*... Fargs) {id4(a[i]); return id1(i, Fargs...);}
template <typename... Targs> static inline void id7(int n, Targs*... Fargs) {for (int i = 1; i <= n; i++) id1(i, Fargs...);}

template <typename T> static inline void id5(int i, T *a) {return Read_P(a[i]);}
template <typename T, typename... Targs> static inline void id5(int i, T *a, Targs*... Fargs) {Read_P(a[i]); return id5(i, Fargs...);}
template <typename... Targs> static inline void id0(int n, Targs*... Fargs) {for (int i = 1; i <= n; i++) id5(i, Fargs...);}



template <int mul, typename T> static inline void Read(T &n) {
	char c;
	bool neg = false;
	while (!isdigit(c = id3())) if (c == '-') neg = true;
	n = int(c - '0');
	while (isdigit(c = id3())) n = n * 10 + int(c - '0');
	
	int cnt = 0;

	if (c == '.') {
		while (isdigit(c = id3())) {
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
	while (!isdigit(c = id3())) ;
	
	n = int(c - '0');
	while (isdigit(c = id3())) n = n * 10 + int(c - '0');
	
	int cnt = 0;

	if (c == '.') {
		while (isdigit(c = id3())) {
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

template <typename T> inline int id10(T a) {
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
template <typename T> void id9(int n, const T *x) {printf("\n"); for (int i = 1; i <= n; i++) _print(x[i]), printf("\n");}







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



int a[kN], b[kN];
vector<int> graph[kN];
int dp1[kN], dp2[kN];
int dp1_from[kN], dp2_from[kN];




int deg[kN];
DSU dsu;
vector<pair<int, int>> cut_edges;
vector<pair<int, int>> add_edges;

void dfs(int cur, int from) {

	for (int i : graph[cur]) if (i != from) dfs(i, cur);

	dp1[cur] = 0;
	for (int i : graph[cur]) if (i != from) dp1[cur] += dp2[i] + 1;

	int mx = 0, mx_val = kInf;
	for (int i : graph[cur]) if (i != from && dp1[i] - dp2[i] < mx_val) {
		mx = i;
		mx_val = dp1[i] - dp2[i];
	}

	dp1_from[cur] = mx;
	if (mx) dp1[cur] += mx_val - 1;
	if (mx) assert(mx_val - 1 <= 0);

	int mx2 = 0, id2 = kInf;
	for (int i : graph[cur]) if (i != from && i != mx && dp1[i] - dp2[i] < id2) {
		mx2 = i;
		id2 = dp1[i] - dp2[i];
	}

	dp2[cur] = dp1[cur];
	dp2_from[cur] = mx2;
	if (mx2) dp2[cur] += id2 - 1;
	if (mx2) assert(id2 - 1 <= 0);

	return ;
}

void dfs2(int cur, int from, int mode) {
	if (mode == 1) {
		deg[cur] = 1;
		for (int i : graph[cur]) if (i != from) {
			if (i != dp1_from[cur]) {
				cut_edges.PB(MP(cur, i));
				dfs2(i, cur, 2);
			}
			else {
				deg[cur]++;
				dsu.Merge(i, cur);
				dfs2(i, cur, 1);
			}
		}
	}
	else if (mode == 2) {
		deg[cur] = 0;
		for (int i : graph[cur]) if (i != from) {
			if (i != dp1_from[cur] && i != dp2_from[cur]) {
				cut_edges.PB(MP(cur, i));
				dfs2(i, cur, 2);
			}
			else {
				deg[cur]++;
				dsu.Merge(i, cur);
				dfs2(i, cur, 1);
			}
		}
	}
	else {
		deg[cur] = 0;
		for (int i : graph[cur]) if (i != from) {
			cut_edges.PB(MP(cur, i));
			dfs2(i, cur, 2);
		}
	}
	return ;
}

void solve() {
	int n; RP(n);
	RLP(n - 1, a, b);

	dsu.init(n + 1);
	cut_edges.clear();
	add_edges.clear();
	for (int i = 1; i <= n; i++) dp1[i] = dp2[i] = dp1_from[i] = dp2_from[i] = deg[i] = 0;
	for (int i = 1; i <= n; i++) graph[i].clear();

	for (int i = 1; i < n; i++) {
		graph[a[i]].PB(b[i]);
		graph[b[i]].PB(a[i]);
	}

	dfs(1, 1);

	int ans = 0;
	ans = dp2[1];
	dfs2(1, 1, 2);

	queue<int> candi;
	for (int i = 1, lst = 0; i <= n; i++) if (deg[i] < 2) {
		if (lst == 0) lst = i;
		else if (!dsu.same(lst, i)) {
			deg[lst]++;
			deg[i]++;
			add_edges.PB(MP(lst, i));
			dsu.Merge(lst, i);

			if (deg[lst] >= 2) {
				if (deg[i] >= 2) {
					if (candi.empty()) lst = 0;
					else {
						lst = candi.front();
						candi.pop();
					}
				}
				else lst = i;
			}
			else {
				if (deg[i] < 2) candi.push(i);
			}
		}
		else candi.push(i);
	}

	assert(int(add_edges.size()) == int(cut_edges.size()) && int(cut_edges.size()) == ans);

	printf("%d\n", ans);
	for (int i = 0; i < ans; i++) 
		printf("%d %d %d %d\n", cut_edges[i].F, cut_edges[i].S, add_edges[i].F, add_edges[i].S);
	return ;
}

int main() {
	int t; RP(t);
	for (int i = 1; i <= t; i++) {
		solve();
	}
}


