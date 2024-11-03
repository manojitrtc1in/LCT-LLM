



























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
		ll n1, n2;
		string st1, st2;
		cin >> n1 >> n2;
		cin >> st1 >> st2;
		bool kl = 0;
		if (n2 > n1)kl = 1;
		if (kl == 0 && n1!=1) {
			while (n1 != n2) {
				if (st1[0] == st2[0] || st1[1] == st2[0]) {
					st1[1] = st2[0];
				}
				st1.erase(0, 1);
				n1--;
			}
		}

		if (st1 != st2) { kl = 1; }
		if (kl == 1) {
			cout << "NO" << endl;
		}
		else { cout << "YES" << endl; }
	}
}


