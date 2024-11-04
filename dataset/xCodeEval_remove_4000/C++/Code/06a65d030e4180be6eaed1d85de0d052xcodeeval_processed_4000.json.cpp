






































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


using namespace __gnu_pbds;

using ordered_set = tree<
	pair<int, int>,
	null_type,
	less<pair<int, int>>,
	rb_tree_tag,
	tree_order_statistics_node_update>;
const int inf = 1e9 + 228;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);
const int mod = 1000001231;
const ld INF = 1e18;
const int MAXN = 4e5 + 228;

signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20), cout.setf(ios::fixed);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		int bal = 0;
		ll ans = 0;
		vector<ordered_set> trees(3);
		trees[0].insert(mp(0, -228));
		for (int j = 0; j < s.size(); ++j)
		{
			if (s[j] == '+')--bal;
			else ++bal;
			pair<int, int> vv = { bal, j };
			int nb = (bal % 3 + 3) % 3;
			ans += trees[nb].order_of_key(vv);
			trees[nb].insert(vv);
		}
		cout << ans << '\n';
	}
	

}
