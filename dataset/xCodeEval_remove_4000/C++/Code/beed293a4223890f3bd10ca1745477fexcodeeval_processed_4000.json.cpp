








































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
const ld EPS = 1e-9;
const ld PI = acos(-1.0);
const int mod = 1000001231;
const ld INF = 1e18;

signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20), cout.setf(ios::fixed);
	int t;
	cin >> t;
	for(int tst=0;tst<t;++tst)
	{
		ll s, n, k;
		cin >> s >> n >> k;
		
		if (s == k)
		{
			cout << "YES\n";
			continue;
		}
		if (k == 1)
		{
			if (n * 2 <= s)
			{
				cout << "NO\n";
			}
			else
			{
				cout << "YES\n";
			}
			continue;
		}
		ll blocks = s / (k * 2);
		
		ll tg = min(k - 1, s % (k * 2));
		blocks *= k;
		blocks += tg;
		if (blocks >= n)
		{
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
	}
	

}
