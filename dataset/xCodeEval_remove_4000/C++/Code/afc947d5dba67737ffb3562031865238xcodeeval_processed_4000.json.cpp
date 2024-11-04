



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
	tin[v] = T++;
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
	T = 0;
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

int dist(int v, int u){
	int l = lca(v, u);
	return h[v] + h[u] - 2 * h[l];
}

set<pt> cur;

int get(int v){
	auto it = cur.lower_bound(mp(tin[v], v));
	int nxt = (it == cur.end() ? cur.begin()->y : it->y);
	int prv = (it == cur.begin() ? cur.rbegin()->y : (--it)->y);
	return dist(prv, v) + dist(v, nxt) - dist(prv, nxt);
}

int add(int v){
	int d = get(v);
	cur.insert(mp(tin[v], v));
	return d;
}

int rem(int v){
	cur.erase(mp(tin[v], v));
	return get(v);
}

void solve(){
	init();
	int ans = 0;
	int l = 0;
	cur.clear();
	int d = 2;
	k *= 2;
	forn(r, n){
		if (cur.empty()){
			cur.insert(mp(tin[r], r));
			ans = max(ans, 1);
			continue;
		}
		d += add(r);
		while (d > k)
			d -= rem(l++);
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