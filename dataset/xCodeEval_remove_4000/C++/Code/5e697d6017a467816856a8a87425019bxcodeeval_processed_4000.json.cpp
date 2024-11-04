



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

const int N = 500 * 1000 + 13;

int n, m;
vector<pt> g[N];
vector<pair<pt, int>> q[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, n){
		g[i].clear();
		q[i].clear();
	}
	forn(i, n - 1){
		int u, w;
		scanf("%d%d", &u, &w);
		--u;
		g[i + 1].pb(mp(u, w));
		g[u].pb(mp(i + 1, w));
	}
	forn(i, m){
		int v, l, r;
		scanf("%d%d%d", &v, &l, &r);
		--v;
		q[v].pb(mp(mp(l - 1, r), i));
	}
	return true;
}

int tin[N], tout[N], T;
li d[N];

void init(int v, int p = -1){
	tin[v] = T++;
	for (auto it : g[v]) if (it.x != p){
		d[it.x] = d[v] + it.y;
		init(it.x, v);
	}
	tout[v] = T;
}

li t[4 * N], upd[4 * N];

void push(int v){
	if (v * 2 + 1 < 4 * N){
		upd[v * 2] += upd[v];
		upd[v * 2 + 1] += upd[v];
	}
	t[v] += upd[v];
	upd[v] = 0;
}

void build(int v, int l, int r){
	upd[v] = 0;
	if (l == r - 1){
		t[v] = (sz(g[l]) == 1 ? d[l] : INF64);
		return;
	}
	int m = (l + r) / 2;
	build(v * 2, l, m);
	build(v * 2 + 1, m, r);
	t[v] = min(t[v * 2], t[v * 2 + 1]);
}

void add(int v, int l, int r, int L, int R, li val){
	push(v);
	if (L >= R)
		return;
	if (l == L && r == R){
		upd[v] += val;
		push(v);
		return;
	}
	int m = (l + r) / 2;
	add(v * 2, l, m, L, min(m, R), val);
	add(v * 2 + 1, m, r, max(m, L), R, val);
	t[v] = min(t[v * 2], t[v * 2 + 1]);
}

li get(int v, int l, int r, int L, int R){
	push(v);
	if (L >= R)
		return INF64;
	if (l == L && r == R)
		return t[v];
	int m = (l + r) / 2;
	li res = min(get(v * 2, l, m, L, min(m, R)), get(v * 2 + 1, m, r, max(m, L), R));
	t[v] = min(t[v * 2], t[v * 2 + 1]);
	return res;
}

li ans[N];

void dfs(int v, int p = -1){
	for (auto it : q[v])
		ans[it.y] = get(1, 0, n, it.x.x, it.x.y);
	for (auto it : g[v]) if (it.x != p){
		add(1, 0, n, 0, n, it.y);
		add(1, 0, n, tin[it.x], tout[it.x], -2ll * it.y);
		dfs(it.x, v);
		add(1, 0, n, tin[it.x], tout[it.x], 2ll * it.y);
		add(1, 0, n, 0, n, -it.y);
	}
}

void solve() {
	T = 0;
	init(0);
	build(1, 0, n);
	dfs(0);
	forn(i, m)
		printf("%lld\n", ans[i]);
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