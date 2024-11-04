



















































































































#pragma comment(linker, "/STACK:150777216")
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



mt19937 rnd(123);
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
const int MAXN = 6e3 + 228;
int cnt[MAXN][4][4][4];
int gcd(int a, int b)
{
	while (b)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}
int stupid(vector<pair<int, int>> a)
{
	int ans = 0;
	for (int i = 0; i < a.size(); ++i)
	{
		for (int j = i + 1; j < a.size(); ++j)
		{
			for (int k = j + 1; k < a.size(); ++k)
			{
				int x1 = a[i].first, y1 = a[i].second, x2 = a[j].first, y2 = a[j].second, x3 = a[k].first, y3 = a[k].second;
				int sq = abs(x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1);
				if (sq % 2) continue;
				int al = gcd(abs(x1 - x2), abs(y1 - y2)) + gcd(abs(x2 - x3), abs(y2 - y3)) + gcd(abs(x1 - x3), abs(y1 - y3));
				sq /= 2;
				if (al % 2)continue;
				int inter = sq - al / 2 + 1;
				if (inter % 2)ans++;
			}
		}
	}
	return ans;
}
int gg[MAXN][MAXN];
ll smart(vector<pair<int, int>> a)
{
	int n = a.size();
	memset(cnt, 0, sizeof cnt);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == j) continue;
			pair<int, int> x = { a[j].first - a[i].first, a[j].second - a[i].second };
			int bb;
			if (!gg[j][i])
				bb = abs(gcd(x.first, x.second));
			else bb = gg[j][i];
			gg[i][j] = bb;
			cnt[i][((x.first%4)+4)%4][((x.second%4) + 4)%4][bb & 3]++;
		}
	}
	ll alleven = 0;
	ll oneeven = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int x1 = 0; x1 < 4; ++x1)
		{
			for (int y1 = 0; y1 < 4; ++y1)
			{
				for (int b1 = 0; b1 < 4; ++b1)
				{
					if (!cnt[i][x1][y1][b1]) continue;
					for (int b2 = 0; b2 < 4; ++b2)
					{
						if ((b1 & 1) != (b2 & 1)) continue;

						for (int x2 = 0; x2 < 4; ++x2)
						{
							for (int y2 = 0; y2 < 4; ++y2)
							{
								if (!cnt[i][x2][y2][b2]) continue;
								if (x2 < x1) continue;
								if (x2 == x1 && y2 < y1) continue;
								if (x2 == x1 && y2 == y1 && b2 < b1) continue;
								int b3 = 0;
								if (x1 == x2 && y1 == y2) b3 = 0;
								else if (((x1 & 1) == (x2 & 1)) && ((y1 & 1) == (y2 & 1))) b3 = 2;
								else continue;
								int bb = ((b1 + b2 + b3) & 3);
								int x3 = (0), y3 = 0;
								int sq = (abs(x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1) & 3);
								if (sq & 1) continue;
								if (((sq >> 1) & 1) == ((bb >> 1) & 1))
								{
									if ((b1 & 1))
									{
										if (x1 == x2 && y1 == y2 && b1 == b2) oneeven += cnt[i][x1][y1][b1] * (cnt[i][x1][y1][b1] - 1) / 2;
										else
											oneeven += cnt[i][x1][y1][b1] * cnt[i][x2][y2][b2];
									}
									else
									{
										if (x1 == x2 && y1 == y2 && b1 == b2) alleven += cnt[i][x1][y1][b1] * (cnt[i][x1][y1][b1] - 1) / 2;
										else
											alleven += cnt[i][x1][y1][b1] * cnt[i][x2][y2][b2];
									}
								}

							}
						}
					}
				}
			}
		}
		

	}
	return alleven / 3 + oneeven;
}
bool ok(vector<pair<int, int>> a)
{
	for (int i = 0; i < a.size(); ++i) for (int j = i + 1; j < a.size(); ++j) if (a[i] == a[j]) return 0;
	for (int i = 0; i < a.size(); ++i)
	{
		for (int j = i + 1; j < a.size(); ++j)
		{
			for (int k = j + 1; k < a.size(); ++k)
			{
				if (a[i].first == a[j].first && a[j].first == a[k].first) continue;
				if (a[j].second == a[i].second && a[j].second == a[k].second) continue;
				int dx1 = a[j].first - a[i].first, dy1 = a[j].second - a[i].second, dx2 = a[j].first - a[k].first, dy2 = a[j].second - a[k].second;
				if (dx1 * dy2 == dx2 * dy1) return 0;
			}
		}
	}
	return 1;
}
signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20), cout.setf(ios::fixed);

	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i].first >> a[i].second;
	}
	cout << smart(a);
	

}