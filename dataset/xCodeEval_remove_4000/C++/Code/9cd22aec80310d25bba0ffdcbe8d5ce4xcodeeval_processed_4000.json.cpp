



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
const int M = 500 * 1000 + 13;






int n, m;
vector<pt> g[N];
bool usede[M];
int deg[N];
bool used[N];

vector<int> path;
void dfs(int v) {
	used[v] = true;
    while (!g[v].empty()) {
        int u = g[v].back().x;
        int i = g[v].back().y;
        g[v].pop_back();
        if (!usede[i]) {
        	usede[i] = true;
        	dfs(u);
        }
    }
    
    path.pb(v);
}

void id2() {
	memset(deg, 0, sizeof(deg));
	forn(i, n) for (auto j : g[i]) if (i <= j.x) {
		++deg[j.x];
		++deg[i];
	}
}

bool id1(vector<int>& res) {
	id2();

	int bad = 0, v1 = -1, v2 = -1;
	forn(i, n) if (deg[i] & 1) {
		++bad;
		if (v1 == -1) v1 = i;
		else if (v2 == -1) v2 = i;
	}
	
	path.clear();
	memset(usede, 0, sizeof(bool) * m);
	
	if (bad == 2) {
		dfs(v1);
	} else if (bad == 0) {
		forn(i, n) if (deg[i]) {
			dfs(i);
			break;
		}
	}
	
	if (m != 0 && sz(path) != m + 1)
		return false;
		
	reverse(all(path));
	res = path;
	
	return true;
}

vector<pt> ans;
int sf[N];
bool usf[N];

bool id0() {
	id2();
	
	int bad = 0;
	forn(i, n) bad += (deg[i] & 1);
	
	memset(usede, 0, sizeof(bool) * m);
	memset(used, 0, sizeof(used));
	memset(usf, 0, sizeof(usf));
	
	if (!bad) forn(i, n) if (deg[i] && !used[i]) {
		path.clear();
		dfs(i);
		int prv = 0;
		forn(j, sz(path) - 1){
			if (prv)
				ans.pb(mp(path[j], path[j + 1]));
			else
				ans.pb(mp(path[j + 1], path[j]));
			prv ^= ((!usf[path[j + 1]] * sf[path[j + 1]]) & 1) ^ 1;
			usf[path[j + 1]] = 1;
		}
	}
	
	return true;
}

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, n){
		g[i].clear();
		sf[i] = 0;
	}
	forn(i, m){
		int v, u;
		scanf("%d%d", &v, &u);
		--v, --u;
		if (v == u)
			++sf[v];
		else{
			g[v].pb(mp(u, i));
			g[u].pb(mp(v, i));
		}
	}
	return true;
}

int in[N], out[N];

void solve() {
	memset(deg, 0, sizeof(deg));
	forn(i, n) deg[i] = sz(g[i]) + sf[i] * 2;
	
	vector<int> ones;
	forn(i, n) if (deg[i] % 2 == 1)
		ones.pb(i);
	assert(sz(ones) % 2 == 0);
	forn(i, sz(ones) / 2){
		int v = ones[i];
		int u = ones[sz(ones) - i - 1];
		g[v].pb(mp(u, m));
		g[u].pb(mp(v, m++));
		++deg[v], ++deg[u];
	}
	
	ans.clear();
	assert(id0());
	
	for (auto it : ans){
		++in[it.x];
		++out[it.y];
	}
	forn(i, n) forn(j, sf[i]){
		ans.pb(mp(i, i));
		++in[i];
		++out[i];
	}
	forn(i, n) if (in[i] % 2 == 1){
		ans.pb(mp(i, i));
		++in[i];
		++out[i];
	}
	forn(i, n) assert(in[i] % 2 == 0 && out[i] % 2 == 0);
	
	printf("%d\n", sz(ans));
	for (auto it : ans)
		printf("%d %d\n", it.x + 1, it.y + 1);
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