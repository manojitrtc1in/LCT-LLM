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
int qs = 0;
int ask(int x)
{
	cout << "? " << x << endl;
	int y;
	cin >> y;
	++qs;
	return y;
}
signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20), cout.setf(ios::fixed);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		qs = 0;
		vector<int> ans(n + 1);
		vector<int> used(n + 1);
		



		for (int i = 1; i <= n; ++i)
		{
			if (used[i]) continue;
			int len = 0;
			vector<int> cycl;
			int xx = ask(i);
			int stq = qs;

			while (!used[xx])
			{
				used[xx] = 1;
				cycl.pbc(xx);
				xx = ask(i);
			}
			if (!cycl.size()) continue;
			auto tcyc = cycl;
			int tt = (cycl.size() - (1) % cycl.size()) % cycl.size();

			rotate(cycl.begin(), cycl.begin() + tt, cycl.end());
			for (int j = 0; j < cycl.size(); ++j)
			{
				ans[cycl[j]] = tcyc[j]; 

			}
		}
		cout << "! ";
		for (int j = 1; j <= n; ++j) cout << ans[j] << ' ';
		cout << endl;
	}
	

}