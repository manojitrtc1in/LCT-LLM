



























using namespace std;
int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin >> t;
	while (t--) {
		ll n, otv = 1000;
		cin >> n;
		vector<vector<ll>>a(10);
		ll nn = n, kol = 0;
		while (n!=0) {
			a[n % 10].p_b(kol);
			kol++;
			n /= 10;

		}
		if (a[0].size() >= 2) {
			otv = a[0][1] - 1;
		}
		if (a[0].size() != 0) {
			ll z = a[0][0];
			for (int j = 0; j < a[5].size(); j++) {
				if (a[5][j] > z) {
					otv = min(otv, a[5][j] - 1ll);
					break;
				}
			}
		}
		if (a[5].size() != 0) {
			ll z = a[5][0];
			for (int j = 0; j < a[2].size(); j++) {
				if (a[2][j] > z) {
					otv = min(otv, a[2][j] - 1ll);
					break;
				}
			}
			for (int j = 0; j < a[7].size(); j++) {
				if (a[7][j] > z) {
					otv = min(otv, a[7][j] - 1ll);
					break;
				}
			}
		}
		cout << otv << endl;
	}
}