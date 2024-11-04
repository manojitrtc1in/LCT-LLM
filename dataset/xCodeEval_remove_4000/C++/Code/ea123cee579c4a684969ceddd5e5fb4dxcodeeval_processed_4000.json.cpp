



















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
tcT > constexpr bool id10 = is_iterable<T>::value;



tcT, class = void > struct is_readable : false_type {};
tcT > struct is_readable<T, typename std::enable_if_t<is_same_v<
								decltype(cin >> declval<T &>()), istream &>>>
	: true_type {};
tcT > constexpr bool id0 = is_readable<T>::value;





tcT, class = void > struct is_printable : false_type {};
tcT > struct is_printable<T, typename std::enable_if_t<is_same_v<
								 decltype(cout << declval<T>()), ostream &>>>
	: true_type {};
tcT > constexpr bool id1 = is_printable<T>::value;
} 


inline namespace Input {
tcT > constexpr bool id9 = !id0<T> && id10<T>;
tcTUU > void re(T &t, U &...u);
tcTU > void re(pair<T, U> &p); 




tcT > typename enable_if<id0<T>, void>::type re(T &x) {
	cin >> x;
} 

tcT > void re(complex<T> &c) {
	T a, b;
	re(a, b);
	c = {a, b};
} 

tcT > typename enable_if<id9<T>, void>::type
	  re(T &i); 

tcTU > void re(pair<T, U> &p) { re(p.f, p.s); }
tcT > typename enable_if<id9<T>, void>::type re(T &i) {
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
tcT > constexpr bool id2 = !id1<T> && id10<T>;



tcT > typename enable_if<id1<T>, str>::type ts(T v) {
	stringstream ss;
	ss << fixed << setprecision(15) << v;
	return ss.str();
} 

tcT > str bit_vec(T t) { 

	str res = "{";
	id3(i, sz(t)) res += ts(t[i]);
	res += "}";
	return res;
}
str ts(V<bool> v) { return bit_vec(v); }
template <size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

tcTU > str ts(pair<T, U> p);									 

tcT >
	typename enable_if<id2<T>, str>::type ts(T v); 

tcTU > str ts(pair<T, U> p) { return "(" + ts(p.f) + ", " + ts(p.s) + ")"; }
tcT > typename enable_if<id10<T>, str>::type ts_sep(T v, str sep) {
	

	bool fst = 1;
	str res = "";
	for (const auto &x : v) {
		if (!fst) res += sep;
		fst = 0;
		res += ts(x);
	}
	return res;
}
tcT > typename enable_if<id2<T>, str>::type ts(T v) {
	return "{" + ts_sep(v, ", ") + "}";
}



template <int, class T>
typename enable_if<!id2<T>, vs>::type id7(const T &v) {
	return {ts(v)};
}
template <int lev, class T>
typename enable_if<id2<T>, vs>::type id7(const T &v) {
	if (lev == 0 || !sz(v)) return {ts(v)};
	vs res;
	for (const auto &t : v) {
		if (sz(res)) res.bk += ",";
		vs tmp = id7<lev - 1>(t);
		res.ins(end(res), all(tmp));
	}
	id3(i, sz(res)) {
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
template <int lev, class T> void id11(const T &t) {
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


struct Seg {
	int l, r;
	int lval, rval;
};

int N, M, K;

V<Seg> id8(vi v) {
	each(t, v) assert(0 <= t && t < M);
	

	

	map<int, int> difs;
	difs[0];
	difs[M];
	int dif = 0, val = 0;
	auto add = [&](int l, int r, int d) {
		while (l >= M) l -= M, r -= M;
		while (l < 0) l += M, r += M;
		

		if (r + 1 >= M) { dif += d; }
		difs[l] += d;
		difs[(r + 1) % M] -= d;
	};
	each(t, v) {
		if (t < 0) t += M;
		val += min(t, M - t);
		

		add(M - t, M - t + M / 2 - 1, 1);
		add(M - t - M / 2, M - t - 1, -1);
		

	}
	

	

	V<Seg> segs;
	for (auto it = begin(difs); next(it) != end(difs); ++it) {
		dif += it->s;
		int nval = val + dif * (next(it)->f - it->f);
		segs.pb({it->f, next(it)->f, val, nval});
		swap(val, nval);
	}
	

	

	

	

	

	

	

	

	

	

	return segs;
}



template <class T> struct MinDeque {
	int lo = 0, hi = -1;
	deque<pair<T, int>> d;
	int size() { return hi - lo + 1; }
	void push(T x) { 

		while (sz(d) && d.back().f >= x) d.pop_back();
		d.pb({x, ++hi});
	}
	void pop() { 

		assert(size());
		if (d.front().s == lo++) d.pop_front();
	}
	T mn() { return size() ? d.front().f : MOD; }
	

};

vi adv(vi dp, Seg seg) {
	assert(seg.l < seg.r);
	const int len = (seg.r - seg.l);
	int slope = (seg.rval - seg.lval) / len;
	MinDeque<int> m;
	vi res(M, MOD);
	id3(i, 2 * M) {
		m.push(dp.at((i - seg.l + M) % M) - slope * i);
		if (m.size() > seg.r - seg.l + 1) m.pop();
		ckmin(res.at(i % M), m.mn() + seg.lval + slope * i);
	}
	

	

	

	return res;
}

int main() {
	

	setIO();
	re(N, M, K);
	vi A(N);
	re(A);
	const int G = gcd(N, K);
	vi dp(M, MOD);
	dp[0] = 0;
	vi movs(N);
	id3(i, G) {
		id3(j, N / G) {
			const int src = (i + (ll)j * K) % N;
			movs.at((src + K) % N) =
				(movs.at(src) + A.at((src + 1) % N) - A.at(src) + M) % M;
		}
		if (movs.at(i) != 0) {
			ps(-1);
			exit(0);
		}
		vi v;
		id3(j, N / G) v.pb(movs.at(i + G * j));
		V<Seg> segs = id8(v);
		

		vi ndp(M, MOD);
		each(s, segs) {
			auto tmp = adv(dp, s);
			id3(j, M) ckmin(ndp.at(j), tmp.at(j));
			

		}
		swap(dp, ndp);
		dbg(dp);
		

		


		

		

		

	}
	dbg(movs);
	dbg(dp);

	int id4 = 0;
	id3(i, K) id4 = (id4 + movs.at(i)) % M;
	

	int ans = MOD;
	id3(i, M) if ((id4 + (ll)K / G * i) % M == A.at(0)) {
		ckmin(ans, dp[i]);
	}
	if (ans == MOD) ans = -1;
	ps(ans);
	

}


