



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

const int N = 200 * 1000 + 13;
const int LOGN = 19;

int n, k;
vector<int> g[N];

bool read () {
	if (scanf("%d%d", &n, &k) != 2)
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

int tin[N], T;
int h[N];
int pos[N];
vector<int> ord;

void dfs(int v, int p = -1){
	ord.pb(v);
	for (auto u : g[v]) if (u != p){
		h[u] = h[v] + 1;
		dfs(u, v);
		ord.pb(v);
	}
}

pt st[LOGN][N];
int pw[N];

int lca(int v, int u){
	v = pos[v];
	u = pos[u];
	if (v > u) swap(v, u);
	++u;
	int len = pw[u - v];
	return min(st[len][v], st[len][u - (1 << len)]).y;
}

void init(){
	ord.clear();
	dfs(0);
	for (int i = sz(ord) - 1; i >= 0; --i)
		pos[ord[i]] = i;
	forn(i, sz(ord))
		st[0][i] = mp(h[ord[i]], ord[i]);
	fore(j, 1, LOGN) forn(i, sz(ord)){
		st[j][i] = st[j - 1][i];
		if (i + (1 << (j - 1)) < sz(ord))
			st[j][i] = min(st[j][i], st[j - 1][i + (1 << (j - 1))]);
	}
	pw[0] = pw[1] = 0;
	fore(i, 2, N)
		pw[i] = pw[i / 2] + 1;
}

pt t[2 * N];
int ps[2 * N];

void push(int v){
	if (v * 2 + 1 < 2 * N){
		ps[v * 2] += ps[v];
		ps[v * 2 + 1] += ps[v];
	}
	t[v].x += ps[v];
	ps[v] = 0;
}

void build(int v, int l, int r){
	ps[v] = 0;
	t[v] = mp(0, r - l);
	if (l == r - 1)
		return;
	int m = (l + r) / 2;
	build(v * 2, l, m);
	build(v * 2 + 1, m, r);
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
	if (t[v * 2].x == t[v * 2 + 1].x)
		t[v] = mp(t[v * 2].x, t[v * 2].y + t[v * 2 + 1].y);
	else
		t[v] = min(t[v * 2], t[v * 2 + 1]);
}

int p[N], siz[N], d[N], nxt[N];

void dfs_sz(int v) {
	if (p[v] != -1) {
		auto it = find(g[v].begin(), g[v].end(), p[v]);
		if (it != g[v].end())
			g[v].erase(it);
	}
	siz[v] = 1;
	for (int &u : g[v]) {
		p[u] = v;
		d[u] = d[v] + 1;
		dfs_sz(u);
		siz[v] += siz[u];
		if (siz[u] > siz[g[v][0]])
			swap(u, g[v][0]);
	}
}

void id1(int v) {
	tin[v] = T++;
	for (int u : g[v]) {
		nxt[u] = (u == g[v][0] ? nxt[v] : u);
		id1(u);
	}
}



void update(int l, int r, int val) {
	

	upd(1, 0, n, l, r + 1, val);
}

void update_path(int v, int u, int val) {
	

	for (; nxt[v] != nxt[u]; u = p[nxt[u]]) {
		if (d[nxt[v]] > d[nxt[u]]) swap(v, u);
		update(tin[nxt[u]], tin[u], val);
	}
	if (d[v] > d[u]) swap(v, u);
	update(tin[v], tin[u], val);
}

void id0(int root = 0) {
	d[root] = 0;
	nxt[root] = root;
	p[root] = -1;
	T = 0;
	dfs_sz(root);
	id1(root);
}

void solve(){
	id0();
	init();
	build(1, 0, n);
	int ans = 0;
	int l = 0;
	set<pt> cur;
	forn(r, n){
		if (cur.empty()){
			update_path(r, r, 1);
			cur.insert(mp(tin[r], r));
			ans = max(ans, 1);
			continue;
		}
		int l1 = lca(cur.begin()->y, cur.rbegin()->y);
		cur.insert(mp(tin[r], r));
		int l2 = lca(cur.begin()->y, cur.rbegin()->y);
		if (l1 != l2)
			update_path(p[l1], l2, sz(cur) - 1);
		update_path(r, l2, 1);
		
		push(1);
		

		
		while (true){
			push(1);
			if ((t[1].x == 0 && n - t[1].y > k) || (t[1].x > 0 && k != n)){
				int l1 = lca(cur.begin()->y, cur.rbegin()->y);
				cur.erase(mp(tin[l], l));
				int l2 = lca(cur.begin()->y, cur.rbegin()->y);
				update_path(l, l1, -1);
				if (l1 != l2)
					update_path(p[l2], l1, -sz(cur));
				++l;
			}
			else{
				break;
			}
		}
		ans = max(ans, r - l + 1);
	}
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