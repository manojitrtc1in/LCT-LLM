



























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
		vector<ll>a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		ll otv = 0;
		for (int i = 1; i < n; i++) {
			if (a[i] < a[i - 1]) { otv++; i++; }
		}
		cout << otv << endl;
	}
}

