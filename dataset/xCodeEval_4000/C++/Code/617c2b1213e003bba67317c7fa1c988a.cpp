

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
const int LOGN = 18;

int n, m;
pair<int, li> a[N];
pt q[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%d%lld", &a[i].x, &a[i].y);
	scanf("%d", &m);
	forn(i, m){
		scanf("%d%d", &q[i].x, &q[i].y);
		--q[i].x, --q[i].y;
	}
	return true;
}

pair<int, li> operator -(const pair<int, li> &a, const pair<int, li> &b){
	return mp(a.x - b.x, a.y - b.y);
}

li cross(const pair<int, li> &a, const pair<int, li> &b){
	return a.x * b.y - a.y * b.x;
}

vector<int> g[N];

int up[N][LOGN];
int d[N];

void init(int v){
	for (auto u : g[v]){
		d[u] = d[v] + 1;
		up[u][0] = v;
		fore(i, 1, LOGN)
			up[u][i] = up[up[u][i - 1]][i - 1];
		init(u);
	}
}

int lca(int v, int u){
	if (d[v] < d[u])
		swap(v, u);
	for (int i = LOGN - 1; i >= 0; --i)
		if (d[up[v][i]] >= d[u])
			v = up[v][i];
	if (v == u)
		return v;
	for (int i = LOGN - 1; i >= 0; --i)
		if (up[v][i] != up[u][i]){
			v = up[v][i];
			u = up[u][i];
		}
	return up[v][0];
}

void solve() {
	vector<int> st(1, n - 1);
	for (int i = n - 2; i >= 0; --i){
		while (sz(st) > 1 && cross(a[st[sz(st) - 2]] - a[i], a[st[sz(st) - 1]] - a[i]) < 0)
			st.pop_back();
		g[st.back()].pb(i);
		st.pb(i);
	}
	forn(i, LOGN)
		up[n - 1][i] = n - 1;
	d[n - 1] = 0;
	init(n - 1);
	forn(i, m) printf("%d ", lca(q[i].x, q[i].y) + 1);
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