



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

const int N = 200 * 1000 + 13;

int n, x, y;
vector<int> g[N];

bool read () {
	if (scanf("%d%d%d", &n, &x, &y) != 3)
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

int dp[N][2];

void dfs(int v, int p = -1){
	dp[v][0] = dp[v][1] = 0;
	int cnt = 0;
	
	for (auto u : g[v]) if (u != p){
		dfs(u, v);
		dp[v][0] += min(dp[u][0], dp[u][1]);
		dp[v][1] += min(dp[u][0], dp[u][1]);
		cnt += (dp[u][0] == dp[u][1]);
	}
	
	if (cnt > 1)
		--dp[v][0];
	
	if (!cnt){
		++dp[v][0];
		++dp[v][1];
	}
	
	

}

void solve() {
	if (x >= y){
		bool ok = false;
		forn(i, n) ok |= (sz(g[i]) == n - 1);
		printf("%lld\n", y * li(n - 1 - ok) + x * ok);
		return;
	}
	
	dfs(0);
	int cnt = dp[0][0] - 1;
	
	printf("%lld\n", y * li(cnt) + x * li(n - 1 - cnt));
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