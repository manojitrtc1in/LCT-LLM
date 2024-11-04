

#include <queue>
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <cmath>
#include <thread>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <chrono>
#include <random>

using namespace std;

using ll = long long;

const int N = 1e4 + 1;

int main() {
	int n, l, r;
	scanf("%d%d%d", &n, &l, &r);

	vector<bool> d1(N, false), d2(N, false);
	vector<int> p(N, -1);

	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i].first);
	}

	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i].second);
	}

	vector<int> b, c;
	for (int i = 0; i < n; ++i) {
		if (a[i].second == 0) b.push_back(a[i].first);
		if (a[i].second == 1) c.push_back(a[i].first);
	}
	sort(b.rbegin(), b.rend());
	sort(c.rbegin(), c.rend());
	a.clear();
	for (auto x : b) {
		a.push_back({x, 0});
	}
	b = c;
	for (auto x : b) {
		a.push_back({x, 1});
	}
	d1[0] = true;
	for (int i = 0; i < n; ++i) {
		for (int j = a[i].first; j < N; ++j) {
			if (d1[j]) {
				d2[j] = true;
			} else {
				if (d1[j - a[i].first]) {
					d2[j] = true;
					p[j] = i;
				}
			}
		}
		for (int j = 1; j < N; ++j) {
			d1[j] = d2[j];
			d2[j] = false;
		}
	}
	int ans = 0;

	for (int i = 0; i <= r; ++i) {
		if (i >= l && d1[i]) {
			vector<bool> was(n, false);
			int cur = i;
			while (cur > 0) {
				was[p[cur]] = true;
				cur -= a[p[cur]].first;
			}
			cur = i;
			int res = 0;
			for (int j = n - 1; j >= 0 && cur <= r && a[j].second == 1; --j) {
				if (!was[j]) {
					++res;
					cur += a[j].first;
				}
			}
			ans = max(res, ans);
		}
	}
	printf("%d\n", ans);
}














