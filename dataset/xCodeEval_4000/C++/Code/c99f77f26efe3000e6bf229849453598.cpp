#include "bits/stdc++.h" 

using namespace std; 


using ll = long long;
using ld = long double;
using db = double;
using str = string;
using ull = unsigned ll;

using pi = pair<ll, ll>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
using pld = pair<ld, ld>;

using vi = vector<ll>;
using vd = vector<db>;
using vld = vector<ld>;
using vl = vector<ll>;
using vs = vector<str>;
using vc = vector<char>;
using vpi = vector<pl>;
using vpl = vector<pl>;
using vpd = vector<pd>;
using vvi = vector<vl>;
using vvl = vector<vl>;
using vvc = vector<vc>;

template<class T> using vt = vector<T>;
template<class T> using vvt = vector<vt<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define si(a) ((int)(a).size())
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define rs resize
#define ins insert
#define nl "\n"
#define tolower(a) transform(all(a), a.begin(), ::tolower)
#define toupper(a) transform(all(a), a.begin(), ::toupper)
#define sor(a) sort(all(a))
#define res(a, n) a.rs(n); re(a)
#define int long long
#define sort_by(x, y) sort(all(x), [&](const auto& a, const auto& b) { return y; } )

#define rep(i, a, b) for(auto i = (a); i < (b); ++i)
#define rop(i, a) rep(i, 0, a)
#define per(i, a, b) for(auto i = (b) - 1; i >= (a); --i)
#define por(i, a) per(i, 0, a)
#define trav(i, a) for (auto& i: a)



template<class A> void re(complex<A>& c);
template<class A, class B> void re(pair<A, B>& p);
template<class A> void re(vector<A>& v);
template<class A, size_t SZ> void re(array<A, SZ>& a);
 
template<class T> void re(T& x) { cin >> x; }
void re(db& d) { string t; re(t); d = stod(t); }
void re(ld& d) { string t; re(t); d = stold(t); }
template<class H, class... T> void re(H& h, T&... t) { re(h); re(t...); }
 
template<class A> void re(complex<A>& c) { A a, b; re(a, b); c = {a, b}; }
template<class A, class B> void re(pair<A, B>& p) { re(p.f, p.s); }
template<class A> void re(vector<A>& x) { trav(i, x) re(i); }
template<class A, size_t SZ> void re(array<A, SZ>& x) { trav(i, x) re(i); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(rng); }



#define ts to_string
string ts(char c) { return string(1, c); }
string ts(bool b) { return b ? "true" : "false"; }
string ts(const char* s) { return (string)s; }
string ts(string s) { return s; }
template<class A> string ts(complex<A> c) { stringstream ss; ss << c; return ss.str(); }
string ts(vector<bool> v) { string res = "{"; for(int i = 0; i < si(v); i++) { res += char('0' + v[i]); } res += "}"; return res; }
template<size_t SZ> string ts(bitset<SZ> b) { string res = ""; for(int i = 0; i < (ll)SZ; i++) { res += char('0' + b[i]); } return res; }
template<class A, class B> string ts(pair<A, B> p) { return "(" + ts(p.f) + ", " + ts(p.s) + ")"; }
template<class T> string ts(T v) { bool fst = 1; string res = "{"; for(const auto& x: v) { if(!fst) { res += ", "; } fst = 0; res += ts(x); } res += "}"; return res; }
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) { cerr << ts(h); if(sizeof...(t)) { cerr << ", "; } DBG(t...); }
void EDBG(string names) { names = names; }
template<class H, class... T> void EDBG(string names, H h, T... t) { auto pos = names.find(','); auto first_name = names.substr(0, pos); auto rest = names.substr(pos + 1); while(rest.front() == ' ') { rest = rest.substr(1); } cerr << "[" << first_name << "]: [" << ts(h) << "]" << nl; EDBG(rest, t...); }

#ifdef LOCAL 

#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#define edbg(...) EDBG(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#define edbg(...) 7
#endif



template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { 
	pr(h); pr(t...); }
void ps() { pr("\n"); } 

template<class H, class... T> void ps(const H& h, const T&... t) { 
	pr(h); if(sizeof...(t)) pr(" "); ps(t...); }



void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void unsyncIO() { ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(20), cerr << fixed << setprecision(20); }
void setIO(string s = "") { unsyncIO(); if(si(s)) { setIn(s + ".in"); setOut(s + ".out"); } }

template<class T> void uni(vector<T>& v) { sort(all(v)); v.erase(unique(all(v)), end(v)); }
ll cdiv(const ll& a, const ll& b) { return a / b + ((a ^ b) > 0 && a % b); } 

ll fdiv(const ll& a, const ll& b) { return a / b - ((a ^ b) < 0 && a % b); } 

int fstTrue(function<bool(int)> f, int lo, int hi) { for(hi++; lo < hi;) { int mid = fdiv((lo + hi), 2); f(mid) ? hi = mid : lo = mid + 1; } return lo; }
int lstTrue(function<bool(int)> f, int lo, int hi) { for(lo--; lo < hi;) { int mid = fdiv((lo + hi + 1), 2); f(mid) ? lo = mid : hi = mid - 1; } return lo; }
ll power(ll a, ll b, ll c) { ll res = 1; a %= c; while(b > 0) { if(b & 1) res = res * a % c; a = a * a % c; b >>= 1; } return res; }
ll power(ll a, ll b) { ll res = 1; while(b > 0) { if(b & 1) res = res * a; a = a * a; b >>= 1; } return res; }
ull modMul(ull a, ull b, const ull mod) { ll ret = a * b - mod * (ull)((ld)a * b / mod); return ret + ((ret < 0) - (ret >= (ll)mod)) * mod; }
ull modPow(ull a, ull b, const ull mod) { if(b == 0) { return 1; } ull res = modPow(a, b / 2, mod); res = modMul(res, res, mod); return b & 1 ? modMul(res, a, mod) : res; }
bool prime(ull n) { if(n < 2 || n % 6 % 4 != 1) { return n - 2 < 2; } ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022}, s = __builtin_ctzll(n - 1), d = n >> s; trav(i, A) { ull p = modPow(i, d, n), a = s; while(p != 1 && p != n - 1 && i % n && a--) { p = modMul(p, p, n); } if(p != n - 1 && a != s) { return false; } } return true; }
ll pct(ll x) { x = (x & 0x5555555555555555LL) + ((x >> 1) & 0x5555555555555555LL); x = (x & 0x3333333333333333LL) + ((x >> 2) & 0x3333333333333333LL); x = (x & 0x0F0F0F0F0F0F0F0FLL) + ((x >> 4) & 0x0F0F0F0F0F0F0F0FLL); return (x * 0x0101010101010101LL) >> 56; }



const int MX = 2e5 + 5;
const long long INF = 1e18;
const long long MOD = 1e9 + 7; 

const long double PI = acos((ld)-1);
const long double EPS = 1e-18;

const int base = 1e9,
	  base_digits = 9;
struct bigint {
	vi z;
	int sign;
	bigint(): sign(1) {}
	bigint(ll v) {
		* this = v;
	}
	bigint & operator = (ll v) {
		sign = v < 0 ? -1 : 1;
		v *= sign;
		z.clear();
		for(; v; v /= base) z.pb(v % base);
		return *this;
	}
	bigint(const str & s) {
		read(s);
	}

	bigint & operator += (const bigint & other) {

		if(sign == other.sign) {
			for(int i = 0, carry = 0; i < si(other.z) || carry; ++i) {
				if(i == si(z)) z.pb(0);
				z[i] += carry + (i < si(other.z) ? other.z[i] : 0);
				carry = z[i] >= base;
				if(carry) z[i] -= base;
			}
		} else if(other != 0 ) * this -= -other;
		return *this;
	}
	friend bigint operator + (bigint a,
			const bigint & b) {
		return a += b;
	}
	bigint & operator -= (const bigint & other) {
		if(sign == other.sign) {
			if((sign == 1 && * this >= other) || (sign == -1 && * this <= other)) {
				for(int i = 0, carry = 0; i < si(other.z) || carry; ++i) {
					z[i] -= carry + (i < si(other.z) ? other.z[i] : 0);
					carry = z[i] < 0;
					if(carry) z[i] += base;
				}
				trim();
			} else {
				* this = other - * this;
				this -> sign = -this -> sign;
			}
		} else *this += -other;
		return *this;
	}
	friend bigint operator - (bigint a,
			const bigint & b) {
		return a -= b;
	}

	bigint & operator *= (int v) {
		if(v < 0) sign = -sign, v = -v;
		for(int i = 0, carry = 0; i < si(z) || carry; ++i) {
			if(i == si(z)) z.pb(0);
			ll cur = (ll) z[i] * v + carry;
			carry = cur / base;
			z[i] = cur % base;
		}
		trim();
		return *this;
	}
	bigint operator * (int v) const {
		return bigint( * this) *= v;
	}
	friend pair<bigint, bigint> divmod(const bigint & a1,
			const bigint & b1) {
		int norm = base / (b1.z.back() + 1);
		bigint a = a1.abs() * norm, b = b1.abs() * norm, q, r;
		q.z.rs(si(a.z));
		for(int i = si(a.z) - 1; i >= 0; --i) {
			r *= base;
			r += a.z[i];
			int s1 = si(b.z) < si(r.z) ? r.z[si(b.z)] : 0;
			int s2 = si(b.z) - 1 < si(r.z) ? r.z[si(b.z) - 1] : 0;
			int d = ((ll) s1 * base + s2) / b.z.back();
			r -= b * d;
			while (r < 0) r += b, --d;
			q.z[i] = d;
		}
		q.trim();
		r.trim();
		return {
			q,
				r / norm
		};
	}
	friend bigint sqrt(const bigint & a1) {
		bigint a = a1;
		while (!si(a.z) || si(a.z) & 1) a.z.pb(0);
		int n = si(a.z), firstDigit = ::sqrt((db) a.z[n - 1] * base + a.z[n - 2]);
		int norm = base / (firstDigit + 1);
		a *= norm;
		a *= norm;
		while (!si(a.z) || si(a.z) & 1) a.z.pb(0);
		bigint r = (ll) a.z[n - 1] * base + a.z[n - 2];
		firstDigit = (int)::sqrt((db) a.z[n - 1] * base + a.z[n - 2]);
		int q = firstDigit;
		bigint res;
		for(int j = n / 2 - 1; j >= 0; --j) {
			for(;; --q) {
				bigint r1 = (r - (res * 2 * base + q) * q) * base * base +
					(j > 0 ? (ll) a.z[2 * j - 1] * base + a.z[2 * j - 2] : 0);
				if(r1 >= 0) {
					r = r1;
					break;
				}
			}
			res *= base;
			res += q;
			if(j > 0) {
				int d1 = si(res.z) + 2 < si(r.z) ? r.z[si(res.z) + 2] : 0;
				int d2 = si(res.z) + 1 < si(r.z) ? r.z[si(res.z) + 1] : 0;
				int d3 = si(res.z) < si(r.z) ? r.z[si(res.z)] : 0;
				q = ((ll) d1 * base * base + (ll) d2 * base + d3) / (firstDigit * 2);
			}
		}
		res.trim();
		return res / norm;
	}
	bigint operator / (const bigint & v) const {
		return divmod( * this, v).f;
	}
	bigint operator % (const bigint & v) const {
		return divmod( * this, v).s;
	}
	bigint & operator /= (int v) {
		if(v < 0) sign = -sign, v = -v;
		for(int i = si(z) - 1, rem = 0; i >= 0; --i) {
			ll cur = z[i] + rem * (ll) base;
			z[i] = cur / v;
			rem = cur % v;
		}
		trim();
		return *this;
	}
	bigint operator / (int v) const {
		return bigint( * this) /= v;
	}
	int operator % (int v) const {
		if(v < 0) v = -v;
		int m = 0;
		for(int i = si(z) - 1; i >= 0; --i) m = (z[i] + m * (ll) base) % v;
		return m * sign;
	}
	bigint & operator *= (const bigint & v) {
		return *this = * this * v;
	}
	bigint & operator /= (const bigint & v) {
		return *this = * this / v;
	}

	bool operator < (const bigint & v) const {
		if(sign != v.sign) return sign < v.sign;
		if(si(z) != si(v.z)) return si(z) * sign < si(v.z) * v.sign;
		for(int i = si(z) - 1; i >= 0; --i) if(z[i] != v.z[i]) return z[i] * sign < v.z[i] * sign;
		return 0;
	}
	bool operator > (const bigint & v) const {
		return v < * this;
	}
	bool operator <= (const bigint & v) const {
		return !(v < * this);
	}
	bool operator >= (const bigint & v) const {
		return !( * this < v);
	}
	bool operator == (const bigint & v) const {
		return !( * this < v) && !(v < * this);
	}
	bool operator != (const bigint & v) const {
		return *this < v || v < * this;
	}
	void trim() {
		while (si(z) && z.back() == 0) z.pop_back();
		if(!si(z)) sign = 1;
	}
	bool isZero() const {
		return !si(z);
	}
	friend bigint operator - (bigint v) {
		if(si(v.z)) v.sign = -v.sign;
		return v;
	}
	bigint abs() const {
		return sign == 1 ? * this : - * this;
	}
	ll longValue() const {
		ll res = 0;
		for(int i = si(z) - 1; i >= 0; --i) res = res * base + z[i];
		return res * sign;
	}
	friend bigint gcd(const bigint & a,
			const bigint & b) {
		return b.isZero() ? a : gcd(b, a % b);
	}
	friend bigint lcm(const bigint & a,
			const bigint & b) {
		return a / gcd(a, b) * b;
	}

	void read(const str & s) {
		sign = 1;
		z.clear();
		int pos = 0;
		while (pos < si(s) && (s[pos] == '-' || s[pos] == '+')) {
			if(s[pos] == '-') sign = -sign;
			++pos;
		}
		for(int i = si(s) - 1; i >= pos; i -= base_digits) {
			int x = 0;
			for(int j = max(pos, i - base_digits + 1); j <= i; j++)
				x = x * 10 + s[j] - '0';
			z.pb(x);
		}
		trim();
	}
	friend istream & operator >> (istream & is, bigint & v) {
		str s;
		is >> s;
		v.read(s);
		return is;
	}
	friend ostream & operator << (ostream & os, const bigint & v) {
		if(v.sign == -1) os << '-';
		os << (!si(v.z) ? 0 : v.z.back());
		for(int i = si(v.z) - 1 - 1; i >= 0; --i) os << setw(base_digits) << setfill('0') << v.z[i];
		return os;
	}
	static vi convert_base(const vi & a, int old_digits, int new_digits) {
		vl p(max(old_digits, new_digits) + 1);
		p[0] = 1;
		for(int i = 1; i < si(p); ++i) p[i] = p[i - 1] * 10;
		vi ans;
		ll cur = 0;
		int cur_digits = 0;
		for(int v: a) {
			cur += v * p[cur_digits];
			cur_digits += old_digits;
			while (cur_digits >= new_digits) {
				ans.pb(cur % p[new_digits]);
				cur /= p[new_digits];
				cur_digits -= new_digits;
			}
		}
		ans.pb(cur);
		while (si(ans) && ans.back() == 0) ans.pop_back();
		return ans;
	}
	static vl karatMul(const vl & a, const vl & b) {
		int n = si(a);
		vl ans(2 * n);
		if(n <= 32) {
			for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) ans[i + j] += a[i] * b[j];
			return ans;
		}
		int k = n / 2;
		vl a1(begin(a), begin(a) + k), a2(k + all(a));
		vl b1(begin(b), begin(b) + k), b2(k + all(b));
		vl a1b1 = karatMul(a1, b1), a2b2 = karatMul(a2, b2);
		for(int i = 0; i < k; ++i) a2[i] += a1[i], b2[i] += b1[i];
		vl r = karatMul(a2, b2);
		for(int i = 0; i < si(a1b1); ++i) r[i] -= a1b1[i];
		for(int i = 0; i < si(a2b2); ++i) r[i] -= a2b2[i];
		for(int i = 0; i < si(r); ++i) ans[i + k] += r[i];
		for(int i = 0; i < si(a1b1); ++i) ans[i] += a1b1[i];
		for(int i = 0; i < si(a2b2); ++i) ans[i + n] += a2b2[i];
		return ans;
	}
	bigint operator * (const bigint & v) const {
		if(min(si(z), si(v.z)) < 150) return mul_simple(v);
		bigint ans;
		vi a6 = convert_base(this -> z, base_digits, 6);
		vi b6 = convert_base(v.z, base_digits, 6);
		vl a(all(a6)), b(all(b6));
		while (si(a) < si(b)) a.pb(0);
		while (si(b) < si(a)) b.pb(0);
		while (si(a) & (si(a) - 1)) a.pb(0), b.pb(0);
		vl c = karatMul(a, b);
		ll cur = 0;
		for(int i = 0; i < si(c); ++i) {
			cur += c[i];
			ans.z.pb(cur % 1000000);
			cur /= 1000000;
		}
		ans.z = convert_base(ans.z, 6, base_digits);
		ans.trim();
		return ans;
	}
	bigint mul_simple(const bigint & v) const {
		bigint ans;
		ans.z.rs(si(z) + si(v.z));
		for(int i = 0; i < si(z); ++i)
			if(z[i]) {
				ll cur = 0;
				for(int j = 0; j < si(v.z) || cur; ++j) {
					cur += ans.z[i + j] + (ll) z[i] * (j < si(v.z) ? v.z[j] : 0);
					ans.z[i + j] = cur % base;
					cur /= base;
				}
			}
		ans.trim();
		return ans;
	}
	friend str ts(const bigint & v) {
		stringstream ss;
		ss << v;
		str s;
		ss >> s;
		return s;
	}
};

bigint n, hld = bigint("1"), cd;
string s = "1";

int32_t main() {
	setIO();

	re(n);
	if(n < 3) {
		ps(-1);
		return 0;
	}
	for(bigint i = 0; i < n - 1; i = i + 1) {
		s += '0';
	}
	

	hld = bigint(s);
	if(hld % 210 == 0) {
		cd = hld / 210;
	} else {
		cd = hld / 210 + 1;
	}
	ps(bigint("210") * cd);
}