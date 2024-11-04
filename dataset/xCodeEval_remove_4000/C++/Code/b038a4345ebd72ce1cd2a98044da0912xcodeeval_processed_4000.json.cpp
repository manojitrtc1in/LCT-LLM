










































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
pair<int, int> operator-(pair<int, int> a, pair<int, int> b)
{
	return { a.first - b.first, a.second - b.second };
}
pair<int, int> operator+(pair<int, int> a, pair<int, int> b)
{
	return { a.first + b.first, a.second + b.second };
}






































const int inf = 1e9 + 228;
using namespace chrono;
const ld EPS = 1e-12;
const ld PI = acos(-1.0);
const int mod = 1000000007;

signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(6), cout.setf(ios::fixed);
	int n, m;
	cin >> n >> m;
	map<pair<int, int>, char> kek;
	int c1 = 0, c2 = 0;
	for (int i = 0; i < m; ++i)
	{
		char t;
		cin >> t;
		if (t == '+')
		{
			int u, v;
			char c;
			cin >> u >> v >> c;
			if (kek.count({ v,u }))
			{
				if (kek[{v, u}] == c) ++c1;
				else ++c2;
			}
			kek[{u, v}] = c;
		}
		else if (t == '-')
		{
			int u, v;
			cin >> u >> v;
			if (kek.count({ v,u }))
			{
				if (kek[{u, v}] == kek[{v, u}])--c1;
				else --c2;
			}
			kek.erase({ u,v });
		}
		else
		{
			int k;
			cin >> k;
			if (k % 2)
			{
				if (c1 || c2)
				{
					cout << "YES\n";
				}
				else
				{
					cout << "NO\n";
				}
			}
			else
			{
				if (c1)
				{
					cout << "YES\n";
				}
				else
				{
					cout << "NO\n";
				}
			}
		}
	}
	

}







