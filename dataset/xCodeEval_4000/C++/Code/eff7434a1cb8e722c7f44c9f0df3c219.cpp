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
const int INF = 1001001001; const ll INFL = 2002002002002002002LL;
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
template <class T> inline ostream& operator<< (ostream& os, const list<T>& v) { repe(x, v) os << x << " "; return os; }
template <class T> inline ostream& operator<< (ostream& os, const set<T>& s) { repe(x, s) os << x << " "; return os; }
template <class T> inline ostream& operator<< (ostream& os, const set<T, greater<T>>& s) { repe(x, s) os << x << " "; return os; }
template <class T> inline ostream& operator<< (ostream& os, const unordered_set<T>& s) { repe(x, s) os << x << " "; return os; }
template <class T, class U> inline ostream& operator<< (ostream& os, const map<T, U>& m) { repe(p, m) os << p << " "; return os; }
template <class T, class U> inline ostream& operator<< (ostream& os, const unordered_map<T, U>& m) { repe(p, m) os << p << " "; return os; }
template <class T> inline ostream& operator<< (ostream& os, stack<T> s) { while (!s.empty()) { os << s.top() << " "; s.pop(); } return os; }
template <class T> inline ostream& operator<< (ostream& os, queue<T> q) { while (!q.empty()) { os << q.front() << " "; q.pop(); } return os; }
template <class T> inline ostream& operator<< (ostream& os, deque<T> q) { while (!q.empty()) { os << q.front() << " "; q.pop_front(); } return os; }
template <class T> inline ostream& operator<< (ostream& os, priority_queue<T> q) { while (!q.empty()) { os << q.top() << " "; q.pop(); } return os; }
template <class T> inline ostream& operator<< (ostream& os, priority_queue_rev<T> q) { while (!q.empty()) { os << q.top() << " "; q.pop(); } return os; }
template <class T> inline vector<T>& operator--(vector<T>& v) { rep(_i_, sz(v)) --v[_i_]; return v; }



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
#define dumpel(a) { int _i_ = -1; cout << "\033[1;36m"; repe(x, a) {cout << ++_i_ << ": " << x << endl;} cout << "\033[0m"; }
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


void solve() {
	int n; ll a, b, c;
	cin >> n >> a >> b >> c;

	string s_;
	cin >> s_;
	vc s(all(s_));

	vector<pair<char, int>> rlc;
	run_length_encodeing(s, rlc);
	int m = sz(rlc);

	if (m == 1) {
		ll res = 0;

		if (n >= 2) {
			if (s[0] == '0') res = a;
			else res = b;
		}

		cout << res << "\n";

		return;
	}

	if (c > b) {
		int cnt0 = 0, cnt1 = 0;
		repe(p, rlc) {
			if (p.first == '0') {
				cnt0 += p.second - 1;
			}
			else {
				cnt1 += p.second - 1;
			}
		}
		dump(cnt0);
		dump(cnt1);

		chmin(cnt0, cnt1 + 1);
		chmin(cnt1, cnt0 + 1);
		dump(cnt0);
		dump(cnt1);

		ll res = cnt0 * a + cnt1 * b;

		cout << res << "\n";

		return;
	}

	bool l0 = false, r0 = false;
	int l0_len = 0, r0_len = 0;
	if (rlc[0].first == '0') {
		l0_len = rlc[0].second;
		l0 = true;
	}
	if (rlc[m - 1].first == '0') {
		r0_len = rlc[m - 1].second;
		r0 = true;
	}

	int cnt1 = 0;
	vi len0;
	rep(j, m) {
		if (rlc[j].first == '1') {
			cnt1 += rlc[j].second - 1;
		}
		else {
			if (j != 0 && j != m - 1) {
				len0.push_back(rlc[j].second);
			}
		}
	}
	sort(all(len0));
	dump(cnt1);
	dump(len0);

	ll res = 0;
	bool f00 = false;
	rep(i, sz(len0)) {
		if (cnt1 >= len0[i] - 1) {
			cnt1 -= len0[i] - 1;
			res += (len0[i] - 1) * (a + b);
			res += b - c;
		}
		else {
			res += cnt1 * (a + b);
			f00 = true;
			cnt1 = 0;
		}
		dump(res);
	}
	if (l0) {
		if (cnt1 >= l0_len - 1) {
			cnt1 -= l0_len - 1;
			res += (l0_len - 1) * (a + b);
		}
		else {
			res += cnt1 * (a + b);
			f00 = true;
			cnt1 = 0;
		}
	}
	if (r0) {
		if (cnt1 >= r0_len - 1) {
			cnt1 -= r0_len - 1;
			res += (r0_len - 1) * (a + b);
		}
		else {
			res += cnt1 * (a + b);
			f00 = true;
			cnt1 = 0;
		}
	}
	if (cnt1 > 0) {
		res += b;
		cnt1--;
	}
	if (l0 && cnt1 > 0) {
		res += b - c;
		cnt1--;
	}
	if (r0 && cnt1 > 0) {
		res += b - c;
		cnt1--;
	}
	if (f00) {
		res += a;
	}

	cout << res << "\n";
}


int main() {
	input_from_file("input.txt");



	int t;
	cin >> t;

	while (t--) {
		dump("------------------------------");
		solve();
	}
}
