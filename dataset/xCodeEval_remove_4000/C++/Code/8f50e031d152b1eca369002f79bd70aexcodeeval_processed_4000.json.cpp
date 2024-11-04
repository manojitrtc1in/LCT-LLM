































using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;










template<typename T1, typename T2>
inline void chkmin(T1& x, const T2& y)
{
	if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y)
{
	if (x < y) x = y;
}
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
ld id0 = 0;
double getTime() { return (clock() - id0) / (double)CLOCKS_PER_SEC; }

const int inf = 1e9 + 228;
const ld EPS = 0;
const ld PI = acos(-1.0);
int mod = 1000000007;
int mul(int a, int b)
{
	return 1ll * a * b % mod;
}
int add(int a, int b)
{
	if (a + b >= mod) return a + b - mod;
	return a + b;
}
int sub(int a, int b)
{
	if (a - b < 0) return a - b + mod;
	return a - b;
}
int binpow(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1)res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}
int inv(int x)
{
	return binpow(x, mod - 2);
}
const int MAXN = 4e6 + 228;
int fact[MAXN]; int rfact[MAXN];
int cnk(int n, int k)
{
	if (k<0 || k>n) return 0;
	return mul(fact[n], mul(rfact[k], rfact[n - k]));
}
signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20), cout.setf(ios::fixed);
	fact[0] = 1;
	for (int i = 1; i < MAXN; ++i) fact[i] = mul(fact[i - 1], i);
	rfact[MAXN - 1] = inv(fact[MAXN - 1]);
	for (int i = MAXN - 2; i >= 0; --i) rfact[i] = mul(rfact[i + 1], i + 1);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int kek = n * m;
		int res = 0;
		int zz = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				char x;
				cin >> x;
				if (x == '0')++zz;
			}
		}
		for (int z = max(zz,1); z <= kek; ++z)
		{
			res = add(res, cnk(kek -zz, z-zz));
		}
		cout << res << '\n';
	}


}