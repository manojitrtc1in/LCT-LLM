



























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
		cin >> n;
		vector<ll>a(n, -1), b(n);
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		sort(b.begin(), b.end());
		ll pos1 = 0, pos2 = n / 2;
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				a[i] = b[pos1];
				pos1++;
			}
			else { a[i] = b[pos2]; pos2++; }
		}
		bool kl = 1, kl1 = 0, kl2 = 0;
		if ((a[0] > a[1] && a[0] > a[n - 1]) || (a[0] < a[1] && a[0] < a[n - 1])) {
			kl1 = 1;
		}
		if ((a[n - 1] > a[0] && a[n - 1] > a[n - 2]) || (a[n - 1] < a[n - 2] && a[n - 1] < a[0])) {
			kl2 = 1;
		}
		for (int i = 1; i < n - 1; i++) {
			if ((a[i] > a[i + 1] && a[i] > a[i - 1]) || (a[i] < a[i + 1] && a[i] < a[i - 1])) {
				continue;
			}
			else { kl = 0; break; }
		}
		if (kl == 0 || kl1 == 0 || kl2 == 0) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
			for (auto& i : a) {
				cout << i << ' ';
			}cout << endl;
		}
	}
}

