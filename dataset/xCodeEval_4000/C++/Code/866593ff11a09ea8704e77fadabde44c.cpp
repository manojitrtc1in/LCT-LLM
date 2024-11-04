


#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iomanip>
#include <fstream>
#include <string>
#include <set>
#include <deque>
#include <queue>
#include <map>
#include <bitset>
#include <random>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;


#define endl "\n"
#define sqrt sqrtl

const ll inf = (ll)1e18 + 7;

ld eps = 1e-6;

struct point {
	ll x, y;
};

signed main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin >> t;
	while (t--) {
		ll w, h, i, j, k;
		cin >> w >> h;
		vector <point> a, b, c, d;
		cin >> k;
		a.resize(k);
		ll mn1 = inf, mx1 = -inf, mn2 = inf, mx2 = -inf, mn3 = inf, mx3 = -inf, mn4 = inf, mx4 = -inf;
		for (i = 0; i < k; i++) {
			cin >> a[i].x;
			mn1 = min(mn1, a[i].x);
			mx1 = max(mx1, a[i].x);
			a[i].y = 0;
		}
		cin >> k;
		b.resize(k);
		for (i = 0; i < k; i++) {
			cin >> b[i].x;
			mn2 = min(mn2, b[i].x);
			mx2 = max(mx2, b[i].x);
			b[i].y = h;
 		}
		cin >> k;
		c.resize(k);
		for (i = 0; i < k; i++) {
			cin >> c[i].y;
			mn3 = min(mn3, c[i].y);
			mx3 = max(mx3, c[i].y);
			c[i].x = 0;
		}
		cin >> k;
		d.resize(k);
		for (i = 0; i < k; i++) {
			cin >> d[i].y;
			mn4 = min(mn4, d[i].y);
			mx4 = max(mx4, d[i].y);
			d[i].x = w;
		}
		vector <ll> ans;
		ans.push_back((mx1 - mn1) * h);
		ans.push_back((mx1 - mn1) * mx3);
		ans.push_back((mx1 - mx1) * mx4);
		ans.push_back((mx2 - mn2) * h);
		ans.push_back((mx2 - mn2) * mn3);
		ans.push_back((mx2 - mn2) * mn4);
		ans.push_back((mx3 - mn3) * w);
		ans.push_back((mx3 - mn3) * mx1);
		ans.push_back((mx3 - mn3) * mx2);
		ans.push_back((mx4 - mn4) * w);
		ans.push_back((mx4 - mn4) * mn1);
		ans.push_back((mx4 - mn4) * mn2);
		sort(ans.rbegin(), ans.rend());
		cout << ans[0] << endl;
	}
}