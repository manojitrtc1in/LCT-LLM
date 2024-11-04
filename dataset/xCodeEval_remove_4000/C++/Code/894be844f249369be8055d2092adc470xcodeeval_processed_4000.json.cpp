




















































smart_io::id5(); \
cout,




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

	void id5() {
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

namespace UltraFast {
	vector<vector<plex>> W;

	int id0(int N) {
		return 31 - __builtin_clz(N);
	}

	void id4(int N) {
		int n = id0(N);
		while (len(W) < n) {
			int layer_log = len(W);
			int k = (1 << layer_log);		
			W.pb(vector<plex>());
			W.back().resize(k);
			for (int j = 0; j < k; j++) {
				W.back()[j] = (plex(cos((2 * M_PI * (ld)j) / (ld)(2 * k)), sin((2 * M_PI * (ld)j) / (ld)(2 * k))));
			}
		}
	}

	void __fft(plex *a, int N, plex e, bool inv) {
		for (int k = 1, id = 0; k < N; k *= 2, id++) {
			for (int i = 0; i < N; i += k * 2) {
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
		}	
	}

	template <class T>
	void id2(T *a, int N) {
		int id3 = (N >> 1), r = 0;
		for (int x = 1; x < N; ++ x) {
			int h = id3;
			while (((r ^= h) & h) == 0) h >>= 1;
			if (r > x) swap(a[x], a[r]);
		}
	}

	void id1(plex *a, int N, bool inv) {
		id2(a, N);
		id4(N);
		plex e(cos(2.0 * M_PI / (ld)N), sin(2.0 * M_PI / (ld)N));
		if (inv) e = conj(e);
		__fft(a, N, e, inv);
	}
}; 


void transform(plex *a, int N) {
	plex div_x = plex(0, 1) * (4.0 * N);
	for (int i = 0; i < N / 2; i++) {
		int j = (N - i) % N;
		a[i] = (a[i] + conj(a[j])) * (a[i] - conj(a[j])) / div_x;
	}
	for (int i = N - 1; i > N / 2; i--) {
		a[i] = conj(a[N - i]);
	}
	a[N / 2] = (a[N / 2] + conj(a[N / 2])) * (a[N / 2] - conj(a[N / 2])) / div_x;
}



inline vector<ll> mul(vector<ll> a, vector<ll> b) {
	int n = len(a) + len(b) + 1;
	while (__builtin_popcount(n) != 1) {
		n++;
	}
	a.resize(n);
	b.resize(n);

	plex e(cos(2 * M_PI / (ld)n), sin(2 * M_PI / (ld)n));

	vector<plex> mvp(n);
	f(i, n) {
		mvp[i] = plex(a[i], b[i]);
	}

	UltraFast::id1(mvp.data(), n, false);
	transform(mvp.data(), n);
	UltraFast::id1(mvp.data(), n, true);


	vector<ll> final(n);
	f(i, n) {
		final[i] = round(real(mvp[i]));	
	}

	return final;
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

	vector<ll> rez = mul(a, b);

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
	

	vector<ll> cnt(n + 1);
	f(i, n + 1) {
		cnt[pr[i]]++;
	}
	

	vector<ll> rcnt = cnt;
	reverse(rcnt.begin(), rcnt.end());
	

	vector<ll> A = mul(
		cnt,
		rcnt
	);
	vector<ll> final = A;
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
	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	near();
	

}