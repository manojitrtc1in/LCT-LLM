



























using namespace std;
int main() {
	

	ifstream fin("input.txt");
	ofstream fout("output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t = 1;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		vector<ll>ans(n);
		vector<pair<ll,ll>>a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i].first;
			a[i].second = i;
		}
		sort(a.begin(), a.end());
		for (int i = 0; i < n - 1; i++) {
			ans[a[i].second] = -a[n - 1]f + a[i]f;
		}
		ans[a[n - 1]s] = -a[n - 2]f + a[n - 1]f;
		for (int i = 0; i < n; i++) {
			cout << ans[i] << ' ';
		}cout << endl;
	}
}


