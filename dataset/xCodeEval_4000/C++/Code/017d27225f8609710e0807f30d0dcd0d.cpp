

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

const int N = 200 * 1000 + 13;

int n;
vector<pt> g[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n) g[i].clear();
	forn(i, n){
		int v, u, w;
		scanf("%d%d%d", &v, &u, &w);
		--v, --u;
		g[v].pb(mp(u, w));
		g[u].pb(mp(v, w));
	}
	return true;
}

int used[N], p[N];
bool cyc[N];

void dfs(int v, int pr = -1){
	used[v] = 1;
	for (auto it : g[v]){
		int u = it.x;
		if (!used[u]){
			p[u] = v;
			dfs(u, v);
		}
		else if (used[u] == 1 && u != pr){
			int cur = v;
			cyc[cur] = true;
			while (cur != u){
				cur = p[cur];
				cyc[cur] = true;
			}
		}
	}
	used[v] = 2;
}

li dist[N];
li ans;

void getmx(int v, int p){
	dist[v] = 0;
	for (auto it : g[v]) if (it.x != p){
		getmx(it.x, v);
		ans = max(ans, dist[v] + dist[it.x] + it.y);
		dist[v] = max(dist[v], dist[it.x] + it.y);
	}
}

li pr[N], prmax[N];
li su[N], sumax[N];

void solve() {
	memset(used, 0, sizeof(used));
	memset(cyc, 0, sizeof(cyc));
	memset(dist, 0, sizeof(dist));
	
	dfs(0);
	ans = 0;
	forn(v, n) if (cyc[v]) for (auto it : g[v]){
		int u = it.x;
		if (!cyc[u]){
			getmx(u, v);
			dist[u] += it.y;
			ans = max(ans, dist[v] + dist[u]);
			dist[v] = max(dist[v], dist[u]);
		}
	}
	
	memset(used, 0, sizeof(used));
	vector<pair<li, li>> cc;
	forn(i, n) if (cyc[i]){
		int v = i;
		while (!used[v]){
			used[v] = true;
			for (auto it : g[v]) if (cyc[it.x] && !used[it.x]){
				cc.pb(mp(dist[it.x], it.y));
				v = it.x;
				break;
			}
		}
		for (auto it : g[v]) if (it.x == i){
			cc.pb(mp(dist[it.x], it.y));
		}
		break;
	}
	
	li tot, mn;
	
	tot = 0;
	mn = -cc[0].x;
	pr[0] = prmax[0] = cc[0].x;
	fore(i, 1, sz(cc) + 1){
		tot += cc[i % sz(cc)].y;
		pr[i] = max(pr[i - 1], tot + cc[i % sz(cc)].x);
		prmax[i] = max(prmax[i - 1], tot + cc[i % sz(cc)].x - mn);
		mn = min(mn, tot - cc[i % sz(cc)].x);
	}
	
	tot = 0;
	mn = 0;
	su[sz(cc)] = sumax[sz(cc)] = 0;
	for (int i = sz(cc) - 1; i >= 0; --i){
		tot += cc[(i + 1) % sz(cc)].y;
		su[i] = max(su[i + 1], tot + cc[i].x);
		sumax[i] = max(sumax[i + 1], tot + cc[i].x - mn);
		mn = min(mn, tot - cc[i].x);
	}
	
	li res = INF64;
	forn(i, sz(cc))
		res = min(res, max({sumax[i + 1], prmax[i], pr[i] + su[i + 1]}));
	
	printf("%lld\n", max(ans, res));
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