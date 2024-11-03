



























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
		ll n, kol = 0;
		string st;
		cin >> n;
		cin >> st;
		vector<ll>pos;
		for (int i = 0; i < n; i++) {
			if (st[i] == '*') {
				pos.push_back(i);
				kol++;
			}
		}
		if (kol != 0) {
			int pp = kol / 2, pos1 = pos[pp];
			ll d = 0, k = 0;
			for (int i = pp - 1; i >= 0; i--) {
				pos1--;
				d = d + abs(pos1 - pos[i]);
			}
			pos1 = pos[pp];
			for (int i = pp + 1; i < kol; i++) {
				pos1++;
				d = d + abs(pos1 - pos[i]);
			}
			cout << d << endl;
		}
		else { cout << 0 << endl; }
	}

}

