

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

int n;
vector<pt> g[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		g[i].clear();
	forn(i, n - 1){
		int v, u, w;
		scanf("%d%d%d", &v, &u, &w);
		--v, --u;
		g[v].pb(mp(u, w));
		g[u].pb(mp(v, w));
	}
	return true;
}

li dw[N];
li bst[N];

void init(int v, int p = -1){
	bst[v] = 0;
	dw[v] = 0;
	for (auto it : g[v]){
		int u = it.x;
		int w = it.y;
		if (u == p) continue;
		init(u, v);
		bst[v] = max({bst[v], bst[u], dw[v] + dw[u] + w});
		dw[v] = max(dw[v], dw[u] + w);
	}
}

li ans;

void dfs(int v, int p = -1){
	{
		vector<li> cur;
		for (auto it : g[v]){
			int u = it.x;
			int w  = it.y;
			cur.pb(dw[u] + w);
		}
		sort(all(cur), greater<li>());
		li len = 0;
		forn(i, min(4, sz(cur))) len += cur[i];
		ans = max(ans, len);
	}
	{
		li curbst = 0, curdw = 0;
		vector<li> subst(sz(g[v]) + 1), sudw(sz(g[v]) + 1);
		for (int i = sz(g[v]) - 1; i >= 0; --i){
			subst[i] = max({subst[i + 1], bst[g[v][i].x], sudw[i + 1] + dw[g[v][i].x] + g[v][i].y});
			sudw[i] = max(sudw[i + 1], dw[g[v][i].x] + g[v][i].y);
		}
		forn(i, sz(g[v])){
			int u = g[v][i].x;
			int w = g[v][i].y;
			ans = max(ans, bst[u] + max({curbst, subst[i + 1], curdw + sudw[i + 1]}) + 2 * w);
			
			if (u != p){
				li svbst = bst[v];
				li svdw = dw[v];
				
				bst[v] = max({curbst, subst[i + 1], curdw + sudw[i + 1]});
				dw[v] = max(curdw, sudw[i + 1]);
				dfs(u, v);
				
				dw[v] = svdw;
				bst[v] = svbst;
			}
			
			curbst = max({curbst, bst[u], curdw + dw[u] + w});
			curdw = max(curdw, dw[u] + w);
		}
		
	}
}

void solve() {
	init(0);
	ans = 0;
	dfs(0);
	li sum = 0;
	forn(v, n) for (auto it : g[v]) sum += it.y;
	printf("%lld\n", sum - ans);
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
