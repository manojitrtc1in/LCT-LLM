#pragma GCC target("sse,sse2,sse3,sse4.1,sse4.2,abm,mmx,avx,avx2,popcnt,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")


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
#include <functional>
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
const ld EPS = 1e-6;
const ld PI = acos(-1.0);
int ppc(ll x)
{
	return __builtin_popcountll(x);
	int res = 0;
	for (; x; x &= (x - 1)) ++res;
	return res;
}
vector<int> psm[61];
int ptr1[61];
int ptr2[61];
ll get(vector<ll>& fs, vector<ll>& ss, int add = 0)
{
	vector<ll> sufmin(fs.size());
	vector<ll> sufmax(fs.size());
	for (int i = fs.size() - 1; i >= 0; --i)
	{
		sufmin[i] = fs[i];
		if (i + 1 < fs.size()) sufmin[i] = min(sufmin[i], sufmin[i + 1]);
		sufmax[i] = fs[i];
		if (i + 1 < fs.size()) sufmax[i] = max(sufmax[i], sufmax[i + 1]);
	}
	vector<ll> prefmin(ss.size()), prefmax(ss.size());
	for (int i = 0; i < ss.size(); ++i)
	{
		prefmin[i] = prefmax[i] = ss[i];
		if (i > 0)
		{
			prefmin[i] = min(prefmin[i], prefmin[i - 1]);
		}
		if (i > 0)
		{
			prefmax[i] = max(prefmax[i], prefmax[i - 1]);
		}
	}
	int ptr = ss.size() - 1;
	ll res = 0;
	for (int i = 0; i < fs.size(); ++i)
	{
		ll nowmin = sufmin[i];
		ll nowmax = sufmax[i];
		if (ppc(nowmin) != ppc(nowmax)) continue;
		while (ptr >= 0 && !(prefmin[ptr] >= nowmin && prefmax[ptr] <= nowmax && (prefmax[ptr] == nowmax && prefmin[ptr] == nowmin) <= add))--ptr;
		res += ptr + 1;
	}
	for (int i = 0; i < 61; ++i) psm[i].clear();
	for (int i = 0; i < ss.size(); ++i) psm[ppc(prefmax[i])].pbc(i);
	int tptr = ss.size() - 1;
	int stit = ss.size();
	memset(ptr1, 0, sizeof ptr1);
	memset(ptr2, 0, sizeof ptr2);
	for (int i = 0; i < 61; ++i) ptr1[i] = ptr2[i] = psm[i].size();
	int sum = 0;
	for (int i = 0; i < 61; ++i) sum += ptr1[i] + ptr2[i];
	assert(sum <= ss.size() * 2);
	for (int i = 0; i < fs.size(); ++i)
	{
		ll nowmin = sufmin[i];
		ll nowmax = sufmax[i];
		while (tptr >= 0 && !(prefmin[tptr] >= nowmin + 1))--tptr;
		while (stit - 1 >= 0 && prefmax[stit - 1] > nowmax)
			--stit;
		int nw = ppc(nowmin);
		while (ptr1[nw] >= 1 && psm[nw][ptr1[nw] - 1] > tptr)ptr1[nw]--;
		while (ptr2[nw] >= 1 && psm[nw][ptr2[nw] - 1] >= stit) ptr2[nw]--;
		if (tptr >= stit)
			res += ptr1[nw] - ptr2[nw];
	}
	return res;
}
ll solve(vector<ll> a)
{
	if (a.size() == 1) return 1;
	vector<ll> fs;
	vector<ll> ss;
	int x = a.size() / 2;
	for (int i = 0; i < x; ++i) fs.pbc(a[i]);
	for (int i = x; i < a.size(); ++i) ss.pbc(a[i]);
	ll res = solve(fs) + solve(ss);
	res += get(fs, ss, 1);
	reverse(all(ss));
	reverse(all(fs));
	res += get(ss, fs, 0);
	return res;
}
ll stupid(vector<ll> a)
{
	ll res = 0;
	for (int l = 0; l < a.size(); ++l)
	{
		ll mn = a[l], mx = a[l];
		for (int r = l; r < a.size(); ++r)
		{
			mn = min(mn, a[r]); mx = max(mx, a[r]);
			res += (ppc(mn) == ppc(mx));
		}
	}
	return res;
}
signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20), cout.setf(ios::fixed);
	
	int n;
	cin >> n;
	vector<ll> a(n);
	vin(a);
	cout << solve(a);
	

}