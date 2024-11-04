




























































































































































































































































































using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;













ll gcd(ll n, ll n1) {
	while (n != 0 && n1 != 0) {
		if (n > n1) n %= n1;
		else n1 %= n;
	}
	return n + n1;
}

ll lcm(ll n, ll n1) {
	ll nod = gcd(n, n1);
	return (n / nod) * (n1 / nod) * nod;
}

const ll mod = 1e9 + 7;

ll binpow(ll n, ll m) {
	if (m == 0)
		return 1;
	if (m % 2 == 1)
		return binpow(n, m - 1) * n;
	else {
		ll b = binpow(n, m / 2);
		return b * b;
	}
}

ll INF = 9999999999999999;

mt19937 gen(time(0));

void solve() {
	ll n;
	cin >> n;
	vector<ll> k(n + 1), h(n + 1);
	k[0] = h[0] = 0;
	for (int i = 1; i <= n; i++) cin >> k[i];
	for (int i = 1; i <= n; i++) cin >> h[i];
	ll cur = 0;
	ll ans = 0;
	for (int i = 0; i <= n; i++) {
		if (i == n) break;
		bool uu = true;
		ll u = INF;
		for (int j = i + 1; j <= n; j++) {
			if (k[j] - h[j] + 1ll <= k[i]) {
				

				uu = false;
				break;
			}
			else {
				u = min(u, (ll)(k[j] - h[j] - k[i]));
			}
		}
		assert(u >= 0);
		

		if (uu) {
			ans += ((ll)(1ll + (k[i+1] - k[i] - u)) * (ll)(k[i + 1] - k[i] - u)) / (ll)2;
			cur = k[i + 1] - k[i] - u;
		}
		else {
			ans += ((ll)(cur + 1ll + cur + 1ll + (k[i + 1] - k[i] - (ll)1)) * (ll)(k[i + 1] - k[i])) / (ll)2;
			cur += (k[i + 1] - k[i]);
		}
		assert(cur >= 1);
		

	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tt;
	cin >> tt;
	

	while (tt--) {
		solve();
	}
	return 0;
}