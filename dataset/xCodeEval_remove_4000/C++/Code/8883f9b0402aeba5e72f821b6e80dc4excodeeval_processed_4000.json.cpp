






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
    int n;
    cin >> n;
    vei a(n), b(n);
    f(n) cin >> a[i];
    f(n) cin >> b[i];
    int mxa = 0, mxb = 0;
    f(n) mxa = max(mxa, a[i]);
    f(n) mxb = max(mxb, b[i]);
    bool swp = 0;
    sort(all(a));
    sort(all(b));
    bool ok = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] + b[n - i - 1] != a[0] + b[n - 1]) ok = 0;
    }
    if (ok) {
        cout << "YES\n";
        f(n) cout << a[i] << ' ';
        cout << '\n';
        cout << 0 << ' ' << a[0] + b[n - 1] << '\n';
        return;
    }
    

    

    

    

    

    

    

    

    

    

    

    if (mxa < mxb) {
        swp = 1;
        swap(mxa, mxb);
        swap(a, b);
    }
    for (int j = 0; j < n; ++j) {
        multiset<int> aa, bb;
        f(n) aa.insert(-a[i]);
        f(n) bb.insert(-b[i]);
        int rst = mxa - b[j];
        bool ok = 1;
        int p = 0, p2 = rst;
        vector<int> ans;
        f(n) {
            if (*aa.begin() < *bb.begin()) {
                int c = -*aa.begin();
                int nd = abs(c - rst);

                if (bb.count(-nd) == 0) {
                    ok = 0;
                    break;
                }
                aa.erase(aa.find(-c));
                bb.erase(bb.find(-nd));
                ans.pb(c);
            }
            else {
                int c = -*bb.begin();
                int nd = abs(c - rst);

                if (aa.count(-nd) == 0) {
                    ok = 0;
                    break;
                }
                aa.erase(aa.find(-nd));
                bb.erase(bb.find(-c));
                ans.pb(rst - c);
            }
        }
        if (!ok) continue;
        sort(all(ans));
        if (ans[0] < 0) {
            p -= ans[0];
            p2 -= ans[0];
        }
        if (swp) swap(p, p2);
        if (ans[0] < 0) {
            for (int j = ans.size() - 1; j >= 0; --j) ans[j] -= ans[0];
        }
        cout << "YES\n";
        for (auto e : ans) cout << e << ' ';
        cout << '\n';
        cout << p << ' ' << p2 << '\n';
        return;
    }
    cout << "NO\n";
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