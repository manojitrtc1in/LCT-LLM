





using namespace std;












	
	
	
	
	

	
	
	
	
	

typedef long long int ll;
typedef unsigned long long int ull;

constexpr int kN = int(5E1 + 10);
constexpr int kM = kN * kN;


















static inline char id8() {
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
	while (!isdigit(c = id8())) ;
	n = int(c - '0');
	while (isdigit(c = id8())) n = n * 10 + int(c - '0');
	return ;
}

template <typename T> static inline void Read(T &n) {
	static_assert(is_integral<T>::value, "Read requires an integral type");
	char c;
	bool neg = false;
	while (!isdigit(c = id8())) if (c == '-') neg = true;
	n = int(c - '0');
	while (isdigit(c = id8())) n = n * 10 + int(c - '0');
	if (neg) n = -n;
	return ;
}

template <typename T> static inline void id4(T &n) {
	static_assert(is_integral<T>::value, "id4 requires an integral type");
	char c;
	while (!isdigit(c = id8())) ;
	n = int(c - '0');
	return ;
}



template <typename T, typename... Targs> static inline void Read(T &n, Targs&... Fargs) {Read(n); return Read(Fargs...);}
template <typename T, typename... Targs> static inline void id4(T &n, Targs&... Fargs) {id4(n); return id4(Fargs...);}
template <typename T, typename... Targs> static inline void Read_P(T &n, Targs&... Fargs) {Read_P(n); return Read_P(Fargs...);}



template <typename T> static inline void id1(int i, T *a) {return Read(a[i]);}
template <typename T, typename... Targs> static inline void id1(int i, T *a, Targs*... Fargs) {Read(a[i]); return id1(i, Fargs...);}
template <typename... Targs> static inline void id7(int n, Targs*... Fargs) {for (int i = 1; i <= n; i++) id1(i, Fargs...);}

template <typename T> static inline void id3(int i, T *a) {return id4(a[i]);}
template <typename T, typename... Targs> static inline void id3(int i, T *a, Targs*... Fargs) {id4(a[i]); return id3(i, Fargs...);}
template <typename... Targs> static inline void id6(int n, Targs*... Fargs) {for (int i = 1; i <= n; i++) id3(i, Fargs...);}

template <typename T> static inline void id5(int i, T *a) {return Read_P(a[i]);}
template <typename T, typename... Targs> static inline void id5(int i, T *a, Targs*... Fargs) {Read_P(a[i]); return id5(i, Fargs...);}
template <typename... Targs> static inline void id0(int n, Targs*... Fargs) {for (int i = 1; i <= n; i++) id5(i, Fargs...);}



template <int mul, typename T> static inline void Read(T &n) {
	char c;
	bool neg = false;
	while (!isdigit(c = id8())) if (c == '-') neg = true;
	n = int(c - '0');
	while (isdigit(c = id8())) n = n * 10 + int(c - '0');
	
	int cnt = 0;

	if (c == '.') {
		while (isdigit(c = id8())) {
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
	while (!isdigit(c = id8())) ;
	
	n = int(c - '0');
	while (isdigit(c = id8())) n = n * 10 + int(c - '0');
	
	int cnt = 0;

	if (c == '.') {
		while (isdigit(c = id8())) {
			n = n * 10 + int(c - '0');
			cnt++;
		}
	}

	while (cnt++ < mul) n = n * 10;
	return ;
}

template <int mul, typename T, typename... Targs> static inline void Read(T &n, Targs&... Fargs) {Read<mul>(n); return Read<mul>(Fargs...);}
template <int mul, typename T, typename... Targs> static inline void Read_P(T &n, Targs&... Fargs) {Read_P<mul>(n); return Read_P<mul>(Fargs...);}



inline void IOS() {ios::sync_with_stdio(false); cin.tie(0); return ;}
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

template <typename T> inline void reverse(vector<T> &v) {return reverse(v.begin(), v.end());}

template <typename T> inline void Merge(vector<T> &a, vector<T> &b, vector<T> &c) {
	if (c.size() < a.size() + b.size()) c.resize(a.size() + b.size());
	merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
	return ;
}
template <typename T> inline void id9(vector<T> &a, vector<T> &b, vector<T> &c) {
	int a_size = int(a.size()), b_size = int(b.size());
	c.resize(a_size + b_size);
	for (int i = 0; i < a_size; i++) c[i] = a[i];
	for (int i = 0; i < b_size; i++) c[i + a_size] = b[i];
	return ;
}

template <typename T> inline void Discrete(vector<T> &v) {sort(v); v.resize(unique(v.begin(), v.end()) - v.begin()); return ;}

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
template <typename T> inline T lcm(T a, T b) {return a * b / gcd(a, b);}
template <typename T, typename... Targs> inline T gcd(T a, T b, T c, Targs... args) {return gcd(a, gcd(b, c, args...));}
template <typename T, typename... Targs> inline T lcm(T a, T b, T c, Targs... args) {return lcm(a, lcm(b, c, args...));}
template <typename T, typename... Targs> inline T min(T a, T b, T c, Targs... args) {return min(a, min(b, c, args...));}
template <typename T, typename... Targs> inline T max(T a, T b, T c, Targs... args) {return max(a, max(b, c, args...));}
template <typename T, typename... Targs> inline void chmin(T &a, T b, Targs... args) {a = min(a, b, args...); return ;}
template <typename T, typename... Targs> inline void chmax(T &a, T b, Targs... args) {a = max(a, b, args...); return ;}

vector<int> Primes(int n) {
	

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

int mex(vector<int> vec) {
	int n = int(vec.size());
	vector<bool> have(n, false);
	for (int i : vec) if (i < n) have[i] = true;
	for (int i = 0; i < n; i++) if (!have[i]) return i;
	return n;
}

template <typename T> T Mdist(pair<T, T> lhs, pair<T, T> rhs) {return ABS(lhs.first - rhs.first) + ABS(lhs.second - rhs.second);}





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
template <typename T> void id2(int n, const T *x) {printf("\n"); for (int i = 1; i <= n; i++) _print(x[i]), printf("\n");}
















struct Bipartite_Matching {
	struct Edge {
		int ed, next;
		Edge(int a, int b) {ed = a, next = b;}
	};
	vector<Edge> edge;
	int *head, *disx, *disy, *matchx, *matchy;
	

	vector<bool> vis;
	int id10, x_size, y_size;

	void init(int n, int m) {
		x_size = n, y_size = m;
		edge.clear();
		delete [] head; head = new int[x_size];
		delete [] disx; disx = new int[x_size];
		delete [] disy; disy = new int[y_size];
		delete [] matchx; matchx = new int[x_size];
		delete [] matchy; matchy = new int[y_size];
		vis.clear(); vis.resize(y_size);
		memset(head, -1, sizeof(int) * x_size);
		return ;
	}

	void AddEdge(int a, int b) {
		edge.push_back(Edge(b, head[a]));
		head[a] = int(edge.size()) - 1;
		return ;
	}

	bool Bfs() {
		queue<int> que;
		id10 = x_size << 1;
		memset(disx, -1, sizeof(int) * x_size);
		memset(disy, -1, sizeof(int) * y_size);

		for (int i = 0; i < x_size; ++i) if (matchx[i] < 0) {
			disx[i] = 0;
			que.push(i);
		}

		while (!que.empty()) {
			int x = que.front();
			que.pop();
			if (disx[x] > id10) break;
			for (int i = head[x]; i >= 0; i = edge[i].next) {
				int y = edge[i].ed;
				if (disy[y] < 0) {
					disy[y] = disx[x] + 1;
					if (matchy[y] < 0) id10 = disy[y];
					else {
						disx[matchy[y]] = disy[y] + 1;
						que.push(matchy[y]);
					}
				}
			}
		}

		return id10 < (x_size << 1);
	}

	bool Dfs(int x) {
		for (int i = head[x]; i >= 0; i = edge[i].next) {
			int y = edge[i].ed;
			if (!vis[y] && disy[y] == disx[x] + 1) {
				vis[y] = true;
				if (matchy[y] >= 0 && disy[y] == id10) continue;
				if (matchy[y] < 0 || Dfs(matchy[y])) {
					matchx[x] = y;
					matchy[y] = x;
					return true;
				}
			}
		}
		return false;
	}

	int MaxMatch() {
		int ret = 0;
		memset(matchx, -1, sizeof(int) * x_size);
		memset(matchy, -1, sizeof(int) * y_size);
		while (Bfs()) {
			fill(vis.begin(), vis.end(), false);
			for (int i = 0; i < x_size; ++i) if (matchx[i] < 0 && Dfs(i)) ++ret;
		}
		return ret;
	}

	int operator ()() {return MaxMatch();}
};



int a[kM], b[kM];
ll x[kN], y[kN];
ll dp[kN][kN]; 

int from[kN][kN];
vector<vector<int>> tmp;

int cal_matching(vector<vector<int>> graph) {
	static Bipartite_Matching bm;
	int n = int(graph.size());

	bm.init(n, n);

	for (int i = 0; i < n; i++) for (int j : graph[i]) bm.AddEdge(i, j);
	return n - bm();
}

vector<vector<int>> remove(vector<vector<int>> graph, int op) {
	int n = int(graph.size());

	if (op > 0) {
		graph[--op].clear();
		return graph;
	}
	else {
		op = -op - 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < int(graph[i].size()); j++) if (graph[i][j] == op) {
				swap(graph[i][j], graph[i].back());
				graph[i].pop_back();
			}
		}
		return graph;
	}
}

int main() {
	int n, m, k; RP(n, m, k);
	RLP(m, a, b);
	RLP(k, x, y);

	tmp.resize(n);
	for (int i = 1; i <= m; i++) tmp[a[i] - 1].PB(b[i] - 1);

	int st = cal_matching(tmp);
	memset(dp, -1, sizeof(dp));
	memset(from, -1, sizeof(from));
	dp[0][st] = 0;

	auto point = [&](int idx, int diff) -> ll {return max<ll>(0, x[idx] - y[idx] * diff);};

	for (int i = 1; i <= k; i++) for (int now = i + 1; now <= n; now++) {
		for (int lst = i; lst <= now; lst++) if (dp[i - 1][lst] != -1 && dp[i - 1][lst] + point(i, now - lst) > dp[i][now]) {
			dp[i][now] = dp[i - 1][lst] + point(i, now - lst);
			from[i][now] = lst;
		}
	}

	ll val = -1, id = 0;
	for (int i = k + 1; i <= n; i++) if (dp[k][i] > val) {
		val = dp[k][i];
		id = i;
	}

	vector<int> seq;
	for (int i = k; i >= 1; i--) {
		seq.PB(id - from[i][id]);
		id = from[i][id];
	}

	reverse(seq);

	vector<int> ans;

	int cur = st;
	for (int i = 0; i < k; i++) {
		for (int j = 1; j <= seq[i]; j++) {
			for (int op = -n; op <= n; op++) if (op != 0) {
				if (cal_matching(remove(tmp, op)) == cur + j) {
					ans.PB(op);
					tmp = remove(tmp, op);
					break;
				}
			}
		}
		cur += seq[i];
		ans.PB(0);
	}

	int sz = int(ans.size());
	printf("%d\n%d", sz, ans[0]); for (int i = 1; i < sz; i++) printf(" %d", ans[i]); printf("\n");
}


