


















































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

signed main(signed argc, char *argv[]) {
	int n;	
	scan n;
	vector<int> v(n);
	scan v;
	vector<int> cords = v;
	sort(cords.begin(), cords.end());
	cords.resize(unique(cords.begin(), cords.end()) - cords.begin());
	for (int i = 0; i < n; i++) {
		v[i] = lower_bound(cords.begin(), cords.end(), v[i]) - cords.begin();
	}
	vector<int> c(len(cords));
	for (int i = 0; i < n; i++) {
		c[v[i]]++;
	}
	int _h = 0, _w = 0;
	for (int w = 1; w * w <= n; w++) {
		int S = 0;
		for (int i = 0; i < len(cords); i++) {
			S += min(w, c[i]);
		}
		int h = S / w;
		if (h >= w) {
			if (_h * _w < h * w) {
				_h = h, _w = w;
			}
		}
	}
	print _h * _w;
	print _w, _h;
	vector<pii> seq;
	for (int i = 0; i < _h; i++) {
		for (int j = 0; j < _w; j++) {
			seq.emplace_back(j, (i + j) % _h);
		}
	}
	vector<vector<int>> rez(_w, vector<int>(_h));
	vector<pii> all;
	for (int i = 0; i < len(cords); i++) {
		if (c[i])
			all.emplace_back(c[i], cords[i]);
	}
	sort(all.rbegin(), all.rend());
	for (pii p : all) {
		for (int j = 0; !seq.empty() && j < min(_h, min(_w, p.x)); j++) {
			rez[seq.back().x][seq.back().y] = p.y;
			seq.pop_back();
		}
	}
	print rez;
	return 0;
	bool fail = false;
	for (int i = 0; i < _w; i++) {
		vector<int> t = vector<int>(rez[i].begin(), rez[i].end());
		sort(t.begin(), t.end());
		t.resize(unique(t.begin(), t.end()) - t.begin());
		if (len(t) != _h) {
			fail = true;
			break;
		}
	}
	for (int i = 0; i < _h; i++) {
		vector<int> t;
		for (int j = 0; j < _w; j++) {
			t.pb(rez[j][i]);
		}
		sort(t.begin(), t.end());
		t.resize(unique(t.begin(), t.end()) - t.begin());
		if (len(t) != _w) {
			fail = true;
			break;
		}
	}
	if (!fail) {
		print rez;
	} else {
		fail = true;
		while (fail) {
			rez = vector<vector<int>>(_w, vector<int>(_h, -1));
			fail = false;
			vector<vector<int>> free(_w);
			for (int i = 0; i < _w; i++) {
				for (int j = 0; j < _h; j++)
					free[i].pb((i + j) % _h);
				

			}
			priority_queue<pii> deq;
			for (int i = 0; i < _w; i++) {
				deq.push(mp(_h, i));
			}
			vector<bool> block(_h, false);
			for (int i = 0; i < len(cords) && !fail; i++) {
				if (c[i]) {
					vector<pii> targets;
					for (int j = 0; j < min(c[i], _w); j++) {
						targets.emplace_back(deq.top());
						deq.pop();
					}
					for (int j = 0; j < min(c[i], _w); j++) {
						deq.push(mp(targets[j].x - 1, targets[j].y));
					}
					vector<int> to_del;
					sort(targets.begin(), targets.end());
					for (pii t : targets) {
						int found = -1;
						for (int j = len(free[t.y]) - 1; ~j; j--) {
							if (!block[free[t.y][j]]) {
								found = j;
								break;
							}
						}
						if (found == -1) {
							fail = true;
							break;
						} else {
							int b = free[t.y][found];
							for (int j = found; j < len(free[t.y]) - 1; j++)
								free[t.y][j] = free[t.y][j + 1];
							free[t.y].pop_back();
							block[b] = true;
							to_del.pb(b);
							rez[t.y][b] = cords[i];
						}
					}
					for (int x : to_del) {
						block[x] = false;
					}
				} 
			}
		}
		print rez;
	}
}
