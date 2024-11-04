



























using namespace std;
int main() {
	ifstream fin("cowart.in");
	ofstream fout("output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t = 1;
	cin >> t;
	while (t--) {
		ll n, otv = 0, x;
		cin >> n >> x;
		vector<ll>a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		ll pos1, pos2 = -1;
		pos1 = pos2;
		for (int i = 0; i < n; i++) {
			if (pos1 == -1) {
				pos1 = a[i] - x;
				pos2 = a[i] + x;
			}
			else {
				ll x1 = a[i] - x, x2 = a[i] + x;
				if (x1 > pos2 || x2 < pos1) {
					pos1 = x1;
					pos2 = x2;
					otv++;
				}
				else {
					pos1 = max(pos1, x1);
					pos2 = min(pos2, x2);
				}
			}
		}
		cout << otv << endl;
	}
}


