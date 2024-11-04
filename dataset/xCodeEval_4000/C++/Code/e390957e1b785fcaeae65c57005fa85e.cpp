
#include <bits/stdc++.h>

using namespace std;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		vector<int> a(n);
		long long s = 0;
		bool done = false;
		int mx_freq = 0, ans = 0;
		map<long long, int> mp;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] == 0) {
				if (!done) ans += mp[0];
				else {
					ans += mx_freq;
				}
				done = true;
				mp.clear();
				mx_freq = 0;
			}
			s += a[i];
			mp[s]++;
			mx_freq = max(mx_freq, mp[s]);
		}
		if (done) ans += mx_freq;
		else ans += mp[0];
		cout << ans << '\n';
	}
	return 0;
}