



























using namespace std;
int main() {
	ifstream fin("cowart.in");
	ofstream fout("output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	
	cin >> t;
	while (t--) {
		ll n, k;
		map<ll, ll>a;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> k;
			a[k % 10]++;
		}
		bool kl = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				for (int z = 0; z < 10; z++) {
					if ((i + j + z) % 10 == 3) {
						map<ll, ll>b;
						b[i]++;
						b[j]++;
						b[z]++;
						if (b[i] <= a[i] && b[j] <= a[j] && b[z] <= a[z]) { kl = 1; }
					}
				}
			}
		}
		if (kl == 1) {
			cout << "YES" << endl;
		}
		else { cout << "NO" << endl; }
		
	}
}

