

#ifdef aimbot
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <immintrin.h>
#endif

#define hur(f, g) template<class c> int f(c a) {if (sizeof(c) == 8) return g##ll(a); else return g(a);}
hur(popc, __builtin_popcount) hur(ctz, __builtin_ctz) hur(clz, __builtin_clz)



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
#define mp make_pair
#define le(v) ((int)v.size())
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

const ll MOD = 1e9 + 7;

int n;
vector<pii> v;

pii inter(pii a, pii b) {
	return mp(max(a.x, b.x), min(a.y, b.y));
}
int mul(int a, int b) {
	return (a * b) % MOD;
}

int choice(pii pp) {
	return max(pp.y - pp.x + 1, 0LL);
}

int nequal(pii a, pii b) {
	return mul(choice(a), choice(b)) - choice(inter(a, b));
}

ll fast_pow(ll x, ll p) {
	if (p == 0) return 1;
	if (p & 1) return (x * fast_pow(x, p - 1)) % MOD;
	ll t = fast_pow(x, p / 2);
	return (t * t) % MOD;
}

signed main(signed argc, char *argv[]) {
	scan n;
	v.resize(n);
	f(i, n) {
		scan v[i].x;
	}
	f(i, n) {
		scan v[i].y;
	}
	v.insert(v.begin(), mp(-1, -1));
	n++;
	vector<ll> inv(n);
	f(i, n) {
		inv[i] = fast_pow(choice(v[i]), MOD - 2);
	}
	ll all = 1;
	for (int i = 0; i < n; i++) {
		all = mul(all, choice(v[i]));
	}
	vector<ll> val(n);
	for (int i = 0; i < n - 1; i++) {
		val[i] = nequal(v[i], v[i + 1]);
		val[i] = mul(mul(val[i], all), mul(inv[i], inv[i + 1]));
		

		

		

		

	}
	vector<ll> valR(n);
	vector<ll> valL(n);
	for (int i = n - 1; i >= 0; i--) {
		valR[i] = val[i];
		if (i + 1 < n) valR[i] += valR[i + 1];	
		valR[i] %= MOD;
	}
	for (int i = 0; i < n; i++) {
		valL[i] = val[i];
		if (i - 1 >= 0) valL[i] += valL[i - 1];
		valL[i] %= MOD;
	}
	ll rez = 0;
	for (int i = 0; i < n - 1; i++) {
		

		{
			int pos = mul(choice(v[i]), choice(v[i + 1])) - choice(inter(v[i], v[i + 1]));
			

			

			

			

			rez += mul(pos, mul(all, mul(inv[i], inv[i + 1])));
		}
		

		if (i + 2 < n) {
			int pos = mul(choice(v[i]), mul(choice(v[i + 1]), choice(v[i + 2])));
			pos -= nequal(inter(v[i], v[i + 1]), v[i + 2]);
			pos -= nequal(v[i], inter(v[i + 1], v[i + 2]));
			pos -= choice(inter(v[i], inter(v[i + 1], v[i + 2])));
			

			

			

			

			rez += mul(mul(mul(2, pos), all), mul(inv[i], mul(inv[i + 1], inv[i + 2])));
		}
		if (i + 2 < n)
			rez += mul(inv[i + 1], mul(inv[i], mul(nequal(v[i], v[i + 1]), valR[i + 2])));
		if (i - 2 >= 0)
			rez += mul(inv[i + 1], mul(inv[i], mul(nequal(v[i], v[i + 1]), valL[i - 2])));
		

		

		

		

		rez %= MOD;
	}
	rez = mul(rez, fast_pow(all, MOD - 2));
	rez %= MOD;
	if (rez < 0) rez += MOD;
	print rez;
}
