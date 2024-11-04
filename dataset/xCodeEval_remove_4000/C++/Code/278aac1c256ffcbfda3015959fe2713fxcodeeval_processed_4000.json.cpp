



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

const int N = 3000 + 7;

int n, m;
vector<int> g[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, n)
		g[i].clear();
	forn(i, m){
		int v, u;
		scanf("%d%d", &v, &u);
		--v, --u;
		g[v].pb(u);
	}
	return true;
}

int d[N][N];

void bfs(int v, int d[N]){
	forn(i, n) d[i] = INF;
	d[v] = 0;
	queue<int> q;
	q.push(v);
	while (!q.empty()){
		int v = q.front();
		q.pop();
		for (int u : g[v]) if (d[u] == INF){
			d[u] = d[v] + 1;
			q.push(u);
		}
	}
}

vector<pt> ind[N], oud[N];

void solve() {
	forn(i, n) bfs(i, d[i]);
	forn(i, n){
		ind[i].clear();
		oud[i].clear();
	}
	forn(i, n) forn(j, n) if (i != j && d[i][j] != INF){
		ind[j].pb(mp(d[i][j], i));
		oud[i].pb(mp(d[i][j], j));
	}
	forn(i, n){
		sort(all(ind[i]), greater<pt>());
		ind[i].resize(min(sz(ind[i]), 4));
		sort(all(oud[i]), greater<pt>());
		oud[i].resize(min(sz(oud[i]), 4));
	}
	vector<pt> d1, d2;
	int ans = -INF;
	vector<int> res;
	forn(v2, n) forn(v3, n) if (v2 != v3 && d[v2][v3] != INF){
		for (auto it : ind[v2]) for (auto jt : oud[v3]){
			if (it.x + jt.x + d[v2][v3] <= ans) continue;
			int v1 = it.y;
			int v4 = jt.y;
			if (v1 != v2 && v1 != v3 && v4 != v1 && v4 != v2 && v4 != v3){
				ans = it.x + jt.x + d[v2][v3];
				res = {v1, v2, v3, v4};
			}
		}
	}
	cerr << ans << endl;
	for (auto it : res)
		printf("%d ", it + 1);
	puts("");
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