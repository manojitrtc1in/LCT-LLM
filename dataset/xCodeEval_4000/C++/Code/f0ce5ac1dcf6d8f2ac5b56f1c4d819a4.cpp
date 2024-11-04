

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
const int MOD = int(1e9) + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 5000 + 7;

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

bool ok[N];
bool dp[N][N];
int siz[N];

void dfs(int v, int p = -1){
	siz[v] = 1;
	for (int u : g[v]) if (u != p){
		dfs(u, v);
		siz[v] += siz[u];
	}
}

void solve() {
	memset(ok, 0, sizeof(ok));
	forn(i, n){
		forn(j, sz(g[i]) + 1) forn(k, n + 1)
			dp[j][k] = false;
		dp[0][0] = true;
		dfs(i);
		forn(j, sz(g[i])) forn(k, n + 1) if (dp[j][k]){
			dp[j + 1][k] = true;
			dp[j + 1][k + siz[g[i][j]]] = true;
		}
		fore(j, 1, n - 1){
			ok[j] |= dp[sz(g[i])][j];
		}
	}
	int ans = 0;
	forn(i, n) ans += ok[i];
	printf("%d\n", ans);
	forn(i, n) if (ok[i])
		printf("%d %d\n", i, n - i - 1);
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

#ifdef MULTITEST
	int tc;
	scanf("%d", &tc);
	while(tc--){
		read();
#else
	while(read()) {	
#endif
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}