



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

const int N = 1000 + 7;

int n, m;
vector<pt> g[N];
bool in[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, n){
		g[i].clear();
		in[i] = false;
	}
	forn(i, m){
		int v, u, w;
		scanf("%d%d%d", &v, &u, &w);
		--v, --u;
		g[v].pb(mp(u, w));
		in[u] = true;
	}
	return true;
}

pt dfs(int v){
	for (pt it : g[v]){
		pt res = dfs(it.x);
		return mp(min(res.x, it.y), res.y);
	}
	return mp(INF, v);
}

void solve() {
	vector<pair<pt, int>> ans;
	forn(i, n) if (!in[i]){
		pt res = dfs(i);
		if (res.x != INF)
			ans.pb(mp(mp(i, res.y), res.x));
	}
	sort(all(ans));
	printf("%d\n", sz(ans));
	for (auto it : ans)
		printf("%d %d %d\n", it.x.x + 1, it.x.y + 1, it.y);
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