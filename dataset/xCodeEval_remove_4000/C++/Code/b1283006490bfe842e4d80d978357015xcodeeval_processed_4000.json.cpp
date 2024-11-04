

















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
constexpr int id4(int x) { return p2(x) - 1; }

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
tcT > constexpr bool id8 = is_iterable<T>::value;



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
tcT > constexpr bool id7 = !id0<T> && id8<T>;
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

tcT > typename enable_if<id7<T>, void>::type
	  re(T &i); 

tcTU > void re(pair<T, U> &p) { re(p.f, p.s); }
tcT > typename enable_if<id7<T>, void>::type re(T &i) {
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

	int id5;                                                           \
	re(id5);

	ints(id5);                                                         \
	decrement(id5);
} 


inline namespace ToString {
tcT > constexpr bool id2 = !id1<T> && id8<T>;



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
tcT > typename enable_if<id8<T>, str>::type ts_sep(T v, str sep) {
	

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
typename enable_if<!id2<T>, vs>::type id6(const T &v) {
	return {ts(v)};
}
template <int lev, class T>
typename enable_if<id2<T>, vs>::type id6(const T &v) {
	if (lev == 0 || !sz(v)) return {ts(v)};
	vs res;
	for (const auto &t : v) {
		if (sz(res)) res.bk += ",";
		vs tmp = id6<lev - 1>(t);
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
template <int lev, class T> void id9(const T &t) {
	cerr << "\n\n" << ts_sep(id6<lev>(t), "\n") << "\n" << endl;
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







using T = db;		

const T EPS = 1e-9; 

using P = pair<T, T>;
using vP = V<P>;
using Line = pair<P, P>;
int sgn(T a) { return (a > EPS) - (a < -EPS); }
T sq(T a) { return a * a; }

bool close(const P &a, const P &b) {
	return sgn(a.f - b.f) == 0 && sgn(a.s - b.s) == 0;
}
T norm(const P &p) { return sq(p.f) + sq(p.s); }
T abs(const P &p) { return sqrt(norm(p)); }
T arg(const P &p) { return atan2(p.s, p.f); }
P conj(const P &p) { return P(p.f, -p.s); }
P perp(const P &p) { return P(-p.s, p.f); }
P dir(T ang) { return P(cos(ang), sin(ang)); }

P operator-(const P &l) { return P(-l.f, -l.s); }
P operator+(const P &l, const P &r) { return P(l.f + r.f, l.s + r.s); }
P operator-(const P &l, const P &r) { return P(l.f - r.f, l.s - r.s); }
P operator*(const P &l, const T &r) { return P(l.f * r, l.s * r); }
P operator*(const T &l, const P &r) { return r * l; }
P operator/(const P &l, const T &r) { return P(l.f / r, l.s / r); }
P operator*(const P &l, const P &r) {
	return P(l.f * r.f - l.s * r.s, l.s * r.f + l.f * r.s);
}
P operator/(const P &l, const P &r) { return l * conj(r) / norm(r); }
P &operator+=(P &l, const P &r) { return l = l + r; }
P &operator-=(P &l, const P &r) { return l = l - r; }
P &operator*=(P &l, const T &r) { return l = l * r; }
P &operator/=(P &l, const T &r) { return l = l / r; }
P &operator*=(P &l, const P &r) { return l = l * r; }
P &operator/=(P &l, const P &r) { return l = l / r; }

P unit(const P &p) { return p / abs(p); }
T dot(const P &a, const P &b) { return a.f * b.f + a.s * b.s; }
T dot(const P &p, const P &a, const P &b) { return dot(a - p, b - p); }
T cross(const P &a, const P &b) { return a.f * b.s - a.s * b.f; }
T cross(const P &p, const P &a, const P &b) { return cross(a - p, b - p); }
P reflect(const P &p, const Line &l) {
	P a = l.f, d = l.s - l.f;
	return a + conj((p - a) / d) * d;
}
P foot(const P &p, const Line &l) { return (p + reflect(p, l)) / (T)2; }
bool onSeg(const P &p, const Line &l) {
	return sgn(cross(l.f, l.s, p)) == 0 && sgn(dot(p, l.f, l.s)) <= 0;
}

ll solve(int tc) {
	ints(N);
	AR<int, 3> goal;
	re(goal);
	V<tuple<int, db, int>> tasks;
	rep(N) {
		int r, type, d;
		re(r, type, d);
		--type;
		tasks.pb({d, r + uniform_real_distribution<db>(0, 1.0 / 3)(rng), type});
	}
	sort(rall(tasks));
	auto greed = [&](AR<db, 3> adds) -> pair<ll, AR<int, 3>> {
		int j = 0;
		priority_queue<pair<db, int>> pq;
		ll ans = 0;
		AR<int, 3> cnt{};
		ROF(i, 1, goal[0] + goal[1] + goal[2] + 1) {
			for (; j < sz(tasks) && get<0>(tasks.at(j)) >= i; ++j) {
				pq.push({get<1>(tasks.at(j)) + adds.at(get<2>(tasks.at(j))),
						 get<2>(tasks.at(j))});
			}
			if (sz(pq)) {
				ans += (ll)floor(pq.top().f - adds.at(pq.top().s));
				++cnt.at(pq.top().s);
				pq.pop();
			}
		}
		return {ans, cnt};
	};
	

	

	AR<AR<db, 2>, 3> bounds;
	id3(i, 3) bounds[i] = {-1e10, 1e10};
	id3(i, 3) {
		AR<db, 3> to_test{-1e10, -1e10, -1e10};
		to_test.at(i) = 1e10;
		auto [_, cnt] = greed(to_test);
		if (cnt.at(i) < goal.at(i)) return -1;
	}
	

	

	

	while (true) {
		AR<db, 2> sums{};
		id3(i, 3) id3(j, 2) sums.at(j) += bounds.at(i).at(j);
		id3(i, 3) {
			

			

			ckmax(bounds.at(i).at(0), bounds.at(i).at(1) - sums.at(1));
			ckmin(bounds.at(i).at(1), bounds.at(i).at(0) - sums.at(0));
			if (bounds.at(i).at(1) - bounds.at(i).at(0) < 1e-8) return -1;
		}

		AR<db, 3> to_test;
		id3(i, 3) to_test.at(i) = (bounds.at(i).at(0) + bounds.at(i).at(1)) / 2;

		db avg = 0;
		each(t, to_test) avg += t;
		avg /= 3;
		each(t, to_test) t -= avg;
		dbg(to_test);
		

		

		

		

		

		

		

		

		

		AR<db, 3> adds{0, to_test[0], to_test[0] + to_test[1]};
		auto [ans, cnt] = greed(adds);
		if (cnt[0] + cnt[1] + cnt[2] != goal[0] + goal[1] + goal[2]) return -1;
		if (cnt == goal) { return ans; }
		id3(i, 3) {
			int j = (i + 1) % 3;
			if (cnt[i] > goal[i] && cnt[j] < goal[j]) {
				

				ckmax(bounds.at(i).at(0), to_test.at(i));
			} 

			if (cnt[i] < goal[i] && cnt[j] > goal[j]) {
				ckmin(bounds.at(i).at(1), to_test.at(i));
			}
		}
	}
}

int main() {
	setIO();
	int TC;
	re(TC);
	vl res;
	FOR(i, 1, TC + 1) res.pb(solve(i));
	each(t, res) ps(t);
}


