#pragma comment(linker, "/stack:256000000")
#pragma gcc optimize("O3")
#pragma gcc target("sse4")
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cerr.tie(0)
#define FAST_BUILTINS


#define mp make_pair
#define gl getline
#define pb push_back
#define eb emplace_back
#define ob pop_back
#define sz(x) ((int)(x.size()))
#define UM unordered_map
#define US unordered_set
#define X first
#define Y second
#define whole(x) x.begin(), x.end()
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cassert>
#include <nmmintrin.h>
#include <fstream>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <cmath>
#include <climits>
#include <bitset>
#include <random>
#include <complex>
#include <ctime>
#include <chrono>
#include <cstdio>
#include <cstring>
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
vvi adjlist_from_edgelist(const vpii& e, const int& n)
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
bool is_rhombus(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
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
bool are_orthogonal(const pair<A, A>& a, const pair<A, A>& b)
{
	return (a * b == 0);
}
template<typename A>
bool are_codirected(const pair<A, A>& a, const pair<A, A>& b)
{
	return (are_parallel(a, b) && (a * b >= 0));
}
template<typename A>
bool is_parallelogram(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
	return ((a - b) == (d - c));
}
template<typename A>
bool is_trapezoid(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
	pair<A, A> x = a - b, z = d - c;
	return are_codirected(x, z);
}
template<typename A>
bool is_convex_polygon(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
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
bool nprcs(const pair<A, A>& a, const pair<A, A>& c)
{
	return ((a % c) >= 0);
}
template<typename A>
bool nprcs(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c)
{
	return nprcs(a - b, a - c);
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
bool different_sides(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
	pair<A, A> x = b - a;
	A p = x % (c - b), q = x % (d - b);
	return (((p >= 0) && (q <= 0)) ||
		((p <= 0) && (q >= 0)));
}
template<typename A>
bool sharply_different_sides(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
	pair<A, A> x = b - a;
	A p = x % (c - b), q = x % (d - b);
	return (((p > 0) && (q < 0)) ||
		((p < 0) && (q > 0)));
}
template<typename A>
pair<A, A> rot_90(const pair<A, A>& p)
{
	return mp(-p.Y, p.X);
}
template<typename A>
pair<A, A> rot_90(const pair<A, A>& p, const pair<A, A>& c)
{
	return c + rot_90(p - c);
}
template<typename A>
bool intersecting_segments(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d) 

{
	return different_sides(a, b, c, d) && different_sides(c, d, a, b);
}
template<typename A>
bool sharply_intersecting_segments(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d) 

{
	return sharply_different_sides(a, b, c, d) && sharply_different_sides(c, d, a, b);
}
template <typename A>
pair<pair<A, A>, A> line_with_normal_vector_through_point(const pair<A, A>& normal, const pair<A, A>& point)
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
pdd circumcenter(const pdd& x, const pdd& y, const pdd& z)
{
	auto p1 = serper(x, y),
		p2 = serper(x, z);
	return ints(p1.X, p1.Y, p2.X, p2.Y);
}
template<typename A>
pair<pair<A, A>, A> l_th_2(const pair<A, A>& p, const pair<A, A>& q)
{
	return mp(mp(q.Y - p.Y, p.X - q.X), -p % q);
}
template<typename A>
vector<pdd> circle_intersection(const pair<pair<A, A>, A>& a, const pair<pair<A, A>, A>& b)
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
			pair<A, A> cr = rot_90(c);
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
	return are_codirected(b - a, c - b);
}
template<typename A>
pair<pair<A, A>, A> perpendicular(const pair<A, A>& line, const pair<A, A>& point)
{
	return line_with_normal_vector_through_point(rot_90(line), point);
}
pdd projection(const pair<pdd, double>& line, const pdd& point)
{
	pair<pdd, double> temp = perpendicular(line.X, point);
	return ints(line.X, line.Y, temp.X, temp.Y);
}
pdd height(const pdd& a, const pdd& b, const pdd& c)
{
	return projection(l_th_2(a, c), b);
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
const int LITTLE_BORDER = 200001; 

struct factorizator
{
	int N;
	vi pr;
	vi md;
	vi mdn;
	vi pw;
	vi without_md;
	factorizator(const int& n) : N(n), md(n), mdn(n), pw(n), without_md(n, 1)
	{
		for (int i = 2; i < N; ++i)
			md[i] = i;
		for (int i = 2; i < N; ++i)
		{
			if (md[i] == i)
			{
				mdn[i] = sz(pr);
				pr.pb(i);
			}
			bool worth = true;
			for (int j = 0; worth && (j < sz(pr)) && (pr[j] <= md[i]); ++j)
			{
				ll temp = ((ll)(pr[j])) * i;
				if (temp < N)
				{
					md[((int)temp)] = pr[j];
					mdn[((int)temp)] = j;
				}
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
#ifdef BIG_FACTORIZATOR
factorizator fac(2000000);
#else
factorizator fac(LITTLE_BORDER);
#endif
ul experimental_prodll(const ul& a, const ul& b, const ul& M, const int& helper)
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
	return experimental_prodll(a, b, M, helper);
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
bool angdis_cmp(const pair<A, A>& a, const pair<A, A>& b)
{
	A p;
	if (p = a % b)
		return (p > 0);
	else
		return sq_len(a) < sq_len(b);
}
template<typename T>
int find_min_idx(const vector<T>& v)
{
	int ans = 0, n = sz(v);
	for (int i = 1; i < n; ++i)
		if (v[i] < v[ans])
			ans = i;
	return ans;
}


template<typename T>
vi convex_hull(vector<pair<T, T>>& a)
{
	int n = sz(a);
	if (n)
	{
		int mt = find_min_idx(a);
		pair<T, T> d = a[mt];
		for (int i = 0; i < n; ++i)
			a[i] -= d;

		vi idx(n);
		for (int i = 0; i < n; ++i)
			idx[i] = i;
		sort(idx.begin(), idx.end(), [&](const int& l, const int& r) {return angdis_cmp(a[l], a[r]); });

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
pii cool_gcd(const int& a, const int& b)
{
	if (b)
	{
		int c = a / b;
		pii ans1 = cool_gcd(b, a - b * c);
		return pll(ans1.Y, ans1.X - ans1.Y * c);
	}
	else
		return pii(1, 0);
}
pll cool_gcdll(const ll& a, const ll& b)
{
	if (b)
	{
		ll c = a / b;
		pll ans1 = cool_gcdll(b, a - b * c);
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
ll pow_modll(const ll& a, const ll& b, const ll& p)
{
	if (b < 2)
	{
		if (b == 0)
			return 1;
		else
			return a;
	}
	ll temp = pow_modll(a, b >> 1ll, p);
	temp = prodll(temp, temp, p);
	if (b & 1ll)
		return prodll(temp, a, p);
	else
		return temp;
}
int inverse(int a, int n)
{
	int c = cool_gcd(a, n).X;
	if (c < 0)
		c += n;
	return c;
}
ll inversell(ll a, ll n)
{
	ll c = cool_gcdll(a, n).X;
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
ll discr_log(ll a, ll b, ll n)
{
	int k = ((int)(sqrt((long double)n)));
	ll a1 = inversell(a, n);
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
ll common_discr_log(ll a, ll b, ll n)
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
			ll ob = inversell(multp, n);
			b = pr_p(b, ob, n);
			ll ans = discr_log(a, b, n);
			if (ans == -1)
				return -1;
			else
				return ans + C;
		}
	}
	else
		return discr_log(a, b, n);
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
bool miller_rabin_check(const ul& n, const ul& prime, const ul& odd, const ul& pot, const ul& nmo)
{
	long long x = pow_modll(prime, odd, n);
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
		if (miller_rabin_check(n, little_primes[i], odd, pot, nmo) == false)
			return false;
		++i;
	}
	return true;
}

vpui factorizator::pollardRho(const ul& n)
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
vpui factorizator::factor(ul n)
{
	vpui ans;
	for (int i = 0; n >= N && i < sz(pr) && pr[i] < LITTLE_BORDER; ++i)
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
bool check_primitive_root(const int& ph, const vi& to_check, const int& r, const int& n)
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
		if (check_primitive_root(p, to_check, i, n))
			return i;
	return -1;
}
int unite_mod(const int& a, const int& p, const int& b, const int& q)
{
	pii c = cool_gcd(p, q);
	int pr = p * q;
	int ans = ((a * c.Y * q + b * c.X * p) % pr + pr) % pr;
	return ans;
}
ll unite_modll(const ll& a, const ll& p, const ll& b, const ll& q)
{
	pll c = cool_gcdll(p, q);
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
int square_root_prime_modulo(int c, int n, const int& pr, const int& k)
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
			int ans1 = square_root_prime_modulo(c, n, pr, k - l);
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
			int u = ((int)discr_log(primitive, c, n));
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
int square_root_modulo(const int& c, const int& n)
{
	vpui f = fac.factor(n);
	int a = 0, p = 1;
	for (int i = 0; i < sz(f); ++i)
	{
		int q = 1;
		for (int j = 0; j < f[i].Y; ++j)
			q *= f[i].X;
		int b = square_root_prime_modulo(c, q, f[i].X, f[i].Y);
		if (b == -1)
			return -1;
		a = unite_mod(a, p, b, q);
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
	inline ll clzdll(ul x)
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
	inline ll ctzdll(ul x)
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

#ifdef FAST_BUILTINS
namespace BGF 

{
	const unsigned BHC = 65535u;
	const ul BHCL = 65535ull;
	const unsigned BHN = 65536u;
	const unsigned BHL = 16u;
	const unsigned LH = 4294901760u;
	const unsigned RH = 65535u;
	const ul BHLL1 = 16ull;
	const ul BHLL2 = 32ull;
	const ul BHLL3 = 48ull;
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
	inline ll cntcll(const ul& x)
	{
		return CNT[x & BHCL] + CNT[(x >> BHLL1) & BHCL] + CNT[(x >> BHLL2) & BHCL] + CNT[(x >> BHLL3) & BHCL];
	}
	inline int clzc(const unsigned& x)
	{
		if (x & LH)
			return CLZ[x >> BHL] - BHL;
		else
			return CLZ[x];
	}
	inline ll clzcll(const ul& x)
	{
		if (x & LHL)
			return clzc(x >> BHLL2);
		else
			return clzc(x) + BHLL2;
	}
	inline int ctzc(const unsigned& x)
	{
		if (x & RH)
			return CTZ[x & RH];
		else
			return CTZ[x >> BHL] + BHL;
	}
	inline ll ctzcll(const ul& x)
	{
		if (x & RHL)
			return ctzc(x);
		else
			return ctzc(x >> BHLL2) + BHLL2;
	}
}
#define __builtin_popcount BGF::cntc
#define __builtin_popcountll BGF::cntcll
#define __builtin_ctzll BGF::ctzcll
#if !defined(__GNUC__)
#define __builtin_ctz BGF::ctzc
#define __builtin_clz BGF::clzc
#define __builtin_clzll BGF::clzcll
#endif
#elif !defined(__GNUC__)
#define __builtin_popcount BGF::cntd
#define __builtin_popcountll BGF::cntdll
#define __builtin_ctzll BGF::ctzdll
#define __builtin_ctz BGF::ctzd
#define __builtin_clz BGF::clzd
#define __builtin_clzll BGF::clzdll
#endif



#define ONPC_FILES
const string INPUT_FILE = "input.txt";
const string OUTPUT_FILE = "output.txt";

const int M = 998244353;


int another_main()
{
	int t;
	cin >> t;
	for (int I = 0; I < t; ++I) {
		int n, k;
		cin >> n >> k;
		vvb v(n, vb(n));
		vvi u(n);
		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			for (int j = 0; j < n; ++j)
				if (v[i][j] = (s[j] == '0'))
					u[i].pb(j);
		}
		vvb ans(n, vb(n, false));
		bool good = true;

		for (int i = k - 2; i >= 0; --i) {
			int r = n - k + i + 1;
			int c = i;
			while (r - c >= k - n - 1 && r >= 0) {
				int C = c;
				while (!u[r].empty() && u[r].back() >= c) {
					C = max(C, u[r].back());
					u[r].pop_back();
				}
				if (r == i)
					C = n - k + i + 1;
				for (int j = c; j <= C; ++j)
					ans[r][j] = true;
				c = C;
				--r;
			}
		}

		for (int i = 0; i < n; ++i)
			for (int j : u[i])
				if (i - j >= k - n && i - j <= n - k)
					good = false;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (i - j < k - n || i - j > n - k)
					ans[i][j] = true;


		if (good) {
			cout << "YES\n";
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j)
					cout << ans[i][j];
				cout << '\n';
			}
		} else
			cout << "NO\n";
	}
	return 0;
}

int main()
{
	FAST_IO;
	

	

#ifdef FAST_BUILTINS
	BGF::initialize();
#endif
#ifdef ONPC
#ifdef ONPC_FILES
	freopen(INPUT_FILE.c_str(), "rt", stdin);
	freopen(OUTPUT_FILE.c_str(), "wt", stdout);
#endif
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#else
#ifdef FILES
	freopen(INPUT_FILE.c_str(), "rt", stdin);
	freopen(OUTPUT_FILE.c_str(), "wt", stdout);
#endif
#endif
	int AMR = another_main();
#ifdef ONPC
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
	return AMR;
}
