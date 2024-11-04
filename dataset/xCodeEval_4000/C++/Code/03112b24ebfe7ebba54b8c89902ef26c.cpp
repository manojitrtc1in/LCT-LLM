

#include "iostream"
#include "fstream"
#include "algorithm"
#include "iomanip"
#include "stack"
#include "queue"
#include "string"
#include "vector"
#include "map"
#include "set"
#include "list"
#include "deque"
#include "complex"
#include "bitset"
#include "cmath"
#include "unordered_set"
#include "unordered_map"
#include "iterator"
#include <ctime>
#include <cassert>
#include "numeric"
#include <cstdio>
#include "random"
#include "chrono"
#include "cstring"








using namespace std;









#define pb push_back
#define maxi(a,b) a = max(a, b);
#define mini(a,b) a = min(a, b);
#define endl '\n'

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sqr(x) ((x) * (x))
#define SZ(a) ((int)(a.size()))
#define watch(x) cout << (#x) << " = " << x << endl;


typedef long double ld;

#define int long long


#define double ld
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<pii> vpii;
typedef vector<char> vc;
typedef vector<vi> vvi;

template<class T>
void show(const vector<T> &a)
{
	for (T x : a)
		cout << x << " ";
	cout << endl;
}

vi xx = { 0, 0, -1, 1 };
vi yy = { -1, 1, 0, 0 };
string dir = "LRUD";

const int N = 5e5 + 50, oo = 3e18 + 500;


const int mod = 1e9 + 7;


const double eps = 1e-9, PI = 2 * acos(0.0);
int n, m, k;
long long cnt = 0;
int lg = 18;
vi g[N];
vi rg[N];
vi visit(N, 0);

int a[N];

void rec(vvi &dp, int i)
{
	visit[i] = 1;

	int j = i + a[i];
	if (j < n)
	{
		int x = ((a[j] & 1) ? 1 : 0);
		dp[i][x] = 1;

		if(!visit[j])
			rec(dp, j);

		mini(dp[i][0], dp[j][0] + 1);
		mini(dp[i][1], dp[j][1] + 1);
	}
		
	j = i - a[i];
	if (j >= 0)
	{
		int x = ((a[j] & 1) ? 1 : 0);
		dp[i][x] = 1;

		if (!visit[j])
			rec(dp, j);

		mini(dp[i][0], dp[j][0] + 1);
		mini(dp[i][1], dp[j][1] + 1);
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	


	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	vvi dp(n, vi(2, oo));

	for (int i = 0; i < n; i++)
	{
		

			rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = n-1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		

		rec(dp, i);
	}

	for (int i = 0; i < n; i++)
	{
		int x = ((a[i] & 1) ? 0 : 1);
		if (dp[i][x] == oo)
			dp[i][x] = -1;
		cout << dp[i][x] << " ";
	}
}


