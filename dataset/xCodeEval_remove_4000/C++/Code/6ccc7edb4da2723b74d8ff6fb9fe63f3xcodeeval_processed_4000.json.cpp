



using namespace std;














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

const int N = 150 + 3;

int n, k, s;
int a[N];

bool read () {
	if (scanf("%d%d%d", &n, &k, &s) != 3)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	return true;
}

int dp[2][N][N * N];

void solve() {
	s = min(s, n * (n - 1) / 2);
	forn(i, n + 1) forn(j, s + 1) dp[0][i][j] = INF;
	dp[0][0][0] = 0;
	forn(ii, n + 1){
		int i = ii & 1;
		int ni = i ^ 1;
		forn(j, n + 1) forn(t, s + 1)
			dp[ni][j][t] = INF;
		for (int j = n; j >= 0; --j) forn(t, s + 1) if (dp[i][j][t] < INF){
			

			if (ii < n && t + j <= s)
				dp[ni][j][t + j] = min(dp[ni][j][t + j], dp[i][j][t] + (ii - j < k ? a[ii] : 0));
			if (ii < n && ii - j < k)
				dp[ni][j + 1][t] = min(dp[ni][j + 1][t], dp[i][j][t]);
			if (ii - j >= k && j > 0)
				dp[i][j - 1][t] = min(dp[i][j - 1][t], dp[i][j][t]);
		}
	}
	printf("%d\n", *min_element(dp[n & 1][0], dp[n & 1][0] + s + 1));
}

int main() {

	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	

	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;


	int tc;
	scanf("%d", &tc);
	while(tc--){
		read();

	while(read()) {	

		solve();
		

	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();


	}
}