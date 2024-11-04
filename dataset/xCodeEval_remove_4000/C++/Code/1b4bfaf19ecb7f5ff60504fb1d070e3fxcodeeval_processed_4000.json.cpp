
using namespace std;


























const double pi = 3.14159265358979323846;
const int module = 1e9 + 7;

int compare(pii a, pii b) {
	if(a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}

int main() {
	IO

	int tc;
	cin >> tc;
	while(tc--) {
		int n;
		cin >> n;

		vector<pii> nums(n); vector<ll> pref(n + 1, 0);
		loop(n) cin >> nums[i].first;
		loop(n) cin >> nums[i].second;

		sort(all(nums));

		for(int i = n - 1; i + 1; i--) pref[i] += nums[i].second + pref[i + 1];

		ll res1 = nums[n - 1].first, res2 = pref[0];
		loop(n) {
			if(nums[i].first >= pref[i + 1]) res1 = min(res1, (ll)nums[i].first);
			if(i && pref[i] >= nums[i - 1].first) res2 = min(res2, (ll)pref[i]);
		}









		cout << min(res1, res2) << "\n";
	}

	return 0;
}
