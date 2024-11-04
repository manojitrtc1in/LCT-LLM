





























































































































































































































































































using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;













int gcd(int n, int n1) {
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

ll mod = 1000000007;

ll binpow(ll n, ll m) {
	if (m == 0)
		return (ll)1;
	if (m % 2 == 1)
		return binpow(n, m - 1) * n;
	else {
		ll b = binpow(n, m / 2);
		return b * b;
	}
}

ll INF = 999999999999999999;

mt19937 gen(time(0));

struct str {
	int i, j, id;
};

vector<vector<int>> a;
vector<vector<bool>> used;

int n, m;

int check(int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= m || i + 1 >= n || j + 1 >= m || i + 1 < 0 || j + 1 < 0) {
		return -1;
	}
	int u = max({ a[i][j], a[i + 1][j], a[i][j + 1], a[i + 1][j + 1] });
	if (u == -1) return -1;
	if ((a[i][j] == -1 || a[i][j] == u) && (a[i + 1][j] == -1 || a[i + 1][j] == u) && (a[i][j + 1] == -1 || a[i][j + 1] == u) && (a[i + 1][j + 1] == -1 || a[i + 1][j + 1] == u)) return u;
	return -1;
}

void solve() {
	cin >> n >> m;
	a.resize(n, vector<int>(m));
	used.resize(n, vector<bool>(m, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> a[i][j];
	queue<pii> q;
	vector<str> ans;
	ans.reserve(n * m);
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {
			if (!used[i][j] && !used[i][j + 1] && !used[i + 1][j] && !used[i + 1][j + 1] && a[i][j] == a[i + 1][j] && a[i][j] == a[i][j + 1] && a[i][j] == a[i + 1][j + 1]) {
				q.push({ i, j });
				q.push({ i + 1, j });
				q.push({ i, j + 1 });
				q.push({ i + 1, j + 1 });
				used[i][j] = used[i + 1][j] = used[i][j + 1] = used[i + 1][j + 1] = 1;
				ans.push_back({ i, j, a[i][j] });
				a[i][j] = a[i + 1][j] = a[i + 1][j + 1] = a[i][j + 1] = -1;
			}
		}
	}
	while (!q.empty()) {
		pii p = q.front();
		q.pop();
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				int u = check(p.ff + i, p.ss + j);
				if (u != -1) {
					ans.push_back({ p.ff + i, p.ss + j, u });
					if(a[p.ff + i][p.ss + j] != -1) q.push({ p.ff + i, p.ss + j });
					a[p.ff + i][p.ss + j] = -1;
					if (a[p.ff + i][p.ss + j + 1] != -1) q.push({ p.ff + i, p.ss + j + 1});
					a[p.ff + i][p.ss + j + 1] = -1;
					if (a[p.ff + i + 1][p.ss + j] != -1) q.push({ p.ff + i + 1, p.ss + j });
					a[p.ff + i + 1][p.ss + j] = -1;
					if (a[p.ff + i + 1][p.ss + j + 1] != -1) q.push({ p.ff + i + 1, p.ss + j + 1 });
					a[p.ff + i + 1][p.ss + j + 1] = -1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != -1) {
				cout << -1 << '\n';
				return;
			}
		}
	}
	reverse(all(ans));
	cout << (int)ans.size() << '\n';
	for (str& u : ans) cout << u.i + 1 << " " << u.j + 1 << " " << u.id << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	

	tt = 1;
	while (tt--) {
		solve();
	}
	return 0;
}