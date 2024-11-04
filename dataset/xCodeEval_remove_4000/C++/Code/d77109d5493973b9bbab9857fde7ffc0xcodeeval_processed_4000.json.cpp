



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

int n, m;
int a[N];
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
		g[u].pb(v);
	}
	forn(i, n)
		scanf("%d", &a[i]);
	return true;
}

int cnt;
bool used[N];

void dfs(int v){
	used[v] = true;
	cnt += a[v];
	for (int u : g[v]) if (!used[u])
		dfs(u);
}

int e;
vector<int> path;
int p[N];

void init(int v){
	path.pb(v);
	used[v] = true;
	for (int u : g[v]) if (!used[u]){
		init(u);
		p[u] = v;
		++e;
		path.pb(v);
	}
}

int b[N];
int lst[N];

void solve() {
	memset(used, 0, sizeof(used));
	vector<int> rt;
	forn(i, n) if (!used[i]){
		cnt = 0;
		dfs(i);
		if (cnt) rt.pb(i);
	}
	if (sz(rt) > 1){
		puts("-1");
		return;
	}
	if (rt.empty()){
		puts("0");
		return;
	}
	
	memset(p, -1, sizeof(p));
	memset(used, 0, sizeof(used));
	e = 0;
	path.clear();
	init(rt[0]);
	
	forn(i, sz(path))
		lst[path[i]] = i;
	
	memcpy(b, a, sizeof(a));
	for (int x : path) b[x] ^= 1;
	
	vector<int> res;
	bool fl = true;
	

	forn(i, sz(path)){
		res.pb(path[i]);
		if (b[path[i]] != 0 && i == lst[path[i]]){
			if (i == sz(path) - 1){
				fl = false;
				break;
			}
			res.pb(path[i + 1]);
			res.pb(path[i]);
			b[path[i]] ^= 1;
			b[path[i + 1]] ^= 1;
		}
	}
	
	if (!fl){
		if (sz(path) == 1){
			puts("-1");
			return;
		}
		int k = sz(path);
		res.pb(path[k - 2]);
		res.pb(path[k - 1]);
		res.pb(path[k - 2]);
		b[path[k - 1]] ^= 1;
	}
	
	assert(count(b, b + n, 1) == 0);
	printf("%d\n", sz(res));
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