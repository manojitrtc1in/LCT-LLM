



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

int n, m, k;
vector<pt> g[N];
vector<int> tg[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, n){
		g[i].clear();
		tg[i].clear();
	}
	forn(i, m){
		int v, u, w;
		scanf("%d%d%d", &v, &u, &w);
		--v, --u;
		g[v].pb(mp(u, w));
		tg[u].pb(v);
	}
	return true;
}

int clr[N];
vector<int> ord;
int used[N];

void ts(int v){
	used[v] = true;
	for (pt it : g[v]) if (!used[it.x])
		ts(it.x);
	ord.pb(v);
}

int tot;

void dfs(int v){
	clr[v] = tot;
	for (int u : tg[v]) if (clr[u] == -1)
		dfs(u);
}

li d[N], gg[N];

void dfs2(int v){
	used[v] = 1;
	for (auto it : g[v]){
		int u = it.x;
		int w = it.y;
		if (!used[u]){
			d[u] = d[v] + w;
			dfs2(u);
		}
		if (clr[u] == clr[v]){
			gg[clr[v]] = __gcd(gg[clr[v]], d[v] - d[u] + w);
		}
	}
	used[v] = 2;
}

void solve() {
	memset(used, 0, sizeof(used));
	ord.clear();
	forn(i, n) if (!used[i]) ts(i);
	reverse(all(ord));
	tot = 0;
	memset(clr, -1, sizeof(clr));
	for (int v : ord) if (clr[v] == -1){
		dfs(v);
		++tot;
	}
	memset(used, 0, sizeof(used));
	memset(d, 0, sizeof(d));
	memset(gg, 0, sizeof(gg));
	forn(i, n) if (!used[i])
		dfs2(i);
	scanf("%d", &k);
	forn(i, k){
		int v, s, t;
		scanf("%d%d%d", &v, &s, &t);
		--v;
		li g = gg[clr[v]];
		if (g == 0){
			puts(s == 0 ? "YES" : "NO");
			continue;
		}
		puts(s % __gcd(li(t), g) == 0 ? "YES" : "NO");
	}
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