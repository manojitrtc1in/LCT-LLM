

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

namespace std::chrono {
	long long get_time_ms() {
		return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
	}
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
		if (a % b == 0) return 0;
		if (a >= 0 && b >= 0) return a % b;
		if (a <= 0 && b <= 0) return a % b;
		return abs(b) - (abs(a) % abs(b));
	}
}

using namespace numbers_operation;
using namespace typedefs;

int n;
vector<int> v;
vector<vector<int>> rez;

void act(int a, int b, int c) {
	assert(a < n && b < n && c < n);
	rez.pb({a, b, c});
	v[a] ^= 1;
	v[b] ^= 1;
	v[c] ^= 1;
	

}

vector<vector<int>> resolve(vector<int> big) {
	auto make = [&big](int st, int k) {
		if (st < len(big)) {
			big[st] ^= 1;
		}
		if (st + k < len(big)) {
			big[st + k] ^= 1;
		}
		if (st + k + k < len(big)) {
			big[st + k + k] ^= 1;
		}
	};
	for (int a = 0; a < len(big); a++) {
		for (int k = 1; a + k <= len(big); k++) {
			for (int b = 0; b < len(big); b++) {
				for (int t = 1; b + t <= len(big); t++) {
					make(a, k);
					make(b, t);

					bool fail = false;
					for (int x : big) {
						if (x != 0) {
							fail = true;
						}
					}
					if (!fail) {
						vector<vector<int>> rez;
						rez.pb({a, a + k, a + 2 * k});
						rez.pb({b, b + t, b + 2 * t});
						return rez;
					}

					make(a, k);
					make(b, t);
				}
			}
		}
	}
	assert(false);
}

vector<int> dist;
vector<int> pref;
void dijkstra(int m) {
	int M = (1 << m);
	dist.resize(M, 1e9);
	pref.resize(M, -1);
	dist[0] = 0;
	deque<int> deq{0};
	while (!deq.empty()) {
		int v = deq[0];
		deq.pop_front();
		for (int i = 0; i < m; i++) {
			for (int k = 1; k * 2 + i < m; k++) {
				int sub = v;
				sub ^= (1 << i);
				sub ^= (1 << (i + k));
				sub ^= (1 << (i + k + k));
				if (dist[sub] > dist[v] + 1) {
					dist[sub] = dist[v] + 1;
					pref[sub] = v;
					deq.pb(sub);
				}
			}
		}
	}
}


signed main(signed argc, char *argv[]) {
	scan n;
	v.resize(n);
	scan v;
	f(i, n - 13) {
		if (v[i] == 0) continue;
		vector<int> small = {v[i], v[i + 1], v[i + 2]};
		vector<int> big = {v[i], v[i + 1], v[i + 2], v[i + 3], v[i + 4], v[i + 5]};
		if (true) {
			vector<vector<int>> __t = resolve(big);
			for (vector<int> t : __t) {
				act(i + t[0], i + t[1], i + t[2]);
			}
		} else {
			int cnt = small[0] + small[1] + small[2];
			vector<int> ones;
			f(j, 3) {
				if (small[j] == 1) {
					ones.pb(j);
				}
			}
			if (cnt == 1) {
				act(i + ones[0], i + ones[0] + 3, i + ones[0] + 6);
			} else if (cnt == 2) {
				act(i + ones[0], i + ones[1], i + ones[1] + 2);
			} else if (cnt == 3) {
				act(i, i + 1, i + 2);
			}
		}
	}


	

	

	

	

	


	int k = min(13, len(v));
	vector<int> end(v.end() - k, v.end());
	int mask = 0;	
	f(i, len(end)) {
		mask = (mask | (end[i] << i));	
	}
	dijkstra(k);
	

	

	if (dist[mask] == 1e9) {
		print "NO";
		return 0;
	}
	

	while (mask) {
		int next = pref[mask];
		int diff = (next ^ mask);
		

		vector<int> pos;
		f(i, k) {
			if ((1 << i) & diff) {
				pos.pb(i + len(v) - k);
			}
		}
		act(pos[0], pos[1], pos[2]);
		mask = next;
	}

	for (int x : v) {
		if (x != 0) {
			print "NO";
			return 0;
		}
	}
	print "YES";
	print len(rez);
	

	for (vector<int> sub : rez) {
		print sub[0] + 1, sub[1] + 1, sub[2] + 1;
	}
}