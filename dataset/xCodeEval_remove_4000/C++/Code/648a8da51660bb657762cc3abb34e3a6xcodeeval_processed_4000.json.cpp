



























using namespace std;
int main()
{
	ifstream fin("cowart.in");
	ofstream fout("output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin >> t;
	while (t--) {
		ll n, k;
		double sum = 0.0, p;
		cin >> n;
		vector<double>a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		bool kl = 0;
		p = n - 1;
		for (int i = 0; i < n; i++) {
			if ((sum - a[i]) / p == a[i]) { kl = 1; break; }
		}
		if (kl == 1) {
			cout << "YES" << endl;
		}
		else { cout << "NO" << endl; }
	}
}

