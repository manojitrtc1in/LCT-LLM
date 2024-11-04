



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

const int N = 1000 * 1000 + 13;

int n;
vector<int> g[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		g[i].clear();
	fore(i, 1, n){
		int p;
		scanf("%d", &p);
		--p;
		g[i].pb(p);
		g[p].pb(i);
	}
	return true;
}

int siz[N];

void init(int v, int p = -1){
	siz[v] = 1;
	for (int u : g[v]) if (u != p){
		init(u, v);
		siz[v] += siz[u];
	}
}

int c;

void dfs(int v, int p, int up){
	int mx = up;
	for (int u : g[v]) if (u != p)
		mx = max(mx, siz[u]);
	if (mx * 2 <= n)
		c = v;
	for (int u : g[v]) if (u != p)
		dfs(u, v, up + siz[v] - siz[u]);
}

bitset<N> dp;

void solve() {
	init(0);
	c = -1;
	dfs(0, -1, 0);
	init(c);
	vector<int> ss;
	for (int u : g[c]) ss.pb(siz[u]);
	
	vector<int> a;
	sort(all(ss));
	forn(i, sz(ss)){
		int j = i;
		while (j + 1 < sz(ss) && ss[j + 1] == ss[i])
			++j;
		int tot = j - i + 1;
		forn(k, 20) if (tot >= (1 << k)){
			a.pb((1 << k) * ss[i]);
			tot -= 1 << k;
		}
		if (tot != 0){
			a.pb(tot * ss[i]);
		}
		i = j;
	}
	
	dp.reset();
	dp[0] = 1;
	for (int x : a) dp |= dp << x;
	
	li base = accumulate(siz, siz + n, 0ll) - siz[c];
	li ans = 0;
	
	forn(i, n + 1) if (dp[i] == 1)
		ans = max(ans, base + (i + 1) * li(n - i));
	printf("%lld\n", ans);
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