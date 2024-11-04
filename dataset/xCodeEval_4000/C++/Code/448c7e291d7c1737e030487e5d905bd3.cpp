

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

const int N = 50 * 1000 + 13;

int n, m;
int a[N], p[N];
vector<int> g[N];
int q[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	forn(i, n)
		g[i].clear();
	fore(i, 1, n){
		scanf("%d", &p[i]);
		--p[i];
		g[p[i]].pb(i);
	}
	forn(i, m){
		scanf("%d", &q[i]);
		--q[i];
	}
	return true;
}

pt val[N];
int mn[11][N], mx[11][N];
int d[N];

void dfs(int v){
	for (int u : g[v]){
		dfs(u);
		forn(i, 10) mn[i + 1][v] = min(mn[i + 1][v], mn[i][u]);
		forn(i, 10) mx[i + 1][v] = max(mx[i + 1][v], mx[i][u]);
	}
}

void solve() {
	queue<int> Q;
	Q.push(0);
	d[0] = 0;
	forn(i, n) forn(j, 11) mn[j][i] = INF, mx[j][i] = -INF;
	int cnt = 0;
	while (!Q.empty()){
		int v = Q.front();
		Q.pop();
		mn[0][v] = cnt;
		mx[0][v] = cnt;
		val[cnt] = mp(a[v], 0);
		++cnt;
		for (int u : g[v]){
			d[u] = d[v] + 1;
			Q.push(u);
		}
	}
	dfs(0);
	
	forn(i, m){
		int v = q[i];
		int ans1 = 0, ans2 = 0;
		forn(j, 11){
			for (int k = mn[j][v]; k <= mx[j][v]; ++k){
				if (val[k].y <= i){
					val[k].y = i + val[k].x;
					++ans1;
					ans2 += j;
				}
			}
		}
		printf("%d %d\n", ans2, ans1);
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