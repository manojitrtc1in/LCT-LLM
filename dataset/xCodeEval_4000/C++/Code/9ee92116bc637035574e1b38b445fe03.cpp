

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define int long long
#define f(a) for(int i = 0; i<a; ++i)
#define deb(a) cerr<<a<<endl;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;
typedef vector<str> vestr;
typedef vector<int> vei;
typedef vector<vector<int>> veve;


void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vei a(k);
    f(k) cin >> a[i];
    int ct = 0, ct2 = 0, ct3 = 0, ct4 = 0;
    f(k) {
        if ((a[i] / n) > 2 && (a[i] / n) % 2 == 1) {
            ct4++;
        }
        else if (a[i] / n > 2) {
            ct3++;
        }
        ct += (a[i] / n) / 2 * 2;
    }
    if (m % 2 == 1) {
        if (ct4 + ct3 > 0) {
            if (ct4 % 2 == 0) {
                if (ct + ct4 > m) {
                    cout << "Yes\n";
                    return;
                }
            }
            else {
                if (ct + ct4 >= m) {
                    cout << "Yes\n";
                    return;
                }
            }
        }
    }
    else {
        if (ct + ct4 >= m) {
            cout << "Yes\n";
            return;
        }
    }
    swap(m, n);
    ct = 0;ct2 = 0;ct3 = 0;ct4 = 0;
    f(k) {
        if ((a[i] / n) > 2 && (a[i] / n) % 2 == 1) {
            ct4++;
        }
        else if (a[i] / n > 2) {
            ct3++;
        }
        ct += (a[i] / n) / 2 * 2;
    }
    if (m % 2 == 1) {
        if (ct4 + ct3 > 0) {
            if (ct4 % 2 == 0) {
                if (ct + ct4 > m) {
                    cout << "Yes\n";
                    return;
                }
            }
            else {
                if (ct + ct4 >= m) {
                    cout << "Yes\n";
                    return;
                }
            }
        }
    }
    else {
        if (ct + ct4 >= m) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    

    

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        

        solve();
    }
}