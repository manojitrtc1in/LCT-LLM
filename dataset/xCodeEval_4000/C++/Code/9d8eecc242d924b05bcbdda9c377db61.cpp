

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

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

struct node{
	int a, b, c;
};

node val[N];
int tin[N], tout[N], T;
int d[N];

void dfs(int v){
	tin[v] = T++;
	val[tin[v]] = {a[v], d[v], 0};
	for (int u : g[v]){
		d[u] = d[v] + 1;
		dfs(u);
	}
	tout[v] = T;
}

void solve() {
	T = 0;
	dfs(0);
	forn(i, m){
		int v = q[i];
		int ans1 = 0, ans2 = 0;
		for (int k = tin[v]; k < tout[v]; ++k){
			if (val[k].c <= i){
				val[k].c = i + val[k].a;
				++ans1;
				ans2 += val[k].b;
			}
		}
		ans2 -= ans1 * d[v];
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