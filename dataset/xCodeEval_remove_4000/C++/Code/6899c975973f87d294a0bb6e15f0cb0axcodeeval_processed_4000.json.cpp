




















using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef array<ll, 3> arr3;


struct BIT {
	int n;
	vector<int> v;

	BIT(int _n) : n(_n), v(_n + 1, 0) {}

	int lowbit(int x) { return x & (-x); }

	void add(int i, int k) {
		while (i <= n) {
			v[i] += k;
			i += lowbit(i);
		}
	}

	int getSum(int i) {
		int res = 0;
		while (i > 0) {
			res += v[i];
			i -= lowbit(i);
		}
		return res;
	}

	int getSum(int l, int r) {
		return getSum(r) - getSum(l - 1);
	}
};
 
const ll base = 1e9 + 7;
 
ll pw(ll a, ll b) {
    ll t = a, r = 1;
    while (b) {
        if (b & 1) r = (r * t) % base;
        t = (t * t) % base;
        b >>= 1;
    }
    return r;
}
 
ll inv(ll x) {
    return pw(x, base - 2);
}
 
const int maxn = 1e6 + 42;
 
ll F[maxn], RF[maxn];
 
ll fact(ll n) {
    return F[n] ? F[n] : F[n] = n ? n * fact(n - 1) % base : 1;
}
ll rfact(ll n) {
    return RF[n] ? RF[n] : RF[n] = inv(fact(n));
}
 
ll nCr(ll n, ll r) {
    return fact(n) * rfact(r) % base * rfact(n - r) % base;
}

void solve() {
	ll T;
	cin >> T;
	const ll base = 1e9 + 7;
	for (ll ii = 1; ii <= T; ++ii) {
		ll n, m, st, ed;
		cin >> n >> m >> st >> ed;
		vector<vector<ll>> g(n + 1);
		vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
		for (ll i = 0; i < m; ++i) {
			ll x, y;
			cin >> x >> y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		vector<vector<pll>> q(2);
		q[0].push_back(pll(0, st));
		dp[st][0] = 1;
		int now = 0;
		vector<bool> vis(n + 1, false);
		while (q[now].size()) {
			set<ll> sett;
			for (auto& [par, x] : q[now]) {
				vis[x] = true;
				

				sett.insert(x);
			}
			vector<ll> ls(sett.begin(), sett.end());
			for (auto x: ls) {
				for (auto nei : g[x]) {
					if (vis[nei] == false) {
						dp[nei][0] = (dp[nei][0] + dp[x][0]) % base;
						q[!now].push_back(pll(x, nei));
					}
					if (sett.find(nei) == sett.end()) continue;
					dp[x][1] = (dp[x][1] + dp[nei][0]) % base;
				}
			}
			for (auto x : ls) {
				for (auto nei : g[x]) {
					if (vis[nei] == false) {
						dp[nei][1] = (dp[nei][1] + dp[x][1]) % base;
					}
				}
			}
			q[now].clear();
			now = !now;
		}
		cout << (dp[ed][0] + dp[ed][1]) % base << endl;
	}
}

int main() {
	solve();
    return 0;
}












































































































































































































