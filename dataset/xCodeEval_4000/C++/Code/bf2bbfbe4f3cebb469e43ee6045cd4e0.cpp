

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
const int MOD = 998244353;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 200 + 7;

int n, m, k;
vector<int> g[N];

bool read () {
	if (scanf("%d%d%d", &n, &m, &k) != 3)
		return false;
	forn(i, n)
		g[i].clear();
	forn(i, m){
		int v, u;
		scanf("%d%d", &v, &u);
		--v, --u;
		g[v].pb(u);
		g[u].pb(v);
	}
	return true;
}

int add(int a, int b){
	a += b;
	if (a >= MOD)
		a -= MOD;
	if (a < 0)
		a += MOD;
	return a;
}

int mul(int a, int b){
	return a * li(b) % MOD;
}

typedef array<array<int, N>, N> mat;

mat operator *(const mat &a, const mat &b){
	mat c;
	forn(i, N) forn(j, N) c[i][j] = 0;
	forn(i, N) forn(j, N) forn(k, N) c[i][j] = add(c[i][j], mul(a[i][k], b[k][j]));
	return c;
}

mat binpow(mat a, int b){
	mat res;
	forn(i, N) forn(j, N) res[i][j] = i == j;
	while (b){
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

void solve() {
	if (k == 1){
		puts("0");
		return;
	}
	
	mat A;
	forn(i, N) forn(j, N) A[i][j] = 0;
	forn(v, n) for (int u : g[v])
		A[u + n][v + n] = 1;
	forn(v, n){
		A[v][v + n] = -(sz(g[v]) - 1);
		A[v + n][v] = 1;
	}
	A = binpow(A, k - 2);
	
	int ans = 0;
	forn(v, n){
		vector<int> cur(N);
		for (int u : g[v]){
			cur[u] = 1;
			for (int w : g[u]) if (w != v)
				cur[w + n] += 1;
		}
		forn(x, N)
			ans = add(ans, mul(A[x][v + n], cur[x]));
	}
	
	printf("%d\n", ans);
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