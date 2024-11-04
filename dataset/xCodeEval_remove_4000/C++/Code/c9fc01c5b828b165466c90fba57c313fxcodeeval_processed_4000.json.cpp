
 










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

const int N = 2e3 + 5;

int n, m, _, k; 
ll a[N], l[N], r[N], f[N];

int main() {
    IOS; cin >> n >> k;
    ll ans = 0, res = k;
    rep (i, 1, n) cin >> l[i] >> r[i] >> a[i];
    per (i, n, 1) {
        ll res = a[i];
        if (r[i] == l[i + 1]) res += f[i + 1];
        if (res > (r[i] - l[i] + 1) * k) { cout << -1; return 0; }
        f[i] = max(0ll, res - (r[i] - l[i]) * k);
    }
    rep (i, 1, n) {
        if (res < f[i]) ans += res, res = k;
        ans += a[i]; res = ((res - a[i]) % k + k) % k;
    }
    cout << ans;
    return 0;
}