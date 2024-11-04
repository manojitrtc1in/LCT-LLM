





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
const int MAXN = 2e5 + 229;
ll t[2 * MAXN];
int tn;
void build(vector<ll>& a)
{
    for (int i = 0; i < a.size(); ++i) t[i + tn] = a[i];
    for (int i = a.size() - 1; i >= 1; --i)
    {
        t[i] = max(t[2 * i], t[2 * i + 1]);
    }
}
inline void upd(int p, ll x)
{
    for (t[p += tn] = x; p > 1; p /= 2) t[p >> 1] = max(t[p], t[p ^ 1]);
}
signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(3), cout.setf(ios::fixed);
    int ta;
    cin >> ta;
    while (ta--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        vin(a);
        vector<pair<int, int>> qs(q);
        for (int i = 0; i < q; ++i) cin >> qs[i].first >> qs[i].second;
        vector<ll> res(q + 1);
        auto ta = a;
        for (int i = 1; i < n; ++i)
        {
            if (n % i) continue;
            vector<ll> w(i);
            a = ta;
            for (int j = 0; j < i; ++j)
            {
                for (int x = j; x < n; x += i)
                {
                    w[j] += a[x];
                }
            }
            tn = i;
            build(w);
            res[0] = max(res[0], 1ll * i * t[1]);

            for (int j = 0; j < q; ++j)
            {
                int go = (qs[j].first - 1) % i;
                upd(go, w[go] - a[qs[j].first - 1] + qs[j].second);
                w[go] += qs[j].second - a[qs[j].first - 1];
                a[qs[j].first - 1] = qs[j].second;
                
                res[j + 1] = max(res[j + 1], 1ll * t[1] * i);
            }
        }
        for (ll i : res) cout << i << '\n';
    }


}