



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
const int LOGN = 18;

int n, m;
vector<int> g[N];
pt q[N];

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
	scanf("%d", &m);
	forn(i, m){
		scanf("%d%d", &q[i].x, &q[i].y);
		--q[i].x, --q[i].y;
	}
	return true;
}

vector<int> ord;
int tin[N], rtin[N], tout[N], T;
int h[N];
int up[N][LOGN];

void init(int v, int p = -1){
	tin[v] = T++;
	rtin[tin[v]] = v;
	ord.pb(v);
	for (int u : g[v]) if (u != p){
		h[u] = h[v] + 1;
		up[u][0] = v;
		fore(i, 1, LOGN)
			up[u][i] = up[up[u][i - 1]][i - 1];
		init(u, v);
	}
	tout[v] = T;
}

int lca(int v, int u){
	if (h[v] < h[u]) swap(v, u);
	for (int i = LOGN - 1; i >= 0; --i)
		if (h[up[v][i]] >= h[u])
			v = up[v][i];
	if (v == u)
		return v;
	for (int i = LOGN - 1; i >= 0; --i)
		if (up[v][i] != up[u][i]){
			v = up[v][i];
			u = up[u][i];
		}
	return up[v][0];
}

pt climb(int v, int k){
	--k;
	for (int i = LOGN - 1; i >= 0; --i)
		if ((k >> i) & 1)
			v = up[v][i];
	return mp(up[v][0], v);
}

vector<pair<int, pt>> qs[N];
int ans[N];

int t[4 * N];
int ps[4 * N];

void build(int v, int l, int r){
	ps[v] = 0;
	if (l == r - 1){
		t[v] = h[rtin[l]];
		return;
	}
	int m = (l + r) / 2;
	build(v * 2, l, m);
	build(v * 2 + 1, m, r);
	t[v] = max(t[v * 2], t[v * 2 + 1]);
}

void push(int v){
	if (v * 2 + 1 < 4 * n){
		ps[v * 2] += ps[v];
		ps[v * 2 + 1] += ps[v];
	}
	t[v] += ps[v];
	ps[v] = 0;
}

void upd(int v, int l, int r, int L, int R, int val){
	push(v);
	if (L >= R)
		return;
	if (l == L && r == R){
		ps[v] += val;
		push(v);
		return;
	}
	int m = (l + r) / 2;
	upd(v * 2, l, m, L, min(m, R), val);
	upd(v * 2 + 1, m, r, max(m, L), R, val);
	t[v] = max(t[v * 2], t[v * 2 + 1]);
}

int get(int v, int l, int r, int L, int R){
	push(v);
	if (L >= R)
		return 0;
	if (l == L && r == R)
		return t[v];
	int m = (l + r) / 2;
	int res = max(get(v * 2, l, m, L, min(m, R)), get(v * 2 + 1, m, r, max(m, L), R));
	t[v] = max(t[v * 2], t[v * 2 + 1]);
	return res;
}

bool isp(int v, int u){
	return tin[v] <= tin[u] && tout[v] >= tout[u];
}

void dfs(int v, int p = -1){
	

	

	

	for (auto it : qs[v]){
		int u1 = it.y.x;
		int u2 = it.y.y;
		if (h[u1] < h[u2])
			swap(u1, u2);
		

		if (isp(u1, v) && isp(u2, v)){
			

			ans[it.x] = max(ans[it.x], get(1, 0, n, tin[u1], tout[u1]));
		}
		else{
			

			ans[it.x] = max(ans[it.x], get(1, 0, n, 0, tin[u1]));
			ans[it.x] = max(ans[it.x], get(1, 0, n, tout[u1], n));
		}
	}
	for (int u : g[v]) if (u != p){
		upd(1, 0, n, 0, n, 1);
		upd(1, 0, n, tin[u], tout[u], -2);
		dfs(u, v);
		upd(1, 0, n, tin[u], tout[u], 2);
		upd(1, 0, n, 0, n, -1);
	}
}

void solve() {
	T = 0;
	init(0);
	forn(i, n) qs[i].clear();
	forn(i, m){
		int v = q[i].x, u = q[i].y;
		int l = lca(v, u);
		int dist = h[v] + h[u] - 2 * h[l];
		pt t;
		if ((h[v] - h[l]) >= (dist + 1) / 2)
			t = climb(v, (dist + 1) / 2);
		else
			t = climb(u, (dist + 1) / 2);
		qs[v].pb(mp(i, t));
		qs[u].pb(mp(i, t));
	}
	build(1, 0, n);
	forn(i, n) ans[i] = 0;
	dfs(0);
	forn(i, m) printf("%d\n", ans[i]);
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