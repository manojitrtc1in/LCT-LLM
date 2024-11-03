




























using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<pll> vpll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<bool, ll> pbl;
typedef vector<pbl> vpbl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<pdd> vpdd;
typedef vector<string> vs;
mt19937 rng(2391);
template<typename A>
istream& operator>>(istream& fin, vector<A>& v)
{
	for (auto it = v.begin(); it != v.end(); ++it)
		fin >> *it;
	return fin;
}
template<typename A, typename B>
istream& operator>>(istream& fin, pair<A, B>& p)
{
	fin >> p.X >> p.Y;
	return fin;
}
template<typename A, typename B>
pair<A, B> operator+(const pair<A, B>& a, const pair<A, B>& b)
{
	return mp(a.X + b.X, a.Y + b.Y);
}
template<typename A, typename B>
pair<A, B> operator+=(pair<A, B>& a, const pair<A, B>& b)
{
	a.X += b.X;
	a.Y += b.Y;
	return a;
}
template<typename A, typename B>
pair<A, B> operator-(const pair<A, B>& a, const pair<A, B>& b)
{
	return mp(a.X - b.X, a.Y - b.Y);
}
template<typename A, typename B>
pair<A, B> operator-(const pair<A, B>& a)
{
	return mp(-a.X, -a.Y);
}
template<typename A, typename B>
pair<A, B>& operator++(pair<A, B>& a)
{
	++a.X;
	++a.Y;
	return a;
}
template<typename A, typename B>
pair<A, B>& operator--(pair<A, B>& a)
{
	--a.X;
	--a.Y;
	return a;
}
template<typename A>
vector<A>& operator++(vector<A>& a)
{
	for (auto it = a.begin(); it != a.end(); ++it)
		++*it;
	return a;
}
template<typename A>
vector<A>& operator--(vector<A>& a)
{
	for (auto it = a.begin(); it != a.end(); ++it)
		--*it;
	return a;
}
template<typename A, typename B>
pair<A, B> operator++(pair<A, B>& a, int)
{
	pair<A, B> b = a;
	++a;
	return b;
}
template<typename A, typename B>
pair<A, B> operator--(pair<A, B>& a, int)
{
	pair<A, B> b = a;
	--a;
	return b;
}
template<typename A>
vector<A>& operator++(vector<A>& a, int)
{
	vector<A> b = a;
	++a;
	return b;
}
template<typename A>
vector<A>& operator--(vector<A>& a, int)
{
	vector<A> b = a;
	--a;
	return b;
}
vvi id29(const vpii& e, const int& n)
{
	vvi g(n);
	for (auto it = e.begin(); it != e.end(); ++it)
	{
		g[it->X].pb(it->Y);
		g[it->Y].pb(it->X);
	}
	return g;
}
template<typename A, typename B>
pair<A, B> operator-=(pair<A, B>& a, const pair<A, B>& b)
{
	a.X -= b.X;
	a.Y -= b.Y;
	return a;
}
template<typename A>
A operator*(const pair<A, A>& p, const pair<A, A>& q)
{
	return p.X * q.X + p.Y * q.Y;
}
template<typename A>
pair<A, A> operator*(const pair<A, A>& p, const A& q)
{
	return mp(p.X * q, p.Y * q);
}
template<typename A>
A operator%(const pair<A, A>& p, const pair<A, A>& q)
{
	return p.X * q.Y - p.Y * q.X;
}
template<typename A>
A sq_len(const pair<A, A>& p)
{
	return p * p;
}
template<typename A>
A sq_dist(const pair<A, A>& p, const pair<A, A>& q)
{
	return sq_len(p - q);
}
template<typename A>
double len(const pair<A, A>& p)
{
	return sqrt(sq_len(p));
}
template<typename A>
double dist(const pair<A, A>& p, const pair<A, A>& q)
{
	return len(p - q);
}
template<typename A>
bool id16(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
	A x = sq_dist(a, b);
	A y = sq_dist(b, c);
	A z = sq_dist(c, d);
	A t = sq_dist(d, a);
	return ((x == y) && (y == z) && (z == t));
}
template<typename A>
bool is_rectangle(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
	pair<A, A> x = a - b,
		y = b - c,
		z = c - d,
		t = d - a;
	return ((x * y == 0) && (y * z == 0) && (z * t == 0) && (t * x == 0));
}
template<typename A>
bool are_parallel(const pair<A, A>& a, const pair<A, A>& b)
{
	return (a % b == 0);
}
template<typename A>
bool id17(const pair<A, A>& a, const pair<A, A>& b)
{
	return (a * b == 0);
}
template<typename A>
bool id30(const pair<A, A>& a, const pair<A, A>& b)
{
	return (are_parallel(a, b) && (a * b >= 0));
}
template<typename A>
bool id36(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
	return ((a - b) == (d - c));
}
template<typename A>
bool id27(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
	pair<A, A> x = a - b, z = d - c;
	return id30(x, z);
}
template<typename A>
bool id21(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
	pair<A, A> x = a - b,
		y = b - c,
		z = c - d,
		t = d - a;
	A p = x % y, q = y % z, r = z % t, s = t % x;
	return (((p >= 0) && (q >= 0) && (r >= 0) && (s >= 0)) ||
		((p <= 0) && (q <= 0) && (r <= 0) && (s <= 0)));
}


template<typename A>
bool id14(const pair<A, A>& a, const pair<A, A>& c)
{
	return ((a % c) >= 0);
}
template<typename A>
bool id14(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c)
{
	return id14(a - b, a - c);
}


template<typename A>
bool npocs(const pair<A, A>& a, const pair<A, A>& c)
{
	return ((a % c) <= 0);
}
template<typename A>
bool npocs(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c)
{
	return npocs(a - b, a - c);
}


template<typename A>
bool prcs(const pair<A, A>& a, const pair<A, A>& c)
{
	return ((a % c) > 0);
}
template<typename A>
bool prcs(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c)
{
	return prcs(a - b, a - c);
}


template<typename A>
bool pocs(const pair<A, A>& a, const pair<A, A>& c)
{
	return ((a % c) < 0);
}
template<typename A>
bool pocs(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c)
{
	return pocs(a - b, a - c);
}
template<typename A>
bool id37(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
	pair<A, A> x = b - a;
	A p = x % (c - b), q = x % (d - b);
	return (((p >= 0) && (q <= 0)) ||
		((p <= 0) && (q >= 0)));
}
template<typename A>
bool id15(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
	pair<A, A> x = b - a;
	A p = x % (c - b), q = x % (d - b);
	return (((p > 0) && (q < 0)) ||
		((p < 0) && (q > 0)));
}
template<typename A>
pair<A, A> id31(const pair<A, A>& p)
{
	return mp(-p.Y, p.X);
}
template<typename A>
pair<A, A> id31(const pair<A, A>& p, const pair<A, A>& c)
{
	return c + id31(p - c);
}
template<typename A>
bool id7(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d) 

{
	return id37(a, b, c, d) && id37(c, d, a, b);
}
template<typename A>
bool id28(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d) 

{
	return id15(a, b, c, d) && id15(c, d, a, b);
}
template <typename A>
pair<pair<A, A>, A> id3(const pair<A, A>& normal, const pair<A, A>& point)
{
	return mp(normal, -(normal * point));
}
template <typename A>
pair<pair<A, A>, A> serper(const pair<A, A>& a, const pair<A, A>& b)
{
	

	

	

	

	pair<A, A> p = b - a;
	return mp(p + p, -(p * (a + b)));
}
pdd ints(const pdd& p, const double& a,
	const pdd& q, const double& b)
{
	double D = p % q;
	double E = pdd(-a, p.Y) % pdd(-b, q.Y);
	double F = pdd(p.X, -a) % pdd(q.X, -b);
	return pdd(E / D, F / D);
}
pdd id33(const pdd& x, const pdd& y, const pdd& z)
{
	auto p1 = serper(x, y),
		p2 = serper(x, z);
	return ints(p1.X, p1.Y, p2.X, p2.Y);
}
template<typename A>
pair<pair<A, A>, A> id6(const pair<A, A>& p, const pair<A, A>& q)
{
	return mp(mp(q.Y - p.Y, p.X - q.X), -p % q);
}
template<typename A>
vector<pdd> id26(const pair<pair<A, A>, A>& a, const pair<pair<A, A>, A>& b)
{
	pair<A, A> c = b.X - a.X;
	A rr1 = a.Y * a.Y, rr2 = b.Y * b.Y, cc = c * c,
		rrrr1 = rr1 * rr1, rrrr2 = rr2 * rr2, cccc = cc * cc,
		D = 2 * (rr1 * rr2 + rr2 * cc + cc * rr1) - (rrrr1 + rrrr2 + cccc);
	if (D >= 0)
	{
		double E = (((double)(rr1 - rr2)) / cc + 1) / 2;
		pdd baza = pdd(a.X.X, a.X.Y) + pdd(c.X, c.Y) * E;
		if (D)
		{
			double lll = sqrt((double)(D)) / (2 * cc);
			pair<A, A> cr = id31(c);
			pdd pmm = pdd(cr.X, cr.Y) * lll;
			return{ baza + pmm, baza - pmm };
		}
		else
			return vector<pdd>(1, baza);
	}
	else
		return vector<pdd>();
}
template<typename A, typename B>
pair<A, B> sopr(const pair<A, B>& p)
{
	return mp(p.X, -p.Y);
}
template<typename A>
bool on_segment(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c)
{
	return id30(b - a, c - b);
}
template<typename A>
pair<pair<A, A>, A> perpendicular(const pair<A, A>& line, const pair<A, A>& point)
{
	return id3(id31(line), point);
}
pdd projection(const pair<pdd, double>& line, const pdd& point)
{
	pair<pdd, double> temp = perpendicular(line.X, point);
	return ints(line.X, line.Y, temp.X, temp.Y);
}
pdd height(const pdd& a, const pdd& b, const pdd& c)
{
	return projection(id6(a, c), b);
}
pdd unitvector(const pdd& a)
{
	return a * (1 / len(a));
}
template<typename T>
vi z_function(const vector<T>& s)
{
	int n = sz(s);
	vi z(n);
	int l = 0, r = 1;
	for (int i = 1; i < n; ++i)
	{
		z[i] = max(0, min(r - i, z[i - l]));
		while (i + z[i] < n && (s[i + z[i]] == s[z[i]]))
			++z[i];
		if (r < i + z[i])
		{
			l = i;
			r = i + z[i];
		}
	}
	return z;
}
pii euc(const int& m, const int& n)
{
	if (n == 0)
		return pii((m >= 0) ? 1 : -1, 0);
	int t = m / n;
	pii ans1 = euc(n, m - t * n);
	return pii(ans1.Y, ans1.X - ans1.Y * t);
}
int prod(const int& a, const int& b, const int& M)
{
	return ((ll)(a)) * b % M;
}
int sum(const int& a, const int& b, const int& M)
{
	int c = a + b;
	return c >= M ? c - M : c;
}
int raz(const int& a, const int& b, const int& M)
{
	int c = a - b;
	return c < 0 ? c + M : c;
}
ll prodll(const ll& a, const ll& b, const ll& M)
{
	return a * b % M;
}
ll sumll(const ll& a, const ll& b, const ll& M)
{
	ll c = a + b;
	return c >= M ? c - M : c;
}
ll razll(const ll& a, const ll& b, const ll& M)
{
	ll c = a - b;
	return c < 0 ? c + M : c;
}


template<typename A>
bool id23(const pair<A, A>& a, const pair<A, A>& b)
{
	A p;
	if (p = a % b)
		return (p > 0);
	else
		return sq_len(a) < sq_len(b);
}
template<typename T>
int id22(const vector<T>& v)
{
	int ans = 0, n = sz(v);
	for (int i = 1; i < n; ++i)
		if (v[i] < v[ans])
			ans = i;
	return ans;
}


template<typename T>
vi id34(vector<pair<T, T>>& a)
{
	int n = sz(a);
	if (n)
	{
		int mt = id22(a);
		pair<T, T> d = a[mt];
		for (int i = 0; i < n; ++i)
			a[i] -= d;

		vi idx(n);
		for (int i = 0; i < n; ++i)
			idx[i] = i;
		sort(idx.begin(), idx.end(), [&](const int& l, const int& r) {return id23(a[l], a[r]); });

		vi h(1, idx.front());
		for (auto it = idx.begin() + 1; it != idx.end(); ++it)
		{
			auto temp = a.begin() + *it;
			if (sz(h) >= 2)
			{
				if (are_parallel(a[h.back()], *temp))
					h.pop_back();
				while ((sz(h) >= 3) && npocs(a[h[sz(h) - 2]], a[h.back()], *temp))
					h.pop_back();
			}
			h.push_back(*it);
		}

		for (int i = 0; i < n; ++i)
			a[i] += d;
		return h;
	}
	else
		return vi();
}
pii id20(const int& a, const int& b)
{
	if (b)
	{
		int c = a / b;
		pii ans1 = id20(b, a - b * c);
		return pll(ans1.Y, ans1.X - ans1.Y * c);
	}
	else
		return pii(1, 0);
}
pll id10(const ll& a, const ll& b)
{
	if (b)
	{
		ll c = a / b;
		pll ans1 = id10(b, a - b * c);
		return pll(ans1.Y, ans1.X - ans1.Y * c);
	}
	else
		return pll(1ll, 0ll);
}
int gcd(int a, int b)
{
	while (b)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}
ll id32(ll a, ll b)
{
	while (b)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}


ll pr_p(const ll& a, const ll& b, const ll& p)
{
	if (b < 1000000)
		return (a * b) % p;
	ll temp = pr_p(a, b >> 1ll, p);
	temp = sumll(temp, temp, p);
	if (b & 1ll)
		return sumll(temp, a, p);
	else
		return temp;
}
ll po_p(const ll& a, const ll& b, const ll& p)
{
	if (b < 2)
	{
		if (b == 0)
			return 1;
		else
			return a;
	}
	ll temp = po_p(a, b >> 1ll, p);
	temp = pr_p(temp, temp, p);
	if (b & 1ll)
		return pr_p(temp, a, p);
	else
		return temp;
}
int pow_mod(const int& a, const int& b, const int& p)
{
	if (b < 2)
	{
		if (b == 0)
			return 1;
		else
			return a;
	}
	int temp = pow_mod(a, b >> 1, p);
	temp = prod(temp, temp, p);
	if (b & 1)
		return prod(temp, a, p);
	else
		return temp;
}
ll id4(const ll& a, const ll& b, const ll& p)
{
	if (b < 2)
	{
		if (b == 0)
			return 1;
		else
			return a;
	}
	ll temp = id4(a, b >> 1ll, p);
	temp = prodll(temp, temp, p);
	if (b & 1ll)
		return prodll(temp, a, p);
	else
		return temp;
}
int inverse(int a, int n)
{
	int c = id20(a, n).X;
	if (c < 0)
		c += n;
	return c;
}
ll id40(ll a, ll n)
{
	ll c = id10(a, n).X;
	if (c < 0)
		c += n;
	return c;
}
template<typename A>
pii equal_elements(const vector<A>& u, const vector<A>& v)
{
	pii ans(INT_MAX, INT_MAX);
	int m = sz(u), n = sz(v);
	vi id_u(m);
	for (int i = 1; i < m; ++i)
		id_u[i] = i;
	vi id_v(n);
	for (int i = 1; i < n; ++i)
		id_v[i] = i;
	sort(id_u.begin(), id_u.end(), [&](const int& x, const int& y) {return u[x] < u[y]; });
	sort(id_v.begin(), id_v.end(), [&](const int& x, const int& y) {return v[x] < v[y]; });
	int i = 0; int j = 0;
	while ((i < m) && (j < n))
	{
		if (u[id_u[i]] < v[id_v[j]])
			++i;
		else if (v[id_v[j]] < u[id_u[i]])
			++j;
		else
		{
			ans = min(ans, pii(id_v[j], id_u[i]));
			++j;
		}
	}
	if (ans.X == INT_MAX)
		return pii(-1, -1);
	else
		return pii(ans.Y, ans.X);
}
ll id18(ll a, ll b, ll n)
{
	int k = ((int)(sqrt((long double)n)));
	ll a1 = id40(a, n);
	int l = k + 20;
	ll a2 = po_p(a1, k, n);
	vl seq1(k), seq2(l);
	seq1.front() = 1;
	for (int i = 1; i < k; ++i)
		seq1[i] = pr_p(seq1[i - 1], a, n);
	seq2.front() = b;
	for (int i = 1; i < l; ++i)
		seq2[i] = pr_p(seq2[i - 1], a2, n);
	pll e = equal_elements(seq1, seq2);
	if (e.X == -1)
		return -1;
	else
		return e.X + e.Y * k;
}
ll id39(ll a, ll b, ll n)
{
	const int C = 70;
	a %= n;
	b %= n;
	if (id32(n, a) != 1)
	{
		for (int i = 0; i < C; ++i)
		{
			if (po_p(a, i, n) == b)
			{
				return i;
			}
		}
		ll multp = po_p(a, C, n);
		ll g = id32(multp, n);
		if (b % g)
		{
			return -1;
		}
		else
		{
			b /= g;
			n /= g;
			multp /= g;
			ll ob = id40(multp, n);
			b = pr_p(b, ob, n);
			ll ans = id18(a, b, n);
			if (ans == -1)
				return -1;
			else
				return ans + C;
		}
	}
	else
		return id18(a, b, n);
}
struct factorizator
{
	const int N = 2000001;
	vi pr;
	vi md;
	vi pw;
	vi without_md;
	void init()
	{
		md.resize(N);
		pw.resize(N);
		pr.reserve(N);
		without_md.resize(N, 1);
		for (int i = 2; i < N; ++i)
			md[i] = i;
		for (int i = 2; i < N; ++i)
		{
			if (md[i] == i)
				pr.pb(i);
			bool worth = true;
			for (int j = 0; worth && (j < sz(pr)) && (pr[j] <= md[i]); ++j)
			{
				ll temp = ((ll)(pr[j])) * i;
				if (temp < N)
					md[((int)temp)] = pr[j];
				else
					worth = false;
			}
		}
		for (int i = 2; i < N; ++i)
		{
			int t = md[i], s = i / t;
			if (md[s] == t)
			{
				pw[i] = 1 + pw[s];
				without_md[i] = without_md[s];
			}
			else
			{
				pw[i] = 1;
				without_md[i] = s;
			}
		}
	}
	void known_factorization(int n, vpii& v)
	{
		while (n > 1)
		{
			v.eb(md[n], pw[n]);
			n = without_md[n];
		}
	}
	vpii factorize(int n)
	{
		vpii ans;
		for (int i = 0; (i < sz(pr)) && (pr[i] * ((ll)(pr[i])) <= n); ++i)
		{
			int t = n / pr[i];
			if (t * pr[i] == n)
			{
				ans.eb(pr[i], 0);
				do
				{
					++ans.back().Y;
					n = t;
					t = n / pr[i];
				} while (t * pr[i] == n);
			}
			if (n < N)
			{
				known_factorization(n, ans);
				return ans;
			}
		}
		if (n > 1)
			ans.eb(n, 1);
		return ans;
	}
	vpii merge(const vpii& p1, const vpii& p2)
	{
		vpii ans;
		int m = sz(p1);
		int n = sz(p2);
		int i = 0; int j = 0;
		while ((i < m) || (j < n))
		{
			if (i < m)
			{
				if (j < n)
				{
					if (p1[i].X < p2[j].X)
						ans.pb(p1[i++]);
					else if (p1[i].X > p2[j].X)
						ans.pb(p2[j++]);
					else
					{
						ans.eb(p1[i].X, p1[i].Y + p2[j].Y);
						++i; ++j;
					}
				}
				else
					ans.pb(p1[i++]);
			}
			else
				ans.pb(p2[j++]);
		}
	}
};
factorizator fac;
int phi(const vpii& v)
{
	int ans = 1;
	for (int i = 0; i < sz(v); ++i)
	{
		ans *= v[i].X - 1;
		for (int j = 1; j < v[i].Y; ++j)
			ans *= v[i].X;
	}
	return ans;
}
int phi(const int& n)
{
	return phi(fac.factorize(n));
}
bool id0(const int& ph, const vi& to_check, const int& r, const int& n)
{
	for (int i = 0; i < sz(to_check); ++i)
		if (pow_mod(r, to_check[i], n) == 1)
			return false;
	return (pow_mod(r, ph, n) == 1);
}
int primitive_root(const int& n)
{
	if (n < 3)
		return n - 1;
	int p = phi(n);
	vpii f = fac.factorize(p);
	vi to_check(sz(f));
	for (int i = 0; i < sz(f); ++i)
		to_check[i] = p / f[i].X;
	for (int i = 2; i < n; ++i)
		if (id0(p, to_check, i, n))
			return i;
	return -1;
}
int id35(const int& a, const int& p, const int& b, const int& q)
{
	pii c = id20(p, q);
	int pr = p * q;
	int ans = ((a * c.Y * q + b * c.X * p) % pr + pr) % pr;
	return ans;
}
ll id1(const ll& a, const ll& p, const ll& b, const ll& q)
{
	pll c = id10(p, q);
	ll pr = p * q;
	ll ans = ((a * c.Y * q + b * c.X * p) % pr + pr) % pr;
	return ans;
}
pii power_v(int n, const int& p)
{
	int ans = 0;
	while (n % p == 0)
	{
		n /= p;
		++ans;
	}
	return pii(ans, n);
}
int id12(int c, int n, const int& pr, const int& k)
{
	c %= n;
	if (c)
	{
		pii kek = power_v(c, pr);
		int l = kek.X;
		if (l & 1)
			return -1;
		if (l > 0)
		{
			int pwl = 1;
			for (int i = 0; i < l; ++i)
				pwl *= pr;
			n /= pwl;
			c /= pwl;
			int ans1 = id12(c, n, pr, k - l);
			if (ans1 == -1)
				return -1;
			for (int i = 0; i < (l >> 1); ++i)
				ans1 *= pr;
			return ans1;
		}
		else
		{
			int primitive;
			if (n & 1)
				primitive = primitive_root(n);
			else
				primitive = 5;
			int u = ((int)id18(primitive, c, n));
			if (u == -1)
				return -1;
			if (u & 1)
				return -1;
			return pow_mod(primitive, u >> 1, n);
		}
	}
	else
		return 0;
}
int id8(const int& c, const int& n)
{
	vpii f = fac.factorize(n);
	int a = 0, p = 1;
	for (int i = 0; i < sz(f); ++i)
	{
		int q = 1;
		for (int j = 0; j < f[i].Y; ++j)
			q *= f[i].X;
		int b = id12(c, q, f[i].X, f[i].Y);
		if (b == -1)
			return -1;
		a = id35(a, p, b, q);
		p *= q;
	}
	return a;
}

int id24(int x)
{
	int ans = 0;
	while (x)
	{
		if (x & 1)
			++ans;
		x >>= 1;
	}
	return ans;
}
ll id11(ll x)
{
	ll ans = 0;
	while (x)
	{
		if (x & 1)
			++ans;
		x >>= 1;
	}
	return ans;
}
int id5(int x)
{
	int ans = 32;
	while (x)
	{
		--ans;
		x >>= 1;
	}
	return ans;
}
ll id9(ll x)
{
	ll ans = 64;
	while (x)
	{
		--ans;
		x >>= 1;
	}
	return ans;
}
int id41(int x)
{
	int ans = 0;
	while ((x & 1) == 0)
	{
		++ans;
		x >>= 1;
	}
	return ans;
}
ll id2(ll x)
{
	ll ans = 0;
	while ((x & 1) == 0)
	{
		++ans;
		x >>= 1;
	}
	return ans;
}


void dfs(const int& v, const vvi& g, vb& nv, vi& p, vvi& c)
{
	nv[v] = false;
	for (int i = 0; i < sz(g[v]); ++i)
	{
		int to = g[v][i];
		if (nv[to])
		{
			dfs(to, g, nv, p, c);
			p[to] = v;
			c[v].pb(to);
		}
	}
}

void dfs_fill(const int& v, const vvi& c, vi& undertree, vi& id38, vi& id19, const vi& h)
{
	undertree.pb(v);
	for (int i = 0; i < sz(c[v]); ++i)
	{
		id38[c[v][i]] = min(id38[v], h[c[v][i]]);
		id19[c[v][i]] = min(id19[v], h[c[v][i]]);
		dfs_fill(c[v][i], c, undertree, id38, id19, h);
	}
}

struct SegmentTree {
	vector<int> mn;
	vector<int> mod;
	int n;

	SegmentTree(int n)
		: mn(4 * n + 17)
		, mod(4 * n + 17)
		, n(n)
	{
		build(1, 1, n);
	}

	void build(int v, int tl, int tr) {
		if (tl == tr) {
			mn[v] = -tl;
		}
		else {
			int tm = (tl + tr) >> 1;
			build(v + v, tl, tm);
			build(v + v + 1, tm + 1, tr);
			mn[v] = min(mn[v + v], mn[v + v + 1]);
		}
	}

	int getv(int v) {
		return mn[v] + mod[v];
	}

	void add(int v, int tl, int tr, int l, int r, int x) {
		if (r < tl || l > tr) {
			return;
		}
		if (tl >= l && tr <= r) {
			mod[v] += x;
			return;
		}
		int tm = (tl + tr) >> 1;
		add(v + v, tl, tm, l, r, x);
		add(v + v + 1, tm + 1, tr, l, r, x);
		mn[v] = min(getv(v + v), getv(v + v + 1));
	}

	void add(int l, int r, int x) {
		add(1, 1, n, l, r, x);
	}

	bool check() {
		return getv(1) >= 0;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cerr.tie(0);

	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	auto start_time = clock();
	cerr << setprecision(3) << fixed;

	

	int n;
	cin >> n;
	vi h(n);
	cin >> h;
	vpii e(n - 1);
	vvi g(n);
	cin >> e;
	--e;
	for (int i = 0; i < n - 1; ++i)
	{
		g[e[i].X].pb(e[i].Y);
		g[e[i].Y].pb(e[i].X);
	}
	vi p(n);
	vvi c(n);
	vb nv(n, true);
	dfs(0, g, nv, p, c);
	
	set<pii> ranked;
	ranked.emplace(h[0], 0);

	int k;
	cin >> k;
	vi s(k);
	cin >> s;
	sort(s.begin(), s.end(), [&](const int& a, const int& b) {return a > b; });

	int x = 0;
	bool good = true;
	while (good && (x < k))
	{
		int d = s[x];
		auto oldest = ranked.end();
		--oldest;
		if (oldest->X >= d)
		{
			int r = oldest->Y;
			ranked.erase(oldest);
			for (int j = 0; j < sz(c[r]); ++j)
				ranked.emplace(h[c[r][j]], c[r][j]);
			++x;
		}
		else
			good = false;
	}
	if (good)
	{
		cout << "0\n";
		return 0;
	}
	

	vi trees;
	for (auto it = ranked.begin(); it != ranked.end(); ++it)
		trees.pb(it->Y);

	int t = sz(trees);
	vi answers(t);
	for (int I = 0; I < t; ++I)
	{
		answers[I] = s[x] - h[trees[I]];
	}
	set<pii> humans;
	for (int i = x; i < k; ++i)
		humans.emplace(-s[i], i);
	vvi id25(t), id13(t);

	vvi undertrees(t);
	vi id38(n), id19(n);
	for (int I = 0; I < t; ++I)
	{
		id38[trees[I]] = h[trees[I]];
		id19[trees[I]] = 2e9;
		dfs_fill(trees[I], c, undertrees[I], id38, id19, h);
	}


	for (int I = 0; I < t; ++I)
	{
		for (int i = 0; i < sz(undertrees[I]); ++i)
		{
			int to = undertrees[I][i];
			auto it = humans.lower_bound(pii(-id38[to], 0));
			if (it != humans.end())
			{
				id13[I].pb(it->Y);
				humans.erase(it);
			}
		}

		for (int i = 0; i < sz(id13[I]); ++i)
			humans.emplace(-s[id13[I][i]], id13[I][i]);

		auto it = humans.begin();
		id25[I].pb(it->Y);
		humans.erase(it);

		for (int i = 0; i < sz(undertrees[I]); ++i)
		{
			int to = undertrees[I][i];
			if (to != trees[I])
			{
				auto it = humans.lower_bound(pii(-id19[to], 0));
				if (it != humans.end())
				{
					id25[I].pb(it->Y);
					humans.erase(it);
				}
			}
		}

		for (int i = 0; i < sz(id25[I]); ++i)
			humans.emplace(-s[id25[I][i]], id25[I][i]);
	}

	SegmentTree st(k - x); 



	for (int I = 0; I < t; ++I)
	{
		for (int i = 0; i < sz(id13[I]); ++i)
			st.add(id13[I][i] - x + 1, k - x, 1);
	}

	int ans = 2e9;

	for (int I = 0; I < t; ++I)
	{
		if (I)
		{
			for (int i = 0; i < sz(id13[I - 1]); ++i)
				st.add(id13[I - 1][i] - x + 1, k - x, 1);
			for (int i = 0; i < sz(id25[I - 1]); ++i)
				st.add(id25[I - 1][i] - x + 1, k - x, -1);
		}
		for (int i = 0; i < sz(id13[I]); ++i)
			st.add(id13[I][i] - x + 1, k - x, -1);
		for (int i = 0; i < sz(id25[I]); ++i)
			st.add(id25[I][i] - x + 1, k - x, 1);
		if (st.check())
			ans = min(ans, answers[I]);
	}

	if (ans != 2e9)
		cout << ans;
	else
		cout << -1;
	cout << '\n';

	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";


	return 0;
}