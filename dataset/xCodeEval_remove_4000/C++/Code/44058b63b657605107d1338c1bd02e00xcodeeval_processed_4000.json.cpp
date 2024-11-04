














































using namespace std;



mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1e5 + 113;
vector<int> gr[maxn];
int tin[maxn], tout[maxn];
int lvl[maxn];
int pr[maxn][22];
int gh = 0;

void dfs(int v, int p)
{
	tin[v] = gh++;
	pr[v][0] = p;
	for (int i = 1; i < 20 && pr[v][i - 1] != 0; i++)
		pr[v][i] = pr[pr[v][i - 1]][i - 1];
	for (int to : gr[v])
	{
		if (to != p)
		{
			lvl[to] = lvl[v] + 1;
			dfs(to, v);
		}
	}
	tout[v] = gh++;
}

int ppr(int a, int b)
{
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b)
{
	if (ppr(a, b))
		return a;
	if (ppr(b, a))
		return b;
	for (int t = 20; t >= 0; t--)
		if (pr[b][t] != 0 && !ppr(pr[b][t], a))
			b = pr[b][t];
	return pr[b][0];
}

int dist(int a, int b)
{
	if (a == b)
		return 1;
	int su = 1;
	for (int t = 20; t >= 0; t--)
	{
		if (pr[a][t] != 0 && !ppr(pr[a][t], b))
			a = pr[a][t], su += (1 << t);
	}
	return su + 1;
}

int add(int f, set<pair<int, int>> &fg)
{
	if (fg.size() == 0)
	{
		fg.insert({ tin[f], f });
		return 1;
	}
	int glo = lca((*fg.begin()).second, (*--fg.end()).second);
	pair<int, int> h = { tin[f], f };
	auto it1 = fg.lower_bound(h);
	int v = -1;
	if (it1 != fg.end())
		v = lca((*it1).second, f);
	if (it1 != fg.begin())
	{
		it1--;
		int v2 = lca((*it1).second, f);
		if (v == -1 || lvl[v] < lvl[v2])
			v = v2;
	}
	fg.insert(h);
	if (lvl[v] >= lvl[glo])
		return dist(f, v) - 1;
	else
		return dist(f, v) + dist(glo, v) - 2;
}

int del(int f, set<pair<int, int>> &fg)
{
	pair<int, int> h = { tin[f], f };
	fg.erase(h);
	if (fg.size() == 0)
	{
		return 1;
	}
	int glo = lca((*fg.begin()).second, (*--fg.end()).second);
	auto it1 = fg.lower_bound(h);
	int v = -1;
	if (it1 != fg.end())
		v = lca((*it1).second, f);
	if (it1 != fg.begin())
	{
		it1--;
		int v2 = lca((*it1).second, f);
		if (v == -1 || lvl[v] < lvl[v2])
			v = v2;
	}
	if (lvl[v] >= lvl[glo])
		return dist(f, v) - 1;
	else
		return dist(f, v) + dist(glo, v) - 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(0);
	int k, n;
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	dfs(1, 0);
	set<pair<int, int>> fg;
	long long sum = 0;
	int ans = 0;
	for (int l = 1, r = 1; l <= n; l++)
	{
		if (l == r)
			sum += add(l, fg);
		while (r <= n)
		{
			int t = add(r, fg);
			if (t + sum > k)
			{
				del(r, fg);
				break;
			}
			else
				sum += t;
			r++;
		}
		ans = max(ans, r - l);
		sum -= del(l, fg);
	}
	cout << ans;
	

}