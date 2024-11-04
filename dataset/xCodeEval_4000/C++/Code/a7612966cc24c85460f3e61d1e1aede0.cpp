

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
const int AL = 20;

int n;
vector<int> g[N];
string s;

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		g[i].clear();
	forn(i, n - 1){
		int v, u;
		scanf("%d%d", &v, &u);
		--v, --u;
		g[v].pb(u);
		g[u].pb(v);
	}
	static char buf[N];
	scanf("%s", buf);
	s = buf;
	return true;
}

int h[N], pcd[N], d[N];
int pv[N];
li ans[N];

int mask[N], val[N];
vector<int> cg[N], st[N];

int dfs(int v, int s, int &cd, int p = -1){
	int sum = 1;
	for (auto u : g[v]) if (h[u] == -1 && u != p)
		sum += dfs(u, s, cd, v);
	if (cd == -1 && (2 * sum >= s || p == -1))
		cd = v;
	return sum;
}

void build(int v, int s, int d, int p = -1){
	int cd = -1;
	dfs(v, s, cd);
	h[cd] = d;
	pcd[cd] = p;
	for (auto u : g[cd]) if (h[u] == -1)
		build(u, s / 2, d + 1, cd);
}

vector<int> ord;
int pos[N];
pt ST[LOGN][N];
int pw[N];

void init(int v, int p = -1){
	ord.pb(v);
	pv[v] = p;
	for (auto u : g[v]) if (u != p){
		d[u] = d[v] + 1;
		mask[u] = mask[v] ^ val[u];
		init(u, v);
		ord.pb(v);
	}
}

void init2(){
	forn(i, sz(ord))
		pos[ord[i]] = i;
	pw[0] = pw[1] = 0;
	fore(i, 2, N)
		pw[i] = pw[i / 2] + 1;
	forn(i, sz(ord))
		ST[0][i] = mp(d[ord[i]], ord[i]);
	fore(j, 1, LOGN){
		forn(i, sz(ord)){
			ST[j][i] = ST[j - 1][i];
			if (i + (1 << (j - 1)) < sz(ord))
				ST[j][i] = min(ST[j][i], ST[j - 1][i + (1 << (j - 1))]);
		}
	}
}

int lca(int v, int u){
	if (pos[v] > pos[u]) swap(v, u);
	int l = pos[v], r = pos[u] + 1;
	int len = pw[r - l];
	return min(ST[len][l], ST[len][r - (1 << len)]).y;
}

int path(int v, int u){
	return mask[v] ^ mask[u] ^ val[lca(v, u)] ^ val[u];
}

int cnt[1 << AL];
int pals[AL + 1];

void add(int v, int u, int k){
	k *= 2;
	int l = lca(v, u);
	if (l != v && l != u){
		ans[pv[v]] += k;
		ans[u] += k;
		ans[l] -= k;
		if (pv[l] != -1) ans[pv[l]] -= k;
	}
	else if (d[u] < d[v]){
		ans[pv[v]] += k;
		if (pv[u] != -1) ans[pv[u]] -= k;
	}
	else{
		ans[u] += k;
		ans[v] -= k;
	}
}

void calc(int v){
	li tot = 0;
	
	for (auto u : st[v]){
		if (v != u) ++cnt[path(u, v)];
		int k = __builtin_popcount(path(u, v) ^ val[v]) <= 1;
		add(v, u, k);
		tot += k * 2;
	}
	
	for (auto u : cg[v]){
		for (auto it : st[u])
			--cnt[path(it, v)];
		for (auto it : st[u]){
			forn(i, AL + 1){
				int k = cnt[path(it, v) ^ val[v] ^ pals[i]];
				add(v, it, k);
				tot += k;
			}
		}
		for (auto it : st[u])
			++cnt[path(it, v)];
	}
	
	ans[v] += tot;
	if (pv[v] != -1) ans[pv[v]] -= tot;
	
	for (auto u : st[v]) if (v != u)
		--cnt[path(u, v)];
	
	for (auto u : cg[v])
		calc(u);
}

void collect(int v, int p = -1){
	for (auto u : g[v]) if (u != p){
		collect(u, v);
		ans[v] += ans[u];
	}
}

void solve(){
	forn(i, AL) pals[i] = (1 << i);
	pals[AL] = 0;
	
	memset(h, -1, sizeof(h));
	build(0, n, 0);
	forn(i, n) val[i] = (1 << (s[i] - 'a'));
	ord.clear();
	init(0);
	init2();
	
	forn(i, n) st[i].clear(), cg[i].clear();
	int ct = -1;
	forn(v, n){
		int u = v;
		while (u != -1){
			st[u].pb(v);
			u = pcd[u];
		}
		if (pcd[v] != -1)
			cg[pcd[v]].pb(v);
		else
			ct = v;
	}
	
	memset(ans, 0, sizeof(ans));
	calc(ct);
	collect(0);
	
	forn(i, n) printf("%lld ", ans[i] / 2);
	puts("");
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