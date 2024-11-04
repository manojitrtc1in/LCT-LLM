#ifndef HIDDEN_IN_VISUAL_STUDIO 




#define _CRT_SECURE_NO_WARNINGS



#include <bits/stdc++.h>
using namespace std;



using ll = long long; 

using pii = pair<int, int>;	using pll = pair<ll, ll>;	using pil = pair<int, ll>;	using pli = pair<ll, int>;
using vi = vector<int>;		using vvi = vector<vi>;		using vvvi = vector<vvi>;
using vl = vector<ll>;		using vvl = vector<vl>;		using vvvl = vector<vvl>;
using vb = vector<bool>;	using vvb = vector<vb>;		using vvvb = vector<vvb>;
using vc = vector<char>;	using vvc = vector<vc>;		using vvvc = vector<vvc>;
using vd = vector<double>;	using vvd = vector<vd>;		using vvvd = vector<vvd>;
template <class T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
using Graph = vvi;



const double PI = 3.14159265359;
const double DEG = PI / 180.; 

const vi dx4 = { 1, 0, -1, 0 }; 

const vi dy4 = { 0, 1, 0, -1 };
const vi dx8 = { 1, 1, 0, -1, -1, -1, 0, 1 }; 

const vi dy8 = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int INF = 1001001001; const ll INFL = 4004004004004004004LL;
const double EPS = 1e-10; 




struct fast_io { fast_io() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); } } fastIOtmp;



#define all(a) (a).begin(), (a).end()
#define sz(x) ((int)(x).size())
#define distance (int)distance
#define Yes(b) {cout << ((b) ? "Yes" : "No") << endl;}
#define rep(i, n) for(int i = 0, i##_len = int(n); i < i##_len; ++i) 

#define repi(i, s, t) for(int i = int(s), i##_end = int(t); i <= i##_end; ++i) 

#define repir(i, s, t) for(int i = int(s), i##_end = int(t); i >= i##_end; --i) 

#define repe(v, a) for(const auto& v : (a)) 

#define repea(v, a) for(auto& v : (a)) 

#define repb(set, d) for(int set = 0; set < (1 << int(d)); ++set) 

#define repp(a) sort(all(a)); for(bool a##_perm = true; a##_perm; a##_perm = next_permutation(all(a))) 

#define repit(it, a) for(auto it = (a).begin(); it != (a).end(); ++it) 

#define repitr(it, a) for(auto it = (a).rbegin(); it != (a).rend(); ++it) 

#define smod(n, m) ((((n) % (m)) + (m)) % (m)) 

#define uniq(a) {sort(all(a)); (a).erase(unique(all(a)), (a).end());} 




template <class T> inline ll pow(T n, int k) { ll v = 1; rep(i, k) v *= n; return v; }
template <class T> inline bool chmax(T& M, const T& x) { if (M < x) { M = x; return true; } return false; } 

template <class T> inline bool chmin(T& m, const T& x) { if (m > x) { m = x; return true; } return false; } 




template <class T, class U> inline istream& operator>> (istream& is, pair<T, U>& p) { is >> p.first >> p.second; return is; }
template <class T, class U> inline ostream& operator<< (ostream& os, const pair<T, U>& p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template <class T, class U, class V> inline istream& operator>> (istream& is, tuple<T, U, V>& t) { is >> get<0>(t) >> get<1>(t) >> get<2>(t); return is; }
template <class T, class U, class V> inline ostream& operator<< (ostream& os, const tuple<T, U, V>& t) { os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ")"; return os; }
template <class T, class U, class V, class W> inline istream& operator>> (istream& is, tuple<T, U, V, W>& t) { is >> get<0>(t) >> get<1>(t) >> get<2>(t) >> get<3>(t); return is; }
template <class T, class U, class V, class W> inline ostream& operator<< (ostream& os, const tuple<T, U, V, W>& t) { os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << "," << get<3>(t) << ")"; return os; }
template <class T> inline istream& operator>> (istream& is, vector<T>& v) { repea(x, v) is >> x; return is; }
template <class T> inline ostream& operator<< (ostream& os, const vector<T>& v) { repe(x, v) os << x << " "; return os; }
template <class T> inline ostream& operator<< (ostream& os, const set<T>& s) { repe(x, s) os << x << " "; return os; }
template <class T> inline ostream& operator<< (ostream& os, const unordered_set<T>& s) { repe(x, s) os << x << " "; return os; }
template <class T, class U> inline ostream& operator<< (ostream& os, const map<T, U>& m) { repe(p, m) os << p << " "; return os; }
template <class T, class U> inline ostream& operator<< (ostream& os, const unordered_map<T, U>& m) { repe(p, m) os << p << " "; return os; }
template <class T> inline ostream& operator<< (ostream& os, stack<T> s) { while (!s.empty()) { os << s.top() << " "; s.pop(); } return os; }
template <class T> inline ostream& operator<< (ostream& os, queue<T> q) { while (!q.empty()) { os << q.front() << " "; q.pop(); } return os; }
template <class T> inline ostream& operator<< (ostream& os, deque<T> q) { while (!q.empty()) { os << q.front() << " "; q.pop_front(); } return os; }
template <class T> inline ostream& operator<< (ostream& os, priority_queue<T> q) { while (!q.empty()) { os << q.top() << " "; q.pop(); } return os; }
template <class T> inline ostream& operator<< (ostream& os, priority_queue_rev<T> q) { while (!q.empty()) { os << q.top() << " "; q.pop(); } return os; }



#ifdef _MSC_VER
#define popcount (int)__popcnt 

#define popcountll (int)__popcnt64
inline int lsb(unsigned int n) { unsigned long i; _BitScanForward(&i, n); return i; } 

inline int lsbll(unsigned long long n) { unsigned long i; _BitScanForward64(&i, n); return i; }
inline int msb(unsigned int n) { unsigned long i; _BitScanReverse(&i, n); return i; } 

inline int msbll(unsigned long long n) { unsigned long i; _BitScanReverse64(&i, n); return i; }
template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
#define dump(x) cout << "\033[1;36m" << (x) << "\033[0m" << endl;
#define dumps(x) cout << "\033[1;36m" << (x) << "\033[0m ";
#define dumpel(a) { int i = 0; cout << "\033[1;36m"; repe(x, a) {cout << i++ << ": " << x << endl;} cout << "\033[0m"; }
#define input_from_file(f) ifstream isTMP(f); cin.rdbuf(isTMP.rdbuf());
#define output_to_file(f) ofstream osTMP(f); cout.rdbuf(osTMP.rdbuf());


#else
#define popcount (int)__builtin_popcount
#define popcountll (int)__builtin_popcountll
#define lsb __builtin_ctz
#define lsbll __builtin_ctzll
#define msb(n) (31 - __builtin_clz(n))
#define msbll(n) (63 - __builtin_clzll(n))
#define gcd __gcd
#define dump(x)
#define dumps(x)
#define dumpel(v)
#define input_from_file(f)
#define output_to_file(f)
#endif

#endif 

































void WA() {
	int n;
	cin >> n;

	vl a(n);
	cin >> a;

	if (n == 2) {
		cout << 0 << "\n";
		return;
	}

	int res = 0;
	int i = 0, j = 1, k = 2;
	while (k < n) {
		if (a[i] + a[k] < a[j] * 2) {
			res++;

			if (a[k] - a[j] < a[j] - a[i]) {
				a[i] = -1;
				while (i >= 0 && a[i] == -1) i--;
				if (i == -1) {
					i = j;
					j = k;
					k++;
				}
			}
			else {
				a[k] = -1;
				k++;
			}
		}
		else {
			i = j;
			j = k;
			k++;
		}
	}

	cout << res << "\n";
}





template <class S, S(*op)(S, S), S(*e)()>
struct Segtree {
	


	

	int n;
	int actual_n; 


	

	

	

	

	vector<S> v;

	

	Segtree() : n(0), actual_n(0) {}

	

	Segtree(int n_) : actual_n(n_) {
		

		int pow2 = 1;
		while (pow2 < n_) {
			pow2 *= 2;
		}
		n = pow2;

		

		v = vector<S>(2 * n, e());
	}

	

	Segtree(vector<S>& v_) : Segtree(sz(v_)) {
		

		rep(i, sz(v_)) {
			v[i + n] = v_[i];
		}

		

		repir(i, n - 1, 1) {
			v[i] = op(v[i * 2], v[i * 2 + 1]);
		}
	}

	

	void set(int i, S x) {
		

		i += n;

		

		v[i] = x;

		

		while (i > 1) {
			i /= 2;
			v[i] = op(v[i * 2], v[i * 2 + 1]);
		}
	}

	

	S get(int i) const { return v[i + n]; }

	

	S prod(int l, int r) const { return prod_rf(l, r, 1, 0, n); }

	

	S prod_rf(int l, int r, int k, int kl, int kr) const {
		

		if (kr <= l || r <= kl) {
			return e();
		}

		

		if (l <= kl && kr <= r) {
			return v[k];
		}

		

		S vl = prod_rf(l, r, k * 2, kl, (kl + kr) / 2);
		S vr = prod_rf(l, r, k * 2 + 1, (kl + kr) / 2, kr);
		return op(vl, vr);
	}

	

	S all_prod() const { return prod_rf(0, n, 1, 0, n); }

	

	int max_right(int l, const function<bool(S)>& f) const {
		S x = e();
		return max_right_rf(l, actual_n, x, 1, 0, n, f);
	}

	

	int max_right_rf(int l, int r, S& x, int k, int kl, int kr, const function<bool(S)>& f) const {
		

		if (kr <= l || r <= kl) {
			return r;
		}

		

		if (f(op(x, v[k]))) {
			x = op(x, v[k]);
			return r;
		}

		

		if (k >= n) {
			return k - n;
		}

		

		int pos = max_right_rf(l, r, x, k * 2, kl, (kl + kr) / 2, f);
		if (pos != r) {
			return pos;
		}

		

		return max_right_rf(l, r, x, k * 2 + 1, (kl + kr) / 2, kr, f);
	}

	

	int min_left(int r, const function<bool(S)>& f) const {
		S x = e();
		return min_left_rf(0, r, x, 1, 0, n, f) + 1;
	}

	

	int min_left_rf(int l, int r, S& x, int k, int kl, int kr, const function<bool(S)>& f) const {
		

		if (kr <= l || r <= kl) {
			return l - 1;
		}

		

		if (f(op(v[k], x))) {
			x = op(v[k], x);
			return l - 1;
		}

		

		if (k >= n) {
			return k - n;
		}

		

		int pos = min_left_rf(l, r, x, k * 2 + 1, (kl + kr) / 2, kr, f);
		if (pos != l - 1) {
			return pos;
		}

		

		return min_left_rf(l, r, x, k * 2, kl, (kl + kr) / 2, f);
	}

	

	friend ostream& operator<<(ostream& os, Segtree seg) {
		rep(i, seg.actual_n) {
			os << seg.get(i) << " ";
		}
		return os;
	}
};





template <typename T>
int coordinate_compression(const vector<T>& a, vi& a_cp, vector<T>* x = nullptr) {
	


	int n = sz(a);
	if (x == nullptr) x = new vector<T>;

	

	*x = a;
	uniq(*x);

	

	a_cp.resize(n);
	rep(i, n) {
		a_cp[i] = distance(x->begin(), lower_bound(all(*x), a[i]));
	}

	return sz(*x);
}





int op3(int a, int b) { return max(a, b); }
int e3() { return 0; }
template <class T>
int longest_increasing_subsequence(const vector<T>& a, vector<T>* lis = nullptr) {
	int n = sz(a);

	

	vi b;
	vector<T> x;
	int m = coordinate_compression(a, b, &x);

	

	

	Segtree<int, op3, e3> dp(m);

	

	rep(i, n) {
		int j = b[i];

		

		

		int len = dp.prod(0, j) + 1;

		

		

		

		if (len > dp.get(j)) {
			dp.set(j, len);
		}
	}

	

	int len = dp.prod(0, m);

	

	if (lis != nullptr) {
		*lis = vector<T>(len);
		int i = len;
		repir(j, m - 1, 0) {
			if (dp.get(j) == i) {
				(*lis)[i - 1] = x[j];
				i--;
			}
		}
		dump(*lis);
	}

	return len;
}


void WA2() {
	int n;
	cin >> n;

	vl a(n);
	cin >> a;

	if (n == 2) {
		cout << 0 << endl;
		return;
	}

	vl d(n - 1);
	rep(i, n - 1) {
		d[i] = a[i + 1] - a[i];
	}

	auto res = longest_increasing_subsequence(d);
	dump(res);

	dumps("ans:");
	cout << n - (res + 2) << endl;
}





template <class T>
void run_length_encodeing(vector<T>& a, vector<pair<T, int>>& rlc) {
	int n = sz(a);
	if (n == 0) {
		rlc = {};
		return;
	}

	rlc = { {a[0], 1} };

	

	T c = a[0];

	repi(i, 1, n - 1) {
		

		if (c == a[i]) {
			

			rlc.rbegin()->second++;
		}
		

		else {
			

			c = a[i];

			

			rlc.push_back({ c, 1 });
		}
	}
}


void WA3() {
	int n;
	cin >> n;

	vl a(n);
	cin >> a;

	int i = 0, res = INF;
	while(i < n) {
		int ni = i + 1, j = i, rmd = 1;
		ll dif = 0;
		bool continuous_flag = true;

		while (true) {
			auto it = lower_bound(a.begin() + j + 1, a.end(), a[j] + dif);
			if (it == a.end()) {
				break;
			}

			dif = *it - a[i];
			int nj = distance(a.begin(), it);
			if (continuous_flag && nj > j + 1) {
				ni = j + 1;
				continuous_flag = false;
			}
			j = nj;
			rmd++;
		}

		chmin(res, n - rmd);
		i = ni;
	}

	cout << res << endl;
}


void solve() {
	int n;
	cin >> n;

	vl a(n);
	cin >> a;

	vector<pair<ll, int>> b;
	run_length_encodeing(a, b);
	int m = sz(b);

	int res = INF;
	rep(i, m) {
		int j = i, rmd = b[i].second;
		ll dif = 0;

		while (true) {
			auto it = lower_bound(b.begin() + j + 1, b.end(), make_pair(b[j].first + dif, 0));
			if (it == b.end()) {
				break;
			}

			dif = it->first - b[i].first;
			j = distance(b.begin(), it);
			rmd++;
		}

		chmin(res, n - rmd);
	}

	dumps("ans:");
	cout << res << endl;
}


int main() {





	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}
