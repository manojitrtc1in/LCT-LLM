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
const int mod = 1000000007;
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
        vector<int> a(n);
        vin(a);
        if (count(all(a), 1) % 2)
        {
            cout << "NO\n";
            continue;
        }
        if (n % 2)
        {
            cout << "YES\n";
            vector<int> ans;
            for (int i = 0; i + 2 < n; i+=2)
            {
                int x = a[i] ^ a[i + 1] ^ a[i + 2];
                a[i] = a[i + 1] = a[i + 2] = x;
                ans.pbc(i);
            }
            for (int i = n - 3; i >= 0; i-=2)
            {
                int x = a[i] ^ a[i + 1] ^ a[i + 2];
                a[i] = a[i + 1] = a[i + 2] = x;
                ans.pbc(i);
            }
            cout << ans.size() << '\n';
            for (auto i : ans)cout << i + 1 << ' ';
            cout << '\n';
    

     

        }
        else
        {
            int cc = 0;
            vector<int> ans;
            for (int i = 0; i < n; ++i)
            {
                cc += a[i];
                if (i % 2 == 0 && cc % 2 == 0)
                {
                    int tn = i + 1;
                    for (int j = 0; j + 2 < tn; j += 2)
                    {
                        ans.pbc(j);
                    }
                    for (int j = tn - 3; j >= 0; j -= 2) ans.pbc(j);
                    for (int j = i + 1; j + 2 < n; j += 2) ans.pbc(j);
                    for (int j = n - 3; j >= i + 1; j -= 2) ans.pbc(j);
                    break;
                }
            }
            if (ans.size())
            {
                cout << "YES\n";
                cout << ans.size() << '\n';
                for (int i : ans) cout << i + 1 << ' ';
                cout << '\n';
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
    

}