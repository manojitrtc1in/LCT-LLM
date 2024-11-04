

















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
constexpr int id5(int x) { return p2(x) - 1; }

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
tcT > constexpr bool id11 = is_iterable<T>::value;



tcT, class = void > struct is_readable : false_type {};
tcT > struct is_readable<T, typename std::enable_if_t<is_same_v<
								decltype(cin >> declval<T &>()), istream &>>>
	: true_type {};
tcT > constexpr bool id1 = is_readable<T>::value;





tcT, class = void > struct is_printable : false_type {};
tcT > struct is_printable<T, typename std::enable_if_t<is_same_v<
								 decltype(cout << declval<T>()), ostream &>>>
	: true_type {};
tcT > constexpr bool id2 = is_printable<T>::value;
} 


inline namespace Input {
tcT > constexpr bool id10 = !id1<T> && id11<T>;
tcTUU > void re(T &t, U &...u);
tcTU > void re(pair<T, U> &p); 




tcT > typename enable_if<id1<T>, void>::type re(T &x) {
	cin >> x;
} 

tcT > void re(complex<T> &c) {
	T a, b;
	re(a, b);
	c = {a, b};
} 

tcT > typename enable_if<id10<T>, void>::type
	  re(T &i); 

tcTU > void re(pair<T, U> &p) { re(p.f, p.s); }
tcT > typename enable_if<id10<T>, void>::type re(T &i) {
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

	int id6;                                                           \
	re(id6);

	ints(id6);                                                         \
	decrement(id6);
} 


inline namespace ToString {
tcT > constexpr bool id3 = !id2<T> && id11<T>;



tcT > typename enable_if<id2<T>, str>::type ts(T v) {
	stringstream ss;
	ss << fixed << setprecision(15) << v;
	return ss.str();
} 

tcT > str bit_vec(T t) { 

	str res = "{";
	id4(i, sz(t)) res += ts(t[i]);
	res += "}";
	return res;
}
str ts(V<bool> v) { return bit_vec(v); }
template <size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

tcTU > str ts(pair<T, U> p);									 

tcT >
	typename enable_if<id3<T>, str>::type ts(T v); 

tcTU > str ts(pair<T, U> p) { return "(" + ts(p.f) + ", " + ts(p.s) + ")"; }
tcT > typename enable_if<id11<T>, str>::type ts_sep(T v, str sep) {
	

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
typename enable_if<!id3<T>, vs>::type id7(const T &v) {
	return {ts(v)};
}
template <int lev, class T>
typename enable_if<id3<T>, vs>::type id7(const T &v) {
	if (lev == 0 || !sz(v)) return {ts(v)};
	vs res;
	for (const auto &t : v) {
		if (sz(res)) res.bk += ",";
		vs tmp = id7<lev - 1>(t);
		res.ins(end(res), all(tmp));
	}
	id4(i, sz(res)) {
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
template <int lev, class T> void id12(const T &t) {
	cerr << "\n\n" << ts_sep(id7<lev>(t), "\n") << "\n" << endl;
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


namespace TwoWayPal {

str S;
vi len{0, -1};
V<AR<int, 26>> fail(2), child(2);
vb active(2);

vi pref_pal{0}, id0{0}, ans{0}, last_set{-1};

void init(str _S) {
	S = _S;
	each(t, fail.at(0)) t = 1;
}

void set_last(int cur) {
	if (!active.at(cur)) {
		last_set.bk = cur;
		active.at(cur) = 1;
		++ans.bk;
	}
}

void append(int i) {
	const int new_len = sz(pref_pal);
	pref_pal.pb(pref_pal.bk);
	id0.pb(id0.bk);
	ans.pb(ans.bk);
	last_set.pb(-1);
	const int c = S.at(i) - 'a';

	if (len.at(id0.bk) == new_len - 1 ||
		S.at(i) != S.at(i - len.at(id0.bk) - 1)) {
		id0.bk =
			fail.at(id0.bk).at(c); 

	}
	{
		int cur = id0.bk;
		if (!child.at(cur).at(c)) {
			const int nxt = sz(len);
			child.at(cur).at(c) = nxt;
			const int link = child.at(fail.at(cur).at(c)).at(c);
			assert(link != 1);
			len.pb(len.at(cur) + 2);
			fail.pb(fail.at(link));
			fail.bk.at(S.at(i - len.at(link)) - 'a') = link;
			child.eb();
			active.eb();
		}
		id0.bk = child.at(cur).at(c);
	}
	

	if (len.at(id0.bk) == new_len) pref_pal.bk = id0.bk;
	set_last(id0.bk);
	dbg("APPEND", i, ans.bk, len.at(pref_pal.bk), len.at(id0.bk));
}

void prepend(int i) {
	const int new_len = sz(pref_pal);
	pref_pal.pb(pref_pal.bk);
	id0.pb(id0.bk);
	ans.pb(ans.bk);
	last_set.pb(-1);
	const int c = S.at(i) - 'a';

	if (len.at(pref_pal.bk) == new_len - 1 ||
		S.at(i) != S.at(i + len.at(pref_pal.bk) + 1)) {
		pref_pal.bk = fail.at(pref_pal.bk)
						  .at(c); 

	}
	{
		int cur = pref_pal.bk;
		if (!child.at(cur).at(c)) {
			const int nxt = sz(len);
			child.at(cur).at(c) = nxt;
			const int link = child.at(fail.at(cur).at(c)).at(c);
			assert(link != 1);
			len.pb(len.at(cur) + 2);
			fail.pb(fail.at(link));
			fail.bk.at(S.at(i + len.at(link)) - 'a') = link;
			child.eb();
			active.eb();
		}
		pref_pal.bk = child.at(cur).at(c);
	}
	if (len.at(pref_pal.bk) == new_len) id0.bk = pref_pal.bk;
	set_last(pref_pal.bk);
	dbg("PREPEND", i, ans.bk, len.at(pref_pal.bk), len.at(id0.bk));
}

void undo() {
	pref_pal.pop_back();
	assert(sz(pref_pal));
	id0.pop_back();
	ans.pop_back();
	if (last_set.bk != -1) { active.at(last_set.bk) = 0; }
	last_set.pop_back();
	dbg("UNDO", ans.bk);
}

int get_ans() { return ans.bk; }
} 


void recurse(const vpi &queries, int l, int r) {
	if (l == r) return;
	if (l + 1 == r) {
		dbg(queries.at(l));
		cout << TwoWayPal::get_ans() << "\n";
		return;
	}
	int m = (l + r) / 2;
	pi ival{queries.at(r - 1).f, queries.at(l).s};
	pi id9{queries.at(m - 1).f, queries.at(l).s};
	pi id8{queries.at(r - 1).f, queries.at(m).s};
	int undos = 0;
	auto undo_all = [&]() {
		while (undos) TwoWayPal::undo(), --undos;
	};

	for (int x = min(queries.at(l).s, queries.at(r - 1).f - 1);
		 x >= queries.at(m - 1).f; --x)
		TwoWayPal::prepend(x), ++undos;
	recurse(queries, l, m);
	undo_all();

	for (int x = max(queries.at(l).s + 1, queries.at(r - 1).f);
		 x <= queries.at(m).s; ++x)
		TwoWayPal::append(x), ++undos;
	recurse(queries, m, r);
	undo_all();
}

int main() {
	

	setIO();
	ints(Q);
	str S;
	vpi queries;
	int l = 0, r = -1;
	rep(Q) {
		str op;
		re(op);
		if (op == "push") {
			char c;
			re(c);
			S += c;
			++r;
		} else {
			++l;
		}
		queries.pb({l, r});
	}
	TwoWayPal::init(S);
	FOR(i, queries.bk.f, queries.ft.s + 1) TwoWayPal::append(i);
	recurse(queries, 0, sz(queries));
	

}

