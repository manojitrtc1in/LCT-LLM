




















































using namespace std;


typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;


const ll INF = 1000LL * 1000 * 1000 * 1000 * 1000 * 1000;
const int inf = 1000 * 1000 * 1000;
const ld PI = acos(-1.0);
const ll mod1 = inf + 7;
const ll mod2 = inf + 9;
const int MAXN = 1000005;
const ld EPS = 1e-11;
int hp = 179;
int invert(bool a)
{
	return ((a & 1) + 1) & 1;
}
vector<vector<int>> bfst(vector<bool>  &a)
{
	vector<bool> x;
	for (int i = a.size() - 6; i < a.size(); ++i)
	{
		x.pbc(a[i]);
	}
	if (x == vector<bool>{0, 0, 00, 00, 0, 0})
	{
		return { {} };
	}
	if (x == vector<bool> {1, 0, 0, 0, 0, 0})
	{
		return { {2,4,6} };
	}
	if (x == vector<bool> {0, 0, 0, 0, 0, 1})
	{
		return { {5,8,11}, {2,5,8} };
	}
	if (x == vector<bool> { 0, 0, 0, 0, 1, 0})
	{
		return { {4,7,10},{3,5,7} };
	}
	if (x == vector<bool> {0, 0, 0, 0, 1, 1})
	{
		return { {4,7,10}, {3,7,11} };
	}
	if (x == vector<bool> {0, 0, 0, 1, 0, 0})
	{
		return { {5,7,9}, {3,5,7} };
	}
	if (x == vector<bool> {0, 0, 0, 1, 0, 1})
	{
		return { {7,9,11},{3,5,7} };
	}
	if (x == vector<bool>{0, 0, 0, 1, 1, 0})
	{
		return { {10,8,9}, {2,5,8} };
	}
	if (x == vector<bool> {0, 0, 0, 1, 1, 1})
	{
		return { {11,9,10} };
	}
	if (x == vector<bool> {1, 1, 0, 1, 1, 1})
	{
		return { {11,9,10}, {5,7,6} };
	}
	if (x == vector<bool> {1, 1, 1, 1, 1, 1})
	{
		return{ {6,7,8},{11,9,10} };
	}
	if (x == vector<bool> {0, 0, 1, 0, 0, 0})
	{
		return { {8,5,2} };
	}
	if (x == vector<bool> {0, 0, 1, 0, 0, 1})
	{
		return { {5,8,11} };
	}
	if (x == vector<bool> {0, 0, 1, 0, 1, 0})
	{
		return { {6,8,10}, {4,5,6} };
	}
	if (x == vector<bool> {0, 0, 1, 0, 1, 1})
	{
		return { {5,8,11},{10,5,0} };
	}
	if (x == vector<bool> {0, 0, 1, 1, 0, 0})
	{
		return { {7,8,9},{3,5,7} };
	}
	if (x == vector<bool> {0, 0, 1, 1, 0, 1})
	{
		return { {5,8,11},{1,5,9} };
	}
	if (x == vector<bool> {0, 0, 1, 1, 1, 0})
	{
		return { {10,9,8} };
	}
	if (x == vector<bool> {0, 0, 1, 1, 1, 1})
	{
		return { {9,10,11}, {8,5,2} };
	}
	if (x == vector<bool> {0, 1, 0, 0, 0, 0})
	{
		return { {3,5,7} };
	}
	if (x == vector<bool>{0, 1, 0, 0, 0, 1})
	{
		return{ {3,7,11} };
	}
	if (x == vector<bool> {0, 1, 0, 0, 1, 0})
	{
		return { {4,7,10} };
	}
	if (x == vector<bool> {0, 1, 0, 0, 1, 1})
	{
		return { {9,10,11}, {5,7,9} };
	}
	if (x == vector<bool> {0, 1, 0, 1, 0, 0})
	{
		return { {5,7,9} };
	}
	if (x == vector<bool> {0, 1, 0, 1, 0, 1})
	{
		return { {7,9,11} };
	}
	if (x == vector<bool> {0, 1, 0, 1, 1, 0})
	{
		return { {4,7,10},{1,5,9} };
	}
	if (x == vector<bool>{0, 1, 0, 1, 1, 1})
	{
		return { {9,10,11},{3,5,7} };
	}
	if (x == vector<bool> {0, 1, 1, 0, 0, 0})
	{
		return { {6,7,8},{4,5,6} };
	}
	if (x == vector<bool> {0, 1, 1, 0, 0, 1})
	{
		return { {5,8,11}, {3,5,7} };
	}
	if (x == vector<bool> {0, 1, 1, 0, 1, 0})
	{
		return { {6,8,10}, { 5,6,7} };
	}
	if (x == vector<bool> {0, 1, 1, 0, 1, 1})
	{
		return { {9,10,11}, { 7,8,9} };
	}
	if (x == vector<bool> {0, 1, 1, 1, 0, 0})
	{
		return { {7,8,9} };
	}
	if (x == vector<bool> {0, 1, 1, 1, 0, 1})
	{
		return { {7,9,11}, {2,5,8} };
	}
	if (x == vector<bool> {0, 1, 1, 1, 1, 0})
	{
		return { {8,9,10}, {3,5,7} };
	}
	if (x == vector<bool> {0, 1, 1, 1, 1, 1})
	{
		return { {3,7,11}, {8,9,10} };
	}
	if (x == vector<bool> {1, 0, 0, 0, 0, 1})
	{
		return { {1,6,11} };
	}
	if (x == vector<bool> {1, 0, 0, 0, 1, 0})
	{
		return { {2,6,10} };
	}
	if (x == vector<bool> {1, 0, 0, 0, 1, 1})
	{
		return { {9,10,11}, {3,6,9} };
	}
	if (x == vector<bool> {1, 0, 0, 1, 0, 0})
	{
		return { {3,6,9} };
	}
	if (x == vector<bool> { 1, 0, 0, 1, 0, 1})
	{
		return { {7,9,11}, { 5,6,7} };
	}
	if (x == vector<bool> {1, 0, 0, 1, 1, 0})
	{
		return { {8,9,10}, {4,6,8} };
	}
	if (x == vector<bool> {1, 0, 0, 1, 1, 1})
	{
		return { {9,10,11}, {4,5,6} };
	}
	if (x == vector<bool> {1, 0, 1, 0, 0, 0})
	{
		return  { {4,6,8} };
	}
	if (x == vector<bool> {1, 0, 1, 0, 0, 1})
	{
		return { {5,8,11},{4,5,6} };
	}
	if (x == vector<bool> {1, 0, 1, 0, 1, 0})
	{
		return  { {6,8,10} };
	}
	if (x == vector<bool> {1, 0, 1, 0, 1, 1})
	{
		return { {5,8,11}, {2,6,10} };
	}
	if (x == vector<bool> {1, 0, 1, 1, 0, 0})
	{
		return { {4,6,8}, { 1,5,9} };
	}
	if (x == vector<bool> {1, 0, 1, 1, 0, 1})
	{
		return{ {7,9,11}, {6,7,8} };
	}
	if (x == vector<bool> {1, 0, 1, 1, 1, 0})
	{
		return  { { 8,9,10}, {4,5,6} };
	}
	if (x == vector<bool>  { 1, 0, 1, 1, 1, 1})
	{
		return{ {9,10,11}, {4,6,8} };
	}
	if (x == vector<bool> {1, 1, 0, 0, 0, 0})
	{
		return { {5,6,7} };
	}
	if (x == vector<bool> {1, 1, 0, 0, 0, 1})
	{
		return { {3,7,11}, {4,5,6} };
	}
	if (x == vector<bool>{1, 1, 0, 0, 1, 0})
	{
		return{ {4,7,10}, { 4,5,6} };
	}
	if (x == vector<bool> {1, 1, 0, 0, 1, 1})
	{
		return{ {3,7,11},{2,6,10} };
	}
	if (x == vector<bool> {1, 1, 0, 1, 0, 0})
	{
		return { {5,7,9}, {4,5,6} };
	}
	if (x == vector<bool> {1, 1, 0, 1, 0, 1})
	{
		return { {7,9,11},{4,5,6} };
	}
	if (x == vector<bool> {1, 1, 0, 1, 1, 0})
	{
		return { {3,6,9}, { 4,7,10} };
	}
	if (x == vector<bool> {1, 1, 0, 1, 1, 1})
	{
		return { {9,10,11}, {5,6,7} };
	}
	if (x == vector<bool> {1, 1, 1, 0, 0, 0})
	{
		return{ {6,7,8} };
	}
	if (x == vector<bool> {1, 1, 1, 0, 0, 1})
	{
		return { {5,8,11}, {5,6,7} };
	}
	if (x == vector<bool> {1, 1, 1, 0, 1, 0})
	{
		return { {6,8,10},{3,5,7} };
	}
	if (x == vector<bool> {1, 1, 1, 0, 1, 1})
	{
		return { {6,8,10}, {3,7,11} };
	}
	if (x == vector<bool> {1, 1, 1, 1, 0, 0})
	{
		return { {7,8,9}, {4,5,6} };
	}
	if (x == vector<bool> {1, 1, 1, 1, 0, 1})
	{
		return { { 7,9,11}, {4,6,8} };
	}
	if (x == vector<bool> {1, 1, 1, 1, 1, 0})
	{
		return { {5,6,7}, {8,9,10} };
	}
	assert(false);
}
signed main()
{
	fastio();
	int n;
	cin >> n;
	vector<bool> a(n);
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		if (x)
			a[i] = 1;
	}
	if (n < 13)
	{
		map<vector<bool>, int> d;
		map<vector<bool>, vector<int>> p;
		map<vector<bool>, int> used;
		d[a] = 0;
		used[a] = 1;
		queue<vector<bool>> q;
		q.push(a);
		while (q.size())
		{
			vector<bool> v = q.front();
			q.pop();
			for (int lg = 1; 2 * lg < n; ++lg)
			{
				for (int i = 0; i + 2 * lg < n; ++i)
				{
					vector<bool> t = v;
					t[i] = invert(t[i]);
					t[i + lg] = invert(t[i + lg]);
					t[i + 2 * lg] = invert(t[i + 2 * lg]);
					if (!used[t])
					{
						used[t] = 1;
						d[t] = d[v] + 1;
						p[t] = { i,i + lg,i + 2 * lg };
						q.push(t);
					}
				}
			}
		}
		vector<bool> x = a;
		for (int i = 0; i < n; ++i)
		{
			x[i] = 0;
		}
		if (used[x] == 0)
		{
			cout << "NO";
			return 0;
		}
		cout << "YES" << endl;
		vector<vector<int>> ans;
		while (x != a)
		{
			ans.pbc(p[x]);
			vector<int> pp = p[x];
			for (int i = 0; i < 3; ++i)
			{
				x[pp[i]] = invert(x[pp[i]]);
			}
		}
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				cout << ans[i][j] + 1 << ' ';
			}
			cout << endl;
		}
		return 0;
	}
	int k = n - 1;
	vector<vector<int>> ans;
	while (k >= 13)
	{	
		vector<bool> help;
		for (int i = k - 11; i < k + 1; ++i)
		{
			help.pbc(a[i]);
		}
		auto xx = bfst(help);
		vector<bool> tmp = vector<bool>(a.begin() + k - 11, a.begin() + k + 1);
		if (xx.size() ==1 && xx[0].size() ==0)
		{
			k -= 6;
			continue;
		}
		for (vector<int> i : xx)
		{
			ans.pbc({ i[0] + k - 11, i[1] + k - 11 , i[2] + k - 11 });
			tmp[i[0]] = invert(tmp[i[0]]);
			tmp[i[1]] = invert(tmp[i[1]]);
			tmp[i[2]] = invert(tmp[i[2]]);
		}

		for (int i = k - 11; i < k + 1; ++i)
		{
			a[i] = tmp[i +11 -k];
		}
		k -= 6;
	}
	map<vector<bool>, int> d;
	map<vector<bool>, vector<int>> p;
	map<vector<bool>, bool> used;
	d[vector<bool> (a.begin() ,a.begin() +k + 1)] = 0;
	used[vector<bool>(a.begin(), a.begin() + k + 1)] = 1;
	queue<vector<bool>> q;
	q.push(vector<bool>(a.begin(), a.begin() + k + 1));
	while (q.size())
	{
		vector<bool> v = q.front();
		q.pop();
		for (int lg = 1; 2 * lg <= k; ++lg)
		{
			for (int i = 0; i + 2 * lg <= k; ++i)
			{
				vector<bool> t = v;
				t[i] = invert(t[i]);
				t[i + lg] = invert(t[i + lg]);
				t[i + 2 * lg] = invert(t[i + 2 * lg]);
				if (!used[t])
				{
					used[t] = 1;
					d[t] = d[v] + 1;
					p[t] = { i,i + lg,i + 2 * lg };
					q.push(t);
				}
			}
		}
	}
	vector<bool> x = vector<bool> (a.begin(), a.begin() +k + 1);
	for (int i = 0; i <= k; ++i)
	{
		x[i] = 0;
	}
	cout << "YES" << endl;
	while (x != vector<bool>(a.begin(), a.begin() +k + 1))
	{
		ans.pbc(p[x]);
		vector<int> pp = p[x];

		for (int i = 0; i < 3; ++i)
		{
			x[pp[i]] = invert(x[pp[i]]);
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << ans[i][j] + 1 << ' ';
		}
		cout << endl;
	}
	
}