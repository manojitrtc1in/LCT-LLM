










hur(popc, __builtin_popcount) hur(ctz, __builtin_ctz) hur(clz, __builtin_clz)









































string buf = "";int bal = 0;for (char c : s) {\
if (c == '(' || c == '[' || c == '{') {bal++;\
} else if (c == ')' || c == ']' || c == '}') {\
bal--;} else {if (bal == 0) {if (c == ',') {\
deq.pb(buf);buf = "";} else {if (c != ' ') {\
buf += c;}}}}}if (!buf.empty()) {deq.pb(buf);}\
smart_io::id3();smart_io::_print(deq, args);}

inline int min(const int &x, const int &y) { return (((y-x)>>(32-1))&(x^y))^x; }
inline int max(const int &x, const int &y) { return (((y-x)>>(32-1))&(x^y))^y; }
inline long long min(const long long &x, const long long &y) { return (((y-x)>>(64-1))&(x^y))^x; }
inline long long max(const long long &x, const long long &y) { return (((y-x)>>(64-1))&(x^y))^y; }


smart_io::id3(); \
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
	
	void id3() {
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


 
template <class T = int> inline T readInt();						
inline double readDouble();
inline int readUInt();					 
inline int readChar(); 

inline void readWord(char *s); 
inline bool readLine(char *s); 

inline bool id4();
inline int getChar(); 
inline int peekChar();
inline bool id2();
inline void id5();
 
template <class T> inline void writeInt(T x, char end = 0, int len = -1);
inline void writeChar(int x); 
inline void writeWord(const char *s);
inline void writeDouble(double x, int len = 0);
inline void flush();
 
static struct buffer_flusher_t {
	~buffer_flusher_t() {
		flush();
	}
} id1;
 

 
static const int buf_size = 4096;
 
static unsigned char buf[buf_size];
static int buf_len = 0, buf_pos = 0;
 
inline bool id4() {
	if (buf_pos == buf_len) {
		buf_pos = 0, buf_len = fread(buf, 1, buf_size, stdin);
		if (buf_pos == buf_len)
			return 1;
	}
	return 0;
}
 
inline int getChar() { 
	return id4() ? -1 : buf[buf_pos++];
}
 
inline int peekChar() { 
	return id4() ? -1 : buf[buf_pos];
}
 
inline bool id2() { 
	int c;
	while ((c = peekChar()) != -1 && c <= 32)
		buf_pos++;
	return c == -1;
}
 
inline void id5() {
	while (!id4() && buf[buf_pos] <= 32U)
		buf_pos++;
}
 
inline int readChar() {
	int c = getChar();
	while (c != -1 && c <= 32)
		c = getChar();
	return c;
}
 
inline int readUInt() {
	int c = readChar(), x = 0;
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return x;
}
 
template <class T>
inline T readInt() {
	int s = 1, c = readChar();
	T x = 0;
	if (c == '-')
		s = -1, c = getChar();
	else if (c == '+')
		c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return s == 1 ? x : -x;
}
 
inline double readDouble() {
	int s = 1, c = readChar();
	double x = 0;
	if (c == '-')
		s = -1, c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	if (c == '.') {
		c = getChar();
		double coef = 1;
		while ('0' <= c && c <= '9')
			x += (c - '0') * (coef *= 1e-1), c = getChar();
	}
	return s == 1 ? x : -x;
}
 
inline void readWord(char *s) { 
	int c = readChar();
	while (c > 32)
		*s++ = c, c = getChar();
	*s = 0;
}
 
inline bool readLine(char *s) { 
	int c = getChar();
	while (c != '\n' && c != -1)
		*s++ = c, c = getChar();
	*s = 0;
	return c != -1;
}
 

 
static int id0 = 0;
static char write_buf[buf_size];
 
inline void writeChar(int x) {
	if (id0 == buf_size)
		fwrite(write_buf, 1, buf_size, stdout), id0 = 0;
	write_buf[id0++] = x;
}
 
inline void flush() {
	if (id0) {
		fwrite(write_buf, 1, id0, stdout), id0 = 0;
		fflush(stdout);
	}
}
 
template <class T> 
inline void writeInt(T x, char end, int output_len) {
	if (x < 0)
		writeChar('-'), x = -x;
 
	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n < output_len)
		s[n++] = '0';
	while (n--)
		writeChar(s[n]);
	if (end)
		writeChar(end);
}
 
inline void writeWord(const char *s) {
	while (*s)
		writeChar(*s++);
}
 
inline void writeDouble(double x, int output_len) {
	if (x < 0)
		writeChar('-'), x = -x;
	int t = (int)x;
	writeInt(t), x -= t;
	writeChar('.');
	for (int i = output_len - 1; i > 0; i--) {
		x *= 10;
		t = std::min(9, (int)x);
		writeChar('0' + t), x -= t;
	}
	x *= 10;
	t = std::min(9, (int)(x + 0.5));
	writeChar('0' + t);
}

int n;
int Root = -1;
vector<vector<int>> h;
vector<vector<pii>> hh;
vector<int> it;
vector<pii> g;
vector<int> max_path;
vector<int> tsize;
vector<int> only_path;
vector<pii> jump;
vector<pii> pref;
void dfs0(int v, int _p) {
	max_path[v] = 1;
	tsize[v] = 1;
	for (pii sub : hh[v]) {
		if (sub.x == _p) continue;	
		it[v]++;
		pref[sub.x] = mp(v, sub.y);
		dfs0(sub.x, v);
		max_path[v] = max(max_path[v], max_path[sub.x] + 1);
		tsize[v] += tsize[sub.x]; 
	}
}
void dfs1(int v, int _p) {
	for (pii _sub : hh[v]) {
		int sub = _sub.x;
		if (sub == _p) continue;
		g[--it[v]] = _sub;
		dfs1(sub, v);
	}
}


























vector<int> tin;
int timer = 0;
pii dfs3(int v, int _p) {
	bool hid = true;
	if (_p == -1 || le(h[v]) != 2) {
		tin[v] = timer++;
		hid = false;
	}
	

	for (int sub : h[v]) {
		if (sub == _p) continue;
		pii t = dfs3(sub, v);
		if (hid) return mp(t.x, t.y + 1);
		hh[tin[v]].emplace_back(t.x, t.y);
		

	}
	return mp(tin[v], 1);
}
int paths = 0;
int dp[500'000][2];
// int dfs(int v, int k) {
// 	if (tsize[v] < k) return max_path[v];
// 	if (max_path[v] * 2 < k) return max_path[v];
// 	if (jump[v].x != v) {
// 		int t = dfs(jump[v].x, k) + jump[v].y;
// 		paths += t / k;
// 		t %= k;
// 		return t;
// 	}
// 	int m1 = 0, m2 = 0;
// 	for (int i = it[v]; i < it[v + 1]; i++) {
// 		int t = dfs(g[i], k);
// 		if (m1 < t) swap(m1, t);
// 		if (m2 < t) swap(m2, t);
// 	}
// 	if (m1 + m2 + 1 >= k) {
// 		paths++;
// 		return 0;
// 	} else return m1 + 1;
// }
vector<int> mem;
int solve(int k) {
	if (k > n) return 0;
	if (mem[k] != -1) return mem[k];
	paths = 0;
	// int t = dfs(Root, k);
	{
		memset(dp, 0, sizeof dp);
		int m1 = 0, m2 = 0; int t;
		for (int v = timer - 1; v > 0; v--) {
			m1 = dp[v][0]; m2 = dp[v][1];
			if (m1 + m2 + 1 >= k) {
				paths++;
				m1 = -1;
			}
			m1 += pref[v].y;
			while (m1 >= k) {
				m1 -= k;
				paths++;
			}
			if (dp[pref[v].x][0] < m1) swap(dp[pref[v].x][0], m1);
			if (dp[pref[v].x][1] < m1) swap(dp[pref[v].x][1], m1);
			
			// for (int i = it[v]; i < it[v + 1]; i++) {
			// 	t = dp[g[i].x] + g[i].y - 1;
			// 	while (t >= k) {
			// 		t -= k;
			// 		paths++;
			// 	}
			// 	if (m1 < t) swap(m1, t);
			// 	if (m2 < t) swap(m2, t);	
			// }
			// if (m1 + m2 + 1 >= k) {
			// 	paths++;
			// } else {
			// 	dp[v] = m1 + 1;
			// }
		}	
	}
	if (dp[0][0] + dp[0][1] + 1 >= k) paths++;
	return mem[k] = paths;	
}
vector<int> rez;
void go(int l, int r, int cl, int cr) {
	if (l > r) return;
	if (cl == cr) {
		for (int i = l; i <= r; i++) {
			rez[i] = cl;
		}
	} else {
		int m = (l + r) / 2;
		int cm = solve(m);
		rez[m] = cm;
		go(l, m - 1, cm, cr);
		go(m + 1, r, cl, cm);
	}
}
signed main(signed argc, char *argv[]) {
	// scan n;
	n = readInt();
	Root = rng() % n;
	mem.resize(n + 3, -1);
	it.resize(n + 1);
	h.resize(n);
	tsize.resize(n);
	pref.resize(n);
	max_path.resize(n);
	only_path.resize(n);
	jump.resize(n);
	tin.resize(n);
	vector<pii> edges;
	f(i, n - 1) {
		int a = readInt() - 1;
		int b = readInt() - 1;
		edges.emplace_back(a, b);
		h[a].pb(b); h[b].pb(a);
	}
	hh.resize(n);
	dfs3(Root, -1);
	Root = tin[Root];
	dfs0(Root, -1);
	for (int i = 1; i < n + 1; i++) {
		it[i] += it[i - 1];
	}
	rez.resize(n + 1);
	g.resize(n - 1);
	dfs1(Root, -1);
	// dfs2(Root, -1);
	// print solve(1);
	go(1, n, 0, n);
	for (int i = 1; i <= n; i++) {
		writeInt(rez[i], '\n');
	}
	

}
