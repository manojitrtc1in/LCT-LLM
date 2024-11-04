#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")


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


const int inf = 2e9 + 228;
const ld EPS = 1e-25;
const ld PI = acos(-1.0);
int mod = 998244353;


int n, m;
ld ask(vector<pair<ld, ld>> a)
{
    cout << "? " << a.size() << endl;
    for (auto i : a)
    {
        cout << i.first << ' ' << i.second << endl;
    }
    ld res;
    cin >> res;
    return res;
}
signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(10), cout.setf(ios::fixed);
    int n, m;
    cin >> n >> m;
    vector<pair<ld, ld>> tox;
    tox.pbc({ 0,0 });
    for (int y = 0; y < m; ++y)
    {
        tox.pbc({ n,y });
        tox.pbc({ 1, y + 1 });
    }
    tox.pbc({ 0,m });
    ld ff = ask(tox);
    vector<pair<ld,ld>> todetx = { {0,0},{n,0},{1,1},{0,1} };
    ld ansx = -1;
    {
        ld l = 0, r = n - 1;
        for (int j = 0; j < 70; ++j)
        {
            ld mid = (l + r) / 2;
            ld bx = mid + 1;
            ld sq = 0;
            ld nx = mid;
            if (mid <= 1)
            {
                sq += 1 - mid;
                nx = 1;
            }
            ld fy = (n - nx) / (n - 1);
            ld sy = (n - bx) / (n - 1);
            sq += (fy + sy)*(bx-nx) / 2;
            if (sq >= ff) l = mid;
            else r = mid;
        }
        ansx = r;
    }
    tox.clear();
    tox.pbc({ 0,0 });
    for(int x=0;x<n;++x)
    {
        tox.pbc({ x,m });
        tox.pbc({ x + 1, 1 });
    }
    tox.pbc({ n,0 });
    ld ss = ask(tox);
    ld ansy = -1;
    {
        ld l = 0, r = m - 1;
        for (int j = 0; j < 70; ++j)
        {
            ld mid = (l + r) / 2;
            ld bx = mid + 1;
            ld sq = 0;
            ld nx = mid;
            if (mid <= 1)
            {
                sq += 1 - mid;
                nx = 1;
            }
            ld fy = (m - nx) / (m - 1);
            ld sy = (m - bx) / (m - 1);
            sq += (fy + sy)*(bx-nx) / 2;
            if (sq >= ss) l = mid;
            else r = mid;
        }
        ansy = r;
    }
    cout << "! " << ansx << ' ' << ansy << endl;
   

}

