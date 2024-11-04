

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

struct CommandY {
	pii compose(pii f1, pii f2) {
		

		

		

		return mp(max(f1.x, f2.x + f1.y), f2.y + f1.y);
	}

	pii largest(pii f1, pii f2) {
		return mp(max(f1.x, f2.x), max(f1.y, f2.y));
	}

	vector<pii> F, H;
	int n;

	CommandY() {}
	CommandY(int _n) {
		n = _n;
		F.resize(2 * n);
		H.resize(2 * n);
	}

	void push(int i, int tl, int tr) {
		if (tl + 1 != tr) {
			int m = (tl + tr) / 2;
			H[i + 1] = largest(H[i + 1], compose(H[i], F[i + 1]));
			H[i + (m - tl) * 2] = largest(H[i + (m - tl) * 2], compose(H[i], F[i + (m - tl) * 2]));
			F[i + 1] = compose(F[i], F[i + 1]);
			F[i + (m - tl) * 2] = compose(F[i], F[i + (m - tl) * 2]);

			F[i] = mp(-1e9, 0);
			H[i] = mp(-1e9, 0);
		}
	}

	void update(int i, int tl, int tr, int ql, int qr, pii func) {
		if (qr <= tl || tr <= ql) return;
		if (ql <= tl && tr <= qr) {
			H[i] = largest(H[i], compose(func, F[i]));
			F[i] = compose(func, F[i]);
		} else {
			push(i, tl, tr);
			int m = (tl + tr) / 2;
			update(i + 1, tl, m, ql, qr, func);
			update(i + (m - tl) * 2, m, tr, ql, qr, func);
		}	
	}
	void update(int ql, int qr, pii func) { update(0, 0, n, ql, qr, func); }

	void extract_history(int i, int tl, int tr, vector<pii> &vals) {
		if (tl + 1 == tr) {
			vals.emplace_back(H[i]);
		} else {
			push(i, tl, tr);
			int m = (tl + tr) / 2;
			extract_history(i + 1, tl, m, vals);
			extract_history(i + (m - tl) * 2, m, tr, vals);
		}
	}

	vector<pii> extract_history() {
		vector<pii> vals;
		extract_history(0, 0, n, vals);
		return vals;
	}
};


const int NN = (1 << 19);




pii F[1];
pii H[1];

pii compose(pii f1, pii f2) {
	

	

	

	return mp(max(f1.x, f2.x + f1.y), f2.y + f1.y);
}

pii largest(pii f1, pii f2) {
	return mp(max(f1.x, f2.x), max(f1.y, f2.y));
}

void push(int i, int tl, int tr) {
	if (tl + 1 != tr) {
		H[i * 2 + 1] = largest(H[i * 2 + 1],
			compose(H[i], F[i * 2 + 1]));
		H[i * 2 + 2] = largest(H[i * 2 + 2],
			compose(H[i], F[i * 2 + 2]));
		F[i * 2 + 1] = compose(F[i], F[i * 2 + 1]);
		F[i * 2 + 2] = compose(F[i], F[i * 2 + 2]);
		F[i] = mp(-1e9, 0);
		H[i] = mp(-1e9, 0);
	}
}

void update(int i, int tl, int tr, int ql, int qr, pii func) {
	if (tr <= ql || qr <= tl) return;
	push(i, tl, tr);
	if (ql <= tl && tr <= qr) {
		H[i] = largest(H[i], compose(func, F[i])); 
		F[i] = compose(func, F[i]);
	} else {
		int m = (tl + tr) / 2;
		update(i * 2 + 1, tl, m, ql, qr, func);
		update(i * 2 + 2, m, tr, ql, qr, func);
	}
}

void gopush(int i, int tl, int tr) {
	push(i, tl, tr);
	int m = (tl + tr) / 2;
	if (tl + 1 != tr) {
		gopush(i * 2 + 1, tl, m);
		gopush(i * 2 + 2, m, tr);
	}
}

CommandY cmdY;

const int N = 5e5;

int n;	
vector<int> g[N];
int th[N];
int gdist[2 * N + 1];

void init(int v, int _p) {
	for (int sub : g[v]) {
		if (sub == _p) continue;
		init(sub, v);
		th[v] = max(th[v], th[sub] + 1);
	}
}

void dfs(int v, int _p, int maxh) {
	

	pii max1 = mp(maxh, -1);
	pii max2 = mp(0, -1);
	for (int sub : g[v]) {
		if (sub == _p) continue;
		pii t = mp(th[sub] + 1, sub);
		if (max1 < t) swap(max1, t);
		if (max2 < t) swap(max2, t);
	}

	cmdY.update(0, NN, mp(-1e9, -1e8));
	cmdY.update(0, maxh + 1, mp(-1e9, 1));
	for (int sub : g[v]) {
		if (sub == _p) continue;
		cmdY.update(0, th[sub] + 2, mp(-1e9, 1));
	}
	for (int sub : g[v]) {
		if (sub == _p) continue;
		int nmaxh = (max1.y == sub) ? max2.x : max1.x;
		int maxsubh = 0;

		cmdY.update(0, th[sub] + 2, mp(-1e9, -1));
		for (int sub2 : g[sub]) {
			if (sub2 == v) continue;
			cmdY.update(0, th[sub2] + 2, mp(-1e9, 1));
			maxsubh = max(maxsubh, th[sub2] + 1);
		}
		gdist[min(maxsubh, nmaxh) * 2 + 1] = 2;
		

		cmdY.update(0, min(nmaxh, maxsubh) + 1, mp(-1e9, 1e8));
		cmdY.update(0, min(nmaxh, maxsubh) + 1, mp(-1e9, -1e8));

		for (int sub2 : g[sub]) {
			if (sub2 == v) continue;
			cmdY.update(0, th[sub2] + 2, mp(-1e9, -1));
		}
		cmdY.update(0, th[sub] + 2, mp(-1e9, 1));
	}
	for (int sub : g[v]) {
		if (sub == _p) continue;
		cmdY.update(0, th[sub] + 2, mp(-1e9, -1));
	}
	cmdY.update(0, maxh + 1, mp(-1e9, -1));
	cmdY.update(0, NN, mp(-1e9, 1e8));
	

	for (int sub : g[v]) {
		if (sub == _p) continue;
		int nmaxh = (max1.y == sub) ? max2.x : max1.x;
		

		dfs(sub, v, nmaxh + 1);
	}
}

void normal(int v, int _p, int maxh) {
	

	cmdY.update(0, maxh + 1, mp(-1e9, 1));
	for (int sub : g[v]) {
		if (sub == _p) continue;
		cmdY.update(0, th[sub] + 2, mp(-1e9, 1));
	}
	

	for (int sub : g[v]) {
		if (sub == _p) continue;
		cmdY.update(0, th[sub] + 2, mp(-1e9, -1));
	}
	cmdY.update(0, maxh + 1, mp(-1e9, -1));
	

	pii max1 = mp(maxh, -1);
	pii max2 = mp(0, -1);
	for (int sub : g[v]) {
		if (sub == _p) continue;
		pii t = mp(th[sub] + 1, sub);
		if (max1 < t) swap(max1, t);
		if (max2 < t) swap(max2, t);
	}
	for (int sub : g[v]) {
		if (sub == _p) continue;
		int nmaxh = (max1.y == sub) ? max2.x : max1.x;
		normal(sub, v, nmaxh + 1);
	}
}

void normal2(int v, int _p, int maxh) {
	

	cmdY.update(0, maxh + 1, mp(-1e9, 1));
	vector<int> added{maxh};
	set<int> was;
	was.insert(maxh);
	for (int sub : g[v]) {
		if (sub == _p) continue;
		if (was.count(th[sub] + 1)) {
			cmdY.update(0, th[sub] + 1, mp(-1e9, 1));
			added.pb(th[sub]);
		} else {
			cmdY.update(0, th[sub] + 2, mp(-1e9, 1));
			added.pb(th[sub] + 1);
			was.insert(th[sub] + 1);	
		}
	}
	

	for (int x : added) {
		cmdY.update(0, x + 1, mp(-1e9, -1));
	}
	

	

	

	

	

	

	pii max1 = mp(maxh, -1);
	pii max2 = mp(0, -1);
	for (int sub : g[v]) {
		if (sub == _p) continue;
		pii t = mp(th[sub] + 1, sub);
		if (max1 < t) swap(max1, t);
		if (max2 < t) swap(max2, t);
	}
	for (int sub : g[v]) {
		if (sub == _p) continue;
		int nmaxh = (max1.y == sub) ? max2.x : max1.x;
		normal2(sub, v, nmaxh + 1);
	}
}

signed main(signed argc, char *argv[]) {
	scan n;
	for (int i = 0; i < n - 1; i++) {
		int a, b; 
		scan a, b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	init(0, -1);
	cmdY = CommandY(NN);
	dfs(0, -1, 0);
	vector<pii> A = cmdY.extract_history();
	vector<int> sdist(2 * n);
	for (int i = 1; i < n; i++) {
		sdist[i * 2] = max(A[i].x, A[i].y);
	}
	cmdY = CommandY(NN);
	normal(0, -1, 0);
	A = cmdY.extract_history();
	vector<int> ddist(2 * n);
	for (int i = 1; i < n; i++) {
		ddist[i * 2] = max(A[i].x, A[i].y);
	}
	cmdY = CommandY(NN);
	normal2(0, -1, 0);
	A = cmdY.extract_history();
	vector<int> cdist(2 * n);
	for (int i = 1; i < n; i++) {
		cdist[i * 2 + 1] = max(A[i].x, A[i].y);
	}

	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			int rez = 0;
			for (int i = 0; i < n; i++)
				rez = max(rez, len(g[i]) + 1);
			print rez;
		} else {
			print max(cdist[i], max(
				max(gdist[i], gdist[i + 1]),
				max(1, max(sdist[i], max(ddist[i], ddist[i + 1])))));
		}
		smart_io::print_start = " ";
	}
}
