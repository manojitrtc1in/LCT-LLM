


























using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;







const ll inf = (ll)1e18 + 7;
ld eps = 1e-9;
ll mod = 1e9 + 7;

signed main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		ll i, j, n;
		vector <ll> key(26, 0);
		for (i = 0; i < s.size(); i++) {
			key[s[i] - 'a']++;
		}
		for (i = 0; i < s.size(); i++) {
			if (key[s[i] - 'a'] > 1) {
				key[s[i] - 'a']--;
			}
			else {
				break;
			}
		}
		for (j = i; j < s.size(); j++) {
			cout << s[j];
		}
		cout << endl;
	}
}


