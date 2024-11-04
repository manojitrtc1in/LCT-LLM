

#include <bits/stdc++.h>

#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin(), (v).end())
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(i, b) for (int i = 0; i < b; i++)
#define For(i, a, b) for (int i = a; i < b; i++)
#define nl << "\n"
#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;



class DSU
{
private:
	int N;
	int *p;
	int *s;

public:
	DSU(int n);
	~DSU();
	void reset(int n);
	int find(int v);
	void merge(int a, int b);
};

DSU::DSU(int n = 100010)
{
	N = n;
	p = new int[N];
	s = new int[N];
	for (int i = 0; i < N; i++)
	{
		p[i] = i;
		s[i] = 1;
	}
}

DSU::~DSU()
{
	delete[] p;
	delete[] s;
}

int DSU::find(int v)
{
	if (v == p[v])
		return v;
	return p[v] = find(p[v]);
}

void DSU::merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b)
	{
		if (s[a] < s[b])
			swap(a, b);
		s[a] += s[b];
		p[b] = a;
	}
}

void DSU::reset(int n = 100010)
{
	N = n;
	delete[] p;
	delete[] s;
	p = new int[N];
	s = new int[N];
	for (int i = 0; i < N; i++)
	{
		p[i] = i;
		s[i] = 1;
	}
}





template <typename T>
class IdemSparseTable
{
private:
	int N;
	int K;
	int **st;
	int *log;
	T (*f)(T, T);

public:
	IdemSparseTable<T>(int *a, int n = 100010, int k = 25, T (*g)(T, T) = min);
	T answer(int L, int R);
	~IdemSparseTable();
};

template <typename T>
IdemSparseTable<T>::IdemSparseTable(int *a, int n, int k, T (*g)(T, T))
{
	N = n;
	K = k;
	f = g;
	log = new int[N + 1];
	st = new int *[N + 1];
	for (int i = 0; i <= N; i++)
		st[i] = new int[K + 1];
	log[1] = 0;
	for (int i = 2; i <= N; i++)
		log[i] = log[i / 2] + 1;
	for (int i = 0; i < n; i++)
		st[i][0] = a[i];
	for (int j = 1; j <= K; j++)
		for (int i = 0; i + (1 << j) <= n; i++)
			st[i][j] = f(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

template <typename T>
IdemSparseTable<T>::~IdemSparseTable()
{
	delete[] log;
	for (int i = 0; i <= N; i++)
		delete[] st[i];
	delete[] st;
}

template <typename T>
T IdemSparseTable<T>::answer(int L, int R)
{
	int j = log[R - L + 1];
	return f(st[L][j], st[R - (1 << j) + 1][j]);
}

template <typename T>
class AssocSparseTable
{
private:
	int N;
	int K;
	int **st;
	T (*f)(T, T);

public:
	AssocSparseTable<T>(int *a, int n = 100010, int k = 25, T (*g)(T, T) = [](T a, T b) -> T { return a + b; });
	T answer(int L, int R);
	~AssocSparseTable();
};

template <typename T>
AssocSparseTable<T>::AssocSparseTable(int *a, int n, int k, T (*g)(T, T))
{
	N = n;
	K = k;
	f = g;
	st = new int *[N + 1];
	for (int i = 0; i <= N; i++)
		st[i] = new int[K + 1];
	for (int i = 0; i < n; i++)
		st[i][0] = a[i];
	for (int j = 1; j <= K; j++)
		for (int i = 0; i + (1 << j) <= n; i++)
			st[i][j] = f(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

template <typename T>
AssocSparseTable<T>::~AssocSparseTable()
{
	for (int i = 0; i <= N; i++)
		delete[] st[i];
	delete[] st;
}

template <typename T>
T AssocSparseTable<T>::answer(int L, int R)
{
	T ans = 0;
	for (int j = K; j >= 0; j--)
	{
		if ((1 << j) <= R - L + 1)
		{
			ans = f(ans, st[L][j]);
			L += 1 << j;
		}
	}
	return ans;
}

typedef IdemSparseTable<int> IST;
typedef AssocSparseTable<int> AST;



ll fibo(ll n) 

{
	ll M[2][2] = {{1, 1}, {1, 0}}, res[2][2] = {{1, 0}, {0, 1}}, a, b, c, d;
	while (n)
	{
		if (n % 2)
		{
			a = (res[0][0] * M[0][0]) + (res[0][1] * M[1][0]);
			b = (res[0][0] * M[1][0]) + (res[0][1] * M[1][1]);
			c = (res[1][0] * M[0][0]) + (res[1][1] * M[1][0]);
			d = (res[1][0] * M[1][0]) + (res[1][1] * M[1][1]);
			res[0][0] = a;
			res[0][1] = b;
			res[1][0] = c;
			res[1][1] = d;
		}
		a = (M[0][0] * M[0][0]) + (M[0][1] * M[1][0]);
		b = (M[0][0] * M[1][0]) + (M[0][1] * M[1][1]);
		c = (M[1][0] * M[0][0]) + (M[1][1] * M[1][0]);
		d = (M[1][0] * M[1][0]) + (M[1][1] * M[1][1]);
		M[0][0] = a;
		M[0][1] = b;
		M[1][0] = c;
		M[1][1] = d;
		n >>= 1;
	}
	return res[0][1];
}

ll fibo(ll n, ll m) 

{
	ll M[2][2] = {{1, 1}, {1, 0}}, res[2][2] = {{1, 0}, {0, 1}}, a, b, c, d;
	while (n)
	{
		if (n % 2)
		{
			a = (res[0][0] * M[0][0]) % m + (res[0][1] * M[1][0]) % m;
			b = (res[0][0] * M[1][0]) % m + (res[0][1] * M[1][1]) % m;
			c = (res[1][0] * M[0][0]) % m + (res[1][1] * M[1][0]) % m;
			d = (res[1][0] * M[1][0]) % m + (res[1][1] * M[1][1]) % m;
			res[0][0] = a % m;
			res[0][1] = b % m;
			res[1][0] = c % m;
			res[1][1] = d % m;
		}
		a = (M[0][0] * M[0][0]) % m + (M[0][1] * M[1][0]) % m;
		b = (M[0][0] * M[1][0]) % m + (M[0][1] * M[1][1]) % m;
		c = (M[1][0] * M[0][0]) % m + (M[1][1] * M[1][0]) % m;
		d = (M[1][0] * M[1][0]) % m + (M[1][1] * M[1][1]) % m;
		M[0][0] = a % m;
		M[0][1] = b % m;
		M[1][0] = c % m;
		M[1][1] = d % m;
		n >>= 1;
	}
	return res[0][1];
}

ull bpow(ull a, ull b)
{
	ull res = 1;
	while (b > 0)
	{
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

ll bpow(ll a, ll b, ll m) 

{
	a %= m;
	ll res = 1;
	while (b > 0)
	{
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}

void bppow(int p[], int n, int k, int res[]) 

{
	int np[n], r[n];
	memcpy(res, p, n * sizeof(int));
	for (int j = 0; j < n; j++)
		r[j] = j;
	while (k > 0)
	{
		if (k % 2)
		{
			for (int j = 0; j < n; j++)
				np[j] = r[res[j]];
			memcpy(r, np, n * sizeof(int));
		}
		for (int j = 0; j < n; j++)
			np[j] = res[res[j]];
		memcpy(res, np, n * sizeof(int));
		k >>= 1;
	}
	memcpy(res, r, n * sizeof(int));
}

int modInverse(int a, int m)
{
	int m0 = m;
	int y = 0, x = 1;
	if (m == 1)
		return 0;
	if (a % m == 0)
		return 0;
	while (a > 1)
	{
		int q = a / m;
		int t = m;
		m = a % m, a = t;
		t = y;
		y = x - q * y;
		x = t;
	}
	if (x < 0)
		x += m0;
	return x;
}

ll gcd(ll a, ll b, ll &x, ll &y)
{
	if (a == 0)
	{
		x = 0;
		y = 1;
		return b;
	}
	ll x1, y1;
	ll d = gcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

ll gcd(ll a, ll b)
{
	return b ? gcd(b, a % b) : a;
}

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b)
{
	return a / gcd(a, b) * b;
}

bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g)
{
	g = gcd(abs(a), abs(b), x0, y0);
	if (c % g)
	{
		return false;
	}

	x0 *= c / g;
	y0 *= c / g;
	if (a < 0)
		x0 = -x0;
	if (b < 0)
		y0 = -y0;
	return true;
}

void shift_solution(ll &x, ll &y, ll a, ll b, ll cnt)
{
	x += cnt * b;
	y -= cnt * a;
}

ll find_all_solutions(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy)
{
	ll x, y, g;
	if (!find_any_solution(a, b, c, x, y, g))
		return 0;
	a /= g;
	b /= g;

	ll sign_a = a > 0 ? +1 : -1;
	ll sign_b = b > 0 ? +1 : -1;

	shift_solution(x, y, a, b, (minx - x) / b);
	if (x < minx)
		shift_solution(x, y, a, b, sign_b);
	if (x > maxx)
		return 0;
	ll lx1 = x;

	shift_solution(x, y, a, b, (maxx - x) / b);
	if (x > maxx)
		shift_solution(x, y, a, b, -sign_b);
	ll rx1 = x;

	shift_solution(x, y, a, b, -(miny - y) / a);
	if (y < miny)
		shift_solution(x, y, a, b, -sign_a);
	if (y > maxy)
		return 0;
	ll lx2 = x;

	shift_solution(x, y, a, b, -(maxy - y) / a);
	if (y > maxy)
		shift_solution(x, y, a, b, sign_a);
	ll rx2 = x;

	if (lx2 > rx2)
		swap(lx2, rx2);
	ll lx = max(lx1, lx2);
	ll rx = min(rx1, rx2);

	if (lx > rx)
		return 0;
	return (rx - lx) / abs(b) + 1;
}

vector<int> primes(int n)
{
	vector<int> pr;
	int *lp = new int[n + 1];
	memset(lp, 0, (n + 1) * sizeof(int));
	for (int i = 2; i <= n; ++i)
	{
		if (lp[i] == 0)
		{
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] <= n; ++j)
			lp[i * pr[j]] = pr[j];
	}
	for (int i = 0; i <= n; i++)
	{
		cout << lp[i] << " ";
	}
	cout << endl;
	return pr;
}

vector<int> factorize(int n) 

{
	vector<int> factorization;
	int t[] = {2, 3, 5};
	for (int i = 0; i < 3; i++)
	{
		while (n % t[i] == 0)
		{
			factorization.push_back(t[i]);
			n /= t[i];
		}
	}
	static array<int, 8> increments = {{4, 2, 4, 2, 4, 6, 2, 6}};
	int i = 0;
	for (int d = 7; d * d <= n; d += increments[i++])
	{
		while (n % d == 0)
		{
			factorization.push_back(d);
			n /= d;
		}
		if (i == 8)
			i = 0;
	}
	if (n > 1)
		factorization.push_back(n);
	return factorization;
}

int phi(int n) 

{
	int result = n;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	}
	if (n > 1)
		result -= result / n;
	return result;
}

bool probablyPrimeFermat(ull n, ull iter = 10) 

{
	srand(time(NULL));
	if (n < 4)
		return n == 2 || n == 3;
	for (ull i = 0; i < iter; i++)
	{
		ull a = 2 + rand() % (n - 3);
		if (bpow(a, n - 1, n) != 1)
			return false;
	}
	return true;
}

map<ll, ll> mfactorize(ll n)
{
	map<ll, ll> factorization;
	ll t[] = {2, 3, 5};
	for (ll i = 0; i < 3; i++)
	{
		while (n % t[i] == 0)
		{
			factorization[t[i]]++;
			n /= t[i];
		}
	}
	static array<ll, 8> increments = {{4, 2, 4, 2, 4, 6, 2, 6}};
	ll i = 0;
	for (ll d = 7; d * d <= n; d += increments[i++])
	{
		while (n % d == 0)
		{
			factorization[d]++;
			n /= d;
		}
		if (i == 8)
			i = 0;
	}
	if (n > 1)
		factorization[n]++;
	return factorization;
}

set<ll> divisors(ll n)
{
	set<ll> d;
	for (ll i = 1; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			d.insert(i);
			d.insert(n / i);
		}
	}
	return d;
}

ull divisorSum(ull n)
{
	map<ll, ll> m = mfactorize(n);
	ull sum = 1;
	for (auto it = m.begin(); it != m.end(); it++)
	{
		ull s = 1;
		for (int i = 1; i <= it->second; i++)
			s += bpow(it->first, i);
		sum *= s;
	}
	return sum;
}

ull divisorNumber(ull n)
{
	map<ll, ll> m = mfactorize(n);
	ull num = 1;
	for (map<ll, ll>::iterator it = m.begin(); it != m.end(); it++)
		num *= it->second + 1;
	return num;
}

bool correct(vector<ull> t)
{
	for (int i = 0; i < t.size() - 1; i++)
	{
		if (t[i] % 3 == 0)
		{
			if (t[i] != t[i+1] * 3 and t[i] * 2 != t[i+1])
				return false;
		}
		else if (t[i+1] != t[i] * 2)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	ull a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<int> g[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i] * 2 == a[j])
				g[i].push_back(j);
			if (a[i] * 3 == a[j])
				g[j].push_back(i);
		}
	}
	int beg = 0;
	vector<ull> test;
	for (int i = 0; i < n; i++)
	{
		if (g[i].size() == 1)
		{
			beg = i;
			test.push_back(a[beg]);
			while (g[beg].size())
			{
				test.push_back(a[g[beg][0]]);
				beg = g[beg][0];
			}
			if (test.size() != n or !correct(test))
				test.clear();
			else
			{
				cout << test[0];
				for (int e = 1; e < test.size(); e++)
				{
					cout << " " << test[e];
				}
				cout << endl;
				return 0;
			}
		}
	}
	return 0;
}
