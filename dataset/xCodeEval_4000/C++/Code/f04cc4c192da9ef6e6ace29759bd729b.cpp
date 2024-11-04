

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

const int N = 3000 + 7;

int n, k;
int a[N];

bool read () {
	if (scanf("%d%d", &n, &k) != 2)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	return true;
}

bool is0[N], is1[N];
int dp[N][N];

void solve() {
	memset(is0, 0, sizeof(is0));
	memset(is1, 0, sizeof(is1));
	is0[n] = true;
	for (int i = n - 1; i >= 0; --i){
		is0[i] = is0[i + 1] && (a[i] != 100);
		is1[i] = is1[i + 1] || (a[i] != 0);
	}
	forn(i, n + 1) forn(j, n + 1) dp[i][j] = INF;
	dp[0][0] = 0;
	forn(i, n) forn(j, n - i + 1) if (dp[i][j] != INF){
		if (a[i] != 0 && i + j + 1 < n && is0[i + j + 1])
			dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
		if (a[i] != 100 && is1[i + j + 1])
			dp[i + j + 1][0] = min(dp[i + j + 1][0], dp[i][j] + 1);
		if (a[i] != 0 && is1[i + j + 1])
			dp[i + j + 2][0] = min(dp[i + j + 2][0], dp[i][j] + 1);
	}
	int ans = 0;
	forn(i, n + 1) forn(j, n - i + 1) if (dp[i][j] <= k)
		++ans;
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

	while(read()) {	
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}