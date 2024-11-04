





















using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<pll> vpll;
typedef vector<ll> vl;
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
bool id14(const pair<A, A>& a, const pair<A, A>& b)
{
	return (are_parallel(a, b) && (a * b >= 0));
}

template<typename A>
bool id18(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
	return ((a - b) == (d - c));
}

template<typename A>
bool id12(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
	pair<A, A> x = a - b, z = d - c;
	return id14(x, z);
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
bool id3(const pair<A, A>& a, const pair<A, A>& c)
{
	return ((a % c) >= 0);
}

template<typename A>
bool id3(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c)
{
	return id3(a - b, a - c);
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
bool id19(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
	pair<A, A> x = b - a;
	A p = x % (c - b), q = x % (d - b);
	return (((p >= 0) && (q <= 0)) ||
		((p <= 0) && (q >= 0)));
}
template<typename A>
bool id4(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
	pair<A, A> x = b - a;
	A p = x % (c - b), q = x % (d - b);
	return (((p > 0) && (q < 0)) ||
		((p < 0) && (q > 0)));
}

template<typename A>
pair<A, A> id15(const pair<A, A>& p)
{
	return mp(-p.Y, p.X);
}

template<typename A>
pair<A, A> id15(const pair<A, A>& p, const pair<A, A>& c)
{
	return c + id15(p - c);
}

template<typename A>
bool id2(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d) 

{
	return id19(a, b, c, d) && id19(c, d, a, b);
}
template<typename A>
bool id13(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d) 

{
	return id4(a, b, c, d) && id4(c, d, a, b);
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

pdd id16(const pdd& x, const pdd& y, const pdd& z)
{
	auto p1 = serper(x, y),
		p2 = serper(x, z);
	return ints(p1.X, p1.Y, p2.X, p2.Y);
}

template<typename A>
pair<pair<A, A>, A> id1(const pair<A, A>& p, const pair<A, A>& q)
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
			pair<A, A> cr = id15(c);
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
	return id14(b - a, c - b);
}
template<typename A>
pair<pair<A, A>, A> perpendicular(const pair<A, A>& line, const pair<A, A>& point)
{
	return id0(id15(line), point);
}
pdd projection(const pair<pdd, double>& line, const pdd& point)
{
	pair<pdd, double> temp = perpendicular(line.X, point);
	return ints(line.X, line.Y, temp.X, temp.Y);
}
pdd height(const pdd& a, const pdd& b, const pdd& c)
{
	return projection(id1(a, c), b);
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
vi id17(vector<pair<T, T>>& a)
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
int gcd(const int& a, const int& b)
{
	return b ? gcd(b, a % b) : a;
}
const int N = 15000001;
void id5(int n, const vb& pr, const vi& prs, const vi& dlt, const vi& ch, vi& occ)
{
	while (n > 1)
	{
		int t = dlt[n];
		--occ[t];
		n = ch[n];
		while (n % t == 0)
			n /= t;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int n;
	cin >> n;
	vi v(n);
	cin >> v;
	int a = v[0];
	for (int i = 1; i < n; ++i)
		a = gcd(v[i], a);
	for (int i = 0; i < n; ++i)
		v[i] /= a;
	vb pr(N, true);
	vi prs;
	prs.reserve(N / 3);
	vi dlt(N, 0), ch(N, 1);
	pr[0] = false;
	pr[1] = false;
	for (int i = 2; i < N; ++i)
	{
	
		if (pr[i])
		{
			prs.pb(i);
			dlt[i] = i;
			ll ii = ((ll)(i)) * i;
			if (ii < N)
				for (int j = ii; j < N; j += i)
				{
					pr[j] = false;
					dlt[j] = i;
					ch[j] = j / i;
				}
		}
	}
	vi occ(N, n);
	for (int i = 0; i < n; ++i)
	{
		id5(v[i], pr, prs, dlt, ch, occ);
	}
	int aa = n;
	for (int i = 0; i < N; ++i)
		aa = min(aa, occ[i]);
	if (aa == n)
		cout << "-1\n";
	else
		cout << aa << '\n';
	return 0;
}