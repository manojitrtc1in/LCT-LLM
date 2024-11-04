



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

const int N = 200 * 1000 + 13;
const int LOGN = 18;

int n;
int a[N];
vector<int> g[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n){
		g[i].clear();
		scanf("%d", &a[i]);
	}
	forn(i, n - 1){
		int v, u;
		scanf("%d%d", &v, &u);
		--v, --u;
		g[v].pb(u);
		g[u].pb(v);
	}
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

int C[N][4];

int tin[N], tout[N], T;
int h[N];
int up[N][LOGN];

void init(int v, int p = -1){
	tin[v] = T++;
	for (int u : g[v]) if (u != p){
		h[u] = h[v] + 1;
		up[u][0] = v;
		fore(i, 1, LOGN)
			up[u][i] = up[up[u][i - 1]][i - 1];
		init(u, v);
	}
	tout[v] = T;
}

bool isp(int v, int u){
	return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int lca(int v, int u){
	if (h[v] < h[u]) swap(v, u);
	for (int i = LOGN - 1; i >= 0; --i)
		if (h[up[v][i]] >= h[u])
			v = up[v][i];
	if (v == u)
		return v;
	for (int i = LOGN - 1; i >= 0; --i){
		if (up[v][i] != up[u][i]){
			v = up[v][i];
			u = up[u][i];
		}
	}
	return up[v][0];
}

vector<pt> ng[N];
vector<int> cur[N];
int ans[N];
int cnt;
bool good[N];
int cntgood;

int dfs(int v){
	int sum = good[v];
	for (auto it : ng[v]){
		int u = it.x, w = it.y;
		int tmp = dfs(u);
		cnt = add(cnt, mul(w, add(C[cntgood][3], -add(C[tmp][3], C[cntgood - tmp][3]))));
		sum += tmp;
	}
	return sum;
}

void solve() {
	forn(i, N){
		C[i][0] = 1;
		if (i < 4) C[i][i] = 1;
		fore(j, 1, min(4, i))
			C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
	}
	T = 0;
	init(0);
	forn(i, N) cur[i].clear();
	forn(i, n){
		int x = a[i];
		for (int j = 2; j * j <= x; ++j) if (x % j == 0){
			while (x % j == 0) x /= j;
			cur[j].pb(i);
		}
		if (x > 1){
			cur[x].pb(i);
		}
	}
	fore(i, 1, N) if (!cur[i].empty()){
		for (int v : cur[i]) good[v] = true;
		vector<int> vts = cur[i];
		vts.pb(0);
		sort(all(vts), [](int x, int y){ return tin[x] < tin[y]; });
		int k = sz(vts);
		forn(j, k - 1) vts.pb(lca(vts[j], vts[j + 1]));
		sort(all(vts), [](int x, int y){ return tin[x] < tin[y]; });
		vts.resize(unique(all(vts)) - vts.begin());
		vector<int> st;
		for (int v : vts){
			while (!st.empty() && !isp(st.back(), v))
				st.pop_back();
			if (!st.empty())
				ng[st.back()].pb(mp(v, h[v] - h[st.back()]));
			st.pb(v);
		}
		cnt = 0;
		cntgood = sz(cur[i]);
		dfs(0);
		ans[i] = cnt;
		for (int v : vts) ng[v].clear();
		for (int v : cur[i]) good[v] = false;
	}
	int res = 0;
	for (int i = N - 1; i >= 1; --i)
		res = add(res, ans[i]);
	printf("%d\n", res);
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