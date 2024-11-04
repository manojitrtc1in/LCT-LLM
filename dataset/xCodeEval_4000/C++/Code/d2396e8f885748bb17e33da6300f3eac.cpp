

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
const int MOD = INF + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 400 * 1000 + 13;
const int LOGN = 19;

int n, k, r, m;
bool a[N];
vector<int> g[N];
pt q[N];

bool read () {
	if (scanf("%d%d%d", &n, &k, &r) != 3)
		return false;
	memset(a, 0, sizeof(a));
	forn(i, 2 * n){
		g[i].clear();
	}
	forn(i, n - 1){
		int v, u;
		scanf("%d%d", &v, &u);
		--v, --u;
		g[v].pb(n + i);
		g[n + i].pb(v);
		g[u].pb(n + i);
		g[n + i].pb(u);
	}
	forn(i, r){
		int x;
		scanf("%d", &x);
		--x;
		a[x] = true;
	}
	n += n - 1;
	scanf("%d", &m);
	forn(i, m){
		scanf("%d%d", &q[i].x, &q[i].y);
		--q[i].x, --q[i].y;
	}
	return true;
}

int d[N];
int rk[N], p[N];
int h[N];

int up[N][LOGN];

void dfs(int v, int p = -1){
	for (auto u : g[v]) if (u != p){
		h[u] = h[v] + 1;
		up[u][0] = v;
		fore(i, 1, LOGN)
			up[u][i] = up[up[u][i - 1]][i - 1];
		dfs(u, v);
	}
}

int getp(int a){
	return a == p[a] ? a : p[a] = getp(p[a]);
}

void unite(int a, int b){
	a = getp(a), b = getp(b);
	if (a == b) return;
	if (rk[a] < rk[b]) swap(a, b);
	rk[a] += rk[b];
	p[b] = a;
}

void bfs(){
	forn(i, n) d[i] = INF;
	queue<int> q;
	forn(i, n + 1) p[i] = i, rk[i] = 1;
	forn(i, n) if (a[i]){
		d[i] = 0;
		q.push(i);
	}
	while (!q.empty()){
		int v = q.front();
		q.pop();
		if (d[v] == k) continue;
		for (auto u : g[v]){
			unite(v, u);
			if (d[u] == INF){
				d[u] = d[v] + 1;
				q.push(u);
			}
		}
	}
	forn(i, n) if (d[i] == INF){
		unite(i, n);
	}
}

int lca(int v, int u){
	if (h[v] < h[u])
		swap(v, u);
	for (int i = LOGN - 1; i >= 0; --i)
		if (h[up[v][i]] >= h[u])
			v = up[v][i];
	if (v == u)
		return v;
	for (int i = LOGN - 1; i >= 0; --i)
		if (up[v][i] != up[u][i])
			v = up[v][i], u = up[u][i];
	return up[v][0];
}

int get(int v, int k){
	forn(i, LOGN) if ((k >> i) & 1)
		v = up[v][i];
	return v;
}

void solve() {
	bfs();
	dfs(0);
	forn(i, m){
		int v = q[i].x;
		int u = q[i].y;
		int l = lca(v, u);
		int d = h[v] + h[u] - 2 * h[l];
		if (d <= 2 * k){
			puts("YES");
			continue;
		}
		int v1 = (h[v] - h[l] >= k ? get(v, k) : get(u, d - k));
		int v2 = (h[u] - h[l] >= k ? get(u, k) : get(v, d - k));
		puts(getp(v1) == getp(v2) && getp(v1) != getp(n) ? "YES" : "NO");
	}
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

	while(read()) {	
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}