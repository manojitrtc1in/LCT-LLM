

#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forn(i, n) for(int i = 0; i < int(n); i++) 
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template <class A, class B> ostream& operator << (ostream& out, const pair<A, B> &a) {
	return out << "(" << a.x << ", " << a.y << ")";
}

template <class A> ostream& operator << (ostream& out, const vector<A> &v) {
	out << "[";
	forn(i, sz(v)) {
		if(i) out << ", ";
		out << v[i];
	}
	return out << "]";
}

mt19937 rnd(time(NULL));

const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = INF + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 80 * 1000 + 13;

int n;
vector<int> g[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		g[i].clear();
	forn(i, n - 1){
		int v, u;
		scanf("%d%d", &v, &u);
		--v, --u;
		g[v].pb(u);
		g[u].pb(v);
	}
	return true;
}

li ans;

li dp[N][3];
int siz[N];

void dfs(int v, int p = -1){
	siz[v] = 1;
	dp[v][0] = 1;
	dp[v][1] = 0;
	dp[v][2] = 0;
	li sum0 = 0;
	for (auto u : g[v]) if (u != p){
		dfs(u, v);
		siz[v] += siz[u];
		dp[v][0] += dp[u][0];
		dp[v][1] += dp[u][1];
		dp[v][2] += dp[u][1] + dp[u][2];
		sum0 += dp[u][0];
	}
	for (auto u : g[v]) if (u != p){
		dp[v][2] += (sum0 - dp[u][0]) * dp[u][1];
	}
	
	li sumlca = 0;
	for (auto u : g[v]) if (u != p){
		sumlca += dp[u][0] * (sum0 - dp[u][0]);
	}
	assert(sumlca % 2 == 0);
	sumlca /= 2;
	for (auto u : g[v]) if (u != p){
		sumlca += dp[u][0];
	}
	dp[v][1] += sumlca;
	
	

	ans += sumlca * (n - siz[v]) * li(n - siz[v] - 1) / 2;
	for (auto u : g[v]) if (u != p){
		

		ans += (sumlca - dp[u][0] * (sum0 - dp[u][0]) - sum0) * dp[u][1];
		ans += (sum0 - dp[u][0]) * dp[u][1];
		ans += (sum0 - dp[u][0]) * dp[u][2];
		ans += dp[u][2];
	}
	
	

}

void solve() {
	ans = 0;
	dfs(0);
	assert(ans % 2 == 0);
	printf("%lld\n", ans);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	
#endif
	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;

	while(read()) {	
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}