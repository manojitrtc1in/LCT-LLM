

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

const int N = 100 * 1000 + 13;

struct query{
	int t, x, y;
};

int n, m;
query a[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, m){
		scanf("%d%d", &a[i].t, &a[i].x);
		--a[i].x;
		if (a[i].t != 2){
			scanf("%d", &a[i].y);
			--a[i].y;
		}
	}
	return true;
}

int tin[N], tout[N], T;

vector<int> pos[N];
vector<int> g[N];
int val[N];
bool root[N];

void init(int v){
	tin[v] = T++;
	for (auto u : g[v])
		init(u);
	tout[v] = T++;
}

bool isp(int v, int u){
	return tin[v] <= tin[u] && tout[u] <= tout[v];
}

bool ans[N];

int p[N];

int getp(int a){
	return a == p[a] ? a : p[a] = getp(p[a]);
}

void solve() {
	forn(i, n) root[i] = true;
	forn(i, n) g[i].clear();
	forn(i, m) if (a[i].t == 1){
		g[a[i].y].pb(a[i].x);
		root[a[i].x] = false;
	}
	T = 0;
	forn(i, n) if (root[i]){
		init(i);
	}
	iota(p, p + n, 0);
	int cnt = 0;
	forn(i, m) pos[i].clear();
	forn(i, m){
		if (a[i].t == 2){
			val[cnt] = a[i].x;
			++cnt;
		}
		else if (a[i].t == 3){
			pos[a[i].y].pb(i);
		}
	}
	cnt = 0;
	forn(i, m){
		if (a[i].t == 1){
			p[a[i].x] = a[i].y;
		}
		else if (a[i].t == 2){
			for (auto it : pos[cnt])
				ans[it] = isp(a[it].x, val[a[it].y]) && getp(val[a[it].y]) == getp(a[it].x);
			++cnt;
		}
	}
	forn(i, m) if (a[i].t == 3){
		puts(ans[i] ? "YES" : "NO");
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