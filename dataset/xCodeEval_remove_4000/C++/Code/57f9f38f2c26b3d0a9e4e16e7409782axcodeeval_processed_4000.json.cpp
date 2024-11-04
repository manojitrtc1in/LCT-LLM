


























using namespace std;








































































typedef long long int lli;
typedef double db;
typedef const char *cstr;
typedef string str;
typedef vec<int> vi;
typedef vec<vi> vvi;
typedef vec<lli> vl;
typedef vec<vl> vvl;
typedef vec<bool> vb;
typedef vec<vb> vvb;
typedef vec<char> vc;
typedef vec<vc> vvc;
typedef vec<str> vs;
typedef pr<int, int> pii;
typedef pr<lli, lli> pll;
typedef pr<db, db> pdd;
typedef vec<pii> vpii;
typedef vec<pll> vpll;
typedef vec<pdd> vpdd;
typedef map<int, int> mii;
typedef map<str, int> msi;
typedef map<char, int> mci;
typedef set<int> si;
typedef set<str> ss;
typedef que<int> qi;



int oo = (~0u) >> 1;
lli ooll = (~0ull) >> 1;
db inf = 1e+10;
db eps = 1e-10;
db gam = 0.5772156649015328606;
db pi = acos(-1.0);
int dx[] = { 1, 0, -1, 0, 1, -1, -1, 1, 0 };
int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1, 0 };
int MOD = 1000000007;



template<typename type> inline bool cmax(type &a, const type &b) {
	rtn a < b ? a = b, true : false;
}
template<typename type> inline bool cmin(type &a, const type &b) {
	rtn b < a ? a = b, true : false;
}
template<typename type> inline type sqr(const type &x) {
	rtn x * x;
}
template<typename type> inline type mod(const type &x) {
	rtn x % MOD;
}
inline int sgn(const db &x) {
	rtn (x > +eps) - (x < -eps);
}
inline int dbcmp(const db &a, const db &b) {
	rtn sgn(a - b);
}
template<typename type> inline pr<type, type> operator-(
		const pr<type, type> &x) {
	rtn mp(-x.x, -x.y);
}
template<typename type> inline pr<type, type> operator+(const pr<type, type> &a,
		const pr<type, type> &b) {
	rtn mp(a.x + b.x, a.y + b.y);
}
template<typename type> inline pr<type, type> operator-(const pr<type, type> &a,
		const pr<type, type> &b) {
	rtn mp(a.x - b.x, a.y - b.y);
}
template<typename type> inline pr<type, type> operator*(const pr<type, type> &a,
		const type &b) {
	rtn mp(a.x * b, a.y * b);
}
template<typename type> inline pr<type, type> operator/(const pr<type, type> &a,
		const type &b) {
	rtn mp(a.x / b, a.y / b);
}
template<typename type> inline pr<type, type>& operator-=(pr<type, type> &a,
		const pr<type, type> &b) {
	rtn a = a - b;
}
template<typename type> inline pr<type, type>& operator+=(pr<type, type> &a,
		const pr<type, type> &b) {
	rtn a = a + b;
}
template<typename type> inline pr<type, type>& operator*=(pr<type, type> &a,
		const type &b) {
	rtn a = a * b;
}
template<typename type> inline pr<type, type>& operator/=(pr<type, type> &a,
		const type &b) {
	rtn a = a / b;
}
template<typename type> inline type cross(const pr<type, type> &a,
		const pr<type, type> &b) {
	rtn a.x * b.y - a.y * b.x;
}
template<typename type> inline type dot(const pr<type, type> &a,
		const pr<type, type> &b) {
	rtn a.x * b.x + a.y * b.y;
}
template<typename type> inline type gcd(type a, type b) {
	if (b)
		whl((a %= b) && (b %= a));
	rtn a + b;
}
template<typename type> inline type lcm(type a, type b) {
	rtn a * b / gcd(a, b);
}
inline lli bin_pow(lli x, lli y) {
	lli z = 1;
	whl(y) {
		if (y & 1)
			z = mod(z * x);
		x = mod(sqr(x)), y >>= 1;
	}
	rtn z;
}
template<typename istream, typename first_type, typename second_type> inline istream& operator>>(
		istream &cin, pr<first_type, second_type> &x) {
	rtn cin >> x.x >> x.y;
}
template<typename ostream, typename first_type, typename second_type> inline ostream& operator<<(
		ostream &cout, const pr<first_type, second_type> &x) {
	rtn cout << x.x << " " << x.y;
}
template<typename istream, typename type> inline istream& operator>>(
		istream &cin, vec<type> &x) {
	rep(i,sz(x))
		cin >> x[i];
	rtn cin;
}
template<typename ostream, typename type> inline ostream& operator<<(
		ostream &cout, const vec<type> &x) {
	rep(i,sz(x))
		cout << x[i] << (i + 1 == sz(x) ? "" : " ");
	rtn cout;
}
inline ostream& pdb(int prcs, db x) {
	rtn cout << setprecision(prcs) << fixed << (sgn(x) ? (x) : 0);
}
template<typename type> inline void bit_inc(vec<type> &st, int x, type inc) {
	whl(x<sz(st))
		st[x] += inc, x |= x + 1;
}
template<typename type> inline type bit_sum(const vec<type> &st, int x) {
	type s = 0;
	whl(x>=0)
		s += st[x], x = (x & (x + 1)) - 1;
	rtn s;
}
template<typename type> inline type id0(const vec<type> &st, int k) {
	int x = 0, y = 0, z = 0;
	whl((1<<(++y))<=sz(st));
	rrep(i,y)
	{
		if ((x += 1 << i) > sz(st) || z + st[x - 1] > k)
			x -= 1 << i;
		else
			z += st[x - 1];
	}
	rtn x;
}
inline void make_set(vi &st) {
	rep(i,sz(st))
		st[i] = i;
}
inline int find_set(vi &st, int x) {
	int y = x, z;
	whl(y!=st[y])
		y = st[y];
	whl(x!=st[x])
		z = st[x], st[x] = y, x = z;
	rtn y;
}
inline bool union_set(vi &st, int a, int b) {
	a = find_set(st, a), b = find_set(st, b);
	rtn a != b ? st[a] = b, true : false;
}
inline void make_set(vpii &st) {
	rep(i,sz(st))
		st[i] = mp(i, 1);
}
inline int find_set(vpii &st, int x) {
	int y = x, z;
	whl(y!=st[y].x)
		y = st[y].x;
	whl(x!=st[x].x)
		z = st[x].x, st[x].x = y, x = z;
	rtn y;
}
inline bool union_set(vpii &st, int a, int b) {
	a = find_set(st, a), b = find_set(st, b);
	rtn a != b ?
			(st[a].y > st[b].y ? st[a].x = b, st[a].y += st[b].y : st[b].x = a, st[b].y +=
					st[a].y), true :
			false;
}
template<typename type> inline void merge(type &a, type &b) {
	if (sz(a) < sz(b))
		swap(a, b);
	whl(sz(b))
		a.ins(*b.begin()), b.ers(b.begin());
}



struct Initializer {

	Initializer() {
		ios::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
	}

	~Initializer() {
		runtime();
	}

} initializer;







typedef __gnu_cxx ::rope<char> rope;
template<typename key, typename value> class ext_map: public __gnu_pbds::tree<
		key, value, less<key>, __gnu_pbds ::rb_tree_tag,
		__gnu_pbds ::tree_order_statistics_node_update> {
};
template<typename key> class ext_set: public __gnu_pbds::tree<key,
		__gnu_pbds ::null_type, less<key>, __gnu_pbds ::rb_tree_tag,
		__gnu_pbds ::tree_order_statistics_node_update> {
};

inline pii find_set(map<pii, pii> &st, pii x) {
	if (!st.count(x)) {
		rtn st[x] = x;
	} else if (st[x] == x) {
		rtn x;
	} else {
		rtn st[x] = find_set(st, st[x]);
	}
}
inline bool union_set(map<pii, pii> &st, pii a, pii b) {
	a = find_set(st, a), b = find_set(st, b);
	rtn a != b ? st[a] = b, true : false;
}

int n;
vpii p(n);

void ins(vec<pr<pii, pii>> &cur, pr<pii, pii> cand, vec<pr<pii, pii>> &nxt) {
	rep(i,sz(cur))
	{
		auto c = cur[i];
		if (cand.x.x == cand.y.x) {
			if (c.x.x == c.y.x) {
				if (cand.x.x == c.x.x) {
					int x = cand.x.x;
					int fr = max(cand.x.y, c.x.y);
					int to = min(cand.y.y, c.y.y);
					if (fr <= to) {
						nxt.pb(mp(mp(x, fr), mp(x, to)));
					}
				}
			} else {
				if (c.x.y <= cand.y.y && c.x.y >= cand.x.y && cand.x.x <= c.y.x
						&& cand.x.x >= c.x.x) {
					auto p = mp(cand.x.x, c.x.y);
					nxt.pb(mp(p, p));
				}
			}
		} else {
			if (c.x.y == c.y.y) {
				if (cand.x.y == c.x.y) {
					int y = cand.x.y;
					int fr = max(cand.x.x, c.x.x);
					int to = min(cand.y.x, c.y.x);
					if (fr <= to) {
						nxt.pb(mp(mp(fr, y), mp(to, y)));
					}
				}
			} else {
				if (c.x.y <= cand.y.y && c.x.y >= cand.x.y && cand.x.x <= c.y.x
						&& cand.x.x >= c.x.x) {
					auto p = mp(cand.x.x, c.x.y);
					nxt.pb(mp(p, p));
				}
			}
		}
	}
}

bool check(int t) {
	map<pii, pii> st;
	rep(i,n)
	{
		rep(j,n)
		{
			if (p[i].x == p[j].x && abs(p[i].y - p[j].y) <= t) {
				union_set(st, p[i], p[j]);
			}
			if (p[i].y == p[j].y && abs(p[i].x - p[j].x) <= t) {
				union_set(st, p[i], p[j]);
			}
		}
	}
	vec<vpii> grp;
	rep(i,n)
	{
		if (find_set(st, p[i]) == p[i]) {
			grp.pb(vpii());
			rep(j,n)
			{
				if (find_set(st, p[j]) == p[i]) {
					grp.back().pb(p[j]);
				}
			}
		}
		if (sz(grp) > 4) {
			rtn false;
		}
	}
	prt(t);
	rep(i,sz(grp))
	{
		prt(mp(i,grp[i]));
	}
	if (sz(grp) == 1) {
		rtn true;
	} else if (sz(grp) == 2) {
		auto &a = grp[0];
		auto &b = grp[1];
		rep(i,sz(a))
		{
			rep(j,sz(b))
			{
				if (a[i].x == b[j].x) {
					if (abs(a[i].y - b[j].y) <= t * 2) {
						rtn true;
					}
				} else if (a[i].y == b[j].y) {
					if (abs(a[i].x - b[j].x) <= t * 2) {
						rtn true;
					}
				} else if (abs(a[i].x - b[j].x) <= t
						&& abs(a[i].y - b[j].y) <= t) {
					rtn true;
				}
			}
		}
		rtn false;
	}
	si xs, ys;
	rep(i,n)
		xs.ins(p[i].x);
	rep(i,n)
		ys.ins(p[i].y);
	typedef map<int, si> idx_t;
	vec<pr<idx_t, idx_t>> idx(sz(grp));
	rep(i,sz(grp))
	{
		auto &g = grp[i];
		rep(j,sz(g))
		{
			idx[i].x[g[j].x].ins(g[j].y);
			idx[i].y[g[j].y].ins(g[j].x);
		}
	}
	auto check = [&](int x, int y) {
		rep(i,sz(grp))
		{
			bool yes = [&]() {
				if (idx[i].x.count(x)) {
					auto &st = idx[i].x[x];
					auto it = st.lb(y);
					if (it != st.end()) {
						if (abs(*it - y) <= t)
							rtn true;
					}
					if (it != st.begin()) {
						it--;
						if (abs(*it - y) <= t)
							rtn true;
					}
				}
				if (idx[i].y.count(y)) {
					auto &st = idx[i].y[y];
					auto it = st.lb(x);
					if (it != st.end()) {
						if (abs(*it - x) <= t)
							rtn true;
					}
					if (it != st.begin()) {
						it--;
						if (abs(*it - x) <= t)
							rtn true;
					}
				}
				rtn false;
			}();








			if (!yes)
				rtn false;
		}
		rtn true;
	};




	for (auto x : xs)
		for (auto y : ys) {
			if (check(x, y)) {
				prt(mp(x,y));
				rtn true;
			}
		}
	rtn false;
}

int main() {
	cin >> n;
	p = vpii(n);
	cin >> p;


	int l = 0, r = 2000000001;
	while (l + 1 != r) {
		int m = (lli(l) + lli(r)) / 2;
		if (check(m)) {
			r = m;
		} else {
			l = m;
		}
	}
	if (r == 2000000001) {
		r = -1;
	}
	cout << r << endl;
}
