



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

const int N = 50 * 1000 + 13;

int n, m;
int a[N], p[N];
vector<int> g[N];
int q[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	forn(i, n)
		g[i].clear();
	fore(i, 1, n){
		scanf("%d", &p[i]);
		--p[i];
		g[p[i]].pb(i);
	}
	forn(i, m){
		scanf("%d", &q[i]);
		--q[i];
	}
	return true;
}

pair<pt, int> val[N];
int tin[N], tout[N], T;
int d[N];

void dfs(int v){
	tin[v] = T++;
	val[tin[v]] = mp(mp(a[v], d[v]), 0);
	for (int u : g[v]){
		d[u] = d[v] + 1;
		dfs(u);
	}
	tout[v] = T;
}

void solve() {
	T = 0;
	dfs(0);
	forn(i, m){
		int v = q[i];
		int ans1 = 0, ans2 = 0;
		for (int k = tin[v]; k < tout[v]; ++k){
			if (val[k].y <= i){
				val[k].y = i + val[k].x.x;
				++ans1;
				ans2 += val[k].x.y;
			}
		}
		ans2 -= ans1 * d[v];
		printf("%d %d\n", ans2, ans1);
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