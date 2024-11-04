







































using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

typedef long long            ll;
typedef unsigned int         uint;
typedef unsigned long long   ull;



const double    Pi    = 2 * acos(0.0),  Euler = 2.71828182845904523536,
                Error = 1e-9,           GoldenR = (1 + sqrtl(5.0)) / 2;

const ll   Magic = 2305843009213693951;
const int  id0  = (int)2e5 + 9,  oo = 0x3f3f3f3f;
const int  id3 = (1 << 30) + 7, id4 = (int)1e9 + 7, ModPT = (int)1e9;



template <class T>
T Gcd(T a, T b) { return b ? Gcd(b, a % b) : a; }

template <class T>
T Lcm(T a, T b) { return a / Gcd(a, b) * 1ll * b; }

template <class T> 
T Phi(T a, T k) { return pow(a, k - 1) * (a - 1); }

template <class T>
using indexed_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update >;

template <class T>
using matrix = vector < vector <T> >;

template <class T>
using min_heap = priority_queue < T, vector <T>, greater <T> >;


template <class T>
string toString(T x) { stringstream sout; sout << x; return sout.str(); }


int dx8[8] = { 1, -1, 0, 0, 1, 1, -1, -1 }, dx4[4] = { 0, 0, 1,-1};
int dy8[8] = { 0, 0, 1, -1, 1, -1, 1, -1 }, dy4[4] = { 1,-1, 0, 0};





template <class T>
vector <T> id5(T v, vector <T> adj[])
{
	vector <T> inDegree(v, 0);
	rep(i, 0, v) rep(j, 0, sz(adj[i])) ++inDegree[adj[i][j]];

    vector <T> topOrder;
	queue <T> q;
	rep(i, 0, v) if(!inDegree[i]) q.push(i);

	while(!q.empty())
	{
		T front = q.front(); q.pop();
		topOrder.PB(front);
		rep(i, 0, sz(adj[front]))
		{
			--inDegree[adj[front][i]];
			if(!inDegree[adj[front][i]]) q.push(adj[front][i]);
		}
	}
	return topOrder;
}



ll ModExp(ll a, ll b,ll m = id4)
{
	ll x = 1;
	while(b > 0)
	{
		if(b & 1) x = (x * a) % m;
		a = (a * a) % m;
		b >>= 1ll;D(x);
	}
	return x;
}



template <class T>
tuple <T, T, T> id9(T a, T b)
{
    if (!b) return {1, 0, a};
    else
    {
        int x, y, g;
        tie(x, y, g) = id9(b, a % b);
        return {y, x - (a / b) * y, g}; 
    }
}



template <class T>
T Alpha(T n)
{
	if(!n) return 1;
	return sqrtl(2.0 * Pi * n) * powl((n / Euler), n);
}




bitset <(ll)1e9 + 9> isPrime;
void sieve(ll n)
{
     for(ll i = 5; i * i <= n; i += 6)
     {
         if(!isPrime[i] && i % 3 && i % 2)
            for (ll j = (ll)i * i; j <= n; j += i) isPrime.set(j);

         ll nx = i + 2;
         if(!isPrime[nx] && nx % 3 && nx % 2)
            for (ll j = nx * nx; j <= n; j += nx)  isPrime.set(j);
     }
}





template <class T>
vector < pair <T, T> > id7(T n)
{
	vector < pair <T, T> > ans;
	for (int i = 2; (ll)i * i <= n; ++i)
	{
		if (n % i == 0)
		{
			int cnt = 0;
			while (n % i == 0) n /= i, cnt++;
			if (cnt) ans.push_back({i, cnt});
		}
	}
	if (n > 1) ans.push_back({n, 1});
	return ans;
}



template <class T>
vector <T> primeFactors(T n)
{
	vector <T> ans;
	for (int i = 2; (ll)i * i <= n; ++i) if (n % i == 0)
	{
        while (n % i == 0) n /= i;
        ans.push_back(i);
	}
	if (n > 1) ans.push_back(n);
	return ans;
}



template <class T>
void factors(vector < pair <T, T> > primeFactors, vector <T> &ans, T cur = 0, T curRes = 1)
{
	if (cur == primeFactors.size()) { ans.push_back(curRes); return; }
	for (int i = 0; i <= primeFactors[cur].second; ++i)
	{
		factors(primeFactors, ans, cur + 1, curRes);
		curRes *= primeFactors[cur].first;
	}
}



vector <ll> zFunction(string s)
{
	ll n = s.size(), L = 0, R = 0;
	vector <ll> z(n);
	for (int i = 1; i < n; ++i)
	{
		if (i > R)
		{
			L = R = i;
			while (R < n && s[R - L] == s[R]) R++;
			z[i] = R - L, R--;
		}
		else
		{
			ll k = i - L;
			if (z[k] < R - i + 1) z[i] = z[k];
			else
			{
				L = i;
				while (R < n && s[R - L] == s[R]) R++;
				z[i] = R - L, R--;
			}
		}
	}
	return z;
}



template <class T>
T id6(vector <T> v, ll a)
{
    ll re = 0;
    for(int i = 0; i < (1ll << sz(v)); i++)
    {
        ll prod = 1, cnt = 0;
        for(int j = 0; j < sz(v); j++) if(i & (1ll << j))
            prod = prod * (ll)v[j], cnt++;

        if(cnt & 1) re -= (a / prod);
        else        re += (a / prod);
    }
    return re;
}



vector <ll> id2(string text, string pattern)
{
	string key = pattern + '$' + text;
	vector <ll> z = zFunction(key);
	vector <ll> res;
	ll m = sz(pattern);
	for (int i = m + 1; i < sz(key); ++i) if (z[i] == m) res.push_back(i - m - 1);
	return res;
}



template <class T>
vector <T> kaden(vector <T> &arr)
{
	vector <T> kaden(arr.size());
	kaden[0] = arr[0];
	for (int i = 1; i < sz(arr); ++i) kaden[i] = max(arr[i], arr[i] + kaden[i - 1]);
	return kaden;
}




int fact[id0], inv[id0];
void id10()
{
	fact[0] = inv[0] = 1;
	for(int i = 1; i < id0; ++i)
	{
		fact[i] = (fact[i-1] * i) % mod;
		inv[i] = powMod(fact[i], mod - 2, mod);
	}
}

ll id8(ll n, ll r, ll M = id4)
{
	ll res = 1;
	res = (res * 1ll * fact[n]) % M;
	res = (res * 1ll * inv[r]) % M;
	res = (res * 1ll * inv[n-r]) % M;
	return res;
}





template <class T>
T MulMod(T a, T b, T m = id4)
{
	T res = 0;
	a = a % m;
	while (b > 0)
	{
		if (b % 2) res = (res + a) % m;
		a = (a * 2) % m;
		b /= 2;
	}
	return res % m;
}



bool id1(ll a)
{
    if(a <= 3) return a > 1;
    if(!(a % 2) || !(a % 3)) return 0;
    for(int i = 5; (ll)i * i <= a; i += 6) if(!(a % i) || !(a % (i + 2))) return 0;
    return 1;
}



ll nCr(ll n, ll r, ll m = id4)
{
	if (n < r) return 0;
	ll res = 1, rem = 1;
	for (int i = n - r + 1; i <= n; i++) res = (res * i) % m;
	for (int i = 2; i <= r; i++) rem = (rem * i) % m;
	return (res * ModExp(rem, m - 2, m)) % m;
}



template <class T>
T ModInverse(T a, T m)
{
	a = a % m;
	for (int x = 1; x < m; ++x) if ((a * x) % m == 1) return x;
	return -1;
}




struct Matrix
{
    int r, c;
    int a[2][2] = {};
    Matrix(int r, int c)
    {
        this->r = r;
        this->c = c;
    }
};

Matrix MatMul(Matrix a, Matrix b)
{
    Matrix c = Matrix(a.r, b.c);
    rep(i, 0, a.r) rep(j, 0, b.c) rep(k, 0, b.r)
        c.a[i][j] = (c.a[i][j] + (a.a[i][k]* 1ll * b.a[k][j]) % id4) % id4;
    return c;
}

Matrix MatExp(Matrix a, ll p)
{
    if(p <= 1) return a;
    if(p & 1) return MatMul(MatExp(a, p - 1), a);

    Matrix half = MatExp(a, p >> 1ll);
    return MatMul(half, half);
}


template <class T>
matrix <T> MatMul(matrix <T> A, matrix <T> B)
{
	matrix <T> C(sz(A), vector <int> (sz(B[0])));
	for (int i = 0; i < sz(A); ++i)
		for (int j = 0; j < sz(B[0]); ++j)
		{
			C[i][j] = 0;
			for (int k = 0; k < sz(B); ++k)
                C[i][j] = (C[i][j] + ((A[i][k] * 1ll * B[k][j]) % id4)) % id4;
		}
	return C;
}

template <class T>
matrix <T> MatPow(matrix <T> A, int p)
{
	if (p == 1) return A;
	if (p & 1) return MatMul(A, MatPow(A, p - 1));
	else
	{
		matrix <T> C = MatPow(A, p/2);
		return MatMul(C, C);
	}
}



void Fast()
{
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin.exceptions(cin.failbit);
}



void File()
{
    
    freopen("new.in", "r", stdin);
    freopen("output.out", "w", stdout);
    

}



int n, m, l, r, x, a[id0], next_a[id0];

inline void Solve()
{
	cin >> n >> m;
	read(a, 0, n);

	next_a[n - 1] = -1;

	repr(i, n - 2, -1) 
		if(a[i] == a[i + 1])
			next_a[i] = next_a[i + 1];
		else
			next_a[i] = i + 2;

	while(m--)
	{
		cin >> l >> r >> x; l--; 
		if(a[l] == x && next_a[l] <= r) 
		{
			cout << next_a[l] << endl;
			continue;
		}
		else if(a[l] != x)
		{
			cout << l + 1 << endl;
			continue;
		}
		else
			cout << -1 << endl;
	}
}



int main()
{
    Fast(); File(); Solve(); 
}