



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

int dp[N][N][2];
int tmp[N][2];
int siz[N];

void dfs(int v, int p = -1){
	forn(i, n + 1) forn(j, 2) dp[v][i][j] = INF;
	siz[v] = 0;
	if (sz(g[v]) == 1){
		dp[v][1][0] = 0;
		dp[v][0][1] = 0;
		siz[v] = 1;
		return;
	}
	dp[v][0][0] = dp[v][0][1] = 0;
	for (auto u : g[v]) if (u != p){
		dfs(u, v);
		forn(i, siz[v] + siz[u] + 1) forn(j, 2) tmp[i][j] = INF;
		forn(i, siz[v] + 1) forn(j, siz[u] + 1){
			tmp[i + j][0] = min(tmp[i + j][0], dp[v][i][0] + dp[u][j][0]);
			tmp[i + j][0] = min(tmp[i + j][0], dp[v][i][0] + dp[u][j][1] + 1);
			tmp[i + j][1] = min(tmp[i + j][1], dp[v][i][1] + dp[u][j][1]);
			tmp[i + j][1] = min(tmp[i + j][1], dp[v][i][1] + dp[u][j][0] + 1);
		}
		forn(i, siz[v] + siz[u] + 1) forn(j, 2) dp[v][i][j] = tmp[i][j];
		siz[v] += siz[u];
	}
}

void solve() {
	if (n == 2){
		puts("1");
		return;
	}
	int cnt = 0;
	forn(i, n) cnt += sz(g[i]) == 1;
	forn(i, n) if (sz(g[i]) > 1){
		dfs(i);
		printf("%d\n", min(dp[i][cnt / 2][0], dp[i][cnt / 2][1]));
		return;
	}
}

int main() {

	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	

	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;

	while(read()) {	
		solve();
		

	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();


	}
}