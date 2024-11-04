



























using namespace std;
int main() {
	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		vector<ll>a(n + 5);
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (i > 0 && a[i] == a[i - 1]) { ans++; }
		}
		ll pos1 = -1, otv = 0;
		
		for (int i = 0; i < n - 1; i++) {
			if (a[i] == a[i + 1]) {
				if (pos1 == -1) {
					pos1 = i + 2ll;
					a[i + 1] = -2;
					a[i + 2] = -1;
					otv++;
				}
				else {
					otv = otv + i - pos1;
					pos1 = i;
					a[i] = -3;
				}
			}
		}
		if (ans == 1) { otv = 0; }
		if (n == 2 ) { otv = 0; }
		cout << otv << endl;
	}
}
