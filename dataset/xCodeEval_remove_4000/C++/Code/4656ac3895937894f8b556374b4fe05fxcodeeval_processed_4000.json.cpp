



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

const int N = 100 + 7;

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

int binpow(int a, int b){
	b = (b % (MOD - 1) + MOD - 1) % (MOD - 1);
	int res = 1;
	while (b){
		if (b & 1)
			res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

int dp[N][N][N];
int siz[N];

void dfs(int v, int p = -1){
	dp[v][1][1] = 1;
	siz[v] = 1;
	for (int u : g[v]) if (u != p){
		dfs(u, v);
		vector<vector<int>> tmp(siz[v] + siz[u] + 1, vector<int>(siz[v] + siz[u] + 1, 0));
		fore(i, 1, siz[v] + 1) fore(k1, 1, siz[v] + 1) fore(j, 1, siz[u] + 1) fore(k2, 1, siz[u] + 1){
			tmp[i + j][k1] = add(tmp[i + j][k1], mul(dp[v][i][k1], mul(k2, dp[u][j][k2])));
			tmp[i + j - 1][k1 + k2] = add(tmp[i + j - 1][k1 + k2], mul(dp[v][i][k1], dp[u][j][k2]));
		}
		siz[v] += siz[u];
		forn(i, siz[v] + 1) forn(j, siz[v] + 1)
			dp[v][i][j] = tmp[i][j];
	}
}

int C[N][N];

void solve() {
	forn(i, N){
		C[i][0] = C[i][i] = 1;
		fore(j, 1, i)
			C[i][j] = add(C[i - 1][j], C[i - 1][j - 1]);
	}
	memset(dp, 0, sizeof(dp));
	dfs(0);
	vector<int> ans(n);
	fore(k, 1, n + 1){
		fore(siz, 1, n + 1)
			ans[n - k] = add(ans[n - k], mul(mul(dp[0][k][siz], siz), binpow(n, k - 2)));
		fore(j, n - k + 1, n)
			ans[n - k] = add(ans[n - k], -mul(C[j][n - k], ans[j]));
	}
	forn(i, n)
		printf("%d ", ans[i]);
	puts("");
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