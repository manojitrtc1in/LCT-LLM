











using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef pair<ll, int> PLI;
typedef vector<int> VI;
typedef double db;

template<class T1, class T2> bool umin(T1& a, T2 b) { return a > b ? (a = b, true) : false; }
template<class T1, class T2> bool umax(T1& a, T2 b) { return a < b ? (a = b, true) : false; }
template<class T> void clear(T& a) { T().swap(a); }

const int N = 5e5 + 5;

int n, m, _, k;
int a[N], f[N], b[N], ans;
bool v[N];

int main() {
    IOS; cin >> n >> m; f[0] = -2e9;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, m) {
        cin >> b[i]; v[b[i]] = 1;
        if (i == 1) continue;
        if (b[i] < b[i - 1] || a[b[i]] - a[b[i - 1]] < b[i] - b[i - 1])
            cout << -1, exit(0);
    }

    rep(i, 1, n) {
        a[i] -= i;
        if (f[ans] <= a[i]) {
            f[++ans] = a[i];
            if (v[i]) k = ans;
        }
        else {
            int cur = upper_bound(f + 1, f + 1 + ans, a[i]) - f;
            if (cur <= k) continue;
            f[cur] = a[i];
            if (v[i]) k = ans = cur;
        }
    }
    cout << n - ans;
    return 0;
}