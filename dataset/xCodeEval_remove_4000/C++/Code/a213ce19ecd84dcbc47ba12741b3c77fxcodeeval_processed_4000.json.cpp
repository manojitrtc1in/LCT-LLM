

















using namespace std;

using ll = long long;
using db = long double; 

using str = string;		




using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;








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



















tcT > int lwb(V<T> &a, const T &b) { return int(lb(all(a), b) - bg(a)); }
tcT > int upb(V<T> &a, const T &b) { return int(ub(all(a), b) - bg(a)); }










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
constexpr int id6(int x) { return p2(x) - 1; }

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




inline namespace Helpers {






tcT, class = void > struct is_iterable : false_type {};
tcT > struct is_iterable<
		  T, void_t<decltype(begin(declval<T>())), decltype(end(declval<T>()))>>
	: true_type {};
tcT > constexpr bool id2 = is_iterable<T>::value;



tcT, class = void > struct is_readable : false_type {};
tcT > struct is_readable<T, typename std::enable_if_t<is_same_v<
								decltype(cin >> declval<T &>()), istream &>>>
	: true_type {};
tcT > constexpr bool id4 = is_readable<T>::value;





tcT, class = void > struct is_printable : false_type {};
tcT > struct is_printable<T, typename std::enable_if_t<is_same_v<
								 decltype(cout << declval<T>()), ostream &>>>
	: true_type {};
tcT > constexpr bool id0 = is_printable<T>::value;
} 


inline namespace Input {
tcT > constexpr bool id1 = !id4<T> && id2<T>;
tcTUU > void re(T &t, U &...u);
tcTU > void re(pair<T, U> &p); 




tcT > typename enable_if<id4<T>, void>::type re(T &x) {
	cin >> x;
} 

tcT > void re(complex<T> &c) {
	T a, b;
	re(a, b);
	c = {a, b};
} 

tcT > typename enable_if<id1<T>, void>::type
	  re(T &i); 

tcTU > void re(pair<T, U> &p) { re(p.f, p.s); }
tcT > typename enable_if<id1<T>, void>::type re(T &i) {
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

	int id7;                                                           \
	re(id7);

	ints(id7);                                                         \
	decrement(id7);
} 


inline namespace ToString {
tcT > constexpr bool id3 = !id0<T> && id2<T>;



tcT > typename enable_if<id0<T>, str>::type ts(T v) {
	stringstream ss;
	ss << fixed << setprecision(15) << v;
	return ss.str();
} 

tcT > str bit_vec(T t) { 

	str res = "{";
	id5(i, sz(t)) res += ts(t[i]);
	res += "}";
	return res;
}
str ts(V<bool> v) { return bit_vec(v); }
template <size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

tcTU > str ts(pair<T, U> p);									 

tcT >
	typename enable_if<id3<T>, str>::type ts(T v); 

tcTU > str ts(pair<T, U> p) { return "(" + ts(p.f) + ", " + ts(p.s) + ")"; }
tcT > typename enable_if<id2<T>, str>::type ts_sep(T v, str sep) {
	

	bool fst = 1;
	str res = "";
	for (const auto &x : v) {
		if (!fst) res += sep;
		fst = 0;
		res += ts(x);
	}
	return res;
}
tcT > typename enable_if<id3<T>, str>::type ts(T v) {
	return "{" + ts_sep(v, ", ") + "}";
}



template <int, class T>
typename enable_if<!id3<T>, vs>::type id8(const T &v) {
	return {ts(v)};
}
template <int lev, class T>
typename enable_if<id3<T>, vs>::type id8(const T &v) {
	if (lev == 0 || !sz(v)) return {ts(v)};
	vs res;
	for (const auto &t : v) {
		if (sz(res)) res.bk += ",";
		vs tmp = id8<lev - 1>(t);
		res.ins(end(res), all(tmp));
	}
	id5(i, sz(res)) {
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
template <int lev, class T> void id9(const T &t) {
	cerr << "\n\n" << ts_sep(id8<lev>(t), "\n") << "\n" << endl;
}









const clock_t beg = clock();

} 


inline namespace FileIO {
void setIn(str s) { freopen(s.c_str(), "r", stdin); }
void setOut(str s) { freopen(s.c_str(), "w", stdout); }
void setIO(str s = "") {
	cin.tie(0)->sync_with_stdio(0); 

	

	

	

	if (sz(s)) setIn(s + ".in"), setOut(s + ".out"); 

}
} 





void solve(int tc) {
	ints(M);
	vi B(M);
	re(B);
	dbg("TEST", B);
	vpi by_val(M);
	id5(i, M) by_val[i] = {B[i], i};
	sort(rall(by_val));
	vi special;
	each(p, by_val) if (p.f > 1) special.pb(p.f);
	V<vi> ans;
	auto add_vec = [&](vi v) {
		while (sz(v) < M) v.eb();
		ans.pb(v);
	};
	if (!sz(special) || special[0] == 2) {
		int pos = sz(special);
		if (special == vi{}) {
			add_vec({1});
			++pos;
		} else if (special == vi{2}) {
			add_vec({1});
			add_vec({2});
		} else if (special == vi{2, 2}) {
			add_vec({0, 1});
			add_vec({2, 2});
			add_vec({1, 0});
			add_vec({2, 1});
			add_vec({0, 2});
			add_vec({1, 1});
			add_vec({2, 0});
			add_vec({1, 2});
		} else {
			ps(-1);
			return;
		}
		for (; pos < M; ++pos) {
			assert(by_val.at(pos).f == 1);
			V<vi> nans;
			if (sz(ans) % 2 == 0) {
				each(t, ans) nans.pb(t);
				nans.pb(vi(M));
				nans.bk.at(pos) = 1;
				each(t, ans) nans.pb(t);
				id5(i, sz(ans)) {
					if (i & 1) nans.at(i).at(pos) = 1;
					else nans.at(i + sz(ans) + 1).at(pos) = 1;
				}
			} else {
				nans.pb(ans.ft);
				id5(i, sz(ans)) {
					nans.pb(ans[i]);
					if (i % 2 == 0) nans.bk.at(pos) = 1;
				}
				nans.pb(vi(M));
				nans.bk.at(pos) = 1;
				FOR(i, 1, sz(ans)) {
					nans.pb(ans[i]);
					if (i % 2 == 1) nans.bk.at(pos) = 1;
				}
			}
			assert(sz(nans) == 2 * sz(ans) + 1);
			swap(ans, nans);
		}
	} else if (special == vi{3}) {
		add_vec({3});
		add_vec({1});
		add_vec({2});
		FOR(pos, 1, M) {
			assert(by_val.at(pos).f == 1);
			V<vi> nans;
			vi needle(M);
			needle.at(0) = 1;
			id5(i, sz(ans)) {
				nans.pb(ans[i]);
				if (i % 2 == 0) nans.bk.at(pos) = 1;
			}
			nans.pb(vi(M));
			nans.bk.at(pos) = 1;
			id5(i, sz(ans)) {
				nans.pb(ans[i]);
				if (i % 2 == 1) nans.bk.at(pos) = 1;
			}
			swap(nans.at(sz(ans)),
				 nans.at(find(all(nans), needle) - begin(nans)));
			swap(nans, ans);
		}
	} else {
		ps(-1);
		return;
	}
	int prod = 1;
	each(t, B) prod *= t + 1;
	dbg(sz(ans), prod);
	assert(sz(ans) + 1 == prod);
	id5(i, sz(ans) - 1) {
		int ret = 0;
		id5(j, M) {
			assert(min(ans[i][j], ans[i + 1][j]) <= 1);
			ret += min(ans[i][j], ans[i + 1][j]) == 1;
		}
		assert(ret == 1);
	}
	set<vi> distinct;
	each(t, ans) {
		assert(!distinct.count(t));
		distinct.ins(t);
		vi act(M);
		id5(i, M) act.at(by_val[i].s) = t[i];
		

		id5(i, M) assert(act[i] <= B[i]);
		ps(ts_sep(act, " "));
	}
	

	

	

}

int main() {
	setIO();
	int TC;
	re(TC);
	FOR(i, 1, TC + 1) solve(i);
}


