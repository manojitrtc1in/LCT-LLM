
















































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

const int N = 2e5 + 10;
const int ONE = 450;
const ll MOD = 6e5 + 11;

int n, q;
int v[N];
ll delta[N];

int col = 0;

const int BLOCKS = 1000;

pii border[BLOCKS];
int hits[BLOCKS][ONE];
ll real[BLOCKS][ONE];
ll d[BLOCKS];

struct Cmp {
	bool operator()(const int &a, const int &b) {
		return delta[a] < delta[b];
	}
};

inline void init(const int &block, const int &l, const int &r) {
	border[block] = mp(l, r);
	for (int j = l; j < r; j++) {
		hits[block][j - l] = j; 
	}
	sort(hits[block], hits[block] + r - l, Cmp());
	for (int i = l; i < r; i++) {
		real[block][i - l] = delta[hits[block][i - l]];
	}
}

inline void recalc(const int &block, const int &p, const int &x) {
	int l = border[block].x;
	int r = border[block].y;
	

		

	

	

	delta[p] += x;
	for (int i = p + 1; i < r; i++) {
		delta[i] -= x;
	}
	

	

	

	vector<int> a;
	vector<int> b;
	int c = p;
	for (int i = l; i < r; i++) {	
		int j = hits[block][i - l];
		if (j > p) {
			a.pb(j);
		} else if (j < p) {
			b.pb(j);
		}
	}
	int it_a = 0;
	int it_b = 0;
	int it_c = 0;
	Cmp cmp;
	while (it_a < len(a) && it_b < len(b)) {
		if (cmp(a[it_a], b[it_b])) {
			hits[block][it_a + it_b] = a[it_a];
			it_a++;
		} else {
			hits[block][it_a + it_b] = b[it_b];
			it_b++;
		}
	}
	while (it_a < len(a)) {
		hits[block][it_a + it_b] = a[it_a];
		it_a++;
	}
	while (it_b < len(b)) {
		hits[block][it_a + it_b] = b[it_b];
		it_b++;
	}
	int in = r - l - 1;
	for (int i = 0; i < r - l - 1; i++) {
		if (cmp(p, hits[block][i])) {
			in = i;
			break;
		}
	}
	for (int i = r - l - 1; i > in; i--) {
		hits[block][i] = hits[block][i - 1];
	}
	hits[block][in] = p;
	for (int i = l; i < r; i++) {
		real[block][i - l] = delta[hits[block][i - l]];
	}
}

inline int kek(const int &block) {
	int l = border[block].x;
	int r = border[block].y;
	

	auto it = lower_bound(real[block], real[block] + r - l, -d[block]);
	if ((it == real[block] + r - l) || (*it != -d[block])) return -2;
	for (int i = l; i < r; i++) {
		if (delta[i] == -d[block]) {
			return i;
		}
	}
	col++;
	return -2;
}

inline void update(const int &block, const int &x) {
	d[block] -= x;
}

signed main(signed argc, char *argv[]) {
	{
		scan n, q;
		f(i, n) {
			scan v[i];
		}
	}
	{
		ll sm = 0;
		for (int i = 0; i < n; i++) {
			delta[i] = v[i] - sm;
			sm += v[i];
		}
	}
	int blocks = 0;
	{
		for (int i = 0; i < n; i += ONE) {
			init(blocks++, i, min(i + ONE, n));	
		}
	}
	{
		f(i, blocks) {
			recalc(i, border[i].x, 0);
		}
	}
	{
		int pref = -2;
		f(i, q) {
			int p, x;
			scan p, x;
			p--;
			int y = x - v[p];
			v[p] = x;

			for (int i = 0; i < blocks; i++) {
				if (border[i].x <= p && p < border[i].y) {
					recalc(i, p, y);
				} else if (border[i].x > p) {
					update(i, y);
				}
			}
			int king = -2;
			
			for (int i = 0; i < blocks; i++) {
				king = max(king, kek(i));
				if (king >= 0) break;
			}
			

				print king + 1;
			

		}
		assert(col < 2e5);
		

			

		

	}
}