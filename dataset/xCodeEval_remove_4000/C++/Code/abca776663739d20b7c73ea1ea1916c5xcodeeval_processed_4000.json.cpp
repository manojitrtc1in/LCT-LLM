








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



typedef pair<ld, ld> point;

int n, q;
vector<point> v;

ld operator^(point a, point b) {
	return a.x * b.y - a.y * b.x;
}

point getX(point a, point b, ld y) {
	if (a.y == b.y) {
		assert(abs(a.y - y) <= 0.000000001);
		return a;
	}
	return mp((y - a.y) * (b.x - a.x) / (b.y - a.y) + a.x, y);
}

ld area(vector<point> v) {
	ld S = 0;
	for (int i = 0; i < le(v); i++) {
		S += (v[i] ^ v[(i + 1) % le(v)]);
	}
	return S / 2;
}

struct Event {
	ld x;
	ld a = 0, b = 0, c = 0; int id = -1;
};

vector<Event> es;

void add_events(point a, point b, ld coef) {
	if (hypot(a.x - b.x, a.y - b.y) <= 0.000001) return;
	if (a.x > b.x) swap(a, b);
	ld k = abs(a.y - b.y) / abs(a.x - b.x) / 2;
	ld h = abs(a.y - b.y);
	if (abs(a.x - b.x) > 0.000001) {
		es.pb({a.x + 0.000000001, k * coef, -2 * a.x * k * coef, a.x * a.x * k * coef});
		es.pb({b.x + 0.000000001, -k * coef, 2 * a.x * k * coef, -a.x * a.x * k * coef});
	}

	es.pb({b.x + 0.0000000001, 0, h * coef, -b.x * h * coef + coef * h * (b.x - a.x) / 2});
}
int it = 0;
void trap(point a, point b, point c, point d) {
	it++;
	

	

	

	

	

	point ab = mp((a.x + b.x) / 2, (a.y + b.y) / 2);
	point cd = mp((c.x + d.x) / 2, (c.y + d.y) / 2);
	add_events(a, d, -1);
	add_events(ab, cd, 2);
	add_events(b, c, -1);
}

signed main(signed argc, char *argv[]) {
	scan n, q;
	v.resize(n);	
	scan v;
	if (area(v) < 0) reverse(v.begin(), v.end());
	

	

	

	int down = 0;
	for (int i = 0; i < n; i++) 
		if (v[i].y < v[down].y)
			down = i;
	

	int l = down;
	int r = down;	
	while ((l - 1 + n) % n != r) {
		int nl = (l - 1 + n) % n;
		int nr = (r + 1) % n;
		if (v[nl].y < v[nr].y) {
			

			point c = v[nl];
			point d = getX(v[r], v[nr], v[nl].y);
			ld down_y = max(v[l].y, v[r].y);
			point b = getX(v[l], v[nl], down_y);
			point a = getX(v[r], v[nr], down_y);
			trap(b, a, d, c);
			l = nl;
		} else {
			point c = v[nr];
			point d = getX(v[l], v[nl], v[nr].y);
			ld down_y = max(v[r].y, v[l].y);
			point b = getX(v[r], v[nr], down_y);
			point a = getX(v[l], v[nl], down_y);
			trap(a, b, c, d);
			r = nr;
		}
	}
	f(i, q) {
		ld F; scan F;
		es.pb({F, -1, -1, -1, i});
	}
	sort(es.begin(), es.end(), [](Event a, Event b) {
		return a.x < b.x;
	});
	ld a = 0; ld b = 0; ld c = abs(area(v));
	

	vector<ld> rez(q);
	for (Event e : es) {
		if (e.id != -1) {
			rez[e.id] = a * e.x * e.x + b * e.x + c;
		} else {
			a += e.a; b += e.b; c += e.c;
		}
	}
	for (ld x : rez) {
		print x;
	}
}
