






































using namespace std;
typedef long long ll;
typedef unsigned long long ul;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
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
typedef pair<ul, int> pui;
typedef vector<pui> vpui;
typedef vector<ul> vu;
mt19937 rng(2391);
mt19937 gnr(chrono::high_resolution_clock::now().time_since_epoch().count());
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
		++* it;
	return a;
}
template<typename A>
vector<A>& operator--(vector<A>& a)
{
	for (auto it = a.begin(); it != a.end(); ++it)
		--* it;
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
vvi id31(const vpii& e, const int& n)
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
bool id19(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
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
bool id20(const pair<A, A>& a, const pair<A, A>& b)
{
	return (a * b == 0);
}
template<typename A>
bool id32(const pair<A, A>& a, const pair<A, A>& b)
{
	return (are_parallel(a, b) && (a * b >= 0));
}
template<typename A>
bool id37(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
	return ((a - b) == (d - c));
}
template<typename A>
bool id29(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
	pair<A, A> x = a - b, z = d - c;
	return id32(x, z);
}
template<typename A>
bool id23(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
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
bool id12(const pair<A, A>& a, const pair<A, A>& c)
{
	return ((a % c) >= 0);
}
template<typename A>
bool id12(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c)
{
	return id12(a - b, a - c);
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
bool id39(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
	pair<A, A> x = b - a;
	A p = x % (c - b), q = x % (d - b);
	return (((p >= 0) && (q <= 0)) ||
		((p <= 0) && (q >= 0)));
}
template<typename A>
bool id16(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
	pair<A, A> x = b - a;
	A p = x % (c - b), q = x % (d - b);
	return (((p > 0) && (q < 0)) ||
		((p < 0) && (q > 0)));
}
template<typename A>
pair<A, A> id33(const pair<A, A>& p)
{
	return mp(-p.Y, p.X);
}
template<typename A>
pair<A, A> id33(const pair<A, A>& p, const pair<A, A>& c)
{
	return c + id33(p - c);
}
template<typename A>
bool id6(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d) 

{
	return id39(a, b, c, d) && id39(c, d, a, b);
}
template<typename A>
bool id30(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d) 

{
	return id16(a, b, c, d) && id16(c, d, a, b);
}
template <typename A>
pair<pair<A, A>, A> id2(const pair<A, A>& normal, const pair<A, A>& point)
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
pdd id34(const pdd& x, const pdd& y, const pdd& z)
{
	auto p1 = serper(x, y),
		p2 = serper(x, z);
	return ints(p1.X, p1.Y, p2.X, p2.Y);
}
template<typename A>
pair<pair<A, A>, A> id5(const pair<A, A>& p, const pair<A, A>& q)
{
	return mp(mp(q.Y - p.Y, p.X - q.X), -p % q);
}
template<typename A>
vector<pdd> id28(const pair<pair<A, A>, A>& a, const pair<pair<A, A>, A>& b)
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
			pair<A, A> cr = id33(c);
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
	return id32(b - a, c - b);
}
template<typename A>
pair<pair<A, A>, A> perpendicular(const pair<A, A>& line, const pair<A, A>& point)
{
	return id2(id33(line), point);
}
pdd projection(const pair<pdd, double>& line, const pdd& point)
{
	pair<pdd, double> temp = perpendicular(line.X, point);
	return ints(line.X, line.Y, temp.X, temp.Y);
}
pdd height(const pdd& a, const pdd& b, const pdd& c)
{
	return projection(id5(a, c), b);
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
const int id14 = 400;
struct id13
{
	int N;
	vi pr;
	vi md;
	vi pw;
	vi without_md;
	id13(const int& n) : N(n), md(n), pw(n), without_md(n, 1)
	{
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
	void known_factorization(int n, vpui& v)
	{
		while (n > 1)
		{
			v.eb(md[n], pw[n]);
			n = without_md[n];
		}
	}
	vpui pollardRho(const ul& n);
	vpui factor(ul n);
	template<typename T>
	vector<pair<T, int>> merge(const vector<pair<T, int>>& p1, const vector<pair<T, int>>& p2)
	{
		vector<pair<T, int>> ans;
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
		return ans;
	}
};

id13 fac(2000000);

id13 fac(id14);

ul id38(const ul& a, const ul& b, const ul& M, const int& helper)
{
	if (M == 0)
		return 0;
	ul q = ((ld)a) * b / M;
	ul a1 = a * b - q * M;
	ul a2 = a1;
	int rm = M % helper;
	int ra = a % helper;
	int rb = b % helper;
	int rq = q % helper;
	int r1 = raz(prod(ra, rb, helper), prod(rq, rm, helper), helper);
	int r2 = r1;
	while (true)
	{
		if (a1 % helper == r1 && a1 < M)
			return a1;
		a1 -= M;
		r1 = raz(r1, rm, helper);

		a2 += M;
		r2 = sum(r2, rm, helper);
		if (a2 % helper == r2 && a2 < M)
			return a2;
	}
}
inline int find_helper(const ul& M)
{
	int i = 30;
	while (M % fac.pr[i] == 0)
		++i;
	return fac.pr[i];
}
ul prodll(const ul& a, const ul& b, const ul& M)
{
	if (M == 0)
		return 0;
	ul helper = find_helper(M);
	return id38(a, b, M, helper);
}
ul sumll(const ul& a, const ul& b, const ul& M)
{
	if (a < M - b)
		return a + b;
	else
		return a + b - M;
}
ul razll(const ul& a, const ul& b, const ul& M)
{
	if (a >= b)
		return a - b;
	else
		return a + M - b;
}
template<typename T>
T diff(const T& a, const T& b) {
	return (a > b) ? (a - b) : (b - a);
}


template<typename A>
bool id25(const pair<A, A>& a, const pair<A, A>& b)
{
	A p;
	if (p = a % b)
		return (p > 0);
	else
		return sq_len(a) < sq_len(b);
}
template<typename T>
int id24(const vector<T>& v)
{
	int ans = 0, n = sz(v);
	for (int i = 1; i < n; ++i)
		if (v[i] < v[ans])
			ans = i;
	return ans;
}


template<typename T>
vi id35(vector<pair<T, T>>& a)
{
	int n = sz(a);
	if (n)
	{
		int mt = id24(a);
		pair<T, T> d = a[mt];
		for (int i = 0; i < n; ++i)
			a[i] -= d;

		vi idx(n);
		for (int i = 0; i < n; ++i)
			idx[i] = i;
		sort(idx.begin(), idx.end(), [&](const int& l, const int& r) {return id25(a[l], a[r]); });

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
pii id22(const int& a, const int& b)
{
	if (b)
	{
		int c = a / b;
		pii ans1 = id22(b, a - b * c);
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
template<typename T>
T gcd(T a, T b)
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
ll id3(const ll& a, const ll& b, const ll& p)
{
	if (b < 2)
	{
		if (b == 0)
			return 1;
		else
			return a;
	}
	ll temp = id3(a, b >> 1ll, p);
	temp = prodll(temp, temp, p);
	if (b & 1ll)
		return prodll(temp, a, p);
	else
		return temp;
}
int inverse(int a, int n)
{
	int c = id22(a, n).X;
	if (c < 0)
		c += n;
	return c;
}
ll id7(ll a, ll n)
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
ll id21(ll a, ll b, ll n)
{
	int k = ((int)(sqrt((long double)n)));
	ll a1 = id7(a, n);
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
ll id42(ll a, ll b, ll n)
{
	const int C = 70;
	a %= n;
	b %= n;
	if (gcd(n, a) != 1)
	{
		for (int i = 0; i < C; ++i)
		{
			if (po_p(a, i, n) == b)
			{
				return i;
			}
		}
		ll multp = po_p(a, C, n);
		ll g = gcd(multp, n);
		if (b % g)
		{
			return -1;
		}
		else
		{
			b /= g;
			n /= g;
			multp /= g;
			ll ob = id7(multp, n);
			b = pr_p(b, ob, n);
			ll ans = id21(a, b, n);
			if (ans == -1)
				return -1;
			else
				return ans + C;
		}
	}
	else
		return id21(a, b, n);
}
const ul minimum_composites[] =
{
	1ull,
	2046ull,
	1373652ull,
	25326000ull,
	3215031750ull,
	2152302898746ull,
	3474749660382ull,
	341550071728320ull,
	341550071728320ull,
	3825123056546413050ull,
	3825123056546413050ull,
	18446744073709551615ull
};
const int little_primes[] =
{
	2,
	3,
	5,
	7,
	11,
	13,
	17,
	19,
	23,
	29,
	31,
	37
};
bool id15(const ul& n, const ul& prime, const ul& odd, const ul& pot, const ul& nmo)
{
	long long x = id3(prime, odd, n);
	if ((x == nmo) || (x == 1))
		return true;
	for (int i = 1; i < pot; ++i)
	{
		x = prodll(x, x, n);
		if (x == nmo)
			return true;
		if (x == 1)
			return false;
	}
	return false;
}
bool is_prime(const ul& n)
{
	if (n <= 2)
		return (n == 2);
	ul odd, pot, nmo;
	nmo = n - 1;
	odd = nmo;
	pot = 0;
	while ((odd & 1ll) == 0)
	{
		odd >>= 1ll;
		++pot;
	}
	int i = 0;
	while (n > minimum_composites[i])
	{
		if (id15(n, little_primes[i], odd, pot, nmo) == false)
			return false;
		++i;
	}
	return true;
}

vpui id13::pollardRho(const ul& n)
{
	if (is_prime(n))
		return vpui(1, pui(n, 1));
	int step = 1;
	while (true)
	{
		step <<= 1;
		ul a = rng();
		ul b = a;
		ul d = 1;
		for (int j = 0; j < step; ++j)
		{
			a = sumll(1, prodll(a, a, n), n);
			b = sumll(1, prodll(b, b, n), n);
			b = sumll(1, prodll(b, b, n), n);
			d = gcd(diff(a, b), n);
			if (d > 1) {
				break;
			}
		}
		if (1 < d && d < n)
			return merge(pollardRho(d), pollardRho(n / d));
	}
	return vpui();
}
vpui id13::factor(ul n)
{
	vpui ans;
	for (int i = 0; n >= N && i < sz(pr) && pr[i] < id14; ++i)
		while (n % pr[i] == 0)
		{
			if (sz(ans) && ans.back().X == pr[i])
				++ans.back().Y;
			else
				ans.eb(pr[i], 1);
			n /= pr[i];
		}
	if (n < N)
	{
		known_factorization(n, ans);
		return ans;
	}
	else
		return merge(ans, pollardRho(n));
}
template<typename T>
T phi(const vector<pair<T, int>>& v)
{
	T ans = 1;
	for (int i = 0; i < sz(v); ++i)
	{
		ans *= v[i].X - 1;
		for (int j = 1; j < v[i].Y; ++j)
			ans *= v[i].X;
	}
	return ans;
}
ul phi(const ul& n)
{
	return phi(fac.factor(n));
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
	vpui f = fac.factor(p);
	vi to_check(sz(f));
	for (int i = 0; i < sz(f); ++i)
		to_check[i] = p / f[i].X;
	for (int i = 2; i < n; ++i)
		if (id0(p, to_check, i, n))
			return i;
	return -1;
}
int id36(const int& a, const int& p, const int& b, const int& q)
{
	pii c = id22(p, q);
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
int id11(int c, int n, const int& pr, const int& k)
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
			int ans1 = id11(c, n, pr, k - l);
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
			int u = ((int)id21(primitive, c, n));
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
	vpui f = fac.factor(n);
	int a = 0, p = 1;
	for (int i = 0; i < sz(f); ++i)
	{
		int q = 1;
		for (int j = 0; j < f[i].Y; ++j)
			q *= f[i].X;
		int b = id11(c, q, f[i].X, f[i].Y);
		if (b == -1)
			return -1;
		a = id36(a, p, b, q);
		p *= q;
	}
	return a;
}

namespace BGF
{
	inline int cntd(unsigned x)
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
	inline ll cntdll(ul x)
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
	inline int clzd(unsigned x)
	{
		int ans = 32;
		while (x)
		{
			--ans;
			x >>= 1;
		}
		return ans;
	}
	inline ll id9(ul x)
	{
		ll ans = 64;
		while (x)
		{
			--ans;
			x >>= 1;
		}
		return ans;
	}
	inline int ctzd(unsigned x)
	{
		if (x == 0)
			return 32;
		int ans = 0;
		while ((x & 1) == 0)
		{
			++ans;
			x >>= 1;
		}
		return ans;
	}
	inline ll id17(ul x)
	{
		if (x == 0)
			return 64;
		ll ans = 0;
		while ((x & 1) == 0)
		{
			++ans;
			x >>= 1;
		}
		return ans;
	}
}


namespace BGF 

{
	const unsigned BHC = 65535u;
	const ul BHCL = 65535ull;
	const unsigned BHN = 65536u;
	const unsigned BHL = 16u;
	const unsigned LH = 4294901760u;
	const unsigned RH = 65535u;
	const ul id4 = 16ull;
	const ul id41 = 32ull;
	const ul id18 = 48ull;
	const ul LHL = 18446744069414584320ull;
	const ul RHL = 4294967295ull;
	int CNT[BHN];
	int CLZ[BHN];
	int CTZ[BHN];
	inline void initialize()
	{
		CNT[0] = 0;
		CLZ[0] = BHL + BHL;
		CTZ[0] = BHL;
		for (unsigned i = 1; i < BHN; ++i)
		{
			CNT[i] = cntd(i);
			CLZ[i] = clzd(i);
			CTZ[i] = ctzd(i);
		}
	}
	inline int cntc(const unsigned& x)
	{
		return CNT[x & BHC] + CNT[(x >> BHL) & BHC];
	}
	inline ll id26(const ul& x)
	{
		return CNT[x & BHCL] + CNT[(x >> id4) & BHCL] + CNT[(x >> id41) & BHCL] + CNT[(x >> id18) & BHCL];
	}
	inline int clzc(const unsigned& x)
	{
		if (x & LH)
			return CLZ[x >> BHL] - BHL;
		else
			return CLZ[x];
	}
	inline ll id40(const ul& x)
	{
		if (x & LHL)
			return clzc(x >> id41);
		else
			return clzc(x) + id41;
	}
	inline int ctzc(const unsigned& x)
	{
		if (x & RH)
			return CTZ[x & RH];
		else
			return CTZ[x >> BHL] + BHL;
	}
	inline ll id27(const ul& x)
	{
		if (x & RHL)
			return ctzc(x);
		else
			return ctzc(x >> id41) + id41;
	}
}




















const string INPUT_FILE = "input.txt";
const string OUTPUT_FILE = "output.txt";

void perform(pii a, pii b, pii c, vvpii& ans, vvb& u)
{
	u[a.X][a.Y] = !u[a.X][a.Y];
	u[b.X][b.Y] = !u[b.X][b.Y];
	u[c.X][c.Y] = !u[c.X][c.Y];
	++a; ++b; ++c;
	ans.push_back({ a, b, c });
}
void fix(pii p, vvpii& ans, vvb& u)
{
	int i = 0;
	if (u[p.X][p.Y])
		++i;
	if (u[p.X + 1][p.Y])
		++i;
	if (u[p.X][p.Y + 1])
		++i;
	if (u[p.X + 1][p.Y + 1])
		++i;
	pii q;
	vpii z;
	for (q.X = p.X; q.X < p.X + 2; ++q.X)
		for (q.Y = p.Y; q.Y < p.Y + 2; ++q.Y)
			if ((i + u[q.X][q.Y]) % 2 == 1)
				z.push_back(q);
	for (pii q : z)
		perform(pii(p.X + p.X + 1 - q.X, q.Y), pii(p.X + p.X + 1 - q.X, p.Y + p.Y + 1 - q.Y), pii(q.X, p.Y + p.Y + 1 - q.Y), ans, u);
}
int another_main()
{
	int t;
	cin >> t;
	for (int I = 0; I < t; ++I)
	{
		int n, m;
		cin >> n >> m;
		vs v(n);
		cin >> v;
		vvb u(n, vb(m));
		
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				u[i][j] = (v[i][j] == '1');
		vvpii ans;
		pii p;
		if (n == 3)
		{
			for (p.Y = 0; p.Y < m; p.Y += 2)
			{
				if (p.Y == m - 1)
					--p.Y;
				for (p.X = 0; p.X < n - 2; ++p.X)
				{
					if (u[p.X][p.Y])
					{
						if (u[p.X][p.Y + 1])
							perform(p, p + pii(0, 1), p + pii(1, 1), ans, u);
						else
							perform(p, p + pii(1, 0), p + pii(1, 1), ans, u);
					}
					else if (u[p.X][p.Y + 1])
						perform(p + pii(0, 1), p + pii(1, 0), p + pii(1, 1), ans, u);
				}
				fix(pii(n - 2, p.Y), ans, u);
			}
		}
		else
		{
			for (p.X = 0; p.X < n; p.X += 2)
			{
				if (p.X == n - 1)
					--p.X;
				for (p.Y = 0; p.Y < m - 2; ++p.Y)
				{
					if (u[p.X][p.Y])
					{
						if (u[p.X + 1][p.Y])
							perform(p, p + pii(1, 0), p + pii(1, 1), ans, u);
						else
							perform(p, p + pii(0, 1), p + pii(1, 1), ans, u);
					}
					else if (u[p.X + 1][p.Y])
						perform(p + pii(0, 1), p + pii(1, 0), p + pii(1, 1), ans, u);
				}
				fix(pii(p.X, m - 2), ans, u);
			}
		}
		cout << sz(ans) << '\n';
		for (int i = 0; i < sz(ans); ++i)
			cout << ans[i][0].X << ' ' << ans[i][0].Y << ' ' << ans[i][1].X << ' ' << ans[i][1].Y << ' ' << ans[i][2].X << ' ' << ans[i][2].Y << '\n';
	}
	return 0;
}

int main()
{
	FAST_IO;

	BGF::initialize();



	freopen(INPUT_FILE.c_str(), "rt", stdin);
	freopen(OUTPUT_FILE.c_str(), "wt", stdout);

	auto start_time = clock();
	cerr << setprecision(3) << fixed;


	freopen(INPUT_FILE.c_str(), "rt", stdin);
	freopen(OUTPUT_FILE.c_str(), "wt", stdout);


	int AMR = another_main();

	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";

	return AMR;
}