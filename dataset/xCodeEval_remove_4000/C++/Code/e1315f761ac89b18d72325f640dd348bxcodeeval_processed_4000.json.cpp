



























using namespace std;
bool comp(pair<ll, ll> a, pair<ll, ll> b) {
	return a.first > b.first;
}
int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		multiset < pair<ll, ll>, greater<pair<ll, ll>>>a;
		for (int i = 0; i < n; i++) {
			ll x1;
			cin >> x1;
			if (x1 != 0) {
				a.insert(mp(x1, i + 1ll));
			}
		}
		queue<pair<ll, ll>>otv;
		while (a.size()>=2) {
			pair<ll, ll>c = *a.begin();
			a.erase(c);
			pair<ll, ll>p = *a.begin();
			otv.push(mp(c.second, p.second));
			a.erase(p);
			c.first--;
			p.first--;
			if (c.first != 0) {
				a.insert(c);
			}
			if (p.first != 0) {
				a.insert(p);
			}
		}
		cout << otv.size() << endl;
		while (!otv.empty()) {
			cout << otv.front()f << ' ' << otv.front()s << endl;
			otv.pop();
		}
		
	}


}
