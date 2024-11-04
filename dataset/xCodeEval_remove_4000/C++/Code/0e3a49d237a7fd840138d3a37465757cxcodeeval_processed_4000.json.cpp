


































using namespace std;






















typedef struct vector<ll> vll;
typedef struct vector<ld> vld;
typedef struct vector<vll> vvll;
typedef struct vector<vld> vvld;
typedef struct pair<ll, ll> ii;
const int MOD = 2111992;
const int MX = 10001;
const long long INF = 1e18 + 7;
const long double PI = 3.141592653589793238462643383279;
struct home {
	ll x1 = 0, y1 = 0;
	ll cnt = 0;
};
bool cmp(ll a, ll b) {
	return a > b;
}

void solve(ll testcase) {
	ll n, x; cin >> n;
	ll sum1 = 0, sum2 = 0;
	ll res = 0;
	vll a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	sort(all(a),cmp);
	sort(all(b),cmp);
	vll sa(n + 1), sb(n + 1);
	for (int i = 1; i <= n; i++) {
		sa[i] = a[i - 1] + sa[i - 1];
		sb[i] = b[i - 1] + sb[i - 1];
	}
	int lo = 0, hi = 1e7;
	while (lo < hi) {
		ll k = (lo + hi) / 2;
		ll m = (n + k) - (n + k) / 4;
		ll ca, cb;
		if (m <= k) ca = 100 * m;
		else ca = 100 * k + sa[m - k];
		cb = sb[min(n, m)];
		if (ca >= cb) hi = k;
		else lo = k + 1;
	}
	cout << lo << nl;
}

int main() {
	NDC;
	ll i = 1LL;
	ll tc; cin >> tc;
	for (i = 1; i <= tc; i++)
		solve(i);
	return 0;
}

