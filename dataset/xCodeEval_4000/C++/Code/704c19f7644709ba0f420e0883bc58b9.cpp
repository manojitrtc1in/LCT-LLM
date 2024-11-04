

























































































#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
 
using namespace std;
template<typename T1, typename T2> inline bool chkmin(T1 &a, T2 b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<typename T1, typename T2> inline bool chkmax(T1 &a, T2 b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
#define rank rank228
using ll = long long;
using ld = long double; 
const int MAXN = 1028;
const int Mod = 998244353;


int sum(int a, int b) {
	return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
	return ((ll)a * b) % Mod;
}

int n, m;
__int128 a[MAXN];
vector<int> g[MAXN];
bool deleted[MAXN];
vector<int> rg[MAXN];
int cnte[MAXN];
bool ok[MAXN];


void solve() {
	cin >> n >> m;
	vector<int> cur;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		a[i] = val;
		g[i].clear();
		rg[i].clear();
		cur.pb(i);
		deleted[i] = false;
	} 
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].pb(y);
		rg[y].pb(x);
	}
	auto check = [&](int &cnt) {
		bool need = false;
		for (auto &i: cur) {
			bool was = false;
			for (auto z: rg[i]) {
				if (!deleted[z]) {
					was = true;
				}
			}
			if (!was && a[i] == 0) {
				deleted[i] = true;
				need = true;
				cnt++;
				swap(i, cur.back());
				cur.pop_back();
				break;
			}
		}
		return need;
	};
	ll ans = 0;
	int cnt = 0;
	while (cnt < n) {
		if (check(cnt)) {
			continue;
		}
		for (auto i: cur) {
			cnte[i] = -1;
			for (auto z: rg[i]) {
				if (!deleted[z]) {
					cnte[i]++;
				}
			}
		} 
		while (true) {
			bool bad = false;
			bool stop = false;
			for (auto i: cur) {
				ok[i] = false;
				if (a[i] == 0 && cnte[i] == -1) {
					stop = true;
				}
				if (a[i] == 0 && cnte[i] != -1) {
					bad = true;
				}
				if (a[i] != 0) {
					ok[i] = true;
				}
			}
			if (stop || !bad) {
				break;
			}
			for (auto i: cur) {
				if (ok[i]) {
					a[i]--;
					for (auto z: g[i]) {
						a[z]++;
					}
				}
			}
			ans = sum(ans, 1);
		}
		__int128 td;
		bool was = false;
		for (auto i: cur) {
			if (cnte[i] == -1) {
				if (!was) {
					td = a[i];
					was = true;
				} else {
					chkmin(td, a[i]);
				}
			}
		}
		if (td) {
			ans = sum(ans, td % Mod);
			for (auto i: cur) {
				a[i] += td * cnte[i];
				a[i] %= (ll)Mod * Mod;		
			}
		}
	}
	cout << ans % Mod << '\n';
}


int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t;
	t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}