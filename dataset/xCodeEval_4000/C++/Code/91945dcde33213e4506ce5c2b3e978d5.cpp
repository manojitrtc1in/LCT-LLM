

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

const int N = 6000 + 7;

int n;
int a[N];
vector<int> g[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n){
		scanf("%d", &a[i]);
		g[i].clear();
	}
	forn(i, n - 1){
		int v, u;
		scanf("%d%d", &v, &u);
		--v, --u;
		g[v].pb(u);
		g[u].pb(v);
	}
	return true;
}

int ans;
vector<int> dpl[N], dpr[N];

void dfs(int v, int p = -1){
	dpl[v] = {-INF, a[v]};
	dpr[v] = {INF, a[v]};
	for (auto u : g[v]) if (u != p){
		dfs(u, v);
		forn(i, sz(dpl[v])) forn(j, sz(dpr[u])){
			if (dpl[v][i] < dpr[u][j])
				ans = max(ans, i + j);
		}
		forn(i, sz(dpr[v])) forn(j, sz(dpl[u])){
			if (dpl[u][j] < dpr[v][i])
				ans = max(ans, i + j);
		}
		
		if (sz(dpl[v]) < sz(dpl[u])) dpl[v].resize(sz(dpl[u]), INF);
		forn(i, sz(dpl[u])){
			if (a[v] > dpl[u][i]){
				if (i + 1 == sz(dpl[v])) dpl[v].pb(a[v]);
				else dpl[v][i + 1] = min(dpl[v][i + 1], a[v]);
			}
			dpl[v][i] = min(dpl[v][i], dpl[u][i]);
		}
		
		if (sz(dpr[v]) < sz(dpr[u])) dpr[v].resize(sz(dpr[u]), -INF);
		forn(i, sz(dpr[u])){
			if (a[v] < dpr[u][i]){
				if (i + 1 == sz(dpr[v])) dpr[v].pb(a[v]);
				else dpr[v][i + 1] = max(dpr[v][i + 1], a[v]);
			}
			dpr[v][i] = max(dpr[v][i], dpr[u][i]);
		}
	}
}

void solve(){
	ans = 1;
	dfs(0);
	printf("%d\n", ans);
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