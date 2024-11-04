#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,abm,mmx,popcnt")
#define _CRT_SECURE_NO_WARNINGS







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
pair<int, int> operator-(pair<int, int> a, pair<int, int> b)
{
    return { a.first - b.first, a.second - b.second };
}
pair<int, int> operator+(pair<int, int> a, pair<int, int> b)
{
    return { a.first + b.first, a.second + b.second };
}


const int inf = 1e9 + 228;
using namespace chrono;
const ld EPS = 1e-25;
const ld PI = acos(-1.0);
const int mod = 998244353;
const int MAXN = 5e5 + 228;
int lst[MAXN];
int fst[MAXN];
int cnt[MAXN];
signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int n;
    cin >> n;
    vector<int> a(n);
    vin(a);
    fill(fst, fst + MAXN, -1);
    for (int i = 0; i < n; ++i)
    {
        lst[a[i]] = i;
        if (fst[a[i]] == -1) fst[a[i]] = i;
    }
    vector<int> dp(n + 1, 0);   
    for (int i = n - 1; i >= 0; --i)
    {
        dp[i] = max(dp[i], dp[i + 1]);
        ++cnt[a[i]];
        if (i == fst[a[i]])
        {
            dp[i] = max(dp[i], cnt[a[i]] + dp[lst[a[i]] + 1]);
        }
        else
        {
            dp[i] = max(dp[i], cnt[a[i]]);
        }
    }
    cout << n - dp[0];
 

}