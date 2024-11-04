






using namespace std;
using namespace __gnu_pbds;









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