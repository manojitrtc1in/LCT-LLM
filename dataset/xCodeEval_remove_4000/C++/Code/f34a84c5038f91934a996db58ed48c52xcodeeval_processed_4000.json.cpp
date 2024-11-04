















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
typedef map<int, int> mii;
typedef map<int, ll> mil;



template <typename T>
class SegmentTree
{
private:
	static const int N = 100010;
	T neutral;
	T t[4 * N];
	int n;

public:
	SegmentTree(T *a, int len = N, T ne = 0);
	void build(T *a, int v, int tl, int tr);
	void update(int v, int tl, int tr, int pos, T new_val);
	T sum(int v, int tl, int tr, int l, int r);
};

template <typename T>
SegmentTree<T>::SegmentTree(T *a, int len, T ne)
{
	n = len;
	neutral = ne;
	build(a, 1, 0, n - 1);
}

template <typename T>
void SegmentTree<T>::build(T a[], int v, int tl, int tr)
{
    if (tl == tr)
        t[v] = a[tl];
	else
	{
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

template <typename T>
T SegmentTree<T>::sum(int v, int tl, int tr, int l, int r)
{
	if (l > r) 
        return neutral;
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm)) + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

template <typename T>
void SegmentTree<T>::update(int v, int tl, int tr, int pos, T new_val) {
    if (tl == tr)
        t[v] = new_val;
    else
	{
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}





template <typename T>
class id1
{
private:
	int n;
	int sz;
	T neutral;
	vector<T> b;
	T *a;
	T (*f)(T a, T b);

public:
	id1(T *ar, int len = 100010, T (*g)(T, T) = [](T a, T b) -> T { return a + b; }, T ne = 0);
	T answer(int l, int r);
	void update(int idx, T val, bool sum = true);
};

template <typename T>
id1<T>::id1(T *ar, int len, T(*g)(T a, T b), T ne)
{
	n = len;
	neutral = ne;
	f = g;
	a = ar;
	sz = (int)sqrt(len) + 1;
	b.assign(sz, neutral);
	for (int i = 0; i < n; i++)
		b[i / sz] = f(b[i / sz], a[i]);
}

template <typename T>
T id1<T>::answer(int l, int r)
{
	T ans = neutral;
	int c_l = l / sz;
	int c_r = r / sz;
	if (c_l == c_r)
	{
		for (int i = l; i <= r; i++)
			ans = f(ans, a[i]);
	}
	else
	{
		for (int i=l, end=(c_l+1)*sz-1; i<=end; ++i)
			ans = f(ans, a[i]);
		for (int i=c_l+1; i<=c_r-1; ++i)
			ans = f(ans, b[i]);
		for (int i=c_r*sz; i<=r; ++i)
			ans = f(ans, a[i]);
	}
	return ans;
}

template <typename T>
void id1<T>::update(int idx, T val, bool sum)
{
	int k = idx / sz;
	if (sum)
	{
		b[k] += val - a[idx];
		a[idx] = val;
	}
	else
	{
		a[idx] = val;
		for (int i = 0; i < sz and k * sz + i < n; i++)
			b[k] = f(b[k], a[k * sz + i]);
	}
}





class DSU
{
private:
	int N;
	int *p;
	int *s;

public:
	DSU(int n = 100010);
	~DSU();
	void reset(int n);
	int find(int v);
	void merge(int a, int b);
};

DSU::DSU(int n)
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
	IdemSparseTable<T>(int *a, int n = 100010, int k = 25, T (*g)(T, T) = [] (T a, T b) -> T {return min(a,b);});
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





template <typename T>
class id9
{
private:
	vector<T> bit;
	int n;
	T def;
	T (*f)(T a, T b);

public:
	id9(T *a = NULL, int sz = 100010, T d = 0, T (*g)(T a, T b) = [](T a, T b) -> T { return a + b; });
	void update(int l, T val);
	void rrupdate(int l, T val);
	void rupdate(int l, int r, T val);
	T answer(int r);
	T panswer(int idx);
};

template <typename T>
id9<T>::id9(T *a, int sz, T d, T (*g)(T a ,T b))
{
	n = sz + 1;
	f = g;
	def = d;
	bit.assign(n, def);
	if (a != NULL)
		for (int i = 0; i < n; i++)
			update(i, a[i]);
}

template <typename T>
void id9<T>::update(int l, T val)
{
	for(; l < n; l = l | (l + 1))
		bit[l] = f(bit[l], val);
}

template <typename T>
void id9<T>::rrupdate(int l, T val)
{
	for(++l; l < n; l += l & (-l))
		bit[l] = f(bit[l], val);
}

template <typename T>
void id9<T>::rupdate(int l, int r, T val)
{
	rrupdate(l, val);
	rrupdate(r + 1, -val);
}

template <typename T>
T id9<T>::answer(int r)
{
	T ret = def;
	for(; r >= 0; r = (r & (r + 1)) - 1)
		ret = f(ret, bit[r]);
	return ret;
}

template <typename T>
T id9<T>::panswer(int idx)
{
	T ret = def;
	for(++idx; idx > 0; idx -= (idx & (-idx)))
		ret = f(ret, bit[idx]);
	return ret;
}

typedef id9<int> FTI;
typedef id9<ll> FTL;



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

void id4(int p[], int n, int k, int res[]) 

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

bool id3(ll a, ll b, ll c, ll &x0, ll &y0, ll &g)
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

ll id6(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy)
{
	ll x, y, g;
	if (!id3(a, b, c, x, y, g))
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

bool id2(ull n, ull iter = 10) 

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

map<ll, ll> id7(ll n)
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

set<ll> id0(ll n)
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

ull id5(ull n)
{
	map<ll, ll> m = id7(n);
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

ull id8(ull n)
{
	map<ll, ll> m = id7(n);
	ull num = 1;
	for (map<ll, ll>::iterator it = m.begin(); it != m.end(); it++)
		num *= it->second + 1;
	return num;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n, a[300100], k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	multiset<int> s;
	for (int i = 0; i < n - 1; i++)
		s.insert(a[i] - a[i + 1]);
	auto it = s.begin();
	advance(it, k - 1);
	cout << accumulate(s.begin(), it, a[n - 1] - a[0]) << endl;
	return 0;
}