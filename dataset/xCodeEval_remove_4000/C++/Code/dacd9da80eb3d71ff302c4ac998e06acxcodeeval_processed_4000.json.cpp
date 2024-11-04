



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
vector<pt> g[N];
li q[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		g[i].clear();
	forn(i, n - 1){
		int v, u, w;
		scanf("%d%d%d", &v, &u, &w);
		--v, --u;
		g[v].pb(mp(u, w));
		g[u].pb(mp(v, w));
	}
	scanf("%d", &m);
	forn(i, m)
		scanf("%lld", &q[i]);
	return true;
}

li a[N];
li mx[N];

void init(int v, int p = -1){
	mx[v] = 0;
	for (auto it : g[v]){
		int u = it.x;
		int w = it.y;
		if (u == p) continue;
		init(u, v);
		mx[v] = max(mx[v], mx[u] + w);
	}
}

void dfs(int v, li up, int p = -1){
	a[v] = max(up, mx[v]);
	pair<li, int> mx1(-1, -1), mx2(-1, -1);
	for (auto it : g[v]){
		int u = it.x;
		int w = it.y;
		if (u == p) continue;
		if (mx[u] + w > mx1.x){
			mx2 = mx1;
			mx1 = mp(mx[u] + w, u);
		}
		else if (mx[u] + w > mx2.x){
			mx2 = mp(mx[u] + w, u);
		}
	}
	for (auto it : g[v]){
		int u = it.x;
		int w = it.y;
		if (u == p) continue;
		dfs(u, max(up, mx1.y == u ? mx2.x : mx1.x) + w, v);
	}
}

vector<int> ord, rord;

int rk[N], p[N];

int getp(int a){
	return a == p[a] ? a : p[a] = getp(p[a]);
}

void unite(int a, int b){
	a = getp(a), b = getp(b);
	if (rk[a] < rk[b]) swap(a, b);
	rk[a] += rk[b];
	p[b] = a;
}

int calc(li x){
	forn(i, n) rk[i] = 1, p[i] = i;
	int res = 0;
	priority_queue<int> cur, del;
	forn(i, n) cur.push(1);
	int r = 0;
	forn(l, n){
		while (r + 1 < n && a[ord[l]] - a[ord[r + 1]] <= x){
			++r;
			for (auto it : g[ord[r]]){
				int v = it.x;
				if (l <= rord[v] && rord[v] <= r){
					del.push(rk[getp(ord[r])]);
					del.push(rk[getp(v)]);
					unite(ord[r], v);
					cur.push(rk[getp(v)]);
				}
			}
		}
		while (!cur.empty() && !del.empty() && del.top() == cur.top()){
			del.pop();
			cur.pop();
		}
		res = max(res, cur.top());
		del.push(rk[getp(ord[l])]);
		--rk[getp(ord[l])];
		cur.push(rk[getp(ord[l])]);
	}
	return res;
}

void solve() {
	init(0);
	dfs(0, 0);
	ord.resize(n);
	iota(all(ord), 0);
	sort(all(ord), [](int x, int y){
		return a[x] > a[y];
	});
	rord.resize(n);
	forn(i, n) rord[ord[i]] = i;
	

	

	forn(i, m) printf("%d\n", calc(q[i]));
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