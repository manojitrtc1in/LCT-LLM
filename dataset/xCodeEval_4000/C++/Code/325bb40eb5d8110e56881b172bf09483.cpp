

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

const int N = 200 * 1000 + 13;

int n;
vector<int> g[N];
int a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		g[i].clear();
	forn(i, n){
		int p;
		scanf("%d%d", &p, &a[i]);
		if (p != -1){
			--p;
			g[p].pb(i);
		}
	}
	return true;
}

li dp[N][2];

void dfs(int v){
	vector<vector<li>> tmp(sz(g[v]) + 1, vector<li>(2, -INF64));
	tmp[0][0] = 0;
	forn(i, sz(g[v])){
		dfs(g[v][i]);
		forn(j, 2) forn(k, 2)
			tmp[i + 1][j ^ k] = max(tmp[i + 1][j ^ k], tmp[i][j] + dp[g[v][i]][k]);
	}
	dp[v][0] = tmp[sz(g[v])][0];
	dp[v][1] = max(tmp[sz(g[v])][1], tmp[sz(g[v])][0] + a[v]);
}

void solve() {
	dfs(0);
	printf("%lld\n", max(dp[0][0], dp[0][1]));
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