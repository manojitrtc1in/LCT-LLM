








































































































































































































































































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

ll binpow(ull n, ull m) {
	if (m == 0)
		return (ll)1;
	if (m % 2 == 1)
		return binpow(n, m - 1ll) * n;
	else {
		ll b = binpow(n, m / (ll)2);
		return b * b;
	}
}

ll INF = 999999999999999999;

mt19937 gen(time(0));

vector<int> depth, par;
vector<vector<int>> a, up, cnt;

int mx = 0, l, smx;

int lca(int a, int b) {
	if (a == b) return a;
	if (depth[a] < depth[b]) swap(a, b);
	int k = depth[a] - depth[b];
	for (int j = l - 1; j >= 0; j--)
		if (k & (1 << j))
			a = up[a][j];
	if (a == b) return a;
	for (int j = l - 1; j >= 0; j--) {
		if (up[a][j] != up[b][j]) {
			b = up[b][j];
			a = up[a][j];
		}
	}
	return up[a][0];
}

void dfs(int v, int p, int h) {
	depth[v] = h;
	cnt[h].push_back(v);
	par[v] = p;
	mx = max(mx, h);
	for (int u : a[v]) {
		if (u != p) {
			up[u][0] = v;
			for (int j = 1; j < l; j++) up[u][j] = up[up[u][j - 1]][j - 1];
			dfs(u, v, h + 1);
		}
	}
}

pii dfs2(int v, int p, int h, int y) {
	int mx = h;
	for (int u : a[v]) 
		if (u != p && u != y) 
			mx = max(mx, dfs2(u, v, h + 1, y).ff);
	return { mx, mx - h };
}

int timer = 0;

struct str {
	int len, fromroot, st;
};

int k;

struct CMP {
	bool operator()(pii p, pii p1) const {
		return p.ff + k - p.ss > p1.ff + k - p1.ss;
	}
};

void solve() {
	int n;
	cin >> n;
	l = log2(n) + 1;
	mx = 0;
	smx = 0;
	cnt.clear();
	par.clear();
	depth.clear();
	a.clear();
	up.clear();
	up.resize(n, vector<int>(l + 1));
	par.resize(n, -1);
	cnt.resize(n);
	depth.resize(n, 0);
	a.resize(n);
	up[0][0] = 0;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	dfs(0, -1, 0);
	int lcaall = cnt[mx][0];
	for (int i = 1; i < cnt[mx].size(); i++) lcaall = lca(lcaall, cnt[mx][i]);
	vector<int> b;
	for (int cur = lcaall; cur != -1; cur = par[cur]) b.push_back(cur);
	reverse(all(b));
	k = (int)b.size();
	vector<pii> num(k);
	for (int i = 0; i < k - 1; i++) {
		num[i] = dfs2(b[i], (i == 0 ? -1 : b[i - 1]), i, b[i + 1]);
	}
	int mxs = 0;
	multiset<pii, CMP> othermxs;
	queue<str> q;
	for (int i = 1; i <= n; i++) {
		int ans = mx;
		mxs = num[0].ff;
		timer = 0;
		othermxs.clear();
		while(q.size()) q.pop();
		q.push({num[0].ss, num[0].ff, timer});
		othermxs.insert({ num[0].ss, timer });
		for (int j = 1; j < k; j++) {
			timer++;
			while (q.size() && q.front().fromroot <= i + q.front().len + abs(timer - q.front().st)) {
				mxs = max(q.front().fromroot, mxs);
				othermxs.erase(othermxs.find({q.front().len, q.front().st}));
				q.pop();
			}
			
			

			ans = min(ans, max(max(mxs, (othermxs.size() ? i + (*othermxs.begin()).ff + abs(timer - (*othermxs.begin()).ss) : -1000000000)), i + mx - depth[b[j]]));
			q.push({num[j].ss, num[j].ff, timer});
			othermxs.insert({ num[j].ss, timer });
		}
		cout << ans << " ";
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	srand(time(NULL));
	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}