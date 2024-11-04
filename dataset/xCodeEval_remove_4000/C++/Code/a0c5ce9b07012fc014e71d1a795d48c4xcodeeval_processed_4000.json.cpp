


















































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

int t, T;
int n, m;
vector<pii> range;
vector<vector<int>> g;
vector<int> color;
vector<int> st;
void dfs(int v) {
	st.pb(v);
	for (int sub : g[v]) {
		if (color[sub] == 0) {
			color[sub] = 3 - color[v];
			dfs(sub);
		}
		if (color[sub] == color[v]) {
			print "IMPOSSIBLE";
			exit(0);
		}
	}
}

struct Event {
	int x, l, r, d;
};

vector<Event> es;

void add(pii X, pii Y, int w) {
	es.pb({X.x, Y.x, Y.y, w});
	es.pb({X.y + 1, Y.x, Y.y, -w});
}

const int N = (1 << 19);
pii V[2 * N + 1];
int M[2 * N + 1];

pii get_value(int i) {
	return mp(V[i].x + M[i], V[i].y);
}

void inc(int i, int tl, int tr, int ql, int qr, int d) {
	if (tr <= ql || qr <= tl) return;
	if (ql <= tl && tr <= qr) {
		M[i] += d;
	} else {
		int m = (tl + tr) / 2;
		inc(i * 2 + 1, tl, m, ql, qr, d);
		inc(i * 2 + 2, m, tr, ql, qr, d);
		V[i] = max(get_value(i * 2 + 1), get_value(i * 2 + 2));
	}
}

pii app(pii p, int x) {
	return mp(p.x + x, p.y);
}

pii query(int i, int tl, int tr, int ql, int qr) {
	if (tr <= ql || qr <= tl) return mp(-1e9, -1);
	if (ql <= tl && tr <= qr) return V[i];
	int m = (tl + tr) / 2;
	return max(app(query(i * 2 + 1, tl, m, ql, qr), M[i * 2 + 1]),
		app(query(i * 2 + 2, m, tr, ql, qr), M[i * 2 + 2]));
}

signed main(signed argc, char *argv[]) {
	scan t, T;
	scan n, m;
	range.resize(n);
	scan range;
	g.resize(n);
	f(i, m) {
		int a, b;
		scan a, b;
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	color.resize(n, 0);
	for (int i = 0; i < N; i++) {
		V[i + N - 1] = mp(0, i);
	}
	int checksum = 0;
	int t1 = -1;
	int t2 = 2e9;
	f(i, n) {
		if (color[i] == 0) {
			st.clear();
			color[i] = 1;
			dfs(i);
			pii F = mp(0, T), S = mp(0, T);
			for (int v : st) {
				if (color[v] == 1) {
					F.x = max(F.x, range[v].x);
					F.y = min(F.y, range[v].y);
				} else {
					S.x = max(S.x, range[v].x);
					S.y = min(S.y, range[v].y);
				}
			}
			if (F.x > F.y || S.x > S.y) {
				print "IMPOSSIBLE";
				return 0;
			}
			t1 = max(t1, max(F.x, S.x));
			t2 = min(t2, min(F.y, S.y));

			checksum++;
		}
	}
	while (t1 + t2 > T) t2--;
	while (t1 + t2 < t) t1++;

	es.pb({T + 1, 0, 0, -1});
	es.pb({0, 0, 0, 0});
	sort(es.begin(), es.end(), [](Event a, Event b) {
		return mp(a.x, a.d) < mp(b.x, b.d);
	});

	vector<int> cords;
	for (int i = 0; i < len(es) - 1; i++) {
		cords.pb(es[i].l);
		cords.pb(es[i].r);
	}

	for (int i = 0; i < len(es) - 1; i++) {
		int x1 = es[i].x;
		int x2 = es[i + 1].x - 1;
		if (x1 <= x2) {
			

			cords.pb(t - x2);
			cords.pb(T - x1);
		}
	}
	sort(cords.begin(), cords.end());
	cords.resize(unique(cords.begin(), cords.end()) - cords.begin());
	auto zip = [&cords](int x) {
		int y = lower_bound(cords.begin(), cords.end(), x) - cords.begin();
		assert(cords[y] == x);
		return y;
	};
	

	int pref = 0;
		
	if (t1 != -1) {
		color.assign(n, 0);
		string result(n, '.');
		f(i, n) {
			if (color[i] == 0) {
				st.clear();
				color[i] = 1;
				dfs(i);
				

				pii F = mp(0, T), S = mp(0, T);
				for (int v : st) {
					if (color[v] == 1) {
						F.x = max(F.x, range[v].x);
						F.y = min(F.y, range[v].y);
					} else {
						S.x = max(S.x, range[v].x);
						S.y = min(S.y, range[v].y);
					}
				}
				char c = '1';
				if (!(F.x <= t1 && t1 <= F.y && S.x <= t2 && t2 <= S.y)) {
					c = '2';
					if ((!(F.x <= t2 && t2 <= F.y && S.x <= t1 && t1 <= S.y))) {
						print "IMPOSSIBLE";
						return 0;
					}
				}
				for (int x : st) {
					if (color[x] == 1) {
						result[x] = c;
					} else {
						result[x] = (c ^ '2' ^ '1');
					}
				}
			}
		}
		print "POSSIBLE";
		print t1, t2;
		print result;
	} else {
		print "IMPOSSIBLE";
	}
}
