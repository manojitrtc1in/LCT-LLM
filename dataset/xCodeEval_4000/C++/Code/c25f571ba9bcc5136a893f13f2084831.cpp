

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

const int N = 1000 + 7;
const int M = 100 + 7;

int n, m;
pt a[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, n)
		scanf("%d%d", &a[i].x, &a[i].y);
	return true;
}

int dp[2][N][N];

void solve() {
	sort(a, a + n, [](const pt &a, const pt &b){
		return a.x > b.x;
	});
	forn(j, n + 1) forn(k, n + 1)
		dp[0][j][k] = -INF;
	dp[0][0][1] = 0;
	int ans = 0;
	forn(ii, m + 1){
		int i = ii & 1;
		int ni = i ^ 1;
		forn(j, n + 1) forn(k, n + 1) dp[ni][j][k] = -INF;
		forn(j, n + 1) forn(k, n + 1) if (dp[i][j][k] >= 0){
			ans = max(ans, dp[i][j][k]);
			if (j < n)
				dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k]);
			if (k > 0 && ii + a[j].x <= m)
				dp[i][j + 1][k - 1] = max(dp[i][j + 1][k - 1], dp[i][j][k] + a[j].y);
			dp[ni][j][min(n, k * 2)] = max(dp[ni][j][min(n, k * 2)], dp[i][j][k]);
		}
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