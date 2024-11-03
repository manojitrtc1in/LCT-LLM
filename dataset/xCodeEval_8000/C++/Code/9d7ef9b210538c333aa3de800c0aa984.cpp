








































































































































































































































































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

ll gcd(ll n, ll n1) {
	if (n == -1) return n1;
	if (n1 == -1) return n;
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

ll mod = 998244353;

ll binpow(ull n, ull m) {
	if (m == 0)
		return (ll)1;
	if (m % 2 == 1)
		return (binpow(n, m - 1ll) * n) % mod;
	else {
		ll b = binpow(n, m / (ll)2);
		return (b * b) % mod;
	}
}

ll INF = 999999999999999999;

mt19937 gen(time(0));

struct str {
	ll to, x, y;
};

vector<vector<str>> a;
vector<ll> val;
vector<bool> used, used2;

ll cur = -1;
ll sum = 0;

vector<vector<int>> primes(200005);
vector<int> mx(200005, 0), c(200005, 0);

void dfs(int v) {
	used[v] = true;
	for (str& s : a[v]) {
		if (!used[s.to]) {
			for (int u : primes[s.x]) c[u]--;
			for (int u : primes[s.y]) {
				c[u]++; mx[u] = max(mx[u], c[u]);
			}
			dfs(s.to);
			for (int u : primes[s.x]) c[u]++;
			for (int u : primes[s.y]) c[u]--;
		}
	}
}

void dfs2(int v, ll num) {
	sum = (sum + num) % mod;
	ll snum = num;
	used2[v] = true;
	for (str& s : a[v]) {
		if (!used2[s.to]) {
			num = snum;
			for (ll u : primes[s.x]) num = (num * u) % mod;
			for (ll u : primes[s.y]) num = (num * binpow(u, mod - 2)) % mod;
			dfs2(s.to, num);
		}
	}
}
void solve(){
	int n;
	cin >> n;
	sum = 0;
	a.clear();
	val.clear();
	used.clear();
	used2.clear();
	a.resize(n);
	val.resize(n);
	used.resize(n, 0);
	used2.resize(n, 0);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		ll x, y;
		cin >> u >> v >> x >> y;
		u--; v--;
		a[u].push_back({ v, y, x });
		a[v].push_back({ u, x, y });
	}
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			cur = 1ll;
			dfs(i);
			for (int j = 0; j <= n; j++) {
				if (mx[j] == 0) continue;
				for (int i1 = 0; i1 < mx[j]; i1++) cur = (cur * (ll)j) % mod;
				mx[j] = c[j] = 0;
			}
			dfs2(i, cur);
		}
	}
	cout << sum << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	srand(time(NULL));
	int tt;
	

	for (int i = 2; i <= 200000; i++) {
		ll i1 = i;
		for (int j = 2; j <= sqrt(i); j++) {
			if (j > i1) {
				primes[i].push_back(i1);
				i1 = 1;
				break;
			}
			while (i1 > 1 && i1 % j == 0) {
				primes[i].push_back(j);
				i1 /= j;
			}
			if (i1 == 1) break;
		}
		if (i1 > 1) primes[i].push_back(i1);
		
	}
	cin >> tt;
	

	while (tt--) {
		solve();
	}
	return 0;
}