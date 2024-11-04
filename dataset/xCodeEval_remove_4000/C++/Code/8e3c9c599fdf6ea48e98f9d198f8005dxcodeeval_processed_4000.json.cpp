
















































string buf = "";int bal = 0;for (char c : s) {\
if (c == '(' || c == '[' || c == '{') {bal++;\
} else if (c == ')' || c == ']' || c == '}') {\
bal--;} else {if (bal == 0) {if (c == ',') {\
deq.pb(buf);buf = "";} else {if (c != ' ') {\
buf += c;}}}}}if (!buf.empty()) {deq.pb(buf);}\
smart_io::id0();smart_io::_print(deq, args);}


smart_io::id0(); \
cout,




const int MAXMEM = 50000000;
char _memory[MAXMEM];
size_t _ptr = 0;
void* operator new(size_t _x) { _ptr += _x; assert(_ptr < MAXMEM); return _memory + _ptr - _x; }
void operator delete (void*) noexcept {}


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

	void id0() {
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

const int N = 5010;

int next[N][2];
int next2[N][2];
int cur[N][2];

int dp(int i, int k, bool pref, int sh) {
	if (k == 0) return cur[k][pref] = 0;
	if (i >= n) {
		if (k == 0) {
			return 0;
		} else {
			return -1;
		}
	}
	if (sh == 1) {
		assert(next[k][pref] != -2);
		return next[k][pref];
	} else if (sh == 2) {
		assert(next2[k][pref] != -2);
		return next2[k][pref];
	}
	int rez = -1;
	{
		int cur = 0;
		int h;
		if (i - 1 < 0) {
			h = -123;
		} else {
			h = v[i - 1];
		}
		if (pref) {
			

			h = min(h, v[i - 2] - 1);
		}
		cur += max(0, h - (v[i] - 1));
		if (i + 1 < n) {
			cur += max(0, v[i + 1] - (v[i] - 1));
		}
		if (dp(i + 2, k - 1, true, 2) != -1) {
			rez = cur + dp(i + 2, k - 1, true, 2);
		}
	}
	{
		if (dp(i + 1, k, false, 1) != -1) {
			if (rez == -1 || rez > dp(i + 1, k, false, 1)) {
				rez = dp(i + 1, k, false, 1);
			}
		}
	}
	return cur[k][pref] = rez;
}

signed main(signed argc, char *argv[]) {
	{
		

		

		

		f(i, N) {
			f(j, 2) {
				int v = -1;
				if (i == 0) {
					v = 0;
				}
				next[i][j] = v;
				next2[i][j] = v;
				cur[i][j] = v;
			}
		}
	}
	{
		scan n;
		v.resize(n);
		scan v;
	}
	{
		for (int i = n - 1; i > -1; i--) {

			int take = 0;
			{	
				int h;
				if (i - 1 < 0) {
					h = -123;
				} else {
					h = v[i - 1];
				}
				

					

					

				

				take += max(0, h - (v[i] - 1));
				if (i + 1 < n) {
					take += max(0, v[i + 1] - (v[i] - 1));
				}
			}
			int take_pref = 0;
			{	
				int h;
				if (i - 1 < 0) {
					h = -123;
				} else {
					h = v[i - 1];
				}
				if (i - 2 >= 0) {
					

					h = min(h, v[i - 2] - 1);
				}
				take_pref += max(0, h - (v[i] - 1));
				if (i + 1 < n) {
					take_pref += max(0, v[i + 1] - (v[i] - 1));
				}
			}
			

			

			

			


			for (int k = 0; k <= (n + 1) / 2; k++) {
				int lim = 2;
				if (i <= 1) {
					lim = 1;
				}
				for (int pref = 0; pref < lim; pref++) {
					if (k == 0) {
						cur[k][pref] = 0;
						continue;
					}
					int rez = -1;
					if (next2[k - 1][true] != -1) {
						int cur = next2[k - 1][true];
						if (pref) {
							cur += take_pref;
						} else {
							cur += take;
						}
						rez = cur;
					}
					if (next[k][false] != -1) {
						if (rez == -1 || rez > next[k][false]) {
							rez = next[k][false];
						}
					}
					cur[k][pref] = rez;
				}
			}
			memcpy(next2, next, sizeof next);
			memcpy(next, cur, sizeof cur);
			

		}
	}
	{
		for (int i = 1; i <= (n + 1) / 2; i++) {
			print cur[i][false];
			smart_io::print_start = " ";
		}
	}
}