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

struct cnm {
	vector<int> pr, sz;
	int ans, n;
	cnm(int n)
	{
		this->n = n;
		pr.resize(n + 1, 0);
		sz.resize(n + 1, 1);
		for (int i = 1; i <= n; i++)
			pr[i] = i;
		ans = n;
	}
	int find_set(int v)
	{
		if (pr[v] == v)
			return v;
		return pr[v] = find_set(pr[v]);
	}
	void union_set(int a, int b)
	{
		a = find_set(a);
		b = find_set(b);
		if (a == b)
			return;
		if (sz[a] < sz[b])
			swap(a, b);
		ans--;
		pr[b] = a;
		sz[a] += sz[b];
	}
	void clear()
	{
		for (int i = 1; i <= n; i++)
			pr[i] = i, sz[i] = 1;
		ans = n;
	}
};

const int maxn = 3113;
int p[maxn];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(0);
	int n;
	cin >> n;
	vector<pair<int, int>> sd;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	int g;
	cin >> g;
	cnm mg(n);
	while (sd.size() < n)
	{
		mg.clear();
		for (int i = 1; i <= n; i++)
			mg.union_set(i, p[i]);
		if (mg.ans > n - g)
		{
			int a = 1, b;
			for (int i = 1; i <= n; i++)
			{
				if (mg.find_set(i) != mg.find_set(1))
				{
					b = i;
					break;
				}
			}
			sd.push_back({ a, b });
			swap(p[a], p[b]);
		}
		else if (mg.ans == n - g)
			break;
		else
		{
			int a, b;
			for (int i = 1; i <= n; i++)
			{
				if (mg.sz[mg.find_set(i)] != 1)
				{
					a = i;
					break;
				}
			}
			for (int i = 1; i <= n; i++)
			{
				if (mg.find_set(i) == mg.find_set(a) && i != a)
				{
					b = i;
					break;
				}
			}
			sd.push_back({ a, b });
			swap(p[a], p[b]);
		}
	}
	cout << sd.size() << "\n";
	for (int i = 0; i < sd.size(); i++)
		cout << sd[i].first << " " << sd[i].second << " ";
	

}

