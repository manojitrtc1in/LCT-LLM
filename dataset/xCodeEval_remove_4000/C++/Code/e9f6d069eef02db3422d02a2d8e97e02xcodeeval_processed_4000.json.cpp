



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

const int N = 8000 + 7;

int n, m;
vector<pt> g[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, n)
		g[i].clear();
	forn(i, m){
		int v, u;
		scanf("%d%d", &v, &u);
		--v, --u;
		g[v].pb(mp(u, i));
		g[u].pb(mp(v, i));
	}
	return true;
}

vector<int> a;
int d[N];
bool used[N];

void dfs(int v, int p = -1){
	used[v] = true;
	for (auto it : g[v]) if (it.y != p){
		int u = it.x;
		if (u == 0)
			a.pb(d[v] + 1);
		else if (!used[u]){
			d[u] = d[v] + 1;
			dfs(u, it.y);
		}
	}
}

int add(int a, int b){
	a += b;
	if (a >= MOD)
		a -= MOD;
	if (a < 0)
		a += MOD;
	return a;
}

int mul(int a, int b){
	return a * li(b) % MOD;
}

int pr[2007][N], su[2007][N];

void calc(int dp[2007][N], bool fl){
	forn(i, sz(a) + 1) forn(j, N) dp[i][j] = 0;
	dp[0][N / 2] = 1;
	forn(i, sz(a)) forn(j, N) if (dp[i][j]){
		dp[i + 1][j + a[i]] = add(dp[i + 1][j + a[i]], dp[i][j]);
		dp[i + 1][j - a[i]] = add(dp[i + 1][j - a[i]], dp[i][j]);
		if (fl) dp[i + 1][j] = add(dp[i + 1][j], dp[i][j]);
	}
}

void solve() {
	memset(used, 0, sizeof(used));
	a.clear();
	dfs(0);
	
	calc(pr, true);
	reverse(all(a));
	calc(su, true);
	reverse(all(a));
	
	int ans = 0;
	forn(i, sz(a)){
		forn(t1, N) if (pr[i][t1]) fore(k, 1, a[i]){
			int t2;
			t2 = a[i] - (t1 - N / 2) - 2 * k + N / 2;
			ans = add(ans, mul(2, mul(pr[i][t1], su[sz(a) - i - 1][t2])));
			if (k < a[i] - 1){
				t2 = a[i] - (t1 - N / 2) - 2 * k - 1 + N / 2;
				ans = add(ans, mul(2, mul(pr[i][t1], su[sz(a) - i - 1][t2])));
			}
		}
	}
	
	calc(pr, false);
	reverse(all(a));
	calc(su, false);
	reverse(all(a));
	
	forn(i, sz(a)){
		forn(t1, N) if (pr[i][t1]){
			int k = 0;
			int t2;
			t2 = a[i] - (t1 - N / 2) - 2 * k - 1 + N / 2;
			ans = add(ans, mul(2, mul(pr[i][t1], su[sz(a) - i - 1][t2])));
			k = a[i] - 1;
			t2 = a[i] - (t1 - N / 2) - 2 * k - 1 + N / 2;
			ans = add(ans, mul(2, mul(pr[i][t1], su[sz(a) - i - 1][t2])));
		}
	}
	
	ans = add(ans, pr[sz(a)][N / 2]);
	printf("%d\n", ans);
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