

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

const int N = 10 * 1000 + 13;

int n, l, r;
pt c[N];

bool read () {
	if (scanf("%d%d%d", &n, &l, &r) != 3)
		return false;
	forn(i, n)
		scanf("%d", &c[i].x);
	forn(i, n)
		scanf("%d", &c[i].y);
	return true;
}

int dp[2][N];
int pr[N];

void solve() {
	sort(c, c + n, [](const pt &a, const pt &b){
		if (a.y != b.y)
			return a.y < b.y;
		if (a.y == 0)
			return a.x < b.x;
		return a.x > b.x;
	});
	
	int sum = 0;
	forn(i, n) sum += c[i].x;
	l = sum - l, r = sum - r;
	swap(l, r);
	
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	pr[0] = 0;
	forn(ii, n){
		int i = ii & 1;
		int ni = i ^ 1;
		pr[ii + 1] = pr[ii] + c[ii].x;
		if (ii) memset(dp[ni], -1, sizeof(int) * (pr[ii - 1] + 1));
		forn(j, pr[ii] + 1) if (dp[i][j] >= 0){
			dp[ni][j] = max(dp[ni][j], dp[i][j]);
			dp[ni][j + c[ii].x] = max(dp[ni][j + c[ii].x], dp[i][j] + (l <= j + c[ii].x && j + c[ii].x <= r && c[ii].y == 1));
		}
	}
	
	int ans = 0;
	forn(i, N) ans = max(ans, dp[n & 1][i]);
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