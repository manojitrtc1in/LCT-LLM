



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
const int MOD = 998244353;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 2000 + 7;

int n;
string s;

bool read () {
	static char buf[N];
	if (scanf("%s", buf) != 1)
		return false;
	s = buf;
	n = sz(s);
	return true;
}

int add(int a, int b){
	a += b;
	if (a >= MOD)
		a -= MOD;
	if (a < 0)
		a += MOD;
	return a;
}

int mul(int a, int b){
	return a * li(b) % MOD;
}

vector<pt> g[N];
int clr[N];
bool fl;

void dfs(int v){
	for (auto it : g[v]){
		int u = it.x;
		int c = it.y;
		if (clr[u] == -1){
			clr[u] = clr[v] ^ c;
			dfs(u);
		}
		else if (clr[u] != (clr[v] ^ c)){
			fl = false;
			break;
		}
	}
}

int get(int m){
	int p0 = 2 * n;
	int p1 = 2 * n + 1;
	
	forn(i, p1 + 1)
		g[i].clear();
	g[p0].pb(mp(p1, 1));
	g[p1].pb(mp(p0, 1));
	
	forn(i, n) if (i != n - i - 1)
		g[i].pb(mp(n - i - 1, 0));
	forn(i, m) if (i != m - i - 1)
		g[n + i].pb(mp(n + m - i - 1, 0));
	
	forn(i, n) if (s[i] != '?'){
		g[i].pb(mp(n + i, s[i] - '0'));
		g[n + i].pb(mp(i, s[i] - '0'));
	}
	
	fore(i, m, n){
		g[n + i].pb(mp(p0, 0));
		g[p0].pb(mp(n + i, 0));
	}
	
	g[n - 1].pb(mp(p1, 0));
	g[p1].pb(mp(n - 1, 0));
	g[n + m - 1].pb(mp(p1, 0));
	g[p1].pb(mp(n + m - 1, 0));
	
	
	
	fl = true;
	memset(clr, -1, sizeof(clr));
	int ans = 1;
	forn(i, n + m + 1) if (clr[i] == -1){
		clr[i] = 0;
		dfs(i);
		if (!fl) return 0;
		ans = mul(ans, 2);
	}
	
	

	ans = mul(ans, (MOD + 1) / 2);
	return ans;
}

void solve() {
	reverse(all(s));
	int ans = 0;
	fore(i, 1, n + 1){
		int cnt = get(i);
		ans = add(ans, cnt);
		

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