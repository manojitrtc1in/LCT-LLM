

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
	T floor_mod(T a, T b) {
		if (a >= 0 && b >= 0) return a % b;
		if (a <= 0 && b <= 0) return a % b;
		return abs(b) - (abs(a) % abs(b));
	}
}

using namespace numbers_operation;
using namespace typedefs;
using namespace random;

int n, k;
vector<vector<int>> g;
vector<int> up;
vector<int> max_depth;

void dfs(int v, int _p) {
	max_depth[v] = 0;
	for (int sub : g[v]) {
		if (sub == _p) continue;
		dfs(sub, v);
		max_depth[v] = max(max_depth[v], max_depth[sub] + 1);
	}
}

void calc_up(int v, int _p) {
	multiset<int> all;
	for (int sub : g[v]) {
		if (sub == _p) continue;
		all.insert(up[sub] + 1);
	}
	all.insert(up[v]);
	for (int sub : g[v]) {
		if (sub == _p) continue;
		all.erase(all.find(up[sub] + 1));
		up[sub] = *all.rbegin();	
		calc_up(sub, v);
		all.insert(up[sub] + 1);
	}
}

void dp(int v, int _p) {
	vector<int> L;
	for (int sub : g[v]) {
		if (sub == _p) continue;
		if (max_depth[sub] + up[v] >= k - 1) {
			L.pb(max_depth[sub] + 1);
		}
	}
	sort(L.rbegin(), L.rend());
	if (len(L) >= 2 && L[0] + L[1] >= k - 1) {
		print "No";
		exit(0);
	}
	for (int sub : g[v]) {
		if (sub == _p) continue;
		dp(sub, v);
	}
}

vector<int> c;
void color(int v, int _p, int d) {
	for (int sub : g[v]) {
		if (sub == _p) continue;
		c[sub] = (c[v] + d) % k;
		color(sub, v, d);
	}
}

vector<int> depth;

void go(int v, int _p) {
	for (int sub : g[v]) {
		if (sub == _p) continue;
		depth[sub] = depth[v] + 1;
		go(sub, v);
	}
}

int farthest(int v) {
	depth = vector<int>(n, 0);
	go(v, -1);
	return max_element(depth.begin(), depth.end()) - depth.begin();
}

vector<int> path;
void get_path(int v) {
	path.pb(v);
	if (depth[v] == 0) return;
	for (int sub : g[v]) 
		if (depth[sub] == depth[v] - 1)
			get_path(sub);
}

void check() {
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			path.clear();
			farthest(i);
			get_path(j);
			if (len(path) == k) {
				set<int> diff;
				for (int x : path) {
					diff.insert(c[x]);
				}
				assert(len(diff) == k);
			}
		}
	}
}

signed main(signed argc, char *argv[]) {
	scan n, k;
	g.resize(n);
	up.resize(n);
	max_depth.resize(n);
	f(i, n - 1) {
		int a, b;
		scan a, b;
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	if (k == 2) {
		print "Yes";
		c.resize(n);
		color(0, -1, 1);
		apply(c, x++);
		print c;
		return 0;
	}
	dfs(0, -1);
	calc_up(0, -1);
	


	int a = farthest(0);
	int b = farthest(a);

	c.resize(n);
	get_path(b);

	for (int i = 0; i < len(path); i++) {
		for (int sub : g[path[i]]) {
			if (i + 1 < len(path) && path[i + 1] == sub) continue;
			if (i - 1 >= 0 && path[i - 1] == sub) continue;
			max_depth[sub] = 0;
			dfs(sub, path[i]);
			if (max_depth[sub] + 1 + i >= k - 1 && max_depth[sub] + 1 + len(path) - i - 1 >= k - 1) {
				print "No";
				return 0;
			}
		}
	}

	print "Yes";

	if (len(path) >= k) {
		c[path[k - 1]] = k - 1;
		c[path[len(path) - k]] = (len(path) - k) % k;
		for (int i = 0; i < len(path); i++) {
			c[path[i]] = i % k;
		}
		

		

		for (int i = 0; i < len(path); i++) {
			for (int sub : g[path[i]]) {
				if (i + 1 < len(path) && path[i + 1] == sub) continue;
				if (i - 1 >= 0 && path[i - 1] == sub) continue;
				max_depth[sub] = 0;
				dfs(sub, path[i]);
				if (max_depth[sub] + 1 + i >= k - 1) {
					c[sub] = (c[path[i]] + 1) % k;
					color(sub, path[i], 1);
				} else {
					c[sub] = (c[path[i]] + k - 1) % k;
					color(sub, path[i], -1);
				}
			}
		}
	} else {

	}
	

	

	

	apply(c, x++);
	print c;
}
