








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

vector<int> v;

struct Q {
	int l, r;
	int id;
};

const int N = (1 << 17);

int T[2 * N + 1];
void _set(int i, int tl, int tr, int j, int val) {
	if (tl + 1 == tr) {
		T[i] = max(T[i], val);
	} else {
		int m = (tl + tr) / 2;
		if (j < m) _set(i * 2 + 1, tl, m, j, val);
		else _set(i * 2 + 2, m, tr, j, val);
		T[i] = max(T[i * 2 + 1], T[i * 2 + 2]);
	}
}
int query(int i, int tl, int tr, int ql, int qr) {
	if (qr <= tl || tr <= ql) return -1;
	if (ql <= tl && tr <= qr) {
		return T[i];
	} else {
		int m = (tl + tr) / 2;
		return max(query(i * 2 + 1, tl, m, ql, qr), query(i * 2 + 2, m, tr, ql, qr));
	}
}
struct TS {
	vector<int> T;
	int n;
	TS(int _n) {
		n = _n;
		T.resize(2 * n, 2e9);
	}
	void _set(int i, int tl, int tr, int j, int val) {
		if (tl + 1 == tr) {
			T[i] = min(T[i], val);
		} else {
			int m = (tl + tr) / 2;
			if (j < m) _set(i + 1, tl, m, j, val);	
			else _set(i + (m - tl) * 2, m, tr, j, val);
			T[i] = min(T[i + 1], T[i + (m - tl) * 2]);
		}
	}
	int query(int i, int tl, int tr, int ql, int qr) {
		if (qr <= tl || tr <= ql) return 2e9;
		if (ql <= tl && tr <= qr) return T[i];
		int m = (tl + tr) / 2;
		return min(query(i + 1, tl, m, ql, qr), query(i + (m - tl) * 2, m, tr, ql, qr));
	}
};
vector<int> cords;
signed main(signed argc, char *argv[]) {
	memset(T, -1, sizeof T);
	scan n; v.resize(n); scan v;
	cords = v;
	sort(cords.begin(), cords.end());
	cords.resize(unique(cords.begin(), cords.end()) - cords.begin());
	

	auto zip = [](int x) -> int {
		return lower_bound(cords.begin(), cords.end(), x) - cords.begin();
	};
	int q;
	scan q;
	vector<Q> qs;
	f(i, q) {
		int l, r;
		scan l, r;
		l--;
		qs.pb({l, r, i});
	}
	sort(qs.begin(), qs.end(), [](Q a, Q b) {
		return a.r < b.r;
	});
	TS ts(n);
	int cur = 0;
	vector<int> rez(q);
	for (Q q : qs) {
		while (cur < q.r) {
			

			int l = v[cur] - 2e9;
			int r = v[cur] + 2e9;
			while (true) {
				int e = query(0, 0, N, zip((l + v[cur] + 1) / 2), zip((r + v[cur] + 1) / 2));
				if (cur == 3) {
					

					

					

					

				}
				if (e == -1) break;
				

				

				

				ts._set(0, 0, n, e, abs(v[e] - v[cur]));
				

				if (v[e] >= v[cur]) {
					r = v[e];
				} else {
					l = v[e];
				}
				

				if (v[e] == v[cur]) break;
			}
			_set(0, 0, N, zip(v[cur]), cur);
			

			cur++;
		}
		

		

		

		rez[q.id] = ts.query(0, 0, n, q.l, n);
	}
	apply(rez, print x);
}
