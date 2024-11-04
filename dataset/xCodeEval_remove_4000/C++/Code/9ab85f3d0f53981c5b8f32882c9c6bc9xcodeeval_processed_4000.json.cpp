


























using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;







const ll inf = (ll)1e18 + 7;
ld eps = 1e-9;
ll mod = 1e9 + 7;

signed main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	cin >> t;
	while (t--) {
		ll n, i, j, mx = -inf, mx2 = -inf, id, id2;
		cin >> n;
		vector <ll> a(n);
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.rbegin(), a.rend());
		cout << a[0] + a[1] << endl;
	}
}


