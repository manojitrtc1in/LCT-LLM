








































































































































































































































































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

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define pb(a) push_back(a)
#define pll pair<ll, ll>
#define pii pair<int, int>
#define pdd pair<ld, ld>
#define ff first
#define ss second	
#define all(v) v.begin(),v.end()

#pragma GCC optimize("-O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-Os")

ll gcd(ll n, ll n1) {
	while (n != 0 && n1 != 0) {
		if (n > n1) n %= n1;
		else n1 %= n;
	}
	return n + n1;
}

ll lcm(ll n, ll n1) {
	ll nod = gcd(n, n1);
	return (n / nod) * (n1 / nod) * nod;
}


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

vector<vector<ll>> cur;

void solve() {
	int n;
	cin >> n;
	vector<vector<ll>> b(n, vector<ll>(n, 0)), a(n, vector<ll>(n, 0));
	for(int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			cin >> b[i][j];
		}
	}
	a[1][0] = b[0][0];
	int i1 = 2, j1 = 1;
	while (i1 < n && j1 < n) {
		a[i1][j1] = b[i1 - 1][j1] ^ a[i1 - 1][j1 - 1];
		i1++; j1++;
	}
	for (int i = 2; i < n; i += 2) {
		a[i + 1][0] = b[i][0] ^ b[0][i] ^ a[i - 1][0] ^ a[i][1];
		int i1 = i + 2, j1 = 1;
		while (i1 < n && j1 < n) {
			a[i1][j1] = b[i1 - 1][j1] ^ b[j1][i1 - 1] ^ a[i1 - 1][j1 - 1] ^ a[i1 - 2][j1] ^ a[i1 - 1][j1 + 1];
			i1++; j1++;
		}
	}
	a[1][n - 1] = b[0][n - 1];
	i1 = 2;
	j1 = n - 2;
	while (i1 < n && j1 >= 0) {
		a[i1][j1] = b[i1 - 1][j1] ^ a[i1 - 1][j1 + 1];
		i1++;
		j1--;
	}
	for (int i = 2; i < n; i+=2) {
		a[i + 1][n - 1] = b[0][n - 1 - i] ^ b[i][n - 1] ^ a[i][n - 2] ^ a[i - 1][n - 1];
		int i1 = i + 2, j1 = n - 2;
		while (i1 < n && j1 >= 0) {
			a[i1][j1] = a[i1 - 1][j1 + 1] ^ b[i1 - 1][j1] ^ b[i1 - 1 - i][j1 - i] ^ a[i1 - 2][j1] ^ a[i1 - 1][j1 - 1];
			i1++;
			j1--;
		}
	}
	ll ans = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans ^= a[i][j];
		}
	}
	

	cout << ans << '\n';
	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int tt;
	cin >> tt;
	

	while (tt--) {
		solve();
	}
	return 0;
}