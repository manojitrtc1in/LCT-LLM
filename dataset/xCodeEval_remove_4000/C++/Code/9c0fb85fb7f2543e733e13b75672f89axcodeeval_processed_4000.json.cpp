










hur(popc, __builtin_popcount) hur(ctz, __builtin_ctz) hur(clz, __builtin_clz)









































string buf = "";int bal = 0;for (char c : s) {\
if (c == '(' || c == '[' || c == '{') {bal++;\
} else if (c == ')' || c == ']' || c == '}') {\
bal--;} else {if (bal == 0) {if (c == ',') {\
deq.pb(buf);buf = "";} else {if (c != ' ') {\
buf += c;}}}}}if (!buf.empty()) {deq.pb(buf);}\
smart_io::id0();smart_io::_print(deq, args);}

inline int min(const int &x, const int &y) { return (((y-x)>>(32-1))&(x^y))^x; }
inline int max(const int &x, const int &y) { return (((y-x)>>(32-1))&(x^y))^y; }
inline long long min(const long long &x, const long long &y) { return (((y-x)>>(64-1))&(x^y))^x; }
inline long long max(const long long &x, const long long &y) { return (((y-x)>>(64-1))&(x^y))^y; }


smart_io::id0(); \
cout,




const int MAXMEM = 200 * 1000 * 1024;
char _memory[MAXMEM];
size_t _ptr = 0;
void* operator new(size_t _x) { _ptr += _x; assert(_ptr < MAXMEM); return _memory + _ptr - _x; }
void operator delete (void*) noexcept {}


using namespace std;

char string_in_buffer[(int)260];


void fast_scan(int &x) { scanf("%d", &x); }
void fast_scan(long long &x) { scanf("%lld", &x); }
void fast_scan(unsigned long long &x) { scanf("%llu", &x); }
void fast_scan(double &x) { scanf("%lf", &x); }
void fast_scan(long double &x) { scanf("%Lf", &x); }
void fast_scan(char &x) {
	scanf("%c", &x);
	if (x == '\n') {
		fast_scan(x);
	}
}
void fast_scan(string &x) {
	scanf("%s", string_in_buffer);
	x = string(string_in_buffer);
}

template<class TFirst, class TSecond>
void fast_scan(pair<TFirst, TSecond> &p) {
	fast_scan(p.first);
	fast_scan(p.second);
}

template <class T>
void fast_scan(vector<T> &v) {
	for (auto &x : v) fast_scan(x);
}

void fast_print(const int &x) { printf("%d", x); }
void fast_print(const unsigned int &x) { printf("%u", x); }
void fast_print(const long long &x) { printf("%lld", x); }
void fast_print(const unsigned long long &x) { printf("%llu", x); }
void fast_print(const char &x) { printf("%c", x); };






























void fast_print(const double &x) { printf("%.15lf", x); }
void fast_print(const long double &x) { printf("%.15Lf", x); }
void fast_print(const string &x) { printf("%s", x.c_str());}
void fast_print(const char v[]) { fast_print((string)v); }

template<class TFirst, class TSecond>
void fast_print(const pair<TFirst, TSecond> &p) {
	fast_print(p.first);
	fast_print(' ');
	fast_print(p.second);
}

template <class T>
void fast_print(const vector<T> &v) {
	if (v.empty()) return;
	fast_print(v[0]);
	for (int i = 1; i < v.size(); i++) {
		fast_print(' ');
		fast_print(v[i]);
	}
}

template <class T>
void fast_print(const vector<vector<T>> &v) {
	if (v.empty()) return;
	fast_print(v[0]);
	for (int i = 1; i < v.size(); i++) {
		fast_print('\n');
		fast_print(v[i]);
	}
}

template <class T>
void fast_print(const T &v) {
	for (const auto &x : v) {
		fast_print(x);
		fast_print(' ');
	}
}


using namespace std;


namespace smart_io {
	string print_start = "";
	string sep = " ";
	bool first_print = false;
	
	void id0() {
		fast_print(print_start);
		print_start = "\n";
		first_print = true;
	}
	
	void _print(deque<string>) {}
	template<class T, class... Args>
	void _print(deque<string> names, T elem, Args... args) {
		if (!first_print) {
			fast_print("\n");
		} else {
			first_print = false;
		}
		fast_print(names.front());
		fast_print(" = ");
		fast_print(elem);
		names.pop_front();
		_print(names, args...);
	}
} 



template <class T>
ostream &operator,(ostream &os, const T &object) {
	if (!smart_io::first_print) {
		fast_print(smart_io::sep);
	} else {
		smart_io::first_print = false;
	}
	fast_print(object);
	return os;
}

template <class T>
istream &operator,(istream &is, T &object) {
	fast_scan(object);
	return is;
}

namespace random {
	using namespace std::chrono;
	mt19937 rng(duration_cast< milliseconds >(
											  system_clock::now().time_since_epoch()
											  ).count());
	uniform_real_distribution<> prob_dist(0.0, 1.0);
};

namespace typedefs {
	typedef long long ll;
	typedef unsigned long long ull;
	typedef pair<int, int> pii;
	typedef long double ld;
}

namespace numbers_operation {
	template<class T>
	inline T floor_mod(T a, const T &b) {
		a %= b;	
		if (a < 0) a += b;
		return a;
	}
}

using namespace numbers_operation;
using namespace typedefs;
using namespace random;

int n;
int Root = -1;
vector<vector<int>> h;
vector<int> it;
vector<int> g;
vector<int> max_path;
vector<int> tsize;
vector<int> only_path;
vector<pii> jump;
void dfs0(int v, int _p) {
	max_path[v] = 1;
	tsize[v] = 1;
	for (int sub : h[v]) {
		if (sub == _p) continue;	
		it[v]++;
		dfs0(sub, v);
		max_path[v] = max(max_path[v], max_path[sub] + 1);
		tsize[v] += tsize[sub]; 
	}
}
void dfs1(int v, int _p) {
	for (int sub : h[v]) {
		if (sub == _p) continue;
		g[--it[v]] = sub;
		dfs1(sub, v);
	}
}
void dfs2(int v, int _p) {
	vector<int> childs;
	for (int sub : h[v]) {
		if (sub == _p) continue;
		dfs2(sub, v);
		childs.pb(sub);
	}
	if (le(childs) == 1) {
		jump[v] = mp(jump[childs[0]].x, jump[childs[0]].y + 1);
	} else {
		jump[v] = mp(v, 0);
	}
}
vector<int> tin;
int timer = 0;
void dfs3(int v, int _p) {
	tin[v] = timer++;
	for (int sub : h[v]) {
		if (sub == _p) continue;
		dfs3(sub, v);
	}
}
int paths = 0;
int dp[500'000];
int dfs(int v, int k) {
	if (tsize[v] < k) return max_path[v];
	if (max_path[v] * 2 < k) return max_path[v];
	if (jump[v].x != v) {
		int t = dfs(jump[v].x, k) + jump[v].y;
		paths += t / k;
		t %= k;
		return t;
	}
	int m1 = 0, m2 = 0;
	for (int i = it[v]; i < it[v + 1]; i++) {
		int t = dfs(g[i], k);
		if (m1 < t) swap(m1, t);
		if (m2 < t) swap(m2, t);
	}
	if (m1 + m2 + 1 >= k) {
		paths++;
		return 0;
	} else return m1 + 1;
}
vector<int> mem;
int solve(int k) {
	if (k > n) return 0;
	if (mem[k] != -1) return mem[k];
	paths = 0;
	

	{
		memset(dp, 0, sizeof dp);
		int m1 = 0, m2 = 0;
		for (int v = n - 1; ~v; v--) {
			m1 = m2 = 0;
			for (int i = it[v]; i < it[v + 1]; i++) {
				int t = dp[g[i]];
				if (m1 < t) swap(m1, t);
				if (m2 < t) swap(m2, t);	
			}
			if (m1 + m2 + 1 >= k) {
				paths++;
			} else {
				dp[v] = m1 + 1;
			}
		}	
	}
	if (dp[0] >= k) paths++;
	return mem[k] = paths;	
}
signed main(signed argc, char *argv[]) {
	scan n;
	Root = rng() % n;
	mem.resize(n + 3, -1);
	it.resize(n + 1);
	h.resize(n);
	tsize.resize(n);
	max_path.resize(n);
	only_path.resize(n);
	jump.resize(n);
	tin.resize(n);
	vector<pii> edges;
	f(i, n - 1) {
		int a, b; scan a, b; a--, b--;
		edges.emplace_back(a, b);
		h[a].pb(b); h[b].pb(a);
	}
	dfs3(Root, -1);
	h.clear(); h.resize(n);
	for (pii pp : edges) {
		h[tin[pp.x]].pb(tin[pp.y]);
		h[tin[pp.y]].pb(tin[pp.x]);
	}
	Root = tin[Root];
	dfs0(Root, -1);
	for (int i = 1; i < n + 1; i++) {
		it[i] += it[i - 1];
	}
	g.resize(n - 1);
	dfs1(Root, -1);
	dfs2(Root, -1);
	vector<int> rez(n + 1);
	int cur = 1;
	while (cur <= n) {
		int cnt = solve(cur);
		if (cnt == 0) break;
		int l = cur;
		int r = n + 1;
		if (solve(cur + 1) == cnt) {
			while (r - l > 1) {
				int m = (l + r) / 2;
				if (solve(m) == cnt) {
					l = m;
				} else r = m;
			}
		}
		for (int j = cur; j <= l; j++) {
			rez[j] = cnt;
		}
		cur = l + 1;
	}
	for (int i = 1; i <= n; i++) {
		print rez[i];
	}
}
