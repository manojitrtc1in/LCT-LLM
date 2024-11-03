



























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
		map<ll, ll>a;
		cin >> n;
		ll x;
		for (int i = 0; i < n; i++) {
			cin >> x;
			a[x]++;
		}
		vector<ll>left, right;
		ll mx=-1;
		for (auto& i : a) {
			if (i.second > 1) {
				right.push_back(i.first);
				left.push_back(i.first);
			}
			else {
				if (left.size() > right.size()) {
					right.push_back(i.first);
				}
				else { left.push_back(i.first); }
			}
			mx = i.second;
		}
		if (n == 1) {
			cout << 1 << endl;
		}
		else {
			if (left.size() != right.size()) {
				left.push_back(0);
				right.push_back(0);
			}
			cout << min(left.size(), right.size()) << endl;
		}
	}
}


