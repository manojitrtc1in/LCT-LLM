









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

vector<bool> det;

struct TS {
	struct Node {
		set<int> ids;
		set<int> wait_list;
		int best = -1;
		int _min = -1;
	};

	int n;
	vector<Node> T;
	TS(int _n) {
		n = _n;
		T.resize(2 * n);
	}
	int get_best(int i, int tl, int tr) {
		if (T[i].best == -1) return -1;
		if (det[T[i].best])
			upd(i, tl, tr);
		return T[i].best;
	}
	void upd(int i, int tl, int tr) {
		T[i].best = -1;
		T[i]._min = -1;
		int m = (tl + tr) / 2;
		if (tl + 1 != tr) {
			T[i]._min = min(T[i + 1]._min, T[i + (m - tl) * 2]._min);
		}
		if (!T[i].ids.empty()) {
			T[i]._min = max(T[i]._min, *T[i].ids.rbegin());
		}
		while (!T[i].wait_list.empty()) {
			int top = *T[i].wait_list.rbegin();
			if (det[top]) {
				T[i].wait_list.erase(top);
				continue;
			}
			if (T[i].best < top) {
				T[i].best = top;
			}
			break;
		}
		if (tl + 1 != tr) {
			int m = (tl + tr) / 2;	
			if (get_best(i + 1, tl, m) > T[i].best)
				T[i].best = get_best(i + 1, tl, m);
			if (get_best(i + (m - tl) * 2, m, tr) > T[i].best)
				T[i].best = get_best(i + (m - tl) * 2, m, tr);
		}
		if (!T[i].ids.empty() && T[i].best < *T[i].ids.rbegin())
			T[i].best = -1;
		if (T[i].best < T[i]._min)
			T[i].best = -1;
		if (T[i].best == 1) {
			

		}
	}
	void update(int i, int tl, int tr, int ql, int qr, int id) {
		if (qr <= tl || tr <= ql) return;
		if (ql <= tl && tr <= qr) {
			

			T[i].ids.insert(id);
			T[i].wait_list.insert(id);
			upd(i, tl, tr);	
			

		} else {
			int m = (tl + tr) / 2;
			update(i + 1, tl, m, ql, qr, id);
			update(i + (m - tl) * 2, m, tr, ql, qr, id);
			upd(i, tl, tr);
		}	
	}
	void update(int ql, int qr, int id) {
		update(0, 0, n, ql, qr, id);
	}
	void remove(int i, int tl, int tr, int ql, int qr, int id) {
		if (qr <= tl || tr <= ql) return;
		if (ql <= tl && tr <= qr) {
			T[i].ids.erase(id);
			if (T[i].wait_list.count(id))
				T[i].wait_list.erase(id);
			upd(i, tl, tr);
		} else {
			int m = (tl + tr) / 2;
			remove(i + 1, tl, m, ql, qr, id);
			remove(i + (m - tl) * 2, m, tr, ql, qr, id);
			upd(i, tl, tr);
		}	
	}
	void remove(int ql, int qr, int id) {
		remove(0, 0, n, ql, qr, id);
	}
	void relax(int i, int tl, int tr, int ql, int qr) { 
		if (qr <= tl || tr <= ql) return;
		if (ql <= tl && tr <= qr) {
			upd(i, tl, tr);
		} else {
			int m = (tl + tr) / 2;
			relax(i + 1, tl, m, ql, qr);
			relax(i + (m - tl) * 2, m, tr, ql, qr);
			upd(i, tl, tr);
		}
	}
	void relax(int ql, int qr) {
		relax(0, 0, n, ql, qr);
	}
};

struct E {
	int x, yl, yr;
	bool add; int id;
};

signed main(signed argc, char *argv[]) {
	int n; scan n;
	vector<E> es;
	vector<int> cords;
	vector<pii> ranges;
	f(i, n) {
		int xl, yl, xr, yr;
		scan xl, yl, xr, yr;
		cords.pb(yl); cords.pb(yr);
		es.pb({xl, yl, yr, true, i + 1});
		es.pb({xr, yl, yr, false, i + 1});
		ranges.pb({yl, yr});
	}
	sort(cords.begin(), cords.end());
	cords.resize(unique(cords.begin(), cords.end()) - cords.begin());
	ranges.insert(ranges.begin(), {0, le(cords) + 2});
	auto zip = [&](int x) {
		return lower_bound(cords.begin(), cords.end(), x) - cords.begin();
	};
	for (E &e : es) {
		e.yl = zip(e.yl);
		e.yr = zip(e.yr); 
	}
	sort(es.begin(), es.end(), [](E a, E b) {
		return a.x < b.x;
	});
	TS ts(le(cords) + 2);
	det.resize(n + 1, false);
	ts.update(0, le(cords) + 2, 0);
	

	int pref = -1e9 - 1;
	for (E e : es) {
		if (pref < e.x) {
			

			

			while (ts.get_best(0, 0, ts.n) != -1) {
				int dot = ts.get_best(0, 0, ts.n);
				assert(!det[dot]);
				det[dot] = true;
				

				

				

				

			}
			pref = e.x;
		}
		if (e.add) {
			

			ts.update(e.yl, e.yr, e.id);
		} else {
			

			ts.remove(e.yl, e.yr, e.id);
		}
	}
	int cnt = 0;
	f(i, n + 1) {
		if (det[i]) {
			

			cnt++;
		}
	}
	print cnt;
}
