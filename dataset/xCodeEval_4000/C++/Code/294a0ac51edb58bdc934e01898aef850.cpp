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
const ld EPS = 1e-9;
const ld PI = acos(-1.0);
const int mod = 1000000007;
#define int ll
const int MAXN = 3e5 + 228;
int cnt[MAXN];
const int lgg = 20;
vector<vector<int>> build(vector<int> a)
{
	vector<vector<int>> spt(a.size(), vector<int>(lgg));
	for (int i = 0; i < a.size(); ++i)
	{
		spt[i][0] = a[i];
	}
	for (int h = 1; (1 << (h - 1)) < a.size(); ++h)
	{
		for (int i = 0; i +(1<<(h-1))< a.size(); ++i)
		{
			spt[i][h] = min(spt[i][h - 1], spt[i + (1 << (h - 1))][h - 1]);
		}
	}
	return spt;
}
int get(vector<vector<int>>& spt, int l, int r)
{
	int xx = cnt[r - l];
	return min(spt[l][xx], spt[r - (1 << xx)][xx]);
}
signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20), cout.setf(ios::fixed);
	int t;
	cin >> t;
	for (int i = 2; i < MAXN; ++i) cnt[i] = cnt[i >> 1] + 1;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		vin(a);
		int ans = 0;
		vector<int> pref(n);
		for (int i = 0; i < n; ++i)
		{
			pref[i] = a[i];
			if (i) pref[i] -= pref[i - 1];
		}
		vector<int> o1(n);
		vector<int> o0(n);
		for (int i = 0; i < n; ++i)
		{
			if (i % 2 == 0) o1[i] = 1e18, o0[i] = a[i] - (i==0 ? 0 : pref[i-1]);
			else o0[i] = 1e18, o1[i] = a[i] - pref[i-1];
		}
		auto spt1 = build(o1), spt0 = build(o0);
		map<int, vector<int>> id0, id1;
		for (int i = 0; i < n; ++i)
		{
			int val = a[i] - (i == 0 ? 0 : pref[i - 1]);
			if (i % 2 == 0)
			{
				id0[val].pbc(i);
			}
			else
			{
				id1[val].pbc(i);
			}
		}
		for (int i = 0; i < n; ++i)
		{
			int l = i, r = n;
			int pos = (i == 0 ? 0 : pref[i - 1]);
			int neg = -pos;
			while (r - l > 1)
			{
				int m = (l + r) / 2;
				auto xx = get(spt0, i, m+1);
				if (i % 2 == 0)
				{
					if (xx >= neg) l = m;
					else r = m;
				}
				else
				{
					if (xx >= pos) l = m;
					else r = m;
				}
			}
			int tl = l;
			l = i, r = n;
			while (r - l > 1)
			{
				int m = (l + r) / 2;
				auto xx = get(spt1, i, m + 1);
				if (i % 2 == 1)
				{
					if (xx >= neg) l = m;
					else r = m;
				}
				else
				{
					if (xx >= pos) l = m;
					else r = m;
				}
			}
			int ttl = l;
			int resbound = min(ttl, tl);
			if (i % 2 == 0)
			{
				ans += max(0ll,(int)(upper_bound(all(id0[neg]), resbound) - lower_bound(all(id0[neg]), i + 1)));
				ans += max(0ll, (int)(upper_bound(all(id1[pos]), resbound) - lower_bound(all(id1[pos]), i + 1)));
			}
			else
			{

				ans += max(0ll, (int)(upper_bound(all(id0[pos]), resbound) - lower_bound(all(id0[pos]), i + 1)));
				ans += max(0ll, (int)(upper_bound(all(id1[neg]), resbound) - lower_bound(all(id1[neg]), i + 1)));
			}
		}
		cout << ans +count(all(a),0)<< '\n';
	}
	

}