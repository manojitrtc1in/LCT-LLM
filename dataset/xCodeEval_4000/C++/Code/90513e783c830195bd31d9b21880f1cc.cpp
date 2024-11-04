


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

#define mt make_tuple
#define x first
#define y second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define umap unordered_map
#define uset unordered_set
#define rt return 0;
#define elif else if
#define len(v) ((int)v.size())
#define plus jasdjalskdjl


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
void fast_print(const long long &x) { printf("%lld", x); }
void fast_print(const unsigned long long &x) { printf("%llu", x); }
void fast_print(const double &x) { printf("%.15lf", x); }
void fast_print(const long double &x) { printf("%.15Lf", x); }
void fast_print(const char &x) { printf("%c", x); };
void fast_print(const string &x) { printf("%s", x.c_str());}

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
		fast_print(" ");
		fast_print(v[i]);
	}
}

template <class T>
void fast_print(const vector<vector<T>> &v) {
	if (v.empty()) return;
	fast_print(v[0]);
	for (int i = 1; i < v.size(); i++) {
		fast_print("\n");
		fast_print(v[i]);
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

#define print    \
smart_io::precall_print(); \
cout,

#define scan cin,


vector<int> get_cock(int n) {
	vector<int> rez;
	for (int i = 0; i < n; i++) {
		rez.pb(i);
	}
	random_shuffle(rez.begin(), rez.end());
	return rez;
}

vector<pii> shs = {
	mp(1, 0),
	mp(0, 1),
	mp(0, -1),
	mp(-1, 0)
};

bool norm(int x, int y, int n, int m) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

vector<vector<int>> slow(vector<vector<int>> v) {
	int n = len(v);
	int m = len(v[0]);

	for (int test = 0; test < 10000; test++) {
		vector<vector<int>> sub = v;
		vector<int> all = get_cock(n * m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				sub[i][j] = all.back();
				all.pop_back();
			}
		}
		bool normal = true;
		vector<set<int>> neigh(n * m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (pii sh : shs) {
					pii t = mp(i + sh.x, j + sh.y);
					if (norm(t.x, t.y, n, m)) {
						neigh[v[i][j]].insert(v[t.x][t.y]);
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (pii sh : shs) {
					pii t = mp(i + sh.x, j + sh.y);
					if (norm(t.x, t.y, n, m)) {
						if (neigh[sub[i][j]].count(sub[t.x][t.y])) {
							normal = false;
						}
					}
				}
			}
		}
		if (normal) return sub;
	}

	return {};
}

vector<vector<int>> plus(vector<vector<int>> v) {
	for (int i = 0; i < len(v); i++) {
		for (int j = 0; j < len(v[i]); j++) {
			v[i][j]++;
		}
	}
	return v;
}

vector<vector<int>> trans(vector<vector<int>> v, bool tr) {
	if (v.empty()) return v;
	if (tr) {
		int n = len(v);
		int m = len(v[0]);
		vector<vector<int>> rez(m, vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				rez[j][i] = v[i][j];
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int x = (rez[i][j] - 1) / m;
				int y = (rez[i][j] - 1) % m;
				rez[i][j] = y * n + x + 1;
			}
		}
		return rez;
	}
	return v;
}

void fuck(vector<vector<int>> v) {
	if (v.empty()) {
		print "NO";
	} else {
		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		print "YES";
		print v;
	}
}

signed main(signed argc, char *argv[]) {
	srand(time(NULL));
	int n, m;
	scan n, m;
	bool sw = (n > m);
	if (sw) {
		swap(n, m);
	}


	vector<vector<int>> v(n, vector<int>(m));
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			v[i][j] = cnt++;
		}
	}


	if (n == 1) {
		if (m <= 17) {
			fuck(trans(plus(slow(v)), sw));
		} else {
			for (int t = 0; t < 2; t++) {
				int x = (m & 1) ? v[0][m - 1] : v[0][m - 2];
				for (int i = 0; i < len(v[0]); i += 2) {
					int y = v[0][i];
					v[0][i] = x;
					x = y;
				}
			}
			fuck(trans(plus(v), sw));
		}
	} else if (n == 2) {
		if (m <= 17) {
			fuck(trans(plus(slow(v)), sw));
		} else {
			for (int t = 0; t < 2; t++) {
				int x = (m & 1) ? v[0][m - 1] : v[0][m - 2];
				for (int i = 0; i < len(v[0]); i += 2) {
					int y = v[0][i];
					v[0][i] = x;
					x = y;
				}
			}

			for (int t = 0; t < 2; t++) {
				int x = (m & 1) ? v[1][m - 2] : v[1][m - 1];
				for (int i = 1; i < m; i += 2) {
					int y = v[1][i];
					v[1][i] = x;
					x = y;
				}
			}

			fuck(trans(plus(v), sw));
		}
	} else if (n == 3 && false) {
		if (m <= 17) {
			fuck(trans(plus(slow(v)), sw));
		} else {
			for (int t = 0; t < 2; t++) {
				int x = v[0][len(v[0]) - 2];
				for (int i = 0; i < len(v[0]); i += 2) {
					int y = v[0][i];
					v[0][i] = x;
					x = y;
				}
			}

			for (int t = 0; t < 2; t++) {
				int x = v[1][m - 1];
				for (int i = 1; i < m; i += 2) {
					int y = v[1][i];
					v[1][i] = x;
					x = y;
				}
			}

			for (int t = 0; t < 2; t++) {
				int x = v[2][len(v[2]) - 2];
				for (int i = 0; i < len(v[2]); i += 2) {
					int y = v[2][i];
					v[2][i] = x;
					x = y;
				}
			}

			fuck(trans(plus(v), sw));
		}
	} else {
		if (n * m <= 30) {
			fuck(trans(plus(slow(v)), sw));
		} else {
			for (int row = 0; row < n; row++) {
				int p;
				if (row & 1) {
					p = 1;
				} else {
					p = 0;
				}
				for (int t = 0; t < 2; t++) {
					int x = v[row][m - 1 - (p ^ (m % 2) ^ 1)];
					for (int i = p; i < m; i += 2) {
						int y = v[row][i];
						v[row][i] = x;
						x = y;
					}
				}
			}
			fuck(trans(plus(v), sw));
		}
	}
}