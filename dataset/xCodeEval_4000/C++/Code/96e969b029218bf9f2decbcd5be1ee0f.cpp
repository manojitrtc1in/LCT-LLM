

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

const int N = 100 * 1000 + 13;

int n, rt;
int a[N];
vector<int> g[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		g[i].clear();
	forn(i, n)
		scanf("%d", &a[i]);
	forn(i, n - 1){
		int v, u;
		scanf("%d%d", &v, &u);
		--v, --u;
		g[v].pb(u);
		g[u].pb(v);
	}
	scanf("%d", &rt);
	--rt;
	return true;
}

li dp[N];

void dfs(int v, int p = -1){
	vector<pair<li, int>> vals;
	for (int u : g[v]) if (u != p){
		dfs(u, v);
		vals.pb(mp(dp[u], u));
	}
	sort(all(vals), greater<pair<li, int>>());
	dp[v] = 1;
	li s = 0;
	forn(i, sz(vals)){
		int u = vals[i].y;
		if (a[v] > 1){
			dp[v] += dp[u] + 1;
			--a[v];
			s += a[u] - 1;
		}
		else{
			s += a[u];
		}
	}
	int t = min(li(a[v] - 1), s);
	dp[v] += t * 2;
	a[v] -= t;	
}

void solve() {
	++a[rt];
	dfs(rt);
	printf("%lld\n", dp[rt] - 1);
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