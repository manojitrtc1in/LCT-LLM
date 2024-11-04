



























using namespace std;
int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	

	

	

	ll n;
	cin >> n;
	vector<ll>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll k1, k2, id2, otv = id1;
	otv = min(otv, id2);
	ll id0;
	for (int i = 1; i < n - 1; i++) {
		ll k1 = a[i - 1];
		ll k2 = a[i + 1];
		if (k1 < k2) {
			swap(k1, k2);
		}
		if (a[i] / 2 >= k2) {
			otv = min(otv, k2 + (k1 - k2 + 1) / 2);
		}
	}
	for (int i = 0; i < n - 1; i++) {
		k1 = a[i];
		k2 = a[i + 1];
		if (k1 < k2) { swap(k1, k2); }
		id2 = (k1 + 1) / 2;
		if (k2 - id2 > 0) {
			id2 = id2 + (k2 + 1 - id2) / 2;
		}
		if ((k1 + 1) / 2 >= k2) {
			id0 = (k1 + 1) / 2;
		}else{ id0 = (k1 + k2 + 2) / 3; }
		
		id2 = min(id2, id0);
		otv = min(otv, id2);
	}
	sort(a.begin(), a.end());
	otv = min(otv, (a[0] + 1) / 2 + (a[1] + 1) / 2);
	cout << otv << endl;
}
