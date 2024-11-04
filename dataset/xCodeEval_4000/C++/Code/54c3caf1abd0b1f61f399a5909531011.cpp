#pragma GCC optimize("unroll-loops")


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
const ld EPS = 1e-9;
const ld PI = acos(-1.0);
const int mod = 998244353;
const ld INF = 1e18;
#define int ll

int l, n;
vector<int> a;
bool check1(int r)
{
    bool ok = 1;
    int x = a[0];
    for (int i = 1; i + 1 < a.size(); ++i)
    {
        int go = a[i];
        int take = max(go, x + r);
        if (i + 2 == a.size() && take > l) return 0;
        if (i + 2 < a.size() && take > a[i + 1]) return 0;
        x = take;
    }
    return 1;
}
bool check2(int r)
{
    int x = a[0];
    for (int i = 1; i + 1 < a.size(); ++i)
    {
        x += r;
        if (x < a[i]) return 0;
        x = min(x, a[i + 1]);
    }

    return x == l;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> l >> n;
    a.resize(n);
    vin(a);
    a.insert(a.begin(), 0);
    a.pbc(l);
    int tl = 0, tr = l + 1;
    check1(2);
    while (tr - tl > 1)
    {
        int m = (tl + tr) / 2;
        if (check1(m)) tl = m;
        else tr = m;
    }int mn, mx;
    mn = tl;
    

    tl = 1, tr = l + 1;
    while (tr - tl > 1)
    {
        int m = (tl + tr) / 2;
        if (check2(m)) tr = m;
        else tl = m;
    }
    mx = tr;
    vector<int> ans(n + 300);
    vector<int> lb(n + 3);
    vector<int> rb(n + 3);
    for (int i = 1; i <= n - 1; ++i)
    {
        lb[i] = max(lb[i - 1] + mn, a[i]);
        rb[i] = min(rb[i - 1] + mx, a[i + 1]);
    }
    int x = 0;
    

    ans[n] = l;
    int mseg = inf, mxs = -inf;
    for (int i = n - 1; i >= 1; --i)
    {
        pair<int, int> fs = { lb[i], rb[i] };
        pair<int, int> ss = { ans[i + 1] - mx, ans[i + 1] - mn };
        pair<int, int> lol = { max(fs.first, ss.first), min(fs.second, ss.second) };
        if (lol.first > lol.second)
        {
            assert(0);
        }
        ans[i] = lol.first;
    }
    for (int i = 1; i <= n; ++i)
    {
        mseg = min(mseg, ans[i] - ans[i - 1]);
        mxs = max(mxs, ans[i] - ans[i - 1]);
    }
    if (mxs != mx || mseg != mn)assert(0);
    for (int i = 0; i + 1 <= n; ++i)
    {
        cout << ans[i] << ' ' << ans[i + 1] << '\n';
    }
   

    return 0;
}