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
const ld EPS = 1e-9;
const ld PI = acos(-1.0);
const int mod = 1000000007;
int n, m;
const int MAXN = 2e5 + 228;
set<int> g[MAXN];
signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20), cout.setf(ios::fixed);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		g[a].insert(b);
		g[b].insert(a);
	}
	while (1)
	{
		if (getTime() > 0.95)break;
		vector<int> fs;
		while (fs.size() < 5)
		{
			int y = rnd() % n + 1;
			if (count(all(fs), y)) continue;
			fs.pbc(y);
		}
		int r = 0;
		for (int i = 0; i < fs.size(); ++i)
		{
			for (int j = i + 1; j < fs.size(); ++j) r += g[fs[i]].count(fs[j]);
		}
		if (r == 0 || r == 10)
		{
			for (int j : fs) cout << j << ' ';
	

			return 0;
		}
	}
	cout << -1;


}