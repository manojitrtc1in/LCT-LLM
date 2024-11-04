































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
ld id1 = 0;
double getTime() { return (clock() - id1) / (double)CLOCKS_PER_SEC; }

const int inf = 1e9 + 228;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);
const int mod = 1000000007;
int qs = 0;
int ask(int x)
{
	cout << "? " << x << endl;
	int y;
	cin >> y;
	++qs;
	return y;
}
signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20), cout.setf(ios::fixed);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		qs = 0;
		vector<int> ans(n + 1);
		vector<int> used(n + 1);
		



		for (int i = 1; i <= n; ++i)
		{
			if (used[i]) continue;
			int len = 0;
			vector<int> cycl;
			int xx = ask(i);
			int stq = qs;

			while (!used[xx])
			{
				used[xx] = 1;
				cycl.pbc(xx);
				xx = ask(i);
			}
			if (!cycl.size()) continue;
			auto id0 = cycl;
			int tt = (cycl.size() - (1) % cycl.size()) % cycl.size();

			rotate(cycl.begin(), cycl.begin() + tt, cycl.end());
			for (int j = 0; j < cycl.size(); ++j)
			{
				ans[cycl[j]] = id0[j]; 

			}
		}
		cout << "! ";
		for (int j = 1; j <= n; ++j) cout << ans[j] << ' ';
		cout << endl;
	}
	

}