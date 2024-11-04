
#define fast_allocator
#define aimbot
#ifdef aimbot
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#endif

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <ostream>
#include <istream>
#include <typeinfo>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <limits>
#include <fstream>
#include <array>
#include <list>
#include <bitset>
#include <functional>
#include <random>
#include <cstring>
#include <chrono>

#define random escape__from__random__aetuhoetnuhshe
#define mt make_tuple
#define x first
#define y second
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define umap unordered_map
#define uset unordered_set
#define elif else if
#define len(v) ((int)v.size())
#define f(i, n) for (int i = 0; i < (n); i++)
#define rof(i, n) for (int i = ((n) - 1); i >= 0; i--)
#define apply(v, act) for (auto &x : v) { act; }
#define log(args...) {string s = #args;deque<string> deq;\
string buf = "";int bal = 0;for (char c : s) {\
if (c == '(' || c == '[' || c == '{') {bal++;\
} else if (c == ')' || c == ']' || c == '}') {\
bal--;} else {if (bal == 0) {if (c == ',') {\
deq.pb(buf);buf = "";} else {if (c != ' ') {\
buf += c;}}}}}if (!buf.empty()) {deq.pb(buf);}\
smart_io::precall_print();smart_io::_print(deq, args);}

inline int min(const int &x, const int &y) { return (((y-x)>>(32-1))&(x^y))^x; }
inline int max(const int &x, const int &y) { return (((y-x)>>(32-1))&(x^y))^y; }
inline long long min(const long long &x, const long long &y) { return (((y-x)>>(64-1))&(x^y))^x; }
inline long long max(const long long &x, const long long &y) { return (((y-x)>>(64-1))&(x^y))^y; }

#define print    \
smart_io::precall_print(); \
cout,

#define scan cin,

#ifdef fast_allocator
const int MAXMEM = 200 * 1000 * 1024;
char _memory[MAXMEM];
size_t _ptr = 0;
void* operator new(size_t _x) { _ptr += _x; assert(_ptr < MAXMEM); return _memory + _ptr - _x; }
void operator delete (void*) noexcept {}
#endif

using namespace std;

char string_in_buffer[(int)2e5];


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
	
	void precall_print() {
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

template<class Value, class Mod, class Magic, class ApplyMod, class MergeMods>
struct TreeSegment {
	struct Node {
		bool have_mod = false;
		Value value;
		Mod mod;
	};	

	Magic magic;
	ApplyMod apply_mod;
	MergeMods merge_mods;

	vector<Node> S;
	int n;

	bool __intersects(const int &tl, const int &tr, const int &ql, const int &qr) {
		return !(tr <= ql || qr <= tl);
	}

	Value __get_value(const int &i, const int &tl, const int &tr) {
		if (!S[i].have_mod) return S[i].value;
		return apply_mod(S[i].value, S[i].mod, tl, tr);
	}

	void __recalc_value(const int &i, const int &tl, const int &tr) {
		if (tl + 1 != tr) {
			int mid = (tl + tr) / 2;
			S[i].value = magic(
				__get_value(i + 1, tl, mid),
				__get_value(i + (mid - tl) * 2, mid, tr)
			);
		}
	}

	void __add_mod(const int &i, const int &tl, const int &tr, const Mod &sub) {
		if (S[i].have_mod) {
			S[i].mod = merge_mods(S[i].mod, sub, tl, tr);
		} else {
			S[i].mod = sub;
			S[i].have_mod = true;
		}
	}

	void __push(const int &i, const int &tl, const int &tr) {
		if (S[i].have_mod) {
			S[i].value = apply_mod(S[i].value, S[i].mod, tl, tr);
			if (tl + 1 != tr) {
				int mid = (tl + tr) / 2;
				__add_mod(i + 1, tl, mid, S[i].mod);
				__add_mod(i + (mid - tl) * 2, mid, tr, S[i].mod);
			}
			S[i].have_mod = false;
		}
	}

	void init(const int &i, const int &tl, const int &tr, const vector<Value> &src) {
		if (tl + 1 == tr) {
			S[i].value = src[tl];
		} else {
			int mid = (tl + tr) / 2;
			init(i + 1, tl, mid, src);
			init(i + (mid - tl) * 2, mid, tr, src);
			__recalc_value(i, tl, tr);
		}
	}

	Value __query(const int &i, const int &tl, const int &tr,
			const int &ql, const int &qr) {
		__push(i, tl, tr);
		if (ql <= tl && tr <= qr) {
			return S[i].value;
		} else {
			int mid = (tl + tr) / 2;
			if (__intersects(tl, mid, ql, qr) && __intersects(mid, tr, ql, qr)) {
				return magic(
					__query(i + 1, tl, mid, ql, qr),
					__query(i + (mid - tl) * 2, mid, tr, ql, qr)
				);
			} else if (__intersects(tl, mid, ql, qr)) {
				return __query(i + 1, tl, mid, ql, qr);
			} else {
				return __query(i + (mid - tl) * 2, mid, tr, ql, qr);
			}
		}
	}

	void __change(const int &i, const int &tl, const int &tr,
			const int &j, const Value &_new) {
		__push(i, tl, tr);
		if (tl + 1 == tr) {
			S[i].value = _new;
		} else {
			int mid = (tl + tr) / 2;
			if (j < mid) {
				__change(i + 1, tl, mid, j, _new);
			} else {
				__change(i + (mid - tl) * 2, mid, tr, j, _new);
			}
			__recalc_value(i, tl, tr);
		}
	}

	void __update(const int &i, const int &tl, const int &tr,
			const int &ql, const int &qr, const Mod &mod) {
		__push(i, tl, tr);
		if (ql <= tl && tr <= qr) {
			__add_mod(i, tl, tr, mod);
		} else {
			int mid = (tl + tr) / 2;
			if (__intersects(tl, mid, ql, qr)) {
				__update(i + 1, tl, mid, ql, qr, mod);	
			}
			if (__intersects(mid, tr, ql, qr)) {
				__update(i + (mid - tl) * 2, mid, tr, ql, qr, mod);
			}
			__recalc_value(i, tl, tr);
		}
	}

	template<class Check>
	pair<int, Value> __find_right(const int &i, const int &tl, const int &tr,
			const int &L, const Check &checker, const Value &pref) {
		__push(i, tl, tr);
		if (tr <= L) return mp(-1, pref);
		if (tl + 1 == tr) {
			Value _this = magic(pref, __get_value(i, tl, tr));
			if (checker(_this)) {
				return mp(tl, _this);
			} else {
				return mp(-1, _this);
			}
		} else {
			int mid = (tl + tr) / 2;
			if (L <= tl) {
				Value _left = magic(pref, __get_value(i + 1, tl, mid));
				if (checker(_left)) {
					return __find_right(i + 1, tl, mid, L, checker, pref);
				} else {
					return __find_right(i + (mid - tl) * 2, mid, tr, L, checker, _left);
				}
			} else {
				auto t = __find_right(i + 1, tl, mid, L, checker, pref);
				if (t.first != -1) return t;
				return __find_right(i + (mid - tl) * 2, mid, tr, L, checker, t.second);
			}	
		}
	}

	template<class Check>
	pair<int, Value> __find_left(const int &i, const int &tl, const int &tr,
			const int &R, const Check &checker, const Value &pref) {
		__push(i, tl, tr);
		if (R < tl) return mp(-1, pref);
		if (tl + 1 == tr) {
			Value _this = magic(pref, __get_value(i, tl, tr));
			if (checker(_this)) {
				return mp(tl, _this);
			} else {
				return mp(-1, _this);
			}
		} else {
			int mid = (tl + tr) / 2;
			if (tr <= R + 1) {
				Value _right = magic(pref, __get_value(S[i].r, mid, tr));
				if (checker(_right)) {
					return __find_left(S[i].r, mid, tr, R, checker, pref);
				} else {
					return __find_left(S[i].l, tl, mid, R, checker, _right);
				}
			} else {
				auto t = __find_left(S[i].r, mid, tr, R, checker, pref);
				if (t.first != -1) return t;
				return __find_left(S[i].l, tl, mid, R, checker, t.second);
			}	
		}
	}

	void init(const vector<Value> &src) {
		n = len(src);
		S.resize(2 * n + 1);
		init(0, 0, len(src), src);
	}
	
	TreeSegment(const int &n, const Value &def,
			Magic _magic, ApplyMod _apply_mod, MergeMods _merge_mods, Mod)
			: magic(_magic), apply_mod(_apply_mod), merge_mods(_merge_mods) {
		init(vector<Value>(n, def));
	}

	TreeSegment(const vector<Value> &def,
			Magic _magic, ApplyMod _apply_mod, MergeMods _merge_mods, Mod) 
			: magic(_magic), apply_mod(_apply_mod), merge_mods(_merge_mods) {
		init(def);
	}

	Value query(const int &ql, const int &qr) {
		assert(ql < qr);
		return __query(0, 0, n, ql, qr);
	}

	void change(const int &i, const Value &value) {
		assert(0 <= i && i < n);
		__change(0, 0, n, i, value);
	}

	void update(const int &ql, const int &qr, const Mod &mod) {
		__update(0, 0, n, ql, qr, mod);
	}
	
	template<class Check>
	int find_right(const int &L, const Check &checker, const Value &start) {
		if (checker(start)) return L - 1;
		int rez = __find_right(0, 0, n, L, checker, start).first;
		return (rez == -1) ? n : rez;
	}

	template<class Check>
	int find_left(const int &R, const Check &checker, const Value &start) {
		if (checker(start)) return R + 1;
		int rez = __find_left(0, 0, n, R, checker, start).first;
		return (rez == -1) ? -1 : rez;
	}
};

struct Elem {
	int _min = 0, _max = 0;
	int _maxmin = 0;
	int _minmax = 0;
	int _full = 0;
};

int n, q;

signed main(signed argc, char *argv[]) {
	scan n, q;
	string s;
	scan s;
	int m = len(s);
	m++;
	s.insert(s.begin(), 0);
	f(i, m) {
		if (s[i] == '(') s[i] = 1;
		else s[i] = -1;
	}
	vector<Elem> v(m);
	for (int i = 1; i < m; i++) {
		v[i] = v[i - 1];
		v[i]._min += s[i];
		v[i]._max += s[i];
		v[i]._maxmin -= s[i];
		v[i]._minmax -= s[i];
	}
	TreeSegment ts(v, [](Elem a, Elem b) {
		Elem c;
		c._min = min(a._min, b._min);
		c._max = max(a._max, b._max);
		c._maxmin = max(
			max(a._maxmin, b._maxmin),
			a._max - 2 * b._min
		);
		c._minmax = max(
			max(a._minmax, b._minmax),
			-2 * a._min + b._max	
		);
		c._full = max(
			max(a._full, b._full),
			max(a._max + b._minmax, a._maxmin + b._max)
		);
		return c;
	}, [](Elem value, int mod, int, int) {
		value._min += mod;
		value._max += mod;
		value._maxmin -= mod;
		value._minmax -= mod;
		return value;
	}, [](int a, int b, int, int) {
		return a + b;
	}, 1337);

	f(i, q + 1) {
		int a = 0, b = 0;
		if (i != 0)	{
			scan a, b;
		}
		if (a > b) swap(a, b);
		if (s[a] != s[b]) {
			ts.update(a, b, -s[a] - s[a]);
			swap(s[a], s[b]);
		}

		print ts.query(0, m)._full;
	}
}

