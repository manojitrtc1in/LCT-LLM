
















































string buf = "";int bal = 0;for (char c : s) {\
if (c == '(' || c == '[' || c == '{') {bal++;\
} else if (c == ')' || c == ']' || c == '}') {\
bal--;} else {if (bal == 0) {if (c == ',') {\
deq.pb(buf);buf = "";} else {if (c != ' ') {\
buf += c;}}}}}if (!buf.empty()) {deq.pb(buf);}\
smart_io::id1();smart_io::_print(deq, args);}


smart_io::id1(); \
cout,




const int MAXMEM = 256000000;
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

const int N = 1e5 + 10;
namespace QQ {
	class Node {
	public:
		int value, prior, id0;
		int value_sum, size;
		Node *less = NULL, *greater = NULL;

		Node() {}
		Node(int _value, int _prior) {
			value = _value;
			prior = _prior;
			id0 = 1;
			size = 1;
			value_sum = value;
		}
	};

	typedef Node* node_ptr;


	class Treap {
	public:
		int get_tree_size(node_ptr tree) {
			if (tree) {
				return tree->size;
			}
			return 0;
		}

		int get_value_sum(node_ptr tree) {
			if (tree) {
				return tree->value_sum;
			}
			return 0;
		}


		void update_tree_size(node_ptr &node) {
			node->size = node->id0;
			if (node->less) {
				node->size += node->less->size; 
			}
			if (node->greater) {
				node->size += node->greater->size;
			}
		}


		void update_value_sum(node_ptr &node) {
			node->value_sum = node->value * node->id0;
			if (node->less) {
				node->value_sum += node->less->value_sum; 
			}
			if (node->greater) {
				node->value_sum += node->greater->value_sum;
			}
		}

		void update_meta(node_ptr &node) {
			if (!node) return;
			update_tree_size(node);
			update_value_sum(node);
		}


		void __split(node_ptr tree, int value, node_ptr &less, node_ptr &greater) {
			if (!tree) {
				less = NULL;
				greater = NULL;
			} else if (tree->value > value) {
				__split(tree->less, value, less, tree->less);
				greater = tree;
			} else {
				__split(tree->greater, value, tree->greater, greater);
				less = tree;
			}
			update_meta(tree);
		}


		void __insert(node_ptr &tree, node_ptr item) {
			if (!tree) {
				tree = item;
			} else if (tree->value == item->value) {
				tree->id0++;
			} else if (item->prior > tree->prior) {
				__split(tree, item->value, item->less, item->greater);
				tree = item;
			} else {
				if (item->value < tree->value) {
					__insert(tree->less, item);
				} else {
					__insert(tree->greater, item);
				}
			}
			update_meta(tree);
		}

		void merge(node_ptr &tree, node_ptr &less, node_ptr &greater) {
			if (!less || !greater) {
				if (less) {
					tree = less;
				} else {
					tree = greater;
				}
			} else if (less->prior > greater->prior) {
				merge(less->greater, less->greater, greater);
				tree = less;
			} else {
				merge(greater->less, less, greater->less);
				tree = greater;
			}
			update_meta(tree);
		}

		void __erase(node_ptr &tree, int value) {
			assert(tree);
			if (tree->value == value) {
				tree->id0--;
				if (tree->id0 == 0) {
					merge(tree, tree->less, tree->greater);
				}
			} else if (value > tree->value) {
				__erase(tree->greater, value);
			} else {
				__erase(tree->less, value);
			}
			update_meta(tree);
		}

		node_ptr root = NULL;

		Treap() {}


		void insert(int value) {
			__insert(root, new Node(value, rand()));
		}

		void erase(int value) {
			__erase(root, value);
		}

		int query(node_ptr tree, int max_size) {
			if (!tree) return 0;
			max_size = min(max_size, get_tree_size(tree));
			if (tree->size == max_size) {
				return tree->value_sum;
			}

			int r = query(tree->greater, max_size);
			max_size -= get_tree_size(tree->greater);
			if (max_size <= 0) {
				return r;
			}
			r += min(tree->id0, max_size) * tree->value;
			max_size -= min(tree->id0, max_size);
			if (max_size <= 0) {
				return r;
			}
			r += query(tree->less, max_size);
			return r;
		}

		int count_less_eq(node_ptr tree, int x) {
			if (!tree) return 0;
			if (tree->value <= x) {
				return get_tree_size(tree->less) + tree->id0 + count_less_eq(tree->greater, x);	
			} else {
				return count_less_eq(tree->less, x);
			}
		}

		int count_less_eq(int x) {
			return count_less_eq(root, x);
		}

		void query_get_rez(node_ptr tree, int max_size, vector<int> &rez) {
			if (!tree) return;
			query_get_rez(tree->greater, max_size, rez);
		}

		void print_tree(node_ptr tree) {
			if (!tree) {
				return;
			}
			printf("{%lld, %lld, %lld} ", tree->value, tree->id0, tree->size);
			

			printf("less->");
			print_tree(tree->less);
			printf("\n");
			printf("greater->");
			print_tree(tree->greater);
		}
	};
};


struct Node {
	int l = -1, r = -1;

	QQ::Treap network;
};

vector<Node> S;
int get() {
	S.pb(Node());
	return len(S) - 1;
}

int root = -1;

int init(int l, int r) {
	int i = get();
	if (l + 1 != r) {
		int mid = (l + r) / 2;
		S[i].l = init(l, mid);
		S[i].r = init(mid, r);
	}
	return i;
}

void inc_fast(int i, int tl, int tr, int x, int y) {
	S[i].network.insert(y);

	if (tl + 1 != tr) {
		int mid = (tl + tr) / 2;
		if (x < mid) {
			inc_fast(S[i].l, tl, mid, x, y);
		} else {
			inc_fast(S[i].r, mid, tr, x, y);
		}
	}
}

int get_fast(int i, int tl, int tr, pii cur, pii sub) {
	if (tr <= cur.first || cur.second <= tl) return 0;
	if (cur.first <= tl && tr <= cur.second) {
		int rez = S[i].network.count_less_eq(sub.second - 1);
		rez -= S[i].network.count_less_eq(sub.first - 1);
		return rez;
		

	}
	if (tl + 1 != tr) {
		int mid = (tl + tr) / 2;
		return get_fast(S[i].l, tl, mid, cur, sub) + get_fast(S[i].r, mid, tr, cur, sub);
	}
	return 0;
}

void inc(int x, int y, int d) {
	assert(d == 1);
	inc_fast(0, 0, N, x, y);
}

int get(int x, int y) {
	return get_fast(0, 0, N, mp(0, x + 1), mp(0, y + 1));
}







































int get(int dx, int dy, int upx, int upy) {
	return get_fast(0, 0, N, mp(dx, upx + 1), mp(dy, upy + 1));
}


vector<int> BAR(3);
vector<int> L(3, 1e9), R(3, -1e9);
vector<int> LL(3, 1), RR(3);

bool in(vector<int> L, vector<int> R, vector<int> p) {
	f(j, 3) {
		if (!(L[j] <= p[j] && p[j] <= R[j])) return false;
	}
	return true;
}

struct Event {
	int x;
	pii down, up;
	int id;
	int fac;

	Event() {}
	Event(int _x, pii _down, pii _up, int _id, int _fac) {
		x = _x;
		down = _down;
		up = _up;
		id = _id;
		fac = _fac;
	}
};

signed main(signed argc, char *argv[]) {
	root = init(0, N);

	scan BAR;

	int n, m, k;
	scan n, m, k;
	f(i, n) {
		vector<int> p(3);
		scan p;
		f(j, 3) {
			L[j] = min(L[j], p[j]);
			R[j] = max(R[j], p[j]);
		}
	}

	RR = BAR;

	vector<Event> qs;

	f(i, m) {
		vector<int> p(3);
		scan p;
		if (in(L, R, p)) {
			print "INCORRECT";
			return 0;
		}
		qs.emplace_back(p[0], mp(p[1], p[2]), mp(-1, -1), -1, -1);
	}

	vector<int> rez(k, 0);
	vector<vector<int>> all;

	f(i, k) {
		vector<int> p(3);
		scan p;
		all.pb(p);
		if (in(L, R, p)) continue;
		vector<int> down = p;
		vector<int> up = p;
		f(j, 3) {
			down[j] = min(down[j], L[j]);
			up[j] = max(up[j], R[j]);
		}
		down[0]--;
		qs.emplace_back(down[0], mp(down[1], down[2]), mp(up[1], up[2]), i, -1);
		qs.emplace_back(up[0], mp(down[1], down[2]), mp(up[1], up[2]), i, 1);
	}

	sort(qs.begin(), qs.end(), [](Event a, Event b) {
		if (a.x < b.x) return true;
		if (a.x > b.x) return false;
		return (a.id == -1) > (b.id == -1);
	});

	for (Event q : qs) {
		if (q.id == -1) {
			inc(q.down.x, q.down.y, 1);
		} else {
			int a = get(q.down.x, q.down.y, q.up.x, q.up.y);
			rez[q.id] += q.fac * a;
		}
	}
	print "CORRECT";
	f(i, k) {
		if (rez[i] > 0) {
			print "CLOSED";
		} else if (in(L, R, all[i])) {
			print "OPEN";
		} else {
			print "UNKNOWN";
		}
	}
}