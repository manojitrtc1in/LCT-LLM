



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
const int MOD = INF + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 3000 + 7;

int n, k;
int a[N], b[N];
vector<int> g[N];

bool read () {
	if (scanf("%d%d", &n, &k) != 2)
		return false;
	forn(i, n)
		g[i].clear();
	forn(i, n)
		scanf("%d", &a[i]);
	forn(i, n)
		scanf("%d", &b[i]);
	forn(i, n - 1){
		int v, u;
		scanf("%d%d", &v, &u);
		--v, --u;
		g[v].pb(u);
		g[u].pb(v);
	}
	return true;
}

pair<int, li> dp[N][N];
li val[N];
int siz[N];

void dfs(int v, int p = -1){
	val[v] = b[v] - a[v];
	forn(i, n + 1) dp[v][i] = mp(-INF, -INF64);
	dp[v][0] = mp(0, val[v]);
	siz[v] = 1;
	for (auto u : g[v]) if (u != p){
		dfs(u, v);
		vector<pair<int, li>> tmp(siz[v] + siz[u], mp(-INF, -INF64));
		forn(i, siz[v]) forn(j, siz[u] + 1){
			pair<int, li> nw = mp(dp[v][i].x + dp[u][j].x, dp[v][i].y + dp[u][j].y);
			tmp[i + j] = max(tmp[i + j], nw);
		}
		forn(i, sz(tmp)){
			dp[v][i] = tmp[i];
		}
		siz[v] += siz[u];
		val[v] += val[u];
	}
	

	for (int i = siz[v] - 1; i >= 0; --i){
		dp[v][i + 1] = max(dp[v][i + 1], mp(dp[v][i].x + (dp[v][i].y > 0), 0ll));
	}
	

}

void solve(){
	

	

	dfs(0);
	printf("%d\n", dp[0][k - 1].x + (dp[0][k - 1].y > 0));
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
	while(tc--) {
		read();
		solve();
		

	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();


	}
}