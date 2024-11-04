


















































string buf = "";int bal = 0;for (char c : s) {\
if (c == '(' || c == '[' || c == '{') {bal++;\
} else if (c == ')' || c == ']' || c == '}') {\
bal--;} else {if (bal == 0) {if (c == ',') {\
deq.pb(buf);buf = "";} else {if (c != ' ') {\
buf += c;}}}}}if (!buf.empty()) {deq.pb(buf);}\
smart_io::id0();smart_io::_print(deq, args);}

inline int min(const int &x, const int &y) { return (((y-x)>>(32-1))&(x^y))^x; }
inline int max(const int &x, const int &y) { return (((y-x)>>(32-1))&(x^y))^y; }
inline long long min(const long long &x, const long long &y) { return (((y-x)>>(64-1))&(x^y))^x; }
inline long long max(const long long &x, const long long &y) { return (((y-x)>>(64-1))&(x^y))^y; }


smart_io::id0(); \
cout,




const int MAXMEM = 200 * 1000 * 1024;
char _memory[MAXMEM];
size_t _ptr = 0;
void* operator new(size_t _x) { _ptr += _x; assert(_ptr < MAXMEM); return _memory + _ptr - _x; }
void operator delete (void*) noexcept {}


using namespace std;

char string_in_buffer[(int)2e6];


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
	
	void id0() {
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

const int AL = 26;
const int SYM = 'a';
struct SA {
	vector<int> sf;
	vector<array<int, AL>> go;
	vector<int> len;
	vector<bool> hit;
	vector<ll> ends;
	vector<bool> used;
	vector<vector<pair<int, ll>>> bells;
	int newn() {
		sf.push_back(-1);
		go.emplace_back(array<int, AL>());
		go.back().fill(-1);
		len.push_back(0);
		hit.push_back(false);
		used.push_back(false);
		ends.emplace_back(0);
		bells.pb({});
		return sf.size() - 1;
	}
	SA() {
		newn();
	}
	void upload_string(string s) {
		int cur = 0;
		for (int i = 0; i < s.size(); ++i) {
			int pos = cur;
			int c = s[i] - SYM;
			int nw = newn();
			len[nw] = i + 1;
			while (cur != -1 && go[cur][c] == -1)
				go[cur][c] = nw, cur = sf[cur];
			if (cur == -1)
				sf[nw] = 0;
			else {
				int q = go[cur][c];
				if (len[q] == len[cur] + 1)
					sf[nw] = q;
				else {
					int cl = len.size();
					len.push_back(len[cur] + 1);
					go.push_back(go[q]);
					sf.push_back(sf[q]);
					hit.push_back(false);
					used.push_back(false);
					ends.emplace_back(0);
					bells.pb({});
					sf[q] = sf[nw] = cl;
					while (cur != -1 && go[cur][c] == q)
						go[cur][c] = cl, cur = sf[cur];
				}
			}
			cur = go[pos][c];
		}
	}
	void Belfast(int i, int id) {
		used[i] = true;
		for (int c = 0; c < AL; c++) {
			if (go[i][c] != -1 && hit[go[i][c]]) {
				if (!used[go[i][c]])
					Belfast(go[i][c], id);
				ends[i] += ends[go[i][c]];
			}
		}
		bells[i].emplace_back(id, ends[i]);
	}
	void clear_work(int i) {
		hit[i] = false;
		ends[i] = 0;
		used[i] = false;

		for (int c = 0; c < AL; c++) {
			if (go[i][c] != -1 && hit[go[i][c]]) {
				if (used[go[i][c]])
					clear_work(go[i][c]);
			}
		}	
	}
	void examine(string s, int id) {
		int cur = 0;
		for (int i = 0; i < len(s); i++) {
			int c = s[i] - SYM;
			cur = go[cur][c];
			int sub = cur;
			while (sub != -1 && !hit[sub]) {
				hit[sub] = true;
				sub = sf[sub];
			}
		}
		while (cur != -1) {
			ends[cur]++;
			cur = sf[cur];
		}
		Belfast(0, id);
		clear_work(0);
	}
};
signed main(signed argc, char *argv[]) {
	string s;
	scan s;
	int m;
	scan m;
	vector<string> v(m);
	scan v;
	SA sat;
	sat.upload_string(s);
	for (string t : v)
		sat.upload_string(t);
	for (int i = 0; i < m; i++)
		sat.examine(v[i], i);
	vector<int> nodes;
	{
		int cur = 0;
		for (int i = 0; i < len(s); i++) {
			int c = s[i] - SYM;
			cur = sat.go[cur][c];
			nodes.pb(cur);
		}
	}
	int q;
	scan q;
	f(i, q) {
		int l, r, pl, pr;
		scan l, r, pl, pr;
		l--, pl--;
		swap(l, pl);
		swap(r, pr);
		int cur = nodes[r - 1];
		while (sat.len[sat.sf[cur]] >= r - l) {
			cur = sat.sf[cur];
		}	
		pair<ll, int> rez = mp(0, pl);
		for (auto p : sat.bells[cur])
			if (pl <= p.x && p.x < pr) 
				if (rez.x < p.y) 
					rez = mp(p.y, p.x);
		print rez.y + 1, rez.x;
	}
}
