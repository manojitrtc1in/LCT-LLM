








































































































































































































































































#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <cmath>
#include <assert.h>
#include <ctime>
#include <math.h>
#include <queue>
#include <string>
#include <numeric>
#include <fstream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <stack>
#include <random>
#include <list>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define pll pair<ll, ll>
#define pii pair<int, int>
#define pdd pair<ld, ld>
#define ff first
#define ss second	
#define all(v) v.begin(),v.end()

#pragma GCC optimize("-O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-Os")
#pragma comment(linker, "/STACK:66777216")

int gcd(int n, int n1) {
	while (n != 0 && n1 != 0) {
		if (n > n1) n %= n1;
		else n1 %= n;
	}
	return n + n1;
}

ll lcm(ll n, ll n1) {
	ll nod = gcd(n, n1);
	return n * n1 / nod;
}

ll mod = 1000000007;

ll binpow(ll n, ll m) {
	if (m == 0)
		return (ll)1;
	if (m % 2 == 1)
		return binpow(n, m - 1) * n;
	else {
		ll b = binpow(n, m / 2);
		return b * b;
	}
}

ll INF = 999999999999999999;

mt19937 gen(time(0));

void solve() {
	int n;
	cin >> n;
	vector<ll> a(n), pref(n, 0);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(all(a));
	reverse(all(a));
	for (int i = 0; i < n; i++) {
		if (i) pref[i] = pref[i - 1];
		pref[i] += a[i];
	}
	for (int i = 0; i < n; i++) {
		if (i + 1 + i + 2 > n) break;
		

		if (pref[n - 1] - pref[n - (i + 2) - 1] < pref[i]) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    

    while (tt--) {
        solve();
    }
    return 0;
}