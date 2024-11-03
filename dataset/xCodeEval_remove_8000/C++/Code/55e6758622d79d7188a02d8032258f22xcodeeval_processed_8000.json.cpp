



















typedef long long ll;

ll const INF = 9223372036854775807;
ll const NINF = -9223372036854775807;
using namespace std;
int main() {
	RR{
	ll n,m;
	cin >> n;
	vector<pair<ll, ll>> vec(n);
	for (ll i = 0; i < n; i++) {
		cin >> m;
		vec[i] = make_pair(m, i + 1);
	}
	sort(vec.begin(), vec.end());
	if (vec[0].first == vec[n - 2].first) cout << vec[n - 1].second << endl;
	else cout << vec[0].second << endl;
	}
	return 0;
}