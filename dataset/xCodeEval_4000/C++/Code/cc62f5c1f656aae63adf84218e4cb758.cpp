





#define _CRT_SECURE_NO_WARNINGS


#pragma comment(linker,"/STACK:256777216")



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
const ld EPS = 1e-15;
const ld PI = acos(-1.0);
int mod = 1000000007;
const ll INF = 1e18;
const int MAXN =2e5 + 228;
const int MAXA = MAXN * 2;
ll t[4 * MAXN];
vector<int> divs[MAXA];
void upd(int v, int l, int r, int ql, int qr, ll x)
{
    if (l >= qr || ql >= r) return;
    if (l >= ql && r <= qr)
    {
        t[v] += x;
        return;
    }
    upd(2 * v + 1, l, (l + r) / 2, ql, qr, x);
    upd(2 * v + 2, (l + r) / 2, r, ql, qr, x);
    t[v] = t[2 * v + 1] + t[2 * v + 2];
}
ll get(int v, int l, int r, int ql, int qr)
{
    if (l >= qr || ql >= r) return 0;
    if (l >= ql && r <= qr) return t[v];
    return get(2 * v + 1, l, (l + r) / 2, ql, qr) + get(2 * v + 2, (l + r) / 2, r, ql, qr);
}
signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(3), cout.setf(ios::fixed);
    for (int i = 1; i < MAXA; ++i) for (int j = i; j < MAXA; j += i) divs[j].pbc(i);
    vector<vector<pair<int, ll>>> kek(MAXN);
    for (int k = 1; k < MAXN; ++k)
    {
        for (int x=0;x< divs[2*k].size();++x)
        {
            int i = divs[2 * k][x];
            if (i >=k ) continue;

            int w = 0;
            for (int y = x + 1; y < divs[2 * k].size(); ++y)
            {
                int j = divs[2 * k][y];
                if (j >= k) break;
                if (i + j <= k)
                {
                    if (k % i == 0 && k % j == 0)++w;
                }
                else
                {
                    if (k % i || k % j) ++w;
                }
            }
            if(w)
            kek[i].pbc({ k, w });
            upd(0, 0, MAXN, k, k + 1, w);
        }
    }
    int t;
    cin >> t;
    vector<pair<pair<int, int>, int>> qs(t);
    for (int i = 0; i < t; ++i)
    {
        qs[i].second = i;
        cin >> qs[i].first.first >> qs[i].first.second;
    }
    sort(all(qs));
    int gol = 0;
    vector<ll> res(t);
    for (auto i : qs)
    {
        while (gol < i.first.first)
        {
            for (auto j : kek[gol])
            {
                upd(0, 0, MAXN, j.first, j.first + 1, -j.second);
            }
            ++gol;
        }
        ll len = i.first.second - i.first.first + 1;
        res[i.second] = len * (len - 1) * (len - 2) / 6 - get(0, 0, MAXN, i.first.first, i.first.second + 1);
    }
    for (int i = 0; i < t; ++i) cout << res[i] << '\n';
  

}