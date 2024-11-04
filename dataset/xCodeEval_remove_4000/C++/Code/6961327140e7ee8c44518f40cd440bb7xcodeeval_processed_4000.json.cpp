



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

const int N = 200 * 1000 + 13;

int n, m;
vector<int> a[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, n){
		a[i].resize(m);
		forn(j, m)
			scanf("%d", &a[i][j]);
	}
	return true;
}

vector<int> g[N];

bool ok;
vector<int> ord;
int used[N];

void dfs(int v){
	used[v] = 1;
	for (auto u : g[v]){
		if (used[u] == 0){
			dfs(u);
		}
		else if (used[u] == 1){
			ok = false;
		}
	}
	used[v] = 2;
	ord.pb(v);
}

void solve() {
	forn(i, N) g[i].clear();
	int siz = m;
	forn(r, n){
		vector<pt> vals;
		forn(i, m) if (a[r][i] != -1)
			vals.pb(mp(a[r][i], i));
		sort(all(vals));
		forn(i, sz(vals)){
			int j = i;
			while (j + 1 < sz(vals) && vals[j + 1].x == vals[j].x)
				++j;
			if (i != 0){
				fore(k, i, j + 1)
					g[siz].pb(vals[k].y);
			}
			if (j != m - 1){
				++siz;
				fore(k, i, j + 1)
					g[vals[k].y].pb(siz);
			}
			i = j;
		}
	}
	assert(siz < N);
	
	ord.clear();
	memset(used, 0, sizeof(used));
	ok = true;
	forn(i, siz) if (!used[i]){
		dfs(i);
		if (!ok){
			puts("-1");
			return;
		}
	}
	reverse(all(ord));
	vector<int> p;
	for (auto v : ord) if (v < m) p.pb(v);
	for (auto v : p) printf("%d ", v + 1);
	puts("");
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