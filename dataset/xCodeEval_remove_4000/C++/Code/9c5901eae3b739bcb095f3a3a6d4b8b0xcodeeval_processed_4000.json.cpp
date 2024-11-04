



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
const int MOD = 998244353;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 300 * 1000 + 13;

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

int dp[N][3];

void dfs(int v, int p = -1){
	dp[v][0] = 1;
	dp[v][1] = 1;
	vector<int> vals, init;
	for (auto u : g[v]) if (u != p){
		dfs(u, v);
		vals.pb(add(dp[u][1], add(dp[u][2], dp[u][2])));
		init.pb(add(dp[u][0], dp[u][1]));
		dp[v][0] = mul(dp[v][0], add(dp[u][1], add(dp[u][2], dp[u][2])));
		dp[v][1] = mul(dp[v][1], add(dp[u][1], dp[u][2]));
	}
	dp[v][0] = add(dp[v][0], -dp[v][1]);
	
	vector<int> pr(1, 1), su(1, 1);
	for (auto it : vals) pr.pb(mul(pr.back(), it));
	reverse(all(vals));
	for (auto it : vals) su.pb(mul(su.back(), it));
	reverse(all(vals));
	reverse(all(su));
	
	dp[v][2] = 0;
	forn(i, sz(vals))
		dp[v][2] = add(dp[v][2], mul(init[i], mul(pr[i], su[i + 1])));
	
	

}

void solve() {
	dfs(0);
	printf("%d\n", add(dp[0][1], dp[0][2]));
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