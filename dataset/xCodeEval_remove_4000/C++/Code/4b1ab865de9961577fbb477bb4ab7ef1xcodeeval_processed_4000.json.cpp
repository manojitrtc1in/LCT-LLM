



















































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




const int MAXMEM = 250 * 1000 * 1024;
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
void fast_print(const double &x) { printf("%.15lf", x); }
void fast_print(const long double &x) { printf("%.15Lf", x); }
void fast_print(const char &x) { printf("%c", x); };
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
	T floor_mod(T a, T b) {
		if (a >= 0 && b >= 0) return a % b;
		if (a <= 0 && b <= 0) return a % b;
		return abs(b) - (abs(a) % abs(b));
	}
}

using namespace numbers_operation;
using namespace typedefs;
using namespace random;

int n, q;
vector<vector<int>> g;
vector<vector<int>> h;
vector<char> symb;
vector<int> pref;
vector<int> up;
vector<int> upI;
vector<vector<vector<int>>> _edge, _cnt;
vector<vector<int>> S2;
vector<vector<int>> dp;
vector<vector<int>> safe;
vector<int> depth;

int err = 0;

int get_safe(int i) {
	if (h[i].empty()) return 0;
	int _min = 1e9;
	f(j, len(h[i])) {
		_min = min(_min, safe[i][j]);
	}
	return _min;
}

bool recalc(int i) {
	if (h[i].empty()) return true;
	if (get_safe(i) < 0) err--;
	f(j, len(h[i])) {
		safe[i][j] = get_safe(h[i][j]) + S2[i][j];	
	}
	f(c, 26) {
		int _max = 0;
		f(j, len(h[i])) {
			int cur = dp[h[i][j]][c] + _edge[i][j][c];
			_max = max(_max, cur);
		}
		f(j, len(h[i])) {
			int cur = dp[h[i][j]][c] + _edge[i][j][c];
			if (cur < _max) {
				safe[i][j] -= _max - cur;
			}
		}
		dp[i][c] = _max;
	}
	if (get_safe(i) < 0) err++;
	return get_safe(i) >= 0;
}


void relax(int i, string _c, int d) {
	if (h[i].empty()) return;
	if (get_safe(i) < 0) err--;
	

	

	

	


	for (char c : _c) {
		c -= 'a';
		int _max = 0;
		f(j, len(h[i])) {
			int cur = dp[h[i][j]][c] + _edge[i][j][c];
			_max = max(_max, cur);
		}
		f(j, len(h[i])) {
			int cur = dp[h[i][j]][c] + _edge[i][j][c];
			if (cur < _max) {
				safe[i][j] -= (_max - cur) * d;
			}
		}
		dp[i][c] = _max;
	}
	{
		f(j, len(h[i])) {
			safe[i][j] += (S2[i][j] + get_safe(h[i][j])) * d;
		}
	}
	

	if (get_safe(i) < 0) err++;
}

void remake(int v, string c, int d) {
	if (d == -1) {
		if (v != 0) 
			remake(up[v], c, d);
		relax(v, c, d);
	} else {
		relax(v, c, d);
		if (v == 0) return;
		remake(up[v], c, d);
	}
}

void add(int v, char c, int d) {
	if (c == '?') {
		S2[up[v]][upI[v]] += d;
	} else {
		_edge[up[v]][upI[v]][c - 'a'] += d;
	}
}

int to_int(char c) {
	if (c == '?') return -1;
	return c - 'a';
}

signed main(signed argc, char *argv[]) {
	scan n, q;
	g.resize(n);
	pref.resize(n);
	symb.resize(n);
	h.resize(n);
	upI.resize(n);
	dp.resize(n, vector<int>(26));
	safe.resize(n, vector<int>(2));
	S2.resize(n, vector<int>(2));
	_edge.resize(n, vector<vector<int>>(2, vector<int>(27, 0)));
	depth.resize(n);
	f(i, n - 1) {
		int p;
		string c;
		scan p, c;
		p--;
		g[p].pb(i + 1);
		symb[i + 1] = c[0];
		pref[i + 1] = p;
		depth[i + 1] = depth[p] + 1;
	}
	up.resize(n, -1);
	for (int i = 1; i < n; i++) {
		if (len(g[pref[i]]) == 2 || pref[i] == 0) {
			up[i] = pref[i];
			upI[i] = (g[pref[i]][0] != i);
		} else {
			up[i] = up[pref[i]];
			upI[i] = upI[pref[i]];
		}
		if (len(g[i]) != 1) {
			h[up[i]].pb(i);
		}
	}
	for (int i = 0; i < n; i++) {
		sort(h[i].begin(), h[i].end(), [](int a, int b) {
			return upI[a] < upI[b];
		});
	}
	{
		int _min = 1e9;
		int _max = -1e9;
		f(i, n) {
			if (g[i].empty()) {
				_min = min(_min, depth[i]);
				_max = max(_max, depth[i]);
			}
		}
		if (_min != _max) {
			f(i, q) {
				print "Fou";
			}	
			return 0;
		}
	}
	for (int i = 1; i < n; i++) {
		add(i, symb[i], 1);
	}	
	for (int i = n - 1; i >= 0; i--) {
		if (!h[i].empty()) {
			recalc(i);
		}
	}
	{
		f(i, q) {
			int v;
			string c;
			scan v, c;
			v--;
			string rescan;
			if (symb[v] != '?')
				rescan += symb[v]; 
			if (c[0] != '?')
				rescan += c[0];
			remake(up[v], rescan, -1);
			add(v, symb[v], -1);
			add(v, c[0], 1);
			remake(up[v], rescan, 1);
			symb[v] = c[0];
			if (err) {
				print "Fou";
			} else {
				ll S = 0;
				f(j, 26) {
					S += (dp[0][j] + get_safe(0)) * (j + 1);
				}	
				print "Shi", S;
			}
		}
	}
}