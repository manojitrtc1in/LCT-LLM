

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

const int N = 1500 + 7;

int n;
int a[N][N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n) forn(j, n)
		scanf("%d", &a[i][j]);
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

int p[N], rk[N];
int dp[N][N];
int tot[N];

int getp(int a){
	return a == p[a] ? a : p[a] = getp(p[a]);
}

void unite(int a, int b){
	a = getp(a), b = getp(b);
	if (a == b) return;
	if (rk[a] < rk[b]) swap(a, b);
	vector<int> tmp(rk[a] + rk[b] + 1, 0);
	fore(i, 1, rk[a] + 1) fore(j, 1, rk[b] + 1)
		tmp[i + j] = add(tmp[i + j], mul(dp[a][i], dp[b][j]));
	rk[a] += rk[b];
	forn(i, rk[a] + 1)
		dp[a][i] = tmp[i];
	p[b] = a;
	tot[a] += tot[b];
}

void solve() {
	vector<pair<int, pt>> e;
	forn(i, n) forn(j, i) e.pb(mp(a[i][j], mp(i, j)));
	memset(dp, 0, sizeof(dp));
	forn(i, n) p[i] = i, rk[i] = 1, dp[i][1] = 1, tot[i] = 0;
	sort(all(e));
	for (auto it : e){
		int v = it.y.x, u = it.y.y;
		unite(v, u);
		++tot[getp(v)];
		if (tot[getp(v)] == rk[getp(v)] * (rk[getp(v)] - 1) / 2)
			++dp[getp(v)][1];
	}
	fore(i, 1, n + 1) printf("%d ", dp[getp(0)][i]);
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