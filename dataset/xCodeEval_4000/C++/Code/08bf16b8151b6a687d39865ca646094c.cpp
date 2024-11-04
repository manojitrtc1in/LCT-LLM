

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
void fast_print(const float &x) { printf("%.15f", x); }
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

namespace typedefs {
	typedef long long ll;
	typedef unsigned long long ull;
	typedef pair<int, int> pii;
	typedef double ld;
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

typedef vector<vector<ld>> Matrix;

int n, m, k;
vector<vector<int>> g;
vector<int> trap;
vector<int> ztraps;

int traps = 0;

Matrix gauss(Matrix M) {
	f(i, len(M[0])) {
		int unz = 0;
		f(j, len(M)) {
			if (abs(M[j][i]) > abs(M[unz][i])) {
				unz = j;
			}
		}
		if (M[unz][i] == 0) continue;
		ld cor = M[unz][i];
		f(j, len(M[0])) {
			M[unz][j] /= cor;
		}
		f(j, len(M)) {
			ld coef = M[j][i] / M[unz][i];
			f(k, len(M[0])) {
				M[j][k] -= coef * M[unz][k];
			}
		}
	}
	return M;
}

Matrix merge(Matrix A, Matrix B) {
	Matrix C(traps, vector<ld>(traps));
	f(st, traps) {
		f(inter, traps) {
			f(end, traps) {
				C[st][end] += A[st][inter] * B[inter][end];
			}
		}
	}
	return C;
}

vector<ld> operator*(vector<ld> v, ld d) {
	for (ld &x : v) {
		x *= d;
	}
	return v;
}

vector<ld> operator+(vector<ld> a, vector<ld> b) {
	assert(len(a) == len(b));
	f(i, len(b)) {
		a[i] += b[i];
	}
	return a;
}

vector<ld> operator-(vector<ld> a, vector<ld> b) {
	return a + (b * -1);
}

vector<vector<ld>> get_first() {
	Matrix prob(n, vector<ld>(n));
	for (int i = 0; i < n; i++) {
		if (trap[i]) {
			prob[i][i] = 1;
		} else {
			for (int j : g[i]) {
				prob[i][j] += 1.0 / len(g[i]);
			}
		}
	}
	Matrix R(n, vector<ld>(n));
	for (int i = 0; i < n; i++) {
		prob[i][i] -= 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (trap[j]) {
				R[i][j] = -prob[i][j];
				prob[i][j] = 0;
			}
		}	
	}
	

	

	

	for (int i = 0; i < n; i++) {
		if (trap[i]) continue;
		for (int j = i + 1; j < n; j++) {
			if (abs(prob[j][i]) > abs(prob[i][i])) {
				swap(prob[j], prob[i]);
				swap(R[j], R[i]);
			}
		}
		

			for (int j = i + 1; j < n; j++) {
				ld cor = prob[j][i] / prob[i][i];
				for (int k = 0; k < n; k++) {
					prob[j][k] -= cor * prob[i][k];
					R[j][k] -= cor * R[i][k];
				}
			}
		

	}
	Matrix final(n, vector<ld>(n));
	for (int i = n - 1; i > -1; i--) {
		if (trap[i]) continue;
		for (int j = 0; j < n; j++) {
			R[i][j] /= prob[i][i];
		}
		prob[i][i] = 1;
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < n; k++) {
				R[j][k] -= prob[j][i] * R[i][k];
			}
			prob[j][i] = 0;
		}
	}
	

	

	

	

	


	Matrix next(n, vector<ld>(n));
	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	for (int i = 0; i < n; i++) {
		if (trap[i]) {
			R[i] = vector<ld>(n, 0);
			R[i][i] = 1;
		}
		ld c = 1;
		for (int j = 0; j < n; j++) {
			c -= R[i][j];
		}
	}
	return R;
}

Matrix one;

Matrix fast_pow(int k) {
	if (k == 1) {
		if (!one.empty()) return one;
		Matrix F = get_first();	
		Matrix P(traps, vector<ld>(traps));
		f(i, traps) {
			f(j, traps) {
				for (int sub : g[ztraps[i]]) {
					P[i][j] += F[sub][ztraps[j]];
				}
				P[i][j] /= len(g[ztraps[i]]);
			}
		}
		return one = P;
	} else {
		if (k % 2 == 0) {
			Matrix x = fast_pow(k / 2);
			return merge(x, x);
		} else {
			Matrix x = fast_pow(k - 1);
			return merge(x, fast_pow(1));
		}
	}
}

signed main(signed argc, char *argv[]) {
	scan n, m, k;	
	trap.resize(n);
	g.resize(n);
	scan trap;
	f(i, n) {
		traps += trap[i];	
		if (trap[i]) {
			ztraps.pb(i);
		}
	}
	f(i, m) {
		int a, b;
		scan a, b;
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	if (k == 2) {
		Matrix F = get_first();
		print F[0][n - 1];
	} else {
		Matrix P = fast_pow(k - 2);
		Matrix F = get_first();
		ld rez = 0;
		f(i, traps) {
			rez += F[0][ztraps[i]] * P[i][traps - 1];
		}
		print rez;
	}
}
