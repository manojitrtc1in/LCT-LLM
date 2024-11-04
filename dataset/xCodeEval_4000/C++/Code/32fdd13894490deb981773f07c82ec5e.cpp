#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,abm,mmx,avx,avx2,popcnt,tune=native")



#include <set>
#include <map>
#include <deque>
#include <string>
#include <cstdint>
#include <cmath>
#include <queue>
#include <cassert>
#include <random>
#include <bitset>
#include <iomanip>
#include <cstring>
#include <numeric>
#include <time.h>

#include <ctime>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <complex>
#include <chrono>
#include <unordered_set>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()
#define pbc push_back
#define pob pop_back()
#define vin(a) for (auto& i : a) cin >> i
#define sp system("pause")
#define mp make_pair



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
ld asdasdcl = 0;
double getTime() { return (clock() - asdasdcl) / (double)CLOCKS_PER_SEC; }

const int inf = 1e9 + 228;
const ld EPS = 0;
const ld PI = acos(-1.0);
const int MAXN = 2e5 + 228;
int p[MAXN];
int rnk[MAXN];
int n, m;
void make(int v)
{
	p[v] = v; rnk[v] = 0;
}
int fin(int v)
{
	return (v == p[v] ? v : p[v] = fin(p[v]));
}
void unite(int a, int b)
{
	a = fin(a), b = fin(b);
	if (a == b) return;
	if (rnk[a] < rnk[b]) swap(a, b);
	rnk[a] += rnk[a] == rnk[b];
	p[b] = a;
}
vector<pair<pair<int, int>, int>> e;
int ppc(int x)
{
	int res = 0;
	for (; x; x &= (x - 1))++res;
	return res;
}
vector<int> g[MAXN];
int color[MAXN];
int comp[MAXN];
int com;
bool bb = 0;
void fuck(int v, int cl)
{
	comp[v] = com, color[v] = cl;
	for (int i : g[v])
	{
		if (!comp[i])
		{
			fuck(i, 3 - cl);
		}
		else
		{
			if (color[v] == color[i])
			{
				bb = 1;

			}
		}
	}
}
signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20), cout.setf(ios::fixed);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		e.resize(n - 1);
		for (int i = 1; i <= n; ++i)
		{
			make(i);
		}
		for (int i = 1; i <= n; ++i) g[i].clear();
		fill(color, color + n + 1, 0); bb = 0;
		fill(comp, comp + n + 1, 0);
		for (int i = 0; i < n - 1; ++i)
		{
			cin >> e[i].first.first >> e[i].first.second >> e[i].second;
			if (e[i].second >= 0 && ppc(e[i].second) %2== 0)
			{
				unite(e[i].first.first, e[i].first.second);
			}
		}
		vector<pair<pair<int, int>, int>> q;
		q.resize(m);
		for (int i = 0; i < m; ++i)
		{
			cin >> q[i].first.first >> q[i].first.second >> q[i].second;
			if (q[i].second == 0)
			{
				unite(q[i].first.first, q[i].first.second);
			}
		}
		for (int i = 0; i < n - 1; ++i)
		{
			if (e[i].second >=0 && ppc(e[i].second) % 2 == 1)
			{
				
				g[fin(e[i].first.first)].pbc(fin(e[i].first.second));
				g[fin(e[i].first.second)].pbc(fin(e[i].first.first));
			}
		}
		for (int i = 0; i < m; ++i)
		{
			if (q[i].second)
			{
				g[fin(q[i].first.first)].pbc(fin(q[i].first.second));
				g[fin(q[i].first.second)].pbc(fin(q[i].first.first));
			}
		}
		com = 1;
		for (int i = 1; i <= n; ++i)
		{
			if (!comp[i])
			{
				++com;
				fuck(i, 1);
			}
		}
		if (bb)
		{
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		for (int i = 0; i < e.size(); ++i)
		{
			if (e[i].second == -1)
			{
				if (color[fin(e[i].first.first)] == color[fin(e[i].first.second)])
				{
					cout << e[i].first.first << ' ' << e[i].first.second << ' ' << 0 << '\n';
				}
				else
				{
					cout << e[i].first.first << ' ' << e[i].first.second << ' ' << 1 << '\n';

				}
			}
			else
			{
				cout << e[i].first.first << ' ' << e[i].first.second << ' ' << e[i].second<<'\n';
			}
		}
	}
	

}