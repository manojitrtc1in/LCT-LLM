



using namespace std;














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

int siz[N];
li ans;
li tot[N];
int siz2[N];

void init(int v, int p, int n){
	siz2[v] = 1;
	tot[v] = 0;
	for (auto it : g[v]){
		int u = it.x;
		int w = it.y;
		if (u == p) continue;
		init(u, v, n);
		siz2[v] += siz2[u];
		tot[v] += tot[u] + w * li(siz2[u]) * li(n - siz2[u]);
	}
}

void calc(int v, int p, int n, int siz, li &bst){
	bst = min(bst, tot[v]);
	for (auto it : g[v]){
		int u = it.x;
		int w = it.y;
		if (u == p) continue;
		li totv = tot[v];
		li totu = tot[u];
		int id0 = siz2[v];
		int id1 = siz2[u];
		
		tot[v] -= tot[u] + w * li(siz2[u]) * li(n - siz2[u]);
		siz2[v] -= siz2[u];
		tot[u] += tot[v] + w * li(siz2[v]) * li(n - siz2[v]);
		siz2[u] += siz2[v];
		
		calc(u, v, n, siz, bst);
		
		tot[v] = totv;
		tot[u] = totu;
		siz2[v] = id0;
		siz2[u] = id1;
	}
}

void dfs(int v, int p = -1, int w = -1){
	siz[v] = 1;
	for (auto it : g[v]){
		int u = it.x;
		if (p == u) continue;
		dfs(u, v, it.y);
		siz[v] += siz[u];
	}
	if (p != -1){
		li bst1 = INF64, bst2 = INF64;
		init(v, p, n);
		calc(v, p, n, n - siz[v], bst1);
		init(p, v, n);
		calc(p, v, n, siz[v], bst2);
		ans = min(ans, bst1 + bst2 + w * li(siz[v]) * li(n - siz[v]));
	}
}

void solve() {
	ans = INF64;
	dfs(0);
	printf("%lld\n", ans);
}

int main() {

	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	

	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;


	int tc;
	scanf("%d", &tc);
	while(tc--){
		read();

	while(read()) {	

		solve();
		

	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();


	}
}