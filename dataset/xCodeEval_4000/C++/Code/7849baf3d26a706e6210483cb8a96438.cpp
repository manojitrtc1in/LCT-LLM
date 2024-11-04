

#include <bits/stdc++.h>

using namespace std;




#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forn(i, n) for(int i = 0; i < int(n); i++) 
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

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

const int INF = (1 << 30);
const li INF64 = li(1e18);
const int MOD = int(1e9) + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 200 * 1000 + 13;
const int LOGN = 19;

struct edge{
	int v, u, w;
};

int n, m;
edge e[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, m){
		scanf("%d%d%d", &e[i].v, &e[i].u, &e[i].w);
		--e[i].v, --e[i].u;
	}
	return true;
}

vector<int> g[N];
set<int> cur;

int p[N], rk[N];

int getp(int a){
	return a == p[a] ? a : p[a] = getp(p[a]);
}

bool unite(int a, int b){
	a = getp(a), b = getp(b);
	if (a == b) return false;
	if (rk[a] < rk[b]) swap(a, b);
	rk[a] += rk[b];
	p[b] = a;
	return true;
}

int up[N][LOGN];
int mn[N][LOGN];
int d[N];

bool used[N];

void dfs(int v, int p = -1){
	used[v] = true;
	for (int u : g[v]) if (u != p){
		up[u][0] = v;
		mn[u][0] = INF;
		d[u] = d[v] + 1;
		fore(i, 1, LOGN){
			up[u][i] = up[up[u][i - 1]][i - 1];
			mn[u][i] = INF;
		}
		dfs(u, v);
	}
}

void upd(int v, int u, int w){
	if (d[v] < d[u]) swap(v, u);
	for (int i = LOGN - 1; i >= 0; --i){
		if (d[up[v][i]] >= d[u]){
			mn[v][i] = min(mn[v][i], w);
			v = up[v][i];
		}
	}
	if (v == u) return;
	for (int i = LOGN - 1; i >= 0; --i){
		if (up[v][i] != up[u][i]){
			mn[v][i] = min(mn[v][i], w);
			mn[u][i] = min(mn[u][i], w);
			v = up[v][i];
			u = up[u][i];
		}
	}
	mn[v][0] = min(mn[v][0], w);
	mn[u][0] = min(mn[u][0], w);
}

void solve() {
	sort(e, e + m, [](const edge &a, const edge &b){
		return a.w < b.w;
	});
	int xr = 0;
	forn(i, m) xr ^= e[i].w;
	
	forn(i, n) g[i].clear();
	forn(i, m){
		g[e[i].v].pb(e[i].u);
		g[e[i].u].pb(e[i].v);
	}
	cur.clear();
	forn(i, n) cur.insert(i);
	vector<pt> es;
	
	vector<pt> segs;
	forn(i, n){
		sort(all(g[i]));
		g[i].resize(unique(all(g[i])) - g[i].begin());
		g[i].insert(g[i].begin(), -1);
		g[i].insert(g[i].end(), n);
		forn(j, sz(g[i]) - 1) if (g[i][j] + 1 != g[i][j + 1]){
			es.pb(mp(i, g[i][j] + 1));
			segs.pb(mp(g[i][j] + 1, g[i][j + 1] - 1));
		}
		g[i].erase(g[i].begin());
		g[i].erase(--g[i].end());
	}
	sort(all(segs));
	
	int l = -INF, r = -INF;
	for (auto it : segs){
		if (it.x > r){
			fore(i, l, r) es.pb(mp(i, i + 1));
			l = it.x, r = it.y;
		}
		else{
			r = max(r, it.y);
		}
	}
	fore(i, l, r) es.pb(mp(i, i + 1));
	
	sort(all(es));
	es.resize(unique(all(es)) - es.begin());
	
	forn(i, n) rk[i] = 1, p[i] = i;
	bool fl = false;
	for (auto it : es) unite(it.x, it.y);
	if (n * li(n - 1) / 2 - m >= n){
		fl = true;
	}
	else{
		es.clear();
		forn(v, n){
			int i = 0;
			for (int u : g[v]){
				while (i < u){
					if (v < i) es.pb(mp(v, i));
					++i;
				}
				++i;
			}
			while (i < n){
				if (v < i) es.pb(mp(v, i));
				++i;
			}
		}
		forn(i, n) p[i] = i, rk[i] = 1;
		for (auto it : es) if (!unite(it.x, it.y))
			fl = true;
	}
	if (!fl){
		forn(i, n) g[i].clear();
		for (auto it : es){
			g[it.x].pb(it.y);
			g[it.y].pb(it.x);
		}
	}
	li sum = 0;
	vector<int> sv;
	forn(i, m){
		if (unite(e[i].v, e[i].u)){
			sum += e[i].w;
			g[e[i].v].pb(e[i].u);
			g[e[i].u].pb(e[i].v);
		}
		else{
			sv.pb(i);
		}
	}
	if (fl){
		printf("%lld\n", sum);
		return;
	}
	
	memset(used, 0, sizeof(used));
	forn(i, n) if (!used[i]){
		forn(j, LOGN) up[i][j] = i, mn[i][j] = INF;
		dfs(i);
	}
	for (int i : sv){
		upd(e[i].v, e[i].u, e[i].w);
	}
	for (int i = LOGN - 1; i > 0; --i){
		forn(j, n){
			mn[j][i - 1] = min(mn[j][i - 1], mn[j][i]);
			mn[up[j][i - 1]][i - 1] = min(mn[up[j][i - 1]][i - 1], mn[j][i]);
		}
	}
	
	li ans = sum + xr;
	for (auto it : es){
		int v = it.x, u = it.y;
		if (d[v] < d[u]) swap(v, u);
		ans = min(ans, sum + mn[v][0]);
	}
	printf("%lld\n", ans);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	
#endif
	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;

#ifdef MULTITEST
	int tc;
	scanf("%d", &tc);
	while(tc--){
		read();
#else
	while(read()) {	
#endif
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}