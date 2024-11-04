

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iomanip>
#include <fstream>
#include <string>
#include <set>
#include <deque>
#include <queue>
#include <map>
#include <bitset>
#include <random>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;


#define endl "\n"
#define sqrt sqrtl



const ll inf = (ll)1e18 + 7;
ld eps = 1e-6;
ld Pi = 3.14159265358979323846;

signed main() {
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    

    while (t--) {
        ll n, i, j, ans = inf, sup, x, y, z, l, r, m;
        cin >> n;
        vector <ll> a(n);
        vector <pair <ll, ll> > b(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
            b[i].first = a[i];
            b[i].second = i;
        }
        sort(b.begin(), b.end());
        ans = (b[0].first + 1) / 2 + (b[1].first + 1) / 2;
        x = a[0];
        y = a[1];
        l = -1, r = 1e12;
        while (r - l > 1) {
            m = (l + r) / 2;
            if (x - 2 * m <= max((y - m), (ll)0) / 2) {
                r = m;
            }
            else {
                l = m;
            }
        }
        m = r;
        ans = min(ans, m + (max((ll)0, (y - m)) + 1) / 2);

        for (i = 1; i < n - 1; i++) {
            if (i != b[0].second) {
                ans = min(ans, (a[i] + 1) / 2 + (b[0].first + 1) / 2);
            }
            else {
                ans = min(ans, (a[i] + 1) / 2 + (b[1].first + 1) / 2);
            }
            x = a[i];
            y = min(a[i - 1], a[i + 1]);
            z = max(a[i - 1], a[i + 1]);
            sup = (z - y) / 2;
            ans = min(ans, sup + max(y, (z - sup * 2)));
            ans = min(ans, z);
            ans = min(ans, (x + 1) / 2 + (max((ll)0, y - (x + 1) / 2) + 1) / 2);
            l = -1, r = 1e12;
            while (r - l > 1) {
                m = (l + r) / 2;
                if (x - 2 * m <= max((y - m), (ll)0) / 2) {
                    r = m;
                }
                else {
                    l = m;
                }
            }
            m = r;
            ans = min(ans, m + (max((ll)0, (y - m)) + 1) / 2);
        }
        cout << ans << endl;
    }
}


 