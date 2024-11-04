
















































string buf = "";int bal = 0;for (char c : s) {\
if (c == '(' || c == '[' || c == '{') {bal++;\
} else if (c == ')' || c == ']' || c == '}') {\
bal--;} else {if (bal == 0) {if (c == ',') {\
deq.pb(buf);buf = "";} else {if (c != ' ') {\
buf += c;}}}}}if (!buf.empty()) {deq.pb(buf);}\
smart_io::id1();smart_io::_print(deq, args);}


smart_io::id1(); \
cout,




const int MAXMEM = 200 * 1000 * 1024;
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

	void id1() {
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


const ll MOD = 1e9 + 7;

template<class Value, class Mod, class Magic, class ApplyMod, class MergeMods>
struct TreeSegment {
	struct Node {
		bool have_mod = false;
		Value value;
		Mod mod;
	};	

	Magic magic;
	ApplyMod apply_mod;
	MergeMods merge_mods;

	

	Node *S;
	int n;

	bool __intersects(const int &tl, const int &tr, const int &ql, const int &qr) {
		return !(tr <= ql || qr <= tl);
	}

	Value __get_value(const int &i, const int &tl, const int &tr) {
		if (!S[i].have_mod) return S[i].value;
		return apply_mod(S[i].value, S[i].mod, tl, tr);
	}

	void __recalc_value(const int &i, const int &tl, const int &tr) {
		if (tl + 1 != tr) {
			int mid = (tl + tr) / 2;
			S[i].value = magic(
				__get_value(i + 1, tl, mid),
				__get_value(i + (mid - tl) * 2, mid, tr)
			);
		}
	}

	void __add_mod(const int &i, const int &tl, const int &tr, const Mod &sub) {
		if (S[i].have_mod) {
			S[i].mod = merge_mods(S[i].mod, sub, tl, tr);
		} else {
			S[i].mod = sub;
			S[i].have_mod = true;
		}
	}

	void __push(const int &i, const int &tl, const int &tr) {
		if (S[i].have_mod) {
			S[i].value = apply_mod(S[i].value, S[i].mod, tl, tr);
			if (tl + 1 != tr) {
				int mid = (tl + tr) / 2;
				__add_mod(i + 1, tl, mid, S[i].mod);
				__add_mod(i + (mid - tl) * 2, mid, tr, S[i].mod);
			}
			S[i].have_mod = false;
		}
	}

	void init(const int &i, const int &tl, const int &tr, const vector<Value> &src) {
		if (tl + 1 == tr) {
			S[i].value = src[tl];
		} else {
			int mid = (tl + tr) / 2;
			init(i + 1, tl, mid, src);
			init(i + (mid - tl) * 2, mid, tr, src);
			__recalc_value(i, tl, tr);
		}
	}

	Value __query(const int &i, const int &tl, const int &tr,
			const int &ql, const int &qr) {
		__push(i, tl, tr);
		if (ql <= tl && tr <= qr) {
			return S[i].value;
		} else {
			int mid = (tl + tr) / 2;
			if (__intersects(tl, mid, ql, qr) && __intersects(mid, tr, ql, qr)) {
				return magic(
					__query(i + 1, tl, mid, ql, qr),
					__query(i + (mid - tl) * 2, mid, tr, ql, qr)
				);
			} else if (__intersects(tl, mid, ql, qr)) {
				return __query(i + 1, tl, mid, ql, qr);
			} else {
				return __query(i + (mid - tl) * 2, mid, tr, ql, qr);
			}
		}
	}

	void __change(const int &i, const int &tl, const int &tr,
			const int &j, const Value &_new) {
		__push(i, tl, tr);
		if (tl + 1 == tr) {
			S[i].value = _new;
		} else {
			int m = (tl + tr) / 2;
			if (j < m) {
				__change(S[i].l, tl, m, j, _new);
			} else {
				__change(S[i].r, m, tr, j, _new);
			}
			__recalc_value(i, tl, tr);
		}
	}

	void __update(const int &i, const int &tl, const int &tr,
			const int &ql, const int &qr, const Mod &mod) {
		__push(i, tl, tr);
		if (ql <= tl && tr <= qr) {
			__add_mod(i, tl, tr, mod);
		} else {
			int mid = (tl + tr) / 2;
			if (__intersects(tl, mid, ql, qr)) {
				__update(i + 1, tl, mid, ql, qr, mod);	
			}
			if (__intersects(mid, tr, ql, qr)) {
				__update(i + (mid - tl) * 2, mid, tr, ql, qr, mod);
			}
			__recalc_value(i, tl, tr);
		}
	}

	template<class Check>
	pair<int, Value> id0(const int &i, const int &tl, const int &tr,
			const int &L, const Check &checker, const Value &pref) {
		__push(i, tl, tr);
		if (tr <= L) return mp(-1, pref);
		if (tl + 1 == tr) {
			Value _this = magic(pref, __get_value(i, tl, tr));
			if (checker(_this)) {
				return mp(tl, _this);
			} else {
				return mp(-1, _this);
			}
		} else {
			int mid = (tl + tr) / 2;
			if (L <= tl) {
				Value _left = magic(pref, __get_value(i + 1, tl, mid));
				if (checker(_left)) {
					return id0(i + 1, tl, mid, L, checker, pref);
				} else {
					return id0(i + (mid - tl) * 2, mid, tr, L, checker, _left);
				}
			} else {
				auto t = id0(i + 1, tl, mid, L, checker, pref);
				if (t.first != -1) return t;
				return id0(i + (mid - tl) * 2, mid, tr, L, checker, t.second);
			}	
		}
	}

	template<class Check>
	pair<int, Value> id3(const int &i, const int &tl, const int &tr,
			const int &R, const Check &checker, const Value &pref) {
		__push(i, tl, tr);
		if (R < tl) return mp(-1, pref);
		if (tl + 1 == tr) {
			Value _this = magic(pref, __get_value(i, tl, tr));
			if (checker(_this)) {
				return mp(tl, _this);
			} else {
				return mp(-1, _this);
			}
		} else {
			int mid = (tl + tr) / 2;
			if (tr <= R + 1) {
				Value _right = magic(pref, __get_value(S[i].r, mid, tr));
				if (checker(_right)) {
					return id3(S[i].r, mid, tr, R, checker, pref);
				} else {
					return id3(S[i].l, tl, mid, R, checker, _right);
				}
			} else {
				auto t = id3(S[i].r, mid, tr, R, checker, pref);
				if (t.first != -1) return t;
				return id3(S[i].l, tl, mid, R, checker, t.second);
			}	
		}
	}

	void init(const vector<Value> &src) {
		n = len(src);
		S = new Node[2 * n + 1];
		init(0, 0, len(src), src);
	}
	
	TreeSegment(const int &n, const Value &def,
			Magic _magic, ApplyMod _apply_mod, MergeMods id2, Mod)
			: magic(_magic), apply_mod(_apply_mod), merge_mods(id2) {
		init(vector<Value>(n, def));
	}

	TreeSegment(const vector<Value> &def,
			Magic _magic, ApplyMod _apply_mod, MergeMods id2, Mod) 
			: magic(_magic), apply_mod(_apply_mod), merge_mods(id2) {
		init(def);
	}

	Value query(const int &ql, const int &qr) {
		assert(ql < qr);
		return __query(0, 0, n, ql, qr);
	}

	void change(const int &i, const Value &value) {
		assert(0 <= i && i < n);
		__change(0, 0, n, i, value);
	}

	void update(const int &ql, const int &qr, const Mod &mod) {
		__update(0, 0, n, ql, qr, mod);
	}
	
	template<class Check>
	int find_right(const int &L, const Check &checker, const Value &start) {
		if (checker(start)) return L - 1;
		int rez = id0(0, 0, n, L, checker, start).first;
		return (rez == -1) ? n : rez;
	}

	template<class Check>
	int find_left(const int &R, const Check &checker, const Value &start) {
		if (checker(start)) return R + 1;
		int rez = id3(0, 0, n, R, checker, start).first;
		return (rez == -1) ? -1 : rez;
	}
};


int n, q;
vector<int> pos;
vector<int> w;

signed main(signed argc, char *argv[]) {
	scan n, q;
	pos.resize(n);
	w.resize(n);
	scan pos, w;

	TreeSegment ts(w, [](int a, int b) {
		return a + b;
	}, [](int value, int mod, int, int) {
		return mod;
	}, [](int old, int _new, int, int) {
		return _new;
	}, 1337LL);

	vector<int> subw(n);
	for (int i = 0; i < n; i++) {
		subw[i] = (w[i] * (i - pos[i])) % MOD;
	}

	TreeSegment resp(subw, [](int a, int b) {
		return (a + b) % MOD;
	}, [](int value, int mod, int, int) {
		return mod;
	}, [](int old, int _new, int, int) {
		return _new;
	}, 1337LL);

	f(i, q) {
		int x, y;
		scan x, y;
		if (x < 0) {
			int ind = -x;
			int _new = y;
			ind--;
			ts.update(ind, ind + 1, _new);
			resp.update(ind, ind + 1, (_new * (ind - pos[ind])) % MOD);
		} else {
			int l = x, r = y;
			l--;

			int sm = ts.query(l, r);

			int bestL = ts.find_right(l, [sm](int x) {
				return x * 2 >= sm;
			}, 0);

			int x = pos[bestL] - bestL + l;

			int left = 0;
			if (l < bestL) {
				left = resp.query(l, bestL) + ts.query(l, bestL) * (x - l);
			}
			int right = 0;
			if (bestL < r) {
				right = resp.query(bestL, r) + ts.query(bestL, r) * (x - l);
			}
			if (l == 2 && r == 5) {
				

			}
			print floor_mod(left - right, MOD);
		}
	}
}