#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

using ll = long long;
using db = long double; 

using str = string;		




using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
#define mp make_pair
#define f first
#define s second

#define tcT template <class T
#define tcTU tcT, class U


tcT > using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;





#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()

#define lb lower_bound
#define ub upper_bound
tcT > int lwb(V<T> &a, const T &b) { return int(lb(all(a), b) - bg(a)); }
tcT > int upb(V<T> &a, const T &b) { return int(ub(all(a), b) - bg(a)); }



#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)
#define each(a, x) for (auto &a : x)

const int MOD = (int)1e9 + 7; 

const int MX = (int)2e5 + 5;
const ll BIG = 1e18; 

const db PI = acos((db)-1);
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1}; 

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;





constexpr int pct(int x) { return __builtin_popcount(x); } 

constexpr int bits(
	int x) { 

	return x == 0 ? 0 : 31 - __builtin_clz(x);
} 

constexpr int p2(int x) { return 1 << x; }
constexpr int msk2(int x) { return p2(x) - 1; }

ll cdiv(ll a, ll b) {
	return a / b + ((a ^ b) > 0 && a % b);
} 

ll fdiv(ll a, ll b) {
	return a / b - ((a ^ b) < 0 && a % b);
} 


tcT > bool ckmin(T &a, const T &b) {
	return b < a ? a = b, 1 : 0;
} 

tcT > bool ckmax(T &a, const T &b) {
	return a < b ? a = b, 1 : 0;
} 


tcTU > T fstTrue(T lo, T hi, U f) {
	++hi;
	assert(lo <= hi); 

	while (lo < hi) { 

		T mid = lo + (hi - lo) / 2;
		f(mid) ? hi = mid : lo = mid + 1;
	}
	return lo;
}
tcTU > T lstTrue(T lo, T hi, U f) {
	--lo;
	assert(lo <= hi); 

	while (lo < hi) { 

		T mid = lo + (hi - lo + 1) / 2;
		f(mid) ? lo = mid : hi = mid - 1;
	}
	return lo;
}
tcT > void remDup(vector<T> &v) { 

	sort(all(v));
	v.erase(unique(all(v)), end(v));
}
tcTU > void erase(T &t, const U &u) { 

	auto it = t.find(u);
	assert(it != end(t));
	t.erase(it);
} 


#define tcTUU tcT, class... U

inline namespace Helpers {






tcT, class = void > struct is_iterable : false_type {};
tcT > struct is_iterable<
		  T, void_t<decltype(begin(declval<T>())), decltype(end(declval<T>()))>>
	: true_type {};
tcT > constexpr bool is_iterable_v = is_iterable<T>::value;



tcT, class = void > struct is_readable : false_type {};
tcT > struct is_readable<T, typename std::enable_if_t<is_same_v<
								decltype(cin >> declval<T &>()), istream &>>>
	: true_type {};
tcT > constexpr bool is_readable_v = is_readable<T>::value;





tcT, class = void > struct is_printable : false_type {};
tcT > struct is_printable<T, typename std::enable_if_t<is_same_v<
								 decltype(cout << declval<T>()), ostream &>>>
	: true_type {};
tcT > constexpr bool is_printable_v = is_printable<T>::value;
} 


inline namespace Input {
tcT > constexpr bool needs_input_v = !is_readable_v<T> && is_iterable_v<T>;
tcTUU > void re(T &t, U &...u);
tcTU > void re(pair<T, U> &p); 




tcT > typename enable_if<is_readable_v<T>, void>::type re(T &x) {
	cin >> x;
} 

tcT > void re(complex<T> &c) {
	T a, b;
	re(a, b);
	c = {a, b};
} 

tcT > typename enable_if<needs_input_v<T>, void>::type
	  re(T &i); 

tcTU > void re(pair<T, U> &p) { re(p.f, p.s); }
tcT > typename enable_if<needs_input_v<T>, void>::type re(T &i) {
	each(x, i) re(x);
}
tcTUU > void re(T &t, U &...u) {
	re(t);
	re(u...);
} 




void rv(size_t) {}
tcTUU > void rv(size_t N, V<T> &t, U &...u);
template <class... U> void rv(size_t, size_t N2, U &...u);
tcTUU > void rv(size_t N, V<T> &t, U &...u) {
	t.rsz(N);
	re(t);
	rv(N, u...);
}
template <class... U> void rv(size_t, size_t N2, U &...u) { rv(N2, u...); }



void decrement() {} 

tcTUU > void decrement(T &t, U &...u) {
	--t;
	decrement(u...);
}
#define ints(...)                                                              \
	int __VA_ARGS__;                                                           \
	re(__VA_ARGS__);
#define int1(...)                                                              \
	ints(__VA_ARGS__);                                                         \
	decrement(__VA_ARGS__);
} 


inline namespace ToString {
tcT > constexpr bool needs_output_v = !is_printable_v<T> && is_iterable_v<T>;



tcT > typename enable_if<is_printable_v<T>, str>::type ts(T v) {
	stringstream ss;
	ss << fixed << setprecision(15) << v;
	return ss.str();
} 

tcT > str bit_vec(T t) { 

	str res = "{";
	F0R(i, sz(t)) res += ts(t[i]);
	res += "}";
	return res;
}
str ts(V<bool> v) { return bit_vec(v); }
template <size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

tcTU > str ts(pair<T, U> p);									 

tcT >
	typename enable_if<needs_output_v<T>, str>::type ts(T v); 

tcTU > str ts(pair<T, U> p) { return "(" + ts(p.f) + ", " + ts(p.s) + ")"; }
tcT > typename enable_if<is_iterable_v<T>, str>::type ts_sep(T v, str sep) {
	

	bool fst = 1;
	str res = "";
	for (const auto &x : v) {
		if (!fst) res += sep;
		fst = 0;
		res += ts(x);
	}
	return res;
}
tcT > typename enable_if<needs_output_v<T>, str>::type ts(T v) {
	return "{" + ts_sep(v, ", ") + "}";
}



template <int, class T>
typename enable_if<!needs_output_v<T>, vs>::type ts_lev(const T &v) {
	return {ts(v)};
}
template <int lev, class T>
typename enable_if<needs_output_v<T>, vs>::type ts_lev(const T &v) {
	if (lev == 0 || !sz(v)) return {ts(v)};
	vs res;
	for (const auto &t : v) {
		if (sz(res)) res.bk += ",";
		vs tmp = ts_lev<lev - 1>(t);
		res.ins(end(res), all(tmp));
	}
	F0R(i, sz(res)) {
		str bef = " ";
		if (i == 0) bef = "{";
		res[i] = bef + res[i];
	}
	res.bk += "}";
	return res;
}
} 


inline namespace Output {
template <class T> void pr_sep(ostream &os, str, const T &t) { os << ts(t); }
template <class T, class... U>
void pr_sep(ostream &os, str sep, const T &t, const U &...u) {
	pr_sep(os, sep, t);
	os << sep;
	pr_sep(os, sep, u...);
}


template <class... T> void pr(const T &...t) { pr_sep(cout, "", t...); }


void ps() { cout << "\n"; }
template <class... T> void ps(const T &...t) {
	pr_sep(cout, " ", t...);
	ps();
}


template <class... T> void dbg_out(const T &...t) {
	pr_sep(cerr, " | ", t...);
	cerr << endl;
}
void loc_info(int line, str names) {
	cerr << "Line(" << line << ") -> [" << names << "]: ";
}
template <int lev, class T> void dbgl_out(const T &t) {
	cerr << "\n\n" << ts_sep(ts_lev<lev>(t), "\n") << "\n" << endl;
}
#ifdef LOCAL
#define dbg(...) loc_info(__LINE__, #__VA_ARGS__), dbg_out(__VA_ARGS__)
#define dbgl(lev, x) loc_info(__LINE__, #x), dbgl_out<lev>(x)
#else 

#define dbg(...) 0
#define dbgl(lev, x) 0
#endif

const clock_t beg = clock();
#define dbg_time() dbg((db)(clock() - beg) / CLOCKS_PER_SEC)
} 


inline namespace FileIO {
void setIn(str s) { freopen(s.c_str(), "r", stdin); }
void setOut(str s) { freopen(s.c_str(), "w", stdout); }
void setIO(str s = "") {
	cin.tie(0)->sync_with_stdio(0); 

	

	

	

	if (sz(s)) setIn(s + ".in"), setOut(s + ".out"); 

}
} 


struct Seg {
	int in = -1;
	AR<int, 2> out{-1, -1};
	AR<ll, 2> sum{0, 0};
};

Seg operator+(Seg l, Seg r) {
	Seg res;
	res.in = r.in;
	F0R(i, 2) {
		res.out[i] = l.out[r.out[i] == l.in];
		res.sum[i] = l.sum[r.out[i] == l.in] + r.sum[i];
	}
	return res;
}




V<AR<int, 20>> counts;
V<vi> child;
vi sub_sz;
vi par;

vpi seg_ch;
vl sum_wo;
V<Seg> seg;
int Q;

void dfs(int x) {
	sub_sz[x] = 1;
	for (int &y : child[x]) {
		dfs(y);
		sub_sz[x] += sub_sz[y];
		if (sub_sz[y] > sub_sz[child[x][0]]) { swap(child[x][0], y); }
	}
}

int decompose(int l, int r) {
	if (!sz(child[l]) || r == child[l][0]) {
		for (int x : child[l])
			if (x != r) { par[decompose(x, -1)] = l; }
		return l;
	}
	int removed = r == -1 ? 0 : sub_sz[r];
	int m = child[l][0];
	while (sz(child[m]) && child[m][0] != r &&
		   2 * (sub_sz[child[m][0]] - removed) >= sub_sz[l] - removed) {
		m = child[m][0];
	}
	assert(l != m && m != r);
	int a = decompose(l, m);
	int b = decompose(m, r);
	int c = sz(par);
	par[a] = par[b] = c;
	par.pb(-1);
	seg_ch.pb({a, b});
	return c;
}

void pull(int x) { seg.at(x) = seg.at(seg_ch[x].f) + seg.at(seg_ch[x].s); }

void update(int x) {
	while (x != -1) {
		assert(x < Q);
		int start = x;
		for (; x == start || x >= Q; x = par[x]) {
			if (0 <= par[x] && par[x] < Q) {
				if (seg[x].out[0] != -1) {
					

					--counts.at(par[x]).at(seg[x].out[0]);
				}
				sum_wo.at(par[x]) -= seg[x].sum[0];
			}
			if (x >= Q) pull(x);
			else {
				int in = 0;
				while (counts.at(x).at(in)) ++in;
				int out = in + 1;
				while (counts.at(x).at(out)) ++out;
				seg.at(x).in = in;
				seg.at(x).out = {in, out};
				F0R(i, 2) seg[x].sum[i] = sum_wo.at(x) + seg[x].out.at(i);
			}
			if (0 <= par[x] && par[x] < Q) {
				++counts.at(par[x]).at(seg[x].out[0]);
				sum_wo.at(par[x]) += seg[x].sum[0];
			}
		}
	}
}

int main() {
	

	setIO();
	re(Q);
	++Q;
	counts.rsz(Q);
	sub_sz.rsz(Q);
	child.rsz(Q);
	par = vi(Q, -1);
	seg_ch = vpi(Q, {-1, -1});
	FOR(i, 1, Q) {
		ints(x);
		--x;
		child[x].pb(i);
	}
	dfs(0);
	assert(sub_sz[0] == Q);
	int root = decompose(0, -1);
	seg.rsz(sz(par));
	sum_wo = vl(sz(par));
	F0R(i, Q) {
		update(i);
		if (i) ps(seg.at(root).sum[0]);
	}
	

}


