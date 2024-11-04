

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

const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = int(1e9) + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 30 * 1000 + 13;
const int LOGN = 16;

int n, k;
vector<int> a[N];

bool read () {
	if (scanf("%d%d", &n, &k) != 2)
		return false;
	forn(i, k){
		a[i].resize(n);
		forn(j, n)
			scanf("%d", &a[i][j]);
	}
	return true;
}

vector<int> g[N];
int p[N], d[N];
vector<pt> tmp[N];
bool used[N];

int tin[N], tout[N];
int T;
int up[N][LOGN];

void dfs(int v, int p) {
	tin[v] = T++;
	
	up[v][0] = p;
	fore(i, 1, LOGN)
		up[v][i] = up[up[v][i - 1]][i - 1];
	
	for (auto u : g[v]) if (u != p){
		d[u] = d[v] + 1;
		dfs(u, v);
	}
		
	tout[v] = T;
}

bool is_anc(int v, int u) {
	return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int lca(int v, int u) {
	if (is_anc(v, u)) return v;
	if (is_anc(u, v)) return u;
	for (int i = LOGN - 1; i >= 0; i--)
		if (!is_anc(up[v][i], u))
			v = up[v][i];
	return up[v][0];
}

void init_lca(int root = 0) {
	T = 0;
	d[root] = 0;
	dfs(root, root);
}

int dist(int v, int u){
	return d[v] + d[u] - 2 * d[lca(v, u)];
}

void solve() {
	forn(i, n) g[i].clear();
	forn(i, n) tmp[i].clear();
	forn(i, n) used[i] = false;
	int r = find(all(a[0]), 0) - a[0].begin();
	if (r == n){
		puts("-1");
		return;
	}
	p[r] = -1;
	used[r] = true;
	forn(i, n) if (i != r) tmp[r].pb(mp(i, a[0][i]));
	fore(z, 1, k){
		int v = find(all(a[z]), 0) - a[z].begin();
		if (v == n){
			puts("-1");
			return;
		}
		vector<pt> vts;
		forn(i, n) if (a[0][i] + a[z][i] == a[0][v])
			vts.pb(mp(a[z][i], i));
		sort(all(vts));
		int w = r;
		int nj = sz(vts) - 1;
		forn(j, sz(vts) - 1){
			if (used[vts[j].y]){
				w = vts[j].y;
				nj = j;
				break;
			}
			p[vts[j].y] = vts[j + 1].y;
			used[vts[j].y] = true;
		}
		vector<pt> dtmp = tmp[w];
		tmp[w].clear();
		for (auto it : dtmp) if (!used[it.x]){
			int dist = a[0][v] + a[0][it.x] - a[z][it.x];
			if (dist % 2 != 0){
				puts("-1");
				return;
			}
			dist /= 2;
			dist = a[0][v] - dist;
			if (dist > nj){
				puts("-1");
				return;
			}
			tmp[vts[dist].y].pb(mp(it.x, a[z][it.x] - dist));
		}
	}
	
	forn(i, n) if (used[i] && i != r)
		g[p[i]].pb(i);
		
	forn(i, n){
		sort(all(tmp[i]), [](const pt &a, const pt &b){
			return a.y < b.y;
		});
		int lst = 0;
		int v = -1, u = i;
		forn(j, sz(tmp[i])){
			if (tmp[i][j].y == lst);
			else if (tmp[i][j].y == lst + 1){
				++lst;
				v = u, u = -1;
			}
			else{
				puts("-1");
				return;
			}
			g[v].pb(tmp[i][j].x);
			u = tmp[i][j].x;
		}
	}
	
	init_lca(r);
	forn(i, k){
		int v = find(all(a[i]), 0) - a[i].begin();
		forn(j, n) if (dist(v, j) != a[i][j]){
			puts("-1");
			return;
		}
	}
	
	forn(v, n) for (int u : g[v])
		printf("%d %d\n", v + 1, u + 1);
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