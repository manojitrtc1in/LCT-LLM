

















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
tcT > constexpr bool id11 = is_iterable<T>::value;



tcT, class = void > struct is_readable : false_type {};
tcT > struct is_readable<T, typename std::enable_if_t<is_same_v<
								decltype(cin >> declval<T &>()), istream &>>>
	: true_type {};
tcT > constexpr bool id0 = is_readable<T>::value;





tcT, class = void > struct is_printable : false_type {};
tcT > struct is_printable<T, typename std::enable_if_t<is_same_v<
								 decltype(cout << declval<T>()), ostream &>>>
	: true_type {};
tcT > constexpr bool id3 = is_printable<T>::value;
} 


inline namespace Input {
tcT > constexpr bool id10 = !id0<T> && id11<T>;
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

	int id7;                                                           \
	re(id7);

	ints(id7);                                                         \
	decrement(id7);
} 


inline namespace ToString {
tcT > constexpr bool id4 = !id3<T> && id11<T>;



tcT > typename enable_if<id3<T>, str>::type ts(T v) {
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
	typename enable_if<id4<T>, str>::type ts(T v); 

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
tcT > typename enable_if<id4<T>, str>::type ts(T v) {
	return "{" + ts_sep(v, ", ") + "}";
}



template <int, class T>
typename enable_if<!id4<T>, vs>::type id8(const T &v) {
	return {ts(v)};
}
template <int lev, class T>
typename enable_if<id4<T>, vs>::type id8(const T &v) {
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
template <int lev, class T> void id12(const T &t) {
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




using ul = uint64_t;
using L = __uint128_t;
struct FastMod {
	ul b, m;
	FastMod(ul b) : b(b), m(-1ULL / b) {}
	ul reduce(ul a) {
		ul q = (ul)((__uint128_t(m) * a) >> 64), r = a - q * b;
		return r - (r >= b) * b;
	}
};



template <int id> struct Mint {
	static FastMod MF;
	static int mod() { return (int)MF.b; }
	static void set_mod(int m) {
		assert(1 <= m);
		MF = FastMod(m);
	}
	int v;
	explicit operator int() const {
		return v;
	} 

	Mint() { v = 0; }
	Mint(ll _v) {
		v = int((-mod() < _v && _v < mod()) ? _v : _v % mod());
		if (v < 0) v += mod();
	}
	friend bool operator==(const Mint &a, const Mint &b) { return a.v == b.v; }
	friend bool operator!=(const Mint &a, const Mint &b) { return !(a == b); }
	friend bool operator<(const Mint &a, const Mint &b) { return a.v < b.v; }
	friend void re(Mint &a) {
		ll x;
		re(x);
		a = Mint(x);
	}
	friend str ts(Mint a) { return ts(a.v); }

	Mint &operator+=(const Mint &m) {
		if ((v += m.v) >= mod()) v -= mod();
		return *this;
	}
	Mint &operator-=(const Mint &m) {
		if ((v -= m.v) < 0) v += mod();
		return *this;
	}
	Mint &operator*=(const Mint &m) {
		v = (int)MF.reduce((ll)v * m.v);
		return *this;
	}
	Mint &operator/=(const Mint &m) { return (*this) *= inv(m); }
	friend Mint pow(Mint a, ll p) {
		Mint ans = 1;
		assert(p >= 0);
		for (; p; p /= 2, a *= a)
			if (p & 1) ans *= a;
		return ans;
	}
	friend Mint inv(const Mint &a) {
		assert(a.v != 0);
		return pow(a, mod() - 2);
	}

	Mint operator-() const { return Mint(-v); }
	Mint &operator++() { return *this += 1; }
	Mint &operator--() { return *this -= 1; }
	friend Mint operator+(Mint a, const Mint &b) { return a += b; }
	friend Mint operator-(Mint a, const Mint &b) { return a -= b; }
	friend Mint operator*(Mint a, const Mint &b) { return a *= b; }
	friend Mint operator/(Mint a, const Mint &b) { return a /= b; }
};
template <int id> FastMod Mint<id>::MF = FastMod(1);
using Mi = Mint<0>;



template <int MOD, int RT> struct mint {
	static const int mod = MOD;
	static constexpr mint rt() { return RT; } 

	int v;
	explicit operator int() const {
		return v;
	} 

	mint() : v(0) {}
	mint(ll _v) {
		v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
		if (v < 0) v += MOD;
	}
	bool operator==(const mint &o) const { return v == o.v; }
	friend bool operator!=(const mint &a, const mint &b) { return !(a == b); }
	friend bool operator<(const mint &a, const mint &b) { return a.v < b.v; }
	friend void re(mint &a) {
		ll x;
		re(x);
		a = mint(x);
	}
	friend str ts(mint a) { return ts(a.v); }

	mint &operator+=(const mint &o) {
		if ((v += o.v) >= MOD) v -= MOD;
		return *this;
	}
	mint &operator-=(const mint &o) {
		if ((v -= o.v) < 0) v += MOD;
		return *this;
	}
	mint &operator*=(const mint &o) {
		v = int((ll)v * o.v % MOD);
		return *this;
	}
	mint &operator/=(const mint &o) { return (*this) *= inv(o); }
	friend mint pow(mint a, ll p) {
		mint ans = 1;
		assert(p >= 0);
		for (; p; p /= 2, a *= a)
			if (p & 1) ans *= a;
		return ans;
	}
	friend mint inv(const mint &a) {
		assert(a.v != 0);
		return pow(a, MOD - 2);
	}

	mint operator-() const { return mint(-v); }
	mint &operator++() { return *this += 1; }
	mint &operator--() { return *this -= 1; }
	friend mint operator+(mint a, const mint &b) { return a += b; }
	friend mint operator-(mint a, const mint &b) { return a -= b; }
	friend mint operator*(mint a, const mint &b) { return a *= b; }
	friend mint operator/(mint a, const mint &b) { return a /= b; }
};

using mi = mint<MOD, 5>; 

using vmi = V<mi>;
using pmi = pair<mi, mi>;
using vpmi = V<pmi>;

V<V<Mi>> scmb; 

void genComb(int SZ) {
	scmb.assign(SZ, V<Mi>(SZ));
	scmb[0][0] = 1;
	FOR(i, 1, SZ)
	id5(j, i + 1) scmb[i][j] = scmb[i - 1][j] + (j ? scmb[i - 1][j - 1] : 0);
}








tcT > void fft(V<T> &A, bool inv = 0) { 

	int n = sz(A);
	assert((T::mod - 1) % n == 0);
	V<T> B(n);
	for (int b = n / 2; b; b /= 2, swap(A, B)) { 

		T w = pow(T::rt(), (T::mod - 1) / n * b), m = 1;
		for (int i = 0; i < n; i += b * 2, m *= w) id5(j, b) {
				T u = A[i + j], v = A[i + j + b] * m;
				B[i / 2 + j] = u + v;
				B[i / 2 + j + n / 2] = u - v;
			}
	}
	if (inv) {
		reverse(1 + all(A));
		T z = T(1) / T(n);
		each(t, A) t *= z;
	}
} 

tcT > V<T> mul(V<T> A, V<T> B) {
	if (!min(sz(A), sz(B))) return {};
	int s = sz(A) + sz(B) - 1, n = 1;
	for (; n < s; n *= 2)
		;
	bool eq = A == B;
	A.rsz(n), fft(A);
	if (eq) B = A; 

	else B.rsz(n), fft(B);
	id5(i, n) A[i] *= B[i];
	fft(A, 1);
	A.rsz(s);
	return A;
}
template <class M, class T> V<M> mulMod(V<T> x, V<T> y) {
	auto con = [](const V<T> &v) {
		V<M> w(sz(v));
		id5(i, sz(v)) w[i] = (int)v[i];
		return w;
	};
	return mul(con(x), con(y));
} 

tcT > V<T> MUL(const V<T> &A, const V<T> &B) {
	using m0 = mint<(119 << 23) + 1, 62>;
	auto c0 = mulMod<m0>(A, B);
	using m1 = mint<(5 << 25) + 1, 62>;
	auto c1 = mulMod<m1>(A, B);
	using m2 = mint<(7 << 26) + 1, 62>;
	auto c2 = mulMod<m2>(A, B);
	int n = sz(c0);
	V<T> res(n);
	m1 r01 = 1 / m1(m0::mod);
	m2 r02 = 1 / m2(m0::mod), r12 = 1 / m2(m1::mod);
	id5(i, n) { 

		int a = c0[i].v, b = ((c1[i] - a) * r01).v,
			c = (((c2[i] - a) * r02 - b) * r12).v;
		res[i] = (T(c) * m1::mod + b) * m0::mod + a; 

	}
	return res;
}

int main() {
	

	setIO();
	ints(N, M);
	Mi::set_mod(M);
	

	vi P(N);

	re(P);
	

	

	vb used(N + 1);
	used.at(0) = 1;
	genComb(N + 5);
	V<Mi> fac(N + 1);
	fac.at(0) = 1;
	FOR(i, 1, N + 1) fac.at(i) = i * fac.at(i - 1);
	auto get_comb = [&](int hi, int lo, int mid) {
		return scmb.at(hi - lo).at(mid - lo) * fac.at(mid);
	};
	V<V<Mi>> to_add(N + 1);
	id5(i, N + 1) { to_add.at(i).rsz(N + 1 - i); }
	auto shift = [&](V<Mi> v, int l, int r) {
		v.ins(begin(v), l, 0);
		id5(i, sz(v)) to_add.at(r - l).at(i) += v.at(i);
		

		

		

		

		

		

	};
	int id2 = 0;
	id5(i, N) {
		dbg("DOING", i);
		

		


		

		

		


		

		


		

		auto must_start = [&](int x) { return used.at(x - 1) && !used.at(x); };
		int num_unused = N - i;
		int id1 = 0;
		FOR(j, 1, N + 1) id1 += must_start(j);
		int ways_a = 0, ways_b = 0;
		FOR(start, 1, P.at(i)) if (!used.at(start)) {
			V<Mi> ways(num_unused + 1);
			if (must_start(start)) {
				if (i && start == P.at(i - 1) + 1) {
					FOR(comps, id1 - 1, num_unused) {
						ways.at(1 + comps) =
							get_comb(num_unused - 1, id1 - 1, comps);
					}
					shift(ways, id2 - 1, i);
				} else {
					++ways_a;
					

				}
				

			} else {
				++ways_b;
				

			}
		}
		if (ways_a) {
			V<Mi> ways(num_unused + 1);
			FOR(comps, id1 - 1, num_unused) {
				ways.at(1 + comps) =
					ways_a *
					get_comb(num_unused - 1, id1 - 1, comps);
			}
			shift(ways, id2, i);
		}
		if (ways_b) {
			V<Mi> ways(num_unused + 1);
			FOR(comps, id1, num_unused) {
				ways.at(1 + comps) =
					ways_b * get_comb(num_unused - 1, id1, comps);
			}
			shift(ways, id2, i);
		}
		if (i && P.at(i) == P.at(i - 1) + 1) {

		} else {
			++id2;
		}
		used.at(P.at(i)) = 1;
	}
	ROF(i, 1, N + 1) {
		id5(j, sz(to_add.at(i))) {
			to_add.at(i - 1).at(j) += to_add.at(i).at(j);
			to_add.at(i - 1).at(j + 1) += to_add.at(i).at(j);
		}
	}
	auto id9 = to_add.at(0);
	FOR(i, 1, N + 1) {
		pr(id9.at(i), ' ');
		FOR(j, i + 1, N + 1) {
			id9.at(j) -= id9.at(i) * scmb.at(N - i).at(j - i);
		}
	}
	

}

