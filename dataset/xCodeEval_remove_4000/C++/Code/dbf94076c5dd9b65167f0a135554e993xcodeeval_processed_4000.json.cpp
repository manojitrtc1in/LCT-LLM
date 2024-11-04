



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

int n;
vector<int> g[N];

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
	return true;
}

pt ask(const vector<int> &a){
	printf("? %d", sz(a));
	for (auto v : a) printf(" %d", v + 1);
	puts("");
	fflush(stdout);
	int v, d;
	scanf("%d%d", &v, &d);
	return mp(v - 1, d);
}

int dist[N][N];

void dfs(int v, int dist[N], int p = -1){
	for (auto u : g[v]) if (u != p){
		dist[u] = dist[v] + 1;
		dfs(u, dist, v);
	}
}

vector<int> get(int v, int d){
	vector<int> nw;
	forn(u, n) if (dist[v][u] == d)
		nw.pb(u);
	return nw;
}

void solve() {
	forn(i, n){
		dist[i][i] = 0;
		dfs(i, dist[i]);
	}
	
	vector<int> cur(n);
	iota(all(cur), 0);
	pt st = ask(cur);
	int v = st.x;
	int d = st.y;
	int lst = v;
	int l = d / 2, r = d;
	while (l <= r){
		int m = (l + r) / 2;
		vector<int> tmp = get(v, m);
		if (tmp.empty()){
			r = m - 1;
			continue;
		}
		pt val = ask(tmp);
		if (val.y != d){
			r = m - 1;
		}
		else{
			l = m + 1;
			lst = val.x;
		}
	}
	
	vector<int> tmp = get(lst, d);
	if (!tmp.empty()) v = lst;
	else tmp = get(v, d);
	
	pt val = ask(tmp);
	assert(val.y == d);
	int u = val.x;
	printf("! %d %d\n", v + 1, u + 1);
	fflush(stdout);
	
	static char buf[20];
	scanf("%s", buf);
	assert(buf[0] == 'C');
}

int main() {





	
	int tt = clock();
	

	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;

	int tc;
	scanf("%d", &tc);
	while(tc--){
		read();
		solve();
		

	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();


	}
}