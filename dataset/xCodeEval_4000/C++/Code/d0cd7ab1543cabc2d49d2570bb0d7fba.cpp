
#define aimbot
#define fast_allocator
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

mt19937 gen(1337);

vector<int> rez;

namespace Flex {
	struct Node {
		Node *l = NULL, *r = NULL;
		int prior = 0;
		int value = 0;
		int count = 0;
		int mod = 0;
		int mod_value = 0;

		vector<int> values;

		Node(int _value, int _id) {
			value = _value;
			values.emplace_back(_id);
			prior = gen();
		}
	};

	pair<Node*, Node*> split(Node *node, int L);

	void push(Node *node);

	Node *interfere(Node *a, Node *b) {
		if (!a) return b;
		if (!b) return a;

		push(a);
		push(b);

		if (a->prior < b->prior) {
			swap(a, b);
		}

		auto t = split(b, a->value);
		auto t2 = split(t.second, a->value + 1);

		if (t2.first) {
			if (len(t2.first->values) > len(a->values)) {
				swap(a->values, t2.first->values);
				swap(a->count, t2.first->count);
			}
			for (int x : t2.first->values) {
				rez[x] += t2.first->count - a->count;
				a->values.pb(x);
			}
		}

		a->l = interfere(a->l, t.first);
		a->r = interfere(a->r, t2.second);

		return a;
	}

	void push(Node *node) {
		if (!node) return;

		node->value += node->mod_value;
		if (node->l) {
			node->l->mod_value += node->mod_value;
		}
		if (node->r) {
			node->r->mod_value += node->mod_value;
		}
		node->mod_value = 0;

		node->count += node->mod;
		if (node->l) {
			node->l->mod += node->mod;
		}
		if (node->r) {
			node->r->mod += node->mod;	
		}
		node->mod = 0;
	}

	Node *merge(Node *l, Node *r) {
		if (!l) return r;
		if (!r) return l;
		push(l);
		push(r);
		if (l->prior > r->prior) {
			l->r = merge(l->r, r);
			return l;
		} else {
			r->l = merge(l, r->l);
			return r;
		}
	}

	pair<Node*, Node*> split(Node *node, int L) {
		if (!node) return mp(node, node);
		push(node);
		if (node->value >= L) {
			auto t = split(node->l, L);
			node->l = NULL;
			return mp(t.first, merge(t.second, node));
		} else {
			auto t = split(node->r, L);
			node->r = NULL;
			return mp(merge(node, t.first), t.second);
		}
	}

	pair<Node*, Node*> cut_segment(Node *node, int l, int r) {
		if (!node) return mp(node, node);
		push(node);
		auto t = split(node, l);
		auto t2 = split(t.second, r);
		return mp(merge(t.first, t2.second), t2.first);
	}

	Node *find(Node *node, int value) {
		if (!node) return node;
		push(node);
		if (node->value == value) return node;
		if (value > node->value) {
			return find(node->r, value);
		} else {
			return find(node->l, value);
		}
	}

	void extract(Node *node, vector<Node*> &all) {
		if (!node) return;
		push(node);
		extract(node->l, all);
		all.pb(node);
		extract(node->r, all);
	}
};

using namespace Flex;

signed main(signed argc, char *argv[]) {
	int n;
	scan n;
	vector<pii> v;
	f(i, n) {
		pii p;
		scan p;
		v.emplace_back(-p.y, p.x);
	}
	sort(v.begin(), v.end());

	Node *root = NULL;

	int k;
	scan k;
	rez.resize(k);
	vector<pii> qs;	
	f(i, k) {
		int b;
		scan b;
		qs.emplace_back(b, i);
		

	}
	sort(qs.begin(), qs.end());
	for (int i = 0; i < len(qs); i++) {
		if (i > 0 && qs[i - 1].first == qs[i].first) {
			find(root, qs[i].first)->values.pb(qs[i].second);
		} else {
			root = merge(root, new Node(qs[i].first, qs[i].second));
		}
	}
	for (pii p : v) {
		auto t = split(root, p.second);
		if (t.second) {
			t.second->mod++;
			t.second->mod_value -= p.second;
		}
		root = interfere(t.first, t.second);
	}
	vector<Node*> all;
	extract(root, all);
	for (Node *node : all) {
		for (int x : node->values) {
			rez[x] += node->count;
		}
	}
	print rez;
}
