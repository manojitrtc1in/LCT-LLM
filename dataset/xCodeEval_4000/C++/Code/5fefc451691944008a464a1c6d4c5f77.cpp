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

mt19937 rng(0);
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





using P = pair<int, int>;
using P2 = pair<int, pi>;

const P ID{-1e9 - 1, -1};
const P2 ID2{ID.f, {-1, -1}};

P2 pairup(const P &l, const P &r) {
	if (l.s == -1 || r.s == -1) return ID2;
	

	return {l.f + r.f, {l.s, r.s}};
}

P comb_out(const P &a, const P &b) { return a.f > b.f ? a : b; }
void comb_out_inplace(P &a, const P &b) {
	if (a.f < b.f) a = b;
}
P comb_in(P a, const P &b) { return a.f > b.f ? a : b; }
void comb_in_inplace(P &a, const P &b) {
	if (a.f < b.f) a = b;
}
P2 comb_inout(const P2 &a, const P2 &b) { return a.f > b.f ? a : b; }
void comb_inout_inplace(P2 &a, const P2 &b) {
	if (a.f < b.f) a = b;
}

struct Node {
	int lazy;
	int mn;
	AR<P, 3> in, in_mn;
	AR<P, 3> out, out_mn;
	AR<AR<pair<int, pi>, 3>, 3> in_out, in_out_mn;
	Node() : lazy(0), mn(0) {
		F0R(i, 3) {
			out[i] = out_mn[i] = ID;
			in[i] = in_mn[i] = ID;
		}
		F0R(i, 3) F0R(j, 3) { in_out[i][j] = in_out_mn[i][j] = ID2; }
	}
};



void comb(Node &p, const Node &l, const Node &r) {
	assert(p.lazy == 0 && l.lazy == 0 && r.lazy == 0);
	p.mn = min(l.mn, r.mn); 

	F0R(i, 3) {
		p.out[i] = comb_out(l.out[i], r.out[i]);
		p.in[i] = comb_in(l.in[i], r.in[i]);
	}
	if (p.mn == r.mn) { 

		p.out_mn = r.out_mn;
	} else {
		p.out_mn = r.out;
		F0R(i, 3) comb_out_inplace(p.out_mn[i], l.out_mn[i]);
	}
	if (p.mn == l.mn) { 

		p.in_mn = l.in_mn;
	} else {
		p.in_mn = l.in;
		F0R(i, 3) comb_in_inplace(p.in_mn[i], r.in_mn[i]);
	}
	F0R(i, 3) F0R(j, 3) if (i != j) p.in_out_mn[i][j] = ID2;
	F0R(i, 3) F0R(j, 3) if (i != j) {
		p.in_out[i][j] = comb_inout(l.in_out[i][j], r.in_out[i][j]);
		comb_inout_inplace(l.mn == p.mn ? p.in_out_mn[i][j] : p.in_out[i][j],
						   l.in_out_mn[i][j]);
		comb_inout_inplace(r.mn == p.mn ? p.in_out_mn[i][j] : p.in_out[i][j],
						   r.in_out_mn[i][j]);
	}
	

	F0R(i, 3) F0R(j, 3) if (i != j) {
		comb_inout_inplace(p.in_out[i][j], pairup(l.in[i], r.out[j]));
		comb_inout_inplace(p.in_out[i][j],
						   pairup(r.mn == p.mn ? r.in_mn[i] : r.in[i],
								  l.mn == p.mn ? l.out_mn[j] : l.out[j]));
		comb_inout_inplace(p.in_out_mn[i][j],
						   pairup(r.in[i], l.out[j])); 

	}
}

V<AR<int, 3>> glob_tasks;

struct Seg {
	ll total_cost = 0;
	int N;
	AR<int, 3> type_count{}, type_ub;
	V<Node> v;
	Seg(int _N, AR<int, 3> _type_ub) : N(_N), type_ub(_type_ub) {
		v.rsz(4 * N);
		

	}
	

	

	

	

	

	

	

	

	

	

	

	

	bool add_path(int p) {
		dbg("add_path", p);
		

		assert(v.at(1).mn == 0);
		

		

		

		


		

		

		V<pair<ll, int>> dist(4, {-BIG, 0});
		dist.at(3).f = 0;
		V<pair<int, pi>> pre(4);
		

		F0R(i, 3) F0R(j, 3) if (i != j) {
			dbg(i, j, v.at(1).in_out.at(i).at(j),
				v.at(1).in_out_mn.at(i).at(j));
		}
		

		rep(3) {
			auto edge = [&](int s, int t, P2 p) {
				if (dist.at(s).f == -BIG) return;
				if (p.f == ID.f) return;
				if (_ == 0) dbg("EDGE", s, t, p);
				if (ckmax(dist.at(t),
						  mp(dist.at(s).f + p.f, dist.at(s).s - 1))) {
					pre.at(t) = {s, p.s};
				}
			};
			F0R(i, 3) {
				edge(3, i, {v.at(1).out.at(i).f, {p, v.at(1).out.at(i).s}});
			}
			F0R(i, 3)
			F0R(j, 3) if (i != j) { edge(i, j, v.at(1).in_out.at(i).at(j)); }
		}
		int best_idx = -1;
		F0R(i, 3) if (type_count.at(i) < type_ub.at(i)) {
			if (best_idx == -1 || dist.at(i).f > dist.at(best_idx).f)
				best_idx = i;
		}
		if (best_idx == -1 || dist.at(best_idx).f == -BIG) return false;
		++type_count.at(best_idx);
		total_cost += dist.at(best_idx).f;
		

		

		int cyc_len = 0;
		

		while (best_idx != 3) {
			++cyc_len;
			if (cyc_len > 3) {
				

				ps(N, type_ub);
				for (auto [d, r, type] : glob_tasks) ps(r, type, d);
				ps(dist);
				exit(0);
			}
			dbg("toggle_and_inc_lazy", pre.at(best_idx).s.f,
				pre.at(best_idx).s.s, pre.at(best_idx).f == 3);
			toggle_and_inc_lazy(pre.at(best_idx).s.f, pre.at(best_idx).s.s,
								pre.at(best_idx).f == 3);
			best_idx = pre.at(best_idx).f;
		}
		assert(v.at(1).mn == 0);
		return true;
	}
	void upd(int p, int r, int type) {
		--type;
		dbg("upd", p, r, type);
		assert(v.at(1).mn == 0);
		upd(p, r, type, 1, 0, N - 1);
		assert(v.at(1).mn == 0);
	}
	void inc_lazy(int p, int inc) {
		

		inc_lazy(p, inc, 1, 0, N - 1);
		

	}
	

	

	

	

	void toggle_and_inc_lazy(int s, int t, bool is_first) {
		

		toggle_and_inc_lazy(s, t, is_first, 1, 0, N - 1);
	}

  private:
	void pull(int ind) {
		comb(v.at(ind), v.at(2 * ind), v.at(2 * ind + 1));
	}								   

	void push(int ind, int L, int R) { 

		v.at(ind).mn += v.at(ind).lazy;
		if (L != R) {
			FOR(i, 2 * ind, 2 * ind + 2) v.at(i).lazy += v.at(ind).lazy;
		}
		v.at(ind).lazy = 0;
	}
	void upd(int p, int r, int type, int ind, int L, int R) {
		push(ind, L, R);
		if (p < L || R < p) return;
		if (L == R) {
			v.at(ind).out.at(type) = {r, p};
			return;
		}
		int M = (L + R) / 2;
		upd(p, r, type, 2 * ind, L, M);
		upd(p, r, type, 2 * ind + 1, M + 1, R);
		pull(ind);
	}
	void toggle(int p, int ind, int L, int R) { 

		push(ind, L, R);
		if (p < L || R < p) return;
		if (L == R) {
			auto negate = [&](P &p) {
				if (p != ID) p.f *= -1;
			};
			F0R(t, 3) {
				swap(v.at(ind).out.at(t), v.at(ind).in.at(t));
				negate(v.at(ind).out.at(t));
				negate(v.at(ind).in.at(t));
			}
			v.at(ind).in_mn = v.at(ind).in;
			return;
		}
		int M = (L + R) / 2;
		toggle(p, 2 * ind, L, M);
		toggle(p, 2 * ind + 1, M + 1, R);
		pull(ind);
	}
	void inc_lazy(int p, int inc, int ind, int L, int R) { 

		push(ind, L, R);
		if (p < L) return;
		if (R <= p) {
			v.at(ind).lazy += inc;
			push(ind, L, R);
			return;
		}
		int M = (L + R) / 2;
		inc_lazy(p, inc, 2 * ind, L, M);
		inc_lazy(p, inc, 2 * ind + 1, M + 1, R);
		pull(ind);
	}
	void toggle_and_inc_lazy(int s, int t, bool is_first, int ind, int L,
							 int R) { 

		push(ind, L, R);
		if (R < min(s, t)) return;
		if (L > max(s, t)) return;
		if (min(s, t) < L && R < max(s, t)) {
			v.at(ind).lazy += (s < t ? 1 : -1);
			push(ind, L, R);
			return;
		}
		if (L == R) {
			auto negate = [&](P &p) {
				if (p != ID) p.f *= -1;
			};
			if (L < max(s, t)) {
				v.at(ind).lazy += (s < t ? 1 : -1);
				push(ind, L, R);
			}
			auto toggle = [&]() {
				F0R(i, 3) {
					swap(v.at(ind).out.at(i), v.at(ind).in.at(i));
					negate(v.at(ind).out.at(i));
					negate(v.at(ind).in.at(i));
				}
				v.at(ind).in_mn = v.at(ind).in;
			};
			if (R == t) {
				toggle();
			} else if (R == s) {
				if (!is_first) { toggle(); }
			} else {
				assert(false);
			}
			return;
		}
		int M = (L + R) / 2;
		toggle_and_inc_lazy(s, t, is_first, 2 * ind, L, M);
		toggle_and_inc_lazy(s, t, is_first, 2 * ind + 1, M + 1, R);
		pull(ind);
	}
};

ll solve_smart(int N, AR<int, 3> ub, V<AR<int, 3>> tasks) {
	if (ub[0] + ub[1] + ub[2] > N) return -1;
	Seg seg(N, ub);
	int idx = sz(tasks);
	ROF(d, 1, ub[0] + ub[1] + ub[2] + 1) {
		while (idx && tasks.at(idx - 1).at(0) >= d) {
			--idx;
			seg.upd(idx, tasks.at(idx).at(1), tasks.at(idx).at(2));
		}
		if (!seg.add_path(idx)) return -1;
	}
	return seg.total_cost;
}

ll solve_dumb(int N, AR<int, 3> ub, V<AR<int, 3>> tasks) {
	if (ub[0] + ub[1] + ub[2] > N) return -1;
	assert(sz(tasks) == N);
	ll best_ans = -1;
	do {
		bool bad = false;
		AR<int, 3> with_type{};
		ll sum = 0;
		F0R(i, ub[0] + ub[1] + ub[2]) {
			if (tasks[i][0] < i + 1) bad = true;
			++with_type.at(tasks[i][2] - 1);
			sum += tasks[i][1];
		}
		if (with_type == ub && !bad) { ckmax(best_ans, sum); }
	} while (next_permutation(all(tasks)));
	return best_ans;
}

ll solve(int tc) {
	

	ints(N, A, B, C);
	

	

	

	

	

	

	

	


	V<AR<int, 3>> tasks;
	rep(N) {
		

		

		ints(r, type, d);
		

		tasks.pb({d, r, type});
	}
	glob_tasks = tasks;
	sor(tasks);
	each(t, tasks) dbg(t);
	auto a_smart = solve_smart(N, {A, B, C}, tasks);
	return a_smart;
	

}

int main() {
	setIO();
	

	int TC;
	re(TC);
	vl anses;
	FOR(i, 1, TC + 1) anses.pb(solve(i));
	each(t, anses) ps(t);
}

