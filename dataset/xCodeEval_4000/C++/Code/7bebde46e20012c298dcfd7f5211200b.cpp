#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <unordered_map>
#include <set>
#include <map>
#include <stack>
#include <math.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;


struct BIT {
	int n;
	vector<int> v;

	BIT(int _n) : n(_n), v(_n + 1, 0) {}

	int lowbit(int x) { return x & (-x); }

	void add(int i, int k) {
		while (i <= n) {
			v[i] += k;
			i += lowbit(i);
		}
	}

	int getSum(int i) {
		int res = 0;
		while (i > 0) {
			res += v[i];
			i -= lowbit(i);
		}
		return res;
	}

	int getSum(int l, int r) {
		return getSum(r) - getSum(l - 1);
	}
};

const ll base = 1e9 + 7;

ll pw(ll a, ll b) {
	ll t = a, r = 1;
	while (b) {
		if (b & 1) r = (r * t) % base;
		t = (t * t) % base;
		b >>= 1;
	}
	return r;
}

ll inv(ll x) {
	return pw(x, base - 2);
}

const int maxn = 1e6 + 42;

ll F[maxn], RF[maxn];

ll fact(ll n) {
	return F[n] ? F[n] : F[n] = n ? n * fact(n - 1) % base : 1;
}
ll rfact(ll n) {
	return RF[n] ? RF[n] : RF[n] = inv(fact(n));
}

ll nCr(ll n, ll r) {
	return fact(n) * rfact(r) % base * rfact(n - r) % base;
}

void solve() {
	ll T;
	cin >> T;
	for (ll ii = 0; ii < T; ++ii) {
		ll n, m, k;
		cin >> n >> m >> k;
		const ll inv2 = inv(2);
		ll res = 0;
		if (m == n) res = n;
		else {
			for (ll i = 1; i <= m; ++i) {
				ll C = nCr(n - 1 - i, m - i);
				ll invpw = inv(pw(2, n - i));
				res += C * invpw % base * i % base;
				res %= base;
			}
		}
		cout << res * k % base << endl;
	}
}

int main() {
	solve();
	return 0;
}












































































































































































































