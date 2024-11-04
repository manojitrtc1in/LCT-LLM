

























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
typedef vector<pdd> vpdd;

template<typename A>
istream& operator>>(istream& fin, vector<A>& v)
{
	int n = sz(v);
	for (int i = 0; i < n; ++i)
		fin >> v[i];
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
bool id6(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
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
bool id7(const pair<A, A>& a, const pair<A, A>& b)
{
	return (a * b == 0);
}

template<typename A>
bool id15(const pair<A, A>& a, const pair<A, A>& b)
{
	return (are_parallel(a, b) && (a * b >= 0));
}

template<typename A>
bool id20(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
	return ((a - b) == (d - c));
}

template<typename A>
bool id12(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
	pair<A, A> x = a - b, z = d - c;
	return id15(x, z);
}

template<typename A>
bool id8(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
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
bool id4(const pair<A, A>& a, const pair<A, A>& c)
{
	return ((a % c) >= 0);
}

template<typename A>
bool id4(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c)
{
	return id4(a - b, a - c);
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
bool id21(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
	pair<A, A> x = b - a;
	A p = x % (c - b), q = x % (d - b);
	return (((p >= 0) && (q <= 0)) ||
		((p <= 0) && (q >= 0)));
}
template<typename A>
bool id5(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
	pair<A, A> x = b - a;
	A p = x % (c - b), q = x % (d - b);
	return (((p > 0) && (q < 0)) ||
		((p < 0) && (q > 0)));
}

template<typename A>
pair<A, A> id16(const pair<A, A>& p)
{
	return mp(-p.Y, p.X);
}

template<typename A>
pair<A, A> id16(const pair<A, A>& p, const pair<A, A>& c)
{
	return c + id16(p - c);
}

template<typename A>
bool id3(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d) 

{
	return id21(a, b, c, d) && id21(c, d, a, b);
}
template<typename A>
bool id13(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d) 

{
	return id5(a, b, c, d) && id5(c, d, a, b);
}

template <typename A>
pair<pair<A, A>, A> id0(const pair<A, A>& normal, const pair<A, A>& point)
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

pdd id18(const pdd& x, const pdd& y, const pdd& z)
{
	auto p1 = serper(x, y),
		p2 = serper(x, z);
	return ints(p1.X, p1.Y, p2.X, p2.Y);
}

template<typename A>
pair<pair<A, A>, A> id2(const pair<A, A>& p, const pair<A, A>& q)
{
	return mp(mp(q.Y - p.Y, p.X - q.X), -p % q);
}

template<typename A>
vector<pdd> id11(const pair<pair<A, A>, A>& a, const pair<pair<A, A>, A>& b)
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
			pair<A, A> cr = id16(c);
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
	return id15(b - a, c - b);
}
template<typename A>
pair<pair<A, A>, A> perpendicular(const pair<A, A>& line, const pair<A, A>& point)
{
	return id0(id16(line), point);
}
pdd projection(const pair<pdd, double>& line, const pdd& point)
{
	pair<pdd, double> temp = perpendicular(line.X, point);
	return ints(line.X, line.Y, temp.X, temp.Y);
}
pdd height(const pdd& a, const pdd& b, const pdd& c)
{
	return projection(id2(a, c), b);
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



template<typename A>
bool id10(const pair<A, A>& a, const pair<A, A>& b)
{
	A p;
	if (p = a % b)
		return (p > 0);
	else
		return sq_len(a) < sq_len(b);
}

template<typename T>
int id9(const vector<T>& v)
{
	int ans = 0, n = sz(v);
	for (int i = 1; i < n; ++i)
		if (v[i] < v[ans])
			ans = i;
	return ans;
}





template<typename T>
vi id19(vector<pair<T, T>>& a)
{
	int n = sz(a);
	if (n)
	{
		int mt = id9(a);
		pair<T, T> d = a[mt];
		for (int i = 0; i < n; ++i)
			a[i] -= d;

		vi idx(n);
		for (int i = 0; i < n; ++i)
			idx[i] = i;
		sort(idx.begin(), idx.end(), [&](const int& l, const int& r) {return id10(a[l], a[r]); });

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

int id17(int r)
{
	

	
	int ans = 0;
	while (r)
	{
		++ans;
		r >>= 1;
	}
	return ans;
	
}

pii id1(const pii& p1, const pii& p2, const int& n)
{
	if ((p1.X == -1) || (p2.X == -1))
		return pii(-1, -1);
	pii np1 = pii(0, raz(p1.Y, p1.X, n));
	pii np2 = pii(raz(p2.X, p1.X, n), raz(p2.Y, p1.X, n));
	if (np2.X <= np2.Y)
	{
		if (np2.Y == n - 1)
			return pii(-1, -1);
		else
			return pii(sum(np1.X, p1.X, n), sum(max(np1.Y, np2.Y), p1.X, n));
	}
	else
	{
		if (np2.X <= np1.Y + 1)
			return pii(-1, -1);
		else
			return pii(sum(np2.X, p1.X, n), sum(max(np1.Y, np2.Y), p1.X, n));
	}
}

struct sparse
{
	int n;
	vvpii sp;
	void construct(const vpii& v)
	{
		n = sz(v);
		int r = id17(n - 1);
		sp.resize(r, vpii(n));
		for (int i = 0; i < n; ++i)
			sp.front()[i] = v[i];
		for (int i = 1; i < r; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				pii p1 = sp[i - 1][j];
				pii p2 = sp[i - 1][(j + (1 << (i - 1))) % n];
				sp[i][j] = id1(p1, p2, n);
			}
		}
	}
	pii segment(const int& l, const int& r)
	{
		if ((l == -1) || (r == -1))
			return pii(-1, -1);
		int szz = raz(r, l, n);
		if (l == r)
			return sp[0][l];
		int g = id17(szz) - 1;
		return id1(sp[g][l], sp[g][((r + 1 - (1 << g)) % n + n) % n], n);
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

	int n;
	cin >> n;
	if (n == 1)
	{
		cout << "0\n";
		return 0;
	}
	vi r(n);
	cin >> r;
	int zz = id17(n) + 1;
	vector<sparse> v(zz);
	vpii prs(n);


	for (int i = 0; i < n; ++i)
	{
		if (r[i] >= n - 1)
			prs[i] = pii(-1, -1);
		else
			prs[i] = id1(pii(raz(i, r[i], n), i), pii(i, sum(i, r[i],n)), n);
	}

	v[0].construct(prs);

	for (int i = 1; i < zz; ++i)
	{
		vpii id14(n);
		for (int j = 0; j < n; ++j)
		{
			pii pairr = v[i - 1].segment(j, j);
			id14[j] = v[i - 1].segment(pairr.X, pairr.Y);
		}
		v[i].construct(id14);
	}

	for (int i = 0; i < n; ++i)
	{
		pii my_pr(i, i);
		int ans = 0;
		for (int j = zz - 1; j >= 0; --j)
		{
			pii new_pr = v[j].segment(my_pr.X, my_pr.Y);
			if (new_pr.X != -1)
			{
				ans += (1 << j);
				my_pr = new_pr;
			}
		}
		cout << ans + 1 << ' ';
	}
	cout << '\n';
	return 0;
}