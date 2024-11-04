



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

const int N = 100 * 1000 + 13;

struct edge{
	int u, w, t, bal1, bal2;
};

int n;
vector<edge> g[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		g[i].clear();
	forn(i, n - 1){
		int v, u, w, t;
		scanf("%d%d%d%d", &v, &u, &w, &t);
		--v, --u;
		g[v].pb({u, w, t, 2 * (t == 0) - (t == 1), 2 * (t == 1) - (t == 0)});
		g[u].pb({v, w, t, 2 * (t == 0) - (t == 1), 2 * (t == 1) - (t == 0)});
	}
	return true;
}

int h[N], pcd[N], d[N];
vector<int> cg[N], st[N];

int dfs(int v, int s, int &cd, int p = -1){
	int sum = 1;
	for (auto it : g[v]) if (h[it.u] == -1 && it.u != p)
		sum += dfs(it.u, s, cd, v);
	if (cd == -1 && (2 * sum >= s || p == -1))
		cd = v;
	return sum;
}

void build(int v, int s, int d, int p = -1){
	int cd = -1;
	dfs(v, s, cd);
	h[cd] = d;
	pcd[cd] = p;
	for (auto it : g[cd]) if (h[it.u] == -1)
		build(it.u, s / 2, d + 1, cd);
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
	int res = 1;
	while (b){
		if (b & 1)
			res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

bool used[N];

int f1[4 * N], f2[4 * N];

void upd(int f[N], int x, int val){
	for (int i = x; i < 4 * N; i |= i + 1)
		f[i] += val;
}

int get(int f[N], int x){
	int res = 0;
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		res += f[i];
	return res;
}

int tot;

void upd(int val, int bal1, int bal2){
	tot += val;
	upd(f1, bal1 + 2 * n, val);
	upd(f2, bal2 + 2 * n, val);
}

void upd(int v, int p, int val, int bal1, int bal2){
	upd(val, bal1, bal2);
	for (auto it : g[v]){
		int u = it.u;
		if (!used[u]) continue;
		if (u == p) continue;
		upd(u, v, val, bal1 + it.bal1, bal2 + it.bal2);
	}
}

int ans;

void calc(int v, int p, int bal1, int bal2, int prod){
	int good = tot - get(f1, bal1 + 2 * n - 1) - get(f2, bal2 + 2 * n - 1);
	assert(good >= 0);
	ans = mul(ans, binpow(prod, good));
	for (auto it : g[v]){
		int u = it.u;
		if (!used[u]) continue;
		if (u == p) continue;
		calc(u, v, bal1 - it.bal1, bal2 - it.bal2, mul(prod, it.w));
	}
}

void dfs1(int v){
	for (int u : st[v])
		used[u] = true;
	upd(1, 0, 0);
	for (auto it : g[v]) if (used[it.u])
		upd(it.u, v, 1, it.bal1, it.bal2);
	for (auto it : g[v]) if (used[it.u]){
		upd(it.u, v, -1, it.bal1, it.bal2);
		calc(it.u, v, -it.bal1, -it.bal2, it.w);
		upd(it.u, v, 1, it.bal1, it.bal2);
	}
	for (auto it : g[v]) if (used[it.u])
		upd(it.u, v, -1, it.bal1, it.bal2);
	upd(-1, 0, 0);
	for (int u : st[v])
		used[u] = false;
	for (int u : cg[v])
		dfs1(u);
}

void solve(){
	memset(h, -1, sizeof(h));
	build(0, n, 0);
	
	forn(i, n) st[i].clear(), cg[i].clear();
	int ct = -1;
	forn(v, n){
		int u = v;
		while (u != -1){
			st[u].pb(v);
			u = pcd[u];
		}
		if (pcd[v] != -1)
			cg[pcd[v]].pb(v);
		else
			ct = v;
	}
	
	ans = 1;
	dfs1(ct);
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