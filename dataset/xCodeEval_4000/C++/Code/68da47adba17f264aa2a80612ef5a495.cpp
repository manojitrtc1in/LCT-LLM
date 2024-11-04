


#ifdef aimbot
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
#include <complex>

#define M_PI acos(-1)
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
#define rof(i, n) for (int i = ((n) - 1); i > -1; i--)
#define apply(v, act) for (auto &x : v) { act; }


#define print    \
smart_io::precall_print(); \
cout,

#define scan cin,


using namespace std;

char string_in_buffer[(int)1e6];


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
	void _print(deque<string> names, T kek, Args... args) {
		if (!first_print) {
			fast_print("\n");
		} else {
			first_print = false;
		}
		fast_print(names.front());
		fast_print(" = ");
		fast_print(kek);
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




namespace typedefs {
	typedef long long ll;
	typedef unsigned long long ull;
	typedef pair<int, int> pii;
	typedef double ld;
	typedef complex<ld> plex;
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

vector<vector<plex>> W;

int rev(int x, int log) {
	int rez = 0;
	f(i, log) {
		if (x & (1 << i)) {
			rez = (rez | (1 << (log - 1 - i)));
		}	
	}
	return rez;
}

namespace UltraFast {
	int n;
	vector<int> gen(int n) {
		if (n == 1) return {0};
		vector<int> sub = gen(n / 2);
		vector<int> rez(n);
		f(i, n / 2) {
			rez[2 * i] = sub[i];
			rez[2 * i + 1] = sub[i] + n / 2;
		}
		return rez;
	}

	vector<plex> a;

	void fft(int l, int r, plex e) {
		if (l + 1 == r) return;
		int n = (r - l);
		int mid = (l + r) / 2;

		fft(l, mid, e * e);
		fft(mid, r, e * e);

		plex cur = 1;
		f(i, n / 2) {
			plex x = a[i + l], y = a[i + mid];
			a[i + l] = x + cur * y;
			a[i + mid] = x - cur * y;
			cur *= e;
		}
	}

	void fft(plex e, bool inv) {
		vector<plex> roots{e};
		for (int k = 2; k < n; k *= 2) {
			roots.pb(roots.back() * roots.back());
		}
		int id = 0;
		for (int k = 1; k < n; k *= 2, id++) {
			for (int i = 0; i < n; i += k * 2) {
				for (int j = 0; j < k; j++) {
					if (!inv) {
						plex x = a[i + j], y = a[i + j + k];
						a[i + j] = x + W[id][j] * y;
						a[i + j + k] = x - W[id][j] * y;
					} else {
						plex x = a[i + j], y = a[i + j + k];
						a[i + j] = x + conj(W[id][j]) * y;
						a[i + j + k] = x - conj(W[id][j]) * y;
					}
				}
			}
			roots.pop_back();
		}	
	}

	vector<plex> ffkek(const vector<plex> _a, int _n, plex e, bool inv) {
		n = _n;
		a = _a;
		int log = 31 - __builtin_clz(n);
		f(i, n) {
			if (i < rev(i, log)) {
				swap(a[i], a[rev(i, log)]);
			}
		}
		fft(e, inv);
		return a;
	}
}; 


plex fast_pow(plex x, ll p) {
	plex rez = 1;
	f(i, p) {
		rez *= x;
	}
	return rez;
}

inline vector<plex> mul(vector<plex> a, vector<plex> b) {
	int n = len(a) + len(b) + 1;
	while (__builtin_popcount(n) != 1) {
		n++;
	}
	a.resize(n);
	b.resize(n);

	plex e(cos(2 * M_PI / (ld)n), sin(2 * M_PI / (ld)n));

	a = UltraFast::ffkek(a, n, e, false);
	b = UltraFast::ffkek(b, n, e, false);

	f(i, n) {
		a[i] *= b[i];
	}

	a = UltraFast::ffkek(a, n, conj(e), true);

	f(i, n) {
		a[i] /= plex(n);
	}

	return a;
}

inline vector<ll> add(const vector<ll> &a, const vector<ll> &b) {
	vector<ll> rez(max(len(a), len(b)));
	for (int i = 0; i < len(a); i++) {
		rez[i] += a[i];
	}
	for (int i = 0; i < len(b); i++) {
		rez[i] += b[i];
	}
	while (!rez.empty() && rez.back() == 0) {
		rez.pop_back();
	}
	return rez;
}

void solve() {
	int n, m;
	vector<ll> a, b;
	scan n;
	a.resize(n);
	scan a;
	scan m;
	b.resize(m);
	scan b;

	vector<plex> A(a.begin(), a.end());
	vector<plex> B(b.begin(), b.end());

	vector<plex> C = mul(A, B);
	vector<ll> rez;
	for (plex p : C) {
		rez.pb(round(p.real()));
	}
	while (!rez.empty() && rez.back() == 0) {
		rez.pop_back();
	}
	print rez;
}

void near() {
	int n, x;
	scan n, x;
	vector<int> v(n);
	scan v;

	f(i, n) {
		if (v[i] < x) {
			v[i] = 1;
		} else {
			v[i] = 0;
		}
	}
	vector<int> pr(n + 1);
	for (int i = 1; i < n + 1; i++) {
		pr[i] = pr[i - 1] + v[i - 1];
	}
	

	vector<int> cnt(n + 1);
	f(i, n + 1) {
		cnt[pr[i]]++;
	}
	

	vector<int> rcnt = cnt;
	reverse(rcnt.begin(), rcnt.end());
	

	vector<plex> A = mul(
		vector<plex>(cnt.begin(), cnt.end()),
		vector<plex>(rcnt.begin(), rcnt.end())	
	);
	vector<ll> final;
	for (int i = 0; i < len(A); i++) {
		final.pb(round(A[i].real()));
	}
	reverse(final.begin(), final.end());
	f(i, n) {
		final.pop_back();
	}
	reverse(final.begin(), final.end());
	final[0] = (final[0] - n - 1) / 2;
	while (len(final) != n + 1) {
		final.pop_back();
	}
	print final;
}

signed main(signed argc, char *argv[]) {
	int P = 18;
	W.resize(P + 1);
	for (int i = 0; i < P + 1; i++) {
		int k = (1 << i);
		W[i].resize(k);
		for (int j = 0; j < k; j++) {
			W[i][j] = (plex(cos((2 * M_PI * (ld)j) / (ld)(2 * k)), sin((2 * M_PI * (ld)j) / (ld)(2 * k))));
		}
	}
	

	

	

	

	

	

	


	near();
}