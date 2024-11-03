#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native") 
#pragma GCC optimize("unroll-loops") 

























#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<math.h>
#include<algorithm>
#include<time.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<deque>
#include<fstream>
#include<unordered_map>
#include<bitset>
#include<cstdio>
#include<random>
#include<chrono>

using namespace std;



mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 2e5 + 113;
vector<pair<int, int>> gr[maxn];
int h[maxn];
int pr[maxn][20];
int zn[maxn][20];
int yd[maxn][20];

struct cnm {
	vector<int> sz;
	vector<int> pr;
	cnm(int n)
	{
		sz.resize(n + 113, 1);
		pr.resize(n + 113);
		for (int i = 1; i <= n; i++)
			pr[i] = i;
	}
	int find_set(int v)
	{
		if (pr[v] == v)
			return v;
		return pr[v] = find_set(pr[v]);
	}
	bool union_set(int a, int b)
	{
		a = find_set(a);
		b = find_set(b);
		if (a == b)
			return false;
		if (sz[a] < sz[b])
			swap(a, b);
		sz[a] += sz[b];
		pr[a] = b;
		return true;
	}
};


void dfs(int v, int p)
{
	if (p != -1)
		pr[v][0] = p;
	for (int i = 1; i <= 19; i++)
	{
		pr[v][i] = pr[pr[v][i - 1]][i - 1];
		zn[v][i] = max(zn[v][i - 1], zn[pr[v][i - 1]][i - 1]);
	}
	for (pair<int, int> to : gr[v])
	{
		if (to.first != p)
		{
			h[to.first] = h[v] + 1;
			zn[to.first][0] = to.second;
			dfs(to.first, v);
		}
	}
}

int lca(int a, int b)
{
	int d = 0;
	if (h[a] > h[b])
		swap(a, b);
	for (int i = 19; i >= 0; i--)
	{
		if (h[b] - (1 << i) >= h[a])
		{
			d = max(zn[b][i], d);
			b = pr[b][i];
		}
	}
	if (b == a)
		return d;
	for (int i = 19; i >= 0; i--)
	{
		if ((1 << i) <= h[a] && pr[a][i] != pr[b][i])
		{
			d = max(zn[a][i], d);
			d = max(zn[b][i], d);
			a = pr[a][i], b = pr[b][i];
		}
	}
	d = max(zn[a][0], d);
	d = max(zn[b][0], d);
	a = pr[a][0];
	return d;
}

void lca2(int a, int b, int c)
{
	if (h[a] > h[b])
		swap(a, b);
	for (int i = 19; i >= 0; i--)
	{
		if (h[b] - (1 << i) >= h[a])
		{
			yd[b][i] = min(yd[b][i], c);
			b = pr[b][i];
		}
	}
	if (b == a)
		return;
	for (int i = 19; i >= 0; i--)
	{
		if ((1 << i) <= h[a] && pr[a][i] != pr[b][i])
		{
			yd[a][i] = min(yd[a][i], c);
			yd[b][i] = min(yd[b][i], c);
			a = pr[a][i], b = pr[b][i];
		}
	}
	yd[a][0] = min(yd[a][0], c);
	yd[b][0] = min(yd[b][0], c);
	return;
}

map<pair<int, int>, int> num;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(0);
	int n, m;
	cin >> n >> m;
	vector < pair<int, pair<int, int>>> sp;
	for (int i = 0; i < m; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		

		

		sp.push_back({ c, {u, v} });
		num[{u, v}] = num[{v, u}] = i + 1;
	}
	vector<int> ans(m + 1);
	sort(sp.begin(), sp.end());
	long long su = 0;
	vector<pair<int, pair<int, int>>> f1, f2;
	cnm ms(n);
	for (int i = 0; i < sp.size(); i++)
	{
		int a = sp[i].second.first, b = sp[i].second.second, c = sp[i].first;
		if (ms.union_set(a, b))
			f1.push_back({ c, { a, b } });
		else
			f2.push_back({ c, { a, b } });
	}
	for (int i = 0; i < f1.size(); i++)
	{
		int c = f1[i].first, a = f1[i].second.first, b = f1[i].second.second;
		gr[a].push_back({ b, c });
		gr[b].push_back({ a, c });
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
		for (int k = 0; k <= 19; k++)
			yd[i][k] = 1e9 + 113;
	for (int i = 0; i < f2.size(); i++)
	{
		int c = f2[i].first, a = f2[i].second.first, b = f2[i].second.second;
		ans[num[{a, b}]] = lca(a, b) - 1;
		lca2(a, b, c);
	}
	for(int k = 19; k > 0; k--)
		for (int i = 1; i <= n; i++)
		{
			yd[i][k - 1] = min(yd[i][k - 1], yd[i][k]);
			if (pr[i][k - 1] != 0)
				yd[pr[i][k - 1]][k - 1] = min(yd[pr[i][k - 1]][k - 1], yd[i][k]);
		}
	for (int i = 1; i <= n; i++)
	{
		if (pr[i][0] != 0)
		{
			int b = pr[i][0];
			ans[num[{i, b}]] = (yd[i][0] != 1e9 + 113) ? (yd[i][0] - 1) : -1;
		}
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << " ";
	

}