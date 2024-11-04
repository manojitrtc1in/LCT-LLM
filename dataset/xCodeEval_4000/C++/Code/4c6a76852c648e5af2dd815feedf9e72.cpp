



#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
const ld EPS = 1e-14;
const ld PI = acos(-1.0);
const int MAXN = 2e5 + 1;
const int bl = 179;
int go[bl * 2][bl*2];
int f[MAXN];
int poggers[MAXN];
int memo[MAXN][2 * bl];
pair<int, int> a[MAXN];
int addtrain[MAXN];
signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(4), cout.setf(ios::fixed);
	for (int i = 0; i < 2 * bl; ++i)
	{
		for (int j = 1; j < 2 * bl; ++j) memo[i][j] = i % j;
	}
	for (int i = 2 * bl; i < MAXN; ++i) for (int j = 1; j < 2 * bl; ++j) memo[i][j] = memo[i - j][j];
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i].first >> a[i].second;
	}
	for (int i = 0; i < m; ++i)
	{
		int op, x;
		cin >> op >> x;
		x--;
		int add = (op == 1 ? 1 : -1);
		if (a[x].first + a[x].second >= bl * 2)
		{
			if (add == 1)
			{
				addtrain[x] = i;
			}
			for (int go = addtrain[x];go + a[x].first< MAXN; go += a[x].first + a[x].second)
			{
				int l = go + a[x].first;
				int r = go + a[x].first + a[x].second;
				if (r < i) continue;
				l = max(l, i);
				poggers[l] += add;
				if (r < MAXN)poggers[r] -= add;
			}
		}
		else
		{
			if (add == 1)
			{
				addtrain[x] = i;
			}
			int s = a[x].first + a[x].second;
			int gg = ( addtrain[x] + a[x].first) % s;
			for (int j = 0; j < a[x].second; ++j)
			{
				go[a[x].first + a[x].second][gg] += add;
				++gg;
				if (gg == s) gg = 0;
			}

		}
		int res = 0;
		for (int j = 2; j < 2 * bl; ++j)
		{
			int gg = memo[i][j];
			res += go[j][gg];
		}
		if (i) poggers[i] += poggers[i - 1];
		cout <<poggers[i] + res << '\n';
	}
	

}