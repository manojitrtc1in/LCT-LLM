



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

const int N = 600 + 7;

int n, m, k;
pair<pt, int> e[N * N];
li a[N][N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, m){
		scanf("%d%d%d", &e[i].x.x, &e[i].x.y, &e[i].y);
		--e[i].x.x, --e[i].x.y;
	}
	forn(i, n) forn(j, n){
		a[i][j] = -INF64;
	}
	scanf("%d", &k);
	forn(i, k){
		int v, u, w;
		scanf("%d%d%d", &v, &u, &w);
		--v, --u;
		a[v][u] = a[u][v] = w;
	}
	return true;
}

li g[N][N];

void solve() {
	forn(i, n) forn(j, n)
		g[i][j] = i == j ? 0 : INF64;
	forn(i, m){
		int v = e[i].x.x, u = e[i].x.y;
		g[v][u] = g[u][v] = e[i].y;
	}
	forn(k, n) forn(i, n) forn(j, n){
		g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
	}
	forn(k, n) forn(i, n) forn(j, n){
		a[i][k] = max(a[i][k], a[i][j] - g[k][j]);
		a[k][j] = max(a[k][j], a[i][j] - g[i][k]);
	}
	int ans = 0;
	forn(i, m) if (a[e[i].x.x][e[i].x.y] - e[i].y >= 0)
		++ans;
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