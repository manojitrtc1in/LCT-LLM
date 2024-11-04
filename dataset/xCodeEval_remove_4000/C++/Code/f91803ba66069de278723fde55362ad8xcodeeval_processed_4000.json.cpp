

























using namespace std;
typedef long long ll;



const long double Pi = acos(-1.0);
const ll dx[] = {0,0,1,-1};
const ll dy[] = {1,-1,0,0};
const ll N = (ll) 1e6 + 17;
const ll M = (ll) 5e3 + 69;
const ll inf = (ll) 1e14 + 3;
const ll mod = (ll) 1e9 + 7;
ll sq(ll x) { return x * x; }

ll zxc = 1, cnt = 0, a[M][M], d1[N], d2[N];

void solve() {
    ll n, m, ans = 0;
    cin >> n >> m;
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= m; j++) {
            cin >> a[i][j];
            d1[i - j + m] += a[i][j], d2[i + j] += a[i][j];
        }
    }
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= m; j++) {
            ans = max(ans, d1[i - j + m] + d2[i + j] - a[i][j]);
        }
    }
    cout << ans << "\n";
    for(ll i = 0; i <= n + m; i++) d1[i] = d2[i] = 0;
}

int main() {
ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> zxc;
    while(zxc--) {
        cnt++;
        solve();
    }
  	return 0;
}



