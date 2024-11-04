

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
#define int long long
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

const int N = (1 << 20);

int T[2 * N + 1];
int C[2 * N + 1];
int D[2 * N + 1];
bool disabled[2 * N + 1];

int get_value(int i) {
	if (disabled[i]) return 1e9;
	return T[i] + D[i];
}

int get_count(int i) {
	if (disabled[i]) return 0;
	return C[i];
}

void push(int i, int tl, int tr) {
	T[i] += D[i];
	if (tl + 1 != tr) {
		D[i * 2 + 1] += D[i];
		D[i * 2 + 2] += D[i];
	}
	D[i] = 0;
}

void update(int i) {
	T[i] = min(get_value(i * 2 + 1), get_value(i * 2 + 2));
	C[i] = 0;
	if (T[i] == get_value(i * 2 + 1))
		C[i] += get_count(i * 2 + 1);
	if (T[i] == get_value(i * 2 + 2))
		C[i] += get_count(i * 2 + 2);
}

void inc(int i, int tl, int tr, int ql, int qr, int d) {
	if (qr <= tl || tr <= ql) return;	
	push(i, tl, tr);
	if (ql <= tl && tr <= qr) {
		D[i] += d;
	} else {
		int m = (tl + tr) / 2;
		inc(i * 2 + 1, tl, m, ql, qr, d);
		inc(i * 2 + 2, m, tr, ql, qr, d);
		update(i);	
	}
}

void invoke(int i, int tl, int tr, int j, bool d) {
	push(i, tl, tr);
	if (tl + 1 == tr) {
		disabled[i] = d;
	} else {
		int m = (tl + tr) / 2;
		if (j < m) invoke(i * 2 + 1, tl, m, j, d);
		else invoke(i * 2 + 2, m, tr, j, d);
		update(i);
	}
}

vector<int> v;
void en(int i, int d) {
	if (i == len(v) - 1) return;
	int a = v[i], b = v[i + 1];	
	if (a > b) swap(a, b);
	inc(0, 0, N, a + 1, b + 1, d);
}

signed main(signed argc, char *argv[]) {
	for (int i = 0; i < 2 * N; i++) {
		C[i] = 1;
	}
	for (int i = N - 1; i < 2 * N; i++)
		disabled[i] = 1;
	for (int i = N - 2; ~i; i--) {
		update(i);
	}
	int n, q;
	scan n, q;
	v.resize(n);
	scan v;
	n += 2;
	v.insert(v.begin(), (int)1e6 + 1);
	v.pb(0);
	for (int i = 0; i < n - 1; i++) {
		en(i, 1);
		invoke(0, 0, N, v[i], 0);
	}
	for (int i = 0; i < q; i++) {
		int pos, val;
		scan pos, val;
		en(pos, -1);
		en(pos - 1, -1);
		invoke(0, 0, N, v[pos], 1);
		v[pos] = val;
		invoke(0, 0, N, v[pos], 0);
		en(pos, 1);
		en(pos - 1, 1);
		

		

		

		

		

		

		print C[0] - 1;
	}
}
