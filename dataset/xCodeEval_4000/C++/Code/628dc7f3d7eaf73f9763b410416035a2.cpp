

#include <bits/stdc++.h>
#define all(n) (n).begin(), (n).end()
#define se second
#define fi first
#define pb push_back
#define mp make_pair
#define sqr(n) (n)*(n)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef double db;

template<class T1, class T2> bool umin(T1& a, T2 b) { return a > b ? (a = b, true) : false; }
template<class T1, class T2> bool umax(T1& a, T2 b) { return a < b ? (a = b, true) : false; }
template<class T> void clear(T& a) { T().swap(a); }

const int N = 1e5 + 5, inf = 1e9;

int n, m, _, k;
int a[60], b[60], c[60];

int main() {
    IOS; cin >> n;
    rep(i, 1, n) cin >> a[i];

    vector<VI> op;
    while (!is_sorted(a + 1, a + 1 + n)) {
        VI cur(1, 0);
        rep(i, 1, n) b[a[i]] = i;
        int i = 1;
        while (b[i] < b[i + 1]) ++i;
        int j = b[i];
        if (b[i + 1] - 1) cur.pb(b[i + 1] - 1);
        while (a[j] - 1 == a[j - 1]) --j;
        cur.pb(j - 1); cur.pb(b[i]);
        if (b[i] != n) cur.push_back(n);
        int cnt = 0;
        per(i, cur.size() - 1, 1)
            rep(j, cur[i - 1] + 1, cur[i]) c[++cnt] = a[j];
        rep(i, 1, n) a[i] = c[i];
        op.pb(cur);
    }

    cout << op.size() << '\n';
    for (auto i : op) {
        cout << i.size() - 1;
        rep(j, 1, i.size() - 1) cout << ' ' << i[j] - i[j - 1];
        cout << '\n';
    }
    return 0;
}