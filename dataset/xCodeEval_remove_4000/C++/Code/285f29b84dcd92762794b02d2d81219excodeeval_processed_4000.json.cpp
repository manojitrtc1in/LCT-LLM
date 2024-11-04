


















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

mt19937 rng(0);
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;





constexpr int pct(int x) { return __builtin_popcount(x); } 

constexpr int bits(
	int x) { 

	return x == 0 ? 0 : 31 - __builtin_clz(x);
} 

constexpr int p2(int x) { return 1 << x; }
constexpr int id8(int x) { return p2(x) - 1; }

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
tcT > constexpr bool id15 = is_iterable<T>::value;



tcT, class = void > struct is_readable : false_type {};
tcT > struct is_readable<T, typename std::enable_if_t<is_same_v<
								decltype(cin >> declval<T &>()), istream &>>>
	: true_type {};
tcT > constexpr bool id0 = is_readable<T>::value;





tcT, class = void > struct is_printable : false_type {};
tcT > struct is_printable<T, typename std::enable_if_t<is_same_v<
								 decltype(cout << declval<T>()), ostream &>>>
	: true_type {};
tcT > constexpr bool id2 = is_printable<T>::value;
} 


inline namespace Input {
tcT > constexpr bool id13 = !id0<T> && id15<T>;
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

tcT > typename enable_if<id13<T>, void>::type
	  re(T &i); 

tcTU > void re(pair<T, U> &p) { re(p.f, p.s); }
tcT > typename enable_if<id13<T>, void>::type re(T &i) {
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

	int id9;                                                           \
	re(id9);

	ints(id9);                                                         \
	decrement(id9);
} 


inline namespace ToString {
tcT > constexpr bool id5 = !id2<T> && id15<T>;



tcT > typename enable_if<id2<T>, str>::type ts(T v) {
	stringstream ss;
	ss << fixed << setprecision(15) << v;
	return ss.str();
} 

tcT > str bit_vec(T t) { 

	str res = "{";
	id7(i, sz(t)) res += ts(t[i]);
	res += "}";
	return res;
}
str ts(V<bool> v) { return bit_vec(v); }
template <size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

tcTU > str ts(pair<T, U> p);									 

tcT >
	typename enable_if<id5<T>, str>::type ts(T v); 

tcTU > str ts(pair<T, U> p) { return "(" + ts(p.f) + ", " + ts(p.s) + ")"; }
tcT > typename enable_if<id15<T>, str>::type ts_sep(T v, str sep) {
	

	bool fst = 1;
	str res = "";
	for (const auto &x : v) {
		if (!fst) res += sep;
		fst = 0;
		res += ts(x);
	}
	return res;
}
tcT > typename enable_if<id5<T>, str>::type ts(T v) {
	return "{" + ts_sep(v, ", ") + "}";
}



template <int, class T>
typename enable_if<!id5<T>, vs>::type id10(const T &v) {
	return {ts(v)};
}
template <int lev, class T>
typename enable_if<id5<T>, vs>::type id10(const T &v) {
	if (lev == 0 || !sz(v)) return {ts(v)};
	vs res;
	for (const auto &t : v) {
		if (sz(res)) res.bk += ",";
		vs tmp = id10<lev - 1>(t);
		res.ins(end(res), all(tmp));
	}
	id7(i, sz(res)) {
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
template <int lev, class T> void id16(const T &t) {
	cerr << "\n\n" << ts_sep(id10<lev>(t), "\n") << "\n" << endl;
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





V<vpi> id6(str S) {
	const int N = sz(S);
	vi prv(N + 1), nxt(N + 1);
	{
		int cur = -1;
		id7(i, N + 1) {
			if (i == N || S.at(i) == '1') cur = i;
			prv.at(i) = cur;
		}
	}
	{
		nxt.at(N) = N;
		id11(i, N) {
			if (S.at(i) == '1') nxt.at(i) = i;
			else nxt.at(i) = nxt.at(i + 1);
		}
	}
	V<vpi> ival(N + 1);
	id11(i, N) {
		int lst = i;
		int cur = S.at(i) == '1' ? i : i - 1;
		bool good = (S.at(i) == '1');
		

		while (true) {
			if (good) {
				

				int next_one = prv.at(min(2 * cur + 2 - i, N));
				if (next_one > cur) {
					cur = next_one;
					continue;
				}
				

				assert((lst == N || S.at(lst) == '1') &&
					   (cur == N || S.at(cur) == '1'));
				ival.at(i).pb({lst, cur});
				good = false;
				continue;
			}
			if (cur == N) break;
			

			int next_one = nxt.at(cur + 1);
			int need_r = 2 * next_one - 2 - cur;
			

			assert(need_r >= next_one);
			int idx = fstTrue(0, sz(ival.at(next_one)) - 1, [&](int x) {
				return ival.at(next_one).at(x).s >= need_r;
			});
			if (idx == sz(ival.at(next_one))) break;
			lst = cur = nxt.at(max(ival.at(next_one).at(idx).f, need_r));
			good = 1;
			

		}
		

	}
	return ival;
}

str rev(str S) {
	reverse(all(S));
	return S;
}



tcT > struct RMQ {
	int level(int x) { return 31 - __builtin_clz(x); }
	V<T> v;
	V<vi> jmp;
	int cmb(int a, int b) {
		return v[a] == v[b] ? min(a, b) : (v[a] > v[b] ? a : b);
	}
	void init(const V<T> &_v) {
		v = _v;
		jmp = {vi(sz(v))};
		iota(all(jmp[0]), 0);
		for (int j = 1; 1 << j <= sz(v); ++j) {
			jmp.pb(vi(sz(v) - (1 << j) + 1));
			id7(i, sz(jmp[j]))
			jmp[j][i] = cmb(jmp[j - 1][i], jmp[j - 1][i + (1 << (j - 1))]);
		}
	}
	int index(int l, int r) {
		assert(l <= r);
		int d = level(r - l + 1);
		return cmb(jmp[d][l], jmp[d][r - (1 << d) + 1]);
	}
	T query(int l, int r) { return v[index(l, r)]; }
};



tcT > struct BIT {
	int N;
	V<T> data;
	void init(int _N) {
		N = _N;
		data.rsz(N);
	}
	void add(int p, T x) {
		for (++p; p <= N; p += p & -p) data[p - 1] += x;
	}
	T sum(int l, int r) { return sum(r + 1) - sum(l); }
	T sum(int r) {
		T s = 0;
		for (; r; r -= r & -r) s += data[r - 1];
		return s;
	}
	int lower_bound(T sum) {
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			int npos = pos + pw;
			if (npos <= N && data[npos - 1] < sum)
				pos = npos, sum -= data[pos - 1];
		}
		return pos;
	}
};

void solve(int N, str S) {
	auto id1 = id6(S);
	auto id3 = id6(rev(S));
	vi cum{0};
	each(c, S) cum.pb(cum.bk + (c == '1'));
	ll ans = 0;
	id7(i, N) { 

		for (auto [a, b] : id1.at(i)) {
			ckmin(b, N - 1);
			ans += cum.at(b + 1) - cum.at(a);
		}
	}
	dbg(id1);
	dbg("ANS END WITH 1", ans);
	id7(i, N) if (S.at(i) == '0') { 

		for (auto [a, b] : id3.at(N - 1 - i)) {
			ckmin(b, N - 1);
			

			ans += cum.at(N - a) - cum.at(N - 1 - b);
		}
	}
	dbg("ANS BEGIN WITH 1, END WITH 0", ans);
	const AR<int, 3> ID{-2, -2, -2};
	V<AR<int, 3>> query_l, query_r;
	vi tot_l, tot_r;
	RMQ<int> id14, id4;
	{
		vi tmp(N);
		int cnt = 0;
		id11(i, N) {
			if (S.at(i) == '0') ++cnt;
			else cnt = 0;
			tmp.at(i) = cnt;
		}
		id14.init(tmp);
	}
	{
		vi tmp(N);
		int cnt = 0;
		id7(i, N) {
			if (S.at(i) == '0') ++cnt;
			else cnt = 0;
			tmp.at(i) = cnt;
		}
		id4.init(tmp);
	}
	vi cum_zero{0};
	each(c,S) cum_zero.pb(cum_zero.bk + (c == '0'));
	auto id12 = [&](int l, int r) {
		return cum_zero.at(r+1) - cum_zero.at(l);
	};
	
	id7(r, N) {
		if (S.at(r) == '1') continue;
		int l = r;
		while (r < N && S.at(r) == '0') ++r;
		--r;
		{
			

			int L = fstTrue(0, l - 1, [&](int x) {
				return id14.query(x, l - 1) < r - l + 1;
			});
			int R = lstTrue(r + 1, N - 1, [&](int x) {
				return id4.query(r + 1, x) <= r - l + 1;
			});
			tot_l.pb(id12(L, l));
			query_l.pb({L, 2 * l - r - 1, l - 1});
			tot_r.pb(id12(r, R));
			query_r.pb({2 * r - l + 1, R, r + 1});
			

			

			

		}
		FOR(small_r, l, r) {
			int L = fstTrue(0, l - 1, [&](int x) {
				return id14.query(x, l - 1) < small_r - l + 1;
			});
			tot_l.pb(id12(L, l));
			query_l.pb({L, 2 * l - small_r - 1, l - 1});
			tot_r.pb(1);
			query_r.pb(ID);
			

		}
		FOR(small_l, l + 1, r + 1) {
			int R = lstTrue(r + 1, N - 1, [&](int x) {
				return id4.query(r + 1, x) <= r - small_l + 1;
			});
			tot_l.pb(1);
			query_l.pb(ID);
			tot_r.pb(id12(r, R));
			query_r.pb({2 * r - small_l + 1, R, r + 1});
			dbg(small_l, r, query_l.bk, query_r.bk);
		}
	}
	vi ans_l(sz(query_l)), ans_r(sz(query_r));
	{ 

		V<AR<int, 4>> offline_queries;
		id7(i, sz(query_l)) if (query_l.at(i) != ID) {
			auto [l, r, pos] = query_l.at(i);
			if (l > r) continue;
			offline_queries.pb({l - 1, pos, -1, i});
			offline_queries.pb({r, pos, 1, i});
		}
		sor(offline_queries);
		

		BIT<int> B;
		B.init(N + 5);
		int nxt = 0;
		for (auto [l, pos, mul, id] : offline_queries) {
			for (; nxt <= l; ++nxt)
				if (S.at(nxt) == '0') {
					for (auto [a, b] : id1.at(nxt)) {
						assert(a <= b);
						B.add(a, 1);
						B.add(b + 1, -1);
					}
					

				}
			ans_l.at(id) += mul * B.sum(pos + 1);
		}
	}
	{ 

		V<AR<int, 4>> offline_queries;
		id7(i, sz(query_r)) if (query_r.at(i) != ID) {
			auto [l, r, pos] = query_r.at(i);
			if (l > r) continue;
			offline_queries.pb({N - 2 - r, N - 1 - pos, -1, i});
			offline_queries.pb({N - 1 - l, N - 1 - pos, 1, i});
		}
		sor(offline_queries);
		BIT<int> B;
		B.init(N + 5);
		int nxt = 0;
		for (auto [l, pos, mul, id] : offline_queries) {
			for (; nxt <= l; ++nxt)
				if (S.at(N - 1 - nxt) == '0') {
					for (auto [a, b] : id3.at(nxt)) {
						B.add(a, 1);
						B.add(b + 1, -1);
					}
				}
			ans_r.at(id) += mul * B.sum(pos + 1);
		}
	}
	

	

	each(t, ans_l) assert(t >= 0);
	each(t, ans_r) assert(t >= 0);
	dbg("ans before", ans);
	id7(i, sz(ans_l)) {
		auto bad_l = tot_l.at(i) - ans_l.at(i);
		auto bad_r = tot_r.at(i) - ans_r.at(i);
		

		ans += (ll)tot_l.at(i) * tot_r.at(i) - (ll)bad_l * bad_r;
	}
	ps(ans);
}

int main() {
	setIO();
	

	

	

	

	

	

	

	int TC;
	re(TC);
	FOR(i, 1, TC + 1) {
		int N; str S;
		re(N,S);
		solve(N,S);
	}
}


