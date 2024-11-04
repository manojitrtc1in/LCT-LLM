

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double
#define all(a) a.begin(), a.end()
#define sz(v) (int) v.size()
#define fori(i, j, n) for (int i = j; i < n; i++)

typedef long long ll;
typedef string str;
typedef pair<int, int> pi;

const int INF = 1e9;
const int PI = static_cast<const int>(3.1415926535897932384626433832795);
const int MOD = (1 << 64) - 1;


class SparseTable {
public:
    vector <vector <int> > d;
    int n;
    vector <int> lg;

    explicit SparseTable(const vector <int>& v) {
        n = v.size();
        lg.resize(n + 1);
        for (int i = 2; i <= n; ++i) {
            lg[i] = lg[i / 2] + 1;
        }
        d.resize(lg[n] + 1, vector <int>(n, INF));
        d[0] = v;
        for (int k = 1; k <= lg[n]; ++k) {
            for (int i = 0; i + (1 << k) <= n; ++i) {
                d[k][i] = min(d[k - 1][i], d[k - 1][i + (1 << (k - 1))]);
            }
        }
    }

    int get(int l, int r) {
        int q = lg[r - l + 1];
        return min(d[q][l], d[q][r - (1 << q) + 1]);
    }
};

int ans = 0;

void split(int l, int r, SparseTable &st) {
    if(l == r) return;
    int n = (l + r) / 2;


    if(st.get(l, n) > st.get(n + 1, r))
        ans++;

    split(l, n, st);
    split(n + 1, r, st);
}

void solve() {
    int n;
    cin >> n;
    ans = 0;

    vector<int> v(n);

    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    if(n % 2 != 0 and n != 1) {
        cout << "-1\n";
        return;
    }
    if((n & (n - 1)) != 0) {
        cout << "-1\n";
        return;
    }
    if (n == 1) {
        cout << 0 << "\n";
        return;
    }
    if(n == 2) {
        if(v[0] > v[1])
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
        return;
    }


    set<int> s;
    for(int i = 0; i < n; i++) {
        if(s.count(v[i])) {
            cout << "-1\n";
            return;
        }
        s.insert(v[i]);
    }

    for(int i = 0; i < n; i+=4) {
        if(abs(v[i] - v[i + 1]) != 1 or abs(v[i + 2] - v[i + 3]) != 1) {
            cout << "-1\n";
            return;
        }
        if(abs(min(v[i], v[i + 1]) - min(v[i + 2], v[i + 3])) != 2) {
            cout << "-1\n";
            return;
        }
    }

    SparseTable st(v);
    split(0, n - 1, st);

    cout << ans << "\n";
}

signed main() {














    int t;
    cin >> t;



    fori(tt, 0, t) {
        

        solve();
    }


    return 0;
}
